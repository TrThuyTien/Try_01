/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

//###INSERT CODE HERE -
#include<iostream>
#define MAXR 100
#define MAXC 100

using namespace std;

void NhapMaTran(int a[][MAXC], int &r, int &c) 
{
    cin >> r >> c;
    for (int i = 0; i < r; i++) 
        for (int j = 0; j < c; j++) cin >> a[i][j];
}

void SapXepCotGiamDan(int a[][MAXC], const int &r, const int &c) 
{
    for (int j = 0; j < c; j++) {
        for (int i = 0; i < r; i++) {
            int selected = a[i][j];
            int k = i - 1;
            while (k >= 0 && a[k][j] < selected) {
                a[k + 1][j] = a[k][j];
                k--;
            }
            a[k+1][j] = selected;
        }
    }
}

void XuatMaTran(int a[][MAXC], const int &r, const int &c)
{
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) cout << a[i][j] << " ";
        cout << endl;
    }
}
 
int main() {
    int a[MAXR][MAXC], r, c;
    NhapMaTran(a, r, c);
    SapXepCotGiamDan(a, r, c);
    XuatMaTran(a, r, c);
    return 0;
}
