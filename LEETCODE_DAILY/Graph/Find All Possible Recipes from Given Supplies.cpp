// MEDIUM 

// LEETCODE 2115

/*
You have information about n different recipes. You are given a string array recipes and a 2D string array ingredients. The ith recipe has the name recipes[i], and you can create it if you have all the needed ingredients from ingredients[i]. A recipe can also be an ingredient for other recipes, i.e., ingredients[i] may contain a string that is in recipes.

You are also given a string array supplies containing all the ingredients that you initially have, and you have an infinite supply of all of them.

Return a list of all the recipes that you can create. You may return the answer in any order.

Note that two recipes may contain each other in their ingredients.


Example 1:

Input: recipes = ["bread"], ingredients = [["yeast","flour"]], supplies = ["yeast","flour","corn"]
Output: ["bread"]
Explanation:
We can create "bread" since we have the ingredients "yeast" and "flour".
Example 2:

Input: recipes = ["bread","sandwich"], ingredients = [["yeast","flour"],["bread","meat"]], supplies = ["yeast","flour","meat"]
Output: ["bread","sandwich"]
Explanation:
We can create "bread" since we have the ingredients "yeast" and "flour".
We can create "sandwich" since we have the ingredient "meat" and can create the ingredient "bread".
Example 3:

Input: recipes = ["bread","sandwich","burger"], ingredients = [["yeast","flour"],["bread","meat"],["sandwich","meat","bread"]], supplies = ["yeast","flour","meat"]
Output: ["bread","sandwich","burger"]
Explanation:
We can create "bread" since we have the ingredients "yeast" and "flour".
We can create "sandwich" since we have the ingredient "meat" and can create the ingredient "bread".
We can create "burger" since we have the ingredient "meat" and can create the ingredients "bread" and "sandwich".
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    private:

    public:

//acceptable hai in leetcode
    vector<string> findAllRecipes_bruteForce(vector<string> &recipes, vector<vector<string>> &ingredients, vector<string> & supplies){
        int n = recipes.size();
        vector<string> result;

        unordered_set<string> st(begin(supplies), end(supplies));

        vector<bool> cooked(n, false);

        int count = n;

        while(count--){
            for(int j = 0; j < n ; j++){
                if(cooked[j] == true){
                    continue;
                }
                //else case
                bool canCook = true;
                int size = ingredients[j].size();
                for(int k = 0 ; k < size; k++){
                    if(!st.count(ingredients[j][k])){
                        canCook = false;
                        break;
                    }
                }
                if(canCook){
                    st.insert(recipes[j]);
                    cooked[j] = true;
                    result.push_back(recipes[j]);
                }
            }
        }

        return result;
    }

//optimal solution -> GRAPH
    vector<string> findAllRecipes_optimal(vector<string> &recipes, vector<vector<string>> &ingredients, vector<string> &supplies){
        int n = recipes.size();

        unordered_set<string> st(begin(supplies), end(supplies));

        //adjancency list
        unordered_map<string, vector<int>> adj; // ingredients ---> recipe ka index

        vector<int> indegree(n, 0);

        for(int i=0; i<n; i++){
            for(string &ingredient : ingredients[i]){
                if(!st.count(ingredient)){
                    adj[ingredient].push_back(i); //means...yeh wala recipe dependent hai iss ingredient mei
                    indegree[i]++;
                }
            }
        }

        //kann's algo
        queue<int> que;
        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                que.push(i);  // means recipes jo kisi pr bhi dependent nahi hai
            }
        }

        vector<string > result;
        while(!que.empty()){
            int i = que.front();
            que.pop();
            string recipe = recipes[i];
            result.push_back(recipe);

            //phir...neighbour mei traverse krenge
            for(auto &idx : adj[recipe]){
                indegree[idx]--;
                if(indegree[idx] == 0){
                    que.push(idx);
                }
            }
        }

        return result;

    }
};

int main(){

    /*
    Input: recipes = ["bread"], ingredients = [["yeast","flour"]], supplies = ["yeast","flour","corn"]
    */
    
    // vector<string> recipes = {"bread"};
    // vector<vector<string>> ingredients = {{"yeast","flour"}};
    // vector<string> supplies = {"yeast","flour","corn"};

    /*
    Input: recipes = ["bread","sandwich","burger"], ingredients = [["yeast","flour"],["bread","meat"],["sandwich","meat","bread"]], supplies = ["yeast","flour","meat"]
    
    */

    vector<string> recipes = {"bread","sandwich","burger"};
    vector<vector<string>> ingredients = {{"yeast", "flour"}, {"bread", "meat"}, {"sandwich", "meat", "bread"}};
    vector<string> supplies = {"yeast", "flour", "meat"};

    Solution sol = Solution();
    vector<string> ans = sol.findAllRecipes_bruteForce(recipes, ingredients, supplies);

    for(auto &x: ans){
        cout << x << " " ;
    }
    cout << endl;

    return 0;
}