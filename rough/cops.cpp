#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int main(){
    
    int t;
    cin >> t;

    

    while(t--){
        vector<bool> safe(101, true);
        safe[0] = false;
        int m, x, y;
        //m = number houses occupied by cops
        //x = speed of cop
        //y = searching time

        cin >> m >> x >> y;

        //places where cops are present
        vector<int> cops(m);
        for(int i=0; i<m; i++){
            cin >> cops[i];
        }

        for(int i=0; i<m; i++){
            int a = cops[i];
            safe[a] = false;
        }

        //number of houses can be searched by a cop
        int maxHouses = x * y;

        while(m--){
            int a = cops[m];
            //left side
            for(int i=a-1, j=0; i>=0 && j<maxHouses; i--, j++){
                if(safe[i]){
                    safe[i] = false;
                }
            }
            //right side
            for(int i=a+1, j=0; i<=100 && j<maxHouses; i++, j++){
                if(safe[i]){
                    safe[i] = false;
                }
            }
        }

        int count = 0;
        for(int i=0; i<101; i++){
            if(safe[i]){
                count++;
            }
        }
        cout << count << endl;
    }


    return 0;
}