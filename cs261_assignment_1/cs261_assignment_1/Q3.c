/* CS261- Assignment 1 - Q.3*/
/* Name:Benjamin Fondell
 * Date:4/16/2017
 * Solution description: Sorts an array of 20 random numbers.
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>


void sort(int* number, int n){
     /*Sort the given array number , of length n*/
    
    if (n == 0)
    {
        printf("error, no numbers in array \n");
        exit(0);
    }
    
    for (int i = 0; i < n; i++)
    {
        int pos = i;
        int minpos = i;
        
        for (int j =pos; j < n; j++)
        {
            if (number[minpos] == number[j] || number[minpos] < number[j])
            {
                continue;
            }
            else minpos = j;
        }
        if(minpos != pos)
        {
            int temp;
            
            temp = number[pos];
            number[pos] = number[minpos];
            number[minpos] = temp;
            
        }
    }
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
    
    int n = 20;
    
    /*Allocate memory for an array of n integers using malloc.*/
    
    int* numbers = malloc(sizeof(int) * n);
    
    /*Fill this array with random numbers, using rand().*/
    
    for (int i = 0; i < n; i++)
    {
        numbers[i] = rand();
    }
    
    /*Print the contents of the array.*/
    
    printf("Before Sort \n");
    
    for (int i = 0; i < 20; i++)
    {
        printf("%d \n",numbers[i]);
    }

    /*Pass this array along with n to the sort() function of part a.*/
    
    sort(numbers, n);
    
    printf("After Sort \n");
    
    /*Print the contents of the array.*/
    
    for (int i = 0; i < n; i++)
    {
        printf("%d \n",numbers[i]);
    }
    
    free(numbers);
    
    return 0;
}
