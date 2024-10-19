/*
Sistema de votaciones
Objetivo: Crear un sistema de votaciones donde cada votante tiene un número de
identificación y vota por un candidato.
La clave será el número de identificación del votante y el valor será el nombre del candidato
por el que ha votado.
Implementa funciones para:
● Registrar un voto.
● Verificar por quién votó una persona (buscando por su ID).
● Eliminar un voto si fue incorrecto.
● Imprimir todos los votos registrados.
Puntos clave:
● Prevenir que un votante registre más de un voto.
● Mostrar un error si se intenta eliminar un voto no existente.
*/

#include <iostream>
#include <string>
#include "HashMap/HashMapList.h"
using namespace std;

void menu(){
    cout << "1. Registrar voto\n";
    cout << "2. Verificar voto por ID\n";
    cout << "3. Eliminar voto\n";
    cout << "4. Imprimir votos\n";
    cout << "5. Salir\n";
    cout << "\n";
}

int main(){
    unsigned int tamanoTabla = 10;
    HashMapList<int,string> votos(tamanoTabla);
    int opcion,dni;
    string nombreCandidato;
    string javo="Javier Milei";

    do{
        menu();
        cout << " Ingrese opcion: ";cin >> opcion;

        switch(opcion){
            case 1:
                cout << "****CANDIDATOS****" << endl;
                printf(" 1. Javier Milei - La Libertad Avanza\n 2. Sergio Massa - Union Por La Patria\n");
                cout << "Ingrese DNI del votante: "; cin >> dni;
                cout << "Ingrese el candidato: "; 
                cin.ignore();
                getline(cin,nombreCandidato);
                try{
                votos.put(dni,nombreCandidato);
                cout << "Voto cargado correctamente****" << endl;
                } catch (int e){
                    if(e == 409){
                        cout << "La persona ya votó****" << endl;
                    } else {
                        cout << "Error: Conflicto ****\n";
                    }
                }
                break;
            case 2:
                cout << "Ingrese dni para verificar voto: "; cin >> dni;
                try{
                    votos.buscar(dni);
                }catch(int e){
                    if(e==409){
                        cout << "El dni: " << dni << " ya voto****\n";
                    } else if(e==700){
                        cout << "No se encontro el dni\n";
                    } else{
                       cout << "Error: Conflicto en busqueda\n"; 
                    }
                }
            case 3:
                cout << "Ingrese dni a eliminar: "; cin >> dni;
                try{
                    votos.buscar(dni);
                }catch(int e){
                    if(e==409){
                        cout << "El voto del dni: " << dni << " fue eliminado" << endl;
                        votos.remove(dni);
                    } else if(e==700){
                        cout << "No se encontro el dni\n";
                    } else{
                       cout << "Error: Conflicto en busqueda\n"; 
                    }
                }
            break;

            case 4:
            system("cls");
            votos.print();
            cout <<"" << endl;
            cout << "--------------------------" << endl;
            break;

        }
    }while(opcion != 5);
}