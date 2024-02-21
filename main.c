#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

bool setBit(unsigned char* pBuf, uint16_t uLen, uint8_t bOffset, bool bIsSet)
{
    bool bIsError;
    uint8_t bByteIdx;
    uint8_t bBitIdx;

    bIsError=false;
//    bByteIdx=(bOffset / 8);
//    bBitIdx=(bOffset % 8);
    bByteIdx=(bOffset>>8);
    bBitIdx=(((bOffset>>8)-1) & bOffset);


    if(bOffset<uLen)
    {
        bIsError=true;

        if(bIsSet)
        {
            pBuf[bByteIdx] |=(1<<bBitIdx);
        }
        else
        {
            pBuf[bByteIdx] &=(~(1<<bBitIdx));
        }
    }
    return bIsError;
}

void convertToBinary(uint16_t uDec)
{
    if (uDec > 1)
    {
        convertToBinary(uDec / 2);
    }
        printf("%d", uDec%2);

}

int main()
{
    uint16_t uValue;
    uint16_t uValLength;
    uint16_t uOffset;
    uint16_t* puValue;
    uint8_t bBitsInByte;
    bool bIsSet;

    bBitsInByte=4;
    uValue=65535;
    puValue=&uValue;
    uValLength=bBitsInByte*sizeof(uValue);
    uOffset=6;
    bIsSet=false;

    printf("BEFORE: %d\n", uValue);
    convertToBinary(uValue);
    printf("\nSET BIT:%d TO:%d\n", uOffset, (int)bIsSet);
    if(setBit(puValue, uValLength, uOffset, bIsSet))
    {
        printf("AFTER: %d\n", uValue);
        convertToBinary(uValue);
        printf("\n");
    }
    else
    {
        printf("ERROR");
    }
    return 0;
}
