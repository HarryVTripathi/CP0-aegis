//https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/0
//NotDoneYet

package Algorithms;

import java.util.*;
import java.lang.*;
import java.io.*;

 public class MaxAllSubarrays {
    public static void main (String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        while(T-->0)
        {
            int N = sc.nextInt();
        int K = sc.nextInt();
        int max = Integer.MIN_VALUE;
            int[] A = new int[N];
            Deque<Integer> q = new LinkedList<Integer>();

            for(int i=0; i<N; i++)
            {
                A[i] = sc.nextInt();

                if(i<K)
                {
                    if(A[i]>max)
                    {
                        q.addFirst(max);
                        max = A[i];
                    }

                    else if(A[i]<max && A[i]>q.peek())
                        q.addFirst(A[i]);

                    else;
                }
            }

            int i=0, j=K-1;
            while(i<N-K)
            {
                System.out.print(max+" ");

                if(A[i]==max)
                {
                    if(!q.isEmpty())
                    max = q.poll();
                }

                else if(!q.isEmpty())
                {
                    if(A[i]==q.peek())
                    q.pollFirst();
                }

                else;

                i++; j++;

                if(A[j]>max)
                    max = A[j];

                else if(A[j]<max && !q.isEmpty())
                {
                    if(A[j]>q.peek())
                        q.addFirst(A[j]);
                    
                }

                else;

            }
            System.out.println(max+"");
        }
    }
}