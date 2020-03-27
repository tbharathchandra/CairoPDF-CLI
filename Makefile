output : CairoPDF.o pdfcli.o
	gcc pdfcli.o CairoPDF.o -I/usr/include/cairo -o pdfcli.out -lcairo -lstdc++
	gcc pdfcli.o CairoPDF.o -I/usr/include/cairo -o pdfcli -lcairo -lstdc++


CairoPDF.o : CairoPDF.cpp CairoPDF.h
	gcc -I/usr/include/cairo  CairoPDF.cpp -c -lcairo

pdfcli.o : pdfcli.cpp
	gcc -Wall -I/usr/include/cairo  pdfcli.cpp -c -lcairo

clean : 
	rm *.out *.o pdfcli

	