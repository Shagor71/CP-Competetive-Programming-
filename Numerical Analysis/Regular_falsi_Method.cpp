#include <bits/stdc++.h>
using namespace std;

double func(double x) {
	return x * x * x - x * x + 2;
}
void regulaFalsi(double a, double b) {
	if (func(a) * func(b) >= 0) {
		cout << "You have not assumed right a and b\n";
		return;
	}
	double c = a;
	int iteration = 20;
	for (int i = 0; i <= iteration; i++) {
		c = (a * func(b) - b * func(a)) / (func(b) - func(a));
		if (func(c) == 0) break;
		else func(c)*func(a) < 0 ? b = c : a = c;
	}
	cout << "The value of root is : " << c;
}
int main() {
	double a, b;
	cin >> a >> b;

	regulaFalsi(a, b);

	return 0;
}