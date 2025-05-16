#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <stdlib.h>

using namespace std;

//Class độc giả
class DocGia{
    protected:
        string maDocGia;
        string Hovaten;
        string ngaysinh;
        string gioitinh;
        string diachi;
        string soDienthoai;
    public:
        void dangkyThe(string maDocGia, string Hovaten, string ngaysinh, string gioitinh, string diachi, string soDienthoai){
            fstream danhsachThe;
            danhsachThe.open("danhsachDocGia.txt", ios::out | ios::app);
            if (danhsachThe.is_open()){
                cout << "Nhap ma doc gia: " << endl;
                getline(cin, maDocGia);
                cout << "Nhap ho va ten doc gia: " << endl;
                getline(cin, Hovaten);
                cout << "Nhap ngay sinh cua doc gia: " << endl;
                getline(cin, ngaysinh);
                cout << "Nhap gioi tinh cua doc gia: " << endl;
                getline(cin, gioitinh);
                cout << "Nhap dia chi cua doc gia: " << endl;
                getline(cin, diachi);
                cout << "Nhap so dien thoai cua doc gia: " << endl;
                getline(cin, soDienthoai);

                danhsachThe << maDocGia << ","
                            << Hovaten << ","
                            << ngaysinh << ","
                            << gioitinh << ","
                            << diachi << ","
                            << soDienthoai << endl;
                
                danhsachThe.close();
                cout << "Thong tin the doc gia da duoc luu." << endl;
            } else {
                cout << "Khong the them the" << endl;
            }
        }

        void xoaThe(string maDocGia){
            fstream danhsachThe;
            danhsachThe.open("danhsachDocGia.txt", ios::in);
            if (danhsachThe.is_open()){
                vector<DocGia> dsDocGia;
                string line;
                while (getline(danhsachThe, line)){
                    DocGia docgia;
                    stringstream ss(line);
                    getline(ss, docgia.maDocGia, ',');
                    getline(ss, docgia.Hovaten, ',');
                    getline(ss, docgia.ngaysinh, ',');
                    getline(ss, docgia.gioitinh, ',');
                    getline(ss, docgia.diachi, ',');
                    getline(ss, docgia.soDienthoai, ',');
                    dsDocGia.push_back(docgia);
                }
                danhsachThe.close();

                ofstream outFile("danhsachDocGia.txt", ios::trunc);
                for (DocGia& dg : dsDocGia){
                    if (dg.maDocGia != maDocGia){
                        outFile << dg.maDocGia << ","
                                << dg.Hovaten << ","
                                << dg.ngaysinh << ","
                                << dg.gioitinh << ","
                                << dg.diachi << ","
                                << dg.soDienthoai << endl;
                    }
                }
            } else {
                cout << "Khong the xoa the" << endl;
            }
        }

};

//Class sách
class Sach{
    protected:
        string maSach;
        string tenSach;
        string tacGia;
        string theLoai;
        int soLuong;
    public:
        void themSach(string maSach, string tenSach, string tacGia, string theLoai, int soLuong){
            fstream sach;
            sach.open("thongtinSach.txt", ios::out | ios::app);
            if (sach.is_open()){
                cout << "Nhap ma sach: " << endl;
                getline(cin, maSach);
                cout << "Nhap ten sach: " << endl;
                getline(cin, tenSach);
                cout << "Nhap tac gia: " << endl;
                getline(cin, tacGia);
                cout << "Nhap the loai: " << endl;
                getline(cin, theLoai);
                cout << "Nhap so luong: " << endl;
                cin >> soLuong;

                sach << maSach << ","
                     << tenSach << "," 
                     << tacGia << ","
                     << theLoai << "," 
                     << soLuong << endl;

                sach.close();
                cout << "Thong tin sach moi da duoc luu!" << endl;
            } else {
                cout << "Khong the them sach" << endl;
            }
        }

        void xoaSach(string maSach){
            fstream sach;
            sach.open("thongtinSach.txt", ios::in);
            if (sach.is_open()){
                vector<Sach> dsSach;
                string line;
                while (getline(sach, line)){
                    Sach sach;
                    stringstream ss(line);
                    getline(ss, sach.maSach, ',');
                    getline(ss, sach.tenSach, ',');
                    getline(ss, sach.tacGia, ',');
                    getline(ss, sach.theLoai, ',');
                    ss >> sach.soLuong;
                    dsSach.push_back(sach);
                }
                sach.close();

                ofstream outFile("thongtinSach.txt", ios::trunc);
                for (Sach& s : dsSach){
                    if (s.maSach != maSach){
                        outFile << s.maSach << ","
                                << s.tenSach << ","
                                << s.tacGia << ","
                                << s.theLoai << ","
                                << s.soLuong << endl;
                    }
                }
                cout << "Da xoa sach thanh cong!" << endl;
            } else {
                cout << "Khong the xoa sach" << endl;
            }
        }

        void timSach(string maSach){
            fstream sach;
            sach.open("thongtinSach.txt", ios::in);
            string line;
                while (getline(sach, line)){
                    Sach sach;
                    stringstream ss(line);
                    getline(ss, sach.maSach, ',');
                    getline(ss, sach.tenSach, ',');
                    getline(ss, sach.tacGia, ',');
                    getline(ss, sach.theLoai, ',');
                    ss >> sach.soLuong;

                    if (sach.maSach == maSach){
                        cout << "Thong tin sach: " << endl;
                        cout << "Ma sach: " << sach.maSach << endl;
                        cout << "Ten sach: " << sach.tenSach << endl;
                        cout << "Tac gia: " << sach.tacGia << endl;
                        cout << "The loai: " << sach.theLoai << endl;
                        cout << "So luong: " << sach.soLuong << endl;
                    }
                }
            sach.close();
        }

        void hienthidanhsachSach(){
            fstream sach;
            sach.open("thongtinSach.txt", ios::in);
            string line;
            cout << "Danh sach sach: " << endl;
                while (getline(sach, line)){
                    Sach sach;
                    stringstream ss(line);
                    getline(ss, sach.maSach, ',');
                    getline(ss, sach.tenSach, ',');
                    getline(ss, sach.tacGia, ',');
                    getline(ss, sach.theLoai, ',');
                    ss >> sach.soLuong;

                    cout << "Ma sach: " << sach.maSach << endl;
                    cout << "Ten sach: " << sach.tenSach << endl;
                    cout << "Tac gia: " << sach.tacGia << endl;
                    cout << "The loai: " << sach.theLoai << endl;
                    cout << "So luong: " << sach.soLuong << endl;
                }
            sach.close();
        }

        void suathongtinSach(string maSach){
            vector<Sach> library;
            fstream sach;
            string line;

            sach.open("thongtinSach.txt", ios::in);
            while (getline(sach, line)){
                    Sach sach;
                    stringstream ss(line);
                    getline(ss, sach.maSach, ',');
                    getline(ss, sach.tenSach, ',');
                    getline(ss, sach.tacGia, ',');
                    getline(ss, sach.theLoai, ',');
                    ss >> sach.soLuong;
                    library.push_back(sach);
            }
            sach.close();

            int chiso = -1;         // gan chi so bang -1 vi khong ton tai ma sach -1
            int n = library.size(); // so thong tin sach trong thu vien
            for (int i = 0; i <= n - 1; i++){
                if (library[i].maSach == maSach){
                    chiso = i;
                    break;
                }
            }
            if (chiso == -1){
                cout << "Khong tim thay sach co ma " << maSach << endl;
            return;
            }

            cout <<"THONG TIN SACH TIM THAY LA:" << endl;
            cout << "Thong tin sach hien tai:" << endl;
            cout << "Ma sach: " << library[chiso].maSach << endl;
            cout << "Ten sach: " << library[chiso].tenSach << endl;
            cout << "Tac gia: " << library[chiso].tacGia << endl;
            cout << "The loai: " << library[chiso].theLoai << endl;
            cout << "So luong: " << library[chiso].soLuong << endl;

            cout << "NHAP THONG TIN BAN CAN MUON SUA: " << endl;
            cout << "Neu khong muon sua doi thong tin thi hay nhap lai thong tin cu!" << endl;
            cout << "Nhap ma sach moi: ";
            getline(cin, library[chiso].maSach);
            cout << "Nhap ten sach moi: ";
            getline(cin, library[chiso].tenSach);
            cout << "Nhap tac gia moi: ";
            getline(cin, library[chiso].tacGia);
            cout << "Nhap the loai moi: ";
            getline(cin, library[chiso].theLoai);
            cout << "Nhap so luong moi: ";
            cin >> library[chiso].soLuong;
            cin.ignore();
            
            ofstream outFile("thongtinSach.txt", ios::out | ios::trunc);
            for (int i = 0; i <= n - 1; i++){
                outFile << library[i].maSach << ","
                        << library[i].tenSach << ","
                        << library[i].tacGia << ","
                        << library[i].theLoai << ","
                        << library[i].soLuong << endl;
            }
            sach.close();
        }

};

int main(){
    DocGia docgia;
    Sach sach;
    int luaChon;
    string maDocGia, Hovaten, ngaysinh, gioitinh, diachi, soDienthoai;
    string maSach, tenSach, tacGia, theLoai;
    int soLuong;

    do {
        system("cls"); // Xóa màn hình
        cout << "XIN CHAO BAN DEN VOI THU VIEN DA NANG!" << endl;
        cout << "HAY CHON CHUC NANG MUON THUC HIEN:" << endl;
        cout << "1. Quan ly doc gia" << endl;
        cout << "2. Quan ly sach" << endl;
        cout << "0. Thoat chuong trinh" << endl;
        cout << "============================================" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> luaChon;

        switch (luaChon) {
            case 1: {
                int luaChonDG;
                do {
                    system("cls");
                    cout << "=======QUAN LY DOC GIA=======" << endl;
                    cout << "1. Dang ky the doc gia" << endl;
                    cout << "2. Xoa the doc gia" << endl;
                    cout << "0. Quay lai menu chinh" << endl;
                    cout << "=============================" << endl;
                    cout << "Nhap lua chon cua ban: ";
                    cin >> luaChonDG;

                    switch (luaChonDG) {
                        case 1:
                            docgia.dangkyThe(maDocGia, Hovaten, ngaysinh, gioitinh, diachi, soDienthoai);
                            cout << "Nhan Enter de tiep tuc...";
                            cin.get();
                            break;
                        case 2:
                            cout << "Nhap ma doc gia can xoa: ";
                            getline(cin, maDocGia);
                            docgia.xoaThe(maDocGia);
                            cout << "Da xoa the doc gia co ma " << maDocGia << endl;
                            cout << "Nhan Enter de tiep tuc...";
                            cin.get();
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Lua chon khong hop le. Vui long thu lai!" << endl;
                            cout << "Nhan Enter de tiep tuc...";
                            cin.get();
                    }
                } while (luaChonDG != 0);
                break;
            }
            case 2: {
                int luaChonSach;
                do {
                    system("cls");
                    cout << "========QUAN LY SACH========" << endl;
                    cout << "1. Them sach moi" << endl;
                    cout << "2. Xoa sach" << endl;
                    cout << "3. Tim kiem sach" << endl;
                    cout << "4. Hien thi danh sach sach" << endl;
                    cout << "5. Sua thong tin sach" << endl;
                    cout << "0. Quay lai menu chinh" << endl;
                    cout << "============================" << endl;
                    cout << "Nhap lua chon cua ban: ";
                    cin >> luaChonSach;
                    cin.ignore();

                    switch (luaChonSach) {
                        case 1:
                            sach.themSach(maSach, tenSach, tacGia, theLoai, soLuong);
                            cout << "Nhan Enter de tiep tuc...";
                            cin.get();
                            break;
                        case 2:
                            cout << "Nhap ma sach can xoa: ";
                            getline(cin, maSach);
                            sach.xoaSach(maSach); // Xóa sách theo mã
                            cout << "Nhan Enter de tiep tuc...";
                            cin.get();
                            break;
                        case 3:
                            cout << "Nhap ma sach can tim: ";
                            getline(cin, maSach);
                            sach.timSach(maSach);
                            cout << "Nhan Enter de tiep tuc...";
                            cin.get();
                            break;
                        case 4:
                            sach.hienthidanhsachSach();
                            cout << "Nhan Enter de tiep tuc...";
                            cin.get();
                            break;
                        case 5:
                            cout << "Nhap ma sach can sua: ";
                            getline(cin, maSach);
                            sach.suathongtinSach(maSach);
                            cout << "Da sua thong tin sach co ma " << maSach << endl;
                            cout << "Nhan Enter de tiep tuc...";
                            cin.get();
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Lua chon khong hop le. Vui long thu lai!" << endl;
                            cout << "Nhan Enter de tiep tuc...";
                            cin.get();
                    }
                } while (luaChonSach != 0);
                break;
            }
            case 0:
                cout << "Cam on ban da su dung chuong trinh!" << endl;
                break;
            default:
                cout << "Lua chon khong hop le. Vui long thu lai!" << endl;
                cout << "Nhan Enter de tiep tuc...";
                cin.get();
        }
    } while (luaChon != 0);

    return 0;
}

