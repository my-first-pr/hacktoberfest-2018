extern crate rand;

use rand::prelude::*;

fn main() {
    let mut obv = 0;
    let mut rev = 0;
    let mut i = 0;

   while i < 10 {
    if random() {
       obv += 1;
    } else {
       rev += 1;
    }
    i += 1;
   }

   if obv > rev {
    println!("Obverse wins!")
   } else {
    println!("Reverse wins!")
   }

   println!("Get info about coin history at https://en.wikipedia.org/wiki/Obverse_and_reverse")
}