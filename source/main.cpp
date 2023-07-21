// Author : Shahkaar Ahmad Khan
// Date : 21july 2023 10:50am
// Email : shahkaar6@gmail.com
// A huge thanks to https://github.com/AIWintermuteAI
// and https://www.youtube.com/@digikey
// for guiding me to successfully complete my first tinyml project
// and helping me config my vs code for raspberry pie pico 

#include <stdio.h>
#include "math.h"
#include "pico/stdlib.h"
#include "ei_run_classifier.h"
#include "hardware/pwm.h"

float features[] = {0};

int raw_feature_get_data(size_t offset, size_t length, float *out_ptr) {
    memcpy(out_ptr, features + offset, length * sizeof(float));
    return 0;
}

int main()
{   
    features[0] = 0;
    float interval = 3.14159/200;
    stdio_init_all();
    float y[200] = {0};
    int pwm[200] = {0};
    
// PWM PIN setup :: start
//  pwm range is from 0-65535
    gpio_set_function(25, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(25);
    pwm_set_wrap(slice_num, 3);
    pwm_set_enabled(slice_num, true);
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, 4.f);
    pwm_init(slice_num, &config, true);
// pwm_set_gpio_level(pin,pwm)
// setup :: end    


//##### Changing the x value every iteration and making pridiction and saving it in an array y #########
// and converting it to pwm signal 0-65535
//               #################START###################
    int a = 0;
    for(a;a<=200;a++)
        {  
        ei_impulse_result_t result = {0};

        // the features are stored into flash, and we don't want to load everything into RAM
        signal_t features_signal;
        features_signal.total_length = sizeof(features[0]) / sizeof(features[0]);
        features_signal.get_data = &raw_feature_get_data;

        EI_IMPULSE_ERROR res = run_classifier(&features_signal, &result, false /* debug */);
        for (size_t ix = 0; ix < EI_CLASSIFIER_LABEL_COUNT; ix++) 
        {
                printf("feature = %lf",features[0]);
                ei_printf("   %s: %.5f ", result.classification[ix].label, result.classification[ix].value);
                y[a] = result.classification[ix].value;
                pwm[a] = ((65535)*y[a])/1.018;
                printf("y[%d] = %lf  pwm[%d] = %d\n",a,y[a],a,pwm[a]);
                sleep_ms(500);
        }
        features[0] = features[0]+interval;
        }
// ##############################END##################################




while (true) 
    
    {
        // Controlling LED's brightness using the values predicted by the model
        for(int p = 0 ; p<=200;p++)
        {   
            pwm_set_gpio_level(25,pwm[p]);
            sleep_ms(80);
        }
        
    }
return 0;
}
