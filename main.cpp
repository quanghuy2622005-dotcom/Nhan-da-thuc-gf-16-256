#include <iostream>
#include <string>
using namespace std;

int nhan_gf(int a, int b, int n, int m)
{
    int ket_qua = 0;

    while (b != 0) {
        if ((b & 1) == 1) {
            ket_qua = ket_qua ^ a;
        }
        a = a << 1;
        if ((a & (1 << n)) != 0) {
            a = a ^ m;
        }
        b = b >> 1;
    }
    return ket_qua;
}

int doc_nhi_phan(char ten, int n)
{
    string chuoi;
    int gia_tri = 0;

    cout << ten << " = ";
    cin >> chuoi;

    if ((int)chuoi.length() != n) {
        return -1;
    }

    for (int i = 0; i < n; i++) {
        if (chuoi[i] != '0' && chuoi[i] != '1') {
            return -1;
        }
        gia_tri = gia_tri * 2 + chuoi[i] - '0';
    }

    return gia_tri;
}

void in_da_thuc(int gia_tri, int n)
{
    int dau = 1;

    if (gia_tri == 0) {
        cout << "0";
        return;
    }

    for (int i = n - 1; i >= 0; i--) {
        if (((gia_tri >> i) & 1) == 1) {
            if (dau == 0) {
                cout << " + ";
            }
            if (i == 0) {
                cout << "1";
            } else if (i == 1) {
                cout << "x";
            } else {
                cout << "x^" << i;
            }
            dau = 0;
        }
    }
}

int main()
{
    string lua_chon;

    cout << "Chon so bit cua truong (4 hoac 8): ";
    cin >> lua_chon;
    if (lua_chon != "4" && lua_chon != "8") {
        cout << "Chon truong 4 hoac 8.\n";
        return 1;
    }

    int n = lua_chon[0] - '0';
    int m = 0x13; //10011
    if (n == 8) {
        m = 0x11B;   //100011011
    }

    cout << "M(x) = ";
    in_da_thuc(m, n + 1);
    cout << "\nNhap da thuc " << n << " bit.\n";
    int a = doc_nhi_phan('A', n);
    if (a == -1) {
        cout << "A khong hop le.\n";
        return 1;
    }

    int b = doc_nhi_phan('B', n);
    if (b == -1) {
        cout << "B khong hop le.\n";
        return 1;
    }

    int ket_qua = nhan_gf(a, b, n, m);
    cout << "Ket qua: ";
    for (int i = n - 1; i >= 0; i--) {
        cout << ((ket_qua >> i) & 1);
    }
    cout << "\nC(x) = ";
    in_da_thuc(ket_qua, n);
    cout << '\n';

    return 0;
}
