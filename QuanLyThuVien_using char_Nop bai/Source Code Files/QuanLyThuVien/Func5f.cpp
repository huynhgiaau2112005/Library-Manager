#include <iostream>
#include "lib.h"

void Func5f(char CurrentDate[10], int SoDocGia, int MaDocGia[100], char HoVaTen[100][100], int MuonSoSach[100], char NgayMuon[100][100], char NgayTraTT[100][100])
{
	system("cls");
	cout << "Danh sach doc gia tre han: ";
	int dem = 0; //Dem so doc gia bi tre han
	for (int i = 1; i <= SoDocGia; i++)
	{
		int ScanMaDG = MaDocGia[i] % 1000;
		if (CheckDGTreHan(ScanMaDG, CurrentDate, MuonSoSach, NgayMuon, NgayTraTT) == true)
		{
			dem++;
			cout << "\n" << dem << ". " << MaDocGia[i] << " - " << HoVaTen[i];
		}
	}
	if (dem == 0)
	{
		XoaDong();
		cout << "Khong co doc gia nao bi tre han";
	}

	//Chon 0 de tro ve menu
	char Func[2];
	cout << "\n\n> Chon 0 de tro ve menu: ";
	cin >> Func;
	while (strcmp(Func, "0") != 0)
	{
		XoaDong();
		cout << "> Chon 0 de tro ve menu: ";
		cin >> Func;
	}
}

bool CheckDGTreHan(int ScanMaDG, char CurrentDate[10], int MuonSoSach[100], char NgayMuon[100][100], char NgayTraTT[100][100])
{
	for (int i = ViTriSachMuon(MuonSoSach, ScanMaDG); i <= ViTriSachMuon(MuonSoSach, ScanMaDG) + MuonSoSach[ScanMaDG] - 1; i++)
	{
		if (strcmp(NgayTraTT[i], "chua tra ") != 0 && strcmp(NgayTraTT[i], "<mat sach>") != 0)
		{
			if (KhoangCach2Ngay(NgayMuon[i], NgayTraTT[i]) > 7) return true;
		}
		if (strcmp(NgayTraTT[i], "chua tra ") == 0 || strcmp(NgayTraTT[i], "<mat sach>") == 0)
		{
			if (KhoangCach2Ngay(NgayMuon[i], CurrentDate) > 7) return true;
		}
	}
	return false;
}