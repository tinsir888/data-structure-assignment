//#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define ll __int128
inline void write(ll x){
	if(x>9)
		write(x/10);
	putchar(x%10+48);
}
using namespace std;
const int maxn = 1e2+6;
int vis[10];
map<ll,int>mp;
ll Mont(ll a ,ll b){
    ll ans=1;
    while(b){
        if(b&1){
            ans*=a;
        }
        b>>=1;
        a*=a;
    }
    return ans;
}
ll sum,b[maxn],res[maxn];
int cnt;
void DFS(int v,int num,int n){
    if(v>9) return;
    if(num>n) return ;
    if(num==n){
        if(sum<=0) return;
        ll t=sum;
        int c[10]={0};//array c[i] means how many times number i appears in number sum    
        while(t){
            int tmp=t%10;
            t/=10;
            c[tmp]++;
        }
        for(int i=0;i<=9;i++){
            if(c[i]!=vis[i])return;
        }
        if(!mp[sum]){
            res[cnt++]=sum;
            mp[sum]=1;
            return;
        }
    }
    for(int i=0;i<=8;i++){
        if(v<9){
            vis[v+1]+=i;
            sum+=i*b[v+1];
            DFS(v+1,num+i,n);
            vis[v+1]-=i;
            sum-=i*b[v+1];
        }
    }
}

int work(int n){
    cnt = 0;
    //scanf("%d",&n);
    for(int i=1;i<=9;i++){
        b[i]=Mont(i,n);
    }
    for(int i=0;i<=3;i++){
        sum=0;
        memset(vis,0,sizeof(vis));
        vis[0]+=i;
        DFS(0,i,n);
        vis[0]-=i;
    }
    if(!cnt) return 0;
    else{
        sort(res,res+cnt);
        for(int i=0;i<cnt;i++){
            write(res[i]);
            puts("");
        }
    }
    return 0;
}
int main(){
	for(int i=1;i<=39;i++){
		printf("第%d位数\n",i);
		work(i);
		printf("程序运行了%.2lf秒\n",(double)clock()/CLOCKS_PER_SEC);
	}
	return 0;
}
