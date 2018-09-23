#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    cout << "Hello World!" << endl;

    for (float x = -4; x <= 4; x = x + 0.000001) {
        float a = (x * x * x * x - 13 * x * x + 36 - 1 / x);
        if ((a > (-0.0001)) && (a < 0.0001)) {
            cout << "answer x = " << x << endl;
            x = x + 0.0001;
        }
    };
    cout << "done" ;

    return 0;
}
