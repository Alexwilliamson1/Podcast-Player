#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <cstddef>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include "Defs.h"

//A template class for creating and using arrays of objects: 
template <typename T>
class Array {
	template <typename V>
	friend std::ostream& operator<<(std::ostream&, const Array<V>&);
	public:
		Array() = default;
		Array<T>& operator+=(const T& element);
		Array<T>& operator-=(const T& element);
		const T& operator[](int index) const;
		T& operator[](int index);
		int getSize() const;
		void clear();
		bool isFull() const;
	private:
		std::vector<T> elements;
};

//To add an element to an array:
template <typename T>
Array<T>& Array<T>::operator+=(const T& element){
	if (!isFull()) { 
  		elements.push_back(element);
	}
	return *this;
}

//To remove an element from an array:
template <typename T>
Array<T>& Array<T>::operator-=(const T& element) {
	auto it = std::find(elements.begin(), elements.end(), element);
        if (it != elements.end()) {
            	elements.erase(it);
        }
    	return *this;
}

//To delete all elements in an array:
template <typename T>
void Array<T>::clear() {
	elements.clear();
}

//To return the size of an array:
template <typename T> 
int Array<T>::getSize() const{
	return static_cast<int>(elements.size());
}

//To determine if an array is full (if it contains 256 or more elements):
template <typename T> 
bool Array<T>::isFull() const{
	return elements.size() >= static_cast<std::size_t>(MAX_ARR);
}

//To access a const element by index:
template <typename T> 
const T& Array<T>::operator[](int index) const {
	if (index < 0) {
		throw std::out_of_range("You are attempting to access a negative array index.");
	}
	return elements.at(static_cast<std::size_t>(index));
}

//To access an element by index:
template <typename T> 
T& Array<T>::operator[](int index) {
	if (index < 0) {
		throw std::out_of_range("You are attempting to access a negative array index.");
	}				
	return elements.at(static_cast<std::size_t>(index));
}

//To output the elements in an array:
template <typename V>
std::ostream& operator<<(std::ostream& out, const Array<V>& arr) {
    	for (const V& element : arr.elements) {
    	        out << element << "\n";
        }
    	return out;
}

#endif
