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
	bool save(std::string imagePath);

	Size size() const;


	friend std::ostream& operator<<(std::ostream& os, const Image& dt);


private:
	unsigned int** m_data;
	unsigned int m_width;
	unsigned int m_height;
};

