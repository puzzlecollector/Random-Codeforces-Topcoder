// Peking Online Judge Problem 1001. Can be solved using BigDecimal class. 
import java.util.*;  
import java.math.*;  
  
public class Main {  
    public static void main(String args[]) {  
        Scanner cin = new Scanner(System.in);  
        BigDecimal R;  
        int n;  
        String s;  
       
        R = cin.nextBigDecimal();  
        n = cin.nextInt();  
        R = R.pow(n);  
        s = R.stripTrailingZeros().toPlainString();
              
        //if(s.startsWith("0")) s = s.substring(1);
        System.out.println(s);  
    }  
}  
