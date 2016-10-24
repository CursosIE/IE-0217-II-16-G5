EmmaDu

1)	Recibe las dimensiones de las matrices que se van a multiplicar desde la terminal de la siguiente manera:
		./mS nA,mA nB,mB p
		
		nA= filas de la matriz A
		mA= columnas de la matriz A
		
		nB= filas de la matriz B
		mB= columnas de la matriz B
		
		donde p es una de las siguientes opciones:
		
		p=1: multiplicación convencional imprimiendo matrices y resultado
		p=2: multiplicación Strassen imprimiendo matrices y resultado
		p=3: comparar resultado de multiplicación convencional y Strassen. Solo se imprimen los resultados
		p=4: para multiplicaciones Strassen con dimensión mayor a 16. No imprime el resultado solo el tiempo que tomó

2)	Para compilar y ejecutar el código: make

3)	Para cambiar las dimensiones y la opción: modificar el Makefile

4)	Para generar la documentación con Doxygen: make doc

5) Para ver la documentación HTML generada :

	opción 1: Abrir el archivo ./doxygen/html/index.html
	opción 2: Abrir y correr el archivo Config_File_p1 con doxywizard
	
6) Para eliminar la documentación creada de doxygen (una vez vista): make clean

7) Para generar el reporte: make pdf
