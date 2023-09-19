STM32单片机PVD功能操作流程解析   
STM32内部自带PVD功能，用于对MCU供电电压VDD进行监控。通过电
源控制寄存器中的PLS［2:0］位可以用来设定监控电压的阀值，通过对外部电压进行比较
来监控电源。当条件触发，需要系统进入特别保护状态，执行紧急关闭任务：对系统的
一些数据保存起来，同时对外设进行相应的保护操作。
 操作流程： 
 1）、
系统启动后启动PVD，并开启相应的中断。  
PWR_PVDLevelConfig（PWR_PVDLevel_2V8）; // 设定监控阀值 
PWR_PVDCmd（ENABLE）; // 使能PVD 
EXTI_StrucTInit（  
EXTI_InitStructure.EXTI_Line = EXTI_Line16; // PVD连接到中断线16上 
EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt; //使用中断模式  
EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Raising;//电压低于阀值时产生中断 
EXTI_InitStructure.EXTI_LineCmd = ENABLE; // 使能中断线 
EXTI_Init（ // 初始  
EXTI_InitStructure.EXTI_Trigger的赋值可选项：  
EXTI_Trigger_Rising---表示电压从高下降到低于设定阀值时产生中断； 
EXTI_Trigger_Falling---表示电压从低上升到高于设定阀值时产生中断；  
EXTI_Trigger_Rising_Falling---表示电压上升或下降越过设定阀值时都产生中断。 
2）、当工作电压低于设定阀值时，将产生PVD中断，在中断程序中进行相应的处理： 
void PVD_IRQHandler（void） 
{ 
 EXTI_ClearITPendingBit（EXTI_Line16）;
 …… // 用户添加紧急处理代码处 
}  
