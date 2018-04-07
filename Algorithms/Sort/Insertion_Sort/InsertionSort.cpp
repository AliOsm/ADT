#include <iostream>
#include <stdio.h>
using namespace std;
const int N=100010;
int arr[N],n;
void InsertionSort(int a[]){
	for(int i=1;i<n;++i){
		int j=i-1;
		int key=a[i];
		while(j>=0&&a[j]>key){
			swap(a[j+1],a[j]);
			--j;
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		scanf("%d",arr+i);
	InsertionSort(arr);
	for(int i=0;i<n;++i)
		printf("%d ",arr[i]);
	puts("");
	return 0;
}
