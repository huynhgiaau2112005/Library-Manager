#include <iostream>
#include "lib.h"
#include <iomanip>

//Ham xoa thong tin cua mang "ThongTin" co "SoLuong" phan tu tai vi tri "ViTriXoa"
void XoaThongTin(int& SoLuong, int ThongTin[100], int ViTriXoa)
{
	for (int i = ViTriXoa; i <= SoLuong - 1; i++)
	{
		ThongTin[i] = ThongTin[i + 1];
	}
}

//Ham xoa thong tin cua mang "ThongTin" co "SoLuong" phan tu tai vi tri "ViTriXoa"
void XoaThongTin(int& SoLuong, char ThongTin[100][100], int ViTriXoa)
{
	for (int i = ViTriXoa; i <= SoLuong - 1; i++)
	{
		strcpy_s(ThongTin[i], sizeof(ThongTin[100]), ThongTin[i + 1]);
	}
}

//Menu chinh cua Function 1d - Xoa thong tin mot doc gia
void Func1d(int& SoDocGia, int MaDocGia[100], char HoVaTen[100][100], char CCCD[100][100], char NgaySinh[100][100], char GioiTinh[100][100], char Email[100][100], char DiaChi[100][100], char NgayLapThe[100][100], char NgayHetHanThe[100][100])
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
		InThongTinDocGia(SoDocGia, MaDocGia, HoVaTen, CCCD, NgaySinh, GioiTinh, Email, DiaChi, NgayLapThe, NgayHetHanThe);
#pragma endregion

		//Nhap ma doc gia can xoa
		cout << endl;
		cout << "Nhap ma doc gia: ";
		int MaDGTimKiem;
		cin >> MaDGTimKiem;
		while (TimKiemViTri(MaDocGia, SoDocGia, MaDGTimKiem) == -1) //Kiem tra xem ma doc gia co ton tai khong
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
			int ViTriDocGia = TimKiemViTri(MaDocGia, SoDocGia, MaDGTimKiem);
			//Xoa ma doc gia
			XoaThongTin(SoDocGia, MaDocGia, ViTriDocGia);
			//Xoa ho va ten
			XoaThongTin(SoDocGia, HoVaTen, ViTriDocGia);
			//Xoa gioi tinh
			XoaThongTin(SoDocGia, GioiTinh, ViTriDocGia);
			//Xoa ngay sinh
			XoaThongTin(SoDocGia, NgaySinh, ViTriDocGia);
			//Xoa CCCD
			XoaThongTin(SoDocGia, CCCD, ViTriDocGia);
			//Xoa Email
			XoaThongTin(SoDocGia, Email, ViTriDocGia);
			//Xoa Dia chi
			XoaThongTin(SoDocGia, DiaChi, ViTriDocGia);
			//Xoa Ngay lap the
			XoaThongTin(SoDocGia, NgayLapThe, ViTriDocGia);
			//Xoa Ngay het han the
			XoaThongTin(SoDocGia, NgayHetHanThe, ViTriDocGia);
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
		if (strcmp(Func, "2") == 0) { Func1a(SoDocGia, MaDocGia, HoVaTen, CCCD, NgaySinh, GioiTinh, Email, DiaChi, NgayLapThe, NgayHetHanThe); return; }
	}
}