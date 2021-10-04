int lower_bound(vector<vector<long long int>>& arr,int search,int n){
    int low=0,high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid][1]<search) low=mid+1;
        else high=mid-1;
    }
    return low;
}
 
vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    int MOD=1000000007; 
    int n=(int) A.size();
 
  
    
    //2 find the no of subarray has max element A[i]
    vector<int> prev(n),next(n);
    stack<int> temp;
    for(int i=0;i<n;i++){
        while(!temp.empty() && A[temp.top()]<=A[i]) temp.pop();
        
        if(temp.empty()==true) prev[i]=-1;
        else prev[i]=temp.top();
        
        temp.push(i);
    }
    
    while(!temp.empty()) temp.pop();
    
    for(int i=n-1;i>=0;i--){
        while(!temp.empty() && A[temp.top()]<A[i]) temp.pop();
        if(temp.empty()==true) next[i]=n;
        else next[i]=temp.top();
        
        temp.push(i);
    }
    
    
    
     //3 find the divisor product
    int mx=*max_element(A.begin(),A.end());
    vector<int> proDiv(mx+1);
    for(int i=0;i<=mx;i++) proDiv[i]=i;
    
    for(int i=2;i<=mx;i++){
        for(int j=2*i;j<=mx;j+=i){
            proDiv[j]=((long long) proDiv[j]*i)%MOD;
        }
    }
    
 
    vector<vector<long long int>> arr(n);
    //fill the array with {divisor_product, count_of_element}
    for(int i=0;i<n;i++){
        arr[i]={proDiv[A[i]],(i-prev[i])*(next[i]-i)};
    }
    
    //4 sort in descending order according to divisor product
    sort(arr.begin(),arr.end(),greater<vector<long long int>>());
    
  
    // prefix sum count for binary search
    for(int i=1;i<n;i++)
     arr[i][1]+=arr[i-1][1];
     
    //query part 
    vector<int> ans;
    for(int val:B){
        //binary search based on count
        int index= lower_bound(arr,val,n);
        ans.push_back(arr[index][0]);
    }
    return ans;
}