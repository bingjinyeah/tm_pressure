#include "stm8s.h"
#include "modbus_driver.h"


extern uint16_t MB_InReg[];
extern uint16_t adc_value;
uint16_t adc_value_last = 0;
float pressure_value;

float get_pressure(float data)
{
    
    
    
    return data;    
}

void pressure_task()
{
    float tmp;
    
    if(adc_value_last!=adc_value){
        adc_value_last = adc_value;
        
        //tmp = (adc_value / 1023.0) * 5 / 30.0 * 1000  (mV);
        tmp = adc_value / 6.138;
        pressure_value = get_pressure(tmp);
        MB_InReg[0] = (uint16_t)(pressure_value * 10);
    }
}