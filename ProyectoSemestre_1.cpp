#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <limits>

/*Este es nuestro Proyecto Final de el Primer semestre de la clase de Logica y Algoritmos */

using namespace std;
// Definir struct
struct PaqueteInternet
{
    string velocidad;
    string descripcion;
    double precio;
};
struct Cliente
{
    string nombre;
    string apellido;
    string direccion;
    int telefono;
    string cedula;
    string Departamento;
};
struct Factura
{
    int numero_factura;
    string fecha;
    double total;
    Cliente cliente;
};
// Funciones principales.
vector<Cliente> clientes;
void Eliminarcliente()
{
    // no esta
}

void agregar_cliente()
{
    Cliente nuevo_cliente;
    cout << "Ingrese el nombre del cliente: ";
    getline(cin, nuevo_cliente.nombre);
    cout << "Ingrese el apellido del cliente: ";
    getline(cin, nuevo_cliente.apellido);
    cout << "Ingrese el Departamento del cliente: ";
    getline(cin, nuevo_cliente.Departamento);
    cout << "Ingrese la direccion del cliente: ";
    getline(cin, nuevo_cliente.direccion);

    cout << "Ingrese el telefono del cliente : ";
    while (true)
    {
        if (cin >> nuevo_cliente.telefono)
        {
            if (to_string(nuevo_cliente.telefono).length() == 8)
            {
                break; 
            }
            else
            {
                cout << "Ingrese un Numero Nacional ";
            }
        }
        else
        {
            cout << "Ingrese Un Numero  ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    cout << "Introduzca la cedula de el cliente : ";
    while (true)
    {
        cin >> nuevo_cliente.cedula;
        if (nuevo_cliente.cedula.length() == 14)
        {
            break;
        }
        else
        {
            cout << "Intente de nuevo ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    clientes.push_back(nuevo_cliente);
    cout << "Cliente agregado con exito." << endl;
}

void mostrar_clientes()
{
    if (clientes.empty())
    {
        cout << "No hay clientes registrados.\n";
        return;
    }
    cout << "Lista de Clientes:\n";
    cout << "------------------\n";
    for (const auto &cliente : clientes)
    {
        cout << "Nombre: " << cliente.nombre << "\nApellido: " << cliente.apellido << "\nDepartamento: " << cliente.Departamento << "\nDireccion: " << cliente.direccion << "\nTelefono: " << cliente.telefono << "\nCedula: " << cliente.cedula << "\n";
        cout << "------------------\n";
    }
}
void buscar_cliente()
{
    char seguir = 's';
    do
    {
        if (clientes.empty())
        {
            cout << "No hay clientes registrados para buscar.\n";
            return;
        }

        int opcion;
        string busqueda;
        cout << "Seleccione el criterio de busqueda:\n";
        cout << "1. Por Plan\n"; // esta no esta hecha jejeje
        cout << "2. Por Cedula\n";
        cout << "3. Por Nombre\n";
        cout << "4. Por Numero\n";
        cout << "Ingrese una opcion: ";

        while (!(cin >> opcion) || opcion < 1 || opcion > 4)
        {
            cout << "Opcion inválida. Por favor, ingrese un número entre 1 y 4: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore();

        bool encontrado = false;
        switch (opcion)
        {
        case 1:
            cout << "funcionalidad no implementada aun.\n";
            //no he hecho esta atento ( es q ta muy complicada pq hace falta añadir que plan quiere el cliente o el manejo de archivos)
            break;
        case 2:
            cout << "Ingrese la cedula del cliente: ";
            getline(cin, busqueda);
            for (const auto &cliente : clientes)
            {
                if (cliente.cedula == busqueda)
                {
                    cout << "Cliente encontrado:\n";
                    cout << "Nombre: " << cliente.nombre << "\nApellido: " << cliente.apellido << "\nDepartamento: " << cliente.Departamento << "\nDireccion: " << cliente.direccion << "\nTelefono: " << cliente.telefono << "\nCedula: " << cliente.cedula << "\n\n";
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado)
                cout << "Cliente no encontrado.\n";
            break;
        case 3:
            cout << "Ingrese el nombre del cliente: ";
            getline(cin, busqueda);
            for (const auto &cliente : clientes)
            {
                if (cliente.nombre == busqueda)
                {
                    cout << "Cliente encontrado:\n";
                    cout << "Nombre: " << cliente.nombre << "\nApellido: " << cliente.apellido << "\nDepartamento: " << cliente.Departamento << "\nDireccion: " << cliente.direccion << "\nTelefono: " << cliente.telefono << "\nCedula: " << cliente.cedula << "\n\n";
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado)
                cout << "Cliente no encontrado.\n";
            break;
        case 4:
            cout << "Ingrese el numero del cliente: ";
            int numero;
            while (!(cin >> numero))
            {
                cout << "Por favor, ingrese un numero valido para el telefono: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            for (const auto &cliente : clientes)
            {
                if (cliente.telefono == numero)
                {
                    cout << "Cliente encontrado:\n";
                    cout << "Nombre: " << cliente.nombre << "\nApellido: " << cliente.apellido << "\nDepartamento: " << cliente.Departamento << "\nDireccion: " << cliente.direccion << "\nTelefono: " << cliente.telefono << "\nCedula: " << cliente.cedula << "\n\n";
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado)
                cout << "Cliente no encontrado.\n";
            break;
        }

        cout << "Desea buscar otro cliente o volver al menu principal? (s para buscar de nuevo, cualquier otra tecla para volver): ";
        cin >> seguir;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (seguir == 's' || seguir == 'B');
}

Factura crear_factura(int numero_factura, const string &fecha, double total, const Cliente &cliente)
{
    Factura factura;
    factura.numero_factura = numero_factura;
    factura.fecha = fecha;
    factura.total = total;
    factura.cliente = cliente;
    return factura;
}
void MenuOpciones()
{
    cout << "                   -----Menu Principal-----" << endl;
    cout << "\n1.Menu de Empresa" << "\n2.Menu para Clientes" << "\n3.Salir del Programa" << endl;
}

void mostrarPrecios()
{
    cout << "Opciones de paquetes de Internet:\n";
    cout << "1. 5 mbps\n";
    cout << "2. 5 mbps + CATV\n";
    cout << "3. 10 mbps + CATV\n";
    cout << "4. 20 mbps + CATV\n";
}
void mostrarInformacionPaquete(const PaqueteInternet &paquete)
{
    cout << "Velocidad: " << paquete.velocidad << " mbps\n";
    cout << "Descripcion: " << paquete.descripcion << "\n";
    cout << "Precio: $" << paquete.precio << "\n";
}

void mostrar_menu()
{
    cout << "\n-- Menu de Empresa--" << endl;
    cout << "1. Agregar Cliente" << endl;
    cout << "2. Mostrar Clientes" << endl;
    cout << "3. Eliminar clientes" << endl;
    cout << "4. Crear Factura" << endl;
    cout << "5. Buscar clientes" << endl;
    cout << "6. Salir" << endl;

    cout << "--------------------\n";
    cout << "Ingrese una opcion: ";
}

void menu_principal()
{
    int opcion = 0;
    do
    {
        cout << "\nMenu Principal\n";
        cout << "1. Agregar Cliente\n";
        cout << "2. Buscar Cliente\n";
        cout << "3. Mostrar Clientes\n";
        cout << "4. Crear Factura\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        // esta onda de cin ignore esta en mucha parte del codigo, sirve para limpiar el buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcion)
        {
        case 1:
            agregar_cliente();
            cout << "Agregar Cliente seleccionado.\n";
            break;
        case 2:
            buscar_cliente();
            cout << "Buscar Cliente seleccionado.\n";
            break;
        case 3:
            mostrar_clientes();
            cout << "Mostrar Clientes seleccionado.\n";
            break;
        case 4:
            // NO HECHO
            cout << "Crear Factura seleccionado.\n";
            break;
        case 5:
            cout << "Saliendo...\n";
            break;
        default:
            cout << "Opción no válida. Por favor, intente de nuevo.\n";
        }
        //falta un break mas acerca de eliminar clientes
    } while (opcion != 5);
}

void menuClientes()
{
    PaqueteInternet paquetes[] = {
        {"5", "Fibra optica hasta la casa.", 17.0},
        {"5", "Fibra optica hasta la casa y CATV.", 22.0},
        {"10", "Fibra optica hasta la casa y CATV.", 25.0},
        {"20", "Fibra optica hasta la casa y CATV.", 30.0}};

    int opcion;

    cout << "-----Bienvenido al menu Para Clientes-----\n";
    do
    {
        cout << "Opciones de paquetes de Internet:\n";
        cout << "1. 5 mbps\n";
        cout << "2. 5 mbps + CATV\n";
        cout << "3. 10 mbps + CATV\n";
        cout << "4. 20 mbps + CATV\n";
        cout << "5. Volver al Menu Principal...\n";
        cout << "Seleccione una opcion para el paquete de Internet: ";
        cin >> opcion;

        if (opcion >= 1 && opcion <= 4)
        {
            cout << "Velocidad: " << paquetes[opcion - 1].velocidad << " mbps\n";
            cout << "Descripción: " << paquetes[opcion - 1].descripcion << "\n";
            cout << "Precio: $" << paquetes[opcion - 1].precio << "\n";
        }
        else if (opcion == 5)
        {
            cout << "volviendo al Menu...";
            break;
        }
        else
        {
            cout << "Opción no válida.\n";
        }
    } while (opcion != 5);
}

void MostrarMenuOpcion()
{
    char opcion;
    do
    {
        MenuOpciones();
        cin >> opcion;
        cin.ignore();

        switch (opcion)
        {
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
int main()
{

    MostrarMenuOpcion();

    return 0;
}