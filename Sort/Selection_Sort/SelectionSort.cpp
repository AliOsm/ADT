#include <iostream>
#include <stdio.h>
using namespace std;
const int N=100010;
int arr[N],n;
void SelectionSort(int a[]){
	int Min_idx;
	for(int i=0;i<n-1;++i){
		Min_idx=i;
		for(int j=i+1;j<n;++j){
			if(a[j]<a[Min_idx])
				Min_idx=j;
		}
		if(i!=Min_idx)
			swap(a[i],a[Min_idx]);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		scanf("%d",arr+i);
	SelectionSort(arr);
	for(int i=0;i<n;++i)
		printf("%d ",arr[i]);
	puts("");
	return 0;
}
