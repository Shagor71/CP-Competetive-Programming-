#include <bits/stdc++.h>
using namespace std;

double f(double x) {
	return x * x * x - x * x + 2.0;
}
void bisection(double a, double b) {
	if (f(a) * f(b) >= 0) {
		cout << "You have not assumed right a and b\n";
		return;
	}

	double c = a;
	int iteration = 20;
	while (iteration--) {
		c = (a + b) / 2;

		if (f(c) == 0.0) break;
		else
			f(c)*f(a) < 0 ? b = c : a = c;
	}
	cout << "The value of root is : " << c;
	return;
}
int main() {

	double a, b;
	cin >> a >> b;

	bisection(a, b);

	return 0;
}