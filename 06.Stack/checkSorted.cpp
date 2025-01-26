#include<iostream>
#include<stack>

using namespace std;

bool checkSorted(stack<int> &s, int element){

   //base case
   if(s.empty()){
    return true;
   }


   int element2 = s.top();
   s.pop();

   if(element2 < element){
    element = element2;
    return checkSorted(s, element);
   }
   else{
    //sorted hi nahi hai
    return false;
   }


}

int main(){

    stack<int> s;
    
    s.push(10);
    s.push(20);
    s.push(100);
    s.push(40);
    s.push(50);

    int element1 = INT_MAX;
    cout << checkSorted(s, element1) <<endl;


    return 0;
}