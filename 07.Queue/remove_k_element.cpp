#include<iostream>
#include<queue>
#include<string>


using namespace std;

string removekdigits(string num, int k){
    // queue<char> q;

    while(k--){

        int size = num.length();
        char maxnum = '0';

        for(int i=0; i<size; i++){
            char ch = num[i];
            if(ch > maxnum){
                maxnum = max(maxnum, ch);
            }
        }

        auto it = num.find(maxnum);
        if(it != string::npos){
            num.erase(it, 1);
        }
    }

    return num;

}

int main(){
    

    string num = "90900";

    int k =2;

    cout << stoi(removekdigits(num, k)) <<endl;


    return 0;
}