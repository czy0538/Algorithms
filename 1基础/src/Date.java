public class Date implements Datable
{
    private final int month;
    private final int day;
    private final int year;

    public Date(int month, int day, int year)
    {
        this.month = month;
        this.day = day;
        this.year = year;
    }

    @Override
    public int month()
    {
        return month;
    }

    @Override
    public int day()
    {
        return day;
    }

    @Override
    public int year()
    {
        return year;
    }

    @Override
    public String toString()
    {
        return month() + "/" + day() + "/" + year();
    }

    @Override
    public boolean equals(Object obj)
    {
        if (this == obj)
        {
            return true;
        }
        if (obj == null)
        {
            return false;
        }
        if (this.getClass() != obj.getClass())
        {
            return false;
        }
        Date that = (Date) obj;
        if (this.day != that.day)
        {
            return false;
        }
        if (this.month != that.month)
        {
            return false;
        }
        if (this.year != that.year)
        {
            return false;
        }
        return true;
    }
}
