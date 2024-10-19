/*
Registro de productos en una tienda. Almacenar productos de una tienda usando un código
único como clave y el nombre del producto como valor. Usa el HashMap para almacenar los
productos. El código de producto es la clave y el nombre es el valor.
Implementa opciones para:
● Añadir productos.
● Buscar productos por su código.
● Actualizar el nombre de un producto existente.
● Eliminar productos.
● Imprimir todos los productos registrados.
● Desafío adicional: Implementa el manejo de colisiones, y lanza excepciones cuando se
intenten agregar productos con códigos ya existentes o buscar productos no
registrados.
*/

#include <iostream>
#include <string>
#include "HashMap/HashMap.h" // Asegúrate de incluir el archivo de encabezado correcto para HashMap

using namespace std;

void menu() {
    cout << "1. Añadir productos" << endl;
    cout << "2. Buscar producto por código" << endl;
    cout << "3. Actualizar nombre de producto existente" << endl;
    cout << "4. Eliminar producto" << endl;
    cout << "5. Imprimir existencia" << endl;
    cout << "6. Salir" << endl;
    cout << "\n";
}

int main() {
    unsigned int tamanoTabla = 10;
    HashMap<int, string> productos(tamanoTabla);
    int opcion;

    do {
        menu();
        cout << "Seleccione una opción: ";
        cin >> opcion;
        system("cls");
        cout << "\n";
        switch(opcion) {
            case 1: {
                // Añadir productos
                int codigo;
                string nombreProducto;
                cout << " Ingrese el codigo del producto: \n";
                cout << "  Codigo: "; cin >> codigo;
                cout << " Nombre del producto: \n";
                cout << "  Nombre: "; 
                cin.ignore();
                getline(cin, nombreProducto);
                try {
                    productos.put(codigo, nombreProducto);
                    cout << "Producto agregado correctamente****" << endl;
                } catch (int e) {
                    if (e == 409) {
                        cout << "El producto ya existe****" << endl;
                        cout << "Vuelva a ingresar un codigo" << endl;
                    } else {
                        cout << "Error: conflicto en búsqueda****" << endl;
                    }
                }
                break;
            }
            case 2: {
                // Buscar producto por código
                int codigo;
                cout << " Ingrese el codigo del producto a buscar: \n";
                cout << "  Codigo: "; cin >> codigo;
                try {
                    string nombreProducto = productos.get(codigo);
                    cout << "Producto con codigo: " << codigo << "; es: " << nombreProducto << endl;
                } catch (int e) {
                    if (e == 404) {
                        cout << "Producto no encontrado.\n";
                    } else {
                        cout << "Error: conflicto en búsqueda****\n";
                    }
                }
                break;
            }
            case 3: {
                // Actualizar nombre de producto existente
                int codigo;
                string nombreProducto;
                cout << " Ingrese el codigo del producto a actualizar: \n";
                cout << "  Codigo: "; cin >> codigo;
                cout << " Ingrese el nuevo nombre del producto: \n";
                cout << "  Nombre: "; 
                cin.ignore();
                getline(cin, nombreProducto);
                try {
                    productos.remove(codigo);
                    productos.put(codigo, nombreProducto);
                    cout << "Producto actualizado correctamente****" << endl;
                } catch (int e) {
                    if (e == 404) {
                        cout << "Producto no encontrado.\n";
                    } else {
                        cout << "Error: conflicto en búsqueda****\n";
                    }
                }
                break;
            }
            case 4: {
                // Eliminar producto
                int codigo;
                cout << " Ingrese el codigo del producto a eliminar: \n";
                cout << "  Codigo: "; cin >> codigo;
                try {
                    productos.remove(codigo);
                    cout << "Producto eliminado correctamente****" << endl;
                } catch (int e) {
                    if (e == 404) {
                        cout << "Producto no encontrado.\n";
                    } else {
                        cout << "Error: conflicto en búsqueda****\n";
                    }
                }
                break;
            }
            case 5:
                // Imprimir existencia
                if(!productos.esVacio()){
                    productos.print();
                }else{
                    cout << "Existencias vacias**********" << endl;
                }
                break;
            case 6:
                // Salir
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
                break;
        }
    } while(opcion != 6);

    return 0;
}
