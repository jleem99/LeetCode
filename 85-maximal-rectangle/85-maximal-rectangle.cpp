class Solution {
    int checkRectangle(vector<vector<char>>& matrix, int x1, int y1, int w, int h) {
        const int m = matrix[0].size();
        const int n = matrix.size();

        for (int y = y1; y < y1 + h; y++) {
            if (y >= n) return 0;
            for (int x = x1; x < x1 + w; x++) {
                if (x >= m || matrix[y][x] == '0') return 0;
            }
        }
        return 1;
    }
    
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        const int m = matrix[0].size();
        const int n = matrix.size();        
        int rank = 0;
        
        for (int y1 = 0; y1 < n; y1++) {
            for (int x1 = 0; x1 < m; x1++) {
                
                int w = 1, h = 1;
                
                for (int h = 1; h <= n - y1; h++) {
                    int w = (rank / h) + 1;
                    // Check starting square if it's filled with 1's
                    if (!checkRectangle(matrix, x1, y1, w, h)) continue;

                    do {
                        rank = w * h;
                        w++;
                    } while (checkRectangle(matrix, x1 + w - 1, y1, 1, h));
                }
            }
        }

        return rank;
    }
};