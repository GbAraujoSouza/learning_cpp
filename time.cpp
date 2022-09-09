#include <iostream>
using namespace std;

int main()
{
    time_t start;

    time(&start);

    cout << start << endl;

    return 0;
}