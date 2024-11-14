#include <iostream>
#include "lib.h"
#include <iomanip>
#include <string.h>

//Giao dien chinh cua Function 2c - Chinh sua thong tin cua sach
void Func2c(int& ListSach, strSach Sach[100])
{
	while (true)
	{
		system("cls");
		//In ra dong dau: 
		for (int i = 1; i <= 15; i++) cout << "-";
		cout << "CHINH SUA THONG TIN SACH";
		for (int i = 1; i <= 16; i++) cout << "-";

#pragma region In ra danh sach sach
		//In ra dong dau chua dac diem thong tin (Ma, Ho va ten, Gioi tinh, ...)
		cout << "\nSTT" << setw(6) << "ISBN" << setw(11) << "Ten sach" << setw(31) << "Tac gia";
		cout << setw(27) << "Nha xuat ban" << setw(18) << "Nam XB" << setw(11) << "The loai" << setw(15);
		cout << "Gia sach" << setw(11) << "So luong\n";
		for (int i = 1; i <= 139; i++) cout << "-";
		cout << endl;

		//Ham in ra thong tin chi tiet cac sach trong thu vien
		InThongTinSach(ListSach, Sach);
#pragma endregion

#pragma region Nhap thong tin sach can chinh sua
		//Nhap ma sach (ISBN)
		int MaSachCanTim;
		cout << "\nNhap ma sach (5 so): ";
		cin >> MaSachCanTim;
		while (ViTri_MaSach(Sach, ListSach, MaSachCanTim) == -1)
		{
			XoaDong();
			cout << "Nhap ma sach (5 so): ";
			cin >> MaSachCanTim;
		}
		for (int i = 1; i <= 56; i++) cout << "-";

		//Bien luu vi tri cua sach
		int ViTriSach = ViTri_MaSach(Sach, ListSach, MaSachCanTim);

		//Nhap thong tin sach
		cout << endl << setw(35) << "Thong tin sach\n";
			//Nhap ten sach
		cout << "- Ten sach: ";
		cin.ignore();
		gets_s(Sach[ViTriSach].Ten, sizeof(Sach[100].Ten));
			//Nhap tac gia 
		cout << "- Tac gia: ";
		gets_s(Sach[ViTriSach].TacGia, sizeof(Sach[100].Ten));
			//Nhap ten nha xuat ban
		cout << "- Nha xuat ban: ";
		gets_s(Sach[ViTriSach].NhaXB, sizeof(Sach[100].NhaXB));
			//Nhap nam xuat ban
		cout << "- Nam xuat ban: ";
		cin >> Sach[ViTriSach].NamXB;
		while (NumberLength(Sach[ViTriSach].NamXB) != 4)
		{
			XoaDong();
			cout << "- Nam xuat ban: ";
			cin >> Sach[ViTriSach].NamXB;
		}
			//Nhap the loai
		cout << "- The loai: ";
		cin.ignore();
		gets_s(Sach[ViTriSach].TheLoai, sizeof(Sach[100].TheLoai));
		FixChuoiKyTu(Sach[ViTriSach].TheLoai);
		XoaDong();
		cout << "- The loai: " << Sach[ViTriSach].TheLoai << endl;

		for (int i = 1; i <= 56; i++) cout << "-";

		//Nhap thong tin ban
		cout << endl;
		Spaces(22);
		cout << "Thong tin ban" << endl;
			//Nhap gia sach
		cout << "Gia sach: ";
		cin >> Sach[ViTriSach].Gia;
		FixGia(Sach[ViTriSach].Gia);
		XoaDong();
		cout << "Gia sach: " << Sach[ViTriSach].Gia << endl;
			//Nhap so luong
		cout << "So luong: ";
		cin >> Sach[ViTriSach].SoLuong;
#pragma endregion

		//In ra thanh cong
		cout << endl;
		for (int i = 1; i <= 56; i++) cout << "-";
		cout << "\nChinh sua sach thanh cong!\n";

#pragma region Nhap chuc nang de tiep tuc chuong trinh
		//Nhap chuc nang de tiep tuc chuong trinh
		for (int i = 1; i <= 56; i++) cout << "-";
		cout << "\n1. Chinh sua mot sach khac";
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

int ViTri_MaSach(strSach Sach[100], int SoLuongPhanTu, int GiaTriCanTim)
{
	for (int i = 1; i <= SoLuongPhanTu; i++)
	{
		if (Sach[i].Ma == GiaTriCanTim) return i;
	}
	return -1;
}