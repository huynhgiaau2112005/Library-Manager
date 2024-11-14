#include <iostream>
#include "lib.h"
#include <iomanip>

void Func5d(int SoDocGia, char GioiTinh[100][100])
{
	system("cls");
	cout << "Gioi tinh" << setw(12) << "So luong" << endl;
	for (int i = 1; i <= 21; i++) cout << "-";
	cout << endl;
	//In ra so luong doc gia co gioi tinh Nam
	int demNam = 0;
	for (int i = 1; i <= SoDocGia; i++)
	{
		if (strcmp(GioiTinh[i], "Nam") == 0) demNam++;
	}
	cout << "  Nam" << setw(13) << demNam << endl;
	//In ra so luong doc gia co gioi tinh Nu
	cout << "  Nu" << setw(14) << SoDocGia - demNam << endl;
	for (int i = 1; i <= 21; i++) cout << "-";
	
	//Chon 0 de tro ve menu
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