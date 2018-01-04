/* CS261- Assignment 1 - Q.1*/
/* Name:Benjamin Fondell
 * Date:4/16/2017
 * Solution description: creates an array of type student. Assigns random scores and id numbers. prints students information
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

const int tenstudents = 10;

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
    
    struct student* students = malloc(sizeof(struct student)*tenstudents);
     
     /*return the pointer*/
    
    return students;
}
int getRandom(int min, int max)      //function for generating random score
{
    int range = max - min + 1;
    return ((rand() % range) + min);
}

void generate(struct student* students){
     /*Generate random and unique ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
    
    for (int i =0; i<tenstudents; i++)
    {
        students[i].id = i + 1;
        students[i].score = getRandom(0,100);
    }
    
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
    for (int i = 0; i < tenstudents; i++)
    {
        printf("%i %i\n",students[i].id, students[i].score);
    }
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
    int sum = 0;
    float average = 0;
    int minscore = -1;
    int maxscore = 0;
    
    for (int i = 0; i < tenstudents; i++)
    {
        sum = sum + students[i].score;
        
        if (minscore > students[i].score || minscore == -1)
        {
            minscore = students[i].score;
            
        }
        if (students[i].score > maxscore)
        {
            maxscore = students[i].score;
        }
        
    }
    
    average = sum / tenstudents;
    
    printf("Average: %f \n", average);
    printf("Minimum: %d \n", minscore);
    printf("Maximum: %d \n", maxscore);
    
}

void deallocate(struct student* stud)
{
     /*Deallocate memory from stud*/
    if (sizeof(stud)==0)
    {
        return;
    }
    free(stud);
    
}


int main(){
    struct student* stud = NULL;
    
    /*call allocate*/
    
    stud = allocate();
    
    /*call generate*/
    
    generate(stud);
    
    /*call output*/
    
    output(stud);
    
    /*call summary*/
    
    summary(stud);
    
    /*call deallocate*/
    
    deallocate(stud);

    return 0;
}
