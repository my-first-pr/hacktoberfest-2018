package com.monotonic.generics._3_classes_and_interfaces.before;

import java.util.Comparator;

public class ReverseComparator<T> implements Comparator<T>
{
    private final Comparator<T> delegateComparator;

    public ReverseComparator(final Comparator<T> delegateComparator)
    {
        this.delegateComparator = delegateComparator;
    }

    public int compare(final T left, final T right)
    {
        return -1 * delegateComparator.compare(left, right);
    }
}
