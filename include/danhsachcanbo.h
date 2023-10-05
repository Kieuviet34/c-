#ifndef DANHSACHCANBO_H
#define DANHSACHCANBO_H

#include <string>
#include <vector>
using namespace std;
class CanBo{
    public:
        int ma_cb;
        string ho_ten,phong_ban, chuc_vu;
        double he_so_luong;
        void inThongTin() const;
        CanBo(int ma, const string& hoten,const string& pb,const string& cv, double he_so_luong);
};
class danh_sach_can_bo{
    public:
        danh_sach_can_bo();

        void themCanbo(int ma, string&hoten, string&phongban, string&chucvu, double hsl);
        void readfile(const string&file_name); //đọc từ dataset
        void writefile(const string&file_name) const; //ghi ra file 
        void timTheoChucVu(const string&chuc_vu) const; //search theo chức vụ  
        void timTheoHSL_PB(double hsl, const string& pb) const; //search theo hệ số lương và phòng ban
        void name_sorted(); //sort theo tên (alphabet order)
        void inHSLDistinct() const ;//tìm theo hệ số lương

    private:
        vector<CanBo> danh_sach;
};
#endif // DANHSACHCANBO_H