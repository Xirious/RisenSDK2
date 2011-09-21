/*

  X86IL - X86(-64) Instruction Length
  Copyright (C) 2003, 2005, 2006 Radim Picha

  Portable C code
    assumes sizeof(X86IL_INSTRUCTION_PAIR_DESCRIPTION) == sizeof(char)
    bit fields can be char

  Updates:
    Jan-05-2006   1.03 : fixed 0F A5 and 0F AD - thanks Villi
    Jan-04-2006   1.02 : fixed A0-3, B8-F, 0F 20-6
                         parameter AddrMode16bit -> Bits
                         added pISize parameter
    May-21-2005   1.01 : basic amd64 support (prefixes only)
                         added pModRM parameter
    Apr-08-2003   1.00 : bugs allowed

//===================================================================


  int X86IL(

    int Bits,                     //  +x - 16bit,
                                  //   0 - 32bit,
                                  //  -x - 64bit code

    const unsigned char *pOriI,   // pointer to original instruction

    unsigned char *pAnaI,         // buffer that retrieves analyzed
                                  // instruction (~ where to copy)
                                  // buffer size >= 26

    int *pnPfx,                   // points to variable for number of
                                  // instruction prefixes

    int *pModRM,                  // pAnaI + *pModRM points to
                                  // ModRM byte if any. Otherwise
                                  // *pModRM = 0.

    int *pISize,                  // points to variable for size of
                                  // immediate value(s) or moffs
  );

  Exceptions:
  1. CPU ignores Mod field of ModRM byte of 0F 20-26 instructions.
     *pModRM = 0 and *pISize = 1 for those instructions.

*/

//===================================================================

typedef struct {
  unsigned char OpdSize     : 3;
  unsigned char IsModRM     : 1;
  unsigned char OpdSizeOdd  : 3;
  unsigned char IsModRMOdd  : 1;
} X86IL_INSTRUCTION_PAIR_DESCRIPTION;

//OpdSize, special values:
#define X86IL_OS_16  2
#define X86IL_OS_32  4

//===================================================================

const X86IL_INSTRUCTION_PAIR_DESCRIPTION X86ILTable[(0x100/2) +(0x100/2)] = {

//00 - ADD    R/M8,  R8
//01 - ADD    R/M32, R32
  {0, 1, 0, 1},

//02 - ADD    R8,    R/M8
//03 - ADD    R32,   R/M32
  {0, 1, 0, 1},

//04 - ADD    AL,    IMM8
//05 - ADD    EAX,   IMM32
  {1, 0, X86IL_OS_32, 0},

//06 - PUSH   ES
//07 - POP    ES
  {0, 0, 0, 0},

//08 - OR     R/M8,  R8
//09 - OR     R/M32, R32
  {0, 1, 0, 1},

//0A - OR     R8,    R/M8
//0B - OR     R32,   R/M32
  {0, 1, 0, 1},

//0C - OR     AL,    IMM8
//0D - OR     EAX,   IMM32
  {1, 0, X86IL_OS_32, 0},

//0E - PUSH   CS
//0F - Table0F
  {0, 0, 0, 0},

//10 - ADC    R/M8,  R8
//11 - ADC    R/M32, R32
  {0, 1, 0, 1},

//12 - ADC    R8,    R/M8
//13 - ADC    R32,   R/M32
  {0, 1, 0, 1},

//14 - ADC    AL,    IMM8
//15 - ADC    EAX,   IMM32
  {1, 0, X86IL_OS_32, 0},

//16 - PUSH   SS
//17 - POP    SS
  {0, 0, 0, 0},

//18 - SBB    R/M8,  R8
//19 - SBB    R/M32, R32
  {0, 1, 0, 1},

//1A - SBB    R8,    R/M8
//1B - SBB    R32,   R/M32
  {0, 1, 0, 1},

//1C - SBB    AL,    IMM8
//1D - SBB    EAX,   IMM32
  {1, 0, X86IL_OS_32, 0},

//1E - PUSH   DS
//1F - POP    DS
  {0, 0, 0, 0},

//20 - AND    R/M8,  R8
//21 - AND    R/M32, R32
  {0, 1, 0, 1},

//22 - AND    R8,    R/M8
//23 - AND    R32,   R/M32
  {0, 1, 0, 1},

//24 - AND    AL,    IMM8
//25 - AND    EAX,   IMM32
  {1, 0, X86IL_OS_32, 0},

//26 - ES:
//27 - DAA
  {0, 0, 0, 0},

//28 - SUB    R/M8,  R8
//29 - SUB    R/M32, R32
  {0, 1, 0, 1},

//2A - SUB    R8,    R/M8
//2B - SUB    R32,   R/M32
  {0, 1, 0, 1},

//2C - SUB    AL,    IMM8
//2D - SUB    EAX,   IMM32
  {1, 0, X86IL_OS_32, 0},

//2E - CS:
//2F - DAS
  {0, 0, 0, 0},

//30 - XOR    R/M8,  R8
//31 - XOR    R/M32, R32
  {0, 1, 0, 1},

//32 - XOR    R8,    R/M8
//33 - XOR    R32,   R/M32
  {0, 1, 0, 1},

//34 - XOR    AL,    IMM8
//35 - XOR    EAX,   IMM32
  {1, 0, X86IL_OS_32, 0},

//36 - SS:
//37 - AAA
  {0, 0, 0, 0},

//38 - CMP    R/M8,  R8
//39 - CMP    R/M32, R32
  {0, 1, 0, 1},

//3A - CMP    R8,    R/M8
//3B - CMP    R32,   R/M32
  {0, 1, 0, 1},

//3C - CMP    AL,    IMM8
//3D - CMP    EAX,   IMM32
  {1, 0, X86IL_OS_32, 0},

//3E - DS:
//3F - AAS
  {0, 0, 0, 0},

//40 - INC    EAX
//41 - INC    ECX
  {0, 0, 0, 0},

//42 - INC    EDX
//43 - INC    EBX
  {0, 0, 0, 0},

//44 - INC    ESP
//45 - INC    EBP
  {0, 0, 0, 0},

//46 - INC    ESI
//47 - INC    EDI
  {0, 0, 0, 0},

//48 - DEC    EAX
//49 - DEC    ECX
  {0, 0, 0, 0},

//4A - DEC    EDX
//4B - DEC    EBX
  {0, 0, 0, 0},

//4C - DEC    ESP
//4D - DEC    EBP
  {0, 0, 0, 0},

//4E - DEC    ESI
//4F - DEC    EDI
  {0, 0, 0, 0},

//50 - PUSH   EAX
//51 - PUSH   ECX
  {0, 0, 0, 0},

//52 - PUSH   EDX
//53 - PUSH   EBX
  {0, 0, 0, 0},

//54 - PUSH   ESP
//55 - PUSH   EBP
  {0, 0, 0, 0},

//56 - PUSH   ESI
//57 - PUSH   EDI
  {0, 0, 0, 0},

//58 - POP    EAX
//59 - POP    ECX
  {0, 0, 0, 0},

//5A - POP    EDX
//5B - POP    EBX
  {0, 0, 0, 0},

//5C - POP    ESP
//5D - POP    EBP
  {0, 0, 0, 0},

//5E - POP    ESI
//5F - POP    EDI
  {0, 0, 0, 0},

//60 - PUSHAD
//61 - POPAD
  {0, 0, 0, 0},

//62 - BOUND
//63 - ARPL
  {0, 1, 0, 1},

//64 - FS:
//65 - GS:
  {0, 0, 0, 0},

//66 - Operand Size Change
//67 - Address Size Change
  {0, 0, 0, 0},

//68 - PUSH    IMM32
//69 - IMUL    R32, R/M16, IMM32
  {X86IL_OS_32, 0, X86IL_OS_32, 1},

//6A - PUSH    IMM8
//6B - IMUL    R32, R/M16, IMM8
  {1, 0, 1, 1},

//6C - INSB
//6D - INSD
  {0, 0, 0, 0},

//6E - OUTSB
//6F - OUTSD
  {0, 0, 0, 0},

//70 - JO      REL8
//71 - JNO     REL8
  {1, 0, 1, 0},

//72 - JC/JB/JNAE REL8
//73 - JNC/JNB/JAE REL8
  {1, 0, 1, 0},

//74 - JE/JZ   REL8
//75 - JNE/JNZ REL8
  {1, 0, 1, 0},

//76 - JBE/JNA REL8
//77 - JA/JNBE REL8
  {1, 0, 1, 0},

//78 - JS      REL8
//79 - JNS     REL8
  {1, 0, 1, 0},

//7A - JP/JPE  REL8
//7B - JNP/JPO REL8
  {1, 0, 1, 0},

//7C - JNS     REL8
//7D - JNS     REL8
  {1, 0, 1, 0},

//7E - JNS     REL8
//7F - JNS     REL8
  {1, 0, 1, 0},

//80 /X - ADD/OR/ADC/SBB/AND/SUB/XOR/CMP  R/M8,  IMM8
//81 /X - ADD/OR/ADC/SBB/AND/SUB/XOR/CMP  R/M32, IMM32
  {1, 1, X86IL_OS_32, 1},

//82 /X - ADD/OR/ADC/SBB/AND/SUB/XOR/CMP  R/M8,  IMM8
//83 /X - ADD/OR/ADC/SBB/AND/SUB/XOR/CMP  R/M32, IMM8
  {1, 1, 1, 1},

//84 - TEST   R8,    R/M8
//85 - TEST   R32,   R/M32
  {0, 1, 0, 1},

//86 - XCHG   R8,    R/M8
//87 - XCHG   R32,   R/M32
  {0, 1, 0, 1},

//88 - MOV    R/M8,  R8
//89 - MOV    R/M32, R32
  {0, 1, 0, 1},

//8A - MOV    R8,    R/M8
//8B - MOV    R32,   R/M32
  {0, 1, 0, 1},

//8C - MOV    R/M32, SREG
//8D - LEA    R32,   R/M32
  {0, 1, 0, 1},

//8E - MOV    SREG,  R/M32
//8F - POP/???/???/???/???/???/???/???  R/M32
  {0, 1, 0, 1},

//90 - NOP
//91 - XCHG   ECX, EAX
  {0, 0, 0, 0},

//92 - XCHG   EDX, EAX
//93 - XCHG   EBX, EAX
  {0, 0, 0, 0},

//94 - XCHG   ESP, EAX
//95 - XCHG   EBP, EAX
  {0, 0, 0, 0},

//96 - XCHG   ESI, EAX
//97 - XCHG   EDI, EAX
  {0, 0, 0, 0},

//98 - CBW/CWDE
//99 - CWDE/CDQ
  {0, 0, 0, 0},

//9A - CALL 16:32
//9B - WAIT
  {X86IL_OS_32 +2, 0, 0, 0},

//9C - PUSHFD
//9D - POPFD
  {0, 0, 0, 0},

//9E - SAHF
//9F - LAHF
  {0, 0, 0, 0},

//A0 - MOV  AL, MOFFS
//A1 - MOV  EAX, MOFFS
  {X86IL_OS_32 +1, 0, X86IL_OS_32 +1, 0},

//A2 - MOV  MOFFS, AL
//A3 - MOV  MOFFS, EAX
  {X86IL_OS_32 +1, 0, X86IL_OS_32 +1, 0},

//A4 - MOVSB
//A5 - MOVSD
  {0, 0, 0, 0},

//A6 - CMPSB
//A7 - CMPSD
  {0, 0, 0, 0},

//A8 - TEST  AL, IMM8
//A9 - TEST  EAX, IMM32
  {1, 0, X86IL_OS_32, 0},

//AA - STOSB
//AB - STOSD
  {0, 0, 0, 0},

//AC - LODSB
//AD - LODSD
  {0, 0, 0, 0},

//AE - SCASB
//AF - SCASD
  {0, 0, 0, 0},

//BO - MOV AL, IMM8
//B1 - MOV CL, IMM8
  {1, 0, 1, 0},

//B2 - MOV DL, IMM8
//B3 - MOV BL, IMM8
  {1, 0, 1, 0},

//B4 - MOV AH, IMM8
//B5 - MOV CH, IMM8
  {1, 0, 1, 0},

//B6 - MOV DH, IMM8
//B7 - MOV BH, IMM8
  {1, 0, 1, 0},

//B8 - MOV EAX, IMM32
//B9 - MOV ECX, IMM32
  {X86IL_OS_32 +3, 0, X86IL_OS_32 +3, 0},

//BA - MOV EDX, IMM32
//BB - MOV EBX, IMM32
  {X86IL_OS_32 +3, 0, X86IL_OS_32 +3, 0},

//BC - MOV ESP, IMM32
//BD - MOV EBP, IMM32
  {X86IL_OS_32 +3, 0, X86IL_OS_32 +3, 0},

//BE - MOV ESI, IMM32
//BF - MOV EDI, IMM32
  {X86IL_OS_32 +3, 0, X86IL_OS_32 +3, 0},

//C0 - ROL/ROR/RCL/RCR/SHL/SHR/SAL/SAR   R/M8,   IMM8
//C1 - ROL/ROR/RCL/RCR/SHL/SHR/SAL/SAR   R/M32,  IMM8
  {1, 1, 1, 1},

//C2 - RET XX XX
//C3 - RET
  {2, 0, 0, 0},

//C4 - LES  R16/32, M16&16/32
//C5 - LDS  R16/32, M16&16/32
  {0, 1, 0, 1},

//C6 - MOV  R/M8,  IMM8
//C7 - MOV  R/M32,  IMM32
  {1, 1, X86IL_OS_32, 1},

//C8 - ENTER
//C9 - LEAVE
  {3, 0, 0, 0},

//CA - RETF XX XX
//CB - RETF
  {2, 0, 0, 0},

//CC - INT 3
//CD - INT XX
  {0, 0, 1, 0},

//CE - INTO
//CF - IRET
  {0, 0, 0, 0},

//D0 - ROL/ROR/RCL/RCR/SHL/SHR/SAL/SAR   R/M8,   1
//D1 - ROL/ROR/RCL/RCR/SHL/SHR/SAL/SAR   R/M32,  1
  {0, 1, 0, 1},

//D2 - ROL/ROR/RCL/RCR/SHL/SHR/SAL/SAR   R/M8,  CL
//D3 - ROL/ROR/RCL/RCR/SHL/SHR/SAL/SAR   R/M32, CL
  {0, 1, 0, 1},

//D4 XX - AAM
//D5 XX - AAD
  {1, 0, 1, 0},

//D6 - SETALC
//D7 - XLATB
  {0, 0, 0, 0},

//D8 - FPUD8
//D9 - FPUD9
  {0, 1, 0, 1},

//DA - FPUDA
//DB - FPUDB
  {0, 1, 0, 1},

//DC - FPUDC
//DD - FPUDD
  {0, 1, 0, 1},

//DE - FPUDE
//DF - FPUDF
  {0, 1, 0, 1},

//E0 - LOOPNE/Z REL8
//E1 - LOOPE/Z  REL8
  {1, 0, 1, 0},

//E2 - LOOP     REL8
//E3 - JECXZ    REL8
  {1, 0, 1, 0},

//E4 - IN  AL,  IMM8
//E5 - IN  EAX, IMM8
  {1, 0, 1, 0},

//E6 - OUT IMM8, AL
//E7 - OUT IMM8, EAX
  {1, 0, 1, 0},

//E8 - CALL REL32
//E9 - JMP REL32
  {X86IL_OS_32, 0, X86IL_OS_32, 0},

//EA - JMP 16:32
//EB - JMP REL8
  {X86IL_OS_32 +2, 0, 1, 0},

//EC - IN  AL,  DX
//ED - IN  EAX, DX
  {0, 0, 0, 0},

//EE - OUT DX, AL
//EF - OUT DX, EAX
  {0, 0, 0, 0},

//F0 - LOCK
//F1 - ICEBP
  {0, 0, 0, 0},

//F2 - REPNE, REPNZ
//F3 - REP, REPE, REPZ
  {0, 0, 0, 0},

//F4 - HLT
//F5 - CMC
  {0, 0, 0, 0},

//F6 - TEST/???/NOT/NEG/MUL/IMUL/DIV/IDIV  //take care: TEST has imm8,     the others not!
//F7 - TEST/???/NOT/NEG/MUL/IMUL/DIV/IDIV  //take care: TEST has imm16/32, the others not!
  {0, 1, 0, 1},

//F8 - CLC
//F9 - STC
  {0, 0, 0, 0},

//FA - CLI
//FB - STI
  {0, 0, 0, 0},

//FC - CLD
//FD - STD
  {0, 0, 0, 0},

//FE - INC/DEC/CALL/CALL/JMP/JMP/PUSH/???  R/M8
//FF - INC/DEC/CALL/CALL/JMP/JMP/PUSH/???  R/M32
  {0, 1, 0, 1},
//};

//===================================================================

//X86IL_INSTRUCTION_PAIR_DESCRIPTION X860FTable[0x100/2] = {

//00 /X - SLDT/LTR/LLDT/LTR/VERR/VERW/???/???      R/M32
//01 /X - SGDT/SIDT/LGDT/LIDT/SMSW/???/LMSW/INVLPG R/M32
  {0, 1, 0, 1},

//02 - LAR R32, R/M32
//03 - LSL R32, R/M32
  {0, 1, 0, 1},

//04 - ???
//05 - LOADALL286
  {0, 0, 0, 0},

//06 - CLTS
//07 - LOADALL386
  {0, 0, 0, 0},

//08 - INVD
//09 - WBINVD
  {0, 0, 0, 0},

//0A - ???
//0B - UD2
  {0, 0, 0, 0},

//0C - ???
//0D /X - PREFETCH/PREFETCHW/???/???/???/???/???/???
  {0, 0, 0, 1},

//0E - FEMMS
//0F - 3DNow!
  {0, 0, 0, 1},

//10 - MOVUPS XMM, X/M32
//11 - MOVUPS X/M32, XMM
  {0, 1, 0, 1},

//12 - MOVLPS XMM, X/M32
//13 - MOVLPS X/M32, XMM
  {0, 1, 0, 1},

//14 - UNPCKLPS XMM, X/M32
//15 - UNPCKHPS XMM, X/M32
  {0, 1, 0, 1},

//16 - MOVHPS XMM, X/M32
//17 - MOVHPS X/M32, XMM
  {0, 1, 0, 1},

//18 /X - PREFETCHNTA/PREFETCHT0/PREFETCHT1/PREFETCHT2/???/???/???/??? R/M32
//19 - ???
  {0, 1, 0, 0},

//1A - ???
//1B - ???
  {0, 0, 0, 0},

//1C - ???
//1D - ???
  {0, 0, 0, 0},

//1E - ???
//1F - ???
  {0, 0, 0, 0},

//20 - MOV R32, CRX
//21 - MOV R32, DRX
  {1, 0, 1, 0},

//22 - MOV CRX, R32
//23 - MOV DRX, R32
  {1, 0, 1, 0},

//24 - MOV R32, TRX
//25 - ???
  {1, 0, 1, 0},

//26 - MOV TRX, R32
//27 - ???
  {1, 0, 1, 0},

//28 - MOVAPS XMM, X/M32
//29 - MOVAPS X/M32, XMM
  {0, 1, 0, 1},

//2A - CVTPI2PS XMM, X/M32
//2B - MOVNTPS X/M32, XMM
  {0, 1, 0, 1},

//2C - CVTTPS2PI XMM, X/M32
//2D - CVTPS2PI XMM, X/M32
  {0, 1, 0, 1},

//2E - UCOMISS XMM, X/M32
//2F - COMISS XMM, X/M32
  {0, 1, 0, 1},

//30 - WRMSR
//31 - RDTSC
  {0, 0, 0, 0},

//32 - RDMSR
//33 - RDPMC
  {0, 0, 0, 0},

//34 - SYSENTER
//35 - SYSEXIT
  {0, 0, 0, 0},

//36 - ???
//37 - ???
  {0, 0, 0, 0},

//38 - ???
//39 - ???
  {0, 0, 0, 0},

//3A - ???
//3B - ???
  {0, 0, 0, 0},

//3C - ???
//3D - ???
  {0, 0, 0, 0},

//3E - ???
//3F - ???
  {0, 0, 0, 0},

//40 - CMOVO      R32, R/M32
//41 - CMOVNO     R32, R/M32
  {0, 1, 0, 1},

//42 - CMOVC/CMOVB/CMOVNAE R32, R/M32
//43 - CMOVNC/CMOVNB/CMOVAE R32, R/M32
  {0, 1, 0, 1},

//44 - CMOVE/CMOVZ R32, R/M32
//45 - CMOVNE/CMOVNZ R32, R/M32
  {0, 1, 0, 1},

//46 - CMOVBE/CMOVNA R32, R/M32
//47 - CMOVA/CMOVNBE R32, R/M32
  {0, 1, 0, 1},

//48 - CMOVS      R32, R/M32
//49 - CMOVS     R32, R/M32
  {0, 1, 0, 1},

//4A - CMOVP/CMOVPE  R32, R/M32
//4B - CMOVNP/CMOVPO R32, R/M32
  {0, 1, 0, 1},

//4C - CMOVL/CMOVNGE R32, R/M32
//4D - CMOVGE/CMOVNL R32, R/M32
  {0, 1, 0, 1},

//4E - CMOVNG/CMOVLE R32, R/M32
//4F - CMOVG/CMOVNLE R32, R/M32
  {0, 1, 0, 1},

//50 - ???
//51 - SQRTPS XMM, X/M32
  {0, 0, 0, 1},

//52 - RSQRTPS XMM, X/M32
//53 - RCPPS XMM, X/M32
  {0, 1, 0, 1},

//54 - ANDPS XMM, X/M32
//55 - ANDNPS XMM, X/M32
  {0, 1, 0, 1},

//56 - ORPS XMM, X/M32
//57 - XORPS XMM, X/M32
  {0, 1, 0, 1},

//58 - ADDPS XMM, X/M32
//59 - MULPS XMM, X/M32
  {0, 1, 0, 1},

//5A - CVTPS2PD XMM, X/M32
//5B - CVTDQ2PS XMM, X/M32
  {0, 1, 0, 1},

//5C - SUBPS XMM, X/M32
//5D - MINPS XMM, X/M32
  {0, 1, 0, 1},

//5E - DIVPS XMM, X/M32
//5F - MAXPS XMM, X/M32
  {0, 1, 0, 1},

//60 - PUNPCKLBW XMM, X/M32
//61 - PUNPCKLWD XMM, X/M32
  {0, 1, 0, 1},

//62 - PUNPCKLDQ XMM, X/M32
//63 - PACKSSWB XMM, X/M32
  {0, 1, 0, 1},

//64 - PCMPGTB XMM, X/M32
//65 - PCMPGTW XMM, X/M32
  {0, 1, 0, 1},

//66 - PCMPGTD XMM, X/M32
//67 - PACKUSWB XMM, X/M32
  {0, 1, 0, 1},

//68 - PUNPCKHBW XMM, X/M32
//69 - PUNPCKHWD XMM, X/M32
  {0, 1, 0, 1},

//6A - PUNPCKHDQ XMM, X/M32
//6B - PACKSSDW XMM, X/M32
  {0, 1, 0, 1},

//6C - ???
//6D - ???
  {0, 0, 0, 0},

//6E - MOVD XMM, X/M32
//6F - MOVQ XMM, X/M32
  {0, 1, 0, 1},

//70 - PSHUFW XMM, X/M32, IMM8
//71 - ???/???/PSRLW/???/PSRAW/???/PSLLW/??? XMM, IMM8
  {1, 1, 1, 1},

//72 - ???/???/PSRLD/???/PSRAD/???/PSLLD/??? XMM, IMM8
//73 - ???/???/PSRLQ/PSRLDQ/???/???/PSLLQ/PSLLDQ XMM, IMM8
  {1, 1, 1, 1},

//74 - PCMPEQB XMM, X/M32
//75 - PCMPEQW XMM, X/M32
  {0, 1, 0, 1},

//76 - PCMPEQW XMM, X/M32
//77 - EMMS
  {0, 1, 0, 0},

//78 - ???
//79 - ???
  {0, 0, 0, 0},

//7A - ???
//7B - ???
  {0, 0, 0, 0},

//7C - ???
//7D - ???
  {0, 0, 0, 0},

//7E - MOVD X/M32, XMM
//7F - MOVQ X/M32, XMM
  {0, 1, 0, 1},

//80 - JO      REL32
//81 - JNO     REL32
  {X86IL_OS_32, 0, X86IL_OS_32, 0},

//82 - JC/JB/JNAE REL32
//83 - JNC/JNB/JAE REL32
  {X86IL_OS_32, 0, X86IL_OS_32, 0},

//84 - JE/JZ   REL32
//85 - JNE/JNZ REL32
  {X86IL_OS_32, 0, X86IL_OS_32, 0},

//86 - JBE/JNA REL32
//87 - JA/JNBE REL32
  {X86IL_OS_32, 0, X86IL_OS_32, 0},

//88 - JS      REL32
//89 - JNS     REL32
  {X86IL_OS_32, 0, X86IL_OS_32, 0},

//8A - JP/JPE  REL32
//8B - JNP/JPO REL32
  {X86IL_OS_32, 0, X86IL_OS_32, 0},

//8C - JL/JNGE REL32
//8D - JGE/JNL REL32
  {X86IL_OS_32, 0, X86IL_OS_32, 0},

//8E - JNG/JLE REL32
//8F - JG/JNLE REL32
  {X86IL_OS_32, 0, X86IL_OS_32, 0},

//90 - SETO      R/M8
//91 - SETNO     R/M8
  {0, 1, 0, 1},

//92 - SETC/SETB/SETNAE R/M8
//93 - SETNC/SETNB/SETAE R/M8
  {0, 1, 0, 1},

//94 - SETE/SETZ R/M8
//95 - SETNE/SETNZ R/M8
  {0, 1, 0, 1},

//96 - SETBE/SETNA R/M8
//97 - SETA/SETNBE R/M8
  {0, 1, 0, 1},

//98 - SETS      R/M8
//99 - SETNS     R/M8
  {0, 1, 0, 1},

//9A - SETP/SETPE  R/M8
//9B - SETNP/SETPO R/M8
  {0, 1, 0, 1},

//9C - SETL/SETNGE R/M8
//9D - SETGE/SETNL R/M8
  {0, 1, 0, 1},

//9E - SETNG/SETLE R/M8
//9F - SETG/SETNLE R/M8
  {0, 1, 0, 1},

//A0 - PUSH FS
//A1 - POP FS
  {0, 0, 0, 0},

//A2 - CPUID
//A3 - BT R/M32, R32
  {0, 0, 0, 1},

//A4 - SHLD R/M32, R32, IMM8
//A5 - SHLD R/M32, R32, CL
  {1, 1, 0, 1},

//A6 - ???
//A7 - ???
  {0, 0, 0, 0},

//A8 - PUSH GS
//A9 - POP GS
  {0, 0, 0, 0},

//AA - RSM
//AB - BTS R/M32, R32
  {0, 0, 0, 1},

//AC - SHRD R/M32, R32, IMM8
//AD - SHRD R/M32, R32, CL
  {1, 1, 0, 1},

//AE /X - FXSAVE/FXRSTOR/LDMXCSR/STMXCSR/???/???/???/CLFLUSH  R/M32 //LFENCE/MFENCE
//AF - IMUL R32, R/M32
  {0, 1, 0, 1},

//B0 - CMPXCHG R/M8, R8
//B1 - CMPXCHG R/M32, R32
  {0, 1, 0, 1},

//B2 - LSS R32, R/M32
//B3 - BTR R/M32, R32
  {0, 1, 0, 1},

//B4 - LFS R32, R/M32
//B5 - LGS R32, R/M32
  {0, 1, 0, 1},

//B6 - MOVZX R32, R/M8
//B7 - MOVZX R32, R/M16
  {0, 1, 0, 1},

//B8 - ???
//B9 - ???
  {0, 0, 0, 0},

//BA /X - ???/???/???/???/BT/BTS/BTR/BTC R/M32, IMM8
//BB - BTC R/M32, R32
  {1, 1, 0, 1},

//BC - BSF   R32, R/M32
//BD - BSR   R32, R/M32
  {0, 1, 0, 1},

//BE - MOVSX R32, R/M8
//BF - MOVSX R32, R/M16
  {0, 1, 0, 1},

//C0 - XADD R/M8, R8
//C1 - XADD R/M32, R32
  {0, 1, 0, 1},

//C2 - CMPEQPS R/M32, R32
//C3 - MOVNTI R/M32, R32
  {0, 1, 0, 1},

//C4 - PINSRW R/M32, R32, IMM8
//C5 - PEXTRW R/M32, R32, IMM8
  {1, 1, 1, 1},

//C6 - SHUFPS R/M32, R32, IMM8
//C7 - CMPXCHG8B R/M64
  {1, 1, 0, 1},

//C8 - BSWAP   EAX
//C9 - BSWAP   ECX
  {0, 0, 0, 0},

//CA - BSWAP   EDX
//CB - BSWAP   EBX
  {0, 0, 0, 0},

//CC - BSWAP   ESP
//CD - BSWAP   EBP
  {0, 0, 0, 0},

//CE - BSWAP   ESI
//CF - BSWAP   EDI
  {0, 0, 0, 0},

//D0 - ???
//D1 - PSRLW R/M32
  {0, 0, 0, 1},

//D2 - PSRLD R/M32
//D3 - PSRLQ R/M32
  {0, 1, 0, 1},

//D4 - PADDQ R/M32
//D5 - PMULLW R/M32
  {0, 1, 0, 1},

//D6 - ???
//D7 - PMOVMSKB R/M32
  {0, 0, 0, 1},

//D8 - PSUBUSB R/M32
//D9 - PSUBUSW R/M32
  {0, 1, 0, 1},

//DA - PMINUB R/M32
//DB - PAND R/M32
  {0, 1, 0, 1},

//DC - PADDUSB R/M32
//DD - PADDUSW R/M32
  {0, 1, 0, 1},

//DE - PMAXUB R/M32
//DF - PANDN R/M32
  {0, 1, 0, 1},

//E0 - PAVGB R/M32
//E1 - PSRAW R/M32
  {0, 1, 0, 1},

//E2 - PSRAD R/M32
//E3 - PAVGW R/M32
  {0, 1, 0, 1},

//E4 - PMULHUW R/M32
//E5 - PMULHW R/M32
  {0, 1, 0, 1},

//E6 - ???
//E7 - MOVNTQ,MOVNTDQ R/M32
  {0, 0, 0, 1},

//E8 - PSUBSB R/M32
//E9 - PSUBSW R/M32
  {0, 1, 0, 1},

//EA - PMINSW R/M32
//EB - POR R/M32
  {0, 1, 0, 1},

//EC - PADDSB R/M32
//ED - PADDSW R/M32
  {0, 1, 0, 1},

//EE - PMAXSW R/M32
//EF - PXOR R/M32
  {0, 1, 0, 1},

//F0 - ???
//F1 - PSLLW R/M32
  {0, 0, 0, 1},

//F2 - PSLLD R/M32
//F3 - PSLLQ R/M32
  {0, 1, 0, 1},

//F4 - PMULUDQ R/M32
//F5 - PMADDWD R/M32
  {0, 1, 0, 1},

//F6 - PSADBW R/M32
//F7 - PMASKMOVQ R/M32
  {0, 1, 0, 1},

//F8 - PSUBB R/M32
//F9 - PSUBW R/M32
  {0, 1, 0, 1},

//FA - PSUBD R/M32
//FB - PSUBQ R/M32
  {0, 1, 0, 1},

//FC - PADDB R/M32
//FD - PADDW R/M32
  {0, 1, 0, 1},

//FE - PADDD R/M32
//FF - ???
  {0, 1, 0, 0}
};

//===================================================================

#define X86IL_PREFIX_COUNT 11
const unsigned char X86IL_Prefixes[X86IL_PREFIX_COUNT] = {
  0x26, 0x2E, 0x36, 0x3E,
  0x64, 0x65, 0x66, 0x67,
  0xF0, 0xF2, 0xF3
};

//===================================================================
int
  X86IL(int Bits,
        const unsigned char *pOriI,
        unsigned char *pAnaI,
        int *pnPfx,
        int *pModRM,
        int *pISize
 ) {

  int DefOpdSize;  // 4 unsigned char for 32bit,  2 unsigned char for 16bit
  int FixOpdSize;  // 0 unsigned char for 32bit, -2 unsigned char for 16bit because tables are 32bit
  int AddressMode; // 0 - 32bit, 1 - 16bit table
  int X86Idx;
  unsigned char OpCode;
  unsigned char ModRM;
  int ModRMAnd7;
  int IsSIB;
  #define i ModRM

  union {
    unsigned char b;
    X86IL_INSTRUCTION_PAIR_DESCRIPTION InstrDesc;
  } u;

//Init------------------------------------------------------------------------

  int OSChanged   = 0;
  int AMChanged   = 0;
  int ILength     = 0;  
  int OpdSize     = 0;
  int ModRMLength = 0;
  char Rex = 0;

  *pModRM = 0;

  if(Bits > 0) {
    DefOpdSize  = +X86IL_OS_16;
    FixOpdSize  = -2;
    AddressMode = +1;
  }
  else {
    DefOpdSize  = +X86IL_OS_32;
    FixOpdSize  = +0;
    AddressMode = +0;
  }

//Prefix----------------------------------------------------------------------

  while(ILength < 16) {
    pAnaI[ILength] = OpCode = pOriI[ILength];
    ILength++;

    if(Bits < 0) {
      if((OpCode >= 0x40) && (OpCode <= 0x4F)) {
        Rex = OpCode;
        continue;
      }
    }

    for(i = 0; (i < X86IL_PREFIX_COUNT) && (X86IL_Prefixes[i] != OpCode); i++);
    if(i == X86IL_PREFIX_COUNT)
      break;
    #undef i

    Rex = 0;

    if(OpCode == 0x66) {
      OSChanged = 1;
    }

    if(OpCode == 0x67) {
      AMChanged = 1;
    }
  }  

  if(ILength >= 16) {
    return(ILength);
  }

  if((Bits >= 0) || !(Rex & 8)) {
    if(OSChanged) {
      if(FixOpdSize == 0) {
        DefOpdSize = X86IL_OS_16;
        FixOpdSize = -2;
      }
      else {
        DefOpdSize = X86IL_OS_32;
        FixOpdSize = +0;
      }
    }
  }

  if((Bits >= 0) && AMChanged) {
    AddressMode ^= 1;
  }

//Instruction-----------------------------------------------------------------

  *pnPfx = ILength -1;
 
  if(OpCode == 0xF) {
    pAnaI[ILength] = OpCode = pOriI[ILength];
    ILength++;
    X86Idx = (OpCode >> 1) + (0x100 >> 1);
  }
  else {
    X86Idx = (OpCode >> 1) + (0x000 >> 1);
  }
  u.InstrDesc = X86ILTable[X86Idx];
  u.b >>= (OpCode & 1) << 2;

//ModRM, SIB------------------------------------------------------------------
    
  if(u.InstrDesc.IsModRM) {
    ModRMLength++;
    pAnaI[ILength] = ModRM = pOriI[ILength];
    *pModRM = ILength;
    ILength++;
    ModRMAnd7 = ModRM & 7;
    IsSIB = ModRMAnd7 == 4;
    switch(ModRM >> 6) {
      case 0  : if(AddressMode == 0) { //32bit
                  if(IsSIB) {
                    if((pOriI[ILength] & 7) == 5)
                      ModRMLength += X86IL_OS_32;
                    ModRMLength++;
                  }
                  else {
                    if(ModRMAnd7 == 5)
                      ModRMLength += X86IL_OS_32;
                  }
                }
                else { //16bit
                  if(ModRMAnd7 == 6)
                    ModRMLength += X86IL_OS_16;
                } 
                break;

      case 1  : if((AddressMode == 0) && (IsSIB)) {
                  ModRMLength++;
                }
                ModRMLength++;
                break;

      case 2  : if(AddressMode == 0) { //32bit
                  if(IsSIB) {
                    ModRMLength++;
                  } 
                  ModRMLength += X86IL_OS_32;
                }
                else { //16bit
                  ModRMLength += X86IL_OS_16;
                }
                break;

      default : ;
    }
    while(--ModRMLength) {
      pAnaI[ILength] = pOriI[ILength];
      ILength++;
    }

    if(( (OpCode & 0xFE) == 0xF6) &&
         (X86Idx         <= 0x7F) &&
         ((ModRM & 0x38) == 0x00) ) { // fix F6, F7 - TEST R/M, IMM
      OpdSize += (OpCode & 1) ? DefOpdSize : 1;
    }
  }

//Operand-----------------------------------------------------------------------

  if(u.InstrDesc.OpdSize) {
    switch(u.InstrDesc.OpdSize) {
      case X86IL_OS_32 +0  : OpdSize += X86IL_OS_32 +0 +FixOpdSize; break;
      case X86IL_OS_32 +1  : OpdSize += (((Bits < 0) && AMChanged) || AddressMode ? X86IL_OS_16 : X86IL_OS_32)*(Bits < 0 ? 2 : 1); break;
      case X86IL_OS_32 +2  : OpdSize += X86IL_OS_32 +2 +FixOpdSize; break;
      case X86IL_OS_32 +3  : OpdSize += (Rex & 8) ? X86IL_OS_32*2 : (X86IL_OS_32 +FixOpdSize); break;
      default              : OpdSize += u.InstrDesc.OpdSize;
    }
  }
  *pISize = OpdSize;

  if(OpCode == 0xF) { //3DNow!
    OpdSize++;
  }

  while(OpdSize--) {
    pAnaI[ILength] = pOriI[ILength];
    ILength++;
  }

  return(ILength);
}

//===================================================================
