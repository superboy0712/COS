#ifndef COS_CARRAY_H
#define COS_CARRAY_H

/*
 o---------------------------------------------------------------------o
 |
 | COS C Array, C array utils
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
 | $Id: carray.h,v 1.3 2009/09/14 13:35:13 ldeniau Exp $
 |
*/

#include <cos/Object.h>

#include <stdlib.h>

/* NOTE-INFO: low level temporary C array
   the array is allocated on the stack if its size <= TMPARRAY_LIMIT
   otherwise it is allocated on the heap.

   {
     TMPARRAY_CREATE(OBJ, buf, 1000);

     buf[100] = gnew(Object);
     grelease(buf[100]);

     TMPARRAY_DESTROY(buf);
   }
*/

#define TMPARRAY_LIMIT (1024 * sizeof(void*))

#define TMPARRAY_CREATE(T,name,nelem) \
        TMPARRAY_CREATE_(T,name,nelem, \
    /* local pointer */  COS_PP_CAT(_cos_tmp_array_p_,name), \
    /* local array   */  COS_PP_CAT(_cos_tmp_array_a_,name), \
    /* local size    */  COS_PP_CAT(_cos_tmp_array_s_,name))

#define TMPARRAY_CREATE_(T,name,N,P,A,S) \
  U32 S = N; T *P, \
    A[S*sizeof(T) <= TMPARRAY_LIMIT ? S : 0]; \
  if (S*sizeof(T) <= TMPARRAY_LIMIT) P = A; \
  else { \
    useclass(ExBadAlloc); \
    if ( !(P = malloc(S * sizeof(T))) ) THROW(ExBadAlloc); \
  } \
  T *const name = P

#define TMPARRAY_DESTROY(name) \
  if (name != COS_PP_CAT(_cos_tmp_array_a_,name)) \
    free(name)

#endif // COS_CARRAY_H
