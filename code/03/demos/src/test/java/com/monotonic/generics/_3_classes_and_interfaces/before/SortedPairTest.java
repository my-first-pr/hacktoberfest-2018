package com.monotonic.generics._3_classes_and_interfaces.before;

import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class SortedPairTest
{
    @Test
    public void shouldRetainOrderOfOrderedPair()
    {
        SortedPair<Integer> pair = new SortedPair<>(1, 2);

        assertEquals(1, pair.getFirst().intValue());
        assertEquals(2, pair.getSecond().intValue());
    }

    @Test
    public void shouldFlipOrderOfMisorderedPair()
    {
        SortedPair<Integer> pair = new SortedPair<>(2, 1);

        assertEquals(1, pair.getFirst().intValue());
        assertEquals(2, pair.getSecond().intValue());
    }

}
