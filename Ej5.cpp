#include <iostream>
#include <string>
#include "HashMap/HashMapList.h"
using namespace std;

void menu() {
    cout << "1. Agregar libro\n";
    cout << "2. Buscar libro por ISBN\n";
    cout << "3. Eliminar libro\n";
    cout << "4. Imprimir todos los libros\n";
    cout << "5. Salir\n";
    cout << "\n";
}

int main() {
    unsigned int tamanoTabla = 10;
    HashMapList<int, string> biblioteca(tamanoTabla);  // ISBN como clave, título como valor
    int opcion, isbn;
    string tituloLibro;

    do {
        menu();
        cout << "Ingrese opción: "; cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese ISBN del libro: "; cin >> isbn;
                cout << "Ingrese título del libro: "; 
                cin.ignore();
                getline(cin, tituloLibro);
                try {
                    biblioteca.put(isbn, tituloLibro);
                    cout << "Libro agregado correctamente****" << endl;
                } catch (int e) {
                    if (e == 409) {
                        cout << "Ya existe un libro con este ISBN****" << endl;
                    } else {
                        cout << "Error: Conflicto ****" << endl;
                    }
                }
                break;

            case 2:
                cout << "Ingrese ISBN para buscar el libro: "; cin >> isbn;
                try {
                    biblioteca.buscar(isbn);
                } catch (int e) {
                    if (e == 409) {
                        cout << "Libro encontrado****" << endl;
                    } else if (e == 700) {
                        cout << "No se encontró el libro con ese ISBN****" << endl;
                    } else {
                        cout << "Error: Conflicto en búsqueda****" << endl;
                    }
                }
                break;

            case 3:
                cout << "Ingrese ISBN para eliminar el libro: "; cin >> isbn;
                try {
                    biblioteca.buscar(isbn);
                } catch (int e) {
                    if(e==409){
                        biblioteca.remove(isbn);
                        cout << "Libro eliminado correctamente****" << endl;
                    } else if (e == 700) {
                        cout << "No se encontró el libro con ese ISBN****" << endl;
                    } else {
                        cout << "Error: Conflicto en eliminación****" << endl;
                    }
                }
                break;

            case 4:
                biblioteca.print();
                cout << "--------------------------" << endl;
                break;
        }
    } while (opcion != 5);
}
