#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<locale.h>

void exibeMenu (void);
void exibeAviso (void);
void tempoExec (void);

int main(void)
{
    setlocale(LC_ALL,"Portuguese");
    exibeMenu();
    int escolha;
    bool status = true;

    while ( status )
    {
        printf("\n Digite a sua escolha: ");
        scanf("%d",&escolha);
        switch (escolha)
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 0:
                status = !status;
                break;
            default:
                printf(" Opção inválida! \n");
        }
    }

    printf("\n\n\n");
    system("pause");

    return 0;
}

void exibeMenu (void)
{
    printf("\t\t**********************\n");
    printf("\t\t*   CUBE TIMER C     *\n");
    printf("\t\t**********************\n");
    printf(" 1 -> 2x2 \n");
    printf(" 2 -> 3x3 \n");
    printf(" 3 -> 4x4 \n");
    printf(" 4 -> 5x5 \n");
    printf(" 0 -> Sair\n");
}

void exibeAviso (void) 
{
    return;
}