#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double p(const double x);  

int main()
{
    double zp, zk, z;
    int n;

    cout << "zp = "; cin >> zp;  
    cout << "zk = "; cin >> zk;  
    cout << "n = "; cin >> n;    

    cout << fixed << setprecision(5);
    cout << "-------------------------------------" << endl;
    cout << "| " << setw(10) << "g" << " | " << setw(20) << "z" << " |" << endl;
    cout << "-------------------------------------" << endl;

    double dz = (zk - zp) / n; 
    double g = zp;

    while (g <= zk)  
    {
        z = p(1 - g * g) + pow(p(1 + g - sqrt(p(g))), 2);  
        cout << "| " << setw(10) << g << " | " << setw(20) << z << " |" << endl;
        g += dz;  
    }
    cout << "-------------------------------------" << endl;
    return 0;
}

double p(const double x)
{
    if (abs(x) >= 1)  
        return (cos(sin(x)) + 1) / (exp(-x) + 1);  
    else
    {
        double S = 0;
        int j = 0;
        double a = 1;
        S = a;

        do  
        {
            j++;
            double R = -x * x / ((3 * j - 2) * (3 * j - 1) * 3 * j);  
            a *= R;
            S += a;
        } while (j < 4);

        return S;
    }
}