code:	comp run eex
comp:
	cd ./code/; g++ -o hex *.cpp
run:                                           
	cd ./code/; ./hex
eex:
	cd ./code/; rm hex
doc:
	doxygen Config_File_p2
	cd ./doxygen/latex/; make
	cd ./doxygen/latex/; xdg-open refman.pdf
	clear
clean:
	rm -rf doxygen
pdf:
	cd ./reporte/; pdflatex project_2.tex
	cd ./reporte/; pdflatex project_2.tex
	cd ./reporte/; rm *.aux *.log *.out *.toc *.lof
	cd ./reporte/; xdg-open project_2.pdf
	clear
