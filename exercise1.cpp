#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
using namespace std;
template<class T>
struct node{
public:
	T val;
	node *pre;
	node *next;
public:
	node(){}
	node(T t,node *pre,node *next){
		this->val=t;
		this->pre=pre;
		this->next=next;
	}
};
template<class T>
class dlink{
private:
	int cnt;
	node<T> *phead;
	node<T> *get_node(int index);
public:
	dlink();
	~dlink();
	
	int size();
	bool empty();
	
	T get(int index);
	//T get_first(T t);
	//T get_last(T t);
	
	int insert(int index,T t);
	int insert_first(T t);
	int append_last(T t);
	
	int del(int index);
	int del_first();
	int del_last();
};
template<class T>
dlink<T>::dlink():cnt(0){
	//create head of double list
	//attention:head of double list doesnot storage datas
	phead=new node<T>();
	phead->pre=phead->next=phead;
}
template<class T>
dlink<T>::~dlink(){
	//delete all the nodes
	node<T>* ptmp;
	node<T>* pnode=phead->next;
	while(pnode!=phead){
		ptmp=pnode;
		pnode=pnode->next;
		delete ptmp;
	}
	//delete head of list
	delete phead;
	phead=NULL;
}
template<class T>
int dlink<T>::size(){
	return cnt;
}
template<class T>
bool dlink<T>::empty(){
	return cnt==0;
}
template<class T>
//get index-th position's pointer
node<T>* dlink<T>::get_node(int index){
	//judge index
	if(index<0||index>=cnt){
		cout<<"failed! the index in "<<index<<" is out of bound: "<<cnt<<endl;
		return NULL;
	}
	
	//find
	if(index<=(cnt>>1)){
		int i=0;
		node<T>* pindex=phead->next;
		while(i++<index){
			pindex=pindex->next;
		}
		return pindex;
	}else{
		int i=0,rind=cnt-index-1;
		node<T>* prindex=phead->pre;
		while(i++<rind)
			prindex=prindex->pre;
		return prindex;
	}
}
template<class T>
//get index-th position's value
T dlink<T>::get(int index){
	return get_node(index)->val;
}
//unknown error
/*
template<class T>
//get first position's value

T dlink<T>::get_first(){
	return get_node(0)->val;
}
template<class T>
//get last position's value
T dlink<T>::get_last(){
	return get_node(cnt-1)->val;
}
*/
template<class T>
//insert node before index-th position
int dlink<T>::insert(int index,T t){
	if(!index)return insert_first(t);
	node<T>* pindex=get_node(index);
	node<T>* pnode=new node<T>(t,pindex->pre,pindex);
	pindex->pre->next=pnode;
	pindex->pre=pnode;
	cnt++;
	return 0;
}
template<class T>
//insert node at first position
int dlink<T>::insert_first(T t){
	node<T>* pnode=new node<T>(t,phead,phead->next);
	phead->next->pre=pnode;
	phead->next=pnode;
	cnt++;
	return 0;
}
template<class T>
//append node at last position
int dlink<T>::append_last(T t){
	node<T>* pnode=new node<T>(t,phead->pre,phead);
	phead->pre->next=pnode;
	phead->pre=pnode;
	cnt++;
}
template<class T>
//delete index-th position's node
int dlink<T>::del(int index){
	node<T>* pindex=get_node(index);
	pindex->next->pre=pindex->pre;
	pindex->pre->next=pindex->next;
	delete pindex;
	cnt--;
	return 0;
}
template<class T>
//delete the first position's node
int dlink<T>::del_first(){
	return del(0);
}
template<class T>
//delete the last position's node
int dlink<T>::del_last(){
	return del(cnt-1);
}
struct poly{
	int coe;
	int ti;
	poly(){}
	poly(int c,int t){
		coe=c;
		ti=t;
	}
};
dlink<poly>* list1=new dlink<poly>();
dlink<poly>* list2=new dlink<poly>();
dlink<poly>* res=new dlink<poly>();
dlink<poly>* rem=new dlink<poly>();
dlink<poly>* cur1=new dlink<poly>();
dlink<poly>* cur2=new dlink<poly>();
//input data
void input(){
	string s,t;
	cin>>s;
	poly tmp;
	for(int i=0;i<s.length();i++){
		bool f=0;int x=0;
		while(s[i]>'9'||s[i]<'0'){if(s[i]=='-')f=1;i++;if(i>=s.length())break;}
		while(s[i]>='0'&&s[i]<='9'){x=x*10+s[i]-48;i++;if(i>=s.length())break;}
		tmp.coe=f?-x:x;
		f=0;x=0;
		while(s[i]>'9'||s[i]<'0'){if(s[i]=='-')f=1;i++;if(i>=s.length())break;}
		while(s[i]>='0'&&s[i]<='9'){x=x*10+s[i]-48;i++;if(i>=s.length())break;}
		tmp.ti=f?-x:x;
		if(tmp.coe||tmp.ti){
			if(list1->empty())list1->append_last(tmp);
			else {
				bool fl=0;
				//the most naive insert algorithm,
				//it can be optimized into binary search
				for(int i=0;i<list1->size();i++){
					poly temp=list1->get(i);
					if(tmp.ti>temp.ti){
						list1->insert(i,tmp);
						fl=1;
						break;
					}
				}
				if(!fl)list1->append_last(tmp);
			}
		}
		//list1->append_last(tmp);
	}
	cin>>s;
	for(int i=0;i<s.length();i++){
		bool f=0;int x=0;
		while(s[i]>'9'||s[i]<'0'){if(s[i]=='-')f=1;i++;if(i>=s.length())break;}
		while(s[i]>='0'&&s[i]<='9'){x=x*10+s[i]-48;i++;if(i>=s.length())break;}
		tmp.coe=f?-x:x;
		f=0;x=0;
		while(s[i]>'9'||s[i]<'0'){if(s[i]=='-')f=1;i++;if(i>=s.length())break;}
		while(s[i]>='0'&&s[i]<='9'){x=x*10+s[i]-48;i++;if(i>=s.length())break;}
		tmp.ti=f?-x:x;
		if(tmp.coe||tmp.ti){
			if(list2->empty())list2->append_last(tmp);
			else {
				bool fl=0;
				//the most naive insert algorithm,
				//it can be optimized into binary search
				for(int i=0;i<list2->size();i++){
					poly temp=list2->get(i);
					if(tmp.ti>temp.ti){
						list2->insert(i,tmp);
						fl=1;
						break;
					}
				}
				if(!fl)list2->append_last(tmp);
			}
		}
		//list2->append_last(tmp);
	}
}
void output(dlink<poly>* res){
	if(res->empty()){
		cout<<0<<endl;
		return;
	}
	int tot=res->size();
	poly temp=res->get(0);
	if(temp.coe>1||temp.coe<-1)cout<<temp.coe;
	else if(temp.coe==-1)cout<<'-';
	if(temp.ti>0){
		cout<<'x';
		if(temp.ti>1)cout<<temp.ti;
	}else {
		cout<<abs(temp.coe);
	}
	for(int i=1;i<tot;i++){
		temp=res->get(i);
		if(temp.coe>0){
			putchar('+');
			if(temp.ti==1){
				if(temp.coe>1)cout<<temp.coe<<'x';
				else cout<<'x';
			}else if(temp.ti==0){
				cout<<temp.coe;
			}else {
				if(temp.coe>1)cout<<temp.coe<<'x'<<temp.ti;
				else cout<<'x'<<temp.ti;
			}
		}else if(temp.coe==-1){
			if(temp.ti>1)cout<<"-x"<<temp.ti;
			else if(temp.ti==1)cout<<"-x";
			else cout<<"-1";
		}else {
			if(temp.ti==1)cout<<temp.coe<<'x';
			else if(temp.ti==0)cout<<temp.coe;
			else cout<<temp.coe<<'x'<<temp.ti;
		}
	}
	cout<<endl;
	return;
}
//polynomial summation
void AND(dlink<poly>* list1,dlink<poly>* list2,dlink<poly>* res){
	while(list1->size()&&list2->size()){
		poly tmp1=list1->get(0),tmp2=list2->get(0),tmp;
		if(tmp1.ti==tmp2.ti){
			tmp.ti=tmp1.ti;
			tmp.coe=tmp1.coe+tmp2.coe;
			list2->del_first();
			list1->del_first();
			if(tmp.coe)res->append_last(tmp);
		}else if(tmp1.ti>tmp2.ti){
			list1->del_first();
			res->append_last(tmp1);
		}else {
			list2->del_first();
			res->append_last(tmp2);
		}
	}
	while(list1->size()){
		res->append_last(list1->get(0));
		list1->del_first();
	}
	while(list2->size()){
		res->append_last(list2->get(0));
		list2->del_first();
	}
	//output(res);
}
//polynomial subtraction
void SUB(dlink<poly>* list1,dlink<poly>* list2,dlink<poly>* res){
	while(list1->size()&&list2->size()){
		poly tmp1=list1->get(0),tmp2=list2->get(0),tmp;
		if(tmp1.ti==tmp2.ti){
			tmp.ti=tmp1.ti;
			tmp.coe=tmp1.coe-tmp2.coe;
			list2->del_first();
			list1->del_first();
			if(tmp.coe)res->append_last(tmp);
		}else if(tmp1.ti>tmp2.ti){
			list1->del_first();
			res->append_last(tmp1);
		}else {
			list2->del_first();
			tmp2.coe=-tmp2.coe;
			res->append_last(tmp2);
		}
	}
	while(list1->size()){
		res->append_last(list1->get(0));
		list1->del_first();
	}
	while(list2->size()){
		poly tt=list2->get(0);
		tt.coe=-tt.coe;
		res->append_last(tt);
		list2->del_first();
	}
	//output(res);
}
void SUBB(int coe1,dlink<poly>* list1,int coe2,int ti2,dlink<poly>* list2,dlink<poly>* res){
	while(list1->size()&&list2->size()){
		poly tmp1=list1->get(0),tmp2=list2->get(0),tmp;
		if(tmp1.ti==tmp2.ti+ti2){
			tmp.ti=tmp1.ti;
			tmp.coe=coe1*tmp1.coe-coe2*tmp2.coe;
			list2->del_first();
			list1->del_first();
			if(tmp.coe)res->append_last(tmp);
		}else if(tmp1.ti>tmp2.ti+ti2){
			list1->del_first();
			res->append_last(poly(tmp1.coe*coe1,tmp1.ti));
		}else {
			list2->del_first();
			res->append_last(poly(-coe2*tmp2.coe,tmp2.ti+ti2));
		}
	}
	while(list1->size()){
		poly ttt=list1->get(0);
		ttt.coe*=coe1;
		res->append_last(ttt);
		list1->del_first();
	}
	while(list2->size()){
		poly tt=list2->get(0);
		tt.coe*=(-coe2);
		tt.ti+=ti2;
		res->append_last(tt);
		list2->del_first();
	}
	//output(res);
}
//differentiate respectively
void DIFF(dlink<poly>* list1,dlink<poly>* list2,dlink<poly>* res){
	int tot=list1->size();
	for(int i=0;i<tot;i++){
		poly tmp=list1->get(i);
		tmp.coe*=tmp.ti;
		tmp.ti--;
		if(tmp.ti>=0)
			res->append_last(tmp);
	}
	cout<<"The first polynomial's differentiation is:"<<endl;
	output(res);
	while(!res->empty())res->del_first();
	tot=list2->size();
	for(int i=0;i<tot;i++){
		poly tmp=list2->get(i);
		tmp.coe*=tmp.ti;
		tmp.ti--;
		if(tmp.ti>=0)
			res->append_last(tmp);
	}
	cout<<"The second polynomial's differentiation is:"<<endl;
	output(res);
	return;
}
//polynomial multiply
//just naive algorithm
void MUL(dlink<poly>* list1,dlink<poly>* list2,dlink<poly>* res){
	int t1=list1->size(),t2=list2->size();
	for(int i=0;i<t1;i++){
		for(int j=0;j<t2;j++){
			poly tmp,tm1=list1->get(i),tm2=list2->get(j);
			tmp.coe=tm1.coe*tm2.coe;
			tmp.ti=tm1.ti+tm2.ti;
			res->append_last(tmp);
		}
	}
	int tot=res->size();
	for(int i=0;i<tot-1;i++){
		poly tmp=res->get(i),tmmp;
		int Max=tmp.ti,ptrmax=i;
		for(int j=i+1;j<tot;j++){
			//*************test*only************
			//cout<<"j="<<i+1<<" is begin."<<endl;
			//**********************************
			poly cur=res->get(j);
			if(Max<cur.ti){
				Max=cur.ti;
				ptrmax=j;
			}
		}
		if(ptrmax==i)continue;
		tmmp=res->get(ptrmax);
		res->del(i);
		res->insert(i,tmmp);
		res->del(ptrmax);
		res->insert(ptrmax,tmp);
	}
	for(int i=0;i<res->size()-1;i++){
		poly prev=(res->get(i)),nex=(res->get(i+1));
		if(prev.ti==nex.ti){
			res->del(i);
			prev.coe+=nex.coe;
			if(prev.coe){
				res->insert(i,prev);
				res->del(i+1);
			}else {
				res->del(i);
			}
		}
	}
	//output(res);
	return;
}
void DIV(dlink<poly>* list1,dlink<poly>* list2,dlink<poly>* res,dlink<poly>* rem){
/*

 ***********************************
 *    ATTENTION:THE POLYNOMIAL     *
 *    DIVISION IS ONLY FOR THE     *
 *     DIVISIBLE ONES WITH NO      * 
 *   FRACTION OR FLOATING POINT    *
 ***********************************

*/
	if(list2->empty()){
		cout<<"ERROR:"<<endl;
		cout<<"Division cannot be zero!"<<endl;
	}
	poly tmp1,tmp2;
	tmp1=list1->get(0);
	tmp2=list2->get(0);
	if(tmp1.ti<tmp2.ti){
		cout<<0<<endl<<"remainder:"<<endl;
		while(list1->size()){
			rem->append_last(list1->get(0));
			list1->del_first();
		}
		output(rem);
		return;
	}
	while(tmp1.ti>=tmp2.ti){
		int rescoe=tmp1.coe/tmp2.coe;
		int resti=tmp1.ti-tmp2.ti;
		int remcoe=tmp1.coe%tmp2.coe;
		int remti=tmp1.ti;
		if(rescoe)res->append_last(poly(rescoe,resti));
		if(remcoe)rem->append_last(poly(remcoe,remti));
		//copy list2 to cur2 should be optimized later
		for(int i=0;i<(list2->size());i++){
			cur2->append_last(list2->get(i));
		}
		SUBB(1,list1,rescoe,resti,cur2,cur1);
		//********test only********
		//cout<<"res:";output(res);
		//cout<<"cur:";output(cur1);
		//*************************
		while(list1->size())list1->del_first();
		while(cur1->size()){
			list1->append_last(cur1->get(0));
			cur1->del_first();
		}
		if(remcoe)
			list1->del_first();
		if(list1->size()){
			tmp1=list1->get(0);
			tmp2=list2->get(0);
		}
		else break;
	}
	while(list1->size()){
		rem->append_last(list1->get(0));
		list1->del_first();
	}
	output(res);
	cout<<"remainder:"<<endl;
	output(rem);
}
int main(){
	//freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	input();
	string s;
	cin>>s;
	if(s[0]=='A'){
		AND(list1,list2,res);
		output(res);
	}else if(s[0]=='S'){
		SUB(list1,list2,res);
		output(res);
	}else if(s[0]=='D'&&s[2]=='F'){
		DIFF(list1,list2,res);
	}else if(s[0]=='M'){
		MUL(list1,list2,res);
		output(res);
	}else if(s[0]=='D'&&s[2]=='V'){
		DIV(list1,list2,res,rem);
	}
	return 0;
}
