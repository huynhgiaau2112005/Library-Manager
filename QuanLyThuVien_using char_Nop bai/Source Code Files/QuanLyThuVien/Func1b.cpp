#include <iostream>
#include "lib.h"
#include <iomanip>
#include <stdbool.h>
#include <iostream>
#include <string.h>

char *Tang4Nam(char NgayThangNam[])
{
	int Nam = stoi(Substr(NgayThangNam, 6, 4)) + 4; //int Nam = Nam hien tai + 4
	char NgayThang[10];
	strcpy_s(NgayThang, sizeof(NgayThang), Substr(NgayThangNam, 0, 6)); //NgayThang = "xx/xx/"
	char charNam[10];
	sprintf_s(charNam, sizeof(charNam), "%d", Nam); //Ep kieu charNam = Nam o tren
	char* NgayThangNamMoi = new char[20];
	strcpy_s(NgayThangNamMoi, 20, NgayThang); //Luc nay NgayThangNamMoi = NgayThang
	strcat_s(NgayThangNamMoi, 20, charNam); //NgayThangNamMoi += charNam = NgayThang + charNam
	return NgayThangNamMoi;
}

//Giao dien chinh cua Function 1b - Them doc gia
void Func1b(int& SoDocGia, int MaDocGia[100], char HoVaTen[100][100], char CCCD[100][100], char NgaySinh[100][100], char GioiTinh[100][100], char Email[100][100], char DiaChi[100][100], char NgayLapThe[100][100], char NgayHetHanThe[100][100])
{
	while(true)
	{
		system("cls");
		//In ra dong dau: ...-------THEM DOC GIA-------...
		for (int i = 1; i <= 22; i++) cout << "-";
		cout << "THEM DOC GIA";
		for (int i = 1; i <= 22; i++) cout << "-";

		//In ra Ma doc gia
		MaDocGia[SoDocGia + 1] = MaDocGia[SoDocGia] + 1;
		cout << "\nMa doc gia: " << MaDocGia[SoDocGia + 1] << endl;
		for (int i = 1; i <= 56; i++) cout << "-";

		//Nhap thong tin ca nhan
		cout << endl << setw(36) << "Thong tin ca nhan\n";
		//Nhap ho va ten
		cout << "- Ho va ten: ";
		cin.ignore();
		gets_s(HoVaTen[SoDocGia + 1], sizeof(HoVaTen[100]));
		FixChuoiKyTu(HoVaTen[SoDocGia + 1]);
		XoaDong();
		cout << "- Ho va ten: " << HoVaTen[SoDocGia + 1] << endl;
		//Nhap gioi tinh
		cout << "- Gioi tinh (Nam/Nu): ";
		cin >> GioiTinh[SoDocGia + 1];
		while (strcmp(upperString(GioiTinh[SoDocGia + 1]), "NAM") != 0 && strcmp(upperString(GioiTinh[SoDocGia + 1]), "NU") != 0)
		{
			XoaDong();
			cout << "- Gioi tinh (Nam/Nu): ";
			cin >> GioiTinh[SoDocGia + 1];
		}
		if (strcmp(upperString(GioiTinh[SoDocGia + 1]), "NAM") == 0) strcpy_s(GioiTinh[SoDocGia + 1], sizeof(GioiTinh[100]), "Nam");
		else strcpy_s(GioiTinh[SoDocGia + 1], sizeof(GioiTinh[100]), "Nu");
		XoaDong();
		cout << "- Gioi tinh (Nam/Nu): " << GioiTinh[SoDocGia + 1] << endl;
		//Nhap ngay sinh
		cout << "- Ngay sinh (ddmmyyyy): ";
		cin >> NgaySinh[SoDocGia + 1];
		while (!CheckNgayThangNam(NgaySinh[SoDocGia + 1]))
		{
			XoaDong();
			cout << "- Ngay sinh (ddmmyyyy): ";
			cin >> NgaySinh[SoDocGia + 1];
		}
		LuuNgayThangNam(NgaySinh[SoDocGia + 1]); //Luu ki tu '/' o giua ngay, thang, nam
		XoaDong();
		cout << "- Ngay sinh (ddmmyyyy): " << NgaySinh[SoDocGia + 1] << endl;
		//Nhap CCCD
		cout << "- CCCD (12 so): ";
		cin >> CCCD[SoDocGia + 1];
		while (strlen(CCCD[SoDocGia + 1]) != 12)
		{
			XoaDong();
			cout << "- CCCD (12 so): ";
			cin >> CCCD[SoDocGia + 1];
		}
		//Nhap email
		cout << "- Email: ";
		cin >> Email[SoDocGia + 1];
		while (!checkEmail(Email[SoDocGia + 1]))
		{
			XoaDong();
			cout << "- Email: ";
			cin >> Email[SoDocGia + 1];
		}
		//Nhap dia chi
		cout << "- Dia chi: ";
		cin.ignore();
		gets_s(DiaChi[SoDocGia + 1], sizeof(DiaChi[100]));

		for (int i = 1; i <= 56; i++) cout << "-";

		//Nhap thong tin the
		cout << endl;
		Spaces(21);
		cout << "Thong tin the" << endl;
		//Nhap ngay lap the
		cout << "Ngay lap the (ddmmyyyy): ";
		cin >> NgayLapThe[SoDocGia + 1];
		while (!CheckNgayThangNam(NgayLapThe[SoDocGia + 1]))
		{
			XoaDong();
			cout << "Ngay lap the (ddmmyyyy): ";
			cin >> NgayLapThe[SoDocGia + 1];
		}
		LuuNgayThangNam(NgayLapThe[SoDocGia + 1]); //Them ki tu '/' o giua ngay, thang, nam
		XoaDong();
		cout << "Ngay lap the (ddmmyyyy): " << NgayLapThe[SoDocGia + 1] << endl;
		//Gan gia tri cho ngay het han the
		strcpy_s(NgayHetHanThe[SoDocGia + 1], sizeof(NgayHetHanThe[100]), Tang4Nam(NgayLapThe[SoDocGia + 1]));
		//In ra ngay het han the
		Spaces(5);
		cout << "> Ngay het han the: " << NgayHetHanThe[SoDocGia + 1] << endl;

		//Tang so doc gia len 1 va in ra thanh cong
		SoDocGia++;
		cout << endl;
		for (int i = 1; i <= 56; i++) cout << "-";
		cout << "\n Them doc gia thanh cong!\n";

		//Nhap chuc nang de tiep tuc chuong trinh
		for (int i = 1; i <= 56; i++) cout << "-";
		cout << "\n1. Them mot doc gia khac";
		cout << "\n2. Xem danh sach doc gia";
		cout << "\n0. Thoat chuc nang\n";
		char Func[2];
		cout << "> Chon mot chuc nang (VD: 1): ";
		cin >> Func;
		while (strcmp(Func, "0") != 0 && strcmp(Func, "1") != 0 && strcmp(Func, "2") != 0)
		{
			XoaDong();
			cout << "> Chon mot chuc nang (VD: 1): ";
			cin >> Func;
		}
		//Thuc hien chuc nang:
		if (strcmp(Func, "0") == 0) return;
		if (strcmp(Func, "2") == 0) { Func1a(SoDocGia, MaDocGia, HoVaTen, CCCD, NgaySinh, GioiTinh, Email, DiaChi, NgayLapThe, NgayHetHanThe); return; }
	}
}

bool CheckNgayThangNam(char NgayThangNam[])
{
	//Kiem tra xem nguoi dung co nhap dung 8 ki tu khong
	if (strlen(NgayThangNam) != 8) return false;
	//Gan gia tri cho bien so nguyen ngay, thang, nam
	int Ngay = stoi(Substr(NgayThangNam, 0, 2));
	int Thang = stoi(Substr(NgayThangNam, 2, 2));
	int Nam = stoi(Substr(NgayThangNam, 4, 4));
	//Kiem tra chi tiet
	if (Ngay <= 0 || Ngay > 31) return false;
	if (Thang <= 0 || Thang > 12) return false;
	if (Nam < 0) return false;
	switch (Thang)
	{
	case 1: //31 ngay
		break;
	case 2:
		if ((Nam % 4 == 0 && Nam % 100 != 0) || (Nam % 400 == 0))
		{
			if (Ngay > 29) return false;
		}
		else if (Ngay > 28) return false;
		break;
	case 3: //31 ngay
		break;
	case 4: if (Ngay == 31) return false;
		break;
	case 5: //31 ngay
		break;
	case 6: if (Ngay == 31) return false;
		return 0;
	case 7: //31 ngay
		break;
	case 8: //31 ngay
		break;
	case 9: if (Ngay == 31) return false;
		break;
	case 10: //31 Ngay
		break;
	case 11: if (Ngay == 31) return false;
		break;
	case 12: //31 Ngay
		break;
	}
	return true;
}