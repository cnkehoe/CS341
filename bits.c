
/* 
 * CS:APP Data Lab 
 * 
 *<name:Charlotte N. Kehoe userID:cnkehoe >
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 8.0.0.  Version 8.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2014, plus Amendment 1 (published
   2015-05-15).  */
/* We do not support C11 <threads.h>.  */
/* 
 * allEvenBits - return 1 if all even-numbered bits in word set to 1
 *   Examples allEvenBits(0xFFFFFFFE) = 0, allEvenBits(0x55555555) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allEvenBits(int x) {
/*
Implementation takes 9 operations. First line of code is setting all the even
bits in x, then in the return, we check to see if the new number is the same as
x
*/
  int even = (0x55<<24)|(0x55<<16)|(0x55<<8)|0x55;
  return x = ((x & ~even) | even); 
}
/*
 * bitParity - returns 1 if x contains an odd number of 0's
 *   Examples: bitParity(5) = 0, bitParity(7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int bitParity(int x) {
/*
Implementation takes 10 operations. Halfing the number repeatedly with the xor
to keep the parity of it until we get to the last bit. If  x is 1 then return 1, 
else return 0.
*/
   x ^= x >> 16;
   x ^= x >> 8;
   x ^= x >> 4;
   x ^= x >> 2;
   x ^= x >> 1;
   return x & 1;
 
}
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
/*
Implementation is 7 operations. Applying De Morgan's law to rewrite the expression
and get rid of the operator.
*/
  return ~(~x & ~y) & ~(x & y);
}
/* 
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2 
 */
int leastBitPos(int x) {
/*
Implementation is 3 operations. We take 1's complement of x and add one to that
so it carries over until it reaches where the bit of x initally is 1, after which 
this result is equal to 1's complement of x, so the only bit where x and 1's complement 
+ 1 have as 1 is the least significant 1 bit.
*/
  return x & (~x + 1);
}
/* 
 * replaceByte(x,n,c) - Replace byte n in x with c
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: replaceByte(0x12345678,1,0xab) = 0x1234ab78
 *   You can assume 0 <= n <= 3 and 0 <= c <= 255
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 3
 */
int replaceByte(int x, int n, int c) {
/*
7 operations. Make a mask to grab the byte we want to change, then make a
new representation with the byte we want to put in, then x & the 1's complement
of the mask for the bytes to save and | with the byte to place gives the result
*/
  int mask = (0xFF << (n << 3));
  int byteToPlace = (c << (n << 3));
  int result = ((x & ~mask) | byteToPlace);
  return result;
}
/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {
/*
2 operations. Return the 1's complement of 1 shifted to the left by 31 bits, which gives
us the maximum 2's complement integer: 0x7FFFFFFF
*/
  return ~(1 << 31);
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
/*
12 operations. Check to see if number is negative, if it is, there's an extra bit to
use in n, then shift number the appropriate amount of times to see if there's a remainder
*/
  int negative = !!(x & (1 << 31));
  int mask = ~(negative + ~0);
  x ^= mask;
  x >>= (n + ~0);
  return !x;
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
/*
goes over the max operations because 1 needs to be added to x after shifting in some cases,
otherwise, just arithmetic right shift x by n bits.
*/
    int divPlusOneToX = (x >> 31) & (~!((x & (~x+1)) + (1 << n)) >> 31 + 1);
    x = x >> n;
    return (~divPlusOneToX & x) | (divPlusOneToX & (x + 1));
}
/* 
 * isEqual - return 1 if x == y, and 0 otherwise 
 *   Examples: isEqual(5,5) = 1, isEqual(4,5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int isEqual(int x, int y) {
/*
2 operations. xor'ing the same 2 numbers gives 0, then take the ! of that, which 
gives 1
*/
  return !(x ^ y);
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
/*
5 operations. Doing it this way so the function accounts 
for the 0 case. 
*/
  return !(((1<<31) & x) | !x);
}
/* 
 * subOK - Determine if can compute x-y without overflow
 *   Example: subOK(0x80000000,0x80000000) = 1,
 *            subOK(0x80000000,0x70000000) = 0, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int subOK(int x, int y) {
/*
18 operations. First need to find out if the x, y, and difference between the 2 are negative,
then, if x is positive and y is negative, the negative number can be overflow
and if x is negative and y is positive, the positive result is overflow
*/
  int diff = x + (~y + 1);
  int sizeX = (x >> 31) & 1;
  int sizeY = (y >> 31) & 1;
  int xYDiff = (diff >> 31) & 1;

  int posMinusNeg = !sizeX & sizeY & xYDiff;
  int negMinusPos = sizeX & !sizeY & !xYDiff;

  return !(posMinusNeg | negMinusPos);
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
/*
First invert all of the negative numbers and use a binary search to 
find the log2(n), then add 1 to the result to represent the sign bit.
*/
    //Have to do this because I kept getting EFFING PARSE ERRORS
    int sign, bit0, bit1, bit2, bit4, bit8, bit16;

    sign = x >> 31;
    x = (sign & ~x) | (~sign & x);

    bit16 = !!(x >> 16) << 4;
    x = x >> bit16;

    bit8 = !!(x >> 8) << 3;
    x = x >> bit8;

    bit4 = !!(x >> 4) << 2;
    x = x >> bit4;

    bit2 = !!(x >> 2) << 1;
    x = x >> bit2;

    bit1 = !!(x >> 1);
    x = x >> 1;

    bit0 = x;

    return bit16 + bit8 + bit4 + bit2 + bit1 + bit0 + 1;
}
/* 
 * float_abs - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_abs(unsigned uf) {
/*
First record the value for the upper bound that can be represented (infinity).
If the number is greater than infinity, just return it, otherwise, just remove the sign
bit to get the absolute value
*/
  unsigned bound = 0x7F800000; 
  unsigned result = uf & ((1 << 31) - 1);
  if (result > bound)
  {
    return uf;
  }
  else
  {
    return result;
  }
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
/*
Divide the unsigned int into a fraction and exponent bit. Set fraction and exponent appropriately
for NaN/Infinity, and de normalized representation, then return the sign bit, exponent, and fraction
for 2*uf
*/
  int exp = (uf & 0x7F800000) >> 23;
  int fraction = (uf & 0x007FFFFF);

  if (exp == 0xFF && fraction >= 0)
  {
    return uf;
  }
  else if (exp == 0)
  {
     fraction = fraction << 1;
   
     if (fraction & (1 << 23))
     {
       exp = 1;
     }
     fraction = fraction & 0x7FFFFF;
  }
  else if (exp == 0xFE)
  {
    exp = 0xFF;
    fraction = 0;
  }
  else 
  {
    exp = exp + 1;
  }
  
  return (uf & (1 << 31)) | (exp << 23) | fraction;
}
/*
 * trueFiveEighths - multiplies by 5/8 rounding toward 0,
 *  avoiding errors due to overflow
 *  Examples: trueFiveEighths(11) = 6
 *            trueFiveEighths(-9) = -5
 *            trueFiveEighths(0x30000000) = 0x1E000000 (no overflow)
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 4
 */
int trueFiveEighths(int x)
{
/*
Shift int by 3 to the right, which is equivalent to dividing by 8, then create a new num
that holds the bits that were shifted away, then take the num that was divided by 8 and 
multiply it by 5 to get x * 5/8. Then get the bits lost by shifting by multiplying those by 5,
then use a negative sign mask to round toward 0. Add it all together + shift by 3  and you do the Hokey Pokey 
and you turn yourself around
*/ 
    int eight = x >> 3;
    int shiftAway = x & 7;
    int eightFive = (eight << 2) + eight;
    int shiftAway5 = (shiftAway << 2) + shiftAway;
    int signBit = x >> 31 & 7;
    return eightFive + (shiftAway5 + signBit >> 3);
}
