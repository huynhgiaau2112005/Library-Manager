#include <iostream>
#include "lib.h"
#include <iomanip>

using namespace std;

//Ham in ra giao dien cua Function 1a
void Func2a(int& ListSach, int MaSach[100], char TenSach[100][100], char TacGia[100][100], char NhaXB[100][100], int NamXB[100], char TheLoai[100][100], char GiaSach[100][100], int SoSach[100])
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
	InThongTinSach(ListSach, MaSach, TenSach, TacGia, NhaXB, NamXB, TheLoai, GiaSach, SoSach);

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
void InThongTinSach(int& ListSach, int MaSach[100], char TenSach[100][100], char TacGia[100][100], char NhaXB[100][100], int NamXB[100], char TheLoai[100][100], char GiaSach[100][100], int SoSach[100])
{
	for (int i = 1; i <= ListSach; i++)
	{
		cout << " " << i;
		Spaces(4 - NumberLength(i));
		cout << MaSach[i];
		Spaces(2);
		cout << TenSach[i];
		Spaces(32 - strlen(TenSach[i]));
		cout << TacGia[i];
		Spaces(22 - strlen(TacGia[i]));
		cout << NhaXB[i];
		Spaces(24 - strlen(NhaXB[i]));
		cout << NamXB[i];
		Spaces(5);
		cout << TheLoai[i];
		cout << setw(22 - strlen(TheLoai[i])) << GiaSach[i];
		cout << setw(9) << SoSach[i] << endl;
	}
	for (int i = 1; i <= 139; i++) cout << "-";
}