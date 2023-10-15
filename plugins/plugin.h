#ifndef __PLUGIN_H
#define __PLUGIN_H
#include "common.h"

class Plugin {
private:
    static int _plugin_id;
public:
    Plugin(){++_plugin_id;};

    ~Plugin(){};

    virtual void run() = 0;
    virtual bool sample() = 0;
    virtual void setNextPlugin(Plugin * plg) = 0;


    static int get_plugin_id() {
        return _plugin_id; // 返回当前对象数量
    }
};

class SamplePlugin: public Plugin {
private:
public:
    SamplePlugin(){};
    ~SamplePlugin(){};

};

class FilterPlugin: public Plugin {
public:
    FilterPlugin(){};
    ~FilterPlugin(){};
    virtual bool filter(void * packet, uint16 size) = 0;
};

class AbstractPlugin: public Plugin {
public:
    AbstractPlugin(){};
    ~AbstractPlugin(){};

    virtual void setup() = 0; // directly
    virtual void update(void * packet, uint16 size) = 0;

    virtual int getSize() = 0;
    virtual int query(const vector<int>& counts) = 0;
};
#endif 