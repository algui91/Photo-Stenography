/**
 * @file componer.cpp
 * @brief Dadas dos transformaciones Tr1(v) y Tr2(v), definimos la transformación composición como: Tr(v)=Tr2( Tr1(v) )
 *
 *	Created on: Jun 04, 2012
 *		@author: Alejandro Alcalde
 */
#include <iostream>

#include "../include/transformacion.h"

void print_help(){
	std::cout << "Uso: componer <t|b> <archivo de transformacion> <transformacion1> <transformacion2>" 					<< std::endl;

	std::cout << "<t|b>:" 																								<< std::endl
			  << "\t b si la transformación compuesta se escribirá en el archivo de forma binaria, o t para texto." 	<< std::endl
			  << "<archivo de transformacion>"																			<< std::endl
			  << "\t Nombre del archivo de transformación a generar"													<< std::endl
			  << "<transformacion1> <transformacion2>:"																	<< std::endl
			  << "\t Las dos transformaciones a componer."							  									<< std::endl;
}

//-----------------------------------------------------------------------------------------------------------------------

int main(int argc, char *argv[]) {

	if (argc < 5){
		print_help();
		return -1;
	}else{
		Transformacion tr_primera;
		Transformacion tr_segunda;
		Transformacion tr_compuesta;

		if(tr_primera.read(argv[3]) && tr_segunda.read(argv[4])){
			char modo = *argv[1];

			tr_compuesta = tr_primera + tr_segunda;
			tr_compuesta.write(argv[2], modo);
		} else
			std::cout << "No se han podido leer los archivos de transformación. " << std::endl;
	}
	return 0;
}
