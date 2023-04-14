! -------------------------------------------------------------------
! - Author:             Chia-Cheng Tsai <cctsai@mail.ntou.edu.tw>   -
! - Date created:       2023-04-13                                  -
! - Date modded:        2023-04-13                                  -
! - Description:        ISO C Binding wrapper for the FORTRAN       -
!                       subroutines contained in Mathieu function   -
!                       TOMS Algorithm 934 library.                 -
! -------------------------------------------------------------------

! Mathieu angular functions Se_m, So_m
function MathieuAngular_wrap(parity,der,n,Q,x,k_max, choice, D_m, norm) result(MAW) bind(C)
    !DEC$ ATTRIBUTES DLLEXPORT :: MathieuAngular_wrap

    ! State ISO_C_BINDING and no implicit variable types.
    use iso_c_binding
    use Blanch_Complex
    implicit none

    ! State intent of FORTRAN variables.
    real(c_double), value, intent(in)     :: x
    complex(c_double_complex), value, intent(in)     :: Q
    integer(c_int), value, intent(in)     :: parity, der, n, choice
    integer(c_int), intent(inout)           :: k_max
    complex(c_double_complex), dimension(*), intent(inout) :: D_m
    complex(c_double_complex), intent(inout)    :: norm

    complex(c_double_complex) :: MAW

    ! Interface to original FORTRAN subroutine.
    !interface
    !        function MathieuAngular(parity,der,n,Q,x,k_max, choice, D_m, norm)
    !                INTEGER parity, der, n, choice
    !                INTEGER K_max
    !                COMPLEX DOUBLE PRECISION Q
    !                DOUBLE PRECISION x
    !                COMPLEX DOUBLE PRECISION norm
    !                COMPLEX DOUBLE PRECISION MathieuAngular
    !                COMPLEX DOUBLE PRECISION D_m
    !        END function MathieuAngular
    !end interface

    MAW=MathieuAngular(parity,der,n,Q,x,k_max, choice, D_m, norm)

end function MathieuAngular_wrap
