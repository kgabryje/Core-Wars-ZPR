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

    if (num < MARSConstants::MEMORY_ARRAY_SIZE)
        index = num;
    int modulo = num % MARSConstants::MEMORY_ARRAY_SIZE;
    index = modulo;
}

bool MemoryIndex::operator==(int cmp) {
    return (index == cmp);
}

int MemoryIndex::operator*() const {
    return this->index;
}

MemoryIndex &MemoryIndex::operator+=(int num) {
    this->index += num;
    if (index >= MARSConstants::MEMORY_ARRAY_SIZE)
        index = index % MARSConstants::MEMORY_ARRAY_SIZE;
    if (index < 0)
        index = MARSConstants::MEMORY_ARRAY_SIZE + index % MARSConstants::MEMORY_ARRAY_SIZE;
    return *this;
}

MemoryIndex MemoryIndex::operator+(int num) {
    int ret = this->index + num;
    if (ret >= MARSConstants::MEMORY_ARRAY_SIZE)
        ret = ret % MARSConstants::MEMORY_ARRAY_SIZE;
    return MemoryIndex(ret);
}

MemoryIndex MemoryIndex::operator-(int num) {
    int ret = this->index - num;
    if (ret < 0)
        ret = MARSConstants::MEMORY_ARRAY_SIZE + ret % MARSConstants::MEMORY_ARRAY_SIZE;
    return MemoryIndex(ret);
}

MemoryIndex &MemoryIndex::operator-=(int num) {
    this->index -= num;
    if (index >= MARSConstants::MEMORY_ARRAY_SIZE)
        index = index % MARSConstants::MEMORY_ARRAY_SIZE;
    if (index < 0)
        index = MARSConstants::MEMORY_ARRAY_SIZE + index % MARSConstants::MEMORY_ARRAY_SIZE;
    return *this;
}
