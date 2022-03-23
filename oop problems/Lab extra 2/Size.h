#pragma once

class Size {
public:

	Size();
	Size(unsigned int size);

	unsigned int size() const;
protected:
	unsigned int m_size;
};