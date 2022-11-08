#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node*next;
};	

typedef struct Node* node;
node Createnode(int x)
{
	node p=new Node;
	p->data=x;
	p->next=NULL;
	return p;
} 

bool empty(node a)
{
	return a==NULL;
}
int size(node a)
{
	int dem=0;
	while(a!=NULL){
		dem++;
		a=a->next;
	}
return dem;
}

void addFirst(node &a, int x)
{
	node tmp=Createnode(x);
	if (a==NULL)
	{
		a=tmp;
	}
	else{
		tmp->next=a;
		a=tmp;
	}
}

void addLast(node &a, int x)
{
	node tmp=Createnode(x);
	if (a==NULL)
	{
		a=tmp;
	}
	else{
		node p=a;
		while(p->next!=NULL){
			p=p->next;
		}
		p->next=tmp;
	}
}

void addMid(node &a,int x,int pos)
{
	int n=size(a);
	if(pos<0||pos>n+1){
		cout<<"Vi tri chen vao khong hop le! \n";
	}
	if(n==1){
		addFirst(a,x);return;
	}
	else if(n==pos+1)
	{
		addLast(a,x);return;
	}
	node p=a;
	for(int i=1; i<pos-1; i++){
		p=p->next;
	}
	node tmp=Createnode(x);
	tmp->next=p->next;
	p->next=tmp;
}

void removeFirst(node &a){
	if (a==NULL) return;
	a=a->next;
}

void removeLast(node &a){
	if (a==NULL) return;
	node truoc = NULL, sau = a;
	while(sau->next != NULL){
		truoc = sau;
		sau = sau->next;
	}
	if(truoc == NULL){
		a = NULL;
	}
	else{
		truoc->next = NULL;
	}	
}

void removeMid(node &a, int pos){
	if(pos <=0 || pos > size(a)) return;
	node truoc = NULL, sau = a;
	for(int i = 1; i < pos; i++){
		truoc = sau;
		sau = sau->next;
	}
	if(truoc == NULL){
		a = a->next;
	}
	else{
		truoc->next = sau->next;
	}
}

void in(node a){
	cout << "--------------------------------\n";
	while(a != NULL){
		cout << a->data << " ";
		a = a->next;
	}
	cout << endl;
	cout << "--------------------------------\n";
}
 
int main()
{
	node head=NULL;
	while(1){
		cout << "-----------------MENU---------------\n";
		cout << "1. Chen phan tu vao dau danh sach\n";
		cout << "2. Chen phan tu vao cuoi danh sach\n";
		cout << "3. Chen phan tu vao giua danh sach\n";
		cout << "4. Xoa phan tu o dau\n";
		cout << "5. Xoa phan tu o cuoi\n";
		cout << "6. Xoa phan tu o giua\n";
		cout << "7. Duyet danh sach lient ket\n";
//		cout << "8. Sap xep cac phan tu trong dslk\n";
		cout << "0. Thoat !\n";
		cout << "-------------------------------------\n";
		cout << "Nhap lua chon :";
		int lc; cin >> lc;
		if(lc == 1){
			int x; cout << "Nhap gia tri can chen :"; cin >> x;
			addFirst(head, x);
		}
		else if(lc == 2){
			int x; cout << "Nhap gia tri can chen :"; cin >> x;
			addLast(head, x);
		}
		else if(lc == 3){
			int x; cout << "Nhap gia tri can chen :"; cin >> x;
			int pos; cout << "Nhap vi tri can chen :"; cin >> pos;
			addMid(head, x, pos);
		}
		else if(lc == 4){
			removeFirst(head);
		}
		else if(lc == 5){
			removeLast(head);
		}
		else if(lc == 6){
			int pos; cout << "Nhap vi tri can xoa:"; cin >> pos;
			removeMid(head, pos);
		}
		else if(lc == 7){
			in(head);
		}
//		else if(lc == 8){
//			sapxep(head);
//		}
		else if(lc == 0){
			break;
		}
	}
	return 0;
}
