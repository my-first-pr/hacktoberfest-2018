#!/usr/bin/perl -w
use strict;
use warnings;
 
############################################################
### Usage: simcache.pl n_blocks n_blocksPerSet(associativity) n_wordsPerBlock TracerFile
### ex : simcache.pl 128 1 4 trace1.txt
### output: n_access n_missRate n_substitutions
### ex : 300 20 35
###
### Celso A. Uliana Junior - Aug 2016
############################################################
 
die "Usage: simcache.pl n_blocks n_blocksPerSet(associativity) n_wordsPerBlock TracerFile\n " if ( @ARGV != 4 );
 
 
my $n_set = ( my $blocks = shift) / ( my $assoc = shift); 
my $n_words = shift; 
my $tracerfile = shift;
my %cs;
my $i = 0, my $j = 0;
my $n_access, my $n_miss, my $n_substitutions, my $n_missRate;
my $n_log_words = log($n_words)/log(2); 
 
############################################################
# If tracerfile is not .txt adds .txt to the string
############################################################
 
if($tracerfile !~ /^\w+\.(doc|txt)$/){
    $tracerfile = $tracerfile . ".txt";
}
 
############################################################
# Reading tracer file
############################################################
 
open TRC , "$tracerfile" or die "Couldn't open the file $tracerfile\n" ;
 
 
 
my $test = 0 ;
my $test2 = 0 ;
my $test3 = 0 ;
 
my $hit = 0 ;
while( <TRC> ){
    chomp ;
    if( $n_set == $blocks ){
        if( $cs{int(($_ / 4) % $n_set)}[0] ){   
                $test = int(($_ / 4) % $n_set);
                $test2 = int( ($_ / 4) / $n_set );
                $test3 = $cs{int(($_ / 4) % $n_set)}[2] ;
                print "indice = $test // tag esperada = $test2 // tag no hash = $test3 \n";
            if( $cs{int(($_ / 4) % $n_set)}[2] != int( ($_ / 4) / $n_set ) ){
                $n_miss++; 
                $n_substitutions++; 
                $cs{(int($_ / 4) % $n_set)}[2] = int( ($_ / 4) / $n_set );
            }
            else{
                $hit++;
            }
        }
        else{
            $cs{int(($_ / 4) % $n_set)}[0] = 1;
            $n_miss++ ;
            $cs{int(($_ / 4) % $n_set)}[2] = int( ($_ / 4) / $n_set);
             
        }
    }

    $n_access++; 
}
 
print "hits = $hit // misses = $n_miss\n"; 
close TRC;

############################################################
# Print the n_acess n_missrate n_substitutions
############################################################
 
printf  ("%d %d %d \n", $n_access, (($n_miss / $n_access) * 100), $n_substitutions);   
 
exit(0);
############################################################