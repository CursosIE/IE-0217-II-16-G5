code:	comp run eex
comp:
	cd ./code; g++ -o main *.cpp
run:
	cd ./code; ./main EETDTEDETD	
eex:
	cd ./code; rm main
doc:
	doxygen Config_File_5
	cd ./doxygen/latex/; make
	cd ./doxygen/latex/; xdg-open refman.pdf
	clear
pdf:
	cd ./reporte/; pdflatex reporte_5.tex
	cd ./reporte/; pdflatex reporte_5.tex
	cd ./reporte/; rm *.aux *.log *.out *.toc
	cd ./reporte/; xdg-open reporte_5.pdf
	clear
clean:
	rm -rf doxygen
