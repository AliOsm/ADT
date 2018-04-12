#include <iostream>
#include <stdio.h>
using namespace std;
const int N=100010;// Change maximum size if needed
typedef int T;// Change type if needed
T arr[N];
int n;
void SelectionSort(T a[]){
	int Min_idx;
	for(int i = 0 ; i < n - 1 ; ++i){
		Min_idx = i;
		for(int j = i + 1 ; j < n ; ++j){
			if(a[j] < a[Min_idx])
				Min_idx = j;
		}
		if(i != Min_idx)
			swap(a[i],a[Min_idx]);
	}
}
int main(){
	cin >>n;
	for(int i = 0 ; i < n ; ++i)
		cin >>arr[i];
	SelectionSort(arr);
	for(int i = 0 ; i < n ; ++i)
		cout <<arr[i];
	puts("");
	return 0;
}
