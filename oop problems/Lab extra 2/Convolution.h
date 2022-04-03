#pragma once
#include "ImageProcessing.cpp"

class Convolution : public ImageProcessing {
public:


    Convolution() {
        m_range = 256;
    };

    Convolution(unsigned int range) {
        m_range = range;
    };

    void Convolution::process(const Image& src, Image& dst) {


 
        unsigned int current_kernel_value = 0;
        unsigned int margin = 0;

        for (unsigned int i = 0; i < src.height(); i++) {
            for (unsigned int j = 0; j < src.width(); j++) {

                if ((i == 0 || j == 0 || src.width() == j || src.height() == i))
                    margin = 1;


                unsigned int new_pixel = 0;
                unsigned int origin = src.at_const(i, j);
                for (int y = -1; y <= 1; y++) {
                    for (int x = -1; x <= 1; x++) {

                        if (margin == 1 && (x == -1 || y == -1)) {
                            current_kernel_value = src.at_const(i, j);
                            new_pixel = new_pixel + (origin * current_kernel_value);
                        }
                        else {
                            current_kernel_value = src.at_const(i + y, j + x);
                            new_pixel = new_pixel + (origin * current_kernel_value);
                        }
                    }
                }
                   
                new_pixel = new_pixel % m_range;
                std::cout << new_pixel << "  ";
                dst.at(i, j) = new_pixel;

                
                //std::cout << dst.at(i, j) << "  ";
            }
        }
    std::cout << dst;
    };


private:
    unsigned int m_range;
};

