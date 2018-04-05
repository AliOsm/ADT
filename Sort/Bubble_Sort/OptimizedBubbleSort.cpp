#include <iostream>
#include <stdio.h>
using namespace std;
const int N=100010;
int arr[N],n;
void OptimizedBubbleSort(int a[]){
	bool swapped;
	for(int i=0;i<n-1;++i){
		swapped=false;
		for(int j=0;j<n-i-1;++j){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
				swapped=true;
			}
		}
		if(!swapped)
			break;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		scanf("%d",arr+i);
	OptimizedBubbleSort(arr);
	for(int i=0;i<n;++i)
		printf("%d ",arr[i]);
	puts("");
	return 0;
}
