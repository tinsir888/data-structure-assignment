#include<iostream>
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
	T get_first(T t);
	T get_last(T t);

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
		cout<<"failed! the index in out of bound"<<endl;
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
int main(){
    // 创建双向链表
    dlink<int>* pdlink = new dlink<int>();

    pdlink->insert(0, 20);        // 将 20 插入到第一个位置
    pdlink->append_last(10);    // 将 10 追加到链表末尾
    pdlink->insert_first(30);    // 将 30 插入到第一个位置
	pdlink->del(0);
    // 双向链表是否为空
    cout << "is_empty()=" << pdlink->empty() <<endl;
    // 双向链表的大小
    cout << "size()=" << pdlink->size() <<endl;

    // 打印双向链表中的全部数据
    int sz = pdlink->size();
    for (int i=0; i<sz; i++)
        cout << "pdlink("<<i<<")=" << pdlink->get(i) <<endl;
}
