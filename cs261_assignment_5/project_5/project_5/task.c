/*
 * CS 261 Assignment 5
 * Name: Benjamin Fondell
 * Date: 5/26/2017
 */

#include "task.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * Creates a new task with the given priority and name.
 * @param priority
 * @param name
 * @return  The new task.
 */
Task* taskNew(int priority, char* name)
{
    Task *new = malloc(sizeof(Task));
    strcpy(new->name, name);
    new->priority = priority;
    
    return new;
}

/**
 * Frees a dynamically allocated task.
 * @param task
 */
void taskDelete(Task* task)
{
    free(task);
}

/**
 * Casts left and right to Task pointers and returns
 * -1 if left's priority < right's priority,
 *  1 if left's priority > right's priority,
 *  0 if left's priority == right's priority.
 * @param left  Task pointer.
 * @param right  Task pointer.
 * @return 
 */
int taskCompare(void* left, void* right)
{
    Task* leftChild = (Task*) left;
    Task* rightChild = (Task*) right;
    
    int compareValue = 0;
    
    if (leftChild->priority < rightChild->priority)
    {
        compareValue = -1;
    }
    else if( leftChild->priority > rightChild->priority)
    {
        compareValue = 1;
    }
    
    return compareValue;
}

/**
 * Prints a task as a (priority, name) pair.
 * @param value  Task pointer.
 */
void taskPrint(void* value)
{
    Task* task = (Task*)value;
    printf("(%d, %s)", task->priority, task->name);
}
