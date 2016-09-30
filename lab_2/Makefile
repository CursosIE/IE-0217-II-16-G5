comp:
	cd ./code; g++ -o main *.cpp
run:
	cd ./code; ./main
eex:
	cd ./code; rm main

code:	comp run eex
doc:
	doxygen Config_File_2
	cd ./doxygen/latex/; make
	cd ./doxygen/latex/; xdg-open refman.pdf
pdf:
	cd ./reporte/; pdflatex reporte_2.tex
	cd ./reporte/; pdflatex reporte_2.tex
	cd ./reporte/; rm *.aux *.log *.out *.toc
	cd ./reporte/; xdg-open reporte_2.pdf
clean:
	rm -rf doxygen

