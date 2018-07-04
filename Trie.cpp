#include<iostream>
#include<string.h> 
const int MAX_N=1000;
class Trie{
	public:
		Trie(){
			tot=0;
		memset(cnt,0,sizeof(cnt));
		memset(ch,-1,sizeof(ch));
		}
	void insert(char* str){
		int p=0;
		if(ch[p]==NULL){
			ch[p]=new int [26];
			memset(ch[p],-1,sizeof(int)*26);
		}
		for(int i=0;str[i];i++){
			if(ch[p][str[i]-'a']==-1){
				ch[p][str[i]-'a']=++tot;
			}
			p=ch[p][str[i]-'a'];
		}
		cnt[p]++;
	}
	int find(char *str){
		int p=0;
		for(int i=0;str[i];i++){
			if(ch[p][str[i]-'a']==-1){
				return 0;
			}
			p=ch[p][str[i]-'a'];
		}
		return cnt[p];
	}
	private:
	int *ch[MAX_N];
	int tot;
	int cnt[MAX_N];
}; 
int main(){
	class Trie trie;
	trie.insert("abc");
	trie.insert("abcd");
	trie.insert("abcf");
	trie.insert("ab");
	trie.find("ab");
	return 0;
}
