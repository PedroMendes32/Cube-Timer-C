void exibeMenu (void)
{
    printf("\t\t**********************\n");
    printf("\t\t*   CUBE TIMER C     *\n");
    printf("\t\t**********************\n");
    printf(" 1 -> Iniciar cronômetro! \n");
    printf(" 2 -> Ver resultados!\n");
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
    int i,escolha;

    printf("\n Digite a quantidade de séries: ");
    scanf("%d",&qtdSeries);

    double * resultados;

    resultados = (double*) malloc (sizeof(double) * qtdSeries);

    for ( i = 0; i < qtdSeries; i++ )
    {
        resultados[i] = conta();
    }

    printf("\n TEMPOS OBTIDOS: \n");

    for ( i = 0; i < qtdSeries; i++ )
    {
        printf(" %d - %.2lf Segundos \n",i+1,resultados[i]);
    }

    printf(" 1 -> Salvar dados \n");
    printf(" 0 -> Sair \n");
    printf("\n Digite a sua escolha: ");
    scanf("%d",&escolha);

    if ( escolha == 1 )
    {
        salvar(resultados,qtdSeries);
    }
}

void salvar (double * valores, int qtd)
{
    FILE * arquivo;
    int escolha, i;
	
	system("cls");
    printf("- SALVAR EM: \n");
    printf("1 - Cubo 2x2\n");
    printf("2 - Cubo 3x3\n");
    printf("3 - Cubo 4x4\n");
    printf("4 - Cubo 5x5\n");
    printf("5 - Sair\n");
    printf("\n Digite a sua escolha: ");
    scanf("%d",&escolha);

    switch ( escolha )
    {
        case 1:
            if ( (arquivo = fopen("Cubo2x2.dat","wb")) == NULL)
            {
                printf("O arquivo não pode ser aberto para escrita!\n");
                exit(1);
            }
            else
            {
                for ( i = 0; i < qtd; i++ )
                {
                    fwrite(&valores[i],sizeof(double),1,arquivo);
                }
            }
            break;
        case 2:
        	if ( (arquivo = fopen("Cubo3x3.dat","wb")) == NULL )
			{
				printf("O arquivo não pode ser aberto para escrita!\n");
				exit(1);
			}
			else
			{
				for ( i = 0; i < qtd; i++ )
				{
					fwrite(&valores[i],sizeof(double),1,arquivo);
				}
			}
			break;
		case 3:
			if ( (arquivo = fopen("Cubo4x4.dat","wb")) == NULL)
			{
				printf("O arquivo não pode ser aberto para escrita!\n");
				exit(1);
			}
			else
			{
				for ( i = 0; i < qtd; i++ )
				{
					fwrite(&valores[i],sizeof(double),1,arquivo);
				}
			}
			break;
		case 4:
			if ( (arquivo = fopen("Cubo5x5.dat","wb")) == NULL )
			{
				printf("O arquivo não pode ser aberto para escrita!\n");
				exit(1);
			}
			else
			{
				for ( i = 0; i < qtd; i++ )
				{
					fwrite(&valores[i],sizeof(double),1,arquivo);
				}
			}
			break;
		case 5:
			printf("Sair!\n\n");
			system("pause");
			break;
			
        default:
            printf("Opção inválida!\n\n");
            system("pause");
    }
}

