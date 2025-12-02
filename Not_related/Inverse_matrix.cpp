#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <numeric>

using namespace std;
const double EPSILON = 1e-9;


void print_matrix(const vector<vector<double>>& matrix) {
    cout << fixed << setprecision(4);
    for (const auto& row : matrix) {
        for (double val : row) {
            cout << setw(10) << val << " ";
        }
        cout << endl;
    }
}
vector<vector<double>> inverse_matrix(vector<vector<double>>& A) {
    int N = A.size();
    if (N == 0 || A[0].size() != N) {
        cerr << "Error: Matrix must be square and non-empty." << endl;
        return {};
    }


    vector<vector<double>> augmented_matrix(N, vector<double>(2 * N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            augmented_matrix[i][j] = A[i][j];
        }

        augmented_matrix[i][i + N] = 1.0;
    }

    cout << "\n--- Starting Gauss-Jordan Elimination ---\n";
    cout << "Initial Augmented Matrix [A | I]:\n";
    print_matrix(augmented_matrix);

    // 


    for (int i = 0; i < N; ++i) { 


        int pivot_row = i;
        for (int k = i + 1; k < N; ++k) {
            if (abs(augmented_matrix[k][i]) > abs(augmented_matrix[pivot_row][i])) {
                pivot_row = k;
            }
        }


        if (abs(augmented_matrix[pivot_row][i]) < EPSILON) {
            cerr << "\nError: Matrix is singular. Cannot find inverse." << endl;
            return {};
        }


        if (pivot_row != i) {
            swap(augmented_matrix[i], augmented_matrix[pivot_row]);
            cout << "\nRow Swap: Swapping row " << i + 1 << " with row " << pivot_row + 1 << endl;
            print_matrix(augmented_matrix);
        }
        

        double pivot_value = augmented_matrix[i][i];
        for (int j = i; j < 2 * N; ++j) {
            augmented_matrix[i][j] /= pivot_value;
        }
        cout << "\nNormalization: Divide row " << i + 1 << " by " << pivot_value << endl;
        print_matrix(augmented_matrix);


        for (int k = 0; k < N; ++k) {
            if (k != i) {
                double factor = augmented_matrix[k][i];
                for (int j = i; j < 2 * N; ++j) {
                    augmented_matrix[k][j] -= factor * augmented_matrix[i][j];
                }
                cout << "\nElimination: Row " << k + 1 << " = R" << k + 1 << " - " << factor << " * R" << i + 1 << endl;
                print_matrix(augmented_matrix);
            }
        }
    }


    vector<vector<double>> A_inv(N, vector<double>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            A_inv[i][j] = augmented_matrix[i][j + N];
        }
    }

    return A_inv;
}

int main() {

    vector<vector<double>> A1 = {
        {4, -2, 1},
        {8, 0, -2},
        {6, 1, 1}
    };
    
    cout << "Original Matrix A1:\n";
    print_matrix(A1);

    vector<vector<double>> A1_inv = inverse_matrix(A1);

    if (!A1_inv.empty()) {
        cout << "\n--- Inverse Matrix A1_inv ---\n";
        print_matrix(A1_inv);
    }


    vector<vector<double>> A2 = {
        {1, 2, 3},
        {4, 5, 6},
        {6, 9, 12}
    };

    cout << "\n========================================\n";
    cout << "Original Matrix A2 (Singular):\n";
    print_matrix(A2);

    vector<vector<double>> A2_inv = inverse_matrix(A2);

    return 0;
}
