#include<iostream>

using namespace std;

class Solution{
    public:

//yeh count of palindromic substring return krega
//using 'i' and 'j' as center and expanding around it in every iteration
    int expandAroundCenter(string s, int i, int j){

        int count = 0;

        while(i >= 0 && j < s.length() && s[i] == s[j]){
            count++;
            i--;
            j++;
        }

        return count;

    }

    int countSubstrings(string s){
        int totalCount = 0;
        for(int center = 0; center < s.length(); center++){
            //odd
            int i = center;
            int j = center;

            int oddPalSubstringKaCount = expandAroundCenter(s, i, j);
            // evev

            i = center;
            j = center +1;

            int evenPalSubstringKaCount = expandAroundCenter(s, i, j);

            totalCount = totalCount + oddPalSubstringKaCount + evenPalSubstringKaCount;
        }
        return totalCount;
    }
};

int main(){

    return 0;
}