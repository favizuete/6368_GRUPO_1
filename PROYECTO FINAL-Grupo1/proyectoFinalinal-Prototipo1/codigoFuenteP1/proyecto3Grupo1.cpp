// proyecto3Grupo1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <stdlib.h>
#include "funcionProyecto.h"

int main()
{
	FILE* F = NULL;
	int opc, tam=0, i ,j;
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
			char mensaje[] = "\nDesea ingresar otro empleado? S/N: ";
			cout << "INGRESAR DATOS." << endl;
			do
			{ 
				datos = (Empleado*)realloc(datos, (tam + 1) * sizeof(Empleado));
				if (datos != NULL)
				{
					leerDatos(&datos[tam]);
					tam++;
				}
				else
					cout << "\nError. No se pudo reservar memoria.";
			} while (continuar(mensaje));
			char mensaje1[] = "\nDesea grabar los datos en el archivo? S/N: ";
			if(continuar(mensaje1))
			{
				guardar(F, archivo, datos, tam);	//guardar datos en el archivo
				free(datos);
				datos = NULL;
				tam = 0;
			}
			break;
		}
		case 3:	//Esta opcion nos permite imprimir por pantalla los datos
		{	
			system("cls");
			imprimirDatos(F, archivo, modorb);
			break;
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
		case 0: {	   //Salir del programa
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
