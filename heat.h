#ifndef HEAT_DEF
#define HEAT_DEF

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

    void readValues(double top[], double bottom[], double left[], double right[])
    {
        for (int i = 0; i < dim; i++)
        {
            a[0][i] = top[i];
            a[i][0] = left[i];
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
                if ((i==0) || (i==dim-1) || (j==0) || (j==n-1))
                    continue;
                a[i][j] = avg;
            }
        }
    }

    void printValues()
    {
        for (int i = 0; i < dim; i++)
        {
            for (int j = 0; j < dim; j++)
                cout<<a<<" ";
            cout<<endl;
        }
    }
};
#endif
