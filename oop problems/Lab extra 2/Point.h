#pragma once

class Point {
public:
	Point();
	Point(unsigned int x, unsigned y);
	unsigned int get_x() const;
	unsigned int get_y() const;
protected:
	unsigned int m_x;
	unsigned int m_y;
};