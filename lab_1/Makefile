comp:
	cd ./code; g++ -o lab1 lab1.cpp
run:
	cd ./code; ./lab1 UAACCUUCUACUACGUAG
	cd ./code; ./lab1 UGAACUACGCCUUCUUAG
	cd ./code; ./lab1 UAGUCUCCUACGACUUAA
clean:
	cd ./code; rm lab1
	
code: comp run clean

doc:
	doxygen Config_File_1
	cd ./doxygen/latex/; make
	cd ./doxygen/latex/; xdg-open refman.pdf
pdf:
	cd ./reporte/; pdflatex reporte_1.tex
	cd ./reporte/; xdg-open reporte_1.pdf

