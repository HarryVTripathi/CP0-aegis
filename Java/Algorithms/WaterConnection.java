//https://practice.geeksforgeeks.org/problems/water-connection-problem/0

package Algorithms;

import java.util.*;

class House
{
    int val;
    House prev;
    House next;
    
    House(int val)
    {
        this.val = val;
        this.prev = null;
        this.next = null;
    }
}

public class WaterConnection {
    
    public static int endPoint(HashMap<Integer, House> h, int i)
    {
        //System.out.println(i);
        if(h.get(i).next != null)
        {
            mindis = Math.min(mindis, d[i][h.get(i).next.val]);
            return endPoint(h, h.get(i).next.val);
        }
        else
            return i;
    }
    
    public static int mindis;
    public static int[][] d;
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        
        while(T-->0)
        {
            int N = sc.nextInt();
            int P = sc.nextInt();
            d = new int[N+1][N+1];
            HashMap<Integer, House> h = new HashMap<Integer, House>();
            ArrayList<String> al = new ArrayList<String>();
            
            for(int i=0; i<=N; i++)
                for(int j=0; j<=N; j++)
                    d[i][j] = Integer.MAX_VALUE;
            
            for(int i=0; i<P; i++)
            {
                int from = sc.nextInt();
                int to = sc.nextInt();
                d[from][to] = sc.nextInt();
                
                House h1;
                House h2;
                
                if(!h.containsKey(from))
                {
                    h1 = new House(from);
                    h.put(from, h1);
                }
                
                else
                    h1 = h.get(from);
                
                if(!h.containsKey(to))
                {
                    h2 = new House(to);
                    h.put(to, h2);
                }
                
                else
                    h2 = h.get(to);
                
                h1.next = h2;
                h2.prev = h1;
            }
            
            for(int i=1; i<=N; i++)
            {
                if(h.containsKey(i))
                {
                    if(h.get(i).prev==null)
                    {
                        mindis = Integer.MAX_VALUE;
                        int ans = endPoint(h,i);
                        al.add(i+" "+ans+" "+mindis);
                    }
                }
            }
            
            System.out.println(al.size());
            
            for(String s: al)
                System.out.println(s);
        }
    }
    
}
