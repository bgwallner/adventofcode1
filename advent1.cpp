#include <stdlib.h>
#include <stdio.h>

#define FILE_NAME          "input.txt"

/* Status codes */
#define E_OK             0x01
#define E_NOT_OK         0x00

static unsigned char read_input_from_txt( void )
{
    unsigned int uiValue; 
    int iFirst, iLast;
    bool boFirst = true;
    char cValue = 0;
    unsigned int uiSum = 0;
    FILE* fhInput;

    
    fhInput = fopen(FILE_NAME, "r");

    iFirst = -1;
    iLast  = -1;

    if (NULL != fhInput)
    {
        while (cValue != EOF)
        {
            cValue = getc(fhInput);

            /* Convert char to uint */
            uiValue = cValue - '0';

            /* Check if end of row */
            if ('\n' == cValue)
            {
                //uiSum+= ....

                if(iLast == -1)
                {
                    iLast = iFirst;
                }

                printf(" -> First:%d Last: %d\n", iFirst, iLast);
                printf("Adding the integer %d\n", 10*iFirst+iLast);
                uiSum += 10*iFirst + iLast;



                boFirst = true;
                iFirst = -1;
                iLast  = -1;
            }
            else
            {
                if( uiValue >= 0 && uiValue <= 9 )
                {
                    printf("%d", uiValue);
                    if(boFirst == true)
                    {
                        iFirst=uiValue;
                        boFirst = false;
                    }
                    else
                    {
                        iLast=uiValue;
                    }
                }
            }
        }
    }

    printf("Final sum is %d\n", uiSum);
    return E_OK;
}

int main()
{
    unsigned char status;
    status = read_input_from_txt();
}