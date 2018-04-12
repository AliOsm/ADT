#include <iostream>
#include <stdio.h>
#include <time.h>
using namespace std;
const int N=100010;// Change maximum size if needed
typedef int T;// Change type if needed
T arr[N];
int n;
int random(int mn,int mx){
	return mn + (rand() % (mx - mn + 1));
}
int partition(T a[],int l,int r){
	int i = random(l,r);
	swap(a[l],a[i]);
	i = l;
	int pivot = a[l];
	for(int j = l + 1 ; j <= r ; ++j){
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
	srand(time(0));

	cin >>n;
	for(int i=0;i<n;++i)
		cin >>arr[i];

	QuickSort(arr,0,n - 1);
	
	for(int i = 0 ; i < n ; ++i)
		cout <<arr[i]<<" ";
	printf("\n");
	return 0;
}
