/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
//###INSERT CODE HERE -
#include <math.h>

using namespace std;

struct PhanSo {
    int ts, ms;
    PhanSo () : ts(0), ms(1) {};
};

istream& operator>>(istream& inp, PhanSo& p) {
    inp >> p.ts >> p.ms;
    return inp;
}

ostream& operator<<(ostream& out, PhanSo& p) {
    if (p.ms == 1) out << p.ts;
    else if (p.ts == 0) out << 0;
    else out << p.ts << "/" << p.ms;
    return out;
}

int gcd(int a, int b) {
    if (a == 0) return 1;
    while (a != b) {
        if (a > b) a -= b;
        else if (b > a) b -= a;
    }
    return a;
}

int bcnn(int a, int b) {
    return (a * b) / gcd(a, b);
}

// Return the allocated size to avoid modifying const reference
void Nhap(PhanSo *&a, int &n) {
    std::cin >> n;
    a = new PhanSo[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

// void RutGon(PhanSo* a, const int& n) {
//     for (int i = 0; i < n; i++) {
//         int ucln = gcd(abs(a[i].ts), abs(a[i].ms));
//         a[i].ts /= ucln;
//         a[i].ms /= ucln;
//     }
// }

void RutGon(PhanSo& p) {
    if (p.ts < 0 && p.ms < 0) {
        p.ts = -p.ts;
        p.ms = -p.ms;
    } else if (p.ts > 0 && p.ms < 0) {
        p.ts = -p.ts;
        p.ms = -p.ms;
    } else if (p.ts == 0 && p.ms < 0) {
        p.ms = abs(p.ms);
    }
    if (p.ts == 0) return;
    int tu = abs(p.ts);
    int mau = abs(p.ms);
    while (tu != mau) {
        if (tu > mau) tu -= mau;
        else if (tu < mau) mau -= tu;
    }
    p.ts /= tu;
    p.ms /= mau;
}


void QuyDong(PhanSo* a, const int& n) {
    // RutGon (a, n);
    // for (int i = 0; i < n; i++) {
    //     RutGon(a[i]);
    // }
    int MSC = abs(a[0].ms);
    for (int i = 1; i < n; i++) {
        if (a[i].ts == 0) continue;
        MSC = bcnn(MSC, abs(a[i].ms));
    }
    for (int i = 0; i < n; i++) {
        int tmp = MSC / a[i].ms;
        a[i].ts *= tmp;
        a[i].ms = MSC;
    }
}

void SapXepGiamDan(PhanSo* a, const int& n) {
    QuyDong(a, n);
    for (int i = 0; i < n - 1; i++) {
        int k = i;
        for (int j = i + 1; j < n; j++)
            if (a[k].ts < a[j].ts) k = j;
        swap(a[k], a[i]);
    }
    for (int i = 0; i < n; i++) {
        RutGon(a[i]);
    }
}

void Xuat(PhanSo *a, const int& n) {
    for (int i = 0; i < n; i++) 
        cout << a[i] << '\n';
}

int main() {
    PhanSo *a;
    int n;
    Nhap(a, n);
    SapXepGiamDan(a, n);
    Xuat(a, n);
    return 0;
}
