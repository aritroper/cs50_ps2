#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

/*
Returns char rotated key amount of times.
*/
int cipher(int key, int plainChar)
{
    //gets # rotations
    int rotations = key - 65;
    //adds key to ASCII value of character
    int cipherChar = plainChar + rotations;
    //check to see if character should "wrap around" i.e. z --> a
    if ((plainChar <= 90 && cipherChar > 90) || (plainChar >= 97 && cipherChar > 122))
    {
        cipherChar = cipherChar - 26;
    }
    return cipherChar;
}
int main(int argc,  char *argv[])
{
    string keyString = argv[1];
    //checks to make sure there is only 1 argument
    if (argc != 2)
    {
        printf("Please input one arg into the command line.");
        return 1;
    }
    //checks that key is only alphabetical
    else
    {
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            string str = argv[1];
            if (!isalpha(str[i]))
            {
                printf("Invalid key.");
                return 1;
            }
        }
    }

    //gets user information
    string plainText = get_string("plaintext: ");
    int nonLetters = 0;
    printf("ciphertext: ");

    for (int i = 0; i < strlen(plainText); i++)
    {
        //does not "rotate" for characters that are not letters
        if (plainText[i] >= 32 && plainText[i] <= 64)
        {
            printf("%c", plainText[i]);
            nonLetters++;
        }
        else
        {
            //rotate char and print
            int charASCII = plainText[i];
            int charKeyASCII = 0;
            if (i >= strlen(keyString))
            {
                charKeyASCII = keyString[((i - nonLetters) % strlen(keyString))];
            }
            else
            {
                charKeyASCII = keyString[(i - nonLetters)];
            }
            //lowecase to uppercasestyle50 vigenere.c
            if (charKeyASCII > 90)
            {
                charKeyASCII -= 32;
            }
            printf("%c", cipher(charKeyASCII, charASCII));
        }
    }

    printf("\n");

    return 0;
}