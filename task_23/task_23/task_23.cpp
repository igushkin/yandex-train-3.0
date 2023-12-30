// task_23.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include <string>
#include <limits.h>
#include <vector>


int db[1000001];

int main()
{
	int n;
	vector<int> res;

	cin >> n;

	for (int i = 2; i <= n; i++) {
		db[i] =  INT_MAX;
	}

	for (int i = 1; i < n; i++) {
		if (i * 2 <= n)
			db[i * 2] = min(db[i] + 1, db[i * 2]);

		if (i * 3 <= n)
			db[i * 3] = min(db[i] + 1, db[i * 3]);

		db[i + 1] = min(db[i] + 1, db[i + 1]);
	}

	int el = n;

	while (el > 1) {
		res.push_back(el);

		int tmp = el - 1;

		if (el % 2 == 0 && db[el / 2] < db[tmp]) {
			tmp = el / 2;
		}
		if (el % 3 == 0 && db[el / 3] < db[tmp]) {
			tmp = el / 3;
		}

		if (db[el] == db[tmp]) {
			break;
		}

		el = tmp;
	}

	res.push_back(1);
	cout << db[n] << endl;
	cout << res[res.size() - 1];

	for (int i = res.size() - 2; i >= 0; i--) {
		cout << " " << res[i];
	}
}