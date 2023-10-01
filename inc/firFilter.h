/**
 * Author:    Haerteleric
 * Created:   11.07.23
 * 
 * (c) Copyright by Eric Haertel
 * 
 * Portable Rolling Window template implementation
 * 
 **/
#ifndef _ROLLING_WINDOW_TEMPLATE_
#error "This template depends on the rollingWindow.h template. include it via extern or cSuite submodule"
#endif


#ifndef _FIR_FILTER_TEMPLATE_
#define _FIR_FILTER_TEMPLATE_

#include <stddef.h>

#ifdef FIR_FILTER_CONFIG_HEADER_INCLUDE
    #include FIR_FILTER_CONFIG_HEADER_INCLUDE
#endif

#ifndef FIR_FILTER_PARAMETER_DATA_TYPE
    #define FIR_FILTER_PARAMETER_DATA_TYPE float
#endif

#ifndef FIR_FILTER_OUTPUT_DATA_TYPE
    #define FIR_FILTER_OUTPUT_DATA_TYPE float
#endif

typedef FIR_FILTER_PARAMETER_DATA_TYPE firParameterDataType_t;
typedef FIR_FILTER_OUTPUT_DATA_TYPE firOutputDataType_t;

typedef struct firFilter_s
{
    firParameterDataType_t *parameter;
    const unsigned int filterOrder;
}firFilter_t;

static firOutputDataType_t fir_getOutput(rollingWindow_t * inputHandle, firFilter_t * firHandle)
{
    firOutputDataType_t output = 0;
    for (unsigned int i = 0; i <= firHandle->filterOrder ; i++)
    {
        output += firHandle->parameter[i] * (*rollingWindow_getSampleKMinusN(inputHandle, i));
    }
    
    return output;
}

#else
#error "this template should only be included once"
#endif //_FIR_FILTER_TEMPLATE_