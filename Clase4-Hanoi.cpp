#include <iostream>

using namespace std;

struct nodo {
    int cantidad;
    nodo *siguiente=NULL;
};

typedef struct nodo *TpNodo;
bool popd= false;

void menu(){
    int n = 0;
    if(popd){
        n=1;
    }
    string opc[2] = {"Pop:","Push:"};
    cout<<"\nTorre de Hanoi"<<endl;
    cout<<"\n Seleccionar torre...\n"<<endl;
    cout<<opc[n]<<"--->";
}


TpNodo CrearNodo(int valor){
    TpNodo nuevoNodo = new(struct nodo);
    nuevoNodo->cantidad = valor;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

void Push(TpNodo &Stack, int valor){
    TpNodo newTop = CrearNodo(valor);
    if(Stack != NULL){
        newTop->siguiente = Stack;
    }
    Stack = newTop;
}

void PushAdd(TpNodo &Stack, TpNodo q){
    if(Stack!=NULL){
		q->siguiente=Stack;
    }
	Stack=q;
}

TpNodo Pop(TpNodo &Stack){
    TpNodo t=Stack;
 	Stack=Stack->siguiente;
 	t->siguiente = NULL;
 	cout<<"\nNodo extraido Nr. " <<t->cantidad<<endl<<endl;
 	return t;
}

void mostrar(TpNodo lista){
	TpNodo p=lista;
	int n=1;
	cout<<"-------------------Top"<<endl;
	while(p!=NULL){
		cout<<p->cantidad<<endl;
		p=p->siguiente;
		n++;
    }
    cout<<"-------------------Bottom"<<endl;

}

bool isComplete(TpNodo stackC){
    TpNodo p=stackC;
    int total=0;
    while(p!=NULL){
        total+=p->cantidad;
        p=p->siguiente;
    }
    if(total==3210){
        return true;
    }
    return false;
}

int main(){

    char seleccionado;
    int movimientos=0;
    TpNodo stackA = NULL, stackB = NULL, stackC = NULL;
    TpNodo temp = NULL;

    Push(stackA, 3000);
    Push(stackA, 200);
    Push(stackA, 10);

    do{
        system("cls");
        cout<<"Torre A"<<endl;
        mostrar(stackA);
        cout<<"Torre B"<<endl;
        mostrar(stackB);
        cout<<"Torre C"<<endl;
        mostrar(stackC);
        cout<<"movimientos: "<<movimientos<<endl;
        if(popd){
            movimientos++;
            cout<<"\n disco levantado:"<<temp->cantidad<<endl;
        }
        menu();
        cin>>seleccionado;

        if(!popd){
            switch(seleccionado){
                case 'a':
                    if(stackA!=NULL){
                        temp = Pop(stackA);
                        popd=true;
                    }else{
                        cout<<"pila vacia"<<endl;
                    }
                    break;
                case 'b':
                    if(stackB!=NULL){
                        temp = Pop(stackB);
                        popd=true;
                    }else{
                        cout<<"pila vacia"<<endl;
                    }
                    break;
                case 'c':
                    if(stackC!=NULL){
                        temp = Pop(stackC);
                        popd=true;
                    }else{
                        cout<<"pila vacia"<<endl;
                    }
                    break;
            }
        }else{
            switch(seleccionado){
                case 'a':
                    if(stackA==NULL || stackA->cantidad > temp->cantidad){
                        PushAdd(stackA, temp);
                        popd=false;
                    }else{
                        cout<<"no se puede apilar"<<endl;
                    }
                    break;
                case 'b':
                    if(stackB==NULL || stackB->cantidad > temp->cantidad){
                        PushAdd(stackB, temp);
                        popd=false;
                    }else{
                        cout<<"no se puede apilar"<<endl;
                    }
                    break;
                case 'c':
                    if(stackC==NULL || stackC->cantidad > temp->cantidad){
                        PushAdd(stackC, temp);
                        popd=false;
                    }else{
                        cout<<"no se puede apilar"<<endl;
                    }
                    break;
            }
        }
        //system("PAUSE");
    }while(!isComplete(stackC));

    system("cls");
    cout<<"Felicidades..."<<endl;
    cout<<"Numero de movimientos: "<<movimientos<<endl;
    if(movimientos==7){
        cout<<"Perfecto!!!"<<endl;
    }

    return 0;
}

/*solucion
a
c
a
b
c
b
a
c
b
a
b
c
a
c
*/


