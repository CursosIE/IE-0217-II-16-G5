comp:
	cd ./code; g++ -o main *.cpp
run:
	cd ./code; ./main
clean:
	cd ./code; rm main
code:	comp run clean
doc:
	doxygen Config_File_2
	cd ./doxygen/latex/; make
	cd ./doxygen/latex/; xdg-open refman.pdf
pdf:
	cd ./reporte/; pdflatex reporte_2.tex
	cd ./reporte/; xdg-open reporte_2.pdf
