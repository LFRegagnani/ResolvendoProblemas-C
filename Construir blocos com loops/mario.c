#include <cs50.h>
#include <stdio.h>

int main(void)
{

    int hash = get_int("write a number to make a montain\n");

    while (hash < 1 || hash > 8) //verifica se o usuario inseriu o caractere correto
    {
        hash = get_int("write a number to make a montain\n");
    }


    int hash2 = 0;
    int vazio = hash;


    for (int a = 0; a < hash; a++)
    {
        hash2++;
        vazio--;

        for (int v = 0; v < vazio; v++)
        {
            printf(" ");
        }

        for (int b = 0; b < hash2; b++)
        {

            printf("#");
        }

        printf("  ");

        for (int b = 0; b < hash2; b++)
        {

            printf("#");

        }

        printf("\n");
    }

}