#include <iostream>
#include "lib.h"
#include <iomanip>

using namespace std;

//Giao dien chinh cua Function 1e - Tim doc gia theo CCCD
void Func1e(int& SoDocGia, int MaDocGia[100], char HoVaTen[100][100], char CCCD[100][100], char NgaySinh[100][100], char GioiTinh[100][100], char Email[100][100], char DiaChi[100][100], char NgayLapThe[100][100], char NgayHetHanThe[100][100])
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
		InThongTinDocGia(SoDocGia, MaDocGia, HoVaTen, CCCD, NgaySinh, GioiTinh, Email, DiaChi, NgayLapThe, NgayHetHanThe);

		//Nhap so CCCD
		char CCCDCanTim[20];
		cout << "\nNhap CCCD can tra cuu: ";
		cin >> CCCDCanTim;
		while (strlen(CCCDCanTim) != 12)
		{
			XoaDong();
			cout << "Nhap CCCD can tra cuu: ";
			cin >> CCCDCanTim;
		}
		int ViTriDocGia = TimKiemViTri(CCCD, SoDocGia, CCCDCanTim);
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
			cout << " " << 1;
			Spaces(4 - NumberLength(ViTriDocGia));
			cout << MaDocGia[ViTriDocGia];
			Spaces(2);
			cout << HoVaTen[ViTriDocGia];
			Spaces(28 - strlen(HoVaTen[ViTriDocGia]));
			cout << GioiTinh[ViTriDocGia];
			Spaces(11 - strlen(GioiTinh[ViTriDocGia]));
			cout << NgaySinh[ViTriDocGia];
			Spaces(2);
			cout << CCCD[ViTriDocGia];
			Spaces(2);
			cout << Email[ViTriDocGia];
			Spaces(30 - strlen(Email[ViTriDocGia]));
			cout << DiaChi[ViTriDocGia];
			Spaces(37 - strlen(DiaChi[ViTriDocGia]));
			cout << NgayLapThe[ViTriDocGia];
			Spaces(5);
			cout << NgayHetHanThe[ViTriDocGia] << endl;
		}
		for (int i = 1; i <= 171; i++) cout << "-";
		//Chon va thuc thi chuc nang de tiep tuc chuong trinh
		cout << endl << "Nhap CCCD can tra cuu: " << CCCDCanTim;
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
		if (strcmp(Func, "2") == 0) { Func1a(SoDocGia, MaDocGia, HoVaTen, CCCD, NgaySinh, GioiTinh, Email, DiaChi, NgayLapThe, NgayHetHanThe); return; }
#pragma endregion
	}
}