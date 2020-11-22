
#ifndef __YX23F01CB_GeneralKey_Touch_Lib_Build_Message_H__
#define __YX23F01CB_GeneralKey_Touch_Lib_Build_Message_H__

//================================================================================
#if (HCTouchLib_IC_BODY == IC_BODY_SOP16)

#if (HCTouchLib_TK_CH_MASK & 0x0001L)
#pragma message "TK2：Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0002L)
#pragma message "TK7：Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0004L)
#pragma message "TK11：Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0008L)
#pragma message "TK12：Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0010L)
#pragma message "TK13：Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0020L)
#pragma message "TK14：Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0040L)
#pragma message "TK15：Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0080L)
#error          "Error：Please reconfigure HCTouchLib_TK_CH_MASK"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0100L)
#error          "Error：Please reconfigure HCTouchLib_TK_CH_MASK"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0200L)
#error          "Error：Please reconfigure HCTouchLib_TK_CH_MASK"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0400L)
#error          "Error：Please reconfigure HCTouchLib_TK_CH_MASK"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0800L)
#error          "Error：Please reconfigure HCTouchLib_TK_CH_MASK"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x1000L)
#error          "Error：Please reconfigure HCTouchLib_TK_CH_MASK"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x2000L)
#error          "Error：Please reconfigure HCTouchLib_TK_CH_MASK"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x4000L)
#error          "Error：Please reconfigure HCTouchLib_TK_CH_MASK"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x8000L)
#error          "Error：Please reconfigure HCTouchLib_TK_CH_MASK"
#endif

#elif (HCTouchLib_IC_BODY == IC_BODY_SOP20_DIP20)

#if (HCTouchLib_TK_CH_MASK & 0x0001L)
#pragma message "TK2：Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0002L)
#pragma message "TK3：Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0004L)
#pragma message "TK7：Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0008L)
#pragma message "TK9：Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0010L)
#pragma message "TK10：Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0020L)
#pragma message "TK11：Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0040L)
#pragma message "TK12：Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0080L)
#pragma message "TK13：Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0100L)
#pragma message "TK14：Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0200L)
#pragma message "TK15：Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0400L)
#error          "Error：Please reconfigure HCTouchLib_TK_CH_MASK"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0800L)
#error          "Error：Please reconfigure HCTouchLib_TK_CH_MASK"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x1000L)
#error          "Error：Please reconfigure HCTouchLib_TK_CH_MASK"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x2000L)
#error          "Error：Please reconfigure HCTouchLib_TK_CH_MASK"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x4000L)
#error          "Error：Please reconfigure HCTouchLib_TK_CH_MASK"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x8000L)
#error          "Error：Please reconfigure HCTouchLib_TK_CH_MASK"
#endif

#elif (HCTouchLib_IC_BODY == IC_BODY_SOP24)

#if (HCTouchLib_TK_CH_MASK & 0x0001L)
#pragma message "TK0：Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0002L)
#pragma message "TK1：Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0004L)
#pragma message "TK2：Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0008L)
#pragma message "TK3：Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0010L)
#pragma message "TK7：Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0020L)
#pragma message "TK9：Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0040L)
#pragma message "TK10：Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0080L)
#pragma message "TK11：Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0100L)
#pragma message "TK12：Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0200L)
#pragma message "TK13：Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0400L)
#pragma message "TK14：Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0800L)
#pragma message "TK15：Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x1000L)
#error          "Error：Please reconfigure HCTouchLib_TK_CH_MASK"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x2000L)
#error          "Error：Please reconfigure HCTouchLib_TK_CH_MASK"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x4000L)
#error          "Error：Please reconfigure HCTouchLib_TK_CH_MASK"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x8000L)
#error          "Error：Please reconfigure HCTouchLib_TK_CH_MASK"
#endif

#elif (HCTouchLib_IC_BODY == IC_BODY_SOP28)

#if (HCTouchLib_TK_CH_MASK & 0x0001L)
#pragma message "TK0：Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0002L)
#pragma message "TK1：Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0004L)
#pragma message "TK2：Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0008L)
#pragma message "TK3：Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0010L)
#pragma message "TK4：Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0020L)
#pragma message "TK5：Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0040L)
#pragma message "TK6：Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0080L)
#pragma message "TK7：Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0100L)
#pragma message "TK8：Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0200L)
#pragma message "TK9：Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0400L)
#pragma message "TK10：Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0800L)
#pragma message "TK11：Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x1000L)
#pragma message "TK12：Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x2000L)
#pragma message "TK13：Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x4000L)
#pragma message "TK14：Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x8000L)
#pragma message "TK15：Enable"
#endif

#endif
//================================================================================
//================================================================================
#if (HCTouchLib_DSCR > 255)
#error	"Error：Please setting HCTouchLib_DSCR < 256"
#endif

//================================================================================
#pragma message "CTK采样频率：Fosc/2"

//================================================================================
//================================================================================
#if (HCTouchLib_PRSDIV > 3)
#error 	"Error：Please setting HCTouchLib_PRSDIV <= 3" 
#elif (HCTouchLib_PRSDIV ==0)
#pragma message "CTK充放电频率：Fosc/2"
#elif (HCTouchLib_PRSDIV ==1)
#pragma message "CTK充放电频率：Fosc/4"
#elif (HCTouchLib_PRSDIV ==2)
#pragma message "CTK充放电频率：Fosc/8"
#elif (HCTouchLib_PRSDIV ==3)
#pragma message "CTK充放电频率：Fosc/16"
#endif

//================================================================================
#if (HCTouchLib_VD > 3)
#error 	"Error：Please setting HCTouchLib_VD < 4"
#elif (HCTouchLib_VD ==0)
#pragma message "CTK充电电源电压：2V "
#elif (HCTouchLib_VD ==1)
#pragma message "CTK充电电源电压：2.5V"
#elif (HCTouchLib_VD ==2)
#pragma message "CTK充电电源电压：3V"
#elif (HCTouchLib_VD ==3)
#pragma message "CTK充电电源电压：4V"
#endif

//================================================================================
#pragma message "CTK充放电伪随机：打开"

//================================================================================
#pragma message "CTK参考电压：0.60V"

//================================================================================
#if (HCTouchLib_RBS > 7)
#error 	"Error：Please setting HCTouchLib_RBS < 8"
#elif (HCTouchLib_RBS ==0)
#pragma message "CTK放电电阻：0.5"
#elif (HCTouchLib_RBS ==1)
#pragma message "CTK放电电阻：1"
#elif (HCTouchLib_RBS ==2)
#pragma message "CTK放电电阻：2"
#elif (HCTouchLib_RBS ==3)
#pragma message "CTK放电电阻：4"
#elif (HCTouchLib_RBS ==4)
#pragma message "CTK放电电阻：8"
#elif (HCTouchLib_RBS ==5)
#pragma message "CTK放电电阻：16"
#elif (HCTouchLib_RBS ==6)
#pragma message "CTK放电电阻：32"
#elif (HCTouchLib_RBS ==7)
#pragma message "CTK放电电阻：64"
#endif

//================================================================================
#pragma message "CTK调制电容：内置电容"

//================================================================================
#pragma message "CTK连续扫描模式：打开"

//================================================================================
#pragma message "CTK扫描补偿：关闭"

//================================================================================
#if ((HCTouchLib_CONFIRM_TOUCH_TIME == 0)|(HCTouchLib_CONFIRM_TOUCH_TIME > 255))
#error	"Error：Please setting 0 < HCTouchLib_CONFIRM_TOUCH_TIME < 256"
#endif

//================================================================================
#if ((HCTouchLib_CONFIRM_NOTOUCH_TIME == 0)|(HCTouchLib_CONFIRM_NOTOUCH_TIME > 255))
#error 	"Error：Please setting 0 < HCTouchLib_CONFIRM_NOTOUCH_TIME < 256"
#endif

//================================================================================
#if (HCTouchLib_HYSTERESIS == 0 )
#pragma message "触摸按键迟滞: 关闭"
#elif (HCTouchLib_HYSTERESIS > 255))
#error 	"Error：Please setting 0 < HCTouchLib_HYSTERESIS < 256"
#endif

#if (((0 < HCTouchLib_CONFIRM_SHORTTOUCH_TIME)&&(HCTouchLib_CONFIRM_SHORTTOUCH_TIME <= HCTouchLib_CONFIRM_TOUCH_TIME))|(HCTouchLib_CONFIRM_SHORTTOUCH_TIME > 2000))
#error 	"Error：Please setting HCTouchLib_CONFIRM_LONGTOUCH_TIME = 0 or HCTouchLib_CONFIRM_TOUCH_TIME < HCTouchLib_CONFIRM_SHORTTOUCH_TIME < 2000"
#endif

//================================================================================
#if (((0 < HCTouchLib_CONFIRM_LONGTOUCH_TIME)&&(HCTouchLib_CONFIRM_LONGTOUCH_TIME <= HCTouchLib_CONFIRM_SHORTTOUCH_TIME))|(HCTouchLib_CONFIRM_LONGTOUCH_TIME > 65535))
#error 	"Error：Please setting HCTouchLib_CONFIRM_LONGTOUCH_TIME = 0 or HCTouchLib_CONFIRM_SHORTTOUCH_TIME < HCTouchLib_CONFIRM_LONGTOUCH_TIME < 65536"
#endif

//================================================================================
#if ((HCTouchLib_LIMIT_FACTOR == 1)|(HCTouchLib_LIMIT_FACTOR > 256))
#error 	"Error：Please setting 1 < HCTouchLib_LIMIT_FACTOR < 256"
#endif

//================================================================================
#if (HCTouchLib_THRESHOLD_NOISE_TIME == 0)
#pragma message "CTK阈值噪声更新: 关闭"
#elif (HCTouchLib_THRESHOLD_NOISE_TIME > 65536)
#error 	"Error：Please setting HCTouchLib_OVERLOW_TIME < 65536"
#else
#pragma message "CTK阈值噪声更新: 打开"
#endif

//================================================================================
#if (HCTouchLib_OVERLOW_TIME == 0)
#pragma message "CTK低基准线复位: 关闭"
#elif ((HCTouchLib_OVERLOW_TIME > 65536)|(HCTouchLib_OVERLOW_TIME < HCTouchLib_CONFIRM_NOTOUCH_TIME))
#error 	"Error：Please setting HCTouchLib_CONFIRM_NOTOUCH_TIME < HCTouchLib_OVERLOW_TIME < 65536"
#else
#pragma message "CTK低基准线复位: 打开"
#endif

//================================================================================
#if ((HCTouchLib_NOISE_BARREL_CAPACITY <= 1)|(HCTouchLib_NOISE_BARREL_CAPACITY > 256))
#error 	"Error：Please setting 1 < HCTouchLib_NOISE_BARREL_CAPACITY < 256"
#endif


//================================================================================
#if (HCTouchLib_ANTI_CS_SCAN_SW == 0)
#pragma message "CTK 抗CS扫描: 关闭"
#elif (HCTouchLib_ANTI_CS_SCAN_SW == 1)
#pragma message "CTK 抗CS扫描: 打开"
#else
#error 	"Error：Please setting HCTouchLib_FILTER_DEPTH = 0 or HCTouchLib_FILTER_DEPTH = 1"
#endif


//================================================================================
#pragma message "CTK通道校准: 打开"

//================================================================================
#if (HCTouchLib_FILTER_DEPTH == 0)
#pragma message "CTK RawData递推中位值平均滤波: 关闭"
#elif ((HCTouchLib_FILTER_DEPTH >= 3)&&(HCTouchLib_FILTER_DEPTH <= 15))
#pragma message "CTK RawData递推中位值平均滤波: 打开"
#else
#error 	"Error：Please setting 3 <= HCTouchLib_FILTER_DEPTH <= 15"
#endif

//================================================================================
#if (HCTouchLib_MULTIBUTTON == 0)
#pragma message "CTK组合按键处理: 多按键模式"
#elif (HCTouchLib_MULTIBUTTON == 1)
#pragma message "CTK组合按键处理: 单按键模式"
#elif (HCTouchLib_MULTIBUTTON == 2)
#pragma message "CTK组合按键处理: 双按键模式"
#else
#error 	"Error：Please setting HCTouchLib_MULTIBUTTON = 0 or HCTouchLib_MULTIBUTTON = 1 or HCTouchLib_MULTIBUTTON = 2"
#endif


#endif /* __YX23F01CB_GeneralKey_Touch_Lib_Build_Message_H__ */

/******************************************************************************************************

 ******************************************************************************************************/

