#include "raylib.h"

#include <stdlib.h>  
#include <time.h>
#include <stdlib.h>

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

void loadMenu(void) {
	ClearBackground(BLACK);
	DrawText("Visualizador de Algoritmos de Ordenacao", 100, 200, 30, WHITE);
	DrawText("Trabalho final da disciplina de Algoritmos E Estruturas De Dados I 2024", 150, 250, 15, WHITE);
	DrawText("Feito por Lucas Machado Cogrossi", 270, 275, 15, WHITE);
	DrawText("Pressione ENTER para inicar", 270, 400, 20, WHITE);
}

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 700;

	size_t n = screenHeight;

    InitWindow(screenWidth, screenHeight, "Visualizador de Algoritmos de Ordenação");

    SetTargetFPS(60);    


    while (!WindowShouldClose()) {
		srand(time(NULL));
        int *v;	
		v = (int*) malloc(n * sizeof(int));

		inicializa(v, n);
		shuffle(v, n);

        BeginDrawing();
		
			loadMenu();

        EndDrawing();
    }

    CloseWindow();
		return 0;
}
