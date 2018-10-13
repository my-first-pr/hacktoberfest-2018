package com.monotonic.generics._3_classes_and_interfaces.before;

public class SortedPair<T extends Comparable<T>>
{
    private final T first;
    private final T second;

    public SortedPair(T left, T right)
    {
        if (left.compareTo(right) < 0)
        {
            first = left;
            second = right;
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
}
