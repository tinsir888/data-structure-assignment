#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int G[maxn][maxn];
int n,res;
bool jg(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(G[i][j]!=5)return false;
	return true;
}
void show(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			cout<<G[i][j]<<" ";
		cout<<endl;
	}
}
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
void DFS(int x,int y){
	G[x][y]=5;
	for(int i=0;i<4;i++){
		if(x+dx[i]>0&&y+dy[i]>0&&x+dx[i]<=n&&y+dy[i]<=n){
			if(G[x+dx[i]][y+dy[i]]==0){
				DFS(x+dx[i],y+dy[i]);
			}
		}
		else continue;
	}
	return;
}
void init(){
	int i;
	for(i=1;i<=n;i++){
		if(G[1][i]==0){
			DFS(1,i);
		}
		if(G[i][1]==0){
			DFS(i,1);
		}
		if(G[i][n]==0){
			DFS(1,n);
		}
		if(G[n][i]==0){
			DFS(n,1);
		}
	}
}
void penetrate(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(G[i][j]==0){
				bool f=0;
				for(int k=0;k<4;k++){
					if(G[i+dx[k]][j+dy[k]]==5){
						f=1;
						break;
					}
				}
				if(f)G[i][j]=5;
			}
		}
}
void melt(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(G[i][j]==1){
				int f=0;
				for(int k=0;k<4;k++){
					if(G[i+dx[k]][j+dy[k]]==5){
						f++;
					}
				}
				if(f>=2)G[i][j]=-1;
			}
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(G[i][j]==-1)G[i][j]=5;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		for(int j=0;j<n;j++)
			if(s[j]=='_')G[i][j+1]=0;
			else if(s[j]=='#') G[i][j+1]=1;
	}
	init();
	for(res=0;;res++){
		if(jg()){
			cout<<res<<endl;
			return 0;
		}
		penetrate();
		melt();
		//////////////////////////////
		show();
		puts("");
		//////////////////////////////
	}
}
/*
16
________________
________________
__##____________
__########______
___####__#####__
___#_##___####__
___#_####_##____
_____########___
_______###______
________________
____#######_____
_____######_____
______##__##____
_______#####____
________________
________________
*/ 
