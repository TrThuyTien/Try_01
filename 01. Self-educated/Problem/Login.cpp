#include<iostream>
#include<string.h>
#include<string>

using namespace std;

char symbol[11] = {'!', '@', '#', '$', '%', '^', '&', '*', '?', '_', '~'};
char nonAccept[5] = {'.', '\\', '/', ' ', ','};
int BaseScore = 40;
int Bonus_Excess = 3;
int Bonus_Upper = 4;
int Bonus_Number = 5;
int Bonus_Symbols = 5;

bool isUpperLetter(char c) 
{
    if (c >= 'A' && c <= 'Z') return true;
    return false;
}

bool isSymbol(char c)
{
    for (int i = 0; i < 11; i++) 
        if (c == symbol[i]) return true;
    return false;
}

bool isNumber(char c) 
{
    if (c >= '0' && c <= '9') return true;
    return false;
}

int Bonus_Combo(string s) 
{
    bool is_upper_letter = false;
    bool is_symbol = false;
    bool is_number = false;
    for (int i = 0; i < s.size(); i++) {
        is_upper_letter |= isUpperLetter(s[i]);
        is_symbol |= isSymbol(s[i]);
        is_number |= isNumber(s[i]);
    }
    if (is_upper_letter && is_symbol && is_number) return 25;
    if (is_upper_letter && is_symbol) return 15;
    if (is_upper_letter && is_number) return 15;
    if (is_symbol && is_number) return 15;
    return 0;
}

int Bonus_FlatLower(string s) 
{
    for (int i = 0; i < s.size(); i++) 
        if (s[i] < 'a' || s[i] > 'z') return 0;
    return -15;
}

int Bonus_FlatNumber(string s)
{
    for (int i = 0; i < s.size(); i++) 
        if (s[i] < '0' || s[i] > '9') return 0;
    return -35;
}

int Number_Excess(string s)
{
    return s.size() - 8;
}

int Number_Upper(string s)
{
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) 
        if (isUpperLetter(s[i])) cnt++;
    return cnt;
}

int Number_Numbers(string s)
{
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) 
        if (isNumber(s[i])) cnt++;
    return cnt;
}

int Number_Symbols(string s)
{
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) 
        if (isSymbol(s[i])) cnt++;
    return cnt;
}

int score(string s) 
{
    return BaseScore + (Number_Excess(s)*Bonus_Excess) + (Number_Upper(s)*Bonus_Upper)
    + (Number_Numbers(s)*Bonus_Number) + (Number_Symbols(s)*Bonus_Symbols)
    + Bonus_Combo(s) + Bonus_FlatLower(s) + Bonus_FlatNumber(s);
}

string result(string s) 
{
    if (s.size() < 8) return "KhongHopLe";
    for (int j = 0; j < s.size(); j++) {
        for (int i = 0; i < 5; i++) {
            if (s[j] == nonAccept[i]) return "KhongHopLe";
        } 
    }
    int Score = score(s);
    if (Score >= 100) return "RatManh";
    if (Score >= 75) return "Manh";
    if (Score >= 50) return "Vua";
    return "Yeu";
}
int main () {
    // freopen("Login.inp", "r", stdin);
    // freopen("Login.out", "w", stdout);
    string s;
    getline(cin, s);
    cout << result(s);
}