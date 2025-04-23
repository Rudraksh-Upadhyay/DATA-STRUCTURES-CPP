// STRING

/*
Given a string expression representing an expression of fraction addition and subtraction, return the calculation result in string format.

The final result should be an irreducible fraction. If your final result is an integer, change it to the format of a fraction that has a denominator 1. So in this case, 2 should be converted to 2/1.

 

Example 1:

Input: expression = "-1/2+1/2"
Output: "0/1"
Example 2:

Input: expression = "-1/2+1/2+1/3"
Output: "1/3"
Example 3:

Input: expression = "1/3-1/2"
Output: "-1/6"
 
*/


#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
    string fractionSolution(string expr){
        int nume = 0;
        int deno = 1;

        int i =0; 
        int n = expr.length();


        while(i < n){
            int currNume = 0;
            int currDeno = 0;

            bool isNeg = (expr[i] == '-');


            if(expr[i] == '+' || expr[i] == '-'){
                i++; //skipping 
            }

            //building numerator
            while(i < n && isdigit(expr[i])){
                int val = expr[i] - '0';
                currNume = (currNume * 10) + val;
                i++;
            }

            i++ ;//skipping '/'

            if(isNeg == true){
                currNume *= -1;
            }


            //building denominator
            while(i < n && isdigit(expr[i])){
                int val = expr[i] - '0';
                currDeno = (currDeno * 10) + val;
                i++;
            }

            //update final numerator and denominator
            nume = nume * currDeno + currNume * deno;
            deno = deno * currDeno;

        }

        //GCD CHECK
        int GCD = abs(__gcd(nume, deno));
        nume /= GCD;
        deno /= GCD;

        return to_string(nume) + "/" + to_string(deno);
    }
};

int main(){

    string expr = "-1/2+1/2";
    Solution sol = Solution();

    cout << sol.fractionSolution(expr) << endl;

    return 0;
}