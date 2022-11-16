#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if (score1 > score2)
    {
        printf("Player 1 wins!"); // Se a primeira string valr mais
    }
    else if (score1 == score2)
    {
        printf("Tie!");// se for empate
    }
    else
    {
        printf("Player 2 wins!");//se a segunda string valer mais
    }

}
//essa função vai calcular o valor das letras uma por uma e retornar o valor total da string.
int compute_score(string word)
{

    int total = 0;
//esse for gigante podia ser substituido por um loop eu acho.
    for (int i = 0; i < strlen(word); i++)
    {
        char letra =  word[i];

        if (letra == 'a' || letra == 'A')
        {
            total = total + POINTS[0];
        }
        else if (letra == 'b' || letra == 'B')
        {
            total = total + POINTS[1];
        }
        else if (letra == 'c' || letra == 'C')
        {
            total = total + POINTS[2];
        }
        else if (letra == 'd' || letra == 'D')
        {
            total = total + POINTS[3];
        }
        else if (letra == 'e' || letra == 'E')
        {
            total = total + POINTS[4];
        }
        else if (letra == 'f' || letra == 'F')
        {
            total = total + POINTS[5];
        }
        else if (letra == 'g' || letra == 'G')
        {
            total = total + POINTS[6];
        }
        else if (letra == 'h' || letra == 'G')
        {
            total = total + POINTS[7];
        }
        else if (letra == 'i' || letra == 'I')
        {
            total = total + POINTS[8];
        }
        else if (letra == 'j' || letra == 'J')
        {
            total = total + POINTS[9];
        }
        else if (letra == 'k' || letra == 'K')
        {
            total = total + POINTS[10];
        }
        else if (letra == 'l' || letra == 'L')
        {
            total = total + POINTS[11];
        }
        else if (letra == 'm' || letra == 'M')
        {
            total = total + POINTS[12];
        }
        else if (letra == 'n' || letra == 'N')
        {
            total = total + POINTS[13];
        }
        else if (letra == 'o' || letra == 'O')
        {
            total = total + POINTS[14];
        }
        else if (letra == 'p' || letra == 'P')
        {
            total = total + POINTS[15];
        }
        else if (letra == 'q' || letra == 'Q')
        {
            total = total + POINTS[16];
        }
        else if (letra == 'r' || letra == 'R')
        {
            total = total + POINTS[17];
        }
        else if (letra == 's' || letra == 'S')
        {
            total = total + POINTS[18];
        }
        else if (letra == 't' || letra == 'T')
        {
            total = total + POINTS[19];
        }
        else if (letra == 'u' || letra == 'U')
        {
            total = total + POINTS[20];
        }
        else if (letra == 'v' || letra == 'V')
        {
            total = total + POINTS[21];
        }
        else if (letra == 'w' || letra == 'W')
        {
            total = total + POINTS[22];
        }
        else if (letra == 'x' || letra == 'X')
        {
            total = total + POINTS[23];
        }
        else if (letra == 'y' || letra == 'Y')
        {
            total = total + POINTS[24];
        }
        else if (letra == 'z' || letra == 'Z')
        {
            total = total + POINTS[25];
        }
        else
        {
            total = total + 0;
        }

    }

    return total;//Todas as somas das letras individuais são reunidas aqui nesta variavel

}
