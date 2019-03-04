#include "Complex.h"
#include <iostream>

using namespace std;

int main() {
    Complex c1(2, 3);
    Complex c2(1, -2);
    Complex c3(2, 3);

    cout << "c1 = ";
    cout << c1;
    cout << "c2 = ";
    cout << c2;
    cout << "c3 = ";
    cout << c3;

    /* Printing numbers */
    Complex sum = c1 + c2;
    cout << "c1 + c2 = ";
    cout << sum;
    Complex dif = c3 - c1;
    cout << "c3 - c1 = ";
    cout << dif;
    Complex mult = c2 * c3;
    cout << "c2 * c3 = ";
    cout << mult;

    /* Verify copy assignment */
    c3 = c1;
    cout << c3;

    cout << "Modulul lui c1 este " << c1.modulus() << "\n";
    cout << "Segmentul dintre c1 si c2 are lungimea " << c1.segment(c2) << "\n";

    return 0;
}
