#include <iostream>
#include "lib.h"

using namespace std;

//Ham luu du lieu Doc Gia vao File
void save_DocGia(FILE* f, int SoDocGia, strDocGia DocGia[100])
{
	fprintf(f, "%d", SoDocGia);
	for (int i = 1; i <= SoDocGia; i++)
	{
		fprintf(f, "\n\n");
		fprintf(f, "%d\n", DocGia[i].Ma);
		fprintf(f, "%s\n", DocGia[i].HoVaTen);
		fprintf(f, "%s\n", DocGia[i].CCCD);
		fprintf(f, "%s\n", DocGia[i].NgaySinh);
		fprintf(f, "%s\n", DocGia[i].GioiTinh);
		fprintf(f, "%s\n", DocGia[i].Email);
		fprintf(f, "%s\n", DocGia[i].DiaChi);
		fprintf(f, "%s\n", DocGia[i].NgayLapThe);
		fprintf(f, "%s", DocGia[i].NgayHetHanThe);
	}
}

//Ham luu du lieu Sach vao File
void save_Sach(FILE* f, int ListSach, strSach Sach[100])
{
	fprintf(f, "%d", ListSach);
	for (int i = 1; i <= ListSach; i++)
	{
		fprintf(f, "\n\n");
		fprintf(f, "%d\n", Sach[i].Ma);
		fprintf(f, "%s\n", Sach[i].Ten);
		fprintf(f, "%s\n", Sach[i].TacGia);
		fprintf(f, "%s\n", Sach[i].NhaXB);
		fprintf(f, "%d\n", Sach[i].NamXB);
		fprintf(f, "%s\n", Sach[i].TheLoai);
		fprintf(f, "%s\n", Sach[i].Gia);
		fprintf(f, "%d", Sach[i].SoLuong);
	}
}

//Ham luu du lieu Muon - Tra sach vao File
void save_MuonTra(FILE* f, int TongSoSachMuon, int MuonSoSach[100], strMuonTra MuonTra[100])
{
	fprintf(f, "%d\n", TongSoSachMuon);
	for (int i = 1; i <= 99; i++)
	{
		fprintf(f, "%d ", MuonSoSach[i]);
	}
	for (int i = 1; i <= TongSoSachMuon; i++)
	{
		fprintf(f, "\n\n");
		fprintf(f, "%d\n", MuonTra[i].Ma);
		fprintf(f, "%s\n", MuonTra[i].NgayMuon);
		fprintf(f, "%s\n", MuonTra[i].NgayTraDK);
		fprintf(f, "%s", MuonTra[i].NgayTraTT);
	}
}

//Ham luu du lieu Tai Khoan dang nhap vao File
void save_TaiKhoan(FILE* f, int SoTaiKhoan, strTaiKhoan TaiKhoan[100])
{
	fprintf(f, "%d", SoTaiKhoan);
	for (int i = 1; i <= SoTaiKhoan; i++)
	{
		fprintf(f, "\n\n");
		fprintf(f, "%s\n", TaiKhoan[i].Username);
		fprintf(f, "%s\n", TaiKhoan[i].Password);
		fprintf(f, "%s", TaiKhoan[i].Email);
	}
}