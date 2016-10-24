code:	comp run eex
comp:
	cd ./code/; g++ -o mS *.cpp
run:                                           
	cd ./code/; ./mS 3,4 4,2 3
eex:
	cd ./code/; rm mS
doc:
	doxygen Config_File_p1
	cd ./doxygen/latex/; make
	cd ./doxygen/latex/; xdg-open refman.pdf
	clear
clean:
	rm -rf doxygen
pdf:
	cd ./reporte/; pdflatex project_1.tex
	cd ./reporte/; pdflatex project_1.tex
	cd ./reporte/; rm *.aux *.log *.out *.toc *.lof
	cd ./reporte/; xdg-open project_1.pdf
	clear
