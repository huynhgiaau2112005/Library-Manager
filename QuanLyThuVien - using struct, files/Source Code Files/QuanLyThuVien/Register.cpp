#include <iostream>
#include <string.h>
#include "lib.h"

using namespace std;

//Ham chinh thuc hien chuc nang dang ky tai khoan
void AccountRegister(int& SoTaiKhoan, strTaiKhoan TaiKhoan[100])
{
	system("cls");
	strTaiKhoan registerAccount;
	cout << "DIEU KIEN NHAP THONG TIN TAI KHOAN CAN DANG KY\n";
	cout << "Username:\n";
	cout << "+ Khong chua ky tu khoang cach (space)\n";
	cout << "+ Toi da 20 ky tu\n";
	cout << "Password:\n";
	cout << "+ Phai chua cac loai ky tu: chu hoa (A), chu thuong (a), chu so (1)\n";
	cout << "+ Toi da 20 ky tu\n\n";
	cout << "NHAP THONG TIN TAI KHOAN CAN DANG KY\n\n";
	cin.ignore();
	do
	{
		XoaDong();
		cout << "Username: ";
		gets_s(registerAccount.Username, sizeof(registerAccount.Username));
	} while (!checkUsername(registerAccount));
	if (ViTri_Username(registerAccount, SoTaiKhoan, TaiKhoan) != -1) //Neu tai khoan da ton tai
	{
		cout << "\nTai khoan da ton tai!\n";
	}
	else //Tiep tuc viec dang ky neu tai khoan chua ton tai
	{
		cout << "\n";
		do
		{
			XoaDong();
			cout << "Password: ";
			gets_s(registerAccount.Password, sizeof(registerAccount.Password));
		} while (!checkPassword(registerAccount));
		cout << "\n";
		do
		{
			XoaDong();
			cout << "Email: ";
			gets_s(registerAccount.Email, sizeof(registerAccount.Email));
		} while (!checkEmail(registerAccount.Email));

		//Hoan tat dang ky
		cout << "\nDang ky thanh cong!\n";
		saveTaiKhoan(registerAccount, SoTaiKhoan, TaiKhoan);
	}
	cout << "1. Dang ky tai khoan khac\n";
	cout << "2. Dang nhap\n\n";
	char Func;
	do
	{
		XoaDong();
		cout << "> Nhap chuc nang: ";
		cin >> Func;
	} while (Func != '1' && Func != '2');
	if (Func == '1') { AccountRegister(SoTaiKhoan, TaiKhoan); return; }
	if (Func == '2') { AccountLogin(SoTaiKhoan, TaiKhoan); return; }
}

/*
DIEU KIEN NHAP THONG TIN TAI KHOAN CAN DANG KY
Username:
+ Khong chua ky tu khoang cach (space)
+ Toi da 20 ky tu
Password:
+ Phai chua cac loai ky tu: chu hoa (A), chu thuong (a), chu so (1)
+ Toi da 20 ky tu

NHAP THONG TIN TAI KHOAN CAN DANG KY  
Username: 
Password:
Email:

Tai khoan da ton tai!
1. Dang ky tai khoan khac
2. Dang nhap

Dang ky thanh cong!
1. Dang ky tai khoan moi 
2. Dang nhap
*/

//Ham kiem tra tinh hop le cua Username nhap vao
bool checkUsername(strTaiKhoan Account)
{
	if (strlen(Account.Username) > 20) return false;
	if (strlen(Account.Username) == 0) return false;
	for (int i = 0; i < strlen(Account.Username); i++)
	{
		if (Account.Username[i] == ' ') return false;
	}
	return true;
}

//Ham kiem tra tinh hop le cua Password nhap vao
bool checkPassword(strTaiKhoan Account)
{
	if (strlen(Account.Password) > 20) return false;
	if (strlen(Account.Password) == 0) return false;
	//Bien letterType luu so loai ky tu co trong Password
	int letterType = 0; //Co 3 loai ky tu: chu hoa, chu thuong, chu so => letterType_max = 3
	//Kiem tra su ton tai cua ky tu hoa
	for (int i = 0; i < strlen(Account.Password); i++)
	{
		if (Account.Password[i] >= 'A' && Account.Password[i] <= 'Z')
		{
			letterType++;
			break;
		}
	}
	//Kiem tra su ton tai cua ky tu thuong
	for (int i = 0; i < strlen(Account.Password); i++)
	{
		if (Account.Password[i] >= 'a' && Account.Password[i] <= 'z')
		{
			letterType++;
			break;
		}
	}
	//Kiem tra su ton tai cua ky tu chu so
	for (int i = 0; i < strlen(Account.Password); i++)
	{
		if (Account.Password[i] >= '0' && Account.Password[i] <= '9')
		{
			letterType++;
			break;
		}
	}
	if (letterType != 3) return false; //Password chi hop le khi letterType = letterType_max = 3 (co du 3 loai ky tu)
	return true;
}

//Ham luu tai khoan duoc dang ky (luu vao bien TaiKhoan[])
void saveTaiKhoan(strTaiKhoan registerAccount, int& SoTaiKhoan, strTaiKhoan TaiKhoan[100])
{
	SoTaiKhoan++;
	strcpy_s(TaiKhoan[SoTaiKhoan].Username, sizeof(TaiKhoan[SoTaiKhoan].Username), registerAccount.Username);
	strcpy_s(TaiKhoan[SoTaiKhoan].Password, sizeof(TaiKhoan[SoTaiKhoan].Password), registerAccount.Password);
	strcpy_s(TaiKhoan[SoTaiKhoan].Email, sizeof(TaiKhoan[SoTaiKhoan].Email), registerAccount.Email);
}

//int ViTri_Email(strTaiKhoan registerAccount, int& SoTaiKhoan, strTaiKhoan TaiKhoan[100])
//{
//	for (int i = 1; i <= SoTaiKhoan; i++)
//	{
//		if (strcmp(registerAccount.Email, TaiKhoan[i].Email) == 0)
//		{
//			return i;
//		}
//	}
//	return -1;
//}