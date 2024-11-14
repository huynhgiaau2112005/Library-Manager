#include <iostream>
#include "lib.h"
#include <iomanip>

//Giao dien menu chinh cua Function 2e - Tim kiem sach bang ten sach
void Func2f(int& ListSach, int MaSach[100], char TenSach[100][100], char TacGia[100][100], char NhaXB[100][100], int NamXB[100], char TheLoai[100][100], char GiaSach[100][100], int SoSach[100])
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
		InThongTinSach(ListSach, MaSach, TenSach, TacGia, NhaXB, NamXB, TheLoai, GiaSach, SoSach);

		//Nhap ma sach can tim
		char TenSachCanTim[100];
		cout << "\nNhap ten sach can tra cuu: ";
		cin.ignore();
		gets_s(TenSachCanTim, sizeof(TenSachCanTim));
		FixChuoiKyTu(TenSachCanTim);
		cout << upperString(TenSachCanTim);
		int ViTriSach = TimKiemViTri(TenSach, ListSach, TenSachCanTim);
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
				if (strcmp(upperString(TenSach[i]), upperString(TenSachCanTim)) == 0)
				{
					cout << " " << dem++;
					Spaces(4);
					cout << MaSach[i];
					Spaces(2);
					cout << TenSach[i];
					Spaces(32 - strlen(TenSach[i]));
					cout << TacGia[i];
					Spaces(22 - strlen(TacGia[i]));
					cout << NhaXB[i];
					Spaces(24 - strlen(NhaXB[i]));
					cout << NamXB[i];
					Spaces(5);
					cout << TheLoai[i];
					Spaces(15 - strlen(TheLoai[i]));
					cout << GiaSach[i];
					cout << setw(8) << SoSach[i] << endl;
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
		if (strcmp(Func, "2") == 0) { Func2a(ListSach, MaSach, TenSach, TacGia, NhaXB, NamXB, TheLoai, GiaSach, SoSach); return; }
#pragma endregion
	}
}