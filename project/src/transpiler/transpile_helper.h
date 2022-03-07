#ifndef __TRANSPILE_HELPER__
#define __TRANSPILE_HELPER__

// Declares clang::SyntaxOnlyAction.
#include "clang/Frontend/FrontendActions.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"

// Declares llvm::cl::extrahelp.
#include "llvm/Support/CommandLine.h"

#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"

#include "clang/AST/ASTContext.h"
#include "eo_object.h"

std::string GetTypeName(clang::QualType val);

EOObject GetFunctionBody(const clang::FunctionDecl *FD);
EOObject GetCompoundStmt(const clang::CompoundStmt *CS);
EOObject GetStmtEOObject(const clang::Stmt* p_stmt);



#endif //__TRANSPILE_HELPER__
