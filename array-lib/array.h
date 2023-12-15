#include <vector>

#include "tools.h"

#pragma once

using Vector = std::vector<double>;
struct Shape {
    int rows; int cols; 
    Shape(const int& r, const int& c) : rows(r), cols(c) {}
    std::string to_string() const {
        return std::to_string(rows) + " x " + std::to_string(cols);
    }
    bool operator==(const Shape& other) const {
        return rows == other.rows && cols == other.cols;
    }
    bool operator!=(const Shape& other) const {
        return !(*this == other);
    }
};

class Array1D {
    private:
        Vector data;

    public:
        // constructor
        Array1D(const Vector& vec) : data(vec) {}
        // copy constructor
        Array1D(const Array1D& other) : data(other.data) {}
        // move constructor
        Array1D(Array1D&& other) noexcept : data(std::move(other.data)) {}
        // copy assignment
        Array1D& operator=(const Array1D& other) {
            data = other.data;
            return *this;
        }
        // move assignment
        Array1D& operator=(Array1D&& other) noexcept {
            data = std::move(other.data);
            return *this;
        }
        // equality operator
        bool operator==(const Array1D& other) const {
            return data == other.data;
        }
        // destructor
        ~Array1D() = default;

        double operator[](int i) const {
            return data[i];
        }

        void print() const;
        int size() const;

        // array operations

        double dot(const Array1D& other) const;

        Array1D operator+(const Array1D& other) const;
        Array1D operator+(const double& scalar) const;

        Array1D operator-(const Array1D& other) const;
        Array1D operator-(const double& scalar) const;

        Array1D operator*(const Array1D& other) const;
        Array1D operator*(const double& scalar) const;

};


using Matrix = std::vector<std::vector<double>>;

class Array2D {
    private:
        Matrix data;
        Shape shape;
        bool is_square() const;
        void throw_if_not_square() const;
        Shape get_shape() const;
        
    public:
        // constructor
        Array2D(const Matrix& mat) : data(mat), shape(get_shape()) {}
        Array2D(const Matrix& mat, const Shape& sh) : data(mat), shape(sh) {}
        // copy constructor
        Array2D(const Array2D& other) : data(other.data), shape(get_shape()) {}
        // move constructor
        Array2D(Array2D&& other) noexcept : data(std::move(other.data)), shape(get_shape()) {}
        // copy assignment
        Array2D& operator=(const Array2D& other) {
            data = other.data;
            return *this;
        }
        // move assignment
        Array2D& operator=(Array2D&& other) noexcept {
            data = std::move(other.data);
            return *this;
        }
        // destructor
        ~Array2D() = default;

        Vector& operator[](int i) {
            return data[i];
        }

        void throw_same_shape(const Array2D& other) const;

        void print() const;

        // array operations
        Array1D dot(const Array1D& other) const;
        Array2D dot(const Array2D& other) const;

        Array2D operator+(const Array2D& other) const;
        Array2D operator+(const double& scalar) const;

        Array2D operator-(const Array2D& other) const;
        Array2D operator-(const double& scalar) const;

        Array2D operator*(const Array2D& other) const;
        Array2D operator*(const double& scalar) const;


        Array2D get_transpose() const;
};
