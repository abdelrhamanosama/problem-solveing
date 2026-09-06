// Last updated: 9/6/2026, 4:02:34 PM
class Solution {
    public int distributeCandies(int[] candyType) {
       Set<Integer> set = new HashSet<>();
        for(int candytype: candyType){
            set.add(candytype);
        }
        return (int)Math.min(set.size() , candyType.length/2);
    }
}