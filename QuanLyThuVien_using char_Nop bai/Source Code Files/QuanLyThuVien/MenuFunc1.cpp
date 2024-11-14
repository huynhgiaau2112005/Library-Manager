#include <iostream>
#include "lib.h"
#include <iomanip>

using namespace std;

//In ra giao dien Menu Function 1 - Quan Li Doc Gia
void Func1_Menu(char CurrentDate[10], int& SoDocGia, int MaDocGia[100], char HoVaTen[100][100], char CCCD[100][100], char NgaySinh[100][100], char GioiTinh[100][100], char Email[100][100], char DiaChi[100][100], char NgayLapThe[100][100], char NgayHetHanThe[100][100])
{
	//while (true) giup khi 1a, 1b, ... bi thoat ra thi Menu Func1 van chay
	while (true)
	{
		char Func[2]; //Bien dung de nhap chuc nang
		//Nhap chuc nang den khi nao hop le
		do
		{
			system("cls");
			//DESIGN GIAO DIEN MENU
			for (int i = 1; i <= 57; i++)
			{
				cout << "=";
			}
			cout << "\n| QUAN LI DOC GIA";
			cout << setw(28) << "Date: " << CurrentDate << " |\n";
			for (int i = 1; i <= 57; i++)
			{
				cout << "=";
			}
			cout << "\nCac chuc nang cua chuong trinh:";

			//In ra menu
			cout << "\na. Xem danh sach doc gia trong thu vien";
			cout << "\nb. Them doc gia ";
			cout << "\nc. Chinh sua thong tin mot doc gia";
			cout << "\nd. Xoa thong tin mot doc gia";
			cout << "\ne. Tim kiem doc gia theo CCCD";
			cout << "\nf. Tim kiem doc gia theo ho ten";
			cout << "\n0. Ve Menu chinh";

			//Nhap chuc nang
			cout << "\nVui long nhap chuc nang (VD: a, 0): ";
			cin >> Func;
		} while (Func1_KiemTraChucNangMenu(Func) == false); //Kiem tra chuc nang da nhap, neu false thi nhap lai
		if (strcmp(Func, "0") == 0) return;
		Func1_NhapChucNangMenu(Func, SoDocGia, MaDocGia, HoVaTen, CCCD, NgaySinh, GioiTinh, Email, DiaChi, NgayLapThe, NgayHetHanThe); //Thuc hien chuc nang
	}
}

//Ham kiem tra xem chuc nang nhap vao co hop le hay khong
bool Func1_KiemTraChucNangMenu(char Func[])
{
	if (strcmp(Func, "a") == 0) return true;
	if (strcmp(Func, "b") == 0) return true;
	if (strcmp(Func, "c") == 0) return true;
	if (strcmp(Func, "d") == 0) return true;
	if (strcmp(Func, "e") == 0) return true;
	if (strcmp(Func, "f") == 0) return true;
	if (strcmp(Func, "0") == 0) return true;
	return false;
}

//Ham thuc hien chuc nang da nhap vao
void Func1_NhapChucNangMenu(char Func[], int& SoDocGia, int MaDocGia[100], char HoVaTen[100][100], char CCCD[100][100], char NgaySinh[100][100], char GioiTinh[100][100], char Email[100][100], char DiaChi[100][100], char NgayLapThe[100][100], char NgayHetHanThe[100][100])
{
	if (strcmp(Func, "a") == 0) { Func1a(SoDocGia, MaDocGia, HoVaTen, CCCD, NgaySinh, GioiTinh, Email, DiaChi, NgayLapThe, NgayHetHanThe); return; }
	if (strcmp(Func, "b") == 0) { Func1b(SoDocGia, MaDocGia, HoVaTen, CCCD, NgaySinh, GioiTinh, Email, DiaChi, NgayLapThe, NgayHetHanThe); return; }
	if (strcmp(Func, "c") == 0) { Func1c(SoDocGia, MaDocGia, HoVaTen, CCCD, NgaySinh, GioiTinh, Email, DiaChi, NgayLapThe, NgayHetHanThe); return; }
	if (strcmp(Func, "d") == 0) { Func1d(SoDocGia, MaDocGia, HoVaTen, CCCD, NgaySinh, GioiTinh, Email, DiaChi, NgayLapThe, NgayHetHanThe); return; }
	if (strcmp(Func, "e") == 0) { Func1e(SoDocGia, MaDocGia, HoVaTen, CCCD, NgaySinh, GioiTinh, Email, DiaChi, NgayLapThe, NgayHetHanThe); return; }
	if (strcmp(Func, "f") == 0) { Func1f(SoDocGia, MaDocGia, HoVaTen, CCCD, NgaySinh, GioiTinh, Email, DiaChi, NgayLapThe, NgayHetHanThe); return; }
}