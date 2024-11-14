#include <iostream>
#include "lib.h"
#include <iomanip>

//Giao dien menu chinh cua Function 2e - Tim kiem sach bang ISBN
void Func2e(int& ListSach, int MaSach[100], char TenSach[100][100], char TacGia[100][100], char NhaXB[100][100], int NamXB[100], char TheLoai[100][100], char GiaSach[100][100], int SoSach[100])
{
	while (true)
	{
#pragma region Truoc tra cuu
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

		//Ham in ra thong tin chi tiet cac sach trong thu vien
		InThongTinSach(ListSach, MaSach, TenSach, TacGia, NhaXB, NamXB, TheLoai, GiaSach, SoSach);

		//Nhap ma sach can tim
		int MaSachCanTim;
		cout << "\nNhap ma sach (5 so) can tra cuu: ";
		cin >> MaSachCanTim;
		while (NumberLength(MaSachCanTim) != 5)
		{
			XoaDong();
			cout << "Nhap ma sach (5 so) can tra cuu: ";
			cin >> MaSachCanTim;
		}
		int ViTriSach = TimKiemViTri(MaSach, ListSach, MaSachCanTim);
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
			cout << " " << 1;
			Spaces(4);
			cout << MaSach[ViTriSach];
			Spaces(2);
			cout << TenSach[ViTriSach];
			Spaces(32 - strlen(TenSach[ViTriSach]));
			cout << TacGia[ViTriSach];
			Spaces(22 - strlen(TacGia[ViTriSach]));
			cout << NhaXB[ViTriSach];
			Spaces(24 - strlen(NhaXB[ViTriSach]));
			cout << NamXB[ViTriSach];
			Spaces(5);
			cout << TheLoai[ViTriSach];
			Spaces(15 - strlen(TheLoai[ViTriSach]));
			cout << GiaSach[ViTriSach];
			cout << setw(8) << SoSach[ViTriSach] << endl;
		}
		for (int i = 1; i <= 140; i++) cout << "-";
		//Chon va thuc thi chuc nang de tiep tuc chuong trinh
		cout << endl << "Nhap ma sach (5 so) can tra cuu: " << MaSachCanTim;
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