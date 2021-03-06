#include <cm/cm.h>

_GENX_MAIN_
void test() {
}


#define STRING2(x) #x
#define STRING(x) STRING2(x)

#ifdef CM_GENX
#pragma message ( "CM_GENX defined with value " STRING(CM_GENX) )
#else
#warning CM_GENX not defined
#endif

#ifdef CM_GEN7_5
#warning CM_GEN7_5 defined
#endif

#ifdef CM_GEN8
#warning CM_GEN8 defined
#endif

#ifdef CM_GEN8_5
#warning CM_GEN8_5 defined
#endif

#ifdef CM_GEN9
#warning CM_GEN9 defined
#endif

#ifdef CM_GEN9_5
#warning CM_GEN9_5 defined
#endif

#ifdef CM_GEN10
#warning CM_GEN10 defined
#endif

#ifdef CM_GEN10_5
#warning CM_GEN10_5 defined
#endif

#ifdef CM_GEN11
#warning CM_GEN11 defined
#endif

#ifdef CM_GEN11_5
#warning CM_GEN11_5 defined
#endif

// We test a number of different ways to specify a KBL jit target option.
// All are equivalent, and should produce the same results, so we only need
// one set of CHECK values for all of these tests.
// We check the expected Gen variant macros are defined (and no others), and
// that the Finalizer is called with the expected platform option - which
// is SKL (as the finalizer doesn't support KBL as a distinct platform).
// We also check that the expected files are generated by deleting them, 
// which also leaves things tidy for the next test.

// RUN: %cmc -Qxcm_jit_target=kbl %w 2>&1 | FileCheck %w
// RUN: rm %W.isa %W_0.visaasm %W_0.asm %W_0.dat

// RUN: %cmc -Qxcm_jit_target:kbl %w 2>&1 | FileCheck %w
// RUN: rm %W.isa %W_0.visaasm %W_0.asm %W_0.dat

// RUN: %cmc -Qxcm_jit_targethsw -Qxcm_jit_targetkbl %w 2>&1 | FileCheck %w
// RUN: rm %W.isa %W_0.visaasm %W_0.asm %W_0.dat

// RUN: %cmc -Qxcm_jit_targetkbl %w 2>&1 | FileCheck %w
// RUN: rm %W.isa %W_0.visaasm %W_0.asm %W_0.dat

// RUN: %cmc -Qxcm_jit_target=gen9_5 %w 2>&1 | FileCheck %w
// RUN: rm %W.isa %W_0.visaasm %W_0.asm %W_0.dat

// RUN: %cmc -Qxcm_jit_target=GEN9_5 %w 2>&1 | FileCheck %w
// RUN: rm %W.isa %W_0.visaasm %W_0.asm %W_0.dat

// RUN: %cmc /Qxcm_jit_target=KBL %w 2>&1 | FileCheck %w
// RUN: rm %W.isa %W_0.visaasm %W_0.asm %W_0.dat

// RUN: %cmc /Qxcm_jit_target:kBl %w 2>&1 | FileCheck %w
// RUN: rm %W.isa %W_0.visaasm %W_0.asm %W_0.dat

// RUN: %cmc /Qxcm_jit_targetKbl %w 2>&1 | FileCheck %w
// RUN: rm %W.isa %W_0.visaasm %W_0.asm %W_0.dat

// RUN: %cmc /Qxcm_jit_targetkBl %w 2>&1 | FileCheck %w
// RUN: rm %W.isa %W_0.visaasm %W_0.asm %W_0.dat

// RUN: %cmc -mcpu=hsw -Qxcm_jit_target=KBl %w 2>&1 | FileCheck %w
// RUN: rm %W.isa %W_0.visaasm %W_0.asm %W_0.dat

// RUN: %cmc -march=bdw -Qxcm_jit_target=KbL -mcpu=hsw %w 2>&1 | FileCheck %w
// RUN: rm %W.isa %W_0.visaasm %W_0.asm %W_0.dat

// RUN: %cmc -Qxcm_jit_target -mcpu=KBL %w 2>&1 | FileCheck %w
// RUN: rm %W.isa %W_0.visaasm %W_0.asm %W_0.dat

// RUN: %cmc -Qxcm_jit_target -mcpu=gEN9_5 %w 2>&1 | FileCheck %w
// RUN: rm %W.isa %W_0.visaasm %W_0.asm %W_0.dat

// RUN: %cmc -march=Kbl -Qxcm_jit_target %w 2>&1 | FileCheck %w
// RUN: rm %W.isa %W_0.visaasm %W_0.asm %W_0.dat

// RUN: %cmc -Qxcm_jit_target -march=Gen9_5 %w 2>&1 | FileCheck %w
// RUN: rm %W.isa %W_0.visaasm %W_0.asm %W_0.dat

// CHECK: cm_jit_target_kbl.cpp(12,9):  warning: CM_GENX defined with value 950 [-W#pragma-messages]
// CHECK: cm_jit_target_kbl.cpp(34,2):  warning: CM_GEN9_5 defined [-W#warnings]
// CHECK: 2 warnings generated.
// CHECK: -platform SKL
