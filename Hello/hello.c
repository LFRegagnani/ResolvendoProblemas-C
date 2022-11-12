#include <stdio.h>
#include <cs50.h>

int main(void)
{

    string name = get_string("what is your name? \n"); //recebe a entrada do usuario

    printf("hello %s \n", name); //diz olá para o usuario no console

}