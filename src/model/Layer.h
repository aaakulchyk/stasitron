#ifndef LAYER_H
#define LAYER_H

#include "Serializer.h"

template <typename T>
class Matrix{};
class Vector{};

template <typename T>
class Layer{
public:
    virtual const Matrix<T>* forward(const Matrix<T>* input);
    virtual const Matrix<T>* backward(const Matrix<T>* grad_output); 

    virtual Serializer& make_serializer();
};




#endif