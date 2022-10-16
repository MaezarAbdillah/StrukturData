#include <iostream>
#include <cstdlib>
using namespace std;
struct data{
	string nama;
	string posisi;
	int tinggi_badan;
	int berat_badan;
	int tahun_lahir;
};
int index = 0;
data pemain[20];
data* ptrpemain[20]={&pemain[0],&pemain[1],&pemain[2],&pemain[3],&pemain[4],
					&pemain[5],&pemain[6],&pemain[7],&pemain[8],&pemain[9],
					&pemain[10],&pemain[11],&pemain[12],&pemain[13],&pemain[14],
					&pemain[15],&pemain[16],&pemain[17],&pemain[18],&pemain[19]};

string loop;
void tampil(){
	if(index>0){
	system("cls");
	for(int i=0;i<index;i++){
		cout<<"==================================="<<endl;
		cout<<"Data Pemain ke-"<<i+1<<endl;
		cout<<"==================================="<<endl;
		cout<<"Nama : "<<ptrpemain[i]->nama<<endl;
		cout<<"Posisi : "<<ptrpemain[i]->posisi<<endl;
		cout<<"Tinggi Badan : "<<ptrpemain[i]->tinggi_badan<<endl;
		cout<<"Berat Badan : "<<ptrpemain[i]->berat_badan<<endl;
		cout<<"Tahun Lahir : "<<ptrpemain[i]->tahun_lahir<<endl;
	}
	}else{
		cout<<"Data masih kosong, silahkan isi data terlebih dahulu"<<endl;
	}
}
void add(){
	do{
	system("cls");
	cout<<"Nama : ";fflush(stdin);
	getline(cin,ptrpemain[index]->nama);
	cout<<"Posisi : ";fflush(stdin);
	getline(cin,ptrpemain[index]->posisi);
	cout<<"Tinggi Badan : ";fflush(stdin);
	cin>>ptrpemain[index]->tinggi_badan;
	cout<<"Berat Badan : ";fflush(stdin);
	cin>>ptrpemain[index]->berat_badan;
	cout<<"Tahun Lahir : ";fflush(stdin);
	cin>>ptrpemain[index]->tahun_lahir;
	index++;
	tampil();
	cout<<"klik y untuk isi lagi\n";
	cout<<"klik t untuk kembali ke menu utama ";
	cin>>loop;
	}while(loop=="y");
}

void update(){
	system("cls");
	int update;
	do{
	if(index>0){
		tampil();
		cout<<"Update data ke : ";
		cin>>update;
		cout<<"Nama : ";fflush(stdin);
		getline(cin,ptrpemain[update-1]->nama);
		cout<<"Posisi : ";fflush(stdin);
		getline(cin,ptrpemain[update-1]->posisi);
		cout<<"Tinggi Badan : ";fflush(stdin);
		cin>>ptrpemain[update-1]->tinggi_badan;
		cout<<"Berat Badan : ";fflush(stdin);
		cin>>ptrpemain[update-1]->berat_badan;
		cout<<"Tahun Lahir : ";fflush(stdin);
		cin>>ptrpemain[update-1]->tahun_lahir;
		tampil();
		cout<<"klik y untuk update lagi \n";
		cout<<"klik t untuk kembali ke menu utama ";
		cin>>loop;
	}else{
		cout<<"Data masih kosong, silahkan isi data terlebih dahulu"<<endl;
		cout<<"klik t untuk kembali ke menu utama ";
		cin>>loop;
	}
	}while(loop=="y");
	
}
void del(){
	system("cls");
	int del;
	do{
		if(index>0){
			tampil();
			cout<<"Delete data ke : ";
			cin>>del;
			for(int i=del;i<index;i++){
				ptrpemain[i-1]->nama=ptrpemain[i]->nama;
				ptrpemain[i-1]->posisi=ptrpemain[i]->posisi;
				ptrpemain[i-1]->tinggi_badan=ptrpemain[i]->tinggi_badan;
				ptrpemain[i-1]->berat_badan=ptrpemain[i]->berat_badan;
				ptrpemain[i-1]->tahun_lahir=ptrpemain[i]->tahun_lahir;
			}
			index--;
			tampil();
			cout<<"klik y untuk hapus lagi\nklik t untuk kembali ke menu utama  ";
			cin>>loop;
		}else{
			cout<<"Tidak ada data yang bisa dihapus, karena data masih kosong"<<endl;
			cout<<"klik t untuk kembali ke menu utama ";
			cin>>loop;
		}
	}while(loop=="y");
}
int main(){
	do{
		system("cls");
		int pilih;
		cout<<"========================"<<endl;
		cout<<"|      MENU UTAMA      |"<<endl;
		cout<<"========================"<<endl;
		cout<<"|1|Create Data         |"<<endl;
		cout<<"|2|Read Data           |"<<endl;
		cout<<"|3|Update Data         |"<<endl;
		cout<<"|4|Delete Data         |"<<endl;
		cout<<"|5|Exit Program        |"<<endl;
		cout<<"========================"<<endl;
		cout<<"Masukkan Pilihan Anda : ";
		cin>>pilih;
		switch(pilih){
			case 1:
				add();
				break;
			case 2:
				do{
					system("cls");
					tampil();
					cout<<"Kembali ke menu utama klik (t) ";
					cin>>loop;
				}while(loop!="t");
				break;
			case 3:
				update();
				break;
			case 4:
				del();
				break;
			case 5:
				system("cls");
				cout<<"Terimakasih telah menggunakan program ini"<<endl;
				exit(EXIT_SUCCESS);
				break;
		}
	}while(loop=="t");
	return 0;
}
