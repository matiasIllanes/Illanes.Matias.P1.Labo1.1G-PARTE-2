#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "vuelo.h"
#include "avion.h"
int listarAvionesAerolinea(eAvion vecAvion[], eAerolinea vecAerolinea[], eTipo vecTipo[], int tamA, int tamAe, int tamT);
int listarAvionesTipo(eAvion vecAvion[], eAerolinea vecAerolinea[], eTipo vecTipo[], int tamA, int tamAe, int tamT);
int mostrarPorcentajeJetAerolinea(eAvion vecAvion[], eAerolinea vecAerolinea[], eTipo vecTipo[], int tamA, int tamAe, int tamT);
int listarAvionesTodasAerolineas(eAvion vecAvion[], eAerolinea vecAerolinea[], eTipo vecTipo[], int tamA, int tamAe, int tamT);
int mostrarAerolineaMasPasajeros(eAvion vecAvion[], eAerolinea vecAerolinea[], eTipo vecTipo[], int tamA, int tamAe, int tamT);
int mostrarAerolineaMenosAviones(eAvion vecAvion[], eAerolinea vecAerolinea[], eTipo vecTipo[], int tamA, int tamAe, int tamT);
int listarVuelosAvion(eVuelo vecVuelo[], eDestino vecDestino[], eAvion vecAvion[], eAerolinea vecAerolinea[], eTipo vecTipo[], int tamV, int tamD, int tamA, int tamAe, int tamT);
int mostrarPrecioVuelosAvion(eVuelo vecVuelo[], eDestino vecDestino[], eAvion vecAvion[], eAerolinea vecAerolinea[], eTipo vecTipo[], int tamV, int tamD, int tamA, int tamAe, int tamT);


#endif // INFORMES_H_INCLUDED
