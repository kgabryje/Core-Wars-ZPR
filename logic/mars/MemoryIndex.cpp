#include <logic/CoreWarsConstants.h>
#include "MemoryIndex.h"

MemoryIndex &MemoryIndex::operator++() {
    if (++index == MARSConstants::MEMORY_ARRAY_SIZE)
        index = 0;
    return *this;
}

MemoryIndex &MemoryIndex::operator++(int) {
    MemoryIndex result(*this);
    ++(*this);
    return result;
}

MemoryIndex::MemoryIndex(int num) {

    if (isBiggerThanMemoryArray(num))
        index = trimNumber(num);
    else if (num < 0)
        index = createMemoryAddressFromNegativeNum(num);
    else index = num;

}

bool MemoryIndex::operator==(int cmp) {
    return (index == cmp);
}

int MemoryIndex::operator*() const {
    return this->index;
}

MemoryIndex &MemoryIndex::operator+=(int num) {
    this->index += num;
    if (isBiggerThanMemoryArray(index))
        index = trimNumber(index);
    if (index < 0)
        index = createMemoryAddressFromNegativeNum(index);
    return *this;
}

MemoryIndex MemoryIndex::operator+(int num) {
    int ret = this->index + num;
    if (isBiggerThanMemoryArray(ret))
        ret = trimNumber(ret);
    if (ret < 0)
        ret = createMemoryAddressFromNegativeNum(ret);

    return MemoryIndex(ret);
}

MemoryIndex MemoryIndex::operator-(int num) {
    int ret = this->index - num;
    if (ret < 0)
        ret = createMemoryAddressFromNegativeNum(ret);
    if (isBiggerThanMemoryArray(ret))
        ret = trimNumber(ret);
    return MemoryIndex(ret);
}

MemoryIndex &MemoryIndex::operator-=(int num) {
    this->index -= num;
    if (isBiggerThanMemoryArray(index))
        index = trimNumber(index);
    if (index < 0)
        index = createMemoryAddressFromNegativeNum(index);
    return *this;
}

bool MemoryIndex::isBiggerThanMemoryArray(int numToCheck) const {
    return numToCheck >= MARSConstants::MEMORY_ARRAY_SIZE;
}

int MemoryIndex::trimNumber(int num) {
    return num % MARSConstants::MEMORY_ARRAY_SIZE;
}

int MemoryIndex::createMemoryAddressFromNegativeNum(int num) {
    return MARSConstants::MEMORY_ARRAY_SIZE + num % MARSConstants::MEMORY_ARRAY_SIZE;
}
