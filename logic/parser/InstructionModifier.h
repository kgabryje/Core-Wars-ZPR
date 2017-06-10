#ifndef CORE_WARS_ZPR_INSTRUCTIONMODIFIER_H
#define CORE_WARS_ZPR_INSTRUCTIONMODIFIER_H

#include <string>
#include <boost/optional.hpp>
#include <logic/mars/Instruction.h>
#include <vector>
#include <memory>

class Instruction;

class MemoryIndex;

class InstructionModifier {
public:
    InstructionModifier(const std::string &modifierCode, int value = 0);

    virtual std::shared_ptr<InstructionModifier> clone() const = 0;

    const std::string &getModifierCode() const;

    int getValue() const;

    void setValue(int value);

    void setModifierCode(const std::string &modifierCode);

    virtual boost::optional<Instruction>
    findTargetInstruction(MemoryIndex &mIndex, const std::vector<Instruction> memoryArray)=0;

private:
    int value;
    std::string modifierCode;
};


#endif //CORE_WARS_ZPR_INSTRUCTIONMODIFIER_H
