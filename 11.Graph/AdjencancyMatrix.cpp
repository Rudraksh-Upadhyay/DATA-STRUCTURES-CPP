#include<iostream>

using namespace std;

int main(){

    int n, m;
    cout << "Enter the number of Nodes->";
    cin >> n;
    cout << "Enter the number of Edges->";
    cin >> m;

    int arr[n][n]; 

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            arr[i][j] = 0;
        }
    }

    for(int i=0; i<m ;i++){
        int u, v;
        cin >> u >> v;

        arr[u][v] = 1;
    }


    cout<<"Adjencancy Matrix->"<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}