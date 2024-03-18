// LAPRAK 2 : UNGUIDED 2
// AFRIZAL DWI NUGRAHA          
// 2311102136
// S1 IF-11-D
#include <iostream>
using namespace std;

// PROGRAM INPUT ARRAY 3 DIMENSI by AFRIZAL DWI NUGRAHA
int main()
{
    // Deklarasi array dengan ukuran 1x3x8
    int array_136[1][3][8];
    // Input elemen
    for (int x_136 = 0; x_136 < 1; x_136++)
    {
        for (int y_136 = 0; y_136 < 3; y_136++)
        {
            for (int z_136 = 0; z_136 < 8; z_136++)
            {
                cout << "Input Array[" << x_136 << "][" << y_136 << "][" << z_136 << "] = ";
                cin >> array_136[x_136][y_136][z_136];
            }
        }
        cout << endl;
    }
    // Output Array
    for (int x_136 = 0; x_136 < 1; x_136++)
    {
        for (int y_136 = 0; y_136 < 3; y_136++)
        {
            for (int z_136 = 0; z_136 < 8; z_136++)
            {
                cout << "Data Array[" << x_136 << "][" << y_136 << "][" << z_136 << "] = " << array_136[x_136][y_136][z_136] << endl;
            }
        }
    }
    cout << endl;
    // Tampilan array
    for (int x_136 = 0; x_136 < 1; x_136++)
    {
        for (int y_136 = 0; y_136 < 3; y_136++)
        {
            for (int z_136 = 0; z_136 < 8; z_136++)
            {
                cout << array_136[x_136][y_136][z_136] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }
}