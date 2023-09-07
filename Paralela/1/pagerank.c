#include <stdio.h>
#include <stdlib.h>

#define NUM_PAGES 4
#define DAMPING_FACTOR 0.85
#define MAX_ITERATIONS 100
#define ERROR_THRESHOLD 0.0001

void pagerank(float adj_matrix[NUM_PAGES][NUM_PAGES], float page_rank[NUM_PAGES]) {
    float temp_rank[NUM_PAGES];
    int i, j, k;
    
    // Inicializar los valores iniciales de PageRank
    for (i = 0; i < NUM_PAGES; i++) {
        page_rank[i] = 1.0 / NUM_PAGES;
    }
    
    // Iterar hasta alcanzar la convergencia o el número máximo de iteraciones
    for (k = 0; k < MAX_ITERATIONS; k++) {
        float error = 0.0;
        
        // Calcular la próxima iteración del PageRank
        for (i = 0; i < NUM_PAGES; i++) {
            temp_rank[i] = 0.0;
            for (j = 0; j < NUM_PAGES; j++) {
                temp_rank[i] += adj_matrix[j][i] * page_rank[j];
            }
            temp_rank[i] *= DAMPING_FACTOR;
            temp_rank[i] += (1.0 - DAMPING_FACTOR) / NUM_PAGES;
            
            // Calcular el error acumulado en esta iteración
            error += fabs(temp_rank[i] - page_rank[i]);
        }
        
        // Actualizar el PageRank y comprobar la convergencia
        for (i = 0; i < NUM_PAGES; i++) {
            page_rank[i] = temp_rank[i];
        }
        
        if (error < ERROR_THRESHOLD) {
            break;
        }
    }
}

int main() {
    float adj_matrix[NUM_PAGES][NUM_PAGES] = {
        {0, 1, 1, 0},
        {1, 0, 1, 1},
        {1, 0, 0, 1},
        {1, 1, 0, 0}
    };
    float page_rank[NUM_PAGES];
    
    pagerank(adj_matrix, page_rank);
    
    printf("PageRank:\n");
    for (int i = 0; i < NUM_PAGES; i++) {
        printf("Page %d: %.4f\n", i + 1, page_rank[i]);
    }
    
    return 0;
}


