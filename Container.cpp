#include "Container.h"
#include <cassert>  // For assert
#include <iostream> // For std::cout and std::endl

// Constructor: Allocates a dynamic array and initializes default values
FloatArray::FloatArray(int maxSize) : maxValues(maxSize), numValues(0) {
    data = new float[maxValues]; // Allocate dynamic array
}

// Destructor: Deallocates the dynamic array
FloatArray::~FloatArray() {
    delete[] data;
}

// Returns true if the array is empty, false otherwise
bool FloatArray::empty() const {
    return numValues == 0;
}

// Returns the number of values in the array
int FloatArray::size() const {
    return numValues;
}

// Returns the maximum number of possible values in the array
int FloatArray::maxSize() const {
    return maxValues;
}

// Reserve new memory if n is greater than the current maximum
void FloatArray::reserve(int n) {
    if (n <= maxValues) {
        return;  // Early exit if no resize is needed
    }

    float* newData = new float[n]; // Allocate new array
    for (int i = 0; i < numValues; i++) {
        newData[i] = data[i]; // Copy old values to new array
    }

    delete[] data; // Deallocate old array
    data = newData; // Point to new array
    maxValues = n;  // Update maxValues
}

// Clears the array and resets the size to 0
void FloatArray::clear() {
    numValues = 0; // Reset the number of values to 0
}

// Adds a value to the end of the array
void FloatArray::push_back(float value) {
    if (numValues == maxValues) {
        reserve(maxValues * 2); // Double the size if full
    }
    data[numValues++] = value; // Add value and increment numValues
}

// Gets the value at the specified index
float FloatArray::getValue(int index) {
    assert(index >= 0 && index < size());  // Ensure index is within bounds
    return data[index];
}

// Resizes the array to the specified new size
void FloatArray::resize(int n) {
    if (n == numValues) {
        return;
    }
    if (n < numValues) {
        float* newData = new float[n];
        for (int i = 0; i < n; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        numValues = n;
        maxValues = n;
    } else if (n > numValues) {
        if (n > maxValues) {
            reserve(n * 2);
        }
        for (int i = numValues; i < n; i++) {
            data[i] = 0.0f;
        }
        numValues = n;
    }
}

// Removes the last value from the array
void FloatArray::pop_back() {
    if (empty()) {
        std::cout << "The array is currently empty." << std::endl;
        return;
    } else {
        numValues--; // Decrement the number of values
    }
}

// Prints all the array values to the console in one line
void FloatArray::print() const {
    for (int i = 0; i < numValues; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}
