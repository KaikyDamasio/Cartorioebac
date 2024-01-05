 #include <stdio.h> // Biblioteca de comunicacao com o usuario
#include <stdlib.h> //Biblioteca de alocacao de espaco em memoria
#include <locale.h> //Biblioteca de alocacoes de texto por regiao
#include <string.h> //Biblioteca responsável por cuidar das Strings


 	int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
		
	printf("Digite seu Cpf a ser cadastrado:");
	scanf("%s",cpf);
	
	strcpy(arquivo,cpf);//Responsavel por copiar os valores das Strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo,"w");// cria o arquivo
	fprintf (file,cpf); // salvo o valor da variavel 
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o Nome a ser cadastrado:");
	scanf("%s",nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o Sobrenome a ser cadastrado:");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o Cargo a ser cadastrado:");
	scanf("%s",cargo);
	
	file=fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}



int consulta()
{
	setlocale (LC_ALL, "Portuguese"); //Definindo a linguagem
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o Cpf a ser consultado:");
	scanf("%s",cpf);
	
	FILE*file;
	file=fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado ! ");
		
	}
	
	while(fgets(conteudo,200,file)!= NULL)
	{
		printf("\n Essas sao as informacoes do usuário: ");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	
	
	
}

int deletar()
{
	setlocale (LC_ALL, "Portuguese");
	
	char cpf[40];
	char b[40];
	
	printf("Digite o CPF do usuário a ser deletado:");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");

	if(file==NULL)
	{
		printf("\n CPF não encontrado!\n\n");
		system("pause");
	}
	
	else{
		fclose(file);
	}
	
	
	if(remove(cpf) == 0)
	{
		printf("\n Usario deleteado com sucesso! \n\n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0; // Definindo Variaveis
	int x=1;
		
	for(x=1;x=1;)
	{	
	
		system("cls");
		
		setlocale (LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf ("***Cartório da Ebac*** \n\n"); //Inicio do menu 
		printf ("Escolha a opção desejada do menu:\n\n");
		printf ("\t1 - Registrar nomes\n");	
		printf ("\t2 - Consultar nomes\n");
		printf ("\t3 - Deletar nomes\n");
		printf ("\t4 - Sair do Sistema\n"); //Opção de saída(fim do menu)
		printf ("Opção:");
		scanf("%d", &opcao);	//Ordem de Armazenar e scanear a escolha do usuario
	
		system("cls"); //Deletar o console anterior
	
		switch(opcao)
		{
			case 1:
			registro();
			break;
			
			case 2: 
			consulta();
			break;
			
			case 3: 
			deletar();
			break;
			
			case 4: 
            printf("Obrigado por utilizar o sistema!");
            return 0;
            break;
	
			default: 
			printf("Essa opcao é invalida!  \n");
			system("pause");
			break;
		}
	}	
}
