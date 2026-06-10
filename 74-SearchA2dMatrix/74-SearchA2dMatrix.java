// Last updated: 6/10/2026, 11:50:38 AM
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int size  = matrix.length * matrix[0].length;   
        int strat = 0;
        int end = size -  1 ;
        boolean flag = false;
        while(strat <= end )    
        {
            int temp = (strat + end) / 2;
            if(matrix[temp / matrix[0].length][temp % matrix[0].length] == target)
                {
                    flag = true;
                    break;
                }
            else if(matrix[temp / matrix[0].length][temp % matrix[0].length] > target)
                end = temp - 1;
            else 
                strat = temp + 1;
        }
    return flag;
    }
     
}