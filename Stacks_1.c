/*
Pilas. Representar e implementar una Pila de 20 items de
cualesquiera de las estructuras presentadas mas conveniente
para el caso, incluyendo las funciones: apilar, desapilar,
cantidad de elementos, pila vacía, pila llena, se debe utilizar
arreglos
*/

#include <stdio.h>
#include <stdlib.h>


/*Estructura anidada a la estructura principal*/

typedef struct{

	int dia;
	int mes;
	int anio;

}Fecha;

/*Estructura principal asignada*/

typedef struct {
	char codigo[20];
	char nombre[60];
	char grupo[30];
	char sexo[2];
	char color[30];
	Fecha fecha_nacimiento;
}Animal;

/*Prototipos de funciones para la pila*/

int PilaVacia(); 
void CantidadDeElementos(); 
int PilaLlena();
void Desapilar();
void Apilar(); 
void MenuPilas();

/*Prototipo de funciones para la implementación de la estructura asignada.*/

void MenuAnimales();
void RegistrarAnimal();
void ImprimirAnimal();
void ImprimirAnimales();

/*Variables globales*/

int TamanioMaximo = 20;
int pila[20];
int n = 0; 
int opcion;
Animal animal[20];

/*	main: se encargará de ejecutar el menú principal */

int main(){

	MenuPilas();
	
	return 0;
}

/*	MenuPilas: tiene el rol del menú principal que maneja todas las funciones del programa
	desde las funciones de la pila hasta las funciones para la implementación de la estructura,
	en esta función inicia el programa y es donde se encuentra su único cierre o salida de este.*/

void MenuPilas()
{
	system("cls");
		do 
	{
		printf("\n\t\t- Introduzca una Opci%cn",162);
		puts("\n\n\t\t 1.Apilar");
		puts("\n\t\t 2.Desapilar");
		puts("\n\t\t 3.Ver Cantidad de Elementos");
		puts("\n\t\t 4.Comprobar Pila Vacia");
		puts("\n\t\t 5.Comprobar Pila Llena");
		puts("\n\t\t 6.Ver Menu Animales");
		puts("\n\t\t 7.Salir");
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
			case 7:
				{
					exit(-1);
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

/*	MenuAnimales: se encarga de anidar otras funciones que interactúan con la estructura
	al menú de las pilas a través de un sub-menú*/

void MenuAnimales()
{
	system("cls");
	do
	{
		printf("\n\t\t- Introduzca una Opci%cn",162);
		puts("\n\n\t\t 1.Imprimir Todos los Animales");
		puts("\n\t\t 2.Imprimir un Animal");
		puts("\n\t\t 3.Volver al Menu Principal");
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

/*	PilaVacia: se encarga de notificar si la pila se encuentra vacía o no
	se encuentra vacía*/

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

/*	CantidadDeElementos: se encarga de mostrar la cantidad de elementos que se encuentran
	apilados y la capacidad máxima de la pila */

void CantidadDeElementos(){ 
	system("cls");
	printf("\t\tLa cantidad de elementos en el pila es de: %d / %d",n,TamanioMaximo);
}

/* PilaLlena: se cargará de notificar cuando la pila se encuentra llena o no
	se encuentra llena*/

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

/*	Desapilar: se encargará del proceso de desapilar el elemento que
	se encuentre en la cima o tope de la pila	*/

void Desapilar(){
	system("cls");
	int tope; 
	
	if (!PilaVacia())
	{
		tope = pila[n];
		n = n -1;
		system("cls");
		printf("\t\tse ha desapilado exitosamente");
	}
		
}

/*	Apilar: se encargará del proceso de apilar, notificar y registrar los elementos
	en la estructura*/

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

/*	RegistrarAnimal: se encargará del proceso de registrar los valores
	a los campos de la estructura animal implementada. Se utiliza como
	subfunción de la función Apilar */

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

/*	ImprimirAnimal: se encargará de mostrar un elemento a elegir
	de los registrados en la pila en el orden que han sido apilados */

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

/*	ImprimirAnimales: se encargará de mostrar en pantalla todos los
 	animales o elementos registrados en la pila.				*/

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

/* Creado por Christian Vasquez (30.452.958) y Edian Sánchez (30.212.255)*/
