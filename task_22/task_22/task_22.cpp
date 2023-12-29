// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
#include <map>
#include <regex>

using namespace std;

int main()
{
    int n, k, sum;

    cin >> n >> k;

    int db[30] = {};
    db[0] = 1;
    db[1] = 1;
    sum = 2;

    for (int i = 2; i < n; i++) {
        if (i > k) {
            sum -= db[i - k - 1];
            db[i] = sum;
            sum += db[i];
        }
        else {
            db[i] = sum;
            sum += db[i];
        }
    }

    cout << db[n - 1];
}