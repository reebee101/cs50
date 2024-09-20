#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

string encrypt (string messages,int keys);

int main(void)
{
    int key = get_int ("enter the key: ");
    string message = get_string ("enter your message: ");
    string encrypted = encrypt(message,key);

    printf("%s",encrypted);
    printf("\n");
}

string encrypt (string messages,int keys)
{
    for (int i=0; i<strlen(messages);i++)
    {
        if (isalpha(messages[i]) && isupper(messages[i]))
        {
            messages[i] = messages[i] - 'A';
            messages[i] = ((messages[i] + keys) % 26);
            messages[i]+='A';
        }
        else if (isalpha(messages[i]) && islower(messages[i]))
        {
            messages[i] = messages[i] - 'a';
            messages[i] = ((messages[i] + keys) % 26);
            messages[i]+='a';
        }
    }
    return messages;
}
