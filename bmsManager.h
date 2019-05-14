/**
* @file bmsManager.h
* @brief bms协议管理
* @author zshare
* @version v1.0
* @date 2018-10-08
* @history  2018-10-08 	封装bms协议
*						说明关于报文代号，B-bms发送，C-充电机发送
*/

#ifndef __BMSMANAGER_H_

#define __BMSMANAGER_H_

//#include "dataType.h"

#define BMSADDR 0xf4	//bms地址
#define CHRGADDR 0x56	//充电机地址




/*=====================握手阶段定义==========================*/
#define PFCHM	0x26	//CHM报文的pf值 充电机握手报文
#define PFBHM	0x27	//BHM报文的pf值	车辆握手报文
#define PFCRM	0x01	//CRM报文的pf值	充电机辨识报文
#define PFBRM	0x02	//BRM报文的pf值	BMS和车辆辨识报文

#define WAITTIMECHM	250	//chm报文周期250ms
#define WAITTIMEBHM	250	//bhm报文周期250ms
#define WAITTIMECRM	250	//crm报文周期250ms
#define WAITTIMEBRM	250	//brm报文周期250ms

/*=====================参数配置阶段定义==========================*/
#define PFBCP	0x06	//BCP动力蓄电池充电参数
#define PFCTS	0x07	//CTS充电机发送时间同步信息
#define PFCML	0x08	//CML充电机最大输出能力
#define PFBRO	0x09	//BRO电池充电准备就绪状态
#define PFCRO	0x0a	//CRO充电机输出准备就绪状态

#define WAITTIMEBCP	500	//BCP报文周期500ms
#define WAITTIMECTS	500	//CTS报文周期500ms
#define WAITTIMECML	250	//CML报文周期250ms
#define WAITTIMEBRO	250	//BRO报文周期250ms
#define WAITTIMECRO	250	//CRO报文周期250ms

/*=====================充电阶段定义==========================*/
#define PFBCL	0x10	//BCL电池充电需求
#define PFBCS	0x11	//BCS电池充电总状态
#define PFCCS	0x12	//CCS充电机充电状态
#define PFBSM	0x13	//BSM动力蓄电池状态信息
//下述三条报文不进行超时判定
#define PFBMV	0x15	//BMV单体动力蓄电池电压
#define PFBMT	0x16	//BMT动力蓄电池温度
#define PFBSP	0x17	//BSP动力蓄电池预留报文

#define PFBST	0x19	//BSTBMS中止充电
#define PFCST	0x1a	//CST充电机中止充电

#define WAITTIMEBCL	50	//BCL电池充电需求报文周期50ms
#define WAITTIMEBCS	250	//BCS电池充电总状态报文周期250ms
#define WAITTIMECCS	50	//CCS充电机充电状态报文周期50ms
#define WAITTIMEBSM	250	//BSM动力蓄电池状态信息报文周期250ms
//下述三条报文不进行超时判定
#define WAITTIMEBMV	(10*1000)	//BMV单体动力蓄电池电压报文周期10s
#define WAITTIMEBMT	(10*1000)	//BMT动力蓄电池温度报文周期10s
#define WAITTIMEBSP	(10*1000)	//BSP动力蓄电池预留报文报文周期10s

#define WAITTIMEBST	10	//BSTBMS中止充电报文周期10ms
#define WAITTIMECST	10	//CST充电机中止充电报文周期10ms

/*=====================充电结束阶段定义==========================*/
#define PFBSD	0x1c	//BSDBMS统计数据
#define PFCSD	0x1d	//CSD充电机统计数据

#define WAITTIMEBSD	250	//BSDBMS统计数据报文周期250ms
#define WAITTIMECSD	250	//CSD充电机统计数据报文周期250ms

/*=====================错误报文定义==========================*/
#define PFBEM	0x1e	//BEMBMS错误报文
#define PFCEM	0x1f	//CEM充电机错误报文

#define WAITTIMEBEM	250	//BEMBMS错误报文报文周期250ms
#define WAITTIMECEM	250	//CEM充电机错误报文报文周期250ms


/*===========================================================*/
//事件定义
#define defEventBitChrgSendHandShakeOk	Bit0	//发送握手报文成功
#define defEventBitChrgRecvHandShakeOk	Bit1	//接收握手报文成功
#define defEventBitChrgRecvIdentyOk		Bit3	//接收车辆辨识报文成功
#define defEventBitChrgRecvBatChrgParaOk Bit4	//接收电池充电参数报文成功
#define defEventBitChrgRecvBatStateChrgNeedOk Bit5	//接收电池充电总状态和电池充电需求报文成功
#define defEventBitChrgRecvThreeMessageOk	Bit6	//接收电池充电需求报文、电池充电总状态报文、蓄电池状态报文成功
#define defEventBitChrgRecvBmsAbortChrgOk	Bit7	//接收到BMS中止充电报文
#define defEventBitChrgRecvBmsStatisticsDataOk	Bit8	//接收到BMS充电统计报文
/*==========================================================*/


//发送内容，发送周期，启动/中止发送报文,
#define CANCMDSND(cmd,time,signal)	canCmdProperty(cmd, time, signal)	//启动某条报文发送

#define CMDFUNCNAME(who,funcName,cmdName,other)	who##funcName##cmdName##other

//cancmd操作单元
typedef struct{
	char *cmdName;
	uint16_t time;
	uint8_t signal;
	tCANMsgObject (*cmdFunc)(bmsDataType bmsData);
}canCmdOperType;

//can指令数组
canCmdOperType canCmdOper[] = {
	{"chm",WAITTIMECHM,STOPSIGNAL,CMDFUNCNAME(chrg,HandShake,ChmCmd,Func)},
	{"crm",WAITTIMECRM,STOPSIGNAL,CMDFUNCNAME(chrg,Identify,CrmCmd,Func)},
	{"cts",WAITTIMECTS,STOPSIGNAL,CMDFUNCNAME(chrg,TimeSyn,CtsCmd,Func)},
	{"cml",WAITTIMECML,STOPSIGNAL,CMDFUNCNAME(chrg,OutPowerMax,CmlCmd,Func)},
	{"cro",WAITTIMECRO,STOPSIGNAL,CMDFUNCNAME(chrg,OutReadyOK,CroCmd,Func)},
	{"ccs",WAITTIMECCS,STOPSIGNAL,CMDFUNCNAME(chrg,ChrgStatue,CcsCmd,Func)},
	{"cst",WAITTIMECCS,STOPSIGNAL,CMDFUNCNAME(chrg,AbortChrging,CstCmd,Func)},
	{"csd",WAITTIMECCS,STOPSIGNAL,CMDFUNCNAME(chrg,StatisticalData,CsdCmd,Func)},
	{"NULL",0,0,NULL},
};

//bms协议中各个阶段单元
typedef struct{
	char *stageName;
	int (*stageFunc)(bmsDataType bmsData);
}bmsStageType;

//bms协议中各个阶段的管理数组
bmsStageType bmsStageProc[] = {
	{"handshakeIdentify1",handShakeStage0},
	{"handshakeIdentify2",handShakeStage1},
	{"paraConfig",paraConfigStage},
	{"chrging",chrgingStage},
	{"chrgDone",chrgDoneStage},
	{"NULL",NULL},
};

enum{
	STARTSIGNAL = 1,
	STOPSIGNAL = 2,
};

enum{
	STAGEOK = 0,
	INSFAILED,
	HANDSHAKEFAILED,
	CHRGPARACONFIGFAILED,
	BMSNEEDDATAFAILED,
	CHRGRECVTHREEMESSAGEFAILED,
	CHRGDONEFAILED,
};

//can数据域的实际数据长度
enum{
	DATALEN0=0,
	DATALEN1,
	DATALEN2,
	DATALEN3,
	DATALEN4,
	DATALEN5,
	DATALEN6,
	DATALEN7,
	DATALEN8,
	DATALEN9,
	DATALEN13=13,
	DATALEN41=41,
};

//优先权等级
enum{
	PRIORITY0=0,
	PRIORITY1,
	PRIORITY2,
	PRIORITY3,
	PRIORITY4,
	PRIORITY5,
	PRIORITY6,
	PRIORITY7,
};


enum{

	UNTRUSTSTATE,//不可信状态
};


//bms通信4个阶段
enum{
	HANDSHAKE=0,	//握手阶段
	CHRGPARACONFIG,	//充电参数配置阶段
	CHRGING,		//充电中阶段
	DONE,			//充电结束
};

//can协议帧head结构
typedef struct _structBmsCanMsgHead
{
    uint8_t     priority;	//优先权         最高0，最低7 	     3bits
    uint8_t     reserve;	//保留位  		1bit
    uint8_t    	dataPage;	//数据页       1bit
    uint8_t     pduFormat;//pf-PDU格式，用来确定pdu格式以及数据域对应的参数组编号               8bits
    uint8_t    	desAddr;//pdu特定格式，该值取决于pdu格式             该协议值为目标地址 8bits
	uint8_t		srcAddr;	//发送此报文的源地址	8bits
}structBmsCanMsgHead;

//can协议帧
typedef struct{
	structBmsCanMsgHead *canMsgHead;
	uint32_t maskId;	
	uint32_t flags;
	uint8_t dataLen;
	uint8_t data[8];
}structBmsCanMsg;

typedef struct{
	uint32_t bmsProVer;//bms版本byte3,byte2-0001H,byte1-01H
	uint8_t batType;//电池类型，
	uint16_t batRateCapacity;//电池额定容量
	uint16_t batRateVol;//电池额定总电压
	uint32_t manufacterName;//厂商名称
	uint32_t batSeriNum;//电池序号
	uint8_t	batYear;//电池生产日期年
	uint8_t batMonth;//电池生产日期月
	uint8_t batDate;//电池生产日期日
	uint32_t batChrgCount;//电池充电次数
	uint8_t reserver;//预留字节
	uint8_t batProperIdentify;//电池产权标识
	uint32_t carVIN[5];//车辆识别码VIN
	uint32_t bmsSoftWareVer[2];//bms软件版本
}structBmsIdentify;

typedef struct{
	uint16_t batPermitChrgVolMax;//电池最高允许充电电压
	uint16_t batPermitChrgCurMax;//最高允许输出充电电流
	uint16_t batPowerMax;//电池标称总能量
	uint16_t batPermitTotalChrgVolMax;//最高允许充电总电压
	uint8_t	batPermitTemp;//最高允许温度
	uint16_t batChrgState;//电池荷电状态
	uint16_t batCurrentVol;//当前电池电压
}structBmsChrgPara;

typedef struct{
	uint16_t batNeedVol;//电池充电需求电压
	uint16_t batNeedCur;//电池充电需求电流
	uint8_t batChrgMode;//电池充电模式	1-恒压模式；2-恒流模式
}structBmsBatNeedInfo;

typedef struct{
	uint16_t batVolMax;//最高单体动力蓄电池电压
	uint8_t batNum;//最高单体动力蓄电池组号
}highOnebatInfo;

typedef struct{
	uint16_t chrgVol;//充电电压测量值
	uint16_t chrgCur;//充电电流测量值
	highOnebatInfo batInfo;//最高单体动力蓄电池电压及其组号
	uint8_t batSoc;//当前荷电状态SOC%
	uint16_t residualChrgTime;//电池剩余充电时间
}structBmsChrgState;

typedef struct{
	uint8_t volMaxBatNumber;//最高单体动力蓄电池电压所在编号
	uint8_t batTempMax;//最高动力蓄电池温度
	uint8_t tempMaxBatNumber;//最高温度检测点编号
	uint8_t batTempMin;//最低动力蓄电池温度
	uint8_t tempMinBatNumber;//最低动力蓄电池温度检测点编号

	uint8_t batVolState:2;//单体动力蓄电池电压过高/过低 00-正常，01-过高；10-过低
	uint8_t batSocState:2;//整车动力蓄电池荷电状态00-正常，01-过高；10-过低
	uint8_t chrgCurState:2;//动力蓄电池充电过流00-正常；01-过流；10-不可信状态
	uint8_t batTempOverState:2;//动力蓄电池温度过高00-正常；01-过高；10-不可信状态
	uint8_t batInsulationState:2;//动力蓄电池绝缘状态00-正常；01-不正常；10-不可信状态
	uint8_t batConnectState:2;//动力蓄电池组输出连接器链接状态00-正常；01-不正常；10-不可信状态
	uint8_t chrgPermit:2;//充电允许	00-禁止，01-允许
}structBmsChrgBatStateInfo;

typedef struct{
	uint8_t bmsAbortChrgRes;//bms中止充电原因
	uint16_t bmsAbortChrgFaultRes;//bms中止充电故障原因
	uint8_t bmsabortChrgErrRes;//bms中止充电错误原因
}structBmsAbortChrgRes;

typedef struct{
	uint8_t bmsAbortSoc;//中止荷电状态soc
	uint16_t batVolMin;//动力蓄电池单体最低电压
	uint16_t batVolMax;//动力蓄电池单体最高电压
	uint8_t batTempMin;//动力蓄电池最低温度
	uint8_t batTempMax;//动力蓄电池最高温度
}structBmsAbortChrgData;

//bms数据结构
typedef struct{
	//bms帧信息
	structBmsCanMsg chmMsg;
	structBmsCanMsg bhmMsg;
	structBmsCanMsg	crmMsg;
	structBmsCanMsg ctsMsg;
	structBmsCanMsg cmlMsg;
	structBmsCanMsg	croMsg;
	structBmsCanMsg ccsMsg;
	structBmsCanMsg	cstMsg;
	structBmsCanMsg	csdMsg;

	//bms帧数据域
	//chrg发送数据
	uint32_t bmsProtocolVer;//标准规定当前版本为V1.1
	uint8_t identifyRes;//辨识结果，0x00-不能辨识，0xaa-bms能辨识
	uint32_t chrgEncode;//充电机编码
	uint32_t chrgAreaCode;//充电机区域编码
	uint16_t second;//秒
	uint16_t minute;//分
	uint16_t hour;//时
	uint16_t date;//日
	uint16_t month;//月
	uint16_t year;//年

	uint16_t outVolMax;//最高输出电压
	uint16_t outVolMin;//最低输出电压
	uint16_t outCurMax;//最大输出电流
	uint16_t outCurMin;//最小输出电流

	uint16_t outVol;//电压输出值
	uint16_t outCur;//电流输出值
	uint16_t chrgingTime;//充电时间min
	uint16_t chrgEnable;//充电允许 0x00-暂停；0x01-允许

	/*
		充电机中止充电原因 1~2位：00-正常；01-达到充电机设定条件中止；10-不可信状态
						   3~4位：00-人工中止；01-人工中止；10-不可信状态
						   5~6位：00-正常；01-故障中止；10-不可信状态
						   7~8位：00-正常；01-BMS中止；10-不可信状态
	*/

	uint8_t chrgAbortRes;
	/*
		充电机中止充电故障原因 1~2位：00-充电机温度正常；01-充电机过温；10-不可信状态
						   	   3~4位：00-充电连接器正常；01-充电连接器故障；10-不可信状态
						       5~6位：00-充电机内部温度正常；01-充电机内部过温；10-不可信状态
						       7~8位：00-电量传送正常；01-电量不能传送；10-不可信状态
						       9~10位：00-正常；01-充电机急停；10-不可信状态
						       11~12位：00-正常；01-故障；10-不可信状态
	*/
	uint16_t chrgAbortFaultRes;//充电机中止充电故障原因 

	/*
		充电机中止充电错误原因 1~2位：00-电流匹配；01-电流不匹配；10-不可信状态
							   3~4位：00-正常；01-电压异常；10-不可信状态
	*/
	uint8_t chrgAbortErrRes;//充电机中止充电错误原因

	uint8_t chrgReadyOk;//充电机是否充电准备好 0x00-充电机未完成充电准备；0xaa-充电机完成准备；0xff-无效

	uint16_t chrgTotalTime;//累计充电时间
	uint16_t chrgTotalPower;//输出电量

	/*==========================下述为bms发送过来的数据==============================*/
	/*
	 *todo@share:下述数据该定义为一个结构来描述
	*/
	//接收到bms数据
	uint16_t chrgAllowVolMax;//最高允许充电总电压

	//部分协议解析后的处理数据
	uint8_t okCode;//bms辨识报文中的确认码
	
	structBmsIdentify bmsIdentifyInfo;//车辆辨识信息
	structBmsChrgPara bmsBatChrgPara;//电池充电参数
	uint8_t bmsChrgReadyOk;//bms是否充电准备好，00-bms未做好充电准备；0xaa-bms完成充电准备；0xff-无效
	structBmsBatNeedInfo bmsBatNeedInfo;//电池充电需求信息
	structBmsChrgState bmsChrgState;//电池充电过程中的信息状态
	structBmsChrgBatStateInfo bmsChrgBatStateInfo;//动力蓄电池状态
	structBmsAbortChrgRes bmsAbortChrgRes;//BMS中止充电原因
	structBmsAbortChrgData bmsAbortChrgData;//BMS中止充电数据

	int (*checkInsDone)();
}bmsDataType;

//bms类型定义
typedef struct{
#ifdef FREERTOS
	EventGroupHandle_t bmsProtoEventGroup;
#endif
	bmsDataType bmsData;
	
	void *cmdInit();
}bmsType;


/*=======================函数声明============================*/
/** @brief bmsCmdInit
 *			初始化bms指令
 * @param	bmsData-bms相关数据结构
 * @param	
 * @param	
 * @return
 *
 */
void bmsCmdInit(bmsDataType bmsData);

/*=============================can协议ID的功能函数=====================================*/
/** @brief bmsDataInit
 *          初始化bms数据
 * @param   模块索引变量
 * @param   模块物理地址
 * @param   模块索引
 * @return
 *
 */
void bmsDataInitFunc(structGreenRct *greenRct,uint8_t *rctIndexToAddr,uint8_t *rctAddrToIndex);
/** @brief getcanid
 *          获取协议帧ID组装
 * @param   帧ID结构数据
 * @param
 * @param
 * @return  帧ID组装值
 *
 */
int getBmsCanId(const structBmsCanMsgHead *canMsgHead);
/** @brief anyscanid
 *          获取协议帧ID组装
 * @param   帧ID需填充的结构
 * @param   需解析的can_id
 * @param
 * @return
 *
 */
void anysBmsCanId(structBmsCanMsgHead *canMsgHead,const int can_id);
/*=============================充电机发送指令功能函数=====================================*/
/** @brief chrgHandShakeChmCmdFunc
 *          充电机发送握手
 * @param   bms数据结构
 * @param   
 * @param
 * @return  can帧数据帧
 *
 */
tCANMsgObject *chrgHandShakeChmCmdFunc(bmsDataType bmsData);
/** @brief chrgIdentifyCrmCmdFunc
 *          充电机发送辨识报文
 * @param   bms数据结构
 * @param   
 * @param
 * @return  can帧数据帧
 *
 */
tCANMsgObject *chrgIdentifyCrmCmdFunc(bmsDataType bmsData);
/** @brief chrgTimeSynCtsCmdFunc
 *          充电机发送时间同步信息报文
 * @param   bms数据结构
 * @param   
 * @param
 * @return  can帧数据帧
 *
 */
tCANMsgObject *chrgTimeSynCtsCmdFunc(bmsDataType bmsData);
/** @brief chrgOutPowerMaxCmlCmdFunc
 *          充电机发送充电机最大输出能力报文
 * @param   bms数据结构
 * @param   
 * @param
 * @return  can帧数据帧
 *
 */
tCANMsgObject *chrgOutPowerMaxCmlCmdFunc(bmsDataType bmsData);
/** @brief chrgOutReadyOKCroCmdFunc
 *          充电机发送充电机输出准备就绪报文
 * @param   bms数据结构
 * @param   
 * @param
 * @return  can帧数据帧
 *
 */
tCANMsgObject *chrgOutReadyOKCroCmdFunc(bmsDataType bmsData);
/** @brief chrgChrgStatueCcsCmdFunc
 *          充电机发送充电机充电状态报文
 * @param   bms数据结构
 * @param   
 * @param
 * @return  can帧数据帧
 *
 */
tCANMsgObject *chrgChrgStatueCcsCmdFunc(bmsDataType bmsData);
/** @brief chrgAbortChrgingCstCmdFunc
 *          充电机发送中止充电报文
 * @param   bms数据结构
 * @param   
 * @param
 * @return  can帧数据帧
 *
 */
tCANMsgObject *chrgAbortChrgingCstCmdFunc(bmsDataType bmsData);
/** @brief chrgStatisticalDataCsdCmdFunc
 *          充电机发送统计数据报文
 * @param   bms数据结构
 * @param   
 * @param
 * @return  can帧数据帧
 *
 */
tCANMsgObject *chrgStatisticalDataCsdCmdFunc(bmsDataType bmsData);
/** @brief analyBmsHandShakeBhmCmdFunc
 *          解析bms发送的握手数据
 * @param   bms数据结构
 * @param   recvData充电机接收的数据
 * @param
 * @return  解析结果
 *
 */
uint8_t analyBmsHandShakeBhmCmdFunc(bmsDataType bmsData,const uint8_t *recvData);
/** @brief analyBmsIdentifyBrmCmdFunc
 *          解析bms发送的车辆辨识数据
 * @param   bms数据结构
 * @param   recvData充电机接收的数据
 * @param
 * @return  解析结果
 *
 */
uint8_t analyBmsIdentifyBrmCmdFunc(bmsDataType bmsData,const uint8_t *recvData);
/** @brief analyBmsBatChrgParaBcpCmdFunc
 *          解析bms发送的电池充电参数数据
 * @param   bms数据结构
 * @param   recvData充电机接收的数据
 * @param
 * @return  解析结果
 *
 */
uint8_t analyBmsBatChrgParaBcpCmdFunc(bmsDataType bmsData,const uint8_t *recvData);
/** @brief analyBmsChrgReadyBroCmdFunc
 *          解析bms发送的是否准备好充电数据
 * @param   bms数据结构
 * @param   recvData充电机接收的数据
 * @param
 * @return  解析结果
 *
 */
uint8_t analyBmsChrgReadyBroCmdFunc(bmsDataType bmsData,const uint8_t *recvData);
/** @brief analyBmsBatChrgParaBcpCmdFunc
 *          解析bms发送的电池充电参数数据
 * @param   bms数据结构
 * @param   recvData充电机接收的数据
 * @param
 * @return  解析结果
 *
 */
uint8_t analyBmsBatChrgParaBcpCmdFunc(bmsDataType bmsData,const uint8_t *recvData);
/** @brief analyBmsBatNeedInfoBclCmdFunc
 *          解析bms发送的电池充电需求数据
 * @param   bms数据结构
 * @param   recvData充电机接收的数据
 * @param
 * @return  解析结果
 *
 */
uint8_t analyBmsBatNeedInfoBclCmdFunc(bmsDataType bmsData,const uint8_t *recvData);
/** @brief analyBmsBatChrgParaBcpCmdFunc
 *          解析bms发送的电池充电参数数据
 * @param   bms数据结构
 * @param   recvData充电机接收的数据
 * @param
 * @return  解析结果
 *
 */
uint8_t analyBmsBatChrgParaBcpCmdFunc(bmsDataType bmsData,const uint8_t *recvData);
/** @brief analyBmsBatChrgStateBsmCmdFunc
 *          解析bms发送的电池充电状态数据
 * @param   bms数据结构
 * @param   recvData充电机接收的数据
 * @param
 * @return  解析结果
 *
 */
uint8_t analyBmsBatChrgStateBsmCmdFunc(bmsDataType bmsData,const uint8_t *recvData);
/** @brief analyBmsAbortChrgResBstCmdFunc
 *          解析bms发送的中止充电数据
 * @param   bms数据结构
 * @param   recvData充电机接收的数据
 * @param
 * @return  解析结果
 *
 */
uint8_t analyBmsAbortChrgResBstCmdFunc(bmsDataType bmsData,const uint8_t *recvData);
/** @brief analyBmsAbortChrgDataBsdCmdFunc
 *          解析bms发送的bms统计数据
 * @param   bms数据结构
 * @param   recvData充电机接收的数据
 * @param
 * @return  解析结果
 *
 */
uint8_t analyBmsAbortChrgDataBsdCmdFunc(bmsDataType bmsData,const uint8_t *recvData);
/** @brief bmsCmdSendFunc
 *          chrg充电机发送线程
 * @param   
 * @param   
 * @param
 * @return  
 *
 */
int bmsCmdSendFunc(void);
/** @brief canCmdProperty
 *          修改命令属性
 * @param   cmd-命令名字
 * @param   time-命令周期
 * @param   signal-命令启动、停止属性
 * @return  
 *
 */
int canCmdProperty(char *cmd,uint32_t time,uint8_t signal);
/** @brief chrgStageProc
 *          充电所有阶段调用
 * @param   bmsData-bms和chrg相关的数据
 * @param   
 * @param
 * @return  该阶段执行结果
 *
 */
int chrgStageProc(bmsDataType bmsData);
/** @brief handShakeStage0
 *          握手的一阶段
 * @param   bmsData-bms和chrg相关的数据
 * @param   
 * @param
 * @return  该阶段执行结果
 *
 */
int handShakeStage0(bmsDataType bmsData);
/** @brief handShakeStage1
 *          握手的二阶段
 * @param   bmsData-bms和chrg相关的数据
 * @param   
 * @param
 * @return  该阶段执行结果
 *
 */
int handShakeStage1(bmsDataType bmsData);
/** @brief paraConfigStage
 *          参数配置阶段
 * @param   bmsData-bms和chrg相关的数据
 * @param   
 * @param
 * @return  该阶段执行结果
 *
 */
int paraConfigStage(bmsDataType bmsData);
/** @brief chrgingStage
 *          充电中阶段
 * @param   bmsData-bms和chrg相关的数据
 * @param   
 * @param
 * @return  该阶段执行结果
 *
 */
int chrgingStage(bmsDataType bmsData);
/** @brief chrgDoneStage
 *          充电完成阶段
 * @param   bmsData-bms和chrg相关的数据
 * @param   
 * @param
 * @return  该阶段执行结果
 *
 */
int chrgDoneStage(bmsDataType bmsData);


























#endif



























