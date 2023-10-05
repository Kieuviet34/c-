#include <iostream>
#include "danhsachcanbo.h"

int main(){
    danh_sach_can_bo ds;
    auto filename = ("data/nhan_su.txt");
    ds.readfile(filename);

    while(true){
        int choice;
        cout << "menu quan ly nhan su: " << endl;
        cout << "1. Them can bo" << endl;
        cout << "2. Tim va in danh sach can bo theo chuc vu" << endl;
        cout << "3. TIm va in danh sach can bo theo he so luong va phong ban" << endl;
        cout << "4. Sap xep danh sach can bo theo thu tu ho ten" << endl;
        cout << "5. In ra danh sach he so luong duy nhat" << endl;
        cout << "6. Exit" << endl;
        cout << "chon chuc nang (1,2,3,4,5,6): ";
        cin >> choice;

        switch (choice)
        {
        case 1:{
            int ma_Cb;
            string hotendem, pb,cv;
            double hsl;
            cout << "nhap ma can bo (ma <= 0 ket thuc): ";
            cin >> ma_Cb;
            if (ma_Cb <= 0){
                return;
            }
            cout << "nhap ho ten can bo: " ;
            cin.ignore();
            getline(cin, hotendem);
            cout << "nhap phong ban: ";
            getline(cin,  pb);
            cout << "nhap chuc danh can bo: ";
            getline(cin, cv);
            cout << "nhap he so luong: ";
            cin >> hsl;
            ds.themCanbo(ma_Cb,hotendem,pb,cv,hsl);
            ds.writefile(filename);
            break;
        }    
        case 2:{
            string chucvu;
            cout << "nhap chuc vu can tim: ";
            cin.ignore();
            getline(cin,chucvu);
            ds.timTheoChucVu(chucvu);
            break;
        }    
        case 3: {
            double hsl;
            string pb;
            cout << "nhap he so luong: ";
            cin >> hsl;
            cout <<"nhap ten phong ban: ";
            cin.ignore();
            getline(cin,pb);
            ds.timTheoHSL_PB(hsl,pb);
            break;
        }
        case 4: {
            ds.name_sorted();
            break;
        }
        case 5:{
            ds.inHSLDistinct();
            break;
        }
        case 6:{
            return 0;
        }    
        default:{
        cout << "chuc nang khong hop le, vui long nhap lai." << endl;
            break;
          }
        }
    }
}