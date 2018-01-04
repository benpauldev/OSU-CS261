/*
 Author: Benjamin Fondell
 Project: CS261 Assignment 2 Part 3
 Due: 4/23/2017
 Description: Application using a stack to test bracket balance. 

*/

/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string 	
	pre: s is not null		
*/
char nextChar(char* s)
{
	static int i = -1;	
	char c;
	++i;	
	c = *s+i;
	if ( c == '\0' )
		return '\0';	
	else 
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string 	
	pre: s is not null	
	post:	
*/


/*
 
 **1**do-while loop passes through string calling nextChar to advance.
 
 **2**first three cases find opening brackets and push the corresponding closing brackets on stack.
   these are brackets "to be found".
  
 **3**three fall-through case statements find the closing brackets
   if the stack of "to be found" brackets is compared to the scanned char.
    if it is found it is popped off the stack. 
  
 **4*the do-while breaks at the end of the string, or if found to be unbalanced
 
 **5**final if statement checks if anything left on stack, if so test = 0 and string is unbalanced

 */
int isBalanced(char* s)
{
    
    int test = 1;
    char x;
    DynArr* stack = newDynArr(2);
    
    
    do                                     //**1**
    {
        x = nextChar(s);
        
        switch (x)
        {
            case '(':                       //**2**
                pushDynArr(stack, ')');
                break;
            
            case '{':
                pushDynArr(stack, '}');
                break;
            
            case '[':
                pushDynArr(stack, ']');
                break;
                
            case ')':                       //**3**
            case '}':
            case ']':
                
                
                if (topDynArr(stack) == x && !isEmptyDynArr(stack))
                {
                    popDynArr(stack);
                }
                else
                {
                    test = 0;
                }
                break;
                
            default:
               
                break;
                
        }
        
       
        
    } while (test && x != '\0');            //**4**
    
    if (!isEmptyDynArr(stack))              //**5**
    {
        test = 0;
    }
    
    deleteDynArr(stack);                    //free memory
    return test;
}

int main(int argc, char* argv[]){
	
	char* s=argv[1];	
	int res;
	
	printf("Assignment 2\n");

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n",s);
	else 
		printf("The string %s is not balanced\n",s);
	
	return 0;	
}

