#ifndef __BIGNUM_H_
#define __BIGNUM_H_
#include <stdio.h>
#include <stdlib.h>

#define bignum_gen_uint(typeName, size)\
typedef struct\
{\
  char byte[ (size)%8 == 0 ? (size)/8 : (size/8) + 1 ];\
} typeName;\
\
char* bignum_ ## typeName ## _printValue (typeName* n)\
{\
  int nu = sizeof(typeName) * 2;\
  char* ptr = n->byte;\
  char rtn[ nu + 10 ];\
  int i, j;\
  for (i = 0, j = nu - 1; i < nu; ++i, --j)\
  {\
    int didget;\
    if (i%2 == 0)\
      didget = 15 & *ptr;\
    else\
      didget = 15 & (*ptr >> 4);\
    switch(didget)\
    {\
      case 0:\
        rtn[j] = '0';\
        break;\
      case 1:\
        rtn[j] = '1';\
        break;\
      case 2:\
        rtn[j] = '2';\
        break;\
      case 3:\
        rtn[j] = '3';\
        break;\
      case 4:\
        rtn[j] = '4';\
        break;\
      case 5:\
        rtn[j] = '5';\
        break;\
      case 6:\
        rtn[j] = '6';\
        break;\
      case 7:\
        rtn[j] = '7';\
        break;\
      case 8:\
        rtn[j] = '8';\
        break;\
      case 9:\
        rtn[j] = '9';\
        break;\
      case 10:\
        rtn[j] = 'A';\
        break;\
      case 11:\
        rtn[j] = 'B';\
        break;\
      case 12:\
        rtn[j] = 'C';\
        break;\
      case 13:\
        rtn[j] = 'D';\
        break;\
      case 14:\
        rtn[j] = 'E';\
        break;\
      case 15:\
        rtn[j] = 'F';\
        break;\
    }\
    if (i%2 == 1) ptr++;\
  }\
  rtn[i] = '\0';\
  printf("%s\n", rtn);\
}\
\
void bignum_ ## typeName ## _rand(typeName* rtn)\
{\
  for (int i = 0; i < size; ++i)\
  {\
    rtn->byte[i/8] |= rand()%2 << i%8;\
  }\
  return;\
}\
char bignum_ ## typeName ## _add(typeName* c,\
    const typeName* a, const typeName* b)\
{\
  char carry = 0;\
  char tmp = 0;\
  for (int i = 0; i < size; ++i)\
  {\
    if (i%8 == 0)\
    {\
      c->byte[i/8] = 0;\
    }\
    c->byte[i/8] |= \
    (((a->byte[i/8] >> i%8) & 1) ^ ((b->byte[i/8] >> i%8) & 1) ^ carry) << i%8;\
        printf("%i  %i  %i  %i\n", \
        ((a->byte[i/8] >> i%8) & 1) ^ ((b->byte[i/8] >> i%8) & 1 ) ^ carry,\
        ((a->byte[i/8] >> i%8) & 1), (b->byte[i/8] >> i%8) & 1, carry);\
    carry = \
    ((a->byte[i/8] >> i%8) & 1) & ((b->byte[i/8] >> i%8) & 1)|\
    (((a->byte[i/8] >> i%8) & 1) ^ ((b->byte[i/8] >> i%8) & 1)) & (carry);\
  }\
  return carry;\
}\
char bignum_ ## typeName ## _cmp(const typeName* a, const typeName* b)\
{\
  for (int i = 0; i < sizeof(typeName); ++i)\
    if (a->byte[i] != b->byte[i]) return 0;\
  return 1;\
}\

#endif
