//
// Created by pk-bin on 25. 2. 10.
//
#include <stdio.h>
#include "include/driver.h"

int main(void) {
   printf("Hello World!\n");
   printf("%d \n",get_driver_version());

   cute_driver_result driver = init_driver();
   driver.destroy(&driver);
   return 0;
}