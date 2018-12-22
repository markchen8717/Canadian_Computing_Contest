#include <iostream>

//three array of strings
//print all nested combinations of strings in order starting with the first array
//each line of string input may contain spaces


using namespace std;

int Q,A,B,C;
string a[20],b[20],c[20];


int main() {
	cin>>Q;
	while(Q--)
	{
		cin>>A>>B>>C;
		cin.ignore(); //use this before getline if you have previous used cin
		for(int i = 0 ; i <A;i++)
			getline(cin,a[i]);
		for(int i = 0 ; i <B;i++)
			getline(cin,b[i]);
		for(int i = 0 ; i <C;i++)
			getline(cin,c[i]);
		for(int i = 0 ; i <A;i++)
			for(int j = 0 ; j <B;j++)
				for(int k = 0 ; k <C;k++)
					cout<<a[i]<<" "<<b[j]<<" "<<c[k]<<".\n";
		cout<<"\n";
	}
	return 0;
}
