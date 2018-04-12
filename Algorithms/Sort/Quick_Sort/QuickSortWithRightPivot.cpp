#include <iostream>
#include <stdio.h>
using namespace std;
const int N=100010;// Change maximum size if needed
typedef int T;// Change type if needed
T arr[N];
int n;
int partition(T a[],int l,int r){
	int pivot = a[r];//almost right pivot (Last Element)
	int i = l - 1;
	for(int j = l ; j < r ; ++j){
		if(a[j] <= pivot){
			++i;
			swap(a[i],a[j]);
		}
	}
	swap(a[i + 1],a[r]);
	return i + 1;
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
