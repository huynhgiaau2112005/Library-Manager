#include <iostream>
#include "lib.h"
#include <iomanip>
#include <string.h>

//Giao dien chinh cua Function 2c - Chinh sua thong tin cua sach
void Func2c(int& ListSach, int MaSach[100], char TenSach[100][100], char TacGia[100][100], char NhaXB[100][100], int NamXB[100], char TheLoai[100][100], char GiaSach[100][100], int SoSach[100])
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
		InThongTinSach(ListSach, MaSach, TenSach, TacGia, NhaXB, NamXB, TheLoai, GiaSach, SoSach);
#pragma endregion

#pragma region Nhap thong tin sach can chinh sua
		//Nhap ma sach (ISBN)
		int MaSachCanTim;
		cout << "\nNhap ma sach (5 so): ";
		cin >> MaSachCanTim;
		while (TimKiemViTri(MaSach, ListSach, MaSachCanTim) == -1)
		{
			XoaDong();
			cout << "Nhap ma sach (5 so): ";
			cin >> MaSachCanTim;
		}
		for (int i = 1; i <= 56; i++) cout << "-";

		//Bien luu vi tri cua sach
		int ViTriSach = TimKiemViTri(MaSach, ListSach, MaSachCanTim);

		//Nhap thong tin sach
		cout << endl << setw(35) << "Thong tin sach\n";
			//Nhap ten sach
		cout << "- Ten sach: ";
		cin.ignore();
		gets_s(TenSach[ViTriSach], sizeof(TenSach[100]));
			//Nhap tac gia 
		cout << "- Tac gia: ";
		gets_s(TacGia[ViTriSach], sizeof(TenSach)[100]);
			//Nhap ten nha xuat ban
		cout << "- Nha xuat ban: ";
		gets_s(NhaXB[ViTriSach], sizeof(NhaXB[100]));
			//Nhap nam xuat ban
		cout << "- Nam xuat ban: ";
		cin >> NamXB[ViTriSach];
		while (NumberLength(NamXB[ViTriSach]) != 4)
		{
			XoaDong();
			cout << "- Nam xuat ban: ";
			cin >> NamXB[ViTriSach];
		}
			//Nhap the loai
		cout << "- The loai: ";
		cin.ignore();
		gets_s(TheLoai[ViTriSach], sizeof(TheLoai[100]));
		FixChuoiKyTu(TheLoai[ViTriSach]);
		XoaDong();
		cout << "- The loai: " << TheLoai[ViTriSach] << endl;

		for (int i = 1; i <= 56; i++) cout << "-";

		//Nhap thong tin ban
		cout << endl;
		Spaces(22);
		cout << "Thong tin ban" << endl;
			//Nhap gia sach
		cout << "Gia sach: ";
		cin >> GiaSach[ViTriSach];
		FixGia(GiaSach[ViTriSach]);
		XoaDong();
		cout << "Gia sach: " << GiaSach[ViTriSach] << endl;
			//Nhap so luong
		cout << "So luong: ";
		cin >> SoSach[ViTriSach];
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
		if (strcmp(Func, "2") == 0) { Func2a(ListSach, MaSach, TenSach, TacGia, NhaXB, NamXB, TheLoai, GiaSach, SoSach); return; }
#pragma endregion
	}
}