#include <stdio.h>
#include <math.h>

int armstrong(int x) {
	int sum = 0, tmp = x;
	while (x) {
		int dgt = x % 10;
		sum += dgt * dgt * dgt;
		x /= 10;
	}
	return sum == tmp;
}
int main() {
	int x;
	scanf("%d", &x);

	if (armstrong(x))
		printf("Armstrong");
	else
		printf("No");
}