#include "plugin.h"

const uint32 fields[5]={};
class FixedFilterPlugin: public Plugin {
private:
    /*
    first -> fields of a packet
        0 : src_ip
        1 : dst_ip
        2 : src_port
        3 ：dst_port
        4 : protocol
    second -> value of fields
    */
    pair<uint32,uint32> _conditions[8];
    uint32 _count; //条件个数
public:
    FixedFilterPlugin():_count(0){};
    ~FixedFilterPlugin(){};
    void addCondition(uint32 field, uint32 value){
        _conditions[_count++] = make_pair(field, value);
    };
    bool filter(void * packet, uint16 length){
        /*...............*/
        IPHeader * iph = (IPHeader *)packet;
        
        
    }

};
