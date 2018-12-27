
#include<bits/stdc++.h>

//output all the perfect numbers between 1000 and 9999 inclusive on one line
//followed by all integers between 100 and 999 whihc are equal to the sum of the cubes of their digits on one line


using namespace std;

bool perfect(int i)
{
	int sum = 0;
	for (int j = 1; j <= sqrt(i); j++)
	{
		if (i%j == 0)
		{
			sum += j;
			if (j*j != i && i/j < i)
				sum += i / j;
		}
	}
	return (sum == i);
}
bool cube(int i)
{
	
	int a, b, c,tmp;
	tmp = i;
	a = i % 10;
	i /= 10;
	b = i % 10;
	i /= 10;
	c = i;
	return (a*a*a + b*b * b + c*c * c == tmp);
}


int main()
{
	for (int i = 1000; i <= 9999; i++)
	{
		if (perfect(i))
			cout << i << " ";
	}
	cout << "\n";

	for (int i = 100; i <= 999; i++)
	{
		if (cube(i))
			cout << i << " ";
	}
	
}

