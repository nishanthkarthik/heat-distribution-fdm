#ifndef HEAT_DEF
#define HEAT_DEF
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class heat
{
public:
    int dim;
    double **a;

    heat(int n)
    {
        dim=n;
        a = new double*[dim];
        for(int i=0; i<dim; ++i)
            a[i] = new double[dim];
    }

    ~heat()
    {
        for(int i=0; i<dim; ++i)
            delete a[i];
        delete a;
    }

    void updateLoop(int count)
    {
        for (int i = 0; i < count; i++)
            update();
    }

    void update()
    {
        for (int i = 1; i < dim-1; i++)
        {
            for (int j = 1; j < dim-1; j++)
            {
                a[i][j] = (a[i-1][j] + a[i+1][j] + a[i][j-1] + a[i][j+1]) / 4;
            }
        }
    }

    void readValues(double top[], double bottom[], double left[], double right[])
    {
        for (int i = 0; i < dim; i++)
        {
            a[i][0] = left[i];
            a[0][i] = top[i];
            a[dim-1][i] = bottom[i];
            a[i][dim-1] = right[i];
        }

        double avg = 0;
        for (int i = 0; i < dim; i++)
        {
            avg += top[i] + bottom[i] + left[i] + right[i];
        }
        avg /= (4 * dim);

        for (int i = 0; i < dim; i++)
        {
            for (int j = 0; j < dim; j++)
            {
                if ((i==0) || (i==dim-1) || (j==0) || (j==dim-1))
                    continue;
                a[i][j] = avg;
            }
        }
    }

    void printValues()
    {
        cout<<std::fixed;
        for (int i = 0; i < dim; i++)
        {
            for (int j = 0; j < dim; j++)
            cout<<std::setprecision(6)<<a[i][j]<<" ";
            cout<<endl;
        }
    }

    void exportCsv(const char* fileName)
    {
        ofstream out(fileName,ios::out);
        out<<std::fixed;
        for (int i = 0; i < dim; i++)
        {
            for (int j = 0; j < dim; j++)
                out<<i<<','<<j<<','<<std::setprecision(6)<<a[i][j]<<endl;
        }
        out.close();
    }
};
#endif
