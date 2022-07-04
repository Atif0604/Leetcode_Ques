#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int>v (n);
	    for(int i=0;i<n;i++){
	        cin>>v[i];
	    }
	    int low =0;
	    int high = n-1;
	    while(low<=high){
	        swap(v[low],v[high]);
	        low++;
	        high--;
	    }
	    for(auto it: v) cout<<it<<" ";
	    cout<<endl;
	}
	return 0;
}