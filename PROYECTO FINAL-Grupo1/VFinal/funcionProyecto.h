#pragma once
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <math.h>
#define N 55
#define C 10
using namespace std;

struct Empleado
{
	char nombre[N];
	long int cedula;
	int edad, sueldo;
};
int menu()	//funcion para el menu de opciones
{
	int opc;
	cout << "\n\t**REGISTRO EMPLEADOS--FABRICA DE CHICLES**" << endl;
	cout << "\n1. Crear nuevo archivo" << endl;
	cout << "\n2. Ingresar datos del Empleado." << endl;
	cout << "\n3. Mostrar datos de Empleados." << endl;
	cout << "\n4. Mostrar datos de Empleados con el mismo apellido." << endl;
	cout << "\n0. Salir del programa" << endl;
	cout << "\tSeleccione una opcion: ";
	cin >> opc;
	return opc;
}

void leerCedula (Empleado *p)//Funcion para ingresar cedula
{
	system("cls");
	cout << "\t**INGRESO DE DATOS**" << endl;
	cout << "\nIngrese el numero de cedula del empleado: ";
	cin >> p->cedula;
}
	
void leerDatos(Empleado* p)	 //funcion ingresar datos de los empleados
{
	cout << "\nIngrese el nombre del empleado(Apellido Nombre): ";
	while (getchar() != '\n');//liberar memoria
	fgets(p->nombre, N, stdin);//leer cadena de caracteres
	do
	{
		cout << "\nIngrese edad del empledado: ";
		cin >> p->edad;
	} while (p->edad < 18 || p->edad > 60);
	do
	{
		cout << "\nIngrese el sueldo mensual del empleado: ";
		cin >> p->sueldo;
	} while (p->sueldo < 390);
}
void validar(long int *a) //Validar cedula
{
	long int res, coc, i, x, aux;
	while (a < 0)
	{
		printf("Su cedula ingresada es invalida, ingrese de nuevo:");
		scanf_s("%ld", a);
	}
	do {
		x = 0;
		aux = *a;
		i = 0;
		do {
			res = aux % 10;
			coc = aux / 10;
			i++;
			aux = coc;
		} while (coc != 0);
		if (i != 10)
		{
			printf("Su cedula no es valida, ingrese de nuevo:");
			scanf_s("%ld", a);
			++x;
		}
	} while (x != 0);
}
void validar_cedula(long int num, int B[]) //Validar cedula
{
	long int coc, res, i = 9, x = 0, sumapar = 0, sumaimpar = 0, resu, aux, j, sumatotal, resutot;
	aux = num;
	do {
		res = aux % 10;
		coc = aux / 10;
		B[i] = res;
		i--;
		aux = coc;
	} while (coc != 0);
	i++;
	for (j = 1; j < 9; j += 2)
		sumapar += B[j];
	for (j = 0; j < C; j += 2)
	{
		x = 2 * B[j];
		if (x > 9)
		{
			x -= 9;
		}
		sumaimpar += x;
	}
	sumatotal = sumapar + sumaimpar;
	res = sumatotal % 10;
	resu = sumatotal + 10 - res;
	resutot = resu - sumatotal;
	if (resutot != B[9])
		printf("Su numero de cedula es invalido");
	else
		printf("Su numero de cedula es valido");
}



//Funcion para continuar (S/N)
bool continuar(char mensaje[])
{
	char ch;
	cout << mensaje;
	do
	{
		cin >> ch;
		ch = toupper(ch);
	} while (ch != 'S' && ch != 'N');
	return(ch == 'S' ? true : false);
}

//funciones manipulacion de archivos

//Funcion para abrir el archivo en un modo determinado
FILE* abrirArchivo(char* nombre, char* modo)
{
	FILE* F;
	errno_t err;
	if ((err = fopen_s(&F, nombre, modo) != 0))
	{
		cout << "No se puede abrir el archivo" << nombre << endl;
		exit(1);
	}
	return F;
}
//Inicializar archivo. CREAR EL ARCHIVO SI NO EXISTE, SI EXISTE VOLVERLO A CREAR.

void inicializar(FILE* F, char* archivo, char* modo)
{
	char mensaje[] = "Desea continuar S/N: ";
	cout << "\n\nCrear el archivo " << archivo << endl;
	cout << "\n\nLa informacion se perdera. " << endl;
	if (continuar(mensaje)) {
		F = abrirArchivo(archivo, modo);
		fclose(F);
	}
}

//Funcion para guardar datos en el archivo

void guardar(FILE* F, char* nombre, Empleado* p, int n)
{
	char modo[] = "rb+";
	cout << "\nGrabando datos en el archivo ..." << endl;
	F = abrirArchivo(nombre, modo);
	fseek(F, 0, SEEK_END); //Busca el ultimo registro del archivo
	for (int i = 0; i < n; i++, p++)
	{
		if (fwrite(p, sizeof(Empleado), 1, F) != 1)
			cout << "ERROR. No se pudo escribir en el archivo." << endl;

	}
	fclose(F);
}

//Funcion para imprimir los datos

void imprimirDatos(FILE* F, char* nombre, char* modo)
{
	Empleado emp;
	int ord = 0;
	cout << "\n\t\t***Empleados Ingresados***" << endl;
	F = abrirArchivo(nombre, modo);
	if (fread(&emp, sizeof(Empleado), 1, F) != 1)//OBTENGO EL PRIMER REGISTRO DEL ARCHIVO
		if (!feof(F))
			cout << "ERROR. Nose pudo leer el archivo." << endl;
	while (!feof(F)) //Recorrer todo el archivo hasta encontrar el eof
	{
		printf("\n\t*Empleado %d*", ++ord);
		cout<<"\nNo. cedula: "<<emp.cedula;
		printf("\nNombre: %s", emp.nombre);
		printf("\nEdad: %d", emp.edad);
		printf("\nSueldo: %d\n", emp.sueldo);
		cout << "--------------------------------" << endl;
		if (fread(&emp, sizeof(Empleado), 1, F) != 1)//OBTENGO EL SIGUIENTE REGISTRO DEL ARCHIVO
			if (!feof(F))
				cout << "ERROR!!! No se pudo leer el archivo." << endl;
	}
	fclose(F);
	system("pause");
}

int menu2()	//funcion para el menu de opciones
{
	int opc;
	cout << "\n\t**DATOS EMPLEADOS--FABRICA DE CHICLES**" << endl;
	cout << "\n1. Datos en orden alfabetico." << endl;
	cout << "\n2. Datos segun el sueldo mensual." << endl;
	cout << "\tSeleccione una opcion: ";
	cin >> opc;
	return opc;
}

 //Funcion para ordenar
void ordAlf(Empleado A[], int n)
{
	int i, j;
	Empleado aux;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (A[j + 1].nombre < A[j].nombre)
			{
				aux = A[j + 1];
				A[j + 1] = A[j];
				A[j] = aux;
			}
}







	












