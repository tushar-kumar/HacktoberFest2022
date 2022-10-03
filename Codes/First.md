//FLOYD's Triangle Pattern Print code --->

import java.util.*;

public class patterns8 {
    public static void main(String[] args) {
        int n=5;
        int number = 1;

        //outer loop 
        for(int i=1; i<=n; i++) {
            //inner loop 
            for(int j=1; j<=i; j++) {
                System.out.print(number+" ");
                number++;//number --> number + 1 
            }
            System.out.println();
        }
        
    }
}
// output
// 1 
// 2 3 
// 4 5 6 
// 7 8 9 10       
// 11 12 13 14 15 
