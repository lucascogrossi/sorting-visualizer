#include "raylib.h"
#include <stdlib.h>

// cc main.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11


const int screenWidth = 800;
const int screenHeight = 700;

// https://benpfaff.org/writings/clc/shuffle.html
void shuffle(int *v, int n) {    
    for (int i = 0; i < n - 1; ++i) {
        int j = i + rand() / (RAND_MAX / (n - i) + 1);
        int t = v[j];
        v[j] = v[i];
        v[i] = t;
    }
}

void inicializa(int *v, int n) {    
    for (int i = 0; i < n; ++i) 
        v[i] = rand() % screenHeight;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sceneMenu(void) {
    ClearBackground(BLACK);

    const int screenWidth = 800;
    const int screenHeight = 700;

    const char *menuTitle = "Visualizador de Algoritmos de Ordenacao";
    DrawText(menuTitle, (screenWidth - MeasureText(menuTitle, 30)) / 2, screenHeight / 2 - 150, 30, WHITE);

    const char *menuSubtitle = "Trabalho final da disciplina de Algoritmos E Estruturas De Dados I 2024";
    DrawText(menuSubtitle, (screenWidth - MeasureText(menuSubtitle, 15)) / 2, screenHeight / 2 - 100, 15, WHITE);

    const char *menuSubSubTitle = "Feito por Lucas Machado Cogrossi";
    DrawText(menuSubSubTitle, (screenWidth - MeasureText(menuSubSubTitle, 15)) / 2, screenHeight / 2 - 75, 15, WHITE);

    const char *menuOp1 = "Pressione ENTER para iniciar";
    DrawText(menuOp1, (screenWidth - MeasureText(menuOp1, 20)) / 2, screenHeight / 2 + 100, 20, WHITE);

}

void sceneSubMenu(void) {
    ClearBackground(BLACK);

    const char *subMenuTitle = "Selecione o algoritmo";
    DrawText(subMenuTitle, (screenWidth - MeasureText(subMenuTitle, 30)) / 2, 200, 30, WHITE);

    const char *subMenuOp1 = "Pressione 1 para bubble sort";
    DrawText(subMenuOp1, (screenWidth - MeasureText(subMenuOp1, 30)) / 2, 300, 30, WHITE);

    const char *subMenuOp2 = "Pressione 2 para merge sort";
    DrawText(subMenuOp2, (screenWidth - MeasureText(subMenuOp2, 30)) / 2, 350, 30, WHITE);

    const char *subMenuOp3 = "Pressione 3 para quick sort";
    DrawText(subMenuOp3, (screenWidth - MeasureText(subMenuOp3, 30)) / 2, 400, 30, WHITE);

}

int main(void) {
    int i = 0, j = 0;
    bool startBubbleSort = false;
    bool showMenu = true;
    bool showSubMenu = false;
    bool showVector = false;
    bool startQuickSort = false;

    InitWindow(screenWidth, screenHeight, "Trabalho final AED1");

    SetTargetFPS(5000);

    int n = screenWidth;
    int *v;    
    v = (int*) malloc(n * sizeof(int));
    inicializa(v, n);
    shuffle(v, n);

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_BACKSPACE)) {
            showMenu = false;
            showSubMenu = true;
            shuffle(v, n);
            showVector = false;
            sceneSubMenu();
            startBubbleSort = false;
            i = 0;
            j = 0;
        }

        if(showMenu) {
            sceneMenu();
        }

        if(showSubMenu) {
            sceneSubMenu();
        }


        if (IsKeyPressed(KEY_ONE)) {
            showMenu = false;
            showSubMenu = false;
            showVector = true;
            startBubbleSort = true;
            
        }
        
        BeginDrawing();
            ClearBackground(BLACK);
            
            if (startBubbleSort) {
                int a = v[j];
                int b = v[j + 1];
                if (a > b) {
                    swap(&v[j], &v[j + 1]);
                }
                
                if (i < n) {
                    j = j + 1;
                    if (j >=  n - i - 1) {
                        j = 0;
                        i  = i + 1;
                    }
                }
            }

            if (showVector) {
                for (int k = 0; k < n; k++) {
                    DrawRectangle(k, screenHeight - v[k], 1, v[k], WHITE);
                }
            }

        EndDrawing();
    }

    free(v);
    CloseWindow();       
    return 0;
}
