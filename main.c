#include "raylib.h"
#include <stdlib.h>  
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

const int screenWidth = 800;
const int screenHeight = 700;

// Function adapted from Ben Pfaff's writing on shuffle:
// https://benpfaff.org/writings/clc/shuffle.html
void shuffle(int *v, size_t n) {	
	for (size_t i = 0; i < n - 1; ++i) {
	  size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
	  int t = v[j];
	  v[j] = v[i];
	  v[i] = t;
	}
}

void inicializa(int *v, size_t n) {	
	for (size_t i = 0; i < n; ++i) 
		v[i] = i; 
}

void sceneMenu(void) {
    ClearBackground(BLACK);

    const char *menuTitle = "Visualizador de Algoritmos de Ordenacao";
    DrawText(menuTitle, (screenWidth - MeasureText(menuTitle, 30)) / 2, 200, 30, BLUE);

    const char *menuSubtitle = "Trabalho final da disciplina de Algoritmos E Estruturas De Dados I 2024";
    DrawText(menuSubtitle, (screenWidth - MeasureText(menuSubtitle, 15)) / 2, 250, 15, BLUE);

    const char *menuSubSubTitle = "Feito por Lucas Machado Cogrossi";
    DrawText(menuSubSubTitle, (screenWidth - MeasureText(menuSubSubTitle, 15)) / 2, 275, 15, BLUE);

    const char *menuOp1 = "Pressione ENTER para iniciar";
    DrawText(menuOp1, (screenWidth - MeasureText(menuOp1, 20)) / 2, 400, 20, BLUE);
}

void sceneSubMenu(void) {
    ClearBackground(BLACK);

    const char *subMenuTitle = "Selecione o algoritmo";
    DrawText(subMenuTitle, (screenWidth - MeasureText(subMenuTitle, 30)) / 2, 200, 30, WHITE);

    const char *subMenuOp1 = "Pressione 1 para quick sort";
    DrawText(subMenuOp1, (screenWidth - MeasureText(subMenuOp1, 30)) / 2, 300, 30, WHITE);

    const char *subMenuOp2 = "Pressione 2 para bubble sort";
    DrawText(subMenuOp2, (screenWidth - MeasureText(subMenuOp2, 30)) / 2, 350, 30, WHITE);

    const char *subMenuOp3 = "Pressione 3 para merge sort";
    DrawText(subMenuOp3, (screenWidth - MeasureText(subMenuOp3, 30)) / 2, 400, 30, WHITE);

	const char *subMenuOp4 = "Pressione ENTER para embaralhar!";
    DrawText(subMenuOp4, (screenWidth - MeasureText(subMenuOp4, 20)) / 2, 500, 20, WHITE);
}

void drawVector(int *v, size_t n) {
	for (int i = 0; i <= n; i++) {
		DrawRectangle(i, screenHeight - v[i], 1, v[i], BLUE);
	}
}

void quickSort (int vet[], int posInicio, int posFim) {
	ClearBackground(BLACK);

    int posEsq, posDir, pivo, aux, i;
    posEsq = posInicio;
    posDir = posFim;
    pivo = vet[(posEsq + posDir) / 2];
    while (posEsq <= posDir) {
	    while (vet[posEsq] < pivo) {
            posEsq = posEsq + 1;
        }    
        while (vet[posDir] > pivo) {
            posDir = posDir - 1;
        }    
        if (posEsq <= posDir) {
   	        aux = vet[posEsq];
            vet[posEsq] = vet[posDir];
            vet[posDir] = aux;
		
            posEsq = posEsq + 1;
            posDir = posDir - 1;
        }      
    }
    if (posInicio < posDir){
        quickSort(vet, posInicio, posDir);
    }
    if (posFim > posEsq){
        quickSort(vet, posEsq, posFim);
	}
}

int main(void) {
    InitWindow(screenWidth, screenHeight, "Visualizador de Algoritmos de Ordenação");

    SetTargetFPS(144);

	double curTime = GetTime();

	bool showMenu = true;
	bool showSubMenu = false;
	bool showVector = false;
	bool startQuickSort = false;
	bool isSorted = false;

	srand(time(NULL));
	size_t n = screenWidth - 1;

    int *v;	
	v = (int*) malloc(n * sizeof(int));
	inicializa(v, n);

    while (!WindowShouldClose()) {
        BeginDrawing();
		
			if (showMenu) {
				sceneMenu();

			}
			showMenu = false;

            if (showSubMenu) {
                sceneSubMenu();
            }
            showSubMenu = false;

			if(showVector) {
			
				drawVector(v, n);
			}
			showVector = false;


			if (IsKeyPressed(KEY_ENTER)) {
				showSubMenu = true;
				showVector = true;
				shuffle(v, n);
			}

	
			if (IsKeyPressed(KEY_ONE)){
				showVector = true;
				showSubMenu = false;
				startQuickSort = true;
				quickSort(v, 0, n-1);
			}
            

        EndDrawing();
    }
    CloseWindow();
	return 0;
}