  ---
files: [hello.c]
window: [terminal]
---

# Problem Set 1: Hello

-- Implement a program that greets user based on user input in C - requires compilation.
```
#include <stdio.h>

int main(void)
{
    printf("hello, world\n");
}

```
## Specs
Suffice it to say, no matter how you compile or execute this program, it only ever prints `hello, world`. 
Challenge: Modify this program in such a way that it first prompts the user for their name and then prints hello, so-and-so, where so-and-so is their actual name (ie Hello, Kat).

As before, be sure to compile your program with:

```
make hello
```
And be sure to execute your program, testing it a few times with different inputs, with:
```
./hello
```
