#include <cs50.h>
#include <stdio.h>

int main (void)
{
int rows = get_int("how many rows? ");
int i = 1;
int j=1;
while (i<=rows)
{
    j=1;
    while (j<=i)
       {
            printf("#");
            j++;
        }
        printf("\n");
        i++;
}
}
