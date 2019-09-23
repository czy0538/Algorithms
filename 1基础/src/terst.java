import edu.princeton.cs.algs4.StdOut;

import java.util.Arrays;

public class terst
{
    public double average(double ...x)
    {
        int count =x.length;
        double aver=0;
        Arrays.sort(x);
        StdOut.println(Arrays.toString(x));
        double sum=0;
        for(int i=1;i<x.length-1;i++)
        {
            sum+=x[i];
        }
        return sum/(x.length-2);
    }
    public static void main(String [] args)
    {
        terst t=new terst();
        StdOut.println( t .average(0,8.8,1.1,2.2,3.3,4.4));

    }
}