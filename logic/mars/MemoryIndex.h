#ifndef CORE_WARS_ZPR_MEMORYINDEX_H
#define CORE_WARS_ZPR_MEMORYINDEX_H


class MemoryIndex {
public:
    MemoryIndex(int index);

    MemoryIndex &operator++();

    MemoryIndex &operator++(int);

    int operator*() const;

    MemoryIndex operator+(int);

    MemoryIndex &operator+=(int);

    MemoryIndex operator-(int);

    MemoryIndex &operator-=(int);

    bool operator==(int);

private:
    int index;
};


#endif //CORE_WARS_ZPR_MEMORYINDEX_H