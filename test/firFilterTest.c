#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
/*****************************TEMPLATE INCLUDE**************************************/
#define ROLLING_WINDOW_DATA_TYPE float
#define FIR_FILTER_PARAMETER_DATA_TYPE float
#define FIR_FILTER_OUTPUT_DATA_TYPE float

//following just for testing
#define ROLLING_WINDOW_ONLY_PROTOTYPE_DECLARATION
#include "rollingWindow.h" //Prototype
#undef ROLLING_WINDOW_ONLY_PROTOTYPE_DECLARATION
#include "rollingWindow.h" //Implementation

#define FIR_FILTER_ONLY_PROTOTYPE_DECLARATION
#include "firFilter.h" //Prototype
#undef FIR_FILTER_ONLY_PROTOTYPE_DECLARATION
#include "firFilter.h" //Implementation
/***********************************************************************************/


static char s_buffer[5] ;
static rollingWindow_t s_rollingWindow = 
{
    .buffer = s_buffer,
    .bufferSize = sizeof(s_buffer)/sizeof(s_buffer[0]),
};

static float s_firParams[3] = 
{ 
    [0 ... (sizeof(s_firParams)/sizeof(s_firParams[0])-1) ] = 
        1.0f / (sizeof(s_firParams)/sizeof(s_firParams[0])) 
};

static firFilter_t s_firFilter = 
{
    .parameter = s_firParams,
    .filterOrder = (sizeof(s_firParams)/sizeof(s_firParams[0])-1)
};

int main(void)
{
    clock_t start = clock();
    rollingWindow_reset(&s_rollingWindow);

    char input = getchar();
    while (input != 'Q')
    {
        if((input >= '0') && (input <= '9'))
        {
            rollingWindow_put(&s_rollingWindow, input - '0' );
            printf("[%f]",fir_getOutput(&s_rollingWindow, &s_firFilter));
        }
        input = getchar();
    }
    
}

