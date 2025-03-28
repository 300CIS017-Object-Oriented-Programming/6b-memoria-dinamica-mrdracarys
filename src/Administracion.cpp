#include <iostream>
#include "Administracion.h"


Administracion::Administracion() {
    cout << "Entre al constructor de administracion \n";
    cobroAscensor = 2000;
    costoBase = 150000;
    recargo = 0.05;
    contIds = 1; // Un incremental automatico de ids de propiedades
    inicializarDatos();

    cout << "Terminé la inicializacion \n";
}

/*
 * Método para instanciar los objetos que se usarán en el código
 */
void Administracion::inicializarDatos() {
    Propietario *persona1 = new Propietario();
    cout << "Objeto Propietario 'persona1' creado exitosamente." << endl;
    Propietario *persona2 = new Propietario();
    cout << "Objeto Propietario 'persona2' creado exitosamente." << endl;
    Propietario *persona3 = new Propietario();
    cout << "Objeto Propietario 'persona3' creado exitosamente." << endl;
    Propietario *persona4 = new Propietario();
    cout << "Objeto Propietario 'persona4' creado exitosamente." << endl;

    Propiedad *prop1 = new Propiedad();
    cout << "Objeto Propiedad 'prop1' creado exitosamente." << endl;
    Propiedad *prop2 = new Propiedad();
    cout << "Objeto Propiedad 'prop2' creado exitosamente." << endl;
    Propiedad *prop3 = new Propiedad();
    cout << "Objeto Propiedad 'prop3' creado exitosamente." << endl;
    Propiedad *prop4 = new Propiedad(); // Constructor por defecto
    cout << "Objeto Propiedad 'prop4' creado exitosamente." << endl;

    CuartoUtil *cuarto1 = new CuartoUtil();
    cout << "Objeto CuartoUtil 'cuarto1' creado exitosamente." << endl;
    CuartoUtil *cuarto2 = new CuartoUtil();
    cout << "Objeto CuartoUtil 'cuarto2' creado exitosamente." << endl;
    CuartoUtil *cuarto3 = new CuartoUtil();
    cout << "Objeto CuartoUtil 'cuarto3' creado exitosamente." << endl;

    // Inicializar cuartos útiles
    vector<CuartoUtil *> cuartosUtiles;
    cuarto1->setPiso(2);
    cuarto1->setNumeracion("A201");
    cuarto1->setEstaTerminado(false);

    cuarto2->setPiso(2);
    cuarto2->setNumeracion("A202");
    cuarto2->setEstaTerminado(true);

    cuarto3->setPiso(2);
    cuarto3->setNumeracion("A203");
    cuarto3->setEstaTerminado(true);

    cuartosUtiles.push_back(cuarto1);
    cuartosUtiles.push_back(cuarto2);
    cuartosUtiles.push_back(cuarto3);

    // Inicializar propiedades
    prop1->setNumIdentificacion(contIds++);
    prop1->setAreaPropiedad(160);
    prop1->setHayParqueadero(true);
    prop1->setPiso(10);

    prop2->setNumIdentificacion(contIds++);
    prop2->setAreaPropiedad(30);
    prop2->setHayParqueadero(false);
    prop2->setPiso(9);

    prop3->setNumIdentificacion(contIds++);
    prop3->setAreaPropiedad(45);
    prop3->setHayParqueadero(true);
    prop3->setPiso(7);

    prop4->setNumIdentificacion(contIds++);
    prop4->setAreaPropiedad(60);
    prop4->setHayParqueadero(false);
    prop4->setPiso(5);

    propiedades.push_back(prop1);
    propiedades.push_back(prop2);
    propiedades.push_back(prop3);
    propiedades.push_back(prop4);

    // Inicializo propietarios
    persona1->setNombre("Debora Vilar");
    persona1->setIdentificacion(20202492);
    persona1->setPropiedad(prop1);
    persona1->getPropiedad()->setCuartoUtil(cuarto1);

    // Imprimir direcciones de memoria para verificar que la propiedad asignada es la misma que prop1
    cout << "Dirección de memoria de persona1: " << persona1 << endl;
    cout << "Dirección de memoria de la propiedad asignada a persona1: " << persona1->getPropiedad() << endl;
    cout << "Dirección de memoria de prop1: " << prop1 << endl;

    persona2->setNombre("Ignacio Rodriguez");
    persona2->setIdentificacion(88888);
    persona2->setPropiedad(prop2);
    persona2->getPropiedad()->setCuartoUtil(cuarto2);

    persona3->setNombre("Erika Munoz");
    persona3->setIdentificacion(1058845781);
    persona3->setPropiedad(prop3);
    persona3->getPropiedad()->setCuartoUtil(cuarto3);

    persona4->setNombre("Modesto Villaverde");
    persona4->setIdentificacion(31321432);
    persona4->setPropiedad(prop4);


    // Incluir los propietarios en el vector
    propietarios.push_back(persona1);
    propietarios.push_back(persona2);
    propietarios.push_back(persona3);
    propietarios.push_back(persona4);
}

void Administracion::agregarPropiedad() {
    int piso;
    float area;
    double id;
    bool parqueadero;
    int cuarto;

    Propiedad *propTemp;

    cout << "Indique el piso\n";
    cin >> piso;
    cout << "Indique el area\n";
    cin >> area;
    cout << "Indique el numero de identificacion\n";
    cin >> id;
    cout << "[1] parqueadero\n"
            "[0] no parqueadero\n";
    cin >> parqueadero;
    cout << "[1] Tiene cuarto util\n"
            "[0] No tiene cuarto util\n";
    cin >> cuarto;

    if (cuarto == 1) {
        string numeracion;
        int pisoCuarto;
        int terminado;
        bool estaTerminado;
        CuartoUtil *nuevoCuarto = new CuartoUtil();

        //Pedir datos del cuarto util
        cout << "Indique la numeracion \n";
        cin >> numeracion;
        cout << "Indique el piso \n";
        cin >> pisoCuarto;
        cout << "[1] Terminado\n"
                "[0] Sin terminar\n";
        cin >> terminado;
        estaTerminado = (terminado = 0) ? true : false;

        //Crear el cuarto util
        nuevoCuarto->setNumeracion(numeracion);
        nuevoCuarto->setPiso(pisoCuarto);
        nuevoCuarto->setEstaTerminado(estaTerminado);

        propTemp = new Propiedad(id, piso, area, parqueadero, nuevoCuarto);
    } else {
        // Se envía NULL en el cuarto útil
        propTemp = new Propiedad(id, piso, area, parqueadero, nullptr);
    }
    propiedades.push_back(propTemp);
    cout << "\nPropiedad agregada" << endl;
}

void Administracion::agregarPropietario() {
    string nombre;
    long id;
    cout << "Ingrese el nombre:" << endl;
    cin.ignore(); // Importante para quitar el salto de línea en caso de que exista
    getline(cin, nombre); // Sirve para leer cadenas
    cout << "Ingrese el id:" << endl;
    cin >> id;
    Propietario *propTemp = new Propietario();
    propTemp->setNombre(nombre);
    propTemp->setIdentificacion(id);
    propietarios.push_back(propTemp);
}


void Administracion::relacionarPropietarioPropiedad() {
    double id;
    bool idFound = false;
    int idPropiedad;
    bool idPropiedadFound = false;

    int idxTempPropietario = -1;
    int idxTempPropiedad = -1;


    cout << "Ingrese el id de la propiedad, -1 para cancelar" << endl;
    cin >> idPropiedad;

    cout << "Ingrese id del propietario, - 1 para cancelar" << endl;
    cin >> id;


    for (int i = 0; i < propietarios.size() && !idFound; ++i) {
        if (propietarios[i]->getIdentificacion() == id) {
            // Se verifica que el propietario no tenga previamente una propiedad
            if (propietarios[i]->getPropiedad() == nullptr) {
                idFound = true;
                idxTempPropietario = i;
            } else {
                cout << " No es posible seleccionar el propietario con id " << id
                        << "este propietario ya tiene una propiedad asociada" << endl;
                break;
            }
        }
    }

    if (!idFound) {
        cout << "Id de propietario no encontrado " << endl;
    } else {
        for (int i = 0; i < propiedades.size() && !idPropiedadFound; ++i) {
            if (propiedades[i]->getNumIdentificacion() == idPropiedad) {
                idPropiedadFound = true;
                idxTempPropiedad = i;
            }
        }
        if (!idPropiedadFound) {
            cout << "Id de propiedad no encontrado " << endl;
        }
    }

    if (idFound && idPropiedadFound) {
        Propiedad *propiedadTemp = propiedades[idxTempPropiedad];
        propietarios[idxTempPropietario]->setPropiedad(propiedadTemp);
        cout << "Propietario " << propietarios[idxTempPropietario]->getNombre() << " asociado con propiedad "
                << propiedadTemp->getNumIdentificacion() << endl;
    }
}


void Administracion::imprimirUnPropietario(double id) {
    bool found = false;
    // Vamos a buscar si un propietario dado esta o no esta en el vector primero
    // Con la bandera es posible controlar que el ciclo pare una vez se ha encontrado el propietario
    for (int i = 0; i < propietarios.size() && !found; i++) {
        if (propietarios[i]->getIdentificacion() == id) {
            propietarios[i]->mostrarDatos();
            found = true;
        }
    }

    // MUY importante controlar los casos de error.
    // Inicialmente lo haremos con cout pero hay mejores maneras de hacerlo
    if (!found) {
        cout << "ERROR: Propietario con id " << id << " no encontrado" << endl;
    }
}

void Administracion::imprimirPropietarios() {
    // Recorrer el arreglo e imprimir todos los propietarios
    for (int i = 0; i < propietarios.size(); i++) {
        propietarios[i]->mostrarDatos();
    }
}

void Administracion::imprimirPropietariosConParqueadero() {
    cout << "Propietarios con parqueadero:\n" << endl;

    for (int i = 0; i < propietarios.size(); i++) {
        if (propietarios[i]->getPropiedad()->isHayParqueadero()) {
            propietarios[i]->mostrarDatos();
        }
    }
}

void Administracion::recaudarAdministracion() {
    float valorAdministracion = 0;
    for (int i = 0; i < propietarios.size(); i++) {
        // Apesar de que tenemos cuarto util la lógica aquí no es necesario que cambie, pq es un ajuste que se puede hacer
        // desde el método calcularRecargo de Propiedad.
        valorAdministracion += propietarios[i]->getPropiedad()->calcularRecargo(cobroAscensor, costoBase, recargo);
    }

    cout << "Este es el valor de administracion " << valorAdministracion << endl;
}


Administracion::~Administracion() {
    for (int i = 0; i < propietarios.size(); i++) {
        // LLama al destructor por cada elemento del arreglo
        delete propietarios[i];
    }

    // Se deben eliminar los datos de todas las colecciones que tenga la clase
    for (int i = 0; i < propiedades.size(); i++) {
        // LLama al destructor por cada elemento del arreglo
        delete propiedades[i];
    }
    cout << "LLame al destructor, elimine todo y termine" << endl;
}


void Administracion::imprimirPropietariosSinCuarto() {
    for (int i = 0; i < propietarios.size(); ++i) {
        if (propietarios[i]->getPropiedad() != nullptr) {
            if (propietarios[i]->getPropiedad()->getCuartoUtil() == nullptr) {
                propietarios[i]->mostrarDatos();
            }
        }
    }
}

void Administracion::imprimirPropietariosCuartoUtil(bool isTerminado) {
    for (auto &propietario: propietarios) {
        if (propietario->getPropiedad() != nullptr) {
            if (propietario->getPropiedad()->getCuartoUtil() != nullptr &&
                propietario->getPropiedad()->getCuartoUtil()->isEstaTerminado() == isTerminado) {
                propietario->mostrarDatos();
            }
        }
    }
}

void Administracion::generarReportePropiedades() {
    float totalRecaudado = 0.0f;
    cout << "=== Reporte de Propiedades ===" << endl;

    for (size_t i = 0; i < propietarios.size(); ++i) {
        Propietario* propietario = propietarios[i];
        cout << "\nPropietario: " << propietario->getNombre()
             << ", ID: " << propietario->getIdentificacion() << endl;

        if (propietario->getPropiedad() != nullptr) {
            cout << "Información de la propiedad:" << endl;
            propietario->getPropiedad()->mostrarDatos();

            if (propietario->getPropiedad()->getCuartoUtil() != nullptr) {
                cout << "La propiedad tiene un cuarto util." << endl;
            } else {
                cout << "La propiedad no tiene cuarto util." << endl;
            }

            // Sumar el recargo calculado para esta propiedad
            totalRecaudado += propietario->getPropiedad()->calcularRecargo(cobroAscensor, costoBase, recargo);
        } else {
            cout << "No tiene propiedad asignada." << endl;
        }

        cout << "---------------------------------" << endl;
    }

    cout << "\nTotal de administracion recaudada: " << totalRecaudado << endl;
}

void Administracion::actualizarEstadoCuartoUtil(double idPropiedad, bool nuevoEstado) {
    bool propiedadEncontrada = false;
    for (size_t i = 0; i < propiedades.size(); ++i) {
        if (propiedades[i]->getNumIdentificacion() == idPropiedad) {
            propiedadEncontrada = true;
            CuartoUtil* cuarto = propiedades[i]->getCuartoUtil();
            if (cuarto != nullptr) {
                cuarto->setEstaTerminado(nuevoEstado);
                cout << "El estado del cuarto util de la propiedad "
                     << idPropiedad << " se ha actualizado a "
                     << (nuevoEstado ? "terminado" : "No terminado") << endl;
            } else {
                cout << "La propiedad " << idPropiedad
                     << " no tiene cuarto util asignado." << endl;
            }
            break;
        }
    }
    if (!propiedadEncontrada) {
        cout << "Propiedad con ID " << idPropiedad << " no encontrada." << endl;
    }
}


