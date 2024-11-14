#include <iostream>
#include "lib.h"
#include <iomanip>
#include <string.h>

//Giao dien chinh cua Fucntion 1b - Them sach
void Func2b(int& ListSach, strSach Sach[100])
{
	while (true)
	{
		system("cls");
		//In ra dong dau: ...-------THEM SACH-------...
		for (int i = 1; i <= 23; i++) cout << "-";
		cout << "THEM SACH";
		for (int i = 1; i <= 23; i++) cout << "-";

#pragma region Nhap thong tin sach can them
		//Nhap ma sach (ISBN)
		cout << "\nNhap ma sach (5 so): ";
		cin >> Sach[ListSach + 1].Ma;
		while (NumberLength(Sach[ListSach + 1].Ma) != 5)
		{
			XoaDong();
			cout << "Nhap ma sach (5 so): ";
			cin >> Sach[ListSach + 1].Ma;
		}
		for (int i = 1; i <= 56; i++) cout << "-";

		//Nhap thong tin sach
		cout << endl << setw(35) << "Thong tin sach\n";
		//Nhap ten sach
		cout << "- Ten sach: ";
		cin.ignore();
		gets_s(Sach[ListSach + 1].Ten, sizeof(Sach[100].Ten));
		//Nhap tac gia 
		cout << "- Tac gia: ";
		gets_s(Sach[ListSach + 1].TacGia, sizeof(Sach[100].TacGia));
		//Nhap ten nha xuat ban
		cout << "- Nha xuat ban: ";
		gets_s(Sach[ListSach + 1].NhaXB, sizeof(Sach[100].NhaXB));
		//Nhap nam xuat ban
		cout << "- Nam xuat ban: ";
		cin >> Sach[ListSach + 1].NamXB;
		while (NumberLength(Sach[ListSach + 1].NamXB) != 4)
		{
			XoaDong();
			cout << "- Nam xuat ban: ";
			cin >> Sach[ListSach + 1].NamXB;
		}
			//Nhap the loai
		cout << "- The loai: ";
		cin.ignore();
		gets_s(Sach[ListSach + 1].TheLoai, sizeof(Sach[100].TheLoai));
		FixChuoiKyTu(Sach[ListSach + 1].TheLoai);
		XoaDong();
		cout << "- The loai: " << Sach[ListSach + 1].TheLoai << endl;
		
		for (int i = 1; i <= 56; i++) cout << "-";

		//Nhap thong tin ban
		cout << endl;
		Spaces(22);
		cout << "Thong tin ban" << endl;
			//Nhap gia sach
		cout << "Gia sach: ";
		cin >> Sach[ListSach + 1].Gia;
		FixGia(Sach[ListSach + 1].Gia);
		XoaDong();
		cout << "Gia sach: " << Sach[ListSach + 1].Gia << endl;
			//Nhap so luong
		cout << "So luong: ";
		cin >> Sach[ListSach + 1].SoLuong;

		//Tang so sach len 1 va in ra thanh cong
		ListSach++;	
		cout << endl;
		for (int i = 1; i <= 56; i++) cout << "-";
		cout << "\nThem sach thanh cong!\n";
#pragma endregion

#pragma region Nhap chuc nang de tiep tuc chuong trinh
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
		if (strcmp(Func, "2") == 0) { Func2a(ListSach, Sach); return; }
#pragma endregion
	}
}