/*************************************************************************
	> File Name: matt.h
    > Author: DCJ
	> Mail: 
    > Created Time: 2019年05月29日 星期三 16时40分31秒
 ************************************************************************/

#ifndef NET_PROC_H
#define NET_PROC_H

#ifdef __cplusplus
extern "C" {
#endif

enum  iot_ctrl_status_t
{
	IOT_STATUS_LOGIN,
	IOT_STATUS_CONNECT,
    IOT_STATUS_DROP
};

typedef void  (*pMessageArrived_Fun)(void*,int len);

void mqtt_module_init(void);
int mqtt_data_write(char *pbuf, int len, char retain);
void mqtt_data_rx_cb(void *pbuf, int len);

void mqtt_data_rx_cb(void *pbuf, int len);
void *cloud_mqtt_thread();

void clientReadMqtt(void *pbuf, int len);

#define mDEBUG(fmt, ...)  printf("%s[%s](%d):" fmt,__FILE__,__FUNCTION__,__LINE__,##__VA_ARGS__)

#ifdef __cplusplus
}
#endif

#endif
