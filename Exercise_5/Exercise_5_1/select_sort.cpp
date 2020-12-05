#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
inline int read(){
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+ch-48,ch=getchar();
	return x;
}
int a[maxn],tmp[maxn],cnt_cmp=0,cnt_swap=0;
void selection_sort(){
	for(int i=1;i<10000;i++){
		int p=i;
		for(int j=i+1;j<=10000;j++){
			cnt_cmp++;
			if(a[j]<a[p])
				p=j;
		}
		int tmp=a[p];
		a[p]=a[i];
		a[i]=tmp;
		cnt_swap++;
	}
} 
void show(){
	cout<<"使用选择排序的比较次数："<<cnt_cmp<<endl;
	cout<<"使用选择排序的交换次数："<<cnt_swap<<endl;
	cout<<"选择排序最终结果："<<endl; 
	for(int i=1;i<=10000;i++){
		cout<<a[i]<<' ';
	}
}
int main(){
	freopen("inputfile.txt","r",stdin);
	freopen("selection_sort_res.txt","w",stdout);
	for(int i=1;i<=10000;i++){
		a[i]=read();
	}
	//使用快速排序 
	selection_sort();
	show();
	return 0;
}
