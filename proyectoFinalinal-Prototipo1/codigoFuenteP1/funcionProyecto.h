#pragma once
#include <iostream>
#include <math.h>
#include<ctype.h>
#define N 55
#define C 10
using namespace std;

struct Empleado
{
	char nombre[N];
	char numeroCedula[C];
	int edad, sueldo;
};
int menu()	//funcion para el menu de opciones
{
	int opc;
	system("color D");
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
void leerDatos(Empleado* p)	 //funcion ingresar datos de los empleados
{
	system("cls");
	cout << "\nIngrese el numero de cedula del empleado: ";
	cin >> p->numeroCedula;
	cout << "\nIngrese el nombre del empleado(Apellido Nombre): ";
	while (getchar() != '\n');
	fgets(p->nombre, N, stdin);
	do
	{
		cout << "\nIngrese edad del empledado: ";
		cin >> p->edad;
	} while (p->edad <= 0||p->edad>150);
	do
	{
		cout << "\nIngrese el sueldo mensual del empleado: ";
		cin >> p->sueldo;
	} while (p->sueldo <= 0);	
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
		printf("\n\t*Empleado %d*\n", ++ord);
		printf("\nC.I.: %s\n", emp.numeroCedula);
		printf("\nNombre: %s\n", emp.nombre);
		printf("\nEdad: %d\n", emp.edad);
		printf("\nSueldo: %d\n", emp.sueldo);
		if (fread(&emp, sizeof(Empleado), 1, F) != 1)//OBTENGO EL SIGUIENTE REGISTRO DEL ARCHIVO
			if (!feof(F))
				cout << "ERROR!!! No se pudo leer el archivo." << endl;
	}
	fclose(F);
	system("pause");
}




