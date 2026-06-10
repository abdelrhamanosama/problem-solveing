// Last updated: 6/10/2026, 11:50:29 AM
import java.util.Scanner;
class Solution {
    public int maxProfit(int[] prices) {
    int size = prices.length , maX = 0 , j;    
    j = size - 1 ;                            
    for(int i = size-2 ; i >= 0 ; i--)
        {   if(prices[j] - prices[i] < 0)
                {j--; i++; continue;}
            if (maX < prices[j] - prices[i])
                maX = prices[j] - prices[i];
        }
        return(maX);
    }
}