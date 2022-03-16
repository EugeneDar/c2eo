#include <sstream>
#include "unit_transpiler.h"
#include "transpile_helper.h"
#include "aliases.h"

std::ostream &operator<<(std::ostream &os, UnitTranspiler unit) {
  if (unit.tmp.empty())
    unit.GenerateResult();
  os << unit.tmp;
  return os;
}


void UnitTranspiler::GenerateResult() {
  EOObject body(EOObjectType::EO_ABSTRACT);
  body.arguments.emplace_back("args...");
  body.postfix = "global";
  body.nested.push_back(glob.GetEOObject());
  body.nested.emplace_back("memory","empty-global-position");
  body.nested.push_back(ret.GetEOObject());
  body.nested.emplace_back("memory","return-mem_size");
  EOObject ret_addr("address","return");
  ret_addr.nested.emplace_back(ret.name);
  ret_addr.nested.emplace_back("0",EOObjectType::EO_LITERAL);
  body.nested.push_back(ret_addr);

  if(!glob.Empty()){
    for(const auto& var : glob){
      body.nested.emplace_back(var.GetAdress(glob.name));
    }
  }

  for(const auto& func : func_manager.GetAllDefinitions()){

    body.nested.push_back(func.GetEOObject());
  }

  EOObject init_seq("seq","@");
  for(const auto& var : glob){
    init_seq.nested.push_back(var.GetInitializer());
  }
  if (std::find_if(body.nested.begin(), body.nested.end(),
                   [] (EOObject x) {return x.postfix=="main";})!=body.nested.end()) {
    init_seq.nested.emplace_back("main");
  }

  init_seq.nested.emplace_back("TRUE",EOObjectType::EO_LITERAL);

  body.nested.push_back(init_seq);

  std::stringstream result;
  result << "+package c2eo.src." << package_name << "\n";

  used_external_objects = FindAllExternalObjects(body);
  for(const auto& ext_obj : used_external_objects)
  {
    if(known_types.find(ext_obj)==known_types.end()) {
      std::string alias;
      try{
        alias = known_aliases.at(ext_obj);
        result << alias << "\n";
      }
      catch (std::out_of_range&)
      {
        llvm::errs() << "Not found alias for " << ext_obj << "\n";
      }
    }
  }

  result << "\n";

  result <<  body;
  tmp = result.str();
}
void UnitTranspiler::SetPackageName(std::string packagename) {
  package_name = std::move(packagename);
}
