/*
Pilas. Representar e implementar una Pila de 20 items de
cualesquiera de las estructuras presentadas mas conveniente
para el caso, incluyendo las funciones: apilar, desapilar,
cantidad de elementos, pila vacía, pila llena, se debe utilizar
arreglos
*/

#include <stdio.h>
#include <stdlib.h>


//Estructuras

typedef struct{

	int dia;
	int mes;
	int anio;

}Fecha;

typedef struct {
	char codigo[20];
	char nombre[60];
	char grupo[30];
	char sexo[2];
	char color[30];
	Fecha fecha_nacimiento;
}Animal;

//Prototipos de funciones para las pilas

int PilaVacia(); 
void CantidadDeElementos(); 
int PilaLlena();
void Desapilar();
void Apilar(); 
void MenuPilas();

//Prototipo de funciones para la implementación de la estructura elegida.

void MenuAnimales();
void RegistrarAnimal();
void ImprimirAnimal();
void ImprimirAnimales();

//Variables globales

int TamanioMaximo = 20;
int pila[20];
int n = 0; //Variable para guardar la entrada de número de elementos.
int opcion;
Animal animal[20];

int main(){

	MenuPilas();
	
	return 0;
}

void MenuPilas()
{
	system("cls");
		do 
	{
		printf("\n\t\t- Introduzca una Opci%cn",162);
		printf("\n\n\t\t 1.Apilar");
		printf("\n\t\t 2.Desapilar");
		printf("\n\t\t 3.Ver Cantidad de Elementos");
		printf("\n\t\t 4.Comprobar Pila Vacia");
		printf("\n\t\t 5.Comprobar Pila Llena");
		printf("\n\t\t 6.Ver Menu Animales");
		printf("\n\t\t 7.Salir");
		printf("\n\n\t\t Ingrese su opci%cn: ",162);
		scanf("%d",&opcion);
		
		
		
		switch(opcion)
		{
			case 1:
				{
					Apilar();
					break;
				}
			case 2:
				{
					Desapilar();
					break;
				}
			case 3:
				{
					CantidadDeElementos();
					break;
				}
			case 4:
				{
					PilaVacia();
					break;
				}
			case 5:
				{
					PilaLlena();
					break;
				}
			case 6:
				{
					MenuAnimales();
					break;
				}
			default: 
			{
				system("cls");
				printf("\n Elecci%cn Inv%clida.",162,131);
			}
				
				
		}
	}
	while(opcion != 7);
}

void MenuAnimales()
{
	system("cls");
	do
	{
		printf("\n\t\t- Introduzca una Opci%cn",162);
		printf("\n\n\t\t 1.Imprimir Todos los Animales");
		printf("\n\t\t 2.Imprimir un Animal");
		printf("\n\t\t 3.Volver al Menu Principal");
		printf("\n\n\t\t Ingrese su Opci%cn: ",162);
		scanf("%d",&opcion);
	
	switch(opcion)
	{
		case 1:
			{
				ImprimirAnimales();
			}
		case 2:
			{
				ImprimirAnimal();
			}
		case 3:
			{
				MenuPilas();
			}
		default: 
			{
			printf("\n Elecci%cn Inv%clida",162,131);
			}
	}
	}while (opcion != 3);
	
	
}

int PilaVacia(){
	
	system("cls");

	if (n == 0){
		
		printf("\t\tLa pila est%c vac%ca, no puede desapilar m%cs elementos",160,161,160);
		return 1;
	}
	else
	{
		printf("\t\tLa pila no se encuentra vac%ca",161);
	}
	
	return 0;
}

void CantidadDeElementos(){ 
	system("cls");
	printf("\t\tLa cantidad de elementos en el pila es de: %d / %d",n,TamanioMaximo);
}

int PilaLlena(){
	
	system("cls");

	if (n == TamanioMaximo){ 
		printf("\t\tLa pila se encuentra llena, no puede apilar más elementos");
		return 1;
	}
	else
	{
		printf("\t\tLa pila a%cn NO se encuentra llena",163);
	}

	return 0;
}


void Desapilar(){
	system("cls");
	int tope; //variable que guardará la variable del tope antes de desapilar
	
	if (!PilaVacia())
	{
		tope = pila[n];
		n = n -1;
		system("cls");
		printf("\t\tse ha desapilado exitosamente");
	}
		
}

void Apilar()
{
	system("cls");
	if(!PilaLlena())
	{
		n++;
		RegistrarAnimal();
		printf("\t\tse ha apilado exitosamente");
		
	}
}

void RegistrarAnimal()
{

	system("cls");
	printf("Ingrese el grupo del animal (mam%cfero, ave, insecto, rept%cl...)\n",161,161);
	scanf("%s",&animal[n].grupo);
	
	puts("\nIngrese el codigo del animal");
	scanf("%s",&animal[n].codigo);
	
	puts("\nIngrese el nombre del animal");
	scanf("%s",&animal[n].nombre);
	
	puts("\nIngrese el sexo del animal (M o F)");
	scanf("%s",&animal[n].sexo);
	
	puts("\nIngrese el color del animal");
	scanf("%s",&animal[n].color);
	
	printf("\nIngrese fecha de nacimiento del animal.\nAsegure a%cadir '/' de esta forma DD/MM/YYYY\n",164);
	scanf("%d/%d/%d",&animal[n].fecha_nacimiento.dia,&animal[n].fecha_nacimiento.mes,&animal[n].fecha_nacimiento.anio);

	system("cls");

}

void ImprimirAnimal()
{

	if(n == 0)
	{
		system("cls");
		puts("no hay animales registrados en la pila en este momento, regrese mas tarde");
		system("pause");
	}
	else
	{
		system("cls");
		int i;
		printf("\n\tcantidad de animales en la pila: %d / %d",n,TamanioMaximo);
		printf("\n\tseleccione una opci%cn del 1 al %d para visualizar sus datos",162,n);
		printf("\n\t Ingrese su opci%cn: ",162);
		scanf("%d",&i);

		printf("\t===================================\n");
		printf("\t||nombre: %s\n",animal[i].nombre);
		printf("\t||codigo: %s\n",animal[i].codigo);
		printf("\t||grupo: %s\n",animal[i].grupo);
		printf("\t||sexo: %s\n",animal[i].sexo);
		printf("\t||color: %s\n",animal[i].color);
		printf("\t||fecha de nacimiento: %d/%d/%d\n",animal[i].fecha_nacimiento.dia,animal[i].fecha_nacimiento.mes,animal[i].fecha_nacimiento.anio);
		printf("\t===================================\n");
		system("pause");
	}


}

void ImprimirAnimales()
{
	int i;
	system("cls");
	if(n == 0)
	{
		puts("no hay animales registrados en la pila en este momento, regrese mas tarde");
		system("pause");
	}
	else{
		for (i = 1; i <= n; i++)
		{
			printf("\t=========Animal(%d / %d)=============\n",i,n);
			printf("\t||nombre: %s\n",animal[i].nombre);
			printf("\t||codigo: %s\n",animal[i].codigo);
			printf("\t||grupo: %s\n",animal[i].grupo);
			printf("\t||sexo: %s\n",animal[i].sexo);
			printf("\t||color: %s\n",animal[i].color);
			printf("\t||fecha de nacimiento: %d/%d/%d\n",animal[i].fecha_nacimiento.dia,animal[i].fecha_nacimiento.mes,animal[i].fecha_nacimiento.anio);
			printf("\t===================================\n");
		}
		system("pause");
	}
	
	
	MenuAnimales();
}
