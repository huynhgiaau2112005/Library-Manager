#include <iostream>
#include "lib.h"
#include <iomanip>

using namespace std;

//In ra giao dien Menu Function 2 - Quan Li Sach
void Func2_Menu(char CurrentDate[10], int& ListSach, int MaSach[100], char TenSach[100][100], char TacGia[100][100], char NhaXB[100][100], int NamXB[100], char TheLoai[100][100], char GiaSach[100][100], int SoSach[100])
{
	//while (true) giup khi 2a, 2b, ... bi thoat ra thi Menu Func1 van chay
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
			cout << "\n| QUAN LI SACH";
			cout << setw(31) << "Date: " << CurrentDate << " |\n";
			for (int i = 1; i <= 57; i++)
			{
				cout << "=";
			}
			cout << "\nCac chuc nang cua chuong trinh:";

			//In ra menu
			cout << "\na. Xem danh sach cac sach trong thu vien";
			cout << "\nb. Them sach";
			cout << "\nc. Chinh sua thong tin mot sach";
			cout << "\nd. Xoa thong tin sach";
			cout << "\ne. Tim kiem sach theo ISBN";
			cout << "\nf. Tim kiem sach theo ten sach";
			cout << "\n0. Ve Menu chinh";

			//Nhap chuc nang
			cout << "\nVui long nhap chuc nang (VD: a, 0): ";
			cin >> Func;
		} while (Func2_KiemTraChucNangMenu(Func) == false); //Kiem tra chuc nang da nhap, neu false thi nhap lai
		if (strcmp(Func, "0") == 0) return;
		Func2_NhapChucNangMenu(Func, ListSach, MaSach, TenSach, TacGia, NhaXB, NamXB, TheLoai, GiaSach, SoSach); //Thuc hien chuc nang
	}
}

//Ham kiem tra xem chuc nang nhap vao co hop le hay khong
bool Func2_KiemTraChucNangMenu(char Func[])
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
void Func2_NhapChucNangMenu(char Func[], int& ListSach, int MaSach[100], char TenSach[100][100], char TacGia[100][100], char NhaXB[100][100], int NamXB[100], char TheLoai[100][100], char GiaSach[100][100], int SoSach[100])
{
	if (strcmp(Func, "a") == 0) { Func2a(ListSach, MaSach, TenSach, TacGia, NhaXB, NamXB, TheLoai, GiaSach, SoSach); return; }
	if (strcmp(Func, "b") == 0) { Func2b(ListSach, MaSach, TenSach, TacGia, NhaXB, NamXB, TheLoai, GiaSach, SoSach); return; }
	if (strcmp(Func, "c") == 0) { Func2c(ListSach, MaSach, TenSach, TacGia, NhaXB, NamXB, TheLoai, GiaSach, SoSach); return; }
	if (strcmp(Func, "d") == 0) { Func2d(ListSach, MaSach, TenSach, TacGia, NhaXB, NamXB, TheLoai, GiaSach, SoSach); return; }
	if (strcmp(Func, "e") == 0) { Func2e(ListSach, MaSach, TenSach, TacGia, NhaXB, NamXB, TheLoai, GiaSach, SoSach); return; }
	if (strcmp(Func, "f") == 0) { Func2f(ListSach, MaSach, TenSach, TacGia, NhaXB, NamXB, TheLoai, GiaSach, SoSach); return; }
}