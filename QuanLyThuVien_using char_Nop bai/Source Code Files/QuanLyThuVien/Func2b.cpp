#include <iostream>
#include "lib.h"
#include <iomanip>
#include <string.h>

//Giao dien chinh cua Fucntion 1b - Them sach
void Func2b(int& ListSach, int MaSach[100], char TenSach[100][100], char TacGia[100][100], char NhaXB[100][100], int NamXB[100], char TheLoai[100][100], char GiaSach[100][100], int SoSach[100])
{
	while (true)
	{
		system("cls");
		//In ra dong dau: ...-------THEM SACH-------...
		for (int i = 1; i <= 23; i++) cout << "-";
		cout << "THEM SACH";
		for (int i = 1; i <= 23; i++) cout << "-";

		//Nhap ma sach (ISBN)
		cout << "\nNhap ma sach (5 so): ";
		cin >> MaSach[ListSach + 1];
		while (NumberLength(MaSach[ListSach + 1]) != 5)
		{
			XoaDong();
			cout << "Nhap ma sach (5 so): ";
			cin >> MaSach[ListSach + 1];
		}
		for (int i = 1; i <= 56; i++) cout << "-";

		//Nhap thong tin sach
		cout << endl << setw(35) << "Thong tin sach\n";
		//Nhap ten sach
		cout << "- Ten sach: ";
		cin.ignore();
		gets_s(TenSach[ListSach + 1], sizeof(TenSach[100]));
		//Nhap tac gia 
		cout << "- Tac gia: ";
		gets_s(TacGia[ListSach + 1], sizeof(TenSach[100]));
		//Nhap ten nha xuat ban
		cout << "- Nha xuat ban: ";
		gets_s(NhaXB[ListSach + 1], sizeof(NhaXB[100]));
		//Nhap nam xuat ban
		cout << "- Nam xuat ban: ";
		cin >> NamXB[ListSach + 1];
		while (NumberLength(NamXB[ListSach + 1]) != 4)
		{
			XoaDong();
			cout << "- Nam xuat ban: ";
			cin >> NamXB[ListSach + 1];
		}
			//Nhap the loai
		cout << "- The loai: ";
		cin.ignore();
		gets_s(TheLoai[ListSach + 1], sizeof(TheLoai[100]));
		FixChuoiKyTu(TheLoai[ListSach + 1]);
		XoaDong();
		cout << "- The loai: " << TheLoai[ListSach + 1] << endl;
		
		for (int i = 1; i <= 56; i++) cout << "-";

		//Nhap thong tin ban
		cout << endl;
		Spaces(22);
		cout << "Thong tin ban" << endl;
			//Nhap gia sach
		cout << "Gia sach: ";
		cin >> GiaSach[ListSach + 1];
		FixGia(GiaSach[ListSach + 1]);
		XoaDong();
		cout << "Gia sach: " << GiaSach[ListSach + 1] << endl;
			//Nhap so luong
		cout << "So luong: ";
		cin >> SoSach[ListSach + 1];
		
		//Tang so sach len 1 va in ra thanh cong
		ListSach++;	
		cout << endl;
		for (int i = 1; i <= 56; i++) cout << "-";
		cout << "\nThem sach thanh cong!\n";

		//Nhap chuc nang de tiep tuc chuong trinh
		for (int i = 1; i <= 56; i++) cout << "-";
		cout << "\n1. Them mot sach khac";
		cout << "\n2. Xem danh sach cac sach trong thu vien";
		cout << "\n0. Thoat chuc nang\n";
		char Func[2];
		cout << "> Chon mot chuc nang (VD: 1): ";
		cin >> Func;
		while (strcmp(Func, "0") != 0 && strcmp(Func, "1") != 0 && strcmp(Func, "2") != 0)
		{
			XoaDong();
			cout << "> Chon mot chuc nang (VD: 1): ";
			cin >> Func;
		}
		//Thuc hien chuc nang:
		if (strcmp(Func, "0") == 0) return;
		if (strcmp(Func, "2") == 0) { Func2a(ListSach, MaSach, TenSach, TacGia, NhaXB, NamXB, TheLoai, GiaSach, SoSach); return; }
	}
}