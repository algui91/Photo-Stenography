/*
 * @file Transformacion1.h
 *
 * @brief Clase Transformación usando memória dinámica
 *  Created on: Mar 15, 2012
 *      @author: Alejandro Alcalde
 */

#ifndef TRANSFORMACION1_H_
#define TRANSFORMACION1_H_

/**
 * Clase Transformación usando memoria dinámica
 */
class Transformacion{

private:
	static const int TAM = 256; //TODO quitar static
	int* tr;

public:
	Transformacion();
	Transformacion(const Transformacion&);
	~Transformacion() {delete[] tr;};

	/**
	 * Constructor de copia
	 */
	Transformacion& operator=(const Transformacion&);

	/**
	 *	Modificar posición del array
	 */
	inline void set(int pos, int val){tr[pos]=val;};

	/**
	 * Obtener valor de una determinada posición
	 */
	inline int get(int pos) const {return tr[pos];};

	/**
	 * Escribir al fichero
	 *
	 * @arg char modo, b ó t
	 */
	bool write(const char*, char);

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

#endif /* TRANSFORMACION1_H_ */
