import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;
import java.util.Stack;
/*
将操作数压入操作数栈
将运算符压入运算符栈
忽略左括号
当遇到右括号的时候弹出第一个运算符，弹出所需要数量的操作数，并将运算结果压入操作数栈
*/

public class Evaluate
{
    Stack<String> ops = new Stack<String>();
    Stack<Double> vals = new Stack<Double>();
    //Scanner input=new Scanner(System.in);
    Evaluate()
    {
        while(!StdIn.isEmpty())
        {
            String s = StdIn.readString();
            if (s.equals("("))
            {
                ;
            }
            else if (s.equals("+") || s.equals("-") || s.equals("*") || s.equals("/") || s.equals("sqrt"))
            {
                ops.push(s);
            }
            else if (s.equals(")"))
            {
                String op = ops.pop();
                double v = vals.pop();
                if (op.equals("+"))
                {
                    v = vals.pop() + v;
                }
                else if (op.equals("-"))
                {
                    v = vals.pop() - v;
                }
                else if (op.equals("*"))
                {
                    v = vals.pop() * v;
                }
                else if (op.equals("/"))
                {
                    v = vals.pop() / v;
                }
                else if (op.equals("+"))
                {
                    v = Math.sqrt(v);
                }
                vals.push(v);
            }
            else vals.push(Double.parseDouble(s));
        }

        StdOut.println(vals.pop());
    }
    public static void main(String[] args)
    {
        Evaluate eva=new Evaluate();

    }
}
