#include <iostream>
#include "lib.h"

void Func5e(int TongSoSachMuon, char NgayTraTT[100][100])
{
	system("cls");
	//Dem so sach dang muon
	int SoSachDangMuon = 0;
	for (int i = 1; i <= TongSoSachMuon; i++)
	{
		if (strcmp(NgayTraTT[i], "chua tra ") == 0) SoSachDangMuon++;
	}
	cout << "So sach dang duoc muon (khong tinh sach bi mat): " << SoSachDangMuon << endl;
	//Dem so sach bi mat
	int SoSachBiMat = 0;
	for (int i = 1; i <= TongSoSachMuon; i++)
	{
		if (strcmp(NgayTraTT[i], "<mat sach>") == 0) SoSachBiMat++;
	}
	cout << "So sach bi mat: " << SoSachBiMat;

	//Chon 0 de tro ve menu:
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