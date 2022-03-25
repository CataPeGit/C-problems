#include "Image.h"
#include <iostream>
#include <iomanip>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>


using namespace std;

bool Image::load(std::string imagePath) {
    fstream imageFile;
    imageFile.open(imagePath);
    imageFile.get();
    //stringstream ss;
    int max_grey_value = 0;
    if (imageFile.is_open()) {
        string line;
        getline(imageFile, line); // reading magic number (such as P5 or P2)
        
        cout << "Magic number: " << line << endl;
        getline(imageFile, line); // reading comment
        cout << "Comment: " << line << endl;
        
        

        imageFile >> this->m_width;
        imageFile >> this->m_height;
        imageFile >> max_grey_value; // maximum gray value -> 255 in our case
        cout << max_grey_value;

        for (int i = 0; i < m_width; i++) {
            for (int j = 0; j < m_height; j++) {
                imageFile >> m_data[i][j];
                cout << m_data[i][j] << " ";
            }
            cout << endl;
        }


        imageFile.close();
        return 1;
    }

    imageFile.close();
    return 0;
}



Image::Image() {
    this->m_data = new unsigned int*[256]();
	this->m_width = 0;
	this->m_height = 0;
}

Image::Image(unsigned int width, unsigned int height) {

	this->m_width = width;
	this->m_height = height;
    this->m_data = new unsigned int* [width]();
    for (unsigned int i = 0; i < m_height; i++) {
        m_data[i] = new unsigned int[m_height]();
    }

}

Image::Image(const Image& other) {
    this->m_width = other.m_width;
    this->m_height = other.m_height;
	m_data = new unsigned int*[256];
	memcpy(m_data, other.m_data, 256);
}

Image& Image::operator=(const Image& other) {

	if (this != &other) {
		delete[] m_data;

		this->m_width = m_width;
		this->m_height = m_height;
	}
	return *this;

}

Image::~Image() {

	//delete[] m_data;
    for (unsigned int i = 0; i < m_height; i++) {
        delete m_data[i];
    }
    delete[] m_data;
    m_data = NULL;
}

unsigned int Image::width() const {
    return this->m_width;
}
unsigned int Image::height() const {
    return this->m_height;
}

Size Image::size() const {
    return Size(this->m_width * this->m_height);
}



/*
// Function to ignore any comments in file
void ignoreComments(FILE* fp)
{
    int ch;
    char line[100];

    // Ignore any blank lines
    while ((ch = fgetc(fp)) != EOF
        && isspace(ch))
        ;

    // Recursively ignore comments
    // in a PGM image commented lines
    // start with a '#'
    if (ch == '#') {
        fgets(line, sizeof(line), fp);
        ignoreComments(fp);
    }
    else
        fseek(fp, -1, SEEK_CUR);
}
*/
