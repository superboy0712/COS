/**
 * C Object System
 * COS Generic
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

#include <cos/gen/op/GOperator.h>

makclass(G_Operator , Generic  );
makclass(G_UnaryOp  , G_Operator);
makclass(G_BinaryOp , G_Operator);
makclass(G_TernaryOp, G_Operator);

#include <cos/gen/op/GNumOp.h>

makclass(G_abs      , G_UnaryOp );
makclass(G_neg      , G_UnaryOp );
makclass(G_sqr      , G_UnaryOp );
makclass(G_inv      , G_UnaryOp );
makclass(G_add      , G_BinaryOp);
makclass(G_sub      , G_BinaryOp);
makclass(G_mul      , G_BinaryOp);
makclass(G_div      , G_BinaryOp);
makclass(G_pow      , G_BinaryOp);
makclass(G_mod      , G_BinaryOp);

makclass(G_absolute , G_UnaryOp );
makclass(G_negate   , G_UnaryOp );
makclass(G_square   , G_UnaryOp );
makclass(G_invert   , G_UnaryOp );
makclass(G_addTo    , G_BinaryOp);
makclass(G_subTo    , G_BinaryOp);
makclass(G_mulBy    , G_BinaryOp);
makclass(G_divBy    , G_BinaryOp);
makclass(G_power    , G_BinaryOp);
makclass(G_modulo   , G_BinaryOp);

#include <cos/gen/op/GFloatOp.h>

makclass(G_conj       , G_UnaryOp  );
makclass(G_arg        , G_UnaryOp  );
makclass(G_exp        , G_UnaryOp  );
makclass(G_log        , G_UnaryOp  );
makclass(G_sqrt       , G_UnaryOp  );
makclass(G_cos        , G_UnaryOp  );
makclass(G_sin        , G_UnaryOp  );
makclass(G_tan        , G_UnaryOp  );
makclass(G_acos       , G_UnaryOp  );
makclass(G_asin       , G_UnaryOp  );
makclass(G_atan       , G_UnaryOp  );
makclass(G_cosh       , G_UnaryOp  );
makclass(G_sinh       , G_UnaryOp  );
makclass(G_tanh       , G_UnaryOp  );
makclass(G_acosh      , G_UnaryOp  );
makclass(G_asinh      , G_UnaryOp  );
makclass(G_atanh      , G_UnaryOp  );
makclass(G_hypot      , G_BinaryOp );
makclass(G_sqrErr     , G_BinaryOp );
makclass(G_mulAdd     , G_TernaryOp);

makclass(G_conjugate  , G_UnaryOp  );
makclass(G_argument   , G_UnaryOp  );
makclass(G_exponential, G_UnaryOp  );
makclass(G_logarithm  , G_UnaryOp  );
makclass(G_sqroot     , G_UnaryOp  );
makclass(G_cosine     , G_UnaryOp  );
makclass(G_sine       , G_UnaryOp  );
makclass(G_tangent    , G_UnaryOp  );
makclass(G_acosine    , G_UnaryOp  );
makclass(G_asine      , G_UnaryOp  );
makclass(G_atangent   , G_UnaryOp  );
makclass(G_cosineh    , G_UnaryOp  );
makclass(G_sineh      , G_UnaryOp  );
makclass(G_tangenth   , G_UnaryOp  );
makclass(G_acosineh   , G_UnaryOp  );
makclass(G_asineh     , G_UnaryOp  );
makclass(G_atangenth  , G_UnaryOp  );

#include <cos/gen/op/GRelOp.h>

makclass(G_compare         , G_BinaryOp);
makclass(G_isEqual         , G_BinaryOp);
makclass(G_isNotEqual      , G_BinaryOp);
makclass(G_isLesser        , G_BinaryOp);
makclass(G_isLesserOrEqual , G_BinaryOp);
makclass(G_isGreater       , G_BinaryOp);
makclass(G_isGreaterOrEqual, G_BinaryOp);
makclass(G_min             , G_BinaryOp);
makclass(G_max             , G_BinaryOp);
makclass(G_hash            , G_UnaryOp );

#include <cos/gen/op/GLogicOp.h>

makclass(G_not    , G_UnaryOp );
makclass(G_and    , G_BinaryOp);
makclass(G_or     , G_BinaryOp);
makclass(G_xor    , G_BinaryOp);
makclass(G_implies, G_BinaryOp);

#include <cos/gen/op/GVectOp.h>

makclass(G_sum , G_UnaryOp);
makclass(G_prod, G_UnaryOp);

