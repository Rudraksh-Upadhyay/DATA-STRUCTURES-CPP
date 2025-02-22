#include<iostream>
#include<vector>

using namespace std;

int main(){

    int rows , cols; 
	cin>> rows >> cols;
	
	vector<vector<int>> matrix(rows, vector<int>(cols));
	
	for(int i=0; i<rows; i++){
	        for(int j=0;j<cols;j++){
	                
	                cin>> matrix[i][j];
	        }
	}
	
	int i = 0;
	int j = 0;
	int sum = matrix[i][j];
	
	while(i < rows - 1 && j < cols - 1){
	        int n = min(matrix[i][j+1] , matrix[i+1][j]);
	        if( j < cols-1 && n==matrix[i][j+1]){
                    cout << "n = " << n <<endl;
	                j++;
	        }
	        else if( i < rows-1 && n==matrix[i+1][j]){
                    cout << "n = " << n <<endl;
	                i++;
	        }
	        sum += n;
	}

    while(i < rows-1){
        i++;
        cout << "n = " << matrix[i][j] <<endl;
        sum += matrix[i][j];
    }

    while(j < cols-1){
        j++;
        cout << "n = " << matrix[i][j] <<endl;
        sum += matrix[i][j];
    }
	
	cout << sum <<endl;


    return 0;
}