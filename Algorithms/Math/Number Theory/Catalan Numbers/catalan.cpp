#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long T; // Change type if needed

int const MAX = 30; // Change maximum number of numbers if needed

T dp[MAX]; // Dynamic Programming array to memorize the solutions

T catalan(T n){
	//Base case
	if(n<=1)
		return 1;
	
	T &ref = dp[n];
	//Check if the solution for 'n' is already calculated or not
	if(ref!=-1)
		return ref;
	
	T res = 0;
	// Calculate N'th catalan number
	for(T i=0;i<n;++i)
		res += catalan(i) * catalan(n-i-1);

	ref=res;
	
	return res;
}

int main(){	
	//Initialize the dp array with -1 values
	memset(dp,-1,sizeof(dp));
	
	T n;
	cin >>n;
	
	// N'th Catalan Number
	cout <<catalan(n)<<endl;
	
	return 0;
}
