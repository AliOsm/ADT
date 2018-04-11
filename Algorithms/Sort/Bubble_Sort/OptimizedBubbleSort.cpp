#include <iostream>
#include <stdio.h>
using namespace std;
const int N=100010;
typedef int T;
T arr[N];
int n;
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
	cin >>n;

	for(int i=0;i<n;++i)
		cin >>arr[i];

	OptimizedBubbleSort(arr);

	for(int i=0;i<n;++i)
		cout <<arr[i]<<" ";
	puts("");
	return 0;
}
