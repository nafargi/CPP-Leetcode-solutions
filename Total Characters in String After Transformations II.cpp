class Solution {
public:
    using Matrix = vector<vector<long long>>;
    const int MOD = 1e9 + 7;
    
    // Helper function to multiply two matrices
    Matrix multiply(const Matrix& A, const Matrix& B) {
        Matrix result(26, vector<long long>(26, 0));
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                for (int k = 0; k < 26; ++k) {
                    result[i][j] = (result[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return result;
    }
    
    // Binary exponentiation to efficiently calculate matrix^exp
    Matrix matrixExpo(Matrix base, long long exp) {
        // Start with identity matrix
        Matrix result(26, vector<long long>(26, 0));
        for (int i = 0; i < 26; ++i) {
            result[i][i] = 1;
        }
        
        while (exp > 0) {
            if (exp & 1) {  
                result = multiply(result, base);
            }
            base = multiply(base, base);  
            exp >>= 1;  
        }
        return result;
    }
    
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        // Count initial characters
        vector<long long> charCount(26, 0);
        for (char c : s) {
            charCount[c - 'a']++;
        }
        
        // Create transformation matrix transform[i][j] means: how many characters i are produced from one character j
        Matrix transform(26, vector<long long>(26, 0));
        for (int i = 0; i < 26; ++i) {
            for (int j = 1; j <= nums[i]; ++j) {
                transform[(i + j) % 26][i]++;
            }
        }
        
        Matrix finalTransform = matrixExpo(transform, t);
        
        // Calculate final character counts
        vector<long long> finalCount(26, 0);
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                finalCount[i] = (finalCount[i] + finalTransform[i][j] * charCount[j]) % MOD;
            }
        }
        
        // Sum up all character counts to get final string length
        long long totalLength = 0;
        for (int i = 0; i < 26; ++i) {
            totalLength = (totalLength + finalCount[i]) % MOD;
        }
        
        return static_cast<int>(totalLength);
    }
};
