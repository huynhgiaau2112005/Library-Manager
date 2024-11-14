#include <iostream>
#include "lib.h"
#include <iomanip>
#include <stdbool.h>

//Giao dien chinh cua Function 1c - Chinh sua thong tin cua doc gia
void Func1c(int& SoDocGia, int MaDocGia[100], char HoVaTen[100][100], char CCCD[100][100], char NgaySinh[100][100], char GioiTinh[100][100], char Email[100][100], char DiaChi[100][100], char NgayLapThe[100][100], char NgayHetHanThe[100][100])
{
	while (true)
	{
		system("cls");
		//In ra dong dau: 
		for (int i = 1; i <= 14; i++) cout << "-";
		cout << "CHINH SUA THONG TIN MOT DOC GIA";
		for (int i = 1; i <= 14; i++) cout << "-";

#pragma region In ra danh sach doc gia
		//In ra dong dau chua dac diem thong tin (Ma, Ho va ten, Gioi tinh, ...)
		cout << "\nSTT" << setw(4) << "Ma" << setw(13) << "Ho va ten" << setw(28) << "Gioi tinh";
		cout << setw(11) << "Ngay sinh" << setw(7) << "CCCD" << setw(15) << "Email" << setw(32);
		cout << "Dia chi" << setw(42) << "Ngay lap the" << setw(16) << "Ngay het han\n";
		for (int i = 1; i <= 171; i++) cout << "-";
		cout << endl;

		//Ham in ra thong tin chi tiet cac doc gia
		InThongTinDocGia(SoDocGia, MaDocGia, HoVaTen, CCCD, NgaySinh, GioiTinh, Email, DiaChi, NgayLapThe, NgayHetHanThe);
#pragma endregion


		//Nhap Ma Doc Gia
		int MaDGTimKiem;
		cout << endl;
		cout << "Nhap ma doc gia: ";
		cin >> MaDGTimKiem;
		while (TimKiemViTri(MaDocGia, SoDocGia, MaDGTimKiem) == -1)
		{
			XoaDong();
			cout << "Nhap ma doc gia: ";
			cin >> MaDGTimKiem;
		}
		for (int i = 1; i <= 60; i++) cout << "-";

		//Bien luu vi tri cua nguoi dung (tim chi so trong mang)
		int ViTriDocGia = TimKiemViTri(MaDocGia, SoDocGia, MaDGTimKiem);

		//Nhap thong tin ca nhan
		cout << endl << setw(36) << "Thong tin ca nhan\n";
		//Nhap ho va ten
		cout << "- Ho va ten: ";
		cin.ignore();
		gets_s(HoVaTen[ViTriDocGia], sizeof(HoVaTen[100]));
		//Nhap gioi tinh
		cout << "- Gioi tinh (Nam/Nu): ";
		cin >> GioiTinh[ViTriDocGia];
		while (strcmp(GioiTinh[ViTriDocGia], "Nam") != 0 && strcmp(GioiTinh[ViTriDocGia], "Nu") != 0)
		{
			XoaDong();
			cout << "- Gioi tinh (Nam/Nu): ";
			cin >> GioiTinh[ViTriDocGia];
		}
		//Nhap ngay sinh
		cout << "- Ngay sinh (ddmmyyyy): ";
		cin >> NgaySinh[ViTriDocGia];
		while (!CheckNgayThangNam(NgaySinh[ViTriDocGia]))
		{
			XoaDong();
			cout << "- Ngay sinh (ddmmyyyy): " << NgaySinh[ViTriDocGia];
		}
		LuuNgayThangNam(NgaySinh[ViTriDocGia]); //Luu ki tu '/' o giua ngay, thang, nam
		XoaDong();
		cout << "- Ngay sinh (ddmmyyyy): " << NgaySinh[ViTriDocGia] << endl;
		//Nhap CCCD
		cout << "- CCCD (12 so): ";
		cin >> CCCD[ViTriDocGia];
		while (strlen(CCCD[ViTriDocGia]) != 12)
		{
			XoaDong();
			cout << "- CCCD (12 so): ";
			cin >> CCCD[ViTriDocGia];
		}
		//Nhap email
		cout << "- Email: ";
		cin >> Email[ViTriDocGia];
		//Nhap dia chi
		cout << "- Dia chi: ";
		cin.ignore();
		gets_s(DiaChi[ViTriDocGia], sizeof(DiaChi[100]));

		for (int i = 1; i <= 60; i++) cout << "-";

		//Nhap thong tin the
		cout << endl;
		Spaces(21);
		cout << "Thong tin the" << endl;
		//Nhap ngay lap the
		cout << "Ngay lap the (ddmmyyyy): ";
		cin >> NgayLapThe[ViTriDocGia];
		while (!CheckNgayThangNam(NgayLapThe[ViTriDocGia]))
		{
			XoaDong();
			cout << "Ngay lap the (ddmmyyyy): ";
			cin >> NgayLapThe[ViTriDocGia];
		}
		LuuNgayThangNam(NgayLapThe[ViTriDocGia]); //Them ki tu '/' o giua ngay, thang, nam
		XoaDong();
		cout << "Ngay lap the (ddmmyyyy): " << NgayLapThe[ViTriDocGia] << endl;
		//Gan gia tri cho ngay het han the
		strcpy_s(NgayHetHanThe[ViTriDocGia], sizeof(NgayHetHanThe[100]), Tang4Nam(NgayLapThe[ViTriDocGia]));
		//In ra ngay het han the
		Spaces(5);
		cout << "> Ngay het han the: " << NgayHetHanThe[ViTriDocGia] << endl;

		//In ra thanh cong
		cout << endl;
		for (int i = 1; i <= 60; i++) cout << "-";
		cout << "\n Chinh sua doc gia thanh cong!\n";

		//Nhap chuc nang de tiep tuc chuong trinh
		for (int i = 1; i <= 60; i++) cout << "-";
		cout << "\n1. Chinh sua mot doc gia khac";
		cout << "\n2. Xem danh sach doc gia";
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
		if (strcmp(Func, "2") == 0) { Func1a(SoDocGia, MaDocGia, HoVaTen, CCCD, NgaySinh, GioiTinh, Email, DiaChi, NgayLapThe, NgayHetHanThe); return; }
	}
}

//Ham tim chi so cua doc gia trong mang co MaDocGia = MaTimKiem
int TimKiemViTri(int Mang[100], int SoLuongPhanTu, int GiaTriCanTim)
{
	for (int i = 1; i <= SoLuongPhanTu; i++)
	{
		if (Mang[i] == GiaTriCanTim) return i;
	}
	return -1;
}

int TimKiemViTri(char Mang[100][100], int SoLuongPhanTu, char GiaTriCanTim[100])
{
	for (int i = 1; i <= SoLuongPhanTu; i++)
	{
		if (strcmp(upperString(Mang[i]), upperString(GiaTriCanTim)) == 0)
		{
			return i;
		}
	}
	return -1;
}