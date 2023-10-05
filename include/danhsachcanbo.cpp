#include "danhsachcanbo.h"
#include <algorithm>
#include <vector>
#include <fstream>
#include <iostream>
#include <set>
#include <unordered_map>


using namespace std;
CanBo::CanBo(int ma, const string &ten, const string& phongban,
        const string&chucvu, double hsl): ma_cb(ma), phong_ban(phongban), chuc_vu(chuc_vu), he_so_luong(hsl){}
void CanBo::inThongTin() const {
    cout << "Ma can bo: " << ma_cb << endl;
    cout << "ho ten can bo: " << ho_ten << endl;
    cout << "phong ban can bo: " << phong_ban << endl;
    cout << "chuc vu can bo: " << chuc_vu << endl;
    cout << "he_so_luong can bo: " << he_so_luong << endl << endl;
}
danh_sach_can_bo::danh_sach_can_bo(){}

void danh_sach_can_bo::themCanbo(int ma_Cb,string&hotendem,string&pb, string&cv,double hsl){
    CanBo cb(ma_Cb, hotendem, pb,cv,hsl);
    danh_sach.push_back(cb);
}

void danh_sach_can_bo::readfile(const string &filename){
    ifstream file(filename);
    if (!file){
        cerr << "Can't open file " << endl;
        return;
    }
    danh_sach.clear();
    int ma_cb;
    string hoten, pb,cv;
    double hsl;

    while(file>> ma_cb){
        file.ignore();
        getline(file,hoten);
        getline(file,pb);
        getline(file,cv);
        file >> hsl;
        CanBo cb(ma_cb,hoten,pb,cv,hsl);
        danh_sach.push_back(cb);
    }
    file.close();
}

void danh_sach_can_bo::writefile(const string&filename) const {
    ofstream file(filename);
    if (!file){
        cerr << "cant open file " << endl;
        return;
    }
    for (const CanBo&cb: danh_sach){
        file << cb.ma_cb << endl;
        file << cb.ho_ten << endl;
        file << cb.phong_ban << endl;
        file << cb.chuc_vu << endl;
        file << cb.he_so_luong << endl;
    }
    file.close();
}
//linear search
void danh_sach_can_bo::timTheoChucVu(const string& chuc_vu) const{
    for (const CanBo&cb : danh_sach){
        if (cb.chuc_vu == chuc_vu){
            cb.inThongTin();
        }
    }
}
//using unordered map in c++ (hash map)
void danh_sach_can_bo::timTheoHSL_PB(double hsl, const string& pb) const{
    unordered_map<double, vector<CanBo>> hsl_map;
    for (const CanBo&cb : danh_sach){
        hsl_map[cb.he_so_luong].push_back(cb);
    }
    if (hsl_map.find(hsl) != hsl_map.end()){
        const vector<CanBo> can_bo_theo_hsl = hsl_map[hsl];
        for (const CanBo&cb : can_bo_theo_hsl){
            if (cb.phong_ban == pb){
                cb.inThongTin();
            }
        }
    }
}

//radix sort algorithm
void CountingSort(vector<CanBo>& arr, int exp) {
    const int n = arr.size();
    vector<CanBo> output(n);
    int count[256] = {0};  //đếm tần suất kí tự (lưu vào mảng count) (bảng mã ASCII 256 kí tự btw)
    //đếm tần suất của kí tự tại index i    
    for (int i = 0; i < n; i++) {
        count[arr[i].ho_ten[exp]]++;
    }
    //tính số lần lặp trong bộ đếm
    for (int i = 1; i < 256; i++) {
        count[i] += count[i - 1];
    }
    //sorting 
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i].ho_ten[exp]] - 1] = arr[i];
        count[arr[i].ho_ten[exp]]--;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}
void radix_sort(vector<CanBo>&a){
    int max_len = 0; 
    const int n = a.size();

    for (int i = 0; i < n;i++){
        max_len =  max(max_len,static_cast<int>(a[i].ho_ten.length()));
        for (int exp = max_len; exp >= 0;exp--){
            CountingSort(a,exp);
        }
    }
}
void danh_sach_can_bo::name_sorted(){
    radix_sort(danh_sach);
}
//using set (hash table)
void danh_sach_can_bo::inHSLDistinct() const{
    set<int> hsl_set;
    for (const CanBo&cb : danh_sach){
        hsl_set.insert(cb.he_so_luong);
    }
    cout << "he so luong duy nhat: " << endl;
    for (auto it : hsl_set){
        cout << it << endl;
    }
}