#include <iostream>
#include "lib.h"
#include <iomanip>

using namespace std;

//In ra giao dien Menu Function 5 - Cac thong ke co ban
void Func5_Menu(char CurrentDate[11], int SoDocGia, strDocGia DocGia[100], int TongSoSachMuon, int MuonSoSach[100], strMuonTra MuonTra[100], int ListSach, strSach Sach[100])
{
	//while (true) giup khi 5a, 5b, ... bi thoat ra thi Menu Func5 van chay
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
			cout << "\n| CAC THONG KE CO BAN";
			cout << setw(24) << "Date: " << CurrentDate << " |\n";
			for (int i = 1; i <= 57; i++)
			{
				cout << "=";
			}
			cout << "\nCac chuc nang cua chuong trinh:";

			//In ra menu
			cout << "\na. Thong ke so luong sach trong thu vien";
			cout << "\nb. Thong ke so luong sach theo the loai";
			cout << "\nc. Thong ke so luong doc gia";
			cout << "\nd. Thong ke so luong doc gia theo gioi tinh";
			cout << "\ne. Thong ke so sach dang duoc muon";
			cout << "\nf. Thong ke danh sach doc gia bi tre han";
			cout << "\n0. Ve Menu chinh";

			//Nhap chuc nang
			cout << "\nVui long nhap chuc nang (VD: a, 0): ";
			cin >> Func;
		} while (Func1_KiemTraChucNangMenu(Func) == false); //Kiem tra chuc nang da nhap, neu false thi nhap lai
		if (strcmp(Func, "0") == 0) return;
		Func5_NhapChucNangMenu(Func, CurrentDate, SoDocGia, DocGia, TongSoSachMuon, MuonSoSach, MuonTra, ListSach, Sach);
	}
}

//Ham kiem tra xem chuc nang nhap vao co hop le hay khong
bool Func5_KiemTraChucNangMenu(char Func[])
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
void Func5_NhapChucNangMenu(char Func[], char CurrentDate[11], int SoDocGia, strDocGia DocGia[100], int TongSoSachMuon, int MuonSoSach[100], strMuonTra MuonTra[100], int ListSach, strSach Sach[100])
{
	if (strcmp(Func, "a") == 0) { Func5a(ListSach, Sach); return; }
	if (strcmp(Func, "b") == 0) { Func5b(ListSach, Sach); return; }
	if (strcmp(Func, "c") == 0) { Func5c(SoDocGia); return; }
	if (strcmp(Func, "d") == 0) { Func5d(SoDocGia, DocGia); return; }
	if (strcmp(Func, "e") == 0) { Func5e(TongSoSachMuon, MuonTra); return; }
	if (strcmp(Func, "f") == 0) { Func5f(CurrentDate, SoDocGia, DocGia, MuonSoSach, MuonTra); return; }
}