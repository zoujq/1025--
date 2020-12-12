/********************************************************************************

ע�����ļ��û������޸ģ�

*******************************************************************************/
#ifndef __YX23F01CB_GeneralKey_Touch_Lib_H__
#define __YX23F01CB_GeneralKey_Touch_Lib_H__

//===================================================================================================
extern void CTK_Init(void);			    //���ô˳���ǰ�����ȴ����ж��ܿ��أ�EA=1������ΪCTK��ʼ��ʱ����ҪCTK�ж����
extern void CTK_ISR_Handle(void);       //�˺���������CTK�ж�����е���
extern void Touch_Signal_Handle(void);  //����ɨ�����һ�ֺ󣬵���һ��
extern void Scan_Pause(void);           //CTKɨ����ͣ
extern void Scan_Continue(void);        //CTKɨ�����
extern void BaseLineReset(void);        //��λ����ͨ������

//===================================================================================================
extern bit  OneCycleScanDone;           //ɨ��һ����λһ�Σ�һ��ʱ�� �� ����ͨ��ɨ��ʱ�� * �����ļ��ͨ������
extern ux16 TouchKeyFlag;               //������Ӧ��־��ÿ1BIT ��Ӧһ��ͨ����BIT��Ӧλ��YXTouchLib_TK_CH_MASK���Ӧ
extern ux16	XDATA_CONFIRM_LONGTOUCH_TIME;//�������Чʱ�����ֵ
extern ux16	XDATA_THRESHOLD_NOISE_TIME; //��ֵ�������¼���ֵ
extern ux8	XDATA_THRESHOLD_RATIO;      //��ָ��ֵ����
extern ux8	XDATA_FineTuning;           //����Ͱ΢������

extern uc8  TOUCH_LIB_VERSION[];       //������汾���

#endif /*__YX23F01CB_GeneralKey_Touch_Lib_H__*/
