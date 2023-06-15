#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
// Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks array with rank_preference given a new vote
bool vote(int rank, string name, int ranks[])
{

// Loop through candidates
for (int i = 0; i < candidate_count; i++)
{
//Check if candidate is valid

if (strcmp(candidates[i], name) == 0)
{
    ranks[rank] = i;
    return true;
}
}
    return false;
}

// Update preferences given one voter's ranks

void record_preferences(int ranks[])
{
for (int i = 0; i < candidate_count - 1; i++)
{
for (int j = i + 1; j < candidate_count; j++)
{
            preferences[ranks [i]][ranks [j]]++;
}
}
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // if there is a TIE between pairs, do not add!
    for (int i = 0; i < candidate_count - 1; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            {
                if (preferences[i][j] > preferences[j][i])
                {
                    pairs[pair_count].winner = i;
                    pairs[pair_count].loser = j;
                  pair_count++;
                }
                else if (preferences[i][j] < preferences[j][i])
                {
                  pairs[pair_count].winner = j;
                  pairs[pair_count].loser = i;
                pair_count++;
                }
            }
        }
    }
    return;
}
// Sort pairs in decreasing order by strength of victory, using merge sort (tideman_sort) (SOV)

void tideman_sort(int i, int j, pair pair_example[], pair temp[])
{
    if (j <= i)
    {
        return;
    }

    int mid = (i + j) / 2;

    tideman_sort(i, mid, pairs, temp);
    tideman_sort(mid + 1, j, pairs, temp);

    int left_pointer = i;
    int right_pointer = mid + 1;

    for (int k = i; k < j + 1; k++) // [k] is the index of the start of array
    {
        int left_winner = pair_example[left_pointer].winner;
        int left_loser = pair_example[left_pointer].loser;
        int right_winner = pair_example[right_pointer].winner;
        int right_loser = pair_example[right_pointer].loser;

        if (left_pointer == mid + 1) // L array ends
        {
            temp[k] = pair_example[right_pointer];
            right_pointer++;
        }
        else if (right_pointer == j + 1) // R array ends
        {
            temp[k] = pair_example[left_pointer];
            left_pointer++;
        }
        else if (preferences[left_winner][left_loser] > preferences[right_winner][right_loser])
        {
            temp[k] = pair_example[left_pointer];
            left_pointer++;
        }
        else
        {
            temp[k] = pair_example[right_pointer];
            right_pointer++;
        }
    }

    for (int k = i; k < j + 1; k++)
    {
        pair_example[k] = temp[k];
    }
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    pair temp[pair_count];
    tideman_sort(0, pair_count - 1, pairs, temp);
    return;
}

bool has_cycle(int cycle_start, int cycle_end)
{
    if (locked[cycle_end][cycle_start]) //create base case
    {
        return true;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[cycle_end][i] == true && has_cycle(cycle_start, i)) // create a cycle
        {
            return true;
        }
    }
    return false;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        if (!has_cycle(pairs[i].winner, pairs[i].loser))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
}
// Print the winner of the election

void print_winner(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        int false_count = 0;
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i] == false)
            {
                false_count++;
                if (false_count == candidate_count)
                {
                    printf("%s\n", candidates[i]);
                }
            }
        }
    }
    return; 
}