
#ifndef _VOICE_H_
#define _VOICE_H_

void IIc_init(void);
UINT8 VOICE_IIC_WRITE(UINT8 x);
void VOICE_INIT(void);
void VOICE_lp_INIT(void);
UINT8 VOICE_test(UINT8 x);
void VOICE(UINT8 voice1,UINT8 voice2);


void voice_ok(void);
void voice_error(void);

void test_voice_ok_and_error(void);


#endif 		/* _VOICE_H_ */


