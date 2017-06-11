#include "ViewConnector.h"
#include "logic/ServerConnector.h"

void ViewConnector::sendToView(IterationResult result) {
    gameInfo.__set_colorTable(std::vector<std::string>());
    createViewData(result);
    ServerConnector::getInstance().setGameInfo(gameInfo);
}

void ViewConnector::createViewData(const IterationResult &result) {

    gameInfo.__set_firstPlayerProcessesNumber(result.getFirstWarriorProcessesIndexes().size());
    gameInfo.__set_secondPlayerProcessesNumber(result.getSecondWarriorProcessesIndexes().size());

    if (result.getLooser().is_initialized()) {
        gameInfo.__set_hasEnded(true);
        gameInfo.__set_winner(result.getPlayerName());
    } else
        gameInfo.__set_hasEnded(false);
    for (Instruction i: result.getMemoryArray())
        colourOperations(i);
    for (MemoryIndex mi: result.getFirstWarriorProcessesIndexes())
        colourWarriorProcesses(*mi, ViewConstants::FIRST_PLAYER_COLOR);
    for (MemoryIndex mi: result.getSecondWarriorProcessesIndexes())
        colourWarriorProcesses(*mi, ViewConstants::SECOND_PLAYER_COLOR);
}

void ViewConnector::colourOperations(const Instruction i) {
    if (i.getOperation()->getOpCode() == ParserConstants::INSTR_CODE_DAT)
        gameInfo.colorTable.push_back(ViewConstants::INSTR_COLOR_DAT);
    else if (i.getOperation()->getOpCode() == ParserConstants::INSTR_CODE_MOV)
        gameInfo.colorTable.push_back(ViewConstants::INSTR_COLOR_MOV);
    else if (i.getOperation()->getOpCode() == ParserConstants::INSTR_CODE_JMP)
        gameInfo.colorTable.push_back(ViewConstants::INSTR_COLOR_JMP);
    else if (i.getOperation()->getOpCode() == ParserConstants::INSTR_CODE_ADD)
        gameInfo.colorTable.push_back(ViewConstants::INSTR_COLOR_ADD);
}

void ViewConnector::colourWarriorProcesses(int i, const std::string colour) {
    gameInfo.colorTable[i] = colour;
}
