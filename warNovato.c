#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Definição da estrutora dos territórios ---
typedef struct{
	char nome[50];
	char cor[30];
	int tropas;
}Territorio;

// --- Função para limpar o buiffer de entrada ---
void limpaBufferEntrada(){
	int c;
	while((c = getchar()) != '\n' && c != EOF);
}

int main(){
	Territorio territorios[5];
	printf("Vamos cadastrar os 5 territorios iniciais do nosso mundo\n\n");

	for(int i=0;i<5;i++){
		printf("--- Cadastrando Territorio %d ---\n",i+1);
		printf("Nome do Territorio: ");
		fgets(territorios[i].nome,50,stdin);
		printf("Cor do territorio: ");
		fgets(territorios[i].cor,30,stdin);
		printf("Numero de Tropas: ");
		scanf("%d",&territorios[i].tropas);
		limpaBufferEntrada();

		territorios[i].nome[strcspn(territorios[i].nome,"\n")] = '\0';
		territorios[i].cor[strcspn(territorios[i].cor,"\n")] = '\0';

	}
	printf("Cadastro inicial concluído com sucesso!\n");
	printf("================================================\n");
	printf("         MAPA DO MUNDO - ESTADO ATUAL\n");
	printf("================================================\n");

	for(int i=0;i<5;i++){
		printf("TERRITORIO %d\n",i+1);
		printf(" - Nome: %s\n - Dominado por: Exercito %s\n - Tropas: %d\n", territorios[i].nome, territorios[i].cor, territorios[i].tropas);
	}

	return 0;
}

