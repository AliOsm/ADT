#include <iostream>
#include <stdio.h>
#include <string>
#include <memory.h> 
using namespace std;
const int N=10004;//Change Maximum size if needed
string a,b;
int dp[N][N];
int LCS(int i,int j){
	if(i==0||j==0)
		return 0;
	
	int &ret=dp[i][j];
	if(ret!=-1)
		return ret;
	ret=0;

	if(a[i-1]==b[j-1])
		return ret = 1+LCS(i-1,j-1);
	else 
		return ret = max(LCS(i-1,j),LCS(i,j-1));
}
int main(){
	cin >>a>>b;
	memset(dp,-1,sizeof dp);
	printf("%d\n",LCS(a.size(),b.size()));
	return 0;
}