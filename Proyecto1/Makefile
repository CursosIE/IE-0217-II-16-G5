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
clean:
	rm -rf doxygen
