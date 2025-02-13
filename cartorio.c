#include <stdio.h>//Sempre que quiser incluir comunicação com o usuario//
#include <stdlib.h>//biblioteca de alocação do espaço de memória//
#include <locale.h>//biblioteca de alocação de texto por região//
#include <string.h>//Responsável por cuidar das strings

int registro ()//função resp por cadastrar//
{
	setlocale(LC_ALL, "Portuguese");//deixa em português//
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf ("Digite o CPF a ser cadastrado: \n");
	scanf ("%s", cpf); //nota que o %s é pra salvar algo em uma string, que vem na sequencia//
	strcpy(arquivo, cpf);//copia o valor de um string em outro do cpf pro arquivo//
	FILE *file;//diz ao sistema para procurar file//
	file = fopen(arquivo,"w"); //deu a ordem: cria um arquivo e o escreva w é write//
	fprintf(file,cpf);//salva o valor da variável//
	fclose(file);//fecha o file//
	
	file=fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: \n");
	scanf("%s", nome);
	
	file=fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file=fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: \n");
	scanf("%s", sobrenome);
	
	file=fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file=fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: \n");
	scanf("%s", cargo);
	
	file=fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system ("pause");
	system ("cls"); 
}

int consulta () 
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf ("Digite o CPF a ser consultado: \n");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file==NULL)
	{
		printf("Não foi possível localizar o usuário \n");
	}
	
	while(fgets(conteudo, 200, file)!=NULL)
	{
		printf("\nEssas são as informações do usuário em questão: ");
		printf("%s", conteudo);
		printf("\n\n");
	}

system ("pause");
system ("cls"); 
}


int deletar () 
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	
	printf ("Por gentileza, digite o CPF cadastrado a ser deletado: \n");
	scanf ("%s", cpf);
	
	FILE *file;
	file=fopen(cpf, "r");
	
	if(file==NULL)
	{
		printf("Não foi possível localizar o usuário \n");
		system ("pause");
	}
	else
	{
		fclose(file);//fecha o arquivo pq ele existe//
		remove(cpf); //remove o que foi selecionado para tomar o delete//
		printf("Usuário deletado com sucesso.\n");
		system ("pause");
		system ("cls"); 
	}
	
	

}
int main ()
{
	int opcao=0;//tem que deixar sempre em zero//
	int x=1;
	for(x=1;x=1;) //laço de repetição - nesse caso é um macete pra repetir pra sempre//
	{
	
		setlocale(LC_ALL, "Portuguese");// Deginindo a linguagem//
		
		printf ("####Cartório da bagunça infinita####\n");
		printf ("Escolhe o que você quer aí, parsonauta: \n");
		printf ("\t1- Registrar nominho\n");
		printf ("\t2- Consultar nominho\n");
		printf ("\t3- Matar o filadaputa\n\n\n");
		
		printf ("Digite a opção selecionada: ");
		scanf ("%d", &opcao);
		
		system ("cls"); //limpar console//
		
		switch(opcao)
		{
		case 1:
		registro ();
		break;
		
		case 2:
		consulta ();
		break;
		
		case 3:
		deletar ();
		break;
		
		default:
		printf ("Escolha uma opção válida\n");
		system ("pause");//Pra que a tela volte bonitinha//
		system ("cls");
		break;
		}
	}
}
