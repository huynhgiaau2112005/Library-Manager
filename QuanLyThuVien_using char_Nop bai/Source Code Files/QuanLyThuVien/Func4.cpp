#include <iostream>
#include "lib.h"
#include <iomanip>
#include <string>

//Ham check xem Ma Code nhap vao co chinh xac hay khong, tra ve True neu dung va False neu sai
bool CheckMaCode(int MaCode, int SoDau, int SoCuoi)
{
	bool check = false;
	//Kiem tra xem ma code nhap vao co phai cua doc gia can chinh sua hay khong
	for (int i = SoDau; i <= SoCuoi; i++)
	{
		if (MaCode == i) check = true;
	}
	if (check == true) return true;
	else return false;
}

//Ham thuc hinh chinh
void Func4(char CurrentDate[10], int SoDocGia, int MaDocGia[100], char HoVaTen[100][100], int TongSoSachMuon, int MuonSoSach[100], int DS_MaSach[100], int ListSach, int MaSach[100], char TenSach[100][100], int SoSach[100], char GiaSach[100][100], char NgayMuon[100][100], char NgayTraDK[100][100], char NgayTraTT[100][100])
{
	while (true)
	{
		system("cls");
#pragma region In ra bang thong ke muon/tra sach
		system("cls");
		//In ra title
		for (int i = 1; i <= 128; i++) cout << "-";
		cout << "\n\n" << setw(87) << "DANH SACH THONG KE MUON/TRA SACH TRONG THU VIEN\n";
		cout << setw(61) << "Date: " << CurrentDate << "\n\n";

		//In ra cac truong cua bang thong ke (DOC GIA, SACH, MUON/TRA)
		for (int i = 1; i <= 4; i++) cout << "-";
		cout << "DOC GIA";
		for (int i = 1; i <= 28; i++) cout << "-";
		cout << "SACH";
		for (int i = 1; i <= 50; i++) cout << "-";
		cout << "MUON/TRA";
		for (int i = 1; i <= 27; i++) cout << "-";

		//In ra cac thong tin cua bang
		cout << "\nMa" << setw(13) << "Ho va ten" << setw(22) << "Ma" << setw(14) << "Ten sach";
		cout << setw(35) << "Ngay muon" << setw(20) << "Ngay tra du kien" << setw(20) << "Ngay tra thuc te\n";
		for (int i = 1; i <= 128; i++) cout << "-";
		cout << endl;
		//Thong ke danh sach muon tra sach:
		ThongKeMuonTraSach(SoDocGia, MaDocGia, HoVaTen, TongSoSachMuon, MuonSoSach, DS_MaSach, ListSach, MaSach, TenSach, NgayMuon, NgayTraDK, NgayTraTT);
#pragma endregion

#pragma region Lap phieu tra sach
		//Nhap ma doc gia cua doc gia can lap phieu tra sach
		int MaDGCanTim;
		cout << "Nhap ma doc gia can tra sach: ";
		cin >> MaDGCanTim;
		while (TimKiemViTri(MaDocGia, SoDocGia, MaDGCanTim) == -1)
		{
			XoaDong();
			cout << "Nhap ma doc gia can tra sach: ";
			cin >> MaDGCanTim;
		}
		XoaDong();
		cout << "Nhap ma doc gia: " << MaDGCanTim << " - " << HoVaTen[TimKiemViTri(MaDocGia, SoDocGia, MaDGCanTim)];

		//In ra danh sach thong ke nhung sach chua tra cua doc gia
		cout << "\n\nDanh sach nhung sach chua tra cua doc gia " << MaDGCanTim << " - " << HoVaTen[TimKiemViTri(MaDocGia, SoDocGia, MaDGCanTim)] << endl;
		for (int i = 1; i <= 79; i++) cout << "-";
		cout << "\nCode  Ma Sach   Ten Sach" << setw(54) << "Ngay muon    Ngay tra du kien\n";
		for (int i = 1; i <= 79; i++) cout << "-";
		cout << endl;

		//Thong ke cac sach chua tra
		int ScanMaDG = MaDGCanTim % 1000;
		int ScanCode = ViTriSachMuon(MuonSoSach, ScanMaDG);
		int SoSachChuaTra = 0; //dem so sach chua tra cua doc gia
		for (int i = ScanCode; i <= ScanCode + MuonSoSach[ScanMaDG] - 1; i++)
		{
			if (strcmp(NgayTraTT[i], "chua tra ") != 0 && strcmp(NgayTraTT[i], "<mat sach>") != 0) continue;
			cout << " " << i << "."; //In ra ma code muon/tra sach
			cout << setw(9 - NumberLength(i)) << DS_MaSach[i]; //In ra ISBN cua sach dang muon
			Spaces(5);
			cout << TenSach[TimKiemViTri(MaSach, ListSach, DS_MaSach[i])]; //In ra ten sach dang muon
			cout << setw(42 - strlen(TenSach[TimKiemViTri(MaSach, ListSach, DS_MaSach[i])])) << NgayMuon[i]; //In ra ngay muon sach
			cout << setw(16) << NgayTraDK[i]; //In ra ngay tra sach du kien
			cout << endl;

			//Tang so sach chua tra len 1 don vi
			SoSachChuaTra++;
		}
		if (SoSachChuaTra == 0)
		{
			cout << setw(52) << "<khong co sach dang muon>\n";
			for (int i = 1; i <= 79; i++) cout << "-";
			char Func[2];
			cout << "\n1. Lap phieu tra sach khac";
			cout << "\n0. Thoat chuc nang";
			cout << "\n> Nhap chuc nang (VD: 1): ";
			cin >> Func;
			while (strcmp(Func, "1") != 0 && strcmp(Func, "0") != 0)
			{
				XoaDong();
				cout << "> Nhap chuc nang (VD: 1): ";
				cin >> Func;
			}
			if (strcmp(Func, "1") == 0) continue;
			else return;
		}
		for (int i = 1; i <= 79; i++) cout << "-";

		//Nhap ma code cua sach can tra
		int MaCode; //Ma code dong thoi la dia chi cua thong tin ngay muon/ngay tra/ISBN trong mang
		cout << "\nNhap ma code (VD: 1): ";
		cin >> MaCode;
		while (!CheckMaCode(MaCode, ScanCode, ScanCode + MuonSoSach[ScanMaDG] - 1) || (strcmp(NgayTraTT[MaCode], "chua tra ") != 0 && strcmp(NgayTraTT[MaCode], "<mat sach>") != 0))
		{
			XoaDong();
			cout << "Nhap ma code (VD: 1): ";
			cin >> MaCode;
		}
		//Chon hinh thuc nhap thong tin tra sach
		char Func[2];
		cout << "a. Nhap ngay tra sach\n";
		cout << "b. Doc gia lam mat sach\n";
		cout << "> Chon hinh thuc nhap (VD: a): ";
		cin >> Func;
		while (strcmp(Func, "a") != 0 && strcmp(Func, "b") != 0)
		{
			cout << "> Chon hinh thuc nhap (VD: a): ";
			cin >> Func;
		}
		//Thuc hien hinh thuc nhap thong tin tra sach
		XoaDong();
		XoaDong();
		XoaDong();
		if (strcmp(Func, "a") == 0)
		{
			cout << "- Nhap ngay tra sach: ";
			cin >> NgayTraTT[MaCode];
			while (!CheckNgayThangNam(NgayTraTT[MaCode]) || KhoangCach2Ngay(NgayMuon[MaCode], NgayTraTT[MaCode]) < 0 || KhoangCach2Ngay(NgayTraTT[MaCode], CurrentDate) < 0)
			{
				XoaDong();
				cout << "- Nhap ngay tra sach: ";
				cin >> NgayTraTT[MaCode];
			}
			SoSach[TimKiemViTri(MaSach, ListSach, DS_MaSach[MaCode])];
			LuuNgayThangNam(NgayTraTT[MaCode]);
			XoaDong();
			cout << "- Nhap ngay tra sach: " << NgayTraTT[MaCode];
			SoSach[TimKiemViTri(MaSach, ListSach, DS_MaSach[MaCode])]++;
		}
		else
		{
			cout << "- Doc gia da lam mat sach";
			strcpy_s(NgayTraTT[MaCode], sizeof(NgayTraTT[100]), "<mat sach>");
		}

		//In ra tinh hinh tra sach
		cout << "\nTinh hinh tra sach:\n";
		if (strcmp(Func, "a") == 0)
		{
			if (KhoangCach2Ngay(NgayMuon[MaCode], NgayTraTT[MaCode]) <= 7) cout << "- Sach duoc tra dung han\n";
			else
			{
				int ThoiGianTre = KhoangCach2Ngay(NgayMuon[MaCode], NgayTraTT[MaCode]) - 7;
				cout << "Sach tra tre han " << ThoiGianTre << " ngay ";
				cout << "-> Nop phat: " << TienString(5000*ThoiGianTre) << " VND\n";
			}
		}
		else
		{
			//Tim vi tri cua sach bi mat
			int ViTri = TimKiemViTri(MaSach, ListSach, DS_MaSach[MaCode]);

			//In ra tien phat
			int TienPhat = 2 * TienInt(GiaSach[ViTri]);
			//cout << TienPhat;
			cout << "- Doc gia lam mat sach -> Nop phat: 200% x " << GiaSach[ViTri] << " = " << TienString(TienPhat) << " VND" << endl;
		}

		//In ra lap phieu thanh cong
		for (int i = 1; i <= 79; i++) cout << "-";
		cout << "\nLap phieu tra sach thanh cong! Chon 1 de in phieu tra sach: ";
		cin >> Func;
		while (strcmp(Func, "1") != 0)
		{
			XoaDong();
			cout << "- Lap phieu tra sach thanh cong! Chon 1 de in phieu tra sach: ";
			cin >> Func;
		}
#pragma endregion

#pragma region In phieu muon sach
		//Tim vi tri cua sach tra
		int ViTri = TimKiemViTri(MaSach, ListSach, DS_MaSach[MaCode]);
		PhieuTraSach(MaDGCanTim, HoVaTen[TimKiemViTri(MaDocGia, SoDocGia, MaDGCanTim)], DS_MaSach[MaCode], TenSach[TimKiemViTri(MaSach, ListSach, DS_MaSach[MaCode])], GiaSach[ViTri], NgayMuon[MaCode], NgayTraDK[MaCode], NgayTraTT[MaCode]);
#pragma endregion

#pragma region Tai lai bang thong ke
		//Tai lai bang thong ke:
		system("cls");
		//In ra title
		for (int i = 1; i <= 128; i++) cout << "-";
		cout << "\n\n" << setw(87) << "DANH SACH THONG KE MUON/TRA SACH TRONG THU VIEN\n";
		cout << setw(61) << "Date: " << CurrentDate << "\n\n";

		//In ra cac truong cua bang thong ke (DOC GIA, SACH, MUON/TRA)
		for (int i = 1; i <= 4; i++) cout << "-";
		cout << "DOC GIA";
		for (int i = 1; i <= 28; i++) cout << "-";
		cout << "SACH";
		for (int i = 1; i <= 50; i++) cout << "-";
		cout << "MUON/TRA";
		for (int i = 1; i <= 27; i++) cout << "-";

		//In ra cac thong tin cua bang
		cout << "\nMa" << setw(13) << "Ho va ten" << setw(22) << "Ma" << setw(14) << "Ten sach";
		cout << setw(35) << "Ngay muon" << setw(20) << "Ngay tra du kien" << setw(20) << "Ngay tra thuc te\n";
		for (int i = 1; i <= 128; i++) cout << "-";
		cout << endl;
		//Thong ke danh sach muon tra sach:
		ThongKeMuonTraSach(SoDocGia, MaDocGia, HoVaTen, TongSoSachMuon, MuonSoSach, DS_MaSach, ListSach, MaSach, TenSach, NgayMuon, NgayTraDK, NgayTraTT);
#pragma endregion

#pragma region Chon chuc nang tiep theo de tiep tuc chuong trinh
		//Chon chuc nang tiep theo de thuc thi chuong trinh
		cout << "1. Lap mot phieu tra sach khac";
		cout << "\n0. Thoat chuc nang";

		//Chon chuc nang
		cout << "\n> Chon chuc nang: ";
		cin >> Func;
		while (strcmp(Func, "0") != 0 && strcmp(Func, "1") != 0)
		{
			XoaDong();
			cout << "> Chon chuc nang: ";
			cin >> Func;
		}
		//Thuc thi chuc nang
		if (strcmp(Func, "0") == 0) return;
#pragma endregion
	}
}

//Ham In ra phieu tra sach
void PhieuTraSach(int MaDocGia, char HoVaTen[100], int MaSach, char TenSach[100], char GiaSach[100], char NgayMuon[100], char NgayTraDK[100], char NgayTraTT[100])
{
	system("cls");
	cout << "****************************************************\n";
	cout << "               PHIEU TRA SACH\n";
	cout << "****************************************************\n";
	cout << "                  DOC GIA\n";
	cout << "Ma: " << MaDocGia << endl;
	cout << "Ho va ten: " << HoVaTen << endl << endl;
	cout << "                   SACH\n";
	cout << "Ma: " << MaSach << endl;
	cout << "Ten sach: " << TenSach << endl << endl;
	cout << "            NGAY MUON/TRA SACH\n";
	cout << "Ngay muon:   " << NgayMuon << endl;
	cout << "Ngay tra DK: " << NgayTraDK << endl;
	
	//Neu doc gia co tra sach
	if (strcmp(NgayTraTT, "<mat sach>") != 0)
	{
		cout << "Ngay tra TT: " << NgayTraTT << endl << endl;
		int KC = KhoangCach2Ngay(NgayMuon, NgayTraTT); // KC (khoangcach) la so ngay nop tre
		if (KC - 7 > 0)
		{
			cout << "- Doc gia tra sach tre han " << KC << " ngay.\n";
			cout << "-> Nop phat: " << TienString(5000 * (KC - 7)) << " VND\n";
		}
		else
		{
			cout << "- Doc gia tra sach dung han.";
		}
	}	
	else
	{
		//In ra tien phat
		int TienPhat = 2 * TienInt(GiaSach);
		cout << "\n- Doc gia lam mat sach.\n-> Nop phat: 200% x " << GiaSach << " = " << TienString(TienPhat) << " VND";
	}
	cout << "\n****************************************************\n\n";
	system("pause");
}

//Ham tinh khoang cach ngay nhap vao so voi ngay 1/1/yearMoc (VD: Ham(10,1,2023,2023) = 10)
int KhoangCachTuNgayDauNam(int day, int month, int year, int yearMoc)
{
	int KhoangCach = 0;
	if (year > yearMoc)
	{
		for (int i = yearMoc; i <= year - 1; i++)
		{
			if (((i % 4 == 0) && (i % 100 != 0)) || (i % 400 == 0)) KhoangCach += 366;
			else KhoangCach += 365;
		}
	}
	int NgayThang2;
	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) NgayThang2 = 29;
	else NgayThang2 = 28;
	switch (month)
	{
	case 1:
		KhoangCach += day;
		break;
	case 2:
		KhoangCach += day + 31;
		break;
	case 3:
		KhoangCach += day + 31 + NgayThang2;
		break;
	case 4:
		KhoangCach += day + 31 + NgayThang2 + 31;
		break;
	case 5:
		KhoangCach += day + 31 + NgayThang2 + 31 + 30;
		break;
	case 6:
		KhoangCach += day + 31 + NgayThang2 + 31 + 30 + 31;
		break;
	case 7:
		KhoangCach += day + 31 + NgayThang2 + 31 + 30 + 31 + 30;
		break;
	case 8:
		KhoangCach += day + 31 + NgayThang2 + 31 + 30 + 31 + 30 + 31;
		break;
	case 9:
		KhoangCach += day + 31 + NgayThang2 + 31 + 30 + 31 + 30 + 31 + 31;
		break;
	case 10:
		KhoangCach += day + 31 + NgayThang2 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
		break;
	case 11:
		KhoangCach += day + 31 + NgayThang2 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
		break;
	case 12:
		KhoangCach += day + 31 + NgayThang2 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
		break;
	}
	return KhoangCach;
}

//Ham tinh khoang cach Ngay Sau - Ngay Truoc
int KhoangCach2Ngay(char NgayTruoc[], char NgaySau[])
{
	int Ngay1, Thang1, Nam1, Ngay2, Thang2, Nam2;
	//Gan gia tri cho bien so nguyen ngay, thang, nam cua ngay truoc
	if (strlen(NgayTruoc) == 10)
	{
		Ngay1 = stoi(Substr(NgayTruoc, 0, 2));
		Thang1 = stoi(Substr(NgayTruoc, 3, 2));
		Nam1 = stoi(Substr(NgayTruoc, 6, 4));
	}
	else
	{
		Ngay1 = stoi(Substr(NgayTruoc, 0, 2));
		Thang1 = stoi(Substr(NgayTruoc, 2, 2));
		Nam1 = stoi(Substr(NgayTruoc, 4, 4));
	}
	//Gan gia tri cho bien so nguyen ngay, thang, nam cua ngay sau
	if (strlen(NgaySau) == 10)
	{
		Ngay2 = stoi(Substr(NgaySau, 0, 2));
		Thang2 = stoi(Substr(NgaySau, 3, 2));
		Nam2 = stoi(Substr(NgaySau, 6, 4));
	}
	else
	{
		Ngay2 = stoi(Substr(NgaySau, 0, 2));
		Thang2 = stoi(Substr(NgaySau, 2, 2));
		Nam2 = stoi(Substr(NgaySau, 4, 4));
	}

	int KhoangCach = KhoangCachTuNgayDauNam(Ngay2, Thang2, Nam2, min(Nam1, Nam2)) - KhoangCachTuNgayDauNam(Ngay1, Thang1, Nam1, min(Nam1, Nam2));
	//cout << KhoangCachTuNgayDauNam(Ngay2, Thang2, Nam2, Nam1) << " - " << KhoangCachTuNgayDauNam(Ngay1, Thang1, Nam1, Nam1) << " = " << KhoangCach << endl << endl;
	return KhoangCach;
}

//Ham giup chuyen tien kieu int sang kieu string (VD: 500000 (int) thanh 500.000 (string)
char* TienString(int TienInt)
{
	//1000.000 (7: 0 -> 6) (6-3+1=4) (4-3)
	char* TienString_temp = new char[15];
	sprintf_s(TienString_temp, 15, "%d", TienInt);
	int ViTriDauCham = strlen(TienString_temp) - 4 + 1; //Vi tri can them dau cham trong Tien, quy luat length() - 4 + 1 - 3k (k >= 0)
	while (ViTriDauCham >= 1)
	{
		Insert(TienString_temp, ViTriDauCham, '.');
		ViTriDauCham -= 3;
	}
	return TienString_temp;
}

//Ham giup chuyen tien kieu string sang tien kieu int (VD: 500.000 (string) thanh 500000 (int))
int TienInt(char TienString[100])
{
	//Tim vi tri chua dau '.' trong xau TienString 
	char TienString_temp[100];
	strcpy_s(TienString_temp, 100, TienString);
	int ViTriDauCham = FindKiTu(TienString_temp, '.');
	while (ViTriDauCham != -1) //string:npos co nghia la khong duoc tim thay
	{
		EraseKiTu(TienString_temp, ViTriDauCham); //Xoa 1 ki tu ke tu vi tri dau '.' duoc tim thay
		ViTriDauCham = FindKiTu(TienString_temp, '.');
	}
	return stoi(TienString_temp);
}