#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
          string name = get_string("enter name of image: ");
          return 1;
    }

    FILE *file = fopen(argv[1],"r");
    if (file == NULL)
    {
      printf("Could not open file.\n");
      return 1;
    }

    FILE *dst = fopen("new.jpg", "w");
    if (dst == NULL)
    {
      fclose(file);
      printf("Could not create file.\n");
      return 1;
    }

    unsigned char buffer[512];

    while (fread(buffer, sizeof(buffer), 1,file) !=0 )
    {
      fwrite(buffer ,sizeof(buffer), 1, dst);
    }

    fclose(dst);
    fclose(file);
}
