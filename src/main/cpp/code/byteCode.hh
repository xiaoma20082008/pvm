//
// Created by chunxiao ma on 2021/11/3.
//

#ifndef PVM_BYTE_CODE_HH
#define PVM_BYTE_CODE_HH
namespace pvm {
// Define pvm.Bytecode Operator Code. From https://github.com/python/cpython/blob/main/Lib/opcode.py
class ByteCode {
public:
  static constexpr unsigned char POP_TOP = 1;
  static constexpr unsigned char ROT_TWO = 2;
  static constexpr unsigned char ROT_THREE = 3;
  static constexpr unsigned char DUP_TOP = 4;
  static constexpr unsigned char DUP_TOP_TWO = 5;
  static constexpr unsigned char ROT_FOUR = 6;

  static constexpr unsigned char NOP = 9;
  static constexpr unsigned char UNARY_POSITIVE = 10;
  static constexpr unsigned char UNARY_NEGATIVE = 11;
  static constexpr unsigned char UNARY_NOT = 12;

  static constexpr unsigned char UNARY_INVERT = 15;
  static constexpr unsigned char BINARY_MATRIX_MULTIPLY = 16;
  static constexpr unsigned char INPLACE_MATRIX_MULTIPLY = 17;

  static constexpr unsigned char BINARY_POWER = 19;
  static constexpr unsigned char BINARY_MULTIPLY = 20;

  static constexpr unsigned char BINARY_MODULO = 22;
  static constexpr unsigned char BINARY_ADD = 23;
  static constexpr unsigned char BINARY_SUBTRACT = 24;
  static constexpr unsigned char BINARY_SUBSCR = 25;
  static constexpr unsigned char BINARY_FLOOR_DIVIDE = 26;
  static constexpr unsigned char BINARY_TRUE_DIVIDE = 27;
  static constexpr unsigned char INPLACE_FLOOR_DIVIDE = 28;
  static constexpr unsigned char INPLACE_TRUE_DIVIDE = 29;
  static constexpr unsigned char GET_LEN = 30;
  static constexpr unsigned char MATCH_MAPPING = 31;
  static constexpr unsigned char MATCH_SEQUENCE = 32;
  static constexpr unsigned char MATCH_KEYS = 33;

  static constexpr unsigned char PUSH_EXC_INFO = 35;

  static constexpr unsigned char POP_EXCEPT_AND_RERAISE = 37;

  static constexpr unsigned char WITH_EXCEPT_START = 49;
  static constexpr unsigned char GET_AITER = 50;
  static constexpr unsigned char GET_ANEXT = 51;
  static constexpr unsigned char BEFORE_ASYNC_WITH = 52;
  static constexpr unsigned char BEFORE_WITH = 53;

  static constexpr unsigned char END_ASYNC_FOR = 54;
  static constexpr unsigned char INPLACE_ADD = 55;
  static constexpr unsigned char INPLACE_SUBTRACT = 56;
  static constexpr unsigned char INPLACE_MULTIPLY = 57;

  static constexpr unsigned char INPLACE_MODULO = 59;
  static constexpr unsigned char STORE_SUBSCR = 60;
  static constexpr unsigned char DELETE_SUBSCR = 61;
  static constexpr unsigned char BINARY_LSHIFT = 62;
  static constexpr unsigned char BINARY_RSHIFT = 63;
  static constexpr unsigned char BINARY_AND = 64;
  static constexpr unsigned char BINARY_XOR = 65;
  static constexpr unsigned char BINARY_OR = 66;
  static constexpr unsigned char INPLACE_POWER = 67;
  static constexpr unsigned char GET_ITER = 68;
  static constexpr unsigned char GET_YIELD_FROM_ITER = 69;
  static constexpr unsigned char PRINT_EXPR = 70;
  static constexpr unsigned char LOAD_BUILD_CLASS = 71;
  static constexpr unsigned char YIELD_FROM = 72;
  static constexpr unsigned char GET_AWAITABLE = 73;
  static constexpr unsigned char LOAD_ASSERTION_ERROR = 74;
  static constexpr unsigned char INPLACE_LSHIFT = 75;
  static constexpr unsigned char INPLACE_RSHIFT = 76;
  static constexpr unsigned char INPLACE_AND = 77;
  static constexpr unsigned char INPLACE_XOR = 78;
  static constexpr unsigned char INPLACE_OR = 79;

  static constexpr unsigned char LIST_TO_TUPLE = 82;
  static constexpr unsigned char RETURN_VALUE = 83;
  static constexpr unsigned char IMPORT_STAR = 84;
  static constexpr unsigned char SETUP_ANNOTATIONS = 85;
  static constexpr unsigned char YIELD_VALUE = 86;

  static constexpr unsigned char POP_EXCEPT = 89;

  static constexpr unsigned char HAVE_ARGUMENT = 90; // Opcodes from here have an argument:

  static constexpr unsigned char STORE_NAME = 90;      // Index in name list
  static constexpr unsigned char DELETE_NAME = 91;     // ""
  static constexpr unsigned char UNPACK_SEQUENCE = 92; // Number of tuple items
  static constexpr unsigned char FOR_ITER = 93;
  static constexpr unsigned char UNPACK_EX = 94;
  static constexpr unsigned char STORE_ATTR = 95;    //  Index in name list
  static constexpr unsigned char DELETE_ATTR = 96;   //  ""
  static constexpr unsigned char STORE_GLOBAL = 97;  //  ""
  static constexpr unsigned char DELETE_GLOBAL = 98; //  ""
  static constexpr unsigned char ROT_N = 99;
  static constexpr unsigned char LOAD_CONST = 100;  // Index in const list
  static constexpr unsigned char LOAD_NAME = 101;   // Index in name list
  static constexpr unsigned char BUILD_TUPLE = 102; // Number of tuple items
  static constexpr unsigned char BUILD_LIST = 103;  // Number of list items
  static constexpr unsigned char BUILD_SET = 104;   // Number of set items
  static constexpr unsigned char BUILD_MAP = 105;   // Number of dict entries
  static constexpr unsigned char LOAD_ATTR = 106;   // Index in name list
  static constexpr unsigned char COMPARE_OP = 107;  // Comparison operator
  static constexpr unsigned char IMPORT_NAME = 108; // Index in name list
  static constexpr unsigned char IMPORT_FROM = 109; // Index in name list
  static constexpr unsigned char JUMP_FORWARD = 110;
  static constexpr unsigned char JUMP_IF_FALSE_OR_POP = 111; // Target byte offset from beginning of code
  static constexpr unsigned char JUMP_IF_TRUE_OR_POP = 112;  // ""
  static constexpr unsigned char JUMP_ABSOLUTE = 113;        // ""
  static constexpr unsigned char POP_JUMP_IF_FALSE = 114;    // ""
  static constexpr unsigned char POP_JUMP_IF_TRUE = 115;     // ""
  static constexpr unsigned char LOAD_GLOBAL = 116;          // Index in name list
  static constexpr unsigned char IS_OP = 117;
  static constexpr unsigned char CONTAINS_OP = 118;
  static constexpr unsigned char RERAISE = 119;
  static constexpr unsigned char COPY = 120;
  static constexpr unsigned char JUMP_IF_NOT_EXC_MATCH = 121;

  static constexpr unsigned char LOAD_FAST = 124;   // Local variable number
  static constexpr unsigned char STORE_FAST = 125;  // Local variable number
  static constexpr unsigned char DELETE_FAST = 126; // Local variable number

  static constexpr unsigned char GEN_START = 129;     // Kind of generator/coroutine
  static constexpr unsigned char RAISE_VARARGS = 130; // Number of raise arguments (1, 2, or 3;
  static constexpr unsigned char CALL_FUNCTION = 131; // #args
  static constexpr unsigned char MAKE_FUNCTION = 132; // Flags
  static constexpr unsigned char BUILD_SLICE = 133;   // Number of items
  static constexpr unsigned char MAKE_CELL = 135;
  static constexpr unsigned char LOAD_CLOSURE = 136;
  static constexpr unsigned char LOAD_DEREF = 137;
  static constexpr unsigned char STORE_DEREF = 138;
  static constexpr unsigned char DELETE_DEREF = 139;

  static constexpr unsigned char CALL_FUNCTION_VAR = 140;
  static constexpr unsigned char CALL_FUNCTION_KW = 141; // #args + #kwargs
  static constexpr unsigned char CALL_FUNCTION_EX = 142; // Flags

  static constexpr unsigned char EXTENDED_ARG = 144;
  static constexpr unsigned char LIST_APPEND = 145;
  static constexpr unsigned char SET_ADD = 146;
  static constexpr unsigned char MAP_ADD = 147;
  static constexpr unsigned char LOAD_CLASSDEREF = 148;

  static constexpr unsigned char MATCH_CLASS = 152;
  static constexpr unsigned char FORMAT_VALUE = 155;
  static constexpr unsigned char BUILD_CONST_KEY_MAP = 156;
  static constexpr unsigned char BUILD_STRING = 157;
  static constexpr unsigned char LOAD_METHOD = 160;
  static constexpr unsigned char CALL_METHOD = 161;
  static constexpr unsigned char LIST_EXTEND = 162;
  static constexpr unsigned char SET_UPDATE = 163;
  static constexpr unsigned char DICT_MERGE = 164;
  static constexpr unsigned char DICT_UPDATE = 165;
  static constexpr unsigned char CALL_METHOD_KW = 166;

  enum COMPARE { LESS = 0, LESS_EQUAL, EQUAL, NOT_EQUAL, GREATER, GREATER_EQUAL, IN, NOT_IN, IS, IS_NOT, EXC_MATCH };
};
} // namespace pvm
#endif // PVM_BYTE_CODE_HH
