! -------------------------------------------------------------------
! - Author:             Chia-Cheng Tsai <joey.dumont@gmail.com>     -       -
! - Date created:       2023-04-13                                  -
! - Date modded:        2023-04-13                                  -
! - Description:        ISO C Binding wrapper for the FORTRAN       -
!                       subroutines contained in Mathieu function   -
!                       TOMS Algorithm 934 library.                 -          -
! -------------------------------------------------------------------

! Mathieu angular functions Se_m, So_m
real(c_double_complex) function MathieuAngular_wrap(parity,der,n,Q,x,k_max, choice, D_m, norm) bind(C)
    !DEC$ ATTRIBUTES DLLEXPORT :: MathieuAngular_wrap

    ! State ISO_C_BINDING and no implicit variable types.
    use iso_c_binding
    use Blanch_Complex
    use Constants
    implicit none

    ! State intent of FORTRAN variables.
    real(c_double), value, intent(in)     :: x
    real(c_double_complex), value, intent(in)     :: Q
    integer(c_int), value, intent(in)     :: parity, der, n, choice
    real(c_double), intent(out)           :: cyr, cyi
    integer(c_int), intent(out)           :: k_max
    type(c_ptr), intent(out) :: D_m

    ! Interface to original FORTRAN subroutine.
    interface
            function MathieuAngular(parity,der,n,Q,x,k_max, choice, D_m, norm)
                    integer,intent(in) :: parity, der, n, choice
                    integer, intent(out):: K_max
                    complex(kind=double), intent(in):: Q
                    real(kind=double), intent(in):: x
                    complex(kind=double), intent(out)::norm
                    complex(kind=double) :: MathieuAngular
                    complex(kind=double), dimension(0:MAX_), intent(out) :: D_m
            END function MathieuAngular
    end interface

    MathieuAngular_wrap=MathieuAngular(parity,der,n,Q,x,k_max, choice, D_m, norm)
end function MathieuAngular_wrap
