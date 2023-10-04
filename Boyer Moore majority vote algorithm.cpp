#include <iostream>
#include <vector>
using namespace std;

pair<bool,int> boyerMoore(vector<int> arr, int left = -1, int right = -1) {
    int element, vote = 0;
    if(left<0||right<0){
        left=0,right = arr.size()-1;
    }
    
    for(int i=left;i<=right;i++){
        if(!vote){
            element = arr[i];
        }
        if(element == arr[i])
            vote++;
        else
            vote--;
    }
    int count = 0;
    for(int i = left; i<=right; i++){
        if(arr[i] == element)
            count++;
    }
    if(count > (right-left+1)/2)
        return {true, element};
    else
        return  {false, element};
}

int main(){
    vector<int> arr = {1,2,4,2,5,1,1,1};
    pair<bool,int> test = boyerMoore(arr);
    if(test.first)
        cout<<"majority element : "<<test.second<<endl;
    else
        cout<<"majority element not present"<<endl;
    test = boyerMoore(arr,1,3);
    if(test.first)
        cout<<"majority element : "<<test.second<<endl;
    else
        cout<<"majority element not present"<<endl;
  
}
