/* CS261- Assignment 1 - Q.5*/
/* Name:Benjamin Fondell
 * Date:4/16/2017
 * Solution description: Prints a user input word in sticky cap letters. prints numbers normally if included.
 */

#include <stdio.h>
#include <stdlib.h>

const int SIZE = 100;

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
    return ch - 32;
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
    return ch + 32;
}

void sticky(char* word){
    /*Convert to sticky caps*/
    
    for (int i = 0; i < sizeof(word); i++)
    {
        if(i % 2 &&(word[i] >= 'A' && word[i] <= 'Z'))
        {
            word[i] = toLowerCase(word[i]);
        }
        else if(i%2 && (word[i] >= 'a' && word[i] <= 'z'))
        {
            word[i] = toUpperCase(word[i]);
        }
        
    }
}

int main(){
    /*Read word from the keyboard using scanf*/
    
    char word[SIZE];
    
    printf("Please enter a word: \n");
    scanf("%s",word);
    
    
    /*Call sticky*/
    
    sticky(word);
    
    /*Print the new word*/
    
    printf("%s\n",word);
    
    return 0;
}
