#pragma once

#include <cairo.h>
#include <cairo-pdf.h>
#include <vector>


struct point{
    double x;
    double y;
};

class CairoPDF {

public:
    CairoPDF(char* name_,char* title_,double height_,double width_):fileName(name_),title(title_),
    height(height_),width(width_) {}


    void createSurface();

    void drawRectangle(double w,double h,double x,double y);
    void drawCircle(double radius,double cx,double cy);
    void drawPolygon(std::vector<point> &poly,double x,double y);
    void drawText(char* text, double x,double y,double size);

private:
    char *fileName, *title;
    double height,width;
    cairo_surface_t *surface;
    cairo_t* cr;

    
};