#include <iostream>
#include "sources/Matrix.hpp"

using namespace zich;
using namespace std;

int main(int argc, char const *argv[])
{
    int option = 0;
    cout << "Welcome to the matrix calculator!" << endl;
    cout << "Supported operations: " << endl
         << "1. mat + mat" << endl
         << "2. mat - mat" << endl
         << "3. mat * mat" << endl
         << "4. scalar * mat" << endl
         << "5. mat--" << endl
         << "6. mat++" << endl
         << endl
         << "Also supports comperison operations such as: " << endl
         << "7. mat > mat" << endl
         << "8. mat < mat" << endl
         << "9. mat => mat" << endl
         << "10. mat <= mat" << endl
         << "11. mat != mat" << endl
         << "12. mat == mat" << endl;

    cout << "Please choose the number of the option you would like (use -1 to exit): ";
    cin >> option;

    while (option != -1)
    {
        Matrix mat1;
        Matrix mat2;
        double scalar = 0;

        switch (option)
        {
        case 1:
            cout << "Enter the first matrix" << endl;
            cin >> mat1;
            cout << "Enter the second matrix" << endl;
            cin >> mat2;
            cout << "Result: " << endl
                 << mat1 + mat2 << endl;
            break;
        case 2:
            cout << "Enter the first matrix" << endl;
            cin >> mat1;
            cout << "Enter the second matrix" << endl;
            cin >> mat2;
            cout << "Result: " << endl
                 << mat1 - mat2 << endl;
            break;
        case 3:
            cout << "Enter the first matrix" << endl;
            cin >> mat1;
            cout << "Enter the second matrix" << endl;
            cin >> mat2;
            cout << "Result: " << endl
                 << mat1 * mat2 << endl;
            break;
        case 4:
            cout << "Enter a matrix" << endl;
            cin >> mat1;
            cout << "Enter a scalar" << endl;
            cin >> scalar;
            cout << "Result: " << endl
                 << mat1 * scalar << endl;
            break;
        case 5:
            cout << "Enter a matrix" << endl;
            cin >> mat1;
            cout << "Result: " << endl
                 << --mat1 << endl;
            break;
        case 6:
            cout << "Enter a matrix" << endl;
            cin >> mat1;
            cout << "Result: " << endl
                 << ++mat1 << endl;
            break;
        case 7:
            cout << "Enter the first matrix" << endl;
            cin >> mat1;
            cout << "Enter the second matrix" << endl;
            cin >> mat2;
            cout << "Result: " << (mat1 > mat2) << endl;
            break;
        case 8:
            cout << "Enter the first matrix" << endl;
            cin >> mat1;
            cout << "Enter the second matrix" << endl;
            cin >> mat2;
            cout << "Result: " << (mat1 < mat2) << endl;
            break;
        case 9:
            cout << "Enter the first matrix" << endl;
            cin >> mat1;
            cout << "Enter the second matrix" << endl;
            cin >> mat2;
            cout << "Result: " << (mat1 >= mat2) << endl;
            break;
        case 10:
            cout << "Enter the first matrix" << endl;
            cin >> mat1;
            cout << "Enter the second matrix" << endl;
            cin >> mat2;
            cout << "Result: " << (mat1 <= mat2) << endl;
            break;
        case 11:
            cout << "Enter the first matrix" << endl;
            cin >> mat1;
            cout << "Enter the second matrix" << endl;
            cin >> mat2;
            cout << "Result: " << (mat1 != mat2) << endl;
            break;
        case 12:
            cout << "Enter the first matrix" << endl;
            cin >> mat1;
            cout << "Enter the second matrix" << endl;
            cin >> mat2;
            cout << "Result: " << (mat1 == mat2) << endl;
            break;

        default:
            cout << "Invlaid Option" << endl;
            break;
        }

        cout << "Please choose the number of the option you would like (use -1 to exit): ";
        cin >> option;
    }

    cout << "Thanks and Goodbye!" << endl;

    return 0;
}
