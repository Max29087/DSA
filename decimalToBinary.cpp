#include <iostream>
using namespace std;
int decToBin(int decimalNum)
{
    int ans = 0;
    int pow = 1;
    while (decimalNum > 0)
    {
        int remainder = decimalNum % 2;
        decimalNum /= 2;
        ans += remainder * pow;
        pow *= 10;
    }
    return ans;
}

int main()
{
    int number;
    cout << "\nEnter a decimal Number: ";
    cin >> number;
    cout << "\nBinary Number: " << decToBin(number) << "\n\n";
    return 0;
}