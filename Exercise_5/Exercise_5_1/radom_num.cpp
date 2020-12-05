#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int main(){
	freopen("inputfile.txt","w",stdout);
	srand((unsigned int)time(NULL));
	for(int i=1;i<=10000;i++){
		cout<<rand()%mod<<' ';
	} 
}
