#include <iostream>
#include "lib.h"
#include <string>
#include <iomanip>
#include <cctype>

//Ham chinh thuc hien chuc nang 5b
void Func5b(int ListSach, strSach Sach[100])
{
	system("cls");
	cout << "The loai" << setw(20) << "So sach" << setw(18) << "So luong sach\n";
	for (int i = 1; i <= 46; i++) cout << "-";
	cout << endl;

	//In ra thong ke so sach tung the loai
	for (int i = 1; i <= ListSach; i++)
	{
		int DemSoLuongSach = 0; //Dem so luong sach co cung the loai (1 sach co nhieu so luong sach)
		int SoSachTheoTheLoai = DemSoTrung(ListSach, Sach, Sach[i].TheLoai, i, DemSoLuongSach); //Dem so sach co cung the loai
		if (SoSachTheoTheLoai != -1)
		{
			cout << Sach[i].TheLoai << setw(25 - strlen(Sach[i].TheLoai)) << SoSachTheoTheLoai << setw(15 - NumberLength(SoSachTheoTheLoai)) << DemSoLuongSach << endl;
		}
		else continue;
	}
	for (int i = 1; i <= 46; i++) cout << "-";

	//Nhap 0 de tro ve menu
	char Func[2];
	cout << "\n> Chon 0 de tro ve menu: ";
	cin >> Func;
	while (strcmp(Func, "0") != 0)
	{
		XoaDong();
		cout << "> Chon 0 de tro ve menu: ";
		cin >> Func;
	}
}

//Ham dem so luong sach co cung the loai
int DemSoTrung(int ListSach, strSach Sach[100], char XetTheLoai[], int XetViTri, int& DemSoLuongSach)
{
	for (int i = 1; i <= XetViTri - 1; i++)
	{
		if (strcmp(upperString(Sach[i].TheLoai), upperString(XetTheLoai)) == 0) return -1; //The loai nay trung voi the loai da duoc xet truoc do
	}
	int dem = 0;
	DemSoLuongSach = 0;
	for (int i = XetViTri; i <= ListSach; i++)
	{
		if (strcmp(upperString(Sach[i].TheLoai), upperString(XetTheLoai)) == 0)
		{
			DemSoLuongSach += Sach[i].SoLuong;
			dem++;
		}
	}
	return dem;
}