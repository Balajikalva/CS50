#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include<ctype.h>
//this problem needs the knowledge object orientation programming with creating a data structure 
// or  something of the kind like hashing . Will comeback to this later when done.

int find(char a);
bool check( string s);
bool number(string s);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage : ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else
    {
        if (number( argv[1] ) == false)
        {
            printf("Key must only contain alhabetic characters.\n");
            return 1;
        }
    }
    
    if (check( argv[1]) == false)
    {
        printf("Key must not contain repeated characters.\n");
        return 1;
    }
    
    string text = get_string("plaintext : ");
    printf("ciphertext: ");
    
    for (int i = 0, l = strlen(text); i < l ; i++)
    {
        int index = find(text[i]);
        
        if (index == -1)
        {
            printf("%c", text[i]);
        }
        else
        {
            if (isupper(text[i]))
            {
                printf("%c", argv[1][index]);
            }
            else
            {
                printf("%c", tolower(argv[1][index]));
            }
        }
        
    }
    
    printf("\n");
}

int find(char a)
{
    string normal = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    int k = 0;
    
    while (normal[k] != '\0')
    {
        if (normal[k] == toupper(a))
        {
            return k;
        }
        
        k++;
    }
    
    return -1;
}


bool check( string s)
{
    int array[255] = {0};
    
    for (int i = 0, l = strlen(s) ; i < l ; i++)
    {
        if( isalpha( s[i]))
        {
            if (array[ (int) tolower(s[i]) ]== 1)
            {
                return false;
            }
            
            array[ (int) tolower(s[i]) ] = 1; 
        }
        else
        {
            return false;
        }
    }
    return true;
}

bool number(string s)
{
    int k = 0;
    
    while (s[k] != '\0')
    {
        if ( isalpha( s[k] ) == false)
        {
            return false;
        }
        
        k++;
    }
   
    return true;
}
