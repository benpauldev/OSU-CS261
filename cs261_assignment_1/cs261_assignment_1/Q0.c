/* CS261- Assignment 1 - Q. 0*/
/* Name: Benjamin Fondell
 * Date: 4/16/2017
 * Solution description: Follows the forms of a pointer. Printing address, value, and value's address. 
 */
 
#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
     /*Print the value pointed to by iptr*/
    
    printf("The value at iptr: %i\n",*iptr);
    
    /*Print the address pointed to by iptr*/
    
    printf("The address pointed to by iptr: %p\n",iptr);
     
     /*Print the address of iptr itself*/
    
    printf("The address of iptr itself: %p\n",&iptr);
}

int main(){
    
    int x = 10;
    
    printf("Address of x    :%p\n",&x);
    
    fooA(&x);
    
    printf("Value of x   :%i\n",x);
    
    return 0;
}
