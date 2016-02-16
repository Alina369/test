#include <iostream>
#include <string>
#include <QTime>
#include <cmath>

using namespace std;


void fiba2(int k, int& ck, int& ck1)
{
   if (k<2)
   {
       ck = 1;
       ck1 = 1;
   }
   else
   {
       fiba2(k-1,ck1,ck);
       ck += ck1;
   }
}

int fiba2a(int k)
{
    int ck, ck1;
    fiba2(k,ck,ck1);
    return ck;
}

double limit()
{
    const double e = 1e-8;
    double r = 0;
    for (int k = 1; ; ++k)
    {
        int ck,ck1;
        fiba2(k,ck,ck1);
        double rk = double(ck)/ck1;
        if (fabs(r - rk) < e)
            return rk;
            r = rk;
    }
}

double sqr(double x)
{
    return x*x;
}

bool realRoot(int a, int b, int c, double& x1, double& x2)
{
    double D = sqr(double(b))-4.*a*c;
    if (D < 0)
        return false;
    else
    {
        x1 = ((double(-b))+sqrt(D))/(2*a);
        x2 = ((double(-b))-sqrt(D))/(2*a);
        return true;
    }

}

bool indentify(double x, int& a, int& b, int& c )
{
    int I = 10;
    const double e = 1e-6;
    for (a = -I; a <= I; ++a)
        for (b = -I; b <= I; ++b)
            for (c = -I; c <= I; ++c)
            {
                double x1, x2;
                if (realRoot(a,b,c,x1,x2))
                {
                    if (fabs(x1-x) < e)
                        return true;
                    if (fabs(x2-x) <e)
                        return true;
                }
            }
    return false;
}

int main()
{
    int a,b,c;
    if (indentify(limit(), a, b, c))
        cout << "a = " << a << endl << "b = " << b << endl << "c = " << c << endl;
    else
        cout << "NAN" << endl;
        cout << limit() << endl;
    return 0;
}
