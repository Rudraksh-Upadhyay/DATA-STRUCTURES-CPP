#include<bits/stdc++.h>

using namespace std;


class Solution{

    private:

    bool isPrime(int n){
        if(n <= 1){
            return false;
        }
        for(int i=2; i <= sqrt(n) + 1; i++){
            if(n % i == 0){
                return false;
            }
        }
        return true;
    }

    public:

    int nearestPrime(int num){
        if(isPrime(num)){
            return num;
        }

        ///lower aur higher prime dekhenge aur difference compare krenge
        int lower = num - 1;
        int higher = num + 1;

        while(lower >= 2 && !isPrime(lower)){
            lower--;
        }
        while(!isPrime(higher)){
            higher++;
        }

        int diff1 = abs(lower - num);
        int diff2 = abs(higher - num);

        if (diff1 < diff2){
            return lower;
        }
        else{
            return higher;
        }
    }
};


int main(){
    Solution sol = Solution();

    int num = 10;

    cout << sol.nearestPrime(num) << endl;


    return 0;
}