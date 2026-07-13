// Last updated: 7/13/2026, 11:32:01 AM
1import java.util.ArrayList;
2import java.util.List;
3
4class Solution {
5    public List<Integer> sequentialDigits(int low, int high) {
6        int []ar = {12,23,34,45,56,67,78,89,0};
7        List <Integer> list = new ArrayList<Integer>();
8        int i = 0 , size = 8;
9        int sizeDigitLow = (int)Math.log10(low)+1;
10        int sizeDigithigh = (int)Math.log10(high)+1;
11        for(i = 2; i <= sizeDigithigh; i++) {
12            for(int j = 0; j < size; j++) {
13                if(ar[j]>=low && ar[j] <= high)
14                    list.add(ar[j]);
15                ar[j] = ar[j]*10+j + i + 1;
16            }
17            size--;
18        }
19        return list;
20    }
21}