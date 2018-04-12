#include <iostream>
#include <stdio.h>
using namespace std;
const int N=100010;// Change maximum size if needed
typedef int T;// Change type if needed
T arr[N];
int n;
int partition(T a[],int l,int r){
	int pivot = a[l];//almost left pivot (First Element)
	int i = l;
	for(int j = l + 1; j <= r ;++j){
		if(a[j] <= pivot){
			++i;
			swap(a[i],a[j]);
		}
	}
	swap(a[i],a[l]);
	return i;
}
void QuickSort(T a[],int l,int r){
	if (l >= r)
		return;

	int mid = partition(a,l,r);
	
	QuickSort(a,l,mid - 1);
	QuickSort(a,mid + 1,r);
}
int main(){
	cin >>n;
	for(int i = 0 ; i < n ; ++i)
		cin >>arr[i];

	QuickSort(arr,0,n - 1);
	
	for(int i = 0 ; i < n ; ++i)
		cout <<arr[i]<<" ";
	printf("\n");
	return 0;
}
