#include <bits/stdc++.h>

using namespace std;

//output the number of distinct substrings of a string
//empty string and the string itself are considered substrings 
//insert all possible substrings starting at index i into a set
//store this count
//clear the set each time i changes

short N;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin>>N;
    string input;
    
    while(N--)
    {
       
        unordered_set <string> s;
        int size = 0;
        cin>>input;
        
        for (int j=0; j<=input.size(); j++) {
	for (int i=0; i+j<=input.size(); i++) {
		 s.insert(input.substr(i,j));
	}
	size+=s.size(); //store count and clear set to not exceed memory limit
	s.clear();
	

}
        
       
        
        
        
        
         
        cout<<size<<"\n";
        
    }
    return 0;
}
