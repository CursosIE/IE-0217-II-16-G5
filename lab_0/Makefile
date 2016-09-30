comp:
	cd ./code; gcc -o sumc suma.c 
	cd ./code; g++ -o sumcpp suma.cpp
run:
	cd ./code; ./sumc 22 3 5
	cd ./code; ./sumcpp 5 5 15
	cd ./code; ./suma.py 7 7 2 2
clean:
	cd ./code; rm sumc
	cd ./code; rm sumcpp
	
code: comp run clean

doc:
	doxygen Config_File_0
	cd ./doxygen/latex/; make
	cd ./doxygen/latex/; xdg-open refman.pdf
pdf:
	cd ./reporte/; pdflatex reporte_0.tex
	cd ./reporte/; xdg-open reporte_0.pdf

	
