//https://codeforces.com/contest/2055/submission/300905124
//https://codeforces.com/blog/entry/106966
// void return type:
// 1.
function<void(int, int, int)> cal = [&](int a, int b, int c)->void {
	//------
	//------ [Body]
	//------
	return;
};
int x = 1, y = 8, z = 3;
cal(x, y, z);


// value return type:
// 1.
auto cal = [&](int a, int b, int c) {
	//Body.
	return (a + b) / c;
};
int x = 1, y = 8, z = 3;
cal(x, y, z);

// 2.
auto cal = [&](int a, int b, int c)->double {
	//Body.
	return (a + b) / c;
};
int x = 1, y = 8, z = 3;
cal(x, y, z);