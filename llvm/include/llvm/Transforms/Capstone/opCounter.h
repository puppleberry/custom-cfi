#ifndef LLVM_TRANSFORMS_UTILS_OP_COUNTER_H
#define LLVM_TRANSFORMS_UTILS_OP_COUNTER_H

#include "llvm/ADT/StringMap.h"
#include "llvm/IR/PassManager.h"

namespace llvm {

class Function;

struct CountOpPass : PassInfoMixin<CountOpPass> {
  PreservedAnalyses run(Function &F, FunctionAnalysisManager &);

private:
  StringMap<uint32_t> opCounter;
  char ID;
};

} // end namespace llvm

#endif // LLVM_TRANSFORMS_UTILS_COUNT_VISITS_H
