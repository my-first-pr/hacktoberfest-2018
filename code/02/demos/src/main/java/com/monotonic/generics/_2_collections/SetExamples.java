package com.monotonic.generics._2_collections;

import java.util.HashSet;
import java.util.Set;

public class SetExamples
{
    public static void main(String[] args)
    {
        Person donDraper = new Person("Don Draper", 89);
        Person peggyOlson = new Person("Peggy Olson", 65);
        Person bertCooper = new Person("Bert Cooper", 100);

        Set<Person> madMen = new HashSet<>();

        // add elements in the same way as a List
        madMen.add(donDraper);
        madMen.add(peggyOlson);
        System.out.println(madMen);

        System.out.println("Don is in the set? " + madMen.contains(donDraper));
        System.out.println("Bert is in the set? " + madMen.contains(bertCooper));

        // Only stores unique members
        madMen.add(donDraper);
        System.out.println(madMen);
        System.out.println(madMen.size());

        // NB: Hashcode/Equals

        // Other collections API stuff applies
        for (Person person : madMen)
        {
            System.out.println(person);
        }

        // No order
        // madMen.get(0)
    }
}
