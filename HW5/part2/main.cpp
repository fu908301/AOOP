#include "Vector.h"
#include "Trace.h"

#include <iostream>

using std::cout;
using std::endl;


Vector<float> fvec(100);
Vector<int> ivec(200);
Vector<char> cvec(300);

Vector<float*> pfvec(100);
Vector<int*> pivec(200);
Vector<char*> pcvec(300);

int main()
{
    TRACE(dummy, "main()");

    fvec[3] = 10.10;
    cout << " fvec[3] = " << fvec[3] << endl;

    ivec[3] = 10;
    cout << " ivec[3] = " << ivec[3] << endl;

    cvec[3] = 'A';
    cout << " cvec[3] = " << cvec[3] << endl;

    float f = 10.10;
    pfvec.elem(3) = &f;
    pfvec[3] = &f;
    cout << " pfvec.elem(3) = " << *pfvec.elem(3) << endl;
    cout << " pfvec[3] = " << *pfvec[3] << endl;

    int a = 10;
    pivec.elem(3) = &a;
    pivec[3] = &a;
    cout << " pivec.elem(3) = " << *pivec.elem(3) << endl;
    cout << " pivec[3] = " << *pivec[3] << endl;

    char c = 'A';
    pcvec.elem(3) = &c;
    pcvec[3] = &c;
    cout << " pcvec.elem(3) = " << *pcvec.elem(3) << endl;
    cout << " pcvec[3] = " << *pcvec[3] << endl;

    return 0;
}
