#include <iostream>

using namespace std;

// Fungsi penjumkahan matriks
void tambahMtrx(int A[2][2], int B[2][2], int hasil[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            hasil[i][j] = A[i][j] + B[i][j];
        }
    }
}
// Fungsi pengurangan matriks
void kurangMtrx(int A[2][2], int B[2][2], int hasil[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            hasil[i][j] = A[i][j] - B[i][j];
        }
    }
}
// Fungsi skalar
void xSkalar(int A[2][2], int k, int hasil[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            hasil[i][j] = A[i][j] * k;
        }
    }
}
// Fungsi perkalian matriks
void kaliMtrx(int A[2][2], int B[2][2], int hasil[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            hasil[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                hasil[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
//Program Utama
int main() {
    int A[2][2] = {{1, 2}, {3, 4}}; // Matriks 2x2
    int B[2][2] = {{1, 1}, {2, 2}};
    int hasil[2][2];
    char ulangi;

    do {
        int pilihan;
        cout << "======================================= " << endl;
        cout << "Matriks A : {1 2} , Matriks B : {1 1} " << endl;
        cout << "            {3 4}               {2 2} " << endl;
        cout << endl;

        cout << "Menu :" << endl;
        cout << "1. Penjumlahan Matriks" << endl;
        cout << "2. Pengurangan Matriks" << endl;
        cout << "3. Perkalian Skalar" << endl;
        cout << "4. Perkalian Matriks" << endl;
        cout << "5. Exit" << endl;
        cout << endl;
        cout << "======================================= " << endl;
        cout << endl;
        cout << "Pilih salah satu menu di atas : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "==========================" << endl;
                tambahMtrx(A, B, hasil);
                cout << "Hasil Penjumlahan : " << endl;
                break;
            case 2:
                cout << "==========================" << endl;
                kurangMtrx(A, B, hasil);
                cout << "Hasil Pengurangan : " << endl;
                break;
            case 3:
                cout << endl;
                int k;
                cout << "Masukkan skalar (n) : ";
                cin >> k;
                cout << k << " x Matriks A" << endl;
                xSkalar(A, k, hasil);
                cout << "==========================" << endl;
                cout << "Hasil Perkalian Skalar : " << endl;
                break;
            case 4:
                cout << "==========================" << endl;
                kaliMtrx(A, B, hasil);
                cout << "Hasil Perkalian Matriks : " << endl;
                break;
            case 5:
                cout << "===================" << endl;
                cout << " See You Again..... " << endl;
                cout << "===================" << endl;
                return 0;
            default:
                cout << "Pilihan tidak valid." << endl;
        }

        // Output Hasil
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                cout << hasil[i][j] << " ";
            }
            cout << endl;
        }

        cout << "==========================" << endl;
        cout << "Ingin memilih menu lagi? (Y/N): ";
        cin >> ulangi;
        system("cls");
        cout << endl;
    } while (ulangi == 'Y' || ulangi == 'y');

    return 0;
}
