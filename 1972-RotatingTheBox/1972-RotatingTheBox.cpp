// Last updated: 6/10/2026, 11:44:32 AM
class Solution
{
private:
// اللهم اهدنا يا رب اليك

public:
   vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int rows = boxGrid.size(), cols = boxGrid[0].size();
        for(int i = 0 ; i < rows; i++){
            int p = 0;
            for(int j = 0 ; j < cols;j++){
                if(boxGrid[i][j] == '.'){
                    swap(boxGrid[i][j],boxGrid[i][p]);
                    p++;
                }
                else if(boxGrid[i][j] == '*') {
                    p = j+1;
                }
            }
        }
        vector<vector<char>> v(cols, vector<char>(rows));
        for (int i = rows-1 , i2 = 0; i >= 0; i-- , i2++) {
            vector<char> x = boxGrid[i];
            for (int j = 0; j < cols; j++) {
                v[j][i2] = x[j];
            }
        }
        return v; 
    }
};
