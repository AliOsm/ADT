#include <iostream>
#include <stdio.h>
using namespace std;
const int N=100010;
typedef int T;
T arr[N];
int n;
void BubbleSort(int a[]){
	for(int i=0;i<n-1;++i){
		for(int j=0;j<n-i-1;++j){
			if(a[j]>a[j+1])
				swap(a[j],a[j+1]);
		}
	}
}
int main(){
	cin >>n;

	for(int i=0;i<n;++i)
		cin >>arr[i];

	BubbleSort(arr);

	for(int i=0;i<n;++i)
		cout <<arr[i]<<" ";
	puts("");
	return 0;
}
