#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include "heat.h"
using namespace std;

#define NGRID 8

int main()
{
    heat ht(NGRID);
    double l[NGRID],r[NGRID],t[NGRID],b[NGRID];
    for (int i = 0; i < NGRID; i++)
    {
        l[i] = r[i] = b[i] = 300;
        t[i] = 400;
    }
    ht.readValues(t,b,l,r);
    ht.printValues();
    cout<<endl;
    ht.update();
    ht.printValues();
    cout<<endl;
    ht.updateLoop(50);
    ht.printValues();
    return 0;
}
