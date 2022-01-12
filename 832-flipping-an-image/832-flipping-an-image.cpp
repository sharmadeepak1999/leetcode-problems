class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int rows, columns;
        rows = columns = image.size();
        for(int i = 0; i < rows; i++) {
            int j = 0, k = columns - 1;
            while(j <= k) {
                int temp = !image[i][j];
                image[i][j] = !image[i][k];
                image[i][k] = temp;
                j++;
                k--;
            }
        }
        return image;
    }
};