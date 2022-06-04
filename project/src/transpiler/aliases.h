#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "fuchsia-statically-constructed-objects"
#ifndef C2EO_SRC_TRANSPILER_ALIASES_H_
#define C2EO_SRC_TRANSPILER_ALIASES_H_

#include "map"
#include "set"
#include "string"

std::set<std::string> known_types = {
    "memory",
    "seq",
    "$",
};

std::map<std::string, std::string> known_aliases = {
    {"abs", "+alias c2eo.coperators.abs"},
    {"add", "+alias c2eo.coperators.add"},
    {"addr-of", "+alias c2eo.coperators.addr-of"},
    {"addrcpy", "+alias c2eo.coperators.addrcpy"},
    {"address", "+alias c2eo.system.address"},
    {"addrmemcpy", "+alias c2eo.coperators.addrmemcpy"},
    {"and", "+alias c2eo.coperators.and"},
    {"as-bool", "+alias c2eo.coperators.as-bool"},
    {"as-float64", "+alias c2eo.coperators.as-float64"},
    {"as-int64", "+alias c2eo.coperators.as-int64"},
    {"as-string", "+alias c2eo.coperators.as-string"},
    {"bit-and", "+alias c2eo.coperators.bit-and"},
    {"bit-not", "+alias c2eo.coperators.bit-not"},
    {"bit-or", "+alias c2eo.coperators.bit-or"},
    {"bit-xor", "+alias c2eo.coperators.bit-xor"},
    {"coawait", "+alias c2eo.coperators.coawait"},
    {"do-while", "+alias c2eo.coperators.do-while"},
    {"div", "+alias c2eo.coperators.div"},
    {"eq", "+alias c2eo.coperators.eq"},
    {"extension", "+alias c2eo.coperators.extension"},
    {"geq", "+alias c2eo.coperators.geq"},
    {"get", "+alias c2eo.coperators.get"},
    {"goto", "+alias org.eolang.gray.goto"},
    {"greater", "+alias c2eo.coperators.greater"},
    {"if", "+alias c2eo.coperators.if"},
    {"if-else", "+alias c2eo.coperators.if-else"},
    {"imag", "+alias c2eo.coperators.imag"},
    {"leq", "+alias c2eo.coperators.leq"},
    {"less", "+alias c2eo.coperators.less"},
    {"memadrcpy", "+alias c2eo.coperators.memadrcpy"},
    {"mod", "+alias c2eo.coperators.mod"},
    {"mul", "+alias c2eo.coperators.mul"},
    {"neg", "+alias c2eo.coperators.neg"},
    {"neq", "+alias c2eo.coperators.neq"},
    {"not", "+alias c2eo.coperators.not"},
    {"or", "+alias c2eo.coperators.or"},
    {"plug", "+alias c2eo.coperators.plug"},
    {"plus", "+alias c2eo.coperators.plus"},
    {"post-dec", "+alias c2eo.coperators.post-dec"},
    {"post-dec-int64", "+alias c2eo.coperators.post-dec-int64"},
    {"post-dec-ptr", "+alias c2eo.coperators.post-dec-ptr"},
    {"post-inc", "+alias c2eo.coperators.post-inc"},
    {"post-inc-int64", "+alias c2eo.coperators.post-inc-int64"},
    {"post-inc-ptr", "+alias c2eo.coperators.post-inc-ptr"},
    {"pow", "+alias c2eo.coperators.pow"},
    {"pre-dec", "+alias c2eo.coperators.pre-dec"},
    {"pre-dec-int64", "+alias c2eo.coperators.pre-dec-int64"},
    {"pre-dec-ptr", "+alias c2eo.coperators.pre-dec-ptr"},
    {"pre-inc", "+alias c2eo.coperators.pre-inc"},
    {"pre-inc-int64", "+alias c2eo.coperators.pre-inc-int64"},
    {"pre-inc-ptr", "+alias c2eo.coperators.pre-inc-ptr"},
    {"printf", "+alias c2eo.stdio.printf"},
    {"ram", "+alias c2eo.system.ram"},
    {"read", "+alias c2eo.coperators.read"},
    {"read-as-address", "+alias c2eo.coperators.read-as-address"},
    {"read-as-bool", "+alias c2eo.coperators.read-as-bool"},
    {"read-as-float64", "+alias c2eo.coperators.read-as-float64"},
    {"read-as-float32", "+alias c2eo.coperators.read-as-float32"},
    {"read-as-int16", "+alias c2eo.coperators.read-as-int16"},
    {"read-as-int32", "+alias c2eo.coperators.read-as-int32"},
    {"read-as-int64", "+alias c2eo.coperators.read-as-int64"},
    {"read-as-ptr", "+alias c2eo.coperators.read-as-ptr"},
    {"real", "+alias c2eo.coperators.real"},
    {"shift-left", "+alias c2eo.coperators.shift-left"},
    {"shift-right", "+alias c2eo.coperators.shift-right"},
    {"sub", "+alias c2eo.coperators.sub"},
    {"while", "+alias c2eo.coperators.while"},
    {"write", "+alias c2eo.coperators.write"},
    {"write-as-bool", "+alias c2eo.coperators.write-as-bool"},
    {"write-as-float64", "+alias c2eo.coperators.write-as-float64"},
    {"write-as-float32", "+alias c2eo.coperators.write-as-float32"},
    {"write-as-int16", "+alias c2eo.coperators.write-as-int16"},
    {"write-as-int32", "+alias c2eo.coperators.write-as-int32"},
    {"write-as-int64", "+alias c2eo.coperators.write-as-int64"},
    {"write-as-ptr", "+alias c2eo.coperators.write-as-ptr"},
};

#endif

#pragma clang diagnostic pop