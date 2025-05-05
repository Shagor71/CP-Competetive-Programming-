#include <bits/stdc++.h>
using namespace std;

double f(double x) {
	return x * x * x - x * x + 2.0;
}
void bisection(double a, double b) {
	if (f(a) * f(b) >= 0) {
		cout << fixed << setprecision(5) << "iteration = 0, f(" << a << ") = " << f(a) << ", f(" << b << ") = " << f(b) << '\n';
		cout << "You have not assumed right a and b\n";
		return;
	}

	double c = a;
	int iteration = 7, itr = 1;
	while (iteration--) {
		c = (a + b) / 2;
		cout << fixed << setprecision(5) << "iteration = " << itr++ << ' ' << ", f(" << a << ") = " << f(a) << ", f(" << b << ") = " << f(b) << ", f(" << c << ") = " << f(c) << '\n';
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
	cout << "a = " << a << ", b = " << b << '\n';
	bisection(a, b);

	return 0;
}