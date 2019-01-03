
#include <bits/stdc++.h>

using namespace std;

//Q lines of text
//replace 2-digit years with 4 digit years
//any year numbered 24 or less is in the 2000s
//any year numbered 25 or more is in the 1900s
//eg. 16 == 2016 26 == 1926
//date formats
	//dd/mm/yy
	//yy.mm.dd
	//Month dd, yy
// dd is 2-digit day (01-31)
//mm is 2-digit month (01-12)
//yy is 2-digit year (00-99)
//Month is in in words eg "December"
//Dates should appear on a single line
//IGNORE 
	//dates traversing two lines
	//dates immediately adjacent to a letter or a digit



#define npos string::npos
#define sb(x,y) substr(x,y)
string input;

int toNum(string x)
{
	char a = x[0], b = x[1];
	if (a <= 57 && a >= 48 && b <= 57 && b >= 48)
	{
		if (a == 48)
			return b - 48;
		return stoi(x);
	}

	return -1;
}

bool notDA(char id) //not digit or letter if true
{
	if ((id >= 48 && id <= 57) || (id >= 65 && id <= 90) || (id >= 97 && id <= 122))
		return false;
	return true;
}

void check(size_t &a, size_t &b, char id)
{
	if (b != a + 3 || b + 2 >= input.length())
		return;
	int dd = (id == '/')? toNum(input.sb(a - 2, 2)) : toNum(input.sb(b + 1, 2));
	int mm = toNum(input.sb(b - 2, 2));
	int yy = (id == '/')? toNum(input.sb(b + 1, 2)) : toNum(input.sb(a - 2, 2));

	
	//check immediate adjacency
	
	bool front = (a - 3 != npos) ? (notDA(input[a - 3])) : true;
	bool back = (b + 3 <= input.length()-1) ? (notDA(input[b + 3])) : true;

	if (dd <= 31 && dd >= 1 && mm <= 12 && mm >= 1 && yy <= 99 && yy >= 0 && front && back)
	{
		string ystring = to_string(yy);
		ystring = (ystring.length() == 1) ? "0" + ystring : ystring;
		string ypre = (yy <= 24) ? "20" : "19";
		if (id == '/') 
		{
			input = input.sb(0, b + 1) + ypre + ystring + input.sb(b + 3, input.length() - b - 3);
		}
		else 
		{
			input = input.sb(0, a - 2) + ypre + ystring + input.sb(a, input.length() - a);
		}
		a = 0, b = 0;
	}
}
string M [] = { "January", "February", "March", "April", "May", "June", 
"July", "August", "September", "October", "November", "December"};
void check(size_t &a)
{
	if (a + 3 >= input.length())
		return;
	auto space = input.rfind(" ", a);
	if (space == npos || space + 3 != a)
		return;
	for (int i = 0; i < 12; i++) 
	{
		auto month = input.substr(0, space).rfind(M[i]);
		if (month != npos && month + M[i].length() == space)
		{
			int dd = toNum(input.sb(a - 2, 2));
			int yy = toNum(input.sb(a + 2, 2));
			bool front = (month - 1 != npos) ? (notDA(input[month-1])) : true;
			bool back = (a+4 <= input.length()-1) ? (notDA(input[a+4])) : true;

			if (dd <= 31 && dd >= 1 && yy <= 99 && yy >= 0 && front && back)
			{
				string ystring = to_string(yy);
				ystring = (ystring.length() == 1) ? "0" + ystring : ystring;
				string ypre = (yy <= 24) ? "20" : "19";
				input = input.sb(0, a + 2) + ypre + ystring + input.sb(a + 4, input.length() - a - 4);
				a = 0;
			}
			break;
		}
	}
}

int Q;
int main()
{
	cin >> Q;
	cin.ignore();
	
	while (Q--)
	{
		getline(cin, input);
		auto s1 = input.find("/");
		auto s2 = input.find("/", s1+1);
		auto p1 = input.find(".");
		auto p2 = input.find(".", p1+1);
		auto c1 = input.find(",");
		while ((s1 != npos && s2 != npos) || (p1 != npos && p2 != npos) || (c1 != npos))
		{
			if (s1 != npos && s2 != npos )
			{
				check(s1, s2,'/');
				
				
			}
			if (p1 != npos && p2 != npos )
			{
				check(p1, p2,'.');
				
			}
			if (c1 != npos)
			{
				check(c1);
				
			}
			
			s1 = input.find("/",s2+1);
			s2 = input.find("/", s1+1);
			p1 = input.find(".",p2+1);
			p2 = input.find(".", p1+1);
			c1 = input.find(",",c1+1);
		}
		cout << input << "\n";
	}

}

