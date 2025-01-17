/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
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
/* Copyright (C) 1991-2023 Free Software Foundation, Inc.
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
   <https://www.gnu.org/licenses/>.  */
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
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
  /*Using Morgan's Laws*/
  return ~(~x | ~y);
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
  /*(n<<3)=n*8 since each byte is 8bits, then shift in x this amount of bites (x>>(n<<3)), finally isolate the least significant byte (& 0xFF)*/
  return (x>>(n<<3) & 0xFF);
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
  /*(x>>n) makes the logical shift, and the mask is an implementation to clear leftmost n bits*/
  int mask = ~(((1 << 31) >> n) << 1);
  return (x >> n) & mask;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
  /*firs are created 3 masks, mask1 with alternated bits, mask 2 with couple 
  alternated bit and mask 3 with tuple alternated bits, than are created masks 
  patterns by operation or with masks and themselves shifted by nbits, for example,
  mask1 = 01010101, mask1 | (mask1 << 8) = 101010101010101, with operator AND (&)
  x is counted by 2-2, 4-4 and 8-8 bits, and all is concatenated, finally bits above
  64 are hided, since an int has 8 bytes or 64 bits*/
  int mask1 = 0x55; // 01010101
  int mask2 = 0x33; // 00110011
  int mask3 = 0x0F; // 00001111

  mask1 = mask1 | (mask1 << 8);
  mask1 = mask1 | (mask1 << 16);

  mask2 = mask2 | (mask2 << 8);
  mask2 = mask2 | (mask2 << 16); 

  mask3 = mask3 | (mask3 << 8);
  mask3 = mask3 | (mask3 << 16);

  x = (x & mask1) + ((x >> 1) & mask1); 
  x = (x & mask2) + ((x >> 2) & mask2); 
  x = (x & mask3) + ((x >> 4) & mask3); 
  x = x + (x >> 8); 
  x = x + (x >> 16); 
  return x & 0x3F; 
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
  /*with mask1 he get 1 if the bit is set and 0 otherwise, mask2 shift for the rightmost bit, than 1 is added to the result*/
  int mask1 = x | (~x + 1);
  int mask2 = mask1 >> 31;
  return mask2 + 1;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  /*shifting 1 31 times the others bits are all 0s*/
  return 1<<31;
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
  /*shift calculate the number of bits to shift, than by "shaking" x,  bits that
  cant be represented are discarded, finally checks if x and shifted are the same.*/
  int shift = 32 + (~n + 1); 
  int shifted = (x << shift) >> shift;
  return !(x ^ shifted);
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
  /*first reads the first bit to see the sing, than create a bias than negative 
  numbers get the right round, finally makes the operation*/
  int sign = (x >> 31) & 1;
  int bias = (sign << n) - sign; 
  return (x + bias) >> n;     
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  /*two's complement negation*/
  return ~x+1;
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
  /*shift sing bit to least significant bit, that gives
  -1 for negatives and 0 for positives, than combines 
  with !x so if x=0 it will also return 1*/
  return !((x>>31) | !x);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  /*shifts sing to lest significant bit, makes it AND 1 isolating it,
  get the sing of the difference, y-x our y+-C2(x), first compare the sings 
  of x and y, with OR operator compares with the case that y and x has the same 
  sign.*/
  int sign_x = (x >> 31) & 1;  
  int sign_y = (y >> 31) & 1;  
  int sign_diff = ((y + (~x + 1)) >> 31) & 1;  

  return (sign_x & !sign_y) | (!(sign_x ^ sign_y) & !sign_diff);
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
  /*result is initialized as 0, x is shifted by 2^4 and if it is non zero result gets 
  one shifted by 4 otherwise 0, the same to 3, 2, 1 and 0, adding the results*/
  int result = 0;

  result = (!!(x >> 16)) << 4;
  result = result + ((!!(x >> (result + 8))) << 3);
  result = result + ((!!(x >> (result + 4))) << 2);
  result = result + ((!!(x >> (result + 2))) << 1);
  result = result + (!!(x >> (result + 1)));

  return result;

}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
  /*sign_mask is the sign to -f, than compare if uf is higher than possible value
  for float, in that case, NaN, if it is, return itself, else, the sign is flipped*/
  
  unsigned sign_mask = 0x80000000;

  if ((uf & 0x7FFFFFFF) > 0x7F800000) {
      return uf;
  }

  return uf ^ sign_mask;
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
  /**/
  if (x==0)  return 0;
  unsigned s = x>>31;
  x = x<0 ? -x : x;
  unsigned E = ilog2(x);
  unsigned exp = E + 127;
  unsigned frac = x ^ (1<<E);
      
  if (E>=23)  frac >>= E-23;
  else  frac <<= 23-E;
  
  return s<<31 | exp<<23 | frac;
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
  /*with help of masks, uf is dismembered in sign (1 bit), exponent (8 bits) and 
  fraction (23 bits), if this exponent is to big, it's NaN, and immediately returned,
  else, if exponent is zero,fraction is shifted with 1 added to the end, with 
  means fraction*2, base gets 1, fraction is normalized and number is returned, 
  else, exponent is acresed by 1, with means f*2, if exponent got the higher value 
  function gets 0, and the number is returned, else, the number is returned.*/
  unsigned sign_mask = 0x80000000;  
  unsigned exponent_mask = 0x7F800000; 
  unsigned fraction_mask = 0x007FFFFF; 

  unsigned sign = uf & sign_mask;
  unsigned exponent = uf & exponent_mask;
  unsigned fraction = uf & fraction_mask;

  if (exponent == 0x7F800000) {
    return uf;
  }

  if (exponent == 0) {
    fraction <<= 1;
    if (fraction & 0x800000) {
      exponent = 0x00800000;
      fraction &= fraction_mask;
    }
  }else {
    exponent += 0x00800000;
    if (exponent == 0x7F800000) {
      fraction = 0;
    }
  }
  return sign | exponent | fraction;
}
