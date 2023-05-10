#include <bits/stdc++.h>
#include <ctime>

using namespace std;

int getMaxVal(int n, int w[], int v[], int c, int i) {
    int vin, vex;
    if (i == n || c <= 0) {
        return 0;
    }
    if (w[i] < c) {
        vin = getMaxVal(n, w, v, c - w[i], i + 1) + v[i];
        vex = getMaxVal(n, w, v, c, i + 1);

        return max(vin, vex);
    } else {
        vex = getMaxVal(n, w, v, c, i + 1);
        return vex;
    }
}

int main() {
    int n = 10;
    int c;
    cout << "Nhap khoi luong toi da: ";
    cin >> c;

    ifstream inFile("CaiTui3.txt");
    int w[100], v[100];
    for (int i = 0; i < n; i++) {
        inFile >> w[i] >> v[i];
    }

    clock_t start = clock();
    int Kq = getMaxVal(n, w, v, c, 0);
    clock_t end = clock();

    double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    cout << "Thoi gian chay: " << duration << " giay" << endl;
    cout << Kq;

    return 0;
}

