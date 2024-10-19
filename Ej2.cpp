/*
Sistema de gestión de empleados. Usar HashMap para almacenar y gestionar empleados por
su número de identificación (ID).
● La clave será el número de identificación del empleado y el valor será su nombre.
● Implementa un menú con opciones para:
● Agregar un nuevo empleado.
● Buscar un empleado por su número de identificación.
● Eliminar un empleado del sistema.
● Imprimir la lista completa de empleados.
*/

#include <iostream>
#include <string>
#include "HashMap/HashMap.h"
using namespace std;

void menu(){
    cout << "" << endl;
    cout << "1. Agregar nuevo empleado\n";
    cout << "2. Buscar empleado por ID\n";
    cout << "3. Eliminar empleado\n";
    cout << "4. Imprimir lista\n";
    cout << "5. Salir\n";
    cout << "\n";
}


int main() {
    unsigned int tamanoTabla = 10;
    HashMap<int, string> empleados(tamanoTabla);
    int opcion, clave;
    string nombre;

    do{
        menu();
        cout << "  Ingrese opcion: ";
        cin >> opcion;
        system("cls");
        cout << "\n";
        switch(opcion){
            case 1: // Agregar nuevo empleado
                cout << "   Ingrese ID del empleado: "; cin >> clave;
                cout << "   Ingrese nombre del empleado: "; 
                cin.ignore();
                getline(cin,nombre);
                empleados.put(clave,nombre);
                cout << "Empleado agregada correctamente.****\n";
                break;
            
            case 2: // Buscar empleado por ID
                cout << "   Ingrese id empleado para buscar: ";cin >> clave;
                try{
                    nombre = empleados.get(clave);
                    cout << "Empleado con id: " << clave << "; es: " << nombre;
                }catch (int e){
                    if(e == 404){
                        cout << "Empleado no encontrado. \n";
                    } else {
                        cout << "Error: conflicto en búsqueda****\n";
                    }
                }
            break;

            case 3: // Eliminar empleado
                cout << "   Ingrese id empleado para eliminar: " << endl;
                cout << "    Clave: "; cin >> clave;
                try{
                    cout << "Empleado ID: " << clave << " nombre: " << empleados.get(clave) << " eliminado correctamente****" << endl;
                    empleados.remove(clave);
                } catch(int e){
                    if(e == 404){
                        cout << "Empleado no encontrado****" << endl;
                    } else {
                        cout << "Error: conflicto en eliminación****" << endl;
                    }
                }
            break;

            case 4: // Imprimir lista
                system("cls");
                try{
                    printf("****Lista de empleados****\n");
                    empleados.print();
                } catch(int e){
                    if(e == 404){
                        cout << "No hay empleados en la lista****" << endl;
                    } else {
                        cout << "Error: conflicto en impresión****" << endl;
                    }
                }
            break;

            case 5: // Salir
                cout << "Saliendo...\n";
            break;
        }
    }while(opcion!=5);
}
