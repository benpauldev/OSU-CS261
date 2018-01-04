#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "circularList.h"

// Double link
struct Link
{
	TYPE value;
	struct Link * next;
	struct Link * prev;
};

struct CircularList
{
	int size;
	struct Link* sentinel;
};

/**
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinel's next and prev should point to the sentinel itself.
 */
static void init(struct CircularList* list)
{
    assert(list != 0);
    
    
    list->sentinel = (struct Link*) malloc(sizeof(struct Link));
    
    assert(list->sentinel != 0);
    
    list->sentinel->next = list->sentinel;
    list->sentinel->prev = list->sentinel;
    
    list->size = 0;
}

/**
 * Creates a link with the given value and NULL next and prev pointers.
 */
static struct Link* createLink(TYPE value)
{
    struct Link* newLink = (struct Link*) malloc(sizeof(struct Link));
    assert(newLink != 0);
    
   
    newLink->value = value;
    
    return newLink;
}

/**
 * Adds a new link with the given value after the given link and
 * increments the list's size.
 */
static void addLinkAfter(struct CircularList* list, struct Link* link, TYPE value)
{
	assert((list != NULL) && (list != 0));
    assert(link != NULL);
    
    struct Link* newLink = createLink(value);
    
    newLink->next = link->next;
    
    newLink->prev = link;
    
    link->next->prev = newLink;
    
    link->next = newLink;
    
    list->size ++;
           
}

/**
 * Removes the given link from the list and
 * decrements the list's size.
 */
static void removeLink(struct CircularList* list, struct Link* link)
{
    assert(list != NULL);
    assert(!circularListIsEmpty(list));
    
    struct Link *position;
    
   position = list->sentinel;
    
    while (position->next != link)
    {
        position = position->next;
    }
    
    position->next = link->next;
    
    
   if(link != 0)
   {
       free(link);
   }
    
    list->size--;
}

/**
 * Allocates and initializes a list.
 */
struct CircularList* circularListCreate()
{
	struct CircularList* list = malloc(sizeof(struct CircularList));
	init(list);
	return list;
}

/**
 * Deallocates every link in the list and frees the list pointer.
 */
void circularListDestroy(struct CircularList* list)
{
   while(!circularListIsEmpty(list))
   {
       circularListRemoveFront(list);
   }

    free(list->sentinel);
    
}

/**
 * Adds a new link with the given value to the front of the deque.
 */
void circularListAddFront(struct CircularList* list, TYPE value)
{
    assert(list != 0);
    
    addLinkAfter(list, list->sentinel, value);
}

/**
 * Adds a new link with the given value to the back of the deque.
 */
void circularListAddBack(struct CircularList* list, TYPE value)
{
    assert(list != 0);
    
    addLinkAfter(list, list->sentinel->prev, value);
    

}


/**
 * Returns the value of the link at the front of the deque.
 */
TYPE circularListFront(struct CircularList* list)
{
     assert((list->size != 0) && (list != 0));
    
    return list->sentinel->next->value;
	
}

/**
 * Returns the value of the link at the back of the deque.
 */
TYPE circularListBack(struct CircularList* list)
{
	assert((list->size != 0) && (list != 0));
    
    return list->sentinel->prev->value;
}

/**
 * Removes the link at the front of the deque.
 */
void circularListRemoveFront(struct CircularList* list)
{
    assert(list != NULL);
    
    assert(!circularListIsEmpty(list));

    
    removeLink(list, list->sentinel->next);
}

/**
 * Removes the link at the back of the deque.
 */
void circularListRemoveBack(struct CircularList* list)
{
    assert(list != NULL);
    
    assert(!circularListIsEmpty(list));
    
    removeLink(list, list->sentinel->prev);
}

/**
 * Returns 1 if the deque is empty and 0 otherwise.
 */
int circularListIsEmpty(struct CircularList* list)
{
    assert(list != NULL);
    
    if(list->size <= 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }}

/**
 * Prints the values of the links in the deque from front to back.
 */
void circularListPrint(struct CircularList* list)
{
    assert((list->size != 0) && (list != 0));
    
    struct Link* position = list->sentinel->next;
    
    int i = 0;
    
    while (i < list->size)
    {
        printf("%g\n", position->value);
        position = position->next;
        
        i++;
    }
}

/**
 * Reverses the deque.
 */
void circularListReverse(struct CircularList* list)
{
    struct Link *prev = NULL;
    
    struct Link *current = list->sentinel->next;
    
    struct Link *next;
    
    int i = 0;
    
    while (i < list->size) {
        next = current->next;
        
        current->next = prev;
        
        prev = current;
        
        current = next;
        
        i++;
    }
    
    list->sentinel->next = prev;

    
    
}














