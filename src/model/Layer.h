#ifndef LAYER_H
#define LAYER_H

class Matrix;
class Vector;
class Serializer;

class Layer{
public:
    virtual const Vector* forward(const Vector* input);
    virtual const Matrix* forward(const Matrix* input); 

    virtual const Vector* backward(const Vector* input);
    virtual const Matrix* backward(const Matrix* input); 

    virtual Serializer& get_serializer();
};


#endif