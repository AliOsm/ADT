#include <iostream>
#include <stdio.h>
using namespace std;
const int N=100010;// Change maximum size if needed
typedef int T;// Change type if needed
T arr[N];
int n;
void InsertionSort(T a[]){
	for(int i = 1 ; i < n ; ++i){
		int j = i - 1;
		int key = a[i];
		while(j >= 0 && a[j] > key){
			swap(a[j+1],a[j]);
			--j;
		}
	}
}
int main(){
	cin >>n;
	for(int i = 0 ; i < n ; ++i)
		cin >>arr[i];
	InsertionSort(arr);
	for(int i = 0 ; i < n ; ++i)
		cout <<arr[i]<<" ";
	puts("");
	return 0;
}
