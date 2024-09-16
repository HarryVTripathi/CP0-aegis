
package dsaa;

import java.util.Arrays;
import java.util.PriorityQueue;

public class pq {

    public static void main(String[] args) 
    {
        int[] a = {2,827,982,25,29,57,18,6,98};
        
        PriorityQueue q = new PriorityQueue();
        
        for(int i=0; i<a.length; i++)
            q.add(a[i]);
        
        System.out.println(q);
    }
    
}
