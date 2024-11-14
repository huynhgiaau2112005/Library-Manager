#include <iostream>
#include "lib.h"
#include <iomanip>
#include <stdbool.h>
#include <iostream>
#include <string.h>

//Tang ngay/thang/nam len 4 nam (= 48 thang), phuc vu cho luu Ngay Het Han the
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
void Func1b(int& SoDocGia, strDocGia DocGia[100])
{
	while(true)
	{
		system("cls");
		//In ra dong dau: ...-------THEM DOC GIA-------...
		for (int i = 1; i <= 22; i++) cout << "-";
		cout << "THEM DOC GIA";
		for (int i = 1; i <= 22; i++) cout << "-";

		//In ra Ma doc gia
		DocGia[SoDocGia + 1].Ma = DocGia[SoDocGia].Ma + 1;
		cout << "\nMa doc gia: " << DocGia[SoDocGia + 1].Ma << endl;
		for (int i = 1; i <= 56; i++) cout << "-";

		//Nhap thong tin ca nhan
		cout << endl << setw(36) << "Thong tin ca nhan\n";
		//Nhap ho va ten
		cout << "- Ho va ten: ";
		cin.ignore();
		gets_s(DocGia[SoDocGia + 1].HoVaTen, sizeof(DocGia[100].HoVaTen));
		FixChuoiKyTu(DocGia[SoDocGia + 1].HoVaTen);
		XoaDong();
		cout << "- Ho va ten: " << DocGia[SoDocGia + 1].HoVaTen << endl;
		//Nhap gioi tinh
		cout << "- Gioi tinh (Nam/Nu): ";
		cin >> DocGia[SoDocGia + 1].GioiTinh;
		while (strcmp(upperString(DocGia[SoDocGia + 1].GioiTinh), "NAM") != 0 && strcmp(upperString(DocGia[SoDocGia + 1].GioiTinh), "NU") != 0)
		{
			XoaDong();
			cout << "- Gioi tinh (Nam/Nu): ";
			cin >> DocGia[SoDocGia + 1].GioiTinh;
		}
		if (strcmp(upperString(DocGia[SoDocGia + 1].GioiTinh), "NAM") == 0) strcpy_s(DocGia[SoDocGia + 1].GioiTinh, sizeof(DocGia[100].GioiTinh), "Nam");
		else strcpy_s(DocGia[SoDocGia + 1].GioiTinh, sizeof(DocGia[100].GioiTinh), "Nu");
		XoaDong();
		cout << "- Gioi tinh (Nam/Nu): " << DocGia[SoDocGia + 1].GioiTinh << endl;
		//Nhap ngay sinh
		cout << "- Ngay sinh (ddmmyyyy): ";
		cin >> DocGia[SoDocGia + 1].NgaySinh;
		while (!CheckNgayThangNam(DocGia[SoDocGia + 1].NgaySinh))
		{
			XoaDong();
			cout << "- Ngay sinh (ddmmyyyy): ";
			cin >> DocGia[SoDocGia + 1].NgaySinh;
		}
		LuuNgayThangNam(DocGia[SoDocGia + 1].NgaySinh); //Luu ki tu '/' o giua ngay, thang, nam
		XoaDong();
		cout << "- Ngay sinh (ddmmyyyy): " << DocGia[SoDocGia + 1].NgaySinh << endl;
		//Nhap CCCD
		cout << "- CCCD (12 so): ";
		cin >> DocGia[SoDocGia + 1].CCCD;
		while (strlen(DocGia[SoDocGia + 1].CCCD) != 12)
		{
			XoaDong();
			cout << "- CCCD (12 so): ";
			cin >> DocGia[SoDocGia + 1].CCCD;
		}
		//Nhap email
		cout << "- Email: ";
		cin >> DocGia[SoDocGia + 1].Email;
		while (!checkEmail(DocGia[SoDocGia + 1].Email))
		{
			XoaDong();
			cout << "- Email: ";
			cin >> DocGia[SoDocGia + 1].Email;
		}
		//Nhap dia chi
		cout << "- Dia chi: ";
		cin.ignore();
		gets_s(DocGia[SoDocGia + 1].DiaChi, sizeof(DocGia[100].DiaChi));

		for (int i = 1; i <= 56; i++) cout << "-";

		//Nhap thong tin the
		cout << endl;
		Spaces(21);
		cout << "Thong tin the" << endl;
		//Nhap ngay lap the
		cout << "Ngay lap the (ddmmyyyy): ";
		cin >> DocGia[SoDocGia + 1].NgayLapThe;
		while (!CheckNgayThangNam(DocGia[SoDocGia + 1].NgayLapThe))
		{
			XoaDong();
			cout << "Ngay lap the (ddmmyyyy): ";
			cin >> DocGia[SoDocGia + 1].NgayLapThe;
		}
		LuuNgayThangNam(DocGia[SoDocGia + 1].NgayLapThe); //Them ki tu '/' o giua ngay, thang, nam
		XoaDong();
		cout << "Ngay lap the (ddmmyyyy): " << DocGia[SoDocGia + 1].NgayLapThe << endl;
		//Gan gia tri cho ngay het han the
		strcpy_s(DocGia[SoDocGia + 1].NgayHetHanThe, sizeof(DocGia[100].NgayHetHanThe), Tang4Nam(DocGia[SoDocGia + 1].NgayLapThe));
		//In ra ngay het han the
		Spaces(5);
		cout << "> Ngay het han the: " << DocGia[SoDocGia + 1].NgayHetHanThe << endl;

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
		if (strcmp(Func, "2") == 0) { Func1a(SoDocGia, DocGia); return; }
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