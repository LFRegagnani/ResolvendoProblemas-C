#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{

    string texto = get_string("Escreva o texto a ser avaliado\n");

    double numeroDeLetras = 0;
    double numeroDePalavras = 1; // começa com 1 pq a ultima palavra do texto geralmente só tem ponto no fim e não tem espaço.
    double numeroDeFrases = 0;

    for (int i = 0; i < strlen(texto); i++)
    {
        char caractere = texto[i];

        if (caractere == 'a' || caractere == 'A' || caractere == 'b' || caractere == 'B' || caractere == 'c' || caractere == 'C'
            || caractere == 'd' || caractere == 'D'
            || caractere == 'e' || caractere == 'E' || caractere == 'f' || caractere == 'F' || caractere == 'g' || caractere == 'G'
            || caractere == 'h' || caractere == 'H'
            || caractere == 'i' || caractere == 'I' || caractere == 'j' || caractere == 'J' || caractere == 'k' || caractere == 'K'
            || caractere == 'l' || caractere == 'L'
            || caractere == 'm' || caractere == 'M' || caractere == 'n' || caractere == 'N' || caractere == 'o' || caractere == 'O'
            || caractere == 'p' || caractere == 'P'
            || caractere == 'q' || caractere == 'Q' || caractere == 'r' || caractere == 'R' || caractere == 's' || caractere == 'S'
            || caractere == 't' || caractere == 'T'
            || caractere == 'u' || caractere == 'U' || caractere == 'v' || caractere == 'V' || caractere == 'w' || caractere == 'W'
            || caractere == 'x' || caractere == 'X'
            || caractere == 'y' || caractere == 'Y' || caractere == 'z' || caractere == 'Z' || caractere == '-')
        {
            numeroDeLetras++;
        }
        else if (caractere == 32)//32 é o espaço na tabela ASCII
        {
            numeroDePalavras++;
        }
        else if (caractere == '.' || caractere == '!' || caractere == '?')
        {
            numeroDeFrases++;

        }

    }

    double letrasPorPalavras = (numeroDeLetras / numeroDePalavras) * 100;
    double palavrasPorFrases = (numeroDeFrases / numeroDePalavras) * 100;
    double indice = 0.0588 * letrasPorPalavras - 0.296 * palavrasPorFrases - 15.8;


    if (indice <= 15 && indice >= 1)
    {
        printf("Grade %i\n", (int)round(indice)); //arredondando para obter o resultado esperado
    }
    else if (indice >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }

}