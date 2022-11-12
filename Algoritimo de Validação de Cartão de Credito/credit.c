#include <cs50.h>
#include <stdio.h>


int main(void)
{

    long numberCard = get_long("insira o número do cartão\n");



    long numberCard2 = numberCard;
    long numberCard3 = numberCard;
    long numeroDigitos = 0;
    long doisPrimeirosDigitos = 0;
    long primeiroDigito = 0;


    long listaNumeros[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    long n = 15;
    long sobra = 0;

//descobrir todos os digitos do cartão
    while (numberCard3 > 0)
    {

        sobra = numberCard3 % 10;
        listaNumeros[n] = sobra;
        numberCard3 = numberCard3 / 10;
        n--;
    }


    long num14 = listaNumeros[14] * 2;

    long num12 = listaNumeros[12] * 2;

    long num10 = listaNumeros[10] * 2;

    long num8 = listaNumeros[8] * 2;

    long num6 = listaNumeros[6] * 2;

    long num4 = listaNumeros[4] * 2;

    long num2 = listaNumeros[2] * 2;

    long num0 = listaNumeros[0] * 2;

//int somaFinal1 = num0+num2+num4+num6+num8+num10+num12+num14;

    long num0a = 0;
    long num0b = 0;
    long num2a = 0;
    long num2b = 0;
    long num4a = 0;
    long num4b = 0;
    long num6a = 0;
    long num6b = 0;
    long num8a = 0;
    long num8b = 0;
    long num10a = 0;
    long num10b = 0;
    long num12a = 0;
    long num12b = 0;
    long num14a = 0;
    long num14b = 0;

    if (num0 >= 10)
    {
        num0b = num0 % 10;
        num0a = num0 / 10;
    }
    else
    {
        num0a = num0;
        num0b = 0;
    }

    if (num2 >= 10)
    {
        num2b = num2 % 10;
        num2a = num2 / 10;
    }
    else
    {
        num2a = num2;
        num2b = 0;
    }


    if (num4 >= 10)
    {
        num4b = num4 % 10;
        num4a = num4 / 10;
    }
    else
    {
        num4a = num4;
        num4b = 0;
    }

    if (num6 >= 10)
    {
        num6b = num6 % 10;
        num6a = num6 / 10;
    }
    else
    {
        num6a = num6;
        num6b = 0;
    }

    if (num8 >= 10)
    {
        num8b = num8 % 10;
        num8a = num8 / 10;
    }
    else
    {
        num8a = num8;
        num8b = 0;
    }

    if (num10 >= 10)
    {
        num10b = num10 % 10;
        num10a = num10 / 10;
    }
    else
    {
        num10a = num10;
        num10b = 0;
    }

    if (num12 >= 10)
    {
        num12b = num12 % 10;
        num12a = num12 / 10;
    }
    else
    {
        num12a = num12;
        num12b = 0;
    }

    if (num14 >= 10)
    {
        num14b = num14 % 10;
        num14a = num14 / 10;
    }
    else
    {
        num14a = num14;
        num14b = 0;
    }

    long somaDosDigitos = num0a + num0b + num2a + num2b + num4a + num4b + num6a + num6b + num8a + num8b + num10a + num10b + num12a +
                          num12b + num14a + num14b;

    long somaFinal = somaDosDigitos + listaNumeros[15] + listaNumeros[13] + listaNumeros[11] + listaNumeros[9] + listaNumeros[7] +
                     listaNumeros[5] + listaNumeros[3] + listaNumeros[1];

    long verificador = somaFinal % 10;

    bool valido = false;


    if (verificador == 0)
    {
        valido = true;
    }


//printf("%i\n",listaNumeros[0]);
//printf("%i\n",listaNumeros[1]);
//printf("%i\n",listaNumeros[2]);
//printf("%i\n",listaNumeros[3]);
//printf("%i\n",listaNumeros[4]);
//printf("%i\n",listaNumeros[5]);
//printf("%i\n",listaNumeros[6]);
//printf("%i\n",listaNumeros[7]);
//printf("%i\n",listaNumeros[8]);
//printf("%i\n",listaNumeros[9]);
//printf("%i\n",listaNumeros[10]);
//printf("%i\n",listaNumeros[11]);
//printf("%i\n",listaNumeros[12]);
//printf("%i\n",listaNumeros[13]);
//printf("%i\n",listaNumeros[14]);
//printf("%i\n",listaNumeros[15]);

//função que verifica o numero de digitos no cartão e primeiro digito


    if (numberCard2 == 0)
    {
        numeroDigitos = 1;
    }
    else
    {
        while (numberCard2 != 0)
        {
            // filtra 2 primeiros digitos
            if (numberCard2 < 100 && numberCard2 >= 10)
            {
                doisPrimeirosDigitos = numberCard2;
            }
            //filtra primeiro digito
            if (numberCard2 < 10 && numberCard2 > 0)
            {
                primeiroDigito = numberCard2;
            }

            numeroDigitos++;
            numberCard2 = numberCard2 / 10;
        }
    }





    if ((numeroDigitos == 15) && (doisPrimeirosDigitos == 34 || doisPrimeirosDigitos == 37) && (valido == true))
    {
        printf("é AMEX\n");
    }
    else if ((numeroDigitos == 16) && (doisPrimeirosDigitos == 51 || doisPrimeirosDigitos == 52 || doisPrimeirosDigitos == 53
                                       || doisPrimeirosDigitos == 54 || doisPrimeirosDigitos == 55) && (valido == true))
    {
        printf("é MASTERCARD\n");
    }
    else if ((numeroDigitos == 13 || numeroDigitos == 16) && (primeiroDigito == 4) && (valido == true))
    {
        printf("é VISA\n");
    }
    else
    {
        printf(" %lo o número digitado é INVALID\n", verificador);
    }
}