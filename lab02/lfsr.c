#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "lfsr.h"

unsigned get_bit(unsigned x,
                 unsigned n) {
    // YOUR CODE HERE
    // Returning -1 is a placeholder (it makes
    // no sense, because get_bit only returns 
    // 0 or 1)
    x=x>>n;
    return x&1;
}
// Set the nth bit of the value of x to v.
// Assume 0 <= n <= 31, and v is 0 or 1
void set_bit(unsigned * x,
             unsigned n,
             unsigned v) {
    // YOUR CODE HERE
    if(v==1){
        v=v<<n;
        *x=*x|v;
    }else{
        v=1;
        v=v<<n;
        v=~v;
        *x=*x&v;
    }
}
// Flip the nth bit of the value of x.
// Assume 0 <= n <= 31
void flip_bit(unsigned * x,
              unsigned n) {
    // YOUR CODE HERE
    int v=1;
    v=v<<n;
    *x=*x^v;
}
void lfsr_calculate(uint16_t *reg) {
    /* YOUR CODE HERE */
    unsigned p0=get_bit(*reg,0);
    unsigned p2=get_bit(*reg,2);
    unsigned p3=get_bit(*reg,3);
    unsigned p5=get_bit(*reg,5);
    *reg=*reg>>1;
    unsigned p15=((p0^p2)^p3)^p5;
    set_bit(reg,15,p15);
}

