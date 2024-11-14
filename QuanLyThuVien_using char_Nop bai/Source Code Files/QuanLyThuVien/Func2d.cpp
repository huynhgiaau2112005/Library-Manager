#include <iostream>
#include "lib.h"
#include <iomanip>

using namespace std;

void Func2d(int& ListSach, int MaSach[100], char TenSach[100][100], char TacGia[100][100], char NhaXB[100][100], int NamXB[100], char TheLoai[100][100], char GiaSach[100][100], int SoSach[100])
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
		InThongTinSach(ListSach, MaSach, TenSach, TacGia, NhaXB, NamXB, TheLoai, GiaSach, SoSach);
#pragma endregion

#pragma region Nhap sach can xoa va Xoa sach
		//Nhap ma sach (ISBN) can xoa
		cout << endl;
		cout << "Nhap ma sach (5 so): ";
		int MaSachTimKiem;
		cin >> MaSachTimKiem;
		while (TimKiemViTri(MaSach, ListSach, MaSachTimKiem) == -1) //Kiem tra xem ma doc gia co ton tai khong
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
			int ViTriDocGia = TimKiemViTri(MaSach, ListSach, MaSachTimKiem);
			//Xoa ma sach
			XoaThongTin(ListSach, MaSach, ViTriDocGia);
			//Xoa ten sach
			XoaThongTin(ListSach, TenSach, ViTriDocGia);
			//Xoa tac gia
			XoaThongTin(ListSach, TacGia, ViTriDocGia);
			//Xoa nha xuat ban
			XoaThongTin(ListSach, NhaXB, ViTriDocGia);
			//Xoa nam xuat ban
			XoaThongTin(ListSach, NamXB, ViTriDocGia);
			//Xoa the loai
			XoaThongTin(ListSach, TheLoai, ViTriDocGia);
			//Xoa gia sach
			XoaThongTin(ListSach, GiaSach, ViTriDocGia);
			//Xoa so luong sach
			XoaThongTin(ListSach, SoSach, ViTriDocGia);
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
		if (strcmp(Func, "2") == 0) { Func2a(ListSach, MaSach, TenSach, TacGia, NhaXB, NamXB, TheLoai, GiaSach, SoSach); return; }
#pragma endregion
	}
}