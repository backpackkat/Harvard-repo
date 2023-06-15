from cs50 import get_int
# Prompt user for height:

height = 0
while height > 8 or height < 1:
    height = get_int("Please enter height: ")

# Loop through rows and then columns in order to know what to print below:
for i in range(1, height + 1):
    for j in range(1, height + 1):

        # Start printing #'s after correct number of spaces
        if j > (height - i):
            print("#", end="")
        else:
            print(" ", end="")

        # Print remaining #'s & centre space
        if j == height:
            print(" ", "#" * i, end="")
    print()