/*
 * @file Transformacion2.h
 *
 * @brief Clase Transformación usando memória estática
 *  Created on: Mar 15, 2012
 *      @author: Alejandro Alcalde
 */

#ifndef TRANSFORMACION2_H_
#define TRANSFORMACION2_H_

/**
 * Clase Transformación usando memoria dinámica
 */
class Transformacion{

private:
	static const int TAM = 256;
	int tr[256];

public:

	Transformacion(const Transformacion&);
	Transformacion();
	/**
	 * Constructor copia
	 */
	Transformacion& operator=(const Transformacion&);

	/**
	 *	Modificar posición del array
	 */
	inline void set(int posicion, int valor){tr[posicion]=valor;};

	/**
	 * Obtener valor de una determinada posición
	 */
	int get(int posicion) const {return tr[posicion];};

	/**
	 * Escribir al fichero
	 */
	bool write(const char*,char);

	/**
	 * Leer del fichero
	 */
	bool read(const char*);

	/**
	 * Devuelve el tamaño del vector tr
	 */
	inline int get_tam() const {return TAM;};
};

/**
 * Fuera de la clase para evitar acceso directo a la parte privada
 */
Transformacion operator+(const Transformacion&, const Transformacion&);


#endif /* TRANSFORMACION2_H_ */
