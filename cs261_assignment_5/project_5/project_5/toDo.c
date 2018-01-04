/*
 * CS 261 Assignment 5
 * Name: Benjamin Fondell
 * Date: 5/26/2017
 */

#include "dynamicArray.h"
#include "task.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * Loads into heap a list from a file with lines formatted like
 * "priority, name".
 * @param heap
 * @param file
 */
void listLoad(DynamicArray* heap, FILE* file)
{
    const int FORMAT_LENGTH = 256;
    char format[FORMAT_LENGTH];
    snprintf(format, FORMAT_LENGTH, "%%d, %%%d[^\n]", TASK_NAME_SIZE);
    
    Task temp;
    while (fscanf(file, format, &temp.priority, &temp.name) == 2)
    {
        dyHeapAdd(heap, taskNew(temp.priority, temp.name), taskCompare);
    }
}

/**
 * Writes to a file all tasks in heap with lines formatted like
 * "priority, name".
 * @param heap
 * @param file
 */
void listSave(DynamicArray* heap, FILE* file)
{
    for (int i = 0; i < dySize(heap); i++)
    {
        Task* task = dyGet(heap, i);
        fprintf(file, "%d, %s\n", task->priority, task->name);
    }
}

/**
 * Prints every task in heap.
 * @param heap
 */
void listPrint(DynamicArray* heap)
{
    DynamicArray* temp = dyNew(1);
    dyCopy(heap, temp);
     while (dySize(temp) > 0)
    {
        Task* task = dyHeapGetMin(temp);
        printf("\n");
        taskPrint(task);
        printf("\n");
        dyHeapRemoveMin(temp, taskCompare);
    }
    dyDelete(temp);
}

/**
 * Handles the given command.
 * @param list
 * @param command
 */
void handleCommand(DynamicArray* list, char command)
{
    char *file = malloc(sizeof(char) * 256);
    char *description = malloc(sizeof(char) * 256);
    int priority;
    
    switch (command)
    {
        case 'l':
            
            printf("Please enter the file name: ");
            
            fgets(file, 100, stdin);
            
            if (file[strlen(file) - 1] == '\n')
            {
                file[strlen(file) -1 ] = 0;
            }
            
            FILE *reading = fopen(file, "r");
            listLoad(list, reading);
            printf("The list has been loaded from the file successfully. \n");
            fclose(reading);
            
            break;
            
        case 's':
            
            printf("Please enter the filename: ");
            fgets(file, 100, stdin);
           
            if (file[strlen(file) - 1] == '\n')
            {
                file[strlen(file) -1 ] = 0;
            }
            
            FILE *saving = fopen(file, "W+");
            listLoad(list, saving);
            printf("The list has been loaded from the file successfully. \n");
            fclose(saving);
            
            break;
            
        case 'a':
            
            printf("Please enter the task description: ");
            fgets(description, 100, stdin);
            
            if (description[strlen(description)] == '\n')
            {
                description[strlen(description)] = 0;
            }
            
            printf("Please enter the task priority (0-999): ");
            scanf("%d", &priority);
            
            while (getchar() != '\n');
            
            Task *task = taskNew(priority, description);
            dyHeapAdd(list, task, taskCompare);
            printf("The task '%s' has been added to the list. \n\n" , description);
            
            break;
            
        case 'g':
            
            if (dySize(list) != 0)
            {
                printf("Your first task is: %s \n\n ", ((struct Task* ) dyHeapGetMin(list))->name);
                
            }
            else
            {
                printf("Your list is empty!\n\n");
            }
            
            break;
            
        case 'r':
            
            if (dySize(list) == 0)
            {
                 printf("Your list is empty!\n\n");
            }
            else
            {
                struct Task* task = (struct Task*)dyHeapGetMin(list);
                printf("Your first task, '%s', has been removed. \n\n", task->name);
                
                dyHeapRemoveMin(list, taskCompare);
                taskDelete(task);
            }
            
            break;
           
        case 'p':
            
            if (dySize(list) == 0)
            {
                printf("Your list is empty!\n\n");
            }
            else
            {
                listPrint(list);
            }
            
            break;
        
        case 'e':
            
            printf("Bye! \n\n");
            break;
    }
    
    free(description);
    free(file);
}

int main()
{
    // Implement
    printf("\n\n** TO-DO LIST APPLICATION **\n\n");
    DynamicArray* list = dyNew(8);
    char command = ' ';
    do
    {
        printf("Press:\n"
               "'l' to load to-do list from a file\n"
               "'s' to save to-do list to a file\n"
               "'a' to add a new task\n"
               "'g' to get the first task\n"
               "'r' to remove the first task\n"
               "'p' to print the list\n"
               "'e' to exit the program\n"
        );
        command = getchar();
        // Eat newlines
        while (getchar() != '\n');
        handleCommand(list, command);
    }
    while (command != 'e');
 /* free dynamically allocated List pointers in array to avoid memory leaks */
         /* Fix it */

    dyDelete(list);
    return 0;
}
