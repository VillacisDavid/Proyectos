#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_DOCUMENTS 10
#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordInfo;

void calculateTFIDF(float tfidf[MAX_DOCUMENTS][MAX_WORDS], int wordCount[MAX_DOCUMENTS][MAX_WORDS], int numDocuments, int numWords) {
    int i, j;
    int docFrequency[MAX_WORDS] = {0};

    // Calcula la frecuencia del documento para cada palabra
    for (i = 0; i < numDocuments; i++) {
        for (j = 0; j < numWords; j++) {
            if (wordCount[i][j] > 0) {
                docFrequency[j]++;
            }
        }
    }

    // Calcula la puntuación TF-IDF para cada palabra en cada documento
    for (i = 0; i < numDocuments; i++) {
        for (j = 0; j < numWords; j++) {
            float tf = (float) wordCount[i][j] / (float) numWords;
            float idf = log((float) numDocuments / (float) docFrequency[j]);
            tfidf[i][j] = tf * idf;
        }
    }
}

int main() {
    int numDocuments = 3;
    int numWords = 4;

    int wordCount[MAX_DOCUMENTS][MAX_WORDS] = {
        {2, 1, 0, 0},
        {0, 3, 1, 0},
        {1, 0, 2, 2}
    };

    float tfidf[MAX_DOCUMENTS][MAX_WORDS];

    calculateTFIDF(tfidf, wordCount, numDocuments, numWords);

    // Imprime la puntuación TF-IDF para cada palabra en cada documento
    int i, j;
    for (i = 0; i < numDocuments; i++) {
        printf("Documento %d:\n", i + 1);
        for (j = 0; j < numWords; j++) {
            printf("Palabra %d: %f\n", j + 1, tfidf[i][j]);
        }
        printf("\n");
    }

    return 0;
}


