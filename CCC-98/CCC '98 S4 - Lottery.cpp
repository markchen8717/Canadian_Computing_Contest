
#include <bits/stdc++.h>

//insert brackets to n expressions and out them separated by an empty line each

//stringstream expressions into a stack

//repeatedly combine sub expressions untill base case where only one operator is left

//first, handle multiplications
//then, additions and subtractions

using namespace std;



stack<string> S,Q;

int N;



bool M()
{
  auto tmp = S;
  while(!tmp.empty())
  {
    if(tmp.top() == "X")
      return true;
    tmp.pop();
  }
  return false;
}
int main() {
  cin>>N;
  cin.ignore();
  while(N--)
  {
    string ex,tmp,left,op,right;
    
    getline(cin,ex);
    reverse(ex.begin(),ex.end());
    stringstream ss (ex);
    while(ss>>tmp)
      reverse(tmp.begin(),tmp.end()),S.push(tmp);
    while(!S.empty() && S.size() > 3)
    {
      
      if(M())
      {
        while(true)
        {
          string top = S.top();
          S.pop();
          if(top =="X")
          {
            string newTop = S.top();
            S.pop();
            S.push("(" + Q.top() +" "+top+ " "+ newTop+")");
            Q.pop();
            while(!Q.empty())
              S.push(Q.top()),Q.pop();
            break;
          }
          else
            Q.push(top);
        }
        
      }
      else 
      {
     
        while(true)
        {
          string top = S.top();
          S.pop();
          if(top =="+" || top == "-")
          {
            string newTop = S.top();
            S.pop();
            S.push("(" + Q.top() +" "+top+ " "+ newTop+")");
            Q.pop();
            while(!Q.empty())
              S.push(Q.top()),Q.pop();
            break;
          }
          else
            Q.push(top);
        }
      }
      
    }
    while(!S.empty())
    {
      cout<<S.top()<<" ";
      S.pop();
    }
    cout<<"\n\n";
  }
}
