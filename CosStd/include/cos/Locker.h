#ifndef COS_LOCKER_H
#define COS_LOCKER_H

/*
 o---------------------------------------------------------------------o
 |
 | COS Locker (proxy)
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
 | $Id: Locker.h,v 1.1 2008/09/28 19:56:26 ldeniau Exp $
 |
*/

#include <cos/Proxy.h>
#include <cos/sys/thread.h>

defclass(Locker,Proxy)
  cos_thread_smutex(lock);
endclass

#endif // COS_LOCKER_H
