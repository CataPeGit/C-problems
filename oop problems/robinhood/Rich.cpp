#include "Rich.h"

Rich::Rich() {
	m_treasure = 0;
}
Rich::Rich(unsigned int treasure) {
	m_treasure = treasure;
}

unsigned int Rich::get_treasure() const {
	return m_treasure;
}