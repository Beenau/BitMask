// Read modify write 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned long uint32_t;

// This function will replace num of bits starting from LSB (least significant bit) position with data in the regData. 
// For example: if the regData is 100 (0x0064), lsbPosition is 4, numOfBits is 4, data is 15 then your program should return 244 (0x00F4). 

uint32_t readModifyWrite(uint32_t regData, uint32_t lsbPosition, uint32_t numOfBits, uint32_t data)
{ 
    //data is the new value to be put into the regData

    uint32_t masked;  //Will hold the result of bit masking the regData

    //mask = ~(~(~0 << numOfBits) << lsbPosition); //Creates mask of 0xFFFFFF0F where 0 only where bits need to be replaced
    //regData = (regData & mask) | (data << lsbPosition);
    //as one line of code:
    masked = (regData & (~(~(~0 << numOfBits) << lsbPosition))) | (data << lsbPosition);
  
    return(masked);
}


/* Driver program to test above functions*/
int main()
{
    uint32_t regData = 100; //0x64
    uint32_t lsbPosition = 4;
    uint32_t numOfBits = 4; 
    uint32_t data = 14;  // 0xe

    uint32_t modifiedWriteValid;

    printf("Input = 0x%08x\n", regData);
    readModifyWrite(regData, lsbPosition, numOfBits, data);
    regData = readModifyWrite(regData, lsbPosition, numOfBits, data);
    printf ("Answer = 0x%08x\n", regData);

    return 0;
}

