#include <iostream>
#include "lib.h"
#include <iomanip>
#include <string.h>

using namespace std;

//Ham in ra giao dien cua Function 1a
void Func1a(int& SoDocGia, strDocGia DocGia[100])
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
	InThongTinDocGia(SoDocGia, DocGia);
	
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
void InThongTinDocGia(int& SoDocGia, strDocGia DocGia[100])
{
	for (int i = 1; i <= SoDocGia; i++)
	{
		cout << " " << i;
		Spaces(4 - NumberLength(i));
		cout << DocGia[i].Ma;
		Spaces(2);
		cout << DocGia[i].HoVaTen;
		Spaces(28 - strlen(DocGia[i].HoVaTen));
		cout << DocGia[i].GioiTinh;
		Spaces(11 - strlen(DocGia[i].GioiTinh));
		cout << DocGia[i].NgaySinh;
		Spaces(2);
		cout << DocGia[i].CCCD;
		Spaces(2);
		cout << DocGia[i].Email;
		Spaces(30 - strlen(DocGia[i].Email));
		cout << DocGia[i].DiaChi;
		Spaces(37 - strlen(DocGia[i].DiaChi));
		cout << DocGia[i].NgayLapThe;
		Spaces(5);
		cout << DocGia[i].NgayHetHanThe << endl;
	}
	for (int i = 1; i <= 171; i++) cout << "-";
}