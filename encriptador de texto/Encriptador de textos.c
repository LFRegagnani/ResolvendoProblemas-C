#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{

    bool chaveValida = false;
    string chave = argv[1];
    char chaveEmChar[26];
    string textoSecreto;
    string codigoDecifrado;

    if (argc != 2)
    {
        printf("Erro: O codigo NÃO foi digitado no formato correto.\n" "O código tem que conter 26 letras não repetidas.\n"
               "O formato correto é ./substitution DigiteAChaveAqui\n");
        return 1;
    }


    if (strlen(chave) != 26)
    {

        printf("Erro: O codigo NÃO foi digitado no formato correto.\n" "O código tem que conter 26 letras não repetidas.\n"
               "O formato correto é ./substitution DigiteAChaveAqui\n");
        return 1;
    }

    for (int i = 0; i <= 25; i++)//verifica se o codigo só contem letras
    {
        char caractere = chave[i];

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
            || caractere == 'y' || caractere == 'Y' || caractere == 'z' || caractere == 'Z')
        {
            chaveEmChar[i] = chave[i];
        }
        else
        {
            printf("Erro: Nem tudo que foi digitado é um caracter valido\n");
            return 1;
        }

    }



    int b = 0;// quando chegar em 26 acaba a validação
    for (int a = 0; a < 26; a++) // Esse loop verifica se tem letra repetido, se não tiver, valida o codigo
    {

        if (chave[a] == chave[b])
        {
            if (a == b)
            {
                //ignore pq é a mesma letra
            }
            else
            {
                printf("Erro: Letra repetida na chave\n");
                return 1;
            }

            // se chave[a] != [b] só ignora
        }
        if (a == 25 && b < 26)
        {
            a = 0;
            b++;
        }
        else
        {
            chaveValida = true;
        }
    }



    textoSecreto = get_string("Insira o texto a ser descriptografado\n");
    int tamanhoDoSegredo = strlen(textoSecreto);

    char alfabetoMinusculo[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char alfabetoMaiusculo[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};



    char chaveEmCharMaiusculo[26] = {toupper(chaveEmChar[0]), toupper(chaveEmChar[1]), toupper(chaveEmChar[2]), toupper(chaveEmChar[3]), toupper(chaveEmChar[4]), toupper(chaveEmChar[5]),
                                     toupper(chaveEmChar[6]),  toupper(chaveEmChar[7]),  toupper(chaveEmChar[8]), toupper(chaveEmChar[9]),  toupper(chaveEmChar[10]),  toupper(chaveEmChar[11]),
                                     toupper(chaveEmChar[12]),  toupper(chaveEmChar[13]),  toupper(chaveEmChar[14]),  toupper(chaveEmChar[15]), toupper(chaveEmChar[16]),  toupper(chaveEmChar[17]),
                                     toupper(chaveEmChar[18]),  toupper(chaveEmChar[19]), toupper(chaveEmChar[20]),  toupper(chaveEmChar[21]),  toupper(chaveEmChar[22]),  toupper(chaveEmChar[23]),
                                     toupper(chaveEmChar[24]),  toupper(chaveEmChar[25])
                                    };

    char chaveEmCharMinusculo[26] = {tolower(chaveEmChar[0]), tolower(chaveEmChar[1]), tolower(chaveEmChar[2]), tolower(chaveEmChar[3]), tolower(chaveEmChar[4]), tolower(chaveEmChar[5]),
                                     tolower(chaveEmChar[6]),  tolower(chaveEmChar[7]),  tolower(chaveEmChar[8]), tolower(chaveEmChar[9]),  tolower(chaveEmChar[10]),  tolower(chaveEmChar[11]),
                                     tolower(chaveEmChar[12]),  tolower(chaveEmChar[13]),  tolower(chaveEmChar[14]),  tolower(chaveEmChar[15]), tolower(chaveEmChar[16]),  tolower(chaveEmChar[17]),
                                     tolower(chaveEmChar[18]),  tolower(chaveEmChar[19]), tolower(chaveEmChar[20]),  tolower(chaveEmChar[21]),  tolower(chaveEmChar[22]),  tolower(chaveEmChar[23]),
                                     tolower(chaveEmChar[24]),  tolower(chaveEmChar[25])
                                    };

    printf("ciphertext: ");
//printf("%s",textoSecreto);

    for (int i = 0; i < tamanhoDoSegredo; i++)
    {
        for (int p = 0; p < 26; p++)
        {
            if (textoSecreto[i] == alfabetoMinusculo[p])
            {
                printf("%c", chaveEmCharMinusculo[p]);
                i++;
                p = -1;

            }
            else if (textoSecreto[i] == alfabetoMaiusculo[p])
            {

                printf("%c", chaveEmCharMaiusculo[p]);
                i++;
                p = 0;
            }
            else if (textoSecreto[i] == '0')
            {
                printf("%c", 48);
                i++;
                p = 0;
            }
            else if (textoSecreto[i] == '1')
            {
                printf("%c", 49);
                i++;
                p = 0;
            }
            else if (textoSecreto[i] == '2')
            {
                printf("%c", 50);
                i++;
                p = 0;
            }
            else if (textoSecreto[i] == '3')
            {
                printf("%c", 51);
                i++;
                p = 0;
            }
            else if (textoSecreto[i] == '4')
            {
                printf("%c", 52);
                i++;
                p = 0;
            }
            else if (textoSecreto[i] == '5')
            {
                printf("%c", 53);
                i++;
                p = 0;
            }
            else if (textoSecreto[i] == '6')
            {
                printf("%c", 54);
                i++;
                p = 0;
            }
            else if (textoSecreto[i] == '7')
            {
                printf("%c", 55);
                i++;
                p = 0;
            }
            else if (textoSecreto[i] == '8')
            {
                printf("%c", 56);
                i++;
                p = 0;
            }
            else if (textoSecreto[i] == '9')
            {
                printf("%c", 57);
                i++;
                p = 0;
            }
            else if (textoSecreto[i] == ',')
            {
                printf("%c", 44);
                i++;
                p = 0;
            }
            else if (textoSecreto[i] == '.')
            {
                printf("%c", 46);
                i++;
                p = 0;
            }
            else if (textoSecreto[i] == ' ')
            {
                printf("%c", 32);
                i++;
                p = 0;
            }
            else if (textoSecreto[i] == '!')
            {
                printf("%c", 33);
                i++;
                p = 0;
            }
            else if (textoSecreto[i] == '-')
            {
                printf("%c", 45);
                i++;
                p = 0;
            }
            else if (textoSecreto[i] == '?')
            {
                printf("%c", 63);
                i++;
                p = 0;
            }
            else if (textoSecreto[i] == 39)
            {
                printf("%c", 39);
                i++;
                p = 0;
            }
            else if (textoSecreto[i] == 34)
            {
                printf("%c", 34);
                i++;
                p = 0;
            }
            else if (textoSecreto[i] == 35)
            {
                printf("%c", 35);
                i++;
                p = 0;
            }
            else if (textoSecreto[i] == 36)
            {
                printf("%c", 36);
                i++;
                p = 0;
            }
            else if (textoSecreto[i] == 37)
            {
                printf("%c", 37);
                i++;
                p = 0;
            }
            else if (textoSecreto[i] == 38)
            {
                printf("%c", 38);
                i++;
                p = 0;
            }
            else if (textoSecreto[i] == 40)
            {
                printf("%c", 40);
                i++;
                p = 0;
            }
            else if (textoSecreto[i] == 41)
            {
                printf("%c", 41);
                i++;
                p = 0;
            }
            else if (textoSecreto[i] == 42)
            {
                printf("%c", 42);
                i++;
                p = 0;
            }
            else if (textoSecreto[i] == 43)
            {
                printf("%c", 43);
                i++;
                p = 0;
            }
            else if (textoSecreto[i] == 37)
            {
                printf("%c", 37);
                i++;
                p = 0;
            }
            else if (textoSecreto[i] == 58)
            {
                printf("%c", 58);
                i++;
                p = 0;
            }
            else if (textoSecreto[i] == 59)
            {
                printf("%c", 59);
                i++;
                p = 0;
            }
            else if (textoSecreto[i] == 60)
            {
                printf("%c", 60);
                i++;
                p = 0;
            }
            else if (textoSecreto[i] == 61)
            {
                printf("%c", 61);
                i++;
                p = 0;
            }
            else if (textoSecreto[i] == 62)
            {
                printf("%c", 39);
                i++;
                p = 0;
            }
            else if (textoSecreto[i] == 64)
            {
                printf("%c", 39);
                i++;
                p = 0;
            }
            else if (textoSecreto[i] == 91)
            {
                printf("%c", 91);
                i++;
                p = 0;
            }
            else if (textoSecreto[i] == 92)
            {
                printf("%c", 92);
                i++;
                p = 0;
            }
            else if (textoSecreto[i] == 93)
            {
                printf("%c", 93);
                i++;
                p = 0;
            }
            else if (textoSecreto[i] == 94)
            {
                printf("%c", 94);
                i++;
                p = 0;
            }
            else if (textoSecreto[i] == 95)
            {
                printf("%c", 95);
                i++;
                p = 0;
            }
            else if (textoSecreto[i] == 96)
            {
                printf("%c", 96);
                i++;
                p = 0;
            }
            else if (textoSecreto[i] == 123)
            {
                printf("%c", 123);
                i++;
                p = 0;
            }
            else if (textoSecreto[i] == 124)
            {
                printf("%c", 124);
                i++;
                p = 0;
            }
            else if (textoSecreto[i] == 125)
            {
                printf("%c", 125);
                i++;
                p = 0;
            }
            else if (textoSecreto[i] == 126)
            {
                printf("%c", 126);
                i++;
                p = 0;
            }


        }

    }





    if (chaveValida == true)
    {
        printf("\n");
        return 0;
    }


}

