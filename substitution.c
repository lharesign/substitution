#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc == 2 && strlen(argv[1]) == 26) //checking for one command line arguement containing 26 chars
    {
        int alphabet_length = 26;
        char key_array[alphabet_length]; //creating an array the length of 26
        for (int i = 0; i < alphabet_length; i++)
        {
            if (!isalpha(argv[1][i])) //rejects if anything other than alphabetic chars
            {
                printf("Usage: ./substitution key\n");
                return 1;
            }
            else
            {
                key_array[i] = tolower(argv[1][i]);
                for (int j = 0; j < i; j++)
                {
                    if (key_array[j] == key_array[i]) //rejects if two chars are the same
                    {
                        printf("Usage: ./substitution key\n");
                        return 1;
                    }
                }
            }
        }
        string plaintext = get_string("plaintext: "); //requesting plaintext from user
        int plaintext_length = strlen(plaintext);
        for (int k = 0; k < plaintext_length; k++)
        {
            if (isalpha(plaintext[k])) //checking if plaintext[i] is a letter
            {
                if (isupper(plaintext[k])) //if a letter, checking if upper
                {
                    plaintext[k] = toupper(key_array[(plaintext[k] - 65)]); //converting from ascii to equivalent in key_array
                }
                else if (islower(plaintext[k])) //if a letter, checking if lower
                {
                    plaintext[k] = key_array[(plaintext[k] - 97)]; //converting from ascii to equivalent in key_array
                }
            }
            else //if not a letter, returning it as it was
            {
                plaintext[k] = plaintext[k];
            }
        }
        printf("ciphertext: %s\n", plaintext); //returning plaintext as ciphertext
    }
    else
    {
        printf("Usage: ./substitution key\n"); //if command line argument not met, returns error and exits
        return 1;
    }
    return 0;
}
