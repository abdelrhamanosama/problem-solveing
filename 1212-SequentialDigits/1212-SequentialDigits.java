// Last updated: 6/10/2026, 11:47:12 AM
import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> sequentialDigits(int low, int high) {
        int []ar = {12,23,34,45,56,67,78,89,0};
        List <Integer> list = new ArrayList<Integer>();
        int i = 0 , size = 8;
        int sizeDigitLow = (int)Math.log10(low)+1;
        int sizeDigithigh = (int)Math.log10(high)+1;
        for(i = 2; i <= sizeDigithigh; i++) {
            for(int j = 0; j < size; j++) {
                if(ar[j]>=low && ar[j] <= high)
                    list.add(ar[j]);
                ar[j] = ar[j]*10+j + i + 1;
            }
            size--;
        }
        return list;
    }
}