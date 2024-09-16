package Algorithms;


//https://practice.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1
import java.io.*;
import java.util.*;
import java.lang.*;

public class DistinctElementsWindow
{
    public static void countDistinct(int[] A, int K, int N)
    {
        for(int i=0; i<=N-K; i++)
        {
            HashSet<Integer> h;
            h = new HashSet();
            int offset = 0;
            while(offset < K)
            {
                h.add(A[i+offset]);
                offset++;
            }
            System.out.print(h.size()+" ");
        }
        
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while(T-->0)
        {
            int N = sc.nextInt();
            int K = sc.nextInt();

            int[] A = new int[N];

            for(int i=0; i<N; i++)
                A[i] = sc.nextInt();

            countDistinct(A,K,N);
        }
    }
}