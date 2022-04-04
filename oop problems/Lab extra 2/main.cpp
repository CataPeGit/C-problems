// Extra Credit 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "Image.h"
#include "ImageProcessing.cpp"
#include "Size.h"
#include "Point.h"
#include "Rectangle.h"
#include "Brightness_and_contrast.h"
#include "Gamma_correction.h"
#include "Convolution.h"
#include "draw.h"

using namespace std;

namespace draw {
    void drawCircle(Image& img, Point center, int radius, unsigned int color) {
        for (unsigned int i = center.get_y() - radius; i <= center.get_y() + radius; i++) {
            for (unsigned int j = center.get_x() - radius; j <= center.get_x() + radius; j++) {
                img.set_point(color, i, j);
            }
        }
    }

    void drawLine(Image& img, Point p1, Point p2, unsigned int color) {
        for (unsigned int i = p1.get_y(); i <= p1.get_y(); i++) {
            for (unsigned int j = p1.get_x(); j <= p2.get_x(); j++) {
                img.set_point(color, i, j);
            }
        }
    }

    void drawRectangle(Image& img, Point topleft, Point bottomright, unsigned char color) {
        for (unsigned int i = topleft.get_y(); i <= bottomright.get_y(); i++) {
            for (unsigned int j = topleft.get_x(); j <= bottomright.get_x(); j++) {
                img.set_point(color, i, j);
            }
        }
    }
} 




int main()
{
    
    Image a = Image(512, 512);
    Image c = Image(512, 512);
    Image b = Image(512, 512);
    Image d = b.ones(512, 512);

    string path = "pgmFile.pgm"; // MAKE SURE THE PATH IS CORRECT

    a.load(path);
    c.load("pgmFile.pgm"); // MAKE SURE THE PATH IS CORRECT

    unsigned int nr1 = 57;
    Point p1(nr1, nr1);
    Point p2(64, 64);
    //draw::drawCircle(d, p1, 34, 155);
    //draw::drawLine(d, p1, p2, 155);
    draw::drawRectangle(d, p1, p2, 155);

    ImageProcessing* process_img = new Convolution(256);
    cout << "Starting process...";
    cout << endl;
 
    process_img->process(a, b);
    
    d.save("pgmFile.pgm");
    //cout << a;
    cout << "Done!";
    a.~Image();
    b.~Image();
    c.~Image();
    d.~Image();
    return 0;
}
