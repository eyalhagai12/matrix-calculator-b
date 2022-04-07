#include <iostream>
#include "Matrix.hpp"

using namespace zich;
using namespace std;

int main(int argc, char const *argv[])
{
    vector<double> vec = {1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6, 1, 2, 3, 4};
    Matrix mat(vec, 2, 8);
    Matrix mat2(vec, 8, 2);
    return 0;
}
