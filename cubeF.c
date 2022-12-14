void exibeMenu (void)
{
    printf("\t\t**********************\n");
    printf("\t\t*   CUBE TIMER C     *\n");
    printf("\t\t**********************\n");
    printf(" 1 -> Iniciar cron?metro! \n");
    printf(" 2 -> Ver resultados!\n");
    printf(" 3 -> Apagar registros!\n");
    printf(" 0 -> Sair\n");
}

void exibeAviso (void) 
{   
	system("cls");
    fflush(stdin);
	escolheSequencia();
    printf(" PARA COME?AR PRESSIONE ENTER! ");
    getchar();
    printf("\n\n");
}

void tempoExec (void)
{   
	system("cls");
    printf(" COME?OU A CONTAR!.. \n");
    printf(" PRESSIONE ENTER PARA FECHAR!..");
    while (true)
    {
        if ( getchar() )
        {
            break;
        }
    }
    printf("\n\n");
    printf("*************\n");
    printf("* TERMINOU! *\n");
    printf("*************\n\n\n");
    system("pause");
    
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
	
	system("cls");
	
    printf("\n Digite a quantidade de s?ries: ");
    scanf("%d",&qtdSeries);
	printf("\n\n");
	
    double * resultados;

    resultados = (double*) malloc (sizeof(double) * qtdSeries);

    for ( i = 0; i < qtdSeries; i++ )
    {
        resultados[i] = conta();
    }
    
    system("cls");
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
    printf(" - SALVAR EM: \n");
    printf(" 1 - Cubo 2x2\n");
    printf(" 2 - Cubo 3x3\n");
    printf(" 3 - Cubo 4x4\n");
    printf(" 4 - Cubo 5x5\n");
    printf(" 5 - Sair\n");
    printf("\n Digite a sua escolha: ");
    scanf("%d",&escolha);

    switch ( escolha )
    {
        case 1:
            if ( (arquivo = fopen("Cubo2x2.dat","wb")) == NULL)
            {
                printf("O arquivo n?o pode ser aberto para escrita!\n");
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
				printf("O arquivo n?o pode ser aberto para escrita!\n");
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
				printf("O arquivo n?o pode ser aberto para escrita!\n");
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
				printf("O arquivo n?o pode ser aberto para escrita!\n");
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
            printf("Op??o inv?lida!\n\n");
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
	printf(" Exibir dados: \n");
	printf(" 1 - Cubo 2x2\n");
	printf(" 2 - Cubo 3x3\n");
	printf(" 3 - Cubo 4x4\n");
	printf(" 4 - Cubo 5x5\n");
	printf(" \nDigite a sua escolha: ");
	scanf("%d",&escolha);
	
	system("cls");
	switch (escolha)
	{
		case 1:
			if ( (arquivo = fopen("Cubo2x2.dat","rb")) == NULL)
			{
				printf("O arquivo n?o pode ser lido!\n");
				exit(1);
			}
			else
			{	
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
				printf(" M?dia Cubo 2x2 --> %.2lf Segundos! \n",media/qtd);
				
				fclose(arquivo);
			}
			break;
		
		case 2:
			if ( (arquivo = fopen("Cubo3x3.dat","rb")) == NULL)
			{
				printf("O arquivo n?o pode ser lido!\n");
				exit(1);
			}
			else
			{
				rewind(arquivo);
				fread(&qtd,sizeof(int),1,arquivo);
				valores = (double*) malloc (sizeof(double) * qtd);
				for ( i = 0; i < qtd; i++ )
				{
					fread(&valores[i],sizeof(double),1,arquivo);
					media = media + valores[i];
				}
				
				printf("**********************\n");
				printf("*** DADOS CUBO 3X3 ***\n");
				printf("**********************\n\n");
				
				for ( i = 0; i < qtd; i++ )
				{
					printf(" %d Tentativa --> %.2lf Segundos! \n",i+1,valores[i]);
				}
				printf(" M?dia Cubo 3x3 --> %.2lf Segundos! \n",media/qtd);
				
				fclose(arquivo);
			}
			break;
		
		case 3:
			if ( (arquivo = fopen("Cubo4x4.dat","rb")) == NULL)
			{
				printf("O arquivo n?o pode ser lido!\n");
				exit(1);
			}
			else
			{
				rewind(arquivo);
				fread(&qtd,sizeof(int),1,arquivo);
				valores = (double*) malloc ( sizeof(double) * qtd );
				for ( i = 0; i < qtd; i++ )
				{
					fread(&valores[i],sizeof(double),1,arquivo);
					media = media + valores[i];
				}
				
				printf("**********************\n");
				printf("*** DADOS CUBO 4X4 ***\n");
				printf("**********************\n\n");
				
				for ( i = 0; i < qtd; i++ )
				{
					printf(" %d Tentativa --> %.2lf Segundos! \n",i+1,valores[i]);
				}
				printf(" M?dia Cubo 4x4 --> %.2lf Segundos! \n",media/qtd);
				
				fclose(arquivo);
			}
			break;
		
		case 4:
			if ( (arquivo = fopen("Cubo5x5.dat","rb")) == NULL )
			{
				printf("O arquivo n?o pode ser lido!\n");
				exit(1);
			}
			else
			{
				rewind(arquivo);
				fread(&qtd,sizeof(int),1,arquivo);
				valores = (double*) malloc ( sizeof(double) * qtd);
				for ( i = 0; i < qtd; i++ )
				{
					fread(&valores[i],sizeof(double),1,arquivo);
					media = media + valores[i];
				}
				
				printf("**********************\n");
				printf("*** DADOS CUBO 4X4 ***\n");
				printf("**********************\n\n");
				
				for ( i = 0; i < qtd; i++ )
				{
					printf(" %d Tentativa --> %.2lf Segundos! \n",i+1,valores[i]);
				}
				printf(" M?dia Cubo 5x5 --> %.2lf Segundos! \n",media/qtd);
				
				fclose(arquivo);
			}
			break;
		default:
			printf("Op??o inv?lida! \n");
	}
	
	printf("\n\n\n");
	system("pause");
	free(valores);
}



void escolheSequencia (void)
{
	FILE * arquivo;
	char sequencia[100];
	int qtd,posicao;
	int i;
	
	if ( (arquivo = fopen("embaralha.txt","r")) == NULL)
	{
		printf("O arquivo n?o pode ser aberto! \n");
		exit(1);
	}
	else
	{	
		fseek(arquivo,0,SEEK_SET);
		fscanf(arquivo,"%d",&qtd);
		posicao = (rand() % qtd)+1;
		
		for ( i = 0; i <= posicao; i++ )
		{	
			fgets(sequencia,100,arquivo);
		}
		
		fclose(arquivo);
		mostraSequencia(sequencia);
	}
}

void mostraSequencia ( char * sequencia )
{
	printf(" SEQU?NCIA DE EMBARALHAMENTO: \n");
	printf(" %s ",sequencia);
	printf("\n\n");
}

void apagaArquivo (void)
{
	int escolha;
	
	system("cls");
	printf(" Excluir Arquivo: \n");
	printf(" 1 -> Cubo2x2.dat \n");
	printf(" 2 -> Cubo3x3.dat \n");
	printf(" 3 -> Cubo4x4.dat \n");
	printf(" 4 -> Cubo5x5.dat \n");
	printf(" 0 -> Voltar \n");
	printf("\nDigite a sua escolha: ");
	scanf("%d",&escolha);
	
	printf("\n\n");
	switch (escolha)
	{
		case 1:
			remove("Cubo2x2.dat");
			printf(" Arquivo Exclu?do com Sucesso! \n\n");
			break;
		case 2:
			remove("Cubo3x3.dat");
			printf(" Arquivo Exclu?do com Sucesso! \n\n");
			break;
		case 3:
			remove("Cubo4x4.dat");
			printf(" Arquivo Exclu?do com Sucesso! \n\n");
			break;
		case 4:
			remove("Cubo5x5.dat");
			printf(" Arquivo Exclu?do com Sucesso! \n\n");
			break;
		case 0:
			break;
		default:
			printf(" Op??o inv?lida! \n\n");

	}
	system("pause");
}



