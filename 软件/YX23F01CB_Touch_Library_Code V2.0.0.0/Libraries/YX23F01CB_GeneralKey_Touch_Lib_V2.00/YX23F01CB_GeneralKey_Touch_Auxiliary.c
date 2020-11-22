
#include "YX23F01CB.h"
#include "YX23F01CB_GeneralKey_Touch_Lib_V2.00\YX23F01CB_GeneralKey_Touch_Lib.h"
#include "YX23F01CB_GeneralKey_Touch_Lib_V2.00\YX23F01CB_GeneralKey_Touch_Auxiliary.h"
#include "YX23F01CB_GeneralKey_Touch_Lib_V2.00\YX23F01CB_GeneralKey_Touch_Lib_CFG.h"
#include <string.h> 

//===================================================================================================
extern ux16	XDATA_RawData[];					//�˲���RawData
extern ux16	XDATA_RawDataBuf[];					//�ɼ�����RawData
extern sx16 XDATA_BaseLine[];					//Baseline
extern uc8  CODE_INTERNAL_INDEX[];				//��ӦIC��ͨ����
extern uc8  CODE_TK_CH_MAX;						//��ӦIC��ͨ������
extern ux8	XDATA_OpenChannel[];
//===================================================================================================
#define HexadecimalToBinary(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p)	\
(																\
	(a<<15)+(b<<14)+(c<<13)+(d<<12)+							\
	(e<<11)+(f<<10)+(g<<9)+(h<<8)+								\
	(i<<7)+(j<<6)+(k<<5)+(l<<4)+								\
	(m<<3)+(n<<2)+(o<<1)+(p<<0)									\
)
#define TKBIN HexadecimalToBinary

//�����ļ��ͨ������
#define HCTouchLib_OPENED_TK_AMOUNT \
((HCTouchLib_TK_CH_MASK>> 0 & 0x01L)+(HCTouchLib_TK_CH_MASK>> 1 & 0x01L)+(HCTouchLib_TK_CH_MASK>> 2 & 0x01L)+(HCTouchLib_TK_CH_MASK>> 3 & 0x01L)+\
 (HCTouchLib_TK_CH_MASK>> 4 & 0x01L)+(HCTouchLib_TK_CH_MASK>> 5 & 0x01L)+(HCTouchLib_TK_CH_MASK>> 6 & 0x01L)+(HCTouchLib_TK_CH_MASK>> 7 & 0x01L)+\
 (HCTouchLib_TK_CH_MASK>> 8 & 0x01L)+(HCTouchLib_TK_CH_MASK>> 9 & 0x01L)+(HCTouchLib_TK_CH_MASK>>10 & 0x01L)+(HCTouchLib_TK_CH_MASK>>11 & 0x01L)+\
 (HCTouchLib_TK_CH_MASK>>12 & 0x01L)+(HCTouchLib_TK_CH_MASK>>13 & 0x01L)+(HCTouchLib_TK_CH_MASK>>14 & 0x01L)+(HCTouchLib_TK_CH_MASK>>15 & 0x01L))

#if HCTouchLib_MULTIBUTTON	
unsigned char code nuc_CombinationKeyA_a[2] = HCTouchLib_COMBINATIONKEYA;
unsigned char code nuc_CombinationKeyB_a[2] = HCTouchLib_COMBINATIONKEYB;
unsigned char code nuc_CombinationKeyC_a[2] = HCTouchLib_COMBINATIONKEYC;
unsigned char code nuc_CombinationKeyD_a[2] = HCTouchLib_COMBINATIONKEYD;
#endif	

//===================================================================================================
#if HCTouchLib_FILTER_DEPTH	
ux16 XDATA_RawData_Filter[HCTouchLib_OPENED_TK_AMOUNT][HCTouchLib_FILTER_DEPTH];
#endif	


/***************************************************************************************
  * @˵��  	�ఴ������ð������
  *	@����	fi_ArrDataOne_a ����������1
  *			fuc_ArrDataTwo_a ����������2
  *			fuc_Len���������鳤��
  * @����ֵ ��
  * @ע		��
***************************************************************************************/
#if HCTouchLib_MULTIBUTTON						//ʹ�ܶఴ������
static void MultiButtonBubbleSort(s16 fi_ArrDataOne_a[], u8 fuc_ArrDataTwo_a[], u8 fuc_Len)
{
    s16 fi_TempOne = 0;
	u8  fuc_TempTwo = 0;
    u8 fuc_i = 0, fuc_j = 0;
    for (fuc_i=0; fuc_i<fuc_Len-1; fuc_i++)
	{
        for (fuc_j=0; fuc_j<fuc_Len-1-fuc_i; fuc_j++) 
		{ 
            if (fi_ArrDataOne_a[fuc_j] > fi_ArrDataOne_a[fuc_j+1]) 
			{ 
                fi_TempOne = fi_ArrDataOne_a[fuc_j];
                fi_ArrDataOne_a[fuc_j] = fi_ArrDataOne_a[fuc_j+1];
                fi_ArrDataOne_a[fuc_j+1] = fi_TempOne;
				
				fuc_TempTwo = fuc_ArrDataTwo_a[fuc_j];
				fuc_ArrDataTwo_a[fuc_j] = fuc_ArrDataTwo_a[fuc_j+1];
				fuc_ArrDataTwo_a[fuc_j+1] = fuc_TempTwo;
            }
        }	
	}
}
#endif


/***************************************************************************************
  * @˵��  	����fuc_SearchData��fuc_ArrData_a[]��λ�ã����ҷ�����λ��
  *	@����	fuc_SearchData ����Ҫ���ҵ�����
  *			fuc_ArrData_a �������ҵ�����
  *			fuc_Len �����ҵ����ݳ���
  * @����ֵ fc_Ret : �����������������ڵ�λ�ã��粻���ڣ��򷵻�-1
  * @ע		��
***************************************************************************************/
#if HCTouchLib_MULTIBUTTON
char Search(u8 fuc_SearchData, u8 fuc_ArrData_a[], u8 fuc_Len)
{
	s8 fc_Ret = -1;
	u8 fuc_i = 0;
	for(fuc_i=0; fuc_i<fuc_Len; fuc_i++)
	{
		if(fuc_ArrData_a[fuc_i] == fuc_SearchData)
		{
			fc_Ret = fuc_i;
			break;
		}
	}
	return fc_Ret;
}
#endif	


/***************************************************************************************
  * @˵��  	��ϰ���������
  *	@����	��
  * @����ֵ ��
  * @ע		��
***************************************************************************************/
void TouchMultibuttonHandle(void)
{
#if HCTouchLib_MULTIBUTTON	
	u8  fuc_TouchKeyFlagNum = 0;
	u8  fuc_i = 0;
	s8 	fc_ChannelLocationFirst	= 0;
	s8 	fc_ChannelLocationSecond = 0;
	s16 fi_MultibuttonDiffer_a[HCTouchLib_OPENED_TK_AMOUNT] = {0x0000};
	u8  fuc_BubbleSortChannel_a[HCTouchLib_OPENED_TK_AMOUNT] = {0x00};

	fuc_TouchKeyFlagNum = (TouchKeyFlag>> 0 & 0x01L)+(TouchKeyFlag>> 1 & 0x01L)+(TouchKeyFlag>> 2 & 0x01L)+(TouchKeyFlag>> 3 & 0x01L)+\
						  (TouchKeyFlag>> 4 & 0x01L)+(TouchKeyFlag>> 5 & 0x01L)+(TouchKeyFlag>> 6 & 0x01L)+(TouchKeyFlag>> 7 & 0x01L)+\
						  (TouchKeyFlag>> 8 & 0x01L)+(TouchKeyFlag>> 9 & 0x01L)+(TouchKeyFlag>>10 & 0x01L)+(TouchKeyFlag>>11 & 0x01L)+\
						  (TouchKeyFlag>>12 & 0x01L)+(TouchKeyFlag>>13 & 0x01L)+(TouchKeyFlag>>14 & 0x01L)+(TouchKeyFlag>>15 & 0x01L);
	//����ͬʱ�м���ͨ��ͬʱ��Ч
	if(fuc_TouchKeyFlagNum >= 2)
	{
		for(fuc_i = 0;fuc_i < HCTouchLib_OPENED_TK_AMOUNT;fuc_i++)
		{
			fi_MultibuttonDiffer_a[fuc_i] = (s16)(XDATA_RawData[fuc_i] - XDATA_BaseLine[fuc_i]);
		}
		memcpy(fuc_BubbleSortChannel_a,XDATA_OpenChannel,HCTouchLib_OPENED_TK_AMOUNT);
		//ÿ���������¸���ͨ������
		MultiButtonBubbleSort(fi_MultibuttonDiffer_a,fuc_BubbleSortChannel_a,HCTouchLib_OPENED_TK_AMOUNT);
		//ð�����򣬽�����ͨ���ŵ�fuc_BubbleSortChannel_a[HCTouchLib_OPENED_TK_AMOUNT-1]��
		
#if   (HCTouchLib_MULTIBUTTON == 1)
	  //����ǵ�����
		fc_ChannelLocationFirst = Search(fuc_BubbleSortChannel_a[HCTouchLib_OPENED_TK_AMOUNT-1],CODE_INTERNAL_INDEX,CODE_TK_CH_MAX);
		//�ж�һ�����İ����Ƿ����
		if(fc_ChannelLocationFirst!= -1)
		{
			TouchKeyFlag = (0x01L<<fc_ChannelLocationFirst);
		}
#elif (HCTouchLib_MULTIBUTTON == 2)
	  //�����˫����
		fc_ChannelLocationFirst = Search(fuc_BubbleSortChannel_a[HCTouchLib_OPENED_TK_AMOUNT-1],CODE_INTERNAL_INDEX,CODE_TK_CH_MAX);
		fc_ChannelLocationSecond = Search(fuc_BubbleSortChannel_a[HCTouchLib_OPENED_TK_AMOUNT-2],CODE_INTERNAL_INDEX,CODE_TK_CH_MAX);
		if(((CODE_INTERNAL_INDEX[fc_ChannelLocationFirst] == nuc_CombinationKeyA_a[0])&&(CODE_INTERNAL_INDEX[fc_ChannelLocationSecond] == nuc_CombinationKeyA_a[1]))\
		   ||((CODE_INTERNAL_INDEX[fc_ChannelLocationFirst] == nuc_CombinationKeyA_a[1])&&(CODE_INTERNAL_INDEX[fc_ChannelLocationSecond] == nuc_CombinationKeyA_a[0])))
		{
			TouchKeyFlag = (0x01L<<fc_ChannelLocationFirst);
			TouchKeyFlag |= (0x01L<<fc_ChannelLocationSecond);
		}
		else if(((CODE_INTERNAL_INDEX[fc_ChannelLocationFirst] == nuc_CombinationKeyB_a[0])&&(CODE_INTERNAL_INDEX[fc_ChannelLocationSecond] == nuc_CombinationKeyB_a[1]))\
		        ||((CODE_INTERNAL_INDEX[fc_ChannelLocationFirst] == nuc_CombinationKeyB_a[1])&&(CODE_INTERNAL_INDEX[fc_ChannelLocationSecond] == nuc_CombinationKeyB_a[0])))
		{
			TouchKeyFlag = (0x01L<<fc_ChannelLocationFirst);
			TouchKeyFlag |= (0x01L<<fc_ChannelLocationSecond);		
		}
		else if(((CODE_INTERNAL_INDEX[fc_ChannelLocationFirst] == nuc_CombinationKeyC_a[0])&&(CODE_INTERNAL_INDEX[fc_ChannelLocationSecond] == nuc_CombinationKeyC_a[1]))\
		        ||((CODE_INTERNAL_INDEX[fc_ChannelLocationFirst] == nuc_CombinationKeyC_a[1])&&(CODE_INTERNAL_INDEX[fc_ChannelLocationSecond] == nuc_CombinationKeyC_a[0])))
		{
			TouchKeyFlag = (0x01L<<fc_ChannelLocationFirst);
			TouchKeyFlag |= (0x01L<<fc_ChannelLocationSecond);		
		}		
		else if(((CODE_INTERNAL_INDEX[fc_ChannelLocationFirst] == nuc_CombinationKeyD_a[0])&&(CODE_INTERNAL_INDEX[fc_ChannelLocationSecond] == nuc_CombinationKeyD_a[1]))\
		        ||((CODE_INTERNAL_INDEX[fc_ChannelLocationFirst] == nuc_CombinationKeyD_a[1])&&(CODE_INTERNAL_INDEX[fc_ChannelLocationSecond] == nuc_CombinationKeyD_a[0])))
		{
			TouchKeyFlag = (0x01L<<fc_ChannelLocationFirst);
			TouchKeyFlag |= (0x01L<<fc_ChannelLocationSecond);		
		}			
		else
		{
			if(fc_ChannelLocationFirst!= -1)
			{
				TouchKeyFlag = (0x01L<<fc_ChannelLocationFirst);
			}		
		}
#endif			
	}
#endif		
}



/***************************************************************************************
  * @˵��  	�˲�ð������
  *	@����	fui_ArrData_a ����������
  *			fuc_Len���������鳤��
  * @����ֵ ��
  * @ע		��
***************************************************************************************/
#if HCTouchLib_FILTER_DEPTH						//ʹ���˲�
static void FilterBubbleSort(u16 fui_ArrData_a[], u8 fuc_Len)
{
    u16 fui_Temp = 0;
    u8 fuc_i = 0, fuc_j = 0;
    for (fuc_i=0; fuc_i<fuc_Len-1; fuc_i++)
	{
        for (fuc_j=0; fuc_j<fuc_Len-1-fuc_i; fuc_j++) 
		{ 
            if (fui_ArrData_a[fuc_j] > fui_ArrData_a[fuc_j+1]) 
			{ 
                fui_Temp = fui_ArrData_a[fuc_j];
                fui_ArrData_a[fuc_j] = fui_ArrData_a[fuc_j+1];
                fui_ArrData_a[fuc_j+1] = fui_Temp;
            }
        }	
	}
}
#endif	

/***************************************************************************************
  * @˵��  	�˲�����
  *	@����	��
  * @����ֵ ��
  * @ע		��
***************************************************************************************/
void TouchRawDataFilter(void)
{
#if HCTouchLib_FILTER_DEPTH		//ʹ���˲�				
	unsigned char fuc_i = 0, fuc_j = 0, fuc_z = 0;
	unsigned long ful_Num[HCTouchLib_OPENED_TK_AMOUNT] = {0x00};

	for(fuc_i = 0; fuc_i < HCTouchLib_OPENED_TK_AMOUNT; fuc_i++)
	{
		XDATA_RawData_Filter[fuc_i][HCTouchLib_FILTER_DEPTH-1] = XDATA_RawDataBuf[fuc_i];
		for(fuc_j = 0; fuc_j<HCTouchLib_FILTER_DEPTH-1; fuc_j++)
		{
			XDATA_RawData_Filter[fuc_i][fuc_j] = XDATA_RawData_Filter[fuc_i][fuc_j+1];
		}
		FilterBubbleSort(XDATA_RawData_Filter[fuc_i],HCTouchLib_FILTER_DEPTH);
		for(fuc_z = 1; fuc_z<HCTouchLib_FILTER_DEPTH-1; fuc_z++)
		{
			ful_Num[fuc_i] += XDATA_RawData_Filter[fuc_i][fuc_z];
		}
		ful_Num[fuc_i] /=  (HCTouchLib_FILTER_DEPTH-2);
		XDATA_RawData[fuc_i] = (u16)(ful_Num[fuc_i]);	
	}
#else											//û��ʹ���˲�
	unsigned char fuc_i = 0;
	for(fuc_i = 0;fuc_i < HCTouchLib_OPENED_TK_AMOUNT;fuc_i++)
	{
		XDATA_RawData[fuc_i] = XDATA_RawDataBuf[fuc_i];
	}	
#endif
	
}

/******************************************************************************************************

 ******************************************************************************************************/
