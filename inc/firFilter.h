/**
 * Author:    Haerteleric
 * 
 * (c) Copyright by Eric Haertel
 * 
 * Portable Fir Filter template implementation
 * 
 * DEPENDS ON : cSuite/cRollingWindow
 **/
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

#ifndef _FIR_FILTER_INSTANCE_STRUCT_DEFINED
#define _FIR_FILTER_INSTANCE_STRUCT_DEFINED

typedef struct firFilter_s
{
    firParameterDataType_t *parameter;
    const unsigned int filterOrder;
}firFilter_t;

#endif

#ifdef FIR_FILTER_INLINE_IMPLEMENTATION
inline
#endif 
#ifdef FIR_FILTER_STATIC_IMPLEMENTATION
static
#endif 
firOutputDataType_t fir_getOutput(rollingWindow_t * inputHandle, firFilter_t * firHandle)
#ifdef FIR_FILTER_ONLY_PROTOTYPE_DECLARATION
;
#else
{
    firOutputDataType_t output = 0;
    for (unsigned int i = 0; i <= firHandle->filterOrder ; i++)
    {
        output += firHandle->parameter[i] * (*rollingWindow_getSampleKMinusN(inputHandle, i));
    }
    
    return output;
}
#endif //FIR_FILTER_ONLY_PROTOTYPE_DECLARATION