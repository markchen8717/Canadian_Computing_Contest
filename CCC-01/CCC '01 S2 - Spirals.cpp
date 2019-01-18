
#include <bits/stdc++.h>
#define obforall(i,a) for( const auto& i : a)
#define modforall(i,a) for (auto&& i : a)

using namespace std;

//given positive integers x and y
//output a list of numbers from x to y inclusive in a spiral
//end value is >= start value
//spiral starts with 1st number in the centre
//the next numbers appears immediately below the first number
//continue spiral with nubers increasing in a counter clowise direction
//starting at the centre of a 13x13 array (6x6)
//down 1 right 1 up 2 left 2 
//down 1+2 right 1+2 up 2+2 left 2+2
//down 3+2 right 3+2 up 4+2 left 4+2
//keep track of the length and width of the spiral and print it

int a, b,r1,r2,c1,c2,spiral[13][13],c,r;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	memset(spiral,-1,sizeof(spiral));
	cin >> a >> b;
	int ori = 0,dr=1,ul=2;
	r=r2=r1=6;
	c=c2=c1=6;
	spiral[r][c]=a;
	a++;
	while (a <= b)
	{
		if (ori == 0)//down
		{
			for(int i = 1 ; i <=dr && a<=b;i++)
			{
				r++;
				spiral[r][c]=a;
				a++;
			}
		}
		else if (ori==1)//right
		{
			for(int i = 1 ; i <=dr && a<=b;i++)
			{
				c++;
				spiral[r][c]=a;
				a++;
			}
		}
		else if (ori==2) //up
		{
			for(int i = 1 ; i <=ul && a<=b;i++)
			{
				r--;
				spiral[r][c]=a;
				a++;
			}
		}
		else if (ori==3)//left
		{
			for(int i = 1 ; i <=ul && a<=b;i++)
			{
				c--;
				spiral[r][c]=a;
				a++;
			}			
		}
		ori++;
		r1=min(r1,r); r2=max(r2,r);
		c1=min(c1,c); c2=max(c2,c);
		if (ori == 4)
		{
			dr += 2;
			ul += 2;
			ori = 0;
		}
	}
	for(int r = r1; r <= r2;r++)
	{
		for(int c = c1; c <=c2;c++)
		{	
			if(spiral[r][c] == -1)
				cout<<"  ";
			else
				cout<<spiral[r][c]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
