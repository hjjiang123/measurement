#ifndef __SKETCHBITMAP_H
#define __SKETCHBITMAP_H
#include "plugin.h"
#include "xxhash32.h"

class SketchBitmap : public SketchPlugin
{
private:
    std::shared_ptr<XXHash32> _hashFunc;
    std::shared_ptr<uint8> _space;

public:
    SketchBitmap();
    ~SketchBitmap();

    void setup() override;
    void configure(int field, int numBits); // directly
    bool process(IPHeader *iph, uint16 length, void **argv) override;

    int getSize() override;
    int query() override;
};
#endif
