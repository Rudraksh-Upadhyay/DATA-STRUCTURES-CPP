#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>


using namespace std;

int main(){

    int t;
    cin>> t;

    while(t--){
        int n, m, h;
        //cars, power outlet, hours
        cin >> n >> m >> h;

        //energy capacity
        vector<int> capacity(n);
        for(int i=0; i<n; i++){
            cin >> capacity[i];

        }

        sort(capacity.begin(), capacity.end(), greater<int>());

        //power in power outlet
        vector<int> powers(m);
        for(int i=0; i<m; i++){
            cin >> powers[i];
        }

        sort(powers.begin(), powers.end(), greater<int>());

        long int ans = 0;

        int size = min(n, m);

        for(int i=0 ; i<size; i++){
            // WE WILL USE 1LL = long long = prevent overfloww
            ans += min(1LL * powers[i] * h, 1LL * capacity[i]);
        }

        cout << ans <<endl;
    }

    return 0;
}