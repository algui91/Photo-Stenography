/*
 * @file procesar.cpp
 * @brief Este módulo implementa funciones para inicializar
 * una transformación (desplazamiento, negativo, etc.).
 *  Created on: Mar 15, 2012
 *      @author: Alejandro Alcalde
 */

#include <cstdlib>

#include "../include/transformaciones.h"
#include "../include/transformacion.h"

void generar_negativo(char* mode[]){

	Transformacion tr_negativa;

	char tipo = *mode[1];

	for (int i = tr_negativa.get_tam()-1; i>=0 ; i--)
		tr_negativa.set(i, 255-i);
	tr_negativa.write(reinterpret_cast<char*>(mode[2]), tipo);

}

//-----------------------------------------------------------------------------------------------------------------------

void generar_desplazar(char* mode[]){
	Transformacion tr_despl;

	char tipo 			= *mode[1];
	int desplazamiento  = atoi(mode[4]);

	for (int i = 0; i < tr_despl.get_tam()-1 ; i++)
		tr_despl.set(i, i << desplazamiento);
	tr_despl.write(mode[2], tipo);

}

//-----------------------------------------------------------------------------------------------------------------------

void generar_umbralizar(char* mode[]){
	Transformacion tr_umb;

	char tipo  = *mode[1];
	int v  	   = atoi(mode[4]);

	for (int i = 0; i < tr_umb.get_tam()-1 ; i++)
		tr_umb.set(i, i <= v ? 0:255);
	tr_umb.write(mode[2], tipo);

}

//-----------------------------------------------------------------------------------------------------------------------

void generar_brillo(char* mode[]){
	Transformacion tr_bri;

	char tipo 	= *mode[1];
	int brillo  = atoi(mode[4]);

	for (int i = 0; i < tr_bri.get_tam()-1 ; i++)
		if (i + brillo < 0)
			tr_bri.set(i, 0);
		else if (i + brillo > 255)
			tr_bri.set(i, 255);
		else tr_bri.set(i, i + brillo);
	tr_bri.write(mode[2], tipo);

}
