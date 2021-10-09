#include <bits/stdc++.h>
using namespace std;




void exploreAllPath(int value,int& a,int& b,vector<int>& ans){
    // if answer exceeds "B"
    if(value>b) return;
    
    
    // if answer in the range then store the result
    if(value>=a && value<=b){
        ans.push_back(value);
    }
    
    int back= value%10;
    // explore previous adjacent
    if((back)!=0){
        exploreAllPath(value*10+(back-1),a,b,ans);
    }
    // explore next adjacent
    if(back!=9){
        exploreAllPath(value*10+(back+1),a,b,ans);
    }
    
}
vector<int> stepnum(int A, int B) {
   vector<int> ans;

   if(A==0) ans.push_back(0);
   
   // start from 1 , 9 and explore all path
   for(int i=1;i<=9;i++){
      exploreAllPath(i,A,B,ans);
   }
   
   // lastly sort the answer
    sort(ans.begin(),ans.end());
    return ans;
}




/*
 let n= 2^(no of digit in B)= 2^(log10(B))
 
 space Complexity:  O(9*n) = O(n)
 time Complexity: n*log(n)  // size of ans

*/
