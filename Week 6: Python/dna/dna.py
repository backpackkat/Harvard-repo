from sys import argv
from csv import reader

# import csv

if len(argv) != 3:
    print(f"Usage: {argv[0]} Database_File_Name Sequences_File_Name")
    exit(1)
with open(argv[1], "r") as csvfile:
    reader = list(reader(csvfile))

# remove headers

    reader[0].remove("name")
    main_work = reader[0]

# open the file and read it

with open(argv[2], "r") as csvsequence:
    dnadata = csvsequence.read()
str_list = []
for helper in range(len(main_work)):
    max_str_count = 0
    str_count = 0
    position = 0
    previous_position = 0
    while position < len(dnadata):
        position = dnadata.find(main_work[helper], position)
        if position == -1:
            str_count = 0
            break
        elif position != -1 and previous_position == 0:
            str_count += 1
            max_str_count = str_count
            previous_position = position
        elif position != -1 and (position - len(main_work[helper])) == previous_position:
            str_count += 1
            previous_position = position
            if str_count > max_str_count:
                max_str_count = str_count
        elif position != -1 and (position - len(main_work[helper])) != previous_position:
            str_count = 1
            previous_position = position
            if str_count > max_str_count:
                max_str_count = str_count
        position += 1
    str_list.append(max_str_count)
str_list = list(map(str, str_list))
s = list(reader)
s.pop(0)
for person in s:
    if person[1:] == str_list:

        #  print correct person

        print(f"{person[0]}")
        break
    elif person == s[-1]:

        #  print No match

        print("No match")