/**
* @file bmsManager.c
* @brief bms协议管理
* @author zshare
* @version v1.0
* @date 2018-10-08
* @history  2018-10-08 	封装bms协议
*
*/


#include "bmsManager.h"

/** @brief bmsCmdInit
 *			初始化bms指令
 * @param	bmsData-bms相关数据结构
 * @param	
 * @param	
 * @return
 *
 */
void bmsCmdInit(bmsDataType bmsData)
{
	/*=====================CHM握手帧========================*/
	bmsData.chmMsg.canMsgHead = (structBmsCanMsgHead *)calloc(1,sizeof(structBmsCanMsgHead));
	if(bmsData.chmMsg.canMsgHead == NULL)
	{
		return ;
	}
	bmsData.chmMsg.canMsgHead->priority = PRIORITY6;
	bmsData.chmMsg.canMsgHead->reserve = 0x0;
	bmsData.chmMsg.canMsgHead->dataPage = 0x0;
	bmsData.chmMsg.canMsgHead->pduFormat = PFCHM;
	bmsData.chmMsg.canMsgHead->desAddr = BMSADDR;
	bmsData.chmMsg.canMsgHead->srcAddr = CHRGADDR;
//	bmsData.chmMsg.maskId = 
	bmsData.chmMsg.flags = MSG_OBJ_TX_INI_ENABLE | MSG_OBJ_EXTENDED_ID;
	bmsData.chmMsg.dataLen = DATALEN3;

	
	/*=====================CRM充电机辨识帧========================*/
	bmsData.crmMsg.canMsgHead = (structBmsCanMsgHead *)calloc(1,sizeof(structBmsCanMsgHead));
	if(bmsData.crmMsg.canMsgHead == NULL)
	{
		return ;
	}
	bmsData.crmMsg.canMsgHead->priority = PRIORITY6;
	bmsData.crmMsg.canMsgHead->reserve = 0x0;
	bmsData.crmMsg.canMsgHead->dataPage = 0x0;
	bmsData.crmMsg.canMsgHead->pduFormat = PFCRM;
	bmsData.crmMsg.canMsgHead->desAddr = BMSADDR;
	bmsData.crmMsg.canMsgHead->srcAddr = CHRGADDR;
//	bmsData.crmMsg.maskId = 
	bmsData.crmMsg.flags = MSG_OBJ_TX_INI_ENABLE | MSG_OBJ_EXTENDED_ID;
	bmsData.crmMsg.dataLen = DATALEN8;

	/*=====================CTS充电机发送时间同步帧========================*/
	bmsData.ctsMsg.canMsgHead = (structBmsCanMsgHead *)calloc(1,sizeof(structBmsCanMsgHead));
	if(bmsData.ctsMsg.canMsgHead == NULL)
	{
		return ;
	}
	bmsData.ctsMsg.canMsgHead->priority = PRIORITY6;
	bmsData.ctsMsg.canMsgHead->reserve = 0x0;
	bmsData.ctsMsg.canMsgHead->dataPage = 0x0;
	bmsData.ctsMsg.canMsgHead->pduFormat = PFCTS;
	bmsData.ctsMsg.canMsgHead->desAddr = BMSADDR;
	bmsData.ctsMsg.canMsgHead->srcAddr = CHRGADDR;
//	bmsData.ctsMsg.maskId = 
	bmsData.ctsMsg.flags = MSG_OBJ_TX_INI_ENABLE | MSG_OBJ_EXTENDED_ID;
	bmsData.ctsMsg.dataLen = DATALEN7;

	/*=====================CML充电机最大输出能力帧========================*/
	bmsData.cmlMsg.canMsgHead = (structBmsCanMsgHead *)calloc(1,sizeof(structBmsCanMsgHead));
	if(bmsData.cmlMsg.canMsgHead == NULL)
	{
		return ;
	}
	bmsData.cmlMsg.canMsgHead->priority = PRIORITY6;
	bmsData.cmlMsg.canMsgHead->reserve = 0x0;
	bmsData.cmlMsg.canMsgHead->dataPage = 0x0;
	bmsData.cmlMsg.canMsgHead->pduFormat = PFCML;
	bmsData.cmlMsg.canMsgHead->desAddr = BMSADDR;
	bmsData.cmlMsg.canMsgHead->srcAddr = CHRGADDR;
//	bmsData.cmlMsg.maskId = 
	bmsData.cmlMsg.flags = MSG_OBJ_TX_INI_ENABLE | MSG_OBJ_EXTENDED_ID;
	bmsData.cmlMsg.dataLen = DATALEN6;

	/*=====================CRO充电机输出准备就绪状态帧========================*/
	bmsData.croMsg.canMsgHead = (structBmsCanMsgHead *)calloc(1,sizeof(structBmsCanMsgHead));
	if(bmsData.croMsg.canMsgHead == NULL)
	{
		return ;
	}
	bmsData.croMsg.canMsgHead->priority = PRIORITY4;
	bmsData.croMsg.canMsgHead->reserve = 0x0;
	bmsData.croMsg.canMsgHead->dataPage = 0x0;
	bmsData.croMsg.canMsgHead->pduFormat = PFCRO;
	bmsData.croMsg.canMsgHead->desAddr = BMSADDR;
	bmsData.croMsg.canMsgHead->srcAddr = CHRGADDR;
//	bmsData.croMsg.maskId = 
	bmsData.croMsg.flags = MSG_OBJ_TX_INI_ENABLE | MSG_OBJ_EXTENDED_ID;
	bmsData.croMsg.dataLen = DATALEN4;

	/*=====================CCS充电机充电状态帧========================*/
	bmsData.ccsMsg.canMsgHead = (structBmsCanMsgHead *)calloc(1,sizeof(structBmsCanMsgHead));
	if(bmsData.ccsMsg.canMsgHead == NULL)
	{
		return ;
	}
	bmsData.ccsMsg.canMsgHead->priority = PRIORITY6;
	bmsData.ccsMsg.canMsgHead->reserve = 0x0;
	bmsData.ccsMsg.canMsgHead->dataPage = 0x0;
	bmsData.ccsMsg.canMsgHead->pduFormat = PFCCS;
	bmsData.ccsMsg.canMsgHead->desAddr = BMSADDR;
	bmsData.ccsMsg.canMsgHead->srcAddr = CHRGADDR;
//	bmsData.ccsMsg.maskId = 
	bmsData.ccsMsg.flags = MSG_OBJ_TX_INI_ENABLE | MSG_OBJ_EXTENDED_ID;
	bmsData.ccsMsg.dataLen = DATALEN8;

	/*=====================CST充电机中止充电帧========================*/
	bmsData.cstMsg.canMsgHead = (structBmsCanMsgHead *)calloc(1,sizeof(structBmsCanMsgHead));
	if(bmsData.cstMsg.canMsgHead == NULL)
	{
		return ;
	}
	bmsData.cstMsg.canMsgHead->priority = PRIORITY4;
	bmsData.cstMsg.canMsgHead->reserve = 0x0;
	bmsData.cstMsg.canMsgHead->dataPage = 0x0;
	bmsData.cstMsg.canMsgHead->pduFormat = PFCST;
	bmsData.cstMsg.canMsgHead->desAddr = BMSADDR;
	bmsData.cstMsg.canMsgHead->srcAddr = CHRGADDR;
//	bmsData.cstMsg.maskId = 
	bmsData.cstMsg.flags = MSG_OBJ_TX_INI_ENABLE | MSG_OBJ_EXTENDED_ID;
	bmsData.cstMsg.dataLen = DATALEN4;

	/*=====================CSD充电机统计数据帧========================*/
	bmsData.csdMsg.canMsgHead = (structBmsCanMsgHead *)calloc(1,sizeof(structBmsCanMsgHead));
	if(bmsData.csdMsg.canMsgHead == NULL)
	{
		return ;
	}
	bmsData.csdMsg.canMsgHead->priority = PRIORITY6;
	bmsData.csdMsg.canMsgHead->reserve = 0x0;
	bmsData.csdMsg.canMsgHead->dataPage = 0x0;
	bmsData.csdMsg.canMsgHead->pduFormat = PFCSD;
	bmsData.csdMsg.canMsgHead->desAddr = BMSADDR;
	bmsData.csdMsg.canMsgHead->srcAddr = CHRGADDR;
//	bmsData.csdMsg.maskId = 
	bmsData.csdMsg.flags = MSG_OBJ_TX_INI_ENABLE | MSG_OBJ_EXTENDED_ID;
	bmsData.csdMsg.dataLen = DATALEN8;
	
}

/*=============================can协议ID的功能函数=====================================*/
/** @brief bmsDataInit
 *			初始化bms数据
 * @param	模块索引变量
 * @param	模块物理地址
 * @param	模块索引
 * @return
 *
 */
void bmsDataInitFunc(structGreenRct *greenRct,uint8_t *rctIndexToAddr,uint8_t *rctAddrToIndex)
{
	uint8_t i = 0;

	memset(greenRct,0,RCT_MAX * sizeof(structGreenRct));
	memset(rctIndexToAddr,0xff,RCT_MAX * sizeof(uint8_t));
	memset(rctAddrToIndex,0xff,RCT_MAX * sizeof(uint8_t));

	for(i = 0;i < RCT_MAX;i++)
	{
		greenRct[i].rctCommState = 1; //模块通信故障初始化为1
	}
}
/** @brief getcanid
 *			获取协议帧ID组装
 * @param	帧ID结构数据
 * @param
 * @param
 * @return	帧ID组装值
 *
 */
int getBmsCanId(const structBmsCanMsgHead *canMsgHead)
{
	//扩展格式11bit基本id，18bit扩展id
	//bit0-28:can标识符
	//bit29:错误帧标志 0， data frame 1，error frame
	//bit30:远程发送请求标志 1，rtr frame
	//31bit:帧格式标志0,标准帧 1，扩展帧
    return  (( ( canMsgHead->priority & 0x07)   << 26 ) | \
            ( ( canMsgHead->reserve & 0x01) << 25 ) | \
            ( ( canMsgHead->dataPage & 0x01) << 24 ) | \
            ( ( canMsgHead->pduFormat & 0xff) << 16) | \
            ( ( canMsgHead->desAddr & 0xff) << 8) | \
            ( ( canMsgHead->srcAddr & 0xff) ) );
}
/** @brief anyscanid
 *			获取协议帧ID组装
 * @param	帧ID需填充的结构
 * @param	需解析的can_id
 * @param
 * @return
 *
 */
void anysBmsCanId(structBmsCanMsgHead *canMsgHead,const int can_id)
{
	canMsgHead->priority = (can_id >> 26) & 0x07;
    canMsgHead->reserve  = ( can_id >> 25 ) & 0x01;
    canMsgHead->dataPage = ( can_id >> 24 ) & 0x01;
    canMsgHead->pduFormat = ( can_id >> 16 ) & 0xff;
    canMsgHead->desAddr = ( can_id >> 8  ) & 0xff;
    canMsgHead->srcAddr = can_id & 0xff;
}

/*=============================充电机发送指令功能函数=====================================*/
/** @brief chrgHandShakeChmCmdFunc
 *			充电机发送握手
 * @param	bms数据结构
 * @param	
 * @param
 * @return	can帧数据帧
 *
 */
tCANMsgObject *chrgHandShakeChmCmdFunc(bmsDataType bmsData)
{
	tCANMsgObject *msgtmp;
	msgtmp = (tCANMsgObject *)calloc(1,sizeof(tCANMsgObject));
	if(msgtmp == NULL)
	{
		return NULL;
	}
	msgtmp->ui32MsgID = getBmsCanId(bmsData.chmMsg.canMsgHead);
	msgtmp->ui32MsgIDMask = bmsData.chmMsg.maskId;
	msgtmp->ui32Flags = bmsData.chmMsg.flags;
	msgtmp->ui32MsgLen = bmsData.chmMsg.dataLen;

	bmsData.chmMsg.data[0] = (uint8_t)bmsData.bmsProtocolVer;
	bmsData.chmMsg.data[1] = (uint8_t)(bmsData.bmsProtocolVer >> 8);
	bmsData.chmMsg.data[2] = (uint8_t)(bmsData.bmsProtocolVer >> 16);

	msgtmp->pui8MsgData = bmsData.chmMsg.data;

	return msgtmp;
}
/** @brief chrgIdentifyCrmCmdFunc
 *			充电机发送辨识报文
 * @param	bms数据结构
 * @param	
 * @param
 * @return	can帧数据帧
 *
 */
tCANMsgObject *chrgIdentifyCrmCmdFunc(bmsDataType bmsData)
{
	tCANMsgObject *msgtmp;
	msgtmp = (tCANMsgObject *)calloc(1,sizeof(tCANMsgObject));
	if(msgtmp == NULL)
	{
		return NULL;
	}
	msgtmp->ui32MsgID = getBmsCanId(bmsData.crmMsg.canMsgHead);
	msgtmp->ui32MsgIDMask = bmsData.crmMsg.maskId;
	msgtmp->ui32Flags = bmsData.crmMsg.flags;
	msgtmp->ui32MsgLen = bmsData.crmMsg.dataLen;

	bmsData.crmMsg.data[0] = bmsData.identifyRes;
	bmsData.crmMsg.data[1] = (uint8_t)(bmsData.chrgEncode);
	bmsData.crmMsg.data[2] = (uint8_t)(bmsData.chrgEncode >> 8);
	bmsData.crmMsg.data[3] = (uint8_t)(bmsData.chrgEncode >> 16);
	bmsData.crmMsg.data[4] = (uint8_t)(bmsData.chrgEncode >> 24);
	bmsData.crmMsg.data[5] = (uint8_t)(bmsData.chrgAreaCode);
	bmsData.crmMsg.data[6] = (uint8_t)(bmsData.chrgAreaCode >> 8);
	bmsData.crmMsg.data[7] = (uint8_t)(bmsData.chrgAreaCode >> 16);

	msgtmp->pui8MsgData = bmsData.crmMsg.data;

	return msgtmp;
}
/** @brief chrgTimeSynCtsCmdFunc
 *			充电机发送时间同步信息报文
 * @param	bms数据结构
 * @param	
 * @param
 * @return	can帧数据帧
 *
 */
tCANMsgObject *chrgTimeSynCtsCmdFunc(bmsDataType bmsData)
{
	tCANMsgObject *msgtmp;
	msgtmp = (tCANMsgObject *)calloc(1,sizeof(tCANMsgObject));
	if(msgtmp == NULL)
	{
		return NULL;
	}
	msgtmp->ui32MsgID = getBmsCanId(bmsData.ctsMsg.canMsgHead);
	msgtmp->ui32MsgIDMask = bmsData.ctsMsg.maskId;
	msgtmp->ui32Flags = bmsData.ctsMsg.flags;
	msgtmp->ui32MsgLen = bmsData.ctsMsg.dataLen;

	bmsData.ctsMsg.data[0] = ((bmsData.second / 10) << 4) + bmsData.second % 10;
	bmsData.ctsMsg.data[1] = ((bmsData.minute / 10) << 4) + bmsData.minute % 10;
	bmsData.ctsMsg.data[2] = ((bmsData.hour / 10) << 4) + bmsData.hour % 10;
	bmsData.ctsMsg.data[3] = ((bmsData.date / 10) << 4) + bmsData.date % 10;
	bmsData.ctsMsg.data[4] = ((bmsData.month / 10) << 4) + bmsData.month % 10;
	bmsData.ctsMsg.data[5] = ((bmsData.year / 10) << 4) + bmsData.year % 10;
	bmsData.ctsMsg.data[6] = ((20 / 10) << 4) + 20 % 10;

	msgtmp->pui8MsgData = bmsData.ctsMsg.data;

	return msgtmp;
}
/** @brief chrgOutPowerMaxCmlCmdFunc
 *			充电机发送充电机最大输出能力报文
 * @param	bms数据结构
 * @param	
 * @param
 * @return	can帧数据帧
 *
 */
tCANMsgObject *chrgOutPowerMaxCmlCmdFunc(bmsDataType bmsData)
{
	tCANMsgObject *msgtmp;
	msgtmp = (tCANMsgObject *)calloc(1,sizeof(tCANMsgObject));
	if(msgtmp == NULL)
	{
		return NULL;
	}
	msgtmp->ui32MsgID = getBmsCanId(bmsData.cmlMsg.canMsgHead);
	msgtmp->ui32MsgIDMask = bmsData.cmlMsg.maskId;
	msgtmp->ui32Flags = bmsData.cmlMsg.flags;
	msgtmp->ui32MsgLen = bmsData.cmlMsg.dataLen;

	bmsData.cmlMsg.data[0] = bmsData.outVolMax & 0x00ff;
	bmsData.cmlMsg.data[1] = (bmsData.outVolMax >> 8) & 0x00ff;
	bmsData.cmlMsg.data[2] = bmsData.outVolMin & 0x00ff;
	bmsData.cmlMsg.data[3] = (bmsData.outVolMin >> 8) & 0x00ff;
	bmsData.cmlMsg.data[4] = (4000 - bmsData.outCurMax) & 0x00ff;
	bmsData.cmlMsg.data[5] = ((4000 - bmsData.outCurMax) >> 8) & 0x00ff;
	bmsData.cmlMsg.data[6] = (4000 - bmsData.outCurMin) & 0x00ff;
	bmsData.cmlMsg.data[7] = ((4000 - bmsData.outCurMin) >> 8) & 0x00ff;

	msgtmp->pui8MsgData = bmsData.cmlMsg.data;

	return msgtmp;
}
/** @brief chrgOutReadyOKCroCmdFunc
 *			充电机发送充电机输出准备就绪报文
 * @param	bms数据结构
 * @param	
 * @param
 * @return	can帧数据帧
 *
 */
tCANMsgObject *chrgOutReadyOKCroCmdFunc(bmsDataType bmsData)
{
	tCANMsgObject *msgtmp;
	msgtmp = (tCANMsgObject *)calloc(1,sizeof(tCANMsgObject));
	if(msgtmp == NULL)
	{
		return NULL;
	}
	msgtmp->ui32MsgID = getBmsCanId(bmsData.croMsg.canMsgHead);
	msgtmp->ui32MsgIDMask = bmsData.croMsg.maskId;
	msgtmp->ui32Flags = bmsData.croMsg.flags;
	msgtmp->ui32MsgLen = bmsData.croMsg.dataLen;

	bmsData.croMsg.data[0] = bmsData.chrgReadyOk;

	msgtmp->pui8MsgData = bmsData.croMsg.data;

	return msgtmp;
}
/** @brief chrgChrgStatueCcsCmdFunc
 *			充电机发送充电机充电状态报文
 * @param	bms数据结构
 * @param	
 * @param
 * @return	can帧数据帧
 *
 */
tCANMsgObject *chrgChrgStatueCcsCmdFunc(bmsDataType bmsData)
{
	tCANMsgObject *msgtmp;
	msgtmp = (tCANMsgObject *)calloc(1,sizeof(tCANMsgObject));
	if(msgtmp == NULL)
	{
		return NULL;
	}
	msgtmp->ui32MsgID = getBmsCanId(bmsData.ccsMsg.canMsgHead);
	msgtmp->ui32MsgIDMask = bmsData.ccsMsg.maskId;
	msgtmp->ui32Flags = bmsData.ccsMsg.flags;
	msgtmp->ui32MsgLen = bmsData.ccsMsg.dataLen;

	bmsData.ccsMsg.data[0] = bmsData.outVol & 0x00ff;
	bmsData.ccsMsg.data[1] = (bmsData.outVol >> 8) & 0x00ff;
	bmsData.ccsMsg.data[2] = (4000 - bmsData.outCur) & 0x00ff;
	bmsData.ccsMsg.data[3] = ((4000 - bmsData.outCur) >> 8) & 0x00ff;
	bmsData.ccsMsg.data[4] = bmsData.chrgingTime & 0x00ff;
	bmsData.ccsMsg.data[5] = (bmsData.chrgingTime >> 8) & 0x00ff;	
	bmsData.ccsMsg.data[6] = bmsData.chrgEnable & 0x00ff;
	bmsData.ccsMsg.data[7] = (bmsData.chrgEnable >> 8) & 0x00ff;

	msgtmp->pui8MsgData = bmsData.ccsMsg.data;

	return msgtmp;
}
/** @brief chrgAbortChrgingCstCmdFunc
 *			充电机发送中止充电报文
 * @param	bms数据结构
 * @param	
 * @param
 * @return	can帧数据帧
 *
 */
tCANMsgObject *chrgAbortChrgingCstCmdFunc(bmsDataType bmsData)
{
	tCANMsgObject *msgtmp;
	msgtmp = (tCANMsgObject *)calloc(1,sizeof(tCANMsgObject));
	if(msgtmp == NULL)
	{
		return NULL;
	}
	msgtmp->ui32MsgID = getBmsCanId(bmsData.cstMsg.canMsgHead);
	msgtmp->ui32MsgIDMask = bmsData.cstMsg.maskId;
	msgtmp->ui32Flags = bmsData.cstMsg.flags;
	msgtmp->ui32MsgLen = bmsData.cstMsg.dataLen;

	bmsData.cstMsg.data[0] = bmsData.chrgAbortRes & 0xff;
	bmsData.cstMsg.data[1] = bmsData.chrgAbortFaultRes & 0x00ff;
	bmsData.cstMsg.data[2] = (bmsData.chrgAbortFaultRes >> 8) & 0x00ff;
	bmsData.cstMsg.data[3] = bmsData.chrgAbortErrRes & 0xff;

	msgtmp->pui8MsgData = bmsData.cstMsg.data;

	return msgtmp;
}
/** @brief chrgStatisticalDataCsdCmdFunc
 *			充电机发送统计数据报文
 * @param	bms数据结构
 * @param	
 * @param
 * @return	can帧数据帧
 *
 */
tCANMsgObject *chrgStatisticalDataCsdCmdFunc(bmsDataType bmsData)
{
	tCANMsgObject *msgtmp;
	msgtmp = (tCANMsgObject *)calloc(1,sizeof(tCANMsgObject));
	if(msgtmp == NULL)
	{
		return NULL;
	}
	msgtmp->ui32MsgID = getBmsCanId(bmsData.csdMsg.canMsgHead);
	msgtmp->ui32MsgIDMask = bmsData.csdMsg.maskId;
	msgtmp->ui32Flags = bmsData.csdMsg.flags;
	msgtmp->ui32MsgLen = bmsData.csdMsg.dataLen;

	bmsData.csdMsg.data[0] = bmsData.chrgTotalTime & 0x00ff;
	bmsData.csdMsg.data[1] = (bmsData.chrgTotalTime >> 8) & 0x00ff;
	bmsData.csdMsg.data[2] = bmsData.chrgTotalPower & 0x00ff;
	bmsData.csdMsg.data[3] = (bmsData.chrgTotalPower >> 8) & 0x00ff;
	bmsData.csdMsg.data[4] = bmsData.chrgEncode & 0x00ff;
	bmsData.csdMsg.data[5] = (bmsData.chrgEncode >> 8) & 0x00ff;
	bmsData.csdMsg.data[6] = (bmsData.chrgEncode >> 16)& 0x00ff;
	bmsData.csdMsg.data[7] = (bmsData.chrgEncode >> 24) & 0x00ff;

	msgtmp->pui8MsgData = bmsData.csdMsg.data;

	return msgtmp;
}
/** @brief analyBmsHandShakeBhmCmdFunc
 *			解析bms发送的握手数据
 * @param	bms数据结构
 * @param	recvData充电机接收的数据
 * @param
 * @return	解析结果
 *
 */
uint8_t analyBmsHandShakeBhmCmdFunc(bmsDataType bmsData,const uint8_t *recvData)
{
	uint8_t res = 0;

	bmsData.chrgAllowVolMax = recvData[1] << 8 + recvData[0];

	return res;
}
/** @brief analyBmsIdentifyBrmCmdFunc
 *			解析bms发送的车辆辨识数据
 * @param	bms数据结构
 * @param	recvData充电机接收的数据
 * @param
 * @return	解析结果
 *
 */
uint8_t analyBmsIdentifyBrmCmdFunc(bmsDataType bmsData,const uint8_t *recvData)
{
	bmsData.bmsIdentifyInfo.bmsProVer = recvData[2] << 16 + recvData[1] << 8 + recvData[0];
	bmsData.bmsIdentifyInfo.batType = recvData[3];
	bmsData.bmsIdentifyInfo.batRateCapacity = recvData[5] << 8 + recvData[4];
	bmsData.bmsIdentifyInfo.batRateVol = recvData[7] << 8 + recvData[6];
	bmsData.bmsIdentifyInfo.manufacterName = recvData[11] << 24 + recvData[10] << 16 + recvData[9] << 8 + recvData[8];
	bmsData.bmsIdentifyInfo.batSeriNum = recvData[15] << 24 + recvData[14] << 16 + recvData[13] << 8 + recvData[12];
	bmsData.bmsIdentifyInfo.batYear = recvData[16];
	bmsData.bmsIdentifyInfo.batMonth = recvData[17];
	bmsData.bmsIdentifyInfo.batDate = recvData[18];
	bmsData.bmsIdentifyInfo.batChrgCount = recvData[21] << 16 + recvData[20] << 8 + recvData[19];
	bmsData.bmsIdentifyInfo.batProperIdentify = recvData[22];
	bmsData.bmsIdentifyInfo.reserver = recvData[23];
	bmsData.bmsIdentifyInfo.carVIN[0] = recvData[27] << 24 + recvData[26] << 16 + recvData[25] << 8 + recvData[24]; 
	bmsData.bmsIdentifyInfo.carVIN[1] = recvData[31] << 24 + recvData[30] << 16 + recvData[29] << 8 + recvData[28]; 
	bmsData.bmsIdentifyInfo.carVIN[2] = recvData[35] << 24 + recvData[34] << 16 + recvData[33] << 8 + recvData[32]; 
	bmsData.bmsIdentifyInfo.carVIN[3] = recvData[39] << 24 + recvData[38] << 16 + recvData[37] << 8 + recvData[36]; 
	bmsData.bmsIdentifyInfo.carVIN[4] = recvData[40]; 
	bmsData.bmsIdentifyInfo.bmsSoftWareVer[0] = recvData[44] << 24 + recvData[43] << 16 + recvData[42] << 8 + recvData[41]; 
	bmsData.bmsIdentifyInfo.bmsSoftWareVer[1] = recvData[48] << 24 + recvData[47] << 16 + recvData[46] << 8 + recvData[45]; 
	return 0;
}
/** @brief analyBmsBatChrgParaBcpCmdFunc
 *			解析bms发送的电池充电参数数据
 * @param	bms数据结构
 * @param	recvData充电机接收的数据
 * @param
 * @return	解析结果
 *
 */
uint8_t analyBmsBatChrgParaBcpCmdFunc(bmsDataType bmsData,const uint8_t *recvData)
{
	bmsData.bmsBatChrgPara.batPermitChrgVolMax = recvData[1] << 8 + recvData[0];
	bmsData.bmsBatChrgPara.batPermitChrgCurMax = recvData[3] << 8 + recvData[2];
	bmsData.bmsBatChrgPara.batPowerMax = recvData[5] << 8 + recvData[4];
	bmsData.bmsBatChrgPara.batPermitTotalChrgVolMax = recvData[7] << 8 + recvData[6];
	bmsData.bmsBatChrgPara.batPermitTemp = recvData[8]; 
	bmsData.bmsBatChrgPara.batChrgState = recvData[10] << 8 + recvData[9];
	bmsData.bmsBatChrgPara.batCurrentVol = recvData[12] << 8 + recvData[11];

	return 0;
}
/** @brief analyBmsChrgReadyBroCmdFunc
 *			解析bms发送的是否准备好充电数据
 * @param	bms数据结构
 * @param	recvData充电机接收的数据
 * @param
 * @return	解析结果
 *
 */
uint8_t analyBmsChrgReadyBroCmdFunc(bmsDataType bmsData,const uint8_t *recvData)
{
	bmsData.bmsChrgReadyOk = recvData[0];

	return 0;
}
/** @brief analyBmsBatChrgParaBcpCmdFunc
 *			解析bms发送的电池充电参数数据
 * @param	bms数据结构
 * @param	recvData充电机接收的数据
 * @param
 * @return	解析结果
 *
 */
uint8_t analyBmsBatChrgParaBcpCmdFunc(bmsDataType bmsData,const uint8_t *recvData)
{
	bmsData.bmsBatChrgPara.batPermitChrgVolMax = recvData[1] << 8 + recvData[0];
	bmsData.bmsBatChrgPara.batPermitChrgCurMax = recvData[3] << 8 + recvData[2];
	bmsData.bmsBatChrgPara.batPowerMax = recvData[5] << 8 + recvData[4];
	bmsData.bmsBatChrgPara.batPermitTotalChrgVolMax = recvData[7] << 8 + recvData[6];
	bmsData.bmsBatChrgPara.batPermitTemp = recvData[8]; 
	bmsData.bmsBatChrgPara.batChrgState = recvData[10] << 8 + recvData[9];
	bmsData.bmsBatChrgPara.batCurrentVol = recvData[12] << 8 + recvData[11];

	return 0;
}
/** @brief analyBmsBatNeedInfoBclCmdFunc
 *			解析bms发送的电池充电需求数据
 * @param	bms数据结构
 * @param	recvData充电机接收的数据
 * @param
 * @return	解析结果
 *
 */
uint8_t analyBmsBatNeedInfoBclCmdFunc(bmsDataType bmsData,const uint8_t *recvData)
{
	bmsData.bmsBatNeedInfo.batNeedVol = recvData[1] << 8 + recvData[0];
	bmsData.bmsBatNeedInfo.batNeedCur = recvData[3] << 8 + recvData[2];
	bmsData.bmsBatNeedInfo.batChrgMode = recvData[4]; 

	return 0;
}
/** @brief analyBmsBatChrgParaBcpCmdFunc
 *			解析bms发送的电池充电参数数据
 * @param	bms数据结构
 * @param	recvData充电机接收的数据
 * @param
 * @return	解析结果
 *
 */
uint8_t analyBmsBatChrgParaBcpCmdFunc(bmsDataType bmsData,const uint8_t *recvData)
{
	bmsData.bmsChrgState.chrgVol = recvData[1] << 8 + recvData[0];
	bmsData.bmsChrgState.chrgCur = recvData[3] << 8 + recvData[2];
	bmsData.bmsChrgState.batInfo.batVolMax = (recvData[5] & 0x0f) << 8 + recvData[4];
	bmsData.bmsChrgState.batInfo.batVolMax = (recvData[5] & 0xf0) >> 4;
	bmsData.bmsChrgState.batSoc = recvData[6]; 
	bmsData.bmsChrgState.residualChrgTime = recvData[8] << 8 + recvData[7];

	return 0;
}
/** @brief analyBmsBatChrgStateBsmCmdFunc
 *			解析bms发送的电池充电状态数据
 * @param	bms数据结构
 * @param	recvData充电机接收的数据
 * @param
 * @return	解析结果
 *
 */
uint8_t analyBmsBatChrgStateBsmCmdFunc(bmsDataType bmsData,const uint8_t *recvData)
{
	bmsData.bmsChrgBatStateInfo.volMaxBatNumber = recvData[0];
	bmsData.bmsChrgBatStateInfo.batTempMax = recvData[1];
	bmsData.bmsChrgBatStateInfo.tempMaxBatNumber = recvData[2];
	bmsData.bmsChrgBatStateInfo.batTempMin = recvData[3];
	bmsData.bmsChrgBatStateInfo.tempMinBatNumber = recvData[4];
	bmsData.bmsChrgBatStateInfo.batVolState = recvData[5] & 0x03;
	bmsData.bmsChrgBatStateInfo.batSocState = (recvData[5]>>2) & 0x03;
	bmsData.bmsChrgBatStateInfo.chrgCurState = (recvData[5]>>4) & 0x03;
	bmsData.bmsChrgBatStateInfo.batTempOverState = (recvData[5]>>6) & 0x03;
	bmsData.bmsChrgBatStateInfo.batInsulationState = recvData[6] & 0x03;
	bmsData.bmsChrgBatStateInfo.batConnectState = (recvData[6]>>2) & 0x03;
	bmsData.bmsChrgBatStateInfo.chrgPermit = (recvData[6]>>4)& 0x03;

	return 0;
}
/** @brief analyBmsAbortChrgResBstCmdFunc
 *			解析bms发送的中止充电数据
 * @param	bms数据结构
 * @param	recvData充电机接收的数据
 * @param
 * @return	解析结果
 *
 */
uint8_t analyBmsAbortChrgResBstCmdFunc(bmsDataType bmsData,const uint8_t *recvData)
{
	bmsData.bmsAbortChrgRes.bmsAbortChrgRes = recvData[0];
	bmsData.bmsAbortChrgRes.bmsAbortChrgFaultRes = recvData[2] << 8 + recvData[1];
	bmsData.bmsAbortChrgRes.bmsabortChrgErrRes = recvData[3];

	return 0;
}
/** @brief analyBmsAbortChrgDataBsdCmdFunc
 *			解析bms发送的bms统计数据
 * @param	bms数据结构
 * @param	recvData充电机接收的数据
 * @param
 * @return	解析结果
 *
 */
uint8_t analyBmsAbortChrgDataBsdCmdFunc(bmsDataType bmsData,const uint8_t *recvData)
{
	bmsData.bmsAbortChrgData.bmsAbortSoc = recvData[0];
	bmsData.bmsAbortChrgData.batVolMin = recvData[2] << 8 + recvData[1];
	bmsData.bmsAbortChrgData.batVolMax = recvData[4] << 8 + recvData[3];
	bmsData.bmsAbortChrgData.batTempMin = recvData[5];
	bmsData.bmsAbortChrgData.batTempMax = recvData[6];

	return 0;
}
/** @brief bmsCmdSendFunc
 *			chrg充电机发送线程
 * @param	
 * @param	
 * @param
 * @return	
 *
 */
int bmsCmdSendFunc(void)
{
	uint32_t count = 0;
	canCmdOperType *canCmdSnd = canCmdOper;

	while(1)
	{
		//如何解决指令拥堵问题？？？？
#ifdef CANSENDCMDMODE0
		for( ;	\
				(((count % canCmdSnd->time) == 0)
					&&(canCmdSnd->signal == STARTSIGNAL)
					&&(canCmdSnd->cmdName != NULL));	\
					*canCmdSnd++)
		{
			发送(canCmdSnd->cmdFunc(bmsData));
			break;
		}
		vTaskDelay(50);
		count += 50;		
		canCmdSnd = canCmdOper;
#endif

#ifdef CANSENDCMDMODE1
		canCmdSnd = canCmdOper;
		
		for( ;	\
				(((count % canCmdSnd->time) == 0)
					&&(canCmdSnd->signal == STARTSIGNAL)
					&&(canCmdSnd->cmdName != NULL));	\
					*canCmdSnd++)
		{
			发送(canCmdSnd->cmdFunc(bmsData));
			vTaskDelay(50);
			count += 50;
		}
		if(count == 0)
			vTaskDelay(50);			
#endif
	}
}
/** @brief canCmdProperty
 *			修改命令属性
 * @param	cmd-命令名字
 * @param	time-命令周期
 * @param	signal-命令启动、停止属性
 * @return	
 *
 */
int canCmdProperty(char *cmd,uint32_t time,uint8_t signal)
{
	canCmdOperType *canCmdSnd = canCmdOper;

	do{
		if(strcmp(canCmdSnd->cmdName,cmd) == 0)
		{
//			canCmdSnd->time = time;
			canCmdSnd->signal = signal;
			break;
		}
	}while(strcmp((++canCmdSnd)->cmdName,"NULL") != 0);

	//打印
//	canCmdSnd = canCmdOper;
//	do{
//		printf("	%s:%d\n",canCmdSnd->cmdName,canCmdSnd->time);
//	}while(strcmp((++canCmdSnd)->cmdName,"NULL") != 0);

	return 0;
}
/** @brief chrgStageProc
 *			充电所有阶段调用
 * @param	bmsData-bms和chrg相关的数据
 * @param	
 * @param
 * @return	该阶段执行结果
 *
 */
int chrgStageProc(bmsDataType bmsData)
{
	int stageRes = STAGEOK;
	bmsStageType *bmsStageFunc = bmsStageProc;

	for( ; \
			((stageRes == STAGEOK)\
				&&(strcmp(bmsStageFunc->stageName,"NULL") != 0)); \
					bmsStageFunc++)
	{
		stageRes = bmsStageFunc->stageFunc(bmsData);
	}

	return stageRes;
}
/** @brief handShakeStage0
 *			握手的一阶段
 * @param	bmsData-bms和chrg相关的数据
 * @param	
 * @param
 * @return	该阶段执行结果
 *
 */
int handShakeStage0(bmsDataType bmsData)
{
	int stageRes = -1;
#ifdef FREERTOS
	EventBits_t uxBitRes;
#endif
	//充电机发送握手
	CANCMDSND("chm",250,STARTSIGNAL);
#ifdef FREERTOS
	
	//阻塞等待bms握手响应，阻塞超时时长50ms
	uxBitRes = xEventGroupWaitBits(bmsProtoEventGroup,
										defEventBitChrgRecvHandShakeOk,
											pdTRUE,pdTRUE,50);
	if((uxBitRes & defEventBitChrgRecvHandShakeOk) == defEventBitChrgRecvHandShakeOk)
	{
		stageRes = STAGEOK;
	}
	else
	{
		//50ms超时处理
		stageRes = STAGEOK;
	}
	
#endif

	return stageRes;
}
/** @brief handShakeStage1
 *			握手的二阶段
 * @param	bmsData-bms和chrg相关的数据
 * @param	
 * @param
 * @return	该阶段执行结果
 *
 */
int handShakeStage1(bmsDataType bmsData)
{
#ifdef FREERTOS
		EventBits_t uxBitRes;
#endif
	int stageRes = -1;

	//绝缘检测失败,该处调用外部函数
	if(bmsData.checkInsDone() = -1)
	{
		stageRes = INSFAILED;
		return stageRes;
	}
	CANCMDSND("chm",250,STOPSIGNAL);

	bmsData.identifyRes = 0x00;
	CANCMDSND("crm",250,STARTSIGNAL);

#ifdef FREERTOS
	//阻塞等待bms握手响应，阻塞超时时长50ms
	uxBitRes = xEventGroupWaitBits(bmsProtoEventGroup,
										defEventBitChrgRecvIdentyOk,
											pdTRUE,pdTRUE,50);
	if((uxBitRes & defEventBitChrgRecvIdentyOk) == defEventBitChrgRecvIdentyOk)
	{
		bmsData.identifyRes = 0xAA;
		CANCMDSND("crm",250,STARTSIGNAL);
		stageRes = STAGEOK;
	}
	else
	{
		//50ms超时处理
		stageRes = HANDSHAKEFAILED;
	}

#endif
	return stageRes;	
}
/** @brief paraConfigStage
 *			参数配置阶段
 * @param	bmsData-bms和chrg相关的数据
 * @param	
 * @param
 * @return	该阶段执行结果
 *
 */
int paraConfigStage(bmsDataType bmsData)
{
#ifdef FREERTOS
		EventBits_t uxBitRes;
#endif
	int stageRes = -1;
	uint8_t count = 0;
#ifdef FREERTOS
	//阻塞等待电池充电参数报文
	uxBitRes = xEventGroupWaitBits(bmsProtoEventGroup,
										defEventBitChrgRecvBatChrgParaOk,
											pdTRUE,pdTRUE,50);
	if((uxBitRes & defEventBitChrgRecvBatChrgParaOk) == defEventBitChrgRecvBatChrgParaOk)
	{
		//配置充电参数，该部分内容已在can发送接收中完成数据赋值，此处只是协议命令流程
		//向bms发送时间同步和充电机最大输出能力参数
		CANCMDSND("cts",500,STARTSIGNAL);
		CANCMDSND("cml", 250, STARTSIGNAL);
	}
	else
	{
		//50ms超时处理
		stageRes = CHRGPARACONFIGFAILED;
		return stageRes;
	}
		
#endif

	//从外部模块获取充电机是否准备好充电，
	//未准备好，向bms发送充电机未准备好，然后继续检测充电机是否准备好，超时 S
	//准备好，继续
	while(bmsData.chrgReadyOk != 0xAA)
	{
		bmsData.chrgReadyOk = 0x00;
		CANCMDSND("cro", WAITTIMECRO, STARTSIGNAL);		
		vTaskDelay(100);
		if(count > n)
		{
			//超时,充电机未准备好
			stageRes = CHRGPARACONFIGFAILED;
			return stageRes;
		}
	}

	//充电机准备就绪
	bmsData.chrgReadyOk = 0xAA;
	CANCMDSND("cro", WAITTIMECRO, STARTSIGNAL);

	stageRes = STAGEOK;

	return stageRes;	
}
/** @brief chrgingStage
 *			充电中阶段
 * @param	bmsData-bms和chrg相关的数据
 * @param	
 * @param
 * @return	该阶段执行结果
 *
 */
int chrgingStage(bmsDataType bmsData)
{
#ifdef FREERTOS
		EventBits_t uxBitRes;
#endif
	int stageRes = -1;
	uint32_t count = 0;
#ifdef FREERTOS
	//阻塞等待电池充电总状态和电池充电需求报文
	uxBitRes = xEventGroupWaitBits(bmsProtoEventGroup,
										defEventBitChrgRecvBatStateChrgNeedOk,
											pdTRUE,pdTRUE,1000);
	if((uxBitRes & defEventBitChrgRecvBatStateChrgNeedOk) == defEventBitChrgRecvBatStateChrgNeedOk)
	{
		;
	}
	else
	{
		//1s超时处理
		stageRes = BMSNEEDDATAFAILED;
		return stageRes;
	}
#endif

	while(1)
	{
		//向bms发送充电机充电状态
		bmsData.outVol = ;
		bmsData.outCur = ;
		bmsData.chrgTotalTime = ;
		bmsData.chrgEnable = ;
		CANCMDSND("ccs",50,STARTSIGNAL);

#ifdef FREERTOS
		//判断BCL、BCS、BSM三条报文是否存在接收超时
		//阻塞等待电池充电需求报文、电池充电总状态报文、蓄电池状态报文
		uxBitRes = xEventGroupWaitBits(bmsProtoEventGroup,
											defEventBitChrgRecvThreeMessageOk,
												pdTRUE,pdTRUE,1000);
		if((uxBitRes & defEventBitChrgRecvThreeMessageOk) == defEventBitChrgRecvThreeMessageOk)
		{
			;
		}
		else
		{
			//1s超时处理
			stageRes = CHRGRECVTHREEMESSAGEFAILED;
			return stageRes;
		}
#endif

		//判断充电是否结束，或者由于接收到bms中止充电报文
		if()
		{
			break;
		}
	}
#ifdef FREERTOS

	//结束充电,充电机发送cst，BMS中止充电报文
	CANCMDSND("cst", 10, STARTSIGNAL);

	while(count < )
	{
		//阻塞等待BMS中止充电报文
		uxBitRes = xEventGroupWaitBits(bmsProtoEventGroup,
											defEventBitChrgRecvBmsAbortChrgOk,
												pdTRUE,pdTRUE,10);
		if((uxBitRes & defEventBitChrgRecvBmsAbortChrgOk) == defEventBitChrgRecvBmsAbortChrgOk)
		{
			stageRes = STAGEOK;
		}
		else
		{
			//10ms超时,再次发送
			CANCMDSND("cst", 10, STARTSIGNAL);		
			count++;
		}
	}

	if(count == )
	{
		stageRes = CHRGRECVTHREEMESSAGEFAILED;
	}

#endif

	return stageRes;	
}
/** @brief chrgDoneStage
 *			充电完成阶段
 * @param	bmsData-bms和chrg相关的数据
 * @param	
 * @param
 * @return	该阶段执行结果
 *
 */
int chrgDoneStage(bmsDataType bmsData)
{
#ifdef FREERTOS
		EventBits_t uxBitRes;
#endif
	int stageRes = -1;
#ifdef FREERTOS
	//阻塞等待BMS充电统计报文
	uxBitRes = xEventGroupWaitBits(bmsProtoEventGroup,
										defEventBitChrgRecvBmsStatisticsDataOk,
											pdTRUE,pdTRUE,1000);
	if((uxBitRes & defEventBitChrgRecvBmsStatisticsDataOk) == defEventBitChrgRecvBmsStatisticsDataOk)
	{
		//从外部模块获取充电机统计数据
		bmsData.chrgTotalTime = ;
		bmsData.chrgTotalPower = ;
		bmsData.chrgEncode = ;
		CANCMDSND("csd",250,STARTSIGNAL);
	}
	else
	{
		//1s超时处理
		stageRes = CHRGDONEFAILED;
		return stageRes;
	}

#endif
	stageRes = STAGEOK;

	return stageRes;	
}























