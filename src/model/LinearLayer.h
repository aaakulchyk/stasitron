#ifndef LINEAR_LAYER_H
#define LINEAR_LAYER_H

#include "Layer.h"
#include "Serializer.h"
#include <vector>

template <typename T>
struct LinearGrad{
private:
    T _a;
    T _b;
public:
    void calculate(const T& last_output, const T& grad_output){
        T last_input_T = last_input.transpose();
        last_input_T.multiply(grad_output, _a);
        grad_output.sum_rows(_b);
    }
};

template <typename T>
class LinearLayer: Layer{
private:
    T a;
    T b;

    T output = nullptr;
    T back_output = nullptr;
    T* last_input = nullptr;

    LinearGrad<T> grad;

public:
    virtual const T* forward(const T* input){
        last_input = input;

        a.multiply(*input, output);
        output.add(b);
        
        return *output;
    };

    virtual const T* backward(const T* grad_output){
        Matrix a_T = a.transpose();
        a_T.multiply(*grad_output, back_output);

        grad.calculate(*last_input, &grad_output);

        return &back_output;
    }; 

    const &LinearGrad<T> get_grad() const{
        return grad;
    }

    Serializer& make_serializer(){
        return MockSerializer();
    };
};


#endif