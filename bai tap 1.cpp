#include<iostream>
using namespace std;
struct PhanSo{
	int tu,mau;
};
void Nhap(struct PhanSo &ps){
	cout<<"Nhap tu: ";
	cin>>ps.tu;
	do{
		cout<<"Nhap mau: ";
		cin>>ps.mau;
	}while(ps.mau==0);	
}
void Xuat(struct PhanSo ps){
	if(ps.tu==0)
		cout<<"0";
	else if(ps.mau==1)
		cout<<ps.tu;
	else if(ps.mau==ps.tu)
		cout<<"1";
	else
		cout<<ps.tu<<"/"<<ps.mau<<endl;
}
void Tong(struct PhanSo ps1, struct PhanSo ps2){
	struct PhanSo ps3;
	ps3.tu=ps1.tu*ps2.mau+ps1.mau*ps2.tu;
	ps3.mau=ps1.mau*ps2.mau;
	cout<<"Tong hai phan so la: ";
	Xuat(ps3);
}
void Hieu(struct PhanSo ps1, struct PhanSo ps2){
	struct PhanSo ps4;
	ps4.tu=ps1.tu*ps2.mau-ps2.tu*ps1.mau;
	ps4.mau=ps1.mau*ps2.mau;
	cout<<"Hieu hai phan so la: ";
	Xuat(ps4);
}
void Tich(struct PhanSo ps1, struct PhanSo ps2){
	struct PhanSo ps5;
	ps5.tu=ps1.tu*ps2.tu;
	ps5.mau=ps1.mau*ps2.mau;
	cout<<"Tich hai phan so la: ";
	Xuat(ps5);
}
void Thuong(struct PhanSo ps1, struct PhanSo ps2){
	struct PhanSo ps6;
	ps6.tu=ps1.tu*ps2.mau;
	ps6.mau=ps1.mau*ps2.tu;
	cout<<"Thuong hai phan so la: ";
	Xuat(ps6);
}
int main(){
	struct PhanSo ps1, ps2;
	Nhap(ps1);
	Nhap(ps2);
	cout<<"Phan so thu 1 la: ";
	Xuat(ps1);
	cout<<"Phan so thu 2 la: ";
	Xuat(ps2);
	Tong(ps1,ps2);
	Hieu(ps1,ps2);
	Tich(ps1,ps2);
	Thuong(ps1,ps2);
	
}
