/*! \file fortranLinkage.h
 *
 * \author Joey Dumont <joey.dumont@gmail.com>
 * \author Denis Gagnon <gagnon88@gmail.com>
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
!   choice:      type of Normalization
!                    1 Stratton
!                    2 Ince
!                    3 Neutral
!   sign:        1 or -1 depending on the sign of sqrt(Q) that appears in the argument of the radial functions
=======================================================================================================================================*/
  extern double _Complex MathieuRadial_wrap(int ,int ,int ,int ,double ,double ,double ,int* ,int ,int);
}
///@}

} // namespace c_mathieu

#endif // C_Mathieu_H
