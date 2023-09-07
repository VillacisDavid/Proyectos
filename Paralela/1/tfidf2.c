#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_DOCUMENTS 10
const int MAX_TERMS = 1024;
#define MAX_TERM_LENGTH 50

typedef struct {
    char term[MAX_TERM_LENGTH];
    int count;
} TermInfo;

typedef struct {
    TermInfo terms[MAX_TERMS];
    int numTerms;
} Document;


void tokenizeContent(char *content, Document *document) {
    char *token;
    token = strtok(content, " \t\n.,;:!?'\"");

    while (token != NULL) {
        int i;
        for (i = 0; i < document->numTerms; i++) {
            if (strcmp(token, document->terms[i].term) == 0) {
                document->terms[i].count++;
                break;
            }
        }

        if (i == document->numTerms) {
            strcpy(document->terms[i].term, token);
            document->terms[i].count = 1;
            document->numTerms++;
        }

        token = strtok(NULL, " \t\n.,;:!?'\"");
    }
}

void calculateTFIDF(float tfidf[MAX_DOCUMENTS][MAX_TERMS], Document *documents, int numDocuments) {
    
    int i, j;
    int docFrequency[MAX_TERMS] = {0};
	    for (i = 0; i < numDocuments; i++) {
	        for (j = 0; j < documents[i].numTerms; j++) {
	            if (documents[i].terms[j].count > 0) {
	                docFrequency[j]++;
	            }
	        }
	    }

	    // Calcula la puntuación TF-IDF para cada término en cada documento
	    for (i = 0; i < numDocuments; i++) {
	        for (j = 0; j < documents[i].numTerms; j++) {
	            float tf = (float) documents[i].terms[j].count / (float) documents[i].numTerms;
	            float idf = log((float) numDocuments / (float) docFrequency[j]);
	            tfidf[i][j] = tf * idf;
	        }
	    }
}

int main(int argc, const char *argv[]) {
    int numDocuments = 3;
    Document documents[MAX_DOCUMENTS];

    // Leer los archivos de texto dados en el classroom
    char *documentFiles[MAX_DOCUMENTS] = {
        (char*)"./input/sample1.txt",
        (char*)"./input/sample2.txt",
        (char*)"./input/sample3.txt"
    };

    for (int i = 0; i < numDocuments; i++) {
        FILE *file = fopen(documentFiles[i], "r");
        if (file == NULL) {
            fprintf(stderr, "No se pudo abrir el archivo: %s\n", documentFiles[i]);
            continue;
        }
        
        char line[1024];
        char content[90000] = "";
        while (fgets(line, sizeof(line), file)) {
            strcat(content, line);
        }

        // Generar el recuento de términos
        tokenizeContent(content, &documents[i]);

        fclose(file);
    }

    float tfidf[MAX_DOCUMENTS][MAX_TERMS];
    calculateTFIDF(tfidf, documents, numDocuments);
	//Imprimir
    int i, j;
    for (i = 0; i < numDocuments; i++) {
        printf("Documento %d:\n", i + 1);
        for (j = 0; j < documents[i].numTerms; j++) {
            printf("Termino: %s, TF-IDF: %f\n", documents[i].terms[j].term, tfidf[i][j]);
        }
        printf("\n");
    }

    return 0;
}