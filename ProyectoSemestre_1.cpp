#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <limits>
#include <algorithm>

/*Este es nuestro Proyecto Final de el Primer semestre de la clase de Logica y Algoritmos */

// acordarse
// agregar filtro
// agregar "mostrar todos los clientes"
// agregar crear factura
// agregar morosos, no morosos
// agregar validaciones
// agregar que plan desea comprar en factura

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
    int Departamento;
};
struct Factura
{
    string periodo;
    string fechaEmision;
    string fechaVencimiento;
    Cliente cliente;
    double saldoPendiente;
    double facturaMes;
    double pagosAbonosRecibidos;
    double subtotalCargosMesActual;
};
// Funciones principales.
vector<Cliente> clientes;
void EliminarCliente()
{
    int opcion;
    string valorEliminar;
    cout << "Seleccione el criterio para eliminar el cliente:\n";
    cout << "1. Nombre\n";
    cout << "2. Cedula\n";
    cout << "3. Numero de telefono\n";
    cout << "Opcion: ";
    cin >> opcion;
    cin.ignore(); // Limpia el buffer después de leer un número

    cout << "Ingrese el valor correspondiente: ";
    getline(cin, valorEliminar);

    auto it = clientes.end(); // Inicializa el iterador al final como valor por defecto

    switch (opcion)
    {
    case 1: // Nombre o Apellido
        it = remove_if(clientes.begin(), clientes.end(), [&](const Cliente &cliente)
                       { return cliente.nombre == valorEliminar || cliente.apellido == valorEliminar; });
        clientes.erase(it, clientes.end()); // Completa la eliminación
        break;
    case 2: // Cédula
        it = remove_if(clientes.begin(), clientes.end(), [&](const Cliente &cliente)
                       { return cliente.cedula == valorEliminar; });
        clientes.erase(it, clientes.end()); // Completa la eliminación
        break;
    case 3: // Número de teléfono
        int valorEliminarInt;
        try
        {
            valorEliminarInt = std::stoi(valorEliminar);
        }
        catch (const std::invalid_argument &e)
        {
            cout << "El valor a eliminar no es un número válido.\n";
            break;
        }
        catch (const std::out_of_range &e)
        {
            cout << "El valor a eliminar está fuera de rango.\n";
            break;
        }

        it = remove_if(clientes.begin(), clientes.end(), [&](const Cliente &cliente)
                       { return cliente.telefono == valorEliminarInt; });
        clientes.erase(it, clientes.end()); // Completa la eliminación
        break;
    }

    // Verifica si se encontraron elementos para eliminar
    if (it != clientes.end())
    {
        clientes.erase(it, clientes.end());
        cout << "Cliente(s) eliminado(s) exitosamente.\n";
    }
    else
    {
        cout << "Cliente no encontrado.\n";
    }
}

void agregar_cliente()
{
    Cliente nuevo_cliente;
    cout << "Ingrese el nombre del cliente: ";
    getline(cin, nuevo_cliente.nombre);
    cout << "Ingrese el apellido del cliente: ";
    getline(cin, nuevo_cliente.apellido);
    cout << "Seleccione el departamento:\n";
    string departamentos[] = {"Atlantico Norte", "Atlantico Sur", "Boaco", "Carazo", "Chinandega", "Chontales", "Esteli", "Granada", "Jinotega", "Leon", "Madriz", "Managua", "Masaya", "Matagalpa", "Nueva Segovia", "Rio San Juan", "Rivas"};
    for (int i = 0; i < 17; ++i)
    {
        cout << i + 1 << ". " << departamentos[i] << "\n";
    }
    cout << "Ingrese el numero del departamento: ";
    cin >> nuevo_cliente.Departamento;
    cin.ignore();

    cout << "Ingrese la direccion del cliente: ";
    getline(cin, nuevo_cliente.direccion);

    cout << "Ingrese el telefono del cliente: ";
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
                cout << "Ingrese un Numero Nacional. ";
            }
        }
        else
        {
            cout << "Ingrese Un Numero  ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    cout << "Introduzca la cedula de el cliente: ";
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
    cout << "Que plan desea el ciente? \n";

    clientes.push_back(nuevo_cliente);
    cout << "Cliente agregado con exito." << endl;
}
// lista de departamentos para que se muestren
string obtenerNombreDepartamento(int numeroDepartamento)
{
    string departamentos[] = {"Atlantico Norte", "Atlantico Sur", "Boaco", "Carazo", "Chinandega", "Chontales", "Esteli", "Granada", "Jinotega", "Leon", "Madriz", "Managua", "Masaya", "Matagalpa", "Nueva Segovia", "Rio San Juan", "Rivas"};
    if (numeroDepartamento > 0 && numeroDepartamento <= 17)
    {
        return departamentos[numeroDepartamento - 1];
    }
    else
    {
        return "Departamento desconocido";
    }
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
        cout << "Nombre: " << cliente.nombre << "\nApellido: " << cliente.apellido << "\nDepartamento: " << obtenerNombreDepartamento(cliente.Departamento) << "\nDireccion: " << cliente.direccion << "\nTelefono: " << cliente.telefono << "\nCedula: " << cliente.cedula << "\n";
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
        system("cls");
        cout << "Seleccione el criterio de busqueda:\n";
        cout << "1. Por Plan\n"; // esta no esta hecha jejeje
        cout << "2. Por Cedula\n";
        cout << "3. Por Nombre\n";
        cout << "4. Por Numero\n";
        cout << "5. Por Departamento\n";
        cout << "Ingrese una opcion: ";

        while (!(cin >> opcion) || opcion < 1 || opcion > 5)
        {
            cout << "Opcion invalida. Por favor, ingrese un numero entre 1 y 5: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore();

        bool encontrado = false;
        switch (opcion)
        {
        case 1:
            cout << "funcionalidad no implementada aun.\n";
            // no he hecho esta atento ( es q ta muy complicada pq hace falta añadir que plan quiere el cliente o el manejo de archivos)
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
                    // break; // Elimina esta línea
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
                    // break; // Elimina esta línea
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
                    // break; // Elimina esta línea
                }
            }
            if (!encontrado)
                cout << "Cliente no encontrado.\n";
            break;

        case 5: // Caso para búsqueda por Departamento
            int numDepartamento;
            cout << "Ingrese el numero del departamento: ";
            while (!(cin >> numDepartamento))
            {
                cout << "Por favor, ingrese un numero valido para el departamento: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            for (const auto &cliente : clientes)
            {
                if (cliente.Departamento == numDepartamento)
                {
                    cout << "Cliente encontrado:\n";
                    cout << "Nombre: " << cliente.nombre << "\nApellido: " << cliente.apellido << "\nDepartamento: " << obtenerNombreDepartamento(cliente.Departamento) << "\nDireccion: " << cliente.direccion << "\nTelefono: " << cliente.telefono << "\nCedula: " << cliente.cedula << "\n\n";
                    encontrado = true;
                    // No se detiene después de encontrar el primer cliente
                }
            }
            if (!encontrado)
                cout << "Cliente no encontrado.\n";
            break;
        }

        cout << "Desea buscar otro cliente o volver al menu principal? (s para buscar de nuevo/n para volver): ";
        cin >> seguir;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (seguir == 's' || seguir == 'B');
}

// menu principal (1,2,3)
void MenuOpciones()
{
    cout << "                   -----Menu Principal-----" << endl;
    cout << "\n1. Menu de Empresa" << "\n2. Menu para Clientes" << "\n3. Salir del Programa" << endl;
    cout << "Seleccione una opcion: ";
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
void crearFactura()
{
    Factura factura;

    // Solicitar datos de la factura
    cout << "Ingrese el periodo de la factura: ";
    cin >> factura.periodo;
    cout << "Ingrese la fecha de emision (DD/MM/AAAA): ";
    cin >> factura.fechaEmision;
    cout << "Ingrese la fecha de vencimiento (DD/MM/AAAA): ";
    cin >> factura.fechaVencimiento;

    // Solicitar datos del cliente
    cout << "Ingrese el nombre del cliente: ";
    cin >> factura.cliente.nombre;
    cout << "Ingrese el apellido del cliente: ";
    cin >> factura.cliente.apellido;
    cout << "Ingrese la direccion del cliente: ";
    cin.ignore();                            // Ignora el '\n' que queda en el buffer
    getline(cin, factura.cliente.direccion); // Permite espacios en la dirección
    cout << "Ingrese el telefono del cliente: ";
    cin >> factura.cliente.telefono;

    // Solicitar detalles de la factura
    cout << "Ingrese el saldo pendiente: ";
    cin >> factura.saldoPendiente;
    cout << "Ingrese el total de la factura del mes: ";
    cin >> factura.facturaMes;
    cout << "Ingrese el total de pagos y abonos recibidos: ";
    cin >> factura.pagosAbonosRecibidos;

    // Calcular el subtotal de cargos del mes actual
    factura.subtotalCargosMesActual = factura.saldoPendiente + factura.facturaMes - factura.pagosAbonosRecibidos;

    // Imprimir la factura
    cout << "\n----- FACTURA -----\n";
    cout << "Periodo: " << factura.periodo << endl;
    cout << "Fecha de Emision: " << factura.fechaEmision << endl;
    cout << "Fecha de Vencimiento: " << factura.fechaVencimiento << endl;
    cout << "CLIENTE: " << factura.cliente.nombre << " " << factura.cliente.apellido << endl;
    cout << "Direccion: " << factura.cliente.direccion << endl;
    cout << "Telefono: " << factura.cliente.telefono << endl;
    cout << "(+) Saldo pendiente: " << factura.saldoPendiente << endl;
    cout << "(+) Factura del Mes: " << factura.facturaMes << endl;
    cout << "(-) Pagos y Abonos Recibidos: " << factura.pagosAbonosRecibidos << endl;
    cout << "DETALLE\n";
    cout << "SUBTOTAL CARGOS MES ACTUAL: " << factura.subtotalCargosMesActual << endl;
}
void mostrar_menu()
{
    cout << "\nMenu de empresa\n";
    cout << "1. Agregar Cliente\n";
    cout << "2. Eliminar Cliente\n";
    cout << "3. Buscar Cliente\n";
    cout << "4. Mostrar Clientes\n";
    cout << "5. Crear Factura\n";
    cout << "6. Salir\n";
    cout << "Seleccione una opcion: ";
}

void menu_empresa()
{
    int opcion = 0;
    do
    {
        cout << "\nMenu de empresa\n";
        cout << "1. Agregar Cliente\n";
        cout << "2. Eliminar Cliente\n";
        cout << "3. Buscar Cliente\n";
        cout << "4. Mostrar Clientes\n";
        cout << "5. Crear Factura\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        // esta onda de cin ignore esta en mucha parte del codigo, sirve para limpiar el buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcion)
        {
        case 1:
            agregar_cliente();
            system("pause");
            system("cls");

            break;
        case 2:
            EliminarCliente();
            system("pause");
            system("cls");
            break;
        case 3:
            buscar_cliente();
            system("pause");
            system("cls");
            break;
        case 4:
            mostrar_clientes();
            system("pause");
            system("cls");
            break;
        case 5:
            crearFactura();
            system("pause");
            system("cls");
            break;
        case 6:
            cout << "Saliendo...\n";

            break;
        default:
            cout << "Opcion no valida. Por favor, intente de nuevo.\n";
        }
    } while (opcion != 6);
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
            cout << "Volviendo al Menu...";
            break;
        }
        else
        {
            cout << "Opcion no valida.\n";
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
        system("cls");
        cin.ignore();

        switch (opcion)
        {
        case '1':
            menu_empresa();
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
            cout << "Opcion invalida. Inténtelo de nuevo." << endl;
        }
    } while (opcion != '3');
}
int main()
{

    MostrarMenuOpcion();

    return 0;
}