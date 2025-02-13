#include <stdio.h>//Sempre que quiser incluir comunica��o com o usuario//
#include <stdlib.h>//biblioteca de aloca��o do espa�o de mem�ria//
#include <locale.h>//biblioteca de aloca��o de texto por regi�o//
#include <string.h>//Respons�vel por cuidar das strings

int registro ()//fun��o resp por cadastrar//
{
	setlocale(LC_ALL, "Portuguese");//deixa em portugu�s//
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf ("Digite o CPF a ser cadastrado: \n");
	scanf ("%s", cpf); //nota que o %s � pra salvar algo em uma string, que vem na sequencia//
	strcpy(arquivo, cpf);//copia o valor de um string em outro do cpf pro arquivo//
	FILE *file;//diz ao sistema para procurar file//
	file = fopen(arquivo,"w"); //deu a ordem: cria um arquivo e o escreva w � write//
	fprintf(file,cpf);//salva o valor da vari�vel//
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
		printf("N�o foi poss�vel localizar o usu�rio \n");
	}
	
	while(fgets(conteudo, 200, file)!=NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio em quest�o: ");
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
		printf("N�o foi poss�vel localizar o usu�rio \n");
		system ("pause");
	}
	else
	{
		fclose(file);//fecha o arquivo pq ele existe//
		remove(cpf); //remove o que foi selecionado para tomar o delete//
		printf("Usu�rio deletado com sucesso.\n");
		system ("pause");
		system ("cls"); 
	}
	
	

}

int main ()
{
	int opcao=0;//tem que deixar sempre em zero//
	int x=1;
	char senha[10]="a";
	int comparacao;
	
	printf("### Cart�rio do EBACKOVSKI\n\n");
	printf("Favor digitar sua senha de camarada admnistrador, ou morra na GULAG: \n");
	scanf ("%s", senha);
	
	comparacao=strcmp(senha, "gulag");
	if(comparacao==0)
	{
	
	
		for(x=1;x=1;) //la�o de repeti��o - nesse caso � um macete pra repetir pra sempre//
		{
		
			setlocale(LC_ALL, "Portuguese");// Deginindo a linguagem//
			
			printf ("####Cart�rio da bagun�a infinita####\n");
			printf ("Escolhe o que voc� quer a�, parsonauta: \n");
			printf ("\t1- Registrar nominho\n");
			printf ("\t2- Consultar nominho\n");
			printf ("\t3- Matar o filadaputa\n");
			printf ("\t4- Sair dessa bodega\n\n\n");
			printf ("Digite a op��o selecionada: ");
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
			
			case 4:
			printf ("Obrigado por testar meu programa! Agora vai tomar um caf� e pensar na vida");
			return 0;
			break;
			
			default:
			printf ("Escolha uma op��o v�lida\n");
			system ("pause");//Pra que a tela volte bonitinha//
			system ("cls");
			break;
			}
		}
	}
	else
		printf("Senha incorreta, vai pra GULAG");

}
