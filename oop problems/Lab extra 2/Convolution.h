#pragma once
#include "ImageProcessing.cpp"

class Convolution : public ImageProcessing {
public:
    

    Convolution() {
        m_range = 256;
    }

    Convolution(unsigned int range) {
        m_range = range;
    }

    void Convolution::process(const Image& src, Image& dst)  {

        for (unsigned int i = 1; i < src.height() - 1; i++) {
            for (unsigned int j = 1; j < src.width() - 1; j++) {
                if (i == 0 || j == 0 || j == src.height() || j == src.width() || i == src.height() || i == src.width()) {
                    dst.at(i, j) = src.at_const(i, j);
                    if (i == 511) {
                       std::cout << i << " ";
                    }
                    continue;
                }
                else {
                    unsigned int new_pixel = 0;
                    unsigned int current_pixel_source = src.at_const(i, j);

                    for (int y = -1; y <= 1; y++) {
                        for (int x = -1; x <= 1; x++) {
                            unsigned int current_kernel_value = src.at_const(i + y, j + x);
                            new_pixel += (current_pixel_source * current_kernel_value);     
                        }
                    }
                    new_pixel = new_pixel % m_range;
                    dst.at(i, j) = new_pixel;
                }

            }
        }
    }


private:
    unsigned int m_range;
};

