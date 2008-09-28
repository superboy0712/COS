/*
 o---------------------------------------------------------------------o
 |
 | COS Object (root class)
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
 | $Id: Object.c,v 1.6 2008/09/28 19:51:51 ldeniau Exp $
 |
*/

#include <cos/Object.h>
#include <cos/gen/object.h>

#include <stdlib.h>
#include "object.h"

// -----

makclass(Object,Any);

// ----- allocator, deallocator

defmethod(OBJ, galloc, mObject)
  retmethod( object_alloc(_1, 0) );
endmethod

defmethod(OBJ, gallocWithSize, mObject, (size_t)extra)
  retmethod( object_alloc(_1, extra) );
endmethod

