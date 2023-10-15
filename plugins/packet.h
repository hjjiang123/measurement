#ifndef __PACKET_H_
#define __PACKET_H_

typedef struct ip_packet_header{
    uint8 version;         // 版本号
    uint8 headerLength;    // 报文头长度（以32位字为单位）
    uint8 typeOfService;   // 服务类型
    uint16 totalLength;    // 总长度
    uint16 identification; // 标识
    uint16 flags;          // 标志位
    uint8 ttl;             // 存活时间
    uint8 protocol;        // 协议
    uint16 checksum;       // 校验和
    uint32 sourceIP;       // 源IP地址
    uint32 destIP;         // 目的IP地址
} IPHeader; 
#endif
