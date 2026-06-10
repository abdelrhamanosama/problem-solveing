// Last updated: 6/10/2026, 11:44:48 AM
class Solution {
    public int minimumLength(String s) {
        int start = 0, end= s.length()-1;
        while(start < end) {
            char c1 = s.charAt(start);
            char c2 = s.charAt(end);
            System.out.println(c1 + " " +c2);
            System.out.println(start +" " + end);
            if(c1!=c2)
                return end-start+1;
            end--;
            start++;
            for (int i = end; i >= 0 && i > start ; i--) {
                if(s.charAt(end+1)==s.charAt(i))
                    end--; //"abbbbbbbaabbbbbbbaa"
                else
                    break;
                System.out.print("C  ");
            }
            for (int i = start; i < s.length() && i <= end ; i++) {
                if (s.charAt(start-1) == s.charAt(i))
                    start++;
                else
                    break;
                System.out.print("A  ");
            }
            System.out.println(start +"" + end);
            
        }
        System.out.println("hi");
        System.out.println(start +"" + end);

        return (start==end)? 1 : 0;

    }
}
