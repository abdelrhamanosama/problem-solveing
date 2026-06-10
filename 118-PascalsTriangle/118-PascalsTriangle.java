// Last updated: 6/10/2026, 11:50:28 AM
import java.util.ArrayList;
import java.util.List;

class Solution {
    /*
     * start with counter = 1 , val = 1
     * then counter if the 1st i so you get 1
     * for(counter) val = 1 odd
     * for counter val= 1 even
     */
    List<List<Integer>> list = new ArrayList<List<Integer>>();
    public List<List<Integer>> generate(int numRows) {
        
        for (int i = 0; i < numRows; i++) {
            list.add(helpy(i));
        }
        return  list;
    }

    List<Integer> helpy(int terms) {
        ArrayList<Integer> listy = new ArrayList<Integer>();
        if (terms == 0)
            listy.add(1);
        else if (terms == 1) {
            listy.add(1);
            listy.add(1);
        } else if (terms == 2) {
            listy.add(1);
            listy.add(2);
            listy.add(1);
        }else {
            listy.add(1);
            for(int i = 1; i < terms; i++) {
                int sums = list.get(terms - 1).get(i - 1) + list.get(terms - 1).get(i);
                listy.add(sums);
            }
            listy.add(1);
        }
    return listy;
    }
}