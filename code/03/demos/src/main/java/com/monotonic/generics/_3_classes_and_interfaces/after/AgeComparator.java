package com.monotonic.generics._3_classes_and_interfaces.after;

import java.util.Comparator;

public class AgeComparator implements Comparator<Person>
{
    @Override
    public int compare(Person left, Person right)
    {
        return Integer.compare(left.getAge(), right.getAge());
    }
}
