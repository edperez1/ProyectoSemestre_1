#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
/*Este es nuestro Proyecto Final de el Primer semestre de la clase de Logica y Algoritmos */
using namespace std;

struct PaqueteInternet {
    string velocidad;
    string descripcion;
    double precio;
};
struct Cliente {
    int id;
    string nombre;
    string direccion;
    string telefono;
};
struct Factura {
    int numero_factura;
    string fecha;
    double total;
    Cliente cliente;
};

vector<Cliente> clientes;
void Eliminarcliente(){
}

void agregar_cliente() {
    Cliente nuevo_cliente;
    cout << "Ingrese el nombre del cliente: ";
    cin.ignore();
    getline(cin, nuevo_cliente.nombre);
    cout << "Ingrese la dirección del cliente: ";
    getline(cin, nuevo_cliente.direccion);
    cout << "Ingrese el teléfono del cliente: ";
    getline(cin, nuevo_cliente.telefono);

    clientes.push_back(nuevo_cliente);
    cout << "Cliente agregado con éxito." << endl;
}

Factura crear_factura(int numero_factura, const string& fecha, double total, const Cliente& cliente) {
    Factura factura;
    factura.numero_factura = numero_factura;
    factura.fecha = fecha;
    factura.total = total;
    factura.cliente = cliente;
    return factura;
}
void MenuOpciones(){
    cout<<"-----Menu Principal-----"<<endl;
    cout << "\n1.Menu Para Empleados"  << "\n2.Menu para Clientes"<< "\n3.Salir del Programa"<<endl;
}

void mostrarPrecios() {
    cout << "Opciones de paquetes de Internet:\n";
    cout << "1. 5 mbps\n";
    cout << "2. 5 mbps + CATV\n";
    cout << "3. 10 mbps + CATV\n";
    cout << "4. 20 mbps + CATV\n";
}
void mostrarInformacionPaquete(const PaqueteInternet& paquete) {
    cout << "Velocidad: " << paquete.velocidad << " mbps\n";
    cout << "Descripción: " << paquete.descripcion << "\n";
    cout << "Precio: $" << paquete.precio << "\n";
}

void mostrar_menu() {
    cout << "\n-- Menu de Empleados--" << endl;
    cout << "1. Agregar Cliente" << endl;
    cout << "2. Mostrar Clientes" << endl;
    cout << "3. Eliminar clientes"<<endl;
    cout << "4. Crear Factura" << endl;
    cout << "5. Salir" << endl;
    cout<< "--------------------\n";
    cout << "Ingrese una opcion: ";
}
 
void menu_principal() {
    char opcion;
    do {
        mostrar_menu();
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case '1':
                agregar_cliente();
                break;
            case '2':
                // Función para mostrar clientes
                break;
            case '3':
                // Función para crear factura
                break;
            case '4':
            // Funcion para eliminar clientes
                cout << "Cliente eliminado" << endl;
                break;
                case '5':
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción inválida. Inténtelo de nuevo." << endl;
        }
    } while (opcion != '5');
}


void menuClientes() {
    PaqueteInternet paquetes[] = {
        {"5", "Fibra optica hasta la casa.", 17.0},
        {"5", "Fibra optica hasta la casa y CATV.", 22.0},
        {"10", "Fibra optica hasta la casa y CATV.", 25.0},
        {"20", "Fibra optica hasta la casa y CATV.", 30.0}
    };

    int opcion;

    cout << "-----Bienvenido al menu Para Clientes-----\n";
    do {
        cout << "Opciones de paquetes de Internet:\n";
        cout << "1. 5 mbps\n";
        cout << "2. 5 mbps + CATV\n";
        cout << "3. 10 mbps + CATV\n";
        cout << "4. 20 mbps + CATV\n";
        cout  <<"5. Volver al Menu Principal...\n";
        cout << "Seleccione una opcion para el paquete de Internet: ";
        cin >> opcion;

        if (opcion >= 1 && opcion <= 4) {
            cout << "Velocidad: " << paquetes[opcion - 1].velocidad << " mbps\n";
            cout << "Descripción: " << paquetes[opcion - 1].descripcion << "\n";
            cout << "Precio: $" << paquetes[opcion - 1].precio << "\n";
        } else if (opcion == 5) {
            cout << "volviendo al Menu...";
            break;
        } else {
            cout << "Opción no válida.\n";
        }
    } while (opcion != 5);
}

void MostrarMenuOpcion(){
    char opcion;
do {
        MenuOpciones();
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case '1':
             menu_principal();
              system("cls");
                break;
            case '2':
                menuClientes();
                system("cls");
                break;
                case '3':
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción inválida. Inténtelo de nuevo." << endl;
        }
    } while (opcion != '3');

}
int main() {
    
    MostrarMenuOpcion();
  
    return 0;
}
