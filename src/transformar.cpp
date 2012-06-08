/**
  * @file transformar.cpp
  * @brief Leer una imagen y una transformación para obtener una nueva
  * imagen transformada
  *
  *	Created on: Mar 15, 2012
  *		@author: Alejandro Alcalde
  */

#include <iostream>

#include "../include/imagenES.h"
#include "../include/imagen.h"
#include "../include/transformacion.h"

using namespace std;

void print_help(){
	cout << "Uso: transformar <imagen_Entrada> <transformacion> <imagen_salida>" << endl;
}

int main(int argc, char *argv[]) {

	if (argc < 4){
		print_help();
		return -1;
	} else {
		Imagen img;
		img.crear(0,0);
		if (!img.leer_imagen(argv[1])){
			cerr << "No se pudo leer la imagen. " << endl;
			return -2;
		}

		Transformacion tr;

		if(tr.read(argv[2])){
			for (int i = 0; i < img.get_filas(); i++)
				for (int k = 0; k < img.get_columnas(); k++)
					img.set_buffer(i, k, tr.get(img.get_buffer(i, k)));

			if(img.escribir_imagen(reinterpret_cast<const char*>(argv[3])))
				cout << argv[2] << " aplicado a la imagen " << argv[1] << endl;
			else
				cout << "Ha debido ocurrir algún error al guardar la imagen" << endl;
		}else
			cerr << "Error al abrir el archivo de transformacion " << argv[2] << endl;
	}
	return 0;
}
