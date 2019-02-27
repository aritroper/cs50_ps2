#include <stdio.h>
#include <cs50.h>
#include <string.h>

/*
Returns char rotated key amount of times.
If key is more than 26, returns char rotated key mod 26 times.
*/
int cipher(int key, int plainChar)
{
    //adds key to ASCII value of character
    int cipherChar = plainChar + key;
    //check to see if character should "wrap around" i.e. z --> a
    if ((plainChar <= 90 && cipherChar > 90) || (plainChar >= 97 && cipherChar > 122))
    {
        cipherChar = cipherChar - 26;
    }
    return cipherChar;
}
int main(int argc,  char *argv[])
{
    //checks to make sure there is only 1 argument
    if (argc != 2)
    {
        printf("Please input one arg into the command line.");
        return 1;
    }

    //gets user information
    string plainText = get_string("plaintext: ");
    printf("ciphertext: ");

    for (int i = 0; i < strlen(plainText); i++)
    {
        //does not "rotate" for characters that are not letters
        if (plainText[i] >= 32 && plainText[i] <= 64)
        {
            printf("%c", plainText[i]);
        }
        else
        {
            //rotate char and print
            int charASCII = plainText[i];
            printf("%c", cipher(atoi(argv[1]) % 26, charASCII));
        }
    }

    printf("\n");

    return 0;
}