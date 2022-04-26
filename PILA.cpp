/*Ejercicio: Hacer un programa para agregar números enteros
a una pila hasta que el usuario lo decida, despues mostrar todos 
los números introducidos en la pila */

#include <stdio.h>
#include<stdlib.h>
#include <conio.h>

struct Nodo{
	int dato; 
	Nodo *siguiente;
};

void agregarPila(Nodo *&,int);
void sacarPila(Nodo *&,int &);

int main(){
	Nodo *pila = NULL;
	int dato;
	char r;
	do{
		printf(" Ingresa un numero \n");
		scanf("%d", &dato);
		agregarPila(pila,dato);
		printf("\n Deseas agregar otro dato a PILA? (s/n) \n");
		scanf("%s", &r);
		
	}while(r=='S' || r=='s');
	
	printf(" Sacando todos los elementos de PILA ");
	while(pila != NULL){ //mientras no sea el final de la pila
		sacarPila(pila,dato);
		if(pila != NULL){
			printf("%d , ", dato);
		}
		else{
			printf("\n %d . ", dato);
		}
	}
}

void agregarPila(Nodo*&pila, int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato=n;
	nuevo_nodo->siguiente=pila;
	pila = nuevo_nodo;
	printf("\n El elemento %d ha sido agregado a PILA correctamente",n);
}

void sacarPila(Nodo*&pila, int &n){
	Nodo *aux = pila;
	n= aux->dato;
	pila=aux->siguiente;
	delete aux;
}
