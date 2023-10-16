#ifndef __SAMPLE_PLUGIN_H
#define __SAMPLE_PLUGIN_H
#include "plugin.h"

class UnionSamplePlugin: public SamplePlugin {
private:
    uint32 _ratio;
    uint32 _cur;
public:
    UnionSamplePlugin(uint32 ratio):_ratio(ratio),_cur(0){};
    ~UnionSamplePlugin(){};
    
    void setup(){
        if(getNextPlugin()){
            setupNextPlugin();
        }
    };
    bool process(){
        if(_cur == 0){
            resetRatio();
            return true;
        }else{
            _cur--;
            return false;
        }
    }
    
    uint32 getRatio(){
        return _ratio;
    };
    void setRatio(uint32 ratio){
        _ratio = ratio;
    }
    inline void resetRatio(){
        _cur = _ratio;
    }
};
#endif  