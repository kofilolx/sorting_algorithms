#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
/**
 * struct listint_s - Doubly linked list node
 * 
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
*/

typedef struct listint_s
{
    const int n;        /* Data*/
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

#endif