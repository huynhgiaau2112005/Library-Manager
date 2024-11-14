#include <iostream>
#include "lib.h"

using namespace std;

//Ham chinh show Menu cua chuc nang dang nhap/dang ky tai khoan
void MenuAccount(int& SoTaiKhoan, strTaiKhoan TaiKhoan[100])
{
	system("cls");
	cout << "VUI LONG DANG NHAP/DANG KY DE QUAN LY THU VIEN\n";
	cout << "Chon 1 chuc nang:\n";
	cout << "1. Dang nhap\n";
	cout << "2. Dang ky\n";
	//cout << "3. Quen mat khau\n";
	cout << "0. Thoat chuong trinh\n\n";
	cout << "> Chon chuc nang: ";
	char Func;
	cin >> Func;
	while (!Account_KiemTraChucNangMenu(Func))
	{
		XoaDong();
		cout << "> Chon chuc nang: ";
		cin >> Func;
	}
	Account_NhapChucNangMenu(Func, SoTaiKhoan, TaiKhoan);
}

/*

VUI LONG DANG NHAP/DANG KY DE QUAN LY THU VIEN
Chon 1 chuc nang:
1. Dang nhap
2. Dang ky
3. Quen mat khau
0. Thoat chuong trinh

> Chon chuc nang:



Trong giao dien 1:

Username:
Password:

Tai khoan khong ton tai!
1. Dang nhap lai
2. Dang ky

Sai mat khau!
1. Dang nhap lai
2. Quen mat khau

> Chon chuc nang:
*/

//Ham kiem tra xem chuc nang nhap vao co hop le khong
bool Account_KiemTraChucNangMenu(char Func)
{
	if (Func == '1') return true;
	if (Func == '2') return true;
	//if (Func == '3') return true;
	if (Func == '0') return true;
	return false;
}

//Ham thuc hien chuc nang nhap vao
void Account_NhapChucNangMenu(char Func, int& SoTaiKhoan, strTaiKhoan TaiKhoan[100])
{
	if (Func == '0') exit(0);
	if (Func == '1') { AccountLogin(SoTaiKhoan, TaiKhoan); return; }
	if (Func == '2') { AccountRegister(SoTaiKhoan, TaiKhoan); return; }
}