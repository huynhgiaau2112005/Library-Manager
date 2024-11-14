#include <iostream>
#include "lib.h"
#include <iomanip>

using namespace std;

//Ham lay dia chi sach dang muon trong mang MuonSoSach[]
int ViTriSachMuon(int MuonSoSach[100], int ScanMaDG)
{
	int S = 0;
	for (int i = 1; i <= ScanMaDG - 1; i++)
	{
		S += MuonSoSach[i];
	}
	S++;
	return S;
}

//Ham thong ke thong tin muon/tra sach
void ThongKeMuonTraSach(int SoDocGia, int MaDocGia[100], char HoVaTen[100][100], int TongSoSachMuon, int MuonSoSach[100], int DS_MaSach[100], int ListSach, int MaSach[100], char TenSach[100][100], char NgayMuon[100][100], char NgayTraDK[100][100], char NgayTraTT[100][100])
{
	for (int ScanDG = 1; ScanDG <= SoDocGia; ScanDG++) //Xet tu doc gia dau toi doc gia cuoi
	{
		int ScanMaDG = MaDocGia[ScanDG] % 1000; //Su dung so duoi doc gia de in ra thong tin (VD: 1xxx lay xxx), de phong thong tin doc gia da bi xoa truoc do gay mat trat tu dia chi mang trong thong tin doc gia
		if (MuonSoSach[ScanMaDG] != 0)
		{
			int dem = ViTriSachMuon(MuonSoSach, ScanMaDG);
			cout << MaDocGia[ScanDG];
			Spaces(2);
			cout << HoVaTen[ScanDG];
			for (int ScanSach = 1; ScanSach <= MuonSoSach[ScanMaDG]; ScanSach++)
			{
				if (ScanSach == 1)
				{
					cout << setw(34 - strlen(HoVaTen[ScanDG])) << DS_MaSach[dem];
				}
				else
				{
					Spaces(35);
					cout << DS_MaSach[dem];
				}
				if (TimKiemViTri(MaSach, ListSach, DS_MaSach[dem]) != -1)
				{
					cout << "   " << TenSach[TimKiemViTri(MaSach, ListSach, DS_MaSach[dem])];
					cout << setw(44 - strlen(TenSach[TimKiemViTri(MaSach, ListSach, DS_MaSach[dem])])) << NgayMuon[dem];
					cout << setw(16) << NgayTraDK[dem];
					cout << setw(19) << NgayTraTT[dem];
					cout << endl;
				}
				else
				{
					cout << "   " << "<du lieu da bi xoa>";
					cout << setw(25) << NgayMuon[dem];
					cout << setw(16) << NgayTraDK[dem];
					cout << setw(19) << NgayTraTT[dem];
					cout << endl;
				}
				dem++;
			}
			for (int i = 1; i <= 128; i++) cout << "-";
			cout << endl;
		}
	}
}

int BoSungViTriMuonSach(int SoDocGia, int MaDocGia[100], int MaDGCanTim, int& TongSoSachMuon, int MuonSoSach[100], int DS_MaSach[100], char NgayMuon[100][100], char NgayTraDK[100][100], char NgayTraTT[100][100])
{
	//Tim dia chi cua mang MuonSoSach de cung cap thong tin muon/tra sach cho doc gia
	int dem = 0;
	int ViTriDocGia = MaDGCanTim % 1000;
	for (int i = 1; i <= ViTriDocGia; i++)
	{
		dem += MuonSoSach[i];
	}
	dem++;

	//Them khoang trong cho dia chi trong mang MuonSoSach vua tim duoc
	for (int i = TongSoSachMuon; i >= dem; i--)
	{
		DS_MaSach[i + 1] =  DS_MaSach[i];
		strcpy_s(NgayMuon[i + 1], sizeof(NgayMuon[100]), NgayMuon[i]);
		strcpy_s(NgayTraDK[i + 1], sizeof(NgayTraDK[100]), NgayTraDK[i]);
		strcpy_s(NgayTraTT[i + 1], sizeof(NgayTraTT[100]), NgayTraTT[i]);
	}
	
	//Tang so sach doc gia do muon len 1 don vi
	MuonSoSach[ViTriDocGia]++;

	//Tang tong so sach dang muon len 1 don vi
	TongSoSachMuon++;
	return dem;
}

//Ham thuc hien chuc nang chinh cua Chuc nang 3
void Func3(char CurrentDate[10], int SoDocGia, int MaDocGia[100], char HoVaTen[100][100], int& TongSoSachMuon, int MuonSoSach[100], int DS_MaSach[100], int ListSach, int MaSach[100], char TenSach[100][100], int SoSach[100], char NgayMuon[100][100], char NgayTraDK[100][100], char NgayTraTT[100][100])
{
	while (true)
	{
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

	#pragma region lap phieu muon sach
		//Thu tuc lap phieu muon sach:
		cout << "Lap phieu muon sach:\n";
			//Nhap ma doc gia
		int MaDGCanTim;
		cout << "- Ma doc gia: ";
		cin >> MaDGCanTim;
		while (TimKiemViTri(MaDocGia, SoDocGia, MaDGCanTim) == -1)
		{
			XoaDong();
			cout << "- Ma doc gia: ";
			cin >> MaDGCanTim;
		}
		XoaDong();
		cout << "- Ma doc gia: " << MaDGCanTim << " (" << HoVaTen[TimKiemViTri(MaDocGia, SoDocGia, MaDGCanTim)] << ")\n";
			//Xac dinh vi tri can bo sung trong mang luu thong tin muon sach (MuonSoSach[])
		int ViTriBoSung = BoSungViTriMuonSach(SoDocGia, MaDocGia, MaDGCanTim, TongSoSachMuon, MuonSoSach, DS_MaSach, NgayMuon, NgayTraDK, NgayTraTT);
			//Nhap ma sach can muon:
		cout << "- Ma sach can muon: ";
		cin >> DS_MaSach[ViTriBoSung];
		while (TimKiemViTri(MaSach, ListSach, DS_MaSach[ViTriBoSung]) == -1)
		{
			XoaDong();
			cout << "- Ma sach can muon: ";
			cin >> DS_MaSach[ViTriBoSung];
		}
		XoaDong();
		cout << "- Ma sach can muon: " << DS_MaSach[ViTriBoSung] << " (" << TenSach[TimKiemViTri(MaSach, ListSach, DS_MaSach[ViTriBoSung])] << ")\n";
			//Nhap ngay muon:
		cout << "- Nhap ngay muon (ddmmyyyy): ";
		cin >> NgayMuon[ViTriBoSung];
		while (!CheckNgayThangNam(NgayMuon[ViTriBoSung]) || KhoangCach2Ngay(NgayMuon[ViTriBoSung], CurrentDate) < 0)
		{
			XoaDong();
			cout << "- Nhap ngay muon (ddmmyyyy): ";
			cin >> NgayMuon[ViTriBoSung];
		}
		LuuNgayThangNam(NgayMuon[ViTriBoSung]);
		XoaDong();
		cout << "- Nhap ngay muon (ddmmyyyy): " << NgayMuon[ViTriBoSung] << endl;
			//Nhap ngay tra du kien (ddmmyyyy):
		cout << "- Nhap ngay tra du kien (ddmmyyyy): ";
		cin >> NgayTraDK[ViTriBoSung];
		while (!CheckNgayThangNam(NgayTraDK[ViTriBoSung]) || KhoangCach2Ngay(NgayMuon[ViTriBoSung], NgayTraDK[ViTriBoSung]) < 0 || KhoangCach2Ngay(NgayMuon[ViTriBoSung], NgayTraDK[ViTriBoSung]) > 7)
		{
			XoaDong();
			cout << "- Nhap ngay tra du kien (ddmmyyyy): ";
			cin >> NgayTraDK[ViTriBoSung];
		}
		LuuNgayThangNam(NgayTraDK[ViTriBoSung]);
		XoaDong();
		cout << "- Nhap ngay tra du kien (ddmmyyyy): " << NgayTraDK[ViTriBoSung] << endl;
			//Giam so luong sach xuong 1
		SoSach[TimKiemViTri(MaSach, ListSach, DS_MaSach[ViTriBoSung])]--;
			//Set ngay tra thuc te la "chua tra"
		strcpy_s(NgayTraTT[ViTriBoSung], sizeof(NgayTraTT[100]), "chua tra ");
		//In ra lap phieu thanh cong va chon 1 de refresh bang thong ke
		for (int i = 1; i <= 128; i++) cout << "-";
		char Func[2];
		cout << "\nLap phieu thanh cong! Chon 1 de in phieu muon sach: ";
		cin >> Func;
		while (strcmp(Func, "1") != 0)
		{
			XoaDong();
			cout << "\nLap phieu thanh cong! Chon 1 de in phieu muon sach: ";
			cin >> Func;
		}
	#pragma endregion

	#pragma region In phieu muon sach
		PhieuMuonSach(MaDGCanTim, HoVaTen[TimKiemViTri(MaDocGia, SoDocGia, MaDGCanTim)], DS_MaSach[ViTriBoSung], TenSach[TimKiemViTri(MaSach, ListSach, DS_MaSach[ViTriBoSung])], NgayMuon[ViTriBoSung], NgayTraDK[ViTriBoSung]);
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
		cout << "1. Lap mot phieu muon sach khac";
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

//In ra phieu muon sach
void PhieuMuonSach(int MaDocGia, char HoVaTen[100], int MaSach, char TenSach[100], char NgayMuon[100], char NgayTraDK[100])
{
	system("cls");
	cout << "****************************************************\n";
	cout << "                PHIEU MUON SACH\n";
	cout << "****************************************************\n";
	cout << "                    DOC GIA\n";
	cout << "Ma: " << MaDocGia << endl;
	cout << "Ho va ten: " << HoVaTen << endl << endl;
	cout << "                   SACH MUON\n";
	cout << "Ma: " << MaSach << endl;
	cout << "Ten sach: " << TenSach << endl << endl;
	cout << "               NGAY MUON/TRA SACH\n";
	cout << "Ngay muon:   " << NgayMuon << endl;
	cout << "Ngay tra DK: " << NgayTraDK << endl;
	cout << "****************************************************\n\n";
	system("pause");
}