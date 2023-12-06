#include <iostream>
#include <cmath>

using namespace std;

// Fungsi untuk menampilkan matriks
void tampilMatrix(float matrix[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Fungsi untuk melakukan translasi
void translasi(float matrix[3][3], float tx, float ty) {
    float translasiMatrix[3][3] = {{1, 0, tx},
                                     {0, 1, ty},
                                     {0, 0, 1}};
    // Matriks hasil perkalian translasi
    float hasilMatrix[3][3] = {{0}};
    // Perkalian matriks
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                hasilMatrix[i][j] += matrix[i][k] * translasiMatrix[k][j];
            }
        }
    }
    // Menampilkan matriks hasil translasi
    cout << "Hasil Translasi:" << endl;
    tampilMatrix(hasilMatrix);
}

// Fungsi untuk melakukan scaling
void scaling(float matrix[3][3], float sx, float sy) {
    float scalingMatrix[3][3] = {{sx, 0, 0},
                                 {0, sy, 0},
                                 {0, 0, 1}};
    // Matriks hasil perkalian scaling
    float hasilMatrix[3][3] = {{0}};
    // Perkalian matriks
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                hasilMatrix[i][j] += matrix[i][k] * scalingMatrix[k][j];
            }
        }
    }
    // Menampilkan matriks hasil scaling
    cout << "Hasil Skala:" << endl;
    tampilMatrix(hasilMatrix);
}

// Fungsi untuk melakukan rotasi
void rotate(float matrix[3][3], float angle) {
    float cosTheta = cos(angle);
    float sinTheta = sin(angle);

    float rotasionMatrix[3][3] = {{cosTheta, -sinTheta, 0},
                                  {sinTheta, cosTheta, 0},
                                  {0, 0, 1}};
    // Matriks hasil perkalian rotasi
    float hasilMatrix[3][3] = {{0}};
    // Perkalian matriks
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                hasilMatrix[i][j] += matrix[i][k] * rotasionMatrix[k][j];
            }
        }
    }
    // Menampilkan matriks hasil rotasi
    cout << "Hasil Rotasi:" << endl;
    tampilMatrix(hasilMatrix);
}

int main() {
    float inputMatrix[3][3];
    // Memasukkan matriks dari pengguna
    cout << "==========================" << endl;
    cout << "  Masukkan nilai Matriks :" << endl;
    cout << "==========================" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "Baris " << i + 1 << ", Kolom " << j + 1 << ": ";
            cin >> inputMatrix[i][j];
        }
        cout << "--------------------------" << endl;
    }
    cout << "==========================" << endl;
    // Menampilkan matriks input
    cout << "Matriks 3x3:" << endl;
    tampilMatrix(inputMatrix);

    char milih;
    do {
        // Memilih operasi (translasi, skala, atau rotasi)
        int operasi;
        cout << "==========================" << endl;
        cout << "Pilih Menu 0perasi      : " << endl;
        cout << "==========================" << endl;
        cout << "1. Translasi \n2. Scaling \n3. Rotasi " << endl;
        cin >> operasi;

        switch (operasi) {
            case 1:
                // Memasukkan vektor translasi
                float tx, ty;
                cout << "Masukkan vektor translasi (tx ty): ";
                cin >> tx >> ty;
                translasi(inputMatrix, tx, ty);
                break;
            case 2:
                // Memasukkan faktor scaling
                float sx, sy;
                cout << "Masukkan faktor scaling (sx sy): ";
                cin >> sx >> sy;
                scaling(inputMatrix, sx, sy);
                break;
            case 3:
                // Memasukkan sudut rotasi (dalam radian)
                float angle;
                cout << "Masukkan sudut rotasi (dalam radian): ";
                cin >> angle;
                rotate(inputMatrix, angle);
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }

        cout << "Ingin mencoba menu lain? (y/n): ";
        cin >> milih;

    } while (milih == 'y' || milih == 'Y');

    return 0;
}

