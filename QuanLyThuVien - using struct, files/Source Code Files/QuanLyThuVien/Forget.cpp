#include <iostream>
#include "lib.h"

using namespace std;

//Ham chinh cua chuc nang Forget Password
void AccountForgetPassword(strTaiKhoan forgetAccount, int& SoTaiKhoan, strTaiKhoan TaiKhoan[100])
{
	system("cls");
	cout << "VUI LONG NHAP EMAIL CUA TAI KHOAN DE KHOI PHUC MAT KHAU\n";
	cout << "Username: " << forgetAccount.Username << endl;
	cout << "Email: ";
	char enterEmail[50];
	int ViTriTaiKhoan = ViTri_Username(forgetAccount, SoTaiKhoan, TaiKhoan);
	cin.ignore();
	gets_s(enterEmail, sizeof(enterEmail));
	//Kiem tra Email nhap vao
	if (strcmp(enterEmail, TaiKhoan[ViTriTaiKhoan].Email) != 0) //Neu nhap sai Email
	{
		cout << "\nEmail khong chinh xac!\n";
		cout << "1. Nhap lai Email\n";
		cout << "2. Dang ky\n\n\n";
		char Func;
		do
		{
			XoaDong();
			cout << "> Chon chuc nang: ";
			cin >> Func;
		} while (Func != '1' && Func != '2');
		if (Func == '1') { AccountForgetPassword(forgetAccount, SoTaiKhoan, TaiKhoan); return; }
		if (Func == '2') { AccountRegister(SoTaiKhoan, TaiKhoan); return; }
	}
	else //Neu nhap dung Email
	{
		cout << "\nNHAP MAT KHAU MOI\n";
		cout << "+ Phai chua cac loai ky tu: chu hoa (A), chu thuong (a), chu so (1)\n";
		cout << "+ Toi da 20 ky tu\n\n";
		do
		{
			XoaDong();
			cout << "New Password: ";
			gets_s(TaiKhoan[ViTriTaiKhoan].Password);
		} while (!checkPassword(TaiKhoan[ViTriTaiKhoan]));
		cout << "\nKhoi phuc mat khau thanh cong!\n";
		cout << "Bam phim bat ky de dang nhap\n";
		system("pause");
		AccountLogin(SoTaiKhoan, TaiKhoan);
		return;
	}
}

/*
VUI LONG NHAP EMAIL CUA TAI KHOAN DE KHOI PHUC MAT KHAU
Username: huynhgiaau27112005@gmail.com
Email: 

Email khong chinh xac!
1. Nhap lai Email
2. Dang ky

NHAP MAT KHAU MOI
+ Phai chua cac loai ky tu: chu hoa (A), chu thuong (a), chu so (1)
+ Toi da 20 ky tu
New Password: 

Khoi phuc mat khau thanh cong!
Bam phim bat ky de dang nhap
Press any key to continue...
*/