#! /usr/bin/python
# -*- coding: utf-8 -*-

import sys

##
 # @file
 # @author  Dunia Barahona <s4sibarahona@gmail.com>
 # @version 1.0
 # @section DESCRIPCIÓN
 #
 # Este es un programa escrito en Python que toma de la línea de comandos una lista de 
 # números reales e imprime en pantalla el resultado de la suma de dichos números.

## @return el resultado de la suma de los números ingresados.
def suma_n():
## Variable de tipo entero.
	bolsita = 0
	for x in range(1, len(sys.argv)):
		bolsita += int(sys.argv[x])
	print bolsita


suma_n()
