#include <bits/stdc++.h>

using namespace std;
//sheeps are on a square 1000 by 1000
//coyotes enters any point on the field at the south boundary
    //proceeds to eat the closest sheep,pick randomly if 
    //more than one is equal
    //leaves feild after eating one sheep
//southwest corner at (0.00,0.00)
//northwest corner at (0.00,1000.00)
//northeast corner at (1000.00,1000.00)
//southeast corner at (1000.00,0.00)

//input are coordinates of sheeps
//output all the coordinates of the sheeps that might be eaten
//for every possible coyote spawn, find the closest sheeps


int N;
vector<pair<double,double>> sheep;

double dis(pair<double,double> sheep,double i)
{
    return sqrt(pow(sheep.first-i,2)+pow(sheep.second,2));
}

int main() {

    cin>>N;
    while(N--)
    {
        double x,y;
        cin>>x>>y;
        sheep.push_back({x,y});
    }
    set<pair<double,double>>output;
    for(double i = 0 ; i <=1000;i+=0.01)
    {
        double min = 0x3f3f3f3f;
        vector<pair<double,double>> might;
        for(auto x: sheep)
        {
            if(dis(x,i) == min)
            {
                might.push_back(x);
            }
            else if (dis(x,i) < min)
            {
                might.clear();
                min = dis(x,i);
                might.push_back(x);
            }
        }
        for(auto x:might)
        {
            output.insert(x);
            //out<<"The sheep at ("<<x.first<<", "<<x.second<<") might be eaten.\n";
        }
    }
    for(auto x:output)
    {
        //remember to set precision
        cout << fixed << showpoint;
        cout<<setprecision(2);
        cout<<"The sheep at ("<<x.first<<", "<<x.second<<") might be eaten.\n";
        
    }
    return 0;
}
