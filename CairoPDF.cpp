#include "CairoPDF.h"


void CairoPDF::createSurface(){
    surface = cairo_pdf_surface_create(fileName,width,height);
    cr = cairo_create(surface);
}

void CairoPDF::drawRectangle(double w,double h,double x,double y){
    createSurface();
    cairo_rectangle(cr,x,y,w,h);
    cairo_stroke(cr);
    cairo_show_page(cr);
    cairo_destroy(cr);
    cairo_surface_destroy(surface);

}