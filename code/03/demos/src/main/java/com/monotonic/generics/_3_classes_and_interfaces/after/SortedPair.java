package com.monotonic.generics._3_classes_and_interfaces.after;

public class SortedPair<T extends Comparable<T>>
{
    private final T first;
    private final T second;

    public SortedPair(final T left, final T right)
    {
        if (left.compareTo(right) < 0)
        {
            this.first = left;
            this.second = right;
        }
        else
        {
            first = right;
            second = left;
        }
    }

    public T getSecond()
    {
        return second;
    }

    public T getFirst()
    {
        return first;
    }

    @Override
    public String toString()
    {
        return "SortedPair{" +
            "first=" + first +
            ", second=" + second +
            '}';
    }
}
