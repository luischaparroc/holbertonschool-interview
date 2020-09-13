# Palindrome integer

Exercise to practice for interviews

## Context

### 0. Palindrome unsigned integer

Write a function that checks whether or not a given unsigned integer is a palindrome.

* Prototype: `int is_palindrome(unsigned long n);`
* Where `n` is the number to be checked
* The function must return `1` if `n` is a palindrome, and `0` otherwise

```
$ cat 0-main.c
#include <stdlib.h>
#include <stdio.h>

#include "palindrome.h"

/**
 * main - Entry point
 *
 * @ac: Arguments counter
 * @av: Arguments vector
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int ac, char **av)
{
    unsigned long n;
    int ret;

    if (ac < 2)
    {
        fprintf(stderr, "Usage: %s arg\n", av[0]);
        return (EXIT_FAILURE);
    }

    n = (unsigned long)(atol(av[1]));
    ret = is_palindrome(n);

    printf("%lu is ", n);
    if (ret == 0)
        printf("not ");
    printf("a palindrome.\n");

    return (EXIT_SUCCESS);
}

$ gcc -Wall -Wextra -Werror -pedantic -g3 -o palindrome 0-main.c 0-is_palindrome.c
$ ./palindrome 1
1 is a palindrome.
$ ./palindrome 11
11 is a palindrome.
$ ./palindrome 112
112 is not a palindrome.
$ ./palindrome 121
121 is a palindrome.
$ ./palindrome 12345678987654321
12345678987654321 is a palindrome.
$ ./palindrome 123456789987654321
123456789987654321 is a palindrome.
$ ./palindrome 1234567898654321
1234567898654321 is not a palindrome.
$
```
