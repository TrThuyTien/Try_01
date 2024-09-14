#include<iostream>
#include<string>

using namespace std;

struct User {
    string name;
    string password;
    int flag;
    User() : name(""), password(""), flag(0) {}
};

struct HashTable {
    int M;
    int n;
    User* table;
};

int HashFunction(HashTable H, string s) {
    int sum = 0;
    for (int i = 0; i < s.size(); i++) 
        sum += int(s[i]);
    return sum % H.M;
}

void CreateHashTable(HashTable& H, int n) {
    for (int i = 0; i < n; i++) {
        H.n++;
        User p;
        cin >> p.name >> p.password;
        int key = HashFunction(H, p.name);
        int k = 0;
        while (k < H.M) {
            int hf = (key + k) % H.M;
            if (H.table[hf].flag == 0) {
                p.flag = 1;
                H.table[hf].flag = 1;
                H.table[hf] = p;
                break;
            } else if (H.table[hf].flag == 1 && H.table[hf].name == p.name) {
                H.table[hf].password = p.password;
                break;
            } else k++;
        }
    }
}

void FindUser(HashTable H, int t) {
    while(t--) {
        string name;
        cin >> name;
        int key = HashFunction(H, name);
        int k = 0;
        bool check = false;
        while (k < H.M) {
            int hf = (key + k) % H.M;
            if (H.table[hf].flag == 0) {
                break;
            } else if (H.table[hf].flag == 1 && H.table[hf].name == name) {
                cout << H.table[hf].password << '\n';
                check = true;
                break;
            } else k++;
        }
        if (!check) cout << "Unregistered User.\n";
    }
}

int main () {
    freopen ("LoginUserPassword.inp", "r", stdin);
    freopen ("LoginUserPassword.out", "w", stdout);
    int n, t;
    cin >> n >> t;
    HashTable H;
    H.M = 10001;
    H.table = new User[H.M];
    CreateHashTable(H, n);
    FindUser(H, t);
}

