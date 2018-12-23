#include <bits/stdc++.h>
//n test cases
  //t number of teams
  //at the end of a round, one win and one lose
//last remaining team has one or fewer losses
//an undefeated team never plays a team with one loss
//as many team as possible are paired each round



using namespace std;

int Q;
int main()
{
  cin>>Q;
  while(Q--)
  {
    int roundNum, undefeated,oneloss,eliminated;
    cin>>undefeated;
    roundNum = 0;
    oneloss = 0;
    eliminated = 0;
    cout<<"Round "<<roundNum<<": "<<undefeated<<" undefeated, "<<oneloss<<" one-loss, "<<eliminated<<" eliminated\n";
    roundNum++;
    while(undefeated>=2 || oneloss >= 2)
    {
      eliminated+=oneloss/2;
      oneloss-=oneloss/2;
      oneloss+=undefeated/2;
      undefeated-=undefeated/2;
      cout<<"Round "<<roundNum<<": "<<undefeated<<" undefeated, "<<oneloss<<" one-loss, "<<eliminated<<" eliminated\n";
      roundNum++;
    }
    if(undefeated ==1 && oneloss == 1)
    {
      undefeated = 0;
      oneloss++;
      cout<<"Round "<<roundNum<<": "<<undefeated<<" undefeated, "<<oneloss<<" one-loss, "<<eliminated<<" eliminated\n";
      roundNum++;
      oneloss--;
      eliminated++;
      cout<<"Round "<<roundNum<<": "<<undefeated<<" undefeated, "<<oneloss<<" one-loss, "<<eliminated<<" eliminated\n";
      
    }
    
    cout<<"There are "<<roundNum<<" rounds.\n\n";

  }
  return 0;
}
