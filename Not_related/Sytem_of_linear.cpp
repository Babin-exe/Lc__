#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <numeric>
#include <algorithm>

using namespace std;


const double EPSILON = 1e-9;
void print_augmented_matrix(const vector<vector<double>>& matrix) {
    int N = matrix.size();
    if (N == 0) return;
    int M = matrix[0].size();

    cout << fixed << setprecision(4);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << setw(10) << matrix[i][j];

            if (j == N - 1) {
                cout << " |";
            }
        }
        cout << endl;
    }
}


bool gauss_elimination_forward(vector<vector<double>>& matrix) {
    int N = matrix.size();

    for (int i = 0; i < N; ++i) {


        int pivot_row = i;
        for (int k = i + 1; k < N; ++k) {
            if (abs(matrix[k][i]) > abs(matrix[pivot_row][i])) {
                pivot_row = k;
            }
        }


        if (abs(matrix[pivot_row][i]) < EPSILON) {
            cerr << "\nSystem is singular (no unique solution)." << endl;
            return false;
        }


        if (pivot_row != i) {
            swap(matrix[i], matrix[pivot_row]);
            cout << "\n[Step] Swapped row " << i + 1 << " with row " << pivot_row + 1 << endl;
            print_augmented_matrix(matrix);
        }


        for (int k = i + 1; k < N; ++k) {
            double factor = matrix[k][i] / matrix[i][i];

            for (int j = i; j < N + 1; ++j) {
                matrix[k][j] -= factor * matrix[i][j];
            }
            cout << "\n[Step] R" << k + 1 << " = R" << k + 1 << " - " << factor << " * R" << i + 1 << endl;
            print_augmented_matrix(matrix);
        }
    }
    return true;
}





vector<double> solve_with_gauss_elimination(vector<vector<double>> A, const vector<double>& b) {
    int N = A.size();
    if (N != b.size() || N == 0) {
        cerr << "Error: Invalid matrix/vector dimensions." << endl;
        return {};
    }


    vector<vector<double>> augmented_matrix(N, vector<double>(N + 1));
    for (int i = 0; i < N; ++i) {
        augmented_matrix[i].assign(A[i].begin(), A[i].end());
        augmented_matrix[i][N] = b[i]; 
    }

    cout << "\n=======================================================\n";
    cout << "  Method 1: Gauss Elimination + Back Substitution\n";
    cout << "=======================================================\n";
    cout << "Initial Augmented Matrix [A | b]:\n";
    print_augmented_matrix(augmented_matrix);


    if (!gauss_elimination_forward(augmented_matrix)) {
        return {}; 
    }

    cout << "\n--- Final Row Echelon Form ---\n";
    print_augmented_matrix(augmented_matrix);


    vector<double> x(N);

    for (int i = N - 1; i >= 0; --i) {
        double sum_of_knowns = 0.0;

        for (int j = i + 1; j < N; ++j) {
            sum_of_knowns += augmented_matrix[i][j] * x[j];
        }

        x[i] = (augmented_matrix[i][N] - sum_of_knowns) / augmented_matrix[i][i];
    }

    return x;
}


// --- 2. SOLVING WITH GAUSS-JORDAN ELIMINATION ---


vector<double> solve_with_gauss_jordan(vector<vector<double>> A, const vector<double>& b) {
    int N = A.size();
    if (N != b.size() || N == 0) {
        cerr << "Error: Invalid matrix/vector dimensions." << endl;
        return {};
    }


    vector<vector<double>> augmented_matrix(N, vector<double>(N + 1));
    for (int i = 0; i < N; ++i) {
        augmented_matrix[i].assign(A[i].begin(), A[i].end());
        augmented_matrix[i][N] = b[i]; 
    }

    cout << "\n=======================================================\n";
    cout << "  Method 2: Gauss-Jordan Elimination\n";
    cout << "=======================================================\n";
    cout << "Initial Augmented Matrix [A | b]:\n";
    print_augmented_matrix(augmented_matrix);
    

    for (int i = 0; i < N; ++i) { 


        int pivot_row = i;
        for (int k = i + 1; k < N; ++k) {
            if (abs(augmented_matrix[k][i]) > abs(augmented_matrix[pivot_row][i])) {
                pivot_row = k;
            }
        }

        if (abs(augmented_matrix[pivot_row][i]) < EPSILON) {
            cerr << "\nSystem is singular (no unique solution)." << endl;
            return {}; // System is singular
        }


        if (pivot_row != i) {
            swap(augmented_matrix[i], augmented_matrix[pivot_row]);
            cout << "\n[Step] Swapped row " << i + 1 << " with row " << pivot_row + 1 << endl;
            print_augmented_matrix(augmented_matrix);
        }


        double pivot_value = augmented_matrix[i][i];
        for (int j = i; j < N + 1; ++j) {
            augmented_matrix[i][j] /= pivot_value;
        }
        cout << "\n[Step] Normalized row " << i + 1 << " (Pivot element is now 1)" << endl;
        print_augmented_matrix(augmented_matrix);


        for (int k = 0; k < N; ++k) {
            if (k != i) { 
                double factor = augmented_matrix[k][i];
                for (int j = i; j < N + 1; ++j) {
                    augmented_matrix[k][j] -= factor * augmented_matrix[i][j];
                }
                cout << "\n[Step] Eliminated row " << k + 1 << " element (R" << k + 1 << " = R" << k + 1 << " - factor * R" << i + 1 << ")" << endl;
                print_augmented_matrix(augmented_matrix);
            }
        }
    }


    vector<double> x(N);
    for (int i = 0; i < N; ++i) {
        x[i] = augmented_matrix[i][N];
    }
    return x;
}

int main() {
    

    vector<vector<double>> A = {
        {1.0, 2.0, 1.0},
        {2.0, 2.0, 3.0},
        {3.0, 1.0, 2.0}
    };


    const vector<double> b = {8.0, 13.0, 12.0};
    
    cout << "--- System of Equations (A*x = b) ---\n";
    cout << "The general problem representation is the Augmented Matrix [A | b]:\n";

    cout << "The system is:\n";
    cout << "R1: 1x + 2y + 1z = 8\n";
    cout << "R2: 2x + 2y + 3z = 13\n";
    cout << "R3: 3x + 1y + 2z = 12\n";



    vector<double> solution_gauss = solve_with_gauss_elimination(A, b);

    if (!solution_gauss.empty()) {
        cout << "\nSolution by Gauss Elimination + Back Substitution:\n";
        cout << "x = " << solution_gauss[0] << endl;
        cout << "y = " << solution_gauss[1] << endl;
        cout << "z = " << solution_gauss[2] << endl;
    }


    vector<double> solution_gauss_jordan = solve_with_gauss_jordan(A, b);

    if (!solution_gauss_jordan.empty()) {
        cout << "\nSolution by Gauss-Jordan Elimination:\n";
        cout << "x = " << solution_gauss_jordan[0] << endl;
        cout << "y = " << solution_gauss_jordan[1] << endl;
        cout << "z = " << solution_gauss_jordan[2] << endl;
    }

    return 0;
}
