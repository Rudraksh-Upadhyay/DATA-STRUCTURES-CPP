#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){
        string s;
        cin>>s;

        int i =0;
        int n = s.length();

        for(int i=0; i<n; i++){
            if(s[i] == 'm'){
                if((i-1 >= 0 && s[i-1] == 's' )|| (i+1 <= n-1 && s[i+1] == 's')){
                    if(s[i-1] == 's'){
                        s[i-1] = 'e';

                    }
                    else{
                        s[i+1] = 'e';
                    }
                }
            }
        }

        int scount = 0;
        int mcount = 0;

        for(auto x : s){
            if(x == 's'){
                scount++;
            }
            else if(x == 'm'){
                mcount++;
            }

        }

        if(scount > mcount){
            cout << "snakes"<<endl;
        }
        else if (scount < mcount){
            cout << "mongooses"<<endl;
        }
        else{
            cout << "tie" <<endl;
        }

    }


    return 0;
}