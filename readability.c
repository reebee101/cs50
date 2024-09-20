#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int letters(string sentence);
int words(string sentence);
int sentences(string sentence);

int main(void)
{
    string sentence = get_string("enter your string: ");

    int letter = letters(sentence);
    int word = words(sentence);
    int sent = sentences(sentence);

    float l = (float) letter / word * 100;
    float s = (float) sent / word * 100;

    float index = 0.0588 * l - 0.296 * s - 15.8;

    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %f\n", index);
    }
}

int letters(string sentence)
{
    int count=0;

    for (int i=0;i<strlen(sentence);i++)
    {
        if(isalpha(sentence[i]))
        {
            count++;
        }
    }

    return count;
}

int words(string sentence)
{
    int count = 0;
    for (int i = 0; i<strlen(sentence); i++)
    {
      if (sentence[i] == ' ')
      {
        count++;
      }
    }
   return count + 1;
}

int sentences(string sentence)
{
    int count = 0;
    for (int i = 0; i<strlen(sentence); i++)
    {
      if (sentence[i] == '!' || sentence[i] == '?' || sentence[i] == '.')
      {
        count++;
      }
    }
   return count;
}
