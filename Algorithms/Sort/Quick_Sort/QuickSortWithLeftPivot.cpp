#include <iostream>
#include <stdio.h>
using namespace std;
const int N=100005;
int partition(int a[],int l,int r){
	int pivot=a[l];//almost left pivot (First Element)
	int i=l;
	for(int j=l+1;j<=r;++j){
		if(a[j]<=pivot){
			++i;
			swap(a[i],a[j]);
		}
	}
	swap(a[i],a[l]);
	return i;
}
void QuickSort(int a[],int l,int r){
	if (l>=r)
		return;

	int mid=partition(a,l,r);
	
	QuickSort(a,l,mid-1);
	QuickSort(a,mid+1,r);
}
int main(){
	int arr[N],n;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		scanf("%d",arr+i);

	QuickSort(arr,0,n-1);
	
	for(int i=0;i<n;++i)
		printf("%d ",arr[i]);
	printf("\n");
	return 0;
}
