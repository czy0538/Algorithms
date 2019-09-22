import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

import java.util.Arrays;

public class BinarySearch
{
    public static int rank(int key, int[] a)
    {
        int lo = 0;//左边界
        int hi = a.length - 1;//右边界
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;//位移到中间
            if (key < a[mid])
            {
                hi = mid - 1;
            } else if (key > a[mid])
            {
                lo = mid + 1;
            } else return mid;
        }
        return -1;
    }

    public static void main(String[] args)
    {
        int[] whitelist = new int[10];
        for (int i = 0; i < 10; i++)
        {
            whitelist[i] = (int) (Math.random() * 100);
        }
        StdOut.println(Arrays.toString(whitelist));
        Arrays.sort(whitelist);
        StdOut.println(Arrays.toString(whitelist));
        while (!StdIn.isEmpty())
        {
            int key = StdIn.readInt();
            if (rank(key, whitelist) < 0)
            {
                StdOut.println(key);
            } else
            {
                StdOut.println("找到啦" + rank(key, whitelist));
            }
        }
    }
}