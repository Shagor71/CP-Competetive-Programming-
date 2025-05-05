#include <bits/stdc++.h>
using namespace std;

double func(double x) {
	return x * x * x - x * x + 2;
}
double derivFunc(double x) {
	return 3 * x * x - 2 * x;
}
void newtonRaphson(double x) {
	double h = func(x) / derivFunc(x);
	int iteration = 20;
	while (iteration--) {
		h = func(x) / derivFunc(x);
		x = x - h;
	}
	cout << fixed << setprecision(4) << "The value of the root is : " << x;
}
int main() {

	double x;
	cin >> x;

	newtonRaphson(x);

	return 0;
}