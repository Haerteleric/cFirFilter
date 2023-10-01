
/**
 * Portable Fir Filter template implementation
 * 
 * DEPENDS ON : cSuite/cRollingWindow
 * 
 * Author:    Haerteleric
 * 
 * MIT License
 * 
 * Copyright (c) 2023 Eric Härtel
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
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