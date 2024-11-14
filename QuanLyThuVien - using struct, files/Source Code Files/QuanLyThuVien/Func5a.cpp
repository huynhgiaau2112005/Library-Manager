#include <iostream>
#include "lib.h"

//Ham chinh thuc hien chuc nang 5a
void Func5a(int ListSach, strSach Sach[100])
{
	system("cls");
	//In ra so sach va so luong sach
	cout << "So sach: " << ListSach;
	int SoLuongSach = 0;
	for (int i = 1; i <= ListSach; i++)
	{
		SoLuongSach += Sach[i].SoLuong;
	}
	cout << "\nSo luong sach: " << SoLuongSach;

	//Chon 0 de tro ve
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