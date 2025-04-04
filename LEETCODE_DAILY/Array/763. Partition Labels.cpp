#include<bits/stdc++.h>

using namespace std;

vector<int> partitionLabels(string s ){
    int n = s.length();

    vector<int> result;

    vector<int> mp(26, -1); // map ka bhi use kr sakte hai 
    for(int i=0; i<n; i++){
        int idx = s[i] - 'a';
        mp[idx] = i;  // 'i' is the last occurrence of the character 's[i]'
                      // toh s[i]..mp mei jaha hoga waha humne uske 's' mei last occurrence ka index store kr diya
    }

    int i = 0;
    while( i < n ){
        int end = mp[s[i] - 'a'];

        int j = i;
        while(j < end){
            end = max(end, mp[s[j] - 'a']);
            j++;
        }
        result.push_back(j - i + 1);
        i = j + 1;
    }

    return result;
}

int main(){

    string s = "ababcbacadefegdehijhklij";

    vector<int> result = partitionLabels(s);

    for(auto x : result)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}