
#include <stdio.h>
    
    
    int main(int argc, const char * argv[])
    {
        
        float measurement;
        float converted;
        char choice;
        
        printf("Enter I to convert to inches. Enter C to convert to centimeters. : \n");
        scanf("%c", &choice);
        
        printf("Enter measurement you would like to convert. : \n");
        scanf("%f",&measurement);
        
        switch (choice)
        {
            case 'I':
                converted = measurement * 0.39370079;
                printf("The length in Inches is %f \n", converted);
                break;
                
            case 'C':
                converted = measurement * 2.54;
                printf("The length in centimeters is %f \n",converted);
                break;
                
            default:
                printf("Please run the program again and enter the letter I or C. \n");
                break;
        }
        
        return 0;
    }

   

