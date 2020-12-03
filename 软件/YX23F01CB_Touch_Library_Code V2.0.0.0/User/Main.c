
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
#include <stdio.h>

//=======================================public data=====================================
//display buffer
char g_shu_ma_guan1=0;
char g_shu_ma_guan2=0;
char g_touch_led1=0;
char g_touch_led2=0;
char g_touch_led3=0;
//work status
char g_work_mode=0;
char g_feng_su=0;
char g_yao_tou=0;
char g_ding_shi=0;
u16  g_ding_shi_timer=0;
char g_xi_ping=0;
u16 op_over_time=0;
char op_type=0;
//=======================================delay============================================================
void Delay_50us(unsigned int n)	   
{
	unsigned char i;
	while(n--)
	{
		for(i=0;i<71;i++);
	}
}
void Delay_ms(unsigned int delay_nms)
{
	while(delay_nms--)
	{
		Delay_50us(20);
	}
}
//===================================================================================================
//=======================================printf============================================================
#define PRINTF_BAUDRATE  		9600   
#define TX  P2_0
void init_printf()
{
	P2M0 = 0xC1;				        //
	
	TXD_MAP = 0x20;						//TXD
	
	T4CON = 0x06;						//

	SCON2 = 0x02;   // uart mode 1
	
	T4 = 65536.5 - (SYSCLK_FOSC / 16 / PRINTF_BAUDRATE); //


}

char putchar (char c)
{
	SBUF = c;

	while(!TI);

	TI = 0;
  	return 0;
}
//===================================================================================================
#define DISPLAY_A  P2_1
#define DISPLAY_B  P2_0
#define DISPLAY_C  P0_1
#define DISPLAY_D  P0_0
#define DISPLAY_E  P2_7
#define DISPLAY_F  P2_6
#define DISPLAY_G  P2_5
//
#define DISPLAY_COM1 P3_4
#define DISPLAY_COM2 P2_3
#define TOUCH_LED_COM P2_2

void init_display()
{
	P2M1=GPIO_Out_PP;
	P2M0=GPIO_Out_PP;
	P0M1=GPIO_Out_PP;
	P0M0=GPIO_Out_PP;
	P2M7=GPIO_Out_PP;
	P2M6=GPIO_Out_PP;
	P2M5=GPIO_Out_PP;

	P3M4=GPIO_Out_PP;
	P2M3=GPIO_Out_PP;
	P2M2=GPIO_Out_PP;

	DISPLAY_A=0;
	DISPLAY_B=0;
	DISPLAY_C=0;
	DISPLAY_D=0;
	DISPLAY_E=0;
	DISPLAY_F=0;
	DISPLAY_G=0;

	DISPLAY_COM1=1;
	DISPLAY_COM2=1;
	TOUCH_LED_COM=1;
}

void display_close()
{
	DISPLAY_A=0;
	DISPLAY_B=0;
	DISPLAY_C=0;
	DISPLAY_D=0;
	DISPLAY_E=0;
	DISPLAY_F=0;
	DISPLAY_G=0;

	DISPLAY_COM1=1;
	DISPLAY_COM2=1;
	TOUCH_LED_COM=1;

}
void display(char c,char b)
{
	DISPLAY_COM1=1;
	DISPLAY_COM2=1;
	TOUCH_LED_COM=1;
	switch(c)
	{
		case 0:
			DISPLAY_A=1;	DISPLAY_B=1;	DISPLAY_C=1;	DISPLAY_D=1;	DISPLAY_E=1;	DISPLAY_F=1;	DISPLAY_G=0;
			break;
		case 1:
			DISPLAY_A=0;	DISPLAY_B=1;	DISPLAY_C=1;	DISPLAY_D=0;	DISPLAY_E=0;	DISPLAY_F=0;	DISPLAY_G=0;
			break;
		case 2:
			DISPLAY_A=1;	DISPLAY_B=1;	DISPLAY_C=0;	DISPLAY_D=1;	DISPLAY_E=1;	DISPLAY_F=0;	DISPLAY_G=1;
			break;
		case 3:
			DISPLAY_A=1;	DISPLAY_B=1;	DISPLAY_C=1;	DISPLAY_D=1;	DISPLAY_E=0;	DISPLAY_F=0;	DISPLAY_G=1;
			break;
		case 4:
			DISPLAY_A=0;	DISPLAY_B=1;	DISPLAY_C=1;	DISPLAY_D=0;	DISPLAY_E=0;	DISPLAY_F=1;	DISPLAY_G=1;
			break;
		case 5:
			DISPLAY_A=1;	DISPLAY_B=0;	DISPLAY_C=1;	DISPLAY_D=1;	DISPLAY_E=0;	DISPLAY_F=1;	DISPLAY_G=1;
			break;
		case 6:
			DISPLAY_A=1;	DISPLAY_B=0;	DISPLAY_C=1;	DISPLAY_D=1;	DISPLAY_E=1;	DISPLAY_F=1;	DISPLAY_G=1;
			break;
		case 7:
			DISPLAY_A=1;	DISPLAY_B=1;	DISPLAY_C=1;	DISPLAY_D=0;	DISPLAY_E=0;	DISPLAY_F=0;	DISPLAY_G=0;
			break;
		case 8:
			DISPLAY_A=1;	DISPLAY_B=1;	DISPLAY_C=1;	DISPLAY_D=1;	DISPLAY_E=1;	DISPLAY_F=1;	DISPLAY_G=1;
			break;
		case 9:
			DISPLAY_A=1;	DISPLAY_B=1;	DISPLAY_C=1;	DISPLAY_D=1;	DISPLAY_E=0;	DISPLAY_F=1;	DISPLAY_G=1;
			break;
		case 'H':
			DISPLAY_A=0;	DISPLAY_B=1;	DISPLAY_C=1;	DISPLAY_D=0;	DISPLAY_E=1;	DISPLAY_F=1;	DISPLAY_G=1;
			break;
		case 'P':
			DISPLAY_A=1;	DISPLAY_B=1;	DISPLAY_C=0;	DISPLAY_D=0;	DISPLAY_E=1;	DISPLAY_F=1;	DISPLAY_G=1;
			break;
		default:
			DISPLAY_A=0;	DISPLAY_B=0;	DISPLAY_C=0;	DISPLAY_D=0;	DISPLAY_E=0;	DISPLAY_F=0;	DISPLAY_G=0;
			break;
		
	}
	if(b==1)
	{
		DISPLAY_COM1=0;
		DISPLAY_COM2=1;
		TOUCH_LED_COM=1;
	}
	else if(b==2)
	{
		DISPLAY_COM1=1;
		DISPLAY_COM2=0;
		TOUCH_LED_COM=1;
	}
	else if(b==3)
	{
		DISPLAY_A=0;	
		DISPLAY_B=0;	
		DISPLAY_C=0;	
		DISPLAY_D=0;	
		DISPLAY_E=0;	
		DISPLAY_F=0;	
		DISPLAY_G=0;
		if(g_touch_led1==1)
		{
			DISPLAY_B=1;
		}
		if(g_touch_led2==1)
		{
			DISPLAY_C=1;
		}
		if(g_touch_led3==1)
		{
			DISPLAY_D=1;
		}
		DISPLAY_COM1=1;
		DISPLAY_COM2=1;
		TOUCH_LED_COM=0;
	}
	
}
void display_flush()
{
	static char tt=0;
	if(g_xi_ping==0)
	{
		if(tt==1)
		{
			display(g_shu_ma_guan1,1);
		}
		else if(tt==2)
		{
			display(g_shu_ma_guan2,2);
		}
		else if(tt==3)
		{
			display('X',3);
			tt=0;
		}
		tt++;
	}
	else
	{
		display_close();
	}
	

}
//===================================================================================================
#define BUZZ P2_4
void  buzzer()
{
	static char inited=0;
	int i=0;
	// if(inited==0)
	// {
		P2M4 = 0xC2;                        //P24设置为推挽输出
		PWM3_MAP = 0x24;					//PWM3映射P03口
		PWM3P = 0x20;						//PWM周期为0xFF
		PWM3D = 0x10;						//PWM占空比设置
		PWM3C = 0x97; 						//使能PWM3，关闭中断，允许输出，时钟4分频
		inited=1;
	// }	
	PWM3C = 0x97;	
	Delay_ms(100);
	PWM3C = 0x07;
	P2M4=GPIO_In_AN;
	
}
//================================================================================
void touch_key_check()
{
	static char touched=0;
	if(TouchKeyFlag)
	{
		if(touched==0)
		{
			touched=1;
			if(TouchKeyFlag & 0x0800L)
			{
				if(g_work_mode==0)
				{
					g_work_mode=1;
					g_ding_shi=0;
					g_feng_su=1;
					g_yao_tou=0;	
					
				}
				else
				{
					g_work_mode=0;
					g_ding_shi=0;
					g_feng_su=0;
					g_yao_tou=0;
					g_xi_ping=0;
				}

			}
			if(g_work_mode==1)
			{
				buzzer();
				if(TouchKeyFlag & 0x0400L)
				{
					op_over_time=0;
					op_type=0;
					if(g_feng_su==1)
					{
						g_feng_su=2;
					}
					else if(g_feng_su==2)
					{
						g_feng_su=3;
					}
					else
					{
						g_feng_su=1;
					}
				}
				else if(TouchKeyFlag & 0x0200L)
				{
					if(g_yao_tou==0)
					{
						g_yao_tou=1;
					}
					else
					{
						g_yao_tou=0;
					}
				}
				else if(TouchKeyFlag & 0x0100L)
				{
					op_over_time=0;
					if(g_ding_shi<9)
					{
						g_ding_shi++;
						op_type=1;
					}
					else
					{
						g_ding_shi=0;
						op_type=0;
					}
					g_ding_shi_timer=g_ding_shi*60;					
				}
			}
		}
		
	}
	else
	{
		touched=0;
	}
}

//========================================NEC=====================================
u8 nec_timer=0; 
u8 nec_end_flag=0;
u8 nec_start_flag=0;
xdata u8 nec_buff[34];
u8 nec_index=0;
xdata u8 nec_data[4];
u16 nec_doing=0;
void init_timer0()
{
	TCON1 = 0x00;						//
	TMOD = 0x00;						//
	
	TH0 = 0xFF;
	TL0 = 0x7B;							//100us
	IE |= 0x02;							//
	TCON |= 0x10;						//
    
}
void init_ext_int_17()
{
	P3M5 = 0x69;			      //P35设置为带SMT上拉输入
	PITS4 |= 0x04;					//INT17下降沿	
	PINTE2 = 0x02;
	IE2 |= 0x01;							//打开INT17中断
	
}
void ISR_INT_TIME0(void) interrupt TIMER0_VECTOR  //时基100us
{
	static u32 tt=0;

	nec_timer++;
	if(nec_timer>150)
	{
		nec_end_flag=1;
		nec_timer=0;
	}
	if(tt%50)//5ms
	{
		display_flush();
	}
	
 	if(tt++>600000)
	{
		tt=0;
		if(g_ding_shi_timer>0)
		{
			g_ding_shi_timer--;
			g_ding_shi=	g_ding_shi_timer/60+1;
			if(g_ding_shi_timer==0)
			{
				g_work_mode=0;
				g_ding_shi=0;
			}	
				
		}
	}
	nec_doing++;
}	


void ISR_INT16_17(void)  interrupt INT16_17_VECTOR
{
	PINTF2 &=~ 0x02;				//清除INT17中断标志位		
	if(nec_start_flag)
	{
		if(nec_timer>105)
		{
			nec_index=0;
		}
		nec_buff[nec_index]=nec_timer;
		nec_timer=0;
		nec_index++;
		if(nec_index>33)
		{
			nec_index=0;
		}
		nec_end_flag=0;
	}
	else
	{
		nec_start_flag=1;
		nec_timer=0;
	}
}
void nec_chu_li();
void nec_decode()
{
	if(nec_index && nec_end_flag)
	{
		nec_data[0]=(nec_buff[1]<0x0F ? 0 : 1)<<0 |
					(nec_buff[2]<0x0F ? 0 : 1)<<1 |
					(nec_buff[3]<0x0F ? 0 : 1)<<2 |
					(nec_buff[4]<0x0F ? 0 : 1)<<3 |
					(nec_buff[5]<0x0F ? 0 : 1)<<4 |
					(nec_buff[6]<0x0F ? 0 : 1)<<5 |
					(nec_buff[7]<0x0F ? 0 : 1)<<6 |
					(nec_buff[8]<0x0F ? 0 : 1)<<7 ;
		nec_data[1]=(nec_buff[9]<0x0F ? 0 : 1)<<0 |
					(nec_buff[10]<0x0F ? 0 : 1)<<1 |
					(nec_buff[11]<0x0F ? 0 : 1)<<2 |
					(nec_buff[12]<0x0F ? 0 : 1)<<3 |
					(nec_buff[13]<0x0F ? 0 : 1)<<4 |
					(nec_buff[14]<0x0F ? 0 : 1)<<5 |
					(nec_buff[15]<0x0F ? 0 : 1)<<6 |
					(nec_buff[16]<0x0F ? 0 : 1)<<7 ;
		nec_data[2]=(nec_buff[17]<0x0F ? 0 : 1)<<0 |
					(nec_buff[18]<0x0F ? 0 : 1)<<1 |
					(nec_buff[19]<0x0F ? 0 : 1)<<2 |
					(nec_buff[20]<0x0F ? 0 : 1)<<3 |
					(nec_buff[21]<0x0F ? 0 : 1)<<4 |
					(nec_buff[22]<0x0F ? 0 : 1)<<5 |
					(nec_buff[23]<0x0F ? 0 : 1)<<6 |
					(nec_buff[24]<0x0F ? 0 : 1)<<7 ;
		nec_data[3]=(nec_buff[25]<0x0F ? 0 : 1)<<0 |
					(nec_buff[26]<0x0F ? 0 : 1)<<1 |
					(nec_buff[27]<0x0F ? 0 : 1)<<2 |
					(nec_buff[28]<0x0F ? 0 : 1)<<3 |
					(nec_buff[29]<0x0F ? 0 : 1)<<4 |
					(nec_buff[30]<0x0F ? 0 : 1)<<5 |
					(nec_buff[31]<0x0F ? 0 : 1)<<6 |
					(nec_buff[32]<0x0F ? 0 : 1)<<7 ;
		nec_index=0;
		nec_chu_li();	
		
		putchar(nec_data[0]);
		putchar(nec_data[1]);
		putchar(nec_data[2]);
		putchar(nec_data[3]);
		
		{
			int i=0;
			for(i=0;i<33;i++)
			{
				nec_buff[i]=0;
			}
			
		}
	}
}
void nec_chu_li()
{
	if(nec_data[0]==0 && nec_data[1]==0xFF)
	{
		if(nec_doing<3000)
		{
			return;
		}
		nec_doing=0;
		if(nec_data[2]==0x46)
		{
			if(g_work_mode==0)
			{
				g_work_mode=1;
				g_ding_shi=0;
				g_feng_su=1;
				g_yao_tou=0;
			}
			else
			{
				g_work_mode=0;
				g_ding_shi=0;
				g_feng_su=0;
				g_yao_tou=0;
				g_xi_ping=0;
			}

		}
		if(g_work_mode==1)
		{
			buzzer();
			if(nec_data[2]==0x44)
			{
				op_over_time=0;
				op_type=0;
				if(g_feng_su==1)
				{
					g_feng_su=2;
				}
				else if(g_feng_su==2)
				{
					g_feng_su=3;
				}
				else
				{
					g_feng_su=1;
				}
			}
			else if(nec_data[2]==0x43)
			{
				if(g_yao_tou==0)
				{
					g_yao_tou=1;
				}
				else
				{
					g_yao_tou=0;
				}
			}
			else if(nec_data[2]==0x16)
			{
				op_over_time=0;
				if(g_ding_shi<9)
				{
					g_ding_shi++;
					op_type=1;
				}
				else
				{
					g_ding_shi=0;
					op_type=0;
				}
				g_ding_shi_timer=g_ding_shi*60;
			}
			
		}
		if(nec_data[2]==0x0D)
		{
			if(g_xi_ping==0)
			{
				g_xi_ping=1;
			}
			else
			{
				g_xi_ping=0;
			}
			
		}
	}
	
	
}
//===============================================================================
#define FAN_YAO_TOU P0_7
#define FAN_DW1 P1_3
#define FAN_DW2 P1_2
#define FAN_DW3 P1_1
void init_work()
{
	P0M7=GPIO_Out_PP;
	P1M3=GPIO_Out_PP;
	P1M2=GPIO_Out_PP;
	P1M1=GPIO_Out_PP;
}
void work_check()
{
	if(g_work_mode==1)
	{
		g_touch_led1=1;
		if(g_yao_tou)
		{
			g_touch_led2=1;
			FAN_YAO_TOU=1;
		}
		else
		{
			g_touch_led2=0;
			FAN_YAO_TOU=0;
		}
		if(g_ding_shi_timer>0)
		{
			g_touch_led3=1;
		}
		else
		{
			g_touch_led3=0;
		}
		if(g_feng_su==1)
		{
			FAN_DW1=1;
			FAN_DW2=0;
			FAN_DW3=0;
		}
		else if(g_feng_su==2)
		{
			FAN_DW1=0;
			FAN_DW2=1;
			FAN_DW3=0;
		}
		else if(g_feng_su==3)
		{
			FAN_DW1=0;
			FAN_DW2=0;
			FAN_DW3=1;
		}
		if(op_over_time<200)
		{
			op_over_time++;
			if(op_type==0)
			{
				g_shu_ma_guan1='P';
				g_shu_ma_guan2=g_feng_su;
			}
			else
			{
				if(g_ding_shi>=1)
				{
					g_shu_ma_guan1=g_ding_shi;
					g_shu_ma_guan2='H';
				}
				else
				{
					g_shu_ma_guan1='P';
					g_shu_ma_guan2=g_feng_su;
				}
			}
		}
		else{
			if(g_ding_shi>=1)
			{
				g_shu_ma_guan1=g_ding_shi;
				g_shu_ma_guan2='H';
			}
			else
			{
				g_shu_ma_guan1='P';
				g_shu_ma_guan2=g_feng_su;
			}
		
		}
		

	}
	else
	{
		g_feng_su=0;
		g_yao_tou=0;
		g_ding_shi=0;
		g_ding_shi_timer=0;
		g_shu_ma_guan1=0;
		g_shu_ma_guan2=0;
		g_touch_led1=0;
		g_touch_led2=0;
		g_touch_led3=0;
	}
}


//================================================================================
void main()
{
	SystemInit();						//16M
	FREQ_CLK = 0x10;
	IO_Init();

	EA = 1;
	CTK_Init();	
	
	//init_printf();
	init_display();
	init_timer0();
	init_ext_int_17();
	init_work();
	

	while(1)
	{
		if(OneCycleScanDone)
		{
			Touch_Signal_Handle();
			OneCycleScanDone = 0;
		}

		touch_key_check();
		nec_decode();
		work_check();
		Delay_ms(10);

  }
}


