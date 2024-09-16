
import java.util.*;
import java.math.BigInteger;

public class doesItDivide {
    public static void main(String args[] ) throws Exception {

        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        
        BigInteger[] fact = new BigInteger[100000000];
        
        
        fact[0] = new BigInteger("1");
        for(int i=1; i<10; i++)
        {
            String I = Integer.toString(i);
            fact[i] = fact[i-1].multiply(new BigInteger(I));
        }
        
        BigInteger b = fact[11];
        
        if(b==null)
        System.out.println(""+fact[11]);
        
        while(T-->0)
        {
            int n = sc.nextInt();
            
            String ns = Integer.toString(n);
            String ns2 = Integer.toString(n+1);
            
            BigInteger N = new BigInteger(ns);
            BigInteger N2 = new BigInteger(ns2);
            
            BigInteger S = N.multiply(N2).divide(new BigInteger("2"));
            
            BigInteger p = new BigInteger("1");
            for(int i=1; i<=n; i++)
            {
                String I = Integer.toString(i);
                p = p.multiply(new BigInteger(I));
            }
            
            String ans = (p.mod(S)).equals(new BigInteger("0")) ? "YES": "NO";
            System.out.println(S+" "+p);
            System.out.println(ans);
            
            
        }
        
    }
}
