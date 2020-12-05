#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=400005;
const ll maxm=2000015;
const ll inf=0x7fffffffffffffff;
ll a,b,c,n,m,S,E,cnt,dis[maxn];
ll Last[maxn],Next[maxm],Len[maxm],End[maxm];
bool flag[maxn];
inline int read() {
  	bool f=0;
   	int x=0;
   	char ch=getchar();
   	while(ch>'9'||ch<'0') {
   		if(ch=='-')f^=1;
   		ch=getchar();
   	}
   	while(ch>='0'&&ch<='9') {
    	x=(x<<3)+(x<<1)+ch-'0';
    	ch=getchar();
   	}
   	return f?-x:x;
}
inline void write(int x) {
   	if(x<0)x=-x,putchar('-');
   	if(x>9)write(x/10);
  	putchar(x%10+48);
}
struct cmp {
   	bool operator()(ll x,ll y) {
   		return dis[x]>dis[y];
   	}
    };
    priority_queue<ll,vector<ll>,cmp> Q;
void add_edge(ll x,ll y,ll z) {
   	End[++cnt]=y,Len[cnt]=z;
   	Next[cnt]=Last[x],Last[x]=cnt;
}
void dijkstra() {
   	for(ll i=1; i<=n; i++) dis[i]=inf;
   	flag[S]=true,dis[S]=0,Q.push(S);
   	while(!Q.empty()) {
   		ll x=Q.top(),temp=Last[x];
   		Q.pop(),flag[x]=false;
   		if(x==E) break;
   		while(temp) {
   			ll y=End[temp];
   			if(dis[y]>dis[x]+Len[temp]) {
   				dis[y]=dis[x]+Len[temp];
   				if(!flag[y]) flag[y]=true,Q.push(y);
   			}
   			temp=Next[temp];
   		}
   	}
  	cout<<dis[E];
}
int main(int argc,const char*argv[]) {
   	scanf("%lld%lld",&n,&m);
   	while(m--) {
   		scanf("%lld%lld%lld",&a,&b,&c);
   		add_edge(a,b,c);
   	}
   	scanf("%lld%lld",&S,&E);
   	dijkstra();
   	return 0;
}
