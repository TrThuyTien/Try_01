/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#include <string>

using namespace std;

#define LOAD 0.7
#define EMPTY 0
#define DELETED -1
#define OCCUPIED 1

struct NODE {
    int flag; // Lưu trạng thái của NODE: -1:DELETE, 0:EMPTY, Giá trị khác: Node đang tồn tại giá trị
    int key;
};

struct HASHTABLE {
    int M; // Kich thuoc bang bam
    int n; // so phan tu hien tai trong bang bam
    NODE *table;
};

int HF(HASHTABLE ht, int key) { return key % ht.M; }

int HF_LinearProbing(HASHTABLE ht, int key, int i) {
    int h=HF(ht, key);
    return (h + i) % ht.M;
}
//###INSERT CODE HERE -

int InsertKey(HASHTABLE& H, int x) {
    if (float(float(H.n + 1)/ H.M) > LOAD) return 0;
    int i = HF(H, x);
    int k = 0;
    do {
        i = HF_LinearProbing(H, x, k++);
        if (H.table[i].flag == EMPTY || H.table[i].flag == DELETED) {
            H.table[i].flag = OCCUPIED;
            H.table[i].key = x;
            H.n++;
            return 1;
        } else if (x == H.table[i].key) return 0;
    } while (k < H.M);
    return 0;
}

int DeleteKey(HASHTABLE& H, int x) {
    int i = HF(H, x);
    int k = 0;
    do {
        i = HF_LinearProbing(H, x, k++);
        if (H.table[i].flag == OCCUPIED && H.table[i].key == x) {
            H.table[i].flag = -1;
            H.n--;
            H.table[i].key = 0;
            return 1;
        }
    } while (k < H.M);
    return 0;
}

void CreateHashTable(HASHTABLE& H) {
    cin >> H.M;
    H.table = new NODE[H.M];
    for (int i = 0; i < H.M; i++) {
        H.table[i].flag = EMPTY;
    }
    H.n = 0;
    int t;
    cin >> t;
    while (t--) {
        int choice, x;
        cin >> choice >> x;
        if (choice) InsertKey(H, x);
        else DeleteKey(H, x);
    }
}

void Traverse(HASHTABLE H) {
    for (int i = 0; i < H.M; i++) {
        cout << i << " --> ";
        if (H.table[i].flag == 1) cout << H.table[i].key;
        else if (H.table[i].flag == -1) cout << "DELETED";
        else cout << "EMPTY";
        cout << '\n';
    }
}

void DeleteHashtable(HASHTABLE &ht) {
    delete [] ht.table;
    ht.table = NULL;
    ht.M = 0;
}

int main(){
    HASHTABLE H;
    CreateHashTable(H);
    Traverse(H);
    DeleteHashtable(H);
    return 0;
}
