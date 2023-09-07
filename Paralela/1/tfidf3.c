#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_DOCUMENTS 10
#define MAX_WORDS 1024
#define MAX_WORD_LENGTH 50

typedef struct WordInfo {
    char word[MAX_WORD_LENGTH];
    int count;
} WordInfo;

typedef struct DocInfo {
    WordInfo words[MAX_WORDS];
    int wordCount;
    int uniqueWordCount;
} DocInfo;

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

void calcularTFIDF( DocInfo *docs[MAX_DOCUMENTS], double *TFIDF[MAX_DOCUMENTS][MAX_WORDS], int cantidadDeDocumentos) {

    int i, ii;
    double TFs[MAX_DOCUMENTS][MAX_WORDS];
    double IDFs[MAX_DOCUMENTS][MAX_WORDS];

    /* Calcular TFs */
    for( i=0; i<cantidadDeDocumentos; i++){
        for( ii=0; ii<docs[i]->wordCount;ii++){
            TFs[i][ii] = docs[i]->words[ii].count / docs[i]->uniqueWordCount;
        }
    }

    /* Calcular en cuantos documentos aparece cada palabra */
    for( i=0; i<cantidadDeDocumentos; i++){
        for( ii=0; ii<docs[i]->wordCount;ii++){
            TFs[i][ii] = docs[i]->words[ii].count / docs[i]->wordCount;
        }
    }



    /*  */

}

void printDocInfo(DocInfo *doc){
    if(doc->wordCount>0){
        printf("Cantidad de palabras: %i\n", doc->wordCount);
        printf("Cantidad de palabras unicas: %i\n", doc->uniqueWordCount);
        for(int i=0; i < doc->wordCount; i++){
            printf("%i. %15s | cantidad: %i \n", i+1, doc->words[i].word, doc->words[i].count);
        }
    }else{
        printf("Documento vacio\n");
    }
}

void calcularPalabrasUnicas(DocInfo *doc){
    int i,ii,p_unicas=0;
    for(i=0; i<doc->wordCount;i++){
        p_unicas++;
        for(ii=0; ii<i;ii++){
            if(strncmp(doc->words[i].word,doc->words[ii].word,MAX_WORD_LENGTH)==0){
                p_unicas--;
                ii=i;
            }
        }
    }

    doc->uniqueWordCount=p_unicas;

}

void calcularFrecuencias(DocInfo *doc){
    /* calcula la cantidad de veces que aparece cada palabra en su documento */
    int contador;
    for(int i=0; i<doc->wordCount; i++){
        contador=0;
        for(int ii=0; ii<doc->wordCount; ii++){
            if(strncmp(doc->words[i].word, doc->words[ii].word, MAX_WORD_LENGTH)==0){
                contador++;
            }
        }
        doc->words[i].count=contador;
    }

}

void tokenizarLinea(char *linea, DocInfo *docInfo){

    /*
        Procesa las lineas del documento y rellena docInfo
    */

    const char *s = " \t\n.,;:!?'\"";
    char *token; // Palabra
    int contadorPalabras=docInfo->wordCount;
    
    /* get the first token */
    token = strtok(linea, s);
   
    /* walk through other tokens */
    while( token != NULL ) {
        /* Copiar el token en la lista de palabras del documento */
        strncpy(docInfo->words[contadorPalabras].word, token, MAX_WORD_LENGTH) ;
        contadorPalabras++;
        token = strtok(NULL, s);
    }

    docInfo->wordCount=contadorPalabras;

}

DocInfo* procesarTxtSimple(const char *fname){
    
    DocInfo *docInfo = (DocInfo*) malloc(sizeof(DocInfo));
    FILE* filePointer;
    const int bufferLength = 1024;
    char buffer[bufferLength];

    /*
        Abre el document0, lo separa en lineas
    */

    filePointer = fopen(fname, "r");
    
    while(fgets(buffer, bufferLength, filePointer)) {
        /* procesa cada linea rellenando docInfo */
        tokenizarLinea(buffer, docInfo);
    }
    fclose(filePointer);

    calcularFrecuencias(docInfo);
    calcularPalabrasUnicas(docInfo);
    
    return docInfo;

}

int main(int argc, char **argv) {

    const int cantidadDeDocumentos = 3; 
    const char *filenames[MAX_DOCUMENTS] = {
        "./input/sample1.txt",
        "./input/sample2.txt",
        "./input/sample3.txt"    
    };

    DocInfo *docs[MAX_DOCUMENTS];

    /* Obtener la informacion de todos los documentos */

    for(int i=0; i<cantidadDeDocumentos; i++){
        docs[i] = procesarTxtSimple(filenames[i]);
    }

    /* Calcular TF-IDF */

    // double tfidf[MAX_DOCUMENTS][MAX_WORDS];
    // calcularTFIDF(docs,&tfidf,cantidadDeDocumentos);

    /* Mostrar los documentos */

    for(int i=0; i<cantidadDeDocumentos; i++){
        printf("\t### Documento %i ###\n", i+1);
        printDocInfo(docs[i]);
        /* liberar memoria */
        //free(docs[i]);
    }

    return 0;
}




