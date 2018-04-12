#include <iostream>
#include <stdio.h>
using namespace std;
const int N=100010;// Change maximum size if needed
typedef int T;// Change type if needed
T arr[N];
int n;
void Merge(T a[],int l,int mid,int r){
	int size1 = mid - l + 1;
	int size2 = r - mid;

	int L[size1],R[size2];
	for(int i = 0 ; i < size1 ; ++i)
		L[i] = a[l + i];
	for(int i = 0 ; i < size2 ; ++i)
		R[i] = a[mid + 1 + i];
	int i=0,j=0;
	int k=l;
	while(i < size1 && j < size2){
		if(L[i] <= R[j]){
			a[k] = L[i];
			++i;
		}
		else{
			a[k] = R[j];
			++j;
		}
		++k;
	}

	while(i < size1){
		a[k] = L[i];
		++i;
		++k;
	}
	while(j < size2){
		a[k] = R[j];
		++j;
		++k;
	}
}
void MergeSort(T a[],int l,int r){
	if(l >= r)
		return;
	int mid = l + (r - l)/2;
	MergeSort(a,l,mid);//left half of array
	MergeSort(a,mid + 1,r);//right half of array

	Merge(a,l,mid,r);
}
int main(){
	cin >>n;
	for(int i = 0 ; i < n ; ++i)
		cin >> arr[i];
	MergeSort(arr,0,n - 1);
	for(int i = 0 ; i < n ; ++i)
		cout << arr[i];
	puts("");
	return 0;
}
