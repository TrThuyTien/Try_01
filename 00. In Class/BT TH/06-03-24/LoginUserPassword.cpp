#include <iostream>
#include <string>

#define N 10000

using namespace std;

int n, m;

struct User {
    int flag;
    string username;
    string password;
};

struct HashTable {
    int M;
    int n;
    User* table;
};

int HF(HashTable ht, string key) { 
    int sum_key = 0;
    for (int i = 0; i < key.size(); i++) {
        sum_key += int(key[i]);
    }
    return sum_key % ht.M;
}


int HF_LinearProbing(HashTable ht, string key, int i) {
    int h = HF(ht, key);
    return (h + i) % ht.M;
}

int InsertKey(HashTable& H, User key) {
    int h = HF(H, key.username);
    int i = h;
    int k = 0;
    do {
        i = (h + k++) % H.M;
        if (H.table[i].flag == 0) {
            H.table[i].flag = 1;
            H.table[i].username = key.username;
            H.table[i].password = key.password;
            H.n++;
            return 1;
        } else if (H.table[i].username == key.username) {
            H.table[i].password = key.password;
            return 1;
        }
    } while (k < H.M);
    return 0;
}

void CreateHashTable(HashTable& H) {
    H.table = new User[n];
    H.M = n;
    for (int i = 0; i < H.M; i++) {
        H.table[i].flag = 0;
    }
    User x;
    for (int i = 0; i < n; i++) {
        cin >> x.username >> x.password;
        InsertKey(H, x);
    }
}

int FindUser(HashTable H, string key) {
    int h = HF(H, key);
    int i;
    int k = 0;
    do {
        i = (h + k++) % H.M;
        if (H.table[i].flag == 0) break;
        if (H.table[i].flag == 1 && H.table[i].username == key) {
            cout << H.table[i].password << '\n';
            return 1;
        }
    } while (k < H.M);
    cout << "Unregistered User.\n";
    return 0;
}

void NewPassWord(HashTable& H) {
    string userName;
    for (int i = 0; i < m; i++) {
        cin >> userName;
        FindUser(H, userName);
    }
    delete[] H.table;
}

int main () {
    freopen ("LoginUserPassWord.inp", "r", stdin);
    freopen ("LoginUserPassWord.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    HashTable H;
    H.M = n;
    CreateHashTable(H);
    NewPassWord(H);
    return 0;
}