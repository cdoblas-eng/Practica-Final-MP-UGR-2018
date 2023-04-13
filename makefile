all: bin/pruebaNube bin/simulacion clean

bin/simulacion: obj/simulacion.o obj/miniwin.o obj/Particula.o obj/Nubeparticulas.o obj/Simulador.o obj/menu.o
	g++ -g -o bin/simulacion obj/simulacion.o obj/miniwin.o obj/Particula.o obj/Nubeparticulas.o obj/Simulador.o obj/menu.o -I./include   -pthread -lX11

bin/pruebaNube: obj/pruebaNube.o obj/miniwin.o obj/Particula.o obj/Nubeparticulas.o obj/Simulador.o
	g++ -g -o bin/pruebaNube obj/pruebaNube.o obj/miniwin.o obj/Particula.o obj/Nubeparticulas.o obj/Simulador.o -I./include   -pthread -lX11

obj/simulacion.o: src/simulacion.cpp
	g++ -g -c -o  obj/simulacion.o src/simulacion.cpp -I./include

obj/pruebaNube.o: src/pruebaNube.cpp
	g++ -g -c -o  obj/pruebaNube.o src/pruebaNube.cpp   -I./include

obj/miniwin.o: src/miniwin.cpp
	g++ -g -c -o  obj/miniwin.o src/miniwin.cpp -I./include

obj/Particula.o: src/Particula.cpp
	g++ -g -c -o obj/Particula.o src/Particula.cpp  -I./include

obj/Nubeparticulas.o: src/Nubeparticulas.cpp
	g++ -g -c -o obj/Nubeparticulas.o src/Nubeparticulas.cpp -I./include

obj/Simulador.o : src/Simulador.cpp
	g++ -g -c -o obj/Simulador.o src/Simulador.cpp -I./include

obj/menu.o: src/menu.cpp
	g++ -c -o obj/menu.o src/menu.cpp  -I./include

clean:
	echo Borrando los archivos obj
	rm obj/*.o
