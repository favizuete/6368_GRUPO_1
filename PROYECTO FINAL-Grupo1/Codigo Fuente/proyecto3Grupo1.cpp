// proyecto3Grupo1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <stdlib.h>
#include "funcionProyecto.h"

int main()
{
	int opc,opc2, tam=0;
	Empleado* datos = NULL;

	do
	{
		system("cls");
		opc = menu();
		switch(opc)
		{
		case 1:
			cout << "INGRESAR DATOS." << endl;
			do
			{
				datos = (Empleado*)realloc(datos, (tam + 1) * sizeof(Empleado));
				if (datos!=NULL)
				{
					leerDatos(&datos[tam]);
					tam++;
				}
				else
					cout << "\nError. No se pudo reservar memoria.";
				cout << "\nDesea ingresar los datos de otro empleado. 1-Si/0-No: ";
				cin >> opc2;
			} while (opc2 != 0);
			break;
		case 2: 
			if(datos != NULL)
			{
				mostrarDatos(datos, tam);
			}
			else
			{
				cout << "\nError. Aun no ha ingresado datos" << endl;
			}
			cout << "\n";
			system("pause");
			break;
		case 0:
			break;
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
