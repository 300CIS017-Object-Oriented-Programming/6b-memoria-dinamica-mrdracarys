#ifndef ADMINISTRACION_H
#define ADMINISTRACION_H

#include <iostream>
#include "Propietario.h"
#include "Propiedad.h"
#include <vector>

using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::vector;

class Administracion
{
private:
    float cobroAscensor;
    float costoBase;
    float recargo;
    int contIds;
    vector<Propietario *> propietarios;
    vector<Propiedad *> propiedades;

    void inicializarDatos();

public:
    Administracion();

    virtual ~Administracion();

    void imprimirPropietariosConParqueadero();

    void imprimirUnPropietario(double id);

    void imprimirPropietarios();

    void imprimirPropietariosSinCuarto();

    void imprimirPropietariosCuartoUtil(bool isTerminado); // Ojo un solo método sirve para las dos funciones.
    void recaudarAdministracion();

    void agregarPropiedad();

    void agregarPropietario();

    void relacionarPropietarioPropiedad();

    // Nuevo método para generar el reporte de propiedades
    void generarReportePropiedades();

    // Nuevo método para actualizar el estado del cuarto útil
    void actualizarEstadoCuartoUtil(double idPropiedad, bool nuevoEstado);

};

#endif