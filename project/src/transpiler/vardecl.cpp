#include "vardecl.h"
#include "unit_transpiler.h"
#include "transpile_helper.h"
#include <sstream>

using namespace clang;

EOObject InitValueAnalysis(const VarDecl *VD);

EOObject InitZeroValueAnalysis(const VarDecl *VD);

void ArrayToBytes(__attribute__((unused)) Stmt *stmt, size_t size, const VarDecl *p_decl, std::string &string);

EOObject InitValueEOObj(const VarDecl *VD, bool is_init);
Variable ProcessVariable(const VarDecl *VD, const std::string &local_name, size_t shift) {
  auto var_name = VD->getNameAsString();
  QualType qual_type = VD->getType();
  TypeInfo type_info = VD->getASTContext().getTypeInfo(qual_type);
  auto type_size = type_info.Width / 8;

  std::string str_type{std::string("c_" + GetTypeName(VD->getType()))};
  auto storage_class = VD->getStorageClass();
  auto static_local = VD->isStaticLocal();
  auto ext_storage = VD->hasExternalStorage();
  auto global_storage = VD->hasGlobalStorage();
  auto is_init = VD->hasInit();
  //std::string str_value;
  EOObject initial_value = InitValueEOObj(VD, is_init);
  extern UnitTranspiler transpiler;

  if (global_storage && !ext_storage && !static_local && (storage_class != SC_Static)) {
    return transpiler.glob_.Add(VD, type_size, str_type, "g-" + var_name, initial_value);
  } else if (global_storage && !ext_storage) {
    return transpiler.glob_.Add(VD, type_size, str_type, "s-" + var_name, initial_value);
  } else if (global_storage) {
    return transpiler.glob_.AddExternal(VD, type_size, str_type, "e-" + var_name, initial_value);
  } else // its local variable!
  {
    if (local_name.empty()) {
      return {};
    }
    const auto *PD = llvm::dyn_cast<ParmVarDecl>(VD);
    if (PD) {
      return transpiler.glob_.Add(VD, type_size, str_type, "p-" + var_name,
                                  initial_value, local_name, shift, VD->hasInit());
    }
    return transpiler.glob_.Add(VD, type_size, str_type, "l-" + var_name,
                                initial_value, local_name, shift, VD->hasInit());
  }
}
EOObject InitValueEOObj(const VarDecl *VD, bool is_init) {
  if (is_init) {
    return InitValueAnalysis(VD);
  } else {
    return InitZeroValueAnalysis(VD);
  }
}

EOObject InitValueAnalysis(const VarDecl *VD) {
  auto qual_type = VD->getType();
  auto type_ptr = qual_type.getTypePtr();

  auto type_info = VD->getASTContext().getTypeInfo(qual_type);
  auto size = type_info.Width;
  APValue *init_val = VD->evaluateValue();
  if(!init_val)
  {
    return GetStmtEOObject(VD->getInit());
  }

  std::string str;
  if (init_val != nullptr) {
    if (init_val->isInt()) {
      auto int_value = init_val->getInt().getExtValue();
      if (type_ptr->isCharType()) {
        str = "'";
        str += char(int_value);
        str += "'";
      } else {
        str = std::to_string(int_value);
      }
    } else if (init_val->isFloat() && (size == 64)) {
      auto float_value = init_val->getFloat().convertToDouble();
      str = std::to_string(float_value);
    } else if (init_val->isFloat() && (size == 32)) {
      auto float_value = init_val->getFloat().convertToFloat();
      str = std::to_string(float_value);
    }
  } else {
    // TODO  IF IT USED rewrite this code or transfer to GetStmtEOObject
    Stmt *body = (Stmt *) ((clang::InitListExpr *) (VD->getInit()));
    ArrayToBytes(body, size, VD, str);
  }
  return {str,EOObjectType::EO_LITERAL};
}

void ArrayToBytes(__attribute__((unused)) Stmt *stmt,
                  __attribute__((unused)) size_t size,
                  __attribute__((unused)) const VarDecl *p_decl,
                  std::string &string) {
  string += "plug";
}

EOObject InitZeroValueAnalysis(const VarDecl *VD) {
  auto qual_type = VD->getType();
  auto type_ptr = qual_type.getTypePtr();
  std::string str;
  if (type_ptr->isCharType()) {
    str = "'\\0'";
  } else if (type_ptr->isIntegerType() || type_ptr->isBooleanType()
      || type_ptr->isPointerType() || type_ptr->isRecordType() || type_ptr->isArrayType()) {
    str = "0";
  } else {
    str = "";
  }
  return {str,EOObjectType::EO_LITERAL};
}
