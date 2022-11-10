#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<locale.h>
#include"cube.h"
#include"cubeF.c"

int main(void)
{
    setlocale(LC_ALL,"Portuguese");
    int escolha;
    bool status = true;

    while ( status )
    {   
        system("cls");
        exibeMenu();
        printf("\n Digite a sua escolha: ");
        scanf("%d",&escolha);
        switch (escolha)
        {
            case 1:
                cronometro();
                break;
            case 2:
            	mostraDados();
            	break;
            case 0:
                status = !status;
                break;
            default:
                printf(" Opção Inválida! \n");
        }
    }

    printf("\n\n\n");
    system("pause");

    return 0;
}
