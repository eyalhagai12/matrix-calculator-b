#include <iostream>
#include "Matrix.hpp"

using namespace zich;
using namespace std;

int main(int argc, char const *argv[])
{
    vector<double> vec = {1, 2, 3, 4, 5, 6};
    vector<double> vec2 = {1, 2, 3, 4, -5, 6};

    Matrix mat1(vec, 2, 3);
    Matrix mat2(vec, 2, 3);
    Matrix mat3(vec2, 2, 3);
    Matrix mat4(vec2, 3 ,2);

    cout << "mat1 > mat2: " << (mat1 > mat2) << std::endl;
    cout << "mat1 >= mat2: " << (mat1 >= mat2) << std::endl;
    cout << "mat1 < mat2: " << (mat1 < mat2) << std::endl;
    cout << "mat1 <= mat2: " << (mat1 <= mat2) << std::endl;
    cout << "mat1 == mat2: " << (mat1 == mat2) << std::endl;
    cout << "mat1 != mat2: " << (mat1 != mat2) << std::endl;
    cout << endl;
    cout << "mat1 > mat3: " << (mat1 > mat3) << std::endl;
    cout << "mat1 >= mat3: " << (mat1 >= mat3) << std::endl;
    cout << "mat1 < mat3: " << (mat1 < mat3) << std::endl;
    cout << "mat1 <= mat3: " << (mat1 <= mat3) << std::endl;
    cout << "mat1 == mat3: " << (mat1 == mat3) << std::endl;
    cout << "mat1 != mat3: " << (mat1 != mat3) << std::endl;
    cout << endl;
    cout << "(*) \n" << (mat1 * mat4) << endl;
    cout << endl;
    cout << "(+) \n" << (mat1 + mat3) << endl;
    cout << endl;
    cout << "(-) \n" << (mat1 - mat3) << endl;

    return 0;
}
