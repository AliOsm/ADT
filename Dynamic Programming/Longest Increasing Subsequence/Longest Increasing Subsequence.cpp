#include <iostream>
#include <stdio.h>
#include <memory.h>
using namespace std;

const int N=100005;//change maximum size if needed

int n,arr[N],dp[N];

int LIS(int i) {
	int &ret = dp[i];

	if(ret != -1) return ret;

	ret = 0;
	for(int j = i+1;j < n;++j)
		if(arr[i] < arr[j])
			ret = max(ret, LIS(j) + 1);

	return ret;
}

int main(){
	scanf("%d",&n);
	
	for(int i=0;i<n;++i)
		scanf("%d",arr+i);
	
	memset(dp,-1,sizeof dp);
	
	printf("%d\n",LIS(0));
	return 0;
}