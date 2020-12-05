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
void merge(int l,int mid,int r){
	int ll=l,lh=mid,rl=mid+1,rh=r,k;
	for(k=0;ll<=lh&&rl<=rh;k++){
		cnt_cmp++;
		if(a[ll]<=a[rl]){
			tmp[k]=a[ll++];
		}else{
			tmp[k]=a[rl++];
		}
	}
	if(ll<=lh)
		for(int i=ll;i<=lh;i++)
			tmp[k++]=a[i];
	if(rl<=rh)
		for(int i=rl;i<=rh;i++)
			tmp[k++]=a[i];
	for(int i=0;i<r-l+1;i++){
		a[l+i]=tmp[i];
	}
	return;
}
void merge_sort(int l,int r){
	int mid=0;
	if(l<r){
		mid=l+r>>1;
		merge_sort(l,mid);
		merge_sort(mid+1,r);
		merge(l,mid,r);
	}
	return;
}
void show(){
	cout<<"使用归并排序的比较次数："<<cnt_cmp<<endl;
	cout<<"使用归并排序的交换次数："<<cnt_swap<<endl;
	cout<<"归并排序最终结果："<<endl; 
	for(int i=1;i<=10000;i++){
		cout<<a[i]<<' ';
	}
}
int main(){
	freopen("inputfile.txt","r",stdin);
	freopen("merge_sort_res.txt","w",stdout);
	for(int i=1;i<=10000;i++){
		a[i]=read();
	}
	//使用快速排序 
	merge_sort(1,10000);
	show();
	return 0;
}
