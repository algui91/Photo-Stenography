/*
 * Transformacion1.cpp
 *
 *  Created on: May 31, 2012
 *      Author: hkr
 */
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

#include "../include/Transformacion1.h"

Transformacion::Transformacion(){
	tr = new int [TAM];

	for(int i=0;i<TAM;i++)
		tr[i]=0;
}
//--------------------------------------------------------------------------------------------------------------------------------------------

Transformacion::Transformacion(const Transformacion &transformacion){
	tr = new int [TAM];

	for(int i=0;i<TAM;i++)
		tr[i] = transformacion.tr[i];
}

//----------------------------------------------------------------------------------------------------------------------------------------

Transformacion& Transformacion::operator=(const Transformacion& transformacion){
	if(&transformacion != this){
		delete[] this->tr;
		this->tr = new int [TAM];
		for(int i = 0; i< TAM; i++)
			this->tr[i] = transformacion.tr[i];
	}
	return *this;
}
//--------------------------------------------------------------------------------------------------------------------------------------
bool Transformacion::write(const char* file, char modo){

	ofstream f;
	//TODO: Optimizar, demasiado código
	switch(modo){
		case 't':
			if (f){
				f.open(file,ios::out);
				f<<"MP-TRF-T 256"<<endl;
				for (int i = 0; i < TAM; i++)
					f<<tr[i]<<endl;
			}else{
				cerr<<"Imposible crear el archive " << file <<endl;
				return false;
			}
			break;
		case 'b':
			f.open(file,ios::out|ios::binary);
			if (f){
				f<<"MP-TRF-B 256"<<endl;
				f.write(reinterpret_cast<char*>(tr),sizeof(int)*TAM); //binario
			}else{
				cerr<<"Imposible crear el archive " << file <<endl;
				return false;
			}
			break;
		default:
			write(file, 'b');
			break;
	}
	return true;
}
//-------------------------------------------------------------------------------------------------------------------------------------
bool Transformacion::read(const char* file){

	int consume_numero;
	char consume_cadena[9];
	int valor;
	ifstream f(file, ios::in|ios::binary);

	if (!f)
		return false;
	else{
		f >> consume_cadena;
		f >> consume_numero;
		f.get(); //Consume el \n

		switch (consume_cadena[7]){
		case 'B':
			f.read(reinterpret_cast<char*>(tr), sizeof(int)*TAM);
			break;
		case 'T':
			for(int i = 0; f; i++){
				f >> valor;
				f.get();
				this->set(i, valor);
			}
			break;
		}
		f.close();

		return true;
	}
}

//--------------------------------------------------------------------------------------------------------------------------------------

Transformacion operator+(const Transformacion& tr1,const Transformacion& tr2){
	Transformacion resultado;

	for(int i = 0; i < resultado.get_tam(); i++)
		resultado.set(i, tr2.get(tr1.get(i)));
	return resultado;
}
//---------------------------------------------------------------------------------------------------------------------------------------


