#pragma once
#include <string>
#include <iostream>

using namespace std;

//CAC HAM
using namespace std;

void MenuRutGon(char Func[], char CurrentDate[10]);
bool KiemTraChucNangMenuChinh(char Func[]);
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

//Luu tru cac ham cho chuc nang 1: Quan li doc gia
#pragma region Function 1: Quan li doc gia

void Func1_Menu(char CurrentDate[10], int& SoDocGia, int MaDocGia[100], char HoVaTen[100][100], char CCCD[100][100], char NgaySinh[100][100], char GioiTinh[100][100], char Email[100][100], char DiaChi[100][100], char NgayLapThe[100][100], char NgayHetHanThe[100][100]);
bool Func1_KiemTraChucNangMenu(char Func[]);
void Func1_NhapChucNangMenu(char Func[], int& SoDocGia, int MaDocGia[100], char HoVaTen[100][100], char CCCD[100][100], char NgaySinh[100][100], char GioiTinh[100][100], char Email[100][100], char DiaChi[100][100], char NgayLapThe[100][100], char NgayHetHanThe[100][100]);
#pragma region Function_1a
void Func1a(int& SoDocGia, int MaDocGia[100], char HoVaTen[100][100], char CCCD[100][100], char NgaySinh[100][100], char GioiTinh[100][100], char Email[100][100], char DiaChi[100][100], char NgayLapThe[100][100], char NgayHetHanThe[100][100]);
void InThongTinDocGia(int& SoDocGia, int MaDocGia[100], char HoVaTen[100][100], char CCCD[100][100], char NgaySinh[100][100], char GioiTinh[100][100], char Email[100][100], char DiaChi[100][100], char NgayLapThe[100][100], char NgayHetHanThe[100][100]);
#pragma endregion
#pragma region Function_1b
void Func1b(int& SoDocGia, int MaDocGia[100], char HoVaTen[100][100], char CCCD[100][100], char NgaySinh[100][100], char GioiTinh[100][100], char Email[100][100], char DiaChi[100][100], char NgayLapThe[100][100], char NgayHetHanThe[100][100]);
bool CheckNgayThangNam(char NgayThangNam[]);
char* Tang4Nam(char NgayThangNam[]);
#pragma endregion
#pragma region Function_1c
void Func1c(int& SoDocGia, int MaDocGia[100], char HoVaTen[100][100], char CCCD[100][100], char NgaySinh[100][100], char GioiTinh[100][100], char Email[100][100], char DiaChi[100][100], char NgayLapThe[100][100], char NgayHetHanThe[100][100]);
int TimKiemViTri(int Mang[100], int SoLuongPhanTu, int GiaTriCanTim);
int TimKiemViTri(char Mang[100][100], int SoLuongPhanTu, char GiaTriCanTim[100]);
#pragma endregion
#pragma region Function_1d
void Func1d(int& SoDocGia, int MaDocGia[100], char HoVaTen[100][100], char CCCD[100][100], char NgaySinh[100][100], char GioiTinh[100][100], char Email[100][100], char DiaChi[100][100], char NgayLapThe[100][100], char NgayHetHanThe[100][100]);
void XoaThongTin(int& SoLuong, int ThongTin[100], int ViTriXoa);
void XoaThongTin(int& SoLuong, char ThongTin[100][100], int ViTriXoa);
#pragma endregion
#pragma region Function_1e
void Func1e(int& SoDocGia, int MaDocGia[100], char HoVaTen[100][100], char CCCD[100][100], char NgaySinh[100][100], char GioiTinh[100][100], char Email[100][100], char DiaChi[100][100], char NgayLapThe[100][100], char NgayHetHanThe[100][100]);
#pragma endregion
#pragma region Function_1f
void Func1f(int& SoDocGia, int MaDocGia[100], char HoVaTen[100][100], char CCCD[100][100], char NgaySinh[100][100], char GioiTinh[100][100], char Email[100][100], char DiaChi[100][100], char NgayLapThe[100][100], char NgayHetHanThe[100][100]);
#pragma endregion
#pragma endregion

//Luu tru cac ham cho chuc nang 2: Quan li sach
#pragma region Function 2: Quan li sach
void Func2_Menu(char CurrentDate[10], int& ListSach, int MaSach[100], char TenSach[100][100], char TacGia[100][100], char NhaXB[100][100], int NamXB[100], char TheLoai[100][100], char GiaSach[100][100], int SoSach[100]);
bool Func2_KiemTraChucNangMenu(char Func[]);
void Func2_NhapChucNangMenu(char Func[], int& ListSach, int MaSach[100], char TenSach[100][100], char TacGia[100][100], char NhaXB[100][100], int NamXB[100], char TheLoai[100][100], char GiaSach[100][100], int SoSach[100]);
#pragma region Function_2a
void Func2a(int& ListSach, int MaSach[100], char TenSach[100][100], char TacGia[100][100], char NhaXB[100][100], int NamXB[100], char TheLoai[100][100], char GiaSach[100][100], int SoSach[100]);
void InThongTinSach(int& ListSach, int MaSach[100], char TenSach[100][100], char TacGia[100][100], char NhaXB[100][100], int NamXB[100], char TheLoai[100][100], char GiaSach[100][100], int SoSach[100]);
#pragma endregion
#pragma region Function_2b
void Func2b(int& ListSach, int MaSach[100], char TenSach[100][100], char TacGia[100][100], char NhaXB[100][100], int NamXB[100], char TheLoai[100][100], char GiaSach[100][100], int SoSach[100]);
#pragma endregion
#pragma region Function_2c
void Func2c(int& ListSach, int MaSach[100], char TenSach[100][100], char TacGia[100][100], char NhaXB[100][100], int NamXB[100], char TheLoai[100][100], char GiaSach[100][100], int SoSach[100]);
#pragma endregion
#pragma region Function_2d
void Func2d(int& ListSach, int MaSach[100], char TenSach[100][100], char TacGia[100][100], char NhaXB[100][100], int NamXB[100], char TheLoai[100][100], char GiaSach[100][100], int SoSach[100]);
#pragma endregion
#pragma region Function_2e
void Func2e(int& ListSach, int MaSach[100], char TenSach[100][100], char TacGia[100][100], char NhaXB[100][100], int NamXB[100], char TheLoai[100][100], char GiaSach[100][100], int SoSach[100]);
#pragma endregion
#pragma region Function_2f
void Func2f(int& ListSach, int MaSach[100], char TenSach[100][100], char TacGia[100][100], char NhaXB[100][100], int NamXB[100], char TheLoai[100][100], char GiaSach[100][100], int SoSach[100]);
#pragma endregion
#pragma endregion

//Luu tru cac ham cho chuc nang 3: Lap phieu muon sach
#pragma region Function 3: Lap phieu muon sach
void Func3(char CurrentDate[10], int SoDocGia, int MaDocGia[100], char HoVaTen[100][100], int &TongSoSachMuon, int MuonSoSach[100], int DS_MaSach[100], int ListSach, int MaSach[100], char TenSach[100][100], int SoSach[100], char NgayMuon[100][100], char NgayTraDK[100][100], char NgayTraTT[100][100]);
void ThongKeMuonTraSach(int SoDocGia, int MaDocGia[100], char HoVaTen[100][100], int TongSoSachMuon, int MuonSoSach[100], int DS_MaSach[100], int ListSach, int MaSach[100], char TenSach[100][100], char NgayMuon[100][100], char NgayTraDK[100][100], char NgayTraTT[100][100]);
int BoSungViTriMuonSach(int SoDocGia, int MaDocGia[100], int MaDGCanTim, int &TongSoSachMuon, int MuonSoSach[100], int DS_MaSach[100], char NgayMuon[100][100], char NgayTraDK[100][100], char NgayTraTT[100][100]);
int ViTriSachMuon(int MuonSoSach[100], int ScanMaDG);
void PhieuMuonSach(int MaDocGia, char HoVaTen[100], int MaSach, char TenSach[100], char NgayMuon[100], char NgayTraDK[100]);
#pragma endregion

//Luu tru cac ham cho chuc nang 4: Lap phieu tra sach
#pragma region Function 4: Lap phieu tra sach
void Func4(char CurrentDate[10], int SoDocGia, int MaDocGia[100], char HoVaTen[100][100], int TongSoSachMuon, int MuonSoSach[100], int DS_MaSach[100], int ListSach, int MaSach[100], char TenSach[100][100], int SoSach[100], char GiaSach[100][100], char NgayMuon[100][100], char NgayTraDK[100][100], char NgayTraTT[100][100]);
int KhoangCachTuNgayDauNam(int day, int month, int year, int yearMoc);
int KhoangCach2Ngay(char NgayTruoc[], char NgaySau[]);
char* TienString(int TienInt);
int TienInt(char TienString[100]);
void PhieuTraSach(int MaDocGia, char HoVaTen[100], int MaSach, char TenSach[100], char GiaSach[100], char NgayMuon[100], char NgayTraDK[100], char NgayTraTT[100]);
#pragma endregion

//Luu tru cac ham cho chuc nang 5: Cac thong ke co ban
#pragma region Function 5: Cac thong ke co ban
void Func5_Menu(char CurrentDate[10], int SoDocGia, int MaDocGia[100], char HoVaTen[100][100], char GioiTinh[100][100], int ListSach, int MaSach[100], char TenSach[100][100], char TheLoai[100][100], int SoSach[100], int TongSoSachMuon, int MuonSoSach[100], char NgayMuon[100][100], char NgayTraTT[100][100]);
bool Func5_KiemTraChucNangMenu(char Func[]);
void Func5_NhapChucNangMenu(char Func[], char CurrentDate[10], int SoDocGia, int MaDocGia[100], char HoVaTen[100][100], char GioiTinh[100][100], int ListSach, int ISBN[100], char TenSach[100][100], char TheLoai[100][100], int SoSach[100], int TongSoSachMuon, int MuonSoSach[100], char NgayMuon[100][100], char NgayTraTT[100][100]);
#pragma region Func_5a
void Func5a(int ListSach, int SoSach[100]);
#pragma endregion
#pragma region Func_5b
void Func5b(int ListSach, char TheLoai[100][100], int SoSach[100]);
int DemSoTrung(int ListSach, char TheLoai[100][100], int SoSach[100], char XetTheLoai[], int XetViTri, int& DemSoLuongSach);
#pragma endregion
#pragma region Func_5c
void Func5c(int SoDocGia);
#pragma endregion
#pragma region Func_5d
void Func5d(int SoDocGia, char GioiTinh[100][100]);
#pragma endregion
#pragma region Func_5e
void Func5e(int TongSoSachMuon, char NgayTraTT[100][100]);
#pragma endregion
#pragma region Func_5f
void Func5f(char CurrentDate[10], int SoDocGia, int MaDocGia[100], char HoVaTen[100][100], int MuonSoSach[100], char NgayMuon[100][100], char NgayTraTT[100][100]);
bool CheckDGTreHan(int ScanMaDG, char CurrentDate[10], int MuonSoSach[100], char NgayMuon[100][100], char NgayTraTT[100][100]);
#pragma endregion
#pragma endregion