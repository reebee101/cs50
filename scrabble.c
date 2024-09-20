#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int calculate_score(string word);

int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 8, 4, 10};

int main(void)
{
    //input the words from user
    string player1 = get_string("what is your word? ");
    string player2 = get_string("what is your word? ");

    //calculate the score of each word
    int score1 = calculate_score(player1);
    int score2 = calculate_score(player2);

    //compare the scores
    if (score1 > score2)
       {printf("the winner is: player1");}

    else if (score2 > score1)
        {printf("the winner is: player2");}

    else
        {printf("tie");}

        printf("\n");
}

int calculate_score(string word) //calculates the score of each word
{
    int len = strlen(word);
    int score = 0;

    for (int i = 0; i < len; i++)
    {
        if (isupper(word[i])) //for upper case letters
        {
            score += points[word[i] - 'A'];
        }
        else //for lower case letters
        {
            score += points[word[i] - 'a'];
        }
    }

    return score;
}
