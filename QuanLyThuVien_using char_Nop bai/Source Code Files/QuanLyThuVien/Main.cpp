#include <iostream>
#include "lib.h"
#include <string.h>

using namespace std;

int main()
{
	//Khai bao bien
	#pragma region Thong tin Doc Gia
	//Chi su dung cac phan tu co chi so tu 1, khong dung phan tu co chi so 0
	int SoDocGia;
	int MaDocGia[100] = { 0, 1001, 1002, 1003, 1004 };
	char HoVaTen[100][100] = { "0", "Huynh Gia Au", "Nguyen Minh Luan", "Do Van Ha", "Do Nguyen Minh Triet" };
	char CCCD[100][100] = { "0", "051205088512", "051205113249", "051302586135", "051205179213" };
	char NgaySinh[100][100] = { "0", "27/11/2005", "11/01/2007", "20/02/2009", "05/12/2006"};
	char GioiTinh[100][100] = { "0", "Nam", "Nam", "Nu", "Nam" };
	char Email[100][100] = { "0", "huynhgiaau27112005@gmail.com", "nguyenminhluan@gmail.com", "HaDvan2002@gmail.com", "TrietTrivippro123@gmail.com" };
	char DiaChi[100][100] =
	{
		"0",
		"109/24/26 Duong Ba Trac, Q8, TP HCM",
		"100/02 Ma Lo, Binh Tan, TP HCM",
		"21 Nguyen Van Cu, Quan 5, TP HCM",
		"30 An Duong Vuong, Quan 5, TP HCM"
	};
	char NgayLapThe[100][100] = {"0", "07/11/2023", "09/12/2022", "01/01/2023", "31/12/2022"};
	char NgayHetHanThe[100][100] = {"0", "07/11/2027", "09/12/2026", "01/01/2027", "31/12/2026"};
#pragma endregion

	#pragma region Thong tin Sach
	int ListSach = 3;
	int MaSach[100] = { 0, 70297, 60780, 51935 };
	char TenSach[100][100] = { "0", "Sans Famille", "Harry Potter va Hoang tu lai", "The Universe in a Nutshell" };
	char TacGia[100][100] = { "0", "Hector Malot", "J. K. Rowling", "Stephen Hawking" };
	char NhaXB[100][100] = { "0", "Nha xuat ban Van hoc", "Bloomsbury Publishing", "Bantam Spectra" };
	int NamXB[100] = { 0, 1878, 2005, 2001 };
	char  TheLoai[100][100] = { "0", "Tieu thuyet", "Ky ao", "Khoa hoc" };
	char GiaSach[100][100] = { "0", "500.000", "399.999", "630.000" };
	int SoSach[100] = { 0, 20, 17, 21 };
#pragma endregion

	#pragma region Thong tin Muon/Tra sach
	char NgayMuon[100][100] = {"0", "20/11/2023", "20/11/2023", "21/11/2023", "21/11/2023", "20/11/2023", "23/11/2023"};
	char NgayTraDK[100][100] = { "0", "25/11/2023", "25/11/2023", "24/11/2023", "26/11/2023", "26/11/2023", "27/11/2023"};
	char NgayTraTT[100][100] = { "0", "24/11/2023", "26/11/2023", "chua tra ", "chua tra ", "25/11/2023", "chua tra " };
	int DS_MaSach[100] = {0, 60780, 70297, 51935, 60780, 60780, 51935};
	int MuonSoSach[100] = {0, 2, 1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int TongSoSachMuon = 6;
#pragma endregion

	//Khai bao ngay hien tai
	char CurrentDate[10];
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
			if (strcmp(Func, "1") == 0) { Func1_Menu(CurrentDate, SoDocGia, MaDocGia, HoVaTen, CCCD, NgaySinh, GioiTinh, Email, DiaChi, NgayLapThe, NgayHetHanThe); }
			if (strcmp(Func, "2") == 0) { Func2_Menu(CurrentDate, ListSach, MaSach, TenSach, TacGia, NhaXB, NamXB, TheLoai, GiaSach, SoSach); }
			if (strcmp(Func, "3") == 0) { Func3(CurrentDate, SoDocGia, MaDocGia, HoVaTen, TongSoSachMuon, MuonSoSach, DS_MaSach, ListSach, MaSach, TenSach, SoSach, NgayMuon, NgayTraDK, NgayTraTT); }
			if (strcmp(Func, "4") == 0) { Func4(CurrentDate, SoDocGia, MaDocGia, HoVaTen, TongSoSachMuon, MuonSoSach, DS_MaSach, ListSach, MaSach, TenSach, SoSach, GiaSach, NgayMuon, NgayTraDK, NgayTraTT); }
			if (strcmp(Func, "5") == 0) { Func5_Menu(CurrentDate, SoDocGia, MaDocGia, HoVaTen, GioiTinh, ListSach, MaSach, TenSach, TheLoai, SoSach, TongSoSachMuon, MuonSoSach, NgayMuon, NgayTraTT); }
			if (strcmp(Func, "0") == 0) exit(0);
		}
	}
	return 0;
}