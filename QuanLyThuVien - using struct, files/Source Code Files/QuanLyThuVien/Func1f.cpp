#include <iostream>
#include "lib.h"
#include <iomanip>
#include <string.h>

using namespace std;

//Giao dien chinh cua Function 1e - Tim kiem doc gia theo ho va ten
void Func1f(int& SoDocGia, strDocGia DocGia[100])
{
	while (true)
	{
#pragma region Truoc tra cuu
		//DESIGN GIAO DIEN
		system("cls");
		for (int i = 1; i <= 77; i++) cout << "-";
		cout << "TIM KIEM DOC GIA";
		for (int i = 1; i <= 78; i++) cout << "-";

		//In ra dong dau chua dac diem thong tin (Ma, Ho va ten, Gioi tinh, ...)
		cout << "\nSTT" << setw(4) << "Ma" << setw(13) << "Ho va ten" << setw(28) << "Gioi tinh";
		cout << setw(11) << "Ngay sinh" << setw(7) << "CCCD" << setw(15) << "Email" << setw(32);
		cout << "Dia chi" << setw(42) << "Ngay lap the" << setw(16) << "Ngay het han\n";
		for (int i = 1; i <= 171; i++) cout << "-";
		cout << endl;

		//Ham in ra thong tin chi tiet cac doc gia
		InThongTinDocGia(SoDocGia, DocGia);

		//Nhap ho va ten can tra cuu
		char HoVaTenCanTim[30];
		cout << "\nNhap ho va ten can tra cuu: ";
		cin.ignore();
		gets_s(HoVaTenCanTim, sizeof(HoVaTenCanTim));
		FixChuoiKyTu(HoVaTenCanTim);
		int ViTriDocGia = ViTri_HoVaTen(DocGia, SoDocGia, HoVaTenCanTim);
#pragma endregion

#pragma region Sau tra cuu
		//DESIGN GIAO DIEN
		system("cls");
		for (int i = 1; i <= 77; i++) cout << "-";
		cout << "TIM KIEM DOC GIA";
		for (int i = 1; i <= 78; i++) cout << "-";

		//In ra dong dau chua dac diem thong tin (Ma, Ho va ten, Gioi tinh, ...)
		cout << "\nSTT" << setw(4) << "Ma" << setw(13) << "Ho va ten" << setw(28) << "Gioi tinh";
		cout << setw(11) << "Ngay sinh" << setw(7) << "CCCD" << setw(15) << "Email" << setw(32);
		cout << "Dia chi" << setw(42) << "Ngay lap the" << setw(16) << "Ngay het han\n";
		for (int i = 1; i <= 171; i++) cout << "-";
		cout << endl;

		//Ham in ra thong tin chi tiet cua doc gia can tim
		if (ViTriDocGia == -1)
		{
			cout << setw(94) << "<khong co du lieu>\n";
		}
		else
		{
			for (int i = 1; i <= SoDocGia; i++)
			{
				if (strcmp(upperString(HoVaTenCanTim), upperString(DocGia[i].HoVaTen)) == 0)
				{
					cout << i;
					Spaces(5 - NumberLength(i));
					cout << DocGia[i].Ma;
					Spaces(2);
					cout << DocGia[i].HoVaTen;
					Spaces(28 - strlen(DocGia[i].HoVaTen));
					cout << DocGia[i].GioiTinh;
					Spaces(11 - strlen(DocGia[i].GioiTinh));
					cout << DocGia[i].NgaySinh;
					Spaces(2);
					cout << DocGia[i].CCCD;
					Spaces(2);
					cout << DocGia[i].Email;
					Spaces(30 - strlen(DocGia[i].Email));
					cout << DocGia[i].DiaChi;
					Spaces(37 - strlen(DocGia[i].DiaChi));
					cout << DocGia[i].NgayLapThe;
					Spaces(5);
					cout << DocGia[i].NgayHetHanThe << endl;
				}
			}
		}
		for (int i = 1; i <= 171; i++) cout << "-";
		//Chon va thuc thi chuc nang de tiep tuc chuong trinh
		cout << "\nNhap ho va ten can tra cuu: " << HoVaTenCanTim;
		cout << "\n\n1. Tim mot doc gia khac";
		cout << "\n2. Xem danh sach doc gia";
		cout << "\n0. Thoat chuc nang\n";
		//Chon chuc nang
		char Func[2];
		cout << "> Nhap chuc nang (VD: 1): ";
		cin >> Func;
		while (strcmp(Func, "0") != 0 && strcmp(Func, "1") != 0 && strcmp(Func, "2") != 0)
		{
			XoaDong();
			cout << "> Nhap chuc nang (VD: 1): ";
			cin >> Func;
		}

		//Thuc thi chuc nang
		if (strcmp(Func, "0") == 0) return;
		if (strcmp(Func, "2") == 0) { Func1a(SoDocGia, DocGia); return; }
#pragma endregion
	}
}

int ViTri_HoVaTen(strDocGia DocGia[100], int SoLuongPhanTu, char GiaTriCanTim[])
{
	for (int i = 1; i <= SoLuongPhanTu; i++)
	{
		if (_stricmp(DocGia[i].HoVaTen, GiaTriCanTim) == 0) return i;
	}
	return -1;
}