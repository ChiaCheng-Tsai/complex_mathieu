
// -lfcmathieu -lfcbessel -lgfortran -lMatrix_double

// 0.37792709591955492 0.10917827825327119
// 9.9669815219814808 4.4953531820694357

//MATHIEUce(order,q,v)
//0.78790669989285289 0
//0.67473747502226378 0
//-0.12175037113106801 0
//-0.91937107086033587 0
//-0.7281377975283605 0

//MATHIEUse(order,q,v)
//0.81669801021646549 0
//0.96799761581021626 0
//0.29299768684283145 0
//-0.66306971495860756 0

//Mathieu_Mc1(order,q,v)
//(-0.13701306415907075,-3.0201672406656803e-016)
//(0.51033460083355564,-7.5064242606106255e-016)
//(0.61793272177517189,1.3621038071771353e-015)
//(0.32943507063501709,-4.8456040457997294e-016)
//(0.12293711927885244,2.7098923930110294e-016)

//Mathieu_Mc2(order,q,v)
//(0.57669726463339877,5.8654309378656597e-016)
//(0.37894923738333369,-7.3326595763323439e-016)
//(-0.32263609856963665,2.4377512259594341e-016)
//(-0.81416154432714161,2.6603654451314696e-016)
//(-1.4434092638840981,-1.72619371674492e-015)

//Mathieu_Ms1(order,q,v)
//(0.57296128678364933,-8.4275894608725415e-016)
//(0.57874614800450208,1.1339779361544627e-015)
//(0.32423130106454801,-4.7690626902134249e-016)
//(0.12270707072411853,2.4042857354829941e-016)

//Mathieu_Ms2(order,q,v)
//(0.17287579209193493,-6.3947857524804592e-016)
//(-0.3656471965703077,1.8661338744169728e-016)
//(-0.81456739040634585,2.6253460225532632e-016)
//(-1.4433225647498029,-1.2021459978377545e-015)

#include <iostream>
#include <iomanip>
#include "cMathieu.h"

using namespace std;

int main()
{

 std::cout<<setprecision(17);
 int k_max;
 double _Complex D_m[200],norm;
 double _Complex a;
 int order;

 a=c_mathieu::MathieuAngular_wrap(0,0,1,-.9,.9,1.,&k_max,1,D_m,&norm);
 std::cout<<creal(a)<<" "<<cimag(a)<<std::endl;
 a=c_mathieu::MathieuRadial_wrap(0,4,0,1,-.9,.9,1.,&k_max,1,1);
 std::cout<<creal(a)<<" "<<cimag(a)<<std::endl<<std::endl;
/*
 cout<<"Mathieu_ce(order,q,v)"<<endl;
 std::cout<<c_mathieu::Mathieu_ce(0,1.,1.)<<std::endl;
 std::cout<<c_mathieu::Mathieu_ce(1,1.,1.)<<std::endl;
 std::cout<<c_mathieu::Mathieu_ce(2,1.,1.)<<std::endl;
 std::cout<<c_mathieu::Mathieu_ce(3,1.,1.)<<std::endl;
 std::cout<<c_mathieu::Mathieu_ce(4,1.,1.)<<std::endl<<std::endl;

 cout<<"Mathieu_se(order,q,v)"<<endl;
 std::cout<<c_mathieu::Mathieu_se(1,1.,1.)<<std::endl;
 std::cout<<c_mathieu::Mathieu_se(2,1.,1.)<<std::endl;
 std::cout<<c_mathieu::Mathieu_se(3,1.,1.)<<std::endl;
 std::cout<<c_mathieu::Mathieu_se(4,1.,1.)<<std::endl<<std::endl;
*/

 cout<<"Mathieu_Mc1(order,q,v)"<<endl;
 std::cout<<c_mathieu::Mathieu_Mc1(0,1.,1.)<<std::endl;
 std::cout<<c_mathieu::Mathieu_Mc1(1,1.,1.)<<std::endl;
 std::cout<<c_mathieu::Mathieu_Mc1(2,1.,1.)<<std::endl;
 std::cout<<c_mathieu::Mathieu_Mc1(3,1.,1.)<<std::endl;
 std::cout<<c_mathieu::Mathieu_Mc1(4,1.,1.)<<std::endl<<std::endl;

 cout<<"Mathieu_Mc2(order,q,v)"<<endl;
 std::cout<<c_mathieu::Mathieu_Mc2(0,1.,1.)<<std::endl;
 std::cout<<c_mathieu::Mathieu_Mc2(1,1.,1.)<<std::endl;
 std::cout<<c_mathieu::Mathieu_Mc2(2,1.,1.)<<std::endl;
 std::cout<<c_mathieu::Mathieu_Mc2(3,1.,1.)<<std::endl;
 std::cout<<c_mathieu::Mathieu_Mc2(4,1.,1.)<<std::endl<<std::endl;

 cout<<"Mathieu_Ms1(order,q,v)"<<endl;
 std::cout<<c_mathieu::Mathieu_Ms1(1,1.,1.)<<std::endl;
 std::cout<<c_mathieu::Mathieu_Ms1(2,1.,1.)<<std::endl;
 std::cout<<c_mathieu::Mathieu_Ms1(3,1.,1.)<<std::endl;
 std::cout<<c_mathieu::Mathieu_Ms1(4,1.,1.)<<std::endl<<std::endl;

 cout<<"Mathieu_Ms2(order,q,v)"<<endl;
 std::cout<<c_mathieu::Mathieu_Ms2(1,1.,1.)<<std::endl;
 std::cout<<c_mathieu::Mathieu_Ms2(2,1.,1.)<<std::endl;
 std::cout<<c_mathieu::Mathieu_Ms2(3,1.,1.)<<std::endl;
 std::cout<<c_mathieu::Mathieu_Ms2(4,1.,1.)<<std::endl<<std::endl;

 /*
 cout<<"Mathieu_Ms1(order,q,v)"<<endl;
 std::cout<<c_mathieu::Mathieu_Ms1(1,1.,1.)<<std::endl;
 std::cout<<c_mathieu::Mathieu_Ms1(2,1.,1.)<<std::endl;
 std::cout<<c_mathieu::Mathieu_Ms1(3,1.,1.)<<std::endl;
 std::cout<<c_mathieu::Mathieu_Ms1(4,1.,1.)<<std::endl<<std::endl;
*/
 system("pause");
 return 0;
}
