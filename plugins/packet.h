#ifndef __PACKET_H_
#define __PACKET_H_
#include "common.h"

typedef struct ip_packet_header{
    uint8_t version;         // 版本号
    uint8_t headerLength;    // 报文头长度（以32位字为单位）
    uint8_t typeOfService;   // 服务类型
    uint16_t totalLength;    // 总长度
    uint16_t identification; // 标识
    uint16_t flags;          // 标志位
    uint8_t ttl;             // 存活时间
    uint8_t protocol;        // 协议
    uint16_t checksum;       // 校验和
    uint32_t sourceIP;       // 源IP地址
    uint32_t destIP;         // 目的IP地址
} IPHeader; 

class Packet
{
 public:
  uint32_t srcip;
  uint32_t dstip;
  uint32_t srcport;
  uint32_t dstport;
  uint8_t proto;
  Packet()
    {
      srcip = 0;
      dstip = 0;
      srcport = 0;
      dstport = 0;
      proto = 0;
    };
};
#endif
