#include <iostream>
#include <string.h>
#include <fstream>
#include <unistd.h>

#include "CairoPDF.h"

int main(int argc, char **argv) 
{
    // name width height title_with_no_spaces rectangle x y w h
    // name width height title_with_no_spaces cude x y a
    // name width height title_with_no_spaces circle x y r

    chdir(getenv("HOME"));

    char* shape = argv[5];
    char* fileName = argv[1];
    double width = atof(argv[2]);
    double height = atof(argv[3]);
    char* title = argv[3];
    

    CairoPDF cpdf(fileName,title,height,width);

    if(strcmp(shape,"rectangle")==0){
        double x = atof(argv[6]);
        double y = atof(argv[7]);
        double w = atof(argv[8]);
        double h = atof(argv[9]);
        cpdf.drawRectangle(w,h,x,y);

    }else if(strcmp(shape,"cude")==0){
        double x = atof(argv[6]);
        double y = atof(argv[7]);
        double a = atof(argv[8]);
        cpdf.drawCube(a,x,y);

    }else if(strcmp(shape,"circle")==0){
        double x = atof(argv[6]);
        double y = atof(argv[7]);
        double r = atof(argv[8]);
        cpdf.drawCircle(r,x,y);

    }else if(strcmp(shape,"polygon")==0){
        double x = atof(argv[6]);
        double y = atof(argv[7]);
        char* points = argv[8];
        std::ifstream fin(points);
        cpdf.drawPolygon(fin,x,y);
        fin.close();
    }

    return 0;

}