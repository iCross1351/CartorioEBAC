#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de espaço de texto por região
#include <string.h> //biblioteca responsável por cuidar das string


	int registro()
	
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo,cpf); // Responsável por copiar os valores das string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo
	fprintf(file, cpf); //Salva o valor da variavel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
}

	int consulta()
{
	setlocale(LC_ALL, "Portuguese_Brazil.1252"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
{
	printf("CPF não cadastrado!\n");
}

	while(fgets(conteudo, 200, file) != NULL);
{
	printf("\n Essas são as informações do usuário: ");
	printf("%s", conteudo);
	printf("\n\n");
}
	
	system("pause");
	
}

	int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if(file == NULL)
{
	system("cls");
	printf("\nCPF não encontrado!\n\n");
	system("pause");
}
	else
{
	if(remove(cpf) == 0);
	printf("\nCPF deletado!\n\n");
	system("pause");
}
}


int main()
{
	int opcao=0; //Definição da variável
	int laco=1;
	
	for(laco=1;laco=1;)
{
	system("cls"); // limpa as informações que não são mais necessárias na tela 
	
	setlocale(LC_ALL, "Portuguese_Brazil.1252"); //Definindo a linguagem
	
	printf("### Cartório da EBAC ###\n\n"); //Ínicio do menu
	printf("Escolha a opção desejada:\n\n");
	printf("\t 1 - Registrar nome\n");
	printf("\t 2 - Consultar nome\n");
	printf("\t 3 - Deletar nome\n");
	printf("\t 4 - Sair do sistema\n\n");
	printf("Opção:"); //Fim do menu
	
	scanf ("%d", &opcao); //Armazendo a escolha do usuário
	system("cls");
	
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
		printf("Obrigado por usar nosso sistema!\n\n");
	return 0;
	break;
	
	default:
		printf("Essa opção não está disponível\n"); //Fim da seleção
		system("pause");
	break;
} 
	
	

}
}