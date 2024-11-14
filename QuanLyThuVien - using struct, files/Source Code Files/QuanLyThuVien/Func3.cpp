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
void ThongKeMuonTraSach(int SoDocGia, strDocGia DocGia[100], int TongSoSachMuon, int MuonSoSach[100], strMuonTra MuonTra[100], int ListSach, strSach Sach[100])
{
	for (int ScanDG = 1; ScanDG <= SoDocGia; ScanDG++) //Xet tu doc gia dau toi doc gia cuoi
	{
		int ScanMaDG = DocGia[ScanDG].Ma % 1000; //Su dung so duoi doc gia de in ra thong tin (VD: 1xxx lay xxx), de phong thong tin doc gia da bi xoa truoc do gay mat trat tu dia chi mang trong thong tin doc gia
		if (MuonSoSach[ScanMaDG] != 0)
		{
			int dem = ViTriSachMuon(MuonSoSach, ScanMaDG);
			cout << DocGia[ScanDG].Ma;
			Spaces(2);
			cout << DocGia[ScanDG].HoVaTen;
			for (int ScanSach = 1; ScanSach <= MuonSoSach[ScanMaDG]; ScanSach++)
			{
				if (ScanSach == 1)
				{
					cout << setw(34 - strlen(DocGia[ScanDG].HoVaTen)) << MuonTra[dem].Ma;
				}
				else
				{
					Spaces(35);
					cout << MuonTra[dem].Ma;
				}
				if (ViTri_MaSach(Sach, ListSach, MuonTra[dem].Ma) != -1)
				{
					cout << "   " << Sach[ViTri_MaSach(Sach, ListSach, MuonTra[dem].Ma)].Ten;
					cout << setw(44 - strlen(Sach[ViTri_MaSach(Sach, ListSach, MuonTra[dem].Ma)].Ten)) << MuonTra[dem].NgayMuon;
					cout << setw(16) << MuonTra[dem].NgayTraDK;
					cout << setw(19) << MuonTra[dem].NgayTraTT;
					cout << endl;
				}
				else
				{
					cout << "   " << "<du lieu da bi xoa>";
					cout << setw(25) << MuonTra[dem].NgayMuon;
					cout << setw(16) << MuonTra[dem].NgayTraDK;
					cout << setw(19) << MuonTra[dem].NgayTraTT;
					cout << endl;
				}
				dem++;
			}
			for (int i = 1; i <= 128; i++) cout << "-";
			cout << endl;
		}
	}
}

//Ham bo sung vi tri muon sach trong Mang luu du lieu muon - tra sach
int BoSungViTriMuonSach(int MaDGCanTim, int SoDocGia, strDocGia DocGia[100], int& TongSoSachMuon, int MuonSoSach[100], strMuonTra MuonTra[100], int ListSach, strSach Sach[100])
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
		MuonTra[i + 1].Ma =  MuonTra[i].Ma;
		strcpy_s(MuonTra[i + 1].NgayMuon, sizeof(MuonTra[100].NgayMuon), MuonTra[i].NgayMuon); 
		strcpy_s(MuonTra[i + 1].NgayTraDK, sizeof(MuonTra[100].NgayTraDK), MuonTra[i].NgayTraDK);
		strcpy_s(MuonTra[i + 1].NgayTraTT, sizeof(MuonTra[100].NgayTraTT), MuonTra[i].NgayTraTT);
	}
	
	//Tang so sach doc gia do muon len 1 don vi
	MuonSoSach[ViTriDocGia]++;

	//Tang tong so sach dang muon len 1 don vi
	TongSoSachMuon++;
	return dem;
}

//Ham thuc hien chuc nang chinh cua Chuc nang 3
void Func3(char CurrentDate[11], int SoDocGia, strDocGia DocGia[100], int& TongSoSachMuon, int MuonSoSach[100], strMuonTra MuonTra[100], int ListSach, strSach Sach[100])
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
		ThongKeMuonTraSach(SoDocGia, DocGia, TongSoSachMuon, MuonSoSach, MuonTra, ListSach, Sach);
	#pragma endregion

	#pragma region lap phieu muon sach
		//Thu tuc lap phieu muon sach:
		cout << "Lap phieu muon sach:\n";
			//Nhap ma doc gia
		int MaDGCanTim;
		cout << "- Ma doc gia: ";
		cin >> MaDGCanTim;
		while (ViTri_MaDG(DocGia, SoDocGia, MaDGCanTim) == -1)
		{
			XoaDong();
			cout << "- Ma doc gia: ";
			cin >> MaDGCanTim;
		}
		XoaDong();
		cout << "- Ma doc gia: " << MaDGCanTim << " (" << DocGia[ViTri_MaDG(DocGia, SoDocGia, MaDGCanTim)].HoVaTen << ")\n";
			//Xac dinh vi tri can bo sung trong mang luu thong tin muon sach (MuonSoSach[])
		int ViTriBoSung = BoSungViTriMuonSach(MaDGCanTim, SoDocGia, DocGia, TongSoSachMuon, MuonSoSach, MuonTra, ListSach, Sach);
			//Nhap ma sach can muon:
		cout << "- Ma sach can muon: ";
		cin >> MuonTra[ViTriBoSung].Ma; //<------------------------------------
		while (ViTri_MaSach(Sach, ListSach, MuonTra[ViTriBoSung].Ma) == -1)
		{
			XoaDong();
			cout << "- Ma sach can muon: ";
			cin >> MuonTra[ViTriBoSung].Ma;
		}
		XoaDong();
		cout << "- Ma sach can muon: " << MuonTra[ViTriBoSung].Ma << " (" << Sach[ViTri_MaSach(Sach, ListSach, MuonTra[ViTriBoSung].Ma)].Ten << ")\n";
			//Nhap ngay muon:
		cout << "- Nhap ngay muon (ddmmyyyy): ";
		cin >> MuonTra[ViTriBoSung].NgayMuon;
		while (!CheckNgayThangNam(MuonTra[ViTriBoSung].NgayMuon) || KhoangCach2Ngay(MuonTra[ViTriBoSung].NgayMuon, CurrentDate) < 0)
		{
			XoaDong();
			cout << "- Nhap ngay muon (ddmmyyyy): ";
			cin >> MuonTra[ViTriBoSung].NgayMuon;
		}
		LuuNgayThangNam(MuonTra[ViTriBoSung].NgayMuon);
		XoaDong();
		cout << "- Nhap ngay muon (ddmmyyyy): " << MuonTra[ViTriBoSung].NgayMuon << endl;
			//Nhap ngay tra du kien (ddmmyyyy):
		cout << "- Nhap ngay tra du kien (ddmmyyyy): ";
		cin >> MuonTra[ViTriBoSung].NgayTraDK;
		while (!CheckNgayThangNam(MuonTra[ViTriBoSung].NgayTraDK) || KhoangCach2Ngay(MuonTra[ViTriBoSung].NgayMuon, MuonTra[ViTriBoSung].NgayTraDK) < 0 || KhoangCach2Ngay(MuonTra[ViTriBoSung].NgayMuon, MuonTra[ViTriBoSung].NgayTraDK) > 7)
		{
			XoaDong();
			cout << "- Nhap ngay tra du kien (ddmmyyyy): ";
			cin >> MuonTra[ViTriBoSung].NgayTraDK;
		}
		LuuNgayThangNam(MuonTra[ViTriBoSung].NgayTraDK);
		XoaDong();
		cout << "- Nhap ngay tra du kien (ddmmyyyy): " << MuonTra[ViTriBoSung].NgayTraDK << endl;
			//Giam so luong sach xuong 1
		Sach[ViTri_MaSach(Sach, ListSach, MuonTra[ViTriBoSung].Ma)].SoLuong--;
			//Set ngay tra thuc te la "chua tra"
		strcpy_s(MuonTra[ViTriBoSung].NgayTraTT, sizeof(MuonTra[100].NgayTraTT), "chua tra ");
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
		PhieuMuonSach(MaDGCanTim, DocGia[ViTri_MaDG(DocGia, SoDocGia, MaDGCanTim)].HoVaTen, MuonTra[ViTriBoSung].Ma, Sach[ViTri_MaSach(Sach, ListSach, MuonTra[ViTriBoSung].Ma)].Ten, MuonTra[ViTriBoSung].NgayMuon, MuonTra[ViTriBoSung].NgayTraDK);
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
		ThongKeMuonTraSach(SoDocGia, DocGia, TongSoSachMuon, MuonSoSach, MuonTra, ListSach, Sach);
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