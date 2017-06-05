#ifndef __LORA_H__
#define __LORA_H__

/*wdq*/
void gpio_init_rf433m_power(void);
void hwapi03_rf433m_power_ctrl(u8 on_off);

void test_hwapi03_rf433m_power_ctrl(void);


#endif
