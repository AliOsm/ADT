#include <iostream>
#include <string>
using namespace std;
void CountSort(string &s){
	int len=(int)s.size();
	
	string out;
	out.resize(len);
	
	int count[255+1]={0};
	
	for(int i=0;i<len;++i)
		++count[s[i]];
	
	for(int i=1;i<=255;++i)
		count[i]+=count[i-1];
	
	for(int i=0;i<len;++i){
		out[count[s[i]]-1]=s[i];
		--count[s[i]];
	}
	
	s=out;
}
int main(){
	string s;
	cin >>s;
	CountSort(s);
	puts(s.c_str());
	return 0;
}
