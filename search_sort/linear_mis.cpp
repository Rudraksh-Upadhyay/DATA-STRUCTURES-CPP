#include<iostream>
#include<vector>

using namespace std;

int main() {
	// your code goes here
	
	int n;
	cin >> n;
	
	
	
// 	pair<int, int> p[n];
    vector<pair<int, int>> p;
	
	
	for(int i=0; i<n; i++){
	        int u, v;
	        cin >> u >> v;
	        p.push_back({u,v});
	        p.push_back({v,u});
	}
	
	int k, l;
	cin >> k >> l;
	
	bool found = false;
	
	for(auto x : p){
	        if((k == x.first && l == x.second) || (k == x.second && l == x.first)){
	                found = true;
	        }
	}
	
	if(found){
	        cout << "Yes"<<endl;
	        
	}
	else{
	        cout << "No"<<endl;
	}
	
	return 0;

}
