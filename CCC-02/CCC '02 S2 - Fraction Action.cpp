
#include <bits/stdc++.h>



using namespace std;
//given a positive fraction
//rewrite it in lowest terms
//numerator must be less than denominator
//find gcf of both numbers
//divide numerator and denominator by gcf
//find coefficient


#define obforall(i,a) for( const auto& i : a)
#define modforall(i,a) for (auto&& i : a)

#define xc .first
#define yc .second


int n, d, c;


int gcf(int a,int b)
{
	int output = 1;
	int c = min(a, b);
		for (int i = 1; i <= c; i++)
		{
			if (a%i == 0 && b%i == 0 && a >= i && b >= i)
			{
				output = max(output, i);
			}
			else if (!(a >= i || b >= i))
				break;
	}
		return output;
	
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> d;
	int g = gcf(n, d);
	n /= g;
	d /= g;
	c = n / d;
	if (c)
		cout << c;
	if (c*d == n)
		return 0;
	cout << " "<<n - c * d << '/' << d;
	return 0;
}
