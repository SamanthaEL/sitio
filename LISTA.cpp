// Ejercicio: Crear una lista que almacene n números enteros y calcule el menor y mayor de ellos.
#include <stdio.h>
#include<stdlib.h>
#include <conio.h>

struct Nodo{
	int num;
	Nodo *siguiente;
};

void insertar(Nodo *&,int);
void mostrar(Nodo *);
void calcularMayorMenor(Nodo *);

int main(){
	Nodo *lista=NULL;
	int num;
	char r;
	do{
		printf("Ingresa un numero: ");
		scanf("%d", &num);
		insertar(lista,num);
		printf("\n Deseas agregar otro numero a la lista? (s/n) \n");
		scanf("%s", &r);
	}while(r=='S' || r=='s');
	printf("\nLista: ");
	mostrar(lista);
	calcularMayorMenor(lista);
}

//función encargada de insertar elementos al final de la lista
void insertar(Nodo *&lista,int n){
	Nodo *nuevo_nodo = new Nodo();
	Nodo *aux;
	nuevo_nodo->num = n;
	nuevo_nodo->siguiente = NULL;
	
	if(lista == NULL){  //preguntsa si las lista está vacia
		lista = nuevo_nodo; //agrega el primer elemnto a la lista
	}
	else{
		aux = lista;  //el auxiliar apunta al inicio de la lista 
		while(aux->siguiente != NULL){ //recorre la lista
			aux = aux->siguiente; //avanza posiciones en la lista
		}
		aux->siguiente = nuevo_nodo; //agrego el nuevo nodo a la lista
	}
	printf("Se agrego correctamente el numero %d a la lista \n", n);
}

//Función encargada de mostrar todos los elementos de la lista
void mostrar(Nodo *lista){
	while(lista != NULL){
		printf("%d -> ", lista->num);
		lista = lista->siguiente; //avanza una posición en lista
	}
}

//Función que calcula el mayor y menor número de la lista
void calcularMayorMenor(Nodo *lista){
	int mayor =0, menor=99999;
	while(lista != NULL){
		if((lista->num)>mayor){ //calcula el mayor 
			mayor =  lista->num;
		}
		if((lista->num)<menor){ //calcula el menor
			menor =  lista->num;
		}
		lista = lista->siguiente; 
	}
	printf("\nEl numero mayor es: %d", mayor);
	printf("\nEl numero menor es: %d", menor);
}
