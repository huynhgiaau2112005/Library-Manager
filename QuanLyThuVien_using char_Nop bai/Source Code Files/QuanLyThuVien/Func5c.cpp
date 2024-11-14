#include <iostream>
#include "lib.h"

void Func5c(int SoDocGia)
{
	system("cls");
	cout << "So luong doc gia: " << SoDocGia << "\n\n";

	//Chon 0 de tro ve
	char Func[2];
	cout << "> Chon 0 de tro ve menu: ";
	cin >> Func;
	while (strcmp(Func, "0") != 0)
	{
		XoaDong();
		cout << "> Chon 0 de tro ve menu: ";
		cin >> Func;
	}
}