/*
 * transformacion.h
 *
 *  Created on: May 31, 2012
 *      Author: hkr
 */

#ifndef TRANSFORMACION_H_
#define TRANSFORMACION_H_

#define CUAL_COMPILO 1

#if CUAL_COMPILO==1
  #include "Transformacion1.h"
#elif CUAL_COMPILO==2
  #include "Transformacion2.h"
#endif

#endif /* TRANSFORMACION_H_ */
