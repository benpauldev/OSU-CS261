/* CS261- Assignment 1 - Q.4*/
/* Name:Benjamin Fondell
 * Date:4/16/2017
 * Solution description: Sorts an array of students by their randomly generated test scores. Highest to Lowest.
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
     /*Sort the n students based on their score*/
    
    if (n == 0)
    {
        printf("error, no students in array \n");
        exit(0);
    }
    
    for (int i = 0; i < n; i++)
    {
        int pos = i;
        int minpos = i;
        
        for (int j =pos; j < n; j++)
        {
            if (students[minpos].score == students[j].score || students[minpos].score > students[j].score)
            {
                continue;
            }
            else minpos = j;
        }
        if(minpos != pos)
        {
            struct student temp;
            
            temp = students[pos];
            students[pos] = students[minpos];
            students[minpos] = temp;
            
        }
    }
}


int main(){
    /*Declare an integer n and assign it a value.*/
    
    int n = 10;
    
    /*Allocate memory for n students using malloc.*/
    
    struct student* students = malloc(sizeof(struct student) * n);
    
    /*Generate random and unique IDs and random scores for the n students, using rand().*/
    
    for (int i =0; i<n; i++)
    {
        students[i].id = i + 1;
        students[i].score = (rand() % 101);
    }
    
    /*Print the contents of the array of n students.*/
    
    for (int i =0; i < n; i++)
    {
        printf("ID :%d Score: %d\n",students[i].id,students[i].score);
    }

    /*Pass this array along with n to the sort() function*/
    
    sort(students, n);
    
    /*Print the contents of the array of n students.*/
    
    printf("After Sort \n");
    
    
    for (int i = 0; i < n; i++)
    {
          printf("ID :%d Score: %d\n",students[i].id,students[i].score);
    }
    
    free(students);
    
    return 0;
}
