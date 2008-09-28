#ifndef COS_GEN_VALUE_H
#define COS_GEN_VALUE_H

/*
 o---------------------------------------------------------------------o
 |
 | COS value generics (C types)
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
 | $Id: value.h,v 1.5 2008/09/28 19:48:21 ldeniau Exp $
 |
*/

#ifndef COS_OBJECT_H
#error "COS: missing #include <cos/Object.h>"
#endif

defgeneric(STR  , gstr , _1);
defgeneric(U32  , gsize, _1);
defgeneric(void*, gptr, _1);
defgeneric(FUNC , gfct, _1);

defgeneric(I8   , gchr, _1);
defgeneric(I16  , gsht, _1);
defgeneric(I32  , gint, _1);
defgeneric(I64  , glng, _1);
defgeneric(R64  , gdbl, _1);
defgeneric(C64  , gcpx, _1);

defgeneric(I8*  , gchrPtr, _1);
defgeneric(I16* , gshtPtr, _1);
defgeneric(I32* , gintPtr, _1);
defgeneric(I64* , glngPtr, _1);
defgeneric(R64* , gdblPtr, _1);
defgeneric(C64* , gcpxPtr, _1);

#endif // COS_GEN_VALUE_H
