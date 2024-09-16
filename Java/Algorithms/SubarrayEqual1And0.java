package Algorithms;

//https://practice.geeksforgeeks.org/problems/count-subarrays-with-equal-number-of-1s-and-0s/0
//

import java.util.*;
import java.lang.*;
import java.io.*;

public class SubarrayEqual1And0 {
    
    public static HashMap<Integer, Integer> H(int[]B, int N)
    {
        HashMap<Integer, Integer> h = new HashMap<Integer, Integer>();
        for(int i=0; i<N; i++)
        {
            if(h.containsKey(B[i]))
            {
                int neW = h.get(B[i])+1;
                h.replace(B[i],neW);
            }
            else
                h.put(B[i],1);
        }
        
        return h;
    }
    
    public static int C(HashMap<Integer, Integer> h)
    {
        int ans = 0;
        ArrayList<Integer> al = new ArrayList<Integer>(h.values());
        for(int i=0; i<al.size(); i++)
        {
            int val = al.get(i);
            
            if(al.get(i)==2)
                ans = ans+1;
            
            else if(al.get(i)>2)
                ans = ans + ((val*(val-1))/2);
                
            else
                ans = ans + 0;
        }
        
        return ans;
    }
    
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        while(T-->0)
        {
            int N = sc.nextInt();
            int[] A = new int[N];
            int[] B = new int[N+1];
            HashMap<Integer, Integer> h = new HashMap<Integer, Integer>();

            B[0] = 0;
            for(int i=0; i<N; i++)
            {
                A[i] = sc.nextInt();

                if(A[i]==0)
                    B[i+1] = B[i]-1;

                else
                    B[i+1] = B[i]+1;
            }

            h = H(B,N+1);

            int ans = C(h);

        System.out.println(ans);
        }

    }
}