#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:

    int solve(vector<int>&coins, int amount){
        //base case
        if(amount == 0){
            return 0;
        }

        //if amount < 0 hua toh

        int minCoinAns = INT_MAX;   

        //hr amount ke liye poore coins k array ko traverse krna hai
        for(int i=0; i<coins.size(); i++){
            int amt = amount ;
            int coin = coins[i];
            //if coin value > amount....no need to call recursion

            //if coin value <= amount ...call recursion
            if(coin <= amount){
                //1 coin toh yaha use ho gaya...amount - coinvalue

                //baki recurrsion
                int recurAns = solve(coins, amount-coin);

                //ho sakta hai ki recurAns invalid ho
                //invalid means-> recurAns = INT_MAX;
                //valid case-> recurAns != INT_MAX;

                if(recurAns != INT_MAX){
                    int coinsUsed = 1 + recurAns;  
                    //kya above ans mininum hai?
                    minCoinAns = min(minCoinAns, coinsUsed);
                }
                
            }
        }
        if(minCoinAns == INT_MAX){
            return -1;
        }
        return minCoinAns;
    }

    int coinChange(vector<int>&coins, int amount){
        return solve(coins, amount);
    }
};

int main(){

    Solution sol = Solution();

    vector<int> coins = {1, 2, 5};
    int amount = 11;

    cout << sol.coinChange(coins, amount);

    return 0;
}