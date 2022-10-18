class Solution {
    public int reverse(int x) {
        double ans = 0;
        while(x != 0){
            int cur = x%10;
            x = x/10;   
            
            if(ans < 2147483647/10 && ans > -2147483647/10 || 
               ans == 2147483647/10 && cur<7 || 
               ans ==  -2147483647/10 && -cur < 7) 
            {ans = ans*10 + cur;}
            
            else
            {return 0;}  
        }
        int output = (int)ans;
        return output;
    }
}
