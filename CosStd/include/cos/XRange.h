#ifndef COS_XRANGE_H
#define COS_XRANGE_H

/**
 * C Object System
 * COS XRange
 *
 * Copyright 2006+ Laurent Deniau <laurent.deniau@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <cos/Number.h>
#include <cos/Sequence.h>

#include <float.h>

/* NOTE-USER: XRanges
  - XRanges defines floating sequences (see Range.h)
*/

defclass(XRange, ValueSequence)
  F64 start;
  F64 end;
  F64 stride;
  FINAL_CLASS
endclass

// ----- automatic constructors

#define aXRange(...)  ( (OBJ)atXRange(__VA_ARGS__) )
#define atXRange(...) COS_PP_CAT_NARG(atXRange_,__VA_ARGS__)(__VA_ARGS__)

// --- shortcuts

#ifndef COS_NOSHORTCUT

#define aXRng(...)  aXRange(__VA_ARGS__)

#endif

/***********************************************************
 * Implementation (private)
 */

#define atXRange_1(end) \
        atXRange_2(0,end)

#define atXRange_2(start,end) \
        atXRange_3(start,end,1)

#define atXRange_3(start,end,stride) XRange_init( \
  &(struct XRange) { {{{ cos_object_auto(XRange) }}}, 0, 0, 0 }, \
  start, end, stride)

#define atXRange_4(start,next,_,end) XRange_enum( \
  &(struct XRange) { {{{ cos_object_auto(XRange) }}}, 0, 0, 0 }, \
  start, next, end)

// --- XRange inliners (low-level monorphic interface)

// constructor
static cos_inline struct XRange*
XRange_init(struct XRange *r, F64 start, F64 end, F64 stride) {
  r->start  = start;
  r->end    = end;
  r->stride = float_equal(stride,0) ? 1 : stride;

  return r;
}

// enumerator
static cos_inline struct XRange*
XRange_enum(struct XRange *r, F64 start, F64 next, F64 end) {
  r->start  = start;
  r->end    = end;
  r->stride = float_equal(start,next) ? 1 : next-start;

  return r;
}

// copy
static cos_inline struct XRange*
XRange_copy(struct XRange *r1, const struct XRange *r2) {
  r1->start  = r2->start;
  r1->end    = r2->end;
  r1->stride = r2->stride;

  return r1;
}

// getters
static cos_inline F64
XRange_start(const struct XRange *r) {
  return r->start;
}

static cos_inline F64
XRange_end(const struct XRange *r) {
  return r->end;
}

static cos_inline F64
XRange_stride(const struct XRange *r) {
  return r->stride;
}

static cos_inline F64
XRange_eval(const struct XRange *r, F64 x) {
  return r->start + x * r->stride;
}

static cos_inline U32
XRange_size(const struct XRange *r)
{
  I32 size = (r->end - r->start) / r->stride + 1 + DBL_EPSILON;
  return size > 0 ? size : 0;
}

// predicates (declaration)
BOOL XRange_isEqual(const struct XRange *r1, const struct XRange *r2);

// closed vs open interval
static cos_inline BOOL
XRange_isClosed(const struct XRange *r) {
  return r->stride > 0 ? r->start <= r->end : r->start >= r->end;
}

// conversion
#include <cos/Range.h>

static cos_inline struct XRange*
XRange_fromSlice(struct XRange *x, const struct Slice *s) {
  return XRange_init(x, Slice_start(s), Slice_end(s), Slice_stride(s));
}

static cos_inline struct XRange*
XRange_fromRange(struct XRange *x, const struct Range *r) {
  return XRange_init(x, Range_start(r), Range_end(r), Range_stride(r));
}

#endif // COS_XRANGE_H
