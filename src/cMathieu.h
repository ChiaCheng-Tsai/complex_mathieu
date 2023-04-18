/*! \file c_mathieu.h
 *
 * \author Chia-Cheng Tsai <cctsai@mail.ntou.edu.tw>
 *
 * \brief Specifies the linkage to the Fortran subroutines
 * for the Mathieu functions of complex parameters with real
 * arguments and integer orders.
 *
 * We use the Fortran code developed by D Erricolo and G. Carluccio \cite EC13
 * to compute the Mathieu functions of complex parameters with real variables
 * and integer order.
 *
 * \copyright LGPL
 */

#ifndef C_Mathieu_H
#define C_Mathieu_H

#include <complex.h>

#undef I

#include <complex>

namespace c_mathieu {
/*! @name Fortran Linkage
 * We link the Fortran subroutines to our C++ code.
 * Since Fortran treats all variables by reference, we must
 * pass our C++ arguments as pointers.
 */
///@{
extern "C"
{
/*!====================================================================================================================================
! Mathieu angular functions Se_m, So_m
!   parity:    0 Even, Se, ..
!              1 Odd, So, ...
!   der:     0 No derivatives required
!            1 Derivatives are required
!   n:      order of the Mathieu function
!   Qr,Qi:  parameter of the Mathieu function, according to the notation of NcLachlan
!   x:      argument of the Mathieu function
!   k_max:  index of the last element of D_m, i.e. D_m contains k_max+1 elements
!   choice: type of Normalization
!                    1 Stratton
!                    2 Ince
!                    3 Neutral
!   D_m:    expansion coefficients
!   norm:   Normalization
=======================================================================================================================================*/
  extern double _Complex MathieuAngular_wrap(int ,int ,int ,double ,double ,double ,int* ,int ,double _Complex * ,double _Complex * );

/*!====================================================================================================================================
! Mathieu radial functions Re1,Re2,Re3,Re4,Ro1,Ro2,Ro3,Ro4
!   parity:      0 Even, Re, ..
!                1 Odd, Ro, ...
!   radial_kind: 1,2,3,4
!   der:         0 No derivatives required
!                1 Derivatives are required
!   n:           order of the Mathieu function
!   Qr,Qi:       parameter of the Mathieu function, according to the notation of Blanch
!   x:           argument of the Mathieu function
!   k_max:       index of the last element of D_m, i.e. D_m contains k_max+1 elements
!   choice:      type of Normalization (Tsai, 2023, 4, 15: no use, the real normalization needs to be dependent on the plane wave series)
!                    1 Stratton
!                    2 Ince
!                    3 Neutral
!   sign:        1 or -1 depending on the sign of sqrt(Q) that appears in the argument of the radial functions
=======================================================================================================================================*/
  extern double _Complex MathieuRadial_wrap(int ,int ,int ,int ,double ,double ,double ,int* ,int ,int);
}
///@}

 inline std::complex<double> Mathieu_ce(int n,std::complex<double> Q,double x)
 {
  int k_max;
  double _Complex D_m[200],norm;
  double _Complex result=c_mathieu::MathieuAngular_wrap(0,0,n,Q.real(),Q.imag(),x,&k_max,2 /* Mathematica choice */,D_m,&norm);
  return std::complex<double>(creal(result),cimag(result));
 }

 inline std::complex<double> Mathieu_se(int n,std::complex<double> Q,double x)
 {
  int k_max;
  double _Complex D_m[200],norm;
  double _Complex result=c_mathieu::MathieuAngular_wrap(1,0,n,Q.real(),Q.imag(),x,&k_max,2 /* Mathematica choice */,D_m,&norm);
  return std::complex<double>(creal(result),cimag(result));
 }

 inline std::complex<double> Mathieu_Mc1(int n,std::complex<double> Q,double x,int Sign=1)
 {
  int k_max;
  double _Complex result=c_mathieu::MathieuRadial_wrap(0,1,0,n,Q.real(),Q.imag(),x,&k_max,2 /* dummy */,Sign);
  return std::complex<double>(creal(result),cimag(result));
 }

 inline std::complex<double> Mathieu_Ms1(int n,std::complex<double> Q,double x,int Sign=1)
 {
  int k_max;
  double _Complex result=c_mathieu::MathieuRadial_wrap(1,1,0,n,Q.real(),Q.imag(),x,&k_max,2 /* dummy */,Sign);
  return std::complex<double>(creal(result),cimag(result));
 }

 inline std::complex<double> Mathieu_Mc2(int n,std::complex<double> Q,double x,int Sign=1)
 {
  int k_max;
  double _Complex result=c_mathieu::MathieuRadial_wrap(0,2,0,n,Q.real(),Q.imag(),x,&k_max,2 /* dummy */,Sign);
  return std::complex<double>(creal(result),cimag(result));
 }

 inline std::complex<double> Mathieu_Ms2(int n,std::complex<double> Q,double x,int Sign=1)
 {
  int k_max;
  double _Complex result=c_mathieu::MathieuRadial_wrap(1,2,0,n,Q.real(),Q.imag(),x,&k_max,2 /* dummy */,Sign);
  return std::complex<double>(creal(result),cimag(result));
 }

 inline std::complex<double> Mathieu_Mc3(int n,std::complex<double> Q,double x,int Sign=1)
 {
  int k_max;
  double _Complex result=c_mathieu::MathieuRadial_wrap(0,3,0,n,Q.real(),Q.imag(),x,&k_max,2 /* dummy */,Sign);
  return std::complex<double>(creal(result),cimag(result));
 }

 inline std::complex<double> Mathieu_Ms3(int n,std::complex<double> Q,double x,int Sign=1)
 {
  int k_max;
  double _Complex result=c_mathieu::MathieuRadial_wrap(1,3,0,n,Q.real(),Q.imag(),x,&k_max,2 /* dummy */,Sign);
  return std::complex<double>(creal(result),cimag(result));
 }

 inline std::complex<double> Mathieu_Mc4(int n,std::complex<double> Q,double x,int Sign=1)
 {
  int k_max;
  double _Complex result=c_mathieu::MathieuRadial_wrap(0,4,0,n,Q.real(),Q.imag(),x,&k_max,2 /* dummy */,Sign);
  return std::complex<double>(creal(result),cimag(result));
 }

 inline std::complex<double> Mathieu_Ms4(int n,std::complex<double> Q,double x,int Sign=1)
 {
  int k_max;
  double _Complex result=c_mathieu::MathieuRadial_wrap(1,4,0,n,Q.real(),Q.imag(),x,&k_max,2 /* dummy */,Sign);
  return std::complex<double>(creal(result),cimag(result));
 }

 inline std::complex<double> Mathieu_DMc1(int n,std::complex<double> Q,double x,int Sign=1)
 {
  int k_max;
  double _Complex result=c_mathieu::MathieuRadial_wrap(0,1,1,n,Q.real(),Q.imag(),x,&k_max,2 /* dummy */,Sign);
  return std::complex<double>(creal(result),cimag(result));
 }

 inline std::complex<double> Mathieu_DMs1(int n,std::complex<double> Q,double x,int Sign=1)
 {
  int k_max;
  double _Complex result=c_mathieu::MathieuRadial_wrap(1,1,1,n,Q.real(),Q.imag(),x,&k_max,2 /* dummy */,Sign);
  return std::complex<double>(creal(result),cimag(result));
 }

 inline std::complex<double> Mathieu_DMc2(int n,std::complex<double> Q,double x,int Sign=1)
 {
  int k_max;
  double _Complex result=c_mathieu::MathieuRadial_wrap(0,2,1,n,Q.real(),Q.imag(),x,&k_max,2 /* dummy */,Sign);
  return std::complex<double>(creal(result),cimag(result));
 }

 inline std::complex<double> Mathieu_DMs2(int n,std::complex<double> Q,double x,int Sign=1)
 {
  int k_max;
  double _Complex result=c_mathieu::MathieuRadial_wrap(1,2,1,n,Q.real(),Q.imag(),x,&k_max,2 /* dummy */,Sign);
  return std::complex<double>(creal(result),cimag(result));
 }

 inline std::complex<double> Mathieu_DMc3(int n,std::complex<double> Q,double x,int Sign=1)
 {
  int k_max;
  double _Complex result=c_mathieu::MathieuRadial_wrap(0,3,1,n,Q.real(),Q.imag(),x,&k_max,2 /* dummy */,Sign);
  return std::complex<double>(creal(result),cimag(result));
 }

 inline std::complex<double> Mathieu_DMs3(int n,std::complex<double> Q,double x,int Sign=1)
 {
  int k_max;
  double _Complex result=c_mathieu::MathieuRadial_wrap(1,3,1,n,Q.real(),Q.imag(),x,&k_max,2 /* dummy */,Sign);
  return std::complex<double>(creal(result),cimag(result));
 }

 inline std::complex<double> Mathieu_DMc4(int n,std::complex<double> Q,double x,int Sign=1)
 {
  int k_max;
  double _Complex result=c_mathieu::MathieuRadial_wrap(0,4,1,n,Q.real(),Q.imag(),x,&k_max,2 /* dummy */,Sign);
  return std::complex<double>(creal(result),cimag(result));
 }

 inline std::complex<double> Mathieu_DMs4(int n,std::complex<double> Q,double x,int Sign=1)
 {
  int k_max;
  double _Complex result=c_mathieu::MathieuRadial_wrap(1,4,1,n,Q.real(),Q.imag(),x,&k_max,2 /* dummy */,Sign);
  return std::complex<double>(creal(result),cimag(result));
 }

 inline std::complex<double> Mathieu_me(int n,std::complex<double> Q,double x)
 {
  if(n>=0)
   return sqrt(2.)*Mathieu_ce(n,Q,x);
  else
   return -sqrt(2.)*std::complex<double>(0,1)*Mathieu_se(-n,Q,x);
 }

 inline std::complex<double> Mathieu_M1(int n,std::complex<double> Q,double x,int Sign=1)
 {
  if(n>=0)
   return Mathieu_Mc1(n,Q,x,Sign);
  else
   return (n%2?-1.:1.)*Mathieu_Ms1(-n,Q,x,Sign);
 }

 inline std::complex<double> Mathieu_M2(int n,std::complex<double> Q,double x,int Sign=1)
 {
  if(n>=0)
   return Mathieu_Mc2(n,Q,x,Sign);
  else
   return (n%2?-1.:1.)*Mathieu_Ms2(-n,Q,x,Sign);
 }

 inline std::complex<double> Mathieu_M3(int n,std::complex<double> Q,double x,int Sign=1)
 {
  if(n>=0)
   return Mathieu_Mc3(n,Q,x,Sign);
  else
   return (n%2?-1.:1.)*Mathieu_Ms3(-n,Q,x,Sign);
 }

 inline std::complex<double> Mathieu_M4(int n,std::complex<double> Q,double x,int Sign=1)
 {
  if(n>=0)
   return Mathieu_Mc4(n,Q,x,Sign);
  else
   return (n%2?-1.:1.)*Mathieu_Ms4(-n,Q,x,Sign);
 }

 inline std::complex<double> Mathieu_DM1(int n,std::complex<double> Q,double x,int Sign=1)
 {
  if(n>=0)
   return Mathieu_DMc1(n,Q,x,Sign);
  else
   return (n%2?-1.:1.)*Mathieu_DMs1(-n,Q,x,Sign);
 }

 inline std::complex<double> Mathieu_DM2(int n,std::complex<double> Q,double x,int Sign=1)
 {
  if(n>=0)
   return Mathieu_DMc2(n,Q,x,Sign);
  else
   return (n%2?-1.:1.)*Mathieu_DMs2(-n,Q,x,Sign);
 }

 inline std::complex<double> Mathieu_DM3(int n,std::complex<double> Q,double x,int Sign=1)
 {
  if(n>=0)
   return Mathieu_DMc3(n,Q,x,Sign);
  else
   return (n%2?-1.:1.)*Mathieu_DMs3(-n,Q,x,Sign);
 }

 inline std::complex<double> Mathieu_DM4(int n,std::complex<double> Q,double x,int Sign=1)
 {
  if(n>=0)
   return Mathieu_DMc4(n,Q,x,Sign);
  else
   return (n%2?-1.:1.)*Mathieu_DMs4(-n,Q,x,Sign);
 }

} // namespace c_mathieu

#endif // C_Mathieu_H
