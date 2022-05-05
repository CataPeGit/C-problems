#include "SMMIterator.h"
#include "SortedMultiMap.h"

#include <iostream>

SMMIterator::SMMIterator(const SortedMultiMap& d) : map(d){
	//TODO - Implementation

	// always start from head (position 0)
	current_element_position = 0;
}

void SMMIterator::first(){
	//TODO - Implementation
	
	// takes the current position back the start of the list (position 0 -> head)
	current_element_position = 0;
}

void SMMIterator::next(){
	//TODO - Implementation
	
	// increases the current position in order to get to the next element in the list

	//while (current_element_position < map.arraySize - 1 && map.sortedMultiMapArray[current_element_position] == map.sortedMultiMapArray[current_element_position + 1]) {
	//	current_element_position += 1;
	//}
	current_element_position += 1;
}

bool SMMIterator::valid() const{
	//TODO - Implementation
	
	// checks if the current position exists

	//for (int i = 0; i < map.arraySize; i++) {
		//std::cout << map.sortedMultiMapArray[i].first << " " << map.sortedMultiMapArray[i].second << std::endl;
	//}

	unsigned int map_size = map.arraySize;
	if (map_size > current_element_position && 0 <= current_element_position)
		return true;
	return false;
}

TElem SMMIterator::getCurrent() const{
	//TODO - Implementation
	// returns the element of type TElem at the current iterator position in the map 

	return TElem(map.sortedMultiMapArray[current_element_position]->first, map.sortedMultiMapArray[current_element_position]->second);
}


