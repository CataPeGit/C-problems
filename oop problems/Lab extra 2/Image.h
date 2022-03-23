#pragma once
#include <string>
#include <fstream>
#include "Size.h"

class Image : public Size{
public:
	Image();
	Image(unsigned int width, unsigned int height);

	Image(const Image& other);

	~Image();

	unsigned int width() const;
	unsigned int height() const;
	
	bool load(std::string imagePath);
	//bool save(std::string imagePath);

	Size size() const;

	Image& operator=(const Image& other);
/*
	Image operator+(const Image& i);
	Image operator-(const Image& i);
	Image operator*(const Image& i);

	bool getROI(Image& roiImg, Rectangle roiRect);
	bool getROI(Image& roiImg, unsigned int x, unsigned int y, unsigned int width, unsigned int height);

	bool isEmpty() const;



	unsigned char& at(unsigned int x, unsigned int y);
	unsigned char& at(Point pt);

	unsigned char* row(int y);

	void release();

	friend std::ostream& operator<<(std::ostream& os, const Image& dt);

	static Image zeros(unsigned int width, unsigned int height);
	static Image ones(unsigned int width, unsigned int height);

	*/

private:
	int** m_data;
	unsigned int m_width;
	unsigned int m_height;
};

