#ifndef __PLUGIN_H
#define __PLUGIN_H
#include "common.h"

class Plugin
{
private:
    static int _plugin_num;
    Plugin *_nextPlugin = nullptr;

public:
    Plugin() { ++_plugin_num; };
    ~Plugin() { --_plugin_num; };
    virtual void setup() = 0;
    virtual bool process(IPHeader *iph, uint16 length, void **argv) = 0;
    void setNextPlugin(Plugin *plg)
    {
        _nextPlugin = plg;
    }
    Plugin *getNextPlugin()
    {
        return _nextPlugin;
    }
    void setupNextPlugin()
    {
        _nextPlugin->setup();
    }

    static int get_plugin_num()
    {
        return _plugin_num; // 返回当前对象数量
    }
};

class SamplePlugin : public Plugin
{
private:
    // int _sample_type; //0表示均匀抽样，1表示随机抽样
public:
    SamplePlugin(){};
    ~SamplePlugin(){};
};

class FilterPlugin : public Plugin
{
public:
    FilterPlugin(){};
    ~FilterPlugin(){};
};

class SketchPlugin : public Plugin
{
protected:
    tHashInfo _hashInfo;
    tCounterInfo _counterInfo;

public:
    SketchPlugin(){};
    ~SketchPlugin(){};

    tHashInfo getHashInfo()
    {
        return _hashInfo;
    }
    tCounterInfo getCounterInfo(){
        return _counterInfo;
    }
    virtual int getSize() = 0;
    virtual int query() = 0;
};
#endif