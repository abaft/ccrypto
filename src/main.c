#include <time.h>
#include "bignum.h"

bignum_gen_uint(mint, 500);

int main()
{
  mint x,y,z;
  bignum_mint_printValue(x);
  printf("\n");
  bignum_mint_printValue(y);
  printf("\n");
  bignum_mint_printValue(x);
}
