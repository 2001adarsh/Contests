#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl 	"\n"
const int N = 100005;
//Large factorials in C++.

void multiply(int *a, int &n, int no) {
	int carry = 0;
	for (int i = 0; i < n; i++) {
		int product = a[i] * no + carry;
		carry = product / 10;
		a[i] = product % 10;
	}
	while (carry) {
		a[n] = carry % 10;
		carry /= 10;
		n++;
	}
}

void factorial(int number) {
	int *a = new int[N];
	for (int i = 0; i < N; i++) {
		a[i] = 0;
	}
	a[0] = 1; // 1 X 2 X 3 X 4 X 5...
	int n = 1; // for current position in array.
	for (int i = 2; i <= number; i++) {
		multiply(a, n, i);
	}

	//printing in reverse order.
	for (int i = n - 1; i >= 0; i--) {
		cout << a[i];
	}
}

int32_t main()
{	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	factorial(5);

	return 0;
}