#include <bits/stdc++.h>

using namespace std;

#define obforall(i,a) for( const auto& i : a)
#define modforall(i,a) for (auto&& i : a)

#define xc .first
#define yc .second


//given coordinates of chips, find the diameter of the smallest round cookie
	//conatining all the chips
//n lines of input
	//each contains one coordinate of a chip
	//each coordinate is an integer 0-1000 inclusive
//output a single real number diameter
//find equations of all unique circles defined by three NON-COLINEAR points 
//also equations circles with two points and their distance as diameter
	//check all points using the equation to see if the radius is within half
	// of the proposed diameter

pair<double, double> centre3(pair<double, double>	*arr)//returns the centre of the circle with 3 NON-COLINEAR
{
	pair<double, double> mid1 = { (arr[0]xc + arr[1]xc) / 2,(arr[0]yc + arr[1]yc) / 2 };
	pair<double, double> mid2 = { (arr[0]xc + arr[2]xc) / 2,(arr[0]yc + arr[2]yc) / 2 };


	double m1 = -((arr[0]xc - arr[1]xc) / (arr[0]yc - arr[1]yc));
	double m2 = -((arr[0]xc - arr[2]xc) / (arr[0]yc - arr[2]yc));

	double b1 = -m1 * mid1 xc + mid1 yc;
	double b2 = -m2 * mid2 xc + mid2 yc;

	double x, y;

	if (m1 == INFINITY || m1 == -INFINITY)
	{
		x=mid1 xc,
		y=m2*x+b2;
	}
	else if (m2 == INFINITY || m2 == -INFINITY)
	{
		x = mid2 xc;
		y = m1 * x + b1;
	}
	else
	{
		x = (b2 - b1) / (m1 - m2);
		y = m1 * x + b1;
	}
	
	return { x,y };
}

pair<double, double> centre2(pair<double, double> *arr)//returns the centre of the circle with distance of 2 points as diameter
{
	double x = (arr[0]xc + arr[1]xc) / 2;
	double y = (arr[0]yc + arr[1]yc) / 2;
	return { x,y };
}

bool collinear(pair<double, double>	*arr)
{
	double k = -((arr[0]xc - arr[1]xc) / (arr[0]xc - arr[2]xc));
	return k * (arr[0]yc - arr[2]yc) == (arr[0]yc - arr[1]yc);
}

double dis(pair<double, double> a, pair<double, double> b)
{
	double one = pow(a xc - b xc, 2);
	double two = pow(a yc - b yc, 2);
	return sqrt(one+two );
}
vector<pair<double, double>> points;
double rad = 0x3f3f3f3f;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	while (n--)
	{
		double x, y;
		cin >> x >> y;
		points.push_back({ x,y });
	}
	vector<int>bitset;
	//3 points
	for (int i = 1; i <= points.size() - 3; i++)
		bitset.push_back(0);
	for (int i = 1; i <= 3; i++)
		bitset.push_back(1);
	do {
		pair<double, double> arr[3];
		int i = 0;
		for (int j = 0; j < bitset.size(); j++)
		{
			if (bitset[j])
			{
				arr[i] = points[j];
				i++;
			}
		}
		if (collinear(arr))
			continue;
		auto centre = centre3(arr);
		double tmpRad = dis(centre, arr[0]);
		bool pass = true;
		for (auto x : points)
		{
			if (sqrt(pow(x xc - centre xc, 2) + pow(x yc - centre yc, 2)) > tmpRad)
			{
				pass = 0; break;
			}

		}
		if (pass)
			rad = min(rad, tmpRad);
	} while (next_permutation(bitset.begin(),bitset.end()));

	//two points
	bitset.clear();
	for (int i = 1; i <= points.size() - 2; i++)
		bitset.push_back(0);
	for (int i = 1; i <= 2; i++)
		bitset.push_back(1);
	do {
		pair<double, double> arr[2];
		int i = 0;
		for (int j = 0; j < bitset.size(); j++)
		{
			if (bitset[j])
			{
				arr[i] = points[j];
				i++;
			}
		}
		auto centre = centre2(arr);
		double tmpRad = dis(centre, arr[0]);
		bool pass = true;
		for (auto x : points)
		{
			if (sqrt(pow(x xc - centre xc, 2) + pow(x yc - centre yc, 2)) > tmpRad)
			{
				pass = 0; break;
			}

		}
		if (pass)
			rad = min(rad, tmpRad);
	} while (next_permutation(bitset.begin(),bitset.end()));
	rad *=2;
	rad = double(int(rad*100 + 0.5))/100;
	cout << fixed << showpoint << setprecision(2) << rad;
	return 0;
}
