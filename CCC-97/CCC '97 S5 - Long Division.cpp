 
#include <iostream>
#include <bits/stdc++.h>

//Q querries
//for each query, given two numbers, each up to 80 digits, output quotient and remainder 
//seperate querries with empty line

//store each digits from the input numbers inside arrays
//starting with 0 padding from the left, repeatedly subtract both numbers until negative different while counting successions

//shift bottom number(divisor) to the right, increase padding
//repeat subtraction untill top number(remainder) is less than the divisor

//each count from changing padding is the digits of the quotient

using namespace std;

int Q,rlen,dlen;
int remainder_[80];
int divisor[80];
int newRemainder[80];



int successDiv(int pad)
{
	int cnt = 0;
	for (int i = 0; i < 80; i++)
		newRemainder[i] = remainder_[i];

	while (true)
	{
		
		for (int i = 79; i >= 0 + pad; i--)
		{
			if (newRemainder[i] < divisor[i - pad] && i - 1 >= 0)
			{
				newRemainder[i - 1]--;
				newRemainder[i] += 10;
			}
			newRemainder[i] -= divisor[i - pad];
		}
		for (int i = 0; i < 80; i++) {
			if (newRemainder[i] < 0)
				return cnt;
		}
		cnt++;
		for (int i = 0; i < 80; i++)
			remainder_[i] = newRemainder[i];
		
	}
}

bool stillBigger(int pad)
{
	int cnt = 0;
	for (int i = 0; i < 80; i++) {
		if (!remainder_[i]) {
			cnt++;
			continue;
		}
		break;
	}
	int nrlen = rlen - cnt;
	if ((nrlen == dlen && remainder_[cnt] > divisor[0]) || nrlen > dlen)
		return true;

	else if (cnt==80 && rlen - pad > 0 && dlen+pad <= rlen)
		return true;
	return false;
}

int main() {
	cin >> Q;
	while (Q--)
	{
		memset(remainder_, 0, sizeof(remainder_));
		memset(divisor, 0, sizeof(divisor));
		memset(newRemainder, 0, sizeof(newRemainder));
		string r, d, quot,rem;
		cin >> r >> d;
		rlen = r.length();
		dlen = d.length();
		int pad = 0;
		for (int i = 0; i < rlen; i++)
			remainder_[i] = r[i] - 48;
		for (int i = 0; i < dlen; i++)
			divisor[i] = d[i] - 48;

		if (!stillBigger(pad)) //dividened < divisor
		{
			cout << 0 << "\n";
			cout << r << "\n\n";
			continue;
		}
		while (stillBigger(pad))
		{
			int tmp = successDiv(pad);
			quot += (!quot.length() && !tmp) ? "" : to_string(tmp); //neglect leading zeros
			pad++;
		}

		cout<<quot<< "\n";
		bool firstD = false;
		for (int i = 0; i < 80; i++)
		{
			if (!firstD && !remainder_[i])
				continue;
			rem += to_string(remainder_[i]);
		}
		rem = (!rem.length())? to_string(0) : rem; //may have no remainder
		cout << rem<<"\n\n";

	}
	return 0;
}
