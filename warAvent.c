#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// --- Definição da estrutora dos territórios ---
typedef struct{
	char nome[50];
	char cor[30];
	int tropas;
}Territorio;

// --- Função para limpar o buffer de entrada ---
void limpaBufferEntrada(){
	int c;
	while((c = getchar()) != '\n' && c != EOF);
}

void atacar(Territorio* atacante, Territorio* defensor){
	int nAtacante, nDefensor;
	srand(time(NULL));
	nAtacante = (rand() % 6) + 1;
	nDefensor = (rand() % 6) + 1;
	printf("************** BATALHA ***************\n\n");
	printf("O atancante %s rolou os dado e tirou: %d\n",atacante->nome, nAtacante);
	printf("O defensor %s rolou os dado e tirou: %d\n", defensor->nome, nDefensor);
	if(nDefensor > nAtacante){
		defensor->tropas++;
		atacante->tropas--;
	}else if(nDefensor < nAtacante){
		defensor->tropas--;
		atacante->tropas++;
	}

}

int main(){
	int numTerritorios;
	//limpaBufferEntrada();	
	printf("Digite o numero de territórios: ");
	scanf("%d", &numTerritorios);
	limpaBufferEntrada();
	
	Territorio* territorios = (Territorio*)malloc(numTerritorios * sizeof(Territorio));

	printf("Vamos cadastrar os %d territorios iniciais do nosso mundo\n\n",numTerritorios);

	for(int i = 0;i < numTerritorios;i++){
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
	
	int escolha = -1;
	int atacante, defensor;
	do{
		printf("================================================\n");
		printf("         MAPA DO MUNDO - ESTADO ATUAL\n");
		printf("================================================\n");

		for(int i=0;i<numTerritorios;i++){
			printf("%d. %s (Exercito %s, tropas: %d)\n", i+1, territorios[i].nome, territorios[i].cor, territorios[i].tropas);
		}	

		printf("--- FASE DE ATAQUE ---\n");
		printf("Escolha o terriório atacante: 1 a %d, 0 par Sair: ",numTerritorios);
		scanf("%d",&escolha);
		limpaBufferEntrada();
		if(escolha != 0){
			if(escolha > numTerritorios+1){
				printf("Território incorreto!\n");
			}else{
				atacante = escolha-1;
				printf("Escolha o territorio defensor: 1 a %d: ", numTerritorios);
				scanf("%d",&escolha);
				limpaBufferEntrada();
				if((escolha > numTerritorios+1) || (escolha == atacante)){
					printf("Território incorreto!\n");
				}else{
					defensor = escolha-1;
					atacar(&territorios[atacante], &territorios[defensor]);
				}	
			}
		}
		//atacar(&territorios[0], &territorios[1]);
	}while(escolha != 0);
	
	free(territorios);
	return 0;
}

