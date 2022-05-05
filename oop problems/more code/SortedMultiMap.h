#pragma once
//DO NOT INCLUDE SMMITERATOR

//DO NOT CHANGE THIS PART
#include <vector>
#include <utility>
typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;
#define NULL_TVALUE -111111
#define NULL_TELEM pair<TKey, TValue>(-111111, -111111);
using namespace std;
class SMMIterator;
typedef bool(*Relation)(TKey, TKey);


class SortedMultiMap {
	friend class SMMIterator;
    private:
        //TODO - Representation
        
        
        // there will be a sortedMultiMapArray array containing TElem type elements
        // which represent the relation between a Tkey and TValue
        
        // Relation is the storing relation of the TElem type elements
        Relation array_relation;

        // an array storing all the relations between Tkey and TValue
        TElem** sortedMultiMapArray;

        // number of all element pointers in sortedMultiMapArray 
        unsigned int arraySize;

        // count of number of elements refferenced by the pointers in sortedMultiMapArray
        //unsigned int countElems;

        // vector holding all values associated to a key
        //vector<TValue>

        // auxiliary functions -> private functions



    public:

    // constructor
    SortedMultiMap(Relation r);

	//adds a new key value pair to the sorted multi map
    void add(TKey c, TValue v);

	//returns the values belonging to a given key
    vector<TValue> search(TKey c) const;

	//removes a key value pair from the sorted multimap
	//returns true if the pair was removed (it was part of the multimap), false if nothing is removed
    bool remove(TKey c, TValue v);

    //returns the number of key-value pairs from the sorted multimap
    int size() const;

    //verifies if the sorted multi map is empty
    bool isEmpty() const;

    // returns an iterator for the sorted multimap. The iterator will returns the pairs as required by the relation (given to the constructor)	
    SMMIterator iterator() const;

    // destructor
    ~SortedMultiMap();
};
