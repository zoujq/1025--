
#ifndef __YX23F01CB_GeneralKey_Touch_Lib_Build_Message_H__
#define __YX23F01CB_GeneralKey_Touch_Lib_Build_Message_H__

//================================================================================
#if (HCTouchLib_IC_BODY == IC_BODY_SOP16)

#if (HCTouchLib_TK_CH_MASK & 0x0001L)
#pragma message "TK2��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0002L)
#pragma message "TK7��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0004L)
#pragma message "TK11��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0008L)
#pragma message "TK12��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0010L)
#pragma message "TK13��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0020L)
#pragma message "TK14��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0040L)
#pragma message "TK15��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0080L)
#error          "Error��Please reconfigure HCTouchLib_TK_CH_MASK"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0100L)
#error          "Error��Please reconfigure HCTouchLib_TK_CH_MASK"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0200L)
#error          "Error��Please reconfigure HCTouchLib_TK_CH_MASK"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0400L)
#error          "Error��Please reconfigure HCTouchLib_TK_CH_MASK"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0800L)
#error          "Error��Please reconfigure HCTouchLib_TK_CH_MASK"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x1000L)
#error          "Error��Please reconfigure HCTouchLib_TK_CH_MASK"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x2000L)
#error          "Error��Please reconfigure HCTouchLib_TK_CH_MASK"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x4000L)
#error          "Error��Please reconfigure HCTouchLib_TK_CH_MASK"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x8000L)
#error          "Error��Please reconfigure HCTouchLib_TK_CH_MASK"
#endif

#elif (HCTouchLib_IC_BODY == IC_BODY_SOP20_DIP20)

#if (HCTouchLib_TK_CH_MASK & 0x0001L)
#pragma message "TK2��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0002L)
#pragma message "TK3��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0004L)
#pragma message "TK7��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0008L)
#pragma message "TK9��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0010L)
#pragma message "TK10��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0020L)
#pragma message "TK11��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0040L)
#pragma message "TK12��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0080L)
#pragma message "TK13��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0100L)
#pragma message "TK14��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0200L)
#pragma message "TK15��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0400L)
#error          "Error��Please reconfigure HCTouchLib_TK_CH_MASK"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0800L)
#error          "Error��Please reconfigure HCTouchLib_TK_CH_MASK"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x1000L)
#error          "Error��Please reconfigure HCTouchLib_TK_CH_MASK"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x2000L)
#error          "Error��Please reconfigure HCTouchLib_TK_CH_MASK"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x4000L)
#error          "Error��Please reconfigure HCTouchLib_TK_CH_MASK"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x8000L)
#error          "Error��Please reconfigure HCTouchLib_TK_CH_MASK"
#endif

#elif (HCTouchLib_IC_BODY == IC_BODY_SOP24)

#if (HCTouchLib_TK_CH_MASK & 0x0001L)
#pragma message "TK0��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0002L)
#pragma message "TK1��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0004L)
#pragma message "TK2��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0008L)
#pragma message "TK3��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0010L)
#pragma message "TK7��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0020L)
#pragma message "TK9��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0040L)
#pragma message "TK10��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0080L)
#pragma message "TK11��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0100L)
#pragma message "TK12��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0200L)
#pragma message "TK13��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0400L)
#pragma message "TK14��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0800L)
#pragma message "TK15��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x1000L)
#error          "Error��Please reconfigure HCTouchLib_TK_CH_MASK"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x2000L)
#error          "Error��Please reconfigure HCTouchLib_TK_CH_MASK"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x4000L)
#error          "Error��Please reconfigure HCTouchLib_TK_CH_MASK"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x8000L)
#error          "Error��Please reconfigure HCTouchLib_TK_CH_MASK"
#endif

#elif (HCTouchLib_IC_BODY == IC_BODY_SOP28)

#if (HCTouchLib_TK_CH_MASK & 0x0001L)
#pragma message "TK0��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0002L)
#pragma message "TK1��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0004L)
#pragma message "TK2��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0008L)
#pragma message "TK3��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0010L)
#pragma message "TK4��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0020L)
#pragma message "TK5��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0040L)
#pragma message "TK6��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0080L)
#pragma message "TK7��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0100L)
#pragma message "TK8��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0200L)
#pragma message "TK9��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0400L)
#pragma message "TK10��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0800L)
#pragma message "TK11��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x1000L)
#pragma message "TK12��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x2000L)
#pragma message "TK13��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x4000L)
#pragma message "TK14��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x8000L)
#pragma message "TK15��Enable"
#endif

#endif
//================================================================================
//================================================================================
#if (HCTouchLib_DSCR > 255)
#error	"Error��Please setting HCTouchLib_DSCR < 256"
#endif

//================================================================================
#pragma message "CTK����Ƶ�ʣ�Fosc/2"

//================================================================================
//================================================================================
#if (HCTouchLib_PRSDIV > 3)
#error 	"Error��Please setting HCTouchLib_PRSDIV <= 3" 
#elif (HCTouchLib_PRSDIV ==0)
#pragma message "CTK��ŵ�Ƶ�ʣ�Fosc/2"
#elif (HCTouchLib_PRSDIV ==1)
#pragma message "CTK��ŵ�Ƶ�ʣ�Fosc/4"
#elif (HCTouchLib_PRSDIV ==2)
#pragma message "CTK��ŵ�Ƶ�ʣ�Fosc/8"
#elif (HCTouchLib_PRSDIV ==3)
#pragma message "CTK��ŵ�Ƶ�ʣ�Fosc/16"
#endif

//================================================================================
#if (HCTouchLib_VD > 3)
#error 	"Error��Please setting HCTouchLib_VD < 4"
#elif (HCTouchLib_VD ==0)
#pragma message "CTK����Դ��ѹ��2V "
#elif (HCTouchLib_VD ==1)
#pragma message "CTK����Դ��ѹ��2.5V"
#elif (HCTouchLib_VD ==2)
#pragma message "CTK����Դ��ѹ��3V"
#elif (HCTouchLib_VD ==3)
#pragma message "CTK����Դ��ѹ��4V"
#endif

//================================================================================
#pragma message "CTK��ŵ�α�������"

//================================================================================
#pragma message "CTK�ο���ѹ��0.60V"

//================================================================================
#if (HCTouchLib_RBS > 7)
#error 	"Error��Please setting HCTouchLib_RBS < 8"
#elif (HCTouchLib_RBS ==0)
#pragma message "CTK�ŵ���裺0.5"
#elif (HCTouchLib_RBS ==1)
#pragma message "CTK�ŵ���裺1"
#elif (HCTouchLib_RBS ==2)
#pragma message "CTK�ŵ���裺2"
#elif (HCTouchLib_RBS ==3)
#pragma message "CTK�ŵ���裺4"
#elif (HCTouchLib_RBS ==4)
#pragma message "CTK�ŵ���裺8"
#elif (HCTouchLib_RBS ==5)
#pragma message "CTK�ŵ���裺16"
#elif (HCTouchLib_RBS ==6)
#pragma message "CTK�ŵ���裺32"
#elif (HCTouchLib_RBS ==7)
#pragma message "CTK�ŵ���裺64"
#endif

//================================================================================
#pragma message "CTK���Ƶ��ݣ����õ���"

//================================================================================
#pragma message "CTK����ɨ��ģʽ����"

//================================================================================
#pragma message "CTKɨ�貹�����ر�"

//================================================================================
#if ((HCTouchLib_CONFIRM_TOUCH_TIME == 0)|(HCTouchLib_CONFIRM_TOUCH_TIME > 255))
#error	"Error��Please setting 0 < HCTouchLib_CONFIRM_TOUCH_TIME < 256"
#endif

//================================================================================
#if ((HCTouchLib_CONFIRM_NOTOUCH_TIME == 0)|(HCTouchLib_CONFIRM_NOTOUCH_TIME > 255))
#error 	"Error��Please setting 0 < HCTouchLib_CONFIRM_NOTOUCH_TIME < 256"
#endif

//================================================================================
#if (HCTouchLib_HYSTERESIS == 0 )
#pragma message "������������: �ر�"
#elif (HCTouchLib_HYSTERESIS > 255))
#error 	"Error��Please setting 0 < HCTouchLib_HYSTERESIS < 256"
#endif

#if (((0 < HCTouchLib_CONFIRM_SHORTTOUCH_TIME)&&(HCTouchLib_CONFIRM_SHORTTOUCH_TIME <= HCTouchLib_CONFIRM_TOUCH_TIME))|(HCTouchLib_CONFIRM_SHORTTOUCH_TIME > 2000))
#error 	"Error��Please setting HCTouchLib_CONFIRM_LONGTOUCH_TIME = 0 or HCTouchLib_CONFIRM_TOUCH_TIME < HCTouchLib_CONFIRM_SHORTTOUCH_TIME < 2000"
#endif

//================================================================================
#if (((0 < HCTouchLib_CONFIRM_LONGTOUCH_TIME)&&(HCTouchLib_CONFIRM_LONGTOUCH_TIME <= HCTouchLib_CONFIRM_SHORTTOUCH_TIME))|(HCTouchLib_CONFIRM_LONGTOUCH_TIME > 65535))
#error 	"Error��Please setting HCTouchLib_CONFIRM_LONGTOUCH_TIME = 0 or HCTouchLib_CONFIRM_SHORTTOUCH_TIME < HCTouchLib_CONFIRM_LONGTOUCH_TIME < 65536"
#endif

//================================================================================
#if ((HCTouchLib_LIMIT_FACTOR == 1)|(HCTouchLib_LIMIT_FACTOR > 256))
#error 	"Error��Please setting 1 < HCTouchLib_LIMIT_FACTOR < 256"
#endif

//================================================================================
#if (HCTouchLib_THRESHOLD_NOISE_TIME == 0)
#pragma message "CTK��ֵ��������: �ر�"
#elif (HCTouchLib_THRESHOLD_NOISE_TIME > 65536)
#error 	"Error��Please setting HCTouchLib_OVERLOW_TIME < 65536"
#else
#pragma message "CTK��ֵ��������: ��"
#endif

//================================================================================
#if (HCTouchLib_OVERLOW_TIME == 0)
#pragma message "CTK�ͻ�׼�߸�λ: �ر�"
#elif ((HCTouchLib_OVERLOW_TIME > 65536)|(HCTouchLib_OVERLOW_TIME < HCTouchLib_CONFIRM_NOTOUCH_TIME))
#error 	"Error��Please setting HCTouchLib_CONFIRM_NOTOUCH_TIME < HCTouchLib_OVERLOW_TIME < 65536"
#else
#pragma message "CTK�ͻ�׼�߸�λ: ��"
#endif

//================================================================================
#if ((HCTouchLib_NOISE_BARREL_CAPACITY <= 1)|(HCTouchLib_NOISE_BARREL_CAPACITY > 256))
#error 	"Error��Please setting 1 < HCTouchLib_NOISE_BARREL_CAPACITY < 256"
#endif


//================================================================================
#if (HCTouchLib_ANTI_CS_SCAN_SW == 0)
#pragma message "CTK ��CSɨ��: �ر�"
#elif (HCTouchLib_ANTI_CS_SCAN_SW == 1)
#pragma message "CTK ��CSɨ��: ��"
#else
#error 	"Error��Please setting HCTouchLib_FILTER_DEPTH = 0 or HCTouchLib_FILTER_DEPTH = 1"
#endif


//================================================================================
#pragma message "CTKͨ��У׼: ��"

//================================================================================
#if (HCTouchLib_FILTER_DEPTH == 0)
#pragma message "CTK RawData������λֵƽ���˲�: �ر�"
#elif ((HCTouchLib_FILTER_DEPTH >= 3)&&(HCTouchLib_FILTER_DEPTH <= 15))
#pragma message "CTK RawData������λֵƽ���˲�: ��"
#else
#error 	"Error��Please setting 3 <= HCTouchLib_FILTER_DEPTH <= 15"
#endif

//================================================================================
#if (HCTouchLib_MULTIBUTTON == 0)
#pragma message "CTK��ϰ�������: �ఴ��ģʽ"
#elif (HCTouchLib_MULTIBUTTON == 1)
#pragma message "CTK��ϰ�������: ������ģʽ"
#elif (HCTouchLib_MULTIBUTTON == 2)
#pragma message "CTK��ϰ�������: ˫����ģʽ"
#else
#error 	"Error��Please setting HCTouchLib_MULTIBUTTON = 0 or HCTouchLib_MULTIBUTTON = 1 or HCTouchLib_MULTIBUTTON = 2"
#endif


#endif /* __YX23F01CB_GeneralKey_Touch_Lib_Build_Message_H__ */

/******************************************************************************************************

 ******************************************************************************************************/

