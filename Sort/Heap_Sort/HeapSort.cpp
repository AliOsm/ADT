#include <iostream>
#include <stdio.h>
using namespace std;
const int N=100010;
int arr[N],n;
void Heapify(int a[],int n,int i){
	int largest=i;
	int leftChild=i*2+1;
	int rightChild=i*2+2;

	if(leftChild < n && a[leftChild] > a[largest])
		largest=leftChild;
	if(rightChild < n && a[rightChild] > a[largest])
		largest=rightChild;
	if(largest!=i){
		swap(a[i],a[largest]);
		Heapify(a,n,largest);
	}
}
void BuildHeap(int a[]){
	for(int i=n/2-1;i>=0;--i)
		Heapify(a,n,i);
}

void HeapSort(int a[]){
	BuildHeap(a);
	for(int i=n-1;i>0;--i){
		swap(a[0],a[i]);
		Heapify(a,i,0);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		scanf("%d",arr+i);
	HeapSort(arr);
	for(int i=0;i<n;++i)
		printf("%d ",arr[i]);
	puts("");
	return 0;
}
