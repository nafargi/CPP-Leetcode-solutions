//Beats 98.90% of users with C++
const long long mod=1e9+7;
using Matrix = vector<vector<unsigned long long>>;
const Matrix T = {
   
    {1, 1, 0, 1, 0, 0},
    {1, 0, 1, 1, 0, 0}, // S1
    {1, 0, 0, 1, 0, 0}, // S2
    {0, 0, 0, 1, 1, 0}, // S3
    {0, 0, 0, 1, 0, 1}, // S4
    {0, 0, 0, 1, 0, 0}  // S5
};

const Matrix I = {//identity matrix
    //S0 S1 S2 S3 S4 S5
    {1, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 1}
};

// Overloading the * operator for matrix multiplication
Matrix operator*(const Matrix& A, const Matrix& B) {
    int n = A.size();
    int m = B[0].size();
    int p = A[0].size();
    Matrix C(n, vector<unsigned long long>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < p; ++k) {
                C[i][j]=(C[i][j]+A[i][k]*B[k][j]) % mod;
            }
        }
    }
    return C;
}

// recursive Function for matrix exponentiation (LSBF)
inline Matrix pow(Matrix M, int n){
    if (n==0) return I;
    Matrix A=(n&1)?M:I;
    return pow((M*M), n/2)*A;
}

class Solution {
public:
    int checkRecord(int n) {
        // Compute T^n
        Matrix A = pow(T, n);

        // Compute the final state using sum(A[0])
        unsigned long long ans=(accumulate(A[0].begin(), A[0].begin()+6, mod))%mod;
        return ans;
    }
};


auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
