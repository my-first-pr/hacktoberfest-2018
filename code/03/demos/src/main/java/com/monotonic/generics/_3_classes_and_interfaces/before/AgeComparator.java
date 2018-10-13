package com.monotonic.generics._3_classes_and_interfaces.before;

import java.util.Comparator;

public class AgeComparator implements Comparator<Person>
{
    public int compare(final Person left, final Person right)
    {
        return Integer.compare(left.getAge(), right.getAge());
    }
}
