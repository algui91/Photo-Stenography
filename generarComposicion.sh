#!/bin/bash

trans="brillo10_txt.trf desplazar2_txt.trf negativo_txt.trf carboncillo_txt.trf brillo10_bin.trf desplazar2_bin.trf negativo_bin.trf carboncillo_bin.trf"

for e in $trans
do
   for i in $trans
   do
      #file=`basename $img"_"$i`".png"
      echo "./bin/componer t $e$i $e $i"
      ./bin/componer t $e$i ./datos/$e ./datos/$i
      #./bin/componer b $e$i ./datos/$e ./datos/$i
   done
done
