#include <stdio.h> //biblioetca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de anota��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar dos string

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//in�cio cria��o de vari�veis/string
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char arquivo[40]; //Definindo quantidaddes de vari�veis para o arquivo.
	char cpf[40]; //Definindo quantidaddes de vari�veis para cpf.
	char nome[40]; //Definindo quantidaddes de vari�veis para nome.
	char sobrenome[40]; //Definindo quantidaddes de vari�veis para sobrenome.
	char cargo[40]; //Definindo quantidaddes de vari�veis para cargo.
	//final da cria��o das vari�veis/srting
	
	printf("Digite o CPF  a ser cadastrado: "); //coletando informa��o do us�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores dos string
	
	FILE *file; //Cria o arquivo
	file = fopen (arquivo, "w"); //Cria o arquivo e o w significa escrever
	fprintf(file,cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abrir o arquivo para gravar dados a ser adiconados
	fprintf(file,","); //Adicionar v�rgula entre os dados inseridos. 
	fclose(file); //fecha o arquivo
	
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); //Abrir o arquivo para gravar dados a ser adiconados
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause"); //respons�vel por limpar a tela

	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o Cpf a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado! \n");	
	}
	
	while(fgets(conteudo, 200,file) != NULL)
	{
		printf("\n Essas s�o as informa��es do usu�rio: \n\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Usu�rio n�o se encontra no sistema! \n");
		system("pause");
	}
	
	remove(cpf);
	
	if(file != NULL)
	{
		printf("\nUsu�rio deletado com sucesso!\n\n");
		system("pause");
	}
	
}


int main () //armazena o menu
	{
	int opcao=0; //Definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("###Cart�rio da EBAC###\n\n"); //In�cio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nome\n");
		printf("\t2 - Consultar nome\n");
		printf("\t3 - Deletar nome\n"); 
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: "); //Fim do menu
	
		scanf("%d", &opcao); //Armazenando escolha do usu�rio
	
		system("cls");
	
		switch(opcao) //inicio da sele��o do menu
		{
			case 1:
			registro(); //chamada de fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigada por utilizar o sistema!\n");
			return 0;
			break;
			
			
			default:
			printf("Essa op��o n�o est� dispon�vel"); 
			system("pause");
			break;
		} //fim da sele��o

	}
}
