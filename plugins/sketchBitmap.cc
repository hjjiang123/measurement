#include "sketchBitmap.h"

SketchBitmap::SketchBitmap()
{
}

SketchBitmap::~SketchBitmap()
{
}

void SketchBitmap::configure(int field, int numBits)
{

    _hashInfo.field = field;
    _hashInfo.numHashValues = 1;
    _hashInfo.range = numBits;

    _counterInfo.numRows = 1;
    _counterInfo.countersPerRow = numBits;
    _counterInfo.updateType = UPDATETYPE_SET;
    // sketch_id, nextOffset, counterSize is set by Calling Function
}

void SketchBitmap::setup()
{
    // 配置哈希函数
    _hashFunc = std::make_shared<XXHash32>();

    //申请内存空间
    uint8 *p2 = new uint8 [getSize() / 8 + 1];
    _space.reset(p2);
}

bool SketchBitmap::process(IPHeader *iph, uint16 length, void **argv)
{
    uint32 origin = _hashInfo.field == 1 ? iph->sourceIP : iph->destIP;
    _hashFunc->add((void *)&origin, 4);
    uint32 hashvalue = _hashFunc->hash() % (_hashInfo.range);
    *(_space.get() + (hashvalue >> 3)) = *(_space.get() + (hashvalue >> 3)) & (7 - (hashvalue - (hashvalue >> 3) * 8));
    return true;
}

int SketchBitmap::getSize()
{
    return _counterInfo.numRows * _counterInfo.countersPerRow;
}

int SketchBitmap::query()
{
    int size = getSize();
    uint32 setBits = 0;
    for (int i = 0; i < size / 8 + 1; i++)
    {
        int temp = 1;
        for (int j = 0; j < 8; j++)
        {
            if (*(_space.get() + i) & temp)
            {
                setBits++;
            }
            temp = temp << 1;
        }
    }

    int numBits = size;
    int zeroBits = size - setBits;
    double estimate = zeroBits * log(((double)numBits) / zeroBits);
    return (int)estimate;
}
