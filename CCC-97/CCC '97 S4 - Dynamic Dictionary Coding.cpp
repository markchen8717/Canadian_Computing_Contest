#include <iostream>
#include <bits/stdc++.h>

//compress N sets of texts, sets are separated by a blank line
//each set consists of several lines, may include spaces
//use a map to store unique words and their ordering
//from start to end, replace each reoccurence of unique words with its position number 


using namespace std;

int main() {
  int N;
  cin>>N;
  cin.ignore();
while(N--)
{
string input;
map<string,int> dic;

int cnt = 1;
do
{    
 getline(cin,input);
istringstream iss(input);
vector<string> results((istream_iterator<string>(iss)),
                                 istream_iterator<string>());

    for ( auto x : results)
    {
      if(dic.count(x))
        cout<<dic[x]<<" ";
      else
      {
        dic[x] = cnt;
        cnt++;
        cout<<x<<" ";
      }

    }
    cout<<"\n";
  }while(!input.empty());//set is done, separeted by empty line
  
   cout<<"\n";
   
  
}

  return 0;
  
}
