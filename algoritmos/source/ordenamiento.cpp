#include<iostream>
#include<vector>
#include<omp.h>
#include<string>

std::vector<int> crear_vector_desordenado(int vec_size){
    std::vector<int> vec;
    for (int i = 0; i < vec_size; i++){
        vec.push_back(rand()%1000);
    } 
    return vec;  
}

void mostrar_vector(std::vector<int> vec, std::string label){
    std::cout<<label<<": [ ";
    for ( std::vector<int>::iterator i = vec.begin(); i != vec.end(); i++){
        std::cout<< *i << " ";
    }
    std::cout<<" ]"<<std::endl;
}

int getpivot(std::vector<int> vec){
    int pivot;
    int n1,n2,n3;
    n1 = vec[rand()%vec.size()];
    n2 = vec[rand()%vec.size()];
    n3 = vec[rand()%vec.size()];
    pivot = (n1 + n2 + n3)/3;
    return pivot;
}

void insertionsort(std::vector<int> &vec){
    if(vec.size()<2) return;
    int key;
    std::vector<int>::iterator i;
    std::vector<int>::reverse_iterator j;
    for (i = vec.begin()+1; i != vec.end(); i++){
        key = *i;
        j=std::vector<int>::reverse_iterator(i);
        for (j; j != vec.rend() && *j>key; j++){
            *(j-1)=*j;
        }
        *(j.base())=key;
    }
}

void quicksort(std::vector<int> &vec){
    int pivote;
    std::vector<int> menores,mayores;
    std::vector<int>::iterator i,j;

    if(vec.size()<20){
        insertionsort(vec);
        return;
    }

    pivote = getpivot(vec);

    for (i=vec.begin(); i!=vec.end(); i++){
        if(*i<pivote){
            menores.push_back(*i);
        }else{
            mayores.push_back(*i);
        }
    }

    quicksort(menores);
    quicksort(mayores);
    
    vec=menores;
    for(j=mayores.begin();j!=mayores.end();j++){
        vec.push_back(*j);
    }

}

int main(int argc, char const *argv[]){
    /* Cantidad de elementos a ordenar */
    int NUM_ELEMENTOS, iteraciones;
    
    NUM_ELEMENTOS=5000;
    iteraciones=10000;

    srand((unsigned) time(NULL));
    double inicio,fin;
    /* Iniciar vector */
    std::vector<int> vector;
    //mostrar_vector(vector, "desordenado");

    double sum=0;
    for (int i = 0; i < iteraciones; i++){
        vector.clear();
        vector = crear_vector_desordenado(NUM_ELEMENTOS);
        inicio = omp_get_wtime();
        /* Ordenamiento */
        //std::cout<<"Haciendo quicksort..."<<std::endl;
        quicksort(vector);
        //std::cout<<"listo"<<std::endl;
        //mostrar_vector(vector, "ordenado");

        fin = omp_get_wtime() - inicio;
        sum += fin;
    }
    
    // Controlar el tiempo de ejecucion 
    std::cout <<"Suma de tiempos de ordenamiento: "<< sum <<std::endl;
    std::cout <<"Promedio de tiempos de ordenamiento: "<< sum/iteraciones <<std::endl;

    return 0;
}
