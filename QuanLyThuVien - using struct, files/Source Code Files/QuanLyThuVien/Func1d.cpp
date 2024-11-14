#include <iostream>
#include "lib.h"
#include <iomanip>

//Ham xoa thong tin cua mang "ThongTin" co "SoLuong" phan tu tai vi tri "ViTriXoa"
void XoaThongTin(int& SoLuong, strDocGia DocGia[100], int ViTriXoa)
{
	for (int i = ViTriXoa; i <= SoLuong - 1; i++)
	{
		DocGia[i].Ma = DocGia[i + 1].Ma;
		strcpy_s(DocGia[i].HoVaTen, sizeof(DocGia[i].HoVaTen), DocGia[i + 1].HoVaTen);
		strcpy_s(DocGia[i].NgaySinh, sizeof(DocGia[i].NgaySinh), DocGia[i + 1].NgaySinh);
		strcpy_s(DocGia[i].CCCD, sizeof(DocGia[i].CCCD), DocGia[i + 1].CCCD);
		strcpy_s(DocGia[i].NgayLapThe, sizeof(DocGia[i].NgayLapThe), DocGia[i + 1].NgayLapThe);
		strcpy_s(DocGia[i].NgayHetHanThe, sizeof(DocGia[i].NgayHetHanThe), DocGia[i + 1].NgayHetHanThe);
		strcpy_s(DocGia[i].Email, sizeof(DocGia[i].Email), DocGia[i + 1].Email);
		strcpy_s(DocGia[i].DiaChi, sizeof(DocGia[i].DiaChi), DocGia[i + 1].DiaChi);
		strcpy_s(DocGia[i].GioiTinh, sizeof(DocGia[i].GioiTinh), DocGia[i + 1].GioiTinh);
	}
}

////Ham xoa thong tin cua mang "ThongTin" co "SoLuong" phan tu tai vi tri "ViTriXoa"
//void XoaThongTin(int& SoLuong, char ThongTin[100][100], int ViTriXoa)
//{
//	for (int i = ViTriXoa; i <= SoLuong - 1; i++)
//	{
//		strcpy_s(ThongTin[i], sizeof(ThongTin[100]), ThongTin[i + 1]);
//	}
//}

//Menu chinh cua Function 1d - Xoa thong tin mot doc gia
void Func1d(int& SoDocGia, strDocGia DocGia[100])
{
	while (true)
	{
		system("cls");
		//In ra dong dau
		for (int i = 1; i <= 17; i++) cout << "-";
		cout << "XOA THONG TIN MOT DOC GIA";
		for (int i = 1; i <= 17; i++) cout << "-";

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

#pragma region Thuc hien xoa doc gia
		//Nhap ma doc gia can xoa
		cout << endl;
		cout << "Nhap ma doc gia: ";
		int MaDGTimKiem;
		cin >> MaDGTimKiem;
		while (ViTri_MaDG(DocGia, SoDocGia, MaDGTimKiem) == -1) //Kiem tra xem ma doc gia co ton tai khong
		{
			XoaDong();
			cout << "Nhap ma doc gia: ";
			cin >> MaDGTimKiem;
		}

		//Xac nhan xoa
		cout << "> Xac nhan xoa [Y/N]: ";
		char XacNhan;
		cin >> XacNhan;
		while (XacNhan != 'Y' && XacNhan != 'N')
		{
			XoaDong();
			cout << "> Xac nhan xoa [Y/N]: ";
			cin >> XacNhan;
		}
		if (XacNhan == 'Y')
		{
			int ViTriDocGia = ViTri_MaDG(DocGia, SoDocGia, MaDGTimKiem);
			//Xoa thong tin doc gia
			XoaThongTin(SoDocGia, DocGia, ViTriDocGia);
			//Giam so luong doc gia
			SoDocGia--;
			for (int i = 1; i <= 60; i++) cout << "-";
			cout << "\nXoa doc gia thanh cong!\n";
			for (int i = 1; i <= 60; i++) cout << "-";
		}
		else
		{
			for (int i = 1; i <= 60; i++) cout << "-";
			cout << "\nDa huy thao tac.\n";
			for (int i = 1; i <= 60; i++) cout << "-";
		}
#pragma endregion

#pragma region Chon chuc nang de tiep tuc chuong trinh
		//Nhap chuc nang de tiep tuc chuong trinh
		cout << "\n1. Xoa mot doc gia khac";
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