#include <bits/stdc++.h>
using namespace std;

int nextPow2(int n) {
    return pow(2, ceil(log2(n)));
}

vector<vector<int>> padMatrix(const vector<vector<int>> &mat, int r, int c) {
    vector<vector<int>> out(r, vector<int>(c));
    for (int i = 0; i < mat.size(); i++)
        for (int j = 0; j < mat[0].size(); j++)
            out[i][j] = mat[i][j];
    return out;
}

vector<vector<int>> matOp(vector<vector<int>> a, vector<vector<int>> b, int n, int sign = 1) {
    vector<vector<int>> res(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            res[i][j] = a[i][j] + sign * b[i][j];
    return res;
}

vector<vector<int>> strMul(vector<vector<int>> a, vector<vector<int>> b) {
    int n = a.size();
    vector<vector<int>> out(n, vector<int>(n));
    if (n == 1) {
        out[0][0] = a[0][0] * b[0][0];
        return out;
    }

    int k = n / 2;
    vector<vector<int>> a1(k, vector<int>(k)), a2(k, vector<int>(k));
    vector<vector<int>> a3(k, vector<int>(k)), a4(k, vector<int>(k));
    vector<vector<int>> b1(k, vector<int>(k)), b2(k, vector<int>(k));
    vector<vector<int>> b3(k, vector<int>(k)), b4(k, vector<int>(k));

    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            a1[i][j] = a[i][j];
            a2[i][j] = a[i][j + k];
            a3[i][j] = a[i + k][j];
            a4[i][j] = a[i + k][j + k];
            b1[i][j] = b[i][j];
            b2[i][j] = b[i][j + k];
            b3[i][j] = b[i + k][j];
            b4[i][j] = b[i + k][j + k];
        }

    auto m1 = strMul(matOp(a1, a4, k), matOp(b1, b4, k));
    auto m2 = strMul(matOp(a3, a4, k), b1);
    auto m3 = strMul(a1, matOp(b2, b4, k, -1));
    auto m4 = strMul(a4, matOp(b3, b1, k, -1));
    auto m5 = strMul(matOp(a1, a2, k), b4);
    auto m6 = strMul(matOp(a3, a1, k, -1), matOp(b1, b2, k));
    auto m7 = strMul(matOp(a2, a4, k, -1), matOp(b3, b4, k));

    auto c1 = matOp(matOp(m1, m4, k), matOp(m7, m5, k, -1), k);
    auto c2 = matOp(m3, m5, k);
    auto c3 = matOp(m2, m4, k);
    auto c4 = matOp(matOp(m1, m3, k), matOp(m6, m2, k, -1), k);

    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            out[i][j] = c1[i][j];
            out[i][j + k] = c2[i][j];
            out[i + k][j] = c3[i][j];
            out[i + k][j + k] = c4[i][j];
        }

    return out;
}

vector<vector<int>> multiplyMat(vector<vector<int>> &a, vector<vector<int>> &b) {
    int r = a.size(), m = a[0].size(), c = b[0].size();
    int size = nextPow2(max({r, m, c}));

    auto A = padMatrix(a, size, size);
    auto B = padMatrix(b, size, size);
    auto C = strMul(A, B);

    vector<vector<int>> res(r, vector<int>(c));
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            res[i][j] = C[i][j];

    return res;
}

int main() {
    vector<vector<int>> A = {
        {2, 4, 1},
        {0, 3, 5}
    };

    vector<vector<int>> B = {
        {1, 2},
        {0, 1},
        {4, 0}
    };

    auto ans = multiplyMat(A, B);
    for (auto &row : ans) {
        for (int x : row) cout << x << ' ';
        cout <<endl;
    }
    return 0;
}
