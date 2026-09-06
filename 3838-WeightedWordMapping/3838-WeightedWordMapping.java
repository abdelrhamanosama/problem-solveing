// Last updated: 9/6/2026, 2:12:19 PM

class Solution {
    public String mapWordWeights(String[] words, int[] weights) {
        int n = words.length;
        StringBuilder s = new StringBuilder("");
        for(int i = 0 ; i < n; i++){
            int m = words[i].length();
            int sum = 0 ;
            for(int j = 0 ; j < m; j++)
                sum = (sum+weights[(words[i].charAt(j)-'a')])%26;
            s.append((char)('z' - sum));
        }
        
        return s.toString();   
    }
}