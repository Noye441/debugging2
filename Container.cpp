#include "Container.h"


float FloatArray::getValue(int index){
    assert( index >=0 && index < size());
    return data[index];
}

void FloatArray::resize(int n){
    if(n==numValues){
        return;
    }
    if(n<numValues){
        float* newData= new float[n];
        for( int i=0;i<n;i++){
            newData[i]=data[i];
        }
        delete[] data;
        data = newData;
        numValues = n;
        maxValues = n; 
    }
    else if (n>numValues){
        if(n>maxValues){
            reserve(n * 2);
        }
        for(int i=numValues; i< n; i++){
            data[i]=0.0f;
        }
        numValues=n;
    }
   
}
void FloatArray::pop_back(){
    if(empty()){
        std::cout<<"The array is currently empty."<<std::endl;
        return;
    }
    else {numValues--;}
}
