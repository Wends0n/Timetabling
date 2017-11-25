#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*Função que cria a matriz onde sera guardada a solucao*/
int ***cria_solucao(int turmas,int dias, int horarios);
/*Função que preenche a solucao na matriz*/
int ***preenche_solucao(int turmas, int dias, int horarios);
/*Função que mostrar a solucao*/
void mostra_solucao(int turmas, int dias, int horarios);

/*Turmas(Linhas) = Cada "Quadrado"
  Dias(Colunas)  = Cada "Linha"
  Horarios()     = Cada "Coluna" 
*/
int main(void){
	
	mostra_solucao(17,5,6);

	getchar();
	getchar();
}

int ***cria_solucao(int turmas,int dias, int horarios){
	int i,j;
	int ***matriz_solucao;

	matriz_solucao = (int ***) malloc(turmas * sizeof(int **));
	for(i = 0; i < turmas; i++){
		matriz_solucao[i] = (int **) malloc(dias * sizeof(int *));
		for(j = 0; j < dias; j++){
			matriz_solucao[i][j] = (int *) malloc(horarios * sizeof(int));
		}
	}
	return matriz_solucao;
}

int ***preenche_solucao(int turmas, int dias,int horarios){
	int ***matriz_solucao;
	/*Custo_disciplina = Calcula um custo para cada escolha
      de disciplina.	
	*/
	int custo_disciplina[97],disciplina;
	int i,j,k;
	
	matriz_solucao = cria_solucao(turmas,dias,horarios);
	
	for(i = 0; i < turmas; i ++){
		for(j = 0; j < dias; j ++){
			for(k = 1; k <= horarios; k += 2){
				disciplina = 1+rand() % 97;
				matriz_solucao[i][j][k] = disciplina;
				matriz_solucao[i][j][k-1] = disciplina;
				
				if (custo_disciplina[disciplina] == 100){
					disciplina = 1+rand() % 97;
					matriz_solucao[i][j][k] = disciplina;
					matriz_solucao[i][j][k-1] = disciplina;
				}
				custo_disciplina[disciplina] = 100;
			}
		}
	}
	return matriz_solucao;
}

void mostra_solucao(int turmas, int dias, int horarios){
	int i,j,k;
	int ***matriz_solucao;
	matriz_solucao = preenche_solucao(turmas,dias,horarios);
	
	for(i = 0; i < turmas; i ++){
		for(j = 0; j < dias; j ++){
			for(k = 0; k < horarios; k ++){
				printf(" %d ",matriz_solucao[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
}

