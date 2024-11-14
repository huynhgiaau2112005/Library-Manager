#include <iostream>
#include "lib.h"

//Ham chinh thuc hien chuc nang 5f
void Func5f(char CurrentDate[11], int SoDocGia, strDocGia DocGia[100], int MuonSoSach[100], strMuonTra MuonTra[100])
{
	system("cls");
	cout << "Danh sach doc gia tre han: ";
	int dem = 0; //Dem so doc gia bi tre han
	for (int i = 1; i <= SoDocGia; i++)
	{
		int ScanMaDG = DocGia[i].Ma % 1000;
		if (CheckDGTreHan(ScanMaDG, CurrentDate, MuonSoSach, MuonTra) == true)
		{
			dem++;
			cout << "\n" << dem << ". " << DocGia[i].Ma << " - " << DocGia[i].HoVaTen;
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

//Ham kiem tra xem doc gia co tre han khong
bool CheckDGTreHan(int ScanMaDG, char CurrentDate[11], int MuonSoSach[100], strMuonTra MuonTra[100])
{
	for (int i = ViTriSachMuon(MuonSoSach, ScanMaDG); i <= ViTriSachMuon(MuonSoSach, ScanMaDG) + MuonSoSach[ScanMaDG] - 1; i++)
	{
		if (strcmp(MuonTra[i].NgayTraTT, "chua tra ") != 0 && strcmp(MuonTra[i].NgayTraTT, "<mat sach>") != 0)
		{
			if (KhoangCach2Ngay(MuonTra[i].NgayMuon, MuonTra[i].NgayTraTT) > 7) return true;
		}
		if (strcmp(MuonTra[i].NgayTraTT, "chua tra ") == 0 || strcmp(MuonTra[i].NgayTraTT, "<mat sach>") == 0)
		{
			if (KhoangCach2Ngay(MuonTra[i].NgayMuon, CurrentDate) > 7) return true;
		}
	}
	return false;
}