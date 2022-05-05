#include "SMMIterator.h"
#include "SortedMultiMap.h"
#include <iostream>
#include <vector>
#include <exception>
using namespace std;



SortedMultiMap::SortedMultiMap(Relation r) {
	//TODO - Implementation
	//contructor
	arraySize = 0;
	sortedMultiMapArray = nullptr;
	array_relation = r;
}

/*
			for (int i = 0; i < arraySize; i++) {
				std::cout << sortedMultiMapArray[i]->first << " " << sortedMultiMapArray[i]->second << endl;

			}
			std::cout << "size: " << arraySize << std::endl;
			std::cout << std::endl << "end" << std::endl << std::endl;
*/

void SortedMultiMap::add(TKey c, TValue v) {
	//TODO - Implementation
	
	/*
	Allocate a new[] array and store it in a temporary pointer.
    Copy over the previous values that you want to keep.
    Delete[] the old array.
    Change the member variables, ptr and size to point to the new array and hold the new size.
	*/
	arraySize += 1;

	if (arraySize == 1) {
		sortedMultiMapArray = new TElem* [arraySize]();

		TElem new_element = TElem(c, v);
		sortedMultiMapArray[0] = new TElem(new_element);
		return;
	}

	TElem** new_array = new TElem*[arraySize]();

	for (unsigned int i = 0; i < arraySize - 1; i++) {
		TElem aux = TElem(sortedMultiMapArray[i]->first, sortedMultiMapArray[i]->second);
		new_array[i] = new TElem(aux);
		//new_array[i] = sortedMultiMapArray[i];
	}
	TElem new_element = TElem(c, v);
	new_array[arraySize - 1] = new TElem(new_element);

	for (unsigned int i = 0; i < arraySize-1; i++) {
		delete sortedMultiMapArray[i];
	}
	delete[] sortedMultiMapArray;

	sortedMultiMapArray = new_array;
	new_array = NULL;

}

vector<TValue> SortedMultiMap::search(TKey c) const {
	//TODO - Implementation
	
	// going trough the list
	// adding all values linked to the given key into a vector

	vector<TValue> all_values_at_key_c;
	
	for (unsigned int i = 0; i < arraySize; i++) {
		if (sortedMultiMapArray[i]->first == c) {
			all_values_at_key_c.push_back(sortedMultiMapArray[i]->second);
		}
	}

	//for (int i = 0; i < arraySize; i++) {
	//	std::cout << sortedMultiMapArray[i]->first << " " << sortedMultiMapArray[i]->second << endl;
	//}

	return all_values_at_key_c;
}

bool SortedMultiMap::remove(TKey c, TValue v) {
	//TODO - Implementation


	// going trough the list
	// removing elements represented by parameters 'TKey c' and 'TValue v'
	// and checking if the action can be performed 
	// return true if element was removed, otherwise return false

	/*
	Allocate a new[] array and store it in a temporary pointer.
	Copy over the previous values that you want to keep.
	Delete[] the old array.
	Change the member variables, ptr and size to point to the new array and hold the new size.
	*/

	SMMIterator array_iterator = iterator();


	while (array_iterator.valid())
	{
		TElem current_element = array_iterator.getCurrent();
		//std::cout << current_element.first << " " << current_element.second << endl;

		if (current_element == TElem(c, v)) {

			sortedMultiMapArray[array_iterator.current_element_position] = sortedMultiMapArray[array_iterator.current_element_position+1];
			arraySize--;


			return true;
		}

		array_iterator.next();
	}
    return false;
}


int SortedMultiMap::size() const {
	//TODO - Implementation
	return arraySize;
}

bool SortedMultiMap::isEmpty() const {
	//TODO - Implementation
	if (arraySize == 0)
		return true;
	return false;
}

SMMIterator SortedMultiMap::iterator() const {
	return SMMIterator(*this);
}

SortedMultiMap::~SortedMultiMap() {
	//TODO - Implementation
	delete[] sortedMultiMapArray;
}

