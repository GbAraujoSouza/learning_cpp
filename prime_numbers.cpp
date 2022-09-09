#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

bool isPrimeNumber(int number);

int main()
{
    time_t start, end;

    int max_number = 1000000;
    time(&start);

    for (int i = 0; i < max_number; i++)
    {
        bool isPrimeFlag = isPrimeNumber(i);
        if (isPrimeFlag)
            cout << i << " is a prime number!\n";
    }

    time(&end);

    double execution_time = double(end - start);
    cout << "\n execution time: " << fixed << execution_time << setprecision(5) << " sec" << endl;

    system("pause>0");
    return 0;


}

bool isPrimeNumber(int number)
{
    if (number == 2) {
        return true;
    }
    if (number % 2 == 0)
    {
        return false;
    }

    int raiz = sqrt(number);
    for (int i = 3; i < number; i+=2)
    {
        if (number % i == 0)
            return false;
    }
    return true;
}