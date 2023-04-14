
//-lcbessel -lMatrix_double

#include<iostream>
#include "fortranLinkage.h"

using namespace std;

int main()
{
 int k_max;

 double _Complex D_m[200],norm;
 double _Complex a;

 a=c_mathieu::MathieuAngular_wrap(0,0,1,-.9,.9,1,&k_max,1,D_m,&norm);
 std::cout<<k_max<<std::endl;
 std::cout<<creal(a)<<" "<<cimag(a)<<std::endl;

 a=c_mathieu::MathieuRadial_wrap(0,4,0,1,-.9,.9,1.,&k_max,1,1);
 std::cout<<k_max<<std::endl;
 std::cout<<creal(a)<<" "<<cimag(a)<<std::endl;

 printf("\nPROGRAM DONE!!\n");
 system("pause");
 return 0;
}
