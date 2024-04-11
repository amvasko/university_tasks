#include <iostream>
#include <vector>

using namespace std;


void createMatrixB(const vector<vector<int>>& matrixA, vector<vector<int>>& matrixB) {
    int rows = matrixA.size();

    
    matrixB = matrixA;

    
    for (int i = 0; i < rows; i++) {
        for (int j = i + 1; j < rows; j++) {
            matrixB[i][j] = 0; 
            matrixB[rows - i - 1][j] = 0; 
        }
    }
}


void compareAndModifyDiagonals(vector<vector<int>>& matrixA, vector<vector<int>>& matrixB) {
    int rows = matrixA.size();

    
    for (int i = 0; i < rows; i++) {
        if (matrixA[i][i] == matrixB[i][i]) {
            
            if (i + 1 < rows && i + 1 < matrixA[0].size()) {
                matrixA[i][i] = matrixA[i + 1][i];
            }
            
            int rowSum = 0;
            for (int j = 0; j < rows; j++) {
                rowSum += matrixB[i][j];
            }
            matrixB[i][i] = rowSum;
        }
    }
}

int main() {
    
    int rows, cols;
    cout << "Enter the number of rows and columns for Matrix A: ";
    cin >> rows >> cols;

    if (rows != cols) {
        cout << "Matrix A must be square for well-defined diagonals." << endl;
        return 1;
    }

    vector<vector<int>> matrixA(rows, vector<int>(cols));
    cout << "Enter the elements for Matrix A:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrixA[i][j];
        }
    }

    
    vector<vector<int>> matrixB;
    createMatrixB(matrixA, matrixB);

    
    cout << "Matrix B:" << endl;
    for (const auto& row : matrixB) {
        for (int element : row) {
            cout << element << " ";
        }
        cout << endl;
    }

    
    compareAndModifyDiagonals(matrixA, matrixB);

    
    cout << "Modified Matrix A:" << endl;
    for (const auto& row : matrixA) {
        for (int element : row) {
            cout << element << " ";
        }
        cout << endl;
    }

    
    cout << "Modified Matrix B:" << endl;
    for (const auto& row : matrixB) {
        for (int element : row) {
            cout << element << " ";
        }
        cout << endl;
    }

    return 0;
}
