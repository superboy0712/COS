/*
 o---------------------------------------------------------------------o
 |
 | COS example01 -- main
 |
 o---------------------------------------------------------------------o
 |
 | C Object System
 |
 | Copyright (c) 2006+ Laurent Deniau, laurent.deniau@cern.ch
 |
 | For more information, see:
 | http://cern.ch/laurent.deniau/cos.html
 |
 o---------------------------------------------------------------------o
 |
 | This file is part of the C Object System framework.
 |
 | The C Object System is free software; you can redistribute it and/or
 | modify it under the terms of the GNU Lesser General Public License
 | as published by the Free Software Foundation; either version 3 of
 | the License, or (at your option) any later version.
 |
 | The C Object System is distributed in the hope that it will be
 | useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 | of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 |
 | See <http://www.gnu.org/licenses> for more details.
 |
 o---------------------------------------------------------------------o
 |
 | $Id: main.c,v 1.1 2009/08/03 21:20:39 ldeniau Exp $
 |
*/

#include <cos/Number.h>
#include <cos/Functor.h>

#include <cos/gen/value.h>
#include <cos/gen/object.h>
#include <cos/gen/functor.h>
#include <cos/gen/operator.h>
#include <cos/gen/container.h>
#include <cos/gen/algorithm.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

useclass(AutoRelease);

/*
-- ghc -O2 sum.hs -o sum
-- ./sum +RTS -K20000000

import Data.List

f = foldl' (.) id $ replicate 1000000 (+1)
main = putStrLn $ show $ f 0
*/

static void
sum_rep(I32 n)
{
  printf("*** functional sum (repeat + eval)\n");

  OBJ pool = gnew(AutoRelease);
  OBJ inc  = gautoDelete(aFunctor(gaddTo,0,aInt(1)));
  F64 t0   = clock();
  OBJ xs   = gcompose(grepeat(inc,aInt(n)));
  F64 t1   = clock();
  I32 x    = gint(geval1(xs,aInt(0)));
  F64 t2   = clock();
             grelease(pool);
  F64 t3   = clock();

  printf("count [n] = %d [%d]\n" , x, n); 
  printf("time init = %.2f sec\n", (t1-t0)/CLOCKS_PER_SEC); 
  printf("time eval = %.2f sec\n", (t2-t1)/CLOCKS_PER_SEC); 
  printf("time fini = %.2f sec\n", (t3-t2)/CLOCKS_PER_SEC); 
  printf("time all  = %.2f sec\n", (t3-t0)/CLOCKS_PER_SEC); 
}

static void
sum_itr(I32 n)
{
  printf("*** functional sum (iterate + eval)\n");

  OBJ pool = gnew(AutoRelease);
  OBJ inc  = gautoDelete(aFunctor(gaddTo,0,aInt(1)));
  F64 t0   = clock();
  OBJ xs   = giterate(inc,aInt(n));
  F64 t1   = clock();
  I32 x    = gint(geval1(xs,aInt(0)));
  F64 t2   = clock();
             grelease(pool);
  F64 t3   = clock();

  printf("count [n] = %d [%d]\n" , x, n); 
  printf("time init = %.2f sec\n", (t1-t0)/CLOCKS_PER_SEC); 
  printf("time eval = %.2f sec\n", (t2-t1)/CLOCKS_PER_SEC); 
  printf("time fini = %.2f sec\n", (t3-t2)/CLOCKS_PER_SEC); 
  printf("time all  = %.2f sec\n", (t3-t0)/CLOCKS_PER_SEC); 
}

static void
sum_oop(I32 n)
{
  printf("*** object-oriented sum (repeat + foldl)\n"); 

  OBJ pool = gnew(AutoRelease);
  OBJ ini  = gautoDelete(aInt(1));
  F64 t0   = clock();
  OBJ xs   = grepeat(ini,aInt(n));
  F64 t1   = clock();
  I32 x    = gint(gfoldl(xs,aFunctor(gaddTo,0,0),aInt(0)));
  F64 t2   = clock();
             grelease(pool);
  F64 t3   = clock();

  printf("count [n] = %d [%d]\n" , x, n); 
  printf("time init = %.2f sec\n", (t1-t0)/CLOCKS_PER_SEC); 
  printf("time eval = %.2f sec\n", (t2-t1)/CLOCKS_PER_SEC); 
  printf("time fini = %.2f sec\n", (t3-t2)/CLOCKS_PER_SEC); 
  printf("time all  = %.2f sec\n", (t3-t0)/CLOCKS_PER_SEC); 
}

int main(int argc, char *argv[])
{
  I32 n = argc == 2 ? strtol(argv[1],0,0) : 1000000;

  if (n <= 10)
    cos_logmsg_set(COS_LOGMSG_TRACE);

  sum_rep(n);
  sum_itr(n);
  sum_oop(n);

  return EXIT_SUCCESS;
}
