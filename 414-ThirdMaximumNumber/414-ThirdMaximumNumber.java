// Last updated: 6/10/2026, 11:49:06 AM
class Solution {
  public int thirdMax(int[] nums) {
      long m1 = Long.MIN_VALUE; 
      long m2 = Long.MIN_VALUE; 
      long m3 = Long.MIN_VALUE;
      for (int i : nums) { //[2,2,3,1]
        boolean flag1 = false, flag2 = false;
        if(i > m1)
        {
          m3 = m2;
          m2 = m1;
          m1 = i;
          flag1 = true;
          flag2 = true;
        }
        if(!flag1 && i > m2 && i!= m1)
          {
            m3 = m2;
            m2 = i;
            flag2 = true;
          }
        if(!flag2 && i > m3 && i != m2 && i != m1)
        {
          m3 = i;
        }
      } 
      if(m1 > m2 && m2 > m3 && m3 != Long.MIN_VALUE)
        return (int)m3;
      else
        return (int)m1;
  }
}