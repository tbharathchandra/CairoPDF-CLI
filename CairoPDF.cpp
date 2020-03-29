#include "CairoPDF.h"
#include <iostream>
#include <math.h>


void CairoPDF::createSurface(){
    surface = cairo_pdf_surface_create(fileName,width,height);
    if(surface==nullptr){
        std::cout<<"Give a valid filename\n";
        exit(0);
    }
    cr = cairo_create(surface);
}

void CairoPDF::drawRectangle(double w,double h,double x,double y){
    createSurface();

    cairo_set_source_rgb(cr,0,0,0);
    cairo_rectangle(cr,x,y,w,h);
    cairo_stroke(cr);
    cairo_show_page(cr);

    cairo_surface_destroy(surface);
    cairo_destroy(cr);

}

void CairoPDF::drawText(char* text, double x,double y,double size){
    createSurface();

    cairo_set_source_rgb(cr,0,0,0);
    cairo_set_font_size(cr,size);
    cairo_move_to(cr, x, y);
    cairo_show_text(cr, text);

    cairo_surface_destroy(surface);
    cairo_destroy(cr);

}

void CairoPDF::drawCircle(double radius,double cx,double cy){
    createSurface();

    cairo_set_source_rgb(cr,0,0,0);
    cairo_arc(cr, cx,cy, radius , 0 , 2*M_PI);
    cairo_stroke_preserve(cr);
    cairo_show_page(cr);
    cairo_surface_destroy(surface);
    cairo_destroy(cr);
}

void CairoPDF::drawPolygon(std::vector<point> &poly,double x,double y){
    

}