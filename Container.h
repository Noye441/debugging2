#ifndef CONTAINER_H
#define CONTAINER_H

class FloatArray {
private:
    int maxValues;
    int numValues;
    float* data;

public:
    FloatArray(int maxSize = 5);
    ~FloatArray();
    bool empty() const;
    int size() const;
    int maxSize() const;
    void reserve(int n);
    void clear();
    void push_back(float value);
    void print() const;
    float getValue(int index);
    void resize(int n);
    void pop_back();
};

#endif
