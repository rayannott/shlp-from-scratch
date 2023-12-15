#include "array.h"



void Array1D::print() const
{
    pprint(data);
}


int Array1D::size() const
{
    return data.size();
}


double Array1D::dot(const Array1D &other) const
{
    if (data.size() != other.data.size()) {
        throw std::invalid_argument("Array1D::dot: Arrays must be of same size, got " 
            + std::to_string(data.size()) + " and " + std::to_string(other.data.size()) + " instead");
    }
    double result = 0.;
    for (int i = 0; i < data.size(); ++i) {
        result += data[i] * other.data[i];
    }
    return result;
}


Array1D Array1D::operator+(const Array1D &other) const
{
    if (data.size() != other.data.size()) {
        throw std::invalid_argument("Array1D::operator+: Arrays must be of same size, got " 
            + std::to_string(data.size()) + " and " + std::to_string(other.data.size()) + " instead");
    }
    Vector result(data.size());
    for (int i = 0; i < data.size(); ++i) {
        result[i] = data[i] + other.data[i];
    }
    return Array1D(result);
}


Array1D Array1D::operator+(const double& scalar) const
{
    Vector result(data.size());
    for (int i = 0; i < data.size(); ++i) {
        result[i] = data[i] + scalar;
    }
    return Array1D(result);
}


Array1D Array1D::operator-(const Array1D &other) const
{
    return *this + (other * (-1.));
}


Array1D Array1D::operator-(const double& scalar) const
{
    return *this + (-scalar);
}


Array1D Array1D::operator*(const Array1D &other) const
{
    if (data.size() != other.data.size()) {
        throw std::invalid_argument("Array1D::operator*: Arrays must be of same size, got " 
            + std::to_string(data.size()) + " and " + std::to_string(other.data.size()) + " instead");
    }
    Vector result(data.size());
    for (int i = 0; i < data.size(); ++i) {
        result[i] = data[i] * other.data[i];
    }
    return Array1D(result);
}


Array1D Array1D::operator*(const double& scalar) const
{
    Vector result(data.size());
    for (int i = 0; i < data.size(); ++i) {
        result[i] = data[i] * scalar;
    }
    return Array1D(result);
}
