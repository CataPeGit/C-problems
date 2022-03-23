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
    int num = 0;
    if (imageFile.is_open()) {
        string line;
        getline(imageFile, line); // reading magic number (such as P5 or P2)
        getline(imageFile, line); // rea
        cout << line << endl;
        cout << "lapte";


        imageFile.close();
        return 1;
    }

    imageFile.close();
    return 0;
}



Image::Image() {
    this->m_data = new int*[256]();
	this->m_width = 0;
	this->m_height = 0;
}

Image::Image(unsigned int width, unsigned int height) {

	this->m_width = width;
	this->m_height = height;
    this->m_data = new int* [width]();

}

Image::Image(const Image& other) {
    this->m_width = other.m_width;
    this->m_height = other.m_height;
	m_data = new int*[256];
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
    for (int i = 0; i < m_height; i++) {
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
