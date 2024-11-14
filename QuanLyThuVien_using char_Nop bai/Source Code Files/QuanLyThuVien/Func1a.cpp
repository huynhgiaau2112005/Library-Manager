#include <iostream>
#include "lib.h"
#include <iomanip>
#include <string.h>

using namespace std;

//Ham in ra giao dien cua Function 1a
void Func1a(int& SoDocGia, int MaDocGia[100], char HoVaTen[100][100], char CCCD[100][100], char NgaySinh[100][100], char GioiTinh[100][100], char Email[100][100], char DiaChi[100][100], char NgayLapThe[100][100], char NgayHetHanThe[100][100])
{
	//DESIGN GIAO DIEN
	system("cls");
	for (int i = 1; i <= 77; i++) cout << "-";
	cout << "DANH SACH DOC GIA";
	for (int i = 1; i <= 77; i++) cout << "-";

	//In ra dong dau chua dac diem thong tin (Ma, Ho va ten, Gioi tinh, ...)
	cout << "\nSTT" << setw(4) << "Ma" << setw(13) << "Ho va ten" << setw(28) << "Gioi tinh";
	cout << setw(11) << "Ngay sinh" << setw(7) << "CCCD" << setw(15) << "Email" << setw(32);
	cout << "Dia chi" << setw(42) << "Ngay lap the" << setw(16) << "Ngay het han\n";
	for (int i = 1; i <= 171; i++) cout << "-";
	cout << endl;

	//Ham in ra thong tin chi tiet cac doc gia
	InThongTinDocGia(SoDocGia, MaDocGia, HoVaTen, CCCD, NgaySinh, GioiTinh, Email, DiaChi, NgayLapThe, NgayHetHanThe);
	
	//Nhan de thoat
	char Func[2];
	cout << "\nNhap 0 de thoat: ";
	cin >> Func;
	while (strcmp(Func, "0") != 0)
	{
		XoaDong();
		cout << "Nhap 0 de thoat: ";
		cin >> Func;
	}
}

//Ham in ra chi tiet thong tin cac doc gia
void InThongTinDocGia(int& SoDocGia, int MaDocGia[100], char HoVaTen[100][100], char CCCD[100][100], char NgaySinh[100][100], char GioiTinh[100][100], char Email[100][100], char DiaChi[100][100], char NgayLapThe[100][100], char NgayHetHanThe[100][100])
{
	for (int i = 1; i <= SoDocGia; i++)
	{
		cout << " " << i;
		Spaces(4 - NumberLength(i));
		cout << MaDocGia[i];
		Spaces(2);
		cout << HoVaTen[i];
		Spaces(28 - strlen(HoVaTen[i]));
		cout << GioiTinh[i];
		Spaces(11 - strlen(GioiTinh[i]));
		cout << NgaySinh[i];
		Spaces(2);
		cout << CCCD[i];
		Spaces(2);
		cout << Email[i];
		Spaces(30 - strlen(Email[i]));
		cout << DiaChi[i];
		Spaces(37 - strlen(DiaChi[i]));
		cout << NgayLapThe[i];
		Spaces(5);
		cout << NgayHetHanThe[i] << endl;
	}
	for (int i = 1; i <= 171; i++) cout << "-";
}