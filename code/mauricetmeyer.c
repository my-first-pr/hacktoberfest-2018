/**                                                         
 * mauricetmeyer.c              
 *                                 
 * Author: Maurice T. Meyer      
 * E-Mail: maurice@lavireo.com                          
 *                            
 * Date: 01-10-2018
 */


#include <stdio.h>

static char hello_world[] = {
  0x48,
  0x65,
  0x6c,
  0x6c,
  0x6f,
  0x2c,
  0x20,
  0x57,
  0x6f,
  0x72,
  0x6c,
  0x64,
  0x21,
  0xA,
  0x0
};

int
main (void)
{
  char* ptr = hello_world;
  do
  {
    printf("%c", *ptr++);
  } while(*ptr != 0);
  return 0;
}
