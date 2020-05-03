#include <stdlib.h>
#include <registryFunction.h>
#include <aSubRecord.h>
#include <epicsExport.h>
#include <string.h>

static bool first = true;

static long signalGenerator(aSubRecord *prec)
{
    //*(epicsInt32*)prec->vala = (epicsInt32)(rand());

    epicsInt32 x[100];

    if (first)
    {
        srand(12345);
        first = false;
    }

    for (int i = 0; i < 100; ++i)
        x[i] = (epicsInt32)(rand());

    memcpy((epicsInt32*)prec->vala, x, sizeof(x));

    return 0;
}

epicsRegisterFunction(signalGenerator);
