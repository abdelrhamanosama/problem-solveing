// Last updated: 6/10/2026, 11:50:49 AM
class Solution {
    public int[] plusOne(int[] digits) {
        int i = digits.length - 1; boolean falg = false;
        int []add = new int[digits.length];
        add[digits.length - 1] = 1;
        for( ; i >= 0 ;i --)
            {
                digits[i] += add[i];
                if(digits[i] > 9 & i != 0)
                    {
                        digits[i] = 0;
                        digits[i - 1] ++;
                    }
                else if(digits[i] > 9 & i == 0)
                    {
                        digits[i] = 0;   
                        falg = true;
                    }
            }
            if(!falg) return digits;
            else add = new int[digits.length + 1];
            add[0] = 1;
           digits = add;
           return add; 
        // while(i != -1)
        // {
        //     if(digits[i] != 9)
        //         {
        //             digits[i]++;
        //             return digits;
        //         }
        // }
        // int arr [] = new int[digits.length + 1];
        // arr[0] = 1;
        // for(int j = 1 ; j < digits.length ; j ++)
        //     arr[j] = 0;
        // digits = arr;
        // return arr;  
    }
}