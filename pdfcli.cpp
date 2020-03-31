#include <iostream>
#include <string.h>
#include <fstream>
#include <unistd.h>

#include "CairoPDF.h"

void help(){
    std::cout<<"\nUsage of PDF-CLI\n\n"
             <<"$(path)/fileName.pdf width height title rectangle x y w h\n"
             <<"$(path)/fileName.pdf width height title cude x y a\n"
             <<"$(path)/fileName.pdf width height title circle x y r\n"
             <<"$(path)/fileName.pdf width height title polygon x y $(anyPath)/points\n"
             <<"$(path)/fileName.pdf width height title polygon x y text size\n\n";
}

int main(int argc, char **argv) 
{
    // $(path)/fileName.pdf width height title rectangle x y w h
    // $(path)/fileName.pdf width height title cude x y a
    // $(path)/fileName.pdf width height title circle x y r
    // $(path)/fileName.pdf width height title polygon x y $(anyPath)/points

    if(chdir(getenv("HOME"))!=0){
        std::cout<<"Problem with changing to home directory\n";
        exit(0);
    }

    if(argc==2){
        if(strcmp("-h",argv[1])==0){
            help();
            exit(0);
        }
    }
    
    if(argc<9){
        std::cout<<"Enter valid commands. For help use -h as first argument \n";
        help();
        exit(0);
    }


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
        if(!fin){
            std::cout<<"\n Unable to open: "<<fileName<<"\n";
            exit(0);
        }
        cpdf.drawPolygon(fin,x,y);
        fin.close();
    }else if(strcmp(shape,"text")==0){
        double x = atof(argv[6]);
        double y = atof(argv[7]);
        char* text = argv[8];
        double size = atof(argv[9]);
        cpdf.drawText(text,x,y,size);
    }

    return 0;

}