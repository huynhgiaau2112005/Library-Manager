#include <iostream>
#include "lib.h"
#include <iomanip>

using namespace std;

void Func2d(int& ListSach, strSach Sach[100])
{
	while (true)
	{
		system("cls");
		//In ra dong dau
		for (int i = 1; i <= 19; i++) cout << "-";
		cout << "XOA THONG TIN SACH";
		for (int i = 1; i <= 20; i++) cout << "-";

#pragma region In ra danh sach cac sach
		//In ra dong dau chua dac diem thong tin (Ma, Ho va ten, Gioi tinh, ...)
		cout << "\nSTT" << setw(6) << "ISBN" << setw(11) << "Ten sach" << setw(31) << "Tac gia";
		cout << setw(27) << "Nha xuat ban" << setw(18) << "Nam XB" << setw(11) << "The loai" << setw(15);
		cout << "Gia sach" << setw(11) << "So luong\n";
		for (int i = 1; i <= 139; i++) cout << "-";
		cout << endl;

		//Ham in ra thong tin chi tiet cac sach trong thu vien
		InThongTinSach(ListSach, Sach);
#pragma endregion

#pragma region Nhap sach can xoa va Xoa sach
		//Nhap ma sach (ISBN) can xoa
		cout << endl;
		cout << "Nhap ma sach (5 so): ";
		int MaSachTimKiem;
		cin >> MaSachTimKiem;
		while (ViTri_MaSach(Sach, ListSach, MaSachTimKiem) == -1) //Kiem tra xem ma doc gia co ton tai khong
		{
			XoaDong();
			cout << "Nhap ma sach (5 so): ";
			cin >> MaSachTimKiem;
		}

		//Xac nhan xoa
		cout << "> Xac nhan xoa [Y/N]: ";
		char XacNhan;
		cin.ignore();
		cin >> XacNhan;
		while (XacNhan != 'Y' && XacNhan != 'N')
		{
			XoaDong();
			cout << "> Xac nhan xoa [Y/N]: ";
			cin >> XacNhan;
		}
		if (XacNhan == 'Y')
		{
			int ViTriSach = ViTri_MaSach(Sach, ListSach, MaSachTimKiem);
			//Xoa thong tin sach
			XoaThongTin(ListSach, Sach, ViTriSach);
			//Giam so luong sach
			ListSach--;
			for (int i = 1; i <= 60; i++) cout << "-";
			cout << "\nXoa sach thanh cong!\n";
			for (int i = 1; i <= 60; i++) cout << "-";
		}
		else
		{
			for (int i = 1; i <= 60; i++) cout << "-";
			cout << "\nDa huy thao tac.\n";
			for (int i = 1; i <= 60; i++) cout << "-";
		}
#pragma endregion

#pragma region Nhap chuc nang de tiep tuc chuong trinh
		//Nhap chuc nang de tiep tuc chuong trinh
		cout << "\n1. Xoa mot sach khac";
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

void XoaThongTin(int& SoLuong, strSach Sach[100], int ViTriXoa)
{
	for (int i = ViTriXoa; i <= SoLuong - 1; i++)
	{
		Sach[i].Ma = Sach[i + 1].Ma;
		Sach[i].NamXB = Sach[i + 1].NamXB;
		Sach[i].SoLuong = Sach[i + 1].SoLuong;
		strcpy_s(Sach[i].Gia, sizeof(Sach[i].Gia), Sach[i + 1].Gia);
		strcpy_s(Sach[i].NhaXB, sizeof(Sach[i].NhaXB), Sach[i + 1].NhaXB);
		strcpy_s(Sach[i].TacGia, sizeof(Sach[i].TacGia), Sach[i + 1].TacGia);
		strcpy_s(Sach[i].Ten, sizeof(Sach[i].Ten), Sach[i + 1].Ten);
		strcpy_s(Sach[i].TheLoai, sizeof(Sach[i].TheLoai), Sach[i + 1].TheLoai);
	}
}