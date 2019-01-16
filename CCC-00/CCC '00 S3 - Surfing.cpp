#include <iostream>
#include<bits/stdc++.h>
//Given a site url and the site html 
//Print out the site url and urls that the site refer to
//Use a map to store each site, and sites it refer to
//Goal is to see if you can get from one site to another
//Do BFS on the starting site


using namespace std;

int N;
map <string,pair<int,vector< string > > > decode;

void bfs( vector< int > &dis, string start)
{
  queue<string> q;
  q.push(start);
  dis[decode[start].first] = 0;
  while(!q.empty())
  {
    auto top = q.front();
    q.pop();
    for(auto x : decode[top].second)
    {
      if(dis[decode[x].first] == -1)
      {
        q.push(x);
        dis[decode[x].first]  = dis[decode[top].first]+1;
      }

    }
  }
}


int main() {
  cin>>N;
  string line;
  string key = "<A HREF=\"";
  //cin.ignore();
  int cnt =0;
  
  while(N--){
    cin>>line;
    string page = line;
    if(!decode.count(line))
    {
      decode[line].first = cnt;
      cnt++;
    }
    cin.ignore();
    getline(cin,line);
   
  
    while(line != "</HTML>")
    {
      auto found = line.find(key);
    
     
      while(found!=std::string::npos)
      {
        auto end = line.find("\">",found+1);
        found+=9;
        
        string link = line.substr(found,end-found);
        
        if(!decode.count(link))
        {
          decode[link].first = cnt;
          cnt++;
        }

        decode[page].second.push_back(link);
        cout<<"Link from " +page+" to " + link+"\n";

        found = line.find(key,found+1);

      }
      
      getline(cin,line);
    }
  }
getline(cin,line);

cout<<"\n";

  while(line!="The End")
{
  if(line == "The End")
    break;
  string b;
  cin>>b;
  vector< int  > dis (decode.size(), -1);
  
  bfs(dis,line);
  if(dis[decode[b].first] != -1)
  {
    cout<<"Can surf from " + line + " to "+ b+".\n";
  }
  else
  {
    cout<<"Can't surf from " + line + " to "+ b+".\n";
  }
  cin.ignore();
  getline(cin,line);
  
  
}





}
