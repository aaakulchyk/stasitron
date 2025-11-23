#ifndef STASITRON_LA_VECTOR_H
#define STASITRON_LA_VECTOR_H

#include <initializer_list>
#include <vector>

namespace stasitron::la {

template <typename T>
class Vector {
public:
    Vector(std::size_t size);

    Vector(std::size_t size, const T& v);

    Vector(const Vector<T>& other);

    Vector(Vector<T>&& other) noexcept;

    Vector(std::initializer_list<T> init);
    
    ~Vector();

    [[nodiscard]]
    std::size_t size() const;

    // [[nodisczard]]
    // Matrix<T> dot(const Vector<T>& other) const;

    [[nodiscard]]
    T& operator[](std::size_t i);

    [[nodiscard]]
    const T& operator[](std::size_t i) const;

    [[nodiscard]]
    T* data();

    [[nodiscard]]
    const T* data() const;

    void operator=(const Vector<T>& other);

    void operator=(Vector<T>&& other) noexcept;

    [[nodiscard]]
    bool operator==(const Vector<T>& other) const;

    [[nodiscard]]
    bool operator!=(const Vector<T>& other) const;

    [[nodiscard]]
    Vector<T> operator+(const T& scalar);

    void operator+=(const T& scalar);

    [[nodiscard]]
    Vector<T> operator+(const Vector<T>& other);

    void operator+=(const Vector<T>& other);

    [[nodiscard]]
    Vector<T> operator-(const T& scalar);

    void operator-=(const T& scalar);

    [[nodiscard]]
    Vector<T> operator-();

    [[nodiscard]]
    Vector<T> operator-(const Vector<T>& other);

    void operator-=(const Vector<T>& other);

    [[nodiscard]]
    Vector<T> operator*(const T& scalar);

    void operator*=(const T& scalar);

    [[nodiscard]]
    Vector<T> operator*(const Vector<T>& other);

    void operator*=(const Vector<T>& other);

    [[nodiscard]]
    Vector<T> operator/(const T& scalar);

    void operator/=(const T& scalar);

    [[nodiscard]]
    Vector<T> operator/(const Vector<T>& other);

    void operator/=(const T& other);

private:
    std::vector<T> data_;

};

template <typename T>
Vector<T>::Vector(std::size_t size) : data_(size) {};

template <typename T>
Vector<T>::~Vector() = default;

template <typename T>
[[nodiscard]]
std::size_t Vector<T>::size() const {
    return data_.capacity();
}

template <typename T>
[[nodiscard]]
T& Vector<T>::operator[](std::size_t i) {
    return data_[i];
}

template <typename T>
[[nodiscard]]
const T& Vector<T>::operator[](std::size_t i) const {
    return data_[i];
}

template <typename T>
[[nodiscard]]
T* Vector<T>::data() {
    return data_.data();
}

template <typename T>
[[nodiscard]]
const T* Vector<T>::data() const {
    return data_.data();
}

template <typename T>
void Vector<T>::operator=(const Vector<T>& other) {
    if (this == &other) return;
    data_ = other.data_;
}

template <typename T>
void Vector<T>::operator=(Vector<T>&& other) noexcept {
    if (this == &other) return;
    data_ = std::move(other.data_);
}

template <typename T>
[[nodiscard]]
bool Vector<T>::operator==(const Vector<T>& other) const {
    return data_ == other.data_;
}

template <typename T>
[[nodiscard]]
bool Vector<T>::operator!=(const Vector<T>& other) const {
    return !(*this == other);
}

template <typename T>
[[nodiscard]]
Vector<T> Vector<T>::operator+(const T& scalar) {
    Vector<T> result(size());
    for (std::size_t i = 0; i < size(); ++i) {
        result[i] = (*this)[i] + scalar;
    }
    return result;
}

template <typename T>
void Vector<T>::operator+=(const T& scalar) {
    for (std::size_t i = 0; i < size(); ++i) {
        (*this)[i] += scalar;
    }
}

template <typename T>
[[nodiscard]]
Vector<T> Vector<T>::operator+(const Vector<T>& other) {
    Vector<T> result(size());
    for (std::size_t i = 0; i < size(); ++i) {
        result[i] = (*this)[i] + other[i];
    }
    return result;
}

template <typename T>
void Vector<T>::operator+=(const Vector<T>& other) {
    for (std::size_t i = 0; i < size(); ++i) {
        (*this)[i] += other[i];
    }
}

template <typename T>
[[nodiscard]]
Vector<T> Vector<T>::operator-() {
    Vector<T> result(size());
    for (std::size_t i = 0; i < size(); ++i) {
        result[i] = -(*this)[i];
    }
    return result;
}

template <typename T>
[[nodiscard]]
Vector<T> Vector<T>::operator-(const T& scalar) {
    Vector<T> result(size());
    for (std::size_t i = 0; i < size(); ++i) {
        result[i] = (*this)[i] - scalar;
    }
    return result;
}

template <typename T>
void Vector<T>::operator-=(const T& scalar) {
    for (std::size_t i = 0; i < size(); ++i) {
        (*this)[i] -= scalar;
    }
}

template <typename T>
[[nodiscard]]
Vector<T> Vector<T>::operator-(const Vector<T>& other) {
    Vector<T> result(size());
    for (std::size_t i = 0; i < size(); ++i) {
        result[i] = (*this)[i] - other[i];
    }
    return result;
}

template <typename T>
void Vector<T>::operator-=(const Vector<T>& other) {
    for (std::size_t i = 0; i < size(); ++i) {
        (*this)[i] -= other[i];
    }
}

template <typename T>
[[nodiscard]]
Vector<T> Vector<T>::operator*(const T& scalar) {
    Vector<T> result(size());
    for (std::size_t i = 0; i < size(); ++i) {
        result[i] = (*this)[i] * scalar;
    }
    return result;
}

template <typename T>
void Vector<T>::operator*=(const T& scalar) {
    for (std::size_t i = 0; i < size(); ++i) {
        (*this)[i] *= scalar;
    }
}

template <typename T>
[[nodiscard]]
Vector<T> Vector<T>::operator*(const Vector<T>& other) {
    Vector<T> result(size());
    for (std::size_t i = 0; i < size(); ++i) {
        result[i] = (*this)[i] * other[i];
    }
    return result;
}

template <typename T>
void Vector<T>::operator*=(const Vector<T>& other) {
    for (std::size_t i = 0; i < size(); ++i) {
        (*this)[i] *= other[i];
    }
}

template <typename T>
[[nodiscard]]
Vector<T> Vector<T>::operator/(const T& scalar) {
    Vector<T> result(size());
    for (std::size_t i = 0; i < size(); ++i) {
        result[i] = (*this)[i] / scalar;
    }
    return result;
}

template <typename T>
void Vector<T>::operator/=(const T& scalar) {
    for (std::size_t i = 0; i < size(); ++i) {
        (*this)[i] /= scalar;
    }
}

template <typename T>
[[nodiscard]]
Vector<T> Vector<T>::operator/(const Vector<T>& other) {
    Vector<T> result(size());
    for (std::size_t i = 0; i < size(); ++i) {
        result[i] = (*this)[i] / other[i];
    }
    return result;
}

template <typename T>
void Vector<T>::operator/=(const T& other) {
    for (std::size_t i = 0; i < size(); ++i) {
        (*this)[i] /= other;
    }
}

}

#endif  // STASITRON_LA_VECTOR_H