#include "llvm/Transforms/Capstone/opCounter.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/PassManager.h"

using namespace llvm;

#define DEBUt_TYPE "count-op"

PreservedAnalyses CountOpPass::run(Function &F, FunctionAnalysisManager &){
    errs() << "Function" << F.getName() <<'\n';
    for(Function::iterator bb = F.begin(), e = F.end(), bb != e; ++b){
        for(BasicBlock::iterator i = bb->begin(), e = bb->end(); i != e; ++i){
            if(opCounter.find(i->getOpcodeName()) == opCounter.end()){
                opCounter[i->getOpcodeName()] = 1;
            }
            else{
                opCounter[i->getOpcodeName()] += 1;
            }
        }
    }
    std::map <std::string, int>::iterator i = opCounter.begin();
    std::map <std::string, int>::iterator e = opCounter.end();
    while(i != e){
        errs() << i->first << ": " << i->second << "\n";
    }
    errs() << "\n"
    opCounter.clear();
    return false;
}
