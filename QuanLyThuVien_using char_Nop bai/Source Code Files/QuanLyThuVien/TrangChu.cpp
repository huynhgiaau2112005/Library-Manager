#include <iostream>
#include "lib.h"
#include <iomanip>
#include <stdbool.h>
#include <string>
#include <cstdlib>

using namespace std;

void XuatChucNangFunction1()
{
	cout << "\n    1a. Xem danh sach doc gia trong thu vien";
	cout << "\n    1b. Them doc gia";
	cout << "\n    1c. Chinh sua thong tin mot doc gia";
	cout << "\n    1d. Xoa thong tin mot doc gia";
	cout << "\n    1e. Tim kiem doc gia theo CMND";
	cout << "\n    1f. Tim kiem sach theo ho ten";
}

void XuatChucNangFunction2()
{
	cout << "\n    2a. Xem danh sach cac sach trong thu vien";
	cout << "\n    2b. Them sach";
	cout << "\n    2c. Chinh sua thong tin mot quyen sach";
	cout << "\n    2d. Xoa thong tin sach";
	cout << "\n    2e. Tim kiem sach theo iSBN";
	cout << "\n    2f. Tim kiem sach theo ten sach";
}

void XuatChucNangFunction5()
{
	cout << "\n    5a. Thong ke so luong sach trong thu vien";
	cout << "\n    5b. Thong ke so luong sach theo the loai";
	cout << "\n    5c. Thong ke so luong doc gia";
	cout << "\n    5d. Thong ke so luong doc gia theo gioi tinh";
	cout << "\n    5e. Thong ke so sach dang duoc muon";
	cout << "\n    5f. Thong ke danh sach doc gia bi tre han";
}

void MenuRutGon(char Func[], char CurrentDate[10])
{
	//Nhap chuc nang den khi nao hop le
	do
	{
		system("cls");
		//DESIGN GIAO DIEN MENU
		for (int i = 1; i <= 57; i++)
		{
			cout << "=";
		}
		cout << "\n| QUAN LI THU VIEN";
		cout << setw(27) << "Date: " << CurrentDate << " |\n";
		for (int i = 1; i <= 57; i++)
		{
			cout << "=";
		}
		cout << "\nCac chuc nang cua chuong trinh:";

		//In ra menu
		cout << "\n1. Quan li doc gia";
		cout << "\n2. Quan li sach";
		cout << "\n3. Lap phieu muon sach";
		cout << "\n4. Lap phieu tra sach";
		cout << "\n5. Cac thong ke co ban";
		//cout << "\n6. Xem menu chi tiet";
		cout << "\n0. Thoat chuong trinh";

		//Nhap chuc nang
		cout << "\nVui long nhap chuc nang (VD: 1): ";
		cin >> Func;
	} while (KiemTraChucNangMenuChinh(Func) == false);
	
	//NhapChucNangMenuChinh(Func, 0); //MenuType = 0: menu rut gon; MenuType = 1: menu chi tiet
}

/*
void MenuChiTiet(string &Func)
{
	do
	{
		system("cls");
		//DESIGN GIAO DIEN MENU
		for (int i = 1; i <= 57; i++)
		{
			cout << "=";
		}
		cout << "\n| QUAN LI THU VIEN";
		cout << setw(39) << "Date: xx/xx/xxxx |\n";
		for (int i = 1; i <= 57; i++)
		{
			cout << "=";
		}
		cout << "\nCac chuc nang cua chuong trinh:";

		//In ra menu
		cout << "\n1. Quan li doc gia";
		XuatChucNangFunction1();
		cout << "\n2. Quan li sach";
		XuatChucNangFunction2();
		cout << "\n3. Lap phieu mua sach";
		cout << "\n4. Lap phieu tra sach";
		cout << "\n5. Cac thong ke co ban";
		XuatChucNangFunction5();
		cout << "\n6. Xem menu chi tiet";
		cout << "\n0. Thoat chuong trinh";
		cout << "\nVui long nhap chuc nang (VD: 1, 1a): ";
		cin >> Func;
	} while (KiemTraChucNangMenuChinh(Func) == false && KiemTraChucNangMenuCon(Func) == false);
	
	if (KiemTraChucNangMenuChinh(Func)) NhapChucNangMenuChinh(Func, 1);
	if (KiemTraChucNangMenuCon(Func)) NhapChucNangMenuCon(Func);
	
	string Func;
	cout << "\nVui long nhap chuc nang (VD: 1, 1a): ";
	cin >> Func;
	if (Func.length() == 1)
	{
		NhapChucNangMenuChinh(Func, 1);
	}
	else
	{
		NhapChucNangMenuCon(Func,1);
	}
	
	
}
*/

bool KiemTraChucNangMenuChinh(char Func[])
{
	if (strcmp(Func, "1") == 0) return true;
	if (strcmp(Func, "2") == 0) return true;
	if (strcmp(Func, "3") == 0) return true;
	if (strcmp(Func, "4") == 0) return true;
	if (strcmp(Func, "5") == 0) return true;
	//if (Func == "6") return true;
	if (strcmp(Func, "0") == 0) return true;
	return false;
}

//KiemTraChucNangMenuCon, KiemTraChucNangMenuChinh, NhapChucNangMenuChinh
/*
bool KiemTraChucNangMenuCon(string Func)
{
	if (Func == "1a") return true;
	if (Func == "1b") return true;
	if (Func == "1c") return true;
	if (Func == "1d") return true;
	if (Func == "1e") return true;
	if (Func == "1f") return true;
	if (Func == "2a") return true;
	if (Func == "2b") return true;
	if (Func == "2c") return true;
	if (Func == "2d") return true;
	if (Func == "2e") return true;
	if (Func == "2f") return true;
	if (Func == "5a") return true;
	if (Func == "5b") return true;
	if (Func == "5c") return true;
	if (Func == "5d") return true;
	if (Func == "5e") return true; 
	if (Func == "5f") return true;
	return false;
}


void NhapChucNangMenuChinh(string Func, bool MenuType)
{
	if (Func == "1") { Func1_Menu(); return; }
	if (Func == "2") { return; }
	if (Func == "3") { return; }
	if (Func == "4") { return; }
	if (Func == "5") { return; }
	if (Func == "6")
	{
		if (MenuType == 0) MenuChiTiet();
		return;
	}
	if (Func == "0") exit(0);
}

//NhapChucNangMenuCon
/*
void NhapChucNangMenuCon(string Func)
{
	if (Func == "1a") { Func1a; return; }
	if (Func == "1b") { return; }
	if (Func == "1c") { return; }
	if (Func == "1d") { return; }
	if (Func == "1e") { return; }
	if (Func == "1f") { return; }
	if (Func == "2a") { return; }
	if (Func == "2b") { return; }
	if (Func == "2c") { return; }
	if (Func == "2d") { return; }
	if (Func == "2e") { return; }
	if (Func == "2f") { return; }
	if (Func == "5a") { return; }
	if (Func == "5b") { return; }
	if (Func == "5c") { return; }
	if (Func == "5d") { return; }
	if (Func == "5e") { return; }
	if (Func == "5f") { return; }
}
*/




//CAC HAM HO TRO (TINH TOAN, IN, ...)

//Ham tinh do dai cua so nguyen duong
int NumberLength(int Number)
{
	int Length = 0;
	if (Number == 0) Length = 1;
	while (Number != 0)
	{
		Number /= 10;
		Length++;
	}
	return Length;
}

void Spaces(int Distance)
{
	for (int i = 1; i <= Distance; i++) cout << " ";
}

void XoaDong()
{
	cout << "\x1b[1A"; //Di chuyen con tro len tren 1 lan
	cout << "\x1b[2K"; //Xoa dong con tro dang o
	/*
	x1b: Escape Charater: dung de bat dau mot chuoi dieu khien dac biet (VD ANSI escape codes)
	[1A: 1 la [so dong], A la dieu khien con tro len tren [so dong] dong
	[2K: 2 la xoa, 2K la xoa toan bo noi dung cua dong hien tai
	*Note: [1A va [2K duoc goi la ma dieu khien ANSI
	*/
}

void LuuNgayThangNam(char NgayThangNam[])
{
	/*
	int Ngay = stoi(NgayThangNam.substr(0, 2));
	int Thang = stoi(NgayThangNam.substr(2, 2));
	int Nam = stoi(NgayThangNam.substr(4, 4));
	NgayThangNam = to_string(Ngay) + "/" + to_string(Thang) + "/" + to_string(Nam);
	*/

	Insert(NgayThangNam, 2, '/');
	Insert(NgayThangNam, 5, '/');
}

//Ham in hoa tat ca cac ki tu trong xau (de thuan tien so sanh)
char* upperString(char Xau[100])
{
	char* newXau = new char[100];
	for (int i = 0; i <= strlen(Xau); i++)
	{
		if (Xau[i] >= 97 && Xau[i] <= 122) newXau[i] = Xau[i] - 32;
		else newXau[i] = Xau[i];
	}
	return newXau;
}

char upperChar(char& KyTu)
{
	if (KyTu >= 97 && KyTu <= 122) KyTu = KyTu - 32;
	return KyTu;
}

char lowerChar(char& KyTu)
{
	if (KyTu >= 'A' && KyTu <= 'Z') KyTu = KyTu + ('a' - 'A');
	return KyTu;
}

//Fix gia nhap sai cach: VD: 5000000 (string) -> 5.000.000 (string)
void FixGia(char Gia[])
{
	//012(3)456(7)89A  (length() = 11)
	//012   345   678  (length() = 9)
	int ViTri = strlen(Gia) - 3 - 1;
	while (ViTri >= 0)
	{
		if (Gia[ViTri] != '.')
		{
			ViTri++;
			Insert(Gia, ViTri, '.');
		}
		ViTri -= 4;
	}
}

char* Substr(char ChuoiCanTrich[], int ViTriDau, int SoKiTu)
{
	char* ChuoiKetQua = new char[20];
	int DiaChi = 0;
	for (int i = ViTriDau; i <= ViTriDau + SoKiTu - 1; i++)
	{
		ChuoiKetQua[DiaChi++] = ChuoiCanTrich[i];
	}
	ChuoiKetQua[DiaChi] = '\0';
	return ChuoiKetQua;
}

void Insert(char ChuoiKiTu[], int ViTri, char KiTu)
{
	for (int i = strlen(ChuoiKiTu); i >= ViTri; i--) //Lay ca ki tu Null
	{
		ChuoiKiTu[i + 1] = ChuoiKiTu[i];
	}
	ChuoiKiTu[ViTri] = KiTu;
}

int FindKiTu(char ChuoiKiTu[], char KiTu)
{
	for (int i = 0; i < strlen(ChuoiKiTu); i++)
	{
		if (ChuoiKiTu[i] == KiTu)
		{
			return i;
		}
	}
	return -1;
}

void EraseKiTu(char ChuoiKiTu[], int ViTri)
{
	for (int i = ViTri; i < strlen(ChuoiKiTu); i++)
	{
		ChuoiKiTu[i] = ChuoiKiTu[i + 1];
	}
	ChuoiKiTu[strlen(ChuoiKiTu) + 1] = '\0';
}

void FixChuoiKyTu(char HoVaTen[])
{
	//Fix "   NguYEn   VAn     AN  " -> "Nguyen Van An"
	while (HoVaTen[0] ==  ' ')
	{
		EraseKiTu(HoVaTen, 0); // Xoa ' ' dau dong
	}
	int i = 0;
	while (HoVaTen[i] != 0)
	{
		if (i == 0) //In hoa ky tu dau dong
		{
			upperChar(HoVaTen[i]);
			i++;
		}
		else
		{
			if (HoVaTen[i - 1] != ' ') // Viet thuong cac ky tu khong phai ky tu dau
			{
				lowerChar(HoVaTen[i]);
				i++;
			}
			if (HoVaTen[i - 1] == ' ')
			{
				if (HoVaTen[i] == ' ') EraseKiTu(HoVaTen, i); // Xoa dau cach thua
				else
				{
					upperChar(HoVaTen[i]); // In hoa ky tu dau sau dau cach
					i++;
				}
			}
		}
	}
}

bool checkEmail(char Email[])
{
	// Format Email chuan: localpart@domain (trong domain co it nhat 1 dau '.'
	char localpart[30] = { 0 };
	char domain[20] = { 0 };
	if (FindKiTu(Email, '@') == -1) return false;
	sscanf_s(Email, "%[^@]@%s", localpart, 30, domain, 20); //%[^@]: doc toi khi nao gap ki tu '@'
	if (localpart[0] == 0 || domain[0] == 0) return false;
	if (FindKiTu(domain, '.') == -1) return false;
	return true;
}