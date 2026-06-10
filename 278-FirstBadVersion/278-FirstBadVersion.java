// Last updated: 6/10/2026, 11:49:26 AM
/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        int start = 1;
        int end = n;
        int bad = 0;
        while(start <= end) {
            bad = start + (end - start) / 2;
            boolean flag1 = isBadVersion(bad), flag2 = isBadVersion(bad -1);
            if(flag1  && flag2 == false)  return bad;
            if(flag1) {
                end = bad - 1;
            }
            else
                start = bad + 1;
        }
        return bad;
    }
}