#include <iostream>
#include "lib.h"
#include <iomanip>

using namespace std;

//Ham in ra giao dien cua Function 1a
void Func2a(int& ListSach, strSach Sach[100])
{
	//DESIGN GIAO DIEN
	system("cls");
	for (int i = 1; i <= 53; i++) cout << "-";
	cout << "DANH SACH SO SACH TRONG THU VIEN";
	for (int i = 1; i <= 53; i++) cout << "-";

	//In ra dong dau chua dac diem thong tin (Ma, Ho va ten, Gioi tinh, ...)
	cout << "\nSTT" << setw(6) << "ISBN" << setw(11) << "Ten sach" << setw(31) << "Tac gia";
	cout << setw(27) << "Nha xuat ban" << setw(18) << "Nam XB" << setw(11) << "The loai" << setw(15);
	cout << "Gia sach" << setw(11) << "So luong\n";
	for (int i = 1; i <= 139; i++) cout << "-";
	cout << endl;

	//Ham in ra thong tin chi tiet cac sach trong thu vien
	InThongTinSach(ListSach, Sach);

	//Nhan de thoat
	char Func[2];
	cout << "\nNhap 0 de thoat: ";
	cin >> Func;
	while (strcmp(Func, "0") != 0)
	{
		XoaDong();
		cout << "Nhap 0 de thoat: ";
		cin >> Func;
	}
}


//Ham in ra thong tin chi tiet cua cac sach trong thu vien
void InThongTinSach(int& ListSach, strSach Sach[100])
{
	for (int i = 1; i <= ListSach; i++)
	{
		cout << " " << i;
		Spaces(4 - NumberLength(i));
		cout << Sach[i].Ma;
		Spaces(2);
		cout << Sach[i].Ten;
		Spaces(32 - strlen(Sach[i].Ten));
		cout << Sach[i].TacGia;
		Spaces(22 - strlen(Sach[i].TacGia));
		cout << Sach[i].NhaXB;
		Spaces(24 - strlen(Sach[i].NhaXB));
		cout << Sach[i].NamXB;
		Spaces(5);
		cout << Sach[i].TheLoai;
		cout << setw(22 - strlen(Sach[i].TheLoai)) << Sach[i].Gia;
		cout << setw(9) << Sach[i].SoLuong << endl;
	}
	for (int i = 1; i <= 139; i++) cout << "-";
}