
//-lcbessel -lMatrix_double

#include "fortranLinkage.h"

using namespace std;

int main()
{
 int k_max;
 double _Complex D_m[200],norm;
 double _Complex Q=1;

 c_mathieu::MathieuAngular_wrap(0,0,1,Q,2,&k_max,1,D_m,&norm);

 printf("\nPROGRAM DONE!!\n");
 system("pause");
 return 0;
}
