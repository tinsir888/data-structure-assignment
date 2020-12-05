#include<bits/stdc++.h>
#include<iomanip>
using namespace std;
string dict[130];
int rescnt[130];
struct raw_node{
	int ch;
	int id;
	int cnt;
	bool is_merged;
	friend bool operator <(raw_node a,raw_node b){
		return a.cnt>b.cnt;
	}
	raw_node(){
		ch=0;
		cnt=0;
		is_merged=0;
	}
}raw_data[130];
struct tnode{
	int ls;
	int rs;
	int id;
	int cnt;
	bool leaf;
	tnode(){
		ls=0;
		rs=0;
		id=0;
		cnt=0;
		leaf=0;
	}
}huff_tree[500];
int tot=0,root,delta=0;
priority_queue<raw_node>Q;
void input_insert(char t){
	if(!tot){
		tot=1;
		raw_data[1].ch=t;
		raw_data[1].cnt=1;
		raw_data[1].id=1;
		raw_data[1].is_merged=0;
		return;
	}
	for(int i=1;i<=tot;i++){
		if(raw_data[i].ch==t){
			raw_data[i].cnt++;
			return;
		}
	}
	raw_data[++tot].ch=t;
	raw_data[tot].cnt=1;
	raw_data[tot].id=tot;
	raw_data[tot].is_merged=0;
}
void merge(raw_node a,raw_node b){
	++delta;
	raw_node cur;
	huff_tree[delta+tot].ls=a.id;
	huff_tree[delta+tot].rs=b.id;
	huff_tree[delta+tot].leaf=0;
	cur.id=huff_tree[delta+tot].id=delta+tot;
	cur.cnt=huff_tree[delta+tot].cnt=a.cnt+b.cnt;
	cur.ch=a.ch+b.ch;
	cur.is_merged=0;
	Q.push(cur);
}
void build_huffman_tree(){
	for(int i=1;i<=tot;i++){
		Q.push(raw_data[i]);
		huff_tree[i].ls=huff_tree[i].rs=1000;
		huff_tree[i].id=i;
		huff_tree[i].cnt=raw_data[i].cnt;
		huff_tree[i].leaf=1;//是叶子节点 
	}
	raw_node t1,t2;
	t1=Q.top();Q.pop();
	t2=Q.top();Q.pop();
	merge(t1,t2);
	while(Q.size()>1){
		t1=Q.top();Q.pop();
		t2=Q.top();Q.pop();
		merge(t1,t2);
	}
	t1=Q.top();
	Q.pop();
	root=t1.id;
	return;
}
void get_code_dictionary(int p,string str){
	if(huff_tree[p].leaf){
		rescnt[raw_data[huff_tree[p].id].ch]=huff_tree[p].cnt;
		dict[raw_data[huff_tree[p].id].ch]=str;
		return;
	}
	get_code_dictionary(huff_tree[p].ls,str+"1");
	get_code_dictionary(huff_tree[p].rs,str+"0");
}
//**********************************************
void show_dict(){
	freopen("outputfile1.txt","w",stdout);
	cout<<"字符    出现次数    对应编码"<<endl; 
	cout<<left;
	for(int i=0;i<130;i++)
		if(dict[i].length()){
			if(i=='\n')
				cout<<setw(8)<<"换行符"<<setw(12)<<rescnt[i];
			else if(i==' ')
				cout<<setw(8)<<"空格"<<setw(12)<<rescnt[i];
			else cout<<setw(8)<<char(i)<<setw(12)<<rescnt[i];
			cout<<setw(12)<<dict[i]<<endl;
		}
}
//**********************************************
void translate_into_huffman_code(){
	freopen("inputfile1.txt","r",stdin); 
	freopen("outputfile.dat","w",stdout);
	for(char ch=getchar();ch!=EOF;ch=getchar()){
		cout<<dict[ch];
	}
}
void translate_into_raw_code(){
	freopen("outputfile.dat","r",stdin);
	freopen("outputfile2.txt","w",stdout);
	int cur=root;
	for(char ch=getchar();ch!=EOF;ch=getchar()){
		if(!huff_tree[cur].leaf){
			if(ch-48)cur=huff_tree[cur].ls;
			else cur=huff_tree[cur].rs;
		}
		if(huff_tree[cur].leaf){
			putchar(raw_data[huff_tree[cur].id].ch);
			cur=root;
		}
	}
}
void input(){
	freopen("inputfile1.txt","r",stdin);
	for(char ch=getchar();ch!=EOF;ch=getchar()){
		input_insert(ch);
	}
}
int main(){
	//进行输入 
	input();
	//生成哈夫曼树 
	build_huffman_tree();
	//生成哈夫曼编码 
	get_code_dictionary(root,"");
	//打印哈夫曼编码 
	show_dict();
	//对文本进行哈夫曼编码 
	translate_into_huffman_code();
	//将哈夫曼编码翻译回原文
	translate_into_raw_code(); 
}
