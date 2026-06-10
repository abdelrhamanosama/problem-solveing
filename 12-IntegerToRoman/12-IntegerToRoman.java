// Last updated: 6/10/2026, 11:51:20 AM
class Solution {
    String s = "";
    public String intToRoman(int num) {
        int i = 0;
        int []arr = {0,0,0,0};
        while(num >0)
        {
            arr[i] = num % 10;
            num /= 10 ; i++;
        }
        for(i = 3 ; i >=0 ; i-- )
            romania(arr[i], i + 1);
        return s;
    }
    private void romania(int x , int itsRank)
    {
        switch(itsRank)
        {
            case 1:
                building1(x); 
            break;
            case 2:
                building2(x);
            break;
            case 3:
                building3(x); 
            break;
            case 4:
                building4(x);
            break;
        }
    }
    private void building1(int x)
    {
        if(x == 4)
            {
                s += "IV";
                return ;
            }
        else if(x == 9 )
            {
                s +="IX";
                return ;
            }
        else if (x>4)
        {
            s += "V";
            x -= 5 ;
        }
        for(int i = 0 ; i < x ;i++)
               s += "I";
    }
    private void building2(int x)
    {
        if(x == 4)
            {
                s += "XL";
                return ;
            }
        else if(x == 9 )
            {
                s +="XC";
                return ;
            }
        else if (x>4)
        {
            s += "L";
            x -= 5 ;
        }
        for(int i = 0 ; i < x ;i++)
               s += "X";
    }
    private void building3(int x)
    {
        if(x == 4)
            {
                s += "CD";
                return ;
            }
        else if(x == 9 )
            {
                s +="CM";
                return ;
            }
        else if (x>4)
        {
            s += "D";
            x -= 5 ;
        }
        for(int i = 0 ; i < x ;i++)
               s += "C";
    }
    private void building4(int x)
    {
        for(int i = 0 ; i < x ;i++)
               s += "M";
    }
}