#include <stdio.h> //biblioetca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de anotações de texto por região
#include <string.h> //biblioteca responsável por cuidar dos string

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//início criação de variáveis/string
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char arquivo[40]; //Definindo quantidaddes de variáveis para o arquivo.
	char cpf[40]; //Definindo quantidaddes de variáveis para cpf.
	char nome[40]; //Definindo quantidaddes de variáveis para nome.
	char sobrenome[40]; //Definindo quantidaddes de variáveis para sobrenome.
	char cargo[40]; //Definindo quantidaddes de variáveis para cargo.
	//final da criação das variáveis/srting
	
	printf("Digite o CPF  a ser cadastrado: "); //coletando informação do usário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores dos string
	
	FILE *file; //Cria o arquivo
	file = fopen (arquivo, "w"); //Cria o arquivo e o w significa escrever
	fprintf(file,cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abrir o arquivo para gravar dados a ser adiconados
	fprintf(file,","); //Adicionar vírgula entre os dados inseridos. 
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
	
	system("pause"); //responsável por limpar a tela

	
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
		printf("Não foi possivel abrir o arquivo, não localizado! \n");	
	}
	
	while(fgets(conteudo, 200,file) != NULL)
	{
		printf("\n Essas são as informações do usuário: \n\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Usuário não se encontra no sistema! \n");
		system("pause");
	}
	
	remove(cpf);
	
	if(file != NULL)
	{
		printf("\nUsuário deletado com sucesso!\n\n");
		system("pause");
	}
	
}


int main () //armazena o menu
	{
	int opcao=0; //Definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("###Cartório da EBAC###\n\n"); //Início do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nome\n");
		printf("\t2 - Consultar nome\n");
		printf("\t3 - Deletar nome\n"); 
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: "); //Fim do menu
	
		scanf("%d", &opcao); //Armazenando escolha do usuário
	
		system("cls");
	
		switch(opcao) //inicio da seleção do menu
		{
			case 1:
			registro(); //chamada de funções
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
			printf("Essa opção não está disponível"); 
			system("pause");
			break;
		} //fim da seleção

	}
}
