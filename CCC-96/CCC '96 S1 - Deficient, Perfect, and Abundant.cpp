#include <bits/stdc++.h>

//f(x) returns the sum of x's factors not including x
// if f(x) < x, x is defficient
//	if f(x) == x, x is perfect
// if f(x) > x, ix is abundant

using namespace std;

int f(int x)
{
	int sum = 0;
	for (int i = 1; i <= x - 1; i++) { //all factors not including x
			if (x%i == 0)
				sum += i;
		}
	return sum;
}

int N;
int main() {
	cin >> N;
	while (N--)
	{
		int in;
		cin >> in;
		int sum = f(in);
		if (sum == in)
			cout << in << " is a perfect number.";  //check spelling & spaces !
		else if (sum < in)
			cout << in << " is a deficient number.";
		else
			cout << in << " is an abundant number.";
		if(N)
			cout << "\n";
	}
	return 0;
}
