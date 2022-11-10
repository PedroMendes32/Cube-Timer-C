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
        free(resultados);
    }
    free(resultados);
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
            	fwrite(&qtd,sizeof(int),1,arquivo);
                for ( i = 0; i < qtd; i++ )
                {
                    fwrite(&valores[i],sizeof(double),1,arquivo);
                }
                
            }
            fclose(arquivo);
            break;
        case 2:
        	if ( (arquivo = fopen("Cubo3x3.dat","wb")) == NULL )
			{
				printf("O arquivo não pode ser aberto para escrita!\n");
				exit(1);
			}
			else
			{	
				fwrite(&qtd,sizeof(int),1,arquivo);
				for ( i = 0; i < qtd; i++ )
				{
					fwrite(&valores[i],sizeof(double),1,arquivo);
				}
			}
			fclose(arquivo);
			break;
		case 3:
			if ( (arquivo = fopen("Cubo4x4.dat","wb")) == NULL)
			{
				printf("O arquivo não pode ser aberto para escrita!\n");
				exit(1);
			}
			else
			{	
				fwrite(&qtd,sizeof(int),1,arquivo);
				for ( i = 0; i < qtd; i++ )
				{
					fwrite(&valores[i],sizeof(double),1,arquivo);
				}
			}
			fclose(arquivo);
			break;
		case 4:
			if ( (arquivo = fopen("Cubo5x5.dat","wb")) == NULL )
			{
				printf("O arquivo não pode ser aberto para escrita!\n");
				exit(1);
			}
			else
			{	
				fwrite(&qtd,sizeof(int),1,arquivo);
				for ( i = 0; i < qtd; i++ )
				{
					fwrite(&valores[i],sizeof(double),1,arquivo);
				}
			}
			fclose(arquivo);
			break;
		case 5:
			printf("Sair!\n\n");
			break;
			
        default:
            printf("Opção inválida!\n\n");
    }
    
    system("pause");
    
}

void mostraDados ( void )
{
	FILE * arquivo;
	int qtd,i;
	int escolha;
	double * valores;
	double media = 0;
	
	system("cls");
	printf("Exibir dados: \n");
	printf("1 - Cubo 2x2\n");
	printf("2 - Cubo 3x3\n");
	printf("3 - Cubo 4x4\n");
	printf("4 - Cubo 5x5\n");
	printf("\nDigite a sua escolha: ");
	scanf("%d",&escolha);
	
	switch (escolha)
	{
		case 1:
			if ( (arquivo = fopen("Cubo2x2.dat","rb")) == NULL)
			{
				printf("O arquivo não pode ser lido!\n");
				exit(1);
			}
			else
			{	
				system("cls");
				rewind(arquivo);
				fread(&qtd,sizeof(int),1,arquivo);
				valores = (double*) malloc ( sizeof(double) * qtd );
				for ( i = 0; i < qtd; i++ )
				{
					fread(&valores[i],sizeof(double),1,arquivo);
					media = media + valores[i];
				}
				
				printf("**********************\n");
				printf("*** DADOS CUBO 2X2 ***\n");
				printf("**********************\n\n");
				
				for ( i = 0; i < qtd; i++ )
				{
					printf(" %d Tentativa --> %.2lf Segundos! \n",i+1,valores[i]);
				}
				printf(" Média Cubo 2x2 --> %.2lf Segundos! \n",media/qtd);
				
				free(valores);
			}
			break;
		
		default:
			printf("Opção inválida!\n");
			
	}
}

