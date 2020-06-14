// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


void max_of_subarrays(int *arr, int n, int k){
    // your code here
    deque<int> dq;
    queue<int>que;
    int max_=0;
    // dq.push_back(0);
    que.push(0);
    for(int i=1;i<k;i++){
        que.push(i);
        if(arr[i]>arr[max_]){
            max_=i;
        }
    }
    dq.push_back(max_);
    // cout<<arr[dq.front()]<<" ";
    for(int i=k;i<n;i++){
        int val=que.front();
        que.pop();
        que.push(i);
        if(val==dq.front()){
            dq.pop_front();
        }
        if(dq.size()==0 || arr[dq.front()]<arr[i]){
               dq.push_back(i);
               dq.pop_front();
        }
     
        cout<<arr[dq.front()]<<" ";
    }
}


// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    
	    max_of_subarrays(arr, n, k);
	    cout << endl;
	    
	}
	
	return 0;
}