#pragma once

#include <cairo.h>
#include <cairo-pdf.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <math.h>
#include <sstream>



struct point{
    double x;
    double y;
};

class CairoPDF {

public:
    CairoPDF(char* name_,char* title_,double height_,double width_):fileName(name_),title(title_),
    height(height_),width(width_) {}



    void drawRectangle(double w,double h,double x,double y);
    void drawCircle(double radius,double cx,double cy);
    void drawPolygon(std::ifstream &fin,double cx,double cy);
    void drawText(char* text, double x,double y,double size);
    void drawCube(double a,double x,double y){ drawRectangle(a,a,x,y); }

private:
    char *fileName, *title;
    double height,width;
    cairo_surface_t *surface;
    cairo_t* cr;
    
    void createSurface();

    
};