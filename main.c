#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void showBox(char box[4][4]);
void showXBox(char box[4][4], char value);
void showCheckedBox(char box[4][4], int ll, int hh, char value);
int checkBox(char box[4][4], char boxRR[4][4], char fletter, char sletter);
void fillBoxRR(char box[4][4], char boxRR[4][4], char fletter, char sletter);
int finishGame(char box[4][4], char boxRR[4][4]);
void await();
void cleanScreen();

//Variáveis para as caixas
int N = 0, M = 0;

void main()
{

	int repeat = 0; 
	int repeat2 = 0;
	
	int dificult;
	
		while(N == 0 && M == 0)
		{
	
			printf("Escolha a dificuldade: \n1-4x3\n2-5x4\n");
			scanf("%d", &dificult);
			
			switch(dificult)
			{
				case 1:
					N = 4;
					M = 3;
					cleanScreen();
					break;	
				
				case 2:
					N = 5;
					M = 4;
					cleanScreen();
					break;
		
				default:
					printf("Escolha invalida!!\n\n");
					break;
			}
			cleanScreen();
		}
	
	char array1[11]= {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
	char array2[11]= {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
	char box[N][M];
	
	//Caixa dos números acertados / global
	char boxRR[N][M];
	
	//Preenche a matriz com z
	memset(box,'z', sizeof(box));
	//Preenche a matrix dos números acertados com X
	memset(boxRR, 'X', sizeof(boxRR));
	
	//Preenchimento com o primeiro vetor
	int space = 0;
	int space2 = 0;
	
		while (repeat != ((N*M)/2))
		{ 
			
			//Permite que os números sejam mesmo aleatórios
			srand(time(NULL));
			
			int pos_l = rand()%N;
			int pos_h = rand()%M;
			
			//Primeira entrada garantida no else
			if(box[pos_l][pos_h] == 'z')
			{
				box[pos_l][pos_h] = array1[space];
				space++;
			}
			else
			{
				while(box[pos_l][pos_h] != 'z')
				{
					pos_l = rand()%N; 
					pos_h = rand()%M;
				}
				box[pos_l][pos_h] = array1[space];
				space++;
			}
			repeat++;
		}
	
	//Preenchimento com o segundo vetor
	int a, b;
		
		for(a=0; a<M; a++){
			for(b=0; b<N; b++){
				if(box[b][a] == 'z'){
					box[b][a] = array2[space2];
					space2++;
				}
			}
		}
	
		//Mostra a matriz
		showBox(box);
		await();
		cleanScreen();
		showXBox(box,'k');
	
		int gameR = 1;
	
		while (gameR == 1)
		{
			int l, h;
			int ll, hh;
				
			printf("HORIZONTAL: ");
			scanf("%d", &l);
			printf("\n");
			printf("VERTICAL: ");
			scanf("%d", &h);
			
			char fletter = box[h][l];
			cleanScreen();
			showCheckedBox(box, l, h, fletter);
			
			printf("HORIZONTAL: ");
			scanf("%d", &ll);
			printf("\n");
			printf("VERTICAL: ");
			scanf("%d", &hh);
			
			char sletter = box[hh][ll];
			checkBox(box, boxRR, fletter, sletter);
			
			gameR = finishGame(box, boxRR);
			
		}
		
		cleanScreen();
		printf("VOCE GANHOU!!");

}


void showBox(char box[N][M])
{
	int l, h;
	
	for(l=0; l<M; l++){
		for(h=0; h<N; h++){
			printf(" |%c| ", box[h][l]);
		}
	printf("\n\n");
	
	}
}

void showXBox(char box[N][M], char value)
{
	int l, h;
		
	for(l=0; l<M; l++){
		for(h=0; h<N; h++){
			if(box[h][l] == value)
			{
				printf(" |%c| ", box[h][l]);
			}
			else
			{
				printf(" |X| ");
			}
		}
	printf("\n\n");
	
	}
}

void showCheckedBox(char box[N][M], int ll, int hh, char value)
{
	int l, h;
		
	for(l=0; l<M; l++){
		for(h=0; h<N; h++){
			if(l == ll && h == hh)
			{
				printf(" |%c| ", box[h][l]);
			}
			else
			{
				printf(" |X| ");
			}
		}
	printf("\n\n");
	
	}
}

int checkBox(char box[N][M], char boxRR[N][M], char fletter, char sletter)
{
	
	if(fletter == sletter)
	{
		fillBoxRR(box, boxRR, fletter, sletter);
		
		cleanScreen();
		showBox(boxRR);
		printf("\nVOCE ACERTOU!!\n");
	}
	else
	{
		cleanScreen();
		showXBox(box, 'k');
		printf("\nVOCE ERROU\n");	
	}

	return 0;	
}

void fillBoxRR(char box[N][M], char boxRR[N][M], char fletter, char sletter)
{
	int l, h;
	
	for(l=0; l<M; l++){
		for(h=0; h<N; h++){
			
			if(box[h][l] == fletter || box[h][l] == sletter)
			{
				boxRR[h][l] = fletter;
			}
		
		}
	
	}
	
}

int finishGame(char box[N][M], char boxRR[N][M])
{
	int l, h;
	
	for(l=0; l<M; l++){
		for(h=0; h<N; h++){
			
			if(box[h][l] != boxRR[h][l])
			{
				return 1;
			}
		
		}
	
	}
	return 0;
}

void cleanScreen()
{
	system("cls");	
}

void await()
{
	sleep(5);
}
