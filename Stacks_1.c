/*
Pilas. Representar e implementar una Pila de 50 items de
cualesquiera de las estructuras presentadas mas conveniente
para el caso, incluyendo las funciones: apilar, desapilar,
cantidad de elementos, pila vacía, pila llena, se debe utilizar
arreglos
*/

#include <stdio.h>
#include <stdlib.h>


//Estructuras

typedef struct {
	
	char isbn[20];
	char titulo [60];
	char autor [30];
	char editorial [30];
	int anio_publicacion;
}Libro;

//Prototipos de funciones para las pilas

int isEmpty(); //Pila Vacia
void Check(); //Cantidad De elementos.
int isFull(); //Pila Llena
int pop(); //Apilar
int push(); //Desapilar
int MenuStacks();

//Prototipo de funciones para el menu de libros o de la estructura elegida.

void MenuBooks();
int AddBook();
int DisplayBooks();

//Variables globales

int maxSize = 50;
int stack[50];
int n = -1; //Variable para guardar la entrada de número de elementos.
int choice;
Libro inventario[50];

int main(){
	
	do
	{
		puts("Ingrese el tamaño de la pila de productos, máximo 50");
		scanf("%d",&n);
		if (n > maxSize -1)
		{
			system("cls");
			puts("Sobrecarga de la pila, la cantidad supera los 50 productos, vuelva a intentarlo");
		}
		else
		if (n <= 0)
		{
			system("cls");
			puts("Introduzca solo numeros mayores a 0, vuelva a intentarlo");
		}

	} while (n > maxSize -1 || n <= 0);
	
	system("cls");

	MenuStacks();
	
	
	return 0;
}

int MenuStacks()
{
		do 
	{
		printf("\n Introduzca una opcion");
		printf("\n\t 1.Apilar \n\t 2.Desapilar \n\t 3.Ver Cantidad de Elementos \n\t 4.Comprobar Pila Vacia \n\t 5.Comprobar Pila Llena \n\t 6.Ver Menu Libros \n\t 7.Salir\n");
		scanf("%d",&choice);
		
		
		
		switch(choice)
		{
			case 1:
				{
					push(n);
					break;
				}
			case 2:
				{
					pop();
					break;
				}
			case 3:
				{
					Check();
					break;
				}
			case 4:
				{
					isEmpty();
					break;
				}
			case 5:
				{
					isFull();
					break;
				}
			case 6:
				{
					MenuBooks();
					break;
				}
			default: 
			{
				system("cls");
				printf("\n Elección Inválida.");
			}
				
				
		}
	}
	while(choice != 7);
}

void MenuBooks()
{
	do
	{
	printf("\n Introduzca una opcion");
	printf("\n\t 1.Añadir Libros \n\t 2.Ver Libros \n\t 3.Volver al menu principal\n");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:
			{
				AddBook();
			}
		case 2:
			{
				DisplayBooks();
			}
		default: 
			{
			printf("\n Elección Inválida");
			}
	}
	}while (choice != 3);
	
	MenuStacks();

}

int isEmpty(){
	
	system("cls");

	if (n == -1){
		
		puts("La pila está vacía, no puede desapilar más elementos");
		return 1;
	}
	else
	puts("La pila no está vacía");
	return 0;
}

void Check(){ 
	system("cls");
	printf("La cantidad de elementos en el stack es de: %d",n);
}

int isFull(){
	
	system("cls");

	if (n == maxSize){ 
		puts("La pila está llena, no puede apilar más elementos");
		return 1;
	}
	else
	puts("La pila aún no está llena");
	return 0;
}


int pop(){
	system("cls");
	int data; //variable que guardará la variable del tope antes de desapilar
	
	if (!isEmpty())
	{
		data = stack[n];
		n = n -1;
		return n;
	}
	else{
		return 0;
	}
	
}

int push(int data)
{
	system("cls");
	if(!isFull())
	{
		n++;
		puts("se ha apilado correctamente");
		return 1;
	}
	else
	{
		return 0;
	}
	
}

int AddBook()
{
	return 0;
}

int DisplayBooks()
{
	return 0;
}
