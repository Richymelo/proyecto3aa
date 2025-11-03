// proyecto-3aa.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Maximo de nodos, basado en K <= 12
#define MAX_NODOS 12

typedef enum {
    NO_DIRIGIDO,
    DIRIGIDO
} TipoGrafo;

typedef struct {
    int K;                             // Numero de nodos (K)
    TipoGrafo tipo;                    // Tipo de grafo (DIRIGIDO/NO_DIRIGIDO)
    int matriz_adyacencia[MAX_NODOS][MAX_NODOS]; // Matriz KxK (binaria, 0 o 1)
    Coordenada posiciones[MAX_NODOS];  // Arreglo de K coordenadas (x, y)
} Grafo;

typedef struct {
    int x;
    int y;
} Coordenada;

bool validar_Num(int k) {

}

bool tipo_Grafo() {

}

int matrizAdj(int **matriz) {
    int i, j;
    int valor;

    // Inicializar la matriz a 0
    for (i = 0; i < g->K; i++) {
        for (j = 0; j < g->K; j++) {
            g->matriz_adyacencia[i][j] = 0;
        }
    }

    printf("\n--- Ingreso de Matriz de Adyacencia (%d x %d) ---\n", g->K, g->K);
    printf("Ingrese 1 si existe una arista, 0 para no arista. \n");//La diagonal (i=j) no es editable (debe ser 0).
    if (g->tipo == NO_DIRIGIDO) {
        printf("Grafo No Dirigido\n"); //: Al ingresar (i, j) = 1, automaticamente se establece (j, i) = 1.
    }

    // Ingreso interactivo de aristas (conexiones)
    while (true) {
        char respuesta;
        printf("Desea ingresar una arista? (s/n): ");
        // Limpiar buffer y leer respuesta
        while (getchar() != '\n');
        if (scanf(" %c", &respuesta) != 1 || (respuesta != 's' && respuesta != 'S' && respuesta != 'n' && respuesta != 'N')) {
            printf("Respuesta no valida. Intente de nuevo.\n");
            continue;
        }

        if (respuesta == 'n' || respuesta == 'N') {
            break; // Salir del bucle
        }

        // Ingresar posiciones de la arista
        printf("Ingrese nodo de origen (0 a %d): ", g->K - 1);
        while (scanf("%d", &i) != 1 || i < 0 || i >= g->K) {
            while (getchar() != '\n');
            printf("indice de origen no v�lido. Reingrese (0 a %d): ", g->K - 1);
        }

        printf("Ingrese nodo de destino (0 a %d): ", g->K - 1);
        while (scanf("%d", &j) != 1 || j < 0 || j >= g->K) {
            while (getchar() != '\n');
            printf("indice de destino no v�lido. Reingrese (0 a %d): ", g->K - 1);
        }

        if (i == j) {
            printf("**ERROR**: La diagonal no es editable. No se permiten bucles/lazos (i=j).\n");
            continue;
        }

        // Se asume que el usuario altera los 0s iniciales a 1.
        g->matriz_adyacencia[i][j] = 1;

        if (g->tipo == NO_DIRIGIDO) {
            g->matriz_adyacencia[j][i] = 1; // Simetria para grafo no dirigido
            printf("Arista (%d, %d) y (%d, %d) establecida.\n", i, j, j, i);
        }
        else {
            printf("Arista (%d, %d) establecida.\n", i, j);
        }
    }

    printf("\nMatriz de Adyacencia final:\n");
    for (i = 0; i < g->K; i++) {
        for (j = 0; j < g->K; j++) {
            printf("%d ", g->matriz_adyacencia[i][j]);
        }
        printf("\n");
    }
}

bool posicionDuplicada(const Coordenada* posiciones, int K, int x, int y) {
    for (int i = 0; i < K; i++) {
        if (posiciones[i].x == x && posiciones[i].y == y) {
            return true;
        }
    }
    return false;
}

void posicion_Nodos() {

}

int grabar_Archivo(char archivo){

}

int cargar_Archivo(char archivo){

}


void main()
{
    
}
