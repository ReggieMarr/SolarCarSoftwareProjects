/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Cruise.c
 *
 * Code generated for Simulink model 'Cruise'.
 *
 * Model version                  : 1.45
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Wed Feb 21 20:09:25 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Microchip->PIC18
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "Cruise.h"
#define NumBitsPerChar                 8U

/* External inputs (root inport signals with auto storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with auto storage) */
ExtY rtY;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
extern real_T rt_powd_snf(real_T u0, real_T u1);
extern real_T rt_hypotd_snf(real_T u0, real_T u1);
uint32_T plook_binc(real_T u, const real_T bp[], uint32_T maxIndex, real_T
                    *fraction);
uint32_T binsearch_u32d(real_T u, const real_T bp[], uint32_T startIndex,
  uint32_T maxIndex);

/* Forward declaration for local functions */
static boolean_T anyNonFinite(const creal_T x_data[], const int16_T x_size[2]);
static void sqrt_d(creal_T *x);
static void xzlartg_n(const creal_T f, const creal_T g, real_T *cs, creal_T *sn);
static void xzlartg(const creal_T f, const creal_T g, real_T *cs, creal_T *sn,
                    creal_T *r);
static void xzhgeqz(const creal_T A_data[], const int16_T A_size[2], int16_T ilo,
                    int16_T ihi, int32_T *info, creal_T alpha1_data[], int16_T
                    *alpha1_size, creal_T beta1_data[], int16_T *beta1_size);
static void xzgeev(const creal_T A_data[], const int16_T A_size[2], int32_T
                   *info, creal_T alpha1_data[], int16_T *alpha1_size, creal_T
                   beta1_data[], int16_T *beta1_size);
static real_T xdlapy3(real_T x1, real_T x2, real_T x3);
static creal_T recip(const creal_T y);
static void xgehrd(creal_T a_data[], int16_T a_size[2]);
static void xscal_o(int16_T n, const creal_T a, creal_T x_data[], int16_T ix0,
                    int16_T incx);
static void xscal(int16_T n, const creal_T a, creal_T x_data[], int16_T ix0);
static creal_T xzlarfg(creal_T *alpha1, creal_T *x);
static int32_T xhseqr(creal_T h_data[], int16_T h_size[2]);
static void roots(const real_T c[4], creal_T r_data[], int16_T *r_size);
extern real_T rtGetInf(void);
extern real32_T rtGetInfF(void);
extern real_T rtGetMinusInf(void);
extern real32_T rtGetMinusInfF(void);
extern real_T rtGetNaN(void);
extern real32_T rtGetNaNF(void);
extern real_T rtInf;
extern real_T rtMinusInf;
extern real_T rtNaN;
extern real32_T rtInfF;
extern real32_T rtMinusInfF;
extern real32_T rtNaNF;
extern void rt_InitInfAndNaN(size_t realSize);
extern boolean_T rtIsInf(real_T value);
extern boolean_T rtIsInfF(real32_T value);
extern boolean_T rtIsNaN(real_T value);
extern boolean_T rtIsNaNF(real32_T value);
typedef struct {
  struct {
    uint32_T wordH;
    uint32_T wordL;
  } words;
} BigEndianIEEEDouble;

typedef struct {
  struct {
    uint32_T wordL;
    uint32_T wordH;
  } words;
} LittleEndianIEEEDouble;

typedef struct {
  union {
    real32_T wordLreal;
    uint32_T wordLuint;
  } wordL;
} IEEESingle;

real_T rtInf;
real_T rtMinusInf;
real_T rtNaN;
real32_T rtInfF;
real32_T rtMinusInfF;
real32_T rtNaNF;

/*
 * Initialize rtInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
real_T rtGetInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T inf = 0.0;
  if (bitsPerReal == 32U) {
    inf = rtGetInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0x7FF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    inf = tmpVal.fltVal;
  }

  return inf;
}

/*
 * Initialize rtInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
real32_T rtGetInfF(void)
{
  IEEESingle infF;
  infF.wordL.wordLuint = 0x7F800000U;
  return infF.wordL.wordLreal;
}

/*
 * Initialize rtMinusInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
real_T rtGetMinusInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T minf = 0.0;
  if (bitsPerReal == 32U) {
    minf = rtGetMinusInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    minf = tmpVal.fltVal;
  }

  return minf;
}

/*
 * Initialize rtMinusInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
real32_T rtGetMinusInfF(void)
{
  IEEESingle minfF;
  minfF.wordL.wordLuint = 0xFF800000U;
  return minfF.wordL.wordLreal;
}

/*
 * Initialize rtNaN needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
real_T rtGetNaN(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T nan = 0.0;
  if (bitsPerReal == 32U) {
    nan = rtGetNaNF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF80000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    nan = tmpVal.fltVal;
  }

  return nan;
}

/*
 * Initialize rtNaNF needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
real32_T rtGetNaNF(void)
{
  IEEESingle nanF = { { 0 } };

  nanF.wordL.wordLuint = 0xFFC00000U;
  return nanF.wordL.wordLreal;
}

/*
 * Initialize the rtInf, rtMinusInf, and rtNaN needed by the
 * generated code. NaN is initialized as non-signaling. Assumes IEEE.
 */
void rt_InitInfAndNaN(size_t realSize)
{
  (void) (realSize);
  rtNaN = rtGetNaN();
  rtNaNF = rtGetNaNF();
  rtInf = rtGetInf();
  rtInfF = rtGetInfF();
  rtMinusInf = rtGetMinusInf();
  rtMinusInfF = rtGetMinusInfF();
}

/* Test if value is infinite */
boolean_T rtIsInf(real_T value)
{
  return (boolean_T)((value==rtInf || value==rtMinusInf) ? 1U : 0U);
}

/* Test if single-precision value is infinite */
boolean_T rtIsInfF(real32_T value)
{
  return (boolean_T)(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
}

/* Test if value is not a number */
boolean_T rtIsNaN(real_T value)
{
  return (boolean_T)((value!=value) ? 1U : 0U);
}

/* Test if single-precision value is not a number */
boolean_T rtIsNaNF(real32_T value)
{
  return (boolean_T)(((value!=value) ? 1U : 0U));
}

uint32_T plook_binc(real_T u, const real_T bp[], uint32_T maxIndex, real_T
                    *fraction)
{
  uint32_T bpIndex;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u <= bp[0UL]) {
    bpIndex = 0UL;
    *fraction = 0.0;
  } else if (u < bp[maxIndex]) {
    bpIndex = binsearch_u32d(u, bp, maxIndex >> 1UL, maxIndex);
    *fraction = (u - bp[bpIndex]) / (bp[bpIndex + 1UL] - bp[bpIndex]);
  } else {
    bpIndex = maxIndex - 1UL;
    *fraction = 1.0;
  }

  return bpIndex;
}

uint32_T binsearch_u32d(real_T u, const real_T bp[], uint32_T startIndex,
  uint32_T maxIndex)
{
  uint32_T bpIndex;
  uint32_T iRght;
  uint32_T bpIdx;

  /* Binary Search */
  bpIdx = startIndex;
  bpIndex = 0UL;
  iRght = maxIndex;
  while (iRght - bpIndex > 1UL) {
    if (u < bp[bpIdx]) {
      iRght = bpIdx;
    } else {
      bpIndex = bpIdx;
    }

    bpIdx = (iRght + bpIndex) >> 1UL;
  }

  return bpIndex;
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S13>/MATLAB Function' */
static boolean_T anyNonFinite(const creal_T x_data[], const int16_T x_size[2])
{
  boolean_T p;
  int16_T nx;
  int16_T k;
  nx = x_size[0] * x_size[1];
  p = false;
  for (k = 0; k + 1 <= nx; k++) {
    p = (p || (rtIsInf(x_data[k].re) || rtIsInf(x_data[k].im) || (rtIsNaN
           (x_data[k].re) || rtIsNaN(x_data[k].im))));
  }

  return p;
}

real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T a;
  a = fabs(u0);
  y = fabs(u1);
  if (a < y) {
    a /= y;
    y *= sqrt(a * a + 1.0);
  } else if (a > y) {
    y /= a;
    y = sqrt(y * y + 1.0) * a;
  } else {
    if (!rtIsNaN(y)) {
      y = a * 1.4142135623730951;
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S13>/MATLAB Function' */
static void sqrt_d(creal_T *x)
{
  real_T xr;
  real_T xi;
  real_T absxr;
  real_T absxi;
  xr = x->re;
  xi = x->im;
  if (xi == 0.0) {
    if (xr < 0.0) {
      absxr = 0.0;
      xr = sqrt(-xr);
    } else {
      absxr = sqrt(xr);
      xr = 0.0;
    }
  } else if (xr == 0.0) {
    if (xi < 0.0) {
      absxr = sqrt(-xi / 2.0);
      xr = -absxr;
    } else {
      absxr = sqrt(xi / 2.0);
      xr = absxr;
    }
  } else if (rtIsNaN(xr)) {
    absxr = xr;
  } else if (rtIsNaN(xi)) {
    absxr = xi;
    xr = xi;
  } else if (rtIsInf(xi)) {
    absxr = fabs(xi);
    xr = xi;
  } else if (rtIsInf(xr)) {
    if (xr < 0.0) {
      absxr = 0.0;
      xr = xi * -xr;
    } else {
      absxr = xr;
      xr = 0.0;
    }
  } else {
    absxr = fabs(xr);
    absxi = fabs(xi);
    if ((absxr > 4.4942328371557893E+307) || (absxi > 4.4942328371557893E+307))
    {
      absxr *= 0.5;
      absxi *= 0.5;
      absxi = rt_hypotd_snf(absxr, absxi);
      if (absxi > absxr) {
        absxr = sqrt(absxr / absxi + 1.0) * sqrt(absxi);
      } else {
        absxr = sqrt(absxi) * 1.4142135623730951;
      }
    } else {
      absxr = sqrt((rt_hypotd_snf(absxr, absxi) + absxr) * 0.5);
    }

    if (xr > 0.0) {
      xr = xi / absxr * 0.5;
    } else {
      if (xi < 0.0) {
        xr = -absxr;
      } else {
        xr = absxr;
      }

      absxr = xi / xr * 0.5;
    }
  }

  x->re = absxr;
  x->im = xr;
}

/* Function for MATLAB Function: '<S13>/MATLAB Function' */
static void xzlartg_n(const creal_T f, const creal_T g, real_T *cs, creal_T *sn)
{
  real_T scale;
  real_T g2;
  real_T f2s;
  real_T fs_re;
  real_T fs_im;
  real_T gs_re;
  real_T gs_im;
  boolean_T guard1 = false;
  scale = fabs(f.re);
  g2 = fabs(f.im);
  if (g2 > scale) {
    scale = g2;
  }

  g2 = fabs(g.re);
  f2s = fabs(g.im);
  if (f2s > g2) {
    g2 = f2s;
  }

  if (g2 > scale) {
    scale = g2;
  }

  fs_re = f.re;
  fs_im = f.im;
  gs_re = g.re;
  gs_im = g.im;
  guard1 = false;
  if (scale >= 7.4428285367870146E+137) {
    do {
      fs_re *= 1.3435752215134178E-138;
      fs_im *= 1.3435752215134178E-138;
      gs_re *= 1.3435752215134178E-138;
      gs_im *= 1.3435752215134178E-138;
      scale *= 1.3435752215134178E-138;
    } while (!(scale < 7.4428285367870146E+137));

    guard1 = true;
  } else if (scale <= 1.3435752215134178E-138) {
    if ((g.re == 0.0) && (g.im == 0.0)) {
      *cs = 1.0;
      sn->re = 0.0;
      sn->im = 0.0;
    } else {
      do {
        fs_re *= 7.4428285367870146E+137;
        fs_im *= 7.4428285367870146E+137;
        gs_re *= 7.4428285367870146E+137;
        gs_im *= 7.4428285367870146E+137;
        scale *= 7.4428285367870146E+137;
      } while (!(scale > 1.3435752215134178E-138));

      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    scale = fs_re * fs_re + fs_im * fs_im;
    g2 = gs_re * gs_re + gs_im * gs_im;
    f2s = g2;
    if (1.0 > g2) {
      f2s = 1.0;
    }

    if (scale <= f2s * 2.0041683600089728E-292) {
      if ((f.re == 0.0) && (f.im == 0.0)) {
        *cs = 0.0;
        g2 = rt_hypotd_snf(gs_re, gs_im);
        sn->re = gs_re / g2;
        sn->im = -gs_im / g2;
      } else {
        scale = sqrt(g2);
        *cs = rt_hypotd_snf(fs_re, fs_im) / scale;
        g2 = fabs(f.re);
        f2s = fabs(f.im);
        if (f2s > g2) {
          g2 = f2s;
        }

        if (g2 > 1.0) {
          g2 = rt_hypotd_snf(f.re, f.im);
          fs_re = f.re / g2;
          fs_im = f.im / g2;
        } else {
          f2s = 7.4428285367870146E+137 * f.re;
          fs_im = 7.4428285367870146E+137 * f.im;
          g2 = rt_hypotd_snf(f2s, fs_im);
          fs_re = f2s / g2;
          fs_im /= g2;
        }

        gs_re /= scale;
        gs_im = -gs_im / scale;
        sn->re = fs_re * gs_re - fs_im * gs_im;
        sn->im = fs_re * gs_im + fs_im * gs_re;
      }
    } else {
      f2s = sqrt(g2 / scale + 1.0);
      fs_re *= f2s;
      fs_im *= f2s;
      *cs = 1.0 / f2s;
      g2 += scale;
      fs_re /= g2;
      fs_im /= g2;
      sn->re = fs_re * gs_re - fs_im * -gs_im;
      sn->im = fs_re * -gs_im + fs_im * gs_re;
    }
  }
}

/* Function for MATLAB Function: '<S13>/MATLAB Function' */
static void xzlartg(const creal_T f, const creal_T g, real_T *cs, creal_T *sn,
                    creal_T *r)
{
  real_T scale;
  int16_T count;
  int16_T rescaledir;
  real_T g2;
  real_T f2s;
  real_T fs_re;
  real_T fs_im;
  real_T gs_re;
  real_T gs_im;
  boolean_T guard1 = false;
  scale = fabs(f.re);
  g2 = fabs(f.im);
  if (g2 > scale) {
    scale = g2;
  }

  g2 = fabs(g.re);
  f2s = fabs(g.im);
  if (f2s > g2) {
    g2 = f2s;
  }

  if (g2 > scale) {
    scale = g2;
  }

  fs_re = f.re;
  fs_im = f.im;
  gs_re = g.re;
  gs_im = g.im;
  count = 0;
  rescaledir = 0;
  guard1 = false;
  if (scale >= 7.4428285367870146E+137) {
    do {
      count++;
      fs_re *= 1.3435752215134178E-138;
      fs_im *= 1.3435752215134178E-138;
      gs_re *= 1.3435752215134178E-138;
      gs_im *= 1.3435752215134178E-138;
      scale *= 1.3435752215134178E-138;
    } while (!(scale < 7.4428285367870146E+137));

    rescaledir = 1;
    guard1 = true;
  } else if (scale <= 1.3435752215134178E-138) {
    if ((g.re == 0.0) && (g.im == 0.0)) {
      *cs = 1.0;
      sn->re = 0.0;
      sn->im = 0.0;
      *r = f;
    } else {
      do {
        count++;
        fs_re *= 7.4428285367870146E+137;
        fs_im *= 7.4428285367870146E+137;
        gs_re *= 7.4428285367870146E+137;
        gs_im *= 7.4428285367870146E+137;
        scale *= 7.4428285367870146E+137;
      } while (!(scale > 1.3435752215134178E-138));

      rescaledir = -1;
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    scale = fs_re * fs_re + fs_im * fs_im;
    g2 = gs_re * gs_re + gs_im * gs_im;
    f2s = g2;
    if (1.0 > g2) {
      f2s = 1.0;
    }

    if (scale <= f2s * 2.0041683600089728E-292) {
      if ((f.re == 0.0) && (f.im == 0.0)) {
        *cs = 0.0;
        r->re = rt_hypotd_snf(g.re, g.im);
        r->im = 0.0;
        g2 = rt_hypotd_snf(gs_re, gs_im);
        sn->re = gs_re / g2;
        sn->im = -gs_im / g2;
      } else {
        scale = sqrt(g2);
        *cs = rt_hypotd_snf(fs_re, fs_im) / scale;
        g2 = fabs(f.re);
        f2s = fabs(f.im);
        if (f2s > g2) {
          g2 = f2s;
        }

        if (g2 > 1.0) {
          g2 = rt_hypotd_snf(f.re, f.im);
          fs_re = f.re / g2;
          fs_im = f.im / g2;
        } else {
          f2s = 7.4428285367870146E+137 * f.re;
          fs_im = 7.4428285367870146E+137 * f.im;
          g2 = rt_hypotd_snf(f2s, fs_im);
          fs_re = f2s / g2;
          fs_im /= g2;
        }

        gs_re /= scale;
        gs_im = -gs_im / scale;
        sn->re = fs_re * gs_re - fs_im * gs_im;
        sn->im = fs_re * gs_im + fs_im * gs_re;
        r->re = (sn->re * g.re - sn->im * g.im) + *cs * f.re;
        r->im = (sn->re * g.im + sn->im * g.re) + *cs * f.im;
      }
    } else {
      f2s = sqrt(g2 / scale + 1.0);
      r->re = f2s * fs_re;
      r->im = f2s * fs_im;
      *cs = 1.0 / f2s;
      g2 += scale;
      scale = r->re / g2;
      g2 = r->im / g2;
      sn->re = scale * gs_re - g2 * -gs_im;
      sn->im = scale * -gs_im + g2 * gs_re;
      if (rescaledir > 0) {
        while (rescaledir <= count) {
          r->re *= 7.4428285367870146E+137;
          r->im *= 7.4428285367870146E+137;
          rescaledir++;
        }
      } else {
        if (rescaledir < 0) {
          for (rescaledir = 1; rescaledir <= count; rescaledir++) {
            r->re *= 1.3435752215134178E-138;
            r->im *= 1.3435752215134178E-138;
          }
        }
      }
    }
  }
}

/* Function for MATLAB Function: '<S13>/MATLAB Function' */
static void xzhgeqz(const creal_T A_data[], const int16_T A_size[2], int16_T ilo,
                    int16_T ihi, int32_T *info, creal_T alpha1_data[], int16_T
                    *alpha1_size, creal_T beta1_data[], int16_T *beta1_size)
{
  creal_T ctemp;
  real_T anorm;
  int16_T j;
  int16_T ifirst;
  int16_T istart;
  int16_T ilast;
  int16_T ilastm1;
  int16_T ifrstm;
  int16_T ilastm;
  int16_T iiter;
  boolean_T goto60;
  boolean_T goto70;
  boolean_T goto90;
  int16_T jp1;
  boolean_T ilazro;
  creal_T ad22;
  creal_T shift;
  creal_T b_A_data[9];
  int16_T jiter;
  real_T scale;
  boolean_T firstNonZero;
  real_T reAij;
  real_T imAij;
  real_T b_temp2;
  int16_T b_i;
  int16_T b_A_size_idx_0;
  creal_T anorm_0;
  real_T ar;
  real_T ai;
  real_T t1_re;
  real_T t1_im;
  real_T shift_im;
  real_T eshift_re;
  real_T eshift_im;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  int32_T exitg1;
  boolean_T exitg2;
  b_A_size_idx_0 = A_size[0];
  ifirst = A_size[0] * A_size[1];
  for (ilast = 0; ilast < ifirst; ilast++) {
    b_A_data[ilast] = A_data[ilast];
  }

  *info = 0L;
  if ((A_size[0] == 1) && (A_size[1] == 1)) {
    ihi = 1;
  }

  *alpha1_size = A_size[0];
  ifirst = A_size[0];
  for (ilast = 0; ilast < ifirst; ilast++) {
    alpha1_data[ilast].re = 0.0;
    alpha1_data[ilast].im = 0.0;
  }

  *beta1_size = A_size[0];
  ifirst = A_size[0];
  for (ilast = 0; ilast < ifirst; ilast++) {
    beta1_data[ilast].re = 1.0;
    beta1_data[ilast].im = 0.0;
  }

  eshift_re = 0.0;
  eshift_im = 0.0;
  ctemp.re = 0.0;
  ctemp.im = 0.0;
  anorm = 0.0;
  if (!(ilo > ihi)) {
    scale = 0.0;
    firstNonZero = true;
    for (ilast = ilo; ilast <= ihi; ilast++) {
      ifirst = ilast + 1;
      if (ihi < ilast + 1) {
        ifirst = ihi;
      }

      for (istart = ilo; istart <= ifirst; istart++) {
        reAij = A_data[((ilast - 1) * A_size[0] + istart) - 1].re;
        imAij = A_data[((ilast - 1) * A_size[0] + istart) - 1].im;
        if (reAij != 0.0) {
          reAij = fabs(reAij);
          if (firstNonZero) {
            anorm = 1.0;
            scale = reAij;
            firstNonZero = false;
          } else if (scale < reAij) {
            b_temp2 = scale / reAij;
            anorm = anorm * b_temp2 * b_temp2 + 1.0;
            scale = reAij;
          } else {
            b_temp2 = reAij / scale;
            anorm += b_temp2 * b_temp2;
          }
        }

        if (imAij != 0.0) {
          reAij = fabs(imAij);
          if (firstNonZero) {
            anorm = 1.0;
            scale = reAij;
            firstNonZero = false;
          } else if (scale < reAij) {
            b_temp2 = scale / reAij;
            anorm = anorm * b_temp2 * b_temp2 + 1.0;
            scale = reAij;
          } else {
            b_temp2 = reAij / scale;
            anorm += b_temp2 * b_temp2;
          }
        }
      }
    }

    anorm = scale * sqrt(anorm);
  }

  imAij = 2.2204460492503131E-16 * anorm;
  scale = 2.2250738585072014E-308;
  if (imAij > 2.2250738585072014E-308) {
    scale = imAij;
  }

  imAij = 2.2250738585072014E-308;
  if (anorm > 2.2250738585072014E-308) {
    imAij = anorm;
  }

  anorm = 1.0 / imAij;
  imAij = 1.0 / sqrt(A_size[0]);
  firstNonZero = true;
  for (ilast = ihi; ilast + 1 <= A_size[0]; ilast++) {
    alpha1_data[ilast] = A_data[A_size[0] * ilast + ilast];
  }

  guard1 = false;
  guard2 = false;
  if (ihi >= ilo) {
    ifirst = ilo;
    istart = ilo;
    ilast = ihi - 1;
    ilastm1 = ihi - 2;
    ifrstm = ilo;
    ilastm = ihi;
    iiter = 0;
    goto60 = false;
    goto70 = false;
    goto90 = false;
    jiter = 1;
    do {
      exitg1 = 0L;
      if (jiter <= ((ihi - ilo) + 1) * 30) {
        if (ilast + 1 == ilo) {
          goto60 = true;
        } else if (fabs(b_A_data[b_A_size_idx_0 * ilastm1 + ilast].re) + fabs
                   (b_A_data[b_A_size_idx_0 * ilastm1 + ilast].im) <= scale) {
          b_A_data[ilast + b_A_size_idx_0 * ilastm1].re = 0.0;
          b_A_data[ilast + b_A_size_idx_0 * ilastm1].im = 0.0;
          goto60 = true;
        } else {
          j = ilastm1;
          exitg2 = false;
          while ((!exitg2) && (j + 1 >= ilo)) {
            if (j + 1 == ilo) {
              ilazro = true;
            } else if (fabs(b_A_data[(j - 1) * b_A_size_idx_0 + j].re) + fabs
                       (b_A_data[(j - 1) * b_A_size_idx_0 + j].im) <= scale) {
              b_A_data[j + b_A_size_idx_0 * (j - 1)].re = 0.0;
              b_A_data[j + b_A_size_idx_0 * (j - 1)].im = 0.0;
              ilazro = true;
            } else {
              ilazro = false;
            }

            if (ilazro) {
              ifirst = j + 1;
              goto70 = true;
              exitg2 = true;
            } else {
              j--;
            }
          }
        }

        if (!(goto60 || goto70)) {
          b_A_size_idx_0 = *alpha1_size;
          for (ilast = 0; ilast < b_A_size_idx_0; ilast++) {
            alpha1_data[ilast].re = (rtNaN);
            alpha1_data[ilast].im = 0.0;
          }

          b_A_size_idx_0 = *beta1_size;
          for (ilast = 0; ilast < b_A_size_idx_0; ilast++) {
            beta1_data[ilast].re = (rtNaN);
            beta1_data[ilast].im = 0.0;
          }

          *info = 1L;
          exitg1 = 1L;
        } else if (goto60) {
          goto60 = false;
          alpha1_data[ilast] = b_A_data[b_A_size_idx_0 * ilast + ilast];
          ilast = ilastm1;
          ilastm1--;
          if (ilast + 1 < ilo) {
            firstNonZero = false;
            guard2 = true;
            exitg1 = 1L;
          } else {
            iiter = 0;
            eshift_re = 0.0;
            eshift_im = 0.0;
            ilastm = ilast + 1;
            if (ifrstm > ilast + 1) {
              ifrstm = ilo;
            }

            jiter++;
          }
        } else {
          if (goto70) {
            goto70 = false;
            iiter++;
            ifrstm = ifirst;
            if (iiter - iiter / 10 * 10 != 0) {
              ar = b_A_data[b_A_size_idx_0 * ilastm1 + ilastm1].re * anorm;
              ai = b_A_data[b_A_size_idx_0 * ilastm1 + ilastm1].im * anorm;
              if (ai == 0.0) {
                shift.re = ar / imAij;
                shift.im = 0.0;
              } else if (ar == 0.0) {
                shift.re = 0.0;
                shift.im = ai / imAij;
              } else {
                shift.re = ar / imAij;
                shift.im = ai / imAij;
              }

              ar = b_A_data[b_A_size_idx_0 * ilast + ilast].re * anorm;
              ai = b_A_data[b_A_size_idx_0 * ilast + ilast].im * anorm;
              if (ai == 0.0) {
                ad22.re = ar / imAij;
                ad22.im = 0.0;
              } else if (ar == 0.0) {
                ad22.re = 0.0;
                ad22.im = ai / imAij;
              } else {
                ad22.re = ar / imAij;
                ad22.im = ai / imAij;
              }

              t1_re = (shift.re + ad22.re) * 0.5;
              t1_im = (shift.im + ad22.im) * 0.5;
              ar = b_A_data[b_A_size_idx_0 * ilast + ilastm1].re * anorm;
              ai = b_A_data[b_A_size_idx_0 * ilast + ilastm1].im * anorm;
              if (ai == 0.0) {
                reAij = ar / imAij;
                b_temp2 = 0.0;
              } else if (ar == 0.0) {
                reAij = 0.0;
                b_temp2 = ai / imAij;
              } else {
                reAij = ar / imAij;
                b_temp2 = ai / imAij;
              }

              ar = b_A_data[b_A_size_idx_0 * ilastm1 + ilast].re * anorm;
              ai = b_A_data[b_A_size_idx_0 * ilastm1 + ilast].im * anorm;
              if (ai == 0.0) {
                ar /= imAij;
                ai = 0.0;
              } else if (ar == 0.0) {
                ar = 0.0;
                ai /= imAij;
              } else {
                ar /= imAij;
                ai /= imAij;
              }

              shift_im = shift.re * ad22.im + shift.im * ad22.re;
              shift.re = ((t1_re * t1_re - t1_im * t1_im) + (reAij * ar -
                b_temp2 * ai)) - (shift.re * ad22.re - shift.im * ad22.im);
              shift.im = ((t1_re * t1_im + t1_im * t1_re) + (reAij * ai +
                b_temp2 * ar)) - shift_im;
              sqrt_d(&shift);
              if ((t1_re - ad22.re) * shift.re + (t1_im - ad22.im) * shift.im <=
                  0.0) {
                shift.re += t1_re;
                shift.im += t1_im;
              } else {
                shift.re = t1_re - shift.re;
                shift.im = t1_im - shift.im;
              }
            } else {
              ar = b_A_data[b_A_size_idx_0 * ilastm1 + ilast].re * anorm;
              ai = b_A_data[b_A_size_idx_0 * ilastm1 + ilast].im * anorm;
              if (ai == 0.0) {
                reAij = ar / imAij;
                b_temp2 = 0.0;
              } else if (ar == 0.0) {
                reAij = 0.0;
                b_temp2 = ai / imAij;
              } else {
                reAij = ar / imAij;
                b_temp2 = ai / imAij;
              }

              eshift_re += reAij;
              eshift_im += b_temp2;
              shift.re = eshift_re;
              shift.im = eshift_im;
            }

            j = ilastm1;
            jp1 = ilastm1 + 1;
            exitg2 = false;
            while ((!exitg2) && (j + 1 > ifirst)) {
              istart = j + 1;
              ctemp.re = b_A_data[b_A_size_idx_0 * j + j].re * anorm - shift.re *
                imAij;
              ctemp.im = b_A_data[b_A_size_idx_0 * j + j].im * anorm - shift.im *
                imAij;
              reAij = fabs(ctemp.re) + fabs(ctemp.im);
              b_temp2 = (fabs(b_A_data[b_A_size_idx_0 * j + jp1].re) + fabs
                         (b_A_data[b_A_size_idx_0 * j + jp1].im)) * anorm;
              t1_re = reAij;
              if (b_temp2 > reAij) {
                t1_re = b_temp2;
              }

              if ((t1_re < 1.0) && (t1_re != 0.0)) {
                reAij /= t1_re;
                b_temp2 /= t1_re;
              }

              if ((fabs(b_A_data[(j - 1) * b_A_size_idx_0 + j].re) + fabs
                   (b_A_data[(j - 1) * b_A_size_idx_0 + j].im)) * b_temp2 <=
                  reAij * scale) {
                goto90 = true;
                exitg2 = true;
              } else {
                jp1 = j;
                j--;
              }
            }

            if (!goto90) {
              istart = ifirst;
              ctemp.re = b_A_data[((ifirst - 1) * b_A_size_idx_0 + ifirst) - 1].
                re * anorm - shift.re * imAij;
              ctemp.im = b_A_data[((ifirst - 1) * b_A_size_idx_0 + ifirst) - 1].
                im * anorm - shift.im * imAij;
              goto90 = true;
            }
          }

          if (goto90) {
            goto90 = false;
            anorm_0.re = b_A_data[(istart - 1) * b_A_size_idx_0 + istart].re *
              anorm;
            anorm_0.im = b_A_data[(istart - 1) * b_A_size_idx_0 + istart].im *
              anorm;
            xzlartg_n(ctemp, anorm_0, &reAij, &ad22);
            j = istart;
            jp1 = istart - 2;
            while (j < ilast + 1) {
              if (j > istart) {
                xzlartg(b_A_data[1 + b_A_size_idx_0 * jp1], b_A_data[j +
                        b_A_size_idx_0 * jp1], &reAij, &ad22, &shift);
                b_A_data[1 + b_A_size_idx_0 * jp1] = shift;
                b_A_data[j + b_A_size_idx_0 * jp1].re = 0.0;
                b_A_data[j + b_A_size_idx_0 * jp1].im = 0.0;
              }

              for (jp1 = j - 1; jp1 + 1 <= ilastm; jp1++) {
                shift.re = b_A_data[(b_A_size_idx_0 * jp1 + j) - 1].re * reAij +
                  (b_A_data[b_A_size_idx_0 * jp1 + j].re * ad22.re -
                   b_A_data[b_A_size_idx_0 * jp1 + j].im * ad22.im);
                shift.im = b_A_data[(b_A_size_idx_0 * jp1 + j) - 1].im * reAij +
                  (b_A_data[b_A_size_idx_0 * jp1 + j].im * ad22.re +
                   b_A_data[b_A_size_idx_0 * jp1 + j].re * ad22.im);
                b_temp2 = b_A_data[(b_A_size_idx_0 * jp1 + j) - 1].re;
                b_A_data[j + b_A_size_idx_0 * jp1].re = b_A_data[b_A_size_idx_0 *
                  jp1 + j].re * reAij - (b_A_data[(b_A_size_idx_0 * jp1 + j) - 1]
                  .re * ad22.re + b_A_data[(b_A_size_idx_0 * jp1 + j) - 1].im *
                  ad22.im);
                b_A_data[j + b_A_size_idx_0 * jp1].im = b_A_data[b_A_size_idx_0 *
                  jp1 + j].im * reAij - (b_A_data[(b_A_size_idx_0 * jp1 + j) - 1]
                  .im * ad22.re - ad22.im * b_temp2);
                b_A_data[(j + b_A_size_idx_0 * jp1) - 1] = shift;
              }

              ad22.re = -ad22.re;
              ad22.im = -ad22.im;
              jp1 = j;
              if (ilast + 1 < j + 2) {
                jp1 = ilast - 1;
              }

              for (b_i = ifrstm - 1; b_i + 1 <= jp1 + 2; b_i++) {
                shift.re = (b_A_data[(j - 1) * b_A_size_idx_0 + b_i].re *
                            ad22.re - b_A_data[(j - 1) * b_A_size_idx_0 + b_i].
                            im * ad22.im) + b_A_data[b_A_size_idx_0 * j + b_i].
                  re * reAij;
                shift.im = (b_A_data[(j - 1) * b_A_size_idx_0 + b_i].im *
                            ad22.re + b_A_data[(j - 1) * b_A_size_idx_0 + b_i].
                            re * ad22.im) + b_A_data[b_A_size_idx_0 * j + b_i].
                  im * reAij;
                b_temp2 = b_A_data[b_A_size_idx_0 * j + b_i].re;
                b_A_data[b_i + b_A_size_idx_0 * (j - 1)].re = b_A_data[(j - 1) *
                  b_A_size_idx_0 + b_i].re * reAij - (b_A_data[b_A_size_idx_0 *
                  j + b_i].re * ad22.re + b_A_data[b_A_size_idx_0 * j + b_i].im *
                  ad22.im);
                b_A_data[b_i + b_A_size_idx_0 * (j - 1)].im = b_A_data[(j - 1) *
                  b_A_size_idx_0 + b_i].im * reAij - (b_A_data[b_A_size_idx_0 *
                  j + b_i].im * ad22.re - ad22.im * b_temp2);
                b_A_data[b_i + b_A_size_idx_0 * j] = shift;
              }

              jp1 = j - 1;
              j++;
            }
          }

          jiter++;
        }
      } else {
        guard2 = true;
        exitg1 = 1L;
      }
    } while (exitg1 == 0L);
  } else {
    guard1 = true;
  }

  if (guard2) {
    if (firstNonZero) {
      *info = ilast + 1;
      for (ifirst = 0; ifirst + 1 <= ilast + 1; ifirst++) {
        alpha1_data[ifirst].re = (rtNaN);
        alpha1_data[ifirst].im = 0.0;
        beta1_data[ifirst].re = (rtNaN);
        beta1_data[ifirst].im = 0.0;
      }
    } else {
      guard1 = true;
    }
  }

  if (guard1) {
    for (ilast = 0; ilast + 1 < ilo; ilast++) {
      alpha1_data[ilast] = b_A_data[b_A_size_idx_0 * ilast + ilast];
    }
  }
}

/* Function for MATLAB Function: '<S13>/MATLAB Function' */
static void xzgeev(const creal_T A_data[], const int16_T A_size[2], int32_T
                   *info, creal_T alpha1_data[], int16_T *alpha1_size, creal_T
                   beta1_data[], int16_T *beta1_size)
{
  creal_T At_data[9];
  real_T anrm;
  boolean_T ilascl;
  real_T absxk;
  int16_T b;
  int16_T k;
  real_T cfromc;
  real_T ctoc;
  boolean_T notdone;
  real_T cto1;
  real_T mul;
  int16_T i;
  creal_T b_A_data[9];
  int16_T ii;
  int16_T nzcount;
  int16_T jj;
  creal_T atmp;
  creal_T s;
  int16_T jcol;
  real_T b_mul;
  int16_T b_A_size[2];
  int16_T At_size_idx_0;
  int16_T At_size_idx_1;
  creal_T alpha1_data_0;
  boolean_T exitg1;
  int32_T exitg2;
  int32_T exitg3;
  boolean_T exitg4;
  At_size_idx_0 = A_size[0];
  At_size_idx_1 = A_size[1];
  ii = A_size[0] * A_size[1];
  for (nzcount = 0; nzcount < ii; nzcount++) {
    At_data[nzcount] = A_data[nzcount];
  }

  *info = 0L;
  anrm = 0.0;
  b = A_size[0] * A_size[1];
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= b - 1)) {
    absxk = rt_hypotd_snf(A_data[k].re, A_data[k].im);
    if (rtIsNaN(absxk)) {
      anrm = (rtNaN);
      exitg1 = true;
    } else {
      if (absxk > anrm) {
        anrm = absxk;
      }

      k++;
    }
  }

  if (!((!rtIsInf(anrm)) && (!rtIsNaN(anrm)))) {
    *alpha1_size = A_size[0];
    ii = A_size[0];
    for (nzcount = 0; nzcount < ii; nzcount++) {
      alpha1_data[nzcount].re = (rtNaN);
      alpha1_data[nzcount].im = 0.0;
    }

    *beta1_size = A_size[0];
    ii = A_size[0];
    for (nzcount = 0; nzcount < ii; nzcount++) {
      beta1_data[nzcount].re = (rtNaN);
      beta1_data[nzcount].im = 0.0;
    }
  } else {
    ilascl = false;
    absxk = anrm;
    if ((anrm > 0.0) && (anrm < 6.7178761075670888E-139)) {
      absxk = 6.7178761075670888E-139;
      ilascl = true;
    } else {
      if (anrm > 1.4885657073574029E+138) {
        absxk = 1.4885657073574029E+138;
        ilascl = true;
      }
    }

    if (ilascl) {
      cfromc = anrm;
      ctoc = absxk;
      notdone = true;
      while (notdone) {
        b_mul = cfromc * 2.0041683600089728E-292;
        cto1 = ctoc / 4.9896007738368E+291;
        if ((b_mul > ctoc) && (ctoc != 0.0)) {
          mul = 2.0041683600089728E-292;
          cfromc = b_mul;
        } else if (cto1 > cfromc) {
          mul = 4.9896007738368E+291;
          ctoc = cto1;
        } else {
          mul = ctoc / cfromc;
          notdone = false;
        }

        ii = At_size_idx_0 * At_size_idx_1;
        for (nzcount = 0; nzcount < ii; nzcount++) {
          atmp.re = mul * At_data[nzcount].re;
          atmp.im = mul * At_data[nzcount].im;
          At_data[nzcount] = atmp;
        }
      }
    }

    b = 1;
    k = A_size[0];
    if (A_size[0] <= 1) {
      k = 1;
    } else {
      do {
        exitg3 = 0L;
        i = 0;
        jcol = 0;
        notdone = false;
        ii = k;
        exitg1 = false;
        while ((!exitg1) && (ii > 0)) {
          nzcount = 0;
          i = ii;
          jcol = k;
          jj = 1;
          exitg4 = false;
          while ((!exitg4) && (jj <= k)) {
            if ((At_data[((jj - 1) * At_size_idx_0 + ii) - 1].re != 0.0) ||
                (At_data[((jj - 1) * At_size_idx_0 + ii) - 1].im != 0.0) || (ii ==
                 jj)) {
              if (nzcount == 0) {
                jcol = jj;
                nzcount = 1;
                jj++;
              } else {
                nzcount = 2;
                exitg4 = true;
              }
            } else {
              jj++;
            }
          }

          if (nzcount < 2) {
            notdone = true;
            exitg1 = true;
          } else {
            ii--;
          }
        }

        if (!notdone) {
          exitg3 = 2L;
        } else {
          ii = At_size_idx_0 * At_size_idx_1;
          for (nzcount = 0; nzcount < ii; nzcount++) {
            b_A_data[nzcount] = At_data[nzcount];
          }

          if (i != k) {
            for (ii = 0; ii + 1 <= At_size_idx_0; ii++) {
              atmp = b_A_data[(At_size_idx_0 * ii + i) - 1];
              b_A_data[(i + At_size_idx_0 * ii) - 1] = b_A_data[(At_size_idx_0 *
                ii + k) - 1];
              b_A_data[(k + At_size_idx_0 * ii) - 1] = atmp;
            }
          }

          if (jcol != k) {
            for (i = 0; i + 1 <= k; i++) {
              atmp = b_A_data[(jcol - 1) * At_size_idx_0 + i];
              b_A_data[i + At_size_idx_0 * (jcol - 1)] = b_A_data[(k - 1) *
                At_size_idx_0 + i];
              b_A_data[i + At_size_idx_0 * (k - 1)] = atmp;
            }
          }

          ii = At_size_idx_0 * At_size_idx_1;
          for (nzcount = 0; nzcount < ii; nzcount++) {
            At_data[nzcount] = b_A_data[nzcount];
          }

          k--;
          if (k == 1) {
            exitg3 = 1L;
          }
        }
      } while (exitg3 == 0L);

      if (exitg3 == 1L) {
      } else {
        do {
          exitg2 = 0L;
          i = 0;
          jcol = 0;
          notdone = false;
          ii = b;
          exitg1 = false;
          while ((!exitg1) && (ii <= k)) {
            nzcount = 0;
            i = k;
            jcol = ii;
            jj = b;
            exitg4 = false;
            while ((!exitg4) && (jj <= k)) {
              if ((At_data[((ii - 1) * At_size_idx_0 + jj) - 1].re != 0.0) ||
                  (At_data[((ii - 1) * At_size_idx_0 + jj) - 1].im != 0.0) ||
                  (jj == ii)) {
                if (nzcount == 0) {
                  i = jj;
                  nzcount = 1;
                  jj++;
                } else {
                  nzcount = 2;
                  exitg4 = true;
                }
              } else {
                jj++;
              }
            }

            if (nzcount < 2) {
              notdone = true;
              exitg1 = true;
            } else {
              ii++;
            }
          }

          if (!notdone) {
            exitg2 = 1L;
          } else {
            ii = At_size_idx_0 * At_size_idx_1;
            for (nzcount = 0; nzcount < ii; nzcount++) {
              b_A_data[nzcount] = At_data[nzcount];
            }

            if (i != b) {
              for (ii = b - 1; ii + 1 <= At_size_idx_0; ii++) {
                atmp = b_A_data[(At_size_idx_0 * ii + i) - 1];
                b_A_data[(i + At_size_idx_0 * ii) - 1] = b_A_data[(At_size_idx_0
                  * ii + b) - 1];
                b_A_data[(b + At_size_idx_0 * ii) - 1] = atmp;
              }
            }

            if (jcol != b) {
              for (i = 0; i + 1 <= k; i++) {
                atmp = b_A_data[(jcol - 1) * At_size_idx_0 + i];
                b_A_data[i + At_size_idx_0 * (jcol - 1)] = b_A_data[(b - 1) *
                  At_size_idx_0 + i];
                b_A_data[i + At_size_idx_0 * (b - 1)] = atmp;
              }
            }

            ii = At_size_idx_0 * At_size_idx_1;
            for (nzcount = 0; nzcount < ii; nzcount++) {
              At_data[nzcount] = b_A_data[nzcount];
            }

            b++;
            if (b == k) {
              exitg2 = 1L;
            }
          }
        } while (exitg2 == 0L);
      }
    }

    b_A_size[0] = A_size[0];
    b_A_size[1] = A_size[1];
    ii = A_size[0] * A_size[1];
    for (nzcount = 0; nzcount < ii; nzcount++) {
      b_A_data[nzcount] = At_data[nzcount];
    }

    if ((!(A_size[0] <= 1)) && (!(k < b + 2))) {
      jcol = b;
      while (jcol < 2) {
        xzlartg(b_A_data[1], b_A_data[2], &cfromc, &s, &atmp);
        b_A_data[1] = atmp;
        b_A_data[2].re = 0.0;
        b_A_data[2].im = 0.0;
        for (jcol = 1; jcol + 1 <= At_size_idx_0; jcol++) {
          atmp.re = (b_A_data[At_size_idx_0 * jcol + 2].re * s.re -
                     b_A_data[At_size_idx_0 * jcol + 2].im * s.im) +
            b_A_data[At_size_idx_0 * jcol + 1].re * cfromc;
          atmp.im = (b_A_data[At_size_idx_0 * jcol + 2].im * s.re +
                     b_A_data[At_size_idx_0 * jcol + 2].re * s.im) +
            b_A_data[At_size_idx_0 * jcol + 1].im * cfromc;
          ctoc = b_A_data[At_size_idx_0 * jcol + 1].re;
          b_A_data[2 + At_size_idx_0 * jcol].re = b_A_data[At_size_idx_0 * jcol
            + 2].re * cfromc - (b_A_data[At_size_idx_0 * jcol + 1].re * s.re +
                                b_A_data[At_size_idx_0 * jcol + 1].im * s.im);
          b_A_data[2 + At_size_idx_0 * jcol].im = b_A_data[At_size_idx_0 * jcol
            + 2].im * cfromc - (b_A_data[At_size_idx_0 * jcol + 1].im * s.re -
                                s.im * ctoc);
          b_A_data[1 + At_size_idx_0 * jcol] = atmp;
        }

        s.re = -s.re;
        s.im = -s.im;
        atmp.re = b_A_data[At_size_idx_0 << 1].re * cfromc + (s.re *
          b_A_data[At_size_idx_0].re - s.im * b_A_data[At_size_idx_0].im);
        atmp.im = b_A_data[At_size_idx_0 << 1].im * cfromc + (s.re *
          b_A_data[At_size_idx_0].im + s.im * b_A_data[At_size_idx_0].re);
        ctoc = b_A_data[At_size_idx_0 << 1].re;
        b_A_data[At_size_idx_0].re = cfromc * b_A_data[At_size_idx_0].re -
          (b_A_data[At_size_idx_0 << 1].re * s.re + b_A_data[At_size_idx_0 << 1]
           .im * s.im);
        b_A_data[At_size_idx_0].im = cfromc * b_A_data[At_size_idx_0].im -
          (b_A_data[At_size_idx_0 << 1].im * s.re - s.im * ctoc);
        b_A_data[At_size_idx_0 << 1] = atmp;
        atmp.re = b_A_data[(At_size_idx_0 << 1) + 1].re * cfromc + (b_A_data[1 +
          At_size_idx_0].re * s.re - b_A_data[1 + At_size_idx_0].im * s.im);
        atmp.im = b_A_data[(At_size_idx_0 << 1) + 1].im * cfromc + (b_A_data[1 +
          At_size_idx_0].im * s.re + b_A_data[1 + At_size_idx_0].re * s.im);
        ctoc = b_A_data[(At_size_idx_0 << 1) + 1].re;
        b_A_data[1 + At_size_idx_0].re = b_A_data[1 + At_size_idx_0].re * cfromc
          - (b_A_data[(At_size_idx_0 << 1) + 1].re * s.re + b_A_data
             [(At_size_idx_0 << 1) + 1].im * s.im);
        b_A_data[1 + At_size_idx_0].im = b_A_data[1 + At_size_idx_0].im * cfromc
          - (b_A_data[(At_size_idx_0 << 1) + 1].im * s.re - s.im * ctoc);
        b_A_data[1 + (At_size_idx_0 << 1)] = atmp;
        atmp.re = b_A_data[(At_size_idx_0 << 1) + 2].re * cfromc + (b_A_data[2 +
          At_size_idx_0].re * s.re - b_A_data[2 + At_size_idx_0].im * s.im);
        atmp.im = b_A_data[(At_size_idx_0 << 1) + 2].im * cfromc + (b_A_data[2 +
          At_size_idx_0].im * s.re + b_A_data[2 + At_size_idx_0].re * s.im);
        ctoc = b_A_data[(At_size_idx_0 << 1) + 2].re;
        b_A_data[2 + At_size_idx_0].re = b_A_data[2 + At_size_idx_0].re * cfromc
          - (b_A_data[(At_size_idx_0 << 1) + 2].re * s.re + b_A_data
             [(At_size_idx_0 << 1) + 2].im * s.im);
        b_A_data[2 + At_size_idx_0].im = b_A_data[2 + At_size_idx_0].im * cfromc
          - (b_A_data[(At_size_idx_0 << 1) + 2].im * s.re - s.im * ctoc);
        b_A_data[2 + (At_size_idx_0 << 1)] = atmp;
        jcol = 2;
      }
    }

    xzhgeqz(b_A_data, b_A_size, b, k, info, alpha1_data, alpha1_size, beta1_data,
            beta1_size);
    if (!((*info != 0L) || (!ilascl))) {
      while (ilascl) {
        cfromc = absxk * 2.0041683600089728E-292;
        ctoc = anrm / 4.9896007738368E+291;
        if ((cfromc > anrm) && (anrm != 0.0)) {
          b_mul = 2.0041683600089728E-292;
          absxk = cfromc;
        } else if (ctoc > absxk) {
          b_mul = 4.9896007738368E+291;
          anrm = ctoc;
        } else {
          b_mul = anrm / absxk;
          ilascl = false;
        }

        ii = *alpha1_size;
        for (nzcount = 0; nzcount < ii; nzcount++) {
          alpha1_data_0.re = b_mul * alpha1_data[nzcount].re;
          alpha1_data_0.im = b_mul * alpha1_data[nzcount].im;
          alpha1_data[nzcount] = alpha1_data_0;
        }
      }
    }
  }
}

/* Function for MATLAB Function: '<S13>/MATLAB Function' */
static real_T xdlapy3(real_T x1, real_T x2, real_T x3)
{
  real_T y;
  real_T a;
  real_T b;
  real_T c;
  a = fabs(x1);
  b = fabs(x2);
  c = fabs(x3);
  y = fmax(a, b);
  if (c > y) {
    y = c;
  }

  if (y > 0.0) {
    if (!rtIsInf(y)) {
      a /= y;
      b /= y;
      c /= y;
      y *= sqrt((a * a + c * c) + b * b);
    } else {
      y = (a + b) + c;
    }
  } else {
    y = (a + b) + c;
  }

  return y;
}

/* Function for MATLAB Function: '<S13>/MATLAB Function' */
static creal_T recip(const creal_T y)
{
  creal_T z;
  real_T br;
  real_T brm;
  real_T bim;
  brm = fabs(y.re);
  bim = fabs(y.im);
  if (y.im == 0.0) {
    z.re = 1.0 / y.re;
    z.im = 0.0;
  } else if (y.re == 0.0) {
    z.re = 0.0;
    z.im = -1.0 / y.im;
  } else if (brm > bim) {
    brm = y.im / y.re;
    bim = brm * y.im + y.re;
    z.re = 1.0 / bim;
    z.im = -brm / bim;
  } else if (brm == bim) {
    bim = 0.5;
    if (y.re < 0.0) {
      bim = -0.5;
    }

    br = 0.5;
    if (y.im < 0.0) {
      br = -0.5;
    }

    z.re = bim / brm;
    z.im = -br / brm;
  } else {
    brm = y.re / y.im;
    bim = brm * y.re + y.im;
    z.re = brm / bim;
    z.im = -1.0 / bim;
  }

  return z;
}

/* Function for MATLAB Function: '<S13>/MATLAB Function' */
static void xgehrd(creal_T a_data[], int16_T a_size[2])
{
  creal_T tau_data[2];
  int16_T n;
  creal_T work_data[3];
  int16_T im1n;
  int16_T in;
  int16_T ia0;
  creal_T alpha1;
  real_T xnorm;
  int16_T knt;
  int16_T rowleft;
  int16_T iy;
  int16_T h;
  int16_T b_ia;
  int16_T jy;
  int16_T b_ix;
  int16_T d_ix;
  int16_T loop_ub;
  creal_T alpha1_0;
  creal_T a_data_0;
  real_T ar;
  real_T e_c_re;
  real_T e_c_im;
  real_T temp_im;
  int32_T exitg1;
  boolean_T exitg2;
  n = a_size[0];
  loop_ub = (int8_T)a_size[0];
  for (im1n = 0; im1n < loop_ub; im1n++) {
    work_data[im1n].re = 0.0;
    work_data[im1n].im = 0.0;
  }

  for (loop_ub = 0; loop_ub + 1 < n; loop_ub++) {
    im1n = loop_ub * n + 2;
    in = (loop_ub + 1) * n;
    ia0 = (loop_ub * n + n) - 1;
    jy = (n - loop_ub) - 2;
    alpha1 = a_data[(a_size[0] * loop_ub + loop_ub) + 1];
    e_c_re = 0.0;
    e_c_im = 0.0;
    if (!(jy + 1 <= 0)) {
      xnorm = 0.0;
      if (!(jy < 1)) {
        xnorm = rt_hypotd_snf(a_data[ia0].re, a_data[ia0].im);
      }

      if ((xnorm != 0.0) || (a_data[(a_size[0] * loop_ub + loop_ub) + 1].im !=
                             0.0)) {
        xnorm = xdlapy3(a_data[(a_size[0] * loop_ub + loop_ub) + 1].re, a_data
                        [(a_size[0] * loop_ub + loop_ub) + 1].im, xnorm);
        if (a_data[(a_size[0] * loop_ub + loop_ub) + 1].re >= 0.0) {
          xnorm = -xnorm;
        }

        if (fabs(xnorm) < 1.0020841800044864E-292) {
          knt = 0;
          do {
            knt++;
            rowleft = ia0 + jy;
            for (d_ix = ia0; d_ix + 1 <= rowleft; d_ix++) {
              temp_im = a_data[d_ix].re;
              ar = a_data[d_ix].im;
              a_data[d_ix].re = 9.9792015476736E+291 * temp_im - 0.0 * ar;
              a_data[d_ix].im = 9.9792015476736E+291 * ar + 0.0 * temp_im;
            }

            xnorm *= 9.9792015476736E+291;
            alpha1.re *= 9.9792015476736E+291;
            alpha1.im *= 9.9792015476736E+291;
          } while (!(fabs(xnorm) >= 1.0020841800044864E-292));

          xnorm = 0.0;
          if (!(jy < 1)) {
            xnorm = rt_hypotd_snf(a_data[ia0].re, a_data[ia0].im);
          }

          xnorm = xdlapy3(alpha1.re, alpha1.im, xnorm);
          if (alpha1.re >= 0.0) {
            xnorm = -xnorm;
          }

          ar = xnorm - alpha1.re;
          if (0.0 - alpha1.im == 0.0) {
            e_c_re = ar / xnorm;
          } else if (ar == 0.0) {
            e_c_im = (0.0 - alpha1.im) / xnorm;
          } else {
            e_c_re = ar / xnorm;
            e_c_im = (0.0 - alpha1.im) / xnorm;
          }

          alpha1_0.re = alpha1.re - xnorm;
          alpha1_0.im = alpha1.im;
          alpha1 = recip(alpha1_0);
          jy += ia0;
          while (ia0 + 1 <= jy) {
            temp_im = a_data[ia0].re;
            ar = a_data[ia0].im;
            a_data[ia0].re = alpha1.re * temp_im - alpha1.im * ar;
            a_data[ia0].im = alpha1.re * ar + alpha1.im * temp_im;
            ia0++;
          }

          for (ia0 = 1; ia0 <= knt; ia0++) {
            xnorm *= 1.0020841800044864E-292;
          }

          alpha1.re = xnorm;
          alpha1.im = 0.0;
        } else {
          ar = xnorm - a_data[(a_size[0] * loop_ub + loop_ub) + 1].re;
          temp_im = 0.0 - a_data[(a_size[0] * loop_ub + loop_ub) + 1].im;
          if (temp_im == 0.0) {
            e_c_re = ar / xnorm;
          } else if (ar == 0.0) {
            e_c_im = temp_im / xnorm;
          } else {
            e_c_re = ar / xnorm;
            e_c_im = temp_im / xnorm;
          }

          a_data_0.re = a_data[(a_size[0] * loop_ub + loop_ub) + 1].re - xnorm;
          a_data_0.im = a_data[(a_size[0] * loop_ub + loop_ub) + 1].im;
          alpha1 = recip(a_data_0);
          knt = ia0 + jy;
          while (ia0 + 1 <= knt) {
            temp_im = a_data[ia0].re;
            ar = a_data[ia0].im;
            a_data[ia0].re = alpha1.re * temp_im - alpha1.im * ar;
            a_data[ia0].im = alpha1.re * ar + alpha1.im * temp_im;
            ia0++;
          }

          alpha1.re = xnorm;
          alpha1.im = 0.0;
        }
      }
    }

    tau_data[loop_ub].re = e_c_re;
    tau_data[loop_ub].im = e_c_im;
    a_data[(loop_ub + a_size[0] * loop_ub) + 1].re = 1.0;
    a_data[(loop_ub + a_size[0] * loop_ub) + 1].im = 0.0;
    ia0 = (n - loop_ub) - 1;
    jy = (loop_ub + im1n) - 1;
    if ((tau_data[loop_ub].re != 0.0) || (tau_data[loop_ub].im != 0.0)) {
      knt = jy + ia0;
      while ((ia0 > 0) && ((a_data[knt - 1].re == 0.0) && (a_data[knt - 1].im ==
               0.0))) {
        ia0--;
        knt--;
      }

      knt = n;
      exitg2 = false;
      while ((!exitg2) && (knt > 0)) {
        rowleft = in + knt;
        d_ix = rowleft;
        do {
          exitg1 = 0L;
          if (d_ix <= (ia0 - 1) * n + rowleft) {
            if ((a_data[d_ix - 1].re != 0.0) || (a_data[d_ix - 1].im != 0.0)) {
              exitg1 = 1L;
            } else {
              d_ix += n;
            }
          } else {
            knt--;
            exitg1 = 2L;
          }
        } while (exitg1 == 0L);

        if (exitg1 == 1L) {
          exitg2 = true;
        }
      }
    } else {
      ia0 = 0;
      knt = 0;
    }

    if (ia0 > 0) {
      if (knt != 0) {
        for (rowleft = 1; rowleft <= knt; rowleft++) {
          work_data[rowleft - 1].re = 0.0;
          work_data[rowleft - 1].im = 0.0;
        }

        rowleft = jy;
        d_ix = ((ia0 - 1) * n + in) + 1;
        for (b_ix = in + 1; b_ix <= d_ix; b_ix += n) {
          e_c_re = a_data[rowleft].re - 0.0 * a_data[rowleft].im;
          e_c_im = 0.0 * a_data[rowleft].re + a_data[rowleft].im;
          iy = 0;
          h = (b_ix + knt) - 1;
          for (b_ia = b_ix; b_ia <= h; b_ia++) {
            work_data[iy].re += a_data[b_ia - 1].re * e_c_re - a_data[b_ia - 1].
              im * e_c_im;
            work_data[iy].im += a_data[b_ia - 1].re * e_c_im + a_data[b_ia - 1].
              im * e_c_re;
            iy++;
          }

          rowleft++;
        }
      }

      e_c_re = -tau_data[loop_ub].re;
      e_c_im = -tau_data[loop_ub].im;
      if (!((-tau_data[loop_ub].re == 0.0) && (-tau_data[loop_ub].im == 0.0))) {
        rowleft = in;
        for (d_ix = 1; d_ix <= ia0; d_ix++) {
          if ((a_data[jy].re != 0.0) || (a_data[jy].im != 0.0)) {
            xnorm = a_data[jy].re * e_c_re + a_data[jy].im * e_c_im;
            temp_im = a_data[jy].re * e_c_im - a_data[jy].im * e_c_re;
            b_ix = 0;
            iy = knt + rowleft;
            for (h = rowleft; h + 1 <= iy; h++) {
              a_data[h].re += work_data[b_ix].re * xnorm - work_data[b_ix].im *
                temp_im;
              a_data[h].im += work_data[b_ix].re * temp_im + work_data[b_ix].im *
                xnorm;
              b_ix++;
            }
          }

          jy++;
          rowleft += n;
        }
      }
    }

    ia0 = (n - loop_ub) - 1;
    im1n = (loop_ub + im1n) - 1;
    knt = (loop_ub + in) + 2;
    if ((tau_data[loop_ub].re != 0.0) || (-tau_data[loop_ub].im != 0.0)) {
      in = im1n + ia0;
      while ((ia0 > 0) && ((a_data[in - 1].re == 0.0) && (a_data[in - 1].im ==
               0.0))) {
        ia0--;
        in--;
      }

      in = (n - loop_ub) - 1;
      exitg2 = false;
      while ((!exitg2) && (in > 0)) {
        jy = (in - 1) * n + knt;
        rowleft = jy;
        do {
          exitg1 = 0L;
          if (rowleft <= (jy + ia0) - 1) {
            if ((a_data[rowleft - 1].re != 0.0) || (a_data[rowleft - 1].im !=
                 0.0)) {
              exitg1 = 1L;
            } else {
              rowleft++;
            }
          } else {
            in--;
            exitg1 = 2L;
          }
        } while (exitg1 == 0L);

        if (exitg1 == 1L) {
          exitg2 = true;
        }
      }
    } else {
      ia0 = 0;
      in = 0;
    }

    if (ia0 > 0) {
      if (in != 0) {
        for (jy = 1; jy <= in; jy++) {
          work_data[jy - 1].re = 0.0;
          work_data[jy - 1].im = 0.0;
        }

        jy = 0;
        rowleft = (in - 1) * n + knt;
        for (d_ix = knt; d_ix <= rowleft; d_ix += n) {
          b_ix = im1n;
          e_c_re = 0.0;
          e_c_im = 0.0;
          iy = (d_ix + ia0) - 1;
          for (h = d_ix - 1; h + 1 <= iy; h++) {
            e_c_re += a_data[h].re * a_data[b_ix].re + a_data[h].im *
              a_data[b_ix].im;
            e_c_im += a_data[h].re * a_data[b_ix].im - a_data[h].im *
              a_data[b_ix].re;
            b_ix++;
          }

          work_data[jy].re += e_c_re - 0.0 * e_c_im;
          work_data[jy].im += 0.0 * e_c_re + e_c_im;
          jy++;
        }
      }

      e_c_re = -tau_data[loop_ub].re;
      e_c_im = -(-tau_data[loop_ub].im);
      if (!((-tau_data[loop_ub].re == 0.0) && (-(-tau_data[loop_ub].im) == 0.0)))
      {
        knt--;
        jy = 0;
        for (rowleft = 1; rowleft <= in; rowleft++) {
          if ((work_data[jy].re != 0.0) || (work_data[jy].im != 0.0)) {
            xnorm = work_data[jy].re * e_c_re + work_data[jy].im * e_c_im;
            temp_im = work_data[jy].re * e_c_im - work_data[jy].im * e_c_re;
            d_ix = im1n;
            b_ix = ia0 + knt;
            for (iy = knt; iy + 1 <= b_ix; iy++) {
              ar = a_data[d_ix].re * temp_im + a_data[d_ix].im * xnorm;
              a_data[iy].re += a_data[d_ix].re * xnorm - a_data[d_ix].im *
                temp_im;
              a_data[iy].im += ar;
              d_ix++;
            }
          }

          jy++;
          knt += n;
        }
      }
    }

    a_data[(loop_ub + a_size[0] * loop_ub) + 1] = alpha1;
  }
}

/* Function for MATLAB Function: '<S13>/MATLAB Function' */
static void xscal_o(int16_T n, const creal_T a, creal_T x_data[], int16_T ix0,
                    int16_T incx)
{
  int16_T b;
  int16_T k;
  real_T x_data_re;
  real_T x_data_im;
  b = (n - 1) * incx + ix0;
  for (k = ix0; k <= b; k += incx) {
    x_data_re = x_data[k - 1].re;
    x_data_im = x_data[k - 1].im;
    x_data[k - 1].re = a.re * x_data_re - a.im * x_data_im;
    x_data[k - 1].im = a.re * x_data_im + a.im * x_data_re;
  }
}

/* Function for MATLAB Function: '<S13>/MATLAB Function' */
static void xscal(int16_T n, const creal_T a, creal_T x_data[], int16_T ix0)
{
  int16_T b;
  int16_T k;
  real_T x_data_re;
  real_T x_data_im;
  b = (ix0 + n) - 1;
  for (k = ix0; k <= b; k++) {
    x_data_re = x_data[k - 1].re;
    x_data_im = x_data[k - 1].im;
    x_data[k - 1].re = a.re * x_data_re - a.im * x_data_im;
    x_data[k - 1].im = a.re * x_data_im + a.im * x_data_re;
  }
}

/* Function for MATLAB Function: '<S13>/MATLAB Function' */
static creal_T xzlarfg(creal_T *alpha1, creal_T *x)
{
  creal_T tau;
  real_T xnorm;
  int16_T knt;
  int16_T k;
  creal_T alpha1_0;
  real_T ar;
  real_T ai;
  real_T x_re;
  real_T x_im;
  tau.re = 0.0;
  tau.im = 0.0;
  xnorm = rt_hypotd_snf(x->re, x->im);
  if ((xnorm != 0.0) || (alpha1->im != 0.0)) {
    xnorm = xdlapy3(alpha1->re, alpha1->im, xnorm);
    if (alpha1->re >= 0.0) {
      xnorm = -xnorm;
    }

    if (fabs(xnorm) < 1.0020841800044864E-292) {
      knt = 0;
      do {
        knt++;
        x->re *= 9.9792015476736E+291;
        x->im *= 9.9792015476736E+291;
        xnorm *= 9.9792015476736E+291;
        alpha1->re *= 9.9792015476736E+291;
        alpha1->im *= 9.9792015476736E+291;
      } while (!(fabs(xnorm) >= 1.0020841800044864E-292));

      xnorm = xdlapy3(alpha1->re, alpha1->im, rt_hypotd_snf(x->re, x->im));
      if (alpha1->re >= 0.0) {
        xnorm = -xnorm;
      }

      ar = xnorm - alpha1->re;
      ai = 0.0 - alpha1->im;
      if (ai == 0.0) {
        tau.re = ar / xnorm;
        tau.im = 0.0;
      } else if (ar == 0.0) {
        tau.re = 0.0;
        tau.im = ai / xnorm;
      } else {
        tau.re = ar / xnorm;
        tau.im = ai / xnorm;
      }

      alpha1_0.re = alpha1->re - xnorm;
      alpha1_0.im = alpha1->im;
      *alpha1 = recip(alpha1_0);
      ar = alpha1->re;
      ai = alpha1->im;
      x_re = x->re;
      x_im = x->im;
      x->re = ar * x_re - ai * x_im;
      x->im = ar * x_im + ai * x_re;
      for (k = 1; k <= knt; k++) {
        xnorm *= 1.0020841800044864E-292;
      }

      alpha1->re = xnorm;
      alpha1->im = 0.0;
    } else {
      ar = xnorm - alpha1->re;
      ai = 0.0 - alpha1->im;
      if (ai == 0.0) {
        tau.re = ar / xnorm;
        tau.im = 0.0;
      } else if (ar == 0.0) {
        tau.re = 0.0;
        tau.im = ai / xnorm;
      } else {
        tau.re = ar / xnorm;
        tau.im = ai / xnorm;
      }

      alpha1_0.re = alpha1->re - xnorm;
      alpha1_0.im = alpha1->im;
      *alpha1 = recip(alpha1_0);
      ar = alpha1->re;
      ai = alpha1->im;
      x_re = x->re;
      x_im = x->im;
      x->re = ar * x_re - ai * x_im;
      x->im = ar * x_im + ai * x_re;
      alpha1->re = xnorm;
      alpha1->im = 0.0;
    }
  }

  return tau;
}

/* Function for MATLAB Function: '<S13>/MATLAB Function' */
static int32_T xhseqr(creal_T h_data[], int16_T h_size[2])
{
  int32_T info;
  int16_T b_info;
  int16_T n;
  int16_T ldh;
  int16_T i;
  real_T SMLNUM;
  int16_T L;
  boolean_T goto140;
  int16_T k;
  real_T tst;
  real_T htmp1;
  real_T ab;
  real_T ba;
  real_T aa;
  creal_T t;
  creal_T u2;
  boolean_T goto70;
  int16_T m;
  int16_T its;
  int16_T b_k;
  int16_T j;
  creal_T x;
  creal_T u2_0;
  creal_T u2_1;
  real_T v_idx_0_re;
  real_T v_idx_0_im;
  real_T v_idx_1_re;
  real_T v_idx_1_im;
  real_T u2_re;
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T exitg3;
  n = h_size[0];
  ldh = h_size[0];
  b_info = -1;
  if (1 != n) {
    if (1 <= n - 2) {
      h_data[n - 1].re = 0.0;
      h_data[n - 1].im = 0.0;
    }

    for (i = 1; i + 1 <= n; i++) {
      if (h_data[(i - 1) * h_size[0] + i].im != 0.0) {
        SMLNUM = h_data[(i - 1) * h_size[0] + i].re;
        ab = h_data[(i - 1) * h_size[0] + i].im;
        htmp1 = fabs(h_data[(i - 1) * h_size[0] + i].re) + fabs(h_data[(i - 1) *
          h_size[0] + i].im);
        if (ab == 0.0) {
          u2.re = SMLNUM / htmp1;
          u2.im = 0.0;
        } else if (SMLNUM == 0.0) {
          u2.re = 0.0;
          u2.im = ab / htmp1;
        } else {
          u2.re = SMLNUM / htmp1;
          u2.im = ab / htmp1;
        }

        htmp1 = rt_hypotd_snf(u2.re, u2.im);
        if (-u2.im == 0.0) {
          u2.re /= htmp1;
          u2.im = 0.0;
        } else if (u2.re == 0.0) {
          u2.re = 0.0;
          u2.im = -u2.im / htmp1;
        } else {
          u2.re /= htmp1;
          u2.im = -u2.im / htmp1;
        }

        h_data[i + h_size[0] * (i - 1)].re = rt_hypotd_snf(h_data[(i - 1) *
          h_size[0] + i].re, h_data[(i - 1) * h_size[0] + i].im);
        h_data[i + h_size[0] * (i - 1)].im = 0.0;
        its = i * ldh + i;
        L = (((n - i) - 1) * ldh + its) + 1;
        while (its + 1 <= L) {
          ab = h_data[its].re;
          ba = h_data[its].im;
          h_data[its].re = u2.re * ab - u2.im * ba;
          h_data[its].im = u2.re * ba + u2.im * ab;
          its += ldh;
        }

        L = i * ldh;
        u2.im = -u2.im;
        its = L + n;
        while (L + 1 <= its) {
          ab = h_data[L].re;
          ba = h_data[L].im;
          h_data[L].re = u2.re * ab - u2.im * ba;
          h_data[L].im = u2.re * ba + u2.im * ab;
          L++;
        }
      }
    }

    SMLNUM = (real_T)n / 2.2204460492503131E-16 * 2.2250738585072014E-308;
    i = n - 1;
    exitg1 = false;
    while ((!exitg1) && (i + 1 >= 1)) {
      L = -1;
      goto140 = false;
      its = 0;
      exitg2 = false;
      while ((!exitg2) && (its < 31)) {
        k = i;
        exitg3 = false;
        while ((!exitg3) && ((k + 1 > L + 2) && (!(fabs(h_data[(k - 1) * h_size
                   [0] + k].re) + fabs(h_data[(k - 1) * h_size[0] + k].im) <=
                  SMLNUM)))) {
          tst = (fabs(h_data[((k - 1) * h_size[0] + k) - 1].re) + fabs(h_data
                  [((k - 1) * h_size[0] + k) - 1].im)) + (fabs(h_data[h_size[0] *
            k + k].re) + fabs(h_data[h_size[0] * k + k].im));
          if (tst == 0.0) {
            if (k - 1 >= 1) {
              tst = fabs(h_data[((k - 2) * h_size[0] + k) - 1].re);
            }

            if (k + 2 <= n) {
              tst += fabs(h_data[(h_size[0] * k + k) + 1].re);
            }
          }

          if (fabs(h_data[(k - 1) * h_size[0] + k].re) <= 2.2204460492503131E-16
              * tst) {
            htmp1 = fabs(h_data[(k - 1) * h_size[0] + k].re) + fabs(h_data[(k -
              1) * h_size[0] + k].im);
            tst = fabs(h_data[(h_size[0] * k + k) - 1].re) + fabs(h_data
              [(h_size[0] * k + k) - 1].im);
            if (htmp1 > tst) {
              ab = htmp1;
              ba = tst;
            } else {
              ab = tst;
              ba = htmp1;
            }

            htmp1 = fabs(h_data[h_size[0] * k + k].re) + fabs(h_data[h_size[0] *
              k + k].im);
            tst = fabs(h_data[((k - 1) * h_size[0] + k) - 1].re - h_data[h_size
                       [0] * k + k].re) + fabs(h_data[((k - 1) * h_size[0] + k)
              - 1].im - h_data[h_size[0] * k + k].im);
            if (htmp1 > tst) {
              aa = htmp1;
              htmp1 = tst;
            } else {
              aa = tst;
            }

            tst = aa + ab;
            if (ab / tst * ba <= fmax(SMLNUM, aa / tst * htmp1 *
                 2.2204460492503131E-16)) {
              exitg3 = true;
            } else {
              k--;
            }
          } else {
            k--;
          }
        }

        L = k - 1;
        if (k + 1 > 1) {
          h_data[k + h_size[0] * (k - 1)].re = 0.0;
          h_data[k + h_size[0] * (k - 1)].im = 0.0;
        }

        if (k + 1 >= i + 1) {
          goto140 = true;
          exitg2 = true;
        } else {
          switch (its) {
           case 10:
            t.re = fabs(h_data[(h_size[0] * k + k) + 1].re) * 0.75 +
              h_data[h_size[0] * k + k].re;
            t.im = h_data[h_size[0] * k + k].im;
            break;

           case 20:
            t.re = fabs(h_data[(i - 1) * h_size[0] + i].re) * 0.75 +
              h_data[h_size[0] * i + i].re;
            t.im = h_data[h_size[0] * i + i].im;
            break;

           default:
            t = h_data[h_size[0] * i + i];
            u2 = h_data[(h_size[0] * i + i) - 1];
            sqrt_d(&u2);
            x = h_data[(i - 1) * h_size[0] + i];
            sqrt_d(&x);
            ab = u2.re * x.re - u2.im * x.im;
            ba = u2.re * x.im + u2.im * x.re;
            tst = fabs(ab) + fabs(ba);
            if (tst != 0.0) {
              x.re = (h_data[((i - 1) * h_size[0] + i) - 1].re - h_data[h_size[0]
                      * i + i].re) * 0.5;
              x.im = (h_data[((i - 1) * h_size[0] + i) - 1].im - h_data[h_size[0]
                      * i + i].im) * 0.5;
              htmp1 = fabs(x.re) + fabs(x.im);
              tst = fmax(tst, fabs(x.re) + fabs(x.im));
              if (x.im == 0.0) {
                t.re = x.re / tst;
                t.im = 0.0;
              } else if (x.re == 0.0) {
                t.re = 0.0;
                t.im = x.im / tst;
              } else {
                t.re = x.re / tst;
                t.im = x.im / tst;
              }

              if (ba == 0.0) {
                u2.re = ab / tst;
                u2.im = 0.0;
              } else if (ab == 0.0) {
                u2.re = 0.0;
                u2.im = ba / tst;
              } else {
                u2.re = ab / tst;
                u2.im = ba / tst;
              }

              aa = u2.re;
              u2_re = u2.re;
              u2.re = u2.re * u2.re - u2.im * u2.im;
              u2.im = aa * u2.im + u2.im * u2_re;
              u2.re += t.re * t.re - t.im * t.im;
              u2.im += t.re * t.im + t.im * t.re;
              sqrt_d(&u2);
              u2.re *= tst;
              u2.im *= tst;
              if (htmp1 > 0.0) {
                if (x.im == 0.0) {
                  t.re = x.re / htmp1;
                  t.im = 0.0;
                } else if (x.re == 0.0) {
                  t.re = 0.0;
                  t.im = x.im / htmp1;
                } else {
                  t.re = x.re / htmp1;
                  t.im = x.im / htmp1;
                }

                if (t.re * u2.re + t.im * u2.im < 0.0) {
                  u2.re = -u2.re;
                  u2.im = -u2.im;
                }
              }

              htmp1 = x.re + u2.re;
              aa = x.im + u2.im;
              if (aa == 0.0) {
                if (ba == 0.0) {
                  tst = ab / htmp1;
                  htmp1 = 0.0;
                } else if (ab == 0.0) {
                  tst = 0.0;
                  htmp1 = ba / htmp1;
                } else {
                  tst = ab / htmp1;
                  htmp1 = ba / htmp1;
                }
              } else if (htmp1 == 0.0) {
                if (ab == 0.0) {
                  tst = ba / aa;
                  htmp1 = 0.0;
                } else if (ba == 0.0) {
                  tst = 0.0;
                  htmp1 = -(ab / aa);
                } else {
                  tst = ba / aa;
                  htmp1 = -(ab / aa);
                }
              } else {
                u2_re = fabs(htmp1);
                tst = fabs(aa);
                if (u2_re > tst) {
                  u2_re = aa / htmp1;
                  htmp1 += u2_re * aa;
                  tst = (u2_re * ba + ab) / htmp1;
                  htmp1 = (ba - u2_re * ab) / htmp1;
                } else if (tst == u2_re) {
                  htmp1 = htmp1 > 0.0 ? 0.5 : -0.5;
                  aa = aa > 0.0 ? 0.5 : -0.5;
                  tst = (ab * htmp1 + ba * aa) / u2_re;
                  htmp1 = (ba * htmp1 - ab * aa) / u2_re;
                } else {
                  u2_re = htmp1 / aa;
                  htmp1 = u2_re * htmp1 + aa;
                  tst = (u2_re * ab + ba) / htmp1;
                  htmp1 = (u2_re * ba - ab) / htmp1;
                }
              }

              t.re = h_data[h_size[0] * i + i].re - (ab * tst - ba * htmp1);
              t.im = h_data[h_size[0] * i + i].im - (ab * htmp1 + ba * tst);
            }
            break;
          }

          goto70 = false;
          m = i;
          exitg3 = false;
          while ((!exitg3) && (m > k + 1)) {
            u2.re = h_data[1 + h_size[0]].re - t.re;
            u2.im = h_data[1 + h_size[0]].im - t.im;
            htmp1 = h_data[2 + h_size[0]].re;
            tst = (fabs(u2.re) + fabs(u2.im)) + fabs(htmp1);
            if (u2.im == 0.0) {
              u2.re /= tst;
              u2.im = 0.0;
            } else if (u2.re == 0.0) {
              u2.re = 0.0;
              u2.im /= tst;
            } else {
              u2.re /= tst;
              u2.im /= tst;
            }

            htmp1 /= tst;
            v_idx_0_re = u2.re;
            v_idx_0_im = u2.im;
            v_idx_1_re = htmp1;
            v_idx_1_im = 0.0;
            if (fabs(h_data[1].re) * fabs(htmp1) <= ((fabs(h_data[(h_size[0] <<
                    1) + 2].re) + fabs(h_data[(h_size[0] << 1) + 2].im)) + (fabs
                  (h_data[1 + h_size[0]].re) + fabs(h_data[1 + h_size[0]].im))) *
                (fabs(u2.re) + fabs(u2.im)) * 2.2204460492503131E-16) {
              goto70 = true;
              exitg3 = true;
            } else {
              m = 1;
            }
          }

          if (!goto70) {
            u2.re = h_data[h_size[0] * k + k].re - t.re;
            u2.im = h_data[h_size[0] * k + k].im - t.im;
            htmp1 = h_data[(h_size[0] * k + k) + 1].re;
            tst = (fabs(u2.re) + fabs(u2.im)) + fabs(htmp1);
            if (u2.im == 0.0) {
              u2.re /= tst;
              u2.im = 0.0;
            } else if (u2.re == 0.0) {
              u2.re = 0.0;
              u2.im /= tst;
            } else {
              u2.re /= tst;
              u2.im /= tst;
            }

            htmp1 /= tst;
            v_idx_0_re = u2.re;
            v_idx_0_im = u2.im;
            v_idx_1_re = htmp1;
            v_idx_1_im = 0.0;
          }

          for (b_k = m; b_k <= i; b_k++) {
            if (b_k > m) {
              v_idx_0_re = h_data[1].re;
              v_idx_0_im = h_data[1].im;
              v_idx_1_re = h_data[2].re;
              v_idx_1_im = h_data[2].im;
            }

            u2.re = v_idx_0_re;
            u2.im = v_idx_0_im;
            x.re = v_idx_1_re;
            x.im = v_idx_1_im;
            t = xzlarfg(&u2, &x);
            v_idx_0_re = u2.re;
            v_idx_0_im = u2.im;
            v_idx_1_re = x.re;
            v_idx_1_im = x.im;
            if (b_k > m) {
              h_data[1] = u2;
              h_data[2].re = 0.0;
              h_data[2].im = 0.0;
            }

            ab = t.re * x.re - t.im * x.im;
            for (j = b_k - 1; j + 1 <= n; j++) {
              u2.re = (h_data[(h_size[0] * j + b_k) - 1].re * t.re - h_data
                       [(h_size[0] * j + b_k) - 1].im * -t.im) + h_data[h_size[0]
                * j + b_k].re * ab;
              u2.im = (h_data[(h_size[0] * j + b_k) - 1].im * t.re + h_data
                       [(h_size[0] * j + b_k) - 1].re * -t.im) + h_data[h_size[0]
                * j + b_k].im * ab;
              h_data[(b_k + h_size[0] * j) - 1].re -= u2.re;
              h_data[(b_k + h_size[0] * j) - 1].im -= u2.im;
              h_data[b_k + h_size[0] * j].re -= u2.re * x.re - u2.im * x.im;
              h_data[b_k + h_size[0] * j].im -= u2.re * x.im + u2.im * x.re;
            }

            for (j = 0; j + 1 <= i + 1; j++) {
              u2.re = (h_data[(b_k - 1) * h_size[0] + j].re * t.re - h_data[(b_k
                        - 1) * h_size[0] + j].im * t.im) + h_data[h_size[0] *
                b_k + j].re * ab;
              u2.im = (h_data[(b_k - 1) * h_size[0] + j].im * t.re + h_data[(b_k
                        - 1) * h_size[0] + j].re * t.im) + h_data[h_size[0] *
                b_k + j].im * ab;
              h_data[j + h_size[0] * (b_k - 1)].re -= u2.re;
              h_data[j + h_size[0] * (b_k - 1)].im -= u2.im;
              h_data[j + h_size[0] * b_k].re -= u2.re * x.re - u2.im * -x.im;
              h_data[j + h_size[0] * b_k].im -= u2.re * -x.im + u2.im * x.re;
            }

            if ((b_k == m) && (m > k + 1)) {
              htmp1 = rt_hypotd_snf(1.0 - t.re, 0.0 - t.im);
              if (0.0 - t.im == 0.0) {
                u2.re = (1.0 - t.re) / htmp1;
                u2.im = 0.0;
              } else if (1.0 - t.re == 0.0) {
                u2.re = 0.0;
                u2.im = (0.0 - t.im) / htmp1;
              } else {
                u2.re = (1.0 - t.re) / htmp1;
                u2.im = (0.0 - t.im) / htmp1;
              }

              ab = h_data[2 + h_size[0]].re;
              ba = h_data[2 + h_size[0]].im;
              h_data[2 + h_size[0]].re = ab * u2.re - ba * -u2.im;
              h_data[2 + h_size[0]].im = ab * -u2.im + ba * u2.re;
              for (j = 2; j <= i + 1; j++) {
                if (j != 3) {
                  if (n > 2) {
                    xscal_o(1, u2, h_data, 2 + (ldh << 1), ldh);
                  }

                  u2_0.re = u2.re;
                  u2_0.im = -u2.im;
                  xscal(1, u2_0, h_data, 1 + ldh);
                }
              }
            }
          }

          u2 = h_data[(i - 1) * h_size[0] + i];
          if (h_data[(i - 1) * h_size[0] + i].im != 0.0) {
            tst = rt_hypotd_snf(h_data[(i - 1) * h_size[0] + i].re, h_data[(i -
              1) * h_size[0] + i].im);
            h_data[i + h_size[0] * (i - 1)].re = tst;
            h_data[i + h_size[0] * (i - 1)].im = 0.0;
            if (u2.im == 0.0) {
              u2.re /= tst;
              u2.im = 0.0;
            } else if (u2.re == 0.0) {
              u2.re = 0.0;
              u2.im /= tst;
            } else {
              u2.re /= tst;
              u2.im /= tst;
            }

            if (n > i + 1) {
              u2_1.re = u2.re;
              u2_1.im = -u2.im;
              xscal_o(1, u2_1, h_data, 2 + (ldh << 1), ldh);
            }

            xscal(i, u2, h_data, 1 + i * ldh);
          }

          its++;
        }
      }

      if (!goto140) {
        b_info = i;
        exitg1 = true;
      } else {
        i = L;
      }
    }
  }

  info = b_info + 1;
  return info;
}

/* Function for MATLAB Function: '<S13>/MATLAB Function' */
static void roots(const real_T c[4], creal_T r_data[], int16_T *r_size)
{
  int16_T k1;
  int16_T k2;
  int16_T companDim;
  real_T ctmp[4];
  int16_T j;
  creal_T a_data[9];
  creal_T eiga_data[3];
  int32_T info;
  creal_T beta1_data[3];
  boolean_T b_p;
  int16_T c_j;
  int16_T b_i;
  int16_T a_size[2];
  int16_T eiga_size;
  int16_T beta1_size;
  real_T brm;
  real_T bim;
  real_T sgnbi;
  creal_T eiga_data_0;
  boolean_T exitg1;
  boolean_T exitg2;
  int32_T exitg3;
  r_data[0].re = 0.0;
  r_data[0].im = 0.0;
  r_data[1].re = 0.0;
  r_data[1].im = 0.0;
  r_data[2].re = 0.0;
  r_data[2].im = 0.0;
  k1 = 1;
  while ((k1 <= 4) && (!(c[k1 - 1] != 0.0))) {
    k1++;
  }

  k2 = 4;
  while ((k2 >= k1) && (!(c[k2 - 1] != 0.0))) {
    k2--;
  }

  if (k1 < k2) {
    companDim = k2 - k1;
    exitg1 = false;
    while ((!exitg1) && (companDim > 0)) {
      j = 0;
      exitg2 = false;
      while ((!exitg2) && (j + 1 <= companDim)) {
        ctmp[j] = c[k1 + j] / c[k1 - 1];
        if (rtIsInf(fabs(ctmp[j]))) {
          exitg2 = true;
        } else {
          j++;
        }
      }

      if (j + 1 > companDim) {
        exitg1 = true;
      } else {
        k1++;
        companDim--;
      }
    }

    if (companDim < 1) {
      if (1 > 4 - k2) {
        *r_size = 0;
      } else {
        *r_size = 4 - k2;
      }
    } else {
      a_size[0] = companDim;
      a_size[1] = companDim;
      j = companDim * companDim;
      for (k1 = 0; k1 < j; k1++) {
        a_data[k1].re = 0.0;
        a_data[k1].im = 0.0;
      }

      for (k1 = 0; k1 + 1 < companDim; k1++) {
        a_data[companDim * k1].re = -ctmp[k1];
        a_data[companDim * k1].im = 0.0;
        a_data[(k1 + companDim * k1) + 1].re = 1.0;
        a_data[(k1 + companDim * k1) + 1].im = 0.0;
      }

      a_data[companDim * (companDim - 1)].re = -ctmp[companDim - 1];
      a_data[companDim * (companDim - 1)].im = 0.0;
      for (k1 = 1; k1 <= 4 - k2; k1++) {
        r_data[k1 - 1].re = 0.0;
        r_data[k1 - 1].im = 0.0;
      }

      if (anyNonFinite(a_data, a_size)) {
        if (companDim == 1) {
          eiga_data[0].re = (rtNaN);
          eiga_data[0].im = 0.0;
        } else {
          for (k1 = 0; k1 < companDim; k1++) {
            eiga_data[k1].re = (rtNaN);
            eiga_data[k1].im = 0.0;
          }
        }
      } else if (companDim == 1) {
        eiga_data[0] = a_data[0];
      } else {
        b_p = true;
        k1 = 0;
        exitg1 = false;
        while ((!exitg1) && (k1 <= companDim - 1)) {
          j = 0;
          do {
            exitg3 = 0L;
            if (j <= k1) {
              if (!((a_data[companDim * k1 + j].re == a_data[companDim * j + k1]
                     .re) && (a_data[companDim * k1 + j].im == -a_data[companDim
                              * j + k1].im))) {
                b_p = false;
                exitg3 = 1L;
              } else {
                j++;
              }
            } else {
              k1++;
              exitg3 = 2L;
            }
          } while (exitg3 == 0L);

          if (exitg3 == 1L) {
            exitg1 = true;
          }
        }

        if (b_p) {
          if (anyNonFinite(a_data, a_size)) {
            a_size[0] = (int8_T)companDim;
            j = (int8_T)companDim * (int8_T)companDim;
            for (k1 = 0; k1 < j; k1++) {
              a_data[k1].re = (rtNaN);
              a_data[k1].im = 0.0;
            }

            if (!(1 >= (int8_T)companDim)) {
              j = 2;
              if ((int8_T)companDim - 2 < (int8_T)companDim - 1) {
                k1 = (int8_T)companDim - 1;
              } else {
                k1 = (int8_T)companDim;
              }

              for (c_j = 1; c_j <= k1; c_j++) {
                for (b_i = j; b_i <= (int8_T)companDim; b_i++) {
                  a_data[(b_i + (int8_T)companDim * (c_j - 1)) - 1].re = 0.0;
                  a_data[(b_i + (int8_T)companDim * (c_j - 1)) - 1].im = 0.0;
                }

                j++;
              }
            }
          } else {
            xgehrd(a_data, a_size);
            xhseqr(a_data, a_size);
          }

          for (k1 = 0; k1 + 1 <= a_size[0]; k1++) {
            eiga_data[k1] = a_data[a_size[0] * k1 + k1];
          }
        } else {
          xzgeev(a_data, a_size, &info, eiga_data, &eiga_size, beta1_data,
                 &beta1_size);
          j = eiga_size;
          for (k1 = 0; k1 < j; k1++) {
            if (beta1_data[k1].im == 0.0) {
              if (eiga_data[k1].im == 0.0) {
                eiga_data_0.re = eiga_data[k1].re / beta1_data[k1].re;
                eiga_data_0.im = 0.0;
              } else if (eiga_data[k1].re == 0.0) {
                eiga_data_0.re = 0.0;
                eiga_data_0.im = eiga_data[k1].im / beta1_data[k1].re;
              } else {
                eiga_data_0.re = eiga_data[k1].re / beta1_data[k1].re;
                eiga_data_0.im = eiga_data[k1].im / beta1_data[k1].re;
              }
            } else if (beta1_data[k1].re == 0.0) {
              if (eiga_data[k1].re == 0.0) {
                eiga_data_0.re = eiga_data[k1].im / beta1_data[k1].im;
                eiga_data_0.im = 0.0;
              } else if (eiga_data[k1].im == 0.0) {
                eiga_data_0.re = 0.0;
                eiga_data_0.im = -(eiga_data[k1].re / beta1_data[k1].im);
              } else {
                eiga_data_0.re = eiga_data[k1].im / beta1_data[k1].im;
                eiga_data_0.im = -(eiga_data[k1].re / beta1_data[k1].im);
              }
            } else {
              brm = fabs(beta1_data[k1].re);
              bim = fabs(beta1_data[k1].im);
              if (brm > bim) {
                brm = beta1_data[k1].im / beta1_data[k1].re;
                bim = brm * beta1_data[k1].im + beta1_data[k1].re;
                eiga_data_0.re = (brm * eiga_data[k1].im + eiga_data[k1].re) /
                  bim;
                eiga_data_0.im = (eiga_data[k1].im - brm * eiga_data[k1].re) /
                  bim;
              } else if (bim == brm) {
                bim = beta1_data[k1].re > 0.0 ? 0.5 : -0.5;
                sgnbi = beta1_data[k1].im > 0.0 ? 0.5 : -0.5;
                eiga_data_0.re = (eiga_data[k1].re * bim + eiga_data[k1].im *
                                  sgnbi) / brm;
                eiga_data_0.im = (eiga_data[k1].im * bim - eiga_data[k1].re *
                                  sgnbi) / brm;
              } else {
                brm = beta1_data[k1].re / beta1_data[k1].im;
                bim = brm * beta1_data[k1].re + beta1_data[k1].im;
                eiga_data_0.re = (brm * eiga_data[k1].re + eiga_data[k1].im) /
                  bim;
                eiga_data_0.im = (brm * eiga_data[k1].im - eiga_data[k1].re) /
                  bim;
              }
            }

            eiga_data[k1] = eiga_data_0;
          }
        }
      }

      for (k1 = 1; k1 <= companDim; k1++) {
        r_data[(k1 - k2) + 3] = eiga_data[k1 - 1];
      }

      *r_size = (companDim - k2) + 4;
    }
  } else if (1 > 4 - k2) {
    *r_size = 0;
  } else {
    *r_size = 4 - k2;
  }
}

/* Model step function */
void Cruise_step(void)
{
  int32_T bitIdx;
  int16_T i;
  creal_T r_data[3];
  boolean_T b_data[3];
  int16_T trueCount;
  int16_T b_i;
  real_T y_data[3];
  real_T x_data[3];
  int16_T tableOffset;
  uint32_T rtb_Prelookup_o1;
  real_T rtb_Add_e;
  real_T rtb_MultiportSwitch;
  real_T rtb_Divide1;
  real_T rtb_Add;
  boolean_T rtb_TmpSignalConversionAtBittoI[2];
  uint8_T rtb_BittoIntegerConverter;
  real_T tmp[4];
  int16_T r_size;

  /* Sum: '<S2>/Add' incorporates:
   *  Gain: '<S2>/Gain'
   *  Inport: '<Root>/Battery Capacity (Wh)'
   *  Inport: '<Root>/Reserve %'
   *  Inport: '<Root>/SOC %'
   *  Inport: '<Root>/Solar Power (W)'
   *  Inport: '<Root>/Time Remaining (h)'
   *  Product: '<S2>/Multiply'
   *  Product: '<S2>/Multiply1'
   *  Sum: '<S2>/Add1'
   */
  rtb_Add = (rtU.SOC - rtU.Reserve) * 0.01 * rtU.BatteryCapacityWh +
    rtU.SolarPowerW * rtU.TimeRemainingh;

  /* Sum: '<S4>/Add' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Inport: '<Root>/Net Distance (miles)'
   */
  rtb_MultiportSwitch = 1999.4957999999995 - rtU.NetDistancemiles;

  /* Saturate: '<S4>/Saturation' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Inport: '<Root>/Net Distance (miles)'
   *  Sum: '<S4>/Add'
   */
  if (1999.4957999999995 - rtU.NetDistancemiles <= 0.0) {
    rtb_MultiportSwitch = 0.0;
  }

  /* End of Saturate: '<S4>/Saturation' */

  /* Product: '<S4>/Divide' incorporates:
   *  Inport: '<Root>/Time Remaining (h)'
   */
  rtb_Add_e = rtb_MultiportSwitch / rtU.TimeRemainingh;

  /* Product: '<S4>/Divide1' incorporates:
   *  Constant: '<S4>/Constant'
   *  Math: '<S4>/Math Function'
   *
   * About '<S4>/Math Function':
   *  Operator: magnitude^2
   */
  rtb_Divide1 = rtb_Add_e * rtb_Add_e * rtb_MultiportSwitch * 37.436168734173037;

  /* PreLookup: '<S5>/Prelookup' incorporates:
   *  Inport: '<Root>/Net Distance (miles)'
   */
  rtb_Prelookup_o1 = plook_binc(rtU.NetDistancemiles,
    rtConstP.Prelookup_BreakpointsData, 41UL, &rtb_Add_e);

  /* LookupNDDirect: '<S5>/Direct Lookup Table (n-D)' incorporates:
   *  MATLAB Function: '<S13>/MATLAB Function'
   *  Product: '<S14>/Divide1'
   *  Product: '<S4>/Multiply2'
   *
   * About '<S5>/Direct Lookup Table (n-D)':
   *  2-dimensional Direct Look-Up returning a Column
   */
  if (!(rtb_Prelookup_o1 < 40UL)) {
    rtb_Prelookup_o1 = 40UL;
  }

  tableOffset = (int16_T)rtb_Prelookup_o1 * 3 + 2;

  /* Sum: '<S4>/Add1' incorporates:
   *  Constant: '<S4>/Constant3'
   *  LookupNDDirect: '<S5>/Direct Lookup Table (n-D)'
   *  MATLAB Function: '<S13>/MATLAB Function'
   *  Product: '<S14>/Divide1'
   *  Product: '<S4>/Multiply2'
   *  Sum: '<S4>/Add3'
   *
   * About '<S5>/Direct Lookup Table (n-D)':
   *  2-dimensional Direct Look-Up returning a Column
   */
  rtb_Add_e = rtConstP.DirectLookupTablenD_table[tableOffset - 1] * (1.0 -
    rtb_Add_e) + rtConstP.DirectLookupTablenD_table[tableOffset - 2];

  /* Sum: '<S4>/Add2' incorporates:
   *  Gain: '<S4>/To Wh'
   */
  rtb_Divide1 = 0.00027777777777777778 * rtb_Divide1 + rtb_Add_e;

  /* Gain: '<S3>/Gain' incorporates:
   *  Inport: '<Root>/Time Remaining (h)'
   */
  rtb_MultiportSwitch = 5000.0 * rtU.TimeRemainingh;

  /* Switch: '<S8>/Switch2' incorporates:
   *  RelationalOperator: '<S8>/LowerRelop1'
   */
  if (!(rtb_Add > rtb_MultiportSwitch)) {
    /* Switch: '<S8>/Switch' incorporates:
     *  Constant: '<S3>/Constant2'
     *  RelationalOperator: '<S8>/UpperRelop'
     */
    if (rtb_Add < 0.0) {
      rtb_MultiportSwitch = 0.0;
    } else {
      rtb_MultiportSwitch = rtb_Add;
    }

    /* End of Switch: '<S8>/Switch' */
  }

  /* End of Switch: '<S8>/Switch2' */

  /* Gain: '<S3>/To Joules' incorporates:
   *  Sum: '<S3>/Add'
   */
  rtb_MultiportSwitch = (rtb_MultiportSwitch - rtb_Add_e) * 3600.0;

  /* Sum: '<S3>/Add1' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Inport: '<Root>/Net Distance (miles)'
   */
  rtb_Add_e = 1999.4957999999995 - rtU.NetDistancemiles;

  /* Saturate: '<S3>/Saturation' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Inport: '<Root>/Net Distance (miles)'
   *  Sum: '<S3>/Add1'
   */
  if (1999.4957999999995 - rtU.NetDistancemiles <= 0.0) {
    rtb_Add_e = 0.0;
  }

  /* End of Saturate: '<S3>/Saturation' */

  /* Sqrt: '<S3>/Sqrt' incorporates:
   *  Constant: '<S3>/Constant'
   *  Product: '<S3>/Divide'
   */
  rtb_MultiportSwitch = sqrt(rtb_MultiportSwitch / 37.436168734173037 /
    rtb_Add_e);

  /* Saturate: '<S3>/Saturation2' */
  if (rtb_MultiportSwitch > 62.137273664980675) {
    rtb_MultiportSwitch = 62.137273664980675;
  } else {
    if (rtb_MultiportSwitch < 0.0) {
      rtb_MultiportSwitch = 0.0;
    }
  }

  /* End of Saturate: '<S3>/Saturation2' */

  /* Product: '<S3>/Divide1' */
  rtb_Add_e *= 1.0 / rtb_MultiportSwitch;

  /* SignalConversion: '<S7>/TmpSignal ConversionAtBit to Integer ConverterInport1' incorporates:
   *  Gain: '<S7>/Gain2'
   *  Inport: '<Root>/Time Remaining (h)'
   *  RelationalOperator: '<S7>/Relational Operator'
   *  RelationalOperator: '<S7>/Relational Operator1'
   */
  rtb_TmpSignalConversionAtBittoI[0] = (rtb_Add < rtb_Divide1);
  rtb_TmpSignalConversionAtBittoI[1] = (0.95 * rtU.TimeRemainingh < rtb_Add_e);

  /* S-Function (scominttobit): '<S7>/Bit to Integer Converter' */
  /* Bit to Integer Conversion */
  bitIdx = 0L;
  i = 0;
  while (i < 1) {
    /* Input bit order is MSB first */
    rtb_Prelookup_o1 = rtb_TmpSignalConversionAtBittoI[bitIdx];
    bitIdx++;

    /* Input bit order is MSB first */
    rtb_Prelookup_o1 = (uint32_T)((int16_T)rtb_Prelookup_o1 << 1);
    rtb_Prelookup_o1 = (uint32_T)((int16_T)rtb_Prelookup_o1 |
      rtb_TmpSignalConversionAtBittoI[bitIdx]);
    bitIdx++;
    rtb_BittoIntegerConverter = (uint8_T)rtb_Prelookup_o1;
    i = 1;
  }

  /* End of S-Function (scominttobit): '<S7>/Bit to Integer Converter' */

  /* MultiPortSwitch: '<S7>/Multiport Switch' */
  switch (rtb_BittoIntegerConverter) {
   case 0:
    /* Outport: '<Root>/Error' incorporates:
     *  Constant: '<S7>/Green'
     */
    rtY.Error = 0.0;
    break;

   case 1:
    /* Outport: '<Root>/Error' incorporates:
     *  Constant: '<S7>/Yellow'
     */
    rtY.Error = 1.0;
    break;

   case 2:
    /* Outport: '<Root>/Error' incorporates:
     *  Constant: '<S7>/Red'
     */
    rtY.Error = 2.0;
    break;

   default:
    /* Outport: '<Root>/Error' incorporates:
     *  Constant: '<S7>/Red1'
     */
    rtY.Error = 2.0;
    break;
  }

  /* End of MultiPortSwitch: '<S7>/Multiport Switch' */

  /* Product: '<S6>/Divide1' incorporates:
   *  Gain: '<S11>/Gain'
   *  Inport: '<Root>/Battery Capacity (Wh)'
   *  Inport: '<Root>/Reserve %'
   *  Inport: '<Root>/SOC %'
   *  Inport: '<Root>/Safety Factor'
   *  Inport: '<Root>/Solar Power (W)'
   *  Inport: '<Root>/Time Remaining (h)'
   *  MinMax: '<S1>/Min'
   *  Product: '<S11>/Divide'
   *  Product: '<S11>/Divide1'
   *  Sum: '<S6>/Sum'
   *  Sum: '<S6>/Sum1'
   */
  rtb_MultiportSwitch = ((rtU.SOC - rtU.Reserve) * 0.01 * (rtU.BatteryCapacityWh
    / fmin(rtU.TimeRemainingh, rtb_Add_e)) + rtU.SolarPowerW) / rtU.SafetyFactor;

  /* Saturate: '<S6>/Saturation2' */
  if (rtb_MultiportSwitch > 5000.0) {
    rtb_MultiportSwitch = 5000.0;
  } else {
    if (rtb_MultiportSwitch < 0.0) {
      rtb_MultiportSwitch = 0.0;
    }
  }

  /* End of Saturate: '<S6>/Saturation2' */

  /* Sum: '<S6>/Add' incorporates:
   *  Constant: '<S14>/Constant'
   *  Constant: '<S14>/Constant1'
   *  Inport: '<Root>/Measured Power (W)'
   *  Inport: '<Root>/Measured Velocity (mph)'
   *  LookupNDDirect: '<S5>/Direct Lookup Table (n-D)'
   *  Math: '<S14>/Math Function'
   *  Product: '<S14>/Divide'
   *  Product: '<S14>/Divide1'
   *  Sum: '<S12>/Add'
   *  Sum: '<S14>/Add'
   *
   * About '<S5>/Direct Lookup Table (n-D)':
   *  2-dimensional Direct Look-Up returning a Column
   */
  rtb_Add_e = ((rt_powd_snf(rtU.MeasuredVelocitymph, 3.0) * 0.011004164824859799
                + rtU.MeasuredVelocitymph *
                rtConstP.DirectLookupTablenD_table[tableOffset]) -
               rtU.MeasuredPowerW) + rtb_MultiportSwitch;

  /* MATLAB Function: '<S13>/MATLAB Function' incorporates:
   *  LookupNDDirect: '<S5>/Direct Lookup Table (n-D)'
   *  Saturate: '<S6>/Saturation1'
   *
   * About '<S5>/Direct Lookup Table (n-D)':
   *  2-dimensional Direct Look-Up returning a Column
   */
  /* MATLAB Function 'Cruise Control System/Set Optimal Speed/Power to Speed/MATLAB Function': '<S15>:1' */
  /* '<S15>:1:3' r=ones(3,2); */
  /* '<S15>:1:4' r=roots([mult_velcubed_ToPower 0 vel_to_power_mult -power]); */
  tmp[0] = 0.011004164824859799;
  tmp[1] = 0.0;
  tmp[2] = rtConstP.DirectLookupTablenD_table[tableOffset];
  if (rtb_Add_e <= 0.0) {
    tmp[3] = -0.0;
  } else {
    tmp[3] = -rtb_Add_e;
  }

  roots(tmp, r_data, &r_size);

  /* '<S15>:1:6' r=r(abs(imag(r))<1e-5); */
  i = r_size;
  for (tableOffset = 0; tableOffset < i; tableOffset++) {
    x_data[tableOffset] = r_data[tableOffset].im;
  }

  i = (int8_T)r_size;
  for (tableOffset = 0; tableOffset + 1 <= r_size; tableOffset++) {
    y_data[tableOffset] = fabs(x_data[tableOffset]);
  }

  for (tableOffset = 0; tableOffset < i; tableOffset++) {
    b_data[tableOffset] = (y_data[tableOffset] < 1.0E-5);
  }

  tableOffset = (int8_T)r_size - 1;
  trueCount = 0;
  for (i = 0; i <= tableOffset; i++) {
    if (b_data[i]) {
      trueCount++;
    }
  }

  i = 0;
  for (b_i = 0; b_i <= tableOffset; b_i++) {
    if (b_data[b_i]) {
      r_data[i] = r_data[b_i];
      i++;
    }
  }

  /* '<S15>:1:8' if(isempty(r)) */
  if (trueCount == 0) {
    /* '<S15>:1:9' speed_mph=-10; */
    rtb_Add = -10.0;

    /* change this  */
  } else {
    /* '<S15>:1:10' else */
    /* '<S15>:1:11' speed_mph = real(r(1)); */
    rtb_Add = r_data[0].re;
  }

  /* Saturate: '<S6>/Saturation' incorporates:
   *  MATLAB Function: '<S13>/MATLAB Function'
   */
  if (rtb_Add > 62.137273664980675) {
    /* Outport: '<Root>/Optimal Velocity (mph)' */
    rtY.OptimalVelocitymph = 62.137273664980675;
  } else if (rtb_Add < 0.0) {
    /* Outport: '<Root>/Optimal Velocity (mph)' */
    rtY.OptimalVelocitymph = 0.0;
  } else {
    /* Outport: '<Root>/Optimal Velocity (mph)' */
    rtY.OptimalVelocitymph = rtb_Add;
  }

  /* End of Saturate: '<S6>/Saturation' */
}

/* Model initialize function */
void Cruise_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
