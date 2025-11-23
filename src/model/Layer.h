#ifndef LAYER_H
#define LAYER_H

#include "Serializer.h"

class Matrix{};
class Vector{};

template <typename T>
class Layer{
public:
    virtual const T* forward(const T* input);
    virtual const T* backward(const T* grad_output); 

    virtual Serializer& make_serializer();
};




#endif