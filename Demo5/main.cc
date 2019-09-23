/*
 * @Description: 
 * @Copyright(c) 2019 enst.org.cn. All rights reserved.
 * @version: 1.0.0.1
 * @Filename:
 * @Author: lihualong
 * @Date: 2019-09-20 10:32:20
 * @LastEditors: lihualong
 * @LastEditTime: 2019-09-23 20:10:36
 */
#include <stdio.h>
#include <stdlib.h>
#include <config.h>

#ifdef USE_MYMATH
  #include <MathFunctions.h>
#else
  #include <math.h>
#endif

#define A 0
void test_marco()
{
#if (A == 1)||(A == 2)
    printf("(A == 1)||(A == 2) \n");
#elif (A == 0)
    printf("A == 0 \n");
#else
    printf("A no 1 2 0 \n");
#endif

//同 #ifdef，但#if defined后可以组成复杂的预编译条件
//#if defined (AAA) && defined (BBB)
//#if defined (AAA) || VERSION > 12
#if defined (A)
#undef A        //解除定义
#define A 200
#elif !defined(B)
#define B 2
#endif 

//同 #ifndef
#if !defined(A)
    printf("no defined A \n");
#endif

#if !defined(__cplusplus) 
#error C++ compiler required.   //产生编译时错误信息
#endif 


    if (A > 1)
        printf("A > 1 \n");
    else if(A == 1)
        printf("A == 1 \n");
    else
        printf("A < 1 \n");
}

int main(int argc, char *argv[])
{
    if (argc < 3){
        printf("Usage: %s base exponent \n", argv[0]);
        return 1;
    }
    double base = atof(argv[1]);
    int exponent = atoi(argv[2]);
    
#ifdef USE_MYMATH
    printf("Now we use our own Math library. \n");
    double result = power(base, exponent);
#else
    printf("Now we use the standard library. \n");
    double result = pow(base, exponent);
#endif

    printf("%g ^ %d is %g\n", base, exponent, result);

#ifdef HAVE_POW
    printf("Now we use the standard library. \n");
    double res = pow(base, exponent);
#else
    printf("Now we use our own Math library. \n");
    double res = power(base, exponent);
#endif
    printf("%g ^ %d is %g\n", base, exponent, result);

    // --------------------------------------------------------------------------------------------------

    test_marco();
    
    return 0;
}
