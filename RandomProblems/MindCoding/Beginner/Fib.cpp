/*** https://mindcoding.ro/pb/fib ***/

#include <iostream>

using namespace std;
int main()
{
    long long int x = 0, twoBefore = 1, oneBefore = 1, fibonacciValue = twoBefore + oneBefore, currentFibonacciNumber = 3;
    cin >> x;

    while (fibonacciValue < x) {
        twoBefore = oneBefore;
        oneBefore = fibonacciValue;
        fibonacciValue = twoBefore + oneBefore;
        currentFibonacciNumber++;
    }

    cout << currentFibonacciNumber - 1;

    return 0;
}