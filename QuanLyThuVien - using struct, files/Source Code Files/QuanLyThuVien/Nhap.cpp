//SoDocGia, MaDocGia, HoVaTen, CCCD, NgaySinh, GioiTinh, Email, DiaChi, NgayLapThe, NgayHetHanThe
//ListSach, MaSach, TenSach, TacGia, NhaXB, NamXB, TheLoai, GiaSach, SoSach


//Giao dien Menu rut gon
/*

========================================================= (57)
| QUAN LI THU VIEN                     Date: xx/xx/xxxx |
========================================================= (57)
Cac chuc nang cua chuong trinh:
1. Quan li doc gia
2. Quan li sach
3. Lap phieu mua sach
4. Lap phieu tra sach
5. Cac thong ke co ban
6. Xem menu chi tiet
0. Thoat chuong trinh

Vui long nhap chuc nang (VD: 1):   

*/

//Giao dien Menu chi tiet
/*

========================================================= (57)
| QUAN LI THU VIEN                     Date: xx/xx/xxxx |
========================================================= (57)
Cac chuc nang cua chuong trinh:
1. Quan li doc gia
    1a. Xem danh sach doc gia trong thu vien
	1b. Them doc gia 
	1c. Chinh sua thong tin mot doc gia
	1d. Xoa thong tin mot doc gia
	1e. Tim kiem doc gia theo CCCD
	1f. Tim kiem sach theo ho ten
2. Quan li sach
	2a. Xem danh sach cac sach trong thu vien
	2b. Them sach
	2c. Chinh sua thong tin mot quyen sach
	2d. Xoa thong tin sach
	2e. Tim kiem sach theo ISBN
	2f. Tim kiem sach theo ten sach
3. Lap phieu mua sach
4. Lap phieu tra sach
5. Cac thong ke co ban
	5a. Thong ke so luong sach trong thu vien (ListSach, ISBN, TenSach, SoSach)
	5b. Thong ke so luong sach theo the loai (ListSach, TheLoai, SoSach)
	5c. Thong ke so luong doc gia (SoDocGia)
	5d. Thong ke so luong doc gia theo gioi tinh (SoDocGia, GioiTinh)
	5e. Thong ke so sach dang duoc muon (SoSachMuon, NgayTraTT)
	5f. Thong ke danh sach doc gia bi tre han (CurrentDate, SoDocGia, MaDocGia, HoVaTen, MuonSoSach, NgayMuon, NgayTraTT)
6. Xem menu rut gon
0. Thoat chuong trinh

//SoDocGia, MaDocGia, HoVaTen, GioiTinh, ListSach, ISBN, TenSach, TheLoai, SoSach, MuonSoSach, NgayMuon, NgayTraTT
Vui long nhap chuc nang (VD: 1, 1a):

*/



#pragma region Function1 - Quan Li Doc Gia
//Giao dien 1a - Xem danh sach Doc Gia
/*


-----------------------------------------------------------------------------DANH SACH DOC GIA---------------------------------------------------------------------------- [77 - 77]

STT  Ma    Ho va ten                   Gioi tinh  Ngay sinh   CCCD          Email                         Dia chi                              Ngay lap the   Ngay het han
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
1    xxxx  Doan Pham Minh Triet        Nam/Nu     xx/xx/xxxx  123456789012  huynhgiaau27112005@gmail.com  109/24/28 Duong Ba Trac, Q8, TPHCM   xx/xx/xxxx     xx/xx/xxxx
           Nguyen Nguyen Quynh Nhu
		   Huynh Duong Ngoc Huy
		   Huynh Duong Ngoc Chuong

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------


setw(...):
5 - NumberLength              -> Ma
2							  -> Ho va ten
28 - <string>.length()		  -> Gioi tinh
11 - <string>.length()		  -> Ngay sinh
2							  -> CCCD
2							  -> Email
30 - <string>.length()		  -> Dia chi
37 - <string>.lenth()		  -> Ngay lap the
5							  -> Ngay het han
*/

//Giao dien 1b - Them doc gia
/*

---------------------THEM DOC GIA---------------------- [22-12-22]
Ma doc gia: xxxx
------------------------------------------------------- [56]
                   Thong tin ca nhan [setw(36)]
- Ho va ten:
- Gioi tinh (Nam/Nu):
- Ngay sinh (ddmmyyyy):
- CCCD (12 so):
- Email:
- Dia chi: [35 kt]
------------------------------------------------------
                   Thong tin the [21-...]
- Ngay lap the (ddmmyyyy):
       > Ngay het han the: 
------------------------------------------------------
Them doc gia thanh cong!
------------------------------------------------------
1. Them mot doc gia khac
2. Xem danh sach doc gia
0. Thoat chuc nang
> Chon mot chuc nang (VD: 1): 

*/

//Giao dien 1c - Chinh sua thong tin mot doc gia
/*
--------------CHINH SUA THONG TIN MOT DOC GIA-------------- [14-...-14]
Nhap ma doc gia: 
----------------------------------------------------------- [60]
				   Thong tin ca nhan [setw(36)]
- Ho va ten:
- Gioi tinh (Nam/Nu):
- Ngay sinh (ddmmyyyy):
- CCCD (12 so):
- Email:
- Dia chi: [35 kt]
-----------------------------------------------------------
				   Thong tin the [21-...]
- Ngay lap the (ddmmyyyy):
		 > Ngay het han the:
-----------------------------------------------------------
Chinh sua doc gia thanh cong!
-----------------------------------------------------------
1. Chinh sua mot doc gia khac
2. Xem danh sach doc gia
0. Thoat chuc nang
> Chon mot chuc nang (VD: 1):


*/

//Giao dien 1d - Xoa thong tin mot doc gia
/*
-----------------XOA THONG TIN MOT DOC GIA----------------- [14-...-14]
Nhap ma doc gia:
> Xac nhan xoa [Y/N]: 
----------------------------------------------------------- [60]
Xoa doc gia thanh cong!
-----------------------------------------------------------
1. Chinh sua mot doc gia khac
2. Xem danh sach doc gia
0. Thoat chuc nang
> Chon mot chuc nang (VD: 1):
*/

//Giao dien 1d(advanced) - Xoa thong tin mot doc gia
/*




*/

//Giao dien 1e - Tim kiem doc gia theo CCCD
/*
TRUOC TIM KIEM
-----------------------------------------------------------------------------TIM KIEM DOC GIA----------------------------------------------------------------------------- [77 - 77]

STT  Ma    Ho va ten                   Gioi tinh  Ngay sinh   CCCD          Email                         Dia chi                              Ngay lap the   Ngay het han
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
1    xxxx  Doan Pham Minh Triet        Nam/Nu     xx/xx/xxxx  123456789012  huynhgiaau27112005@gmail.com  109/24/28 Duong Ba Trac, Q8, TPHCM   xx/xx/xxxx     xx/xx/xxxx
2    xxxx  Doan Pham Minh Triet        Nam/Nu     xx/xx/xxxx  123456789012  huynhgiaau27112005@gmail.com  109/24/28 Duong Ba Trac, Q8, TPHCM   xx/xx/xxxx     xx/xx/xxxx
3    xxxx  Doan Pham Minh Triet        Nam/Nu     xx/xx/xxxx  123456789012  huynhgiaau27112005@gmail.com  109/24/28 Duong Ba Trac, Q8, TPHCM   xx/xx/xxxx     xx/xx/xxxx
4    xxxx  Doan Pham Minh Triet        Nam/Nu     xx/xx/xxxx  123456789012  huynhgiaau27112005@gmail.com  109/24/28 Duong Ba Trac, Q8, TPHCM   xx/xx/xxxx     xx/xx/xxxx
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Nhap so CCCD cua doc gia can tim: xxxxxxxxxxxx


SAU TIM KIEM
-----------------------------------------------------------------------------TIM KIEM DOC GIA----------------------------------------------------------------------------- [77 - 77]

STT  Ma    Ho va ten                   Gioi tinh  Ngay sinh   CCCD          Email                         Dia chi                              Ngay lap the   Ngay het han
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                                            <Khong co du lieu>
1    xxxx  Doan Pham Minh Triet        Nam/Nu     xx/xx/xxxx  123456789012  huynhgiaau27112005@gmail.com  109/24/28 Duong Ba Trac, Q8, TPHCM   xx/xx/xxxx     xx/xx/xxxx                                                                        
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Nhap so CCCD cua doc gia can tim: xxxxxxxxxxxx

1. Tim mot doc gia khac
2. Xem danh sach doc gia
0. Thoat chuc nang
> Chon chuc nang (VD: 1):


*/
#pragma endregion

#pragma region Function2 - Quan Li Sach
//Giao dien 2a - Xem danh sach cac sach trong thu vien
/*

-----------------------------------------------------DANH SACH CAC SACH TRONG THU VIEN----------------------------------------------------- [53-...-53]

STT  ISBN   Ten sach                        Tac gia               Nha xuat ban            Nam XB   The loai       Gia sach   So luong
-------------------------------------------------------------------------------------------------------------------------------------------
 1   70297  Sans Famille                    Hector Malot          Nha Xuat ban Van hoc    1878     Tieu thuyet    500.000       20
 2   60780  Harry Potter va Hoang tu lai    J. K. Rowling         Bloomsbury Publishing   2005     Ky ao          399.999       17
 3   51935  The Universe in a Nutshell      Stephen Hawking       Bantam Spectra          2001     Khoa hoc       630.000       21
		   

*/

//Giao dien 2b - Them sach
/*

-----------------------THEM SACH----------------------- [23-12-23]
Nhap ma sach (5 so): xxxxx
------------------------------------------------------- [56]
				    Thong tin sach [setw(35)]
- Ten sach:
- Tac gia:
- Nha xuat ban:
- Nam xuat ban:
- The loai:
------------------------------------------------------
				    Thong tin ban [22-...]
- Gia sach:
- So luong:
------------------------------------------------------
Them doc gia thanh cong!
------------------------------------------------------
1. Them mot doc gia khac
2. Xem danh sach doc gia
0. Thoat chuc nang
> Chon mot chuc nang (VD: 1):



*/

//Giao dien 2c - Chinh sua thong tin cua sach
/*

---------------CHINH SUA THONG TIN SACH---------------- [15-...-16]
Nhap ma sach (5 so): xxxxx
------------------------------------------------------- [56]
					Thong tin sach [setw(35)]
- Ten sach:
- Tac gia:
- Nha xuat ban:
- Nam xuat ban:
- The loai:
------------------------------------------------------
					Thong tin ban [22-...]
- Gia sach:
- So luong:
------------------------------------------------------
Them doc gia thanh cong!
------------------------------------------------------
1. Them mot doc gia khac
2. Xem danh sach doc gia
0. Thoat chuc nang
> Chon mot chuc nang (VD: 1):

*/

//Giao dien 1d - Xoa thong tin mot doc gia
/*
--------------------XOA THONG TIN SACH--------------------- [19-...-20]
Nhap ma doc gia:
> Xac nhan xoa [Y/N]:
----------------------------------------------------------- [60]
Xoa doc gia thanh cong!
-----------------------------------------------------------
1. Chinh sua mot doc gia khac
2. Xem danh sach doc gia
0. Thoat chuc nang
> Chon mot chuc nang (VD: 1):
*/

//Giao dien 1e - Tim kiem sach bang ISBN
/*

-------------------------------------------------------TIM KIEM SACH TRONG THU VIEN-------------------------------------------------------- [55-...-56]

STT  ISBN   Ten sach                        Tac gia               Nha xuat ban            Nam XB   The loai       Gia sach   So luong
-------------------------------------------------------------------------------------------------------------------------------------------
                                                             <khong co du lieu>
 1   70297  Sans Famille                    Hector Malot          Nha Xuat ban Van hoc    1878     Tieu thuyet    500.000       20
 2   60780  Harry Potter va Hoang tu lai    J. K. Rowling         Bloomsbury Publishing   2005     Ky ao          399.999       17
 3   51935  The Universe in a Nutshell      Stephen Hawking       Bantam Spectra          2001     Khoa hoc       630.000       21
 ------------------------------------------------------------------------------------------------------------------------------------------
 
*/
#pragma endregion

#pragma region Function3 - Lap phieu muon sach
//Ma doc gia
//Ngay muon
//Ngay tra du kien
//Ngay tra thuc te
//Danh sach ISBN
//Bo sung: ten sach

//Function 3 - Giao dien chinh 
/*


-------------------------------------------------------------------------------------------------------------------------------- [128]

                                        DANH SACH THONG KE MUON/TRA SACH TRONG THU VIEN
									                   Date: xx/xx/xxxx

----DOC GIA----------------------------SACH--------------------------------------------------MUON/TRA--------------------------- [4-28-50-27]
Ma    Ho va ten                    Ma      Ten sach                          Ngay muon    Ngay tra du kien    Ngay tra thuc te
--------------------------------------------------------------------------------------------------------------------------------
xxxx  Nguyen Nguyen Quynh Nhu      12345   Harry Potter va Hoang tu lai      xx/xx/xxxx       xx/xx/xxxx         xx/xx/xxxx
                                   45678   The Universe in a Nutshell        xx/xx/xxxx       xx/xx/xxxx         xx/xx/xxxx
xxxx  Huynh Gia Au                 xxxxx   Chiec la cuoi cung                xx/xx/xxxx       xx/xx/xxxx          chua tra
										   <du lieu da bi xoa>                                                   <mat sach>
--------------------------------------------------------------------------------------------------------------------------------
Lap phieu muon sach:
- Ma doc gia: xxxx (Huynh Gia Au)
- Ma sach can muon: xxxxx (Harry Potter va Hoang tu lai)
- Ngay muon (ddmmyyyy): xx/xx/xxxx
- Ngay tra du kien (ddmmyyyy): xx/xx/xxxx
--------------------------------------------------------------------------------------------------------------------------------
Lap phieu thanh cong!
1. Lap mot phieu muon sach khac
0. Thoat chuc nang
> Chon chuc nang:



//Phieu muon sach
****************************************************
                PHIEU MUON SACH
****************************************************
                    DOC GIA
Ma: xxxx
Ho va ten: Huynh Gia Au

                   SACH MUON
Ma: xxxxx
Ten sach: Harry Potter va Hoang tu lai
                   
		       NGAY MUON/TRA SACH
Ngay muon:   xx/xx/xxxx
Ngay tra DK: xx/xx/xxxx
****************************************************
*/
#pragma endregion

#pragma region Function4 - Lap phieu tra sach
/*
//Giao dien chinh cua Function 4 - Lap phieu tra sach

Nhap ma doc gia: 

Danh sach nhung sach chua tra cua doc gia [Ma doc gia] - [Ho ten doc gia]:
------------------------------------------------------------------------------- [79]
Code  Ma sach   Ten Sach                         Ngay muon    Ngay tra du kien
-------------------------------------------------------------------------------
 2.   xxxxx     Harry Potter va Hoang tu lai     xx/xx/xxxx      xx/xx/xxxx    
 3.   xxxxx     The Universe in a Nutshell       xx/xx/xxxx      xx/xx/xxxx
                           <khong co sach dang muon>
-------------------------------------------------------------------------------
Nhap ma code (VD: 2): 
a. Nhap ngay tra sach
b. Doc gia lam mat sach
> Chon hinh thuc nhap (VD: a): a


Nhap ma code (VD: 2):
- Nhap ngay tra sach (ddmmyyyy):


TINH HINH TRA SACH:
- Sach duoc tra dung han
-------------------------------------------------------------------------------
Lap phieu tra sach thanh cong! Chon 1 de xem danh sach muon/tra sach: 1




- Tre han n ngay -> Nop phat: xxx.xxx VND

- Doc gia lam mat sach -> Nop phat: xxx.xxx VND
-------------------------------------------------------------------------------


//Phieu tra sach
****************************************************
				PHIEU TRA SACH
****************************************************
					DOC GIA
Ma: xxxx
Ho va ten: Huynh Gia Au

				     SACH
Ma: xxxxx
Ten sach: Harry Potter va Hoang tu lai

			   NGAY MUON/TRA SACH
Ngay muon:   xx/xx/xxxx
Ngay tra DK: xx/xx/xxxx
Ngay tra TT: xx/xx/xxxx

- Doc gia tra sach dung han
- Doc gia tra sach tre han ... ngay
-> Nop phat: ...
- Doc gia lam mat sach
-> Nop phat: ...
****************************************************

*/
#pragma endregion

#pragma region Function5 - Thong ke co ban
//Giao dien chinh (Menu)
/*

========================================================= (57)
| CAC THONG KE CO BAN                  Date: xx/xx/xxxx |
========================================================= (57)
Cac chuc nang cua chuong trinh:
a. Thong ke so luong sach trong thu vien
b. Thong ke so luong sach theo the loai
c. Thong ke so luong doc gia
d. Thong ke so luong doc gia theo gioi tinh
e. Thong ke so sach dang duoc muon
f. Thong ke danh sach doc gia bi tre han
0. Thoat chuong trinh



*/

//Giao dien Func 5b
/*
The Loai             So sach     So luong sach
---------------------------------------------- (46)
Khoa hoc vien tuong    10            100
Truyen thuyet           5             25
----------------------------------------------
> Chon 0 de tro ve menu: 


*/

//Giao dien Func 5d
/*
Gioi tinh    So luong
--------------------- [21]
  Nam           14
  Nu             5
---------------------
> Chon 0 de tro ve menu: 0
*/

//Giao dien Func 5f
/*



*/
#pragma endregion