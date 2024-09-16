
import java.util.*;

/**
 *
 * @author Harry
 */
public class gp {

    public static void main(String[] args) 
    {
        
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int count=0;
        HashMap<Character, Integer> h = new HashMap<Character, Integer>();
        
       for(int i=0; i<s.length(); i++)
       {
           char a = s.charAt(i);
           
           if(h.containsKey(a))
           {
               int v = h.get(a);
               v++;
               h.replace(a, v);
           }
           
           else
               h.put(a, 1);
       }
       
       System.out.println(h);
    }
    
}
