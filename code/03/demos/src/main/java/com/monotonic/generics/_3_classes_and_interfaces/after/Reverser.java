package com.monotonic.generics._3_classes_and_interfaces.after;

import java.util.Comparator;

public class Reverser<T> implements Comparator<T>
{
    private final Comparator<T> comparator;

    public Reverser(Comparator<T> comparator)
    {
        this.comparator = comparator;
    }

    @Override
    public int compare(T left, T right)
    {
        return comparator.compare(right, left);
    }
}
