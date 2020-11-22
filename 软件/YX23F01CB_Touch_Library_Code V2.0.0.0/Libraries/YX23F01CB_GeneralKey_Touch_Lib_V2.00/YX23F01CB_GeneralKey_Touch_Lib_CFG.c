

//===================================================================================================
#include "YX_DEFINE.H"
#include "YX23F01CB_GeneralKey_Touch_Lib_V2.00\YX23F01CB_GeneralKey_Touch_Lib_CFG.h"
#include "YX23F01CB_GeneralKey_Touch_Lib_V2.00\YX23F01CB_GeneralKey_Touch_Auxiliary.h"

//===================================================================================================
#define IC_BODY_SOP20_DIP20                   0   //YX23F01CB	SOP20/DIP20
#define IC_BODY_SOP24                         1   //YX23F01CB	SOP24
#define IC_BODY_SOP28                         2   //YX23F01CB	SOP28
#define IC_BODY_SOP16                         3   //YX23F01CB	SOP16


//===================================================================================================
#define HexadecimalToBinary(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p)	\
(																\
	(a<<15)+(b<<14)+(c<<13)+(d<<12)+							\
	(e<<11)+(f<<10)+(g<<9)+(h<<8)+								\
	(i<<7)+(j<<6)+(k<<5)+(l<<4)+								\
	(m<<3)+(n<<2)+(o<<1)+(p<<0)									\
)
#define TKBIN HexadecimalToBinary

//===================================================================================================
#if (HCTouchLib_IC_BODY == IC_BODY_SOP16)
#pragma message "IC Body: YX23F01CB-SOP16"
#define TK_CH_MAX  		7
uc8 CODE_INTERNAL_INDEX[TK_CH_MAX] = {2, 7, 11, 12, 13, 14, 15};

#elif (HCTouchLib_IC_BODY == IC_BODY_SOP20_DIP20)
#pragma message "IC Body: YX23F01CB-SOP20/DIP20"
#define TK_CH_MAX  		10
uc8 CODE_INTERNAL_INDEX[TK_CH_MAX] = {2, 3, 7, 9, 10, 11, 12, 13, 14, 15};

#elif (HCTouchLib_IC_BODY == IC_BODY_SOP24)
#pragma message "IC Body: YX23F01CB-SOP24"
#define TK_CH_MAX  		12
uc8 CODE_INTERNAL_INDEX[TK_CH_MAX] = {0, 1, 2, 3, 7, 9, 10, 11, 12, 13, 14, 15};

#elif (HCTouchLib_IC_BODY == IC_BODY_SOP28)
#pragma message "IC Body: YX23F01CB-SOP28"
#define TK_CH_MAX  		16
uc8 CODE_INTERNAL_INDEX[TK_CH_MAX] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

#else
#define TK_CH_MAX  		1
uc8 CODE_INTERNAL_INDEX[TK_CH_MAX] = {0};
#error "No IC Body,Please reconfigure HCTouchLib_IC_BODY"
#endif

//===================================================================================================
#include "YX23F01CB_GeneralKey_Touch_Lib_V2.00\YX23F01CB_GeneralKey_Touch_Lib_Build_Message.h"

//===================================================================================================
#if ((HCTouchLib_TK_CH_MASK & (0xFFFF >> (16 - TK_CH_MAX))) == 0)
#error "No channel is enabled,Please reconfigure HCTouchLib_TK_CH_MASK"
#endif

//===================================================================================================
//开启的检测通道个数
#define HCTouchLib_OPENED_TK_AMOUNT \
((HCTouchLib_TK_CH_MASK>> 0 & 0x01L)+(HCTouchLib_TK_CH_MASK>> 1 & 0x01L)+(HCTouchLib_TK_CH_MASK>> 2 & 0x01L)+(HCTouchLib_TK_CH_MASK>> 3 & 0x01L)+\
 (HCTouchLib_TK_CH_MASK>> 4 & 0x01L)+(HCTouchLib_TK_CH_MASK>> 5 & 0x01L)+(HCTouchLib_TK_CH_MASK>> 6 & 0x01L)+(HCTouchLib_TK_CH_MASK>> 7 & 0x01L)+\
 (HCTouchLib_TK_CH_MASK>> 8 & 0x01L)+(HCTouchLib_TK_CH_MASK>> 9 & 0x01L)+(HCTouchLib_TK_CH_MASK>>10 & 0x01L)+(HCTouchLib_TK_CH_MASK>>11 & 0x01L)+\
 (HCTouchLib_TK_CH_MASK>>12 & 0x01L)+(HCTouchLib_TK_CH_MASK>>13 & 0x01L)+(HCTouchLib_TK_CH_MASK>>14 & 0x01L)+(HCTouchLib_TK_CH_MASK>>15 & 0x01L))

//===================================================================================================
uc16	CODE_TK_CH_MASK                 = HCTouchLib_TK_CH_MASK;
uc16	CODE_TK_LONGKEY                 = HCTouchLib_TK_LONGKEY;
uc8		CODE_CHANNEL_CALIBRATE_SW       = 0;
uc8		CODE_CALIBRATE_DEFLECTED_AREA   = 20;
uc16	CODE_CALIBRATE_TARGET_LINE      = 0;
uc8		CODE_DSCR                       = HCTouchLib_DSCR;
uc8		CODE_CTKDS_PRSDIV               = (0 << 4) | (1 << 3) | HCTouchLib_PRSDIV;
uc8		CODE_CTKDS_PRSDIV_ANTICS        = (0 << 4) | (1 << 3) | (HCTouchLib_PRSDIV + 1);
uc8		CODE_VD_RV                      = (HCTouchLib_VD << 4) | 0;
uc8		CODE_RBS                        = (0 << 7) | HCTouchLib_RBS;
uc16	CODE_OVERLOW_TIME               = HCTouchLib_OVERLOW_TIME;
uc8		CODE_CONFIRM_TOUCH_TIME         = HCTouchLib_CONFIRM_TOUCH_TIME;
uc8		CODE_CONFIRM_NOTOUCH_TIME       = HCTouchLib_CONFIRM_NOTOUCH_TIME;
uc8		CODE_LIMIT_FACTOR               = HCTouchLib_LIMIT_FACTOR;
uc8		CODE_BARREL_CAPACITY            = HCTouchLib_NOISE_BARREL_CAPACITY;
uc16	CODE_NOISE_THRESHOLD[16]        = HCTouchLib_NOISE_THRESHOLD;
uc16	CODE_FINGER_THRESHOLD[16]       = HCTouchLib_FINGER_THRESHOLD;
uc8		CODE_OPENED_TK_AMOUNT           = HCTouchLib_OPENED_TK_AMOUNT;
uc8		CODE_HYSTERESIS					= HCTouchLib_HYSTERESIS;
uc8 	CODE_TK_CH_MAX                  = TK_CH_MAX;
uc8		CODE_FILTER_DEPTH				= HCTouchLib_FILTER_DEPTH;
uc8		CODE_ANTI_CS_SCAN_SW			= HCTouchLib_ANTI_CS_SCAN_SW;
uc16	CODE_RAWDATA_OVER				= ((HCTouchLib_DSCR+1)*256-1)/10*8;
uc16	CODE_RAWDATA_MAX				= ((HCTouchLib_DSCR+1)*256-1);
uc8		CODE_ANTI_CS_OFFSET				= 4;
//===================================================================================================
ux16	XDATA_RawData 	 	[HCTouchLib_OPENED_TK_AMOUNT];
ux16	XDATA_RawDataBuf 	[HCTouchLib_OPENED_TK_AMOUNT];
ux16	XDATA_RawDataAntiCS	[HCTouchLib_OPENED_TK_AMOUNT];
sx16 	XDATA_BaseLine	 	[HCTouchLib_OPENED_TK_AMOUNT];
ux16 	XDATA_OverLowCnt 	[HCTouchLib_OPENED_TK_AMOUNT];
ux8 	XDATA_TouchCnt   	[HCTouchLib_OPENED_TK_AMOUNT];
ux8 	XDATA_NoTouchCnt 	[HCTouchLib_OPENED_TK_AMOUNT];
sx16 	XDATA_DifferAccum	[HCTouchLib_OPENED_TK_AMOUNT];
ux16	XDATA_LongRstCnt 	[HCTouchLib_OPENED_TK_AMOUNT];
ux16	XDATA_THRNoiseCnt	[HCTouchLib_OPENED_TK_AMOUNT];
ux8		XDATA_OpenChannel	[HCTouchLib_OPENED_TK_AMOUNT];
ux8  	XDATA_AccessIndex	[TK_CH_MAX];
ux8  	XDATA_LongKeyIndex	[TK_CH_MAX];
ux16	XDATA_ConfirmLongTouchTime	= HCTouchLib_CONFIRM_LONGTOUCH_TIME;
ux16	XDATA_ConfirmShortTouchTime	= HCTouchLib_CONFIRM_SHORTTOUCH_TIME;
ux16	XDATA_ThresholdNoiseTime	= HCTouchLib_THRESHOLD_NOISE_TIME;
ux8		XDATA_ThresholdRatio			= 10;
ux8		XDATA_FineTuning				= 2;

/******************************************************************************************************

 ******************************************************************************************************/
 