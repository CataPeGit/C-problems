#include "Point.h"
#include <iostream>
#include <iomanip>


Point::Point() {
	m_x = 0;
	m_y = 0;
}
Point::Point(unsigned int x, unsigned y) {
	m_x = x;
	m_y = y;
}

unsigned int Point::get_x() const {
	return m_x;
}

unsigned int Point::get_y() const {
	return m_y;
}