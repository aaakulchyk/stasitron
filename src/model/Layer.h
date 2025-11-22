#ifndef LAYER_H
#define LAYER_H

class Matrix;
class Vector;
class Serializer;

class Layer{
public:
    virtual Vector* forward(const Vector* input);
    virtual Matrix* forward(const Matrix* input); 

    virtual Vector* backward(const Vector* input);
    virtual Matrix* backward(const Matrix* input); 

    virtual Serializer& get_serializer();
};


#endif