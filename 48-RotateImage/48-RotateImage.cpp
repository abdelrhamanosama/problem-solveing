// Last updated: 6/10/2026, 11:50:55 AM
class Solution
{
private:
// اللهم اهدنا يا رب اليك

public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i =  0; i < matrix[0].size(); i++){
            for(int j = 0 ; j < matrix.size()/2; j++){
                swap(matrix[j][i] , matrix[matrix.size()-1-j][i]);
            }
        }
        int times = matrix.size() - 1;
        int srow = 1;
        int scol = 1;
        int snode = 0;
        while(times--){

            int i = srow , j = scol;
            while(i < matrix.size() && j < matrix.size())
            {
                swap(matrix[snode][j] , matrix[i][snode]);
                i++;
                j++;
            }
            snode++;
            srow++;
            scol++;
        }
    }
};