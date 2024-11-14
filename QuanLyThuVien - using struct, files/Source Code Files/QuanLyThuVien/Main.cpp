#include <iostream>
#include "lib.h"
#include <string.h>

using namespace std;

int main()
{
	#pragma region Khai bao bien va mang
	//Mang chi su dung cac phan tu co chi so tu 1, khong dung phan tu co chi so 0	
	//Doc gia
	int SoDocGia;
	strDocGia DocGia[100];

	//Sach
	int ListSach;
	strSach Sach[100];

	//Thong tin Muon - Tra sach
	int MuonSoSach[100] = {0, 2, 1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int TongSoSachMuon = 6;
	strMuonTra MuonTra[100];

	//Thong tin tai khoan
	int SoTaiKhoan; //Bien luu tru so luong tai khoan de dang nhap
	strTaiKhoan TaiKhoan[100];
	#pragma endregion

	#pragma region Lay du lieu tu Files
	//Doc du lieu
	FILE* fDocGia, * fSach, * fMuonTra, * fTaiKhoan;
	fopen_s(&fDocGia, "DocGia.txt", "rt");
	read_DocGia(fDocGia, SoDocGia, DocGia); //Luu du lieu doc gia tu File vao cac bien
	fopen_s(&fSach, "Sach.txt", "rt");
	read_Sach(fSach, ListSach, Sach); //Luu du lieu sach tu File vao cac bien
	fopen_s(&fMuonTra, "MuonTra.txt", "rt");
	read_MuonTra(fMuonTra, TongSoSachMuon, MuonSoSach, MuonTra); //Luu du lieu thong tin muon tra tu File vao cac bien
	fopen_s(&fTaiKhoan, "TaiKhoan.txt", "rt");
	read_TaiKhoan(fTaiKhoan, SoTaiKhoan, TaiKhoan);
	_fcloseall();
	#pragma endregion

	#pragma region Dang nhap de Quan ly Thu vien
	//Dang nhap de vao quan ly thu vien
	MenuAccount(SoTaiKhoan, TaiKhoan);
	cout << "\nDang nhap thanh cong! Bam phim bat ky de vao quan ly thu vien\n";
	system("pause");
	#pragma endregion

	#pragma region Quan ly Thu vien
	//Khai bao ngay hien tai
	system("cls");
	char CurrentDate[11];
	cout << "Vui long nhap ngay hien tai (ddmmyyyy): ";
	cin >> CurrentDate;
	while (!CheckNgayThangNam(CurrentDate))
	{
		XoaDong();
		cout << "Vui long nhap ngay hien tai (ddmmyyyy): ";
		cin >> CurrentDate;
	}
	LuuNgayThangNam(CurrentDate);
	SoDocGia = 4;
	while (true)
	{
		char Func[2];
		MenuRutGon(Func, CurrentDate);

		//Thuc hien chuc nang
		{
			if (strcmp(Func, "1") == 0) { Func1_Menu(CurrentDate, SoDocGia, DocGia); }
			if (strcmp(Func, "2") == 0) { Func2_Menu(CurrentDate, ListSach, Sach); }
			if (strcmp(Func, "3") == 0) { Func3(CurrentDate, SoDocGia, DocGia, TongSoSachMuon, MuonSoSach, MuonTra, ListSach, Sach); }
			if (strcmp(Func, "4") == 0) { Func4(CurrentDate, SoDocGia, DocGia, TongSoSachMuon, MuonSoSach, MuonTra, ListSach, Sach); }
			if (strcmp(Func, "5") == 0) { Func5_Menu(CurrentDate, SoDocGia, DocGia, TongSoSachMuon, MuonSoSach, MuonTra, ListSach, Sach); }
			if (strcmp(Func, "0") == 0) break;
		}
	}
	#pragma endregion

	#pragma region Luu du lieu vao lai cac Files va ket thuc chuong trinh
	//Luu du lieu vao cac file
	fopen_s(&fDocGia, "DocGia.txt", "wt");
	save_DocGia(fDocGia, SoDocGia, DocGia);
	fopen_s(&fSach, "Sach.txt", "wt");
	save_Sach(fSach, ListSach, Sach); //Luu du lieu sach tu File vao cac bien
	fopen_s(&fMuonTra, "MuonTra.txt", "wt");
	save_MuonTra(fMuonTra, TongSoSachMuon, MuonSoSach, MuonTra);
	fopen_s(&fTaiKhoan, "TaiKhoan.txt", "wt");
	save_TaiKhoan(fTaiKhoan, SoTaiKhoan, TaiKhoan);
	_fcloseall();
	return 0;
	#pragma endregion
}