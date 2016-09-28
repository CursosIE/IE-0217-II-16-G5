comp:
	cd ./code; g++ -o main *.cpp
run:
	cd ./code; ./main
eex:
	cd ./code; rm main
code:	comp run eex
doc:
	doxygen Config_File_3
	cd ./doxygen/latex/; make
	cd ./doxygen/latex/; xdg-open refman.pdf
pdf:
	cd ./reporte/; pdflatex reporte_3.tex
	cd ./reporte/; pdflatex reporte_3.tex
	cd ./reporte/; rm *.aux *.log *.out *.toc
	cd ./reporte/; xdg-open reporte_3.pdf
clean:
	cd ./doxygen/; rm -rf latex html
	cd ./doxygen/; rm -f *.db
