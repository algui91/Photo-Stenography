/**
 * @file generar.cpp
 * @brief Programa encargado de generar archivos trf de transformaciones de imágenes
 *
 *	Created on: Jun 04, 2012
 *		@author: Alejandro Alcalde
 */

#include <iostream>
#include <string>
#include <cstdlib>

#include "../include/transformaciones.h"

void print_help(){
	std::cout << "Uso: generar <t|b> <archivo de transformacion> <tipo transformacion> <param adicionales>" << std::endl;

	std::cout << "<t|b>:" 																					<< std::endl
			  << "\t b si la transformación se escribirá en el archivo de forma binaria, o t para texto." 	<< std::endl
			  << "<archivo de transformacion>"																<< std::endl
			  << "\t Nombre del archivo de transformación a generar"										<< std::endl
			  << "<tipo transformacion>"																	<< std::endl
			  << "\t negativo:   Genera la trasnformacion para un negativo."			  					<< std::endl
			  << "\t brillo:     Genera la trasnformacion aclarar una imagen."								<< std::endl
			  << "\t umbralizar: Genera la trasnformacion umbralizar (blanco o negro)."						<< std::endl
			  << "\t desplazar:  Genera la trasnformacion para desplazar los valores n bits."				<< std::endl
			  << "<param adicionales>:"																		<< std::endl
			  << "\t El número deseado para las opciones brillo, umbralizar y desplazar"					<< std::endl;
}

//-----------------------------------------------------------------------------------------------------------------------

int main(int argc, char *argv[]) {

	if (argc < 2){
		print_help();
		return -1;
	}else{

		std::string negativo  = "negativo";
		std::string desplazar = "desplazar";
		std::string umbralizar= "umbralizar";
		std::string brillo    = "brillo";

		if(argv[4] && !atoi(argv[4])){
			std::cout << "El cuarto argumento debe ser un número" << std::endl;
			return -1;
		}

		if(argv[3] == negativo)
			generar_negativo(argv);
		else if (argv[3] == desplazar)
			generar_desplazar(argv);
		else if (argv[3] == umbralizar)
			generar_umbralizar(argv);
		else if (argv[3] == brillo)
			generar_brillo(argv);
	}
	return 0;
}


