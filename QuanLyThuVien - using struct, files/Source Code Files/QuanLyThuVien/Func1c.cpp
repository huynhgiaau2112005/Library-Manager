#include <iostream>
#include "lib.h"
#include <iomanip>
#include <stdbool.h>

//Giao dien chinh cua Function 1c - Chinh sua thong tin cua doc gia
void Func1c(int& SoDocGia, strDocGia DocGia[100])
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
		InThongTinDocGia(SoDocGia, DocGia);
#pragma endregion

#pragma region Nhap lai thong tin cua doc gia
		//Nhap Ma Doc Gia
		int MaDGTimKiem;
		cout << endl;
		cout << "Nhap ma doc gia: ";
		cin >> MaDGTimKiem;
		while (ViTri_MaDG(DocGia, SoDocGia, MaDGTimKiem) == -1)
		{
			XoaDong();
			cout << "Nhap ma doc gia: ";
			cin >> MaDGTimKiem;
		}
		for (int i = 1; i <= 60; i++) cout << "-";

		//Bien luu vi tri cua nguoi dung (tim chi so trong mang)
		int ViTriDocGia = ViTri_MaDG(DocGia, SoDocGia, MaDGTimKiem);

		//Nhap thong tin ca nhan
		cout << endl << setw(36) << "Thong tin ca nhan\n";
		//Nhap ho va ten
		cout << "- Ho va ten: ";
		cin.ignore();
		gets_s(DocGia[ViTriDocGia].HoVaTen, sizeof(DocGia[100].HoVaTen));
		//Nhap gioi tinh
		cout << "- Gioi tinh (Nam/Nu): ";
		cin >> DocGia[ViTriDocGia].GioiTinh;
		while (strcmp(DocGia[ViTriDocGia].GioiTinh, "Nam") != 0 && strcmp(DocGia[ViTriDocGia].GioiTinh, "Nu") != 0)
		{
			XoaDong();
			cout << "- Gioi tinh (Nam/Nu): ";
			cin >> DocGia[ViTriDocGia].GioiTinh;
		}
		//Nhap ngay sinh
		cout << "- Ngay sinh (ddmmyyyy): ";
		cin >> DocGia[ViTriDocGia].NgaySinh;
		while (!CheckNgayThangNam(DocGia[ViTriDocGia].NgaySinh))
		{
			XoaDong();
			cout << "- Ngay sinh (ddmmyyyy): " << DocGia[ViTriDocGia].NgaySinh;
		}
		LuuNgayThangNam(DocGia[ViTriDocGia].NgaySinh); //Luu ki tu '/' o giua ngay, thang, nam
		XoaDong();
		cout << "- Ngay sinh (ddmmyyyy): " << DocGia[ViTriDocGia].NgaySinh << endl;
		//Nhap CCCD
		cout << "- CCCD (12 so): ";
		cin >> DocGia[ViTriDocGia].CCCD;
		while (strlen(DocGia[ViTriDocGia].CCCD) != 12)
		{
			XoaDong();
			cout << "- CCCD (12 so): ";
			cin >> DocGia[ViTriDocGia].CCCD;
		}
		//Nhap email
		cout << "- Email: ";
		cin >> DocGia[ViTriDocGia].Email;
		//Nhap dia chi
		cout << "- Dia chi: ";
		cin.ignore();
		gets_s(DocGia[ViTriDocGia].DiaChi, sizeof(DocGia[100].DiaChi));

		for (int i = 1; i <= 60; i++) cout << "-";

		//Nhap thong tin the
		cout << endl;
		Spaces(21);
		cout << "Thong tin the" << endl;
		//Nhap ngay lap the
		cout << "Ngay lap the (ddmmyyyy): ";
		cin >> DocGia[ViTriDocGia].NgayLapThe;
		while (!CheckNgayThangNam(DocGia[ViTriDocGia].NgayLapThe))
		{
			XoaDong();
			cout << "Ngay lap the (ddmmyyyy): ";
			cin >> DocGia[ViTriDocGia].NgayLapThe;
		}
		LuuNgayThangNam(DocGia[ViTriDocGia].NgayLapThe); //Them ki tu '/' o giua ngay, thang, nam
		XoaDong();
		cout << "Ngay lap the (ddmmyyyy): " << DocGia[ViTriDocGia].NgayLapThe << endl;
		//Gan gia tri cho ngay het han the
		strcpy_s(DocGia[ViTriDocGia].NgayHetHanThe, sizeof(DocGia[100].NgayHetHanThe), Tang4Nam(DocGia[ViTriDocGia].NgayLapThe));
		//In ra ngay het han the
		Spaces(5);
		cout << "> Ngay het han the: " << DocGia[ViTriDocGia].NgayHetHanThe << endl;
#pragma endregion

		//In ra thanh cong
		cout << endl;
		for (int i = 1; i <= 60; i++) cout << "-";
		cout << "\n Chinh sua doc gia thanh cong!\n";

#pragma region Nhap chuc nang de tiep tuc chuong trinh
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
		if (strcmp(Func, "2") == 0) { Func1a(SoDocGia, DocGia); return; }
#pragma endregion
	}
}

//Ham tim chi so cua doc gia trong mang co MaDocGia = MaTimKiem
int ViTri_MaDG(strDocGia DocGia[100], int SoLuongPhanTu, int GiaTriCanTim)
{
	for (int i = 1; i <= SoLuongPhanTu; i++)
	{
		if (DocGia[i].Ma == GiaTriCanTim) return i;
	}
	return -1;
}