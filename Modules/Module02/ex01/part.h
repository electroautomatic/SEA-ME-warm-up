#ifndef PART_H
#define PART_H

class Part {
public:
    virtual void print() = 0; // Pure virtual function to be overridden by derived classes
    virtual ~Part() {}
};

#endif // PART_H
