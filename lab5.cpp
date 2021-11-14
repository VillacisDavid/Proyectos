#include <iostream>

using namespace std;

struct nodo{
    char establecimiento;
	int paquetes;
    int distSgte;
    struct nodo *ant;
	struct nodo *sgte;
    bool entregar;
};

int nrnodos=0;
typedef struct nodo *TpNodo;// Definiendo un tipo de dato tipo struct nodo 

TpNodo CrearNodo(char name, int paquetes, int dSgte){
		TpNodo nuevo = new(struct nodo);
        nuevo->establecimiento=name;
		nuevo->paquetes=paquetes;
        nuevo->distSgte=dSgte;
        nuevo->ant=NULL;
		nuevo->sgte=NULL;
        nuevo->entregar=true;
		return nuevo;
}

void InsertarFinal(TpNodo &lista, char name, int paquetes,int dSgte){
	TpNodo p=lista, q = CrearNodo(name,paquetes,dSgte);
	if(lista==NULL)
	   lista=q;
	else{
		while(p->sgte != NULL)
			p=p->sgte;
		p->sgte=q;
		q->ant=p;	
	}   
}

void menu(){
	cout<<endl;
	cout<<"1.- Ir al siguiente "<<endl;
	cout<<"2.- Ir al anterior "<<endl; 
	cout<<"3.- Agregar parada"<<endl;
		
	cout<<"\n0.- Salir"<<endl;
	cout<<"\nIngresar Opcion ---> ";
}


void MostrarLista(TpNodo lista, TpNodo pos, int km, int pqt){
 	TpNodo p=lista, t=NULL;
	int	n=1;
	cout<<"RECORRIDO DEL CAMION"<<endl;
	while(p!=NULL){
		cout<<"La parada "<<n<<" es en ---> "<< p->establecimiento;
        if(pos->establecimiento==p->establecimiento){
            cout<<" <---"<<endl;
            cout<<"Distancia recorrida: "<<km<<"km | Paquetes en bodega: "<<pqt;
            cout<<" | Paquetes del establecimiento: "<<p->paquetes<<" | paquetes entregados: "<<30-pqt<<endl;
        }else{
            cout<<endl;
        }

        cout<<"\t|distancia: "<<p->distSgte<<endl;
		t=p;
		p=p->sgte;
		n++;
	}

}

void InsertarPosicion(TpNodo &lista, int pos){
	TpNodo p=lista, q=NULL;
	int x=1;
	bool flag = false;

    if(pos==1){
		cout<<"No se puede insertar en esta posicion"<<endl;
        system("pause");
		return;
	}
	
	q=CrearNodo('x',0,0);
	while(p->sgte != NULL && x!= pos){
		p=p->sgte;
		x++;
		if(x==pos)
			flag=true;
	}
	if(flag ==true){

			q->sgte =p;
			p->ant->sgte=q;
			q->ant=p->ant;
			p->ant=q;	

            cout<<"Nombre: ";cin>>q->establecimiento;
            cout<<"Distancia del anterior: ";cin>>q->ant->distSgte;
            cout<<"Distancia del siguiente: ";cin>>q->distSgte;
            cout<<"Paquetes a entregar: ";cin>>q->paquetes;
	}
	else{
		cout<<"ERROR: Posicion "<<pos<< " ingresada No Existe "<<endl;
		system("pause");
	}
}


int main( ) {
	TpNodo lista=NULL,posicion=NULL;
	int opc,pos, totalDistancia=0, paquetesRestantes=30;
    InsertarFinal(lista,'S',0,5);
    lista->entregar=false;
    InsertarFinal(lista,'A',3,3);
    InsertarFinal(lista,'B',10,6);
    InsertarFinal(lista,'C',5,8);
    InsertarFinal(lista,'D',4,0);

    posicion=lista;

	do{
        system("cls");
        MostrarLista(lista,posicion,totalDistancia,paquetesRestantes);
		menu();
		cin>>opc;
		switch(opc){
			case 1:
                if(posicion->sgte!=NULL){
                    totalDistancia+=posicion->distSgte;
                    posicion = posicion->sgte;
                    if(posicion->entregar){
                        paquetesRestantes-=posicion->paquetes;
                        cout<<"Se entrego "<<posicion->paquetes<<" paquetes."<<endl;
                        posicion->entregar=false;
                    }
                }else{
                    cout<<"Es hora de volver"<<endl;
                }
                system("pause");
                break;
			case 2:
                if(posicion->ant!=NULL){
                    posicion = posicion->ant;
                    totalDistancia+=posicion->distSgte;
                }else{
                    cout<<"No hay a donde ir"<<endl;
                }
                system("pause");
                break;
            case 3:
                cout<<"Posicion: ";cin>>pos;
                InsertarPosicion(lista,pos);
                break;
		}//switch
	}while(opc !=0);
	
	return 0;
}
