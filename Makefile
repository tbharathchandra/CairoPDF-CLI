PROG = pdfcli

INCLUDEDIRS = \
	-I/usr/include/cairo

LIBDIRS = \
	-L/usr/lib/x86_64-linux-gnu

LIBS = \
	-lcairo \
	-lstdc++

CXXSOURCES = \
	CairoPDF.cpp \
	pdfcli.cpp

CXXOBJECTS = $(CXXSOURCES:.cpp=.o)

CXX = gcc

$(PROG) : $(CXXOBJECTS)
	$(CXX) $^ $(INCLUDEDIRS) -o $@ $(LIBS)

%.o : %.cpp
	$(CXX) $(INCLUDEDIRS) $< -c $(LIBS)

clean : 
	rm $(CXXOBJECTS) $(PROG)

# Dependency chain
CairoPDF.o : CairoPDF.cpp CairoPDF.h
pdfcli.o : pdfcli.cpp
