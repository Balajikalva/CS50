#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main()
{
    string text = get_string("text :");
    int w = 1; 
    int l = 0;
    int s = 0;
    
    for (int i = 0 , n = strlen(text) ; i < n ; i++)
    {   
        if (text[i] == ' ')
        {
            w++;
        } 
        else if (text[i] == '!' || text[i] == '?' || text[i] == '.')
        {
            s++;
        }
        else if (isalpha(text[i]))
        {
            //printf("%c",text[i]);
            l++;
        }
    }
    
   // printf("\nwords : %d , sentences : %d and  letters : %d \n",w,s,l);
    
    float L,S,index;
    L = ((float) l / w) * 100;
    S = ((float) s / w) * 100;
    index = 0.0588 * L - 0.296 * S - 15.8;
    
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index < 16)
    {
        printf("Grade %.0f\n",index);
    }
    else
    {
        printf("Grade 16+\n");
    }
    
   // printf("\nL and S are : %f  %f\n",L,S);
    
}
