#include <stdio.h>
#include <cs50.h>
int change;

int calculate_quart(int cent);

int main(void)
{
    do
      {
        change = get_int("change owned: ");
      }
    while (change<1);

    int quarts=calculate_quart(change);
    change = change - (quarts*25);
    printf("%i",quarts);
    printf("\n");

}

int calculate_quart(int cent)
{
    int quart=0;
    while (change>=25)
    {
        quart++;
        change = change-25;
    }
    return quart;
}
