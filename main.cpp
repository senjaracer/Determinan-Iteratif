#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace chrono;

// Fungsi untuk menghitung determinan menggunakan eliminasi Gauss
double determinantIterative(vector<vector<double>> matrix, int n) {
    double det = 1.0;

    for (int i = 0; i < n; i++) {
        // Cari elemen diagonal utama yang bukan nol
        if (matrix[i][i] == 0.0) {
            for (int j = i + 1; j < n; j++) {
                if (matrix[j][i] != 0.0) {
                    swap(matrix[i], matrix[j]);
                    det *= -1; // Tukar baris mengubah tanda determinan
                    break;
                }
            }
        }
        if (matrix[i][i] == 0.0) return 0.0; // Determinan nol jika elemen diagonal utama nol

        det *= matrix[i][i];
        for (int j = i + 1; j < n; j++) {
            double factor = matrix[j][i] / matrix[i][i];
            for (int k = i; k < n; k++) {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
    }
    return det;
}

// Fungsi untuk menghasilkan matriks acak
vector<vector<double>> generateRandomMatrix(int n) {
    vector<vector<double>> matrix(n, vector<double>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 10 + 1; // Nilai acak 1-10
        }
    }
    return matrix;
}

int main() {
    for (int n = 1; n <= 12; n ++) {
        vector<vector<double>> matrix = generateRandomMatrix(n);
        auto start = high_resolution_clock::now();
        double det = determinantIterative(matrix, n);
        auto end = high_resolution_clock::now();
        duration<double> elapsed = end - start;
        cout << "Iterative | Size: " << n << " | Determinant: " << det << " | Time: " << elapsed.count() << "s\n";
    }
    return 0;
}
