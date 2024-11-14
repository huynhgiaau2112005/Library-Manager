#pragma once
#include <string>
#include <iostream>

using namespace std;

#pragma region Khai bao Struct
struct strDocGia
{
	int Ma;
	char HoVaTen[100];
	char CCCD[100];
	char NgaySinh[100];
	char GioiTinh[100];
	char Email[100];
	char DiaChi[100];
	char NgayLapThe[100];
	char NgayHetHanThe[100];
};

struct strSach
{
	int Ma;
	char Ten[100];
	char TacGia[100];
	char NhaXB[100];
	int NamXB;
	char TheLoai[100];
	char Gia[100];
	int SoLuong;
};

struct strMuonTra
{
	int Ma;
	char NgayMuon[100];
	char NgayTraDK[100];
	char NgayTraTT[100];
};

struct strTaiKhoan
{
	char Username[50];
	char Password[50];
	char Email[50];
};
#pragma endregion

#pragma region Cac ham doc Files va xuat du lieu vao Files
//Doc du lieu tu Files
void read_DocGia(FILE* f, int& SoDocGia, strDocGia DocGia[100]);
void read_Sach(FILE* f, int& ListSach, strSach Sach[100]);
void read_MuonTra(FILE* f, int& TongSoSachMuon, int MuonSoSach[100], strMuonTra MuonTra[100]);
void read_TaiKhoan(FILE* f, int& SoTaiKhoan, strTaiKhoan TaiKhoan[100]);
//Xuat du lieu vao Files
void save_DocGia(FILE* f, int SoDocGia, strDocGia DocGia[100]);
void save_Sach(FILE* f, int ListSach, strSach Sach[100]);
void save_MuonTra(FILE* f, int TongSoSachMuon, int MuonSoSach[100], strMuonTra MuonTra[100]);
void save_TaiKhoan(FILE* f, int SoTaiKhoan, strTaiKhoan TaiKhoan[100]);
#pragma endregion

//CAC HAM
//Luu tru cac ham cho Trang Chu + cac ham ho tro khac
#pragma region Trang Chu + Cac ham ho tro khac
//Cac ham chinh thuc hien chuc nang cua Trang Chu
void MenuRutGon(char Func[], char CurrentDate[11]);
bool KiemTraChucNangMenuChinh(char Func[]);
//Cac ham ho tro khac cho chuong trinh
int NumberLength(int Number);
void Spaces(int Distance);
void XoaDong();
void LuuNgayThangNam(char NgayThangNam[]);
char* upperString(char Xau[100]);
char upperChar(char& KyTu);
char lowerChar(char& KyTu);
void FixGia(char Gia[]);
char* Substr(char ChuoiCanTrich[], int ViTriDau, int SoKiTu);
void Insert(char ChuoiKiTu[], int ViTri, char KiTu);
int FindKiTu(char ChuoiKiTu[], char KiTu);
void EraseKiTu(char ChuoiKiTu[], int ViTri);
void FixChuoiKyTu(char ChuoiKyTu[]);
bool checkEmail(char Email[]);
#pragma endregion

//Luu tru cac ham cho chuc nang Login:
#pragma region Account
//Menu
void MenuAccount(int& SoTaiKhoan, strTaiKhoan TaiKhoan[100]);
bool Account_KiemTraChucNangMenu(char Func);
void Account_NhapChucNangMenu(char Func, int& SoTaiKhoan, strTaiKhoan TaiKhoan[100]);
//Login
void AccountLogin(int& SoTaiKhoan, strTaiKhoan TaiKhoan[100]);
int ViTri_Username(strTaiKhoan loginAccount, int SoTaiKhoan, strTaiKhoan TaiKhoan[100]);
//Register
void AccountRegister(int& SoTaiKhoan, strTaiKhoan TaiKhoan[100]);
bool checkUsername(strTaiKhoan Account);
bool checkPassword(strTaiKhoan Account);
void saveTaiKhoan(strTaiKhoan registerAccount, int& SoTaiKhoan, strTaiKhoan TaiKhoan[100]);
//int ViTri_Email(strTaiKhoan registerAccount, int& SoTaiKhoan, strTaiKhoan TaiKhoan[100]);
//Forget Password
void AccountForgetPassword(strTaiKhoan forgetAccount, int& SoTaiKhoan, strTaiKhoan TaiKhoan[100]);
#pragma endregion

//Luu tru cac ham cho chuc nang 1: Quan li doc gia
#pragma region Function 1: Quan li doc gia

void Func1_Menu(char CurrentDate[11], int& SoDocGia, strDocGia DocGia[100]);
bool Func1_KiemTraChucNangMenu(char Func[]);
void Func1_NhapChucNangMenu(char Func[], char CurrentDate[11], int& SoDocGia, strDocGia DocGia[100]);
#pragma region Function_1a
void Func1a(int& SoDocGia, strDocGia DocGia[100]);
void InThongTinDocGia(int& SoDocGia, strDocGia DocGia[100]);
#pragma endregion
#pragma region Function_1b
void Func1b(int& SoDocGia, strDocGia DocGia[100]);
bool CheckNgayThangNam(char NgayThangNam[]);
char* Tang4Nam(char NgayThangNam[]);
#pragma endregion
#pragma region Function_1c
void Func1c(int& SoDocGia, strDocGia DocGia[100]);
int ViTri_MaDG(strDocGia DocGia[100], int SoLuongPhanTu, int GiaTriCanTim);
#pragma endregion
#pragma region Function_1d
void Func1d(int& SoDocGia, strDocGia DocGia[100]);
void XoaThongTin(int& SoLuong, strDocGia DocGia[100], int ViTriXoa);
#pragma endregion
#pragma region Function_1e
void Func1e(int& SoDocGia, strDocGia DocGia[100]);
int ViTri_CCCD(strDocGia DocGia[100], int SoLuongPhanTu, char GiaTriCanTim[]);
#pragma endregion
#pragma region Function_1f
void Func1f(int& SoDocGia, strDocGia DocGia[100]);
int ViTri_HoVaTen(strDocGia DocGia[100], int SoLuongPhanTu, char GiaTriCanTim[]);
#pragma endregion
#pragma endregion

//Luu tru cac ham cho chuc nang 2: Quan li sach
#pragma region Function 2: Quan li sach
void Func2_Menu(char CurrentDate[11], int& ListSach, strSach Sach[100]);
bool Func2_KiemTraChucNangMenu(char Func[]);
void Func2_NhapChucNangMenu(char Func[], int& ListSach, strSach Sach[100]);
#pragma region Function_2a
void Func2a(int& ListSach, strSach Sach[100]);
void InThongTinSach(int& ListSach, strSach Sach[100]);
#pragma endregion
#pragma region Function_2b
void Func2b(int& ListSach, strSach Sach[100]);
#pragma endregion
#pragma region Function_2c
void Func2c(int& ListSach, strSach Sach[100]);
int ViTri_MaSach(strSach Sach[100], int SoLuongPhanTu, int GiaTriCanTim);
#pragma endregion
#pragma region Function_2d
void Func2d(int& ListSach, strSach Sach[100]);
void XoaThongTin(int& SoLuong, strSach Sach[100], int ViTriXoa);
#pragma endregion
#pragma region Function_2e
void Func2e(int& ListSach, strSach Sach[100]);
#pragma endregion
#pragma region Function_2f
void Func2f(int& ListSach, strSach Sach[100]);
int ViTri_TenSach(strSach Sach[100], int SoLuongPhanTu, char GiaTriCanTim[]);
#pragma endregion
#pragma endregion

//Luu tru cac ham cho chuc nang 3: Lap phieu muon sach
#pragma region Function 3: Lap phieu muon sach
void Func3(char CurrentDate[11], int SoDocGia, strDocGia DocGia[100], int &TongSoSachMuon, int MuonSoSach[100], strMuonTra MuonTra[100], int ListSach, strSach Sach[100]);
void ThongKeMuonTraSach(int SoDocGia, strDocGia DocGia[100], int TongSoSachMuon, int MuonSoSach[100], strMuonTra MuonTra[100], int ListSach, strSach Sach[100]);
int BoSungViTriMuonSach(int MaDGCanTim, int SoDocGia, strDocGia DocGia[100], int& TongSoSachMuon, int MuonSoSach[100], strMuonTra MuonTra[100], int ListSach, strSach Sach[100]);
int ViTriSachMuon(int MuonSoSach[100], int ScanMaDG);
void PhieuMuonSach(int MaDocGia, char HoVaTen[100], int MaSach, char TenSach[100], char NgayMuon[100], char NgayTraDK[100]);
#pragma endregion

//Luu tru cac ham cho chuc nang 4: Lap phieu tra sach
#pragma region Function 4: Lap phieu tra sach
void Func4(char CurrentDate[11], int SoDocGia, strDocGia DocGia[100], int TongSoSachMuon, int MuonSoSach[100], strMuonTra MuonTra[100], int ListSach, strSach Sach[100]);
int KhoangCachTuNgayDauNam(int day, int month, int year, int yearMoc);
int KhoangCach2Ngay(char NgayTruoc[], char NgaySau[]);
char* TienString(int TienInt);
int TienInt(char TienString[100]);
void PhieuTraSach(int MaDocGia, char HoVaTen[100], int MaSach, char TenSach[100], char GiaSach[100], char NgayMuon[100], char NgayTraDK[100], char NgayTraTT[100]);
#pragma endregion

//Luu tru cac ham cho chuc nang 5: Cac thong ke co ban
#pragma region Function 5: Cac thong ke co ban
void Func5_Menu(char CurrentDate[11], int SoDocGia, strDocGia DocGia[100], int TongSoSachMuon, int MuonSoSach[100], strMuonTra MuonTra[100], int ListSach, strSach Sach[100]);
bool Func5_KiemTraChucNangMenu(char Func[]);
void Func5_NhapChucNangMenu(char Func[], char CurrentDate[11], int SoDocGia, strDocGia DocGia[100], int TongSoSachMuon, int MuonSoSach[100], strMuonTra MuonTra[100], int ListSach, strSach Sach[100]);
#pragma region Func_5a
void Func5a(int ListSach, strSach Sach[100]);
#pragma endregion
#pragma region Func_5b
void Func5b(int ListSach, strSach Sach[100]);
int DemSoTrung(int ListSach, strSach Sach[100], char XetTheLoai[], int XetViTri, int& DemSoLuongSach);
#pragma endregion
#pragma region Func_5c
void Func5c(int SoDocGia);
#pragma endregion
#pragma region Func_5d
void Func5d(int SoDocGia, strDocGia DocGia[100]);
#pragma endregion
#pragma region Func_5e
void Func5e(int TongSoSachMuon, strMuonTra MuonTra[100]);
#pragma endregion
#pragma region Func_5f
void Func5f(char CurrentDate[11], int SoDocGia, strDocGia DocGia[100], int MuonSoSach[100], strMuonTra MuonTra[100]);
bool CheckDGTreHan(int ScanMaDG, char CurrentDate[11], int MuonSoSach[100], strMuonTra MuonTra[100]);
#pragma endregion
#pragma endregion