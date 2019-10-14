#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

char digital(string s); // checking whether a string has all digits in it starting from 0-9
void msg(void);         // message prompting the user for correct format
void cipher(int t ,string s); // printing out the cipher code of the provided string 

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        msg();
        return 1;
    }
    
    if (argc == 2)
    {  
        char y = digital(argv[1]);
        
        if (y!='Y')
        {
            msg();
            return 1;
        }
       
    }
    
    int t = atoi(argv[1]);
    string text = get_string("plaintext :");
    printf("ciphertext:");
    cipher(t, text);
    printf("\n");
    
}

void msg()
{
    printf("Usage : ./caesar key\n");
}

char digital(string s)
{
    int l = 0;
    
    while(s[l]!='\0')
    {
        if (s[l] < '0' || s[l] > '9')
        {
            return 'N'; // is means of telling that it's not a string with all digital values in it 
        }
        
        l++;
    }
    
    return 'Y'; // if Y is returned then all the values in the string are digits 
        
}

void cipher(int t, string s)
{
    int l = strlen(s);
    int val;
    
    for (int i = 0 ; i < l; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            val = ((s[i] + t - 'a') % 26) + 'a';
            printf("%c", val);            
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            val = ((s[i] + t - 'A') % 26) + 'A';
            printf("%c", val);    
        }
        else
        {
            printf("%c", s[i]);
        }
    }
}
