#include <bits/stdc++.h>
//if a word has no vowel, itself is a syllable
//syllable of a world is a substring from last vowel to end
//vowels are a,e,i,o,u
//two lines rhyme if last syllables are same, ignoring case
//type of rhyme
	//perfect: four lines all rhyme
	//cross: 1st and 3rd lines rhyme, 2nd and 4th rhyme
	//even: 1st and 2nd lines rhyme, last two lines rhyme
	//shell: 1st and 4th, 2nd and thrd
	//free: neither previous form


using namespace std;

int verse;
string one,two,three,four;


bool rhyme (string a, string b)
{for(auto &c:b)
	c = tolower(c);
for(auto &c:a)
	c = tolower(c);

	int i1 = 0,i2 = 0;
	for(int i = a.length()-1 ; i >=0;i--)
	{if(a[i] == 'a' || a[i]=='e' || a[i]=='i' || a[i]=='o' || a[i]=='u') {i1 = i; break;}
		if(a[i] == ' ') {i1 = i+1 ;break;}}
for(int i = b.length()-1 ; i >=0;i--)
	{if(b[i] == 'a' || b[i]=='e' || b[i]=='i' || b[i]=='o' || b[i]=='u') {i2 = i; break;}
		if(b[i] == ' ') {i2 = i+1 ;break;}}
	
	//cout<<a.substr(i1)<<" "<<b.substr(i2)<<"\n";
	return a.substr(i1)==( b.substr(i2));

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>verse;
	cin.ignore();
	for(int i = 1; i <=verse;i++)
	{
		getline(cin,one);
		getline(cin,two);
		getline(cin,three);
		getline(cin,four);
		
		if(rhyme(one,two)&&rhyme(one,three)&&rhyme(one,four)&& rhyme(two,three)&&rhyme(two,four)&&rhyme(three,four) )
			{cout<<"perfect\n";}

      
		else if (rhyme(one,two) && rhyme(three,four))
		{cout<<"even\n";}
	else if (rhyme(one,three) && rhyme(two,four))
	{
		cout<<"cross\n";
	}
	else if (rhyme(one,four)&&rhyme(two,three))
	{cout<<"shell\n";}
else{cout<<"free\n";}
	}
	
	return 0;
}
