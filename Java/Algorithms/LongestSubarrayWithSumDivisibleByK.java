package Algorithms;
//Hashing
import java.util.*;
import java.lang.*;
import java.io.*;

class Comp4 implements Comparator
{
    @Override
    public int compare(Object o1, Object o2)
    {
        Range r1 = (Range) o1;
        Range r2 = (Range) o2;

        if(r1.length < r2.length)
            return 1;

        else if(r1.length > r2.length)
            return -1;

        else
            return 0;

    }
}

class Range
{
    int startInd;
    int endInd;    
    int length;

    Range(int startInd, int endInd)
    {
        this.startInd = startInd;
        this.endInd = endInd;
        this.length = endInd - startInd ;
    }
    
    void Print()
    {
        System.out.println(this.startInd + " " + this.endInd);
        System.out.println("Length : "+this.length);
    }

}


public class LongestSubarrayWithSumDivisibleByK {

    public static HashMap<Integer, Range> H(int[] B, int K)
    {

        int N = B.length;

        HashMap<Integer, Range> h = new HashMap<Integer, Range>();

        int[] C = new int[N+1];

        C[0] = 0;

        for(int i=0; i<N; i++)
        {
            C[i+1] = B[i]%K;
            if(C[i+1]<0)
                C[i+1]+=K;
        }

        //for(int i=0; i<=N; i++)
            //System.out.println(C[i]);

        for(int i=0; i<C.length; i++)
        {
            if(h.containsKey(C[i]))
            {
                int startInd = h.get(C[i]).startInd;
                Range r = new Range(startInd, i);
                h.replace(C[i], r);
            }

            else
            {
                h.put(C[i], new Range(i,i));
            }
        }
        
        return h;

    }


    public static int F(int[] A, int K)

    {

        int N = A.length;

        int[] B = new int[N];


        B[0] = A[0];


        for(int i=1; i<N; i++)

            B[i] = A[i] + B[i-1];


        HashMap<Integer, Range> h = H(B,K);
        
        
        ArrayList<Map.Entry<Integer, Range>> al = new ArrayList<Map.Entry<Integer, Range>>(h.entrySet());
        
        for(Map.Entry<Integer, Range> m : al)
            System.out.println(m.getKey()+" "+m.getValue().startInd+":"+m.getValue().endInd);
        
        
        LinkedList<Range> l = new LinkedList<Range>(h.values());
        
        Collections.sort(l, new Comp4());
        
        /*
        for(Range r: l)
            r.Print();
        */
        
        return l.get(0).length;

    }

    public static void main (String[] args) 

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

            

            int ans = F(A,K);
            System.out.println(ans);

        }

    }

}

    