---
files: [marioless.c]
window: [terminal]
---

# Problem Set 1: Mario (Less)

-- Toward the beginning of World 1-1 in Nintendo’s Super Mario Brothers, Mario must hop over right-aligned pyramids of blocks, per the below.
Recreate those pyramids in C, albeit in text, using hashes (#) for bricks, a la the below. Each hash is a bit taller than it is wide, so the pyramids themselves will also be taller than they are wide. --
```
       #
      ##
     ###
    ####
   #####
  ######
 #######
########
```
The program will be called mario. Allow the user to decide just how tall the pyramids should be by first prompting them for a positive integer between, say, 1 and 8, inclusive.

Here’s how the program might work if the user inputs 8 when prompted:
```
$ ./mario
Height: 8
       #
      ##
     ###
    ####
   #####
  ######
 #######
########
```
Here’s how the program might work if the user inputs 4 when prompted:
```
$ ./mario
Height: 4
   #
  ##
 ###
####
```
Here’s how the program might work if the user inputs 2 when prompted:
```
$ ./mario
Height: 2
 #
##
```
And here’s how the program might work if the user inputs 1 when prompted:
```
$ ./mario
Height: 1
#
```
If the user doesn’t, in fact, input a positive integer between 1 and 8, inclusive, when prompted, the program should re-prompt the user until they cooperate:
```
$ ./mario
Height: -1
Height: 0
Height: 42
Height: 50
Height: 4
   #
  ##
 ###
####
```
## Testing
Does your code work as prescribed when you input:

- `-1` (or other negative numbers)?
- `0`?
- `1` through `8`?
- `9` or other positive numbers?
- letters or words?
- no input at all, when you only hit Enter?
