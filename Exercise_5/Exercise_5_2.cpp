#include<bits/stdc++.h>
using namespace std;
int G[105][23];
bool flag[105]={0},used[105]={0};
//flag[i]=1表示可以通过k次变换使得第i行全亮 
int main(){
	int n,m,k,res=0;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>G[i][j];
	for(int i=1;i<=n;i++){
		int cnt_0=0;
		for(int j=1;j<=m;j++){
			if(!G[i][j])cnt_0++;
		}
		if((cnt_0&1)==(k&1)&&cnt_0<=k){
			flag[i]=1;
		}
		else flag[i]=0;
	}
	for(int i=1;i<=n;i++){
		if(used[i]||(!flag[i]))continue;
		used[i]=1;
		int cur=1;
		for(int ii=1;ii<=n;ii++){
			if(used[ii]||(!flag[ii]))continue;
			bool f=1;
			for(int j=1;j<=m;j++){
				if(G[i][j]!=G[ii][j]){
					f=0;
//					/////////////////////////////////
//					cout<<i<<" "<<ii<<":"<<j<<endl;
//					////////////////////////////////
					break;
				}
			}
//			/////////////////////////////////
//			cout<<i<<' '<<ii<<' '<<f<<endl;
//			/////////////////////////////////
			if(f){
				used[ii]=1;
				cur++;
			}
		}
//		/////////////////////////////////
//		cout<<"第"<<i<<"行："<<cur<<endl;
//		/////////////////////////////////
		res=max(cur,res);
	}
	cout<<res<<endl;
}
/*
6 5 3
1 0 0 1 0
1 1 0 0 0
0 1 1 1 0
0 0 0 1 1
1 0 1 0 1
1 1 0 0 0
*/
