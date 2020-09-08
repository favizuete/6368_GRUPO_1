#pragma once
#include <iostream>
#define N 55
#define C 10
using namespace std;

struct Empleado
{
	char nombre[N];
	char numeroCedula[C];
	int edad, sueldo;
};
int menu()
{
	int opc;
	system("color D");
	 cout<< "\n BIENVENIDOS: SISTEMA DE TRABAJADORES DE UNA EMPRESA DE CHICLES."<<endl;
	cout << "\n*****MENU DE OPCIONES"**** << endl;
	cout << "\n1. Ingresar datos del Empleado." << endl;
	cout << "\n2. Mostrar datos de Empleados." << endl;
	cout << "\n3. Mostrar datos de Empleados con el mismo apellido." << endl;
	cout << "\n0. Salir del programa" << endl;
	cout << "\tSeleccione una opcion: ";
	cin >> opc;
	return opc;
}
void leerDatos(Empleado* p)
{
	cout << "\nIngrese el nombre completo del empleado (Nombre, Apellido): ";
	while (getchar() != '\n');
	fgets(p->nombre, N, stdin);
	cout << "\nIngrese el numero de cedula del empleado: ";
	cin >> p->numeroCedula;
	do
	{
		cout << "\nIngrese edad del empledado: ";
		cin >> p->edad;
	} while (p->edad < 0);
	do
	{
		cout << "\nIngrese el sueldo mensual del empleado: ";
		cin >> p->sueldo;
	} while (p->sueldo < 0);
	
}
void mostrarDatos(Empleado* p, int n)
{
	for (int i = 0; i < n; i++, p++)
	{
		cout << "****DATOS DE EMPLEADOS***" << endl;
		cout << "\n" << "\n\tEmpleado [" << i + 1<<"]"<<endl;
		cout << "\n" <<"\n\tNombre: " <<p->nombre << endl;
		cout << "\n" <<"\n\tNumero de Cedula: " <<p->numeroCedula << endl;
		cout << "\n" <<"\n\tEdad: " << p->edad << endl;
		cout << "\n" <<"\n\tSueldo Mensual: " << p->sueldo << endl;
	}
	cout << endl;
}
int menu2()
{
	int opc;
	cout << "\n\tMENU DE OPCIONES" << endl;
	cout << "\n1. Empleados en orden alfabetico" << endl;
	cout << "\n2. Empleados segun el sueldo que ganan" << endl;
	cout << "\n0. Salir del programa" << endl;
	cout << "\tSeleccione una opcion: " <<  endl;
	cin >> opc;
	return opc;
}
