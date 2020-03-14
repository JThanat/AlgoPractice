#include <vector>

using namespace std;

void rotate(vector<vector<int>>& matrix) {
        // transpose matrx
        for(int i = 0; i < matrix.size() ; i++) {
            for(int j = 0; j < i ; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // reverse
        for(int i = 0; i < matrix.size() ; i++) {
            int front = 0;
            int back = matrix[i].size() - 1;
            while(front < back) {
                swap(matrix[i][front],matrix[i][back]);
                front++;
                back--;
            }
            // reverse(matrix[i].begin(), matrix[i].end());
        }
    }