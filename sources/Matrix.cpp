#include <iostream>
#include <vector>
#include "Matrix.hpp"

using namespace zich;

// split string on a given delimeter
std::vector<std::string> split(std::string str, const std::string &delimeter)
{
    std::vector<std::string> result;
    while (!str.empty())
    {
        // find delimeter and get substring
        size_t idx = str.find(delimeter);

        // check if not found
        if (idx == std::string::npos)
        {
            result.push_back(str);
            break;
        }
        else
        {
            result.push_back(str.substr(0, idx + delimeter.size()));
            str = str.substr(idx + delimeter.size(), str.size());
        }
    }

    return result;
}

// constructor and destructor
std::vector<double> empty(1, 0.0);
Matrix::Matrix() {}
Matrix::~Matrix() {}

// ---------------------------------------------------------------
// real value addition operators (+)
// ---------------------------------------------------------------
Matrix Matrix::operator+(const double &value) const
{
    std::vector<double> vec;
    for (size_t i = 0; i < this->rows; ++i)
    {
        for (size_t j = 0; j < this->columns; ++j)
        {
            vec.push_back(this->mat.at(i).at(j) + value);
        }
    }

    return Matrix(vec, this->rows, this->columns);
}

Matrix &Matrix::operator+=(const double &value)
{
    for (size_t i = 0; i < this->rows; ++i)
    {
        for (size_t j = 0; j < this->columns; ++j)
        {
            this->mat.at(i).at(j) += value;
        }
    }

    return *this;
}

Matrix Matrix::operator+() const { return *this; }

Matrix zich::operator+(const double &value, const Matrix &mat) { return mat + value; }

// ---------------------------------------------------------------
// matrix addition operators (+)
// ---------------------------------------------------------------
Matrix Matrix::operator+(const Matrix &mat) const
{
    // validate input
    if (this->rows != mat.rows || this->columns != mat.columns)
    {
        throw std::invalid_argument("Matrices dimensions dont match!\n");
    }

    // add matrices
    std::vector<double> vec;
    for (size_t i = 0; i < this->mat.size(); ++i)
    {
        for (size_t j = 0; j < this->mat.at(1).size(); ++j)
        {
            vec.push_back(this->mat.at(i).at(j) + mat.mat.at(i).at(j));
        }
    }

    return Matrix(vec, this->rows, this->columns);
}
Matrix &Matrix::operator+=(const Matrix &mat)
{
    // validate input
    if (this->rows != mat.rows || this->columns != mat.columns)
    {
        throw std::invalid_argument("Matrices dimensions dont match!\n");
    }

    for (size_t i = 0; i < this->rows; ++i)
    {
        for (size_t j = 0; j < this->columns; ++j)
        {
            this->mat.at(i).at(j) += mat.mat.at(i).at(j);
        }
    }

    return *this;
}

// ---------------------------------------------------------------
// real value subtraction operators (-)
// ---------------------------------------------------------------
Matrix Matrix::operator-(const double &value) const { return *this + (-value); }

Matrix &Matrix::operator-=(const double &value)
{
    for (size_t i = 0; i < this->rows; ++i)
    {
        for (size_t j = 0; j < this->columns; ++j)
        {
            this->mat.at(i).at(j) -= value;
        }
    }

    return *this;
}

Matrix Matrix::operator-() const
{
    std::vector<double> vec;

    for (size_t i = 0; i < this->rows; ++i)
    {
        for (size_t j = 0; j < this->columns; ++j)
        {
            vec.push_back(-this->mat.at(i).at(j));
        }
    }

    return Matrix(vec, this->rows, this->columns);
}

Matrix operator-(const double &value, const Matrix &mat) { return (-mat) + value; }

// ---------------------------------------------------------------
// matrix subtraction operators (-)
//----------------------------------------------------------------
Matrix Matrix::operator-(const Matrix &mat) const { return *this + (-mat); }

Matrix &Matrix::operator-=(const Matrix &mat)
{
    // validate input
    if (this->rows != mat.rows || this->columns != mat.columns)
    {
        throw std::invalid_argument("Matrices dimensions dont match!\n");
    }

    for (size_t i = 0; i < this->rows; ++i)
    {
        for (size_t j = 0; j < this->columns; ++j)
        {
            this->mat.at(i).at(j) -= mat.mat.at(i).at(j);
        }
    }

    return *this;
}

// ---------------------------------------------------------------
// real value multiplaction operators (*)
// ---------------------------------------------------------------
Matrix Matrix::operator*(const double &value) const
{
    std::vector<double> vec;

    for (size_t i = 0; i < this->rows; ++i)
    {
        for (size_t j = 0; j < this->columns; ++j)
        {
            vec.push_back(this->mat.at(i).at(j) * value);
        }
    }

    return Matrix(vec, this->rows, this->columns);
}

Matrix &Matrix::operator*=(const double &value)
{
    for (size_t i = 0; i < this->rows; ++i)
    {
        for (size_t j = 0; j < this->columns; ++j)
        {
            this->mat.at(i).at(j) *= value;
        }
    }

    return *this;
}

Matrix operator*(const double &value, const Matrix &mat) { return mat * value; }

// ---------------------------------------------------------------
// matrix multiplaction operators (*)
// ---------------------------------------------------------------
Matrix Matrix::operator*(const Matrix &mat) const
{
    // validate input
    if (this->columns != mat.rows)
    {
        throw std::invalid_argument("Matrices dimensions dont fir for matrix multiplaction operation!\n");
    }

    // do matrix multiplication
    std::vector<double> vec;

    for (size_t i = 0; i < this->rows; ++i)
    {
        for (size_t j = 0; j < mat.columns; ++j)
        {
            double sum = 0;
            for (size_t k = 0; k < this->columns; ++k)
            {
                sum += this->mat.at(i).at(k) * mat.mat.at(k).at(j);
            }
            vec.push_back(sum);
        }
    }

    return Matrix(vec, this->rows, mat.columns);
}

Matrix &Matrix::operator*=(const Matrix &mat)
{
    return *this;
}

// ---------------------------------------------------------------
// comparison operators (<, >, <=, >=, ==, !=)
// ---------------------------------------------------------------
bool Matrix::operator>(const Matrix &mat) const { return false; }
bool Matrix::operator<(const Matrix &mat) const { return false; }
bool Matrix::operator<=(const Matrix &mat) const { return false; }
bool Matrix::operator>=(const Matrix &mat) const { return false; }
bool Matrix::operator==(const Matrix &mat) const { return false; }
bool Matrix::operator!=(const Matrix &mat) const { return false; }

// ---------------------------------------------------------------
// increment and decrement operators
// ---------------------------------------------------------------
Matrix &Matrix::operator++() { return *this; }    // prefix (++x)
Matrix &Matrix::operator++(int) { return *this; } // postfix (x++)
Matrix &Matrix::operator--() { return *this; }    // prefix (--x)
Matrix &Matrix::operator--(int) { return *this; } // postfix (x--)

// ---------------------------------------------------------------
// input and output operators
// ---------------------------------------------------------------
std::ostream &zich::operator<<(std::ostream &out, const Matrix &mat)
{
    for (size_t i = 0; i < mat.mat.size(); ++i)
    {
        std::cout << "[";
        for (size_t j = 0; j < mat.mat.at(i).size() - 1; ++j)
        {
            std::cout << mat.mat.at(i).at(j) << " ";
        }
        std::cout << mat.mat.at(i).at(mat.mat.at(i).size() - 1);
        std::cout << "]" << std::endl;
    }

    return out;
}
std::istream &zich::operator>>(std::istream &in, Matrix &mat)
{
    // get input as string
    std::string str;
    getline(in, str);

    // try to spilt
    std::vector<std::string> str_rows = split(str, ", ");

    // modify row string
    str_rows[0] = str_rows[0].substr(1, str_rows[0].size() - 4);
    for (size_t i = 1; i < str_rows.size(); ++i)
    {
        str_rows[i] = str_rows[i].substr(1, str_rows[i].size() - 2);
    }

    // check if rows have the same shape
    size_t row_length = str_rows.size();

    for (size_t i = 1; i < str_rows.size(); ++i)
    {
        if (str_rows[i].size() != row_length)
        {
            throw std::invalid_argument("All rows must be the same length!!\n");
        }
    }

    // parse values to mat variable
    for (size_t i = 0; i < str_rows.size(); ++i)
    {
        std::vector<std::string> row = split(str_rows[i], " ");
        std::vector<double> vec;
        for (size_t j = 0; j < row.size(); ++j)
        {
            vec.push_back(std::stod(row.at(j)));
        }
        mat.mat.push_back(vec);
    }

    return in;
}