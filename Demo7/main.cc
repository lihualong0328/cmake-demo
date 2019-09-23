/*
 * @Description: 
 * @Copyright(c) 2019 enst.org.cn. All rights reserved.
 * @version: 1.0.0.1
 * @Filename:
 * @Author: lihualong
 * @Date: 2019-09-20 10:32:20
 * @LastEditors: lihualong
 * @LastEditTime: 2019-09-23 21:16:51
 */
#include <stdio.h>
#include <stdlib.h>
#include <config.h>

#include "MathFunctions.h"


int main(int argc, char *argv[])
{
    if (argc < 3){
        // print version info
        printf("%s Version %d.%d\n",
            argv[0],
            Demo_VERSION_MAJOR,
            Demo_VERSION_MINOR);
        printf("Usage: %s base exponent \n", argv[0]);
        return 1;
    }

    double base = atof(argv[1]);
    int exponent = atoi(argv[2]);
    
    printf("Now we use our own Math library. \n");
    double result = power(base, exponent);

    printf("%g ^ %d is %g\n", base, exponent, result);
    return 0;
}
