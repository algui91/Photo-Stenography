BIN     = bin
SRC 	  = src
INC 	  = ./include
OBJ 	  = obj
DIR_LIB = lib
LIB	  = libimagen.a
CXX 	  = g++
CPPFLAGS= -Wall -v -g -ansi -I$(INC) -c # Poner -O3 -ansi cuando deje de depuarar para optimizar
INC_LIB = -L./$(DIR_LIB) -limagen
IMAGENES= obj/imagen1.cpp obj/imagen2.cpp obj/imagen3.cpp obj/imagen4.cpp
TRANS   = obj/Transformacion1.cpp obj/Transformacion2.cpp
TRANSO  = $(TRANS:.cpp=.o)
IMAGENESO= $(IMAGENES:.cpp=.o)

all: $(BIN)/transformar $(BIN)/generar $(BIN)/componer $(BIN)/negativo $(BIN)/desplazar $(BIN)/ocultar $(BIN)/revelar

$(BIN)/negativo: $(OBJ)/negativo.o $(OBJ)/imagenES.o $(OBJ)/imagen.o $(OBJ)/procesar.o $(DIR_LIB)/$(LIB)
	@echo Creando la $@... con $^
	$(CXX) -Wall -g $^ $(INC_LIB) -o $@
$(BIN)/desplazar: $(OBJ)/desplazar.o $(OBJ)/imagenES.o $(OBJ)/imagen.o $(OBJ)/procesar.o $(DIR_LIB)/$(LIB)
	@echo Creando la $@... con $^
	$(CXX) -Wall -g  $^ $(INC_LIB) -o $@
$(BIN)/transformar: $(OBJ)/imagenES.o $(OBJ)/imagen.o $(OBJ)/transformacion.o $(OBJ)/transformar.o $(DIR_LIB)/$(LIB)
	@echo Creando la $@... con $^
	$(CXX) -Wall -g $^ $(INC_LIB) -o $@
$(BIN)/generar: $(OBJ)/transformaciones.o $(OBJ)/generar.o $(OBJ)/transformacion.o $(DIR_LIB)/$(LIB)
	@echo Creando la $@... con $^
	$(CXX) -Wall -g $^ $(INC_LIB) -o $@	
$(BIN)/componer: $(OBJ)/transformacion.o $(OBJ)/componer.o $(DIR_LIB)/$(LIB)
	@echo Creando la $@... con $^
	$(CXX) -Wall -g $^ $(INC_LIB) -o $@
$(BIN)/ocultar: $(OBJ)/ocultar.o $(OBJ)/imagenES.o $(OBJ)/procesar.o $(DIR_LIB)/$(LIB)
	$(CXX) -Wall -g  $^ -o $@
$(BIN)/revelar: $(OBJ)/revelar.o $(OBJ)/imagenES.o $(OBJ)/procesar.o $(DIR_LIB)/$(LIB)
	$(CXX) -Wall -g  $^ -o $@

$(OBJ)/imagenES.o : $(SRC)/imagenES.cpp $(INC)/imagenES.h
	@echo Creando la $@... con $^
	$(CXX) $(CPPFLAGS) $(SRC)/imagenES.cpp -o $(OBJ)/imagenES.o
$(OBJ)/negativo.o : $(SRC)/negativo.cpp
	@echo Creando la $@... con $^
	$(CXX) $(CPPFLAGS) $(SRC)/negativo.cpp -o $(OBJ)/negativo.o
$(OBJ)/desplazar.o : $(SRC)/desplazar.cpp
	@echo Creando la $@... con $^
	$(CXX) $(CPPFLAGS) $(SRC)/desplazar.cpp -o $(OBJ)/desplazar.o
$(OBJ)/transformaciones.o: $(SRC)/transformaciones.cpp $(INC)/transformaciones.h
	@echo Creando la $@... con $^
	$(CXX) $(CPPFLAGS) $(SRC)/transformaciones.cpp -o $(OBJ)/transformaciones.o
$(OBJ)/transformar.o: $(SRC)/transformar.cpp
	@echo Creando la $@... con $^
	$(CXX) $(CPPFLAGS) $(SRC)/transformar.cpp -o $(OBJ)/transformar.o
$(OBJ)/generar.o: $(SRC)/generar.cpp
	@echo Creando la $@... con $^
	$(CXX) $(CPPFLAGS) $(SRC)/generar.cpp -o $(OBJ)/generar.o
$(OBJ)/componer.o: $(SRC)/componer.cpp
	@echo Creando la $@... con $^
	$(CXX) $(CPPFLAGS) $(SRC)/componer.cpp -o $(OBJ)/componer.o
$(OBJ)/procesar.o: $(SRC)/procesar.cpp
	@echo Creando la $@... con $^
	$(CXX) $(CPPFLAGS) $(SRC)/procesar.cpp -o $(OBJ)/procesar.o
$(OBJ)/revelar.o : $(SRC)/revelar.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/revelar.cpp -o $(OBJ)/revelar.o
$(OBJ)/ocultar.o : $(SRC)/ocultar.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/ocultar.cpp -o $(OBJ)/ocultar.o

$(OBJ)/imagen.o : $(IMAGENESO) $(INC)/imagen*.h
	@echo Creando la $@... con $^
	$(CXX) $(CPPFLAGS) $(SRC)/imagen.cpp -o $(OBJ)/imagen.o

#Creacion objetos imágenes	
$(OBJ)/imagen1.o : $(SRC)/imagen1.cpp $(INC)/imagen1.h
	@echo Creando la $@... con $^
	$(CXX) $(CPPFLAGS) $(SRC)/imagen1.cpp -o $(OBJ)/imagen1.o
$(OBJ)/imagen2.o : $(SRC)/imagen2.cpp $(INC)/imagen2.h
	@echo Creando la $@... con $^
	$(CXX) $(CPPFLAGS) $(SRC)/imagen2.cpp -o $(OBJ)/imagen2.o
$(OBJ)/imagen3.o : $(SRC)/imagen3.cpp $(INC)/imagen3.h
	@echo Creando la $@... con $^
	$(CXX) $(CPPFLAGS) $(SRC)/imagen3.cpp -o $(OBJ)/imagen3.o
$(OBJ)/imagen4.o : $(SRC)/imagen4.cpp $(INC)/imagen4.h
	@echo Creando la $@... con $^
	$(CXX) $(CPPFLAGS) $(SRC)/imagen4.cpp -o $(OBJ)/imagen4.o

$(OBJ)/transformacion.o: obj/Transformacion1.o obj/Transformacion2.o $(INC)/Transformacion*.h $(INC)/transformacion.h
	@echo Creando la $@... con $^
	$(CXX) $(CPPFLAGS) $(SRC)/transformacion.cpp -o $(OBJ)/transformacion.o
	
$(OBJ)/Transformacion1.o : $(SRC)/Transformacion1.cpp $(INC)/Transformacion1.h
	@echo Creando la $@... con $^
	$(CXX) $(CPPFLAGS) $(SRC)/Transformacion1.cpp -o $(OBJ)/Transformacion1.o
$(OBJ)/Transformacion2.o : $(SRC)/Transformacion2.cpp $(INC)/Transformacion2.h
	@echo Creando la $@... con $^
	$(CXX) $(CPPFLAGS) $(SRC)/Transformacion2.cpp -o $(OBJ)/Transformacion2.o


$(DIR_LIB)/$(LIB): $(OBJ)/imagenES.o $(OBJ)/transformaciones.o $(OBJ)/imagen.o $(OBJ)/transformacion.o $(OBJ)/transformaciones.o $(OBJ)/procesar.o
	@echo Creando la librería $@... con $^
	ar rvs $@ $^

documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Limpieza ************
.PHONY: clean
clean :
	@echo Limpiando archivos intermedios...
	rm $(DIR_LIB)/* $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
