#include <iostream>
#include "lib.h"

using namespace std;

/*

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

//Ham chinh thuc hien chuc nang Login
void AccountLogin(int& SoTaiKhoan, strTaiKhoan TaiKhoan[100])
{
	system("cls");
	cout << "DANG NHAP:\n";
	strTaiKhoan loginAccount;
	cout << "Username: ";
	cin >> loginAccount.Username;
	int ViTriTaiKhoan = ViTri_Username(loginAccount, SoTaiKhoan, TaiKhoan); //Bien luu dia chi cua Username nhap vao trong mang TaiKhoan[]
	if (ViTriTaiKhoan == -1) //Neu username khong ton tai
	{
		cout << "\nTai khoan khong ton tai!\n";
		cout << "1. Dang nhap lai\n";
		cout << "2. Dang ky\n\n";
		cout << "> Nhap chuc nang: ";
		char Func;
		cin >> Func;
		if (Func != '1' && Func != '2')
		{
			XoaDong();
			cout << "> Nhap chuc nang: ";
			cin >> Func;
		}
		if (Func == '1') { AccountLogin(SoTaiKhoan, TaiKhoan); return; }
		if (Func == '2') { AccountRegister(SoTaiKhoan, TaiKhoan); return; }
	}
	else //Neu username co ton tai
	{
		cout << "Password: ";
		cin >> loginAccount.Password;
		if (strcmp(loginAccount.Password, TaiKhoan[ViTriTaiKhoan].Password) != 0)
		{
			cout << "\nSai mat khau!\n";
			cout << "1. Dang nhap lai\n";
			cout << "2. Quen mat khau\n\n";
			cout << "> Nhap chuc nang: ";
			char Func;
			cin >> Func;
			if (Func != '1' && Func != '2')
			{
				XoaDong();
				cout << "> Nhap chuc nang: ";
				cin >> Func;
			}
			if (Func == '1') { AccountLogin(SoTaiKhoan, TaiKhoan); return; }
			if (Func == '2') { AccountForgetPassword(loginAccount, SoTaiKhoan, TaiKhoan); return; }
		}
		else
		{
			return;
		}
	}
	
}

//Ham tim dia chi cua tai khoan trong mang TaiKhoan dua vao Username (tra ve -1 neu khong tim thay)
int ViTri_Username(strTaiKhoan loginAccount, int SoTaiKhoan, strTaiKhoan TaiKhoan[100])
{
	for (int i = 1; i <= SoTaiKhoan; i++)
	{
		if (strcmp(TaiKhoan[i].Username, loginAccount.Username) == 0) return i;
	}
	return -1;
}