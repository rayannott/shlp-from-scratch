#include "array.h"


void Array2D::throw_same_shape(const Array2D& other) const {
    auto shape_me = shape;
    auto shape_other = other.shape;
    if (shape_me != shape_other) {
        throw std::invalid_argument("Array2D: Arrays must be of same shape, got (" 
            + shape_me.to_string() + ") and (" + shape_other.to_string() + ") instead");
    }
}

void Array2D::print() const
{
    pprint(data);
}

// check if matrix is square
bool Array2D::is_square() const
{
    auto shp = shape;
    return shp.rows == shp.cols;
}


// get the shape of the matrix; returns pair of ints (rows, columns)
// throws exception if matrix is not rectangular
Shape Array2D::get_shape() const
{
    int shape_0 = data.size();
    int shape_1 = data[0].size();
    for (int i = 1; i < shape_0; ++i) {
        if (data[i].size() != shape_1) {
            throw std::invalid_argument("Array2D: matrix must be rectangular, got " 
                + std::to_string(shape_0) + "x(" + std::to_string(shape_1) + "/" 
                + std::to_string(data[i].size()) + ") instead");
        }
    }
    return Shape(shape_0, shape_1);
}


Array2D Array2D::operator+(const Array2D &other) const
{
    throw_same_shape(other);
    Matrix result(shape.rows, Vector(shape.cols));
    for (int i = 0; i < shape.rows; ++i) {
        for (int j = 0; j < shape.cols; ++j) {
            result[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return Array2D(result, shape);
}


Array2D Array2D::operator+(const double& scalar) const
{
    Matrix result(shape.rows, Vector(shape.cols));
    for (int i = 0; i < shape.rows; ++i) {
        for (int j = 0; j < shape.cols; ++j) {
            result[i][j] = data[i][j] + scalar;
        }
    }
    return Array2D(result, shape);
}


Array2D Array2D::operator-(const Array2D &other) const
{
    return *this + (other * (-1.));
}


Array2D Array2D::operator-(const double& scalar) const
{
    return *this + (-scalar);
}


Array2D Array2D::operator*(const Array2D &other) const
{
    throw_same_shape(other);
    Matrix result(shape.rows, Vector(shape.cols));
    for (int i = 0; i < shape.rows; ++i) {
        for (int j = 0; j < shape.cols; ++j) {
            result[i][j] = data[i][j] * other.data[i][j];
        }
    }
    return Array2D(result, shape);
}


Array2D Array2D::operator*(const double& scalar) const
{
    Matrix result(shape.rows, Vector(shape.cols));
    for (int i = 0; i < shape.rows; ++i) {
        for (int j = 0; j < shape.cols; ++j) {
            result[i][j] = data[i][j] * scalar;
        }
    }
    return Array2D(result, shape);
}


Array1D Array2D::dot(const Array1D &other) const
{
    if (shape.cols != other.size()) {
        throw std::invalid_argument("Array2D::dot: Array1D must be of size " 
            + std::to_string(shape.cols) + ", got " + std::to_string(other.size()) + " instead");
    }
    Vector result(shape.rows);
    for (int i = 0; i < shape.rows; ++i) {
        result[i] = 0.;
        for (int j = 0; j < shape.cols; ++j) {
            result[i] += data[i][j] * other[j];
        }
    }
    return Array1D(result);
}


Array2D Array2D::dot(const Array2D &other) const
{
    // TODO check shapes
    auto shp = shape; auto shp_other = other.shape;
    if (shape.cols != other.shape.rows) {
        throw std::invalid_argument("Array2D::dot: shapes must be compatible for matrix multiplication, got (" 
            + shp.to_string() + ") and (" + shp_other.to_string() + ") instead");
    }
    Matrix result(shape.rows, Vector(other.shape.cols));
    for (int i = 0; i < data.size(); ++i) {
        for (int j = 0; j < data.size(); ++j) {
            result[i][j] = 0.;
            for (int k = 0; k < data.size(); ++k) {
                result[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    auto new_shape = Shape(shape.rows, other.shape.cols);
    return Array2D(result, new_shape);
}

Array2D Array2D::get_transpose() const {
    auto shp = shape;
    Matrix result(shp.cols, Vector(shp.rows));
    for (int i = 0; i < data.size(); ++i) {
        for (int j = 0; j < data.size(); ++j) {
            result[i][j] = data[j][i];
        }
    }
    auto new_shape = Shape(shp.cols, shp.rows);
    return Array2D(result, new_shape);
}
