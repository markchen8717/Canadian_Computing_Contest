#include <bits/stdc++.h>

//a nasty positive integer has at least two pairs of +integer factors
//such that the difference of one pair queals the sum of another
//example 6:  6*1=6,2*3=6,6-1=2+3

//Q querries to test nasty
//for n in Q, n < 32001
//output:
	//n is nasty
	//or
	//n is not nasty
	
using namespace std;

struct F{
	short sum;
	short dif;
};

short Q,N;


bool nasty ()
{
  vector<F> factors;//make sure this is inside the function, so its fresh and new for every num
	for(int i = 1; i <= sqrt(N); i++)
	{
		if(N%i==0)
		{
			F f;
			f.sum = i+N/i;
			f.dif = abs(i-N/i);
			
			for(auto x: factors)
			{
       //cout<<int(x.sum)<<" "<<int(x.dif)<<"\n";
				if(x.sum == f.dif || x.dif == f.sum)
					return true;
			}
			factors.push_back(f);
		}
	}
	return false;
}

int main() {
	cin>>Q;
	while(Q--)
	{
		cin>>N;
		if(nasty())
			cout<<N<<" is nasty\n";
		else
			cout<<N<<" is not nasty\n";
	}
	return 0;
}
