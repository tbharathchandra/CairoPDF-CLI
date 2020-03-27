#include <iostream>
#include <string.h>

#include "CairoPDF.h"

int main(int argc, char **argv) 
{
    // name width height title_with_no_spaces rectangle x y w h
    // name width height title_with_no_spaces cude x y a
    // name width height title_with_no_spaces circle x y r

    char* shape = argv[4];
    char* fileName = argv[0];
    double width = atof(argv[1]);
    double height = atof(argv[2]);
    char* title = argv[3];

    CairoPDF cpdf(fileName,title,height,width);

    if(strcmp(shape,"rectangle")){
        double x = atof(argv[5]);
        double y = atof(argv[6]);
        double w = atof(argv[7]);
        double h = atof(argv[8]);
        //std::cout<<"before calling drawrectangle\n";
        cpdf.drawRectangle(w,h,x,y);
        //std::cout<<"after calling drawrectangle\n";


    }else if(strcmp(shape,"cude")){
        double x = atof(argv[5]);
        double y = atof(argv[6]);
        double a = atof(argv[7]);

    }else if(strcmp(shape,"circle")){
        double x = atof(argv[5]);
        double y = atof(argv[6]);
        double r = atof(argv[7]);
    }else if(strcmp(shape,"polygon")){

    }

    return 0;

}