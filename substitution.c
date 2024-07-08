#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

void cipher(string text, string key);

int main(int argc, string argv[])
{
    if (argc!=2)
    {
        printf("Usage: ./substitution <key> \n");
        return 1;
    }

    string key=argv[1];
    int lenght=strlen(key);

    if (lenght!=26)
    {
       printf("The key must be 26 characters long \n");
        return 1;
    }

    for(int i=0; i<lenght; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("The key must be only alphabetical \n");
            return 1;
        }
        else
        {
            key[i]=toupper(key[i]);
        }
    }

    for(int i=0; i<lenght-1; i++)
    {
        for(int j=i+1; j<lenght; j++)
        {
            if(key[i]==key[j])
            {
                printf("Every character of the key must be unique \n");
                return 1;
            }
        }
    }

    string ptext= get_string("plaintext: ");

    cipher(ptext, key);

    return 0;
}

void cipher(string text, string key)
{
    int lenght=strlen(text);
    int index;

    for(int i=0; i<lenght; i++)
    {
        if(isalpha(text[i]))
        {
            if(isupper(text[i]))
            {
                index=text[i]-'A';

                text[i]=key[index];
            }
            else
            {
                index=text[i]-'a';

                text[i]=tolower(key[index]);
            }
        }
    }

    printf("ciphertext: %s\n", text);
}
