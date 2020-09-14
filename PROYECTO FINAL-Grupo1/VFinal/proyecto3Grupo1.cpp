// proyecto3Grupo1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
/*
TEMA: DATOS DE EMPLEADOS DE EMPRESA DE CHICLES
INTEGRANTES: ALISSON CHAVARRIA, DENILSON CACHIGUNAGO, FAUSTO VIZUETE
*/
#include <stdlib.h>
#include "funcionProyecto.h"

int main()
{
	FILE* F = NULL;
	int opc,opc2, tam=0, i=0 ,j=0;
	int x[C], n=0;
	long int num = 0;
	char archivo[] = "EMPLEADOS"; //Nombre del archivo binario para almacenar los datos
	char modowb[] = "wb"; //Modo de escritura binaria / Crear archivo.
	char modorb[] = "rb"; //Modo de lectrura binaria
	Empleado* datos = NULL;

	do
	{
		system("cls");
		opc = menu();
		switch(opc)
		{
		case 1: 
			inicializar(F, archivo, modowb);
			break;
		case 2: 
		{	  //Ingresar nombres usando realloc
			system("cls");
			char mensaje[] = "\nDesea ingresar otro empleado? S/N: ";
			cout << "\t\t\t**Ha seleccionado la opcion 2**"<<endl;
			cout << "\t**A continuacion ingrese los siguientes datos de los empleados**" << endl;
			system("pause");
			do
			{ 
				datos = (Empleado*)realloc(datos, (tam + 1) * sizeof(Empleado));
				if (datos != NULL)
				{
					leerCedula(&datos[tam]);
					validar(&num);
					validar_cedula(num, x);
					leerDatos(&datos[tam]);
					tam++;
				}
				else
					cout << "\nError. No se pudo reservar memoria.";
			} while (continuar(mensaje));
			char mensaje1[] = "\nDesea grabar los datos en el archivo? S/N: ";
			if(continuar(mensaje1))
			{
				guardar(F, archivo, datos, tam);
				free(datos);
				datos = NULL;
				tam = 0;
			}
			break;
		}
		case 3:
		{	
			system("cls");
			cout << "\t\t\t\t**Ha seleccionado la opcion 3**" << endl;
			cout << "\t**A continuacion seleccione una opcion para ver los datos de los empleados ingresados**" << endl;
			system("pause");
			opc2 = menu2();
			switch (opc2)
			{
			case 1:
			{
				Empleado emp;
				int ord = 0;
				cout << "\n\t\t***Empleados Ingresados***" << endl;
				F = abrirArchivo(archivo, modorb);
				if (fread(&emp, sizeof(Empleado), 1, F) != 1)//OBTENGO EL PRIMER REGISTRO DEL ARCHIVO
					if (!feof(F))
						cout << "ERROR. Nose pudo leer el archivo." << endl;
				while (!feof(F)) //Recorrer todo el archivo hasta encontrar el eof
				{
					ordAlf(datos, n);
					for (i = 0; i < n; i++)
					{
						cout << "\n\t * Empleado  " << i + 1 << "*" << endl;
						cout << "Nombre: " << emp.nombre << endl;
						cout << "Ci: " << emp.cedula << endl;
						cout << "Edad: " << emp.edad << endl;
						cout << "Sueldo: " << emp.sueldo << endl;
					}
					fclose(F);
					system("pause");
					break;
				}
			}
			case 2:
			{
				imprimirDatos(F, archivo, modorb);
				break;
			default:
				cout << "\nError. Opcion no valida." << endl;
			}
			}
		}
		case 4: {
			if (datos != NULL)
			{
			}
			else
			{
				cout << "\nError. Aun no ha ingresado datos" << endl;
			}
			cout << "\n";
			system("pause");
			break;
		}
		case 0: 
		{
			cout << "\nGracias por usar el programa!!";
			cout << "\nBuen Dia!! :)" << endl;
			break;
		default:
			cout << "\nError. Opcion no valida." << endl;
		}
		}

	} while (opc != 0);
}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
