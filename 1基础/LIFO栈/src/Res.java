import edu.princeton.cs.algs4.StdOut;

import java.util.Iterator;

public class Res<Item> implements Iterable<Item>
{
    private Item[] a = (Item[]) new Object[1];
    private int N = 0;

    public boolean isEmpty()
    {
        return N == 0;
    }

    public int size()
    {
        return N;
    }

    public void push(Item item)
    {
        if (N == a.length)
        {
            resize(2 * a.length);
        }
        a[N++]=item;
    }

    public Item pop()
    {
        Item item = a[--N];
        a[N] = null;//调用GC机制防止出现孤儿
        if (N > 0 && N == a.length / 4)
        {
            resize(a.length / 2);
        }
        return item;
    }

    private void resize(int max)
    {
        Item[] temp = (Item[]) new Object[max];
        for (int i = 0; i < a.length; i++)
        {
            temp[i]=a[i];
        }

            a = temp;
    }

    @Override//重写迭代器
    public Iterator<Item> iterator()
    {
        return new ResIterator();
    }

    private class ResIterator implements Iterator<Item>
    {
        private int i = N;

        @Override
        public boolean hasNext()
        {
            return i > 0;
        }

        @Override
        public Item next()
        {
            return a[--i];
        }

        @Override
        public void remove()
        {

        }

    }


}
