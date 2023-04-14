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

#ifndef FORTRANLINKAGE_H
#define FORTRANLINKAGE_H

namespace c_mathieu {
/*! @name Fortran Linkage
 * We link the Fortran subroutines to our C++ code.
 * Since Fortran treats all variables by reference, we must
 * pass our C++ arguments as pointers.
 */
///@{
extern "C"
{
  /*! Mathieu angular functions Se_m, So_m. */
  extern void MathieuAngular_wrap(double, double, double, int, int, double*, double*, int*, int*);
}
///@}

} // namespace sp_bessel

#endif // FORTRANLINKAGE_H
