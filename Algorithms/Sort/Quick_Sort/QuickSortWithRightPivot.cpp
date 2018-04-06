#include <iostream>
#include <stdio.h>
using namespace std;
const int N=100005;
int partition(int a[],int l,int r){
	int pivot=a[r];//almost right pivot (Last Element)
	int i=l-1;
	for(int j=l;j<r;++j){
		if(a[j]<=pivot){
			++i;
			swap(a[i],a[j]);
		}
	}
	swap(a[i+1],a[r]);
	return i+1;
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
