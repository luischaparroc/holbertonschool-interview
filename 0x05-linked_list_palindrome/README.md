# Linked list palindrome

Exercise to practice for interviews

## Context

### 0. Linked list palindrome

Write a function in C that checks if a singly linked list is a palindrome:

* Prototype: `int is_palindrome(listint_t **head);`
* Return: `0` if it is not a palindrome, `1` if it is a palindrome
* An empty list is considered a palindrome

```
$ cat 0-main.c
#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    listint_t *head;

    head = NULL;
    add_nodeint_end(&head, 1);
    add_nodeint_end(&head, 17);
    add_nodeint_end(&head, 972);
    add_nodeint_end(&head, 50);
    add_nodeint_end(&head, 98);
    add_nodeint_end(&head, 98);
    add_nodeint_end(&head, 50);
    add_nodeint_end(&head, 972);
    add_nodeint_end(&head, 17);
    add_nodeint_end(&head, 1);
    print_listint(head);

    if (is_palindrome(&head) == 1)
        printf("Linked list is a palindrome\n");
    else
        printf("Linked list is not a palindrome\n");

    free_listint(head);

    return (0);
}

$ gcc -Wall -Werror -Wextra -pedantic 0-main.c linked_lists.c 0-is_palindrome.c -o palindrome
$ ./palindrome
1
17
972
50
98
98
50
972
17
1
Linked list is a palindrome
$
```
