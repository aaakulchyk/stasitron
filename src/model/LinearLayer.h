#ifndef LINEAR_LAYER_H
#define LINEAR_LAYER_H

#include <exception>

#include "Layer.h"
#include "Serializer.h"

template <typename T>
struct LinearGrad{
private:
    Matrix<T> _a;
    Matrix<T> _b;
public:
    void calculate(const Matrix<T>& last_output, const Matrix<T>& grad_output){
        auto last_input_T = last_input.transpose();
        last_input_T.multiply(grad_output, _a);
        grad_output.sum_rows(_b);
    }
};

template <typename T>
class LinearLayer: Layer{
private:
    Matrix<T> a;
    Matrix<T> b;

    Matrix<T> output = nullptr;
    Matrix<T> back_output = nullptr;
    Matrix<T>* last_input = nullptr;

    LinearGrad<T> grad;

public:
    virtual const Matrix<T>* forward(const Matrix<T>* input){
        last_input = input;

        a.multiply(*input, output);
        output.add(b);
        
        return *output;
    };

    virtual const Matrix<T>* backward(const Matrix<T>* grad_output){
        if(!last_input){
            throw std::exception("Backward can't be processed. The last_input pointed is null");
        }

        Matrix a_T = a.transpose();
        a_T.multiply(*grad_output, back_output);

        grad.calculate(*last_input, &grad_output);

        last_input = nullptr;
        return &back_output;
    }; 

    const LinearGrad<T>& get_grad() const{
        return grad;
    }

    Serializer& make_serializer(){
        return MockSerializer();
    };
};


#endif