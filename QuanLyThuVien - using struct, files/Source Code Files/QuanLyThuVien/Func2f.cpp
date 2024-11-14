#include <iostream>
#include "lib.h"
#include <iomanip>

//Giao dien menu chinh cua Function 2e - Tim kiem sach bang ten sach
void Func2f(int& ListSach, strSach Sach[100])
{
	while (true)
	{
#pragma region Truoc tra cuu
		//DESIGN GIAO DIEN
		system("cls");
		for (int i = 1; i <= 55; i++) cout << "-";
		cout << "TIM KIEM SACH TRONG THU VIEN";
		for (int i = 1; i <= 56; i++) cout << "-";

		//In ra dong dau chua dac diem thong tin (Ma sach, ten sach, tac gia, ...
		cout << "\nSTT" << setw(6) << "ISBN" << setw(11) << "Ten sach" << setw(31) << "Tac gia";
		cout << setw(27) << "Nha xuat ban" << setw(18) << "Nam XB" << setw(11) << "The loai" << setw(15);
		cout << "Gia sach" << setw(11) << "So luong\n";
		for (int i = 1; i <= 139; i++) cout << "-";
		cout << endl;

		//Ham in ra thong tin chi tiet cac sach trong thu vien
		InThongTinSach(ListSach, Sach);

		//Nhap ma sach can tim
		char TenSachCanTim[100];
		cout << "\nNhap ten sach can tra cuu: ";
		cin.ignore();
		gets_s(TenSachCanTim, sizeof(TenSachCanTim));
		FixChuoiKyTu(TenSachCanTim);
		cout << upperString(TenSachCanTim);
		int ViTriSach = ViTri_TenSach(Sach, ListSach, TenSachCanTim);
#pragma endregion

#pragma region Sau tra cuu
		//DESIGN GIAO DIEN
		system("cls");
		for (int i = 1; i <= 55; i++) cout << "-";
		cout << "TIM KIEM SACH TRONG THU VIEN";
		for (int i = 1; i <= 56; i++) cout << "-";

		//In ra dong dau chua dac diem thong tin (Ma sach, ten sach, tac gia, ...)
		cout << "\nSTT" << setw(6) << "ISBN" << setw(11) << "Ten sach" << setw(31) << "Tac gia";
		cout << setw(27) << "Nha xuat ban" << setw(18) << "Nam XB" << setw(11) << "The loai" << setw(15);
		cout << "Gia sach" << setw(11) << "So luong\n";
		for (int i = 1; i <= 139; i++) cout << "-";
		cout << endl;

		//Ham in ra thong tin chi tiet cua sach can tim
		if ((ViTriSach) == -1)
		{
			cout << setw(80) << "<khong co du lieu>\n";
		}
		else
		{
			int dem = 1;
			for (int i = 1; i <= ListSach; i++)
			{
				if (strcmp(upperString(Sach[i].Ten), upperString(TenSachCanTim)) == 0)
				{
					cout << " " << dem++;
					Spaces(4);
					cout << Sach[i].Ma;
					Spaces(2);
					cout << Sach[i].Ten;
					Spaces(32 - strlen(Sach[i].Ten));
					cout << Sach[i].TacGia;
					Spaces(22 - strlen(Sach[i].TacGia));
					cout << Sach[i].NhaXB;
					Spaces(24 - strlen(Sach[i].NhaXB));
					cout << Sach[i].NamXB;
					Spaces(5);
					cout << Sach[i].TheLoai;
					Spaces(15 - strlen(Sach[i].TheLoai));
					cout << Sach[i].Gia;
					cout << setw(8) << Sach[i].SoLuong << endl;
				}
			}
		}
		for (int i = 1; i <= 139; i++) cout << "-";
		//Chon va thuc thi chuc nang de tiep tuc chuong trinh
		cout << endl << "Nhap ten sach can tra cuu: " << TenSachCanTim;
		cout << "\n\n1. Tim mot quyen sach khac";
		cout << "\n2. Xem danh sach cac sach trong thu vien";
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
		if (strcmp(Func, "2") == 0) { Func2a(ListSach, Sach); return; }
#pragma endregion
	}
}

int ViTri_TenSach(strSach Sach[100], int SoLuongPhanTu, char GiaTriCanTim[])
{
	for (int i = 1; i <= SoLuongPhanTu; i++)
	{
		if (_stricmp(Sach[i].Ten, GiaTriCanTim) == 0) return i;
	}
	return -1;
}