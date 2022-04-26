#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

struct Nodo{
	int dato;
	Nodo *der;
	Nodo *izq;
};

void menu();
Nodo *crearNodo(int);
void insertarNodo(Nodo *&arbol, int);
void mostrarArbol(Nodo *,int);

Nodo *arbol = NULL;

int main (){
	menu();
	
	getch();
	return 0;
}
//Función del Menú
void menu(){
	int dato, op, contador=0;
	
	cout<<"\t Menu"<<endl;
		cout<<"1. Poner un nodo nuevo"<<endl;
		cout<<"2. Mostrar el arbol"<<endl;
		cout<<"3. SALIR"<<endl;
	
	do{
		cout<<"Ingresa la opcion deseada: ";
		cin>>op;
		switch(op){
			case 1: cout<<"\n Digite un numero: ";
			cin>>dato;
			insertarNodo(arbol,dato);
			break;
			case 2: cout<<"\nMostrando arbol: \n \n";
			    mostrarArbol(arbol,contador);  
			break;
		}
		
	}while(op != 3);
}

//Creación del nuevo nodo

Nodo *crearNodo(int n){

    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->der = NULL;
    nuevo_nodo->izq = NULL;
    
    return nuevo_nodo;
}

//Función que inserta un nodo en el arbol

void insertarNodo(Nodo *&arbol,int n){
	if(arbol == NULL){
		Nodo *nuevo_nodo = crearNodo(n);
		arbol = nuevo_nodo;
	}
	else{
		int valorRaiz = arbol->dato;
		if(n < valorRaiz){
			insertarNodo(arbol->izq,n);
		}
		else{
			insertarNodo(arbol->der,n);
		}
	}
}

//Función que muestrar el árbol
void mostrarArbol(Nodo *arbol,int cont){
	if(arbol == NULL){
	}
	else{
		mostrarArbol(arbol->der, cont+1);
		for(int i=0;i<cont;i++){
			cout<< "  ";
		}
		cout<<arbol->dato<<endl;
		mostrarArbol(arbol->izq,cont+1);	
	}
}
