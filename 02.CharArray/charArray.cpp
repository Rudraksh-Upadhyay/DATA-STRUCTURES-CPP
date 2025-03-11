#include<iostream>

using namespace std;

int getLength(char arr[]){
    int count = 0;
    int index = 0;
    
    while(arr[index] != '\0'){
        count++;
        index++;
    }
    return count;
}


void convertToUpperCase(char arr[]){
    int len = getLength(arr);
    for(int i=0; i<len; i++){
        char ch = arr[i];
        //chech kro
        //agar ch ek lowercase character hai then only usko uppercase mei convert kro
        if(ch>='a' && ch<='z'){

            ch = ch-'a'+'A';
            arr[i] = ch;
        }
    }
}


void convertToLowerCase(char arr[]){
    int len = getLength(arr);
    for(int i=0; i<len; i++){
        char ch = arr[i];
        //chech kro
        //agar ch ek upprcase character hai then only usko lower mei convert kro
        if(ch>='A' && ch<='Z'){

            ch = ch-'A'+'a';
            arr[i] = ch;
        }
    }
}


void reverseCharArray(char arr[]){
    int len = getLength(arr);
    int i = 0;
    int j = len-1;

    while(i<=j){
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}


bool checkPalindrome(char arr[]){
    // char initial[100];

    int n = getLength(arr);
    int i =0;
    int j= n-1;

    while(i<=j){
        if(arr[i] != arr[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}



int main(){
    char name[100];
    cout << "enter your name->";
    cin >> name;

    // cin.getline(name, 100, '\t');


    // cout << name <<endl;
    // cout << name[0] <<endl;
    // cout <<name[1] <<endl;
    // cout <<name[2] << endl;
    // cout << name[3] << endl;
    // cout <<name[4] <<endl;

    // convertToUpperCase(name);

    // reverseCharArray(name);


    // cout << endl << "input->" << endl << name<<endl;

    cout << endl << "palindrome->" << checkPalindrome(name) <<endl;

    // int length = getLength(name);

    // cout<<"length->" << length << endl;
    return 0;
}