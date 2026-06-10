// Last updated: 6/10/2026, 11:49:00 AM
class Solution {
    public String frequencySort(String s) {
        int freq[][] = new int [62][2];
        int size = s.length();
        StringBuilder ss = new StringBuilder("");
        for(int i = 0; i < 62; i++) {
            if(i < 26) 
                freq[i][1] = 'a' + i;
            else if( i < 52)
                freq[i][1] = 'A' + i-26;
            else
                freq[i][1] = '0' + i - 52;
        }
        for (int i = 0; i < size; i++) {
            char c = s.charAt(i);
            if('z' >= c && c >= 'a') {
                freq[c-'a'][0]++; // 0 to  25
            }
            else if ('Z' >= c && c >= 'A') {
                freq[c-'A' + 26][0]++; //
            }
            else 
                freq[c-'0'+52][0]++;
        }
        sort(freq);
        for (int i = 61; i >= 0; i--) {
            while(freq[i][0]-- > 0)
                ss.append((char)freq[i][1]);
        }
        return ss.toString();
    }
    private void sort (int [][]a){
        boolean sorted = false;
        int temp1 = 0, temp2 = 0;
        while(!sorted){
            sorted = true;
            for(int i = 0; i < a.length-1; i++){
                if(a[i][0] > a[i+1][0])
                    {
                        temp1 = a[i][0];
                        a[i][0] = a[i+1][0];
                        a[i+1][0] = temp1; // we exchange the values in i  and i + 1
                        temp2 = a[i][1];
                        a[i][1] = a[i+1][1];
                        a[i+1][1] = temp2; // we exchange the characters in i and i + 1
                        sorted = false;
                    }
            }
        }
    }
}