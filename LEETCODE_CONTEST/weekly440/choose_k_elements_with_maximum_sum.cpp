#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

class Solution {
public:

//TIME LIMIT EXCEEDED
    vector<long long> findMaxSum(vector<int>& arr1, vector<int>& arr2, int k) {
        int n = arr1.size();
        vector<long long> ans(n);

        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0); //[0, 1, 2, 3, ...]
        //sort krenge according to arr1
        sort(indices.begin(), indices.end(), [&](int a, int b){
            return arr1[a] < arr1[b];
        });



        vector<pair<int, vector<int>>> pairs;

        for(int i=0; i<n; i++){
            int j = 0;
            vector<int> v;
            while(arr1[indices[j]] < arr1[i]){
                v.push_back(indices[j]);
                j++;
            }
            pairs.push_back({arr1[i], v});
        }

        // ab pairs ke vectors ko sort krna hai---descending order
        for(auto& x : pairs){
            sort(x.second.begin(), x.second.end(), [&](int a, int b){
                
                return arr2[a] > arr2[b];
            });
        }
        
        // ab har pair ke vectors mei se first k elements ka sum lenge aur ans vector mei store kr denge
        for(auto& x : pairs){
            int sum  = 0 ;
            for(int i=0 ; i<min(k, (int)x.second.size()); i++){
                sum += arr2[x.second[i]];
            }
            ans.push_back(sum);
        }

        return ans;
    }


//OPTIMAL APPROACH
//MIN-HEAP APPROACH

    vector<long long> findMaxSum_minheap(vector<int>& arr1, vector<int>& arr2, int k) {
        int n = arr1.size();
        vector<long long> ans(n);

        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0); //[0, 1, 2, 3, ...]
        //sort krenge according to arr1
        sort(indices.begin(), indices.end(), [&](int a, int b){
            return arr1[a] < arr1[b];
        });

        for(int i=1 ; i<n; i++){
            if(arr1[indices[i]] == arr1[indices[i-1]]){
                indices[i] = indices[i-1];
            }
        }



        priority_queue<long long, vector<long long>, greater<long long>> minHeap;

        int j = 0;
        long long sum = 0;

        for(long long i=0; i<n; i++){
            // long long j = 0;

            while(j < i){

                if(indices[j] == 0){
                    break;
                }
                
                minHeap.push(arr2[indices[j]]);
                sum += arr2[indices[j]];
                j++;
            }

            while(!minHeap.empty() && (int)minHeap.size() > k){
                sum -= minHeap.top();
                minHeap.pop();

            }
            ans[indices[i]] = sum;

        }

        return ans;
    }

    void print(vector<long long> &ans){
        for(auto x : ans){
            cout << x << " ";
        }
        cout << endl;
    }
};

int main(){

    vector<int> arr1 = {2,2,2,2};
    vector<int> arr2 = {3, 1, 2, 3};
    int k = 1;

    Solution sol = Solution();
    vector<long long> ans = sol.findMaxSum_minheap(arr1, arr2, k);

    sol.print(ans);

    return 0;
}