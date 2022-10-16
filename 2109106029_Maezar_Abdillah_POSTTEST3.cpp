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

Node *SortedMergeDescTB(Node *a, Node *b);
Node *SortedMergeAscTB(Node *a, Node *b);
Node *SortedMergeDescBB(Node *a, Node *b);
Node *SortedMergeAscBB(Node *a, Node *b);
Node *SortedMergeDescTL(Node *a, Node *b);
Node *SortedMergeAscTL(Node *a, Node *b);
void FrontBackSplit(Node *source,Node **frontRef, Node **backRef);

void MergeSortDescTB(Node **headRef){
	Node *head = *headRef;
	Node *a;
	Node *b;
	if ((head == NULL) || (head->next == NULL)){
		return;
	}
	FrontBackSplit(head, &a, &b);
	MergeSortDescTB(&a);
	MergeSortDescTB(&b);
	*headRef = SortedMergeDescTB(a, b);
}

void MergeSortAscTB(Node **headRef){
	Node *head = *headRef;
	Node *a;
	Node *b;
	if ((head == NULL) || (head->next == NULL)){
		return;
	}
	FrontBackSplit(head, &a, &b);
	MergeSortAscTB(&a);
	MergeSortAscTB(&b);
	*headRef = SortedMergeAscTB(a, b);
}

void MergeSortDescBB(Node **headRef){
	Node *head = *headRef;
	Node *a;
	Node *b;
	if ((head == NULL) || (head->next == NULL)){
		return;
	}
	FrontBackSplit(head, &a, &b);
	MergeSortDescBB(&a);
	MergeSortDescBB(&b);
	*headRef = SortedMergeDescBB(a, b);
}

void MergeSortAscBB(Node **headRef){
	Node *head = *headRef;
	Node *a;
	Node *b;
	if ((head == NULL) || (head->next == NULL)){
		return;
	}
	FrontBackSplit(head, &a, &b);
	MergeSortAscBB(&a);
	MergeSortAscBB(&b);
	*headRef = SortedMergeAscBB(a, b);
}

void MergeSortDescTL(Node **headRef){
	Node *head = *headRef;
	Node *a;
	Node *b;
	if ((head == NULL) || (head->next == NULL)){
		return;
	}
	FrontBackSplit(head, &a, &b);
	MergeSortDescTL(&a);
	MergeSortDescTL(&b);
	*headRef = SortedMergeDescTL(a, b);
}

void MergeSortAscTL(Node **headRef){
	Node *head = *headRef;
	Node *a;
	Node *b;
	if ((head == NULL) || (head->next == NULL)){
		return;
	}
	FrontBackSplit(head, &a, &b);
	MergeSortAscTL(&a);
	MergeSortAscTL(&b);
	*headRef = SortedMergeAscTL(a, b);
}

Node *SortedMergeDescTB(Node *a, Node *b){
	Node *result = NULL;

	if (a == NULL)
		return (b);
		else if (b == NULL)
		return (a);

	if (a->pemain.tinggi_badan >= b->pemain.tinggi_badan){
		result = a;
		result->next = SortedMergeDescTB(a->next, b);
	}else{
		result = b;
		result->next = SortedMergeDescTB(a, b->next);
	}
	return (result);
}

Node *SortedMergeAscTB(Node *a, Node *b){
	Node *result = NULL;

	if (a == NULL)
		return (b);
		else if (b == NULL)
		return (a);

	if (a->pemain.tinggi_badan <= b->pemain.tinggi_badan){
		result = a;
		result->next = SortedMergeAscTB(a->next, b);
	}else{
		result = b;
		result->next = SortedMergeAscTB(a, b->next);
	}
	return (result);
}

Node *SortedMergeDescBB(Node *a, Node *b){
	Node *result = NULL;

	if (a == NULL)
		return (b);
		else if (b == NULL)
		return (a);

	if (a->pemain.berat_badan >= b->pemain.berat_badan){
		result = a;
		result->next = SortedMergeDescBB(a->next, b);
	}else{
		result = b;
		result->next = SortedMergeDescBB(a, b->next);
	}
	return (result);
}

Node *SortedMergeAscBB(Node *a, Node *b){
	Node *result = NULL;

	if (a == NULL)
		return (b);
		else if (b == NULL)
		return (a);

	if (a->pemain.berat_badan <= b->pemain.berat_badan){
		result = a;
		result->next = SortedMergeAscBB(a->next, b);
	}else{
		result = b;
		result->next = SortedMergeAscBB(a, b->next);
	}
	return (result);
}

Node *SortedMergeDescTL(Node *a, Node *b){
	Node *result = NULL;

	if (a == NULL)
		return (b);
		else if (b == NULL)
		return (a);

	if (a->pemain.tahun_lahir >= b->pemain.tahun_lahir){
		result = a;
		result->next = SortedMergeDescTL(a->next, b);
	}else{
		result = b;
		result->next = SortedMergeDescTL(a, b->next);
	}
	return (result);
}

Node *SortedMergeAscTL(Node *a, Node *b){
	Node *result = NULL;

	if (a == NULL)
		return (b);
		else if (b == NULL)
		return (a);

	if (a->pemain.tahun_lahir <= b->pemain.tahun_lahir){
		result = a;
		result->next = SortedMergeAscTL(a->next, b);
	}else{
		result = b;
		result->next = SortedMergeAscTL(a, b->next);
	}
	return (result);
}

void FrontBackSplit(Node *source,Node **frontRef, Node **backRef){
	Node *fast;
	Node *slow;
	slow = source;
	fast = source->next;
	while (fast != NULL){
		fast = fast->next;
		if (fast != NULL){
			slow = slow->next;
			fast = fast->next;
		}
	}

	*frontRef = source;
	*backRef = slow->next;
	slow->next = NULL;
}

void tambah(Node **head){
	int pil;
	while(pil != 4){
	system("cls");
	cout<<"============================="<<endl
		<<"|        TAMBAH DATA        |"<<endl
		<<"============================="<<endl
		<<"|1|Tambah Data Pertama      |"<<endl
		<<"|2|Tambah Data Tengah       |"<<endl
		<<"|3|Tambah Data Terakhir     |"<<endl
		<<"|4|Kembali Ke Menu Utama    |"<<endl
		<<"============================="<<endl;
	cout<<"Masukkan Pilihan Anda : ";
	cin>>pil;
	switch(pil){
		case 1 :
			add_first(head);
			cout<<"Data Berhasil ditambahkan"<<endl
				<<"Tekan apa saja untuk kembali ";getch();
			break;
		case 2 :
			add_mid(head);
			cout<<"Data Berhasil ditambahkan"<<endl
				<<"Tekan apa saja untuk kembali ";getch();
			break;
		case 3 :
			add_last(head);
			cout<<"Data Berhasil ditambahkan"<<endl
				<<"Tekan apa saja untuk kembali ";getch();
			break;
		case 4 :
			continue;
		default:
			system("cls");
			cout<<"Pilihan Tidak Ada !"<<endl
				<<"Klik apa saja untuk kembali "<<endl;
			getch();
	}
	}
		
}

void hapus(Node **head){
	system("cls");
	Node* HEAD = *head;
	while(HEAD->next != NULL){
		HEAD = HEAD->next;
	}
	int pil;
	while(pil != 4){
		system("cls");
		cout<<"============================="<<endl
			<<"|        HAPUS DATA         |"<<endl
			<<"============================="<<endl
			<<"|1|Hapus Data Pertama       |"<<endl
			<<"|2|Hapus Data Tengah        |"<<endl
			<<"|3|Hapus Data Terakhir      |"<<endl
			<<"|4|Kembali Ke Menu Utama    |"<<endl
			<<"============================="<<endl;
		cout<<"Masukkan Pilihan Anda : ";
		cin>>pil;
		switch(pil){
			case 1 :
				delete_first(head);
				cout<<"Data Berhasil dihapus"<<endl
					<<"Tekan apa saja untuk kembali ";getch();
				break;
			case 2 :
				delete_mid(HEAD);
				cout<<"Data Berhasil dihapus"<<endl
					<<"Tekan apa saja untuk kembali ";getch();
				break;
			case 3 :
				delete_last(head);
				cout<<"Data Berhasil dihapus"<<endl
					<<"Tekan apa saja untuk kembali ";getch();
				break;
			case 4 :
				continue;
			default:
				system("cls");
				cout<<"Pilihan Tidak Ada !"<<endl
					<<"Klik apa saja untuk kembali "<<endl;
				getch();
			}
		}
	
}

void sort(Node** head){
	system("cls");
	Node* HEAD = *head;
	while(HEAD->next != NULL){
		HEAD = HEAD->next;
	}
	int pil;
	int pilih;
	while(pil != 4){
		system("cls");
		cout<<"==================================="<<endl
			<<"|           SORTING DATA          |"<<endl
			<<"==================================="<<endl
			<<"|1|Sort Berdasarkan Tinggi Badan  |"<<endl
			<<"|2|Sort Berdasarkan Berat Badan   |"<<endl
			<<"|3|Sort Berdasarkan Tahun Lahir   |"<<endl
			<<"|4|Kembali Ke Menu Utama          |"<<endl
			<<"==================================="<<endl
			<<"Masukkan Pilihan Anda : ";
			cin>>pil;
			switch(pil){
				case 1 :
					while(pilih != 3){
						system("cls");
						cout<<"========================"<<endl
							<<"|   SORT TINGGI BADAN   |"<<endl
							<<"========================="<<endl
							<<"|1|Ascending            |"<<endl
							<<"|2|Descending           |"<<endl
							<<"|3|Kembali              |"<<endl
							<<"========================"<<endl
							<<"Masukkan Pilihan Anda : ";
							cin>>pilih;
							switch(pilih){
								case 1 :
									MergeSortAscTB(head);
									print_data(HEAD);
									cout<<"Data Berhasil Tersorting"<<endl;
									cout<<"Tekan apa saja untuk kembali ";getch();
									break;
								case 2 :
									MergeSortDescTB(head);
									print_data(HEAD);
									cout<<"Data Berhasil Tersorting"<<endl;
									cout<<"Tekan apa saja untuk kembali ";getch();
									break;
								case 3 :
									continue;
								default:
									system("cls");
									cout<<"Pilihan Tidak Ada !"<<endl
										<<"Klik apa saja untuk kembali "<<endl;
									getch();	
							}		
					}
					break;
				case 2 :
					while(pilih != 3){
						system("cls");
						cout<<"========================"<<endl
							<<"|   SORT BERAT BADAN    |"<<endl
							<<"========================="<<endl
							<<"|1|Ascending            |"<<endl
							<<"|2|Descending           |"<<endl
							<<"|3|Kembali              |"<<endl
							<<"========================"<<endl
							<<"Masukkan Pilihan Anda : ";
							cin>>pilih;
							switch(pilih){
								case 1 :
									MergeSortAscBB(head);
									print_data(HEAD);
									cout<<"Data Berhasil Tersorting"<<endl;
									cout<<"Tekan apa saja untuk kembali ";getch();
									break;
								case 2 :
									MergeSortDescBB(head);
									print_data(HEAD);
									cout<<"Data Berhasil Tersorting"<<endl;
									cout<<"Tekan apa saja untuk kembali ";getch();
									break;
								case 3 :
									continue;
								default:
									system("cls");
									cout<<"Pilihan Tidak Ada !"<<endl
										<<"Klik apa saja untuk kembali "<<endl;
									getch();	
							}		
					}
					break;
				case 3 :
					while(pilih != 3){
						system("cls");
						cout<<"========================"<<endl
							<<"|   SORT TAHUN LAHIR    |"<<endl
							<<"========================="<<endl
							<<"|1|Ascending            |"<<endl
							<<"|2|Descending           |"<<endl
							<<"|3|Kembali              |"<<endl
							<<"========================"<<endl
							<<"Masukkan Pilihan Anda : ";
							cin>>pilih;
							switch(pilih){
								case 1 :
									MergeSortAscTL(head);
									print_data(HEAD);
									cout<<"Data Berhasil Tersorting"<<endl;
									cout<<"Tekan apa saja untuk kembali ";getch();
									break;
								case 2 :
									MergeSortDescTL(head);
									print_data(HEAD);
									cout<<"Data Berhasil Tersorting"<<endl;
									cout<<"Tekan apa saja untuk kembali ";getch();
									break;
								case 3 :
									continue;
								default:
									system("cls");
									cout<<"Pilihan Tidak Ada !"<<endl
										<<"Klik apa saja untuk kembali "<<endl;
									getch();	
							}		
					}
					break;
				case 4 :
					continue;
				default:
					system("cls");
					cout<<"Pilihan Tidak Ada !"<<endl
						<<"Klik apa saja untuk kembali "<<endl;
					getch();
			}
	}
}

int main(){
	struct Node* HEAD = NULL;
	int menu;
	while(menu != 6){
		system("cls");
		cout<<"============================"<<endl
			<<"|        MENU UTAMA        |"<<endl
			<<"============================"<<endl
			<<"|1|Tambah Data             |"<<endl
			<<"|2|Tampil Data             |"<<endl
			<<"|3|Hapus Data              |"<<endl
			<<"|4|Update Data             |"<<endl
			<<"|5|Sorting Data            |"<<endl
			<<"|6|Keluar Dari Program     |"<<endl
			<<"============================"<<endl
			<<"Masukkan Pilihan Anda : ";
			cin>>menu;
			switch(menu){
				case 1 :
					tambah(&HEAD);
					break;
				case 2 :
					print_data(HEAD);
					cout<<"Tekan apa saja untuk kembali ke menu utama";getch();
					break;
				case 3 :
					hapus(&HEAD);
					break;
				case 4 :
					update_data(&HEAD);
					cout<<"Data Berhasil di update"<<endl;
					cout<<"Tekan apa saja untuk kembali ke menu utama";getch();
					break;
				case 5 :
					sort(&HEAD);
					break;
				case 6 :
					system("cls");
					cout<<"======================================"<<endl;
					cout<<"            S A Y O N A R A           "<<endl;
					cout<<"======================================"<<endl;
					continue;
				default:
					system("cls");
					cout<<"Pilihan Tidak Ada !"<<endl
						<<"Klik apa saja untuk kembali "<<endl;
					getch();
			}
	}
	return 0;
}
