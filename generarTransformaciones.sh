#!/bin/bash

./bin/generar b ./datos/negativo_bin.trf negativo
./bin/generar t ./datos/negativo_txt.trf negativo
./bin/generar b ./datos/desplazar2_bin.trf desplazar 4
./bin/generar t ./datos/desplazar2_txt.trf desplazar 4
./bin/generar b ./datos/mitad_bin.trf umbralilzar 127
./bin/generar t ./datos/mitad_txt.trf umbralilzar 127
./bin/generar b ./datos/brillo10_bin.trf brillo 10
./bin/generar t ./datos/brillo10_txt.trf brillo 10
