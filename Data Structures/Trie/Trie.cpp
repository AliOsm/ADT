#include <iostream>
#include <string>
#include <string.h>
using namespace std;

struct trie {
	trie *next[26];
	int cnt;
	bool end;
	trie() {
		memset(next,0,sizeof next);
		cnt = 0;
		end=false;
	}
};

trie *root;


void insert(string &s) {
	trie *cur = root;

	int len=(int)s.size();

	for(int i=0,idx;i<len;++i){

		idx = s[i]-'a';
		
		if(cur->next[idx] == NULL)//create new path with this character if there is no one
			cur->next[idx] = new trie();

		cur = cur->next[idx];
		++cur->cnt;//count how many times this character in this path repeated
	}
	cur -> end =true;//this node is an end node for a string 
}


bool find(string &s) {
	trie *cur = root;
	int len=(int)s.size();
	for(int i=0,idx;i<len;++i){
		idx = s[i]-'a';
		
		if(cur->next[idx]==NULL)//if there is no path with this character
			return false;
	
		cur=cur->next[idx];
	}
	return cur->end;//check if cur is on end of a word 
}
void freeTrie(trie *cur) {
	if(cur == NULL)
		return;
	for(int i=0;i<26;++i)
		freeTrie(cur->next[i]);
	delete [] cur;
}
int main(){
	string s;
	root = new trie();
  	int n;//number of strings to put in the dictionary (Tire Tree)
  	int q;//number of Queries on the tree
  	scanf("%d%d",&n,&q);
	for(int i = 0; i < n; ++i) {
		cin >>s;
		insert(s);
	}
	for(int i = 0; i < q; ++i) {
		cin >>s;
	  	puts(find(s)?"YES":"NO");
	}
	freeTrie(root);
	return 0;
}