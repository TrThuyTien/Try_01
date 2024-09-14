/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

struct NGAY {
    int Ngay, Thang, Nam;
};
struct SINHVIEN {
    string MASV;
    string HoTen;
    NGAY NgaySinh;
    char GioiTinh;
    float DiemToan, DiemLy, DiemHoa, DTB;
};
struct NODE{
    SINHVIEN key;
    NODE* pNext;
};
struct LIST{
    NODE*pHead, *pTail;
};

void NhapNgay(NGAY &);
void XuatNgay(NGAY);
void NhapSinhVien(SINHVIEN &);
void XuatSinhVien(SINHVIEN );
NODE* CreateNode(SINHVIEN );
void CreateEmptyList(LIST &);
void AddTail(LIST&, NODE* );
void XuatDS(LIST L);
void NhapDS(LIST &, int );
void Tim_SinhVien_TheoNamSinh(LIST, int);

int main() {
    LIST L;
    int n, namsinh;

    cin >> namsinh;
    cin >> n ;
    NhapDS(L, n);

    Tim_SinhVien_TheoNamSinh(L, namsinh);

    return 0;
}
void NhapNgay(NGAY &a){
    cin >> a.Ngay >> a.Thang >> a.Nam;
}
void XuatNgay(NGAY a){
    cout << a.Ngay << "/" << a.Thang << "/" << a.Nam;
}
void NhapSinhVien(SINHVIEN &a){
    cin >> ws;
    getline(cin, a.MASV);
    getline(cin, a.HoTen);
    NhapNgay(a.NgaySinh);
    cin >> a.GioiTinh;
    cin >> a.DiemToan >> a.DiemLy >> a.DiemHoa;
    a.DTB = (a.DiemToan + a.DiemLy + a.DiemHoa) / 3;
}
void XuatSinhVien(SINHVIEN a){
    cout << a.MASV;         cout << "\t";
    cout << a.HoTen;        cout << "\t";
    XuatNgay(a.NgaySinh);   cout << "\t";
    cout << a.GioiTinh;     cout << "\t";
    cout << a.DiemToan;     cout << "\t";
    cout << a.DiemLy;       cout << "\t";
    cout << a.DiemHoa;      cout << "\t";
    cout << setprecision(3);
    cout << a.DTB;
}

//###INSERT CODE HERE -

NODE* CreateNode(SINHVIEN sv) {
    NODE* p = new NODE;
    if (p == NULL) exit(1);
    p->key = sv;
    p->pNext = NULL;
    return p;
}

void CreateEmptyList(LIST &L) {
    L.pHead = NULL;
    L.pTail = NULL;
}

void AddTail(LIST& L, NODE* p) {
    if (L.pHead == NULL) {
        L.pHead = p;
        L.pTail = p;
    } else {
        L.pTail->pNext = p;
        L.pTail = p;
    }
}

void NhapDS (LIST& L, const int n) {
    CreateEmptyList(L);
    for (int i = 0; i < n; i++) {
        SINHVIEN sv;
        NhapSinhVien(sv);
        AddTail(L, CreateNode(sv));
    }
}

void Tim_SinhVien_TheoNamSinh(LIST L, int namsinh) {
    int check = false;
    NODE* curr = L.pHead;
    while (curr != NULL) {
        if (curr->key.NgaySinh.Nam == namsinh) {
            check = true;
            XuatSinhVien(curr->key);
            cout << '\n';
        }
        curr = curr->pNext;
    }
    if (!check) cout << "Not found in list.\n";
}