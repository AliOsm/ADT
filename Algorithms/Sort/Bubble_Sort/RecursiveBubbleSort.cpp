#include <iostream>
#include <stdio.h>
using namespace std;
const int N=100010;
typedef int T;
T arr[N];
int n;
void RecursiveBubbleSort(int a[],int idx){
	if(idx==1)
		return;
	for(int i=0;i<n-1;++i)
		if(a[i]>a[i+1])
			swap(a[i],a[i+1]);
	RecursiveBubbleSort(a,idx-1);
}
int main(){
	cin >>n;
	for(int i=0;i<n;++i)
		cin >>arr[i];

	RecursiveBubbleSort(arr,n);
	
	for(int i=0;i<n;++i)
		cout <<arr[i]<<" ";
	puts("");
	return 0;
}
