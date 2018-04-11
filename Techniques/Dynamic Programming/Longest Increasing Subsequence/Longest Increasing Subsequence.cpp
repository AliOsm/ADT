#include <iostream>
#include <stdio.h>
#include <memory.h>
using namespace std;

typedef int T;

const int N=100005;//change maximum size if needed

int n;
T arr[N],dp[N];

T LIS(int i) {

	T &ret = dp[i];
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
	
	int ans = -1;
	for(int i = 0; i < n; ++i)
		ans = max(ans, LIS(i)+1);
	
	printf("%d\n", ans);
	return 0;
}