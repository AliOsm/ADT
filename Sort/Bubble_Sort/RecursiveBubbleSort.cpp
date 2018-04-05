#include <iostream>
#include <stdio.h>
using namespace std;
const int N=100010;
int arr[N],n;
void RecursiveBubbleSort(int a[],int idx){
	if(idx==1)
		return;
	for(int i=0;i<n-1;++i)
		if(a[i]>a[i+1])
			swap(a[i],a[i+1]);
	RecursiveBubbleSort(a,idx-1);
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		scanf("%d",arr+i);
	RecursiveBubbleSort(arr,n);
	for(int i=0;i<n;++i)
		printf("%d ",arr[i]);
	puts("");
	return 0;
}
