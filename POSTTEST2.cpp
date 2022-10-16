#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
#include <conio.h>
#include <cstdlib>
using namespace std;

struct data{
	string nama;
	string posisi;
	int tinggi_badan;
	int berat_badan;
	int tahun_lahir;
};

struct Node{
	data pemain;
	struct Node* next;
};

int is_empty(Node **head){
	system("cls");
	if(*head == NULL){
		cout<<"======================================================================================================================="<<endl;
		cout<<"| No |          Nama Pemain          |         Posisi Pemain         |  Tinggi Badan  |  Berat Badan  |  Tahun Lahir  |"<<endl;
		cout<<"======================================================================================================================="<<endl;
		cout<<"| "<<setiosflags(ios::left)<<setw(3)<<"-"<<"|";
		cout<<" "<<setiosflags(ios::left)<<setw(30)<<"Kosong"<<"|";
		cout<<" "<<setiosflags(ios::left)<<setw(30)<<"Kosong"<<"|";
		cout<<" "<<setiosflags(ios::left)<<setw(15)<<"Kosong"<<"|";
		cout<<" "<<setiosflags(ios::left)<<setw(14)<<"Kosong"<<"|";
		cout<<" "<<setiosflags(ios::left)<<setw(14)<<"Kosong"<<"|"<<endl;
		cout<<"======================================================================================================================="<<endl;
		return 1;
	}
	else return 0;
}

void print_data(Node* head){
	if(head == NULL){
		is_empty(&head);
	}
	else if(head != NULL){
	int i=0;
	system("cls");
	cout<<"======================================================================================================================="<<endl;
	cout<<"| No |          Nama Pemain          |         Posisi Pemain         |  Tinggi Badan  |  Berat Badan  |  Tahun Lahir  |"<<endl;
	cout<<"======================================================================================================================="<<endl;
	while(head != NULL){
		cout<<"| "<<setiosflags(ios::left)<<setw(3)<<i+1<<"|";
		cout<<" "<<setiosflags(ios::left)<<setw(30)<<head->pemain.nama<<"|";
		cout<<" "<<setiosflags(ios::left)<<setw(30)<<head->pemain.posisi<<"|";
		cout<<" "<<setiosflags(ios::left)<<setw(12)<<head->pemain.tinggi_badan<<" cm"<<"|";
		cout<<" "<<setiosflags(ios::left)<<setw(11)<<head->pemain.berat_badan<<" kg"<<"|";
		cout<<" "<<setiosflags(ios::left)<<setw(14)<<head->pemain.tahun_lahir<<"|"<<endl;
		head = head->next;
		i++;

	}
	cout<<"======================================================================================================================="<<endl;
	}

}

void add_first(Node **head){
	system("cls");
	cout<<"============================================================"<<endl;
	cout<<"                         ADD FIRST                          "<<endl;
	cout<<"============================================================"<<endl;
	Node* nodebaru = new Node;
	cout<<"Masukkan Nama         : ";fflush(stdin);
	getline(cin,nodebaru->pemain.nama);
	cout<<"Masukkan Posisi       : ";fflush(stdin);
	getline(cin,nodebaru->pemain.posisi);
	cout<<"Masukkan Tinggi Badan : ";fflush(stdin);
	cin>>nodebaru->pemain.tinggi_badan;
	cout<<"Masukkan Berat Badan  : ";fflush(stdin);
	cin>>nodebaru->pemain.berat_badan;
	cout<<"Masukkan Tahun Lahir  : ";fflush(stdin);
	cin>>nodebaru->pemain.tahun_lahir;
	nodebaru->next = *head;
	*head = nodebaru;
}

void add_last(Node **head){
	system("cls");
	cout<<"============================================================"<<endl;
	cout<<"                         ADD LAST                           "<<endl;
	cout<<"============================================================"<<endl;
	Node* nodebaru = new Node;
	cout<<"Masukkan Nama         : ";fflush(stdin);
	getline(cin,nodebaru->pemain.nama);
	cout<<"Masukkan Posisi       : ";fflush(stdin);
	getline(cin,nodebaru->pemain.posisi);
	cout<<"Masukkan Tinggi Badan : ";fflush(stdin);
	cin>>nodebaru->pemain.tinggi_badan;
	cout<<"Masukkan Berat Badan  : ";fflush(stdin);
	cin>>nodebaru->pemain.berat_badan;
	cout<<"Masukkan Tahun Lahir  : ";fflush(stdin);
	cin>>nodebaru->pemain.tahun_lahir;
	nodebaru->next = NULL;
	
	if(*head == NULL){
		*head = nodebaru;
		return;
	}
	Node* temp = *head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = nodebaru;
}

void add_mid(Node** head){
	system("cls");
	data pemain;
	cout<<"============================================================"<<endl;
	cout<<"                       ADD MIDDLE                           "<<endl;
	cout<<"============================================================"<<endl;
	Node* nodebaru = new Node;
	Node* ptr = *head;
	int len = 0;
	cout<<"Masukkan Nama         : ";fflush(stdin);
	getline(cin,nodebaru->pemain.nama);
	cout<<"Masukkan Posisi       : ";fflush(stdin);
	getline(cin,nodebaru->pemain.posisi);
	cout<<"Masukkan Tinggi Badan : ";fflush(stdin);
	cin>>nodebaru->pemain.tinggi_badan;
	cout<<"Masukkan Berat Badan  : ";fflush(stdin);
	cin>>nodebaru->pemain.berat_badan;
	cout<<"Masukkan Tahun Lahir  : ";fflush(stdin);
	cin>>nodebaru->pemain.tahun_lahir;	
	if(*head == NULL){
		*head = nodebaru;
	}
	while(ptr != NULL){
		len++;
		ptr = ptr->next;
	}
	int count = ((len % 2)==0)?(len/2):(len+1)/2;
	ptr = *head;
	
	while(count-- > 1){
		ptr = ptr->next;
	}
	nodebaru->next = ptr->next;
	ptr->next = nodebaru;
}

void delete_first(Node** head){
	if(*head == NULL){
		cout<<"Linked List Masih Kosong !"<<endl;
		return;
	}
	*head = (*head)->next;
}

void delete_last(Node** head){
	if(*head == NULL){
		cout<<"Linked List Masih Kosong !"<<endl;
		return;
	}
	if((*head)->next == NULL){
		*head = NULL;
		return;
	}
	Node* temp = *head;
	while(temp->next->next != NULL){
		temp = temp->next;
	}
	temp->next = NULL;
}

struct Node* delete_mid(struct Node* head){
	if(head == NULL){
		cout<<"Linked List Masih Kosong !"<<endl;
		return NULL;
	}
	if(head->next == NULL){
		delete head;
		return NULL;
	}
	struct Node* slow_ptr = head;
	struct Node* fast_ptr = head;
	struct Node* prev;
	while(fast_ptr != NULL && fast_ptr->next != NULL){
		fast_ptr = fast_ptr->next->next;
		prev = slow_ptr;
		slow_ptr = slow_ptr->next;
	}
	prev->next = slow_ptr->next;
	delete slow_ptr;
	return head;
}

void update_data(Node** head){
	system("cls");
	if(*head == NULL){
		cout<<"Linked List Masih Kosong !"<<endl;
	}
	string nama;
	cout<<"================================================"<<endl
		<<"                  UPDATE DATA                   "<<endl
		<<"================================================"<<endl;
	cout<<"Masukkan Nama yang akan diubah : ";fflush(stdin);
	getline(cin,nama);
	Node *temp = (*head);
	while(temp != NULL){
		if(temp->pemain.nama == nama){
			cout<<"Masukkan Nama Baru    : ";fflush(stdin);
			getline(cin,temp->pemain.nama);
			cout<<"Masukkan Posisi Baru  : ";fflush(stdin);
			getline(cin,temp->pemain.posisi);
			cout<<"Masukkan Tinggi Badan : ";fflush(stdin);
			cin>>temp->pemain.tinggi_badan;
			cout<<"Masukkan Berat Badan  : ";fflush(stdin);
			cin>>temp->pemain.berat_badan;
			cout<<"Masukkan Tahun Lahir  : ";fflush(stdin);
			cin>>temp->pemain.tahun_lahir;
			return;	
		}
		temp = temp->next;
	}
	cout<<"Data tidak ada !"<<endl;
}
int main(){
	struct Node* HEAD = NULL;
	int menu;
	while(menu != 9){
		system("cls");
		cout<<"================================"<<endl
			<<"|          MENU UTAMA          |"<<endl
			<<"================================"<<endl
			<<"|1|Tambah Data Node Pertama    |"<<endl
			<<"|2|Tambah Data Node Tengah     |"<<endl
			<<"|3|Tambah Data Node Terakhir   |"<<endl
			<<"|4|Tampil Data                 |"<<endl
			<<"|5|Update Data                 |"<<endl
			<<"|6|Hapus Data Node Pertama     |"<<endl
			<<"|7|Hapus Data Node Tengah      |"<<endl
			<<"|8|Hapus Data Node Terakhir    |"<<endl
			<<"|9|Keluar                      |"<<endl
			<<"================================"<<endl;
		cout<<"Masukkan Pilihan Anda : ";
		cin>>menu;
		switch(menu){
			case 1 : 
				add_first(&HEAD);
				cout<<"Data Berhasil ditambahkan"<<endl
					<<"Tekan apa saja untuk kembali ke menu utama";getch();
				break;
			case 2 :
				add_mid(&HEAD);
				cout<<"Data Berhasil ditambahkan"<<endl
					<<"Tekan apa saja untuk kembali ke menu utama";getch();
				break;
			case 3 :
				add_last(&HEAD);
				cout<<"Data Berhasil ditambahkan"<<endl
					<<"Tekan apa saja untuk kembali ke menu utama";getch();
				break;
			case 4 :
				print_data(HEAD);
				cout<<"Tekan apa saja untuk kembali ke menu utama";getch();
				break;
			case 5:
				update_data(&HEAD);
				cout<<"Data Berhasil di update"<<endl;
				cout<<"Tekan apa saja untuk kembali ke menu utama";getch();
				break;
			case 6:
				system("cls");
				delete_first(&HEAD);
				print_data(HEAD);
				cout<<"Data berhasil dihapus"<<endl;
				cout<<"Tekan apa saja untuk kembali ke menu utama";getch();
				break;
			case 7:
				system("cls");
				delete_mid(HEAD);
				print_data(HEAD);
				cout<<"Data berhasil dihapus"<<endl;
				cout<<"Tekan apa saja untuk kembali ke menu utama";getch();
				break;
			case 8:
				system("cls");
				delete_last(&HEAD);
				print_data(HEAD);
				cout<<"Data berhasil dihapus"<<endl;
				cout<<"Tekan apa saja untuk kembali ke menu utama";getch();
				break;
			case 9 :
				system("cls");
				cout<<"======================================"<<endl;
				cout<<"            S A Y O N A R A           "<<endl;
				cout<<"======================================"<<endl;
				continue;
			default :
				system("cls");
				cout<<"Pilihan Tidak Ada !"<<endl
					<<"Klik apa saja untuk kembali "<<endl;
				getch();
		}
	}
	return 0;	
}
