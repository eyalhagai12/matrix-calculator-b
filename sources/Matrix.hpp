#include <iostream>
#include <vector>

namespace zich
{
	class Matrix;
	Matrix operator+(const double &value, const Matrix &mat);
	Matrix operator-(const double &value, const Matrix &mat);
	Matrix operator*(const double &value, const Matrix &mat);
	Matrix operator*(double const &value, Matrix &mat);
	std::ostream &operator<<(std::ostream &out, const Matrix &mat);
	std::istream &operator>>(std::istream &in, Matrix &mat);

} // namespace zich

class zich::Matrix
{
private:
	std::vector<std::vector<double>> mat; // matrix data structure
	int rows;
	int columns;

public:
	// constructor and destructor
	Matrix(std::vector<double> vec, int rows, int columns) : mat(std::vector<std::vector<double>>((size_t)rows, std::vector<double>((size_t)columns, 0.0))), rows(rows), columns(columns)
	{
		// validate input
		if (rows * columns != vec.size())
		{
			throw std::invalid_argument("rows * columns must be equall to the length of the given vector\n");
		}

		// fill matrix
		for (size_t i = 0; i < rows; ++i)
		{
			for (size_t j = 0; j < columns; ++j)
			{
				mat.at(i).at(j) = vec.at((i * (size_t)columns) + j);
			}
		}
	}
	Matrix() : rows(1), columns(1) {}
	Matrix(const Matrix& matrix) : mat(matrix.mat), rows(matrix.rows), columns(matrix.columns) {} 
	~Matrix();

	// real value addition operators (+)
	Matrix operator+(const double &value) const;
	Matrix &operator+=(const double &value);
	Matrix operator+() const;
	friend Matrix operator+(const double &value, const Matrix &mat);

	// matrix addition operators (+)
	Matrix operator+(const Matrix &mat) const;
	Matrix &operator+=(const Matrix &mat);

	// real value subtraction operators (-)
	Matrix operator-(const double &value) const;
	Matrix &operator-=(const double &value);
	Matrix operator-() const;
	friend Matrix operator-(const double &value, const Matrix &mat);

	// matrix subtraction operators (-)
	Matrix operator-(const Matrix &mat) const;
	Matrix &operator-=(const Matrix &mat);

	// real value multiplaction operators (*)
	Matrix operator*(const double &value) const;
	Matrix &operator*=(const double &value);
	friend Matrix operator*(const double &value, const Matrix &mat);
	friend Matrix operator*(double const &value, Matrix &mat);

	// matrix multiplaction operators (*)
	Matrix operator*(const Matrix &mat) const;
	Matrix &operator*=(const Matrix &mat);

	// comparison operators (<, >, <=, >=, ==, !=)
	bool operator<(const Matrix &mat) const;
	bool operator>(const Matrix &mat) const;
	bool operator<=(const Matrix &mat) const;
	bool operator>=(const Matrix &mat) const;
	bool operator==(const Matrix &mat) const;
	bool operator!=(const Matrix &mat) const;

	// increment and decrement operators
	Matrix &operator++();	 // prefix (++x)
	Matrix operator++(int); // postfix (x++)
	Matrix &operator--();	 // prefix (--x)
	Matrix operator--(int); // postfix (x--)

	// input and output operators
	friend std::ostream &operator<<(std::ostream &out, const Matrix &mat);
	friend std::istream &operator>>(std::istream &in, Matrix &mat);
};