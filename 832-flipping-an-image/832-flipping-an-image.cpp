class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int rows, columns;
        rows = columns = image.size();
        for(int i = 0; i < rows; i++) {
            reverse(image[i].begin(), image[i].end());
            for(auto &b : image[i]) b ^= 1;
        }
        return image;
    }
};