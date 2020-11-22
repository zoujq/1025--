
//================================================================================
#define  ALLOCATE_EXTERN
#include "YX23F01CB.h"
#include "YX23F01CB_SYS.h"
#include "YX23F01CB_IO_INIT.h"
#include "YX23F01CB_GeneralKey_Touch_Lib_V2.00\YX23F01CB_GeneralKey_Touch_Lib.h"
#include "YX23F01CB_GeneralKey_Touch_Lib_V2.00\YX23F01CB_GeneralKey_Touch_Auxiliary.h"
#include "YX23F01CB_TouchUartDebug_Lib_V2.00\YX23F01CB_TouchUartDebug_Lib_CFG.h"
#include "YX23F01CB_TouchUartDebug_Lib_V2.00\YX23F01CB_TouchUartDebug_Lib.h"
#include "YX23F01CB_PORT_MAP.h"
//================================================================================
void main()
{
	SystemInit();						//ʱ�ӳ�ʼ������(Ĭ��Fosc=Fcpu=16M)
	FREQ_CLK = 0x10;
	IO_Init();

	EA = 1;
	CTK_Init();							
#if TouchUartDebugLib_SW
	CTK_TouchUartDebug_Init();			//�������ڵ��Գ�ʼ��
#endif 
	
	while(1)
	{
		if(OneCycleScanDone)
		{
			Touch_Signal_Handle();
			OneCycleScanDone = 0;
		}

		
		if(TouchKeyFlag)
		{
			//TouchKeyFlag Ϊ���������־�Ĵ�����������鿴YX23F01CB_GeneralKey_Touch_Lib.h
			
		}
			

  }
}


