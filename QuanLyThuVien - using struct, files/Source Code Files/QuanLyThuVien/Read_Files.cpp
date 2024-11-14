#include <iostream>
#include "lib.h"

using namespace std;

//Ham doc du lieu Doc Gia tu File 
void read_DocGia(FILE* f, int& SoDocGia, strDocGia DocGia[100])
{
	fscanf_s(f, "%d\n\n", &SoDocGia);
	for (int i = 1; i <= SoDocGia; i++)
	{
		fscanf_s(f, "%d\n", &DocGia[i].Ma);
		fscanf_s(f, "%[^\n]\n", DocGia[i].HoVaTen, sizeof(DocGia[i].HoVaTen));
		fscanf_s(f, "%[^\n]\n", DocGia[i].CCCD, sizeof(DocGia[i].CCCD));
		fscanf_s(f, "%[^\n]\n", DocGia[i].NgaySinh, sizeof(DocGia[i].NgaySinh));
		fscanf_s(f, "%[^\n]\n", DocGia[i].GioiTinh, sizeof(DocGia[i].GioiTinh));
		fscanf_s(f, "%[^\n]\n", DocGia[i].Email, sizeof(DocGia[i].Email));
		fscanf_s(f, "%[^\n]\n", DocGia[i].DiaChi, sizeof(DocGia[i].DiaChi));
		fscanf_s(f, "%[^\n]\n", DocGia[i].NgayLapThe, sizeof(DocGia[i].NgayLapThe));
		fscanf_s(f, "%[^\n]\n\n", DocGia[i].NgayHetHanThe, sizeof(DocGia[i].NgayHetHanThe));
	}
}

//Ham doc du lieu Sach tu File
void read_Sach(FILE* f, int& ListSach, strSach Sach[100])
{
	fscanf_s(f, "%d\n\n", &ListSach);
	for (int i = 1; i <= ListSach; i++)
	{
		fscanf_s(f, "%d\n", &Sach[i].Ma);
		fscanf_s(f, "%[^\n]\n", Sach[i].Ten, sizeof(Sach[i].Ten));
		fscanf_s(f, "%[^\n]\n", Sach[i].TacGia, sizeof(Sach[i].TacGia));
		fscanf_s(f, "%[^\n]\n", Sach[i].NhaXB, sizeof(Sach[i].NhaXB));
		fscanf_s(f, "%d\n", &Sach[i].NamXB);
		fscanf_s(f, "%[^\n]\n", Sach[i].TheLoai, sizeof(Sach[i].TheLoai));
		fscanf_s(f, "%[^\n]\n", Sach[i].Gia, sizeof(Sach[i].Gia));
		fscanf_s(f, "%d\n\n", &Sach[i].SoLuong);
	}
}

//Ham doc du lieu Muon - Tra sach tu File
void read_MuonTra(FILE* f, int& TongSoSachMuon, int MuonSoSach[100], strMuonTra MuonTra[100])
{
	fscanf_s(f, "%d\n", &TongSoSachMuon);
	for (int i = 1; i <= 99; i++)
	{
		fscanf_s(f, "%d", &MuonSoSach[i]);
	}
	fscanf_s(f, "\n\n");
	for (int i = 1; i <= TongSoSachMuon; i++)
	{
		fscanf_s(f, "%d\n", &MuonTra[i].Ma);
		fscanf_s(f, "%[^\n]\n", MuonTra[i].NgayMuon, sizeof(MuonTra[i].NgayMuon));
		fscanf_s(f, "%[^\n]\n", MuonTra[i].NgayTraDK, sizeof(MuonTra[i].NgayTraDK));
		fscanf_s(f, "%[^\n]\n\n", MuonTra[i].NgayTraTT, sizeof(MuonTra[i].NgayTraTT));
	}
}

//Ham doc du lieu Tai Khoan dang nhap tu File
void read_TaiKhoan(FILE* f, int& SoTaiKhoan, strTaiKhoan TaiKhoan[100])
{
	fscanf_s(f, "%d", &SoTaiKhoan);
	for (int i = 1; i <= SoTaiKhoan; i++)
	{
		fscanf_s(f, "\n\n");
		fscanf_s(f, "%[^\n]\n", TaiKhoan[i].Username, sizeof(TaiKhoan[i].Username));
		fscanf_s(f, "%[^\n]\n", TaiKhoan[i].Password, sizeof(TaiKhoan[i].Password));
		fscanf_s(f, "%[^\n]", TaiKhoan[i].Email, sizeof(TaiKhoan[i].Email));
	}
}