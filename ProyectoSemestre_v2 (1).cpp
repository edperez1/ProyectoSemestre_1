#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <limits>
#include <algorithm>
#include <iomanip>
#include <regex>

/*Este es nuestro Proyecto Final de el Primer semestre de la clase de Logica y Algoritmos */

using namespace std;
// Estructura para almacenar la información de los paquetes de internet
struct PaqueteInternet
{
    string velocidad;
    string descripcion;
    double precio;
    
};

// Arreglo global de paquetes de internet

PaqueteInternet paquetes[] = {
    {"5", "Fibra optica hasta la casa.", 17.0},
    {"5", "Fibra optica hasta la casa y CATV.", 22.0},
    {"10", "Fibra optica hasta la casa y CATV.", 25.0},
    {"20", "Fibra optica hasta la casa y CATV.", 30.0}
};
// Estructura para almacenar la información de los clientes

struct Cliente
{
    int id;
    string nombre;
    string apellido;
    string direccion;
    int telefono;
    string cedula;
    int Departamento;
    int planInternet;
};
int ultimoId;
// Estructura para almacenar la información de las facturas

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
// Vector global para almacenar los clientes registrados
vector<Cliente> clientes;
// Función para eliminar un cliente por ID o nombre

void EliminarCliente()
{
    int opcion;
    do
    {
        cout << "Seleccione el criterio para eliminar el cliente:\n";
        cout << "1. Nombre\n";
        cout << "2. Cedula\n";
        cout << "3. Numero de telefono\n";
        cout << "4. Salir al menu principal\n";
        cout << "Opcion: ";
        while (!(cin >> opcion) || opcion < 1 || opcion > 4)
        {
            cout << "Opcion no valida. Por favor, intente de nuevo con un numero entre 1 y 4: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (opcion == 4)
        {
            cout << "Regresando al menu principal...\n";
            break; // Sale del bucle y regresa al menú principal
        }
        cin.ignore();
        cout << "Ingrese el valor correspondiente: ";
        string valorEliminar;
        getline(cin, valorEliminar);
        auto it = clientes.end();
        bool encontrado = false; // Añadido para verificar si se encontró el cliente
        switch (opcion)
        {
        case 1: // Nombre o Apellido
            it = remove_if(clientes.begin(), clientes.end(), [&](const Cliente &cliente)
                           { return cliente.nombre == valorEliminar || cliente.apellido == valorEliminar; });
            encontrado = it != clientes.end();
            break;
        case 2: // Cédula
            it = remove_if(clientes.begin(), clientes.end(), [&](const Cliente &cliente)
                           { return cliente.cedula == valorEliminar; });
            encontrado = it != clientes.end();
            break;
        case 3: // Número de teléfono
            int valorEliminarInt;
            try
            {
                valorEliminarInt = std::stoi(valorEliminar);
                it = remove_if(clientes.begin(), clientes.end(), [&](const Cliente &cliente)
                               { return cliente.telefono == valorEliminarInt; });
                encontrado = it != clientes.end();
            }
            catch (const std::invalid_argument &e)
            {
                cout << "El valor a eliminar no es un número válido.\n";
            }
            catch (const std::out_of_range &e)
            {
                cout << "El valor a eliminar está fuera de rango.\n";
            }
            break;
        }
        if (encontrado)
        {
            clientes.erase(it, clientes.end());
            cout << "Cliente(s) eliminado(s) exitosamente.\n";
        }
        else
        {
            cout << "Cliente no encontrado.\n";
        }
        system("pause");
        system("cls");
    } while (opcion != 4); // Mantiene al usuario en el menú de eliminación hasta que decida salir
}
// Función para agregar un nuevo cliente al sistema

void agregar_cliente()
{
    Cliente nuevo_cliente;

    cin.clear();                                         // Limpia el estado de error de cin
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta la entrada hasta el siguiente salto de línea
    nuevo_cliente.id = ultimoId++;
    // Validación del nombre
    // Validación del nombre
    bool nombre_valido = false;
    while (!nombre_valido) {
        cout << "Ingrese el nombre del cliente: ";
        getline(cin, nuevo_cliente.nombre);
        bool esNombreValido = true;
        // Verifica que el nombre solo contenga letras y no espacios
        for (char c : nuevo_cliente.nombre) {
            if (!isalpha(c) || nuevo_cliente.nombre.find(' ') != string::npos) {
                esNombreValido = false;
                break;
            }
        }
        if (esNombreValido) {
            nombre_valido = true;
        } else {
            cout << "El nombre no es válido. Por favor ingrese solo letras y sin espacios.\n";
        }
    }
    // Validacion de que sea un Apellido
    bool apellido_valido = false;
    while (!apellido_valido) {
        cout << "Ingrese el apellido del cliente: ";
        getline(cin, nuevo_cliente.apellido);
        // Verifica que el apellido contenga solo letras
        bool esApellidoValido = true;
        for (char c : nuevo_cliente.apellido) {
            if (!isalpha(c)) { // Cambiado para verificar solo letras
                esApellidoValido = false;
                break;
            }
        }
        if (esApellidoValido) {
            apellido_valido = true;
        } else {
            cout << "El apellido no es válido. Por favor ingrese un apellido que contenga solo letras.\n";
        }
    }
    cout << "Seleccione el departamento:\n";
    string departamentos[] = {"Atlantico Norte", "Atlantico Sur", "Boaco", "Carazo", "Chinandega", "Chontales", "Esteli", "Granada", "Jinotega", "Leon", "Madriz", "Managua", "Masaya", "Matagalpa", "Nueva Segovia", "Rio San Juan", "Rivas"};
    for (int i = 0; i < 17; ++i)
    {
        cout << i + 1 << ". " << departamentos[i] << "\n";
    }
    int departamentoSeleccionado = 0;
    do
    {
        cout << "Ingrese el numero del departamento (1-17): ";
        cin >> departamentoSeleccionado;
        if (cin.fail() || departamentoSeleccionado < 1 || departamentoSeleccionado > 17)
        {
            cout << "Opcion no valida. Por favor, intente de nuevo.\n";
            cin.clear();                                         // Limpia el estado de error de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta la entrada hasta el siguiente salto de línea
        }
        else
        {
            break; // Salir del bucle si la opción es válida
        }
    } while (true);
    nuevo_cliente.Departamento = departamentoSeleccionado;

    cin.ignore(); // Prepara para la siguiente entrada de texto

    cout << "Ingrese la direccion del cliente: ";
    getline(cin, nuevo_cliente.direccion);

    cout << "Ingrese el telefono del cliente: ";
    string telefonoStr;
    do
    {
        getline(cin, telefonoStr); // Usa getline para leer la línea completa, incluidos los espacios
        bool esNumeroValido = true;
        // Verifica si la cadena tiene exactamente 8 dígitos
        if (telefonoStr.length() == 8)
        {
            for (char c : telefonoStr)
            {
                if (!isdigit(c)) // Verifica si cada carácter no es un dígito
                {
                    esNumeroValido = false;
                    break;
                }
            }
        }
        else
        {
            esNumeroValido = false;
        }

        if (!esNumeroValido)
        {
            cout << "El numero de telefono debe de constar de 8 digitos segun el numero nacional. Por favor, intente de nuevo: ";
        }
        else
        {
            nuevo_cliente.telefono = stoi(telefonoStr); // Convierte la cadena a entero
            break;                                      // Sale del bucle si el número es válido
        }
    } while (true);

    cout << "Introduzca la cedula del cliente: ";
    string cedula;
    bool cedulaValida = false;
    while (!cedulaValida) {
        cin >> cedula;
        // Expresión regular para validar el formato de la cédula
        regex formatoCedula("^[0-9]{3}-[0-9]{6}-[0-9]{4}[a-zA-Z]$");
        if (regex_match(cedula, formatoCedula)) {
            // Verifica que la última letra no sea 'ñ' o 'Ñ'
            char ultimaLetra = cedula.back();
            if (ultimaLetra != 'ñ' && ultimaLetra != 'Ñ') {
                cedulaValida = true;
            } else {
                cout << "La cédula no puede terminar con 'ñ'. Intente de nuevo (Formato 000-000000-0000n): ";
            }
        } else {
            cout << "Intente de nuevo (Formato 000-000000-0000n): ";
        }
    }
    nuevo_cliente.cedula = cedula;
    int opcion_paquete;
    vector<PaqueteInternet> paquetes = {
        {"5 mbps", "Paquete 1", 17.0},
        {"5 mbps + CATV", "Paquete 2", 22.0},
        {"10 mbps + CATV", "Paquete 3", 25.0},
        {"20 mbps + CATV", "Paquete 4", 30.0}
    };
    do
    {
        cout << "1. 5 mbps (17$)\n";
        cout << "2. 5 mbps + CATV (22$)\n";
        cout << "3. 10 mbps + CATV (25$)\n";
        cout << "4. 20 mbps + CATV (30$)\n";
        cout << "Seleccione una opcion para el paquete de Internet (1-4): ";
        cin >> opcion_paquete;
        if (!cin.fail() && opcion_paquete >= 1 && opcion_paquete <= 4)
        {
            nuevo_cliente.planInternet = opcion_paquete;
            // Se actualiza el mensaje para incluir la descripción del paquete seleccionado
            cout << "Paquete seleccionado: " << opcion_paquete << ": " 
                 << paquetes[opcion_paquete - 1].velocidad << " mbps ("
                 << paquetes[opcion_paquete - 1].precio << "$)\n";
            break; // Salir del bucle si la opción es válida
        }
        else
        {
            cout << "Opcion no valida. Por favor, intente de nuevo.\n";
            cin.clear();                                         // Limpia el estado de error de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta la entrada hasta el siguiente salto de línea
        }
    } while (true);
            clientes.push_back(nuevo_cliente);
            cout << "Cliente agregado con exito. ID: " << nuevo_cliente.id << endl;
        }
// Función para obtener el nombre del departamento basado en un número
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
// Función para mostrar todos los clientes registrados

void mostrar_clientes() 
{
    if (clientes.empty())
    {
        cout << "No hay clientes registrados.\n";
        return;
    }
    cout << "\nListado de Clientes:\n";
    cout << "===============================================================================================================================================\n";
    cout << setw(5) << "ID" << " | "
         << setw(20) << "Nombre Completo" << " | "
         << setw(20) << "Departamento" << " | "
         << setw(30) << "Direccion" << " | "
         << setw(15) << "Telefono" << " | "
         << setw(20) << "Cedula" << " | "
         << setw(10) << "Plan" << "\n";
    cout << "===============================================================================================================================================\n";

    for (int i = 0; i < clientes.size(); i++) {
        Cliente clienteActual = clientes[i];
        cout << setw(5) << clienteActual.id << " | "
             << setw(20) << clienteActual.nombre + " " + clienteActual.apellido << " | "
             << setw(20) << obtenerNombreDepartamento(clienteActual.Departamento) << " | "
             << setw(30) << clienteActual.direccion << " | "
             << setw(15) << clienteActual.telefono << " | "
             << setw(20) << clienteActual.cedula << " | "
             << setw(10) << clienteActual.planInternet << "\n";
    }

    cout << "===============================================================================================================================================    \n";
}
// Función para buscar un cliente por ID o nombre

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
        cout << "1. Por Cedula\n";
        cout << "2. Por Nombre\n";
        cout << "3. Por Numero\n";
        cout << "4. Por Departamento\n";
        cout << "5. Por ID\n";
        cout << "6. Salir al menu principal\n";
        cout << "Ingrese una opcion: ";
       while (!(cin >> opcion) || opcion < 1 || opcion > 6) // Actualizar el rango de validación
        {
            cin.clear(); // Limpia el estado de error de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta la entrada hasta el siguiente salto de línea
            cout << "Opcion invalida. Por favor, ingrese un numero entre 1 y 6: ";
        }
        if (opcion == 6) // Condición para salir al menú principal
        {
            return; // Sale de la función, volviendo al menú principal
        }
        cin.ignore();
        bool encontrado = false;
        switch (opcion)
        {

        case 1:
            cout << "Ingrese la cedula del cliente: ";
            getline(cin, busqueda);
            for (const auto &cliente : clientes)
            {
                if (cliente.cedula == busqueda)
                {
                    cout << "Cliente encontrado:\n";
                    cout << "Nombre: " << cliente.nombre << "\nApellido: " << cliente.apellido << "\nDepartamento: " << cliente.Departamento << "\nDireccion: " << cliente.direccion << "\nTelefono: " << cliente.telefono << "\nCedula: " << cliente.cedula << "\n\n";
                    encontrado = true;
                }
            }
            if (!encontrado)
                cout << "Cliente no encontrado.\n";
            break;
        case 2:
            cout << "Ingrese el nombre del cliente: ";
            getline(cin, busqueda);
            for (const auto &cliente : clientes)
            {
                if (cliente.nombre == busqueda)
                {
                    cout << "Cliente encontrado:\n";
                    cout << "Nombre: " << cliente.nombre << "\nApellido: " << cliente.apellido << "\nDepartamento: " << cliente.Departamento << "\nDireccion: " << cliente.direccion << "\nTelefono: " << cliente.telefono << "\nCedula: " << cliente.cedula << "\n\n";
                    encontrado = true;
                }
            }
            if (!encontrado)
                cout << "Cliente no encontrado.\n";
            break;
        case 3:
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
                }
            }
            if (!encontrado)
                cout << "Cliente no encontrado.\n";
            break;

        case 4: // Caso para búsqueda por Departamento
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
        case 5: // Caso para búsqueda por ID
                cout << "Ingrese el ID del cliente: ";
                int idBusqueda;
                cin >> idBusqueda;
                for (const auto &cliente : clientes)
                {
                    if (cliente.id == idBusqueda)
                    {
                        cout << "Cliente encontrado:\n";
                           cout << "Nombre: " << cliente.nombre << "\nApellido: " << cliente.apellido << "\nDepartamento: " << obtenerNombreDepartamento(cliente.Departamento) << "\nDireccion: " << cliente.direccion << "\nTelefono: " << cliente.telefono << "\nCedula: " << cliente.cedula << "\n\n";
                        encontrado = true;
                        break;
                    }
                }
                if (!encontrado)
                    cout << "Cliente no encontrado.\n";
                break;
        }
        cout << "¿Desea buscar otro cliente o volver al menu principal? (s para buscar de nuevo/n para volver): ";
        cin >> seguir;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (seguir == 's' || seguir == 'B');
}

// Función para mostrar el menú principal y manejar las opciones seleccionadas
void MenuOpciones()
{
    cout << "                   >>--------------------------<<" << endl;
    cout << "                   ||      Menu Principal      ||" << endl;
    cout << "                   >>--------------------------<<" << endl;
    cout << "\n1. Menu de Empresa" << "\n2. Menu para Clientes" << "\n3. Salir del Programa" << endl;
    cout << "Seleccione una opcion: ";
}
// Mostrar paquetes de interent
void mostrarPrecios()
{
    cout << " -----Opciones de paquetes de Internet -----:\n";
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
// Vector donde se guardan las facturas
vector<Factura> facturas;
// Función para crear una nueva factura
void crearFactura()
{
    cout << "Ingrese el ID del cliente: ";
    string idClienteStr;
    cin >> idClienteStr;
    for (char c : idClienteStr) {
        if (!isdigit(c)) {
            cout << "El ID del cliente debe contener solo números.\n";
            return; // O manejar el error de manera adecuada
        }
    }
    int idCliente = stoi(idClienteStr);
    // Buscar el cliente por ID
    auto it = find_if(clientes.begin(), clientes.end(), [idCliente](const Cliente& cliente) {
        return cliente.id == idCliente;
    });
    if (it == clientes.end()) {
        cout << "Cliente no encontrado." << endl;
        return; // Salir de la función si no se encuentra el cliente
    }
    Cliente clienteFactura = *it; // Cliente encontrado
    // Asegúrate de que el índice del paquete esté dentro del rango válido
    if (clienteFactura.planInternet >= 1 && clienteFactura.planInternet <= sizeof(paquetes)/sizeof(paquetes[0])) {
        cout << "El cliente selecciono el plan de internet: " 
             << clienteFactura.planInternet << ". " 
             << paquetes[clienteFactura.planInternet - 1].velocidad << " mbps ("
             << paquetes[clienteFactura.planInternet - 1].precio << "$)\n";
    } else {
        cout << "Plan de internet no válido.\n";
        return;
    }

    // Crear una nueva factura y asignar el cliente encontrado
    Factura factura;
    factura.cliente = clienteFactura;

    cout << "Ingrese el periodo de la factura: ";
    string periodo;
    cin >> periodo;
    bool esValido = all_of(periodo.begin(), periodo.end(), [](char c) { return isalpha(c); });
    if (!esValido) {
        cout << "El periodo debe contener solo letras.\n";
        return; // O manejar el error de manera adecuada
    }
    factura.periodo = periodo;

    cout << "Ingrese la fecha de emision (DD/MM/AAAA): ";
    string fechaEmision;
    cin >> fechaEmision;
    regex fechaRegex("^\\d{2}/\\d{2}/\\d{4}$");
    if (!regex_match(fechaEmision, fechaRegex)) {
        cout << "Formato de fecha no valido.\n";
        return; // O manejar el error de manera adecuada
    }
    factura.fechaEmision = fechaEmision;

    cout << "Ingrese la fecha de vencimiento (DD/MM/AAAA): ";
    string fechaVencimiento;
    cin >> fechaVencimiento;
    if (!regex_match(fechaVencimiento, fechaRegex)) {
        cout << "Formato de fecha no válido.\n";
        return; // O manejar el error de manera adecuada
    }
    factura.fechaVencimiento = fechaVencimiento;

    cout << "Ingrese el saldo pendiente: ";
    double saldoPendiente;
    cin >> saldoPendiente;
    if (cin.fail() || saldoPendiente < 0) {
        cout << "El saldo pendiente debe ser un valor positivo.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return; // O manejar el error de manera adecuada
    }
    factura.saldoPendiente = saldoPendiente;

    cout << "Ingrese el total de la factura del mes: ";
    double facturaMes;
    cin >> facturaMes;
    if (cin.fail() || facturaMes < 0) {
        cout << "El total de la factura del mes debe ser un valor positivo.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return; // O manejar el error de manera adecuada
    }
    factura.facturaMes = facturaMes;

    cout << "Ingrese los abonos recibidos: ";
    double abonosRecibidos;
    cin >> abonosRecibidos;
    if (cin.fail() || abonosRecibidos < 0) {
        cout << "Los abonos recibidos deben ser un valor positivo.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return; // O manejar el error de manera adecuada
    }
    factura.pagosAbonosRecibidos = abonosRecibidos;

    // Calcular el subtotal de cargos del mes actual
    factura.subtotalCargosMesActual = factura.saldoPendiente + factura.facturaMes - factura.pagosAbonosRecibidos;

    // Agregar la nueva factura a la lista de facturas
    facturas.push_back(factura);

    cout << "Factura creada con exito.\n";
}
// Función para mostrar las facturas registradas

void mostrar_facturas()
{
    if (facturas.empty())
    {
        cout << "No hay facturas registradas.\n";
        return;
    }
    cout << "Lista de Facturas:\n";
    cout << "------------------\n";
    for (const auto &factura : facturas)
    {

        // Calcular el subtotal de cargos del mes actual

        cout << "Periodo: " << factura.periodo << "\n";
        cout << "Fecha de Emision: " << factura.fechaEmision << "\n";
        cout << "Fecha de Vencimiento: " << factura.fechaVencimiento << "\n";
        cout << "Cliente: " << factura.cliente.nombre << " " << factura.cliente.apellido << "\n";
        cout << "Direccion: " << factura.cliente.direccion << "\n";
        cout << "Telefono: " << factura.cliente.telefono << "\n";
        cout << "Plan de Internet: " << factura.cliente.planInternet << "\n";
        cout << "(+) Saldo pendiente: " << factura.saldoPendiente << "\n";
        cout << "(+) Factura del Mes: " << factura.facturaMes << "\n";
        cout << "(-) Pagos y Abonos Recibidos: " << factura.pagosAbonosRecibidos << "\n";
        cout << "SUBTOTAL CARGOS MES ACTUAL: " << factura.subtotalCargosMesActual << "\n";
        cout << "------------------\n";
    }
}
// Funcion para base de menu_empresa
void mostrar_menu()
{
    cout << "\n-----Menu de empresa-----\n";
    cout << "1. Agregar Cliente\n";
    cout << "2. Eliminar Cliente\n";
    cout << "3. Buscar Cliente\n";
    cout << "4. Mostrar Clientes\n";
    cout << "5. Crear Factura\n";
    cout << "6. Mostrar Facturas\n";
    cout << "7. Salir\n";
    cout << "Seleccione una opcion: ";
}
// Funcion donde se muestra el menu de empresa
void menu_empresa()
{
    int opcion = 0;
    do
    {
        system("cls");
        cout << "\n-----Menu de empresa-----\n";
        cout << "1. Agregar Cliente\n";
        cout << "2. Eliminar Cliente\n";
        cout << "3. Buscar Cliente\n";
        cout << "4. Mostrar Clientes\n";
        cout << "5. Crear Factura\n";
        cout << "6. Mostrar Facturas\n";
        cout << "7. Salir\n";
        cout << "Seleccione una opcion: ";

        while (!(cin >> opcion) || opcion < 1 || opcion > 7)
        {
            cout << "Opcion no valida. Por favor, intente de nuevo con un numero entre 1 y 7: ";
            cin.clear();                                         // Limpia el estado de error de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta la entrada hasta el siguiente salto de línea
        }
        system("cls");
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
            mostrar_facturas();
            system("pause");
            system("cls");
            break;
        case 7:
            cout << "Saliendo...\n";
            break;
        default:
            break;
        }
    } while (opcion != 7);
}
// Funcion para el mostrar el menu de clientes
// Funcion para el mostrar el menu de clientes
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
        
        while (!(cin >> opcion)) {
            cout << "Por favor, introduzca un numero válido: ";
            cin.clear(); // Limpia el estado de error de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta la entrada hasta el siguiente salto de línea
        }

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
// Funcion para seleccionar las anteriores funciones
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

// Función principal del programa
int main()
{

    MostrarMenuOpcion();

    return 0;
}