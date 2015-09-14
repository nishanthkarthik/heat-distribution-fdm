#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include "heat.h"
using namespace std;

#define NGRID 50

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
    //ht.printValues();
    //cout<<endl;
    //ht.update();
    //ht.printValues();
    //ht.exportCsv("init.csv");
    //cout<<endl;

    for(int i = 0; i < 100; i++)
    {
        string fileName = std::to_string(i) + ".csv";
        ht.exportCsv(fileName.c_str());
        ht.updateLoop(50);
    }

    //ht.exportCsv("result.csv");
    //ht.printValues();
    cout<<"Export Done"<<endl;

    return 0;
}
