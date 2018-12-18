#include <bits/stdc++.h>

//f(x) recursively prints the series of numbers formed as a digit is deleted and subtracted
	//if current number has more than two digits
	//delete last digit, subtract last digit from shortened number to form new number
	//neglect leading zeros
	//if resulting number is divisible by 11, so is the original number
//output message in main function, divisible as long as original number is
//since numbers can have up to 50 digits, use a vector of shorts to represent each digit


using namespace std;

vector<short> num;

void delete_n_subtract()
{
	if (!num[0])
		num.erase(num.begin());//remove leading zero
	for (short i = 0; i < num.size(); i++) //print current number
		cout << num[i];
	cout << "\n";
	if (num.size() > 2)
	{
		short unit = num[num.size() - 1];
		num.erase(num.begin() + num.size() - 1);
		for (short i = num.size() - 1; i >= 0; i--) //go from right to left, burrow if needed
		{
			if (num[i] < unit)
				num[i] = num[i] + 10, num[i - 1]--;
			num[i] -= unit;
			unit = 0;
		}
		delete_n_subtract();
	}	
	else
		return;
}

bool f(string x)
{
	num = vector<short>();
	for (short i = 0; i < x.length(); i++) //fill vector with digits
		num.push_back(x[i] - 48);
	delete_n_subtract();
	if (num.size() == 2 && (num[0] * 10 + num[1]) % 11 == 0)
		return true;
	else
		return false;
}

int N;
int main() {
	cin >> N;
	while (N--)
	{
		string x;
		cin >> x;
		if (f(x))
			cout << "The number " << x << " is divisible by 11.\n";
		else
			cout << "The number " << x << " is not divisible by 11.\n";
	}
	return 0;
}
