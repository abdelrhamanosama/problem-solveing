// Last updated: 6/10/2026, 11:48:33 AM
import java.util.ArrayList;

class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {//[1,0,0,0,0,0,1]
    int count = 0 ;
    boolean flagR = false , flagL = false;
    ArrayList<Integer> listOfOnes = new ArrayList<Integer>();
    for(int i = 0 ; i < flowerbed.length ; i ++)
        {
            if(flowerbed[i] == 1)
                listOfOnes.add(i);
            
        }
    if(listOfOnes.isEmpty())
        return(((flowerbed.length+1)/2) >= n);
    if(flowerbed[0] == 0)
        flagL = true;
    if(flowerbed[flowerbed.length - 1] == 0)
        flagR = true;
    for(int i = 0 ; i < listOfOnes.size() - 1; i ++)
        {
            int temp = listOfOnes.get( i + 1) - listOfOnes.get(i);
                count += (temp - 2)/2;
        }
    if(flagL)
        count  += (listOfOnes.get(0) - 0) / 2 ;
    if(flagR)
        count += ( -1*listOfOnes.get(listOfOnes.size() - 1) + flowerbed.length - 1) / 2 ;
        return(count >= n);
                
    }
}