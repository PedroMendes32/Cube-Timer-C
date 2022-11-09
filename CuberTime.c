#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<locale.h>

void exibeMenu (void);
void exibeAviso (void);
void tempoExec (void);
void cronometro (void);
double conta (void);
void salvar (void);

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
                cronometro();
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
    printf(" 1 -> Iniciar cronômetro! \n");
    printf(" 0 -> Sair\n");
}

void exibeAviso (void) 
{   
    fflush(stdin);
    printf(" PARA COMEÇAR PRESSIONE ENTER! ");
    getchar();
    printf("\n\n");
}

void tempoExec (void)
{   
    printf(" COMEÇOU A CONTAR!.. \n");
    printf(" PRESSIONE ENTER PARA FECHAR!..");
    while (true)
    {
        if ( getchar() )
        {
            break;
        }
    }
    printf("\n\n\n");
    printf(" TERMINOU! \n");
}

double conta (void)
{   
    double tempoF;
    exibeAviso();
    printf("\n");
    size_t tempo;
    tempo = clock();
    tempoExec();
    tempo = clock() - tempo;

    tempoF = ((double)tempo/CLOCKS_PER_SEC);
    
    return tempoF;
}

void cronometro (void)
{
    int qtdSeries;
    int i;

    printf("\n Digite a quantidade de séries: ");
    scanf("%d",&qtdSeries);

    double * resultados;

    resultados = (double*) malloc (sizeof(double) * qtdSeries);

    for ( i = 1; i <= qtdSeries; i++ )
    {
        resultados[i] = conta();
    }

    system("pause");
    printf(" TEMPOS OBTIDOS: \n");

    for ( i = 1; i <= qtdSeries; i++ )
    {
        printf(" %d - %.2lf Segundos \n",i,resultados[i]);
    }
}

void salvar (void)
{
    return;
}

