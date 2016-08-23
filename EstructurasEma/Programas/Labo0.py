#! /usr/bin/python
import sys
##Este es un metodo que suma argumentos ingresados desde consola
def suma():
    i = sys.argv
    result = 0
    for x in range(1, len(sys.argv)):
        result+=float(i[x])
    print result
suma()
