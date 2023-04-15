! -------------------------------------------------------------------
! - Author:             Chia-Cheng Tsai <cctsai@mail.ntou.edu.tw>   -
! - Date created:       2023-04-13                                  -
! - Date modded:        2023-04-13                                  -
! - Description:        ISO C Binding wrapper for the FORTRAN       -
!                       subroutines contained in Mathieu function   -
!                       TOMS Algorithm 934 library.                 -
! -------------------------------------------------------------------

! Mathieu angular functions Se_m, So_m
function MathieuAngular_wrap(parity,der,n,Qr,Qi,x,k_max,choice,D_m,norm) result(MAW) bind(C,name='MathieuAngular_wrap')
    !DEC$ ATTRIBUTES DLLEXPORT :: MathieuAngular_wrap

    ! State ISO_C_BINDING and no implicit variable types.
    use iso_c_binding
    use Blanch_Complex
    implicit none

    ! State intent of FORTRAN variables.
    real(c_double), value, intent(in)     :: Qr,Qi,x
    integer(c_int), value, intent(in)     :: parity, der, n, choice
    integer(c_int), intent(inout)         :: k_max
    complex(c_double_complex), dimension(*), intent(inout) :: D_m
    complex(c_double_complex), intent(inout)    :: norm
    complex(c_double_complex) :: MAW

    MAW=MathieuAngular(parity,der,n,COMPLEX(Qr,Qi),x,k_max, choice, D_m, norm)

end function MathieuAngular_wrap

! Mathieu radial functions Re1,Re2,Re3,Re4,Ro1,Ro2,Ro3,Ro4
function MathieuRadial_wrap(parity,radial_kind,der,n,Qr,Qi,x,k_max,choice,sign) result(MRW) bind(C,name='MathieuRadial_wrap')
    !DEC$ ATTRIBUTES DLLEXPORT :: MathieuRadial_wrap

    ! State ISO_C_BINDING and no implicit variable types.
    use iso_c_binding
    use Blanch_Complex
    implicit none

    ! State intent of FORTRAN variables.
    real(c_double), value, intent(in)     :: Qr,Qi,x
    integer(c_int), value, intent(in)     :: parity, radial_kind, der, n, choice, sign
    integer(c_int), intent(inout)         :: k_max
    complex(c_double_complex) :: MRW

    MRW=MathieuRadial(parity,radial_kind,der,n,COMPLEX(Qr,Qi),x,k_max, choice, sign)

end function MathieuRadial_wrap
