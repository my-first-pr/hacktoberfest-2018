#!/usr/bin/perl
scalar getpwuid($<) ? print "Hello ". scalar getpwuid($<) ."\n" : "Hello World\n";