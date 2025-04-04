#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    double *apa = new(nothrow) double[922337203685477580];
    if (apa == NULL)
    {
        cout << "Memory allocation failed" << endl;
        return 1;
    }
    return 0;
}