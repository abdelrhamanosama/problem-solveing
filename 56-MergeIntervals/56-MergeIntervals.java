// Last updated: 6/10/2026, 11:50:54 AM
class Solution {
    public int[][] merge(int[][] intervals ) {
        int [][]arr = new int [intervals.length][2];
        int i , j = 0 ;
        intervals = sortIntervals(intervals);
        arr[0][0] = intervals[0][0]; arr[0][1] = intervals [0][1];
        for(i = 1 ; i < intervals.length ; i++)
            {try{
                if(intervals[i][0] <= arr[j][0])
                    arr[j][0] = intervals[i][0];
                if(arr[j][1] >= intervals[i][0])
                    {if(arr[j][1] < intervals[i][1])
                        arr[j][1] = intervals[i][1];}
                else
                    {
                         j++;
                        arr[j][0] = intervals[i ][0];
                        arr[j][1] = intervals[i ][1];
                    }
            }
            catch(Exception e){}    
        }
        int [][]  q = new int [j+1][2];
        for(i = 0 ;  i <= j ; i++)
            {
                q[i][0] = arr[i][0];
                q[i][1] = arr[i][1];
            }
        for(i = 0 ;  i <= j ; i++)
            {
                System.out.println(q[i][0] + " " + q[i][1]);
            }
        return(q);
    }
public int[][] sortIntervals(int [][] intervals){
    boolean check = false;
    while(!check)
    {   
        check = true;
        for(int i = 0 ; i < intervals.length - 1;i++)
        {
            if(intervals[i][0] > intervals[i+1][0])
                {
                    int temp1 = intervals[i][0] ,temp2 = intervals[i][1];
                    intervals[i][0] = intervals[i + 1][0]; intervals[i][1]  = intervals[i + 1][1];
                    intervals[i + 1][0] = temp1 ;intervals[i + 1][1] = temp2;
                    check = false;
                }
        }
    }
    return(intervals);
}
}