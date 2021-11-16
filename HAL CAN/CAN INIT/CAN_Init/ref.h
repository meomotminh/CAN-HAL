/** @addtogroup FDCAN_Exported_Functions_Group6
  * @{
  * /
/* Callback functions *********************************************************/
void HAL_FDCAN_ClockCalibrationCallback(FDCAN_HandleTypeDef *hfdcan, uint32_t ClkCalibrationITs);
void HAL_FDCAN_TxEventFifoCallback(FDCAN_HandleTypeDef *hfdcan, uint32_t TxEventFifoITs);
void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo0ITs);
void HAL_FDCAN_RxFifo1Callback(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo1ITs);
void HAL_FDCAN_TxFifoEmptyCallback(FDCAN_HandleTypeDef *hfdcan);
void HAL_FDCAN_TxBufferCompleteCallback(FDCAN_HandleTypeDef *hfdcan, uint32_t BufferIndexes);
void HAL_FDCAN_TxBufferAbortCallback(FDCAN_HandleTypeDef *hfdcan, uint32_t BufferIndexes);
void HAL_FDCAN_RxBufferNewMessageCallback(FDCAN_HandleTypeDef *hfdcan);
void HAL_FDCAN_HighPriorityMessageCallback(FDCAN_HandleTypeDef *hfdcan);
void HAL_FDCAN_TimestampWraparoundCallback(FDCAN_HandleTypeDef *hfdcan);
void HAL_FDCAN_TimeoutOccurredCallback(FDCAN_HandleTypeDef *hfdcan);
void HAL_FDCAN_ErrorCallback(FDCAN_HandleTypeDef *hfdcan);
void HAL_FDCAN_ErrorStatusCallback(FDCAN_HandleTypeDef *hfdcan, uint32_t ErrorStatusITs);
void HAL_FDCAN_TT_ScheduleSyncCallback(FDCAN_HandleTypeDef *hfdcan, uint32_t TTSchedSyncITs);
void HAL_FDCAN_TT_TimeMarkCallback(FDCAN_HandleTypeDef *hfdcan, uint32_t TTTimeMarkITs);
void HAL_FDCAN_TT_StopWatchCallback(FDCAN_HandleTypeDef *hfdcan, uint32_t SWTime, uint32_t SWCycleCount);
void HAL_FDCAN_TT_GlobalTimeCallback(FDCAN_HandleTypeDef *hfdcan, uint32_t TTGlobTimeITs);
/**
  * @}
  */

// CAN_Init elf file

ELF Header:
  Magic:   7f 45 4c 46 01 01 01 00 00 00 00 00 00 00 00 00 
  Class:                             ELF32
  Data:                              2's complement, little endian
  Version:                           1 (current)
  OS/ABI:                            UNIX - System V
  ABI Version:                       0
  Type:                              EXEC (Executable file)
  Machine:                           ARM
  Version:                           0x1
  Entry point address:               0x805f245
  Start of program headers:          52 (bytes into file)
  Start of section headers:          8279492 (bytes into file)
  Flags:                             0x5000200, Version5 EABI, soft-float ABI
  Size of this header:               52 (bytes)
  Size of program headers:           32 (bytes)
  Number of program headers:         7
  Size of section headers:           40 (bytes)
  Number of section headers:         27
  Section header string table index: 26

Section Headers:
  [Nr] Name              Type            Addr     Off    Size   ES Flg Lk Inf Al
  [ 0]                   NULL            00000000 000000 000000 00      0   0  0
  [ 1] .text             PROGBITS        08040000 000140 033450 00  AX  0   0 64
  [ 2] .ARM.extab        PROGBITS        08073450 033590 000abc 00   A  0   0  4
  [ 3] .ARM.exidx        ARM_EXIDX       08073f0c 03404c 000c88 00  AL  1   0  4
  [ 4] .data             PROGBITS        24000000 034cd8 001aa0 00  WA  0   0  8
  [ 5] .uninitialized    PROGBITS        24001aa0 036778 000000 00   W  0   0  1
  [ 6] .bss              NOBITS          24001aa0 036778 010428 00  WA  0   0  8
  [ 7] .openamp_section  NOBITS          38000000 036778 00008c 00  WA  0   0  4
  [ 8] .pdm_section      NOBITS          3800008c 036778 00fb74 00  WA  0   0  1
  [ 9] .heap             PROGBITS        24011ec8 036778 06dd38 00   W  0   0  1
  [10] .lwip_sec         NOBITS          30000000 036778 044000 00  WA  0   0  4
  [11] .ARM.attributes   ARM_ATTRIBUTES  00000000 0a44b0 00002c 00      0   0  1
  [12] .comment          PROGBITS        00000000 0a44dc 00009c 01  MS  0   0  1
  [13] .debug_info       PROGBITS        00000000 0a4578 1bffa7 00      0   0  1
  [14] .debug_abbrev     PROGBITS        00000000 26451f 01c0d9 00      0   0  1
  [15] .debug_loc        PROGBITS        00000000 2805f8 038c3b 00      0   0  1
  [16] .debug_aranges    PROGBITS        00000000 2b9233 002878 00      0   0  1
  [17] .debug_ranges     PROGBITS        00000000 2bbaab 00ada0 00      0   0  1
  [18] .debug_macro      PROGBITS        00000000 2c684b 094a61 00      0   0  1
  [19] .debug_line       PROGBITS        00000000 35b2ac 0741a4 00      0   0  1
  [20] .debug_str        PROGBITS        00000000 3cf450 3cc345 01  MS  0   0  1
  [21] .debug_frame      PROGBITS        00000000 79b798 01446c 00      0   0  4
  [22] .stab             PROGBITS        00000000 7afc04 00003c 0c     23   0  4
  [23] .stabstr          STRTAB          00000000 7afc40 000076 00      0   0  1
  [24] .symtab           SYMTAB          00000000 7afcb8 01ec40 10     25 5518  4
  [25] .strtab           STRTAB          00000000 7ce8f8 016baf 00      0   0  1
  [26] .shstrtab         STRTAB          00000000 7e54a7 00011a 00      0   0  1
Key to Flags:
  W (write), A (alloc), X (execute), M (merge), S (strings), I (info),
  L (link order), O (extra OS processing required), G (group), T (TLS),
  C (compressed), x (unknown), o (OS specific), E (exclude),
  y (noread), p (processor specific)

There are no section groups in this file.

Program Headers:
  Type           Offset   VirtAddr   PhysAddr   FileSiz MemSiz  Flg Align
  EXIDX          0x03404c 0x08073f0c 0x08073f0c 0x00c88 0x00c88 R   0x4
  LOAD           0x000140 0x08040000 0x08040000 0x34b94 0x34b94 R E 0x40
  LOAD           0x034cd8 0x24000000 0x08074b94 0x01aa0 0x01aa0 RW  0x8
  LOAD           0x036778 0x30000000 0x08074b94 0x00000 0x44000 RW  0x4
  LOAD           0x036778 0x38000000 0x08074b94 0x00000 0x0008c RW  0x4
  LOAD           0x036778 0x3800008c 0x08074b94 0x00000 0x0fb74 RW  0x1
  LOAD           0x036778 0x24001aa0 0x08076638 0x00000 0x10428 RW  0x8

 Section to Segment mapping:
  Segment Sections...
   00     .ARM.exidx 
   01     .text .ARM.extab .ARM.exidx 
   02     .data 
   03     .lwip_sec 
   04     .openamp_section 
   05     .pdm_section 
   06     .bss 

There is no dynamic section in this file.

There are no relocations in this file.

Unwind table index '.ARM.exidx' at offset 0x3404c contains 401 entries:

0x80402d8 <_start>: 0x1 [cantunwind]

0x8040364 <_ZN14clmdep_msgpack2v17sbufferC2Ej>: 0x80a8b0b0
  Compact model index: 0
  0xa8      pop {r4, r14}
  0xb0      finish
  0xb0      finish

0x80403a0 <HAL_RTC_AlarmAEventCallback>: 0x80b108a9
  Compact model index: 0
  0xb1 0x08 pop {r3}
  0xa9      pop {r4, r5, r14}

0x80403dc <_Z15HAL_RTC_MspInitv>: @0x8073450
  Compact model index: 1
  0x04      vsp = vsp + 20
  0x3f      vsp = vsp + 256
  0x84 0x00 pop {r14}
  0xb0      finish
  0xb0      finish

0x80404a0 <_Z13my_can_filterP5can_smm9CANFormatlP8LOITRUCK>: 0x800aadb0
  Compact model index: 0
  0x0a      vsp = vsp + 44
  0xad      pop {r4, r5, r6, r7, r8, r9, r14}
  0xb0      finish

0x80405cc <HAL_FDCAN_TxBufferCompleteCallback>: 0x1 [cantunwind]

0x8040604 <_ZNSt10unique_ptrIN14clmdep_msgpack2v14zoneESt14default_deleteIS2_EED2Ev>: @0x807345c
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0xaa      pop {r4, r5, r6, r14}
  0xb0      finish
  0xb0      finish

0x804063c <_ZN14clmdep_msgpack2v16packerINS0_7sbufferEE13append_bufferEPKcj>: 0x80b108ab
  Compact model index: 0
  0xb1 0x08 pop {r3}
  0xab      pop {r4, r5, r6, r7, r14}

0x80406ac <_ZN14clmdep_msgpack2v16packerINS0_7sbufferEE8pack_strEm>: 0x8001a8b0
  Compact model index: 0
  0x01      vsp = vsp + 8
  0xa8      pop {r4, r14}
  0xb0      finish

0x8040706 <_ZN14clmdep_msgpack2v16packerINS0_7sbufferEE14pack_imp_int32IiEEvT_>: 0x80028400
  Compact model index: 0
  0x02      vsp = vsp + 12
  0x84 0x00 pop {r14}

0x804077e <_ZN14clmdep_msgpack2v14packINS0_7sbufferESt5tupleIJhiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES3_IJiiEEEEEEvRT_RKT0_>: 0x8001aab0
  Compact model index: 0
  0x01      vsp = vsp + 8
  0xaa      pop {r4, r5, r6, r14}
  0xb0      finish

0x80407fa <_ZN7arduino3RPC4callIJiiEEEN14clmdep_msgpack2v113object_handleERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEDpT_>: @0x8073468
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0x10      vsp = vsp + 68
  0xad      pop {r4, r5, r6, r7, r8, r9, r14}
  0xb0      finish

0x8040908 <loop>: @0x807348c
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0x13      vsp = vsp + 80
  0xac      pop {r4, r5, r6, r7, r8, r14}
  0xb0      finish

0x8040d2c <_GLOBAL__sub_I_SerialUSB1>: 0x1 [cantunwind]

0x80410c4 <setup>: 0x8001a8b0
  Compact model index: 0
  0x01      vsp = vsp + 8
  0xa8      pop {r4, r14}
  0xb0      finish

0x8041214 <_Z8Set_FreqP5can_sPK12can_pinmap_ti>: 0x8034abb0
  Compact model index: 0
  0x34      vsp = vsp + 212
  0xab      pop {r4, r5, r6, r7, r14}
  0xb0      finish

0x8041354 <_Z11Set_CAN_PinP5can_s7PinNameS1_i>: 0x8005aeb0
  Compact model index: 0
  0x05      vsp = vsp + 24
  0xae      pop {r4, r5, r6, r7, r8, r9, r10, r14}
  0xb0      finish

0x80413bc <_Z17Trd_internal_initP5can_s>: 0x80a8b0b0
  Compact model index: 0
  0xa8      pop {r4, r14}
  0xb0      finish
  0xb0      finish

0x8041460 <_Z12my_can_writeP5can_sN4mbed10CANMessageEiP8LOITRUCK>: 0x80ac03b0
  Compact model index: 0
  0xac      pop {r4, r5, r6, r7, r8, r14}
  0x03      vsp = vsp + 16
  0xb0      finish

0x804154c <_Z11my_can_modeP5can_s7CanMode>: 0x80aab0b0
  Compact model index: 0
  0xaa      pop {r4, r5, r6, r14}
  0xb0      finish
  0xb0      finish

0x80415a0 <_GLOBAL__sub_I__Z8Set_FreqP5can_sPK12can_pinmap_ti>: 0x1 [cantunwind]

0x80415ec <_Z8RTC_InitP8LOITRUCK>: @0x80734c0
  Compact model index: 1
  0xb1 0x08 pop {r3}
  0x84 0x00 pop {r14}
  0xb0      finish
  0xb0      finish

0x8041634 <_Z18RTC_CalendarConfigP8LOITRUCK>: 0x8005a8b0
  Compact model index: 0
  0x05      vsp = vsp + 24
  0xa8      pop {r4, r14}
  0xb0      finish

0x8041668 <_Z15RTC_AlarmConfigP8LOITRUCK>: 0x8009a8b0
  Compact model index: 0
  0x09      vsp = vsp + 40
  0xa8      pop {r4, r14}
  0xb0      finish

0x80416bc <_GLOBAL__sub_I__Z8RTC_InitP8LOITRUCK>: 0x1 [cantunwind]

0x8041708 <_Z17write_SDO_to_SRAMP8LOITRUCK>: @0x80734cc
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0x97      vsp = r7
  0x0e      vsp = vsp + 60
  0xaf      pop {r4, r5, r6, r7, r8, r9, r10, r11, r14}

0x8041f70 <_Z15init_SDO_objectP8LOITRUCK>: 0x80a8b0b0
  Compact model index: 0
  0xa8      pop {r4, r14}
  0xb0      finish
  0xb0      finish

0x8041ffc <_Z22manipulate_SDO_on_SRAM11My_FunctioniP8LOITRUCK>: 0x80a803b0
  Compact model index: 0
  0xa8      pop {r4, r14}
  0x03      vsp = vsp + 16
  0xb0      finish

0x804202c <_GLOBAL__sub_I__Z17write_SDO_to_SRAMP8LOITRUCK>: 0x1 [cantunwind]

0x80421c4 <_Z14read_parameterP8LOITRUCK>: 0x80aab0b0
  Compact model index: 0
  0xaa      pop {r4, r5, r6, r14}
  0xb0      finish
  0xb0      finish

0x8042450 <_Z18append_Linked_ListPP3SDOS0_>: 0x1 [cantunwind]

0x8042488 <_Z19display_Linked_ListP8LOITRUCK>: 0x80b108ab
  Compact model index: 0
  0xb1 0x08 pop {r3}
  0xab      pop {r4, r5, r6, r7, r14}

0x8042510 <_Z13find_ScenarioP8LOITRUCK>: 0x1 [cantunwind]

0x80427f6 <_ZN7arduino21UsbDebugCommInterface8readableEv>: @0x80734f4
  Compact model index: 1
  0xb1 0x08 pop {r3}
  0x84 0x00 pop {r14}
  0xb0      finish
  0xb0      finish

0x804280a <_ZN7arduino21UsbDebugCommInterface9writeableEv>: 0x1 [cantunwind]

0x804280e <_ZN7arduino21UsbDebugCommInterface4readEv>: @0x8073500
  Compact model index: 1
  0xb1 0x08 pop {r3}
  0x84 0x00 pop {r14}
  0xb0      finish
  0xb0      finish

0x804281c <_ZN7arduino21UsbDebugCommInterface5writeEh>: 0x1 [cantunwind]

0x8042828 <displayMemFaultCauseToGdbConsole>: 0x80aab0b0
  Compact model index: 0
  0xaa      pop {r4, r5, r6, r14}
  0xb0      finish
  0xb0      finish

0x8042968 <displayUsageFaultCauseToGdbConsole>: 0x80a8b0b0
  Compact model index: 0
  0xa8      pop {r4, r14}
  0xb0      finish
  0xb0      finish

0x80429e8 <_ZL17readThreadContextP10MriContextPmPv>: 0x80aeb0b0
  Compact model index: 0
  0xae      pop {r4, r5, r6, r7, r8, r9, r10, r14}
  0xb0      finish
  0xb0      finish

0x8042a98 <_ZL31wakeMriMainToDebugCurrentThreadv>: @0x807350c
  Compact model index: 1
  0xb1 0x08 pop {r3}
  0x84 0x00 pop {r14}
  0xb0      finish
  0xb0      finish

0x8042ac4 <_ZN7arduino21UsbDebugCommInterfaceD0Ev>: 0x1 [cantunwind]

0x8042b70 <sendRegisterForTResponse>: 0x8001a8b0
  Compact model index: 0
  0x01      vsp = vsp + 8
  0xa8      pop {r4, r14}
  0xb0      finish

0x8042bb8 <findDWTComparator>: 0x1 [cantunwind]

0x8042c64 <_ZL24justEnteredSetupCallbackPv>: 0x80a8b0b0
  Compact model index: 0
  0xa8      pop {r4, r14}
  0xb0      finish
  0xb0      finish

0x8042ca8 <enableFPBBreakpoint.part.1>: 0x1 [cantunwind]

0x8042d08 <_ZL13serialISRHookv>: 0x80a8b0b0
  Compact model index: 0
  0xa8      pop {r4, r14}
  0xb0      finish
  0xb0      finish

0x8042d68 <_ZN4mbed6detail12CallbackBase7destroyEv>: 0x1 [cantunwind]

0x8042d74 <_ZN7arduino21UsbDebugCommInterface6attachEPFvvE>: @0x8073518
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0x03      vsp = vsp + 16
  0xac      pop {r4, r5, r6, r7, r8, r14}
  0xb0      finish

0x8042df4 <mriCortexMSetPriority>: 0x1 [cantunwind]

0x8042e7c <mriPlatform_DisplayFaultCauseToGdbConsole>: 0x80a8b0b0
  Compact model index: 0
  0xa8      pop {r4, r14}
  0xb0      finish
  0xb0      finish

0x8042f04 <mriPlatform_LeavingDebugger>: 0x1 [cantunwind]

0x8042f7c <mriPlatform_WasProgramCounterModifiedByUser>: @0x8073534
  Compact model index: 1
  0xb1 0x08 pop {r3}
  0x84 0x00 pop {r14}
  0xb0      finish
  0xb0      finish

0x8042f94 <mriPlatform_WasMemoryFaultEncountered>: 0x1 [cantunwind]

0x8042fb0 <throwingMemRead16>: @0x8073540
  Compact model index: 1
  0xb1 0x08 pop {r3}
  0x84 0x00 pop {r14}
  0xb0      finish
  0xb0      finish

0x8042fcc <mriPlatform_AdvanceProgramCounterToNextInstruction>: 0x80b108a9
  Compact model index: 0
  0xb1 0x08 pop {r3}
  0xa9      pop {r4, r5, r14}

0x8043048 <mriPlatform_DetermineCauseOfException>: 0x80aab0b0
  Compact model index: 0
  0xaa      pop {r4, r5, r6, r14}
  0xb0      finish
  0xb0      finish

0x8043124 <mriPlatform_WriteTResponseRegistersToBuffer>: 0x80b108a9
  Compact model index: 0
  0xb1 0x08 pop {r3}
  0xa9      pop {r4, r5, r14}

0x804317c <mriPlatform_SetHardwareBreakpointOfGdbKind>: 0x1 [cantunwind]

0x80431c8 <mriPlatform_SetHardwareBreakpoint>: 0x80b108a9
  Compact model index: 0
  0xb1 0x08 pop {r3}
  0xa9      pop {r4, r5, r14}

0x8043204 <mriPlatform_ClearHardwareBreakpointOfGdbKind>: 0x1 [cantunwind]

0x8043240 <mriPlatform_ClearHardwareBreakpoint>: 0x80b108a9
  Compact model index: 0
  0xb1 0x08 pop {r3}
  0xa9      pop {r4, r5, r14}

0x8043414 <mriPlatform_SetHardwareWatchpoint>: 0x1 [cantunwind]

0x804351c <_ZN10ThreadList8allocateEm>: 0x80b108a9
  Compact model index: 0
  0xb1 0x08 pop {r3}
  0xa9      pop {r4, r5, r14}

0x8043540 <_ZN10ThreadList13resumeThreadsEv>: 0x8002afb0
  Compact model index: 0
  0x02      vsp = vsp + 12
  0xaf      pop {r4, r5, r6, r7, r8, r9, r10, r11, r14}
  0xb0      finish

0x80435b4 <_ZN10ThreadList12findThreadIdEPv>: 0x8003a8b0
  Compact model index: 0
  0x03      vsp = vsp + 16
  0xa8      pop {r4, r14}
  0xb0      finish

0x80435d8 <_ZL7mriMainPv>: 0x8002afb0
  Compact model index: 0
  0x02      vsp = vsp + 12
  0xaf      pop {r4, r5, r6, r7, r8, r9, r10, r11, r14}
  0xb0      finish

0x8043868 <_ZN7arduino11ThreadDebugC2EPNS_18DebugCommInterfaceEbm>: 0x80b108ab
  Compact model index: 0
  0xb1 0x08 pop {r3}
  0xab      pop {r4, r5, r6, r7, r14}

0x8043938 <_ZN7arduino11ThreadDebugD2Ev>: 0x1 [cantunwind]

0x8043974 <mriPlatform_Init>: 0x80a8b0b0
  Compact model index: 0
  0xa8      pop {r4, r14}
  0xb0      finish
  0xb0      finish

0x8043a44 <mriPlatform_CommHasReceiveData>: @0x807354c
  Compact model index: 1
  0xb1 0x08 pop {r3}
  0x84 0x00 pop {r14}
  0xb0      finish
  0xb0      finish

0x8043a58 <mriPlatform_CommHasTransmitCompleted>: @0x8073558
  Compact model index: 1
  0xb1 0x08 pop {r3}
  0x84 0x00 pop {r14}
  0xb0      finish
  0xb0      finish

0x8043a6c <mriPlatform_CommReceiveChar>: 0x80a8b0b0
  Compact model index: 0
  0xa8      pop {r4, r14}
  0xb0      finish
  0xb0      finish

0x8043a8c <mriPlatform_CommSendChar>: 0x1 [cantunwind]

0x8043b00 <mriPlatform_RtosIsThreadActive>: @0x8073564
  Compact model index: 1
  0xb1 0x08 pop {r3}
  0x84 0x00 pop {r14}
  0xb0      finish
  0xb0      finish

0x8043b18 <mriPlatform_RtosGetExtraThreadInfo>: 0x8001a8b0
  Compact model index: 0
  0x01      vsp = vsp + 8
  0xa8      pop {r4, r14}
  0xb0      finish

0x8043c00 <mriPlatform_RtosGetThreadContext>: 0x80a8b0b0
  Compact model index: 0
  0xa8      pop {r4, r14}
  0xb0      finish
  0xb0      finish

0x8043c34 <mriPlatform_RtosIsSetThreadStateSupported>: 0x1 [cantunwind]

0x8043c38 <mriPlatform_RtosSetThreadState>: 0x80b108a9
  Compact model index: 0
  0xb1 0x08 pop {r3}
  0xa9      pop {r4, r5, r14}

0x8043c94 <mriPlatform_RtosRestorePrevThreadState>: 0x80acb0b0
  Compact model index: 0
  0xac      pop {r4, r5, r6, r7, r8, r14}
  0xb0      finish
  0xb0      finish

0x8043ce4 <mriDebugMonitorHandler>: 0x80a8b0b0
  Compact model index: 0
  0xa8      pop {r4, r14}
  0xb0      finish
  0xb0      finish

0x8043d88 <mriFaultHandler>: 0x80b108ab
  Compact model index: 0
  0xb1 0x08 pop {r3}
  0xab      pop {r4, r5, r6, r7, r14}

0x8043e50 <_ZN7arduino21UsbDebugCommInterfaceC2EPNS_9USBSerialE>: 0x1 [cantunwind]

0x8043eb4 <_ZN7arduino3RPC28rpmsg_recv_cm4tocm7_callbackEP14rpmsg_endpointPvjmS3_>: 0x80b108a9
  Compact model index: 0
  0xb1 0x08 pop {r3}
  0xa9      pop {r4, r5, r14}

0x8043eec <_Z12eventHandlerv>: 0x80048400
  Compact model index: 0
  0x04      vsp = vsp + 20
  0x84 0x00 pop {r14}

0x8043f0c <rpmsg_send>: 0x8002a9b0
  Compact model index: 0
  0x02      vsp = vsp + 12
  0xa9      pop {r4, r5, r14}
  0xb0      finish

0x8043f30 <_ZN7arduino3RPC5writeEPKhj>: 0x80a8b0b0
  Compact model index: 0
  0xa8      pop {r4, r14}
  0xb0      finish
  0xb0      finish

0x8043f44 <_ZN7arduino3RPC5writeEh>: 0x80028400
  Compact model index: 0
  0x02      vsp = vsp + 12
  0x84 0x00 pop {r14}

0x8043f64 <_ZN14clmdep_msgpack2v16detail10decr_countEPv>: 0x1 [cantunwind]

0x80440ec <_ZN7arduino3RPC14new_service_cbEP12rpmsg_devicePKcm>: 0x8002a9b0
  Compact model index: 0
  0x02      vsp = vsp + 12
  0xa9      pop {r4, r5, r14}
  0xb0      finish

0x8044164 <_ZN14clmdep_msgpack2v14zone15allocate_expandEj.part.7>: @0x8073570
  Compact model index: 1
  0xb1 0x08 pop {r3}
  0x84 0x00 pop {r14}
  0xb0      finish
  0xb0      finish

0x8044184 <_ZNKSt14default_deleteIN14clmdep_msgpack2v14zoneEEclEPS2_.isra.29.part.30>: @0x807357c
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0xb1 0x08 pop {r3}
  0xa9      pop {r4, r5, r14}

0x80441b8 <_ZN7arduino3RPC23rpmsg_recv_raw_callbackEP14rpmsg_endpointPvjmS3_>: 0x80b108a9
  Compact model index: 0
  0xb1 0x08 pop {r3}
  0xa9      pop {r4, r5, r14}

0x8044204 <_ZNSt12_Vector_baseIPN14clmdep_msgpack2v26objectESaIS3_EE13_M_deallocateEPS3_j.isra.52>: 0x1 [cantunwind]

0x8044254 <_ZN14clmdep_msgpack2v26detail21create_object_visitor11parse_errorEjj.isra.21>: @0x8073588
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0xa8      pop {r4, r14}
  0xb0      finish
  0xb0      finish

0x804428c <_ZN7arduino3RPC28rpmsg_recv_cm7tocm4_callbackEP14rpmsg_endpointPvjmS3_>: 0x80b108a9
  Compact model index: 0
  0xb1 0x08 pop {r3}
  0xa9      pop {r4, r5, r14}

0x80442c2 <_ZN14clmdep_msgpack2v14zone15finalizer_array4pushEPFvPvES3_>: 0x80acb0b0
  Compact model index: 0
  0xac      pop {r4, r5, r6, r7, r8, r14}
  0xb0      finish
  0xb0      finish

0x804430c <_ZN14clmdep_msgpack2v14zone10chunk_listC2Ej>: 0x80b108a9
  Compact model index: 0
  0xb1 0x08 pop {r3}
  0xa9      pop {r4, r5, r14}

0x8044348 <_ZN14clmdep_msgpack2v14zone14allocate_alignEjj>: 0x80acb0b0
  Compact model index: 0
  0xac      pop {r4, r5, r6, r7, r8, r14}
  0xb0      finish
  0xb0      finish

0x80443b8 <_ZN14clmdep_msgpack2v26detail21create_object_visitor22visit_negative_integerEx>: 0x1 [cantunwind]

0x80443dc <_ZN14clmdep_msgpack2v26detail21create_object_visitor9visit_strEPKcm>: @0x807359c
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0xb1 0x08 pop {r3}
  0xab      pop {r4, r5, r6, r7, r14}

0x804445c <_ZN14clmdep_msgpack2v26detail21create_object_visitor9visit_binEPKcm>: @0x80735b0
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0xb1 0x08 pop {r3}
  0xab      pop {r4, r5, r6, r7, r14}

0x80444dc <_ZN14clmdep_msgpack2v26detail21create_object_visitor9visit_extEPKcm>: @0x80735c4
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0xb1 0x08 pop {r3}
  0xab      pop {r4, r5, r6, r7, r14}

0x804455c <_ZN4rtos6ThreadC2E12osPriority_tmPhPKc>: @0x80735d8
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0x02      vsp = vsp + 12
  0xad      pop {r4, r5, r6, r7, r8, r9, r14}
  0xb0      finish

0x80445bc <_ZN4mbed10TickerBaseD2Ev>: @0x80735f4
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0xb1 0x08 pop {r3}
  0xa9      pop {r4, r5, r14}

0x80445e0 <_ZN3rpc6client4postEPN14clmdep_msgpack2v17sbufferE>: 0x1 [cantunwind]

0x804461c <_ZN14clmdep_msgpack2v28unpacker12release_zoneEv>: @0x8073600
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0xaa      pop {r4, r5, r6, r14}
  0xb0      finish
  0xb0      finish

0x80446a4 <_ZN14clmdep_msgpack2v26parserINS0_8unpackerENS0_19zone_push_finalizerEED1Ev>: 0x1 [cantunwind]

0x80446fc <_ZNSt10_HashtableINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESt4pairIKS5_St8functionIFSt10unique_ptrIN14clmdep_msgpack2v113object_handleESt14default_deleteISC_EERKNSA_2v26objectEEEESaISM_ENSt8__detail10_Select1stESt8equal_toIS5_ESt4hashIS5_ENSO_18_Mod_range_hashingENSO_20_Default_ranged_hashENSO_20_Prime_rehash_policyENSO_17_Hashtable_traitsILb1ELb0ELb1EEEED1Ev>: @0x807361c
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0xb1 0x08 pop {r3}
  0xab      pop {r4, r5, r6, r7, r14}

0x804474c <_ZN7arduino3RPCD1Ev>: @0x8073628
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0xb1 0x08 pop {r3}
  0xa9      pop {r4, r5, r14}

0x80447a8 <_ZN14clmdep_msgpack2v26parserINS0_8unpackerENS0_19zone_push_finalizerEE13expand_bufferEj>: @0x8073634
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0xb1 0x08 pop {r3}
  0xad      pop {r4, r5, r6, r7, r8, r9, r14}

0x80448c4 <_ZN7arduino3RPC5beginEv>: @0x807365c
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0x08      vsp = vsp + 36
  0xab      pop {r4, r5, r6, r7, r14}
  0xb0      finish

0x8044a84 <_ZNKSt6vectorIPN14clmdep_msgpack2v26objectESaIS3_EE12_M_check_lenEjPKc>: 0x80a8b0b0
  Compact model index: 0
  0xa8      pop {r4, r14}
  0xb0      finish
  0xb0      finish

0x8044ab6 <_ZN14clmdep_msgpack2v26detail7contextINS0_8unpackerEE12unpack_stack7consumeERS3_>: 0x1 [cantunwind]

0x8044b58 <_ZNSt6vectorIN14clmdep_msgpack2v26detail7contextINS1_8unpackerEE12unpack_stack10stack_elemESaIS7_EE17_M_realloc_insertIJS7_EEEvN9__gnu_cxx17__normal_iteratorIPS7_S9_EEDpOT_>: 0x80b108ad
  Compact model index: 0
  0xb1 0x08 pop {r3}
  0xad      pop {r4, r5, r6, r7, r8, r9, r14}

0x8044bc6 <_ZNSt6vectorIN14clmdep_msgpack2v26detail7contextINS1_8unpackerEE12unpack_stack10stack_elemESaIS7_EE12emplace_backIJS7_EEEvDpOT_>: 0x80a8b0b0
  Compact model index: 0
  0xa8      pop {r4, r14}
  0xb0      finish
  0xb0      finish

0x8044bec <_ZNSt11__copy_moveILb1ELb1ESt26random_access_iterator_tagE8__copy_mIPN14clmdep_msgpack2v26objectEEEPT_PKS7_SA_S8_>: 0x1 [cantunwind]

0x8044c08 <_ZNSt6vectorIPN14clmdep_msgpack2v26objectESaIS3_EE17_M_realloc_insertIJRKS3_EEEvN9__gnu_cxx17__normal_iteratorIPS3_S5_EEDpOT_>: 0x80b108ad
  Compact model index: 0
  0xb1 0x08 pop {r3}
  0xad      pop {r4, r5, r6, r7, r8, r9, r14}

0x8044c70 <_ZN14clmdep_msgpack2v26detail21create_object_visitor11start_arrayEm>: @0x8073694
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0xb1 0x08 pop {r3}
  0xa9      pop {r4, r5, r14}

0x8044d44 <_ZNSt6vectorIPN14clmdep_msgpack2v26objectESaIS3_EE12emplace_backIJS3_EEEvDpOT_>: 0x80a8b0b0
  Compact model index: 0
  0xa8      pop {r4, r14}
  0xb0      finish
  0xb0      finish

0x8044d64 <_ZN14clmdep_msgpack2v26detail21create_object_visitor9start_mapEm>: @0x80736b8
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0x02      vsp = vsp + 12
  0xa9      pop {r4, r5, r14}
  0xb0      finish

0x8044e2c <_ZN14clmdep_msgpack2v26detail7contextINS0_8unpackerEE7executeEPKcjRj>: @0x80736dc
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0x20      vsp = vsp + 132
  0xaf      pop {r4, r5, r6, r7, r8, r9, r10, r11, r14}
  0xb0      finish

0x804530c <_ZN14clmdep_msgpack2v28unpackerC2EPFbNS_2v14type11object_typeEjPvES5_jRKNS2_12unpack_limitE>: @0x80736fc
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0x02      vsp = vsp + 12
  0xad      pop {r4, r5, r6, r7, r8, r9, r14}
  0xb0      finish

0x8045434 <_ZN7arduino3RPCC1Ev>: @0x8073720
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0x07      vsp = vsp + 32
  0xaa      pop {r4, r5, r6, r14}
  0xb0      finish

0x8045500 <_ZN14clmdep_msgpack2v28unpacker4nextERNS_2v113object_handleERb>: 0x80b108ad
  Compact model index: 0
  0xb1 0x08 pop {r3}
  0xad      pop {r4, r5, r6, r7, r8, r9, r14}

0x80455ec <_ZN7arduino3RPC8dispatchEv>: @0x8073744
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0x17      vsp = vsp + 96
  0xae      pop {r4, r5, r6, r7, r8, r9, r10, r14}
  0xb0      finish

0x8045758 <_GLOBAL__sub_I__ZN3rpc6client4postEPN14clmdep_msgpack2v17sbufferE>: 0x1 [cantunwind]

0x80457ce <_ZNSt6vectorIhSaIhEEC2ERKS1_>: 0x80aab0b0
  Compact model index: 0
  0xaa      pop {r4, r5, r6, r14}
  0xb0      finish
  0xb0      finish

0x8045812 <_ZNSt12_Vector_baseIhSaIhEED2Ev>: 0x1 [cantunwind]

0x8045824 <_ZN7arduino14SerialRPCClassD1Ev>: @0x807377c
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0xa8      pop {r4, r14}
  0xb0      finish
  0xb0      finish

0x8045848 <_ZN14clmdep_msgpack2v14packINS0_7sbufferESt5tupleIJhiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES3_IJSt6vectorIhSaIhEEEEEEEEvRT_RKT0_>: 0x8003aab0
  Compact model index: 0
  0x03      vsp = vsp + 16
  0xaa      pop {r4, r5, r6, r14}
  0xb0      finish

0x8045910 <_ZN3rpc6client4callIJSt6vectorIhSaIhEEEEEN14clmdep_msgpack2v113object_handleERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEDpT_>: @0x8073788
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0x12      vsp = vsp + 76
  0xab      pop {r4, r5, r6, r7, r14}
  0xb0      finish

0x80459d0 <_ZN7arduino14SerialRPCClass5writeEPhj>: @0x80737b4
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0x14      vsp = vsp + 84
  0xaf      pop {r4, r5, r6, r7, r8, r9, r10, r11, r14}
  0xb0      finish

0x8045ba0 <_ZN7arduino14SerialRPCClass5writeEh>: 0x80028400
  Compact model index: 0
  0x02      vsp = vsp + 12
  0x84 0x00 pop {r14}

0x8045bb8 <_GLOBAL__sub_I_SerialRPC>: 0x1 [cantunwind]

0x8045cb4 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tag.isra.237>: 0x8001aab0
  Compact model index: 0
  0x01      vsp = vsp + 8
  0xaa      pop {r4, r5, r6, r14}
  0xb0      finish

0x8045cfc <_ZSt8__fill_aIcEN9__gnu_cxx11__enable_ifIXsrSt9__is_byteIT_E7__valueEvE6__typeEPS3_S7_RKS3_.isra.245>: 0x1 [cantunwind]

0x8045d88 <_ZN10clmdep_fmt11FormatErrorC1ENS_15BasicCStringRefIcEE>: 0x80a8b0b0
  Compact model index: 0
  0xa8      pop {r4, r14}
  0xb0      finish
  0xb0      finish

0x8045d9c <_ZN10clmdep_fmt12_GLOBAL__N_121parse_nonnegative_intIcEEiRPKT_>: @0x80737dc
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0xa8      pop {r4, r14}
  0xb0      finish
  0xb0      finish

0x8045e18 <_ZN10clmdep_fmt8internal12count_digitsEy>: 0x1 [cantunwind]

0x804601c <_ZN10clmdep_fmt6BufferIcE6resizeEj>: 0x80b108a9
  Compact model index: 0
  0xb1 0x08 pop {r3}
  0xa9      pop {r4, r5, r14}

0x8046048 <_ZN10clmdep_fmt14BasicFormatterIcE15parse_arg_indexERPKc>: @0x80737f4
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0x02      vsp = vsp + 12
  0xab      pop {r4, r5, r6, r7, r14}
  0xb0      finish

0x80460c8 <_ZNSt8_Rb_treeIN10clmdep_fmt14BasicStringRefIcEESt4pairIKS2_NS0_8internal3ArgEESt10_Select1stIS7_ESt4lessIS2_ESaIS7_EE8_M_eraseEPSt13_Rb_tree_nodeIS7_E>: 0x1 [cantunwind]

0x804610c <_ZN10clmdep_fmt11BasicWriterIcElsENS_14BasicStringRefIcEE>: 0x8001acb0
  Compact model index: 0
  0x01      vsp = vsp + 8
  0xac      pop {r4, r5, r6, r7, r8, r14}
  0xb0      finish

0x804616c <_ZN10clmdep_fmt8internal13FormatterBase5writeIcEEvRNS_11BasicWriterIT_EEPKS4_S8_.isra.242>: 0x80028400
  Compact model index: 0
  0x02      vsp = vsp + 12
  0x84 0x00 pop {r14}

0x8046188 <_ZN10clmdep_fmt8internal12MemoryBufferIcLj500ESaIcEE4growEj>: 0x80aab0b0
  Compact model index: 0
  0xaa      pop {r4, r5, r6, r14}
  0xb0      finish
  0xb0      finish

0x80461c8 <_ZN10clmdep_fmt8internal14format_decimalImcEEvPT0_T_j>: 0x1 [cantunwind]

0x8046246 <_ZN10clmdep_fmt11BasicWriterIcE9write_strIcEEPcPKT_jRKNS_9AlignSpecE>: 0x80b108ab
  Compact model index: 0
  0xb1 0x08 pop {r3}
  0xab      pop {r4, r5, r6, r7, r14}

0x80462a6 <_ZNSt8_Rb_treeIN10clmdep_fmt14BasicStringRefIcEESt4pairIKS2_NS0_8internal3ArgEESt10_Select1stIS7_ESt4lessIS2_ESaIS7_EE16_M_insert_uniqueIS7_EES3_ISt17_Rb_tree_iteratorIS7_EbEOT_>: 0x80b108af
  Compact model index: 0
  0xb1 0x08 pop {r3}
  0xaf      pop {r4, r5, r6, r7, r8, r9, r10, r11, r14}

0x804634e <_ZN10clmdep_fmt8internal6ArgMapIcE4initERKNS_7ArgListE>: 0x800aafb0
  Compact model index: 0
  0x0a      vsp = vsp + 44
  0xaf      pop {r4, r5, r6, r7, r8, r9, r10, r11, r14}
  0xb0      finish

0x804649c <_ZN10clmdep_fmt14BasicFormatterIcE14parse_arg_nameERPKc>: @0x8073808
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0x02      vsp = vsp + 12
  0xab      pop {r4, r5, r6, r7, r14}
  0xb0      finish

0x8046580 <_ZN10clmdep_fmt8internal14format_decimalIycEEvPT0_T_j>: 0x1 [cantunwind]

0x8046602 <_ZN10clmdep_fmt11BasicWriterIcE18prepare_int_bufferINS_9AlignSpecEEEPcjRKT_PKcj>: 0x8008afb0
  Compact model index: 0
  0x08      vsp = vsp + 36
  0xaf      pop {r4, r5, r6, r7, r8, r9, r10, r11, r14}
  0xb0      finish

0x8046890 <_ZN10clmdep_fmt11BasicWriterIcE12write_doubleIeEEvT_RKNS_10FormatSpecE>: @0x8073824
  Compact model index: 1
  0x0a      vsp = vsp + 44
  0xc9 0x80 pop {D8}
  0xaf      pop {r4, r5, r6, r7, r8, r9, r10, r11, r14}
  0xb0      finish
  0xb0      finish

0x8046ab4 <_ZN10clmdep_fmt8internal10ArgVisitorINS0_12ArgFormatterIcEEvE5visitERKNS0_3ArgE>: 0x8008abb0
  Compact model index: 0
  0x08      vsp = vsp + 36
  0xab      pop {r4, r5, r6, r7, r14}
  0xb0      finish

0x8046c30 <_ZN10clmdep_fmt14BasicFormatterIcE6formatERPKcRKNS_8internal3ArgE>: @0x8073830
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0x15      vsp = vsp + 88
  0xae      pop {r4, r5, r6, r7, r8, r9, r10, r14}
  0xb0      finish

0x8047054 <_ZN10clmdep_fmt14BasicFormatterIcE6formatENS_15BasicCStringRefIcEE>: @0x80738c0
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0x06      vsp = vsp + 28
  0xa9      pop {r4, r5, r14}
  0xb0      finish

0x80470f4 <_ZN10clmdep_fmt11BasicWriterIcE5writeENS_15BasicCStringRefIcEENS_7ArgListE>: @0x80738dc
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0x0c      vsp = vsp + 52
  0xa9      pop {r4, r5, r14}
  0x01      vsp = vsp + 8

0x8047144 <_ZN10clmdep_fmt6formatB5cxx11ENS_15BasicCStringRefIcEENS_7ArgListE>: @0x80738f0
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0xb2 0x06 vsp = vsp + 540
  0xa9      pop {r4, r5, r14}
  0x01      vsp = vsp + 8
  0xb0      finish
  0xb0      finish
  0xb0      finish

0x80471c4 <_ZN10clmdep_fmt6formatIJcEEENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEENS_15BasicCStringRefIcEEDpRKT_.isra.320>: 0x8008a9b0
  Compact model index: 0
  0x08      vsp = vsp + 36
  0xa9      pop {r4, r5, r14}
  0xb0      finish

0x80471f8 <_ZN10clmdep_fmt12_GLOBAL__N_124require_numeric_argumentERKNS_8internal3ArgEc.isra.321>: @0x8073908
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0x05      vsp = vsp + 24
  0xa8      pop {r4, r14}
  0xb0      finish

0x8047244 <_ZN10clmdep_fmt12_GLOBAL__N_110check_signIcEEvRPKT_RKNS_8internal3ArgE>: @0x8073924
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0x05      vsp = vsp + 24
  0xaa      pop {r4, r5, r6, r14}
  0xb0      finish

0x80472b4 <_ZN10clmdep_fmt8internal19report_unknown_typeEcPKc>: @0x8073940
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0x10      vsp = vsp + 68
  0xad      pop {r4, r5, r6, r7, r8, r9, r14}
  0xb0      finish

0x8047370 <_ZN10clmdep_fmt11BasicWriterIcE9write_intIiNS_10FormatSpecEEEvT_T0_>: 0x8004ab01
  Compact model index: 0
  0x04      vsp = vsp + 20
  0xab      pop {r4, r5, r6, r7, r14}
  0x01      vsp = vsp + 8

0x80474f0 <_ZN10clmdep_fmt8internal17BasicArgFormatterINS0_12ArgFormatterIcEEcE10visit_charEi>: @0x8073968
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0x04      vsp = vsp + 20
  0xab      pop {r4, r5, r6, r7, r14}
  0xb0      finish

0x80475b4 <_ZN10clmdep_fmt11BasicWriterIcE9write_intIjNS_10FormatSpecEEEvT_T0_>: 0x8004ab01
  Compact model index: 0
  0x04      vsp = vsp + 20
  0xab      pop {r4, r5, r6, r7, r14}
  0x01      vsp = vsp + 8

0x804771c <_ZN10clmdep_fmt8internal17BasicArgFormatterINS0_12ArgFormatterIcEEcE13write_pointerEPKv>: 0x8003aab0
  Compact model index: 0
  0x03      vsp = vsp + 16
  0xaa      pop {r4, r5, r6, r14}
  0xb0      finish

0x8047748 <_ZN10clmdep_fmt11BasicWriterIcE9write_intIxNS_10FormatSpecEEEvT_T0_>: 0x8003acb0
  Compact model index: 0
  0x03      vsp = vsp + 16
  0xac      pop {r4, r5, r6, r7, r8, r14}
  0xb0      finish

0x8047ac4 <_ZN10clmdep_fmt11BasicWriterIcE9write_intIbNS_10FormatSpecEEEvT_T0_>: 0x8004ab01
  Compact model index: 0
  0x04      vsp = vsp + 20
  0xab      pop {r4, r5, r6, r7, r14}
  0x01      vsp = vsp + 8

0x8047bd8 <_ZN10clmdep_fmt11BasicWriterIcE9write_strIcEEvRKNS_8internal5Value11StringValueIT_EERKNS_10FormatSpecE>: @0x8073984
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0xa8      pop {r4, r14}
  0xb0      finish
  0xb0      finish

0x8047c40 <_ZN10clmdep_fmt11BasicWriterIcE12write_doubleIdEEvT_RKNS_10FormatSpecE>: @0x807399c
  Compact model index: 1
  0x0a      vsp = vsp + 44
  0xc9 0x80 pop {D8}
  0xaf      pop {r4, r5, r6, r7, r8, r9, r10, r11, r14}
  0xb0      finish
  0xb0      finish

0x8047e64 <_ZNSt19_Sp_counted_deleterIPN14clmdep_msgpack2v113object_handleENSt12__shared_ptrIS2_LN9__gnu_cxx12_Lock_policyE0EE8_DeleterISaIS2_EEES9_LS6_0EED1Ev>: 0x1 [cantunwind]

0x8047edc <_ZN14clmdep_msgpack2v14zone15allocate_expandEj.part.15>: @0x80739a8
  Compact model index: 1
  0xb1 0x08 pop {r3}
  0x84 0x00 pop {r14}
  0xb0      finish
  0xb0      finish

0x8047efc <_ZNK14clmdep_msgpack2v17adaptor7convertINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEvEclERKNS_2v26objectERS8_.isra.35>: 0x80a8b0b0
  Compact model index: 0
  0xa8      pop {r4, r14}
  0xb0      finish
  0xb0      finish

0x8047f38 <_ZN14clmdep_msgpack2v14type6detail20convert_integer_signIaLb1EE7convertERKNS_2v26objectE.part.41>: @0x80739b4
  Compact model index: 1
  0xb1 0x08 pop {r3}
  0x84 0x00 pop {r14}
  0xb0      finish
  0xb0      finish

0x8047f58 <_ZNSt19_Sp_counted_deleterIPN14clmdep_msgpack2v113object_handleESt14default_deleteIS2_ESaIvELN9__gnu_cxx12_Lock_policyE0EE10_M_disposeEv>: 0x1 [cantunwind]

0x8047f74 <_ZNKSt8functionIFSt10unique_ptrIN14clmdep_msgpack2v113object_handleESt14default_deleteIS3_EERKNS1_2v26objectEEEclESA_>: 0x80b108a9
  Compact model index: 0
  0xb1 0x08 pop {r3}
  0xa9      pop {r4, r5, r14}

0x8047f88 <_ZNSt10unique_ptrIN14clmdep_msgpack2v113object_handleESt14default_deleteIS2_EED2Ev>: 0x1 [cantunwind]

0x8047fa4 <_ZN14clmdep_msgpack2v14type6detail20convert_integer_signIaLb1EE7convertERKNS_2v26objectE>: @0x80739c0
  Compact model index: 1
  0xb1 0x08 pop {r3}
  0x84 0x00 pop {r14}
  0xb0      finish
  0xb0      finish

0x8047ff8 <_ZNK14clmdep_msgpack2v26object7convertISt5tupleIJaNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES1_EEEERT_SC_>: 0x8004abb0
  Compact model index: 0
  0x04      vsp = vsp + 20
  0xab      pop {r4, r5, r6, r7, r14}
  0xb0      finish

0x8048100 <_ZNSt10_HashtableINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESt4pairIKS5_St8functionIFSt10unique_ptrIN14clmdep_msgpack2v113object_handleESt14default_deleteISC_EERKNSA_2v26objectEEEESaISM_ENSt8__detail10_Select1stESt8equal_toIS5_ESt4hashIS5_ENSO_18_Mod_range_hashingENSO_20_Default_ranged_hashENSO_20_Prime_rehash_policyENSO_17_Hashtable_traitsILb1ELb0ELb1EEEE4findERS7_>: @0x80739cc
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0xb1 0x08 pop {r3}
  0xad      pop {r4, r5, r6, r7, r8, r9, r14}

0x8048170 <_ZN3rpc6detail10dispatcher21dispatch_notificationERKN14clmdep_msgpack2v26objectEb>: @0x80739d8
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0x0e      vsp = vsp + 60
  0xab      pop {r4, r5, r6, r7, r14}
  0xb0      finish

0x80481f8 <_ZNSt14__shared_countILN9__gnu_cxx12_Lock_policyE0EEC2IN14clmdep_msgpack2v113object_handleESt14default_deleteIS6_EEEOSt10unique_ptrIT_T0_E>: 0x80aab0b0
  Compact model index: 0
  0xaa      pop {r4, r5, r6, r14}
  0xb0      finish
  0xb0      finish

0x8048228 <_ZNSt15__allocated_ptrISaIN14clmdep_msgpack2v113object_handleEEED1Ev>: 0x1 [cantunwind]

0x8048238 <_ZN3rpc6detail8response10make_errorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEES1_mOT_>: @0x8073a10
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0x09      vsp = vsp + 40
  0xae      pop {r4, r5, r6, r7, r8, r9, r10, r14}
  0xb0      finish

0x8048360 <_ZN3rpc6detail10dispatcher13dispatch_callERKN14clmdep_msgpack2v26objectEb>: @0x8073a44
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0x38      vsp = vsp + 228
  0xab      pop {r4, r5, r6, r7, r14}
  0xb0      finish

0x80485cc <_ZN3rpc6detail10dispatcher8dispatchERKN14clmdep_msgpack2v26objectEb>: 0x80b108a9
  Compact model index: 0
  0xb1 0x08 pop {r3}
  0xa9      pop {r4, r5, r14}

0x80485ee <_ZNSt19_Sp_counted_deleterIPN14clmdep_msgpack2v113object_handleENSt12__shared_ptrIS2_LN9__gnu_cxx12_Lock_policyE0EE8_DeleterISaIS2_EEES9_LS6_0EE10_M_disposeEv>: 0x1 [cantunwind]

0x804860c <_ZN14clmdep_msgpack2v17sbuffer13expand_bufferEj.part.13>: @0x8073ac0
  Compact model index: 1
  0xb1 0x08 pop {r3}
  0x84 0x00 pop {r14}
  0xb0      finish
  0xb0      finish

0x804862c <_ZNKSt14default_deleteIN14clmdep_msgpack2v14zoneEEclEPS2_.isra.16.part.17>: @0x8073acc
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0xb1 0x08 pop {r3}
  0xa9      pop {r4, r5, r14}

0x8048660 <_ZNK14clmdep_msgpack2v17adaptor4packINS_2v26objectEvEclINS0_7sbufferEEERNS0_6packerIT_EESB_RKS4_.part.53>: @0x8073ad8
  Compact model index: 1
  0xb1 0x08 pop {r3}
  0x84 0x00 pop {r14}
  0xb0      finish
  0xb0      finish

0x8048680 <_ZN14clmdep_msgpack2v117aligned_zone_sizeERKNS_2v26objectE>: 0x1 [cantunwind]

0x804872e <_ZN14clmdep_msgpack2v16objectC1INS_2v26objectEEERKT_RNS0_4zoneE>: 0x8007a8b0
  Compact model index: 0
  0x07      vsp = vsp + 32
  0xa8      pop {r4, r14}
  0xb0      finish

0x804875a <_ZNK14clmdep_msgpack2v17adaptor16object_with_zoneINS_2v26objectEvEclERNS0_6object9with_zoneERKS4_>: 0x80b108ad
  Compact model index: 0
  0xb1 0x08 pop {r3}
  0xad      pop {r4, r5, r6, r7, r8, r9, r14}

0x8048848 <_ZN14clmdep_msgpack2v14type6detail20convert_integer_signImLb0EE7convertERKNS_2v26objectE>: @0x8073ae4
  Compact model index: 1
  0xb1 0x08 pop {r3}
  0x84 0x00 pop {r14}
  0xb0      finish
  0xb0      finish

0x804887c <_ZNK14clmdep_msgpack2v26object7convertISt5tupleIJmmS1_S1_EEEERT_S6_>: 0x8003acb0
  Compact model index: 0
  0x03      vsp = vsp + 16
  0xac      pop {r4, r5, r6, r7, r8, r14}
  0xb0      finish

0x8048914 <_ZNSt12__shared_ptrIN14clmdep_msgpack2v113object_handleELN9__gnu_cxx12_Lock_policyE0EEaSEOS5_>: 0x1 [cantunwind]

0x804893c <_ZNSt14__shared_countILN9__gnu_cxx12_Lock_policyE0EEC2IPN14clmdep_msgpack2v113object_handleENSt12__shared_ptrIS6_LS1_0EE8_DeleterISaIS6_EEESB_EET_T0_T1_>: @0x8073af0
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0x01      vsp = vsp + 8
  0xaa      pop {r4, r5, r6, r14}
  0xb0      finish

0x804898c <_ZNSt12__shared_ptrIN14clmdep_msgpack2v113object_handleELN9__gnu_cxx12_Lock_policyE0EEC1ISaIS2_EJEEESt19_Sp_make_shared_tagRKT_DpOT0_>: @0x8073b10
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0x05      vsp = vsp + 24
  0xaa      pop {r4, r5, r6, r14}
  0xb0      finish

0x80489e6 <_ZN3rpc6detail8responseC1EN14clmdep_msgpack2v113object_handleE>: @0x8073b28
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0x1c      vsp = vsp + 116
  0xaf      pop {r4, r5, r6, r7, r8, r9, r10, r11, r14}
  0xb0      finish

0x8048b56 <_ZN14clmdep_msgpack2v16packerINS0_7sbufferEE10pack_arrayEm>: 0x8001a8b0
  Compact model index: 0
  0x01      vsp = vsp + 8
  0xa8      pop {r4, r14}
  0xb0      finish

0x8048cc2 <_ZN14clmdep_msgpack2v16packerINS0_7sbufferEE15pack_imp_uint64IyEEvT_>: 0x80068481
  Compact model index: 0
  0x06      vsp = vsp + 28
  0x84 0x81 pop {r4, r11, r14}

0x8048d50 <_ZN14clmdep_msgpack2v16packerINS0_7sbufferEE14pack_imp_int64IxEEvT_>: 0x8005848f
  Compact model index: 0
  0x05      vsp = vsp + 24
  0x84 0x8f pop {r4, r5, r6, r7, r11, r14}

0x8048e34 <_ZNK14clmdep_msgpack2v17adaptor4packINS_2v26objectEvEclINS0_7sbufferEEERNS0_6packerIT_EESB_RKS4_>: 0x8005aab0
  Compact model index: 0
  0x05      vsp = vsp + 24
  0xaa      pop {r4, r5, r6, r14}
  0xb0      finish

0x8048f50 <_ZN14clmdep_msgpack2v1lsINS0_7sbufferENS_2v26objectEEENSt9enable_ifIXntsrSt8is_arrayIT0_E5valueERNS0_6packerIT_EEE4typeESC_RKS7_>: 0x80028400
  Compact model index: 0
  0x02      vsp = vsp + 12
  0x84 0x00 pop {r14}

0x8048fb8 <_ZNK3rpc6detail8response8get_dataEv>: @0x8073b58
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0x12      vsp = vsp + 76
  0xad      pop {r4, r5, r6, r7, r8, r9, r14}
  0xb0      finish

0x8049056 <_ZNK3rpc6detail8response8get_dataEv+0x9e>: 0x1 [cantunwind]

0x804c0ac <_ZN4mbed3I2CD2Ev>: @0x8073b74
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0xa8      pop {r4, r14}
  0xb0      finish
  0xb0      finish

0x804c0d0 <_ZN4mbed3I2CD0Ev>: 0x1 [cantunwind]

0x804c0e4 <_Z12fixup3V1Railv>: @0x8073b80
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0x3a      vsp = vsp + 236
  0x84 0x00 pop {r14}

0x804c120 <initVariant>: @0x8073b98
  Compact model index: 1
  0xb1 0x08 pop {r3}
  0x84 0x00 pop {r14}
  0xb0      finish
  0xb0      finish

0x804c154 <_Z21getUniqueSerialNumberPh>: 0x80a8b0b0
  Compact model index: 0
  0xa8      pop {r4, r14}
  0xb0      finish
  0xb0      finish

0x804c180 <_Z16_ontouch1200bps_v>: @0x8073ba4
  Compact model index: 1
  0xb1 0x08 pop {r3}
  0x84 0x00 pop {r14}
  0xb0      finish
  0xb0      finish

0x804c1b4 <_ZN7arduino4UART5flushEv>: 0x80a8b0b0
  Compact model index: 0
  0xa8      pop {r4, r14}
  0xb0      finish
  0xb0      finish

0x804c1c6 <_ZN7arduino4UART5beginEmt>: 0x80aab0b0
  Compact model index: 0
  0xaa      pop {r4, r5, r6, r14}
  0xb0      finish
  0xb0      finish

0x804c212 <_ZN7arduino4UART3endEv>: 0x1 [cantunwind]

0x804c264 <_ZN7arduino4UARTcvbEv>: @0x8073bb0
  Compact model index: 1
  0xb1 0x08 pop {r3}
  0x84 0x00 pop {r14}
  0xb0      finish
  0xb0      finish

0x804c290 <_ZN7arduino4UART5on_rxEv>: 0x8001a8b0
  Compact model index: 0
  0x01      vsp = vsp + 8
  0xa8      pop {r4, r14}
  0xb0      finish

0x804c2fc <_ZN7arduino4UART5beginEm>: @0x8073bbc
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0x03      vsp = vsp + 16
  0xaa      pop {r4, r5, r6, r14}
  0xb0      finish

0x804c398 <_Z19digitalPinToPinNameh>: 0x80a8b0b0
  Compact model index: 0
  0xa8      pop {r4, r14}
  0xb0      finish
  0xb0      finish

0x804c3b4 <_ZN7arduino9USBSerial5writeEh>: 0x80aab0b0
  Compact model index: 0
  0xaa      pop {r4, r5, r6, r14}
  0xb0      finish
  0xb0      finish

0x804c3d0 <_ZThn1216_N7arduino9USBSerial5writeEh>: 0x80b0b0b0
  Compact model index: 0
  0xb0      finish
  0xb0      finish
  0xb0      finish

0x804c3d8 <_ZN7arduino4UART5writeEh>: 0x8001a8b0
  Compact model index: 0
  0x01      vsp = vsp + 8
  0xa8      pop {r4, r14}
  0xb0      finish

0x804c41c <_ZN7arduino9USBSerial5writeEPKhj>: 0x80acb0b0
  Compact model index: 0
  0xac      pop {r4, r5, r6, r7, r8, r14}
  0xb0      finish
  0xb0      finish

0x804c456 <_ZThn1216_N7arduino9USBSerial5writeEPKhj>: 0x80b0b0b0
  Compact model index: 0
  0xb0      finish
  0xb0      finish
  0xb0      finish

0x804c45c <_ZN7arduino4UART5writeEPKhj>: 0x80aab0b0
  Compact model index: 0
  0xaa      pop {r4, r5, r6, r14}
  0xb0      finish
  0xb0      finish

0x804c4ac <_ZN7arduino9USBSerial11onInterruptEv>: 0x80023fa9
  Compact model index: 0
  0x02      vsp = vsp + 12
  0x3f      vsp = vsp + 256
  0xa9      pop {r4, r5, r14}

0x804c524 <_ZN7arduino9USBSerial9availableEv>: 0x80b108a9
  Compact model index: 0
  0xb1 0x08 pop {r3}
  0xa9      pop {r4, r5, r14}

0x804c540 <_ZThn1216_N7arduino9USBSerial9availableEv>: 0x80b0b0b0
  Compact model index: 0
  0xb0      finish
  0xb0      finish
  0xb0      finish

0x804c548 <_ZN7arduino4UART9availableEv>: 0x80a8b0b0
  Compact model index: 0
  0xa8      pop {r4, r14}
  0xb0      finish
  0xb0      finish

0x804c570 <_ZN7arduino9USBSerial4peekEv>: 0x80b108a9
  Compact model index: 0
  0xb1 0x08 pop {r3}
  0xa9      pop {r4, r5, r14}

0x804c59e <_ZThn1216_N7arduino9USBSerial4peekEv>: 0x80b0b0b0
  Compact model index: 0
  0xb0      finish
  0xb0      finish
  0xb0      finish

0x804c5a4 <_ZN7arduino4UART4peekEv>: 0x80a8b0b0
  Compact model index: 0
  0xa8      pop {r4, r14}
  0xb0      finish
  0xb0      finish

0x804c5e0 <_ZN7arduino9USBSerial4readEv>: 0x80b108a9
  Compact model index: 0
  0xb1 0x08 pop {r3}
  0xa9      pop {r4, r5, r14}

0x804c624 <_ZThn1216_N7arduino9USBSerial4readEv>: 0x80b0b0b0
  Compact model index: 0
  0xb0      finish
  0xb0      finish
  0xb0      finish

0x804c62c <_ZN7arduino4UART4readEv>: 0x80a8b0b0
  Compact model index: 0
  0xa8      pop {r4, r14}
  0xb0      finish
  0xb0      finish

0x804c680 <_ZN7arduino11RingBufferNILi256EEC2Ev>: 0x1 [cantunwind]

0x804c774 <_ZN7arduino18PluggableUSBDevice14callback_resetEv>: 0x80a8b0b0
  Compact model index: 0
  0xa8      pop {r4, r14}
  0xb0      finish
  0xb0      finish

0x804c78a <_ZN7arduino18PluggableUSBDevice21callback_state_changeEN9USBDevice11DeviceStateE>: 0x80b108a9
  Compact model index: 0
  0xb1 0x08 pop {r3}
  0xa9      pop {r4, r5, r14}

0x804c7a4 <_ZN7arduino18PluggableUSBDevice25string_imanufacturer_descEv>: 0x1 [cantunwind]

0x804c7ac <_ZN7arduino18PluggableUSBDeviceD2Ev>: @0x8073be4
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0xa8      pop {r4, r14}
  0xb0      finish
  0xb0      finish

0x804c7c8 <_ZN7arduino18PluggableUSBDeviceD0Ev>: 0x1 [cantunwind]

0x804c7de <_ZN7arduino18PluggableUSBDevice16callback_requestEPKN9USBDevice14setup_packet_tE>: 0x8002abb0
  Compact model index: 0
  0x02      vsp = vsp + 12
  0xab      pop {r4, r5, r6, r7, r14}
  0xb0      finish

0x804c81e <_ZN7arduino18PluggableUSBDevice26callback_request_xfer_doneEPKN9USBDevice14setup_packet_tEb>: 0x80aab0b0
  Compact model index: 0
  0xaa      pop {r4, r5, r6, r14}
  0xb0      finish
  0xb0      finish

0x804c87a <_ZN7arduino18PluggableUSBDevice22callback_set_interfaceEth>: 0x80b108ab
  Compact model index: 0
  0xb1 0x08 pop {r3}
  0xab      pop {r4, r5, r6, r7, r14}

0x804c8a4 <_ZN7arduino18PluggableUSBDevice11device_descEv>: 0x8005aab0
  Compact model index: 0
  0x05      vsp = vsp + 24
  0xaa      pop {r4, r5, r6, r14}
  0xb0      finish

0x804c934 <_ZL10TO_UNICODEPKcPh>: 0x1 [cantunwind]

0x804c960 <_ZN7arduino18PluggableUSBDevice22string_iinterface_descEv>: 0x80b108a9
  Compact model index: 0
  0xb1 0x08 pop {r3}
  0xa9      pop {r4, r5, r14}

0x804c99c <_ZN7arduino18PluggableUSBDevice20string_iproduct_descEv>: 0x1 [cantunwind]

0x804c9c8 <_ZN7arduino18PluggableUSBDevice19string_iserial_descEv>: 0x80a8b0b0
  Compact model index: 0
  0xa8      pop {r4, r14}
  0xb0      finish
  0xb0      finish

0x804c9ec <_ZN7arduino18PluggableUSBDevice18configuration_descEh>: 0x8003acb0
  Compact model index: 0
  0x03      vsp = vsp + 16
  0xac      pop {r4, r5, r6, r7, r8, r14}
  0xb0      finish

0x804ca6c <_ZN7arduino18PluggableUSBDeviceC1Ett>: 0x8001aab0
  Compact model index: 0
  0x01      vsp = vsp + 8
  0xaa      pop {r4, r5, r6, r14}
  0xb0      finish

0x804ca98 <_ZN7arduino18PluggableUSBDevice4plugEPNS_8internal18PluggableUSBModuleE>: 0x80a8b0b0
  Compact model index: 0
  0xa8      pop {r4, r14}
  0xb0      finish
  0xb0      finish

0x804cad6 <_ZN7arduino18PluggableUSBDevice4initEv>: @0x8073bf0
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0x03      vsp = vsp + 16
  0xa8      pop {r4, r14}
  0xb0      finish

0x804cb16 <_ZN7arduino18PluggableUSBDevice5beginEv>: 0x80a8b0b0
  Compact model index: 0
  0xa8      pop {r4, r14}
  0xb0      finish
  0xb0      finish

0x804cb28 <_Z13PluggableUSBDv>: @0x8073c08
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0xb1 0x08 pop {r3}
  0x84 0x00 pop {r14}
  0xb0      finish
  0xb0      finish
  0xb0      finish

0x804cb78 <_ZN7arduino8internal18PluggableUSBModule4lockEv>: 0x80a8b0b0
  Compact model index: 0
  0xa8      pop {r4, r14}
  0xb0      finish
  0xb0      finish

0x804cba8 <_ZN7arduino18PluggableUSBDevice4lockEv>: 0x1 [cantunwind]

0x804cd38 <_ZN7arduino6USBCDCD2Ev>: @0x8073c20
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0xa8      pop {r4, r14}
  0xb0      finish
  0xb0      finish

0x804cd68 <_ZN7arduino6USBCDCD0Ev>: 0x1 [cantunwind]

0x804cdfc <_ZN7arduino6USBCDC4initER16EndpointResolver>: 0x80b108a9
  Compact model index: 0
  0xb1 0x08 pop {r3}
  0xa9      pop {r4, r5, r14}

0x804ce84 <_ZN7arduino6USBCDC26callback_request_xfer_doneEPKN9USBDevice14setup_packet_tEb>: 0x8001acb0
  Compact model index: 0
  0x01      vsp = vsp + 8
  0xac      pop {r4, r5, r6, r7, r8, r14}
  0xb0      finish

0x804cf0e <_ZN7arduino6USBCDC9_send_isrEv>: 0x80a8b0b0
  Compact model index: 0
  0xa8      pop {r4, r14}
  0xb0      finish
  0xb0      finish

0x804cf50 <_ZN7arduino6USBCDC12_receive_isrEv>: 0x80aab0b0
  Compact model index: 0
  0xaa      pop {r4, r5, r6, r14}
  0xb0      finish
  0xb0      finish

0x804cfa8 <_ZN4mbed8CallbackIFvvEE11target_callIZNS2_C4IPN7arduino6USBCDCEMS6_FvvELi0EEET_T0_EUlvE_EEvPKNS_6detail12CallbackBaseE>: 0x1 [cantunwind]

0x804cfc4 <_ZN7arduino6USBCDC26callback_set_configurationEh>: @0x8073c2c
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0x05      vsp = vsp + 24
  0xaa      pop {r4, r5, r6, r14}
  0xb0      finish

0x804d07c <_ZN7arduino6USBCDCC1EP6USBPhyPKcttt>: @0x8073c5c
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0xac      pop {r4, r5, r6, r7, r8, r14}
  0xb0      finish
  0xb0      finish

0x804d0e4 <_ZN7arduino6USBCDC26_change_terminal_connectedEb>: 0x80aab0b0
  Compact model index: 0
  0xaa      pop {r4, r5, r6, r14}
  0xb0      finish
  0xb0      finish

0x804d18c <_ZN7arduino6USBCDC14callback_resetEv>: 0x80a8b0b0
  Compact model index: 0
  0xa8      pop {r4, r14}
  0xb0      finish
  0xb0      finish

0x804d1a0 <_ZN7arduino6USBCDC21callback_state_changeEN9USBDevice11DeviceStateE>: 0x80b108a9
  Compact model index: 0
  0xb1 0x08 pop {r3}
  0xa9      pop {r4, r5, r14}

0x804d1bc <_ZN7arduino6USBCDC16callback_requestEPKN9USBDevice14setup_packet_tEPNS1_13RequestResultEPPh>: 0x80b108ab
  Compact model index: 0
  0xb1 0x08 pop {r3}
  0xab      pop {r4, r5, r6, r7, r14}

0x804d22c <_ZN7arduino6USBCDC10wait_readyEv>: @0x8073c7c
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0x09      vsp = vsp + 40
  0xa8      pop {r4, r14}
  0xb0      finish

0x804d27c <_ZN7arduino6USBCDC4sendEPhm>: @0x8073c94
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0x0d      vsp = vsp + 56
  0xaa      pop {r4, r5, r6, r14}
  0xb0      finish

0x804d2e0 <_ZN7arduino6USBCDC15_send_isr_startEv>: 0x80a8b0b0
  Compact model index: 0
  0xa8      pop {r4, r14}
  0xb0      finish
  0xb0      finish

0x804d310 <_ZN7arduino6USBCDC7send_nbEPhmPmb>: 0x80b108ad
  Compact model index: 0
  0xb1 0x08 pop {r3}
  0xad      pop {r4, r5, r6, r7, r8, r9, r14}

0x804d372 <_ZN7arduino6USBCDC10AsyncWrite7processEv>: 0x8004abb0
  Compact model index: 0
  0x04      vsp = vsp + 20
  0xab      pop {r4, r5, r6, r7, r14}
  0xb0      finish

0x804d3c0 <_ZN7arduino6USBCDC7receiveEPhmPm>: @0x8073cac
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0x10      vsp = vsp + 68
  0xad      pop {r4, r5, r6, r7, r8, r9, r14}
  0xb0      finish

0x804d440 <_ZN7arduino6USBCDC18_receive_isr_startEv>: 0x80a8b0b0
  Compact model index: 0
  0xa8      pop {r4, r14}
  0xb0      finish
  0xb0      finish

0x804d46a <_ZN7arduino6USBCDC10receive_nbEPhmPm>: 0x1 [cantunwind]

0x804d4ba <_ZN7arduino6USBCDC9AsyncRead7processEv>: 0x8002a9b0
  Compact model index: 0
  0x02      vsp = vsp + 12
  0xa9      pop {r4, r5, r14}
  0xb0      finish

0x804d518 <_ZN4mbed10FileHandle8truncateEl>: 0x1 [cantunwind]

0x804d54a <_ZThn1216_N7arduino9USBSerial5beginEmt>: 0x80b0b0b0
  Compact model index: 0
  0xb0      finish
  0xb0      finish
  0xb0      finish

0x804d550 <_ZN7arduino9USBSerial3endEv>: 0x1 [cantunwind]

0x804d558 <_ZN7arduino9USBSerialcvbEv>: 0x80a8b0b0
  Compact model index: 0
  0xa8      pop {r4, r14}
  0xb0      finish
  0xb0      finish

0x804d568 <_ZThn1216_N7arduino9USBSerialcvbEv>: 0x80b0b0b0
  Compact model index: 0
  0xb0      finish
  0xb0      finish
  0xb0      finish

0x804d570 <_ZL16waitForPortClosev>: 0x80b108a9
  Compact model index: 0
  0xb1 0x08 pop {r3}
  0xa9      pop {r4, r5, r14}

0x804d5b0 <_ZN7arduino9USBSerial5_putcEi>: 0x80028400
  Compact model index: 0
  0x02      vsp = vsp + 12
  0x84 0x00 pop {r14}

0x804d5d0 <_ZThn1192_N7arduino9USBSerial5_putcEi>: 0x80b0b0b0
  Compact model index: 0
  0xb0      finish
  0xb0      finish
  0xb0      finish

0x804d5d8 <_ZN7arduino9USBSerial5_getcEv>: 0x80028400
  Compact model index: 0
  0x02      vsp = vsp + 12
  0x84 0x00 pop {r14}

0x804d5fa <_ZThn1192_N7arduino9USBSerial5_getcEv>: 0x80b0b0b0
  Compact model index: 0
  0xb0      finish
  0xb0      finish
  0xb0      finish

0x804d602 <_ZN7arduino9USBSerial19line_coding_changedEiiii>: 0x80b108ad
  Compact model index: 0
  0xb1 0x08 pop {r3}
  0xad      pop {r4, r5, r6, r7, r8, r9, r14}

0x804d63c <_ZN7arduino9USBSerial7data_rxEv>: 0x80aab0b0
  Compact model index: 0
  0xaa      pop {r4, r5, r6, r14}
  0xb0      finish
  0xb0      finish

0x804d668 <_Z14usbPortChangediiii>: 0x1 [cantunwind]

0x804d698 <_ZN7arduino9USBSerialD1Ev>: @0x8073cc4
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0xaa      pop {r4, r5, r6, r14}
  0xb0      finish
  0xb0      finish

0x804d6e4 <_ZThn1192_N7arduino9USBSerialD1Ev>: 0x1 [cantunwind]

0x804d71c <_ZN7arduino9USBSerialC1EbPKcttt>: @0x8073cd0
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0x02      vsp = vsp + 12
  0xab      pop {r4, r5, r6, r7, r14}
  0xb0      finish

0x804d7e4 <_ZN7arduino9USBSerial10_availableEv>: 0x80b108a9
  Compact model index: 0
  0xb1 0x08 pop {r3}
  0xa9      pop {r4, r5, r14}

0x804d810 <_ZN7arduino9USBSerial5beginEm>: @0x8073cf0
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0x06      vsp = vsp + 28
  0xab      pop {r4, r5, r6, r7, r14}
  0xb0      finish

0x804d92c <_ZThn1216_N7arduino9USBSerial5beginEm>: 0x80b0b0b0
  Compact model index: 0
  0xb0      finish
  0xb0      finish
  0xb0      finish

0x804d934 <_ZN7arduino9USBSerial9connectedEv>: 0x1 [cantunwind]

0x804d998 <__cxa_pure_virtual>: @0x8073d2c
  Compact model index: 1
  0xb1 0x08 pop {r3}
  0x84 0x00 pop {r14}
  0xb0      finish
  0xb0      finish

0x804d99e <_ZNK7arduino9IPAddress7printToERNS_5PrintE>: 0x80b108ad
  Compact model index: 0
  0xb1 0x08 pop {r3}
  0xad      pop {r4, r5, r6, r7, r8, r9, r14}

0x804d9dc <_GLOBAL__sub_I__ZN7arduino9IPAddressC2Ev>: 0x1 [cantunwind]

0x804d9f0 <_ZN7arduino5Print5writeEPKhj>: 0x80acb0b0
  Compact model index: 0
  0xac      pop {r4, r5, r6, r7, r8, r14}
  0xb0      finish
  0xb0      finish

0x804da1c <_ZN7arduino5Print5writeEPKc.part.2>: 0x1 [cantunwind]

0x804da4c <_ZN7arduino5Print5printEPKc>: @0x8073d38
  Compact model index: 1
  0xb1 0x08 pop {r3}
  0x84 0x00 pop {r14}
  0xb0      finish
  0xb0      finish

0x804da54 <_ZN7arduino5Print5printEc>: 0x1 [cantunwind]

0x804da68 <_ZN7arduino5Print7printlnERKNS_6StringE>: 0x80b108a9
  Compact model index: 0
  0xb1 0x08 pop {r3}
  0xa9      pop {r4, r5, r14}

0x804da90 <_ZN7arduino5Print11printNumberEmh>: 0x8009aab0
  Compact model index: 0
  0x09      vsp = vsp + 40
  0xaa      pop {r4, r5, r6, r14}
  0xb0      finish

0x804daca <_ZN7arduino5Print5printEli>: 0x80acb0b0
  Compact model index: 0
  0xac      pop {r4, r5, r6, r7, r8, r14}
  0xb0      finish
  0xb0      finish

0x804db0e <_ZN7arduino5Print5printEii>: 0x1 [cantunwind]

0x804db12 <_ZN7arduino5Print7printlnEii>: 0x80b108a9
  Compact model index: 0
  0xb1 0x08 pop {r3}
  0xa9      pop {r4, r5, r14}

0x804db26 <_ZN7arduino5Print5printEmi>: 0x1 [cantunwind]

0x804db44 <_ZN7arduino5Print7printlnEmi>: 0x80b108a9
  Compact model index: 0
  0xb1 0x08 pop {r3}
  0xa9      pop {r4, r5, r14}

0x804db58 <_ZN7arduino6StringD1Ev>: 0x1 [cantunwind]

0x804dcdc <main>: 0x80a8b0b0
  Compact model index: 0
  0xa8      pop {r4, r14}
  0xb0      finish
  0xb0      finish

0x804dd14 <_Z14PinNameToIndex7PinName>: 0x80aab0b0
  Compact model index: 0
  0xaa      pop {r4, r5, r6, r14}
  0xb0      finish
  0xb0      finish

0x804dd3c <_ZN4mbed13LowPowerTimerD2Ev>: 0x1 [cantunwind]

0x804dd54 <millis>: 0x80028400
  Compact model index: 0
  0x02      vsp = vsp + 12
  0x84 0x00 pop {r14}

0x804dd78 <delay>: 0x1 [cantunwind]

0x804dd7c <init>: @0x8073d44
  Compact model index: 1
  0xb1 0x08 pop {r3}
  0x84 0x00 pop {r14}
  0xb0      finish
  0xb0      finish

0x804dd98 <_GLOBAL__sub_I_millis>: 0x1 [cantunwind]

0x804ddd8 <analogRead>: @0x8073d50
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0xaa      pop {r4, r5, r6, r14}
  0xb0      finish
  0xb0      finish

0x804de74 <_ZN4mbed9DigitalInC2E7PinName7PinMode>: 0x80aab0b0
  Compact model index: 0
  0xaa      pop {r4, r5, r6, r14}
  0xb0      finish
  0xb0      finish

0x804de94 <_Z7pinModeh7PinMode>: @0x8073d68
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0xac      pop {r4, r5, r6, r7, r8, r14}
  0xb0      finish
  0xb0      finish

0x804df20 <_Z7pinMode7PinName7PinMode>: @0x8073d80
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0x08      vsp = vsp + 36
  0xa9      pop {r4, r5, r14}
  0xb0      finish

0x804df94 <digitalWrite>: @0x8073d98
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0x01      vsp = vsp + 8
  0xac      pop {r4, r5, r6, r7, r8, r14}
  0xb0      finish

0x804e028 <_Z12digitalWrite7PinName9PinStatus>: 0x8008a9b0
  Compact model index: 0
  0x08      vsp = vsp + 36
  0xa9      pop {r4, r5, r14}
  0xb0      finish

0x804e084 <osSignalSet>: 0x1 [cantunwind]

0x806235c <_ZL28read_encoded_value_with_basehjPKhPj>: 0x80b108ab
  Compact model index: 0
  0xb1 0x08 pop {r3}
  0xab      pop {r4, r5, r6, r7, r14}

0x806241c <_ZL21base_of_encoded_valuehP15_Unwind_Context.part.3>: @0x8073db4
  Compact model index: 1
  0xb1 0x08 pop {r3}
  0x84 0x00 pop {r14}
  0xb0      finish
  0xb0      finish

0x8062454 <_ZL17parse_lsda_headerP15_Unwind_ContextPKhP16lsda_header_info>: 0x80b108ab
  Compact model index: 0
  0xb1 0x08 pop {r3}
  0xab      pop {r4, r5, r6, r7, r14}

0x80624e8 <__gxx_personality_v0>: @0x8073dc0
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0x18      vsp = vsp + 100
  0xaf      pop {r4, r5, r6, r7, r8, r9, r10, r11, r14}
  0xb0      finish

0x80629cc <_ZNKSt8bad_cast4whatEv>: 0x1 [cantunwind]

0x8062c04 <__cxa_call_unexpected>: @0x8073de4
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0x04      vsp = vsp + 20
  0xaf      pop {r4, r5, r6, r7, r8, r9, r10, r11, r14}
  0xb0      finish

0x8062ce0 <__cxa_throw_bad_array_new_length>: @0x8073e0c
  Compact model index: 1
  0xb1 0x08 pop {r3}
  0x84 0x00 pop {r14}
  0xb0      finish
  0xb0      finish

0x8062d00 <__cxa_begin_catch>: @0x8073e18
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0xb1 0x08 pop {r3}
  0xa9      pop {r4, r5, r14}

0x8062d80 <__cxa_end_catch>: 0x1 [cantunwind]

0x8062e18 <_ZN10__cxxabiv111__terminateEPFvvE>: @0x8073e24
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0xb1 0x08 pop {r3}
  0x84 0x00 pop {r14}
  0xb0      finish
  0xb0      finish
  0xb0      finish

0x8062e40 <_ZSt9terminatev>: 0x1 [cantunwind]

0x8062e54 <_ZN10__cxxabiv112__unexpectedEPFvvE>: @0x8073e50
  Compact model index: 1
  0xb1 0x08 pop {r3}
  0x84 0x00 pop {r14}
  0xb0      finish
  0xb0      finish

0x8062e5c <_ZSt10unexpectedv>: @0x8073e5c
  Compact model index: 1
  0xb1 0x08 pop {r3}
  0x84 0x00 pop {r14}
  0xb0      finish
  0xb0      finish

0x8062e70 <_ZSt13get_terminatev>: 0x1 [cantunwind]

0x8062e9c <__cxa_type_match>: 0x8002abb0
  Compact model index: 0
  0x02      vsp = vsp + 12
  0xab      pop {r4, r5, r6, r7, r14}
  0xb0      finish

0x8062f4c <__cxa_begin_cleanup>: 0x1 [cantunwind]

0x8063020 <_ZL23__gxx_exception_cleanup19_Unwind_Reason_CodeP21_Unwind_Control_Block>: 0x80a8b0b0
  Compact model index: 0
  0xa8      pop {r4, r14}
  0xb0      finish
  0xb0      finish

0x8063064 <__cxa_init_primary_exception>: 0x1 [cantunwind]

0x80630bc <__cxa_throw>: 0x80b108ab
  Compact model index: 0
  0xb1 0x08 pop {r3}
  0xab      pop {r4, r5, r6, r7, r14}

0x80630f4 <__cxa_rethrow>: 0x80a8b0b0
  Compact model index: 0
  0xa8      pop {r4, r14}
  0xb0      finish
  0xb0      finish

0x8063164 <_ZN10__cxxabiv120__si_class_type_infoD2Ev>: 0x1 [cantunwind]

0x8063250 <_ZNK10__cxxabiv120__si_class_type_info11__do_upcastEPKNS_17__class_type_infoEPKvRNS1_15__upcast_resultE>: 0x80acb0b0
  Compact model index: 0
  0xac      pop {r4, r5, r6, r7, r8, r14}
  0xb0      finish
  0xb0      finish

0x806327c <_ZNSt9type_infoD1Ev>: 0x1 [cantunwind]

0x80632b0 <_ZNK10__cxxabiv117__class_type_info11__do_upcastEPKS0_PPv>: 0x8003aab0
  Compact model index: 0
  0x03      vsp = vsp + 16
  0xaa      pop {r4, r5, r6, r14}
  0xb0      finish

0x80632e8 <_ZNK10__cxxabiv117__class_type_info20__do_find_public_srcEiPKvPKS0_S2_>: 0x1 [cantunwind]

0x806363c <_ZNSs4_Rep9_S_createEjjRKSaIcE>: 0x80a8b0b0
  Compact model index: 0
  0xa8      pop {r4, r14}
  0xb0      finish
  0xb0      finish

0x8063694 <_ZNSs4_Rep10_M_destroyERKSaIcE>: 0x1 [cantunwind]

0x8063698 <_ZNSs12_S_constructIPKcEEPcT_S3_RKSaIcESt20forward_iterator_tag>: 0x80aab0b0
  Compact model index: 0
  0xaa      pop {r4, r5, r6, r14}
  0xb0      finish
  0xb0      finish

0x80636fc <_ZNSsC1EPKcjRKSaIcE>: 0x80b108a9
  Compact model index: 0
  0xb1 0x08 pop {r3}
  0xa9      pop {r4, r5, r14}

0x8063718 <_ZNSsC1EPKcRKSaIcE>: 0x80aab0b0
  Compact model index: 0
  0xaa      pop {r4, r5, r6, r14}
  0xb0      finish
  0xb0      finish

0x8063744 <_ZNSt11logic_errorC2EPKc>: @0x8073e68
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0x01      vsp = vsp + 8
  0xa8      pop {r4, r14}
  0xb0      finish

0x806376c <_ZNSt12length_errorC2EPKc>: 0x80a8b0b0
  Compact model index: 0
  0xa8      pop {r4, r14}
  0xb0      finish
  0xb0      finish

0x8063780 <_ZNSt13runtime_errorC1EPKc>: @0x8073e7c
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0x01      vsp = vsp + 8
  0xa8      pop {r4, r14}
  0xb0      finish

0x80637a8 <_ZNSt12__cow_stringC1EPKcj>: 0x8001a8b0
  Compact model index: 0
  0x01      vsp = vsp + 8
  0xa8      pop {r4, r14}
  0xb0      finish

0x80637bc <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERjj>: @0x8073e90
  Compact model index: 1
  0xb1 0x08 pop {r3}
  0x84 0x00 pop {r14}
  0xb0      finish
  0xb0      finish

0x8063804 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv>: 0x1 [cantunwind]

0x8063830 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_mutateEjjPKcj>: 0x8002afb0
  Compact model index: 0
  0x02      vsp = vsp + 12
  0xaf      pop {r4, r5, r6, r7, r8, r9, r10, r11, r14}
  0xb0      finish

0x80638e0 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_replaceEjjPKcj>: 0x8004afb0
  Compact model index: 0
  0x04      vsp = vsp + 20
  0xaf      pop {r4, r5, r6, r7, r8, r9, r10, r11, r14}
  0xb0      finish

0x8063a6c <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6assignEPKcj>: 0x8001a8b0
  Compact model index: 0
  0x01      vsp = vsp + 8
  0xa8      pop {r4, r14}
  0xb0      finish

0x8063a84 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPcEEvT_S7_St20forward_iterator_tag>: 0x8001aab0
  Compact model index: 0
  0x01      vsp = vsp + 8
  0xaa      pop {r4, r5, r6, r14}
  0xb0      finish

0x8063ae4 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2ERKS4_>: 0x80a8b0b0
  Compact model index: 0
  0xa8      pop {r4, r14}
  0xb0      finish
  0xb0      finish

0x8063b04 <_ZSt17__throw_bad_allocv>: @0x8073e9c
  Compact model index: 1
  0xb1 0x08 pop {r3}
  0x84 0x00 pop {r14}
  0xb0      finish
  0xb0      finish

0x8063b24 <_ZSt19__throw_logic_errorPKc>: @0x8073ea8
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0xb1 0x08 pop {r3}
  0xa9      pop {r4, r5, r14}

0x8063b54 <_ZSt20__throw_length_errorPKc>: @0x8073ebc
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0xb1 0x08 pop {r3}
  0xa9      pop {r4, r5, r14}

0x8063b84 <_ZNKSt17bad_function_call4whatEv>: 0x1 [cantunwind]

0x8063bbc <_ZSt25__throw_bad_function_callv>: @0x8073ed0
  Compact model index: 1
  0xb1 0x08 pop {r3}
  0x84 0x00 pop {r14}
  0xb0      finish
  0xb0      finish

0x8063bdc <_ZNKSt20bad_array_new_length4whatEv>: 0x1 [cantunwind]

0x8063e30 <_ZNKSt3_V214error_category10_M_messageB5cxx11Ei>: @0x8073edc
  Personality routine: 0x80624e9 <__gxx_personality_v0>
  0x05      vsp = vsp + 24
  0xa8      pop {r4, r14}
  0xb0      finish

0x8063e6c <_ZNK12_GLOBAL__N_122generic_error_category7messageB5cxx11Ei>: 0x8002abb0
  Compact model index: 0
  0x02      vsp = vsp + 12
  0xab      pop {r4, r5, r6, r7, r14}
  0xb0      finish

0x8063ed4 <_ZNKSt3_V214error_category10equivalentEiRKSt15error_condition>: 0x1 [cantunwind]

0x806443c <get_eit_entry>: 0x8002a9b0
  Compact model index: 0
  0x02      vsp = vsp + 12
  0xa9      pop {r4, r5, r14}
  0xb0      finish

0x80644e0 <restore_non_core_regs>: 0x80a8b0b0
  Compact model index: 0
  0xa8      pop {r4, r14}
  0xb0      finish
  0xb0      finish

0x8064538 <_Unwind_decode_typeinfo_ptr.isra.0>: 0x1 [cantunwind]

0x806454c <unwind_phase2>: 0x80aab0b0
  Compact model index: 0
  0xaa      pop {r4, r5, r6, r14}
  0xb0      finish
  0xb0      finish

0x806458c <unwind_phase2_forced>: 0x80b271ae
  Compact model index: 0
  0xb2 0x71 vsp = vsp + 968
  0xae      pop {r4, r5, r6, r7, r8, r9, r10, r14}

0x8064654 <_Unwind_GetCFA>: 0x1 [cantunwind]

0x8064658 <__gnu_Unwind_RaiseException>: 0x80383fab
  Compact model index: 0
  0x38      vsp = vsp + 228
  0x3f      vsp = vsp + 256
  0xab      pop {r4, r5, r6, r7, r14}

0x80646b8 <__gnu_Unwind_ForcedUnwind>: 0x1 [cantunwind]

0x80646cc <__gnu_Unwind_Resume>: 0x80aab0b0
  Compact model index: 0
  0xaa      pop {r4, r5, r6, r14}
  0xb0      finish
  0xb0      finish

0x8064710 <__gnu_Unwind_Resume_or_Rethrow>: 0x1 [cantunwind]

0x80647bc <__gnu_Unwind_Backtrace>: 0x80b20eab
  Compact model index: 0
  0xb2 0x0e vsp = vsp + 572
  0xab      pop {r4, r5, r6, r7, r14}

0x806482c <__gnu_unwind_pr_common>: 0x8008afb0
  Compact model index: 0
  0x08      vsp = vsp + 36
  0xaf      pop {r4, r5, r6, r7, r8, r9, r10, r11, r14}
  0xb0      finish

0x8064b00 <__aeabi_unwind_cpp_pr0>: 0x1 [cantunwind]

0x8064b0c <_Unwind_VRS_Pop>: 0x80033fac
  Compact model index: 0
  0x03      vsp = vsp + 16
  0x3f      vsp = vsp + 256
  0xac      pop {r4, r5, r6, r7, r8, r14}

0x8064d8c <__restore_core_regs>: 0x1 [cantunwind]

0x8064f70 <_Unwind_GetGR.constprop.0>: 0x80048400
  Compact model index: 0
  0x04      vsp = vsp + 20
  0x84 0x00 pop {r14}

0x8064f8c <unwind_UCB_from_context>: 0x1 [cantunwind]

0x8064f90 <__gnu_unwind_execute>: 0x8004adb0
  Compact model index: 0
  0x04      vsp = vsp + 20
  0xad      pop {r4, r5, r6, r7, r8, r9, r14}
  0xb0      finish

0x8065254 <__gnu_unwind_frame>: 0x8003a8b0
  Compact model index: 0
  0x03      vsp = vsp + 16
  0xa8      pop {r4, r14}
  0xb0      finish

0x806527c <_Unwind_GetRegionStart>: @0x8073ef4
  Compact model index: 1
  0xb1 0x08 pop {r3}
  0x84 0x00 pop {r14}
  0xb0      finish
  0xb0      finish

0x8065288 <_Unwind_GetLanguageSpecificData>: @0x8073f00
  Compact model index: 1
  0xb1 0x08 pop {r3}
  0x84 0x00 pop {r14}
  0xb0      finish
  0xb0      finish

0x806529c <_Unwind_GetDataRelBase>: 0x1 [cantunwind]


Symbol table '.symtab' contains 7876 entries:
   Num:    Value  Size Type    Bind   Vis      Ndx Name
     0: 00000000     0 NOTYPE  LOCAL  DEFAULT  UND 
     1: 08040000     0 SECTION LOCAL  DEFAULT    1 
     2: 08073450     0 SECTION LOCAL  DEFAULT    2 
     3: 08073f0c     0 SECTION LOCAL  DEFAULT    3 
     4: 24000000     0 SECTION LOCAL  DEFAULT    4 
     5: 24001aa0     0 SECTION LOCAL  DEFAULT    5 
     6: 24001aa0     0 SECTION LOCAL  DEFAULT    6 
     7: 38000000     0 SECTION LOCAL  DEFAULT    7 
     8: 3800008c     0 SECTION LOCAL  DEFAULT    8 
     9: 24011ec8     0 SECTION LOCAL  DEFAULT    9 
    10: 30000000     0 SECTION LOCAL  DEFAULT   10 
    11: 00000000     0 SECTION LOCAL  DEFAULT   11 
    12: 00000000     0 SECTION LOCAL  DEFAULT   12 
    13: 00000000     0 SECTION LOCAL  DEFAULT   13 
    14: 00000000     0 SECTION LOCAL  DEFAULT   14 
    15: 00000000     0 SECTION LOCAL  DEFAULT   15 
    16: 00000000     0 SECTION LOCAL  DEFAULT   16 
    17: 00000000     0 SECTION LOCAL  DEFAULT   17 
    18: 00000000     0 SECTION LOCAL  DEFAULT   18 
    19: 00000000     0 SECTION LOCAL  DEFAULT   19 
    20: 00000000     0 SECTION LOCAL  DEFAULT   20 
    21: 00000000     0 SECTION LOCAL  DEFAULT   21 
    22: 00000000     0 SECTION LOCAL  DEFAULT   22 
    23: 00000000     0 SECTION LOCAL  DEFAULT   23 
    24: 00000000     0 FILE    LOCAL  DEFAULT  ABS startup_stm32h747xx.o
    25: 0805f244     0 NOTYPE  LOCAL  DEFAULT    1 $t
    26: 0805f258     0 NOTYPE  LOCAL  DEFAULT    1 LoopCopyDataInit
    27: 0805f250     0 NOTYPE  LOCAL  DEFAULT    1 CopyDataInit
    28: 0805f26c     0 NOTYPE  LOCAL  DEFAULT    1 LoopFillZerobss
    29: 0805f266     0 NOTYPE  LOCAL  DEFAULT    1 FillZerobss
    30: 0805f290     0 NOTYPE  LOCAL  DEFAULT    1 Infinite_Loop
    31: 0805f290     0 NOTYPE  LOCAL  DEFAULT    1 $t
    32: 0805f278     0 NOTYPE  LOCAL  DEFAULT    1 $d
    33: 00000000     0 FILE    LOCAL  DEFAULT  ABS crtstuff.c
    34: 0807344c     0 OBJECT  LOCAL  DEFAULT    1 __EH_FRAME_BEGIN__
    35: 24000000     0 NOTYPE  LOCAL  DEFAULT    4 $d
    36: 08040298     0 NOTYPE  LOCAL  DEFAULT    1 $t
    37: 08040299     0 FUNC    LOCAL  DEFAULT    1 __do_global_dtors_aux
    38: 080402b0     0 NOTYPE  LOCAL  DEFAULT    1 $d
    39: 24001aa0     1 NOTYPE  LOCAL  DEFAULT    6 completed.9929
    40: 24001a98     0 NOTYPE  LOCAL  DEFAULT    4 $d
    41: 24001a98     0 OBJECT  LOCAL  DEFAULT    4 __do_global_dtors_aux_fin
    42: 080402bc     0 NOTYPE  LOCAL  DEFAULT    1 $t
    43: 080402bd     0 FUNC    LOCAL  DEFAULT    1 frame_dummy
    44: 080402cc     0 NOTYPE  LOCAL  DEFAULT    1 $d
    45: 24001aa4    24 NOTYPE  LOCAL  DEFAULT    6 object.9934
    46: 24001a38     0 NOTYPE  LOCAL  DEFAULT    4 $d
    47: 24001a38     0 OBJECT  LOCAL  DEFAULT    4 __frame_dummy_init_array_
    48: 24001aa0     0 NOTYPE  LOCAL  DEFAULT    6 $d
    49: 00000000     0 FILE    LOCAL  DEFAULT  ABS /root/.arduino15/packages
    50: 080402d8     0 NOTYPE  LOCAL  DEFAULT    1 $t
    51: 0804032c     0 NOTYPE  LOCAL  DEFAULT    1 $d
    52: 08073f0c     0 NOTYPE  LOCAL  DEFAULT    3 $d
    53: 00000000     0 FILE    LOCAL  DEFAULT  ABS CAN_Init.ino.cpp
    54: 0804034c     0 NOTYPE  LOCAL  DEFAULT    1 $t
    55: 08040354     0 NOTYPE  LOCAL  DEFAULT    1 $d
    56: 08073f14     0 NOTYPE  LOCAL  DEFAULT    3 $d
    57: 08040358     0 NOTYPE  LOCAL  DEFAULT    1 $t
    58: 08040360     0 NOTYPE  LOCAL  DEFAULT    1 $d
    59: 08073f14     0 NOTYPE  LOCAL  DEFAULT    3 $d
    60: 08040364     0 NOTYPE  LOCAL  DEFAULT    1 $t
    61: 08040394     0 NOTYPE  LOCAL  DEFAULT    1 $d
    62: 08073f14     0 NOTYPE  LOCAL  DEFAULT    3 $d
    63: 080403a0     0 NOTYPE  LOCAL  DEFAULT    1 $t
    64: 080403d8     0 NOTYPE  LOCAL  DEFAULT    1 $d
    65: 08073f1c     0 NOTYPE  LOCAL  DEFAULT    3 $d
    66: 080403dc     0 NOTYPE  LOCAL  DEFAULT    1 $t
    67: 0804046c     0 NOTYPE  LOCAL  DEFAULT    1 $d
    68: 08073450     0 NOTYPE  LOCAL  DEFAULT    2 $d
    69: 08073f24     0 NOTYPE  LOCAL  DEFAULT    3 $d
    70: 080404a0     0 NOTYPE  LOCAL  DEFAULT    1 $t
    71: 08040598     0 NOTYPE  LOCAL  DEFAULT    1 $d
    72: 08073f2c     0 NOTYPE  LOCAL  DEFAULT    3 $d
    73: 080405cc     0 NOTYPE  LOCAL  DEFAULT    1 $t
    74: 080405d8     0 NOTYPE  LOCAL  DEFAULT    1 $d
    75: 08073f34     0 NOTYPE  LOCAL  DEFAULT    3 $d
    76: 080405dc     0 NOTYPE  LOCAL  DEFAULT    1 $t
    77: 080405ec     0 NOTYPE  LOCAL  DEFAULT    1 $d
    78: 08073f3c     0 NOTYPE  LOCAL  DEFAULT    3 $d
    79: 080405f0     0 NOTYPE  LOCAL  DEFAULT    1 $t
    80: 08073f3c     0 NOTYPE  LOCAL  DEFAULT    3 $d
    81: 080405f4     0 NOTYPE  LOCAL  DEFAULT    1 $t
    82: 08040600     0 NOTYPE  LOCAL  DEFAULT    1 $d
    83: 08073f3c     0 NOTYPE  LOCAL  DEFAULT    3 $d
    84: 08040604     0 NOTYPE  LOCAL  DEFAULT    1 $t
    85: 0807345c     0 NOTYPE  LOCAL  DEFAULT    2 $d
    86: 08073f3c     0 NOTYPE  LOCAL  DEFAULT    3 $d
    87: 0804063c     0 NOTYPE  LOCAL  DEFAULT    1 $t
    88: 080406a0     0 NOTYPE  LOCAL  DEFAULT    1 $d
    89: 08073f44     0 NOTYPE  LOCAL  DEFAULT    3 $d
    90: 080406ac     0 NOTYPE  LOCAL  DEFAULT    1 $t
    91: 08073f4c     0 NOTYPE  LOCAL  DEFAULT    3 $d
    92: 08040706     0 NOTYPE  LOCAL  DEFAULT    1 $t
    93: 08073f54     0 NOTYPE  LOCAL  DEFAULT    3 $d
    94: 0804077e     0 NOTYPE  LOCAL  DEFAULT    1 $t
    95: 08073f5c     0 NOTYPE  LOCAL  DEFAULT    3 $d
    96: 080407fa     0 NOTYPE  LOCAL  DEFAULT    1 $t
    97: 08073468     0 NOTYPE  LOCAL  DEFAULT    2 $d
    98: 08073f64     0 NOTYPE  LOCAL  DEFAULT    3 $d
    99: 08040908     0 NOTYPE  LOCAL  DEFAULT    1 $t
   100: 08040b98     0 NOTYPE  LOCAL  DEFAULT    1 $d
   101: 08040bdc     0 NOTYPE  LOCAL  DEFAULT    1 $t
   102: 08040d10     0 NOTYPE  LOCAL  DEFAULT    1 $d
   103: 0807348c     0 NOTYPE  LOCAL  DEFAULT    2 $d
   104: 08073f6c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   105: 08040d2c     0 NOTYPE  LOCAL  DEFAULT    1 $t
   106: 08040d2d   920 FUNC    LOCAL  DEFAULT    1 _GLOBAL__sub_I_SerialUSB1
   107: 0804106c     0 NOTYPE  LOCAL  DEFAULT    1 $d
   108: 08073f74     0 NOTYPE  LOCAL  DEFAULT    3 $d
   109: 24001a3c     0 NOTYPE  LOCAL  DEFAULT    4 $d
   110: 080410c4     0 NOTYPE  LOCAL  DEFAULT    1 $t
   111: 080411dc     0 NOTYPE  LOCAL  DEFAULT    1 $d
   112: 08073f7c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   113: 24001abc     0 NOTYPE  LOCAL  DEFAULT    6 $d
   114: 240020f4     0 NOTYPE  LOCAL  DEFAULT    6 $d
   115: 240020f4    32 OBJECT  LOCAL  DEFAULT    6 _ZL10Scenario_2
   116: 24002118     0 NOTYPE  LOCAL  DEFAULT    6 $d
   117: 24002118    40 OBJECT  LOCAL  DEFAULT    6 _ZL15function_linear
   118: 24002140     0 NOTYPE  LOCAL  DEFAULT    6 $d
   119: 24002140   384 OBJECT  LOCAL  DEFAULT    6 _ZL4fake
   120: 240022c0     0 NOTYPE  LOCAL  DEFAULT    6 $d
   121: 240022c8     0 NOTYPE  LOCAL  DEFAULT    6 $d
   122: 240029e0     0 NOTYPE  LOCAL  DEFAULT    6 $d
   123: 0806d18e     8 OBJECT  LOCAL  DEFAULT    1 _ZL5temp0
   124: 0806d18e     0 NOTYPE  LOCAL  DEFAULT    1 $d
   125: 0806d196     8 OBJECT  LOCAL  DEFAULT    1 _ZL5temp1
   126: 0806d19e     8 OBJECT  LOCAL  DEFAULT    1 _ZL5temp2
   127: 0806d1a6     8 OBJECT  LOCAL  DEFAULT    1 _ZL5temp3
   128: 0806d1ae     8 OBJECT  LOCAL  DEFAULT    1 _ZL5temp4
   129: 0806d1b6     8 OBJECT  LOCAL  DEFAULT    1 _ZL5temp6
   130: 0806d1be     8 OBJECT  LOCAL  DEFAULT    1 _ZL5temp7
   131: 0806d1c6     8 OBJECT  LOCAL  DEFAULT    1 _ZL5temp8
   132: 00000000     0 FILE    LOCAL  DEFAULT  ABS FDCAN.cpp
   133: 08041214     0 NOTYPE  LOCAL  DEFAULT    1 $t
   134: 08041334     0 NOTYPE  LOCAL  DEFAULT    1 $d
   135: 08073f84     0 NOTYPE  LOCAL  DEFAULT    3 $d
   136: 08041354     0 NOTYPE  LOCAL  DEFAULT    1 $t
   137: 080413b4     0 NOTYPE  LOCAL  DEFAULT    1 $d
   138: 08073f8c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   139: 080413bc     0 NOTYPE  LOCAL  DEFAULT    1 $t
   140: 08041434     0 NOTYPE  LOCAL  DEFAULT    1 $d
   141: 08073f94     0 NOTYPE  LOCAL  DEFAULT    3 $d
   142: 08041460     0 NOTYPE  LOCAL  DEFAULT    1 $t
   143: 0804153c     0 NOTYPE  LOCAL  DEFAULT    1 $d
   144: 08073f9c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   145: 0804154c     0 NOTYPE  LOCAL  DEFAULT    1 $t
   146: 08041574     0 NOTYPE  LOCAL  DEFAULT    1 $d
   147: 0804157a     0 NOTYPE  LOCAL  DEFAULT    1 $t
   148: 08041598     0 NOTYPE  LOCAL  DEFAULT    1 $d
   149: 08073fa4     0 NOTYPE  LOCAL  DEFAULT    3 $d
   150: 080415a0     0 NOTYPE  LOCAL  DEFAULT    1 $t
   151: 080415a1    76 FUNC    LOCAL  DEFAULT    1 _GLOBAL__sub_I__Z8Set_Fre
   152: 080415dc     0 NOTYPE  LOCAL  DEFAULT    1 $d
   153: 08073fac     0 NOTYPE  LOCAL  DEFAULT    3 $d
   154: 24001a40     0 NOTYPE  LOCAL  DEFAULT    4 $d
   155: 240029e4     0 NOTYPE  LOCAL  DEFAULT    6 $d
   156: 240029e4    32 OBJECT  LOCAL  DEFAULT    6 _ZL10Scenario_2
   157: 24002a08     0 NOTYPE  LOCAL  DEFAULT    6 $d
   158: 24002a08    40 OBJECT  LOCAL  DEFAULT    6 _ZL15function_linear
   159: 00000000     0 FILE    LOCAL  DEFAULT  ABS RTC.cpp
   160: 080415ec     0 NOTYPE  LOCAL  DEFAULT    1 $t
   161: 08041624     0 NOTYPE  LOCAL  DEFAULT    1 $d
   162: 080734c0     0 NOTYPE  LOCAL  DEFAULT    2 $d
   163: 08073fb4     0 NOTYPE  LOCAL  DEFAULT    3 $d
   164: 08041634     0 NOTYPE  LOCAL  DEFAULT    1 $t
   165: 08041660     0 NOTYPE  LOCAL  DEFAULT    1 $d
   166: 08073fbc     0 NOTYPE  LOCAL  DEFAULT    3 $d
   167: 08041668     0 NOTYPE  LOCAL  DEFAULT    1 $t
   168: 080416b8     0 NOTYPE  LOCAL  DEFAULT    1 $d
   169: 08073fc4     0 NOTYPE  LOCAL  DEFAULT    3 $d
   170: 080416bc     0 NOTYPE  LOCAL  DEFAULT    1 $t
   171: 080416bd    76 FUNC    LOCAL  DEFAULT    1 _GLOBAL__sub_I__Z8RTC_Ini
   172: 080416f8     0 NOTYPE  LOCAL  DEFAULT    1 $d
   173: 08073fcc     0 NOTYPE  LOCAL  DEFAULT    3 $d
   174: 24001a44     0 NOTYPE  LOCAL  DEFAULT    4 $d
   175: 24002a30     0 NOTYPE  LOCAL  DEFAULT    6 $d
   176: 24002a30    32 OBJECT  LOCAL  DEFAULT    6 _ZL10Scenario_2
   177: 24002a50     0 NOTYPE  LOCAL  DEFAULT    6 $d
   178: 24002a50    40 OBJECT  LOCAL  DEFAULT    6 _ZL15function_linear
   179: 00000000     0 FILE    LOCAL  DEFAULT  ABS SRAM.cpp
   180: 08041708     0 NOTYPE  LOCAL  DEFAULT    1 $t
   181: 08041a50     0 NOTYPE  LOCAL  DEFAULT    1 $d
   182: 08041b28     0 NOTYPE  LOCAL  DEFAULT    1 $t
   183: 08041e60     0 NOTYPE  LOCAL  DEFAULT    1 $d
   184: 08041f20     0 NOTYPE  LOCAL  DEFAULT    1 $t
   185: 080734cc     0 NOTYPE  LOCAL  DEFAULT    2 $d
   186: 08073fd4     0 NOTYPE  LOCAL  DEFAULT    3 $d
   187: 08041f70     0 NOTYPE  LOCAL  DEFAULT    1 $t
   188: 08041fec     0 NOTYPE  LOCAL  DEFAULT    1 $d
   189: 08073fdc     0 NOTYPE  LOCAL  DEFAULT    3 $d
   190: 08041ffc     0 NOTYPE  LOCAL  DEFAULT    1 $t
   191: 08073fe4     0 NOTYPE  LOCAL  DEFAULT    3 $d
   192: 0804202c     0 NOTYPE  LOCAL  DEFAULT    1 $t
   193: 0804202d    76 FUNC    LOCAL  DEFAULT    1 _GLOBAL__sub_I__Z17write_
   194: 08042068     0 NOTYPE  LOCAL  DEFAULT    1 $d
   195: 08073fec     0 NOTYPE  LOCAL  DEFAULT    3 $d
   196: 24001a48     0 NOTYPE  LOCAL  DEFAULT    4 $d
   197: 24002a78     0 NOTYPE  LOCAL  DEFAULT    6 $d
   198: 24002a78    32 OBJECT  LOCAL  DEFAULT    6 _ZL10Scenario_2
   199: 24002a98     0 NOTYPE  LOCAL  DEFAULT    6 $d
   200: 24002a98    40 OBJECT  LOCAL  DEFAULT    6 _ZL15function_linear
   201: 00000000     0 FILE    LOCAL  DEFAULT  ABS TIMER.cpp
   202: 08042078     0 NOTYPE  LOCAL  DEFAULT    1 $t
   203: 08042079    76 FUNC    LOCAL  DEFAULT    1 _GLOBAL__sub_I_TIMER.cpp
   204: 080420b4     0 NOTYPE  LOCAL  DEFAULT    1 $d
   205: 08073ff4     0 NOTYPE  LOCAL  DEFAULT    3 $d
   206: 24001a4c     0 NOTYPE  LOCAL  DEFAULT    4 $d
   207: 24002ac0     0 NOTYPE  LOCAL  DEFAULT    6 $d
   208: 24002ac0    32 OBJECT  LOCAL  DEFAULT    6 _ZL10Scenario_2
   209: 24002ae0     0 NOTYPE  LOCAL  DEFAULT    6 $d
   210: 24002ae0    40 OBJECT  LOCAL  DEFAULT    6 _ZL15function_linear
   211: 00000000     0 FILE    LOCAL  DEFAULT  ABS UTILITY.cpp
   212: 080420c4     0 NOTYPE  LOCAL  DEFAULT    1 $t
   213: 08073ff4     0 NOTYPE  LOCAL  DEFAULT    3 $d
   214: 080420ce     0 NOTYPE  LOCAL  DEFAULT    1 $t
   215: 08073ff4     0 NOTYPE  LOCAL  DEFAULT    3 $d
   216: 0804211a     0 NOTYPE  LOCAL  DEFAULT    1 $t
   217: 08073ff4     0 NOTYPE  LOCAL  DEFAULT    3 $d
   218: 08042134     0 NOTYPE  LOCAL  DEFAULT    1 $t
   219: 08073ff4     0 NOTYPE  LOCAL  DEFAULT    3 $d
   220: 080421c4     0 NOTYPE  LOCAL  DEFAULT    1 $t
   221: 080422fa     0 NOTYPE  LOCAL  DEFAULT    1 $d
   222: 080422fe     0 NOTYPE  LOCAL  DEFAULT    1 $t
   223: 08042448     0 NOTYPE  LOCAL  DEFAULT    1 $d
   224: 08073ff4     0 NOTYPE  LOCAL  DEFAULT    3 $d
   225: 08042450     0 NOTYPE  LOCAL  DEFAULT    1 $t
   226: 08073ffc     0 NOTYPE  LOCAL  DEFAULT    3 $d
   227: 08042488     0 NOTYPE  LOCAL  DEFAULT    1 $t
   228: 080424f8     0 NOTYPE  LOCAL  DEFAULT    1 $d
   229: 08074004     0 NOTYPE  LOCAL  DEFAULT    3 $d
   230: 08042510     0 NOTYPE  LOCAL  DEFAULT    1 $t
   231: 0804252c     0 NOTYPE  LOCAL  DEFAULT    1 $d
   232: 0807400c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   233: 08042530     0 NOTYPE  LOCAL  DEFAULT    1 $t
   234: 08074014     0 NOTYPE  LOCAL  DEFAULT    3 $d
   235: 08042538     0 NOTYPE  LOCAL  DEFAULT    1 $t
   236: 08042539   104 FUNC    LOCAL  DEFAULT    1 _GLOBAL__sub_I__Z10prepar
   237: 0804258c     0 NOTYPE  LOCAL  DEFAULT    1 $d
   238: 08074014     0 NOTYPE  LOCAL  DEFAULT    3 $d
   239: 24001a50     0 NOTYPE  LOCAL  DEFAULT    4 $d
   240: 24002b08     0 NOTYPE  LOCAL  DEFAULT    6 $d
   241: 24002b08    32 OBJECT  LOCAL  DEFAULT    6 _ZL10Scenario_1
   242: 24002b28     0 NOTYPE  LOCAL  DEFAULT    6 $d
   243: 24002b28    32 OBJECT  LOCAL  DEFAULT    6 _ZL10Scenario_2
   244: 24002b48     0 NOTYPE  LOCAL  DEFAULT    6 $d
   245: 24002b48    40 OBJECT  LOCAL  DEFAULT    6 _ZL15function_linear
   246: 00000000     0 FILE    LOCAL  DEFAULT  ABS loiTruck.cpp
   247: 080425a0     0 NOTYPE  LOCAL  DEFAULT    1 $t
   248: 08074014     0 NOTYPE  LOCAL  DEFAULT    3 $d
   249: 08042638     0 NOTYPE  LOCAL  DEFAULT    1 $t
   250: 08042639    76 FUNC    LOCAL  DEFAULT    1 _GLOBAL__sub_I__ZN8LOITRU
   251: 08042674     0 NOTYPE  LOCAL  DEFAULT    1 $d
   252: 08074014     0 NOTYPE  LOCAL  DEFAULT    3 $d
   253: 24001a54     0 NOTYPE  LOCAL  DEFAULT    4 $d
   254: 24002b70     0 NOTYPE  LOCAL  DEFAULT    6 $d
   255: 24002b70    32 OBJECT  LOCAL  DEFAULT    6 _ZL10Scenario_2
   256: 24002b90     0 NOTYPE  LOCAL  DEFAULT    6 $d
   257: 24002b90    40 OBJECT  LOCAL  DEFAULT    6 _ZL15function_linear
   258: 00000000     0 FILE    LOCAL  DEFAULT  ABS /tmp/arduino_build_866360
   259: 0000000d     0 NOTYPE  LOCAL  DEFAULT  ABS EXC_RETURN_THREADMODE_PRO
   260: 00000009     0 NOTYPE  LOCAL  DEFAULT  ABS EXC_RETURN_THREADMODE_MAI
   261: e000ed2c     0 NOTYPE  LOCAL  DEFAULT  ABS HFSR
   262: 80000000     0 NOTYPE  LOCAL  DEFAULT  ABS HFSR_DEBUG_EVENT_BIT
   263: e000edfc     0 NOTYPE  LOCAL  DEFAULT  ABS DEMCR
   264: 00020000     0 NOTYPE  LOCAL  DEFAULT  ABS DEMCR_MON_PEND_BIT
   265: 08042684     0 NOTYPE  LOCAL  DEFAULT    1 $t
   266: 080426ba     0 NOTYPE  LOCAL  DEFAULT    1 $d
   267: 080426bc     0 NOTYPE  LOCAL  DEFAULT    1 $d
   268: 080426c0     0 NOTYPE  LOCAL  DEFAULT    1 $t
   269: 080426c8     0 NOTYPE  LOCAL  DEFAULT    1 $d
   270: 080426cc     0 NOTYPE  LOCAL  DEFAULT    1 $t
   271: 080426d4     0 NOTYPE  LOCAL  DEFAULT    1 $d
   272: 080426d8     0 NOTYPE  LOCAL  DEFAULT    1 $t
   273: 080426e0     0 NOTYPE  LOCAL  DEFAULT    1 $d
   274: 080426e4     0 NOTYPE  LOCAL  DEFAULT    1 $t
   275: 080426ec     0 NOTYPE  LOCAL  DEFAULT    1 $d
   276: 080426f0     0 NOTYPE  LOCAL  DEFAULT    1 $t
   277: 080426fc     0 NOTYPE  LOCAL  DEFAULT    1 $d
   278: 08042700     0 NOTYPE  LOCAL  DEFAULT    1 $t
   279: 08042708     0 NOTYPE  LOCAL  DEFAULT    1 $d
   280: 0804270c     0 NOTYPE  LOCAL  DEFAULT    1 $t
   281: 08042714     0 NOTYPE  LOCAL  DEFAULT    1 $d
   282: 08042718     0 NOTYPE  LOCAL  DEFAULT    1 $t
   283: 08042720     0 NOTYPE  LOCAL  DEFAULT    1 $d
   284: 00000000     0 FILE    LOCAL  DEFAULT  ABS ThreadDebug.cpp
   285: 08042724     0 NOTYPE  LOCAL  DEFAULT    1 $t
   286: 08042725    20 FUNC    LOCAL  DEFAULT    1 __NVIC_SetVector
   287: 08042734     0 NOTYPE  LOCAL  DEFAULT    1 $d
   288: 08074014     0 NOTYPE  LOCAL  DEFAULT    3 $d
   289: 08042738     0 NOTYPE  LOCAL  DEFAULT    1 $t
   290: 08074014     0 NOTYPE  LOCAL  DEFAULT    3 $d
   291: 0804273c     0 NOTYPE  LOCAL  DEFAULT    1 $t
   292: 0804273d    20 FUNC    LOCAL  DEFAULT    1 setExceptionCode
   293: 0804274c     0 NOTYPE  LOCAL  DEFAULT    1 $d
   294: 08074014     0 NOTYPE  LOCAL  DEFAULT    3 $d
   295: 08042750     0 NOTYPE  LOCAL  DEFAULT    1 $t
   296: 08042751    24 FUNC    LOCAL  DEFAULT    1 getFPBCodeComparatorCount
   297: 08042764     0 NOTYPE  LOCAL  DEFAULT    1 $d
   298: 08074014     0 NOTYPE  LOCAL  DEFAULT    3 $d
   299: 08042768     0 NOTYPE  LOCAL  DEFAULT    1 $t
   300: 08042769    36 FUNC    LOCAL  DEFAULT    1 isBreakpointAddressInvali
   301: 08042784     0 NOTYPE  LOCAL  DEFAULT    1 $d
   302: 08074014     0 NOTYPE  LOCAL  DEFAULT    3 $d
   303: 0804278c     0 NOTYPE  LOCAL  DEFAULT    1 $t
   304: 0804278d    28 FUNC    LOCAL  DEFAULT    1 isInstruction32Bit
   305: 08074014     0 NOTYPE  LOCAL  DEFAULT    3 $d
   306: 080427a8     0 NOTYPE  LOCAL  DEFAULT    1 $t
   307: 08074014     0 NOTYPE  LOCAL  DEFAULT    3 $d
   308: 080427be     0 NOTYPE  LOCAL  DEFAULT    1 $t
   309: 080427bf     2 FUNC    LOCAL  DEFAULT    1 _ZL7mriIdlePv
   310: 08074014     0 NOTYPE  LOCAL  DEFAULT    3 $d
   311: 080427c0     0 NOTYPE  LOCAL  DEFAULT    1 $t
   312: 080427c1    52 FUNC    LOCAL  DEFAULT    1 _ZL29recordAndClearFaultS
   313: 080427ec     0 NOTYPE  LOCAL  DEFAULT    1 $d
   314: 08074014     0 NOTYPE  LOCAL  DEFAULT    3 $d
   315: 080427f4     0 NOTYPE  LOCAL  DEFAULT    1 $t
   316: 08074014     0 NOTYPE  LOCAL  DEFAULT    3 $d
   317: 080427f6     0 NOTYPE  LOCAL  DEFAULT    1 $t
   318: 080734f4     0 NOTYPE  LOCAL  DEFAULT    2 $d
   319: 08074014     0 NOTYPE  LOCAL  DEFAULT    3 $d
   320: 0804280a     0 NOTYPE  LOCAL  DEFAULT    1 $t
   321: 0807401c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   322: 0804280e     0 NOTYPE  LOCAL  DEFAULT    1 $t
   323: 08073500     0 NOTYPE  LOCAL  DEFAULT    2 $d
   324: 08074024     0 NOTYPE  LOCAL  DEFAULT    3 $d
   325: 0804281c     0 NOTYPE  LOCAL  DEFAULT    1 $t
   326: 0807402c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   327: 08042824     0 NOTYPE  LOCAL  DEFAULT    1 $t
   328: 08074034     0 NOTYPE  LOCAL  DEFAULT    3 $d
   329: 08042828     0 NOTYPE  LOCAL  DEFAULT    1 $t
   330: 08042829   152 FUNC    LOCAL  DEFAULT    1 displayMemFaultCauseToGdb
   331: 0804289c     0 NOTYPE  LOCAL  DEFAULT    1 $d
   332: 08074034     0 NOTYPE  LOCAL  DEFAULT    3 $d
   333: 080428c0     0 NOTYPE  LOCAL  DEFAULT    1 $t
   334: 080428c1   168 FUNC    LOCAL  DEFAULT    1 displayBusFaultCauseToGdb
   335: 08042940     0 NOTYPE  LOCAL  DEFAULT    1 $d
   336: 0807403c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   337: 08042968     0 NOTYPE  LOCAL  DEFAULT    1 $t
   338: 08042969   128 FUNC    LOCAL  DEFAULT    1 displayUsageFaultCauseToG
   339: 080429c4     0 NOTYPE  LOCAL  DEFAULT    1 $d
   340: 0807403c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   341: 080429e8     0 NOTYPE  LOCAL  DEFAULT    1 $t
   342: 080429e9   176 FUNC    LOCAL  DEFAULT    1 _ZL17readThreadContextP10
   343: 08042a94     0 NOTYPE  LOCAL  DEFAULT    1 $d
   344: 08074044     0 NOTYPE  LOCAL  DEFAULT    3 $d
   345: 08042a98     0 NOTYPE  LOCAL  DEFAULT    1 $t
   346: 08042a99    44 FUNC    LOCAL  DEFAULT    1 _ZL31wakeMriMainToDebugCu
   347: 08042ab8     0 NOTYPE  LOCAL  DEFAULT    1 $d
   348: 0807350c     0 NOTYPE  LOCAL  DEFAULT    2 $d
   349: 0807404c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   350: 08042ac4     0 NOTYPE  LOCAL  DEFAULT    1 $t
   351: 08074054     0 NOTYPE  LOCAL  DEFAULT    3 $d
   352: 08042ad2     0 NOTYPE  LOCAL  DEFAULT    1 $t
   353: 0807405c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   354: 08042ae0     0 NOTYPE  LOCAL  DEFAULT    1 $t
   355: 08042ae1    60 FUNC    LOCAL  DEFAULT    1 calculateFPBComparatorVal
   356: 08042b18     0 NOTYPE  LOCAL  DEFAULT    1 $d
   357: 0807405c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   358: 08042b1c     0 NOTYPE  LOCAL  DEFAULT    1 $t
   359: 08042b1d    84 FUNC    LOCAL  DEFAULT    1 findFPBBreakpointComparat
   360: 08042b68     0 NOTYPE  LOCAL  DEFAULT    1 $d
   361: 0807405c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   362: 08042b70     0 NOTYPE  LOCAL  DEFAULT    1 $t
   363: 08042b71    70 FUNC    LOCAL  DEFAULT    1 sendRegisterForTResponse
   364: 0807405c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   365: 08042bb8     0 NOTYPE  LOCAL  DEFAULT    1 $t
   366: 08042bb9    84 FUNC    LOCAL  DEFAULT    1 findDWTComparator
   367: 08042c00     0 NOTYPE  LOCAL  DEFAULT    1 $d
   368: 08074064     0 NOTYPE  LOCAL  DEFAULT    3 $d
   369: 08042c0c     0 NOTYPE  LOCAL  DEFAULT    1 $t
   370: 08042c0d    88 FUNC    LOCAL  DEFAULT    1 _ZL18stopSingleSteppingv
   371: 08042c4c     0 NOTYPE  LOCAL  DEFAULT    1 $d
   372: 0807406c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   373: 08042c64     0 NOTYPE  LOCAL  DEFAULT    1 $t
   374: 08042c65    68 FUNC    LOCAL  DEFAULT    1 _ZL24justEnteredSetupCall
   375: 08042c98     0 NOTYPE  LOCAL  DEFAULT    1 $d
   376: 08042d09    96 FUNC    LOCAL  DEFAULT    1 _ZL13serialISRHookv
   377: 0807406c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   378: 08042ca8     0 NOTYPE  LOCAL  DEFAULT    1 $t
   379: 08042ca9    96 FUNC    LOCAL  DEFAULT    1 enableFPBBreakpoint.part.
   380: 08042d04     0 NOTYPE  LOCAL  DEFAULT    1 $d
   381: 08074074     0 NOTYPE  LOCAL  DEFAULT    3 $d
   382: 08042d08     0 NOTYPE  LOCAL  DEFAULT    1 $t
   383: 08042d50     0 NOTYPE  LOCAL  DEFAULT    1 $d
   384: 0807407c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   385: 08042d68     0 NOTYPE  LOCAL  DEFAULT    1 $t
   386: 08074084     0 NOTYPE  LOCAL  DEFAULT    3 $d
   387: 08042d74     0 NOTYPE  LOCAL  DEFAULT    1 $t
   388: 08042df0     0 NOTYPE  LOCAL  DEFAULT    1 $d
   389: 08073518     0 NOTYPE  LOCAL  DEFAULT    2 $d
   390: 0807408c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   391: 08042df4     0 NOTYPE  LOCAL  DEFAULT    1 $t
   392: 08042e30     0 NOTYPE  LOCAL  DEFAULT    1 $d
   393: 08074094     0 NOTYPE  LOCAL  DEFAULT    3 $d
   394: 08042e38     0 NOTYPE  LOCAL  DEFAULT    1 $t
   395: 08042e44     0 NOTYPE  LOCAL  DEFAULT    1 $d
   396: 0807409c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   397: 08042e48     0 NOTYPE  LOCAL  DEFAULT    1 $t
   398: 08042e54     0 NOTYPE  LOCAL  DEFAULT    1 $d
   399: 0807409c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   400: 08042e58     0 NOTYPE  LOCAL  DEFAULT    1 $t
   401: 08042e5c     0 NOTYPE  LOCAL  DEFAULT    1 $d
   402: 0807409c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   403: 08042e60     0 NOTYPE  LOCAL  DEFAULT    1 $t
   404: 0807409c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   405: 08042e68     0 NOTYPE  LOCAL  DEFAULT    1 $t
   406: 08042e78     0 NOTYPE  LOCAL  DEFAULT    1 $d
   407: 0807409c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   408: 08042e7c     0 NOTYPE  LOCAL  DEFAULT    1 $t
   409: 08042e8c     0 NOTYPE  LOCAL  DEFAULT    1 $d
   410: 08042e90     0 NOTYPE  LOCAL  DEFAULT    1 $t
   411: 08042ee8     0 NOTYPE  LOCAL  DEFAULT    1 $d
   412: 0807409c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   413: 08042f04     0 NOTYPE  LOCAL  DEFAULT    1 $t
   414: 08042f4c     0 NOTYPE  LOCAL  DEFAULT    1 $d
   415: 080740a4     0 NOTYPE  LOCAL  DEFAULT    3 $d
   416: 08042f60     0 NOTYPE  LOCAL  DEFAULT    1 $t
   417: 08042f68     0 NOTYPE  LOCAL  DEFAULT    1 $d
   418: 080740ac     0 NOTYPE  LOCAL  DEFAULT    3 $d
   419: 08042f6c     0 NOTYPE  LOCAL  DEFAULT    1 $t
   420: 08042f78     0 NOTYPE  LOCAL  DEFAULT    1 $d
   421: 080740ac     0 NOTYPE  LOCAL  DEFAULT    3 $d
   422: 08042f7c     0 NOTYPE  LOCAL  DEFAULT    1 $t
   423: 08042f90     0 NOTYPE  LOCAL  DEFAULT    1 $d
   424: 08073534     0 NOTYPE  LOCAL  DEFAULT    2 $d
   425: 080740ac     0 NOTYPE  LOCAL  DEFAULT    3 $d
   426: 08042f94     0 NOTYPE  LOCAL  DEFAULT    1 $t
   427: 08042fac     0 NOTYPE  LOCAL  DEFAULT    1 $d
   428: 080740b4     0 NOTYPE  LOCAL  DEFAULT    3 $d
   429: 08042fb0     0 NOTYPE  LOCAL  DEFAULT    1 $t
   430: 08042fb1    26 FUNC    LOCAL  DEFAULT    1 throwingMemRead16
   431: 08073540     0 NOTYPE  LOCAL  DEFAULT    2 $d
   432: 080740bc     0 NOTYPE  LOCAL  DEFAULT    3 $d
   433: 08042fcc     0 NOTYPE  LOCAL  DEFAULT    1 $t
   434: 08043000     0 NOTYPE  LOCAL  DEFAULT    1 $d
   435: 080740c4     0 NOTYPE  LOCAL  DEFAULT    3 $d
   436: 08043004     0 NOTYPE  LOCAL  DEFAULT    1 $t
   437: 08043044     0 NOTYPE  LOCAL  DEFAULT    1 $d
   438: 080740cc     0 NOTYPE  LOCAL  DEFAULT    3 $d
   439: 08043048     0 NOTYPE  LOCAL  DEFAULT    1 $t
   440: 0804307c     0 NOTYPE  LOCAL  DEFAULT    1 $d
   441: 08043086     0 NOTYPE  LOCAL  DEFAULT    1 $t
   442: 08043110     0 NOTYPE  LOCAL  DEFAULT    1 $d
   443: 080740cc     0 NOTYPE  LOCAL  DEFAULT    3 $d
   444: 08043124     0 NOTYPE  LOCAL  DEFAULT    1 $t
   445: 08043178     0 NOTYPE  LOCAL  DEFAULT    1 $d
   446: 080740d4     0 NOTYPE  LOCAL  DEFAULT    3 $d
   447: 0804317c     0 NOTYPE  LOCAL  DEFAULT    1 $t
   448: 080431c4     0 NOTYPE  LOCAL  DEFAULT    1 $d
   449: 080740dc     0 NOTYPE  LOCAL  DEFAULT    3 $d
   450: 080431c8     0 NOTYPE  LOCAL  DEFAULT    1 $t
   451: 08043200     0 NOTYPE  LOCAL  DEFAULT    1 $d
   452: 080740e4     0 NOTYPE  LOCAL  DEFAULT    3 $d
   453: 08043204     0 NOTYPE  LOCAL  DEFAULT    1 $t
   454: 0804323c     0 NOTYPE  LOCAL  DEFAULT    1 $d
   455: 080740ec     0 NOTYPE  LOCAL  DEFAULT    3 $d
   456: 08043240     0 NOTYPE  LOCAL  DEFAULT    1 $t
   457: 08043264     0 NOTYPE  LOCAL  DEFAULT    1 $d
   458: 080740f4     0 NOTYPE  LOCAL  DEFAULT    3 $d
   459: 08043268     0 NOTYPE  LOCAL  DEFAULT    1 $t
   460: 080432bc     0 NOTYPE  LOCAL  DEFAULT    1 $d
   461: 080740fc     0 NOTYPE  LOCAL  DEFAULT    3 $d
   462: 080432d0     0 NOTYPE  LOCAL  DEFAULT    1 $t
   463: 080433b0     0 NOTYPE  LOCAL  DEFAULT    1 $d
   464: 080740fc     0 NOTYPE  LOCAL  DEFAULT    3 $d
   465: 080433d8     0 NOTYPE  LOCAL  DEFAULT    1 $t
   466: 0804340c     0 NOTYPE  LOCAL  DEFAULT    1 $d
   467: 080740fc     0 NOTYPE  LOCAL  DEFAULT    3 $d
   468: 08043414     0 NOTYPE  LOCAL  DEFAULT    1 $t
   469: 08043490     0 NOTYPE  LOCAL  DEFAULT    1 $d
   470: 080740fc     0 NOTYPE  LOCAL  DEFAULT    3 $d
   471: 0804349c     0 NOTYPE  LOCAL  DEFAULT    1 $t
   472: 080434e4     0 NOTYPE  LOCAL  DEFAULT    1 $d
   473: 08074104     0 NOTYPE  LOCAL  DEFAULT    3 $d
   474: 080434e8     0 NOTYPE  LOCAL  DEFAULT    1 $t
   475: 08074104     0 NOTYPE  LOCAL  DEFAULT    3 $d
   476: 080434f0     0 NOTYPE  LOCAL  DEFAULT    1 $t
   477: 080434f4     0 NOTYPE  LOCAL  DEFAULT    1 $d
   478: 08074104     0 NOTYPE  LOCAL  DEFAULT    3 $d
   479: 080434f8     0 NOTYPE  LOCAL  DEFAULT    1 $t
   480: 08043514     0 NOTYPE  LOCAL  DEFAULT    1 $d
   481: 08074104     0 NOTYPE  LOCAL  DEFAULT    3 $d
   482: 0804351c     0 NOTYPE  LOCAL  DEFAULT    1 $t
   483: 08074104     0 NOTYPE  LOCAL  DEFAULT    3 $d
   484: 08043540     0 NOTYPE  LOCAL  DEFAULT    1 $t
   485: 080435ac     0 NOTYPE  LOCAL  DEFAULT    1 $d
   486: 0807410c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   487: 080435b4     0 NOTYPE  LOCAL  DEFAULT    1 $t
   488: 080435d4     0 NOTYPE  LOCAL  DEFAULT    1 $d
   489: 08074114     0 NOTYPE  LOCAL  DEFAULT    3 $d
   490: 080435d8     0 NOTYPE  LOCAL  DEFAULT    1 $t
   491: 080435d9   656 FUNC    LOCAL  DEFAULT    1 _ZL7mriMainPv
   492: 080437fc     0 NOTYPE  LOCAL  DEFAULT    1 $d
   493: 0807411c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   494: 08043868     0 NOTYPE  LOCAL  DEFAULT    1 $t
   495: 080438f4     0 NOTYPE  LOCAL  DEFAULT    1 $d
   496: 08074124     0 NOTYPE  LOCAL  DEFAULT    3 $d
   497: 08043938     0 NOTYPE  LOCAL  DEFAULT    1 $t
   498: 0804396c     0 NOTYPE  LOCAL  DEFAULT    1 $d
   499: 0807412c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   500: 08043974     0 NOTYPE  LOCAL  DEFAULT    1 $t
   501: 08043a00     0 NOTYPE  LOCAL  DEFAULT    1 $d
   502: 08074134     0 NOTYPE  LOCAL  DEFAULT    3 $d
   503: 08043a44     0 NOTYPE  LOCAL  DEFAULT    1 $t
   504: 08043a54     0 NOTYPE  LOCAL  DEFAULT    1 $d
   505: 0807354c     0 NOTYPE  LOCAL  DEFAULT    2 $d
   506: 0807413c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   507: 08043a58     0 NOTYPE  LOCAL  DEFAULT    1 $t
   508: 08043a68     0 NOTYPE  LOCAL  DEFAULT    1 $d
   509: 08073558     0 NOTYPE  LOCAL  DEFAULT    2 $d
   510: 08074144     0 NOTYPE  LOCAL  DEFAULT    3 $d
   511: 08043a6c     0 NOTYPE  LOCAL  DEFAULT    1 $t
   512: 08043a88     0 NOTYPE  LOCAL  DEFAULT    1 $d
   513: 0807414c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   514: 08043a8c     0 NOTYPE  LOCAL  DEFAULT    1 $t
   515: 08043a9c     0 NOTYPE  LOCAL  DEFAULT    1 $d
   516: 08074154     0 NOTYPE  LOCAL  DEFAULT    3 $d
   517: 08043aa0     0 NOTYPE  LOCAL  DEFAULT    1 $t
   518: 0807415c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   519: 08043aa8     0 NOTYPE  LOCAL  DEFAULT    1 $t
   520: 08043aac     0 NOTYPE  LOCAL  DEFAULT    1 $d
   521: 0807415c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   522: 08043ab0     0 NOTYPE  LOCAL  DEFAULT    1 $t
   523: 0807415c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   524: 08043ab4     0 NOTYPE  LOCAL  DEFAULT    1 $t
   525: 0807415c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   526: 08043ab8     0 NOTYPE  LOCAL  DEFAULT    1 $t
   527: 08043ac0     0 NOTYPE  LOCAL  DEFAULT    1 $d
   528: 0807415c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   529: 08043ac4     0 NOTYPE  LOCAL  DEFAULT    1 $t
   530: 08043adc     0 NOTYPE  LOCAL  DEFAULT    1 $d
   531: 0807415c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   532: 08043ae0     0 NOTYPE  LOCAL  DEFAULT    1 $t
   533: 08043afc     0 NOTYPE  LOCAL  DEFAULT    1 $d
   534: 0807415c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   535: 08043b00     0 NOTYPE  LOCAL  DEFAULT    1 $t
   536: 08043b14     0 NOTYPE  LOCAL  DEFAULT    1 $d
   537: 08073564     0 NOTYPE  LOCAL  DEFAULT    2 $d
   538: 0807415c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   539: 08043b18     0 NOTYPE  LOCAL  DEFAULT    1 $t
   540: 08043bbc     0 NOTYPE  LOCAL  DEFAULT    1 $d
   541: 08074164     0 NOTYPE  LOCAL  DEFAULT    3 $d
   542: 08043c00     0 NOTYPE  LOCAL  DEFAULT    1 $t
   543: 08043c24     0 NOTYPE  LOCAL  DEFAULT    1 $d
   544: 0807416c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   545: 08043c34     0 NOTYPE  LOCAL  DEFAULT    1 $t
   546: 08074174     0 NOTYPE  LOCAL  DEFAULT    3 $d
   547: 08043c38     0 NOTYPE  LOCAL  DEFAULT    1 $t
   548: 08043c8c     0 NOTYPE  LOCAL  DEFAULT    1 $d
   549: 0807417c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   550: 08043c94     0 NOTYPE  LOCAL  DEFAULT    1 $t
   551: 08043cd8     0 NOTYPE  LOCAL  DEFAULT    1 $d
   552: 08074184     0 NOTYPE  LOCAL  DEFAULT    3 $d
   553: 08043ce4     0 NOTYPE  LOCAL  DEFAULT    1 $t
   554: 08043d6c     0 NOTYPE  LOCAL  DEFAULT    1 $d
   555: 0807418c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   556: 08043d88     0 NOTYPE  LOCAL  DEFAULT    1 $t
   557: 08043e38     0 NOTYPE  LOCAL  DEFAULT    1 $d
   558: 08074194     0 NOTYPE  LOCAL  DEFAULT    3 $d
   559: 08043e50     0 NOTYPE  LOCAL  DEFAULT    1 $t
   560: 08043e58     0 NOTYPE  LOCAL  DEFAULT    1 $d
   561: 0807419c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   562: 0806d670     0 NOTYPE  LOCAL  DEFAULT    1 $d
   563: 24002bb8     0 NOTYPE  LOCAL  DEFAULT    6 $d
   564: 24002bb8     4 OBJECT  LOCAL  DEFAULT    6 _ZL10g_controlC
   565: 24002bbc     0 NOTYPE  LOCAL  DEFAULT    6 $d
   566: 24002bbc     4 OBJECT  LOCAL  DEFAULT    6 _ZL10g_threadSP
   567: 24002bc0     0 NOTYPE  LOCAL  DEFAULT    6 $d
   568: 24002bc0   132 OBJECT  LOCAL  DEFAULT    6 _ZL12g_tempFloats
   569: 24002c44     0 NOTYPE  LOCAL  DEFAULT    6 $d
   570: 24002c44    32 OBJECT  LOCAL  DEFAULT    6 _ZL13g_threadLists
   571: 24002c64     1 OBJECT  LOCAL  DEFAULT    6 _ZL14g_breakInSetup
   572: 24002c64     0 NOTYPE  LOCAL  DEFAULT    6 $d
   573: 24002c68     0 NOTYPE  LOCAL  DEFAULT    6 $d
   574: 24002c68     4 OBJECT  LOCAL  DEFAULT    6 _ZL15g_debugThreadId
   575: 24002c6c     0 NOTYPE  LOCAL  DEFAULT    6 $d
   576: 24002c6c     8 OBJECT  LOCAL  DEFAULT    6 _ZL15g_threadContext
   577: 24002c74     0 NOTYPE  LOCAL  DEFAULT    6 $d
   578: 24002c74     4 OBJECT  LOCAL  DEFAULT    6 _ZL16g_haltedThreadId
   579: 24002c78     0 NOTYPE  LOCAL  DEFAULT    6 $d
   580: 24002c78     4 OBJECT  LOCAL  DEFAULT    6 _ZL16g_maxThreadCount
   581: 24002c7c     0 NOTYPE  LOCAL  DEFAULT    6 $d
   582: 24002c7c    64 OBJECT  LOCAL  DEFAULT    6 _ZL17g_contextSections
   583: 24002cbc     0 NOTYPE  LOCAL  DEFAULT    6 $d
   584: 24002cbc     4 OBJECT  LOCAL  DEFAULT    6 _ZL17g_enableDWTandFPB
   585: 24002cc0     0 NOTYPE  LOCAL  DEFAULT    6 $d
   586: 24002cc0     4 OBJECT  LOCAL  DEFAULT    6 _ZL17g_mriIdleThreadId
   587: 24002cc4     0 NOTYPE  LOCAL  DEFAULT    6 $d
   588: 24002cc4     4 OBJECT  LOCAL  DEFAULT    6 _ZL17g_pCurrThreadList
   589: 24002cc8     0 NOTYPE  LOCAL  DEFAULT    6 $d
   590: 24002cc8     4 OBJECT  LOCAL  DEFAULT    6 _ZL17g_pPrevThreadList
   591: 24002ccc    64 OBJECT  LOCAL  DEFAULT    6 _ZL17g_threadExtraInfo
   592: 24002ccc     0 NOTYPE  LOCAL  DEFAULT    6 $d
   593: 24002d0c     0 NOTYPE  LOCAL  DEFAULT    6 $d
   594: 24002d0c     4 OBJECT  LOCAL  DEFAULT    6 _ZL19g_pAllActiveThreads
   595: 24002d10     0 NOTYPE  LOCAL  DEFAULT    6 $d
   596: 24002d10    64 OBJECT  LOCAL  DEFAULT    6 _ZL23g_threadContextSecti
   597: 24002d50     0 NOTYPE  LOCAL  DEFAULT    6 $d
   598: 24002d50     4 OBJECT  LOCAL  DEFAULT    6 _ZL7g_pComm
   599: 24002d54     0 NOTYPE  LOCAL  DEFAULT    6 $d
   600: 24002d54    68 OBJECT  LOCAL  DEFAULT    6 _ZZN7arduino11ThreadDebug
   601: 24002d98     0 NOTYPE  LOCAL  DEFAULT    6 $d
   602: 24002d98    68 OBJECT  LOCAL  DEFAULT    6 _ZZN7arduino11ThreadDebug
   603: 24002de0     0 NOTYPE  LOCAL  DEFAULT    6 $d
   604: 24002de0    80 OBJECT  LOCAL  DEFAULT    6 _ZZN7arduino11ThreadDebug
   605: 24002e30     0 NOTYPE  LOCAL  DEFAULT    6 $d
   606: 24002e30  1024 OBJECT  LOCAL  DEFAULT    6 _ZZN7arduino11ThreadDebug
   607: 24003230     0 NOTYPE  LOCAL  DEFAULT    6 $d
   608: 24003838     0 NOTYPE  LOCAL  DEFAULT    6 $d
   609: 2400383c     0 NOTYPE  LOCAL  DEFAULT    6 $d
   610: 24003a10     0 NOTYPE  LOCAL  DEFAULT    6 $d
   611: 24003a14     0 NOTYPE  LOCAL  DEFAULT    6 $d
   612: 24003a18     0 NOTYPE  LOCAL  DEFAULT    6 $d
   613: 24003a1c     0 NOTYPE  LOCAL  DEFAULT    6 $d
   614: 24003a20     0 NOTYPE  LOCAL  DEFAULT    6 $d
   615: 24003a24     0 NOTYPE  LOCAL  DEFAULT    6 $d
   616: 24003a28     0 NOTYPE  LOCAL  DEFAULT    6 $d
   617: 24003a2c     0 NOTYPE  LOCAL  DEFAULT    6 $d
   618: 24003a30     0 NOTYPE  LOCAL  DEFAULT    6 $d
   619: 0806d67c     3 OBJECT  LOCAL  DEFAULT    1 CSWTCH.322
   620: 0806d67f  1610 OBJECT  LOCAL  DEFAULT    1 _ZL11g_targetXml
   621: 0806dcc9  1295 OBJECT  LOCAL  DEFAULT    1 _ZL14g_memoryMapXml
   622: 0806e2a8     0 NOTYPE  LOCAL  DEFAULT    1 $d
   623: 0806e2cc     0 NOTYPE  LOCAL  DEFAULT    1 $d
   624: 0806e2cc    32 OBJECT  LOCAL  DEFAULT    1 _ZZ26determineCauseOfDebu
   625: 0806e2ec     0 NOTYPE  LOCAL  DEFAULT    1 $d
   626: 0806e2ec    36 OBJECT  LOCAL  DEFAULT    1 _ZZN7arduino11ThreadDebug
   627: 0806e310     0 NOTYPE  LOCAL  DEFAULT    1 $d
   628: 0806e310    36 OBJECT  LOCAL  DEFAULT    1 _ZZN7arduino11ThreadDebug
   629: 00000000     0 FILE    LOCAL  DEFAULT  ABS RPC.cpp
   630: 08043e5c     0 NOTYPE  LOCAL  DEFAULT    1 $t
   631: 080741a4     0 NOTYPE  LOCAL  DEFAULT    3 $d
   632: 08043e60     0 NOTYPE  LOCAL  DEFAULT    1 $t
   633: 080741a4     0 NOTYPE  LOCAL  DEFAULT    3 $d
   634: 08043e64     0 NOTYPE  LOCAL  DEFAULT    1 $t
   635: 080741a4     0 NOTYPE  LOCAL  DEFAULT    3 $d
   636: 08043e6a     0 NOTYPE  LOCAL  DEFAULT    1 $t
   637: 080741a4     0 NOTYPE  LOCAL  DEFAULT    3 $d
   638: 08043e6c     0 NOTYPE  LOCAL  DEFAULT    1 $t
   639: 080741a4     0 NOTYPE  LOCAL  DEFAULT    3 $d
   640: 08043e84     0 NOTYPE  LOCAL  DEFAULT    1 $t
   641: 080741a4     0 NOTYPE  LOCAL  DEFAULT    3 $d
   642: 08043eb4     0 NOTYPE  LOCAL  DEFAULT    1 $t
   643: 080741a4     0 NOTYPE  LOCAL  DEFAULT    3 $d
   644: 08043eec     0 NOTYPE  LOCAL  DEFAULT    1 $t
   645: 08043f08     0 NOTYPE  LOCAL  DEFAULT    1 $d
   646: 080741ac     0 NOTYPE  LOCAL  DEFAULT    3 $d
   647: 08043f0c     0 NOTYPE  LOCAL  DEFAULT    1 $t
   648: 08043f0d    36 FUNC    LOCAL  DEFAULT    1 rpmsg_send
   649: 08043f2c     0 NOTYPE  LOCAL  DEFAULT    1 $d
   650: 080741b4     0 NOTYPE  LOCAL  DEFAULT    3 $d
   651: 08043f30     0 NOTYPE  LOCAL  DEFAULT    1 $t
   652: 08043f40     0 NOTYPE  LOCAL  DEFAULT    1 $d
   653: 080741bc     0 NOTYPE  LOCAL  DEFAULT    3 $d
   654: 08043f44     0 NOTYPE  LOCAL  DEFAULT    1 $t
   655: 08043f60     0 NOTYPE  LOCAL  DEFAULT    1 $d
   656: 080741c4     0 NOTYPE  LOCAL  DEFAULT    3 $d
   657: 08043f64     0 NOTYPE  LOCAL  DEFAULT    1 $t
   658: 080741cc     0 NOTYPE  LOCAL  DEFAULT    3 $d
   659: 08043f84     0 NOTYPE  LOCAL  DEFAULT    1 $t
   660: 08043f94     0 NOTYPE  LOCAL  DEFAULT    1 $d
   661: 080741d4     0 NOTYPE  LOCAL  DEFAULT    3 $d
   662: 08043f98     0 NOTYPE  LOCAL  DEFAULT    1 $t
   663: 080741d4     0 NOTYPE  LOCAL  DEFAULT    3 $d
   664: 08043fac     0 NOTYPE  LOCAL  DEFAULT    1 $t
   665: 08043fbc     0 NOTYPE  LOCAL  DEFAULT    1 $d
   666: 080741d4     0 NOTYPE  LOCAL  DEFAULT    3 $d
   667: 08043fc0     0 NOTYPE  LOCAL  DEFAULT    1 $t
   668: 080741d4     0 NOTYPE  LOCAL  DEFAULT    3 $d
   669: 08043fd4     0 NOTYPE  LOCAL  DEFAULT    1 $t
   670: 08043fe4     0 NOTYPE  LOCAL  DEFAULT    1 $d
   671: 080741d4     0 NOTYPE  LOCAL  DEFAULT    3 $d
   672: 08043fe8     0 NOTYPE  LOCAL  DEFAULT    1 $t
   673: 080741d4     0 NOTYPE  LOCAL  DEFAULT    3 $d
   674: 08043ffc     0 NOTYPE  LOCAL  DEFAULT    1 $t
   675: 0804400c     0 NOTYPE  LOCAL  DEFAULT    1 $d
   676: 080741d4     0 NOTYPE  LOCAL  DEFAULT    3 $d
   677: 08044010     0 NOTYPE  LOCAL  DEFAULT    1 $t
   678: 080741d4     0 NOTYPE  LOCAL  DEFAULT    3 $d
   679: 08044024     0 NOTYPE  LOCAL  DEFAULT    1 $t
   680: 08044034     0 NOTYPE  LOCAL  DEFAULT    1 $d
   681: 080741d4     0 NOTYPE  LOCAL  DEFAULT    3 $d
   682: 08044038     0 NOTYPE  LOCAL  DEFAULT    1 $t
   683: 080741d4     0 NOTYPE  LOCAL  DEFAULT    3 $d
   684: 0804404c     0 NOTYPE  LOCAL  DEFAULT    1 $t
   685: 0804405c     0 NOTYPE  LOCAL  DEFAULT    1 $d
   686: 080741d4     0 NOTYPE  LOCAL  DEFAULT    3 $d
   687: 08044060     0 NOTYPE  LOCAL  DEFAULT    1 $t
   688: 080741d4     0 NOTYPE  LOCAL  DEFAULT    3 $d
   689: 08044074     0 NOTYPE  LOCAL  DEFAULT    1 $t
   690: 08044084     0 NOTYPE  LOCAL  DEFAULT    1 $d
   691: 080741d4     0 NOTYPE  LOCAL  DEFAULT    3 $d
   692: 08044088     0 NOTYPE  LOCAL  DEFAULT    1 $t
   693: 080741d4     0 NOTYPE  LOCAL  DEFAULT    3 $d
   694: 0804409c     0 NOTYPE  LOCAL  DEFAULT    1 $t
   695: 080440ac     0 NOTYPE  LOCAL  DEFAULT    1 $d
   696: 080741d4     0 NOTYPE  LOCAL  DEFAULT    3 $d
   697: 080440b0     0 NOTYPE  LOCAL  DEFAULT    1 $t
   698: 080741d4     0 NOTYPE  LOCAL  DEFAULT    3 $d
   699: 080440c4     0 NOTYPE  LOCAL  DEFAULT    1 $t
   700: 080440d4     0 NOTYPE  LOCAL  DEFAULT    1 $d
   701: 080741d4     0 NOTYPE  LOCAL  DEFAULT    3 $d
   702: 080440d8     0 NOTYPE  LOCAL  DEFAULT    1 $t
   703: 080741d4     0 NOTYPE  LOCAL  DEFAULT    3 $d
   704: 080440ec     0 NOTYPE  LOCAL  DEFAULT    1 $t
   705: 08044140     0 NOTYPE  LOCAL  DEFAULT    1 $d
   706: 080741d4     0 NOTYPE  LOCAL  DEFAULT    3 $d
   707: 08044164     0 NOTYPE  LOCAL  DEFAULT    1 $t
   708: 08044165    32 FUNC    LOCAL  DEFAULT    1 _ZN14clmdep_msgpack2v14zo
   709: 08044178     0 NOTYPE  LOCAL  DEFAULT    1 $d
   710: 08073570     0 NOTYPE  LOCAL  DEFAULT    2 $d
   711: 080741dc     0 NOTYPE  LOCAL  DEFAULT    3 $d
   712: 08044165    32 FUNC    LOCAL  DEFAULT    1 _ZN14clmdep_msgpack2v14zo
   713: 08044165    32 FUNC    LOCAL  DEFAULT    1 _ZN14clmdep_msgpack2v14zo
   714: 08044184     0 NOTYPE  LOCAL  DEFAULT    1 $t
   715: 08044185    52 FUNC    LOCAL  DEFAULT    1 _ZNKSt14default_deleteIN1
   716: 0807357c     0 NOTYPE  LOCAL  DEFAULT    2 $d
   717: 080741e4     0 NOTYPE  LOCAL  DEFAULT    3 $d
   718: 080441b8     0 NOTYPE  LOCAL  DEFAULT    1 $t
   719: 080741ec     0 NOTYPE  LOCAL  DEFAULT    3 $d
   720: 08044204     0 NOTYPE  LOCAL  DEFAULT    1 $t
   721: 08044205     8 FUNC    LOCAL  DEFAULT    1 _ZNSt12_Vector_baseIPN14c
   722: 080741f4     0 NOTYPE  LOCAL  DEFAULT    3 $d
   723: 0804420c     0 NOTYPE  LOCAL  DEFAULT    1 $t
   724: 080741fc     0 NOTYPE  LOCAL  DEFAULT    3 $d
   725: 08044228     0 NOTYPE  LOCAL  DEFAULT    1 $t
   726: 08044229     8 FUNC    LOCAL  DEFAULT    1 _ZNSt12_Vector_baseIN14cl
   727: 080741fc     0 NOTYPE  LOCAL  DEFAULT    3 $d
   728: 08044230     0 NOTYPE  LOCAL  DEFAULT    1 $t
   729: 08044231    36 FUNC    LOCAL  DEFAULT    1 _ZSt22__uninitialized_cop
   730: 080741fc     0 NOTYPE  LOCAL  DEFAULT    3 $d
   731: 08044254     0 NOTYPE  LOCAL  DEFAULT    1 $t
   732: 08044255    56 FUNC    LOCAL  DEFAULT    1 _ZN14clmdep_msgpack2v26de
   733: 0804427c     0 NOTYPE  LOCAL  DEFAULT    1 $d
   734: 08073588     0 NOTYPE  LOCAL  DEFAULT    2 $d
   735: 080741fc     0 NOTYPE  LOCAL  DEFAULT    3 $d
   736: 0804428c     0 NOTYPE  LOCAL  DEFAULT    1 $t
   737: 08074204     0 NOTYPE  LOCAL  DEFAULT    3 $d
   738: 080442c2     0 NOTYPE  LOCAL  DEFAULT    1 $t
   739: 0807420c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   740: 0804430c     0 NOTYPE  LOCAL  DEFAULT    1 $t
   741: 0804433c     0 NOTYPE  LOCAL  DEFAULT    1 $d
   742: 08074214     0 NOTYPE  LOCAL  DEFAULT    3 $d
   743: 08044348     0 NOTYPE  LOCAL  DEFAULT    1 $t
   744: 0807421c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   745: 080443b8     0 NOTYPE  LOCAL  DEFAULT    1 $t
   746: 08074224     0 NOTYPE  LOCAL  DEFAULT    3 $d
   747: 080443dc     0 NOTYPE  LOCAL  DEFAULT    1 $t
   748: 0804444c     0 NOTYPE  LOCAL  DEFAULT    1 $d
   749: 0807359c     0 NOTYPE  LOCAL  DEFAULT    2 $d
   750: 0807422c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   751: 0804445c     0 NOTYPE  LOCAL  DEFAULT    1 $t
   752: 080444cc     0 NOTYPE  LOCAL  DEFAULT    1 $d
   753: 080735b0     0 NOTYPE  LOCAL  DEFAULT    2 $d
   754: 08074234     0 NOTYPE  LOCAL  DEFAULT    3 $d
   755: 080444dc     0 NOTYPE  LOCAL  DEFAULT    1 $t
   756: 0804454c     0 NOTYPE  LOCAL  DEFAULT    1 $d
   757: 080735c4     0 NOTYPE  LOCAL  DEFAULT    2 $d
   758: 0807423c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   759: 0804455c     0 NOTYPE  LOCAL  DEFAULT    1 $t
   760: 080445b8     0 NOTYPE  LOCAL  DEFAULT    1 $d
   761: 080735d8     0 NOTYPE  LOCAL  DEFAULT    2 $d
   762: 08074244     0 NOTYPE  LOCAL  DEFAULT    3 $d
   763: 080445bc     0 NOTYPE  LOCAL  DEFAULT    1 $t
   764: 080445dc     0 NOTYPE  LOCAL  DEFAULT    1 $d
   765: 080735f4     0 NOTYPE  LOCAL  DEFAULT    2 $d
   766: 0807424c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   767: 080445e0     0 NOTYPE  LOCAL  DEFAULT    1 $t
   768: 080445ec     0 NOTYPE  LOCAL  DEFAULT    1 $d
   769: 08074254     0 NOTYPE  LOCAL  DEFAULT    3 $d
   770: 080445f0     0 NOTYPE  LOCAL  DEFAULT    1 $t
   771: 0807425c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   772: 080445f8     0 NOTYPE  LOCAL  DEFAULT    1 $t
   773: 0807425c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   774: 0804460e     0 NOTYPE  LOCAL  DEFAULT    1 $t
   775: 0807425c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   776: 0804461c     0 NOTYPE  LOCAL  DEFAULT    1 $t
   777: 080446a0     0 NOTYPE  LOCAL  DEFAULT    1 $d
   778: 08073600     0 NOTYPE  LOCAL  DEFAULT    2 $d
   779: 0807425c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   780: 080446a4     0 NOTYPE  LOCAL  DEFAULT    1 $t
   781: 08074264     0 NOTYPE  LOCAL  DEFAULT    3 $d
   782: 080446ba     0 NOTYPE  LOCAL  DEFAULT    1 $t
   783: 0807426c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   784: 080446e6     0 NOTYPE  LOCAL  DEFAULT    1 $t
   785: 0807426c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   786: 080446fc     0 NOTYPE  LOCAL  DEFAULT    1 $t
   787: 0807361c     0 NOTYPE  LOCAL  DEFAULT    2 $d
   788: 0807426c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   789: 0804474c     0 NOTYPE  LOCAL  DEFAULT    1 $t
   790: 080447a0     0 NOTYPE  LOCAL  DEFAULT    1 $d
   791: 08073628     0 NOTYPE  LOCAL  DEFAULT    2 $d
   792: 08074274     0 NOTYPE  LOCAL  DEFAULT    3 $d
   793: 080447a8     0 NOTYPE  LOCAL  DEFAULT    1 $t
   794: 080448b4     0 NOTYPE  LOCAL  DEFAULT    1 $d
   795: 08073634     0 NOTYPE  LOCAL  DEFAULT    2 $d
   796: 0807427c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   797: 080448c4     0 NOTYPE  LOCAL  DEFAULT    1 $t
   798: 08044a58     0 NOTYPE  LOCAL  DEFAULT    1 $d
   799: 0807365c     0 NOTYPE  LOCAL  DEFAULT    2 $d
   800: 08074284     0 NOTYPE  LOCAL  DEFAULT    3 $d
   801: 08044a84     0 NOTYPE  LOCAL  DEFAULT    1 $t
   802: 0807428c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   803: 08044ab6     0 NOTYPE  LOCAL  DEFAULT    1 $t
   804: 08074294     0 NOTYPE  LOCAL  DEFAULT    3 $d
   805: 08044b26     0 NOTYPE  LOCAL  DEFAULT    1 $t
   806: 0807429c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   807: 08044b58     0 NOTYPE  LOCAL  DEFAULT    1 $t
   808: 0807429c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   809: 08044bc6     0 NOTYPE  LOCAL  DEFAULT    1 $t
   810: 080742a4     0 NOTYPE  LOCAL  DEFAULT    3 $d
   811: 08044bec     0 NOTYPE  LOCAL  DEFAULT    1 $t
   812: 080742ac     0 NOTYPE  LOCAL  DEFAULT    3 $d
   813: 08044c08     0 NOTYPE  LOCAL  DEFAULT    1 $t
   814: 08044c6c     0 NOTYPE  LOCAL  DEFAULT    1 $d
   815: 080742b4     0 NOTYPE  LOCAL  DEFAULT    3 $d
   816: 08044c70     0 NOTYPE  LOCAL  DEFAULT    1 $t
   817: 08044d24     0 NOTYPE  LOCAL  DEFAULT    1 $d
   818: 08073694     0 NOTYPE  LOCAL  DEFAULT    2 $d
   819: 080742bc     0 NOTYPE  LOCAL  DEFAULT    3 $d
   820: 08044d44     0 NOTYPE  LOCAL  DEFAULT    1 $t
   821: 080742c4     0 NOTYPE  LOCAL  DEFAULT    3 $d
   822: 08044d64     0 NOTYPE  LOCAL  DEFAULT    1 $t
   823: 08044e0c     0 NOTYPE  LOCAL  DEFAULT    1 $d
   824: 080736b8     0 NOTYPE  LOCAL  DEFAULT    2 $d
   825: 080742cc     0 NOTYPE  LOCAL  DEFAULT    3 $d
   826: 08044e2c     0 NOTYPE  LOCAL  DEFAULT    1 $t
   827: 08045026     0 NOTYPE  LOCAL  DEFAULT    1 $d
   828: 08045064     0 NOTYPE  LOCAL  DEFAULT    1 $t
   829: 080450fc     0 NOTYPE  LOCAL  DEFAULT    1 $d
   830: 0804510c     0 NOTYPE  LOCAL  DEFAULT    1 $t
   831: 080452fc     0 NOTYPE  LOCAL  DEFAULT    1 $d
   832: 080736dc     0 NOTYPE  LOCAL  DEFAULT    2 $d
   833: 080742d4     0 NOTYPE  LOCAL  DEFAULT    3 $d
   834: 0804530c     0 NOTYPE  LOCAL  DEFAULT    1 $t
   835: 08045428     0 NOTYPE  LOCAL  DEFAULT    1 $d
   836: 080736fc     0 NOTYPE  LOCAL  DEFAULT    2 $d
   837: 080742dc     0 NOTYPE  LOCAL  DEFAULT    3 $d
   838: 08045434     0 NOTYPE  LOCAL  DEFAULT    1 $t
   839: 080454f4     0 NOTYPE  LOCAL  DEFAULT    1 $d
   840: 08073720     0 NOTYPE  LOCAL  DEFAULT    2 $d
   841: 080742e4     0 NOTYPE  LOCAL  DEFAULT    3 $d
   842: 08045500     0 NOTYPE  LOCAL  DEFAULT    1 $t
   843: 080455e8     0 NOTYPE  LOCAL  DEFAULT    1 $d
   844: 080742ec     0 NOTYPE  LOCAL  DEFAULT    3 $d
   845: 080455ec     0 NOTYPE  LOCAL  DEFAULT    1 $t
   846: 08045754     0 NOTYPE  LOCAL  DEFAULT    1 $d
   847: 08073744     0 NOTYPE  LOCAL  DEFAULT    2 $d
   848: 080742f4     0 NOTYPE  LOCAL  DEFAULT    3 $d
   849: 08045758     0 NOTYPE  LOCAL  DEFAULT    1 $t
   850: 08045759    36 FUNC    LOCAL  DEFAULT    1 _GLOBAL__sub_I__ZN3rpc6cl
   851: 08045770     0 NOTYPE  LOCAL  DEFAULT    1 $d
   852: 080742fc     0 NOTYPE  LOCAL  DEFAULT    3 $d
   853: 24001a58     0 NOTYPE  LOCAL  DEFAULT    4 $d
   854: 0806e62c     0 NOTYPE  LOCAL  DEFAULT    1 $d
   855: 0806e660     0 NOTYPE  LOCAL  DEFAULT    1 $d
   856: 0806e698     0 NOTYPE  LOCAL  DEFAULT    1 $d
   857: 0806e6d0     0 NOTYPE  LOCAL  DEFAULT    1 $d
   858: 0806e708     0 NOTYPE  LOCAL  DEFAULT    1 $d
   859: 0806e740     0 NOTYPE  LOCAL  DEFAULT    1 $d
   860: 0806e778     0 NOTYPE  LOCAL  DEFAULT    1 $d
   861: 0806e7a8     0 NOTYPE  LOCAL  DEFAULT    1 $d
   862: 0806e7e0     0 NOTYPE  LOCAL  DEFAULT    1 $d
   863: 0806e7ec     0 NOTYPE  LOCAL  DEFAULT    1 $d
   864: 0806e800     0 NOTYPE  LOCAL  DEFAULT    1 $d
   865: 0806e814     0 NOTYPE  LOCAL  DEFAULT    1 $d
   866: 0806e828     0 NOTYPE  LOCAL  DEFAULT    1 $d
   867: 0806e83c     0 NOTYPE  LOCAL  DEFAULT    1 $d
   868: 0806e850     0 NOTYPE  LOCAL  DEFAULT    1 $d
   869: 0806e864     0 NOTYPE  LOCAL  DEFAULT    1 $d
   870: 0806e878     0 NOTYPE  LOCAL  DEFAULT    1 $d
   871: 0806e88c     0 NOTYPE  LOCAL  DEFAULT    1 $d
   872: 0806e8a0     0 NOTYPE  LOCAL  DEFAULT    1 $d
   873: 0806e8ac     0 NOTYPE  LOCAL  DEFAULT    1 $d
   874: 0806e8b8     0 NOTYPE  LOCAL  DEFAULT    1 $d
   875: 24003a38     0 NOTYPE  LOCAL  DEFAULT    6 $d
   876: 24003d00     0 NOTYPE  LOCAL  DEFAULT    6 $d
   877: 24003d00   256 OBJECT  LOCAL  DEFAULT    6 _ZL12rp_endpoints
   878: 24003e00     0 NOTYPE  LOCAL  DEFAULT    6 $d
   879: 0806ea94     0 NOTYPE  LOCAL  DEFAULT    1 $d
   880: 0806eab8   213 OBJECT  LOCAL  DEFAULT    1 _ZZN14clmdep_msgpack2v26d
   881: 00000000     0 FILE    LOCAL  DEFAULT  ABS SerialRPC.cpp
   882: 0804577c     0 NOTYPE  LOCAL  DEFAULT    1 $t
   883: 08074304     0 NOTYPE  LOCAL  DEFAULT    3 $d
   884: 08045782     0 NOTYPE  LOCAL  DEFAULT    1 $t
   885: 08074304     0 NOTYPE  LOCAL  DEFAULT    3 $d
   886: 08045784     0 NOTYPE  LOCAL  DEFAULT    1 $t
   887: 08074304     0 NOTYPE  LOCAL  DEFAULT    3 $d
   888: 0804579c     0 NOTYPE  LOCAL  DEFAULT    1 $t
   889: 08074304     0 NOTYPE  LOCAL  DEFAULT    3 $d
   890: 080457ce     0 NOTYPE  LOCAL  DEFAULT    1 $t
   891: 08074304     0 NOTYPE  LOCAL  DEFAULT    3 $d
   892: 08045812     0 NOTYPE  LOCAL  DEFAULT    1 $t
   893: 0807430c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   894: 08045824     0 NOTYPE  LOCAL  DEFAULT    1 $t
   895: 08045844     0 NOTYPE  LOCAL  DEFAULT    1 $d
   896: 0807377c     0 NOTYPE  LOCAL  DEFAULT    2 $d
   897: 08074314     0 NOTYPE  LOCAL  DEFAULT    3 $d
   898: 08045848     0 NOTYPE  LOCAL  DEFAULT    1 $t
   899: 0807431c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   900: 08045910     0 NOTYPE  LOCAL  DEFAULT    1 $t
   901: 08073788     0 NOTYPE  LOCAL  DEFAULT    2 $d
   902: 08074324     0 NOTYPE  LOCAL  DEFAULT    3 $d
   903: 080459d0     0 NOTYPE  LOCAL  DEFAULT    1 $t
   904: 08045b90     0 NOTYPE  LOCAL  DEFAULT    1 $d
   905: 080737b4     0 NOTYPE  LOCAL  DEFAULT    2 $d
   906: 0807432c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   907: 08045ba0     0 NOTYPE  LOCAL  DEFAULT    1 $t
   908: 08074334     0 NOTYPE  LOCAL  DEFAULT    3 $d
   909: 08045bb8     0 NOTYPE  LOCAL  DEFAULT    1 $t
   910: 08045bb9    88 FUNC    LOCAL  DEFAULT    1 _GLOBAL__sub_I_SerialRPC
   911: 08045c00     0 NOTYPE  LOCAL  DEFAULT    1 $d
   912: 0807433c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   913: 24001a5c     0 NOTYPE  LOCAL  DEFAULT    4 $d
   914: 0806eb90     0 NOTYPE  LOCAL  DEFAULT    1 $d
   915: 24003e04     0 NOTYPE  LOCAL  DEFAULT    6 $d
   916: 00000000     0 FILE    LOCAL  DEFAULT  ABS format.cpp
   917: 08045c10     0 NOTYPE  LOCAL  DEFAULT    1 $t
   918: 08045c2c     0 NOTYPE  LOCAL  DEFAULT    1 $d
   919: 08074344     0 NOTYPE  LOCAL  DEFAULT    3 $d
   920: 08045c30     0 NOTYPE  LOCAL  DEFAULT    1 $t
   921: 08045c44     0 NOTYPE  LOCAL  DEFAULT    1 $d
   922: 08074344     0 NOTYPE  LOCAL  DEFAULT    3 $d
   923: 08045c48     0 NOTYPE  LOCAL  DEFAULT    1 $t
   924: 08074344     0 NOTYPE  LOCAL  DEFAULT    3 $d
   925: 08045c5e     0 NOTYPE  LOCAL  DEFAULT    1 $t
   926: 08074344     0 NOTYPE  LOCAL  DEFAULT    3 $d
   927: 08045c74     0 NOTYPE  LOCAL  DEFAULT    1 $t
   928: 08045c84     0 NOTYPE  LOCAL  DEFAULT    1 $d
   929: 08074344     0 NOTYPE  LOCAL  DEFAULT    3 $d
   930: 08045c88     0 NOTYPE  LOCAL  DEFAULT    1 $t
   931: 08074344     0 NOTYPE  LOCAL  DEFAULT    3 $d
   932: 08045c9c     0 NOTYPE  LOCAL  DEFAULT    1 $t
   933: 08045c9d    24 FUNC    LOCAL  DEFAULT    1 _ZN10clmdep_fmt12_GLOBAL_
   934: 08074344     0 NOTYPE  LOCAL  DEFAULT    3 $d
   935: 08045cb4     0 NOTYPE  LOCAL  DEFAULT    1 $t
   936: 08045cb5    72 FUNC    LOCAL  DEFAULT    1 _ZNSt7__cxx1112basic_stri
   937: 08045cf8     0 NOTYPE  LOCAL  DEFAULT    1 $d
   938: 08074344     0 NOTYPE  LOCAL  DEFAULT    3 $d
   939: 08045cfc     0 NOTYPE  LOCAL  DEFAULT    1 $t
   940: 08045cfd    14 FUNC    LOCAL  DEFAULT    1 _ZSt8__fill_aIcEN9__gnu_c
   941: 0807434c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   942: 08045d0a     0 NOTYPE  LOCAL  DEFAULT    1 $t
   943: 08045d0b    48 FUNC    LOCAL  DEFAULT    1 _ZNKSt4lessIN10clmdep_fmt
   944: 08074354     0 NOTYPE  LOCAL  DEFAULT    3 $d
   945: 08045d3a     0 NOTYPE  LOCAL  DEFAULT    1 $t
   946: 08074354     0 NOTYPE  LOCAL  DEFAULT    3 $d
   947: 08045d42     0 NOTYPE  LOCAL  DEFAULT    1 $t
   948: 08074354     0 NOTYPE  LOCAL  DEFAULT    3 $d
   949: 08045d88     0 NOTYPE  LOCAL  DEFAULT    1 $t
   950: 08045d98     0 NOTYPE  LOCAL  DEFAULT    1 $d
   951: 08074354     0 NOTYPE  LOCAL  DEFAULT    3 $d
   952: 08045d9c     0 NOTYPE  LOCAL  DEFAULT    1 $t
   953: 08045d9d   124 FUNC    LOCAL  DEFAULT    1 _ZN10clmdep_fmt12_GLOBAL_
   954: 08045e00     0 NOTYPE  LOCAL  DEFAULT    1 $d
   955: 080737dc     0 NOTYPE  LOCAL  DEFAULT    2 $d
   956: 0807435c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   957: 08045e18     0 NOTYPE  LOCAL  DEFAULT    1 $t
   958: 08045e54     0 NOTYPE  LOCAL  DEFAULT    1 $d
   959: 08074364     0 NOTYPE  LOCAL  DEFAULT    3 $d
   960: 08045e58     0 NOTYPE  LOCAL  DEFAULT    1 $t
   961: 08045e7c     0 NOTYPE  LOCAL  DEFAULT    1 $d
   962: 0807436c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   963: 08045e80     0 NOTYPE  LOCAL  DEFAULT    1 $t
   964: 0807436c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   965: 08045f34     0 NOTYPE  LOCAL  DEFAULT    1 $t
   966: 08045f60     0 NOTYPE  LOCAL  DEFAULT    1 $d
   967: 0807436c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   968: 08045f64     0 NOTYPE  LOCAL  DEFAULT    1 $t
   969: 08045f8c     0 NOTYPE  LOCAL  DEFAULT    1 $d
   970: 0807436c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   971: 08045f90     0 NOTYPE  LOCAL  DEFAULT    1 $t
   972: 08045fb8     0 NOTYPE  LOCAL  DEFAULT    1 $d
   973: 0807436c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   974: 08045fbc     0 NOTYPE  LOCAL  DEFAULT    1 $t
   975: 0807436c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   976: 08045fec     0 NOTYPE  LOCAL  DEFAULT    1 $t
   977: 0807436c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   978: 0804601c     0 NOTYPE  LOCAL  DEFAULT    1 $t
   979: 0807436c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   980: 08046032     0 NOTYPE  LOCAL  DEFAULT    1 $t
   981: 08046033    22 FUNC    LOCAL  DEFAULT    1 _ZN10clmdep_fmt11BasicWri
   982: 08074374     0 NOTYPE  LOCAL  DEFAULT    3 $d
   983: 08046048     0 NOTYPE  LOCAL  DEFAULT    1 $t
   984: 080460bc     0 NOTYPE  LOCAL  DEFAULT    1 $d
   985: 080737f4     0 NOTYPE  LOCAL  DEFAULT    2 $d
   986: 08074374     0 NOTYPE  LOCAL  DEFAULT    3 $d
   987: 080460c8     0 NOTYPE  LOCAL  DEFAULT    1 $t
   988: 0807437c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   989: 080460e6     0 NOTYPE  LOCAL  DEFAULT    1 $t
   990: 08074384     0 NOTYPE  LOCAL  DEFAULT    3 $d
   991: 080460f4     0 NOTYPE  LOCAL  DEFAULT    1 $t
   992: 08074384     0 NOTYPE  LOCAL  DEFAULT    3 $d
   993: 0804610c     0 NOTYPE  LOCAL  DEFAULT    1 $t
   994: 08046160     0 NOTYPE  LOCAL  DEFAULT    1 $d
   995: 08074384     0 NOTYPE  LOCAL  DEFAULT    3 $d
   996: 0804616c     0 NOTYPE  LOCAL  DEFAULT    1 $t
   997: 0804616d    28 FUNC    LOCAL  DEFAULT    1 _ZN10clmdep_fmt8internal1
   998: 0807438c     0 NOTYPE  LOCAL  DEFAULT    3 $d
   999: 08046188     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1000: 08074394     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1001: 080461c8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1002: 08046214     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1003: 0807439c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1004: 08046218     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1005: 080743a4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1006: 08046246     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1007: 080743a4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1008: 080462a6     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1009: 080743ac     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1010: 0804634e     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1011: 080743b4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1012: 0804649c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1013: 08046564     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1014: 08073808     0 NOTYPE  LOCAL  DEFAULT    2 $d
  1015: 080743bc     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1016: 08046580     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1017: 080465f0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1018: 080743c4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1019: 080465f4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1020: 080743cc     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1021: 08046602     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1022: 080743cc     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1023: 08046748     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1024: 080743d4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1025: 08046890     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1026: 08046a98     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1027: 08073824     0 NOTYPE  LOCAL  DEFAULT    2 $d
  1028: 080743d4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1029: 08046ab4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1030: 08046ac8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1031: 08046c18     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1032: 080743dc     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1033: 08046c30     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1034: 080471f9    76 FUNC    LOCAL  DEFAULT    1 _ZN10clmdep_fmt12_GLOBAL_
  1035: 08047245   112 FUNC    LOCAL  DEFAULT    1 _ZN10clmdep_fmt12_GLOBAL_
  1036: 08046e4e     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1037: 08046e52     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1038: 08046f08     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1039: 08046f0c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1040: 08046f64     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1041: 08046f88     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1042: 08047040     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1043: 08073830     0 NOTYPE  LOCAL  DEFAULT    2 $d
  1044: 080743e4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1045: 08047054     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1046: 080470e8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1047: 080738c0     0 NOTYPE  LOCAL  DEFAULT    2 $d
  1048: 080743ec     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1049: 080470f4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1050: 080738dc     0 NOTYPE  LOCAL  DEFAULT    2 $d
  1051: 080743f4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1052: 08047144     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1053: 080471bc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1054: 080738f0     0 NOTYPE  LOCAL  DEFAULT    2 $d
  1055: 080743fc     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1056: 080471c4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1057: 080471c5    52 FUNC    LOCAL  DEFAULT    1 _ZN10clmdep_fmt6formatIJc
  1058: 08074404     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1059: 080471f8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1060: 08047238     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1061: 08073908     0 NOTYPE  LOCAL  DEFAULT    2 $d
  1062: 0807440c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1063: 08047244     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1064: 080472a8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1065: 08073924     0 NOTYPE  LOCAL  DEFAULT    2 $d
  1066: 08074414     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1067: 080472b4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1068: 08047360     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1069: 08073940     0 NOTYPE  LOCAL  DEFAULT    2 $d
  1070: 0807441c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1071: 08047370     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1072: 080474e0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1073: 08074424     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1074: 080474f0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1075: 080475a8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1076: 08073968     0 NOTYPE  LOCAL  DEFAULT    2 $d
  1077: 0807442c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1078: 080475b4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1079: 0804770c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1080: 08074434     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1081: 0804771c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1082: 0807443c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1083: 08047748     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1084: 08047908     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1085: 08074444     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1086: 08047918     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1087: 08047ab4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1088: 0807444c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1089: 08047ac4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1090: 08047bc8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1091: 0807444c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1092: 08047bd8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1093: 08047c2c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1094: 08073984     0 NOTYPE  LOCAL  DEFAULT    2 $d
  1095: 08074454     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1096: 08047c40     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1097: 08047e48     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1098: 0807399c     0 NOTYPE  LOCAL  DEFAULT    2 $d
  1099: 0807445c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1100: 0806ebdc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1101: 0806ebe8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1102: 0806ebfc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1103: 0806ec10     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1104: 240000d0     0 NOTYPE  LOCAL  DEFAULT    4 $d
  1105: 24000170     0 NOTYPE  LOCAL  DEFAULT    4 $d
  1106: 0806f046    84 OBJECT  LOCAL  DEFAULT    1 _ZZN10clmdep_fmt12_GLOBAL
  1107: 0806f09a   108 OBJECT  LOCAL  DEFAULT    1 _ZZN10clmdep_fmt14BasicFo
  1108: 0806f106    81 OBJECT  LOCAL  DEFAULT    1 _ZZN10clmdep_fmt6BufferIc
  1109: 0806f157   165 OBJECT  LOCAL  DEFAULT    1 _ZZN10clmdep_fmt8internal
  1110: 08046ad5     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1111: 08046ad6     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1112: 00000000     0 FILE    LOCAL  DEFAULT  ABS dispatcher.cpp
  1113: 08047e64     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1114: 08074464     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1115: 08047e66     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1116: 0807446c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1117: 08047e6a     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1118: 0807446c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1119: 08047e6c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1120: 0807446c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1121: 08047e70     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1122: 0807446c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1123: 08047e74     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1124: 0807446c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1125: 08047e78     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1126: 0807446c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1127: 08047e86     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1128: 0807446c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1129: 08047e94     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1130: 08047ea4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1131: 0807446c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1132: 08047ea8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1133: 0807446c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1134: 08047ebc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1135: 08047ebd    32 FUNC    LOCAL  DEFAULT    1 _ZNSt16_Sp_counted_baseIL
  1136: 0807446c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1137: 08047edc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1138: 08047edd    32 FUNC    LOCAL  DEFAULT    1 _ZN14clmdep_msgpack2v14zo
  1139: 08047ef0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1140: 080739a8     0 NOTYPE  LOCAL  DEFAULT    2 $d
  1141: 0807446c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1142: 08047edd    32 FUNC    LOCAL  DEFAULT    1 _ZN14clmdep_msgpack2v14zo
  1143: 08047efc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1144: 08047efd    60 FUNC    LOCAL  DEFAULT    1 _ZNK14clmdep_msgpack2v17a
  1145: 08047f2c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1146: 08074474     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1147: 08047f38     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1148: 08047f39    32 FUNC    LOCAL  DEFAULT    1 _ZN14clmdep_msgpack2v14ty
  1149: 08047f4c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1150: 080739b4     0 NOTYPE  LOCAL  DEFAULT    2 $d
  1151: 0807447c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1152: 08047f39    32 FUNC    LOCAL  DEFAULT    1 _ZN14clmdep_msgpack2v14ty
  1153: 08047f58     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1154: 08074484     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1155: 08047f74     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1156: 0807448c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1157: 08047f88     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1158: 08074494     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1159: 08047fa4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1160: 08047fec     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1161: 080739c0     0 NOTYPE  LOCAL  DEFAULT    2 $d
  1162: 0807449c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1163: 08047ff8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1164: 08048060     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1165: 080744a4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1166: 0804806c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1167: 080480f4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1168: 080744ac     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1169: 08048100     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1170: 0804816c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1171: 080739cc     0 NOTYPE  LOCAL  DEFAULT    2 $d
  1172: 080744ac     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1173: 08048170     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1174: 080739d8     0 NOTYPE  LOCAL  DEFAULT    2 $d
  1175: 080744b4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1176: 080481f8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1177: 08048224     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1178: 080744bc     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1179: 08048228     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1180: 080744c4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1181: 08048238     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1182: 0804835c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1183: 08073a10     0 NOTYPE  LOCAL  DEFAULT    2 $d
  1184: 080744cc     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1185: 08048360     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1186: 0804843a     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1187: 0804843e     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1188: 080485bc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1189: 08073a44     0 NOTYPE  LOCAL  DEFAULT    2 $d
  1190: 080744d4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1191: 080485cc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1192: 080744dc     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1193: 080485ee     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1194: 080744e4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1195: 0806f220     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1196: 0806f248     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1197: 0806f274     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1198: 0806f2a4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1199: 0806f2ac     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1200: 0806f2c0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1201: 0806f2dc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1202: 00000000     0 FILE    LOCAL  DEFAULT  ABS response.cpp
  1203: 0804860c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1204: 0804860d    32 FUNC    LOCAL  DEFAULT    1 _ZN14clmdep_msgpack2v14zo
  1205: 08048620     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1206: 08073ac0     0 NOTYPE  LOCAL  DEFAULT    2 $d
  1207: 080744ec     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1208: 0804860d    32 FUNC    LOCAL  DEFAULT    1 _ZN14clmdep_msgpack2v17sb
  1209: 0804860d    32 FUNC    LOCAL  DEFAULT    1 _ZN14clmdep_msgpack2v14zo
  1210: 0804862c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1211: 0804862d    52 FUNC    LOCAL  DEFAULT    1 _ZNKSt14default_deleteIN1
  1212: 08073acc     0 NOTYPE  LOCAL  DEFAULT    2 $d
  1213: 080744f4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1214: 08048660     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1215: 08048661    32 FUNC    LOCAL  DEFAULT    1 _ZNK14clmdep_msgpack2v17a
  1216: 08048674     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1217: 08073ad8     0 NOTYPE  LOCAL  DEFAULT    2 $d
  1218: 080744fc     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1219: 08048661    32 FUNC    LOCAL  DEFAULT    1 _ZNK14clmdep_msgpack2v17a
  1220: 08048680     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1221: 08048692     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1222: 08074504     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1223: 080486f4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1224: 0807450c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1225: 08048704     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1226: 0807450c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1227: 08048708     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1228: 0807450c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1229: 0804871a     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1230: 0807450c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1231: 0804872a     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1232: 0807450c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1233: 0804872e     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1234: 0807450c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1235: 0804875a     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1236: 08048770     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1237: 08074514     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1238: 08048848     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1239: 08048870     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1240: 08073ae4     0 NOTYPE  LOCAL  DEFAULT    2 $d
  1241: 0807451c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1242: 0804887c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1243: 08048908     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1244: 08074524     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1245: 08048914     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1246: 0807452c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1247: 0804893c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1248: 08048988     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1249: 08073af0     0 NOTYPE  LOCAL  DEFAULT    2 $d
  1250: 08074534     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1251: 0804898c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1252: 08073b10     0 NOTYPE  LOCAL  DEFAULT    2 $d
  1253: 0807453c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1254: 080489e6     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1255: 08073b28     0 NOTYPE  LOCAL  DEFAULT    2 $d
  1256: 08074544     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1257: 08048b56     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1258: 0807454c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1259: 08048b9e     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1260: 08074554     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1261: 08048be8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1262: 08048bf8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1263: 08048c08     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1264: 08074554     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1265: 08048c7a     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1266: 08074554     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1267: 08048cc2     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1268: 08074554     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1269: 08048d50     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1270: 08048e30     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1271: 0807455c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1272: 08048e34     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1273: 08048e48     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1274: 08074564     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1275: 08048f50     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1276: 0807456c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1277: 08048f62     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1278: 08074574     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1279: 08048fb8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1280: 08073b58     0 NOTYPE  LOCAL  DEFAULT    2 $d
  1281: 08074574     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1282: 08048697     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1283: 08048698     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1284: 0804877b     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1285: 0804877c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1286: 08048e53     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1287: 08048e54     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1288: 00000000     0 FILE    LOCAL  DEFAULT  ABS openamp.c
  1289: 08049058     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1290: 08049184     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1291: 080491b8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1292: 080491d4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1293: 080491d8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1294: 080491e0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1295: 080491e4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1296: 08049220     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1297: 0806f454     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1298: 2400423c     0 NOTYPE  LOCAL  DEFAULT    6 $d
  1299: 2400423c     4 OBJECT  LOCAL  DEFAULT    6 rsc_io
  1300: 24004240     0 NOTYPE  LOCAL  DEFAULT    6 $d
  1301: 24004240     4 OBJECT  LOCAL  DEFAULT    6 rsc_table
  1302: 24004244     0 NOTYPE  LOCAL  DEFAULT    6 $d
  1303: 24004244   120 OBJECT  LOCAL  DEFAULT    6 rvdev
  1304: 240042bc     0 NOTYPE  LOCAL  DEFAULT    6 $d
  1305: 240042bc     4 OBJECT  LOCAL  DEFAULT    6 shm_io
  1306: 240042c0     0 NOTYPE  LOCAL  DEFAULT    6 $d
  1307: 240042c0     4 OBJECT  LOCAL  DEFAULT    6 shm_physmap
  1308: 240042c4     0 NOTYPE  LOCAL  DEFAULT    6 $d
  1309: 240042c4    12 OBJECT  LOCAL  DEFAULT    6 shpool
  1310: 24000198     0 NOTYPE  LOCAL  DEFAULT    4 $d
  1311: 00000000     0 FILE    LOCAL  DEFAULT  ABS remoteproc_virtio.c
  1312: 08049228     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1313: 08049229     4 FUNC    LOCAL  DEFAULT    1 rproc_virtio_negotiate_fe
  1314: 0804922c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1315: 0804922d     2 FUNC    LOCAL  DEFAULT    1 rproc_virtio_read_config
  1316: 08049230     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1317: 08049231    64 FUNC    LOCAL  DEFAULT    1 rproc_virtio_virtqueue_no
  1318: 08049264     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1319: 08049270     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1320: 08049271    28 FUNC    LOCAL  DEFAULT    1 metal_io_write.part.1
  1321: 08049280     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1322: 0804928c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1323: 0804928d    28 FUNC    LOCAL  DEFAULT    1 metal_io_read.part.2
  1324: 0804929c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1325: 080492a8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1326: 080492a9     2 FUNC    LOCAL  DEFAULT    1 rproc_virtio_write_config
  1327: 080492aa     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1328: 080492ab    84 FUNC    LOCAL  DEFAULT    1 rproc_virtio_get_status
  1329: 080492fe     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1330: 080492ff    82 FUNC    LOCAL  DEFAULT    1 rproc_virtio_get_features
  1331: 08049350     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1332: 08049351    98 FUNC    LOCAL  DEFAULT    1 rproc_virtio_set_features
  1333: 080493b2     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1334: 080493b3   114 FUNC    LOCAL  DEFAULT    1 rproc_virtio_set_status
  1335: 08049424     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1336: 08049425    12 FUNC    LOCAL  DEFAULT    1 rproc_virtio_reset_device
  1337: 08049430     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1338: 08049504     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1339: 08049508     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1340: 08049532     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1341: 0806f498    14 OBJECT  LOCAL  DEFAULT    1 __func__.7327
  1342: 0806f4a6    15 OBJECT  LOCAL  DEFAULT    1 __func__.7344
  1343: 0806f4b5    30 OBJECT  LOCAL  DEFAULT    1 __func__.7952
  1344: 0806f53c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1345: 00000000     0 FILE    LOCAL  DEFAULT  ABS rpmsg.c
  1346: 08049576     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1347: 08049577    32 FUNC    LOCAL  DEFAULT    1 __metal_mutex_acquire
  1348: 08049596     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1349: 08049597    62 FUNC    LOCAL  DEFAULT    1 rpmsg_unregister_endpoint
  1350: 080495d4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1351: 080495f4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1352: 080495f8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1353: 0804962a     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1354: 08049686     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1355: 0804969c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1356: 0804978c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1357: 00000000     0 FILE    LOCAL  DEFAULT  ABS rpmsg_virtio.c
  1358: 08049790     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1359: 08049791    18 FUNC    LOCAL  DEFAULT    1 metal_io_virt_to_offset
  1360: 080497a2     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1361: 080497a3    32 FUNC    LOCAL  DEFAULT    1 __metal_mutex_acquire
  1362: 080497c2     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1363: 080497c3    14 FUNC    LOCAL  DEFAULT    1 __metal_mutex_release
  1364: 080497d0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1365: 080497d1     4 FUNC    LOCAL  DEFAULT    1 metal_mutex_acquire
  1366: 080497d4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1367: 080497d5     4 FUNC    LOCAL  DEFAULT    1 metal_mutex_release
  1368: 080497d8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1369: 080497f6     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1370: 0804980a     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1371: 0804980b    34 FUNC    LOCAL  DEFAULT    1 rpmsg_virtio_get_rx_buffe
  1372: 0804982c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1373: 0804982d   284 FUNC    LOCAL  DEFAULT    1 rpmsg_virtio_send_offchan
  1374: 0804993c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1375: 08049948     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1376: 08049949     2 FUNC    LOCAL  DEFAULT    1 rpmsg_virtio_tx_callback
  1377: 0804994a     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1378: 0804994b   148 FUNC    LOCAL  DEFAULT    1 rpmsg_virtio_rx_callback
  1379: 080499de     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1380: 080499df   228 FUNC    LOCAL  DEFAULT    1 rpmsg_virtio_ns_callback
  1381: 08049ac4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1382: 08049bf4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1383: 00000000     0 FILE    LOCAL  DEFAULT  ABS rsc_table.c
  1384: 08049c14     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1385: 08049c6c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1386: 38000000     0 NOTYPE  LOCAL  DEFAULT    7 $d
  1387: 00000000     0 FILE    LOCAL  DEFAULT  ABS sys.c
  1388: 08049c74     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1389: 08049c76     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1390: 08049c78     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1391: 00000000     0 FILE    LOCAL  DEFAULT  ABS virtio.c
  1392: 08049c7a     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1393: 00000000     0 FILE    LOCAL  DEFAULT  ABS virtqueue.c
  1394: 08049d14     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1395: 08049d15    42 FUNC    LOCAL  DEFAULT    1 metal_io_phys
  1396: 08049d3e     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1397: 08049e02     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1398: 08049e78     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1399: 08049e9c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1400: 08049efa     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1401: 08049f42     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1402: 00000000     0 FILE    LOCAL  DEFAULT  ABS device.c
  1403: 08049f50     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1404: 08049f8c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1405: 08049f90     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1406: 08049fcc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1407: 08049ff0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1408: 0804a028     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1409: 0804a02c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1410: 0804a084     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1411: 0804a08c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1412: 0804a0c4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1413: 0804a0f8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1414: 24000214     0 NOTYPE  LOCAL  DEFAULT    4 $d
  1415: 00000000     0 FILE    LOCAL  DEFAULT  ABS generic_device.c
  1416: 0804a100     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1417: 00000000     0 FILE    LOCAL  DEFAULT  ABS generic_init.c
  1418: 0804a128     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1419: 0804a134     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1420: 00000000     0 FILE    LOCAL  DEFAULT  ABS generic_io.c
  1421: 0804a138     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1422: 00000000     0 FILE    LOCAL  DEFAULT  ABS init.c
  1423: 0804a17c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1424: 0804a1b8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1425: 00000000     0 FILE    LOCAL  DEFAULT  ABS io.c
  1426: 0804a1bc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1427: 0804a218     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1428: 0804a292     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1429: 0804a308     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1430: 00000000     0 FILE    LOCAL  DEFAULT  ABS log.c
  1431: 0804a37a     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1432: 00000000     0 FILE    LOCAL  DEFAULT  ABS mailbox_hsem_if.c
  1433: 0804a380     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1434: 0804a39c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1435: 0804a3a4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1436: 0804a3e0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1437: 0804a3e4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1438: 0804a400     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1439: 0804a404     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1440: 240042d0     0 NOTYPE  LOCAL  DEFAULT    6 $d
  1441: 240042d0     4 OBJECT  LOCAL  DEFAULT    6 msg_received
  1442: 00000000     0 FILE    LOCAL  DEFAULT  ABS buffer.c
  1443: 0804a418     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1444: 0804a419    56 FUNC    LOCAL  DEFAULT    1 HexCharToNibble
  1445: 0804a44c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1446: 0804a450     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1447: 0804a45a     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1448: 0804a460     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1449: 0804a46c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1450: 0804a47c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1451: 0804a47d    36 FUNC    LOCAL  DEFAULT    1 throwExceptionAndFlagBuff
  1452: 0804a49c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1453: 0804a4a0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1454: 0804a4a1    76 FUNC    LOCAL  DEFAULT    1 matchesString
  1455: 0804a4e8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1456: 0804a4ec     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1457: 0804a4ed    54 FUNC    LOCAL  DEFAULT    1 doesBufferContainThisStri
  1458: 0804a522     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1459: 0804a530     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1460: 0804a550     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1461: 0804a554     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1462: 0804a578     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1463: 0804a57c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1464: 0804a5b0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1465: 0804a5b8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1466: 0804a5fc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1467: 0804a600     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1468: 0804a601   104 FUNC    LOCAL  DEFAULT    1 doesBufferContainThisHexS
  1469: 0804a668     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1470: 0804a698     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1471: 0804a69c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1472: 0804a6b6     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1473: 0804a6cc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1474: 0804a730     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1475: 0804a734     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1476: 0804a788     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1477: 0804a78c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1478: 0804a7b8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1479: 0804a7bc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1480: 0804a808     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1481: 0804a80c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1482: 0804a830     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1483: 0804a834     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1484: 0804a858     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1485: 0806f610     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1486: 0806f620    16 OBJECT  LOCAL  DEFAULT    1 NibbleToHexChar
  1487: 00000000     0 FILE    LOCAL  DEFAULT  ABS cmd_break_watch.c
  1488: 0804a85c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1489: 0804a85d    28 FUNC    LOCAL  DEFAULT    1 handleBreakpointWatchpoin
  1490: 0804a86c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1491: 0804a878     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1492: 0804a879    76 FUNC    LOCAL  DEFAULT    1 parseBreakpointWatchpoint
  1493: 0804a8c0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1494: 0804a8c4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1495: 0804a8c5    52 FUNC    LOCAL  DEFAULT    1 handleWatchpointSetComman
  1496: 0804a8f0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1497: 0804a8f8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1498: 0804a8f9    52 FUNC    LOCAL  DEFAULT    1 handleWatchpointRemoveCom
  1499: 0804a924     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1500: 0804a92c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1501: 0804a954     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1502: 0804a958     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1503: 0804a98c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1504: 0804a99c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1505: 0804a9c4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1506: 0804a9c8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1507: 0804a9fc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1508: 00000000     0 FILE    LOCAL  DEFAULT  ABS cmd_common.c
  1509: 0804aa0c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1510: 0804aa24     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1511: 0804aa28     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1512: 0804aa40     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1513: 0804aa44     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1514: 0804aa70     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1515: 0804aa74     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1516: 0804aa94     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1517: 00000000     0 FILE    LOCAL  DEFAULT  ABS cmd_continue.c
  1518: 0804aa98     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1519: 0804aab4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1520: 0804aae0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1521: 0804ab08     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1522: 0804ab0c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1523: 0804ab60     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1524: 0804ab68     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1525: 0804ab88     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1526: 00000000     0 FILE    LOCAL  DEFAULT  ABS cmd_file.c
  1527: 0804ab8c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1528: 0804abd8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1529: 0806f638     3 OBJECT  LOCAL  DEFAULT    1 controlCFlag.6292
  1530: 00000000     0 FILE    LOCAL  DEFAULT  ABS cmd_memory.c
  1531: 0804abe0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1532: 0804ac1c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1533: 0804ac28     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1534: 0804ac6c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1535: 0804ac80     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1536: 0804acc4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1537: 00000000     0 FILE    LOCAL  DEFAULT  ABS cmd_query.c
  1538: 0804acd8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1539: 0804acd9    90 FUNC    LOCAL  DEFAULT    1 handleQueryTransferReadCo
  1540: 0804ad32     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1541: 0804ad33    62 FUNC    LOCAL  DEFAULT    1 outputThreadIds
  1542: 0804ad70     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1543: 0804ad71    48 FUNC    LOCAL  DEFAULT    1 handleMonitorHelpCommand
  1544: 0804ad90     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1545: 0804ada0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1546: 0804ada1   160 FUNC    LOCAL  DEFAULT    1 readQueryTransferReadArgu
  1547: 0804ae34     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1548: 0804ae40     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1549: 0804aff0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1550: 0806f643     9 OBJECT  LOCAL  DEFAULT    1 featureObject.6286
  1551: 0806f67e     5 OBJECT  LOCAL  DEFAULT    1 help.6357
  1552: 0806f683    11 OBJECT  LOCAL  DEFAULT    1 memoryMapObject.6285
  1553: 0806f6d8     5 OBJECT  LOCAL  DEFAULT    1 qRcmdCommand.6274
  1554: 0806f6dd    10 OBJECT  LOCAL  DEFAULT    1 qSupportedCommand.6269
  1555: 0806f6e7    16 OBJECT  LOCAL  DEFAULT    1 qThreadExtraInfo.6273
  1556: 0806f6f7     5 OBJECT  LOCAL  DEFAULT    1 qXferCommand.6270
  1557: 0806f6fc    12 OBJECT  LOCAL  DEFAULT    1 qfThreadInfo.6271
  1558: 0806f708    12 OBJECT  LOCAL  DEFAULT    1 qsThreadInfo.6272
  1559: 0806f714    56 OBJECT  LOCAL  DEFAULT    1 querySupportResponse.6278
  1560: 0806f74c     5 OBJECT  LOCAL  DEFAULT    1 readCommand.6297
  1561: 0806f751     6 OBJECT  LOCAL  DEFAULT    1 reset.6355
  1562: 0806f757    10 OBJECT  LOCAL  DEFAULT    1 showfault.6356
  1563: 0806f761    11 OBJECT  LOCAL  DEFAULT    1 targetXmlAnnex.6302
  1564: 00000000     0 FILE    LOCAL  DEFAULT  ABS cmd_registers.c
  1565: 0804b03c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1566: 0804b0d4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1567: 0804b0e4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1568: 0804b0fc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1569: 0804b124     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1570: 00000000     0 FILE    LOCAL  DEFAULT  ABS cmd_step.c
  1571: 0804b12c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1572: 0804b15a     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1573: 00000000     0 FILE    LOCAL  DEFAULT  ABS cmd_thread.c
  1574: 0804b188     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1575: 0804b1dc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1576: 0804b1e8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1577: 0804b224     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1578: 00000000     0 FILE    LOCAL  DEFAULT  ABS cmd_vcont.c
  1579: 0804b230     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1580: 0804b231    92 FUNC    LOCAL  DEFAULT    1 parseOptionalThreadId
  1581: 0804b284     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1582: 0804b28c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1583: 0804b28d    72 FUNC    LOCAL  DEFAULT    1 handleAction
  1584: 0804b2d0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1585: 0804b2d4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1586: 0804b2d5   328 FUNC    LOCAL  DEFAULT    1 parseAction
  1587: 0804b418     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1588: 0804b41c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1589: 0804b41d   106 FUNC    LOCAL  DEFAULT    1 getActionPriority
  1590: 0804b488     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1591: 0804b69c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1592: 0804b6b4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1593: 0806f78a     3 OBJECT  LOCAL  DEFAULT    1 negativeOne.6400
  1594: 0806f78d     5 OBJECT  LOCAL  DEFAULT    1 vContCommand.6314
  1595: 0806f792     6 OBJECT  LOCAL  DEFAULT    1 vContQueryCommand.6313
  1596: 00000000     0 FILE    LOCAL  DEFAULT  ABS context.c
  1597: 0804b6c6     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1598: 0804b6cc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1599: 0804b6ec     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1600: 0804b728     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1601: 0804b72c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1602: 0804b764     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1603: 0804b768     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1604: 0804b7b2     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1605: 00000000     0 FILE    LOCAL  DEFAULT  ABS gdb_console.c
  1606: 0804b7fe     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1607: 0804b7ff    42 FUNC    LOCAL  DEFAULT    1 writeStringToExclusiveGdb
  1608: 0804b828     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1609: 0804b82c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1610: 0804b860     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1611: 00000000     0 FILE    LOCAL  DEFAULT  ABS memory.c
  1612: 0804b864     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1613: 0804b865    52 FUNC    LOCAL  DEFAULT    1 readMemoryBytesIntoHexBuf
  1614: 0804b898     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1615: 0804b899    72 FUNC    LOCAL  DEFAULT    1 writeHexBufferToByteMemor
  1616: 0804b8dc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1617: 0804b8e0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1618: 0804b8e1   108 FUNC    LOCAL  DEFAULT    1 writeBinaryBufferToByteMe
  1619: 0804b948     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1620: 0804b94c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1621: 0804b94d    88 FUNC    LOCAL  DEFAULT    1 readBytesFromBinaryBuffer
  1622: 0804b9a0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1623: 0804b9a4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1624: 0804ba28     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1625: 0804babc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1626: 0804bac0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1627: 00000000     0 FILE    LOCAL  DEFAULT  ABS mri.c
  1628: 0804bb10     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1629: 0804bb11    48 FUNC    LOCAL  DEFAULT    1 prepareForDebuggerExit
  1630: 0804bb3c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1631: 0804bb40     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1632: 0804bb84     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1633: 0804bb8c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1634: 0804bbd0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1635: 0804bbd8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1636: 0804bbf4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1637: 0804bbf8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1638: 0804bc0c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1639: 0804bc10     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1640: 0804bc1c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1641: 0804bc20     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1642: 0804bc38     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1643: 0804bc3c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1644: 0804bc44     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1645: 0804bc48     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1646: 0804bc50     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1647: 0804bc54     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1648: 0804bc68     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1649: 0804bc6c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1650: 0804bc74     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1651: 0804bc78     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1652: 0804bc80     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1653: 0804bc84     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1654: 0804bc88     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1655: 0804bc8c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1656: 0804bc98     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1657: 0804bc9c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1658: 0804bcc8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1659: 0804bcd0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1660: 0804bd34     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1661: 0804bd48     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1662: 0804be2c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1663: 240042d4     0 NOTYPE  LOCAL  DEFAULT    6 $d
  1664: 240042d4    72 OBJECT  LOCAL  DEFAULT    6 g_mri
  1665: 0806f79c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1666: 0806f79c   144 OBJECT  LOCAL  DEFAULT    1 commandTable.7418
  1667: 00000000     0 FILE    LOCAL  DEFAULT  ABS packet.c
  1668: 0804be34     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1669: 0804be35    56 FUNC    LOCAL  DEFAULT    1 HexCharToNibble
  1670: 0804be68     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1671: 0804be6c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1672: 0804bf28     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1673: 0804bf2c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1674: 0804bf94     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1675: 0806f82c    16 OBJECT  LOCAL  DEFAULT    1 NibbleToHexChar
  1676: 00000000     0 FILE    LOCAL  DEFAULT  ABS token.c
  1677: 0804bf98     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1678: 0804bfb0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1679: 0804bfb4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1680: 0804c068     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1681: 00000000     0 FILE    LOCAL  DEFAULT  ABS native-mem.c
  1682: 0804c06c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1683: 0804c070     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1684: 0804c074     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1685: 0804c078     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1686: 0804c07c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1687: 0804c080     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1688: 00000000     0 FILE    LOCAL  DEFAULT  ABS variant.cpp
  1689: 0804c084     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1690: 0804c085    36 FUNC    LOCAL  DEFAULT    1 _ZL5utox8mPh
  1691: 08074584     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1692: 0804c0a8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1693: 08074584     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1694: 0804c0ac     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1695: 0804c0cc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1696: 08073b74     0 NOTYPE  LOCAL  DEFAULT    2 $d
  1697: 08074584     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1698: 0804c0d0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1699: 0807458c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1700: 0804c0e4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1701: 08073b80     0 NOTYPE  LOCAL  DEFAULT    2 $d
  1702: 08074594     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1703: 0804c120     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1704: 0804c148     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1705: 08073b98     0 NOTYPE  LOCAL  DEFAULT    2 $d
  1706: 0807459c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1707: 0804c154     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1708: 080745a4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1709: 0804c180     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1710: 0804c1a8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1711: 08073ba4     0 NOTYPE  LOCAL  DEFAULT    2 $d
  1712: 080745ac     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1713: 2400431c     0 NOTYPE  LOCAL  DEFAULT    6 $d
  1714: 24000240     0 NOTYPE  LOCAL  DEFAULT    4 $d
  1715: 24000280     0 NOTYPE  LOCAL  DEFAULT    4 $d
  1716: 00000000     0 FILE    LOCAL  DEFAULT  ABS Serial.cpp
  1717: 0804c1b4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1718: 080745b4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1719: 0804c1c6     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1720: 080745bc     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1721: 0804c212     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1722: 080745c4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1723: 0804c248     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1724: 080745cc     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1725: 0804c264     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1726: 0804c28c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1727: 08073bb0     0 NOTYPE  LOCAL  DEFAULT    2 $d
  1728: 080745cc     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1729: 0804c290     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1730: 080745d4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1731: 0804c2fc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1732: 0804c390     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1733: 08073bbc     0 NOTYPE  LOCAL  DEFAULT    2 $d
  1734: 080745dc     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1735: 0804c398     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1736: 0804c3b0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1737: 080745e4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1738: 0804c3b4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1739: 080745ec     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1740: 0804c3d8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1741: 0804c418     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1742: 080745fc     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1743: 0804c41c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1744: 08074604     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1745: 0804c45c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1746: 0804c4a8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1747: 08074614     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1748: 0804c4ac     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1749: 0807461c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1750: 0804c524     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1751: 08074624     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1752: 0804c548     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1753: 0804c56c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1754: 08074634     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1755: 0804c570     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1756: 0807463c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1757: 0804c5a4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1758: 0804c5dc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1759: 0807464c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1760: 0804c5e0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1761: 08074654     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1762: 0804c62c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1763: 0804c67c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1764: 08074664     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1765: 0804c680     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1766: 0807466c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1767: 0804c69c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1768: 0804c69d   208 FUNC    LOCAL  DEFAULT    1 _GLOBAL__sub_I__ZN7arduin
  1769: 0804c758     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1770: 08074674     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1771: 24001a60     0 NOTYPE  LOCAL  DEFAULT    4 $d
  1772: 0806f840     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1773: 24004340     0 NOTYPE  LOCAL  DEFAULT    6 $d
  1774: 2400447c     0 NOTYPE  LOCAL  DEFAULT    6 $d
  1775: 240045b8     0 NOTYPE  LOCAL  DEFAULT    6 $d
  1776: 240046f4     0 NOTYPE  LOCAL  DEFAULT    6 $d
  1777: 0806f84c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1778: 00000000     0 FILE    LOCAL  DEFAULT  ABS PluggableUSBDevice.cpp
  1779: 0804c76c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1780: 08074674     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1781: 0804c770     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1782: 08074674     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1783: 0804c772     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1784: 08074674     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1785: 0804c774     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1786: 08074674     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1787: 0804c78a     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1788: 0807467c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1789: 0804c7a4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1790: 0804c7a8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1791: 08074684     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1792: 0804c7ac     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1793: 0804c7c4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1794: 08073be4     0 NOTYPE  LOCAL  DEFAULT    2 $d
  1795: 0807468c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1796: 0804c7c8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1797: 08074694     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1798: 0804c7de     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1799: 0807469c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1800: 0804c81e     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1801: 080746a4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1802: 0804c852     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1803: 080746ac     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1804: 0804c87a     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1805: 080746ac     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1806: 0804c8a4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1807: 080746b4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1808: 0804c934     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1809: 0804c935    44 FUNC    LOCAL  DEFAULT    1 _ZL10TO_UNICODEPKcPh
  1810: 080746bc     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1811: 0804c960     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1812: 080746c4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1813: 0804c99c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1814: 0804c9c4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1815: 080746cc     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1816: 0804c9c8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1817: 080746d4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1818: 0804c9ec     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1819: 0804ca68     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1820: 080746dc     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1821: 0804ca6c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1822: 0804ca94     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1823: 080746e4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1824: 0804ca98     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1825: 080746ec     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1826: 0804cad6     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1827: 08073bf0     0 NOTYPE  LOCAL  DEFAULT    2 $d
  1828: 080746f4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1829: 0804cb16     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1830: 080746fc     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1831: 0804cb28     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1832: 0804cb68     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1833: 08073c08     0 NOTYPE  LOCAL  DEFAULT    2 $d
  1834: 08074704     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1835: 0804cb78     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1836: 0807470c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1837: 0804cb88     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1838: 08074714     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1839: 0804cb98     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1840: 08074714     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1841: 0804cba8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1842: 08074714     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1843: 0804cbac     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1844: 0807471c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1845: 0804cbb0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1846: 0807471c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1847: 24004830     0 NOTYPE  LOCAL  DEFAULT    6 $d
  1848: 24004830     4 OBJECT  LOCAL  DEFAULT    6 _ZGVZ13PluggableUSBDvE3ob
  1849: 24004834     0 NOTYPE  LOCAL  DEFAULT    6 $d
  1850: 24004834  1424 OBJECT  LOCAL  DEFAULT    6 _ZZ13PluggableUSBDvE3obj
  1851: 0806f88c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1852: 0806f914    16 OBJECT  LOCAL  DEFAULT    1 _ZZN7arduino18PluggableUS
  1853: 00000000     0 FILE    LOCAL  DEFAULT  ABS USBCDC.cpp
  1854: 0804cbb4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1855: 0807471c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1856: 0804cbb6     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1857: 0807471c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1858: 0804cbb8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1859: 0807471c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1860: 0804cbba     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1861: 0807471c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1862: 0804cbc2     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1863: 0807471c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1864: 0804cbc8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1865: 0807471c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1866: 0804cbcc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1867: 0804cbd0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1868: 0807471c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1869: 0804cbd4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1870: 0807471c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1871: 0804cd38     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1872: 0804cd64     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1873: 08073c20     0 NOTYPE  LOCAL  DEFAULT    2 $d
  1874: 0807471c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1875: 0804cd68     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1876: 08074724     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1877: 0804cd7e     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1878: 0807472c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1879: 0804cd84     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1880: 0804cd94     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1881: 0807472c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1882: 0804cd98     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1883: 0807472c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1884: 0804cdac     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1885: 0804cdbc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1886: 0807472c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1887: 0804cdc0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1888: 0807472c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1889: 0804cdd4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1890: 0804cde4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1891: 0807472c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1892: 0804cde8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1893: 0807472c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1894: 0804cdfc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1895: 0804ce78     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1896: 0807472c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1897: 0804ce84     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1898: 08074734     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1899: 0804cf0e     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1900: 0807473c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1901: 0804cf50     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1902: 0804cfa0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1903: 08074744     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1904: 0804cfa8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1905: 0807474c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1906: 0804cfc4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1907: 0804d070     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1908: 08073c2c     0 NOTYPE  LOCAL  DEFAULT    2 $d
  1909: 08074754     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1910: 0804d07c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1911: 0804d0e0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1912: 08073c5c     0 NOTYPE  LOCAL  DEFAULT    2 $d
  1913: 0807475c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1914: 0804d0e4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1915: 0804d180     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1916: 08074764     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1917: 0804d18c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1918: 0807476c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1919: 0804d1a0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1920: 08074774     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1921: 0804d1bc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1922: 0807477c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1923: 0804d22c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1924: 0804d274     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1925: 08073c7c     0 NOTYPE  LOCAL  DEFAULT    2 $d
  1926: 08074784     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1927: 0804d27c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1928: 0804d2d8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1929: 08073c94     0 NOTYPE  LOCAL  DEFAULT    2 $d
  1930: 0807478c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1931: 0804d2e0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1932: 08074794     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1933: 0804d310     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1934: 0807479c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1935: 0804d372     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1936: 080747a4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1937: 0804d3c0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1938: 0804d438     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1939: 08073cac     0 NOTYPE  LOCAL  DEFAULT    2 $d
  1940: 080747ac     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1941: 0804d440     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1942: 080747b4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1943: 0804d46a     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1944: 080747bc     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1945: 0804d4ba     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1946: 080747c4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1947: 0806f924     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1948: 0806f93c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1949: 0806f954     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1950: 0806f96c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1951: 0806f978     7 OBJECT  LOCAL  DEFAULT    1 _ZL23cdc_line_coding_defa
  1952: 0806f980     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1953: 0806f980     4 OBJECT  LOCAL  DEFAULT    1 _ZN4rtos6KernelL20wait_fo
  1954: 0806fa24     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1955: 0806fa6c    22 OBJECT  LOCAL  DEFAULT    1 _ZZN7arduino6USBCDC20stri
  1956: 00000000     0 FILE    LOCAL  DEFAULT  ABS USBSerial.cpp
  1957: 0804d518     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1958: 080747cc     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1959: 0804d51e     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1960: 080747d4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1961: 0804d52a     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1962: 080747d4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1963: 0804d52e     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1964: 080747d4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1965: 0804d534     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1966: 080747d4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1967: 0804d53a     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1968: 080747d4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1969: 0804d53e     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1970: 080747d4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1971: 0804d540     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1972: 080747d4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1973: 0804d542     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1974: 080747d4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1975: 0804d544     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1976: 080747d4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1977: 0804d550     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1978: 080747dc     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1979: 0804d554     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1980: 080747e4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1981: 0804d558     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1982: 080747e4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1983: 0804d570     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1984: 0804d571    64 FUNC    LOCAL  DEFAULT    1 _ZL16waitForPortClosev
  1985: 0804d5a8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  1986: 080747f4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1987: 0804d5b0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1988: 080747fc     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1989: 0804d5d0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1990: 08074804     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1991: 0804d5d8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1992: 0807480c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1993: 0804d5fa     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1994: 08074814     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1995: 0804d602     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1996: 0807481c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1997: 0804d63c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  1998: 08074824     0 NOTYPE  LOCAL  DEFAULT    3 $d
  1999: 0804d668     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2000: 0804d678     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2001: 0807482c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2002: 0804d67c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2003: 08074834     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2004: 0804d698     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2005: 0804d6e0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2006: 08073cc4     0 NOTYPE  LOCAL  DEFAULT    2 $d
  2007: 08074834     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2008: 0804d6e4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2009: 0807483c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2010: 0804d6ec     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2011: 08074844     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2012: 0804d6f4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2013: 08074844     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2014: 0804d70a     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2015: 08074844     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2016: 0804d712     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2017: 08074844     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2018: 0804d71c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2019: 0804d7e0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2020: 08073cd0     0 NOTYPE  LOCAL  DEFAULT    2 $d
  2021: 08074844     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2022: 0804d7e4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2023: 0807484c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2024: 0804d810     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2025: 0804d910     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2026: 08073cf0     0 NOTYPE  LOCAL  DEFAULT    2 $d
  2027: 08074854     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2028: 0804d92c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2029: 0807485c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2030: 0804d934     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2031: 08074864     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2032: 0804d93c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2033: 0804d93d    84 FUNC    LOCAL  DEFAULT    1 _GLOBAL__sub_I__Z14usbPor
  2034: 0804d97c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2035: 0807486c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2036: 24001a64     0 NOTYPE  LOCAL  DEFAULT    4 $d
  2037: 0806fa84     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2038: 24004dc4     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2039: 240053fc     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2040: 240053fc    20 OBJECT  LOCAL  DEFAULT    6 _ZL5event
  2041: 0806fa98     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2042: 00000000     0 FILE    LOCAL  DEFAULT  ABS WMath.cpp
  2043: 0804d990     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2044: 0807486c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2045: 00000000     0 FILE    LOCAL  DEFAULT  ABS abi.cpp
  2046: 0804d998     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2047: 08073d2c     0 NOTYPE  LOCAL  DEFAULT    2 $d
  2048: 0807486c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2049: 00000000     0 FILE    LOCAL  DEFAULT  ABS IPAddress.cpp
  2050: 0804d99e     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2051: 08074874     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2052: 0804d9dc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2053: 0804d9dd    20 FUNC    LOCAL  DEFAULT    1 _GLOBAL__sub_I__ZN7arduin
  2054: 0804d9e8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2055: 0807487c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2056: 24001a68     0 NOTYPE  LOCAL  DEFAULT    4 $d
  2057: 24005410     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2058: 0806fbb4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2059: 00000000     0 FILE    LOCAL  DEFAULT  ABS Print.cpp
  2060: 0804d9f0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2061: 08074884     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2062: 0804da1c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2063: 0804da1d    28 FUNC    LOCAL  DEFAULT    1 _ZN7arduino5Print5writeEP
  2064: 0807488c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2065: 0804da38     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2066: 08074894     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2067: 0804da42     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2068: 08074894     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2069: 0804da4c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2070: 08073d38     0 NOTYPE  LOCAL  DEFAULT    2 $d
  2071: 08074894     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2072: 0804da54     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2073: 0807489c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2074: 0804da5c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2075: 0804da64     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2076: 080748a4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2077: 0804da68     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2078: 080748a4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2079: 0804da7c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2080: 080748ac     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2081: 0804da90     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2082: 080748ac     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2083: 0804daca     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2084: 080748b4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2085: 0804db0e     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2086: 080748bc     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2087: 0804db12     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2088: 080748c4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2089: 0804db26     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2090: 080748cc     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2091: 0804db40     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2092: 080748d4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2093: 0804db44     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2094: 080748d4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2095: 00000000     0 FILE    LOCAL  DEFAULT  ABS String.cpp
  2096: 0804db58     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2097: 080748dc     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2098: 0804db68     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2099: 080748e4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2100: 0804db7e     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2101: 080748e4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2102: 0804db96     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2103: 080748e4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2104: 0804dbbe     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2105: 080748e4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2106: 0804dbee     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2107: 080748e4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2108: 0804dc12     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2109: 080748e4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2110: 0804dc54     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2111: 080748e4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2112: 0804dc6a     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2113: 080748e4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2114: 0804dc9c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2115: 0804dcd8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2116: 080748e4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2117: 00000000     0 FILE    LOCAL  DEFAULT  ABS main.cpp
  2118: 0804dcdc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2119: 0804dd0c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2120: 080748e4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2121: 00000000     0 FILE    LOCAL  DEFAULT  ABS pinToIndex.cpp
  2122: 0804dd14     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2123: 0804dd38     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2124: 080748ec     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2125: 00000000     0 FILE    LOCAL  DEFAULT  ABS wiring.cpp
  2126: 0804dd3c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2127: 080748f4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2128: 0804dd48     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2129: 080748fc     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2130: 0804dd54     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2131: 0804dd74     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2132: 080748fc     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2133: 0804dd78     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2134: 08074904     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2135: 0804dd7c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2136: 0804dd90     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2137: 08073d44     0 NOTYPE  LOCAL  DEFAULT    2 $d
  2138: 0807490c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2139: 0804dd98     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2140: 0804dd99    64 FUNC    LOCAL  DEFAULT    1 _GLOBAL__sub_I_millis
  2141: 0804ddc4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2142: 08074914     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2143: 24001a6c     0 NOTYPE  LOCAL  DEFAULT    4 $d
  2144: 24005418     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2145: 24005418    24 OBJECT  LOCAL  DEFAULT    6 _ZL13lowPowerTimer
  2146: 24005430     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2147: 24005430    24 OBJECT  LOCAL  DEFAULT    6 _ZL5timer
  2148: 00000000     0 FILE    LOCAL  DEFAULT  ABS wiring_analog.cpp
  2149: 0804ddd8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2150: 0804de64     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2151: 08073d50     0 NOTYPE  LOCAL  DEFAULT    2 $d
  2152: 0807491c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2153: 24000ea0     0 NOTYPE  LOCAL  DEFAULT    4 $d
  2154: 24000ea0     4 OBJECT  LOCAL  DEFAULT    4 _ZL15read_resolution
  2155: 00000000     0 FILE    LOCAL  DEFAULT  ABS wiring_digital.cpp
  2156: 0804de74     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2157: 08074924     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2158: 0804de94     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2159: 0804df1c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2160: 08073d68     0 NOTYPE  LOCAL  DEFAULT    2 $d
  2161: 0807492c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2162: 0804df20     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2163: 08073d80     0 NOTYPE  LOCAL  DEFAULT    2 $d
  2164: 08074934     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2165: 0804df94     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2166: 0804e01c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2167: 08073d98     0 NOTYPE  LOCAL  DEFAULT    2 $d
  2168: 0807493c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2169: 0804e028     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2170: 0804e07c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2171: 08074944     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2172: 00000000     0 FILE    LOCAL  DEFAULT  ABS cmsis_os1.c
  2173: 0804e084     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2174: 0804e098     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2175: 00000000     0 FILE    LOCAL  DEFAULT  ABS irq_cm4f.o
  2176: 00000014     0 NOTYPE  LOCAL  DEFAULT  ABS I_T_RUN_OFS
  2177: 00000038     0 NOTYPE  LOCAL  DEFAULT  ABS TCB_SP_OFS
  2178: 00000022     0 NOTYPE  LOCAL  DEFAULT  ABS TCB_SF_OFS
  2179: 0804e0d8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2180: 0804e154     0 NOTYPE  LOCAL  DEFAULT    1 SVC_User
  2181: 0804e0fe     0 NOTYPE  LOCAL  DEFAULT    1 SVC_Context
  2182: 0804e11e     0 NOTYPE  LOCAL  DEFAULT    1 SVC_ContextSave
  2183: 0804e134     0 NOTYPE  LOCAL  DEFAULT    1 SVC_ContextSwitch
  2184: 0804e136     0 NOTYPE  LOCAL  DEFAULT    1 SVC_ContextRestore
  2185: 0804e152     0 NOTYPE  LOCAL  DEFAULT    1 SVC_Exit
  2186: 08074954     0 NOTYPE  LOCAL  DEFAULT    3 $d
  2187: 0804e190     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2188: 00000000     0 FILE    LOCAL  DEFAULT  ABS rtx_delay.c
  2189: 0804e19c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2190: 0804e19d    16 FUNC    LOCAL  DEFAULT    1 svcRtxDelay
  2191: 0804e1ac     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2192: 0804e1d8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2193: 00000000     0 FILE    LOCAL  DEFAULT  ABS rtx_evflags.c
  2194: 0804e1dc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2195: 0804e1dd    22 FUNC    LOCAL  DEFAULT    1 IsIrqMasked
  2196: 0804e1f2     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2197: 0804e1f3    50 FUNC    LOCAL  DEFAULT    1 svcRtxEventFlagsClear
  2198: 0804e224     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2199: 0804e225   120 FUNC    LOCAL  DEFAULT    1 svcRtxEventFlagsNew
  2200: 0804e294     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2201: 0804e375    48 FUNC    LOCAL  DEFAULT    1 osRtxEventFlagsPostProces
  2202: 0804e29c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2203: 0804e29d   112 FUNC    LOCAL  DEFAULT    1 svcRtxEventFlagsDelete
  2204: 0804e308     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2205: 0804e30c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2206: 0804e30d   104 FUNC    LOCAL  DEFAULT    1 EventFlagsCheck
  2207: 0804e374     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2208: 0804e3a4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2209: 0804e3a5    92 FUNC    LOCAL  DEFAULT    1 svcRtxEventFlagsWait
  2210: 0804e3fc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2211: 0804e400     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2212: 0804e401   126 FUNC    LOCAL  DEFAULT    1 svcRtxEventFlagsSet
  2213: 0804e480     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2214: 0804e4ac     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2215: 0804e4b0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2216: 0804e50c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2217: 0804e510     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2218: 0804e53c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2219: 0804e540     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2220: 0804e598     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2221: 0804e59c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2222: 0804e5c8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2223: 00000000     0 FILE    LOCAL  DEFAULT  ABS rtx_evr.c
  2224: 0804e5cc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2225: 0804e5ce     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2226: 0804e5d0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2227: 00000000     0 FILE    LOCAL  DEFAULT  ABS rtx_kernel.c
  2228: 0804e5d2     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2229: 0804e5d3    22 FUNC    LOCAL  DEFAULT    1 IsIrqMasked
  2230: 0804e5e8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2231: 0804e5e9    12 FUNC    LOCAL  DEFAULT    1 svcRtxKernelGetTickCount
  2232: 0804e5f0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2233: 0804e5f4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2234: 0804e5f5    44 FUNC    LOCAL  DEFAULT    1 svcRtxKernelLock
  2235: 0804e61c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2236: 0804e620     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2237: 0804e621   300 FUNC    LOCAL  DEFAULT    1 svcRtxKernelInitialize
  2238: 0804e744     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2239: 0804e74c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2240: 0804e74d   176 FUNC    LOCAL  DEFAULT    1 svcRtxKernelStart
  2241: 0804e7e8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2242: 0804e7fc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2243: 0804e7fd    48 FUNC    LOCAL  DEFAULT    1 svcRtxKernelRestoreLock
  2244: 0804e828     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2245: 0804e82c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2246: 0804e82d    88 FUNC    LOCAL  DEFAULT    1 svcRtxKernelSuspend
  2247: 0804e87c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2248: 0804e884     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2249: 0804e885   144 FUNC    LOCAL  DEFAULT    1 svcRtxKernelResume
  2250: 0804e90c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2251: 0804e914     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2252: 0804e918     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2253: 0804e944     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2254: 0804e948     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2255: 0804e970     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2256: 0804e974     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2257: 0804e99c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2258: 0804e9a0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2259: 0804e9cc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2260: 0804e9d0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2261: 0804e9f4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2262: 0804e9f8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2263: 0804ea20     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2264: 0804ea24     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2265: 0804ea44     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2266: 24000ea4     0 NOTYPE  LOCAL  DEFAULT    4 $d
  2267: 00000000     0 FILE    LOCAL  DEFAULT  ABS rtx_memory.c
  2268: 0804ea4c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2269: 0804ea7c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2270: 0804eae6     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2271: 00000000     0 FILE    LOCAL  DEFAULT  ABS rtx_mempool.c
  2272: 0804eb22     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2273: 0804eb64     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2274: 0804eb98     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2275: 00000000     0 FILE    LOCAL  DEFAULT  ABS rtx_msgqueue.c
  2276: 0804ebe0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2277: 0804ebe1    22 FUNC    LOCAL  DEFAULT    1 IsIrqMasked
  2278: 0804ebf6     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2279: 0804ebf7    24 FUNC    LOCAL  DEFAULT    1 MessageQueueRemove
  2280: 0804ec10     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2281: 0804ec11   288 FUNC    LOCAL  DEFAULT    1 svcRtxMessageQueueNew
  2282: 0804ed28     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2283: 0804edbd   186 FUNC    LOCAL  DEFAULT    1 osRtxMessageQueuePostProc
  2284: 0804ed30     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2285: 0804ed31    66 FUNC    LOCAL  DEFAULT    1 MessageQueueGet
  2286: 0804ed72     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2287: 0804ed73    74 FUNC    LOCAL  DEFAULT    1 MessageQueuePut
  2288: 0804edbc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2289: 0804ee78     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2290: 0804ee79   188 FUNC    LOCAL  DEFAULT    1 svcRtxMessageQueuePut
  2291: 0804ef30     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2292: 0804ef34     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2293: 0804ef35   220 FUNC    LOCAL  DEFAULT    1 svcRtxMessageQueueGet
  2294: 0804f00c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2295: 0804f010     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2296: 0804f03c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2297: 0804f040     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2298: 0804f0bc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2299: 0804f0c0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2300: 0804f134     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2301: 00000000     0 FILE    LOCAL  DEFAULT  ABS rtx_mutex.c
  2302: 0804f138     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2303: 0804f139    22 FUNC    LOCAL  DEFAULT    1 IsIrqMasked
  2304: 0804f150     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2305: 0804f151   124 FUNC    LOCAL  DEFAULT    1 svcRtxMutexNew
  2306: 0804f1c8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2307: 0804f1cc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2308: 0804f1cd   168 FUNC    LOCAL  DEFAULT    1 svcRtxMutexAcquire
  2309: 0804f270     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2310: 0804f274     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2311: 0804f275   196 FUNC    LOCAL  DEFAULT    1 svcRtxMutexRelease
  2312: 0804f334     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2313: 0804f338     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2314: 0804f339   176 FUNC    LOCAL  DEFAULT    1 svcRtxMutexDelete
  2315: 0804f3e4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2316: 0804f3e8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2317: 0804f42c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2318: 0804f470     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2319: 0804f49c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2320: 0804f4a0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2321: 0804f4cc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2322: 0804f4d0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2323: 0804f4fc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2324: 0804f500     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2325: 0804f52c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2326: 00000000     0 FILE    LOCAL  DEFAULT  ABS rtx_semaphore.c
  2327: 0804f530     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2328: 0804f531    22 FUNC    LOCAL  DEFAULT    1 IsIrqMasked
  2329: 0804f546     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2330: 0804f547    34 FUNC    LOCAL  DEFAULT    1 SemaphoreTokenDecrement
  2331: 0804f568     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2332: 0804f569    46 FUNC    LOCAL  DEFAULT    1 SemaphoreTokenIncrement
  2333: 0804f598     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2334: 0804f599   148 FUNC    LOCAL  DEFAULT    1 svcRtxSemaphoreNew
  2335: 0804f624     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2336: 0804f69d    34 FUNC    LOCAL  DEFAULT    1 osRtxSemaphorePostProcess
  2337: 0804f62c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2338: 0804f62d   112 FUNC    LOCAL  DEFAULT    1 svcRtxSemaphoreDelete
  2339: 0804f698     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2340: 0804f69c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2341: 0804f6be     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2342: 0804f6bf    74 FUNC    LOCAL  DEFAULT    1 svcRtxSemaphoreRelease
  2343: 0804f708     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2344: 0804f709    80 FUNC    LOCAL  DEFAULT    1 svcRtxSemaphoreAcquire
  2345: 0804f754     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2346: 0804f758     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2347: 0804f784     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2348: 0804f788     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2349: 0804f7d4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2350: 0804f7d8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2351: 0804f830     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2352: 0804f834     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2353: 0804f860     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2354: 00000000     0 FILE    LOCAL  DEFAULT  ABS rtx_system.c
  2355: 0804f864     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2356: 0804f865    26 FUNC    LOCAL  DEFAULT    1 atomic_inc16_lim
  2357: 0804f880     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2358: 0804f8ec     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2359: 0804f8f0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2360: 0804f938     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2361: 0804f95c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2362: 0804f97c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2363: 0804f980     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2364: 0804f9dc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2365: 00000000     0 FILE    LOCAL  DEFAULT  ABS rtx_thread.c
  2366: 0804f9e4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2367: 0804f9e5    22 FUNC    LOCAL  DEFAULT    1 IsIrqMasked
  2368: 0804f9fa     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2369: 0804f9fb    12 FUNC    LOCAL  DEFAULT    1 osRtxThreadListRoot
  2370: 0804fa08     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2371: 0804fa09    48 FUNC    LOCAL  DEFAULT    1 osRtxThreadBlock
  2372: 0804fa34     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2373: 0804fa38     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2374: 0804fa39    16 FUNC    LOCAL  DEFAULT    1 svcRtxThreadGetName
  2375: 0804fa48     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2376: 0804fa49    12 FUNC    LOCAL  DEFAULT    1 svcRtxThreadGetId
  2377: 0804fa50     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2378: 0804fa54     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2379: 0804fa55    40 FUNC    LOCAL  DEFAULT    1 svcRtxThreadGetCount
  2380: 0804fa78     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2381: 0804fa7c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2382: 0804fa7d    84 FUNC    LOCAL  DEFAULT    1 osRtxThreadFree
  2383: 0804facc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2384: 0804fad0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2385: 0804fae8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2386: 08050229    96 FUNC    LOCAL  DEFAULT    1 svcRtxThreadExit
  2387: 0804faec     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2388: 0804faed    60 FUNC    LOCAL  DEFAULT    1 osRtxThreadDelayRemove
  2389: 0804fb24     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2390: 0804fb28     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2391: 0804fb29    84 FUNC    LOCAL  DEFAULT    1 svcRtxThreadEnumerate
  2392: 0804fb78     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2393: 0804fb7c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2394: 0804fb7d   104 FUNC    LOCAL  DEFAULT    1 ThreadFlagsCheck
  2395: 0804fbe4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2396: 0804fc08     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2397: 0804fc1a     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2398: 0804fc2c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2399: 0804fc50     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2400: 0804fc5c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2401: 0804fc60     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2402: 0804fcbc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2403: 0804fcc0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2404: 0804fcd4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2405: 0804fcf4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2406: 0804fcfc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2407: 0804fd0c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2408: 0804fd10     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2409: 0804fd64     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2410: 0804fd68     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2411: 0804fd8c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2412: 0804fd8d    38 FUNC    LOCAL  DEFAULT    1 osRtxThreadPostProcess
  2413: 0804fdb2     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2414: 0804fdb3   122 FUNC    LOCAL  DEFAULT    1 svcRtxThreadFlagsSet
  2415: 0804fe2c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2416: 0804fe2d   468 FUNC    LOCAL  DEFAULT    1 svcRtxThreadNew
  2417: 0804ffec     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2418: 08050000     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2419: 08050001    92 FUNC    LOCAL  DEFAULT    1 svcRtxThreadSetPriority
  2420: 0805005c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2421: 0805005d    68 FUNC    LOCAL  DEFAULT    1 svcRtxThreadResume
  2422: 080500a0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2423: 0805011c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2424: 08050124     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2425: 08050125    96 FUNC    LOCAL  DEFAULT    1 svcRtxThreadFlagsWait
  2426: 08050180     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2427: 08050184     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2428: 08050185   164 FUNC    LOCAL  DEFAULT    1 svcRtxThreadSuspend
  2429: 08050220     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2430: 08050228     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2431: 08050280     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2432: 08050288     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2433: 08050289   200 FUNC    LOCAL  DEFAULT    1 svcRtxThreadTerminate
  2434: 08050348     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2435: 08050350     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2436: 08050380     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2437: 08050390     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2438: 080503bc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2439: 080503c0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2440: 080503e0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2441: 080503e4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2442: 08050404     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2443: 0805040c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2444: 08050438     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2445: 0805043c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2446: 08050468     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2447: 0805046c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2448: 08050498     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2449: 0805049c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2450: 080504cc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2451: 080504d0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2452: 080504ec     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2453: 080504f0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2454: 08050510     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2455: 08050514     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2456: 08050584     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2457: 08050588     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2458: 080505b4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2459: 00000000     0 FILE    LOCAL  DEFAULT  ABS rtx_timer.c
  2460: 080505b8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2461: 080505b9    56 FUNC    LOCAL  DEFAULT    1 TimerInsert
  2462: 080505ec     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2463: 080505f0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2464: 080505f1    84 FUNC    LOCAL  DEFAULT    1 osRtxTimerTick
  2465: 08050640     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2466: 08050644     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2467: 08050674     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2468: 00000000     0 FILE    LOCAL  DEFAULT  ABS mbed_boot_gcc_arm.c
  2469: 08050680     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2470: 080506a8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2471: 080506c8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2472: 08050704     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2473: 08050724     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2474: 08050728     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2475: 08050734     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2476: 08050738     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2477: 08050740     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2478: 24005c18     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2479: 24005c18    16 OBJECT  LOCAL  DEFAULT    6 env_mutex_attr
  2480: 24005c28     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2481: 24005c28     4 OBJECT  LOCAL  DEFAULT    6 env_mutex_id
  2482: 24005c2c     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2483: 24005c2c    28 OBJECT  LOCAL  DEFAULT    6 env_mutex_obj
  2484: 24005c48     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2485: 24005c48    16 OBJECT  LOCAL  DEFAULT    6 malloc_mutex_attr
  2486: 24005c58     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2487: 24005c58     4 OBJECT  LOCAL  DEFAULT    6 malloc_mutex_id
  2488: 24005c5c     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2489: 24005c5c    28 OBJECT  LOCAL  DEFAULT    6 malloc_mutex_obj
  2490: 00000000     0 FILE    LOCAL  DEFAULT  ABS mbed_boot.c
  2491: 08050744     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2492: 0805077c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2493: 08050784     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2494: 08050786     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2495: 08050788     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2496: 24005c78     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2497: 24005c7c     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2498: 00000000     0 FILE    LOCAL  DEFAULT  ABS mbed_rtos_rtx.c
  2499: 080507a6     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2500: 080507ac     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2501: 080507f4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2502: 08050814     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2503: 08050830     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2504: 0806fd44     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2505: 24005c80     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2506: 2400dc80     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2507: 2400dca4     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2508: 2400dce8     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2509: 2400dcec     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2510: 00000000     0 FILE    LOCAL  DEFAULT  ABS mbed_rtx_handlers.c
  2511: 08050838     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2512: 08050839    52 FUNC    LOCAL  DEFAULT    1 trap_rtx_error
  2513: 08050864     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2514: 0805086c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2515: 08050874     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2516: 08050888     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2517: 080508c0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2518: 080508f0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2519: 080508f8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2520: 080508fc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2521: 08050904     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2522: 08050908     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2523: 08050910     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2524: 08050914     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2525: 0805091c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2526: 08050920     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2527: 08050930     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2528: 08050934     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2529: 0805093c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2530: 08050940     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2531: 08050954     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2532: 08050958     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2533: 08050964     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2534: 2400dd08     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2535: 2400dd08     4 OBJECT  LOCAL  DEFAULT    6 terminate_hook
  2536: 0806ff08     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2537: 0806ff08    24 OBJECT  LOCAL  DEFAULT    1 CSWTCH.12
  2538: 0805088d     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2539: 0805088e     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2540: 00000000     0 FILE    LOCAL  DEFAULT  ABS mbed_rtx_idle.cpp
  2541: 08050968     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2542: 08050969    16 FUNC    LOCAL  DEFAULT    1 rtos_event_pending
  2543: 08050974     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2544: 08050978     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2545: 08050979    48 FUNC    LOCAL  DEFAULT    1 default_idle_hook
  2546: 0805099c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2547: 080509a8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2548: 08050a1c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2549: 08050a30     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2550: 08050a40     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2551: 08050a48     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2552: 08050a4c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2553: 08050a54     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2554: 08050a58     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2555: 08050a60     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2556: 08050a6c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2557: 24000f48     0 NOTYPE  LOCAL  DEFAULT    4 $d
  2558: 24000f48     4 OBJECT  LOCAL  DEFAULT    4 _ZL14idle_hook_fptr
  2559: 00000000     0 FILE    LOCAL  DEFAULT  ABS BLEInstanceBaseImpl.cpp
  2560: 08050a70     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2561: 08050a7a     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2562: 08050a88     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2563: 08050a89    28 FUNC    LOCAL  DEFAULT    1 _GLOBAL__sub_I_stack_hand
  2564: 08050a9c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2565: 24001a70     0 NOTYPE  LOCAL  DEFAULT    4 $d
  2566: 2400dd0c     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2567: 00000000     0 FILE    LOCAL  DEFAULT  ABS GattServerImpl.cpp
  2568: 08050aa4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2569: 08050abc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2570: 08050abd    20 FUNC    LOCAL  DEFAULT    1 _GLOBAL__sub_I__ZN3ble4im
  2571: 08050acc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2572: 24001a74     0 NOTYPE  LOCAL  DEFAULT    4 $d
  2573: 2400dd20     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2574: 2400dd20    20 OBJECT  LOCAL  DEFAULT    6 _ZN3ble4impl12_GLOBAL__N_
  2575: 00000000     0 FILE    LOCAL  DEFAULT  ABS AT_CellularContext.cpp
  2576: 08050ad0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2577: 08050aec     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2578: 08050af4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2579: 00000000     0 FILE    LOCAL  DEFAULT  ABS ATHandler.cpp
  2580: 08050afc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2581: 08050b18     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2582: 00000000     0 FILE    LOCAL  DEFAULT  ABS CellularDevice.cpp
  2583: 08050b20     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2584: 0806fff8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2585: 00000000     0 FILE    LOCAL  DEFAULT  ABS whd_emac.cpp
  2586: 08050b40     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2587: 08050b5c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2588: 00000000     0 FILE    LOCAL  DEFAULT  ABS whd_interface.cpp
  2589: 08050b64     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2590: 08050b70     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2591: 08050b71    48 FUNC    LOCAL  DEFAULT    1 _GLOBAL__sub_I_whd_iface_
  2592: 08050b94     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2593: 24001a78     0 NOTYPE  LOCAL  DEFAULT    4 $d
  2594: 2400dd34     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2595: 00000000     0 FILE    LOCAL  DEFAULT  ABS stm32h7_eth_init.c
  2596: 08050ba0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2597: 08050d60     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2598: 00000000     0 FILE    LOCAL  DEFAULT  ABS lan8742.c
  2599: 08050d7c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2600: 08050da4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2601: 08050e6c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2602: 00000000     0 FILE    LOCAL  DEFAULT  ABS stm32xx_emac.cpp
  2603: 08050f00     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2604: 08050f06     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2605: 08050f0a     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2606: 08050f0e     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2607: 08050f10     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2608: 08050f12     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2609: 08050f18     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2610: 08050f19     4 FUNC    LOCAL  DEFAULT    1 _ZL17ETH_PHY_IO_DeInitv
  2611: 08050f1c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2612: 08050f1d     4 FUNC    LOCAL  DEFAULT    1 _ZL18ETH_PHY_IO_GetTickv
  2613: 08050f20     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2614: 08050f98     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2615: 08050f9c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2616: 08050fac     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2617: 08050fb0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2618: 08050fb4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2619: 08050fb5    24 FUNC    LOCAL  DEFAULT    1 _ZNK4mbed8CallbackIFvbEE4
  2620: 08050fc4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2621: 08050fb5    24 FUNC    LOCAL  DEFAULT    1 _ZNK4mbed8CallbackIFvvEE4
  2622: 08050fb5    24 FUNC    LOCAL  DEFAULT    1 _ZNK4mbed8CallbackIFvPvEE
  2623: 08050fcc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2624: 08050fec     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2625: 08051018     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2626: 0805101c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2627: 0805103a     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2628: 08051058     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2629: 08051074     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2630: 0805107c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2631: 08051084     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2632: 08051088     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2633: 08051092     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2634: 08051096     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2635: 080510c0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2636: 080510f0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2637: 080510f4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2638: 08051170     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2639: 08051174     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2640: 080511bc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2641: 080511f8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2642: 08051200     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2643: 08051216     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2644: 0805121c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2645: 0805123c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2646: 08051240     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2647: 08051258     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2648: 08051300     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2649: 08051324     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2650: 080513d8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2651: 080513f0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2652: 080513fc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2653: 0805142c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2654: 0805143c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2655: 0805143d    36 FUNC    LOCAL  DEFAULT    1 _ZL18ETH_PHY_IO_ReadRegmm
  2656: 08051460     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2657: 08051461    36 FUNC    LOCAL  DEFAULT    1 _ZL19ETH_PHY_IO_WriteRegm
  2658: 08051484     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2659: 08051485    16 FUNC    LOCAL  DEFAULT    1 _ZL15ETH_PHY_IO_Initv
  2660: 08051494     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2661: 080514ac     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2662: 080514bc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2663: 080514cc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2664: 080514d4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2665: 080514e4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2666: 080514ec     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2667: 08051584     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2668: 08070080     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2669: 30040400     0 NOTYPE  LOCAL  DEFAULT   10 $d
  2670: 30040000     0 NOTYPE  LOCAL  DEFAULT   10 $d
  2671: 30040100     0 NOTYPE  LOCAL  DEFAULT   10 $d
  2672: 2400dd68     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2673: 2400dd68     4 OBJECT  LOCAL  DEFAULT    6 _ZGVZN10STM32_EMAC12get_i
  2674: 2400dd6c     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2675: 2400dd6c     4 OBJECT  LOCAL  DEFAULT    6 _ZGVZN10STM32_EMAC15threa
  2676: 2400dd70     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2677: 2400dd70    32 OBJECT  LOCAL  DEFAULT    6 _ZL7LAN8742
  2678: 2400dd90     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2679: 2400dd90    52 OBJECT  LOCAL  DEFAULT    6 _ZL8TxConfig
  2680: 2400ddc4     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2681: 2400ddc4   376 OBJECT  LOCAL  DEFAULT    6 _ZZN10STM32_EMAC12get_ins
  2682: 2400df3c     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2683: 2400df3c     4 OBJECT  LOCAL  DEFAULT    6 _ZZN10STM32_EMAC15thread_
  2684: 24000f4c     0 NOTYPE  LOCAL  DEFAULT    4 $d
  2685: 24000f4c    20 OBJECT  LOCAL  DEFAULT    4 _ZL13LAN8742_IOCtx
  2686: 0807008c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2687: 00000000     0 FILE    LOCAL  DEFAULT  ABS lwip_memcpy.c
  2688: 08051588     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2689: 00000000     0 FILE    LOCAL  DEFAULT  ABS lwip_sys_arch.c
  2690: 080515c4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2691: 0805163c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2692: 08051644     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2693: 08051668     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2694: 08051670     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2695: 08051690     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2696: 08051698     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2697: 080516c0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2698: 080516cc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2699: 080516ec     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2700: 2400df40     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2701: 00000000     0 FILE    LOCAL  DEFAULT  ABS lwip_tcpip.c
  2702: 080516f8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2703: 08051728     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2704: 2400df44     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2705: 2400df44    72 OBJECT  LOCAL  DEFAULT    6 tcpip_mbox
  2706: 00000000     0 FILE    LOCAL  DEFAULT  ABS lwip_mem.c
  2707: 0805172c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2708: 0805181c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2709: 0805182c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2710: 080518ec     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2711: 2400df8c     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2712: 2400df8c     4 OBJECT  LOCAL  DEFAULT    6 lfree
  2713: 2400df90     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2714: 2400df90    48 OBJECT  LOCAL  DEFAULT    6 mem_mutex
  2715: 2400dfc0     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2716: 2400dfc0     4 OBJECT  LOCAL  DEFAULT    6 ram
  2717: 2400dfc4     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2718: 2400dfc4     4 OBJECT  LOCAL  DEFAULT    6 ram_end
  2719: 00000000     0 FILE    LOCAL  DEFAULT  ABS lwip_memp.c
  2720: 080518fc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2721: 080518fd    26 FUNC    LOCAL  DEFAULT    1 do_memp_malloc_pool
  2722: 08051918     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2723: 0805192c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2724: 08051930     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2725: 08051958     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2726: 2400dfc8     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2727: 2400e133     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2728: 2400e1b6     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2729: 2400e239     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2730: 2400e56c     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2731: 2400f14f     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2732: 2400f1d2     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2733: 2400f275     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2734: 2400f378     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2735: 2400f3fb     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2736: 2400f47e     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2737: 2400f4f1     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2738: 2400f784     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2739: 2400f887     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2740: 2400f92c     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2741: 2400f92c     4 OBJECT  LOCAL  DEFAULT    6 memp_tab_FRAG_PBUF
  2742: 2400f930     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2743: 2400f930     4 OBJECT  LOCAL  DEFAULT    6 memp_tab_IGMP_GROUP
  2744: 2400f934     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2745: 2400f934     4 OBJECT  LOCAL  DEFAULT    6 memp_tab_NETBUF
  2746: 2400f938     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2747: 2400f938     4 OBJECT  LOCAL  DEFAULT    6 memp_tab_NETCONN
  2748: 2400f93c     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2749: 2400f93c     4 OBJECT  LOCAL  DEFAULT    6 memp_tab_PBUF
  2750: 2400f940     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2751: 2400f940     4 OBJECT  LOCAL  DEFAULT    6 memp_tab_PBUF_POOL
  2752: 2400f944     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2753: 2400f944     4 OBJECT  LOCAL  DEFAULT    6 memp_tab_REASSDATA
  2754: 2400f948     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2755: 2400f948     4 OBJECT  LOCAL  DEFAULT    6 memp_tab_SYS_TIMEOUT
  2756: 2400f94c     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2757: 2400f94c     4 OBJECT  LOCAL  DEFAULT    6 memp_tab_TCPIP_MSG_API
  2758: 2400f950     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2759: 2400f950     4 OBJECT  LOCAL  DEFAULT    6 memp_tab_TCPIP_MSG_INPKT
  2760: 2400f954     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2761: 2400f954     4 OBJECT  LOCAL  DEFAULT    6 memp_tab_TCP_PCB
  2762: 2400f958     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2763: 2400f958     4 OBJECT  LOCAL  DEFAULT    6 memp_tab_TCP_PCB_LISTEN
  2764: 2400f95c     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2765: 2400f95c     4 OBJECT  LOCAL  DEFAULT    6 memp_tab_TCP_SEG
  2766: 2400f960     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2767: 2400f960     4 OBJECT  LOCAL  DEFAULT    6 memp_tab_UDP_PCB
  2768: 08070148     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2769: 08070154     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2770: 08070160     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2771: 0807016c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2772: 08070178     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2773: 08070184     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2774: 08070190     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2775: 0807019c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2776: 080701a8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2777: 080701b4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2778: 080701c0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2779: 080701cc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2780: 080701d8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2781: 080701e4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2782: 080701f0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2783: 00000000     0 FILE    LOCAL  DEFAULT  ABS lwip_pbuf.c
  2784: 0805195c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2785: 0805195d    48 FUNC    LOCAL  DEFAULT    1 pbuf_free_ooseq_callback
  2786: 08051984     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2787: 0805198c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2788: 080519b0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2789: 08051a14     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2790: 08051b10     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2791: 08051b20     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2792: 2400f964     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2793: 00000000     0 FILE    LOCAL  DEFAULT  ABS lwip_tcp.c
  2794: 08051b68     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2795: 08051b84     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2796: 08051b94     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2797: 2400f968     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2798: 00000000     0 FILE    LOCAL  DEFAULT  ABS mbed_trng.cpp
  2799: 08051ba8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2800: 08051bec     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2801: 00000000     0 FILE    LOCAL  DEFAULT  ABS AnalogIn.cpp
  2802: 08051bf8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2803: 08051bfa     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2804: 08051c08     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2805: 08051c2c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2806: 08051c3c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2807: 08051c40     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2808: 08051c50     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2809: 08051c54     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2810: 08051c78     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2811: 08070280     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2812: 2400f96c     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2813: 00000000     0 FILE    LOCAL  DEFAULT  ABS BufferedSerial.cpp
  2814: 08051c7c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2815: 08051c86     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2816: 00000000     0 FILE    LOCAL  DEFAULT  ABS DigitalInOut.cpp
  2817: 08051c90     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2818: 08051caa     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2819: 08051cc4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2820: 00000000     0 FILE    LOCAL  DEFAULT  ABS I2C.cpp
  2821: 08051ce0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2822: 08051ce1    44 FUNC    LOCAL  DEFAULT    1 gpio_write
  2823: 08051d04     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2824: 08051d0c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2825: 08051d38     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2826: 08051d64     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2827: 08051d68     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2828: 08051daa     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2829: 08051e94     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2830: 08051ea4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2831: 08051ea8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2832: 08051eb8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2833: 08051ebc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2834: 08051f24     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2835: 2400f994     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2836: 2400f9bc     0 NOTYPE  LOCAL  DEFAULT    6 $d
  2837: 08070298     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2838: 00000000     0 FILE    LOCAL  DEFAULT  ABS SerialBase.cpp
  2839: 08051f34     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2840: 08051f38     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2841: 08051f8c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2842: 08051f90     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2843: 08051fcc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2844: 08051fd0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2845: 08051ffc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2846: 08052008     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2847: 08052009    34 FUNC    LOCAL  DEFAULT    1 _ZN4mbed8CallbackIFvvEEaS
  2848: 0805202c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2849: 08052090     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2850: 08052098     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2851: 080520be     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2852: 080520ec     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2853: 0805210e     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2854: 08052130     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2855: 080521ac     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2856: 08052204     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2857: 08052208     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2858: 0805221c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2859: 08052222     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2860: 08052230     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2861: 08052242     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2862: 080522d0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2863: 080702f0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2864: 00000000     0 FILE    LOCAL  DEFAULT  ABS Ticker.cpp
  2865: 0805235e     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2866: 08052388     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2867: 080523ac     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2868: 080523b0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2869: 080523e4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2870: 08052400     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2871: 08070308     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2872: 00000000     0 FILE    LOCAL  DEFAULT  ABS Timer.cpp
  2873: 08052404     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2874: 08052418     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2875: 08052446     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2876: 0805247e     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2877: 080524b2     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2878: 080524d8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2879: 080524f8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2880: 0805250e     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2881: 00000000     0 FILE    LOCAL  DEFAULT  ABS TimerEvent.cpp
  2882: 08052524     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2883: 0805252c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2884: 08052550     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2885: 08052558     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2886: 0805256c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2887: 08052578     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2888: 08052588     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2889: 08070314     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2890: 00000000     0 FILE    LOCAL  DEFAULT  ABS UnbufferedSerial.cpp
  2891: 0805258c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2892: 08052590     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2893: 0805259c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2894: 080525a8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2895: 080525b0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2896: 080525b8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2897: 080525e2     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2898: 080525ea     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2899: 080525f4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2900: 080525fc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2901: 08052606     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2902: 08052610     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2903: 08052620     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2904: 08052624     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2905: 0805262c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2906: 08052646     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2907: 0805268a     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2908: 08052692     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2909: 080526b8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2910: 080526c0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2911: 080526d8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2912: 080526dc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2913: 08070320     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2914: 00000000     0 FILE    LOCAL  DEFAULT  ABS AsyncOp.cpp
  2915: 08052708     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2916: 0805274c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2917: 08052760     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2918: 08052764     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2919: 08052784     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2920: 08052790     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2921: 080527cc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2922: 080527d6     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2923: 080527e0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2924: 0805284c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2925: 080703f4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2926: 00000000     0 FILE    LOCAL  DEFAULT  ABS EndpointResolver.cpp
  2927: 08052854     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2928: 08052862     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2929: 08052864     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2930: 0805287a     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2931: 080528dc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2932: 0805291e     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2933: 08052928     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2934: 08052932     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2935: 00000000     0 FILE    LOCAL  DEFAULT  ABS LinkedListBase.cpp
  2936: 08052950     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2937: 08052958     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2938: 0805295a     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2939: 0805295e     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2940: 08052970     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2941: 08052984     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2942: 00000000     0 FILE    LOCAL  DEFAULT  ABS OperationListBase.cpp
  2943: 080529b8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2944: 080529c4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2945: 080529d2     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2946: 08052a02     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2947: 08052a26     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2948: 08052a4e     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2949: 08052a68     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2950: 00000000     0 FILE    LOCAL  DEFAULT  ABS USBAudio.cpp
  2951: 08052a7a     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2952: 00000000     0 FILE    LOCAL  DEFAULT  ABS USBDevice.cpp
  2953: 08052a7c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2954: 08052a7e     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2955: 08052a84     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2956: 08052ae0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2957: 08052ae4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2958: 08052ae8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2959: 08052aec     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2960: 08052af0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2961: 08052af4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2962: 08052af8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2963: 08052afc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2964: 08052b00     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2965: 08052b04     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2966: 08052b08     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2967: 08052b0c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2968: 08052b10     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2969: 08052b14     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2970: 08052b34     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2971: 08052b84     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2972: 08052b8c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2973: 08052ba4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2974: 08052bac     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2975: 08052bd0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2976: 08052bd8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2977: 08052c34     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2978: 08052c3c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2979: 08052d0c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2980: 08052d12     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2981: 08052d8e     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2982: 08052db8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2983: 08052df4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2984: 08052e00     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2985: 08052e7c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2986: 08052ed0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2987: 08052edc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2988: 08052f6c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2989: 08052fb0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2990: 08052fb8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2991: 08052ff4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2992: 08053000     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2993: 0805301e     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2994: 08053050     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2995: 08053074     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2996: 080530b0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2997: 080530bc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  2998: 08053130     0 NOTYPE  LOCAL  DEFAULT    1 $d
  2999: 08053134     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3000: 08053178     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3001: 080531b8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3002: 080531c0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3003: 08053208     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3004: 08053214     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3005: 080532c8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3006: 080532e0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3007: 08053348     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3008: 08053370     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3009: 080533be     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3010: 080533fc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3011: 0805341c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3012: 08053450     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3013: 08053528     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3014: 0805353c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3015: 08053548     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3016: 080535b4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3017: 080535b8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3018: 080535f0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3019: 08053668     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3020: 08053678     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3021: 080536fc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3022: 0805370c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3023: 08053758     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3024: 080537e4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3025: 080537f4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3026: 08053840     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3027: 080538e4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3028: 080538fc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3029: 0805396c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3030: 0805397c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3031: 08053a28     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3032: 08053a40     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3033: 08053aa4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3034: 08053ab4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3035: 08053b1e     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3036: 08053b4c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3037: 08053b8c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3038: 08053ba8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3039: 08053bb4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3040: 08053c12     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3041: 08053c96     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3042: 08053cc0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3043: 08053d06     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3044: 08053d38     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3045: 08053d70     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3046: 08053d7c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3047: 08053d9e     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3048: 2400f9c0     0 NOTYPE  LOCAL  DEFAULT    6 $d
  3049: 2400f9c0     2 OBJECT  LOCAL  DEFAULT    6 _ZZN9USBDevice19_request_
  3050: 0807065c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3051: 080706e4     4 OBJECT  LOCAL  DEFAULT    1 _ZZN9USBDevice18string_la
  3052: 080706e8    22 OBJECT  LOCAL  DEFAULT    1 _ZZN9USBDevice19string_is
  3053: 080706fe    22 OBJECT  LOCAL  DEFAULT    1 _ZZN9USBDevice20string_ip
  3054: 08070714     8 OBJECT  LOCAL  DEFAULT    1 _ZZN9USBDevice22string_ii
  3055: 0807071c    18 OBJECT  LOCAL  DEFAULT    1 _ZZN9USBDevice25string_im
  3056: 0807072e     6 OBJECT  LOCAL  DEFAULT    1 _ZZN9USBDevice26string_ic
  3057: 00000000     0 FILE    LOCAL  DEFAULT  ABS EventQueue.cpp
  3058: 08053e10     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3059: 08053e2e     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3060: 08053e42     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3061: 00000000     0 FILE    LOCAL  DEFAULT  ABS equeue.c
  3062: 08053e4a     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3063: 08053eb8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3064: 08053ede     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3065: 08053f34     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3066: 08053fa4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3067: 08054018     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3068: 080540b0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3069: 080540f2     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3070: 08054276     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3071: 0805427c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3072: 08054282     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3073: 00000000     0 FILE    LOCAL  DEFAULT  ABS equeue_mbed.cpp
  3074: 08054288     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3075: 0805428c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3076: 080542b8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3077: 080542bc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3078: 080542c0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3079: 080542c2     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3080: 080542c6     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3081: 080542cc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3082: 080542d8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3083: 080542dc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3084: 080542e0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3085: 080542e6     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3086: 00000000     0 FILE    LOCAL  DEFAULT  ABS mbed_shared_queues.cpp
  3087: 080542fc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3088: 080543c0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3089: 080543f8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3090: 08054404     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3091: 2400f9c4     0 NOTYPE  LOCAL  DEFAULT    6 $d
  3092: 2400f9c8     0 NOTYPE  LOCAL  DEFAULT    6 $d
  3093: 2400fa88     0 NOTYPE  LOCAL  DEFAULT    6 $d
  3094: 24010288     0 NOTYPE  LOCAL  DEFAULT    6 $d
  3095: 2401028c     0 NOTYPE  LOCAL  DEFAULT    6 $d
  3096: 240102e8     0 NOTYPE  LOCAL  DEFAULT    6 $d
  3097: 00000000     0 FILE    LOCAL  DEFAULT  ABS mbed_compat.c
  3098: 08054408     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3099: 00000000     0 FILE    LOCAL  DEFAULT  ABS mbed_critical_section_api
  3100: 0805440c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3101: 08054428     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3102: 08054430     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3103: 08054458     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3104: 08054468     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3105: 08054470     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3106: 240105e8     1 OBJECT  LOCAL  DEFAULT    6 critical_interrupts_enabl
  3107: 240105e8     0 NOTYPE  LOCAL  DEFAULT    6 $d
  3108: 240105e9     1 OBJECT  LOCAL  DEFAULT    6 state_saved
  3109: 240105e9     0 NOTYPE  LOCAL  DEFAULT    6 $d
  3110: 00000000     0 FILE    LOCAL  DEFAULT  ABS mbed_gpio.c
  3111: 08054474     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3112: 08054475    38 FUNC    LOCAL  DEFAULT    1 _gpio_init_in
  3113: 0805449c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3114: 0805449d    80 FUNC    LOCAL  DEFAULT    1 _gpio_init_out
  3115: 080544e4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3116: 080544ec     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3117: 080544f2     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3118: 080544f6     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3119: 080544fe     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3120: 08054504     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3121: 0805454c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3122: 00000000     0 FILE    LOCAL  DEFAULT  ABS mbed_lp_ticker_api.c
  3123: 08054554     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3124: 08054558     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3125: 0805455c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3126: 08054568     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3127: 240105f0     0 NOTYPE  LOCAL  DEFAULT    6 $d
  3128: 240105f0    56 OBJECT  LOCAL  DEFAULT    6 events
  3129: 24000f60     0 NOTYPE  LOCAL  DEFAULT    4 $d
  3130: 24000f60     4 OBJECT  LOCAL  DEFAULT    4 irq_handler
  3131: 080707d8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3132: 080707d8     8 OBJECT  LOCAL  DEFAULT    1 lp_data
  3133: 080707e0    36 OBJECT  LOCAL  DEFAULT    1 lp_interface
  3134: 080707e0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3135: 00000000     0 FILE    LOCAL  DEFAULT  ABS mbed_pinmap_common.c
  3136: 08054570     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3137: 080545b0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3138: 080545b8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3139: 080545e0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3140: 080545e8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3141: 08054600     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3142: 08054624     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3143: 0805462c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3144: 08054644     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3145: 08054668     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3146: 00000000     0 FILE    LOCAL  DEFAULT  ABS mbed_ticker_api.c
  3147: 08054670     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3148: 08054671   134 FUNC    LOCAL  DEFAULT    1 update_present_time
  3149: 080546f6     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3150: 08054720     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3151: 08054721   252 FUNC    LOCAL  DEFAULT    1 schedule_interrupt
  3152: 08054814     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3153: 0805481c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3154: 0805481d   292 FUNC    LOCAL  DEFAULT    1 initialize
  3155: 0805492c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3156: 08054940     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3157: 08054941    72 FUNC    LOCAL  DEFAULT    1 insert_event
  3158: 08054988     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3159: 080549a2     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3160: 08054a02     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3161: 08054a32     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3162: 08054a68     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3163: 00000000     0 FILE    LOCAL  DEFAULT  ABS mbed_us_ticker_api.c
  3164: 08054a90     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3165: 08054a91     2 FUNC    LOCAL  DEFAULT    1 block_us_ticker_free
  3166: 08054a94     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3167: 08054a98     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3168: 08054a9c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3169: 08054aa8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3170: 24010628     0 NOTYPE  LOCAL  DEFAULT    6 $d
  3171: 24010628    56 OBJECT  LOCAL  DEFAULT    6 events
  3172: 24000f64     0 NOTYPE  LOCAL  DEFAULT    4 $d
  3173: 24000f64     4 OBJECT  LOCAL  DEFAULT    4 irq_handler
  3174: 08070904     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3175: 08070904     8 OBJECT  LOCAL  DEFAULT    1 us_data
  3176: 0807090c    36 OBJECT  LOCAL  DEFAULT    1 us_interface
  3177: 0807090c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3178: 00000000     0 FILE    LOCAL  DEFAULT  ABS mbed_mpu_v7m.c
  3179: 08054ab0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3180: 08054b2c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3181: 00000000     0 FILE    LOCAL  DEFAULT  ABS static_pinmap.cpp
  3182: 08054b4c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3183: 00000000     0 FILE    LOCAL  DEFAULT  ABS CThunkBase.cpp
  3184: 08054b58     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3185: 08054b64     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3186: 24010660     0 NOTYPE  LOCAL  DEFAULT    6 $d
  3187: 00000000     0 FILE    LOCAL  DEFAULT  ABS CriticalSectionLock.cpp
  3188: 08054b68     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3189: 08054b78     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3190: 00000000     0 FILE    LOCAL  DEFAULT  ABS FileBase.cpp
  3191: 08054b88     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3192: 08054b8c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3193: 08054bc4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3194: 08054bd0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3195: 08054c24     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3196: 08054c34     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3197: 08054c48     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3198: 08054cac     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3199: 24010664     0 NOTYPE  LOCAL  DEFAULT    6 $d
  3200: 24010668     0 NOTYPE  LOCAL  DEFAULT    6 $d
  3201: 24010690     0 NOTYPE  LOCAL  DEFAULT    6 $d
  3202: 08070970     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3203: 00000000     0 FILE    LOCAL  DEFAULT  ABS FileHandle.cpp
  3204: 08054cbc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3205: 08054cc0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3206: 08070980     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3207: 00000000     0 FILE    LOCAL  DEFAULT  ABS FilePath.cpp
  3208: 08054cf4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3209: 08054d38     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3210: 08054d44     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3211: 08054d48     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3212: 08054d5a     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3213: 08054d6c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3214: 08054d7e     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3215: 08054d90     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3216: 00000000     0 FILE    LOCAL  DEFAULT  ABS Stream.cpp
  3217: 08054d9a     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3218: 08054d9e     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3219: 08054dce     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3220: 08054e00     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3221: 08054e04     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3222: 08054e08     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3223: 08054e48     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3224: 08054e5c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3225: 08054e88     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3226: 08070a18     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3227: 08070a78     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3228: 00000000     0 FILE    LOCAL  DEFAULT  ABS SysTimer.cpp
  3229: 08054e90     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3230: 08054e91    20 FUNC    LOCAL  DEFAULT    1 _ZN4mbed8internal8SysTime
  3231: 08054e9c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3232: 08054e91    20 FUNC    LOCAL  DEFAULT    1 _ZN4mbed8internal8SysTime
  3233: 08054e91    20 FUNC    LOCAL  DEFAULT    1 _ZN4mbed8internal8SysTime
  3234: 08054ea4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3235: 08054ea5    18 FUNC    LOCAL  DEFAULT    1 _ZNK4mbed15TickerDataCloc
  3236: 08054eb8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3237: 08054eec     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3238: 08054ef0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3239: 08054ef6     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3240: 08054f1e     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3241: 08054f32     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3242: 08054f40     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3243: 08054f60     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3244: 08054f70     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3245: 08054fcc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3246: 08055028     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3247: 08055030     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3248: 0805510c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3249: 08055114     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3250: 08055120     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3251: 08055124     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3252: 08055136     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3253: 08055150     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3254: 08055190     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3255: 0805519c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3256: 080551a0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3257: 08070b38     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3258: 00000000     0 FILE    LOCAL  DEFAULT  ABS except.S
  3259: 00000010     0 NOTYPE  LOCAL  DEFAULT  ABS FAULT_TYPE_HARD_FAULT
  3260: 00000020     0 NOTYPE  LOCAL  DEFAULT  ABS FAULT_TYPE_MEMMANAGE_FAUL
  3261: 00000030     0 NOTYPE  LOCAL  DEFAULT  ABS FAULT_TYPE_BUS_FAULT
  3262: 00000040     0 NOTYPE  LOCAL  DEFAULT  ABS FAULT_TYPE_USAGE_FAULT
  3263: 080551b4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3264: 08074954     0 NOTYPE  LOCAL  DEFAULT    3 $d
  3265: 080551d8     0 NOTYPE  LOCAL  DEFAULT    1 Fault_Handler_Continue
  3266: 080551f6     0 NOTYPE  LOCAL  DEFAULT    1 Fault_Handler_Continue1
  3267: 080551fc     0 NOTYPE  LOCAL  DEFAULT    1 Fault_Handler_Continue2
  3268: 08055214     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3269: 00000000     0 FILE    LOCAL  DEFAULT  ABS mbed_fault_handler.c
  3270: 08055218     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3271: 080552cc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3272: 08055304     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3273: 08055374     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3274: 24010694     0 NOTYPE  LOCAL  DEFAULT    6 $d
  3275: 00000000     0 FILE    LOCAL  DEFAULT  ABS mbed_alloc_wrappers.cpp
  3276: 080553a8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3277: 080553fa     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3278: 08055434     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3279: 080554c4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3280: 080554d0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3281: 080554dc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3282: 0805555c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3283: 08055568     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3284: 240106e8     0 NOTYPE  LOCAL  DEFAULT    6 $d
  3285: 240106e8    28 OBJECT  LOCAL  DEFAULT    6 _ZL10heap_stats
  3286: 24010704     0 NOTYPE  LOCAL  DEFAULT    6 $d
  3287: 24010704    40 OBJECT  LOCAL  DEFAULT    6 _ZL18malloc_stats_mutex
  3288: 00000000     0 FILE    LOCAL  DEFAULT  ABS mbed_assert.c
  3289: 08055574     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3290: 08055584     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3291: 00000000     0 FILE    LOCAL  DEFAULT  ABS mbed_atomic_impl.c
  3292: 08055588     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3293: 0805559c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3294: 080555ae     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3295: 080555c0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3296: 080555d2     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3297: 080555e4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3298: 00000000     0 FILE    LOCAL  DEFAULT  ABS mbed_board.c
  3299: 08055600     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3300: 08055694     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3301: 080556a4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3302: 080556f4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3303: 08055728     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3304: 0805572c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3305: 00000000     0 FILE    LOCAL  DEFAULT  ABS mbed_critical.c
  3306: 08055746     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3307: 08055752     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3308: 0805575e     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3309: 08055764     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3310: 08055784     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3311: 08055790     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3312: 080557a4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3313: 2401072c     0 NOTYPE  LOCAL  DEFAULT    6 $d
  3314: 2401072c     4 OBJECT  LOCAL  DEFAULT    6 critical_section_reentran
  3315: 00000000     0 FILE    LOCAL  DEFAULT  ABS mbed_error.c
  3316: 080557a8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3317: 080557a9    52 FUNC    LOCAL  DEFAULT    1 mbed_halt_system
  3318: 080557d8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3319: 080557dc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3320: 080557dd   400 FUNC    LOCAL  DEFAULT    1 print_error_report.constp
  3321: 08055812     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3322: 08055826     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3323: 08055910     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3324: 0805596c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3325: 08055970     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3326: 08055971   200 FUNC    LOCAL  DEFAULT    1 handle_error.constprop.0
  3327: 08055a18     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3328: 08055a38     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3329: 08055a74     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3330: 08055a84     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3331: 08055a88     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3332: 08055a90     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3333: 08055a94     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3334: 08055aa4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3335: 08055ad4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3336: 24010730     0 NOTYPE  LOCAL  DEFAULT    6 $d
  3337: 24010730     4 OBJECT  LOCAL  DEFAULT    6 error_count
  3338: 24010734     0 NOTYPE  LOCAL  DEFAULT    6 $d
  3339: 24010734     4 OBJECT  LOCAL  DEFAULT    6 error_hook
  3340: 24010738     0 NOTYPE  LOCAL  DEFAULT    6 $d
  3341: 24010738    52 OBJECT  LOCAL  DEFAULT    6 first_error_ctx
  3342: 2401076c     1 OBJECT  LOCAL  DEFAULT    6 halt_in_progress
  3343: 2401076c     0 NOTYPE  LOCAL  DEFAULT    6 $d
  3344: 24010770     0 NOTYPE  LOCAL  DEFAULT    6 $d
  3345: 24010770    52 OBJECT  LOCAL  DEFAULT    6 last_error_ctx
  3346: 240107a4     0 NOTYPE  LOCAL  DEFAULT    6 $d
  3347: 00000000     0 FILE    LOCAL  DEFAULT  ABS mbed_mem_trace.cpp
  3348: 08055ad8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3349: 08055af8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3350: 08055b00     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3351: 08055b28     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3352: 08055b30     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3353: 08055b58     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3354: 08055b60     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3355: 08055b88     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3356: 08055b90     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3357: 08055ba8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3358: 08055bb0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3359: 08055bc8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3360: 240107a8     0 NOTYPE  LOCAL  DEFAULT    6 $d
  3361: 240107a8     4 OBJECT  LOCAL  DEFAULT    6 _ZL12mem_trace_cb
  3362: 240107ac     0 NOTYPE  LOCAL  DEFAULT    6 $d
  3363: 240107ac    40 OBJECT  LOCAL  DEFAULT    6 _ZL15mem_trace_mutex
  3364: 240107d4     1 OBJECT  LOCAL  DEFAULT    6 _ZL16trace_lock_count
  3365: 240107d4     0 NOTYPE  LOCAL  DEFAULT    6 $d
  3366: 00000000     0 FILE    LOCAL  DEFAULT  ABS mbed_os_timer.cpp
  3367: 08055bd0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3368: 08055bec     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3369: 08055bf4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3370: 08055c10     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3371: 08055c14     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3372: 08055c7c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3373: 08055c80     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3374: 08055cbc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3375: 08055cc0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3376: 08055d04     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3377: 240107d8     0 NOTYPE  LOCAL  DEFAULT    6 $d
  3378: 240107d8    72 OBJECT  LOCAL  DEFAULT    6 _ZN4mbed8internal12_GLOBA
  3379: 24010820     0 NOTYPE  LOCAL  DEFAULT    6 $d
  3380: 00000000     0 FILE    LOCAL  DEFAULT  ABS mbed_power_mgmt.c
  3381: 08055d08     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3382: 08055d09    28 FUNC    LOCAL  DEFAULT    1 read_us
  3383: 08055d20     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3384: 08055d24     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3385: 08055d44     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3386: 08055d50     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3387: 08055d78     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3388: 08055d84     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3389: 08055d94     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3390: 08055d98     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3391: 08055df8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3392: 24010824     0 NOTYPE  LOCAL  DEFAULT    6 $d
  3393: 24010824     2 OBJECT  LOCAL  DEFAULT    6 deep_sleep_lock
  3394: 24010828     0 NOTYPE  LOCAL  DEFAULT    6 $d
  3395: 24010828     8 OBJECT  LOCAL  DEFAULT    6 deep_sleep_time
  3396: 24010830     0 NOTYPE  LOCAL  DEFAULT    6 $d
  3397: 24010830     4 OBJECT  LOCAL  DEFAULT    6 sleep_ticker
  3398: 24010838     0 NOTYPE  LOCAL  DEFAULT    6 $d
  3399: 24010838     8 OBJECT  LOCAL  DEFAULT    6 sleep_time
  3400: 00000000     0 FILE    LOCAL  DEFAULT  ABS mbed_retarget.cpp
  3401: 08055e00     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3402: 08055e06     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3403: 08055e0c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3404: 08055e10     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3405: 08055e14     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3406: 08055e18     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3407: 08055e19    20 FUNC    LOCAL  DEFAULT    1 _ZL14singleton_lockv
  3408: 08055e28     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3409: 08055e2c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3410: 08055e2d    16 FUNC    LOCAL  DEFAULT    1 _ZL16singleton_unlockv
  3411: 08055e38     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3412: 08055e3c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3413: 08055e5c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3414: 08055e60     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3415: 08055e8c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3416: 08055e90     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3417: 08055ea8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3418: 08055eac     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3419: 08055ed0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3420: 08055edc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3421: 08055ee0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3422: 08055ee4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3423: 08055ef4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3424: 08055efc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3425: 08055f1c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3426: 08055f28     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3427: 08055f2c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3428: 08055f30     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3429: 08055f36     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3430: 08055f3e     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3431: 08055f48     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3432: 08055f84     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3433: 08055f8c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3434: 08055fb8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3435: 08055fc0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3436: 0805602c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3437: 08056044     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3438: 0805607c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3439: 08056080     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3440: 08056084     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3441: 080560ba     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3442: 080560f0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3443: 0805611c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3444: 08056148     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3445: 08056214     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3446: 08056224     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3447: 08056228     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3448: 080562b8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3449: 080562c4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3450: 080562fa     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3451: 080562fe     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3452: 0805632c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3453: 08056358     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3454: 0805635c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3455: 08056362     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3456: 0805639e     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3457: 080563a4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3458: 080563cc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3459: 080563d4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3460: 080563f8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3461: 08056404     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3462: 08056408     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3463: 0805641c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3464: 08056420     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3465: 08056434     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3466: 08056438     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3467: 08056446     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3468: 0805644c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3469: 08056480     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3470: 08056488     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3471: 08056489    84 FUNC    LOCAL  DEFAULT    1 _ZL18reserve_filehandlev
  3472: 080564d4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3473: 080564dc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3474: 080564fc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3475: 08056508     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3476: 08056544     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3477: 08056548     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3478: 080565e8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3479: 080565f4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3480: 08056650     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3481: 24010840     0 NOTYPE  LOCAL  DEFAULT    6 $d
  3482: 24010840     4 OBJECT  LOCAL  DEFAULT    6 _ZGVZL15default_consolevE
  3483: 24010844    64 OBJECT  LOCAL  DEFAULT    6 _ZL13stdio_in_prev
  3484: 24010844     0 NOTYPE  LOCAL  DEFAULT    6 $d
  3485: 24010884    64 OBJECT  LOCAL  DEFAULT    6 _ZL14stdio_out_prev
  3486: 24010884     0 NOTYPE  LOCAL  DEFAULT    6 $d
  3487: 240108c4     0 NOTYPE  LOCAL  DEFAULT    6 $d
  3488: 240108c4    40 OBJECT  LOCAL  DEFAULT    6 _ZL16filehandle_mutex
  3489: 240108ec     0 NOTYPE  LOCAL  DEFAULT    6 $d
  3490: 240108ec     4 OBJECT  LOCAL  DEFAULT    6 _ZZL15default_consolevE7c
  3491: 240108f0     0 NOTYPE  LOCAL  DEFAULT    6 $d
  3492: 240108f4     0 NOTYPE  LOCAL  DEFAULT    6 $d
  3493: 24000f68     0 NOTYPE  LOCAL  DEFAULT    4 $d
  3494: 24000f68   256 OBJECT  LOCAL  DEFAULT    4 _ZL11filehandles
  3495: 24001068     0 NOTYPE  LOCAL  DEFAULT    4 $d
  3496: 24001068     4 OBJECT  LOCAL  DEFAULT    4 _ZZ5_sbrkE4heap
  3497: 08071100     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3498: 08071150     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3499: 08071150    24 OBJECT  LOCAL  DEFAULT    1 _ZZL15default_consolevE14
  3500: 00000000     0 FILE    LOCAL  DEFAULT  ABS mbed_stats.c
  3501: 0805665c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3502: 080566a8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3503: 00000000     0 FILE    LOCAL  DEFAULT  ABS mbed_wait_api_no_rtos.c
  3504: 080566b8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3505: 080566c8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3506: 00000000     0 FILE    LOCAL  DEFAULT  ABS EventFlags.cpp
  3507: 080566cc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3508: 080566f8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3509: 08056700     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3510: 08056710     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3511: 08056714     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3512: 08056720     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3513: 08056726     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3514: 08056734     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3515: 0805674a     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3516: 0805675c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3517: 00000000     0 FILE    LOCAL  DEFAULT  ABS Kernel.cpp
  3518: 08056760     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3519: 08056790     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3520: 240108f8     0 NOTYPE  LOCAL  DEFAULT    6 $d
  3521: 240108f8     4 OBJECT  LOCAL  DEFAULT    6 _ZZN4rtos6Kernel4impl14ge
  3522: 240108fc     0 NOTYPE  LOCAL  DEFAULT    6 $d
  3523: 240108fc     4 OBJECT  LOCAL  DEFAULT    6 _ZZN4rtos6Kernel4impl14ge
  3524: 00000000     0 FILE    LOCAL  DEFAULT  ABS Mutex.cpp
  3525: 08056798     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3526: 080567d4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3527: 080567e0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3528: 080567f0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3529: 08056824     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3530: 0805682c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3531: 08056858     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3532: 08056860     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3533: 00000000     0 FILE    LOCAL  DEFAULT  ABS Semaphore.cpp
  3534: 08056870     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3535: 0805689c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3536: 080568a4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3537: 080568b4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3538: 080568e8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3539: 080568f0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3540: 080568f6     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3541: 00000000     0 FILE    LOCAL  DEFAULT  ABS ThisThread.cpp
  3542: 08056904     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3543: 08056918     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3544: 00000000     0 FILE    LOCAL  DEFAULT  ABS Thread.cpp
  3545: 08056920     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3546: 08056958     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3547: 08056960     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3548: 080569d0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3549: 080569d4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3550: 080569ec     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3551: 08056aa8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3552: 08056ab4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3553: 08056af8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3554: 08056b30     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3555: 08056b34     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3556: 08056b48     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3557: 08071394     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3558: 00000000     0 FILE    LOCAL  DEFAULT  ABS QSPIFBlockDevice.cpp
  3559: 08056bd0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3560: 08056bd1    28 FUNC    LOCAL  DEFAULT    1 _GLOBAL__sub_I__ZN16QSPIF
  3561: 08056be8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3562: 24001a7c     0 NOTYPE  LOCAL  DEFAULT    4 $d
  3563: 24010900     0 NOTYPE  LOCAL  DEFAULT    6 $d
  3564: 00000000     0 FILE    LOCAL  DEFAULT  ABS stm32h7xx_hal.c
  3565: 08056bec     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3566: 08056bf0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3567: 08056c3c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3568: 08056c4c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3569: 08056c6c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3570: 08056c70     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3571: 08056c78     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3572: 08056c7c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3573: 08056c84     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3574: 08056c88     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3575: 08056c90     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3576: 08056c94     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3577: 08056c9c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3578: 08056ca0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3579: 08056cb0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3580: 08056cb4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3581: 08056cc0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3582: 08056cc4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3583: 08056d16     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3584: 24001070     0 NOTYPE  LOCAL  DEFAULT    4 $d
  3585: 00000000     0 FILE    LOCAL  DEFAULT  ABS stm32h7xx_hal_adc.c
  3586: 08056d68     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3587: 08056d69    32 FUNC    LOCAL  DEFAULT    1 LL_ADC_SetChannelSampling
  3588: 08056d88     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3589: 08056d89     8 FUNC    LOCAL  DEFAULT    1 LL_ADC_IsEnabled
  3590: 08056d90     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3591: 08056d91     8 FUNC    LOCAL  DEFAULT    1 LL_ADC_REG_IsConversionOn
  3592: 08056d98     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3593: 08056d9c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3594: 08056ea8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3595: 08056eb8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3596: 08056ec0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3597: 0805721c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3598: 08057250     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3599: 08057254     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3600: 0805731c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3601: 08057320     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3602: 080573c0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3603: 080573d4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3604: 080574c0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3605: 080574cc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3606: 08057536     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3607: 08057574     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3608: 08057684     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3609: 080576a0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3610: 08057894     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3611: 00000000     0 FILE    LOCAL  DEFAULT  ABS stm32h7xx_hal_adc_ex.c
  3612: 080578b8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3613: 080578b9     8 FUNC    LOCAL  DEFAULT    1 LL_ADC_IsEnabled
  3614: 080578c0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3615: 080578c1     8 FUNC    LOCAL  DEFAULT    1 LL_ADC_REG_IsConversionOn
  3616: 080578c8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3617: 08057960     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3618: 08057968     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3619: 08057a24     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3620: 00000000     0 FILE    LOCAL  DEFAULT  ABS stm32h7xx_hal_cortex.c
  3621: 08057a30     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3622: 08057a50     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3623: 08057a54     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3624: 08057ab0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3625: 08057ab8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3626: 08057ad0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3627: 08057ad4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3628: 08057af4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3629: 08057af8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3630: 08057b10     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3631: 08057b14     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3632: 08057b30     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3633: 08057b34     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3634: 08057b88     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3635: 08057b8c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3636: 08057ba0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3637: 00000000     0 FILE    LOCAL  DEFAULT  ABS stm32h7xx_hal_dma.c
  3638: 08057ba4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3639: 08057cb8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3640: 08057cc4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3641: 00000000     0 FILE    LOCAL  DEFAULT  ABS stm32h7xx_hal_eth.c
  3642: 08057cca     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3643: 08057ccb   386 FUNC    LOCAL  DEFAULT    1 ETH_SetMACConfig
  3644: 08057e4c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3645: 08057e4d   140 FUNC    LOCAL  DEFAULT    1 ETH_SetDMAConfig
  3646: 08057ed0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3647: 08057ed8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3648: 08057ed9   772 FUNC    LOCAL  DEFAULT    1 ETH_Prepare_Tx_Descriptor
  3649: 080581d4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3650: 080581dc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3651: 0805821a     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3652: 080582b2     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3653: 0805830a     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3654: 080583bc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3655: 080584c4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3656: 08058562     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3657: 0805859c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3658: 08058620     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3659: 08058622     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3660: 08058624     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3661: 08058626     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3662: 08058628     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3663: 0805878c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3664: 080587e8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3665: 08058848     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3666: 0805884c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3667: 080589d8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3668: 080589f0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3669: 08058a48     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3670: 080589f1   120 FUNC    LOCAL  DEFAULT    1 ETH_MAC_MDIO_ClkConfig
  3671: 08058a68     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3672: 08058c78     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3673: 00000000     0 FILE    LOCAL  DEFAULT  ABS stm32h7xx_hal_exti.c
  3674: 08058c84     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3675: 00000000     0 FILE    LOCAL  DEFAULT  ABS stm32h7xx_hal_fdcan.c
  3676: 08058da4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3677: 08058da5   124 FUNC    LOCAL  DEFAULT    1 FDCAN_CopyMessageToRAM
  3678: 08058e1c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3679: 08058e20     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3680: 08058e24     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3681: 08059154     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3682: 08059160     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3683: 080591f8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3684: 080591fc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3685: 08059274     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3686: 080592a6     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3687: 080592ce     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3688: 080592f6     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3689: 08059326     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3690: 0805934c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3691: 0805937e     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3692: 080593ee     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3693: 08059454     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3694: 080595b8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3695: 080595bc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3696: 08059634     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3697: 08059638     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3698: 0805963a     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3699: 0805963c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3700: 0805963e     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3701: 08059640     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3702: 08059642     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3703: 08059644     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3704: 08059646     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3705: 08059648     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3706: 0805964a     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3707: 0805964c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3708: 0805964e     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3709: 08059650     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3710: 08059654     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3711: 080598d8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3712: 080598e0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3713: 080713a4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3714: 080713f0    16 OBJECT  LOCAL  DEFAULT    1 DLCtoBytes
  3715: 00000000     0 FILE    LOCAL  DEFAULT  ABS stm32h7xx_hal_gpio.c
  3716: 08059910     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3717: 08059ad4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3718: 08059ae0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3719: 00000000     0 FILE    LOCAL  DEFAULT  ABS stm32h7xx_hal_hsem.c
  3720: 08059aec     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3721: 08059b00     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3722: 08059b08     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3723: 08059b14     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3724: 08059b18     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3725: 08059b24     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3726: 08059b28     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3727: 08059b40     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3728: 00000000     0 FILE    LOCAL  DEFAULT  ABS stm32h7xx_hal_i2c.c
  3729: 08059b44     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3730: 08059b45    28 FUNC    LOCAL  DEFAULT    1 I2C_Flush_TXDR
  3731: 08059b60     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3732: 08059b61    40 FUNC    LOCAL  DEFAULT    1 I2C_TransferConfig
  3733: 08059b84     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3734: 08059b88     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3735: 08059b89   104 FUNC    LOCAL  DEFAULT    1 I2C_Enable_IRQ
  3736: 08059be8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3737: 0805a3e9   260 FUNC    LOCAL  DEFAULT    1 I2C_Master_ISR_DMA
  3738: 0805a6c1   396 FUNC    LOCAL  DEFAULT    1 I2C_Slave_ISR_DMA
  3739: 08059bf0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3740: 08059bf1    66 FUNC    LOCAL  DEFAULT    1 I2C_Disable_IRQ
  3741: 08059c32     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3742: 08059c33    26 FUNC    LOCAL  DEFAULT    1 I2C_ConvertOtherXferOptio
  3743: 08059c4c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3744: 08059c4e     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3745: 0805a2c7   290 FUNC    LOCAL  DEFAULT    1 I2C_Master_ISR_IT
  3746: 0805a84d   274 FUNC    LOCAL  DEFAULT    1 I2C_Slave_ISR_IT
  3747: 08059cf0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3748: 08059d8c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3749: 08059d94     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3750: 08059e30     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3751: 0805a95f    22 FUNC    LOCAL  DEFAULT    1 I2C_DMAAbort
  3752: 08059e38     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3753: 08059eec     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3754: 08059ef4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3755: 08059f18     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3756: 08059f1c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3757: 08059f2a     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3758: 08059f2b    68 FUNC    LOCAL  DEFAULT    1 I2C_ITMasterSeqCplt
  3759: 08059f6e     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3760: 08059f6f   108 FUNC    LOCAL  DEFAULT    1 I2C_ITSlaveSeqCplt
  3761: 08059fda     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3762: 08059fdb   136 FUNC    LOCAL  DEFAULT    1 I2C_ITAddrCplt.constprop.
  3763: 0805a064     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3764: 0805a065    96 FUNC    LOCAL  DEFAULT    1 I2C_ITListenCplt
  3765: 0805a0c0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3766: 0805a0c4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3767: 0805a0c6     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3768: 0805a0c8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3769: 0805a0c9    44 FUNC    LOCAL  DEFAULT    1 I2C_TreatErrorCallback
  3770: 0805a0f4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3771: 0805a0f5   228 FUNC    LOCAL  DEFAULT    1 I2C_ITError
  3772: 0805a1cc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3773: 0805a1d8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3774: 0805a1d9   238 FUNC    LOCAL  DEFAULT    1 I2C_ITMasterCplt
  3775: 0805a2c6     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3776: 0805a3e8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3777: 0805a4ec     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3778: 0805a54c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3779: 0805a54d   372 FUNC    LOCAL  DEFAULT    1 I2C_ITSlaveCplt.constprop
  3780: 0805a6b8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3781: 0805a6c0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3782: 0805a80e     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3783: 0805a818     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3784: 0805a848     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3785: 0805a84c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3786: 0805a95e     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3787: 00000000     0 FILE    LOCAL  DEFAULT  ABS stm32h7xx_hal_i2c_ex.c
  3788: 0805a974     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3789: 0805a9c0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3790: 0805a9e8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3791: 00000000     0 FILE    LOCAL  DEFAULT  ABS stm32h7xx_hal_lptim.c
  3792: 0805a9f0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3793: 0805a9f1    48 FUNC    LOCAL  DEFAULT    1 LPTIM_WaitForFlag
  3794: 0805aa1c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3795: 0805aa20     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3796: 0805aa24     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3797: 0805aae4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3798: 0805aaf0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3799: 00000000     0 FILE    LOCAL  DEFAULT  ABS stm32h7xx_hal_pcd.c
  3800: 0805ab3e     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3801: 0805ab40     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3802: 0805ac52     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3803: 0805ac54     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3804: 0805ac7e     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3805: 0805acbc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3806: 0805ad04     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3807: 0805ad06     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3808: 0805ad08     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3809: 0805b29c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3810: 0805b2a4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3811: 0805b2cc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3812: 0805b33c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3813: 0805b39a     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3814: 0805b3e2     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3815: 0805b3f2     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3816: 0805b432     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3817: 0805b4a6     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3818: 0805b512     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3819: 00000000     0 FILE    LOCAL  DEFAULT  ABS stm32h7xx_hal_pcd_ex.c
  3820: 0805b544     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3821: 0805b584     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3822: 0805b58c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3823: 0805b5b2     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3824: 00000000     0 FILE    LOCAL  DEFAULT  ABS stm32h7xx_hal_pwr.c
  3825: 0805b5b4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3826: 0805b5c0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3827: 0805b5c4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3828: 0805b5dc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3829: 00000000     0 FILE    LOCAL  DEFAULT  ABS stm32h7xx_hal_pwr_ex.c
  3830: 0805b5e0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3831: 0805b654     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3832: 0805b658     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3833: 0805b6d4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3834: 0805b6dc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3835: 0805b6e8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3836: 00000000     0 FILE    LOCAL  DEFAULT  ABS stm32h7xx_hal_rcc.c
  3837: 0805b6ec     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3838: 0805b988     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3839: 0805b990     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3840: 0805bc0c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3841: 0805bc10     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3842: 0805bd38     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3843: 0805bd54     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3844: 0805bf88     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3845: 0805bfa0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3846: 0805bfd4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3847: 0805bfe4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3848: 0805c000     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3849: 0805c008     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3850: 0805c024     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3851: 0805c02c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3852: 0805c114     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3853: 0805c118     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3854: 0805c164     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3855: 00000000     0 FILE    LOCAL  DEFAULT  ABS stm32h7xx_hal_rcc_ex.c
  3856: 0805c16c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3857: 0805c16d   240 FUNC    LOCAL  DEFAULT    1 RCCEx_PLL2_Config
  3858: 0805c258     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3859: 0805c25c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3860: 0805c25d   240 FUNC    LOCAL  DEFAULT    1 RCCEx_PLL3_Config
  3861: 0805c348     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3862: 0805c34c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3863: 0805c382     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3864: 0805c38c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3865: 0805c564     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3866: 0805c56c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3867: 0805c634     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3868: 0805c638     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3869: 0805c87c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3870: 0805c882     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3871: 0805c8b0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3872: 0805c8bc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3873: 0805c924     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3874: 0805c930     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3875: 0805c948     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3876: 0805c94c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3877: 0805cc0c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3878: 0805cc10     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3879: 0805ccf4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3880: 0805ccf8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3881: 0805cd14     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3882: 0805cd1c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3883: 0805ce5c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3884: 0805ce70     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3885: 0805cfb0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3886: 0805cfc4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3887: 0805d104     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3888: 0805d118     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3889: 0805d130     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3890: 0805d13a     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3891: 0805d398     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3892: 0805d3a8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3893: 0805d3b0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3894: 0805d3b8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3895: 0805d3c8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3896: 00000000     0 FILE    LOCAL  DEFAULT  ABS stm32h7xx_hal_rtc.c
  3897: 0805d3cc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3898: 0805d3ce     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3899: 0805d476     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3900: 0805d4d8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3901: 0805d508     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3902: 0805d548     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3903: 0805d588     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3904: 0805d58c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3905: 0805d618     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3906: 0805d62e     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3907: 0805d6f2     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3908: 0805d78e     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3909: 00000000     0 FILE    LOCAL  DEFAULT  ABS stm32h7xx_hal_rtc_ex.c
  3910: 0805d8f6     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3911: 0805d900     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3912: 00000000     0 FILE    LOCAL  DEFAULT  ABS stm32h7xx_hal_sram.c
  3913: 0805d902     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3914: 0805d904     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3915: 0805d968     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3916: 00000000     0 FILE    LOCAL  DEFAULT  ABS stm32h7xx_hal_tim.c
  3917: 0805d96c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3918: 0805d970     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3919: 0805da34     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3920: 0805da3c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3921: 0805da9c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3922: 0805dab8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3923: 0805dbcc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3924: 00000000     0 FILE    LOCAL  DEFAULT  ABS stm32h7xx_hal_uart.c
  3925: 0805dbd8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3926: 0805dbdc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3927: 0805dc5a     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3928: 0805dc6c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3929: 0805de54     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3930: 08071429     6 OBJECT  LOCAL  DEFAULT    1 CSWTCH.61
  3931: 08071429     6 OBJECT  LOCAL  DEFAULT    1 CSWTCH.62
  3932: 08071429     6 OBJECT  LOCAL  DEFAULT    1 CSWTCH.63
  3933: 08071400    41 OBJECT  LOCAL  DEFAULT    1 CSWTCH.64
  3934: 08071429     6 OBJECT  LOCAL  DEFAULT    1 CSWTCH.65
  3935: 08071429     6 OBJECT  LOCAL  DEFAULT    1 CSWTCH.66
  3936: 0805deb4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3937: 0805dec4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3938: 0805dee8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3939: 0805df68     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3940: 0805df78     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3941: 0805e022     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3942: 0805e0b6     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3943: 0805e120     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3944: 08071429     6 OBJECT  LOCAL  DEFAULT    1 CSWTCH.60
  3945: 08071400    41 OBJECT  LOCAL  DEFAULT    1 CSWTCH.59
  3946: 0807142f     6 OBJECT  LOCAL  DEFAULT    1 CSWTCH.67
  3947: 08071436     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3948: 00000000     0 FILE    LOCAL  DEFAULT  ABS stm32h7xx_hal_uart_ex.c
  3949: 0805e180     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3950: 0805e1a0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3951: 00000000     0 FILE    LOCAL  DEFAULT  ABS stm32h7xx_ll_fmc.c
  3952: 0805e1c0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3953: 0805e244     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3954: 0805e248     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3955: 0805e2a0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3956: 0805e2d8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3957: 00000000     0 FILE    LOCAL  DEFAULT  ABS stm32h7xx_ll_usb.c
  3958: 0805e2dc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3959: 0805e2dd    48 FUNC    LOCAL  DEFAULT    1 USB_CoreReset
  3960: 0805e308     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3961: 0805e30c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3962: 0805e3a0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3963: 0805e444     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3964: 0805e480     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3965: 0805e48c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3966: 0805e498     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3967: 0805e4c8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3968: 0805e4e8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3969: 0805e4ec     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3970: 0805e508     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3971: 0805e50c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3972: 0805e51c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3973: 0805e684     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3974: 0805e688     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3975: 0805e69e     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3976: 0805e71c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3977: 0805e7c0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3978: 0805e7c8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3979: 0805e8b4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3980: 0805e8bc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3981: 0805e8e4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3982: 0805ea98     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3983: 0805eaa4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3984: 0805eae4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3985: 0805eb3a     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3986: 0805eb8c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3987: 0805ebcc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3988: 0805ebec     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3989: 0805ec08     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3990: 0805ec24     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3991: 0805ec2c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3992: 0805ec3c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3993: 0805ec4c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3994: 0805ec5e     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3995: 0805ec80     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3996: 0805ec88     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3997: 0805eca8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  3998: 0805ecf0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  3999: 00000000     0 FILE    LOCAL  DEFAULT  ABS system_stm32h7xx_dualcore
  4000: 0805ecf4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4001: 0805edac     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4002: 0805edd8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4003: 0805eefc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4004: 24001074     0 NOTYPE  LOCAL  DEFAULT    4 $d
  4005: 24001078     0 NOTYPE  LOCAL  DEFAULT    4 $d
  4006: 00000000     0 FILE    LOCAL  DEFAULT  ABS cyabs_rtos_rtxv5.c
  4007: 0805ef20     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4008: 0805ef21    36 FUNC    LOCAL  DEFAULT    1 error_converter
  4009: 0805ef38     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4010: 0805ef44     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4011: 0805ef5c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4012: 24010904     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4013: 24010904     4 OBJECT  LOCAL  DEFAULT    6 dbgErr
  4014: 08071460     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4015: 08071460    24 OBJECT  LOCAL  DEFAULT    1 CSWTCH.11
  4016: 00000000     0 FILE    LOCAL  DEFAULT  ABS cyhal_sdio.c
  4017: 0805ef60     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4018: 0805efdc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4019: 24010908     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4020: 24010908     4 OBJECT  LOCAL  DEFAULT    6 irqstatus
  4021: 2401090c     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4022: 2401090c     4 OBJECT  LOCAL  DEFAULT    6 sdio_irq_handler
  4023: 24010910     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4024: 24010910     4 OBJECT  LOCAL  DEFAULT    6 sdio_transfer_failed
  4025: 24010914     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4026: 24010914     4 OBJECT  LOCAL  DEFAULT    6 sdio_transfer_finished_se
  4027: 24010918     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4028: 24010918     4 OBJECT  LOCAL  DEFAULT    6 whd_handler
  4029: 00000000     0 FILE    LOCAL  DEFAULT  ABS portenta_power.cpp
  4030: 0805eff4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4031: 00000000     0 FILE    LOCAL  DEFAULT  ABS system_clock_override.c
  4032: 0805f068     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4033: 0805f218     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4034: 0805f228     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4035: 0805f23c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4036: 0805f240     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4037: 00000000     0 FILE    LOCAL  DEFAULT  ABS analogin_device.c
  4038: 0805f294     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4039: 0805f2e8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4040: 0805f2f4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4041: 0805f448     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4042: 0805f478     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4043: 0805f4f0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4044: 0805f504     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4045: 0805f5ac     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4046: 00000000     0 FILE    LOCAL  DEFAULT  ABS i2c_device.c
  4047: 0805f624     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4048: 0805f6b0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4049: 00000000     0 FILE    LOCAL  DEFAULT  ABS serial_device.c
  4050: 0805f6d4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4051: 0805f6d5   128 FUNC    LOCAL  DEFAULT    1 uart_irq
  4052: 0805f748     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4053: 0805f754     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4054: 0805f755    12 FUNC    LOCAL  DEFAULT    1 lpuart1_irq
  4055: 0805f75c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4056: 0805f760     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4057: 0805f761    12 FUNC    LOCAL  DEFAULT    1 uart8_irq
  4058: 0805f768     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4059: 0805f76c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4060: 0805f76d    12 FUNC    LOCAL  DEFAULT    1 uart7_irq
  4061: 0805f774     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4062: 0805f778     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4063: 0805f779    12 FUNC    LOCAL  DEFAULT    1 uart6_irq
  4064: 0805f780     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4065: 0805f784     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4066: 0805f785    12 FUNC    LOCAL  DEFAULT    1 uart5_irq
  4067: 0805f78c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4068: 0805f790     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4069: 0805f791    12 FUNC    LOCAL  DEFAULT    1 uart4_irq
  4070: 0805f798     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4071: 0805f79c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4072: 0805f79d    12 FUNC    LOCAL  DEFAULT    1 uart3_irq
  4073: 0805f7a4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4074: 0805f7a8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4075: 0805f7a9    12 FUNC    LOCAL  DEFAULT    1 uart2_irq
  4076: 0805f7b0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4077: 0805f7b4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4078: 0805f7b5    12 FUNC    LOCAL  DEFAULT    1 uart1_irq
  4079: 0805f7bc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4080: 0805f7c0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4081: 0805f7d0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4082: 0805f7d8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4083: 0805f8dc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4084: 0805f91c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4085: 0805f984     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4086: 0805f988     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4087: 0805f9ac     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4088: 0805f9b0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4089: 0805fa7c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4090: 2401091c     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4091: 2401091c     4 OBJECT  LOCAL  DEFAULT    6 irq_handler
  4092: 24010920     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4093: 24010944     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4094: 00000000     0 FILE    LOCAL  DEFAULT  ABS USBPhy_STM32.cpp
  4095: 0805fa94     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4096: 0805fa96     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4097: 0805fa98     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4098: 0805fa9c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4099: 0805faa2     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4100: 0805faa8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4101: 0805faac     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4102: 0805fab0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4103: 0805fab4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4104: 0805face     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4105: 0805fade     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4106: 0805fb02     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4107: 0805fb0e     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4108: 0805fb30     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4109: 0805fb31    32 FUNC    LOCAL  DEFAULT    1 __NVIC_DisableIRQ
  4110: 0805fb4c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4111: 0805fb50     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4112: 0805fb74     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4113: 0805fb7c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4114: 0805fba4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4115: 0805fbac     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4116: 0805fbc4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4117: 0805fbcc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4118: 0805fbe4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4119: 0805fbec     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4120: 0805fc04     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4121: 0805fc0c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4122: 0805fc3c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4123: 0805fc44     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4124: 0805fc60     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4125: 0805fc68     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4126: 0805fc84     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4127: 0805fc8c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4128: 0805fca8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4129: 0805fcb0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4130: 0805fce0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4131: 0805fce8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4132: 0805fd0c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4133: 0805fd14     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4134: 0805fd40     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4135: 0805fd48     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4136: 0805fd80     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4137: 0805fd8c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4138: 0805ff64     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4139: 0805ff98     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4140: 0805ffcc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4141: 0805ffd4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4142: 0805ffec     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4143: 08060038     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4144: 08060044     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4145: 08060062     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4146: 0806008e     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4147: 080600c0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4148: 080600cc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4149: 080600da     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4150: 080600e8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4151: 080600ea     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4152: 08060164     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4153: 08060198     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4154: 24010e54     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4155: 24010e54     4 OBJECT  LOCAL  DEFAULT    6 _ZGVZ11get_usb_phyvE6usbp
  4156: 24010e58     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4157: 24010e58     4 OBJECT  LOCAL  DEFAULT    6 _ZL8instance
  4158: 24010e5c     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4159: 24010e5c  1060 OBJECT  LOCAL  DEFAULT    6 _ZZ11get_usb_phyvE6usbphy
  4160: 0807208c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4161: 0807208c    24 OBJECT  LOCAL  DEFAULT    1 _ZL11tx_ep_sizes
  4162: 080720a4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4163: 08072120     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4164: 08072120    68 OBJECT  LOCAL  DEFAULT    1 _ZZN8USBPhyHw14endpoint_t
  4165: 00000000     0 FILE    LOCAL  DEFAULT  ABS analogin_api.c
  4166: 080601ac     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4167: 00000000     0 FILE    LOCAL  DEFAULT  ABS can_api.c
  4168: 080601b0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4169: 080601b1   212 FUNC    LOCAL  DEFAULT    1 can_irq
  4170: 08060278     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4171: 08060284     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4172: 0806028c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4173: 08060290     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4174: 08060294     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4175: 0806029c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4176: 080602a0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4177: 24011280     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4178: 24011280     8 OBJECT  LOCAL  DEFAULT    6 can_irq_ids
  4179: 24011288     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4180: 24011288     4 OBJECT  LOCAL  DEFAULT    6 irq_handler
  4181: 00000000     0 FILE    LOCAL  DEFAULT  ABS gpio_api.c
  4182: 080602a4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4183: 080602b4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4184: 08060400     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4185: 08060434     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4186: 08060458     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4187: 08060460     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4188: 0806049c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4189: 080604a0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4190: 080604a8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4191: 080604dc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4192: 080602bf     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4193: 080602c0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4194: 00000000     0 FILE    LOCAL  DEFAULT  ABS hal_tick_overrides.c
  4195: 080604e4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4196: 080604f0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4197: 08060540     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4198: 2401128c     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4199: 2401128c     2 OBJECT  LOCAL  DEFAULT    6 prev_tick_remainder
  4200: 24011290     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4201: 24011290     4 OBJECT  LOCAL  DEFAULT    6 prev_time
  4202: 24011294     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4203: 24011294     4 OBJECT  LOCAL  DEFAULT    6 total_ticks
  4204: 00000000     0 FILE    LOCAL  DEFAULT  ABS i2c_api.c
  4205: 08060550     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4206: 08060551    36 FUNC    LOCAL  DEFAULT    1 __NVIC_SetPriority
  4207: 08060570     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4208: 08060574     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4209: 08060575    28 FUNC    LOCAL  DEFAULT    1 i2c4_irq
  4210: 0806058c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4211: 08060590     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4212: 08060591    28 FUNC    LOCAL  DEFAULT    1 i2c3_irq
  4213: 080605a8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4214: 080605ac     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4215: 080605ad    28 FUNC    LOCAL  DEFAULT    1 i2c2_irq
  4216: 080605c4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4217: 080605c8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4218: 080605c9    28 FUNC    LOCAL  DEFAULT    1 i2c1_irq
  4219: 080605e0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4220: 080605e4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4221: 08060654     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4222: 0806065c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4223: 08060674     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4224: 08060682     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4225: 08060686     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4226: 080606a0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4227: 080606b4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4228: 08060768     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4229: 08060784     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4230: 080607c0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4231: 080607c8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4232: 080607ee     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4233: 08060802     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4234: 0806080a     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4235: 08060850     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4236: 08060862     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4237: 08060880     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4238: 080609a4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4239: 080609b4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4240: 08060a78     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4241: 08060a88     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4242: 08060b10     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4243: 08060b20     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4244: 08060b70     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4245: 08060b94     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4246: 08060c9c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4247: 08060cd4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4248: 08060e10     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4249: 08060e44     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4250: 08060eb0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4251: 08060eb8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4252: 08060f50     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4253: 08060f58     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4254: 24011298     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4255: 24011298  2560 OBJECT  LOCAL  DEFAULT    6 I2c_valid_timing
  4256: 24011c98     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4257: 24011c98     4 OBJECT  LOCAL  DEFAULT    6 I2c_valid_timing_nbr
  4258: 24011c9c     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4259: 24011c9c    20 OBJECT  LOCAL  DEFAULT    6 i2c_handles
  4260: 08072274     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4261: 08072274   132 OBJECT  LOCAL  DEFAULT    1 I2C_Charac
  4262: 00000000     0 FILE    LOCAL  DEFAULT  ABS lp_ticker.c
  4263: 08060f9c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4264: 08060fa0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4265: 08060fa4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4266: 08060fb0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4267: 08060fb4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4268: 08060fdc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4269: 08060fe8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4270: 0806103c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4271: 08061054     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4272: 08061190     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4273: 080612b1   216 FUNC    LOCAL  DEFAULT    1 LPTIM_IRQHandler
  4274: 080611c0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4275: 080611e0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4276: 080611e8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4277: 08061290     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4278: 080612b0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4279: 08061368     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4280: 08061388     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4281: 24011cb0     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4282: 24011cb0     4 OBJECT  LOCAL  DEFAULT    6 LPTICKER_inited
  4283: 24011cb4     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4284: 24011cec     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4285: 24011ced     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4286: 24011cee     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4287: 24011cf0     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4288: 24011cf4     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4289: 24011cf5     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4290: 24011cf6     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4291: 08072348     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4292: 08072348     8 OBJECT  LOCAL  DEFAULT    1 info.0
  4293: 00000000     0 FILE    LOCAL  DEFAULT  ABS mbed_overrides.c
  4294: 0806138c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4295: 08061390     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4296: 080614a0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4297: 24011cf8     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4298: 00000000     0 FILE    LOCAL  DEFAULT  ABS pinmap.c
  4299: 080614b0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4300: 080614b1    40 FUNC    LOCAL  DEFAULT    1 configure_dualpad_switch
  4301: 080614d4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4302: 080614d8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4303: 080614d9    76 FUNC    LOCAL  DEFAULT    1 stm_pin_PullConfig
  4304: 0806151c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4305: 08061524     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4306: 0806159a     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4307: 0806159e     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4308: 0806167c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4309: 08061694     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4310: 08061718     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4311: 08072394     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4312: 080723bc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4313: 00000000     0 FILE    LOCAL  DEFAULT  ABS serial_api.c
  4314: 08061724     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4315: 08061725     8 FUNC    LOCAL  DEFAULT    1 LL_USART_IsEnabled
  4316: 0806172c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4317: 0806172d     8 FUNC    LOCAL  DEFAULT    1 LL_USART_IsActiveFlag_TC
  4318: 08061734     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4319: 08061735    40 FUNC    LOCAL  DEFAULT    1 debug.constprop.0
  4320: 08061754     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4321: 0806175c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4322: 08061960     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4323: 08061990     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4324: 080619ac     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4325: 080619b0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4326: 080619c4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4327: 080619c8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4328: 08061a4c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4329: 08061a54     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4330: 08061b28     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4331: 08061b3c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4332: 08061ba8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4333: 08061bb0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4334: 08061c1c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4335: 08061c24     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4336: 08061e38     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4337: 08061e80     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4338: 08061f40     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4339: 24011cfc     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4340: 24011d20     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4341: 00000000     0 FILE    LOCAL  DEFAULT  ABS sleep.c
  4342: 08061f64     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4343: 08061f84     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4344: 08061f88     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4345: 0806208c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4346: 00000000     0 FILE    LOCAL  DEFAULT  ABS us_ticker.c
  4347: 080620a8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4348: 080620c8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4349: 080620d0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4350: 080620d4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4351: 080620d8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4352: 08062190     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4353: 080621b4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4354: 080621c8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4355: 080621cc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4356: 080621d4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4357: 080621d8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4358: 080621f0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4359: 080621f4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4360: 08062210     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4361: 08062214     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4362: 08062224     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4363: 08062228     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4364: 08062234     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4365: 08062238     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4366: 08062254     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4367: 08062268     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4368: 08062284     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4369: 24011d24     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4370: 24011d70     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4371: 24011d74     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4372: 24011d78     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4373: 08072560     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4374: 08072560     8 OBJECT  LOCAL  DEFAULT    1 info.0
  4375: 00000000     0 FILE    LOCAL  DEFAULT  ABS eh_exception.cc
  4376: 08062298     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4377: 08074954     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4378: 0806229c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4379: 08074954     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4380: 080622a0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4381: 080622a4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4382: 08074954     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4383: 080622a8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4384: 08074954     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4385: 08072568     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4386: 0807257c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4387: 08072584     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4388: 0807258c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4389: 08072598     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4390: 080725a0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4391: 080725c0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4392: 080725e4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4393: 080725f8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4394: 08072608     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4395: 00000000     0 FILE    LOCAL  DEFAULT  ABS hash_bytes.cc
  4396: 080622b8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4397: 08062358     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4398: 08074954     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4399: 00000000     0 FILE    LOCAL  DEFAULT  ABS eh_personality.cc
  4400: 0806235c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4401: 0806235d   192 FUNC    LOCAL  DEFAULT    1 _ZL28read_encoded_value_w
  4402: 0806236e     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4403: 08074954     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4404: 0806241c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4405: 0806241d    56 FUNC    LOCAL  DEFAULT    1 _ZL21base_of_encoded_valu
  4406: 08073db4     0 NOTYPE  LOCAL  DEFAULT    2 $d
  4407: 0807495c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4408: 08062454     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4409: 08062455   148 FUNC    LOCAL  DEFAULT    1 _ZL17parse_lsda_headerP15
  4410: 08074964     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4411: 080624e8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4412: 080628f8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4413: 0806290c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4414: 08073dc0     0 NOTYPE  LOCAL  DEFAULT    2 $d
  4415: 0807496c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4416: 0806237b     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4417: 0806237c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4418: 00000000     0 FILE    LOCAL  DEFAULT  ABS bad_cast.cc
  4419: 080629cc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4420: 080629d0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4421: 08074974     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4422: 080629d4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4423: 080629e4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4424: 0807497c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4425: 080629e8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4426: 08062a00     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4427: 0807497c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4428: 0807261c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4429: 0807262c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4430: 08072638     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4431: 08072644     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4432: 00000000     0 FILE    LOCAL  DEFAULT  ABS eh_alloc.cc
  4433: 08062a04     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4434: 08062a05   144 FUNC    LOCAL  DEFAULT    1 _ZN12_GLOBAL__N_14pool4fr
  4435: 08062a90     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4436: 0807497c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4437: 08062a94     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4438: 08062a95   100 FUNC    LOCAL  DEFAULT    1 _ZN12_GLOBAL__N_14pool8al
  4439: 08062af4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4440: 0807497c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4441: 08062af8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4442: 0807497c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4443: 08062b28     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4444: 08062b44     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4445: 0807497c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4446: 08062b48     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4447: 08062b49    40 FUNC    LOCAL  DEFAULT    1 _GLOBAL__sub_I__ZN9__gnu_
  4448: 08062b6c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4449: 0807497c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4450: 24001a80     0 NOTYPE  LOCAL  DEFAULT    4 $d
  4451: 24011d7c     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4452: 24011d7c    16 OBJECT  LOCAL  DEFAULT    6 _ZN12_GLOBAL__N_114emerge
  4453: 00000000     0 FILE    LOCAL  DEFAULT  ABS bad_alloc.cc
  4454: 08062b70     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4455: 08062b74     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4456: 0807497c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4457: 08062b78     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4458: 08062b88     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4459: 0807497c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4460: 08062b8c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4461: 08062ba4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4462: 0807497c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4463: 08072658     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4464: 08072668     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4465: 08072674     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4466: 08072684     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4467: 00000000     0 FILE    LOCAL  DEFAULT  ABS eh_call.cc
  4468: 08062ba8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4469: 08062ba9    58 FUNC    LOCAL  DEFAULT    1 _ZN10__cxxabiv1L24__is_gx
  4470: 0807497c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4471: 08062be4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4472: 0807497c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4473: 08062c04     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4474: 08062cd4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4475: 08073de4     0 NOTYPE  LOCAL  DEFAULT    2 $d
  4476: 0807497c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4477: 00000000     0 FILE    LOCAL  DEFAULT  ABS eh_aux_runtime.cc
  4478: 08062ce0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4479: 08062cf4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4480: 08073e0c     0 NOTYPE  LOCAL  DEFAULT    2 $d
  4481: 08074984     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4482: 00000000     0 FILE    LOCAL  DEFAULT  ABS eh_catch.cc
  4483: 08062d00     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4484: 08073e18     0 NOTYPE  LOCAL  DEFAULT    2 $d
  4485: 0807498c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4486: 08062d80     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4487: 08074994     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4488: 00000000     0 FILE    LOCAL  DEFAULT  ABS eh_globals.cc
  4489: 08062e08     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4490: 08062e0c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4491: 0807499c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4492: 08062e10     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4493: 08062e14     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4494: 0807499c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4495: 24011d8c     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4496: 24011d8c    12 OBJECT  LOCAL  DEFAULT    6 _ZL10eh_globals
  4497: 00000000     0 FILE    LOCAL  DEFAULT  ABS eh_terminate.cc
  4498: 08062e18     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4499: 08073e24     0 NOTYPE  LOCAL  DEFAULT    2 $d
  4500: 0807499c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4501: 08062e40     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4502: 08062e50     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4503: 080749a4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4504: 08062e54     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4505: 08073e50     0 NOTYPE  LOCAL  DEFAULT    2 $d
  4506: 080749ac     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4507: 08062e5c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4508: 08062e6c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4509: 08073e5c     0 NOTYPE  LOCAL  DEFAULT    2 $d
  4510: 080749b4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4511: 08062e70     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4512: 08062e7c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4513: 080749bc     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4514: 08062e80     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4515: 08062e8c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4516: 080749c4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4517: 00000000     0 FILE    LOCAL  DEFAULT  ABS eh_arm.cc
  4518: 08062e90     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4519: 08062e9c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4520: 08062f44     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4521: 080749c4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4522: 08062f4c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4523: 080749cc     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4524: 08062fb0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4525: 080749d4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4526: 00000000     0 FILE    LOCAL  DEFAULT  ABS eh_throw.cc
  4527: 08063020     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4528: 08063021    68 FUNC    LOCAL  DEFAULT    1 _ZL23__gxx_exception_clea
  4529: 080749d4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4530: 08063064     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4531: 080630b8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4532: 080749dc     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4533: 080630bc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4534: 080749e4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4535: 080630f4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4536: 080749ec     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4537: 00000000     0 FILE    LOCAL  DEFAULT  ABS si_class_type_info.cc
  4538: 08063164     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4539: 08063174     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4540: 080749f4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4541: 08063178     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4542: 08063190     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4543: 080749fc     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4544: 08063194     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4545: 080749fc     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4546: 080631d0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4547: 080749fc     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4548: 08063250     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4549: 080749fc     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4550: 08072698     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4551: 080726a4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4552: 080726cc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4553: 00000000     0 FILE    LOCAL  DEFAULT  ABS tinfo.cc
  4554: 0806327c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4555: 08074a04     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4556: 08063280     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4557: 08074a0c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4558: 08063284     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4559: 08074a0c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4560: 080726f8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4561: 08072700     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4562: 00000000     0 FILE    LOCAL  DEFAULT  ABS class_type_info.cc
  4563: 080632b0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4564: 08074a0c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4565: 080632e8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4566: 08074a14     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4567: 080632f4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4568: 08063304     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4569: 08074a1c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4570: 08063308     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4571: 08063320     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4572: 08074a1c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4573: 08063324     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4574: 08074a1c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4575: 08063368     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4576: 08074a1c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4577: 08063380     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4578: 08074a1c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4579: 08072710     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4580: 0807271c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4581: 08072740     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4582: 00000000     0 FILE    LOCAL  DEFAULT  ABS tree.cc
  4583: 080633ac     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4584: 080633ad    64 FUNC    LOCAL  DEFAULT    1 _ZStL23local_Rb_tree_decr
  4585: 08074a1c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4586: 080633ec     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4587: 08074a1c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4588: 080633f0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4589: 08074a1c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4590: 00000000     0 FILE    LOCAL  DEFAULT  ABS stdexcept.cc
  4591: 0806355c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4592: 08074a1c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4593: 08063560     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4594: 08074a1c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4595: 08063564     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4596: 0806359c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4597: 08074a1c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4598: 080635a4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4599: 08074a1c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4600: 080635b8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4601: 080635c8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4602: 08074a1c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4603: 080635cc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4604: 080635e4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4605: 08074a1c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4606: 080635e8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4607: 08063620     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4608: 08074a1c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4609: 08063628     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4610: 08074a1c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4611: 0807276c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4612: 08072778     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4613: 08072784     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4614: 08072790     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4615: 080727a0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4616: 080727b4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4617: 080727c8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4618: 080727dc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4619: 080727f0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4620: 00000000     0 FILE    LOCAL  DEFAULT  ABS cow-string-inst.cc
  4621: 0806363c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4622: 0806368c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4623: 08074a1c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4624: 08063694     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4625: 08074a24     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4626: 08063698     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4627: 080636f0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4628: 08074a2c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4629: 080636fc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4630: 08074a34     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4631: 08063718     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4632: 08074a3c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4633: 24011d98     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4634: 08072804     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4635: 08072830     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4636: 00000000     0 FILE    LOCAL  DEFAULT  ABS cow-stdexcept.cc
  4637: 08063744     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4638: 08063768     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4639: 08073e68     0 NOTYPE  LOCAL  DEFAULT    2 $d
  4640: 08074a44     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4641: 0806376c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4642: 0806377c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4643: 08074a4c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4644: 08063780     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4645: 080637a4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4646: 08073e7c     0 NOTYPE  LOCAL  DEFAULT    2 $d
  4647: 08074a54     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4648: 080637a8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4649: 08074a5c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4650: 00000000     0 FILE    LOCAL  DEFAULT  ABS string-inst.cc
  4651: 080637bc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4652: 08063800     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4653: 08073e90     0 NOTYPE  LOCAL  DEFAULT    2 $d
  4654: 08074a64     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4655: 08063804     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4656: 08074a6c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4657: 08063814     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4658: 08074a74     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4659: 08063830     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4660: 08074a74     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4661: 080638e0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4662: 08063a68     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4663: 08074a7c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4664: 08063a6c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4665: 08074a84     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4666: 08063a84     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4667: 08063ae0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4668: 08074a8c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4669: 08063ae4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4670: 08074a94     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4671: 08072848     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4672: 08072864     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4673: 08072890     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4674: 00000000     0 FILE    LOCAL  DEFAULT  ABS functexcept.cc
  4675: 08063b04     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4676: 08063b18     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4677: 08073e9c     0 NOTYPE  LOCAL  DEFAULT    2 $d
  4678: 08074a9c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4679: 08063b24     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4680: 08063b4c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4681: 08073ea8     0 NOTYPE  LOCAL  DEFAULT    2 $d
  4682: 08074aa4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4683: 08063b54     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4684: 08063b7c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4685: 08073ebc     0 NOTYPE  LOCAL  DEFAULT    2 $d
  4686: 08074aac     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4687: 00000000     0 FILE    LOCAL  DEFAULT  ABS functional.cc
  4688: 08063b84     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4689: 08063b88     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4690: 08074ab4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4691: 08063b8c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4692: 08063b9c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4693: 08074abc     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4694: 08063ba0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4695: 08063bb8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4696: 08074abc     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4697: 08063bbc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4698: 08063bd0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4699: 08073ed0     0 NOTYPE  LOCAL  DEFAULT    2 $d
  4700: 08074abc     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4701: 080728a8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4702: 080728bc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4703: 080728c8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4704: 080728e0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4705: 00000000     0 FILE    LOCAL  DEFAULT  ABS bad_array_new.cc
  4706: 08063bdc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4707: 08063be0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4708: 08074ac4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4709: 08063be4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4710: 08063bf4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4711: 08074acc     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4712: 08063bf8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4713: 08063c10     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4714: 08074acc     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4715: 080728f4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4716: 08072910     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4717: 0807291c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4718: 08072938     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4719: 00000000     0 FILE    LOCAL  DEFAULT  ABS wlocale-inst.cc
  4720: 08063c14     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4721: 08063c15   196 FUNC    LOCAL  DEFAULT    1 _GLOBAL__sub_I__ZNSt12cty
  4722: 08063ca8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4723: 08074acc     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4724: 24001a84     0 NOTYPE  LOCAL  DEFAULT    4 $d
  4725: 24011da8     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4726: 24011dac     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4727: 24011db0     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4728: 24011db4     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4729: 24011db8     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4730: 24011dbc     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4731: 24011dc0     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4732: 24011dc4     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4733: 24011dc8     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4734: 24011dcc     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4735: 24011dd0     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4736: 24011dd4     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4737: 00000000     0 FILE    LOCAL  DEFAULT  ABS cxx11-locale-inst.cc
  4738: 08063cd8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4739: 08063cd9   132 FUNC    LOCAL  DEFAULT    1 _GLOBAL__sub_I__ZNSt12cty
  4740: 08063d3c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4741: 08074acc     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4742: 24001a88     0 NOTYPE  LOCAL  DEFAULT    4 $d
  4743: 24011dd8     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4744: 24011ddc     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4745: 24011de0     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4746: 24011de4     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4747: 24011de8     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4748: 24011dec     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4749: 24011df0     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4750: 24011df4     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4751: 00000000     0 FILE    LOCAL  DEFAULT  ABS cxx11-wlocale-inst.cc
  4752: 08063d5c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4753: 08063d5d   132 FUNC    LOCAL  DEFAULT    1 _GLOBAL__sub_I__ZNSt12cty
  4754: 08063dc0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4755: 08074acc     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4756: 24001a8c     0 NOTYPE  LOCAL  DEFAULT    4 $d
  4757: 24011df8     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4758: 24011dfc     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4759: 24011e00     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4760: 24011e04     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4761: 24011e08     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4762: 24011e0c     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4763: 24011e10     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4764: 24011e14     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4765: 00000000     0 FILE    LOCAL  DEFAULT  ABS system_error.cc
  4766: 08063de0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4767: 08063de1     8 FUNC    LOCAL  DEFAULT    1 _ZNK12_GLOBAL__N_122gener
  4768: 08063de4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4769: 08074acc     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4770: 08063de8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4771: 08063de9     8 FUNC    LOCAL  DEFAULT    1 _ZNK12_GLOBAL__N_121syste
  4772: 08063dec     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4773: 08074acc     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4774: 08063df0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4775: 08074acc     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4776: 08063df8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4777: 08074acc     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4778: 08063e10     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4779: 08063e11     2 FUNC    LOCAL  DEFAULT    1 _ZN12_GLOBAL__N_121system
  4780: 08074acc     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4781: 08063e11     2 FUNC    LOCAL  DEFAULT    1 _ZN12_GLOBAL__N_121system
  4782: 08063e14     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4783: 08063e15     2 FUNC    LOCAL  DEFAULT    1 _ZN12_GLOBAL__N_122generi
  4784: 08074acc     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4785: 08063e15     2 FUNC    LOCAL  DEFAULT    1 _ZN12_GLOBAL__N_122generi
  4786: 08063e18     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4787: 08063e19    12 FUNC    LOCAL  DEFAULT    1 _ZN12_GLOBAL__N_121system
  4788: 08074acc     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4789: 08063e24     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4790: 08063e25    12 FUNC    LOCAL  DEFAULT    1 _ZN12_GLOBAL__N_122generi
  4791: 08074acc     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4792: 08063e30     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4793: 08073edc     0 NOTYPE  LOCAL  DEFAULT    2 $d
  4794: 08074acc     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4795: 08063e6c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4796: 08063e6d   104 FUNC    LOCAL  DEFAULT    1 _ZNK12_GLOBAL__N_122gener
  4797: 08063ed0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4798: 08074ad4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4799: 08063e6d   104 FUNC    LOCAL  DEFAULT    1 _ZNK12_GLOBAL__N_121syste
  4800: 08063ed4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4801: 08063f0c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4802: 08074adc     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4803: 08063f10     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4804: 08063f11    48 FUNC    LOCAL  DEFAULT    1 _GLOBAL__sub_I__ZSt20__th
  4805: 08063f2c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4806: 08074ae4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4807: 24001a90     0 NOTYPE  LOCAL  DEFAULT    4 $d
  4808: 24001084     0 NOTYPE  LOCAL  DEFAULT    4 $d
  4809: 24001084     4 OBJECT  LOCAL  DEFAULT    4 _ZN12_GLOBAL__N_1L24syste
  4810: 080729f0    40 OBJECT  LOCAL  DEFAULT    1 _ZTVN12_GLOBAL__N_121syst
  4811: 24001088     0 NOTYPE  LOCAL  DEFAULT    4 $d
  4812: 24001088     4 OBJECT  LOCAL  DEFAULT    4 _ZN12_GLOBAL__N_1L25gener
  4813: 08072a18    40 OBJECT  LOCAL  DEFAULT    1 _ZTVN12_GLOBAL__N_122gene
  4814: 0807294c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4815: 08072954     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4816: 08072864     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4817: 0807295c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4818: 0807295c    12 OBJECT  LOCAL  DEFAULT    1 _ZTIN12_GLOBAL__N_121syst
  4819: 0807297c    41 OBJECT  LOCAL  DEFAULT    1 _ZTSN12_GLOBAL__N_121syst
  4820: 08072968     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4821: 08072968    12 OBJECT  LOCAL  DEFAULT    1 _ZTIN12_GLOBAL__N_122gene
  4822: 080729a8    42 OBJECT  LOCAL  DEFAULT    1 _ZTSN12_GLOBAL__N_122gene
  4823: 08072974     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4824: 0807297c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4825: 080729a8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4826: 080729d4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4827: 080729f0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4828: 08072a18     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4829: 00000000     0 FILE    LOCAL  DEFAULT  ABS locale-inst.cc
  4830: 08063f40     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4831: 08063f41   196 FUNC    LOCAL  DEFAULT    1 _GLOBAL__sub_I__ZNSt12cty
  4832: 08063fd4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4833: 08074ae4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4834: 24001a94     0 NOTYPE  LOCAL  DEFAULT    4 $d
  4835: 24011e18     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4836: 24011e1c     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4837: 24011e20     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4838: 24011e24     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4839: 24011e28     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4840: 24011e2c     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4841: 24011e30     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4842: 24011e34     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4843: 24011e38     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4844: 24011e3c     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4845: 24011e40     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4846: 24011e44     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4847: 00000000     0 FILE    LOCAL  DEFAULT  ABS _aeabi_ldivmod.o
  4848: 08064004     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4849: 00000000     0 FILE    LOCAL  DEFAULT  ABS _aeabi_uldivmod.o
  4850: 080640a4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4851: 00000000     0 FILE    LOCAL  DEFAULT  ABS libgcc2.c
  4852: 080640d4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4853: 08074ae4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4854: 00000000     0 FILE    LOCAL  DEFAULT  ABS unwind-arm.c
  4855: 080643a0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4856: 080643a1    18 FUNC    LOCAL  DEFAULT    1 selfrel_offset31
  4857: 08074ae4     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4858: 080643b5    96 FUNC    LOCAL  DEFAULT    1 search_EIT_table
  4859: 08064415    40 FUNC    LOCAL  DEFAULT    1 __gnu_unwind_get_pr_addr
  4860: 08064430     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4861: 0806443c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4862: 0806443d   164 FUNC    LOCAL  DEFAULT    1 get_eit_entry
  4863: 080644d4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4864: 080644e0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4865: 080644e1    88 FUNC    LOCAL  DEFAULT    1 restore_non_core_regs
  4866: 08064539    10 FUNC    LOCAL  DEFAULT    1 _Unwind_decode_typeinfo_p
  4867: 08064545     4 FUNC    LOCAL  DEFAULT    1 __gnu_unwind_24bit.isra.1
  4868: 08064549     2 FUNC    LOCAL  DEFAULT    1 _Unwind_DebugHook
  4869: 0806454d    62 FUNC    LOCAL  DEFAULT    1 unwind_phase2
  4870: 0806458d   198 FUNC    LOCAL  DEFAULT    1 unwind_phase2_forced
  4871: 08064738     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4872: 0806475d    24 FUNC    LOCAL  DEFAULT    1 _Unwind_GetGR
  4873: 0806477c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4874: 080647a1    26 FUNC    LOCAL  DEFAULT    1 _Unwind_SetGR
  4875: 0806482d   724 FUNC    LOCAL  DEFAULT    1 __gnu_unwind_pr_common
  4876: 08064afc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4877: 08064b00     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4878: 08064b1c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4879: 0806473d     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4880: 0806473e     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4881: 08064781     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4882: 08064782     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4883: 08064b21     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4884: 08064b22     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4885: 00000000     0 FILE    LOCAL  DEFAULT  ABS libunwind.o
  4886: 08064d8c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4887: 00000000     0 FILE    LOCAL  DEFAULT  ABS pr-support.c
  4888: 08064f38     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4889: 08064f39    56 FUNC    LOCAL  DEFAULT    1 next_unwind_byte
  4890: 08074b5c     0 NOTYPE  LOCAL  DEFAULT    3 $d
  4891: 08064f71    26 FUNC    LOCAL  DEFAULT    1 _Unwind_GetGR.constprop.0
  4892: 08064f8d     2 FUNC    LOCAL  DEFAULT    1 unwind_UCB_from_context
  4893: 08073ef4     0 NOTYPE  LOCAL  DEFAULT    2 $d
  4894: 00000000     0 FILE    LOCAL  DEFAULT  ABS _dvmd_tls.o
  4895: 080652ac     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4896: 00000000     0 FILE    LOCAL  DEFAULT  ABS abort.c
  4897: 080652b0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4898: 00000000     0 FILE    LOCAL  DEFAULT  ABS assert.c
  4899: 080652c0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4900: 080652ec     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4901: 08072a40     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4902: 00000000     0 FILE    LOCAL  DEFAULT  ABS bsearch.c
  4903: 080652fc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4904: 00000000     0 FILE    LOCAL  DEFAULT  ABS errno.c
  4905: 08065340     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4906: 08065348     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4907: 00000000     0 FILE    LOCAL  DEFAULT  ABS fclose.c
  4908: 0806534c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4909: 0806541c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4910: 08065428     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4911: 00000000     0 FILE    LOCAL  DEFAULT  ABS fflush.c
  4912: 0806542c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4913: 0806557c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4914: 08065580     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4915: 080655dc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4916: 080655f4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4917: 00000000     0 FILE    LOCAL  DEFAULT  ABS findfp.c
  4918: 08065600     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4919: 08065601    80 FUNC    LOCAL  DEFAULT    1 std
  4920: 08065640     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4921: 08065650     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4922: 08065658     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4923: 0806565c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4924: 0806568c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4925: 080656dc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4926: 080656e4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4927: 0806577c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4928: 08065788     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4929: 08065790     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4930: 08065794     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4931: 0806579c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4932: 00000000     0 FILE    LOCAL  DEFAULT  ABS fiprintf.c
  4933: 080657a0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4934: 080657c4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4935: 00000000     0 FILE    LOCAL  DEFAULT  ABS fopen.c
  4936: 080657c8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4937: 08065878     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4938: 08065888     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4939: 08065894     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4940: 00000000     0 FILE    LOCAL  DEFAULT  ABS mallocr.c
  4941: 08065898     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4942: 0806592c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4943: 08065938     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4944: 08065b10     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4945: 00000000     0 FILE    LOCAL  DEFAULT  ABS fseek.c
  4946: 08065b20     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4947: 00000000     0 FILE    LOCAL  DEFAULT  ABS fseeko.c
  4948: 08065b24     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4949: 08065e38     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4950: 00000000     0 FILE    LOCAL  DEFAULT  ABS fstatr.c
  4951: 08065e3c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4952: 08065e60     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4953: 00000000     0 FILE    LOCAL  DEFAULT  ABS fvwrite.c
  4954: 08065e64     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4955: 08066158     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4956: 00000000     0 FILE    LOCAL  DEFAULT  ABS fwalk.c
  4957: 08066160     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4958: 080661ac     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4959: 00000000     0 FILE    LOCAL  DEFAULT  ABS init.c
  4960: 08066200     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4961: 08066238     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4962: 00000000     0 FILE    LOCAL  DEFAULT  ABS isprint.c
  4963: 08066248     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4964: 00000000     0 FILE    LOCAL  DEFAULT  ABS locale.c
  4965: 0806625c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4966: 08066270     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4967: 08066278     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4968: 0806628c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4969: 240014b8     0 NOTYPE  LOCAL  DEFAULT    4 $d
  4970: 08072b88     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4971: 08072b94     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4972: 00000000     0 FILE    LOCAL  DEFAULT  ABS lock.c
  4973: 08066294     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4974: 08066298     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4975: 0806629c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4976: 080662a0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4977: 00000000     0 FILE    LOCAL  DEFAULT  ABS makebuf.c
  4978: 080662a4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4979: 08066300     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4980: 08066390     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4981: 00000000     0 FILE    LOCAL  DEFAULT  ABS malloc.c
  4982: 08066394     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4983: 080663a0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4984: 080663a4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4985: 080663b0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4986: 00000000     0 FILE    LOCAL  DEFAULT  ABS mallocr.c
  4987: 080663b4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4988: 080666ec     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4989: 08066708     0 NOTYPE  LOCAL  DEFAULT    1 $t
  4990: 080668f8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  4991: 24011e48     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4992: 24011e70     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4993: 24011e74     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4994: 24011e78     0 NOTYPE  LOCAL  DEFAULT    6 $d
  4995: 24001624     0 NOTYPE  LOCAL  DEFAULT    4 $d
  4996: 24001a2c     0 NOTYPE  LOCAL  DEFAULT    4 $d
  4997: 24001a30     0 NOTYPE  LOCAL  DEFAULT    4 $d
  4998: 00000000     0 FILE    LOCAL  DEFAULT  ABS mbtowc_r.c
  4999: 080668fc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5000: 00000000     0 FILE    LOCAL  DEFAULT  ABS lib_a-memchr.o
  5001: 08066930     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5002: 00000000     0 FILE    LOCAL  DEFAULT  ABS memcmp.c
  5003: 080669d0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5004: 00000000     0 FILE    LOCAL  DEFAULT  ABS lib_a-memcpy.o
  5005: 08066a34     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5006: 00000000     0 FILE    LOCAL  DEFAULT  ABS memmove.c
  5007: 08066b68     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5008: 00000000     0 FILE    LOCAL  DEFAULT  ABS memset.c
  5009: 08066c30     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5010: 00000000     0 FILE    LOCAL  DEFAULT  ABS openr.c
  5011: 08066cc4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5012: 08066cec     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5013: 00000000     0 FILE    LOCAL  DEFAULT  ABS printf.c
  5014: 08066cf0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5015: 08066d14     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5016: 00000000     0 FILE    LOCAL  DEFAULT  ABS qsort.c
  5017: 08066d18     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5018: 00000000     0 FILE    LOCAL  DEFAULT  ABS random.c
  5019: 080672d4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5020: 080672e0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5021: 00000000     0 FILE    LOCAL  DEFAULT  ABS realloc.c
  5022: 080672e4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5023: 080672f0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5024: 00000000     0 FILE    LOCAL  DEFAULT  ABS refill.c
  5025: 080672f4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5026: 080672f5    18 FUNC    LOCAL  DEFAULT    1 lflush
  5027: 08067308     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5028: 08067418     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5029: 00000000     0 FILE    LOCAL  DEFAULT  ABS sbrkr.c
  5030: 08067420     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5031: 08067440     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5032: 00000000     0 FILE    LOCAL  DEFAULT  ABS setbuf.c
  5033: 08067444     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5034: 00000000     0 FILE    LOCAL  DEFAULT  ABS setvbuf.c
  5035: 08067454     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5036: 080675d0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5037: 00000000     0 FILE    LOCAL  DEFAULT  ABS signal.c
  5038: 080675d4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5039: 0806762c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5040: 08067638     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5041: 00000000     0 FILE    LOCAL  DEFAULT  ABS signalr.c
  5042: 0806763c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5043: 08067660     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5044: 08067664     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5045: 00000000     0 FILE    LOCAL  DEFAULT  ABS snprintf.c
  5046: 08067668     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5047: 080676f4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5048: 00000000     0 FILE    LOCAL  DEFAULT  ABS stdio.c
  5049: 080676f8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5050: 0806771c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5051: 08067758     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5052: 08067778     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5053: 00000000     0 FILE    LOCAL  DEFAULT  ABS lib_a-strcmp.o
  5054: 08067780     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5055: 00000000     0 FILE    LOCAL  DEFAULT  ABS strerror.c
  5056: 08067a5c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5057: 08067a68     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5058: 08067b86     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5059: 08067ce4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5060: 08067e28     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5061: 08067e3c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5062: 08072b98     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5063: 00000000     0 FILE    LOCAL  DEFAULT  ABS lib_a-strlen.o
  5064: 08067e40     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5065: 00000000     0 FILE    LOCAL  DEFAULT  ABS strncmp.c
  5066: 08067f1c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5067: 00000000     0 FILE    LOCAL  DEFAULT  ABS strncpy.c
  5068: 08067fb4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5069: 00000000     0 FILE    LOCAL  DEFAULT  ABS strspn.c
  5070: 08068018     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5071: 00000000     0 FILE    LOCAL  DEFAULT  ABS vfprintf.c
  5072: 08068050     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5073: 0806811e     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5074: 080681d0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5075: 080682e0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5076: 080682f4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5077: 08068770     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5078: 08068788     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5079: 08068ad0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5080: 08068ad8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5081: 08068e8c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5082: 08068e90     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5083: 0806919c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5084: 080691a4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5085: 08069420     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5086: 08073298     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5087: 080732dc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5088: 080732dc    16 OBJECT  LOCAL  DEFAULT    1 blanks.8551
  5089: 080732ec     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5090: 080732ec    16 OBJECT  LOCAL  DEFAULT    1 zeroes.8552
  5091: 00000000     0 FILE    LOCAL  DEFAULT  ABS u_strerr.c
  5092: 08069430     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5093: 00000000     0 FILE    LOCAL  DEFAULT  ABS vfprintf.c
  5094: 08069434     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5095: 08069435   118 FUNC    LOCAL  DEFAULT    1 __sprint_r.part.0
  5096: 080694ac     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5097: 080694c0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5098: 080695ae     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5099: 08069660     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5100: 08069a88     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5101: 08069a94     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5102: 0806a0e5   132 FUNC    LOCAL  DEFAULT    1 __sbprintf
  5103: 08069da4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5104: 08069dac     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5105: 0806a0e0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5106: 0806a0e4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5107: 080732a8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5108: 080732fc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5109: 080732fc    16 OBJECT  LOCAL  DEFAULT    1 blanks.8545
  5110: 0807330c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5111: 0807330c    16 OBJECT  LOCAL  DEFAULT    1 zeroes.8546
  5112: 00000000     0 FILE    LOCAL  DEFAULT  ABS vfprintf.c
  5113: 0806a168     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5114: 0806a27c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5115: 0806a32e     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5116: 0806b5f9   132 FUNC    LOCAL  DEFAULT    1 __sbprintf
  5117: 0806a468     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5118: 0806a478     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5119: 0806a824     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5120: 0806a830     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5121: 0806ab40     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5122: 0806ab54     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5123: 0806afd0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5124: 0806afd4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5125: 0806b374     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5126: 0806b37c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5127: 0806b5d0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5128: 0806b5e0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5129: 0806b5f4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5130: 0806b5f8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5131: 08073298     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5132: 0807331c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5133: 0807331c    16 OBJECT  LOCAL  DEFAULT    1 blanks.8566
  5134: 0807332c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5135: 0807332c    16 OBJECT  LOCAL  DEFAULT    1 zeroes.8567
  5136: 00000000     0 FILE    LOCAL  DEFAULT  ABS vsnprintf.c
  5137: 0806b67c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5138: 0806b6ec     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5139: 0806b708     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5140: 00000000     0 FILE    LOCAL  DEFAULT  ABS wbuf.c
  5141: 0806b70c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5142: 00000000     0 FILE    LOCAL  DEFAULT  ABS wcrtomb.c
  5143: 0806b7bc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5144: 0806b804     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5145: 00000000     0 FILE    LOCAL  DEFAULT  ABS wctomb_r.c
  5146: 0806b80c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5147: 00000000     0 FILE    LOCAL  DEFAULT  ABS writer.c
  5148: 0806b828     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5149: 0806b850     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5150: 00000000     0 FILE    LOCAL  DEFAULT  ABS wsetup.c
  5151: 0806b854     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5152: 0806b91c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5153: 00000000     0 FILE    LOCAL  DEFAULT  ABS closer.c
  5154: 0806b920     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5155: 0806b940     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5156: 00000000     0 FILE    LOCAL  DEFAULT  ABS dtoa.c
  5157: 0806b944     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5158: 0806b945   292 FUNC    LOCAL  DEFAULT    1 quorem
  5159: 0806ba68     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5160: 0806bbea     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5161: 0806bbf2     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5162: 0806bd80     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5163: 0806bdb4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5164: 0806c100     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5165: 0806c104     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5166: 0806c64c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5167: 0806c654     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5168: 0807333c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5169: 00000000     0 FILE    LOCAL  DEFAULT  ABS flags.c
  5170: 0806c688     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5171: 00000000     0 FILE    LOCAL  DEFAULT  ABS fputwc.c
  5172: 0806c6fc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5173: 0806c79c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5174: 00000000     0 FILE    LOCAL  DEFAULT  ABS isattyr.c
  5175: 0806c800     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5176: 0806c820     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5177: 00000000     0 FILE    LOCAL  DEFAULT  ABS localeconv.c
  5178: 0806c824     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5179: 0806c838     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5180: 00000000     0 FILE    LOCAL  DEFAULT  ABS lseekr.c
  5181: 0806c840     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5182: 0806c868     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5183: 00000000     0 FILE    LOCAL  DEFAULT  ABS mprec.c
  5184: 0806c86c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5185: 0806c8b8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5186: 0806c8cc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5187: 0806c94c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5188: 0806c98c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5189: 0806c9ec     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5190: 0806ca00     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5191: 0806cb4c     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5192: 0806cbe8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5193: 0806cbec     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5194: 0806cc98     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5195: 0806ccd0     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5196: 0806cdbc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5197: 08073350     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5198: 08073378     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5199: 08073440     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5200: 08073440    12 OBJECT  LOCAL  DEFAULT    1 p05.7367
  5201: 00000000     0 FILE    LOCAL  DEFAULT  ABS readr.c
  5202: 0806ce78     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5203: 0806cea0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5204: 00000000     0 FILE    LOCAL  DEFAULT  ABS vfprintf.c
  5205: 0806cea4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5206: 00000000     0 FILE    LOCAL  DEFAULT  ABS getpid.c
  5207: 0806cf98     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5208: 0806cfa4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5209: 00000000     0 FILE    LOCAL  DEFAULT  ABS kill.c
  5210: 0806cfa8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5211: 0806cfb4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5212: 00000000     0 FILE    LOCAL  DEFAULT  ABS /root/.arduino15/packages
  5213: 0806cfb8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5214: 0806cfc4     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5215: 00000000     0 FILE    LOCAL  DEFAULT  ABS /root/.arduino15/packages
  5216: 0806cfbc     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5217: 0806cfc8     0 NOTYPE  LOCAL  DEFAULT    1 $t
  5218: 00000000     0 FILE    LOCAL  DEFAULT  ABS rtx_lib.c
  5219: 24005448     0 NOTYPE  LOCAL  DEFAULT    6 $d
  5220: 24005448    64 OBJECT  LOCAL  DEFAULT    6 os_isr_queue
  5221: 24005488     0 NOTYPE  LOCAL  DEFAULT    6 $d
  5222: 24005488    52 OBJECT  LOCAL  DEFAULT    6 os_timer_mq_cb
  5223: 240054bc     0 NOTYPE  LOCAL  DEFAULT    6 $d
  5224: 240054bc    80 OBJECT  LOCAL  DEFAULT    6 os_timer_mq_data
  5225: 2400550c     0 NOTYPE  LOCAL  DEFAULT    6 $d
  5226: 2400550c    68 OBJECT  LOCAL  DEFAULT    6 os_timer_thread_cb
  5227: 24005550    68 OBJECT  LOCAL  DEFAULT    6 os_idle_thread_cb
  5228: 24005598     0 NOTYPE  LOCAL  DEFAULT    6 $d
  5229: 24005598   768 OBJECT  LOCAL  DEFAULT    6 os_timer_thread_stack
  5230: 24005898   896 OBJECT  LOCAL  DEFAULT    6 os_idle_thread_stack
  5231: 0806fbe0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5232: 0806fc84    36 OBJECT  LOCAL  DEFAULT    1 os_idle_thread_attr
  5233: 0806fcc0    36 OBJECT  LOCAL  DEFAULT    1 os_timer_thread_attr
  5234: 0806fca8    24 OBJECT  LOCAL  DEFAULT    1 os_timer_mq_attr
  5235: 0806fc80     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5236: 0806fc84     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5237: 0806fca8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5238: 0806fcc0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5239: 00000000     0 FILE    LOCAL  DEFAULT  ABS PeripheralPins.c
  5240: 08071478     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5241: 08071718     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5242: 08071748     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5243: 080717a8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5244: 080717fc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5245: 08071898     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5246: 08071934     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5247: 080719e8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5248: 08071a9c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5249: 08071bf8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5250: 08071d48     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5251: 08071d6c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5252: 00000000     0 FILE    LOCAL  DEFAULT  ABS ctype_.c
  5253: 08072a80     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5254: 00000000     0 FILE    LOCAL  DEFAULT  ABS impure.c
  5255: 2400108c     0 NOTYPE  LOCAL  DEFAULT    4 $d
  5256: 24001090  1064 OBJECT  LOCAL  DEFAULT    4 impure_data
  5257: 24001090     0 NOTYPE  LOCAL  DEFAULT    4 $d
  5258: 08072b84     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5259: 00000000     0 FILE    LOCAL  DEFAULT  ABS crtstuff.c
  5260: 0807344c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5261: 0807344c     0 OBJECT  LOCAL  DEFAULT    1 __FRAME_END__
  5262: 00000000     0 FILE    LOCAL  DEFAULT  ABS eh_term_handler.cc
  5263: 2400107c     0 NOTYPE  LOCAL  DEFAULT    4 $d
  5264: 00000000     0 FILE    LOCAL  DEFAULT  ABS eh_unex_handler.cc
  5265: 24001080     0 NOTYPE  LOCAL  DEFAULT    4 $d
  5266: 00000000     0 FILE    LOCAL  DEFAULT  ABS try_catch.c
  5267: 00000000     0 FILE    LOCAL  DEFAULT  ABS 
  5268: 24001a38     0 NOTYPE  LOCAL  DEFAULT    4 __preinit_array_start
  5269: 24001a38     0 NOTYPE  LOCAL  DEFAULT    4 __preinit_array_end
  5270: 24001a98     0 NOTYPE  LOCAL  DEFAULT    4 __init_array_end
  5271: 24001a38     0 NOTYPE  LOCAL  DEFAULT    4 __init_array_start
  5272: 0806cfd0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5273: 0806cfda     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5274: 0806d0cf     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5275: 0806d196     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5276: 0806d19e     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5277: 0806d1a6     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5278: 0806d1ae     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5279: 0806d1b6     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5280: 0806d1be     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5281: 0806d1c6     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5282: 0806d1ce     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5283: 0806d2c1     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5284: 0806d3ca     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5285: 0806d3db     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5286: 0806d3fa     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5287: 0806d554     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5288: 0806d5de     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5289: 0806d603     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5290: 0806d628     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5291: 0806d63b     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5292: 0806d644     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5293: 0806d67c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5294: 0806d67f     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5295: 0806dcc9     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5296: 0806e1d8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5297: 0806e21d     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5298: 0806e334     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5299: 0806e391     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5300: 0806e448     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5301: 0806e4ed     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5302: 0806e531     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5303: 0806e5f5     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5304: 0806e605     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5305: 0806e638     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5306: 0806e66c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5307: 0806e6a4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5308: 0806e6dc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5309: 0806e714     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5310: 0806e74c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5311: 0806e784     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5312: 0806e7b4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5313: 0806e928     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5314: 0806e934     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5315: 0806e95c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5316: 0806e96e     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5317: 0806e980     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5318: 0806e992     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5319: 0806e9a4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5320: 0806ea11     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5321: 0806ea1c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5322: 0806ea36     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5323: 0806ea4c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5324: 0806ea77     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5325: 0806eab8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5326: 0806ebb4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5327: 0806ebbd     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5328: 24000004     0 NOTYPE  LOCAL  DEFAULT    4 $d
  5329: 0806ec20     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5330: 0806ec3b     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5331: 0806ec5d     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5332: 0806ec74     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5333: 0806ec81     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5334: 0806ecb0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5335: 0806ecc5     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5336: 0806ecde     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5337: 0806ed66     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5338: 0806ed96     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5339: 0806edbb     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5340: 0806edd1     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5341: 0806edf0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5342: 0806ee93     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5343: 0806eea6     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5344: 0806ef26     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5345: 0806ef42     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5346: 0806ef7b     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5347: 0806efb4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5348: 0806efd6     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5349: 0806f01c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5350: 0806f046     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5351: 0806f09a     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5352: 0806f106     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5353: 0806f157     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5354: 0806f1fc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5355: 0806f22c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5356: 0806f254     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5357: 0806f27c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5358: 0806f2f8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5359: 0806f45c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5360: 0806f46e     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5361: 0806f498     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5362: 0806f4a6     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5363: 0806f4b5     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5364: 0806f4d3     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5365: 0806f560     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5366: 0806f5eb     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5367: 0806f5fa     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5368: 0806f620     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5369: 0806f630     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5370: 0806f638     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5371: 0806f63b     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5372: 0806f63f     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5373: 0806f643     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5374: 0806f64c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5375: 0806f67e     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5376: 0806f683     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5377: 0806f68e     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5378: 0806f6d8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5379: 0806f6dd     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5380: 0806f6e7     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5381: 0806f6f7     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5382: 0806f6fc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5383: 0806f708     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5384: 0806f714     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5385: 0806f74c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5386: 0806f751     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5387: 0806f757     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5388: 0806f761     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5389: 0806f76c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5390: 0806f77a     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5391: 0806f78a     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5392: 0806f78d     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5393: 0806f792     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5394: 0806f798     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5395: 0806f82c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5396: 0806f83c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5397: 0806f880     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5398: 0806f914     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5399: 0806f978     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5400: 0806f984     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5401: 0806f992     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5402: 0806f9b4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5403: 0806fa6c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5404: 0806fa90     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5405: 0806fbc0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5406: 0806fbcb     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5407: 0806fce4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5408: 0806fcfb     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5409: 0806fd31     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5410: 0806fd54     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5411: 0806fe64     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5412: 0806ff20     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5413: 0806ff82     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5414: 0806ffbc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5415: 08070004     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5416: 08070016     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5417: 0807004a     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5418: 080700d0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5419: 080700e8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5420: 080700fe     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5421: 08070116     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5422: 0807012e     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5423: 08070228     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5424: 080702b0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5425: 080703ac     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5426: 080703e3     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5427: 0807040c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5428: 08070443     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5429: 08070462     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5430: 0807048d     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5431: 080704ff     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5432: 0807052b     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5433: 08070553     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5434: 08070576     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5435: 080705b0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5436: 080705be     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5437: 0807060f     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5438: 0807064e     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5439: 080706e4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5440: 080706e8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5441: 080706fe     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5442: 08070714     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5443: 0807071c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5444: 0807072e     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5445: 08070734     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5446: 0807073b     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5447: 08070779     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5448: 0807078c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5449: 08070804     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5450: 08070815     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5451: 08070826     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5452: 08070846     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5453: 08070864     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5454: 080708af     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5455: 08070930     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5456: 08070965     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5457: 080709d0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5458: 08070a02     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5459: 08070ae8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5460: 08070b19     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5461: 08070b44     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5462: 08070c71     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5463: 08070d01     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5464: 08070d06     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5465: 08070d61     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5466: 08070f8a     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5467: 08070f9f     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5468: 08070fc1     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5469: 08070fdf     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5470: 08070fe9     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5471: 08071033     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5472: 0807106a     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5473: 080710a4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5474: 080710e0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5475: 08071168     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5476: 08071170     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5477: 08071177     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5478: 0807117f     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5479: 080711b4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5480: 080711dd     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5481: 080711fd     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5482: 0807125b     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5483: 0807126d     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5484: 08071281     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5485: 080712b4     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5486: 080712cd     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5487: 08071377     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5488: 2400106c     0 NOTYPE  LOCAL  DEFAULT    4 $d
  5489: 080713f0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5490: 08071400     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5491: 08071429     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5492: 0807142f     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5493: 0807144e     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5494: 08071e08     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5495: 08040000     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5496: 08071e1c     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5497: 08071e44     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5498: 08071f0e     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5499: 08071f51     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5500: 08071f9f     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5501: 0807200d     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5502: 0807205b     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5503: 08072069     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5504: 08072079     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5505: 08072164     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5506: 08072185     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5507: 080721c0     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5508: 080721e6     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5509: 08072241     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5510: 0807225a     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5511: 080722f8     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5512: 08072350     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5513: 0807236e     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5514: 080723fc     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5515: 08072426     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5516: 08072483     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5517: 08072510     0 NOTYPE  LOCAL  DEFAULT    1 $d
  5518: 0807065c   136 OBJECT  GLOBAL DEFAULT    1 _ZTV9USBDevice
  5519: 0806e778    12 OBJECT  WEAK   DEFAULT    1 _ZTIN14clmdep_msgpack2v11
  5520: 08050f11     2 FUNC    GLOBAL DEFAULT    1 _ZN10STM32_EMAC17set_all_
  5521: 2400f887   163 OBJECT  GLOBAL DEFAULT    6 memp_memory_UDP_PCB_base
  5522: 24011ec8     0 NOTYPE  GLOBAL DEFAULT    6 _ebss
  5523: 080491e5    68 FUNC    GLOBAL DEFAULT    1 OPENAMP_Wait_EndPointread
  5524: 0804474d    92 FUNC    WEAK   DEFAULT    1 _ZN7arduino3RPCD2Ev
  5525: 08043869   208 FUNC    GLOBAL DEFAULT    1 _ZN7arduino11ThreadDebugC
  5526: 08052855    14 FUNC    GLOBAL DEFAULT    1 _ZN16EndpointResolverC1EP
  5527: 08053d9f   114 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice27_complete_
  5528: 080446e7    22 FUNC    WEAK   DEFAULT    1 _ZN3rpc6detail8responseD1
  5529: 080556a5    80 FUNC    GLOBAL DEFAULT    1 mbed_error_puts
  5530: 08055747    12 FUNC    GLOBAL DEFAULT    1 core_util_are_interrupts_
  5531: 080504d1    32 FUNC    GLOBAL DEFAULT    1 osThreadGetCount
  5532: 080538fd   128 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice11read_finis
  5533: 080728e0    20 OBJECT  GLOBAL DEFAULT    1 _ZTVSt17bad_function_call
  5534: 08052a85    96 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice11device_des
  5535: 080592f7    48 FUNC    GLOBAL DEFAULT    1 HAL_FDCAN_ConfigTimeoutCo
  5536: 08071d6c   156 OBJECT  WEAK   DEFAULT    1 PinMap_USB_HS
  5537: 0805859d   132 FUNC    GLOBAL DEFAULT    1 HAL_ETH_BuildRxDescriptor
  5538: 080632e9    12 FUNC    GLOBAL DEFAULT    1 _ZNK10__cxxabiv117__class
  5539: 08042e39    16 FUNC    GLOBAL DEFAULT    1 mriPlatform_EnableSingleS
  5540: 08059cf1   164 FUNC    GLOBAL DEFAULT    1 HAL_I2C_Master_Seq_Transm
  5541: 08050959    16 FUNC    GLOBAL DEFAULT    1 EvrRtxThreadTerminate
  5542: 0804bc49    12 FUNC    GLOBAL DEFAULT    1 mriCore_SetContext
  5543: 080491b9    32 FUNC    GLOBAL DEFAULT    1 OPENAMP_create_endpoint
  5544: 080521ad    92 FUNC    GLOBAL DEFAULT    1 _ZN4mbed10SerialBaseD2Ev
  5545: 08056701    20 FUNC    GLOBAL DEFAULT    1 _ZN4rtos10EventFlagsC2Ev
  5546: 0804455d    96 FUNC    WEAK   DEFAULT    1 _ZN4rtos6ThreadC2E12osPri
  5547: 080481f9    48 FUNC    WEAK   DEFAULT    1 _ZNSt14__shared_countILN9
  5548: 080440c5    20 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v111p
  5549: 0805ffd5    22 FUNC    GLOBAL DEFAULT    1 _Z19HAL_PCDEx_GetTxFiFoP1
  5550: 08051ebd   120 FUNC    GLOBAL DEFAULT    1 _ZN4mbed3I2CC2E7PinNameS1
  5551: 080410c5   336 FUNC    GLOBAL DEFAULT    1 setup
  5552: 080445e1    16 FUNC    GLOBAL DEFAULT    1 _ZN3rpc6client4postEPN14c
  5553: 08056c71    12 FUNC    GLOBAL DEFAULT    1 HAL_GetREVID
  5554: 08071170     7 OBJECT  GLOBAL DEFAULT    1 __stdin_name
  5555: 08048705     4 FUNC    GLOBAL DEFAULT    1 _ZNK3rpc6detail8response6
  5556: 0805fa95     2 FUNC    GLOBAL DEFAULT    1 _ZN8USBPhyHw11unconfigure
  5557: 080544ff     6 FUNC    GLOBAL DEFAULT    1 gpio_init_out
  5558: 0805facf    16 FUNC    GLOBAL DEFAULT    1 _ZN8USBPhyHwD0Ev
  5559: 0805bfa1    68 FUNC    GLOBAL DEFAULT    1 HAL_RCC_GetHCLKFreq
  5560: 0807262c    12 OBJECT  GLOBAL DEFAULT    1 _ZTISt8bad_cast
  5561: 08064da5     0 FUNC    GLOBAL HIDDEN     1 __gnu_Unwind_Restore_VFP
  5562: 08066279    28 FUNC    GLOBAL DEFAULT    1 __locale_ctype_ptr
  5563: 08054fcd   100 FUNC    WEAK   DEFAULT    1 _ZN4mbed8internal8SysTime
  5564: 08051931    44 FUNC    GLOBAL DEFAULT    1 memp_free
  5565: 080486f5    16 FUNC    GLOBAL DEFAULT    1 _ZN3rpc6detail8responseC2
  5566: 080540b1    66 FUNC    GLOBAL DEFAULT    1 equeue_post
  5567: 0804da5d    12 FUNC    GLOBAL DEFAULT    1 _ZN7arduino5Print7println
  5568: 08064b01     4 FUNC    GLOBAL HIDDEN     1 __aeabi_unwind_cpp_pr0
  5569: 0805a0c5     2 FUNC    WEAK   DEFAULT    1 HAL_I2C_MemTxCpltCallback
  5570: 0806e7a8    12 OBJECT  WEAK   DEFAULT    1 _ZTIN14clmdep_msgpack2v11
  5571: 08043e65     6 FUNC    WEAK   DEFAULT    1 _ZN7arduino3RPC9available
  5572: 0806c8b9    18 FUNC    GLOBAL DEFAULT    1 _Bfree
  5573: 080527d7    10 FUNC    GLOBAL DEFAULT    1 _ZN7AsyncOp12_host_unlock
  5574: 08063281     4 FUNC    GLOBAL DEFAULT    1 _ZNKSt9type_info15__is_fu
  5575: 2401028c    92 OBJECT  WEAK   DEFAULT    6 _ZZN4mbed33do_shared_even
  5576: 0805f291     2 FUNC    WEAK   DEFAULT    1 TIM1_TRG_COM_IRQHandler
  5577: 08045825    36 FUNC    WEAK   DEFAULT    1 _ZN7arduino14SerialRPCCla
  5578: 24004340   316 OBJECT  GLOBAL DEFAULT    6 _UART1_
  5579: 080637a9    18 FUNC    GLOBAL DEFAULT    1 _ZNSt12__cow_stringC2EPKc
  5580: 0805ec4d    18 FUNC    GLOBAL DEFAULT    1 USB_ReadDevOutEPInterrupt
  5581: 0804bfb5   184 FUNC    GLOBAL DEFAULT    1 mriToken_SplitString
  5582: 0805f291     2 FUNC    WEAK   DEFAULT    1 MDMA_IRQHandler
  5583: 0805fc8d    36 FUNC    GLOBAL DEFAULT    1 _ZN8USBPhyHw16endpoint_un
  5584: 08061055   364 FUNC    GLOBAL DEFAULT    1 lp_ticker_init
  5585: 08046581   116 FUNC    WEAK   DEFAULT    1 _ZN10clmdep_fmt8internal1
  5586: 0807019c    12 OBJECT  GLOBAL DEFAULT    1 memp_SYS_TIMEOUT
  5587: 080489e7   368 FUNC    GLOBAL DEFAULT    1 _ZN3rpc6detail8responseC2
  5588: 0804d7e5    42 FUNC    GLOBAL DEFAULT    1 _ZN7arduino9USBSerial10_a
  5589: 0805f291     2 FUNC    WEAK   DEFAULT    1 MDIOS_IRQHandler
  5590: 0804cbad     4 FUNC    WEAK   DEFAULT    1 _ZN7arduino18PluggableUSB
  5591: 0804a381    36 FUNC    GLOBAL DEFAULT    1 HAL_HSEM_FreeCallback
  5592: 0805107d    12 FUNC    GLOBAL DEFAULT    1 _Z14_phy_get_statev
  5593: 08050785     2 FUNC    WEAK   DEFAULT    1 mbed_tfm_init
  5594: 080432d1   264 FUNC    GLOBAL DEFAULT    1 mriCortexMInit
  5595: 080566cd    52 FUNC    GLOBAL DEFAULT    1 _ZN4rtos10EventFlags11con
  5596: 0804e1ad    48 FUNC    GLOBAL DEFAULT    1 osDelay
  5597: 08059641     2 FUNC    WEAK   DEFAULT    1 HAL_FDCAN_TxBufferAbortCa
  5598: 0804898d    90 FUNC    WEAK   DEFAULT    1 _ZNSt12__shared_ptrIN14cl
  5599: 0805274d    24 FUNC    GLOBAL DEFAULT    1 _ZN7AsyncOpC2Ev
  5600: 0805f291     2 FUNC    WEAK   DEFAULT    1 DMA1_Stream3_IRQHandler
  5601: 08063ae5    30 FUNC    WEAK   DEFAULT    1 _ZNSt7__cxx1112basic_stri
  5602: 0806c94d    62 FUNC    GLOBAL DEFAULT    1 __hi0bits
  5603: 08052765    44 FUNC    GLOBAL DEFAULT    1 _ZN7AsyncOpD1Ev
  5604: 0804d553     2 FUNC    WEAK   DEFAULT    1 _ZThn1216_N7arduino9USBSe
  5605: 080489e7   368 FUNC    GLOBAL DEFAULT    1 _ZN3rpc6detail8responseC1
  5606: 08045435   204 FUNC    WEAK   DEFAULT    1 _ZN7arduino3RPCC1Ev
  5607: 0804a669    52 FUNC    GLOBAL DEFAULT    1 mriBuffer_WriteSizedStrin
  5608: 080426d9    12 FUNC    GLOBAL DEFAULT    1 mriBusFaultHandlerStub
  5609: 080472b5   188 FUNC    GLOBAL DEFAULT    1 _ZN10clmdep_fmt8internal1
  5610: 08053549   112 FUNC    GLOBAL DEFAULT    1 _ZN9USBDeviceC1EP6USBPhyt
  5611: 0805301f    50 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice22_request_g
  5612: 08071177     8 OBJECT  GLOBAL DEFAULT    1 __stdout_name
  5613: 0804f4d1    48 FUNC    GLOBAL DEFAULT    1 osMutexRelease
  5614: 0804c3d9    68 FUNC    GLOBAL DEFAULT    1 _ZN7arduino4UART5writeEh
  5615: 0804bbf9    24 FUNC    GLOBAL DEFAULT    1 mriCore_PrepareStringResp
  5616: 0804c541     6 FUNC    WEAK   DEFAULT    1 _ZThn1216_N7arduino9USBSe
  5617: 2400f4f1   659 OBJECT  GLOBAL DEFAULT    6 memp_memory_TCP_PCB_base
  5618: 08053fa5   116 FUNC    GLOBAL DEFAULT    1 equeue_dealloc
  5619: 0805f291     2 FUNC    WEAK   DEFAULT    1 TIM8_CC_IRQHandler
  5620: 0805b5b5    16 FUNC    GLOBAL DEFAULT    1 HAL_PWR_EnableBkUpAccess
  5621: 08050e6d   148 FUNC    GLOBAL DEFAULT    1 LAN8742_GetLinkState
  5622: 0805f291     2 FUNC    WEAK   DEFAULT    1 DCMI_IRQHandler
  5623: 08050941    24 FUNC    GLOBAL DEFAULT    1 EvrRtxThreadExit
  5624: 08052525     6 FUNC    GLOBAL DEFAULT    1 _ZN4mbed10TimerEvent3irqE
  5625: 080542c7     4 FUNC    GLOBAL DEFAULT    1 equeue_mutex_unlock
  5626: 0804445d   128 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v26de
  5627: 0807144e    16 OBJECT  GLOBAL DEFAULT    1 D1CorePrescTable
  5628: 0805e181    32 FUNC    GLOBAL DEFAULT    1 HAL_UARTEx_EnableStopMode
  5629: 0804f42d    68 FUNC    GLOBAL DEFAULT    1 osRtxMutexOwnerRestore
  5630: 08072598     8 OBJECT  GLOBAL DEFAULT    1 _ZTISt9exception
  5631: 08058c85   286 FUNC    GLOBAL DEFAULT    1 HAL_EXTI_SetConfigLine
  5632: 0805ac55    42 FUNC    GLOBAL DEFAULT    1 HAL_PCD_DeInit
  5633: 08043fe9    20 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v119d
  5634: 08062e5d    20 FUNC    GLOBAL DEFAULT    1 _ZSt10unexpectedv
  5635: 0804a6cd   104 FUNC    GLOBAL DEFAULT    1 mriBuffer_ReadUIntegerAsH
  5636: 0804893d    80 FUNC    WEAK   DEFAULT    1 _ZNSt14__shared_countILN9
  5637: 0805f291     2 FUNC    WEAK   DEFAULT    1 RTC_Alarm_IRQHandler
  5638: 08062b79    20 FUNC    GLOBAL DEFAULT    1 _ZNSt9bad_allocD2Ev
  5639: 0804d67d    28 FUNC    WEAK   DEFAULT    1 _ZN4mbed8CallbackIFvvEE11
  5640: 24010944  1296 OBJECT  GLOBAL DEFAULT    6 uart_handlers
  5641: 08064e5d     0 FUNC    GLOBAL HIDDEN     1 __gnu_Unwind_Restore_WMMX
  5642: 0804c853    40 FUNC    GLOBAL DEFAULT    1 _ZN7arduino18PluggableUSB
  5643: 0805aaf1    78 FUNC    GLOBAL DEFAULT    1 HAL_LPTIM_Counter_Start
  5644: 0805f291     2 FUNC    WEAK   DEFAULT    1 MDIOS_WKUP_IRQHandler
  5645: 0804f3e9    68 FUNC    GLOBAL DEFAULT    1 osRtxMutexOwnerRelease
  5646: 08062b29    32 FUNC    GLOBAL DEFAULT    1 __cxa_free_exception
  5647: 080435b5    36 FUNC    WEAK   DEFAULT    1 _ZN10ThreadList12findThre
  5648: 080427f7    20 FUNC    GLOBAL DEFAULT    1 _ZN7arduino21UsbDebugComm
  5649: 0804dd15    40 FUNC    GLOBAL DEFAULT    1 _Z14PinNameToIndex7PinNam
  5650: 080405f1     2 FUNC    GLOBAL DEFAULT    1 HAL_FDCAN_TimeoutOccurred
  5651: 0805f291     2 FUNC    WEAK   DEFAULT    1 DSI_IRQHandler
  5652: 080727f0    20 OBJECT  GLOBAL DEFAULT    1 _ZTVSt13runtime_error
  5653: 0805d509    64 FUNC    GLOBAL DEFAULT    1 RTC_EnterInitMode
  5654: 08064ecd    34 FUNC    GLOBAL HIDDEN     1 ___Unwind_Resume_or_Rethr
  5655: 0805fa97     2 FUNC    GLOBAL DEFAULT    1 _ZN8USBPhyHwD2Ev
  5656: 08064711    14 FUNC    GLOBAL HIDDEN     1 __gnu_Unwind_Resume_or_Re
  5657: 08051175    72 FUNC    GLOBAL DEFAULT    1 _ZN10STM32_EMAC9packet_rx
  5658: 08041635    52 FUNC    GLOBAL DEFAULT    1 _Z18RTC_CalendarConfigP8L
  5659: 080440d9    20 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v111p
  5660: 08056405     4 FUNC    GLOBAL DEFAULT    1 _Znaj
  5661: 0804c0a9     4 FUNC    GLOBAL DEFAULT    1 PINCOUNT_fn
  5662: 0804fc09    18 FUNC    GLOBAL DEFAULT    1 osRtxThreadListGet
  5663: 0805d901     2 FUNC    WEAK   DEFAULT    1 HAL_RTCEx_AlarmBEventCall
  5664: 08063745    40 FUNC    GLOBAL DEFAULT    1 _ZNSt11logic_errorC2EPKc
  5665: 0804c121    52 FUNC    GLOBAL DEFAULT    1 initVariant
  5666: 08052591     6 FUNC    WEAK   DEFAULT    1 _ZN4mbed16UnbufferedSeria
  5667: 0805e1a1    32 FUNC    GLOBAL DEFAULT    1 HAL_UARTEx_DisableStopMod
  5668: 080631d1   128 FUNC    GLOBAL DEFAULT    1 _ZNK10__cxxabiv120__si_cl
  5669: 08056d99     2 FUNC    WEAK   DEFAULT    1 HAL_ADC_MspInit
  5670: 08049c15    96 FUNC    GLOBAL DEFAULT    1 resource_table_init
  5671: 08063b8d    20 FUNC    GLOBAL DEFAULT    1 _ZNSt17bad_function_callD
  5672: 08047e65     2 FUNC    WEAK   DEFAULT    1 _ZNSt19_Sp_counted_delete
  5673: 08043049   220 FUNC    GLOBAL DEFAULT    1 mriPlatform_DetermineCaus
  5674: 0805eff5   114 FUNC    GLOBAL DEFAULT    1 enableEthPowerSupply
  5675: 2400431c    36 OBJECT  GLOBAL DEFAULT    6 RTCHandle
  5676: 080582b3    88 FUNC    GLOBAL DEFAULT    1 HAL_ETH_Stop
  5677: 30040400  6112 OBJECT  GLOBAL DEFAULT   10 Rx_Buff
  5678: 080434f9    36 FUNC    GLOBAL DEFAULT    1 mriPlatform_ResetDevice
  5679: 08062b71     8 FUNC    GLOBAL DEFAULT    1 _ZNKSt9bad_alloc4whatEv
  5680: 0804a555    40 FUNC    GLOBAL DEFAULT    1 mriBuffer_ReadChar
  5681: 08062d01   126 FUNC    GLOBAL DEFAULT    1 __cxa_begin_catch
  5682: 080620a9    40 FUNC    GLOBAL DEFAULT    1 timer_irq_handler
  5683: 08067779     8 FUNC    GLOBAL DEFAULT    1 __sclose
  5684: 08055fc1   132 FUNC    GLOBAL DEFAULT    1 _ZN4mbed16mbed_file_handl
  5685: 0804de75    30 FUNC    WEAK   DEFAULT    1 _ZN4mbed9DigitalInC2E7Pin
  5686: 08052971    20 FUNC    GLOBAL DEFAULT    1 _ZN14LinkedListBase7deque
  5687: 2400e133   131 OBJECT  GLOBAL DEFAULT    6 memp_memory_IGMP_GROUP_ba
  5688: 08049efb    72 FUNC    GLOBAL DEFAULT    1 virtqueue_kick
  5689: 0805a0c7     2 FUNC    WEAK   DEFAULT    1 HAL_I2C_MemRxCpltCallback
  5690: 0804cde9    20 FUNC    WEAK   DEFAULT    1 _ZN7arduino6USBCDC9AsyncR
  5691: 0805f291     2 FUNC    WEAK   DEFAULT    1 I2C4_ER_IRQHandler
  5692: 2400f9bc     4 OBJECT  GLOBAL DEFAULT    6 _ZN4mbed3I2C6_ownerE
  5693: 0804f835    48 FUNC    GLOBAL DEFAULT    1 osSemaphoreDelete
  5694: 0806f2ac    20 OBJECT  WEAK   DEFAULT    1 _ZTVN14clmdep_msgpack2v11
  5695: 08042511    32 FUNC    GLOBAL DEFAULT    1 _Z13find_ScenarioP8LOITRU
  5696: 0805fab5    26 FUNC    GLOBAL DEFAULT    1 _ZN8USBPhyHw9ep0_stallEv
  5697: 080611e9   200 FUNC    GLOBAL DEFAULT    1 lp_ticker_set_interrupt
  5698: 08043b01    24 FUNC    GLOBAL DEFAULT    1 mriPlatform_RtosIsThreadA
  5699: 0805fbed    32 FUNC    GLOBAL DEFAULT    1 _ZN8USBPhyHw11set_address
  5700: 08072638    12 OBJECT  GLOBAL DEFAULT    1 _ZTSSt8bad_cast
  5701: 0804df95   148 FUNC    GLOBAL DEFAULT    1 digitalWrite
  5702: 0805f291     2 FUNC    WEAK   DEFAULT    1 OTG_FS_IRQHandler
  5703: 080402d9     0 FUNC    GLOBAL DEFAULT    1 _start
  5704: 080427f5     2 FUNC    GLOBAL DEFAULT    1 _ZN7arduino21UsbDebugComm
  5705: 0805f291     2 FUNC    WEAK   DEFAULT    1 WWDG_IRQHandler
  5706: 24011cf4     1 OBJECT  GLOBAL DEFAULT    6 lp_delayed_prog
  5707: 0805287b    98 FUNC    GLOBAL DEFAULT    1 _ZN16EndpointResolver10ne
  5708: 08054d5b    18 FUNC    GLOBAL DEFAULT    1 _ZN4mbed8FilePath10fileSy
  5709: 24080000     0 NOTYPE  GLOBAL DEFAULT    8 __StackTop
  5710: 080702f0    24 OBJECT  GLOBAL DEFAULT    1 _ZTVN4mbed10SerialBaseE
  5711: 0805f291     2 FUNC    WEAK   DEFAULT    1 DMA2_Stream1_IRQHandler
  5712: 080510c1    52 FUNC    GLOBAL DEFAULT    1 _ZN10STM32_EMACC2Ev
  5713: 08063695     4 FUNC    WEAK   DEFAULT    1 _ZNSs4_Rep10_M_destroyERK
  5714: 0804f471    48 FUNC    GLOBAL DEFAULT    1 osMutexNew
  5715: 08055f31     6 FUNC    GLOBAL DEFAULT    1 _ZN4mbed26mbed_set_unbuff
  5716: 080511bd    68 FUNC    GLOBAL DEFAULT    1 _ZN10STM32_EMAC15thread_f
  5717: 08054cf5    80 FUNC    GLOBAL DEFAULT    1 _ZN4mbed8FilePathC1EPKc
  5718: 0807276c    12 OBJECT  GLOBAL DEFAULT    1 _ZTISt11logic_error
  5719: 08056549   172 FUNC    GLOBAL DEFAULT    1 open
  5720: 0804c7df    64 FUNC    GLOBAL DEFAULT    1 _ZN7arduino18PluggableUSB
  5721: 0805f2f5   388 FUNC    GLOBAL DEFAULT    1 analogin_init
  5722: 08045e81   178 FUNC    WEAK   DEFAULT    1 _ZNK10clmdep_fmt7ArgListi
  5723: 0804a7bd    80 FUNC    GLOBAL DEFAULT    1 mriBuffer_ReadIntegerAsHe
  5724: 08055219   236 FUNC    GLOBAL DEFAULT    1 print_context_info
  5725: 0804f981   100 FUNC    GLOBAL DEFAULT    1 osRtxPostProcess
  5726: 08054b79    16 FUNC    GLOBAL DEFAULT    1 _ZN4mbed19CriticalSection
  5727: 08044ab7   112 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v26de
  5728: 0804b489   556 FUNC    GLOBAL DEFAULT    1 mriCmd_HandleVContCommand
  5729: 0804428d    54 FUNC    GLOBAL DEFAULT    1 _ZN7arduino3RPC28rpmsg_re
  5730: 0804b6cd    30 FUNC    GLOBAL DEFAULT    1 mriContext_Count
  5731: 08055125    18 FUNC    WEAK   DEFAULT    1 _ZN4mbed8internal8SysTime
  5732: 0804c771     2 FUNC    WEAK   DEFAULT    1 _ZN9USBDevice14callback_p
  5733: 0804887d   152 FUNC    WEAK   DEFAULT    1 _ZNK14clmdep_msgpack2v26o
  5734: 24011da8     4 OBJECT  WEAK   DEFAULT    6 _ZGVNSt7collateIwE2idE
  5735: 0804d373    78 FUNC    WEAK   DEFAULT    1 _ZN7arduino6USBCDC10Async
  5736: 080508f1    12 FUNC    GLOBAL DEFAULT    1 EvrRtxKernelError
  5737: 2400df40     4 OBJECT  GLOBAL DEFAULT    6 lwip_sys_mutex
  5738: 080500a1   132 FUNC    GLOBAL DEFAULT    1 osRtxThreadWaitEnter
  5739: 0804d5d1     8 FUNC    GLOBAL DEFAULT    1 _ZThn1192_N7arduino9USBSe
  5740: 08072584     8 OBJECT  GLOBAL DEFAULT    1 _ZTIN10__cxxabiv119__fore
  5741: 080535b9    54 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice24endpoint_m
  5742: 08054b4d    12 FUNC    WEAK   DEFAULT    1 serial_init_direct
  5743: 0806c825    28 FUNC    GLOBAL DEFAULT    1 _localeconv_r
  5744: 0805f291     2 FUNC    WEAK   DEFAULT    1 PVD_AVD_IRQHandler
  5745: 08060b21   116 FUNC    GLOBAL DEFAULT    1 i2c_get_timing
  5746: 24011dc4     4 OBJECT  WEAK   DEFAULT    6 _ZGVNSt8numpunctIwE2idE
  5747: 0806771d    60 FUNC    GLOBAL DEFAULT    1 __swrite
  5748: 08048b57    72 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v16pa
  5749: 08043e51    12 FUNC    GLOBAL DEFAULT    1 _ZN7arduino21UsbDebugComm
  5750: 0804872f    44 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v16ob
  5751: 080542fd   252 FUNC    WEAK   DEFAULT    1 _ZN4mbed33do_shared_event
  5752: 08052e01   122 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice12_control_o
  5753: 080629d5    20 FUNC    GLOBAL DEFAULT    1 _ZNSt8bad_castD2Ev
  5754: 0804601d    22 FUNC    WEAK   DEFAULT    1 _ZN10clmdep_fmt6BufferIcE
  5755: 0807291c    25 OBJECT  GLOBAL DEFAULT    1 _ZTSSt20bad_array_new_len
  5756: 080549a3    96 FUNC    GLOBAL DEFAULT    1 ticker_irq_handler
  5757: 0806355d     4 FUNC    GLOBAL DEFAULT    1 _ZNKSt11logic_error4whatE
  5758: 0805ac53     2 FUNC    WEAK   DEFAULT    1 HAL_PCD_MspDeInit
  5759: 08040365    60 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v17sb
  5760: 08059b29    28 FUNC    GLOBAL DEFAULT    1 HAL_HSEM_IRQHandler
  5761: 080460e7    14 FUNC    WEAK   DEFAULT    1 _ZNSt8_Rb_treeIN10clmdep_
  5762: 0804bc3d    12 FUNC    GLOBAL DEFAULT    1 mriCore_GetContext
  5763: 0806376d    20 FUNC    GLOBAL DEFAULT    1 _ZNSt12length_errorC1EPKc
  5764: 080405f5    16 FUNC    GLOBAL DEFAULT    1 HAL_FDCAN_TimestampWrapar
  5765: 0807257c     8 OBJECT  GLOBAL DEFAULT    1 _ZTIN10__cxxabiv115__forc
  5766: 08047e95    20 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v110t
  5767: 08052a7d     2 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice7suspendEb
  5768: 0805040d    48 FUNC    GLOBAL DEFAULT    1 osThreadSetPriority
  5769: 08056447     4 FUNC    GLOBAL DEFAULT    1 _ZdaPv
  5770: 2400dce8     4 OBJECT  GLOBAL DEFAULT    6 singleton_mutex_id
  5771: 0806ba69  3104 FUNC    GLOBAL DEFAULT    1 _dtoa_r
  5772: 24001080     4 OBJECT  GLOBAL DEFAULT    4 _ZN10__cxxabiv120__unexpe
  5773: 0806e784    35 OBJECT  WEAK   DEFAULT    1 _ZTSN14clmdep_msgpack2v11
  5774: 080629e9    28 FUNC    GLOBAL DEFAULT    1 _ZNSt8bad_castD0Ev
  5775: 080503c1    36 FUNC    GLOBAL DEFAULT    1 osThreadGetName
  5776: 0804d22d    80 FUNC    GLOBAL DEFAULT    1 _ZN7arduino6USBCDC10wait_
  5777: 24003838     4 OBJECT  GLOBAL DEFAULT    6 mriCortexMFlags
  5778: 08064ecd    34 FUNC    GLOBAL HIDDEN     1 _Unwind_Resume_or_Rethrow
  5779: 08051f35     2 FUNC    GLOBAL DEFAULT    1 _ZN4mbed10SerialBase6unlo
  5780: 0804d9f1    44 FUNC    GLOBAL DEFAULT    1 _ZN7arduino5Print5writeEP
  5781: 0805e1c1   136 FUNC    GLOBAL DEFAULT    1 FMC_NORSRAM_Init
  5782: 0806f2dc    28 OBJECT  WEAK   DEFAULT    1 _ZTVSt19_Sp_counted_delet
  5783: 08063a6d    22 FUNC    WEAK   DEFAULT    1 _ZNSt7__cxx1112basic_stri
  5784: 0804d46b    80 FUNC    GLOBAL DEFAULT    1 _ZN7arduino6USBCDC10recei
  5785: 0805fb7d    48 FUNC    GLOBAL DEFAULT    1 _ZN8USBPhyHw9ep0_writeEPh
  5786: 08050f0f     2 FUNC    GLOBAL DEFAULT    1 _ZN10STM32_EMAC10set_hwad
  5787: 08052865    22 FUNC    GLOBAL DEFAULT    1 _ZN16EndpointResolver5val
  5788: 0805f291     2 FUNC    WEAK   DEFAULT    1 SPI6_IRQHandler
  5789: 08042739     2 FUNC    WEAK   DEFAULT    1 _ZN4mbed6detail12Callback
  5790: 08043fad    20 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v113s
  5791: 08048f63    86 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v16pa
  5792: 08056149   220 FUNC    GLOBAL DEFAULT    1 _write
  5793: 24000000     0 NOTYPE  GLOBAL DEFAULT    4 _sdata
  5794: 080662a1     2 FUNC    GLOBAL DEFAULT    1 __retarget_lock_release_r
  5795: 08049c79     2 FUNC    GLOBAL DEFAULT    1 metal_machine_io_mem_map
  5796: 08061e81   228 FUNC    GLOBAL DEFAULT    1 serial_is_tx_ongoing
  5797: 08056af9    60 FUNC    GLOBAL DEFAULT    1 _ZN4rtos6ThreadD1Ev
  5798: 08059b09    16 FUNC    GLOBAL DEFAULT    1 HAL_HSEM_Release
  5799: 08061f65    36 FUNC    GLOBAL DEFAULT    1 hal_sleep
  5800: 08051bfb    14 FUNC    WEAK   DEFAULT    1 _ZN4mbed8AnalogInD0Ev
  5801: 08066a35   308 FUNC    GLOBAL DEFAULT    1 memcpy
  5802: 0806629d     2 FUNC    GLOBAL DEFAULT    1 __retarget_lock_acquire_r
  5803: 0805252d    44 FUNC    GLOBAL DEFAULT    1 _ZN4mbed10TimerEventC1EPK
  5804: 0804ca99    62 FUNC    GLOBAL DEFAULT    1 _ZN7arduino18PluggableUSB
  5805: 24003a38   712 OBJECT  GLOBAL DEFAULT    6 RPC1
  5806: 0805963b     2 FUNC    WEAK   DEFAULT    1 HAL_FDCAN_TxEventFifoCall
  5807: 24011e30     4 OBJECT  WEAK   DEFAULT    6 _ZGVNSt7num_getIcSt19istr
  5808: 08044061    20 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v117e
  5809: 0806eb90    36 OBJECT  WEAK   DEFAULT    1 _ZTVN7arduino14SerialRPCC
  5810: 0806ebe8    20 OBJECT  WEAK   DEFAULT    1 _ZTVN10clmdep_fmt11Format
  5811: 08054bd1   100 FUNC    GLOBAL DEFAULT    1 _ZN4mbed8FileBaseD2Ev
  5812: 0805353d    10 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice14endpoint_t
  5813: 0804dbef    36 FUNC    GLOBAL DEFAULT    1 _ZN7arduino6StringC2EPKc
  5814: 0805a4ed    96 FUNC    GLOBAL DEFAULT    1 HAL_I2C_ER_IRQHandler
  5815: 08054277     6 FUNC    GLOBAL DEFAULT    1 equeue_event_delay
  5816: 0806fc18   104 OBJECT  GLOBAL DEFAULT    1 osRtxConfig
  5817: 08054e09    84 FUNC    GLOBAL DEFAULT    1 _ZN4mbed6StreamC1EPKc
  5818: 080440b1    20 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v117b
  5819: 08052693    38 FUNC    GLOBAL DEFAULT    1 _ZN4mbed16UnbufferedSeria
  5820: 0805fcb1    56 FUNC    GLOBAL DEFAULT    1 _ZN8USBPhyHw14endpoint_wr
  5821: 08048101   112 FUNC    WEAK   DEFAULT    1 _ZNSt10_HashtableINSt7__c
  5822: 0805937f   112 FUNC    GLOBAL DEFAULT    1 HAL_FDCAN_Stop
  5823: 0804c2fd   156 FUNC    GLOBAL DEFAULT    1 _ZN7arduino4UART5beginEm
  5824: 08059d95   164 FUNC    GLOBAL DEFAULT    1 HAL_I2C_Master_Seq_Receiv
  5825: 0805198d    36 FUNC    GLOBAL DEFAULT    1 pbuf_alloc_reference
  5826: 0804bc85     8 FUNC    GLOBAL DEFAULT    1 mriCore_GetBuffer
  5827: 08054f41    32 FUNC    WEAK   DEFAULT    1 _ZN4mbed8internal8SysTime
  5828: 0805bc11   324 FUNC    GLOBAL DEFAULT    1 HAL_RCC_GetSysClockFreq
  5829: 080701cc    12 OBJECT  GLOBAL DEFAULT    1 memp_TCP_PCB_LISTEN
  5830: 0805964f     2 FUNC    WEAK   DEFAULT    1 HAL_FDCAN_TT_StopWatchCal
  5831: 0804d52b     4 FUNC    WEAK   DEFAULT    1 _ZNK4mbed10FileHandle11is
  5832: 0804c5e1    68 FUNC    WEAK   DEFAULT    1 _ZN7arduino9USBSerial4rea
  5833: 0806e814    20 OBJECT  WEAK   DEFAULT    1 _ZTVN14clmdep_msgpack2v11
  5834: 0806e88c    20 OBJECT  WEAK   DEFAULT    1 _ZTVN14clmdep_msgpack2v11
  5835: 08071436    24 OBJECT  GLOBAL DEFAULT    1 UARTPrescTable
  5836: 08056905    28 FUNC    GLOBAL DEFAULT    1 _ZN4rtos10ThisThread9slee
  5837: 08043241    40 FUNC    GLOBAL DEFAULT    1 mriPlatform_ClearHardware
  5838: 24003e00     4 OBJECT  GLOBAL DEFAULT    6 eventHandlerThreadId
  5839: 0804c071     4 FUNC    GLOBAL DEFAULT    1 mriPlatform_MemRead16
  5840: 080446fd    78 FUNC    WEAK   DEFAULT    1 _ZNSt10_HashtableINSt7__c
  5841: 080526c1    28 FUNC    GLOBAL DEFAULT    1 _ZN4mbed16UnbufferedSeria
  5842: 0805f291     2 FUNC    WEAK   DEFAULT    1 WWDG_RST_IRQHandler
  5843: 0804db41     4 FUNC    GLOBAL DEFAULT    1 _ZN7arduino5Print5printEh
  5844: 080583bd   264 FUNC    GLOBAL DEFAULT    1 HAL_ETH_IsRxDataAvailable
  5845: 0804aa99    28 FUNC    GLOBAL DEFAULT    1 mriCmd_SkipHardcodedBreak
  5846: 24003a30     4 OBJECT  GLOBAL DEFAULT    6 mriThreadSingleStepThread
  5847: 08059911   464 FUNC    GLOBAL DEFAULT    1 HAL_GPIO_Init
  5848: 0804c625     6 FUNC    WEAK   DEFAULT    1 _ZThn1216_N7arduino9USBSe
  5849: 0804aa75    36 FUNC    GLOBAL DEFAULT    1 mriCmd_ReadAddressAndLeng
  5850: 0804a405    20 FUNC    GLOBAL DEFAULT    1 MAILBOX_Notify
  5851: 08050da5   200 FUNC    GLOBAL DEFAULT    1 LAN8742_Init
  5852: 24011ea4     1 OBJECT  GLOBAL DEFAULT    6 __lock___at_quick_exit_mu
  5853: 08052b35    88 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice6unlockEv
  5854: 08052ae5     8 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice18string_lan
  5855: 0805b6ed  1316 FUNC    WEAK   DEFAULT    1 HAL_RCC_OscConfig
  5856: 08047f59    28 FUNC    WEAK   DEFAULT    1 _ZNSt19_Sp_counted_delete
  5857: 08072668    12 OBJECT  GLOBAL DEFAULT    1 _ZTISt9bad_alloc
  5858: 0804cb99    16 FUNC    GLOBAL DEFAULT    1 _ZN7arduino8internal18Plu
  5859: 0805f291     2 FUNC    WEAK   DEFAULT    1 EXTI15_10_IRQHandler
  5860: 24003230  1544 OBJECT  GLOBAL DEFAULT    6 mriCortexMDebuggerStack
  5861: 080445bd    36 FUNC    WEAK   DEFAULT    1 _ZN4mbed10TickerBaseD2Ev
  5862: 0804cd69    22 FUNC    GLOBAL DEFAULT    1 _ZN7arduino6USBCDCD0Ev
  5863: 08058563    58 FUNC    GLOBAL DEFAULT    1 HAL_ETH_GetRxDataLength
  5864: 08049059   352 FUNC    GLOBAL DEFAULT    1 MX_OPENAMP_Init
  5865: 080425a1   150 FUNC    GLOBAL DEFAULT    1 _ZN8LOITRUCKC1Ev
  5866: 08066301   148 FUNC    GLOBAL DEFAULT    1 __smakebuf_r
  5867: 080672e5    16 FUNC    GLOBAL DEFAULT    1 realloc
  5868: 24000170    40 OBJECT  WEAK   DEFAULT    4 _ZN10clmdep_fmt8internal9
  5869: 08050745    64 FUNC    GLOBAL DEFAULT    1 mbed_init
  5870: 0805acbd    72 FUNC    GLOBAL DEFAULT    1 HAL_PCD_Stop
  5871: 08059b19    16 FUNC    GLOBAL DEFAULT    1 HAL_HSEM_ActivateNotifica
  5872: 080629cd     8 FUNC    GLOBAL DEFAULT    1 _ZNKSt8bad_cast4whatEv
  5873: 08055edd     4 FUNC    WEAK   DEFAULT    1 _ZN4mbed28mbed_target_ove
  5874: 08052aed     8 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice25string_ima
  5875: 0804c249    28 FUNC    WEAK   DEFAULT    1 _ZN4mbed8CallbackIFvvEE11
  5876: 08055bb1    32 FUNC    GLOBAL DEFAULT    1 mbed_mem_trace_unlock
  5877: 080523b1    52 FUNC    GLOBAL DEFAULT    1 _ZN4mbed10TickerBase6deta
  5878: 0806e850    20 OBJECT  WEAK   DEFAULT    1 _ZTVN14clmdep_msgpack2v11
  5879: 08064731    42 FUNC    GLOBAL HIDDEN     1 _Unwind_VRS_Get
  5880: 0805210f    34 FUNC    GLOBAL DEFAULT    1 _ZN4mbed10SerialBase9writ
  5881: 24011db8     4 OBJECT  WEAK   DEFAULT    6 _ZGVNSt11__timepunctIwE2i
  5882: 0804ce85   138 FUNC    GLOBAL DEFAULT    1 _ZN7arduino6USBCDC26callb
  5883: 080555c1    18 FUNC    GLOBAL DEFAULT    1 core_util_atomic_decr_u32
  5884: 0804bb41    76 FUNC    GLOBAL DEFAULT    1 mriInit
  5885: 08052243   142 FUNC    GLOBAL DEFAULT    1 _ZN4mbed10SerialBase12ena
  5886: 0806fa24    72 OBJECT  GLOBAL DEFAULT    1 _ZTVN7arduino6USBCDCE
  5887: 08055e07     6 FUNC    WEAK   DEFAULT    1 _ZN12DirectSerial4sizeEv
  5888: 08045825    36 FUNC    WEAK   DEFAULT    1 _ZN7arduino14SerialRPCCla
  5889: 0806ebfc    20 OBJECT  WEAK   DEFAULT    1 _ZTVN10clmdep_fmt8interna
  5890: 08043939    60 FUNC    GLOBAL DEFAULT    1 _ZN7arduino11ThreadDebugD
  5891: 08063165    20 FUNC    GLOBAL DEFAULT    1 _ZN10__cxxabiv120__si_cla
  5892: 0805f291     2 FUNC    WEAK   DEFAULT    1 SWPMI1_IRQHandler
  5893: 0806b5e1    24 FUNC    GLOBAL DEFAULT    1 vfprintf
  5894: 08065651    12 FUNC    GLOBAL DEFAULT    1 _cleanup_r
  5895: 24001074     4 OBJECT  GLOBAL DEFAULT    4 SystemCoreClock
  5896: 080573d5   248 FUNC    GLOBAL DEFAULT    1 HAL_ADC_Start
  5897: 0806b7bd    80 FUNC    GLOBAL DEFAULT    1 _wcrtomb_r
  5898: 0804ac29    88 FUNC    GLOBAL DEFAULT    1 mriCmd_HandleMemoryWriteC
  5899: 0804d27d   100 FUNC    GLOBAL DEFAULT    1 _ZN7arduino6USBCDC4sendEP
  5900: 0804a5b9    72 FUNC    GLOBAL DEFAULT    1 mriBuffer_ReadByteAsHex
  5901: 08054d9b     4 FUNC    GLOBAL DEFAULT    1 _ZN4mbed6Stream4tellEv
  5902: 0805d619    22 FUNC    GLOBAL DEFAULT    1 RTC_ByteToBcd2
  5903: 0804f881   112 FUNC    GLOBAL DEFAULT    1 osRtxTick_Handler
  5904: 08050b65    12 FUNC    WEAK   DEFAULT    1 _ZN27whd_interface_shared
  5905: 0804d569     6 FUNC    WEAK   DEFAULT    1 _ZThn1216_N7arduino9USBSe
  5906: 080513fd    64 FUNC    GLOBAL DEFAULT    1 _ZN10STM32_EMAC12get_inst
  5907: 08065255    40 FUNC    GLOBAL HIDDEN     1 __gnu_unwind_frame
  5908: 08060fe9   108 FUNC    GLOBAL DEFAULT    1 lp_ticker_disable_interru
  5909: 08071898   156 OBJECT  WEAK   DEFAULT    1 PinMap_I2C_SDA
  5910: 0805e3a1   224 FUNC    GLOBAL DEFAULT    1 USB_SetTurnaroundTime
  5911: 080491d9    12 FUNC    GLOBAL DEFAULT    1 OPENAMP_check_for_message
  5912: 08070b38    12 OBJECT  WEAK   DEFAULT    1 _ZTVN4mbed8internal8SysTi
  5913: 0804a451    10 FUNC    GLOBAL DEFAULT    1 mriBuffer_Init
  5914: 0804f0c1   120 FUNC    GLOBAL DEFAULT    1 osMessageQueueGet
  5915: 24011ea0     4 OBJECT  GLOBAL DEFAULT    6 errno
  5916: 0805b585     8 FUNC    GLOBAL DEFAULT    1 HAL_PCDEx_SetRxFiFo
  5917: 08058625     2 FUNC    WEAK   DEFAULT    1 HAL_ETH_EEECallback
  5918: 08048d51   228 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v16pa
  5919: 0805fd15    52 FUNC    GLOBAL DEFAULT    1 _ZN8USBPhyHw10disconnectE
  5920: 08055d85    20 FUNC    GLOBAL DEFAULT    1 sleep_manager_can_deep_sl
  5921: 08044075    20 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v117s
  5922: 08050f0f     2 FUNC    GLOBAL DEFAULT    1 _ZN10STM32_EMAC22remove_m
  5923: 080426e5    12 FUNC    GLOBAL DEFAULT    1 mriUsageFaultHandlerStub
  5924: 080445f9    22 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v16de
  5925: 0804a80d    40 FUNC    GLOBAL DEFAULT    1 mriBuffer_MatchesString
  5926: 08051645    44 FUNC    GLOBAL DEFAULT    1 sys_mutex_lock
  5927: 0804b82d    56 FUNC    GLOBAL DEFAULT    1 mriGdbConsole_WriteHexVal
  5928: 0806065d    24 FUNC    GLOBAL DEFAULT    1 i2c_ev_err_disable
  5929: 08056229   156 FUNC    GLOBAL DEFAULT    1 _read
  5930: 08053001    30 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice26_request_g
  5931: 080532e1   104 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice27_complete_
  5932: 24003a18     4 OBJECT  GLOBAL DEFAULT    6 mriThreadOrigHardFault
  5933: 0804268b    54 FUNC    GLOBAL DEFAULT    1 mriFaultHandlerStub
  5934: 08052765    44 FUNC    GLOBAL DEFAULT    1 _ZN7AsyncOpD2Ev
  5935: 08071394    16 OBJECT  GLOBAL DEFAULT    1 _ZTVN4rtos6ThreadE
  5936: 08043e85    48 FUNC    WEAK   DEFAULT    1 _ZN7arduino3RPC4readEv
  5937: 08068019    52 FUNC    GLOBAL DEFAULT    1 strspn
  5938: 08052641     6 FUNC    WEAK   DEFAULT    1 _ZThn124_N4mbed16Unbuffer
  5939: 08056761    56 FUNC    GLOBAL DEFAULT    1 _ZN4rtos6Kernel4impl14get
  5940: 08062be5    30 FUNC    GLOBAL DEFAULT    1 __cxa_call_terminate
  5941: 24011dac     4 OBJECT  WEAK   DEFAULT    6 _ZGVNSt8messagesIwE2idE
  5942: 0806cfc5     0 FUNC    GLOBAL DEFAULT    1 _fini
  5943: 080555af    18 FUNC    GLOBAL DEFAULT    1 core_util_atomic_decr_u16
  5944: 0805f291     2 FUNC    WEAK   DEFAULT    1 TIM1_BRK_IRQHandler
  5945: 08060e45   116 FUNC    GLOBAL DEFAULT    1 i2c_init
  5946: 08062229    16 FUNC    GLOBAL DEFAULT    1 us_ticker_clear_interrupt
  5947: 08043415   136 FUNC    GLOBAL DEFAULT    1 mriPlatform_SetHardwareWa
  5948: 24001abc  1592 OBJECT  GLOBAL DEFAULT    6 SerialUSB1
  5949: 0805f291     2 FUNC    WEAK   DEFAULT    1 I2C2_ER_IRQHandler
  5950: 0805f291     2 FUNC    WEAK   DEFAULT    1 LPTIM5_IRQHandler
  5951: 0806f840    12 OBJECT  WEAK   DEFAULT    1 _ZZN4mbed8CallbackIFvvEE8
  5952: 0805f625   176 FUNC    GLOBAL DEFAULT    1 i2c_get_pclk
  5953: 0804610d    96 FUNC    WEAK   DEFAULT    1 _ZN10clmdep_fmt11BasicWri
  5954: 24001aa0     0 NOTYPE  GLOBAL DEFAULT    5 __uninitialized_end
  5955: 08041669    84 FUNC    GLOBAL DEFAULT    1 _Z15RTC_AlarmConfigP8LOIT
  5956: 0805f291     2 FUNC    WEAK   DEFAULT    1 LPTIM3_IRQHandler
  5957: 08054ef7    40 FUNC    WEAK   DEFAULT    1 _ZN4mbed8internal8SysTime
  5958: 0804c5a5    60 FUNC    GLOBAL DEFAULT    1 _ZN7arduino4UART4peekEv
  5959: 08052b0d     8 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice20string_ipr
  5960: 24011d70     4 OBJECT  GLOBAL DEFAULT    6 timer_ccr1_reg
  5961: 080446e7    22 FUNC    WEAK   DEFAULT    1 _ZN3rpc6detail8responseD2
  5962: 080446a5    22 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v26pa
  5963: 0806534d   208 FUNC    GLOBAL DEFAULT    1 _fclose_r
  5964: 08056727    14 FUNC    GLOBAL DEFAULT    1 _ZN4rtos10EventFlagsD1Ev
  5965: 0805f291     2 FUNC    WEAK   DEFAULT    1 CM4_SEV_IRQHandler
  5966: 080622a1     8 FUNC    GLOBAL DEFAULT    1 _ZGTtNKSt13bad_exception4
  5967: 08062e55     8 FUNC    GLOBAL DEFAULT    1 _ZN10__cxxabiv112__unexpe
  5968: 0805256d    10 FUNC    GLOBAL DEFAULT    1 _ZN4mbed10TimerEvent6remo
  5969: 080497d9    30 FUNC    WEAK   DEFAULT    1 rpmsg_virtio_shm_pool_get
  5970: 0804cf0f    64 FUNC    GLOBAL DEFAULT    1 _ZN7arduino6USBCDC9_send_
  5971: 0805e2a1    60 FUNC    GLOBAL DEFAULT    1 FMC_NORSRAM_Extended_Timi
  5972: 08052985    52 FUNC    GLOBAL DEFAULT    1 _ZN14LinkedListBase6remov
  5973: 0805f291     2 FUNC    WEAK   DEFAULT    1 TIM7_IRQHandler
  5974: 08063e31    58 FUNC    GLOBAL DEFAULT    1 _ZNKSt3_V214error_categor
  5975: 08047055   160 FUNC    WEAK   DEFAULT    1 _ZN10clmdep_fmt14BasicFor
  5976: 080635e9    64 FUNC    GLOBAL DEFAULT    1 _ZNSt13runtime_errorD2Ev
  5977: 0805e71d   172 FUNC    GLOBAL DEFAULT    1 USB_DeactivateEndpoint
  5978: 0806c9ed    18 FUNC    GLOBAL DEFAULT    1 __i2b
  5979: 0806376d    20 FUNC    GLOBAL DEFAULT    1 _ZNSt12length_errorC2EPKc
  5980: 0804871b    16 FUNC    GLOBAL DEFAULT    1 _ZN3rpc6detail8response5e
  5981: 0805ffed    88 FUNC    GLOBAL DEFAULT    1 _ZN8USBPhyHw12endpoint_ad
  5982: 24003a24     4 OBJECT  GLOBAL DEFAULT    6 mriThreadOrigSVCall
  5983: 08045c31    24 FUNC    WEAK   DEFAULT    1 _ZN10clmdep_fmt17BasicMem
  5984: 08056861    14 FUNC    GLOBAL DEFAULT    1 _ZN4rtos5MutexD2Ev
  5985: 08050a41    12 FUNC    GLOBAL DEFAULT    1 OS_Tick_Disable
  5986: 0806fa84    12 OBJECT  WEAK   DEFAULT    1 _ZZN4mbed8CallbackIFvvEE8
  5987: 08051b95    18 FUNC    GLOBAL DEFAULT    1 tcp_free_ooseq
  5988: 080605e5   120 FUNC    GLOBAL DEFAULT    1 i2c_ev_err_enable
  5989: 0805aa25   204 FUNC    GLOBAL DEFAULT    1 HAL_LPTIM_Init
  5990: 08056bed     2 FUNC    WEAK   DEFAULT    1 HAL_MspInit
  5991: 08064e85    34 FUNC    GLOBAL HIDDEN     1 _Unwind_RaiseException
  5992: 08043ab5     4 FUNC    GLOBAL DEFAULT    1 mriSemihost_HandleSemihos
  5993: 080542cd    16 FUNC    GLOBAL DEFAULT    1 equeue_sema_create
  5994: 080635cd    28 FUNC    GLOBAL DEFAULT    1 _ZNSt12length_errorD0Ev
  5995: 0804eb23    66 FUNC    GLOBAL DEFAULT    1 osRtxMemoryPoolInit
  5996: 08063179    28 FUNC    GLOBAL DEFAULT    1 _ZN10__cxxabiv120__si_cla
  5997: 0805b659   132 FUNC    GLOBAL DEFAULT    1 HAL_PWREx_EnterSTOPMode
  5998: 080619b1    24 FUNC    GLOBAL DEFAULT    1 serial_writable
  5999: 08055d25    44 FUNC    GLOBAL DEFAULT    1 sleep_manager_lock_deep_s
  6000: 080726f8     8 OBJECT  GLOBAL DEFAULT    1 _ZTISt9type_info
  6001: 0804c8a5   144 FUNC    GLOBAL DEFAULT    1 _ZN7arduino18PluggableUSB
  6002: 08051d39    48 FUNC    GLOBAL DEFAULT    1 _ZN4mbed3I2C6aquireEv
  6003: 080427f5     2 FUNC    GLOBAL DEFAULT    1 _ZN7arduino21UsbDebugComm
  6004: 08057a55   100 FUNC    GLOBAL DEFAULT    1 HAL_NVIC_SetPriority
  6005: 0806fa98   284 OBJECT  GLOBAL DEFAULT    1 _ZTVN7arduino9USBSerialE
  6006: 08065b21     4 FUNC    GLOBAL DEFAULT    1 _fseek_r
  6007: 0804da43    10 FUNC    GLOBAL DEFAULT    1 _ZN7arduino5Print5printER
  6008: 08071718    48 OBJECT  WEAK   DEFAULT    1 PinMap_ADC_Internal
  6009: 0805f291     2 FUNC    WEAK   DEFAULT    1 DMA2D_IRQHandler
  6010: 0805f291     2 FUNC    WEAK   DEFAULT    1 FLASH_IRQHandler
  6011: 0804c291   106 FUNC    GLOBAL DEFAULT    1 _ZN7arduino4UART5on_rxEv
  6012: 0804a101    40 FUNC    GLOBAL DEFAULT    1 metal_generic_dev_sys_ope
  6013: 08040365    60 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v17sb
  6014: 080635b9    20 FUNC    GLOBAL DEFAULT    1 _ZNSt12length_errorD2Ev
  6015: 080606b5   208 FUNC    GLOBAL DEFAULT    1 i2c_hw_reset
  6016: 08045f65    44 FUNC    WEAK   DEFAULT    1 _ZN10clmdep_fmt8internal1
  6017: 0806cea5   244 FUNC    GLOBAL DEFAULT    1 __ssprint_r
  6018: 0805b3f3    64 FUNC    GLOBAL DEFAULT    1 HAL_PCD_EP_Transmit
  6019: 08063629    18 FUNC    GLOBAL DEFAULT    1 _ZNSt13runtime_errorD0Ev
  6020: 08043869   208 FUNC    GLOBAL DEFAULT    1 _ZN7arduino11ThreadDebugC
  6021: 0804da7d    20 FUNC    GLOBAL DEFAULT    1 _ZN7arduino5Print7println
  6022: 0805f291     2 FUNC    WEAK   DEFAULT    1 OTG_FS_EP1_IN_IRQHandler
  6023: 0804c181    52 FUNC    GLOBAL DEFAULT    1 _Z16_ontouch1200bps_v
  6024: 0804fad1    28 FUNC    GLOBAL DEFAULT    1 osThreadExit
  6025: 08054d7f    18 FUNC    GLOBAL DEFAULT    1 _ZN4mbed8FilePath4fileEv
  6026: 080601ad     4 FUNC    GLOBAL DEFAULT    1 analogin_read_u16
  6027: 0804d6e5     8 FUNC    GLOBAL DEFAULT    1 _ZThn1192_N7arduino9USBSe
  6028: 0805046d    48 FUNC    GLOBAL DEFAULT    1 osThreadResume
  6029: 0804579d    50 FUNC    WEAK   DEFAULT    1 _ZN7arduino14SerialRPCCla
  6030: 080551a1    20 FUNC    WEAK   DEFAULT    1 _ZN4mbed8internal8SysTime
  6031: 080568b5    60 FUNC    GLOBAL DEFAULT    1 _ZN4rtos9Semaphore15try_a
  6032: 0804fcfd    20 FUNC    GLOBAL DEFAULT    1 osRtxThreadSwitch
  6033: 0804c457     6 FUNC    WEAK   DEFAULT    1 _ZThn1216_N7arduino9USBSe
  6034: 080446bb    44 FUNC    WEAK   DEFAULT    1 _ZNSt14__shared_countILN9
  6035: 0805103b    30 FUNC    GLOBAL DEFAULT    1 _ZN10STM32_EMAC17set_link
  6036: 08053371    78 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice23_complete_
  6037: 08047f89    28 FUNC    WEAK   DEFAULT    1 _ZNSt10unique_ptrIN14clmd
  6038: 080652ad     2 FUNC    WEAK   HIDDEN     1 __aeabi_idiv0
  6039: 080427a9    22 FUNC    WEAK   DEFAULT    1 _ZN10ThreadList17compareT
  6040: 0806763d    40 FUNC    GLOBAL DEFAULT    1 _kill_r
  6041: 080425a1   150 FUNC    GLOBAL DEFAULT    1 _ZN8LOITRUCKC2Ev
  6042: 08060881   308 FUNC    GLOBAL DEFAULT    1 i2c_compute_scll_sclh
  6043: 08063b55    48 FUNC    GLOBAL DEFAULT    1 _ZSt20__throw_length_erro
  6044: 08052b8d    32 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice13assert_loc
  6045: 0804d669    20 FUNC    GLOBAL DEFAULT    1 _Z14usbPortChangediiii
  6046: 080652c1    60 FUNC    GLOBAL DEFAULT    1 __assert_func
  6047: 08057537    62 FUNC    GLOBAL DEFAULT    1 HAL_ADC_Stop
  6048: 080403a1    60 FUNC    GLOBAL DEFAULT    1 HAL_RTC_AlarmAEventCallba
  6049: 24011e04     4 OBJECT  WEAK   DEFAULT    6 _ZGVNSt7__cxx118numpunctI
  6050: 0804c7c9    22 FUNC    GLOBAL DEFAULT    1 _ZN7arduino18PluggableUSB
  6051: 08055c81    64 FUNC    GLOBAL DEFAULT    1 _ZN4mbed8internal23do_tim
  6052: 0805d905   104 FUNC    GLOBAL DEFAULT    1 HAL_SRAM_Init
  6053: 24011cf0     4 OBJECT  GLOBAL DEFAULT    6 lp_delayed_counter
  6054: 0805f291     2 FUNC    WEAK   DEFAULT    1 DMA1_Stream7_IRQHandler
  6055: 08055f8d    52 FUNC    GLOBAL DEFAULT    1 __cxa_guard_release
  6056: 0804cbb5     2 FUNC    WEAK   DEFAULT    1 _ZN7arduino6USBCDC19line_
  6057: 08042d69    10 FUNC    WEAK   DEFAULT    1 _ZN4mbed6detail12Callback
  6058: 0806fc80     4 OBJECT  WEAK   DEFAULT    1 osRtxUserSVC
  6059: 0805f291     2 FUNC    WEAK   DEFAULT    1 DMA2_Stream0_IRQHandler
  6060: 080661ad    82 FUNC    GLOBAL DEFAULT    1 _fwalk_reent
  6061: 08042531     8 FUNC    GLOBAL DEFAULT    1 _Z24convert_Scenario_To_C
  6062: 08067309   280 FUNC    GLOBAL DEFAULT    1 __srefill_r
  6063: 0806e6a4    41 OBJECT  WEAK   DEFAULT    1 _ZTSN14clmdep_msgpack2v11
  6064: 08053349    40 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice20_control_a
  6065: 080600e9     2 FUNC    GLOBAL DEFAULT    1 HAL_PCD_DisconnectCallbac
  6066: 0806c841    44 FUNC    GLOBAL DEFAULT    1 _lseek_r
  6067: 08049f91    60 FUNC    GLOBAL DEFAULT    1 metal_generic_dev_dma_map
  6068: 0806c6fd   158 FUNC    GLOBAL DEFAULT    1 __fputwc
  6069: 0804d63d    42 FUNC    GLOBAL DEFAULT    1 _ZN7arduino9USBSerial7dat
  6070: 08053e11    30 FUNC    GLOBAL DEFAULT    1 _ZN6events10EventQueueC1E
  6071: 24010694    84 OBJECT  GLOBAL DEFAULT    6 mbed_fault_context
  6072: 0804a1bd    92 FUNC    GLOBAL DEFAULT    1 metal_io_init
  6073: 08059455   360 FUNC    GLOBAL DEFAULT    1 HAL_FDCAN_GetRxMessage
  6074: 08056961   116 FUNC    GLOBAL DEFAULT    1 _ZN4rtos6Thread11construc
  6075: 08050681    72 FUNC    GLOBAL DEFAULT    1 software_init_hook
  6076: 0804530d   296 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v28un
  6077: 08063a85    96 FUNC    WEAK   DEFAULT    1 _ZNSt7__cxx1112basic_stri
  6078: 080607ef    20 FUNC    GLOBAL DEFAULT    1 HAL_I2C_AddrCallback
  6079: 08066299     2 FUNC    GLOBAL DEFAULT    1 __retarget_lock_close_rec
  6080: 0804fc51    16 FUNC    GLOBAL DEFAULT    1 osRtxThreadReadyPut
  6081: 08066395    16 FUNC    GLOBAL DEFAULT    1 malloc
  6082: 08046603   326 FUNC    WEAK   DEFAULT    1 _ZN10clmdep_fmt11BasicWri
  6083: 08056409    24 FUNC    GLOBAL DEFAULT    1 _ZdlPv
  6084: 080461c9    80 FUNC    WEAK   DEFAULT    1 _ZN10clmdep_fmt8internal1
  6085: 08052447    56 FUNC    GLOBAL DEFAULT    1 _ZNK4mbed9TimerBase9slice
  6086: 0804d5d9    34 FUNC    GLOBAL DEFAULT    1 _ZN7arduino9USBSerial5_ge
  6087: 0805f291     2 FUNC    WEAK   DEFAULT    1 UART5_IRQHandler
  6088: 080593ef   100 FUNC    GLOBAL DEFAULT    1 HAL_FDCAN_AddMessageToTxF
  6089: 08067a5d   972 FUNC    GLOBAL DEFAULT    1 _strerror_r
  6090: 24001aa0     0 NOTYPE  GLOBAL DEFAULT    4 __data_end__
  6091: 08050ba1   476 FUNC    GLOBAL DEFAULT    1 HAL_ETH_MspInit
  6092: 2400447c   316 OBJECT  GLOBAL DEFAULT    6 _UART2_
  6093: 0805f291     2 FUNC    WEAK   DEFAULT    1 CEC_IRQHandler
  6094: 0804cbcd     8 FUNC    GLOBAL DEFAULT    1 _ZN7arduino6USBCDC20strin
  6095: 0805291f    10 FUNC    GLOBAL DEFAULT    1 _ZN16EndpointResolver11en
  6096: 08042e59     8 FUNC    GLOBAL DEFAULT    1 mriPlatform_GetPacketBuff
  6097: 0805e499    46 FUNC    GLOBAL DEFAULT    1 USB_SetCurrentMode
  6098: 080504f1    36 FUNC    GLOBAL DEFAULT    1 osThreadEnumerate
  6099: 08065e3d    40 FUNC    GLOBAL DEFAULT    1 _fstat_r
  6100: 08053759   156 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice16endpoint_u
  6101: 0805f291     2 FUNC    WEAK   DEFAULT    1 UART7_IRQHandler
  6102: 08060675    64 FUNC    GLOBAL DEFAULT    1 i2c_get_irq_handler
  6103: 080703f4    24 OBJECT  GLOBAL DEFAULT    1 _ZTV7AsyncOp
  6104: 08064f15    34 FUNC    GLOBAL HIDDEN     1 ___Unwind_Backtrace
  6105: 080675d5    86 FUNC    GLOBAL DEFAULT    1 _raise_r
  6106: 24011cf5     1 OBJECT  GLOBAL DEFAULT    6 roll_over_flag
  6107: 0806327d     2 FUNC    GLOBAL DEFAULT    1 _ZNSt9type_infoD2Ev
  6108: 08057cc5     6 FUNC    GLOBAL DEFAULT    1 HAL_DMA_GetState
  6109: 0804a17d    64 FUNC    GLOBAL DEFAULT    1 metal_init
  6110: 0805f7c1    24 FUNC    GLOBAL DEFAULT    1 serial_irq_handler
  6111: 080514bd    24 FUNC    GLOBAL DEFAULT    1 HAL_ETH_DMAErrorCallback
  6112: 08040605    56 FUNC    WEAK   DEFAULT    1 _ZNSt10unique_ptrIN14clmd
  6113: 0804e4b1    96 FUNC    GLOBAL DEFAULT    1 osEventFlagsSet
  6114: 0805f291     2 FUNC    WEAK   DEFAULT    1 ADC_IRQHandler
  6115: 08052bd9   100 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice3outEh
  6116: 08065789    12 FUNC    GLOBAL DEFAULT    1 __sfp_lock_acquire
  6117: 0804aa45    48 FUNC    GLOBAL DEFAULT    1 mriCmd_ReadAddressAndLeng
  6118: 08045785    24 FUNC    WEAK   DEFAULT    1 _ZN7arduino14SerialRPCCla
  6119: 08067f1d   150 FUNC    GLOBAL DEFAULT    1 strncmp
  6120: 08055bf5    32 FUNC    WEAK   DEFAULT    1 _ZNK4mbed8internal18timed
  6121: 08067759    32 FUNC    GLOBAL DEFAULT    1 __sseek
  6122: 080509a9   136 FUNC    GLOBAL DEFAULT    1 OS_Tick_Setup
  6123: 080568f1     6 FUNC    GLOBAL DEFAULT    1 _ZN4rtos9Semaphore7releas
  6124: 0805d3cd     2 FUNC    WEAK   DEFAULT    1 HAL_RTC_MspInit
  6125: 08064db5     0 FUNC    GLOBAL HIDDEN     1 __gnu_Unwind_Restore_VFP_
  6126: 240108f4     4 OBJECT  GLOBAL DEFAULT    6 mbed_heap_start
  6127: 08064b05     4 FUNC    WEAK   HIDDEN     1 __aeabi_unwind_cpp_pr1
  6128: 08061695   144 FUNC    GLOBAL DEFAULT    1 pin_mode
  6129: 0804cd39    48 FUNC    GLOBAL DEFAULT    1 _ZN7arduino6USBCDCD2Ev
  6130: 08051cc5    28 FUNC    GLOBAL DEFAULT    1 _ZN4mbed12DigitalInOut4mo
  6131: 0805b33d    94 FUNC    GLOBAL DEFAULT    1 HAL_PCD_EP_Close
  6132: 08054c49   116 FUNC    GLOBAL DEFAULT    1 _ZN4mbed8FileBase6lookupE
  6133: 30040100   240 OBJECT  GLOBAL DEFAULT   10 DMATxDscrTab
  6134: 080567e1    14 FUNC    GLOBAL DEFAULT    1 _ZN4rtos5MutexC2Ev
  6135: 0805f291     2 FUNC    WEAK   DEFAULT    1 SAI3_IRQHandler
  6136: 08052647    68 FUNC    GLOBAL DEFAULT    1 _ZN4mbed16UnbufferedSeria
  6137: 08054d49    18 FUNC    GLOBAL DEFAULT    1 _ZN4mbed8FilePath12isFile
  6138: 0804a46d    14 FUNC    GLOBAL DEFAULT    1 mriBuffer_BytesLeft
  6139: 08043ac5    28 FUNC    GLOBAL DEFAULT    1 mriPlatform_RtosGetFirstT
  6140: 08065b25   792 FUNC    GLOBAL DEFAULT    1 _fseeko_r
  6141: 08052863     2 FUNC    GLOBAL DEFAULT    1 _ZN16EndpointResolverD2Ev
  6142: 0804d6ed     8 FUNC    GLOBAL DEFAULT    1 _ZThn1196_N7arduino9USBSe
  6143: 08059ef5    40 FUNC    GLOBAL DEFAULT    1 HAL_I2C_EnableListen_IT
  6144: 0805043d    48 FUNC    GLOBAL DEFAULT    1 osThreadSuspend
  6145: 0805eb3b    82 FUNC    GLOBAL DEFAULT    1 USB_EPClearStall
  6146: 08055575    20 FUNC    GLOBAL DEFAULT    1 mbed_assert_internal
  6147: 0804d557     2 FUNC    WEAK   DEFAULT    1 _ZThn1216_N7arduino9USBSe
  6148: 0805665d    92 FUNC    GLOBAL DEFAULT    1 mbed_stats_sys_get
  6149: 240029e0     1 OBJECT  GLOBAL DEFAULT    6 threadDebug
  6150: 08054ab1   156 FUNC    GLOBAL DEFAULT    1 mbed_mpu_init
  6151: 080431c9    60 FUNC    GLOBAL DEFAULT    1 mriPlatform_SetHardwareBr
  6152: 0806363d    88 FUNC    WEAK   DEFAULT    1 _ZNSs4_Rep9_S_createEjjRK
  6153: 0805559d    18 FUNC    GLOBAL DEFAULT    1 core_util_atomic_incr_u16
  6154: 08063561     4 FUNC    GLOBAL DEFAULT    1 _ZNKSt13runtime_error4wha
  6155: 0804771d    42 FUNC    WEAK   DEFAULT    1 _ZN10clmdep_fmt8internal1
  6156: 0806ce79    44 FUNC    GLOBAL DEFAULT    1 _read_r
  6157: 08059c4f   162 FUNC    GLOBAL DEFAULT    1 HAL_I2C_Init
  6158: 08054a9d    20 FUNC    GLOBAL DEFAULT    1 us_ticker_irq_handler
  6159: 0804dd3d    12 FUNC    WEAK   DEFAULT    1 _ZN4mbed13LowPowerTimerD2
  6160: 0805f291     2 FUNC    WEAK   DEFAULT    1 LPTIM4_IRQHandler
  6161: 0805f291     2 FUNC    WEAK   DEFAULT    1 TIM16_IRQHandler
  6162: 24011cb4    56 OBJECT  GLOBAL DEFAULT    6 LptimHandle
  6163: 0805e4c9    36 FUNC    GLOBAL DEFAULT    1 USB_FlushTxFifo
  6164: 0804a69d    26 FUNC    GLOBAL DEFAULT    1 mriBuffer_WriteString
  6165: 08054d45     4 FUNC    GLOBAL DEFAULT    1 _ZN4mbed8FilePath8fileNam
  6166: 08070a78   112 OBJECT  GLOBAL DEFAULT    1 _ZTVN4mbed6StreamE
  6167: 0805dbdd   924 FUNC    GLOBAL DEFAULT    1 UART_SetConfig
  6168: 080544f7     8 FUNC    GLOBAL DEFAULT    1 gpio_init_out_ex
  6169: 240107a4     1 OBJECT  GLOBAL DEFAULT    6 mbed_error_in_progress
  6170: 08056871    52 FUNC    GLOBAL DEFAULT    1 _ZN4rtos9Semaphore11const
  6171: 0806e878    20 OBJECT  WEAK   DEFAULT    1 _ZTVN14clmdep_msgpack2v11
  6172: 38010000     0 NOTYPE  GLOBAL DEFAULT  ABS __OPENAMP_region_end__
  6173: 08064dc5     0 FUNC    GLOBAL HIDDEN     1 __gnu_Unwind_Restore_VFP_
  6174: 0805dab9   288 FUNC    GLOBAL DEFAULT    1 HAL_TIM_OC_Start
  6175: 08050b41    36 FUNC    WEAK   DEFAULT    1 _ZNK4mbed8CallbackIFvbEE4
  6176: 08060063    44 FUNC    GLOBAL DEFAULT    1 HAL_PCD_DataOutStageCallb
  6177: 08047e87    14 FUNC    WEAK   DEFAULT    1 _ZNSt19_Sp_counted_delete
  6178: 08053135    68 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice14_control_s
  6179: 08044d65   200 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v26de
  6180: 0804b15b    46 FUNC    GLOBAL DEFAULT    1 mriCmd_HandleSingleStepWi
  6181: 08063719    42 FUNC    WEAK   DEFAULT    1 _ZNSsC1EPKcRKSaIcE
  6182: 080647bd   112 FUNC    GLOBAL HIDDEN     1 __gnu_Unwind_Backtrace
  6183: 08043fd5    20 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v119d
  6184: 080621b5    24 FUNC    GLOBAL DEFAULT    1 us_ticker_init
  6185: 08067665     4 FUNC    GLOBAL DEFAULT    1 _getpid_r
  6186: 08062239    48 FUNC    GLOBAL DEFAULT    1 save_timer_ctx
  6187: 08062f4d   100 FUNC    GLOBAL DEFAULT    1 __cxa_begin_cleanup
  6188: 0806e638    37 OBJECT  WEAK   DEFAULT    1 _ZTSN14clmdep_msgpack2v11
  6189: 08053d39    68 FUNC    GLOBAL DEFAULT    1 _ZN9USBDeviceD1Ev
  6190: 0804db59    16 FUNC    GLOBAL DEFAULT    1 _ZN7arduino6StringD2Ev
  6191: 0805ad07     2 FUNC    WEAK   DEFAULT    1 HAL_PCD_ISOINIncompleteCa
  6192: 0804e511    48 FUNC    GLOBAL DEFAULT    1 osEventFlagsClear
  6193: 2400f3fb   131 OBJECT  GLOBAL DEFAULT    6 memp_memory_TCPIP_MSG_INP
  6194: 08063b85     8 FUNC    GLOBAL DEFAULT    1 _ZNKSt17bad_function_call
  6195: 08067e41   220 FUNC    GLOBAL DEFAULT    1 strlen
  6196: 0805fc0d    56 FUNC    GLOBAL DEFAULT    1 _ZN8USBPhyHw8ep0_readEPhm
  6197: 24011d24    76 OBJECT  GLOBAL DEFAULT    6 TimMasterHandle
  6198: 0805f291     2 FUNC    WEAK   DEFAULT    1 BDMA_Channel5_IRQHandler
  6199: 080540f3   388 FUNC    GLOBAL DEFAULT    1 equeue_dispatch
  6200: 24011dd4     4 OBJECT  WEAK   DEFAULT    6 _ZGVNSt10moneypunctIwLb0E
  6201: 0804abe1    72 FUNC    GLOBAL DEFAULT    1 mriCmd_HandleMemoryReadCo
  6202: 0805f291     2 FUNC    WEAK   DEFAULT    1 BDMA_Channel0_IRQHandler
  6203: 08043c01    52 FUNC    GLOBAL DEFAULT    1 mriPlatform_RtosGetThread
  6204: 24080000     0 NOTYPE  GLOBAL DEFAULT  ABS _estack
  6205: 08063b8d    20 FUNC    GLOBAL DEFAULT    1 _ZNSt17bad_function_callD
  6206: 080701c0    12 OBJECT  GLOBAL DEFAULT    1 memp_TCP_PCB
  6207: 0804ea7d   106 FUNC    WEAK   DEFAULT    1 osRtxMemoryAlloc
  6208: 0805252d    44 FUNC    GLOBAL DEFAULT    1 _ZN4mbed10TimerEventC2EPK
  6209: 08060851    18 FUNC    GLOBAL DEFAULT    1 HAL_I2C_ListenCpltCallbac
  6210: 080404a1   300 FUNC    GLOBAL DEFAULT    1 _Z13my_can_filterP5can_sm
  6211: 0804280b     4 FUNC    GLOBAL DEFAULT    1 _ZN7arduino21UsbDebugComm
  6212: 0805f291     2 FUNC    WEAK   DEFAULT    1 HRTIM1_TIMA_IRQHandler
  6213: 0805fa95     2 FUNC    GLOBAL DEFAULT    1 _ZN8USBPhyHw9configureEv
  6214: 08071bf8   336 OBJECT  WEAK   DEFAULT    1 PinMap_UART_TX
  6215: 080640d5   716 FUNC    GLOBAL HIDDEN     1 __udivmoddi4
  6216: 0806e740    12 OBJECT  WEAK   DEFAULT    1 _ZTIN14clmdep_msgpack2v11
  6217: 0804e919    48 FUNC    GLOBAL DEFAULT    1 osKernelInitialize
  6218: 08055a89    12 FUNC    GLOBAL DEFAULT    1 mbed_get_error_in_progres
  6219: 08062c05   220 FUNC    GLOBAL DEFAULT    1 __cxa_call_unexpected
  6220: 08064d8d    24 FUNC    GLOBAL HIDDEN     1 restore_core_regs
  6221: 2400107c     4 OBJECT  GLOBAL DEFAULT    4 _ZN10__cxxabiv119__termin
  6222: 0804cd85    20 FUNC    WEAK   DEFAULT    1 _ZN7arduino6USBCDC9AsyncW
  6223: 08051b69    28 FUNC    GLOBAL DEFAULT    1 tcp_seg_free
  6224: 0806f924    24 OBJECT  WEAK   DEFAULT    1 _ZTVN7arduino6USBCDC10Asy
  6225: 0805f291     2 FUNC    WEAK   DEFAULT    1 SPDIF_RX_IRQHandler
  6226: 0805f291     2 FUNC    WEAK   DEFAULT    1 OTG_FS_WKUP_IRQHandler
  6227: 08061f89   288 FUNC    WEAK   DEFAULT    1 hal_deepsleep
  6228: 08054eb9    56 FUNC    WEAK   DEFAULT    1 _ZN4mbed8internal8SysTime
  6229: 24011dfc     4 OBJECT  WEAK   DEFAULT    6 _ZGVNSt7__cxx118messagesI
  6230: 08043fad    20 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v113s
  6231: 0805f291     2 FUNC    WEAK   DEFAULT    1 DMA1_Stream5_IRQHandler
  6232: 08055151    62 FUNC    WEAK   DEFAULT    1 _ZN4mbed8internal8SysTime
  6233: 24011de4     4 OBJECT  WEAK   DEFAULT    6 _ZGVNSt7__cxx118numpunctI
  6234: 0804634f   332 FUNC    WEAK   DEFAULT    1 _ZN10clmdep_fmt8internal6
  6235: 08056225     4 FUNC    GLOBAL DEFAULT    1 _isatty
  6236: 0805ff99    60 FUNC    GLOBAL DEFAULT    1 _ZN8USBPhyHw7processEv
  6237: 08055d51    52 FUNC    GLOBAL DEFAULT    1 sleep_manager_unlock_deep
  6238: 0804e5cf     2 FUNC    WEAK   DEFAULT    1 EvrRtxThreadFlagsError
  6239: 080568f7    14 FUNC    GLOBAL DEFAULT    1 _ZN4rtos9SemaphoreD1Ev
  6240: 24011de0     4 OBJECT  WEAK   DEFAULT    6 _ZGVNSt7__cxx118time_getI
  6241: 0804c213    54 FUNC    GLOBAL DEFAULT    1 _ZN7arduino4UART3endEv
  6242: 0805f069   448 FUNC    GLOBAL DEFAULT    1 SetSysClock_PLL_HSE
  6243: 0804dd79     4 FUNC    GLOBAL DEFAULT    1 delay
  6244: 0805ec2d    16 FUNC    GLOBAL DEFAULT    1 USB_ReadDevAllOutEpInterr
  6245: 0806b67d   110 FUNC    GLOBAL DEFAULT    1 _vsnprintf_r
  6246: 0805b58d    38 FUNC    GLOBAL DEFAULT    1 HAL_PCDEx_ActivateLPM
  6247: 080406ad    90 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v16pa
  6248: 08052af5     8 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice19string_ise
  6249: 0805e69f   126 FUNC    GLOBAL DEFAULT    1 USB_ActivateEndpoint
  6250: 0804f041   128 FUNC    GLOBAL DEFAULT    1 osMessageQueuePut
  6251: 08044bc7    38 FUNC    WEAK   DEFAULT    1 _ZNSt6vectorIN14clmdep_ms
  6252: 08053841   188 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice10read_start
  6253: 080562c5    54 FUNC    GLOBAL DEFAULT    1 lseek
  6254: 08064655     4 FUNC    GLOBAL HIDDEN     1 _Unwind_GetCFA
  6255: 080520bf    46 FUNC    GLOBAL DEFAULT    1 _ZN4mbed10SerialBase6form
  6256: 08054989    26 FUNC    GLOBAL DEFAULT    1 ticker_set_handler
  6257: 08052951     8 FUNC    GLOBAL DEFAULT    1 _ZN14LinkedListBaseC1Ev
  6258: 0804cdc1    20 FUNC    WEAK   DEFAULT    1 _ZN7arduino6USBCDC10Async
  6259: 0804a835    40 FUNC    GLOBAL DEFAULT    1 mriBuffer_MatchesHexStrin
  6260: 0804fd11    88 FUNC    GLOBAL DEFAULT    1 osRtxThreadDispatch
  6261: 080527cd    10 FUNC    GLOBAL DEFAULT    1 _ZN7AsyncOp10_host_lockEP
  6262: 08054b69    16 FUNC    GLOBAL DEFAULT    1 _ZN4mbed19CriticalSection
  6263: 08048229    16 FUNC    WEAK   DEFAULT    1 _ZNSt15__allocated_ptrISa
  6264: 0804fd69    36 FUNC    GLOBAL DEFAULT    1 osRtxThreadWaitExit
  6265: 08067669   144 FUNC    GLOBAL DEFAULT    1 snprintf
  6266: 0805f291     2 FUNC    WEAK   DEFAULT    1 TIM15_IRQHandler
  6267: 0804bc6d    12 FUNC    GLOBAL DEFAULT    1 mriCore_GetSignalValue
  6268: 08050f21   124 FUNC    GLOBAL DEFAULT    1 _ZN10STM32_EMAC8link_outE
  6269: 080525fd    10 FUNC    GLOBAL DEFAULT    1 _ZN4mbed16UnbufferedSeria
  6270: 0804351d    34 FUNC    WEAK   DEFAULT    1 _ZN10ThreadList8allocateE
  6271: 080441b9    76 FUNC    GLOBAL DEFAULT    1 _ZN7arduino3RPC23rpmsg_re
  6272: 30040000    96 OBJECT  GLOBAL DEFAULT   10 DMARxDscrTab
  6273: 0804b6ed    64 FUNC    GLOBAL DEFAULT    1 mriContext_Get
  6274: 08064e71     0 FUNC    GLOBAL HIDDEN     1 __gnu_Unwind_Save_WMMXC
  6275: 08054d9f    48 FUNC    GLOBAL DEFAULT    1 _ZN4mbed6Stream5writeEPKv
  6276: 08072674    13 OBJECT  GLOBAL DEFAULT    1 _ZTSSt9bad_alloc
  6277: 0804d999     6 FUNC    GLOBAL DEFAULT    1 __cxa_pure_virtual
  6278: 0804bc9d    52 FUNC    GLOBAL DEFAULT    1 mriCore_SendPacketToGdb
  6279: 0804de95   140 FUNC    GLOBAL DEFAULT    1 _Z7pinModeh7PinMode
  6280: 0804dbbf    48 FUNC    GLOBAL DEFAULT    1 _ZN7arduino6String4copyEP
  6281: 08071168     8 OBJECT  GLOBAL DEFAULT    1 __stderr_name
  6282: 08055f29     4 FUNC    GLOBAL DEFAULT    1 __aeabi_atexit
  6283: 0805f291     2 FUNC    WEAK   DEFAULT    1 I2C1_ER_IRQHandler
  6284: 08055589    20 FUNC    GLOBAL DEFAULT    1 core_util_atomic_flag_tes
  6285: 080636fd    26 FUNC    WEAK   DEFAULT    1 _ZNSsC1EPKcjRKSaIcE
  6286: 080622a9    14 FUNC    GLOBAL DEFAULT    1 _ZNSt13bad_exceptionD0Ev
  6287: 0804a3e5    32 FUNC    GLOBAL DEFAULT    1 MAILBOX_Poll
  6288: 08062e09     8 FUNC    GLOBAL DEFAULT    1 __cxa_get_globals_fast
  6289: 08052f6d    76 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice6ep0_inEv
  6290: 0805f291     2 FUNC    WEAK   DEFAULT    1 UART8_IRQHandler
  6291: 0804bbd9    32 FUNC    GLOBAL DEFAULT    1 mriCore_InitBuffer
  6292: 08056861    14 FUNC    GLOBAL DEFAULT    1 _ZN4rtos5MutexD1Ev
  6293: 24011e34     4 OBJECT  WEAK   DEFAULT    6 _ZGVNSt8numpunctIcE2idE
  6294: 0805da3d    96 FUNC    GLOBAL DEFAULT    1 HAL_TIM_OC_Init
  6295: 08054d6d    18 FUNC    GLOBAL DEFAULT    1 _ZN4mbed8FilePath6isFileE
  6296: 2400f9c4     4 OBJECT  WEAK   DEFAULT    6 _ZGVZN4mbed33do_shared_ev
  6297: 08053215   180 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice23_control_s
  6298: 080587e9   100 FUNC    GLOBAL DEFAULT    1 HAL_ETH_WritePHYRegister
  6299: 080568f7    14 FUNC    GLOBAL DEFAULT    1 _ZN4rtos9SemaphoreD2Ev
  6300: 0804f4a1    48 FUNC    GLOBAL DEFAULT    1 osMutexAcquire
  6301: 080457cf    68 FUNC    WEAK   DEFAULT    1 _ZNSt6vectorIhSaIhEEC2ERK
  6302: 08055137    26 FUNC    WEAK   DEFAULT    1 _ZN4mbed8internal8SysTime
  6303: 0804c59f     6 FUNC    WEAK   DEFAULT    1 _ZThn1216_N7arduino9USBSe
  6304: 08056c7d    12 FUNC    GLOBAL DEFAULT    1 HAL_GetUIDw0
  6305: 08052863     2 FUNC    GLOBAL DEFAULT    1 _ZN16EndpointResolverD1Ev
  6306: 08050915    12 FUNC    GLOBAL DEFAULT    1 EvrRtxMutexError
  6307: 0804a129    16 FUNC    GLOBAL DEFAULT    1 metal_sys_init
  6308: 0805f291     2 FUNC    WEAK   DEFAULT    1 DMA1_Stream1_IRQHandler
  6309: 0804f789    80 FUNC    GLOBAL DEFAULT    1 osSemaphoreAcquire
  6310: 08065899   160 FUNC    GLOBAL DEFAULT    1 _malloc_trim_r
  6311: 24001aa0     0 NOTYPE  GLOBAL DEFAULT    5 __uninitialized_start
  6312: 08051a15   268 FUNC    GLOBAL DEFAULT    1 pbuf_alloc
  6313: 08050f9d    20 FUNC    GLOBAL DEFAULT    1 _ZNK10STM32_EMAC10get_ifn
  6314: 080560bb    54 FUNC    GLOBAL DEFAULT    1 read
  6315: 08049e79    36 FUNC    GLOBAL DEFAULT    1 virtqueue_disable_cb
  6316: 08042f6d    16 FUNC    GLOBAL DEFAULT    1 mriPlatform_SetProgramCou
  6317: 08063df9    22 FUNC    GLOBAL DEFAULT    1 _ZNKSt3_V214error_categor
  6318: 0804cdad    20 FUNC    WEAK   DEFAULT    1 _ZN7arduino6USBCDC10Async
  6319: 08052223    14 FUNC    GLOBAL DEFAULT    1 _ZN4mbed10SerialBase10_ba
  6320: 08052611    20 FUNC    WEAK   DEFAULT    1 _ZN4mbed16UnbufferedSeria
  6321: 08072778    12 OBJECT  GLOBAL DEFAULT    1 _ZTISt12length_error
  6322: 08067421    36 FUNC    GLOBAL DEFAULT    1 _sbrk_r
  6323: 08063369    24 FUNC    GLOBAL DEFAULT    1 _ZNK10__cxxabiv117__class
  6324: 2400f994    40 OBJECT  GLOBAL DEFAULT    6 _ZN4mbed3I2C6_mutexE
  6325: 08062269    48 FUNC    GLOBAL DEFAULT    1 restore_timer_ctx
  6326: 08057b35    88 FUNC    GLOBAL DEFAULT    1 HAL_MPU_ConfigRegion
  6327: 08064f15    34 FUNC    GLOBAL HIDDEN     1 _Unwind_Backtrace
  6328: 0805d4d9    48 FUNC    GLOBAL DEFAULT    1 HAL_RTC_WaitForSynchro
  6329: 08053e43     8 FUNC    GLOBAL DEFAULT    1 _ZN6events10EventQueue16d
  6330: 0806e66c    43 OBJECT  WEAK   DEFAULT    1 _ZTSN14clmdep_msgpack2v11
  6331: 0804e59d    48 FUNC    GLOBAL DEFAULT    1 osEventFlagsDelete
  6332: 08041461   236 FUNC    GLOBAL DEFAULT    1 _Z12my_can_writeP5can_sN4
  6333: 0804ab8d    84 FUNC    GLOBAL DEFAULT    1 mriHandleFileIOCommand
  6334: 08064775    42 FUNC    GLOBAL HIDDEN     1 _Unwind_VRS_Set
  6335: 08064b0d   638 FUNC    GLOBAL HIDDEN     1 _Unwind_VRS_Pop
  6336: 08052405    20 FUNC    GLOBAL DEFAULT    1 _ZN4mbed9TimerBaseD2Ev
  6337: 08054e01     4 FUNC    GLOBAL DEFAULT    1 _ZN4mbed6Stream4seekEli
  6338: 08071934   180 OBJECT  WEAK   DEFAULT    1 PinMap_UART_CTS
  6339: 24011cee     1 OBJECT  GLOBAL DEFAULT    6 lp_cmpok
  6340: 0806ec10    16 OBJECT  WEAK   DEFAULT    1 _ZTVN10clmdep_fmt17BasicM
  6341: 080591fd   120 FUNC    GLOBAL DEFAULT    1 HAL_FDCAN_ConfigFilter
  6342: 08060b95   320 FUNC    GLOBAL DEFAULT    1 i2c_frequency
  6343: 0804db7f    24 FUNC    GLOBAL DEFAULT    1 _ZN7arduino6String12chang
  6344: 0805e4ed    32 FUNC    GLOBAL DEFAULT    1 USB_FlushRxFifo
  6345: 08066161    74 FUNC    GLOBAL DEFAULT    1 _fwalk
  6346: 0804c525    28 FUNC    WEAK   DEFAULT    1 _ZN7arduino9USBSerial9ava
  6347: 0804ca6d    44 FUNC    GLOBAL DEFAULT    1 _ZN7arduino18PluggableUSB
  6348: 0805639f     4 FUNC    GLOBAL DEFAULT    1 _fstat
  6349: 24011e2c     4 OBJECT  WEAK   DEFAULT    6 _ZGVNSt7num_putIcSt19ostr
  6350: 08052a7b     2 FUNC    WEAK   DEFAULT    1 _ZN9USBDevice14callback_r
  6351: 08049ff1    60 FUNC    GLOBAL DEFAULT    1 metal_bus_find
  6352: 080544ed     6 FUNC    GLOBAL DEFAULT    1 gpio_init_in
  6353: 080609b5   212 FUNC    GLOBAL DEFAULT    1 i2c_compute_presc_scldel_
  6354: 0805ccf9    36 FUNC    GLOBAL DEFAULT    1 HAL_RCCEx_GetD3PCLK1Freq
  6355: 0805f291     2 FUNC    WEAK   DEFAULT    1 DFSDM1_FLT0_IRQHandler
  6356: 0804cbb1     4 FUNC    WEAK   DEFAULT    1 _ZN7arduino18PluggableUSB
  6357: 0805f291     2 FUNC    WEAK   DEFAULT    1 TIM8_UP_TIM13_IRQHandler
  6358: 080462a7   168 FUNC    WEAK   DEFAULT    1 _ZNSt8_Rb_treeIN10clmdep_
  6359: 08050fcd    30 FUNC    WEAK   DEFAULT    1 _ZN4mbed8CallbackIFvvEE11
  6360: 08071478   672 OBJECT  WEAK   DEFAULT    1 PinMap_ADC
  6361: 08055aa5    52 FUNC    WEAK   DEFAULT    1 mbed_error
  6362: 0805f291     2 FUNC    WEAK   DEFAULT    1 DMA2_Stream4_IRQHandler
  6363: 0805f291     2 FUNC    WEAK   DEFAULT    1 EXTI0_IRQHandler
  6364: 0804da55     6 FUNC    GLOBAL DEFAULT    1 _ZN7arduino5Print5printEc
  6365: 0806b855   204 FUNC    GLOBAL DEFAULT    1 __swsetup_r
  6366: 0805e023   148 FUNC    GLOBAL DEFAULT    1 UART_WaitOnFlagUntilTimeo
  6367: 080602a1     4 FUNC    GLOBAL DEFAULT    1 FDCAN2_IT1_IRQHandler
  6368: 0805632d    48 FUNC    GLOBAL DEFAULT    1 _exit
  6369: 0805674b    18 FUNC    GLOBAL DEFAULT    1 _ZN4rtos10EventFlags12wai
  6370: 0805f291     2 FUNC    WEAK   DEFAULT    1 OTG_HS_EP1_IN_IRQHandler
  6371: 08051589    60 FUNC    GLOBAL DEFAULT    1 thumb2_memcpy
  6372: 08043f99    20 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v112u
  6373: 0806e7e0    12 OBJECT  WEAK   DEFAULT    1 _ZTIN14clmdep_msgpack2v11
  6374: 0804e9f9    44 FUNC    GLOBAL DEFAULT    1 osKernelResume
  6375: 080592cf    40 FUNC    GLOBAL DEFAULT    1 HAL_FDCAN_EnableTimestamp
  6376: 0806c79d   100 FUNC    GLOBAL DEFAULT    1 _fputwc_r
  6377: 080637a9    18 FUNC    GLOBAL DEFAULT    1 _ZNSt12__cow_stringC1EPKc
  6378: 0805f291     2 FUNC    WEAK   DEFAULT    1 DebugMon_Handler
  6379: 08044b27    50 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v26de
  6380: 08062af9    46 FUNC    GLOBAL DEFAULT    1 __cxa_allocate_exception
  6381: 080526b9     8 FUNC    GLOBAL DEFAULT    1 _ZThn124_N4mbed16Unbuffer
  6382: 0805f291     2 FUNC    WEAK   DEFAULT    1 DMA2_Stream3_IRQHandler
  6383: 0805f291     2 FUNC    WEAK   DEFAULT    1 OTG_HS_IRQHandler
  6384: 0805675d     4 FUNC    GLOBAL DEFAULT    1 _ZN4rtos10EventFlags8wait
  6385: 0804a3a5    64 FUNC    GLOBAL DEFAULT    1 MAILBOX_Init
  6386: 0805e481    12 FUNC    GLOBAL DEFAULT    1 USB_EnableGlobalInt
  6387: 08060a89   152 FUNC    GLOBAL DEFAULT    1 i2c_compute_timing
  6388: 08043125    88 FUNC    GLOBAL DEFAULT    1 mriPlatform_WriteTRespons
  6389: 0804c9ed   128 FUNC    GLOBAL DEFAULT    1 _ZN7arduino18PluggableUSB
  6390: 080701a8    12 OBJECT  GLOBAL DEFAULT    1 memp_TCPIP_MSG_API
  6391: 0804d551     2 FUNC    WEAK   DEFAULT    1 _ZN7arduino9USBSerial3end
  6392: 0804d07d   104 FUNC    GLOBAL DEFAULT    1 _ZN7arduino6USBCDCC1EP6US
  6393: 08053edf    86 FUNC    GLOBAL DEFAULT    1 equeue_destroy
  6394: 08052855    14 FUNC    GLOBAL DEFAULT    1 _ZN16EndpointResolverC2EP
  6395: 080445f1     8 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v16de
  6396: 080516f9    52 FUNC    GLOBAL DEFAULT    1 tcpip_try_callback
  6397: 0805427d     6 FUNC    GLOBAL DEFAULT    1 equeue_event_period
  6398: 0805274d    24 FUNC    GLOBAL DEFAULT    1 _ZN7AsyncOpC1Ev
  6399: 08042f95    28 FUNC    GLOBAL DEFAULT    1 mriPlatform_WasMemoryFaul
  6400: 080525b1     4 FUNC    WEAK   DEFAULT    1 _ZN4mbed16UnbufferedSeria
  6401: 08065289    18 FUNC    GLOBAL HIDDEN     1 _Unwind_GetLanguageSpecif
  6402: 24011dec     4 OBJECT  WEAK   DEFAULT    6 _ZGVNSt7__cxx119money_get
  6403: 0804b72d    60 FUNC    GLOBAL DEFAULT    1 mriContext_Set
  6404: 0804280f    14 FUNC    GLOBAL DEFAULT    1 _ZN7arduino21UsbDebugComm
  6405: 24011ea8     1 OBJECT  GLOBAL DEFAULT    6 __lock___malloc_recursive
  6406: 08056af9    60 FUNC    GLOBAL DEFAULT    1 _ZN4rtos6ThreadD2Ev
  6407: 080507a7     4 FUNC    GLOBAL DEFAULT    1 mbed_rtos_init
  6408: 0805172d   256 FUNC    GLOBAL DEFAULT    1 mem_free
  6409: 08051c2d    20 FUNC    WEAK   DEFAULT    1 _ZN4mbed8AnalogIn4lockEv
  6410: 0805f291     2 FUNC    WEAK   DEFAULT    1 TIM1_UP_IRQHandler
  6411: 08045c11    32 FUNC    WEAK   DEFAULT    1 _ZN10clmdep_fmt8internal1
  6412: 08042f05    92 FUNC    GLOBAL DEFAULT    1 mriPlatform_LeavingDebugg
  6413: 240108f0     4 OBJECT  GLOBAL DEFAULT    6 mbed_heap_size
  6414: 08053b4d    64 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice26_request_s
  6415: 08059c4d     2 FUNC    WEAK   DEFAULT    1 HAL_I2C_MspInit
  6416: 0805611d    44 FUNC    GLOBAL DEFAULT    1 fdopen
  6417: 0806e7b4    43 OBJECT  WEAK   DEFAULT    1 _ZTSN14clmdep_msgpack2v11
  6418: 080620d9   220 FUNC    GLOBAL DEFAULT    1 init_32bit_timer
  6419: 08057af9    28 FUNC    GLOBAL DEFAULT    1 HAL_MPU_Disable
  6420: 0804c78b    26 FUNC    GLOBAL DEFAULT    1 _ZN7arduino18PluggableUSB
  6421: 0804c775    22 FUNC    GLOBAL DEFAULT    1 _ZN7arduino18PluggableUSB
  6422: 0805f479   428 FUNC    GLOBAL DEFAULT    1 adc_read
  6423: 0804875b   236 FUNC    WEAK   DEFAULT    1 _ZNK14clmdep_msgpack2v17a
  6424: 08067445    16 FUNC    GLOBAL DEFAULT    1 setbuf
  6425: 0804d545     6 FUNC    WEAK   DEFAULT    1 _ZN7arduino9USBSerial5beg
  6426: 0804b6c7     6 FUNC    GLOBAL DEFAULT    1 mriContext_Init
  6427: 080434e9     6 FUNC    GLOBAL DEFAULT    1 mriPlatform_GetTargetXmlS
  6428: 08054d9b     4 FUNC    GLOBAL DEFAULT    1 _ZN4mbed6Stream5closeEv
  6429: 0804474d    92 FUNC    WEAK   DEFAULT    1 _ZN7arduino3RPCD1Ev
  6430: 080592a7    40 FUNC    GLOBAL DEFAULT    1 HAL_FDCAN_ConfigTimestamp
  6431: 08059639     2 FUNC    WEAK   DEFAULT    1 HAL_FDCAN_ClockCalibratio
  6432: 0805f291     2 FUNC    WEAK   DEFAULT    1 COMP1_IRQHandler
  6433: 08046247    96 FUNC    WEAK   DEFAULT    1 _ZN10clmdep_fmt11BasicWri
  6434: 2400f378   131 OBJECT  GLOBAL DEFAULT    6 memp_memory_TCPIP_MSG_API
  6435: 0804430d    60 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v14zo
  6436: 0804c1b5    18 FUNC    GLOBAL DEFAULT    1 _ZN7arduino4UART5flushEv
  6437: 2400f1d2   163 OBJECT  GLOBAL DEFAULT    6 memp_memory_REASSDATA_bas
  6438: 08045e59    40 FUNC    WEAK   DEFAULT    1 _ZN10clmdep_fmt8internal1
  6439: 0804de75    30 FUNC    WEAK   DEFAULT    1 _ZN4mbed9DigitalInC1E7Pin
  6440: 0804cbd5   354 FUNC    GLOBAL DEFAULT    1 _ZN7arduino6USBCDC18confi
  6441: 08054f61    16 FUNC    WEAK   DEFAULT    1 _ZN4mbed8internal8SysTime
  6442: 0805ebed    28 FUNC    GLOBAL DEFAULT    1 USB_DevConnect
  6443: 24011dc8     4 OBJECT  WEAK   DEFAULT    6 _ZGVNSt9money_putIwSt19os
  6444: 0804409d    20 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v117b
  6445: 080624e9  1250 FUNC    GLOBAL DEFAULT    1 __gxx_personality_v0
  6446: 08045435   204 FUNC    WEAK   DEFAULT    1 _ZN7arduino3RPCC2Ev
  6447: 24005c80 32768 OBJECT  GLOBAL DEFAULT    6 _main_stack
  6448: 08070280    24 OBJECT  WEAK   DEFAULT    1 _ZTVN4mbed8AnalogInE
  6449: 24011df0     4 OBJECT  WEAK   DEFAULT    6 _ZGVNSt7__cxx1110moneypun
  6450: 24011d78     4 OBJECT  GLOBAL DEFAULT    6 timer_dier_reg
  6451: 24001aa0     0 NOTYPE  GLOBAL DEFAULT    6 __bss_start__
  6452: 0804e181    16 FUNC    GLOBAL DEFAULT    1 SysTick_Handler
  6453: 0804cdfd   136 FUNC    GLOBAL DEFAULT    1 _ZN7arduino6USBCDC4initER
  6454: 2400f784   259 OBJECT  GLOBAL DEFAULT    6 memp_memory_TCP_SEG_base
  6455: 0805eaa5    64 FUNC    GLOBAL DEFAULT    1 USB_ReadPacket
  6456: 0804d1bd   112 FUNC    GLOBAL DEFAULT    1 _ZN7arduino6USBCDC16callb
  6457: 08060eb9   160 FUNC    GLOBAL DEFAULT    1 i2c_write
  6458: 08043a8d    20 FUNC    GLOBAL DEFAULT    1 mriPlatform_CommSendChar
  6459: 0804c265    44 FUNC    GLOBAL DEFAULT    1 _ZN7arduino4UARTcvbEv
  6460: 080521ad    92 FUNC    GLOBAL DEFAULT    1 _ZN4mbed10SerialBaseD1Ev
  6461: 08051c87    10 FUNC    WEAK   DEFAULT    1 _ZN4mbed10FileHandle6rewi
  6462: 08060291     4 FUNC    GLOBAL DEFAULT    1 FDCAN1_IT1_IRQHandler
  6463: 0804db45    20 FUNC    GLOBAL DEFAULT    1 _ZN7arduino5Print7println
  6464: 0805bd55   588 FUNC    GLOBAL DEFAULT    1 HAL_RCC_ClockConfig
  6465: 0805c009    36 FUNC    GLOBAL DEFAULT    1 HAL_RCC_GetPCLK2Freq
  6466: 08064ea9    34 FUNC    GLOBAL HIDDEN     1 _Unwind_Resume
  6467: 24011d98    16 OBJECT  WEAK   DEFAULT    6 _ZNSs4_Rep20_S_empty_rep_
  6468: 0804c62d    84 FUNC    GLOBAL DEFAULT    1 _ZN7arduino4UART4readEv
  6469: 0805b5b3     2 FUNC    WEAK   DEFAULT    1 HAL_PCDEx_LPM_Callback
  6470: 080420c5    10 FUNC    GLOBAL DEFAULT    1 _Z10prepare_IDt
  6471: 0804e099    62 FUNC    GLOBAL DEFAULT    1 osSignalWait
  6472: 0805f291     2 FUNC    WEAK   DEFAULT    1 HSEM2_IRQHandler
  6473: 0804ab69    36 FUNC    GLOBAL DEFAULT    1 mriCmd_HandleDetachComman
  6474: 0804d543     2 FUNC    WEAK   DEFAULT    1 _ZN4mbed6Stream6unlockEv
  6475: 08057321   180 FUNC    GLOBAL DEFAULT    1 ADC_Enable
  6476: 240022c8  1816 OBJECT  GLOBAL DEFAULT    6 loiTruck
  6477: 08056701    20 FUNC    GLOBAL DEFAULT    1 _ZN4rtos10EventFlagsC1Ev
  6478: 080576a1   536 FUNC    GLOBAL DEFAULT    1 HAL_ADC_Init
  6479: 080569ed   200 FUNC    GLOBAL DEFAULT    1 _ZN4rtos6Thread5startEN4m
  6480: 08043fc1    20 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v113s
  6481: 08068051  5088 FUNC    GLOBAL DEFAULT    1 _svfprintf_r
  6482: 08042ac5    14 FUNC    GLOBAL DEFAULT    1 _ZN7arduino21UsbDebugComm
  6483: 0804bc21    28 FUNC    GLOBAL DEFAULT    1 mriCore_SetSingleStepping
  6484: 080717a8    84 OBJECT  WEAK   DEFAULT    1 PinMap_CAN_TD
  6485: 0805821b   152 FUNC    GLOBAL DEFAULT    1 HAL_ETH_Start_IT
  6486: 08042fcd    56 FUNC    GLOBAL DEFAULT    1 mriPlatform_AdvanceProgra
  6487: 08043e6b     2 FUNC    WEAK   DEFAULT    1 _ZN7arduino3RPC5flushEv
  6488: 0806e2a8    36 OBJECT  GLOBAL DEFAULT    1 _ZTVN7arduino21UsbDebugCo
  6489: 0805a9c1    48 FUNC    GLOBAL DEFAULT    1 HAL_I2CEx_EnableFastModeP
  6490: 0805c02d   236 FUNC    GLOBAL DEFAULT    1 HAL_RCC_GetOscConfig
  6491: 080420cf    76 FUNC    GLOBAL DEFAULT    1 _Z18prepare_Command_IDbP8
  6492: 08061b3d   116 FUNC    GLOBAL DEFAULT    1 serial_format
  6493: 080553a9    82 FUNC    GLOBAL DEFAULT    1 __wrap__realloc_r
  6494: 08048849    52 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v14ty
  6495: 0805f291     2 FUNC    WEAK   DEFAULT    1 DMA1_Stream0_IRQHandler
  6496: 0805fa97     2 FUNC    GLOBAL DEFAULT    1 _ZN8USBPhyHwD1Ev
  6497: 08053549   112 FUNC    GLOBAL DEFAULT    1 _ZN9USBDeviceC2EP6USBPhyt
  6498: 08050645    60 FUNC    WEAK   DEFAULT    1 osRtxTimerThread
  6499: 08066b69   198 FUNC    GLOBAL DEFAULT    1 memmove
  6500: 24003e04  1080 OBJECT  GLOBAL DEFAULT    6 SerialRPC
  6501: 08047371   384 FUNC    WEAK   DEFAULT    1 _ZN10clmdep_fmt11BasicWri
  6502: 08051325   204 FUNC    GLOBAL DEFAULT    1 _ZN10STM32_EMAC8power_upE
  6503: 0805f291     2 FUNC    WEAK   DEFAULT    1 EXTI3_IRQHandler
  6504: 08045e19    64 FUNC    WEAK   DEFAULT    1 _ZN10clmdep_fmt8internal1
  6505: 0805182d   208 FUNC    GLOBAL DEFAULT    1 mem_malloc
  6506: 080725c0    36 OBJECT  GLOBAL DEFAULT    1 _ZTSN10__cxxabiv119__fore
  6507: 0805f291     2 FUNC    WEAK   DEFAULT    1 LPUART1_IRQHandler
  6508: 0806541d    16 FUNC    GLOBAL DEFAULT    1 fclose
  6509: 080495d5    36 FUNC    GLOBAL DEFAULT    1 rpmsg_send_offchannel_raw
  6510: 08054571    72 FUNC    GLOBAL DEFAULT    1 pinmap_pinout
  6511: 08052099    38 FUNC    GLOBAL DEFAULT    1 _ZN4mbed10SerialBase4baud
  6512: 080633f1   362 FUNC    GLOBAL DEFAULT    1 _ZSt29_Rb_tree_insert_and
  6513: 080407fb   268 FUNC    WEAK   DEFAULT    1 _ZN7arduino3RPC4callIJiiE
  6514: 08054409     2 FUNC    WEAK   DEFAULT    1 gpio_free
  6515: 0804c0d1    20 FUNC    WEAK   DEFAULT    1 _ZN4mbed3I2CD0Ev
  6516: 0805cd1d   340 FUNC    GLOBAL DEFAULT    1 HAL_RCCEx_GetPLL2ClockFre
  6517: 08050fed    48 FUNC    WEAK   DEFAULT    1 _ZN10STM32_EMACD1Ev
  6518: 0804455d    96 FUNC    WEAK   DEFAULT    1 _ZN4rtos6ThreadC1E12osPri
  6519: 080652ad     2 FUNC    WEAK   HIDDEN     1 __aeabi_ldiv0
  6520: 08053f35   112 FUNC    GLOBAL DEFAULT    1 equeue_alloc
  6521: 24011e24     4 OBJECT  WEAK   DEFAULT    6 _ZGVNSt8time_putIcSt19ost
  6522: 080720a4   124 OBJECT  GLOBAL DEFAULT    1 _ZTV8USBPhyHw
  6523: 0806625d    28 FUNC    GLOBAL DEFAULT    1 __locale_mb_cur_max
  6524: 080727c8    20 OBJECT  GLOBAL DEFAULT    1 _ZTVSt11logic_error
  6525: 080440c5    20 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v111p
  6526: 08043fd5    20 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v119d
  6527: 08049431   216 FUNC    GLOBAL DEFAULT    1 rproc_virtio_create_vdev
  6528: 0804a461    12 FUNC    GLOBAL DEFAULT    1 mriBuffer_SetEndOfBuffer
  6529: 08056eb9     6 FUNC    GLOBAL DEFAULT    1 HAL_ADC_GetValue
  6530: 08054555     8 FUNC    GLOBAL DEFAULT    1 get_lp_ticker_data
  6531: 0805644d    60 FUNC    GLOBAL DEFAULT    1 _ZN4mbed17remove_filehand
  6532: 08049f51    64 FUNC    GLOBAL DEFAULT    1 metal_generic_dev_open
  6533: 08052d8f    40 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice20_decode_se
  6534: 0804461d   136 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v28un
  6535: 08066201    72 FUNC    GLOBAL DEFAULT    1 __libc_init_array
  6536: 24011e7c    32 OBJECT  GLOBAL DEFAULT    6 _metal
  6537: 08072938    20 OBJECT  GLOBAL DEFAULT    1 _ZTVSt20bad_array_new_len
  6538: 08055b01    48 FUNC    GLOBAL DEFAULT    1 mbed_mem_trace_realloc
  6539: 0805f291     2 FUNC    WEAK   DEFAULT    1 HRTIM1_FLT_IRQHandler
  6540: 080554dd   140 FUNC    GLOBAL DEFAULT    1 free_wrapper
  6541: 0804577d     6 FUNC    WEAK   DEFAULT    1 _ZN7arduino14SerialRPCCla
  6542: 08052a03    36 FUNC    GLOBAL DEFAULT    1 _ZN17OperationListBase3ad
  6543: 080520ed    34 FUNC    GLOBAL DEFAULT    1 _ZN4mbed10SerialBase8read
  6544: 08056b35    20 FUNC    GLOBAL DEFAULT    1 _ZN4rtos6ThreadD0Ev
  6545: 080652fd    66 FUNC    GLOBAL DEFAULT    1 bsearch
  6546: 08050875   124 FUNC    GLOBAL DEFAULT    1 osRtxErrorNotify
  6547: 080726a4    37 OBJECT  GLOBAL DEFAULT    1 _ZTSN10__cxxabiv120__si_c
  6548: 24011e0c     4 OBJECT  WEAK   DEFAULT    6 _ZGVNSt7__cxx119money_get
  6549: 080523e5    32 FUNC    GLOBAL DEFAULT    1 _ZN4mbed6TickerC1Ev
  6550: 0805f291     2 FUNC    WEAK   DEFAULT    1 FDCAN_CAL_IRQHandler
  6551: 0805d6f3   156 FUNC    GLOBAL DEFAULT    1 HAL_RTC_SetDate
  6552: 2400f14f   131 OBJECT  GLOBAL DEFAULT    6 memp_memory_PBUF_base
  6553: 08065889    16 FUNC    GLOBAL DEFAULT    1 fopen
  6554: 0804e9d1    40 FUNC    GLOBAL DEFAULT    1 osKernelSuspend
  6555: 08059649     2 FUNC    WEAK   DEFAULT    1 HAL_FDCAN_ErrorStatusCall
  6556: 0804d2e1    48 FUNC    GLOBAL DEFAULT    1 _ZN7arduino6USBCDC15_send
  6557: 0804cdad    20 FUNC    WEAK   DEFAULT    1 _ZN7arduino6USBCDC10Async
  6558: 08072684    20 OBJECT  GLOBAL DEFAULT    1 _ZTVSt9bad_alloc
  6559: 08070190    12 OBJECT  GLOBAL DEFAULT    1 memp_REASSDATA
  6560: 08052405    20 FUNC    GLOBAL DEFAULT    1 _ZN4mbed9TimerBaseD1Ev
  6561: 0804c7ad    28 FUNC    GLOBAL DEFAULT    1 _ZN7arduino18PluggableUSB
  6562: 0804e0d9   152 FUNC    GLOBAL DEFAULT    1 SVC_Handler
  6563: 0804c3d1     6 FUNC    WEAK   DEFAULT    1 _ZThn1216_N7arduino9USBSe
  6564: 0805370d    74 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice20_request_s
  6565: 0804eb65    52 FUNC    GLOBAL DEFAULT    1 osRtxMemoryPoolAlloc
  6566: 080542dd     4 FUNC    GLOBAL DEFAULT    1 equeue_sema_destroy
  6567: 0804bc11    16 FUNC    GLOBAL DEFAULT    1 mriCore_RequestResetOnNex
  6568: 08042df5    68 FUNC    GLOBAL DEFAULT    1 mriCortexMSetPriority
  6569: 08054283     6 FUNC    GLOBAL DEFAULT    1 equeue_event_dtor
  6570: 08049e03   118 FUNC    GLOBAL DEFAULT    1 virtqueue_get_buffer
  6571: 08054d9b     4 FUNC    GLOBAL DEFAULT    1 _ZN4mbed6Stream4syncEv
  6572: 08065e65   764 FUNC    GLOBAL DEFAULT    1 __sfvwrite_r
  6573: 0804f011    48 FUNC    GLOBAL DEFAULT    1 osMessageQueueNew
  6574: 08050a71    10 FUNC    WEAK   DEFAULT    1 _ZN26FunctionPointerWithC
  6575: 0804d555     2 FUNC    WEAK   DEFAULT    1 _ZN7arduino9USBSerial5flu
  6576: 08050aa5    24 FUNC    WEAK   DEFAULT    1 _ZN4UUIDC1Et
  6577: 08055d99   104 FUNC    GLOBAL DEFAULT    1 sleep_manager_sleep_auto
  6578: 0804e5d1     2 FUNC    WEAK   DEFAULT    1 EvrRtxDelayError
  6579: 080460e7    14 FUNC    WEAK   DEFAULT    1 _ZNSt8_Rb_treeIN10clmdep_
  6580: 0805ef61   148 FUNC    GLOBAL DEFAULT    1 SDMMC1_IRQHandler
  6581: 0804a309   114 FUNC    GLOBAL DEFAULT    1 metal_io_block_set
  6582: 0805f291     2 FUNC    WEAK   DEFAULT    1 BDMA_Channel3_IRQHandler
  6583: 080568a5    16 FUNC    GLOBAL DEFAULT    1 _ZN4rtos9SemaphoreC2El
  6584: 0806c98d    94 FUNC    GLOBAL DEFAULT    1 __lo0bits
  6585: 0805fc45    36 FUNC    GLOBAL DEFAULT    1 _ZN8USBPhyHw13endpoint_re
  6586: 08063be5    20 FUNC    GLOBAL DEFAULT    1 _ZNSt20bad_array_new_leng
  6587: 08043c35     4 FUNC    GLOBAL DEFAULT    1 mriPlatform_RtosIsSetThre
  6588: 080526dd    44 FUNC    GLOBAL DEFAULT    1 _ZN4mbed16UnbufferedSeria
  6589: 0805d58d   140 FUNC    GLOBAL DEFAULT    1 HAL_RTC_Init
  6590: 08063ba1    28 FUNC    GLOBAL DEFAULT    1 _ZNSt17bad_function_callD
  6591: 08074b94     0 NOTYPE  GLOBAL DEFAULT    3 __exidx_end
  6592: 24011e38     4 OBJECT  WEAK   DEFAULT    6 _ZGVNSt9money_putIcSt19os
  6593: 08044c09   104 FUNC    WEAK   DEFAULT    1 _ZNSt6vectorIPN14clmdep_m
  6594: 2400e56c  3043 OBJECT  GLOBAL DEFAULT    6 memp_memory_PBUF_POOL_bas
  6595: 2400e239   819 OBJECT  GLOBAL DEFAULT    6 memp_memory_NETCONN_base
  6596: 08059655   700 FUNC    GLOBAL DEFAULT    1 HAL_FDCAN_IRQHandler
  6597: 08054b59    16 FUNC    GLOBAL DEFAULT    1 _ZN10CThunkBase11cthunk_f
  6598: 080485cd    34 FUNC    GLOBAL DEFAULT    1 _ZN3rpc6detail10dispatche
  6599: 08055ead    48 FUNC    GLOBAL DEFAULT    1 _ZN12DirectSerialC1ERK15s
  6600: 080589f1   120 FUNC    GLOBAL DEFAULT    1 HAL_ETH_SetMDIOClockRange
  6601: 08072a80   257 OBJECT  GLOBAL DEFAULT    1 _ctype_
  6602: 080604a1     8 FUNC    GLOBAL DEFAULT    1 gpio_mode
  6603: 0804d603    58 FUNC    WEAK   DEFAULT    1 _ZN7arduino9USBSerial19li
  6604: 08054f33    14 FUNC    WEAK   DEFAULT    1 _ZNK4mbed8internal8SysTim
  6605: 08043975   208 FUNC    GLOBAL DEFAULT    1 mriPlatform_Init
  6606: 24011dc0     4 OBJECT  WEAK   DEFAULT    6 _ZGVNSt7num_getIwSt19istr
  6607: 08058623     2 FUNC    WEAK   DEFAULT    1 HAL_ETH_PMTCallback
  6608: 0804cdd5    20 FUNC    WEAK   DEFAULT    1 _ZN7arduino6USBCDC9AsyncR
  6609: 08048cc3   142 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v16pa
  6610: 0806fff8    12 OBJECT  WEAK   DEFAULT    1 _ZZN4mbed8CallbackIFvvEE8
  6611: 08051bf9     2 FUNC    WEAK   DEFAULT    1 _ZN4mbed8AnalogInD1Ev
  6612: 080542e1     6 FUNC    GLOBAL DEFAULT    1 equeue_sema_signal
  6613: 0806f1fc    34 OBJECT  WEAK   DEFAULT    1 _ZTSN14clmdep_msgpack2v11
  6614: 0804ae41   508 FUNC    GLOBAL DEFAULT    1 mriCmd_HandleQueryCommand
  6615: 0804dacb    68 FUNC    GLOBAL DEFAULT    1 _ZN7arduino5Print5printEl
  6616: 08051c09    34 FUNC    GLOBAL DEFAULT    1 _ZN4mbed8AnalogIn8read_u1
  6617: 0805eca9    76 FUNC    GLOBAL DEFAULT    1 USB_EP0_OutStart
  6618: 08051699    52 FUNC    GLOBAL DEFAULT    1 sys_arch_protect
  6619: 2407fc00     0 NOTYPE  GLOBAL DEFAULT  ABS __StackLimit
  6620: 08061389     4 FUNC    GLOBAL DEFAULT    1 lp_ticker_free
  6621: 08055f37     8 FUNC    GLOBAL DEFAULT    1 __malloc_lock
  6622: 0804a08d    56 FUNC    GLOBAL DEFAULT    1 metal_device_open
  6623: 0804a523    14 FUNC    GLOBAL DEFAULT    1 mriBuffer_OverrunDetected
  6624: 24011dbc     4 OBJECT  WEAK   DEFAULT    6 _ZGVNSt7num_putIwSt19ostr
  6625: 080564dd    44 FUNC    GLOBAL DEFAULT    1 _ZN4mbed10bind_to_fdEPNS_
  6626: 08052709    66 FUNC    GLOBAL DEFAULT    1 _ZN7AsyncOp8completeEv
  6627: 08056715    12 FUNC    GLOBAL DEFAULT    1 _ZN4rtos10EventFlagsC2EPK
  6628: 0805f291     2 FUNC    WEAK   DEFAULT    1 BDMA_Channel2_IRQHandler
  6629: 0805f291     2 FUNC    WEAK   DEFAULT    1 USART6_IRQHandler
  6630: 08049e9d    94 FUNC    GLOBAL DEFAULT    1 virtqueue_create
  6631: 08054e05     2 FUNC    GLOBAL DEFAULT    1 _ZN4mbed6Stream6rewindEv
  6632: 080656e5   164 FUNC    GLOBAL DEFAULT    1 __sfp
  6633: 0804cfc5   184 FUNC    GLOBAL DEFAULT    1 _ZN7arduino6USBCDC26callb
  6634: 2400f968     4 OBJECT  GLOBAL DEFAULT    6 tcp_active_pcbs
  6635: 08045813    16 FUNC    WEAK   DEFAULT    1 _ZNSt12_Vector_baseIhSaIh
  6636: 0804d5fb     8 FUNC    GLOBAL DEFAULT    1 _ZThn1192_N7arduino9USBSe
  6637: 08054b8d    68 FUNC    GLOBAL DEFAULT    1 _ZN4mbed8FileBaseC2EPKcNS
  6638: 0804a02d    96 FUNC    GLOBAL DEFAULT    1 metal_bus_register
  6639: 24011e08     4 OBJECT  WEAK   DEFAULT    6 _ZGVNSt7__cxx119money_put
  6640: 08051241    22 FUNC    GLOBAL DEFAULT    1 mbed_mac_address
  6641: 080555e5    28 FUNC    GLOBAL DEFAULT    1 core_util_atomic_load_u64
  6642: 0806f22c    28 OBJECT  WEAK   DEFAULT    1 _ZTSN3rpc6detail12client_
  6643: 0804b769    74 FUNC    GLOBAL DEFAULT    1 mriContext_CopyToBuffer
  6644: 080485ef    30 FUNC    WEAK   DEFAULT    1 _ZNSt19_Sp_counted_delete
  6645: 0805f291     2 FUNC    WEAK   DEFAULT    1 USART2_IRQHandler
  6646: 08055bd1    36 FUNC    GLOBAL DEFAULT    1 _ZN4mbed8internal13init_o
  6647: 0804a735    88 FUNC    GLOBAL DEFAULT    1 mriBuffer_WriteUIntegerAs
  6648: 080630bd    54 FUNC    GLOBAL DEFAULT    1 __cxa_throw
  6649: 0804c399    28 FUNC    WEAK   DEFAULT    1 _Z19digitalPinToPinNameh
  6650: 0804d71d   200 FUNC    GLOBAL DEFAULT    1 _ZN7arduino9USBSerialC1Eb
  6651: 0804d07d   104 FUNC    GLOBAL DEFAULT    1 _ZN7arduino6USBCDCC2EP6US
  6652: 080457cf    68 FUNC    WEAK   DEFAULT    1 _ZNSt6vectorIhSaIhEEC1ERK
  6653: 08042451    56 FUNC    GLOBAL DEFAULT    1 _Z18append_Linked_ListPP3
  6654: 08044e2d  1248 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v26de
  6655: 080551c1     6 FUNC    GLOBAL DEFAULT    1 BusFault_Handler
  6656: 08052bd9   100 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice2inEh
  6657: 08046c31  1060 FUNC    WEAK   DEFAULT    1 _ZN10clmdep_fmt14BasicFor
  6658: 0805f291     2 FUNC    WEAK   DEFAULT    1 RTC_WKUP_IRQHandler
  6659: 0805596d     2 FUNC    WEAK   DEFAULT    1 mbed_error_hook
  6660: 08064721     2 FUNC    GLOBAL HIDDEN     1 _Unwind_Complete
  6661: 080563a5    48 FUNC    GLOBAL DEFAULT    1 __cxa_guard_abort
  6662: 0806ccd1   236 FUNC    GLOBAL DEFAULT    1 __mdiff
  6663: 08047919   428 FUNC    WEAK   DEFAULT    1 _ZN10clmdep_fmt11BasicWri
  6664: 080629d5    20 FUNC    GLOBAL DEFAULT    1 _ZNSt8bad_castD1Ev
  6665: 0805b39b    72 FUNC    GLOBAL DEFAULT    1 HAL_PCD_EP_Receive
  6666: 08052791    60 FUNC    GLOBAL DEFAULT    1 _ZN7AsyncOp6_abortEb
  6667: 08056085    54 FUNC    GLOBAL DEFAULT    1 write
  6668: 24005410     8 OBJECT  GLOBAL DEFAULT    6 _ZN7arduino11INADDR_NONEE
  6669: 24011df4     4 OBJECT  WEAK   DEFAULT    6 _ZGVNSt7__cxx1110moneypun
  6670: 0804d53b     4 FUNC    WEAK   DEFAULT    1 _ZNK4mbed10FileHandle4pol
  6671: 08051e95    20 FUNC    GLOBAL DEFAULT    1 _ZN4mbed3I2C4lockEv
  6672: 2400dc80    36 OBJECT  GLOBAL DEFAULT    6 _main_thread_attr
  6673: 08055601   164 FUNC    WEAK   DEFAULT    1 mbed_die
  6674: 08062fb1   112 FUNC    GLOBAL DEFAULT    1 __gnu_end_cleanup
  6675: 0804a293   118 FUNC    GLOBAL DEFAULT    1 metal_io_block_write
  6676: 08053eb9    38 FUNC    GLOBAL DEFAULT    1 equeue_create
  6677: 08063309    28 FUNC    GLOBAL DEFAULT    1 _ZN10__cxxabiv117__class_
  6678: 0806080b    70 FUNC    GLOBAL DEFAULT    1 HAL_I2C_SlaveRxCpltCallba
  6679: 080529d3    48 FUNC    GLOBAL DEFAULT    1 _ZN17OperationListBase7pr
  6680: 080506c9    92 FUNC    GLOBAL DEFAULT    1 mbed_toolchain_init
  6681: 080513f1    12 FUNC    GLOBAL DEFAULT    1 _ZNK10STM32_EMAC10get_hwa
  6682: 24001aa0     0 NOTYPE  GLOBAL DEFAULT    6 _sbss
  6683: 08067455   384 FUNC    GLOBAL DEFAULT    1 setvbuf
  6684: 0806ebbd    28 OBJECT  WEAK   DEFAULT    1 _ZTSN10clmdep_fmt11Format
  6685: 08054bd1   100 FUNC    GLOBAL DEFAULT    1 _ZN4mbed8FileBaseD1Ev
  6686: 08055e15     2 FUNC    WEAK   DEFAULT    1 _ZN12DirectSerialD2Ev
  6687: 08053b1f    46 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice20_request_s
  6688: 0804cb79    16 FUNC    GLOBAL DEFAULT    1 _ZN7arduino8internal18Plu
  6689: 08052933    30 FUNC    GLOBAL DEFAULT    1 _ZN16EndpointResolver13en
  6690: 080560f1    44 FUNC    GLOBAL DEFAULT    1 isatty
  6691: 080448c5   448 FUNC    GLOBAL DEFAULT    1 _ZN7arduino3RPC5beginEv
  6692: 08052579    20 FUNC    GLOBAL DEFAULT    1 _ZN4mbed10TimerEventD1Ev
  6693: 0805f291     2 FUNC    WEAK   DEFAULT    1 HRTIM1_TIMB_IRQHandler
  6694: 08043d89   200 FUNC    GLOBAL DEFAULT    1 mriFaultHandler
  6695: 080636fd    26 FUNC    WEAK   DEFAULT    1 _ZNSsC2EPKcjRKSaIcE
  6696: 08063719    42 FUNC    WEAK   DEFAULT    1 _ZNSsC2EPKcRKSaIcE
  6697: 08043f85    20 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v112u
  6698: 08064b09     4 FUNC    WEAK   HIDDEN     1 __aeabi_unwind_cpp_pr2
  6699: 08072394    40 OBJECT  GLOBAL DEFAULT    1 PinMapAnalogSwitch
  6700: 08043005    68 FUNC    GLOBAL DEFAULT    1 mriPlatform_TypeOfCurrent
  6701: 08052a27    40 FUNC    GLOBAL DEFAULT    1 _ZN17OperationListBase6re
  6702: 08045501   236 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v28un
  6703: 08047ac5   276 FUNC    WEAK   DEFAULT    1 _ZN10clmdep_fmt11BasicWri
  6704: 08050a31    14 FUNC    GLOBAL DEFAULT    1 OS_Tick_Enable
  6705: 08045fbd    48 FUNC    WEAK   DEFAULT    1 _ZN10clmdep_fmt8internal1
  6706: 08046219    46 FUNC    WEAK   DEFAULT    1 _ZN10clmdep_fmt11BasicWri
  6707: 08042e61     6 FUNC    GLOBAL DEFAULT    1 mriPlatform_GetPacketBuff
  6708: 08063b05    32 FUNC    GLOBAL DEFAULT    1 _ZSt17__throw_bad_allocv
  6709: 080621d9    28 FUNC    GLOBAL DEFAULT    1 us_ticker_set_interrupt
  6710: 0806f27c    37 OBJECT  WEAK   DEFAULT    1 _ZTSN3rpc6detail21handler
  6711: 0804872f    44 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v16ob
  6712: 0805221d     6 FUNC    GLOBAL DEFAULT    1 _ZN4mbed10SerialBase10_ba
  6713: 080445bd    36 FUNC    WEAK   DEFAULT    1 _ZN4mbed10TickerBaseD1Ev
  6714: 08050fb1     4 FUNC    GLOBAL DEFAULT    1 _ZN10STM32_EMAC10power_do
  6715: 0804dd49    12 FUNC    WEAK   DEFAULT    1 _ZN4mbed5TimerD1Ev
  6716: 08056439    14 FUNC    WEAK   DEFAULT    1 _ZN12DirectSerialD0Ev
  6717: 0805d3cf   168 FUNC    GLOBAL DEFAULT    1 HAL_RTC_DeactivateAlarm
  6718: 08055b61    48 FUNC    GLOBAL DEFAULT    1 mbed_mem_trace_free
  6719: 08064ea9    34 FUNC    GLOBAL HIDDEN     1 ___Unwind_Resume
  6720: 0804fcc1    20 FUNC    GLOBAL DEFAULT    1 osRtxThreadRegPtr
  6721: 08047e75     4 FUNC    WEAK   DEFAULT    1 _ZNSt19_Sp_counted_delete
  6722: 08062b8d    28 FUNC    GLOBAL DEFAULT    1 _ZNSt9bad_allocD0Ev
  6723: 240022c0     8 OBJECT  GLOBAL DEFAULT    6 debugComm
  6724: 0805440d    36 FUNC    WEAK   DEFAULT    1 hal_critical_section_ente
  6725: 08040359    12 FUNC    GLOBAL DEFAULT    1 _Z21FDCAN1_IT0_IRQHandler
  6726: 24001070     4 OBJECT  GLOBAL DEFAULT    4 uwTickPrio
  6727: 0805049d    52 FUNC    GLOBAL DEFAULT    1 osThreadTerminate
  6728: 0805f291     2 FUNC    WEAK   DEFAULT    1 DFSDM1_FLT3_IRQHandler
  6729: 0804872b     4 FUNC    GLOBAL DEFAULT    1 _ZNK3rpc6detail8response8
  6730: 08050aa5    24 FUNC    WEAK   DEFAULT    1 _ZN4UUIDC2Et
  6731: 24011e48    40 OBJECT  GLOBAL DEFAULT    6 __malloc_current_mallinfo
  6732: 0804cdd5    20 FUNC    WEAK   DEFAULT    1 _ZN7arduino6USBCDC9AsyncR
  6733: 08060803     8 FUNC    GLOBAL DEFAULT    1 HAL_I2C_SlaveTxCpltCallba
  6734: 08054645    44 FUNC    GLOBAL DEFAULT    1 pinmap_function
  6735: 0804c155    42 FUNC    GLOBAL DEFAULT    1 _Z21getUniqueSerialNumber
  6736: 08056045    60 FUNC    GLOBAL DEFAULT    1 close
  6737: 08047e67     4 FUNC    WEAK   DEFAULT    1 _ZNSt19_Sp_counted_delete
  6738: 0804e171    16 FUNC    GLOBAL DEFAULT    1 PendSV_Handler
  6739: 24000000     0 OBJECT  GLOBAL HIDDEN     4 __dso_handle
  6740: 08055ee1     4 FUNC    WEAK   DEFAULT    1 _ZN4mbed21mbed_override_c
  6741: 24011e28     4 OBJECT  WEAK   DEFAULT    6 _ZGVNSt11__timepunctIcE2i
  6742: 08047e71     4 FUNC    WEAK   DEFAULT    1 _ZNSt19_Sp_counted_delete
  6743: 2407fc00     0 NOTYPE  GLOBAL DEFAULT    9 __HeapLimit
  6744: 0805f291     2 FUNC    WEAK   DEFAULT    1 DMA2_Stream5_IRQHandler
  6745: 08052419    46 FUNC    GLOBAL DEFAULT    1 _ZN4mbed9TimerBase5startE
  6746: 0805f291     2 FUNC    WEAK   DEFAULT    1 BDMA_Channel7_IRQHandler
  6747: 0804430d    60 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v14zo
  6748: 08056799    72 FUNC    GLOBAL DEFAULT    1 _ZN4rtos5Mutex11construct
  6749: 080405dd    20 FUNC    GLOBAL DEFAULT    1 HAL_FDCAN_RxFifo0Callback
  6750: 080542c1     2 FUNC    GLOBAL DEFAULT    1 equeue_mutex_destroy
  6751: 08063ed5    60 FUNC    GLOBAL DEFAULT    1 _ZNKSt3_V214error_categor
  6752: 08063ae5    30 FUNC    WEAK   DEFAULT    1 _ZNSt7__cxx1112basic_stri
  6753: 08047ea9    20 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v110t
  6754: 24010920    36 OBJECT  GLOBAL DEFAULT    6 serial_irq_ids
  6755: 0806fbb4    12 OBJECT  GLOBAL DEFAULT    1 _ZTVN7arduino9IPAddressE
  6756: 0805cfc5   340 FUNC    GLOBAL DEFAULT    1 HAL_RCCEx_GetPLL1ClockFre
  6757: 08048e35   284 FUNC    WEAK   DEFAULT    1 _ZNK14clmdep_msgpack2v17a
  6758: 08051217     4 FUNC    WEAK   DEFAULT    1 _Z20mbed_otp_mac_addressP
  6759: 0804a139    66 FUNC    GLOBAL DEFAULT    1 metal_sys_io_mem_map
  6760: 08050d7d    40 FUNC    GLOBAL DEFAULT    1 LAN8742_RegisterBusIO
  6761: 08054e5d    52 FUNC    GLOBAL DEFAULT    1 _ZN4mbed6StreamD1Ev
  6762: 08043541   116 FUNC    WEAK   DEFAULT    1 _ZN10ThreadList13resumeTh
  6763: 08048b9f    74 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v16pa
  6764: 0804b6b5    18 FUNC    GLOBAL DEFAULT    1 mriCmd_RestoreThreadState
  6765: 0805b2cd   112 FUNC    GLOBAL DEFAULT    1 HAL_PCD_EP_Open
  6766: 0804a99d   112 FUNC    GLOBAL DEFAULT    1 mriCmd_HandleBreakpointWa
  6767: 080621f5    32 FUNC    GLOBAL DEFAULT    1 us_ticker_fire_interrupt
  6768: 08061391   288 FUNC    GLOBAL DEFAULT    1 mbed_sdk_init
  6769: 08043939    60 FUNC    GLOBAL DEFAULT    1 _ZN7arduino11ThreadDebugD
  6770: 08055ead    48 FUNC    GLOBAL DEFAULT    1 _ZN12DirectSerialC2ERK15s
  6771: 08048681   116 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v117a
  6772: 0804f501    48 FUNC    GLOBAL DEFAULT    1 osMutexDelete
  6773: 080524d9    32 FUNC    GLOBAL DEFAULT    1 _ZN4mbed9TimerBaseC2EPK13
  6774: 0805f291     2 FUNC    WEAK   DEFAULT    1 I2C4_EV_IRQHandler
  6775: 08062e91     0 FUNC    GLOBAL DEFAULT    1 __cxa_end_cleanup
  6776: 08063565    64 FUNC    GLOBAL DEFAULT    1 _ZNSt11logic_errorD1Ev
  6777: 080604f1    96 FUNC    GLOBAL DEFAULT    1 HAL_GetTick
  6778: 08045c49    22 FUNC    WEAK   DEFAULT    1 _ZN10clmdep_fmt17BasicMem
  6779: 08048be9   146 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v16pa
  6780: 24011ec8     0 NOTYPE  GLOBAL DEFAULT    9 __end__
  6781: 0805f291     2 FUNC    WEAK   DEFAULT    1 SPI4_IRQHandler
  6782: 08056921    64 FUNC    GLOBAL DEFAULT    1 _ZN4rtos6Thread6_thunkEPv
  6783: 08056727    14 FUNC    GLOBAL DEFAULT    1 _ZN4rtos10EventFlagsD2Ev
  6784: 24010664     4 OBJECT  GLOBAL DEFAULT    6 _ZN4mbed8FileBase5_headE
  6785: 08050789    30 FUNC    GLOBAL DEFAULT    1 mbed_start
  6786: 08057255   204 FUNC    GLOBAL DEFAULT    1 ADC_ConversionStop
  6787: 2400108c     4 OBJECT  GLOBAL DEFAULT    4 _impure_ptr
  6788: 080434f1     8 FUNC    GLOBAL DEFAULT    1 mriPlatform_GetTargetXml
  6789: 08058627     2 FUNC    WEAK   DEFAULT    1 HAL_ETH_WakeUpCallback
  6790: 0804c7a5     8 FUNC    GLOBAL DEFAULT    1 _ZN7arduino18PluggableUSB
  6791: 24005c7c     4 OBJECT  GLOBAL DEFAULT    6 mbed_stack_isr_start
  6792: 24080000     0 NOTYPE  GLOBAL DEFAULT  ABS __stack
  6793: 0805f291     2 FUNC    WEAK   DEFAULT    1 DMA2_Stream7_IRQHandler
  6794: 0805f291     2 FUNC    WEAK   DEFAULT    1 JPEG_IRQHandler
  6795: 0805e8e5   448 FUNC    GLOBAL DEFAULT    1 USB_EPStartXfer
  6796: 24011ec8     0 NOTYPE  GLOBAL DEFAULT    6 __bss_end__
  6797: 0804d713     8 FUNC    GLOBAL DEFAULT    1 _ZThn1192_N7arduino9USBSe
  6798: 08066295     2 FUNC    GLOBAL DEFAULT    1 __retarget_lock_init_recu
  6799: 08063165    20 FUNC    GLOBAL DEFAULT    1 _ZN10__cxxabiv120__si_cla
  6800: 08050815    36 FUNC    GLOBAL DEFAULT    1 mbed_rtos_init_singleton_
  6801: 080719e8   180 OBJECT  WEAK   DEFAULT    1 PinMap_UART_RTS
  6802: 0805f291     2 FUNC    WEAK   DEFAULT    1 WAKEUP_PIN_IRQHandler
  6803: 0805f291     2 FUNC    WEAK   DEFAULT    1 EXTI1_IRQHandler
  6804: 0805f291     2 FUNC    WEAK   DEFAULT    1 LTDC_ER_IRQHandler
  6805: 0805f241     4 FUNC    GLOBAL DEFAULT    1 HSEM1_IRQHandler
  6806: 080525b9    42 FUNC    GLOBAL DEFAULT    1 _ZNK4mbed16UnbufferedSeri
  6807: 08059e39   188 FUNC    GLOBAL DEFAULT    1 HAL_I2C_Slave_Seq_Receive
  6808: 080611c1    40 FUNC    GLOBAL DEFAULT    1 lp_ticker_clear_interrupt
  6809: 0804893d    80 FUNC    WEAK   DEFAULT    1 _ZNSt14__shared_countILN9
  6810: 080569d5    22 FUNC    GLOBAL DEFAULT    1 _ZN4rtos6Thread11construc
  6811: 080542bd     4 FUNC    GLOBAL DEFAULT    1 equeue_mutex_create
  6812: 0806b829    44 FUNC    GLOBAL DEFAULT    1 _write_r
  6813: 08060285    12 FUNC    GLOBAL DEFAULT    1 FDCAN1_IT0_IRQHandler
  6814: 080728bc    12 OBJECT  GLOBAL DEFAULT    1 _ZTISt17bad_function_call
  6815: 08064725    12 FUNC    GLOBAL HIDDEN     1 _Unwind_DeleteException
  6816: 24011eac     1 OBJECT  GLOBAL DEFAULT    6 __lock___atexit_recursive
  6817: 0805b6dd    16 FUNC    GLOBAL DEFAULT    1 HAL_PWREx_EnableUSBVoltag
  6818: 08052afd     8 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice26string_ico
  6819: 0804c4ad   120 FUNC    WEAK   DEFAULT    1 _ZN7arduino9USBSerial11on
  6820: 080600db    14 FUNC    GLOBAL DEFAULT    1 HAL_PCD_ResumeCallback
  6821: 0805d119   672 FUNC    GLOBAL DEFAULT    1 HAL_RCCEx_GetPeriphCLKFre
  6822: 0805f291     2 FUNC    WEAK   DEFAULT    1 USART1_IRQHandler
  6823: 08052131   124 FUNC    GLOBAL DEFAULT    1 _ZN4mbed10SerialBase6atta
  6824: 08063281     4 FUNC    GLOBAL DEFAULT    1 _ZNKSt9type_info14__is_po
  6825: 08072608    20 OBJECT  GLOBAL DEFAULT    1 _ZTVSt13bad_exception
  6826: 080525f5     8 FUNC    GLOBAL DEFAULT    1 _ZThn124_N4mbed16Unbuffer
  6827: 0805e48d    12 FUNC    GLOBAL DEFAULT    1 USB_DisableGlobalInt
  6828: 0804b0fd    48 FUNC    GLOBAL DEFAULT    1 mriCmd_HandleRegisterWrit
  6829: 08056c89    12 FUNC    GLOBAL DEFAULT    1 HAL_GetUIDw1
  6830: 0804b189    96 FUNC    GLOBAL DEFAULT    1 mriCmd_HandleThreadContex
  6831: 0806c8cd   128 FUNC    GLOBAL DEFAULT    1 __multadd
  6832: 08059645     2 FUNC    WEAK   DEFAULT    1 HAL_FDCAN_HighPriorityMes
  6833: 0804c3b5    28 FUNC    WEAK   DEFAULT    1 _ZN7arduino9USBSerial5wri
  6834: 08059647     2 FUNC    WEAK   DEFAULT    1 HAL_FDCAN_ErrorCallback
  6835: 08050f01     6 FUNC    GLOBAL DEFAULT    1 _ZNK10STM32_EMAC12get_mtu
  6836: 080621cd    12 FUNC    GLOBAL DEFAULT    1 us_ticker_read
  6837: 080701b4    12 OBJECT  GLOBAL DEFAULT    1 memp_TCPIP_MSG_INPKT
  6838: 0805f291     2 FUNC    WEAK   DEFAULT    1 BDMA_Channel4_IRQHandler
  6839: 0804ddd9   156 FUNC    GLOBAL DEFAULT    1 analogRead
  6840: 08055a95    14 FUNC    GLOBAL DEFAULT    1 mbed_warning
  6841: 0804281d     8 FUNC    GLOBAL DEFAULT    1 _ZN7arduino21UsbDebugComm
  6842: 08042ad3    14 FUNC    WEAK   DEFAULT    1 _ZN4mbed6detail12Callback
  6843: 0807271c    34 OBJECT  GLOBAL DEFAULT    1 _ZTSN10__cxxabiv117__clas
  6844: 08062299     2 FUNC    GLOBAL DEFAULT    1 _ZNSt9exceptionD1Ev
  6845: 080524d9    32 FUNC    GLOBAL DEFAULT    1 _ZN4mbed9TimerBaseC1EPK13
  6846: 0804c7ad    28 FUNC    GLOBAL DEFAULT    1 _ZN7arduino18PluggableUSB
  6847: 08067fb5   100 FUNC    GLOBAL DEFAULT    1 strncpy
  6848: 08046049   128 FUNC    WEAK   DEFAULT    1 _ZN10clmdep_fmt14BasicFor
  6849: 080727dc    20 OBJECT  GLOBAL DEFAULT    1 _ZTVSt12length_error
  6850: 080516cd    44 FUNC    GLOBAL DEFAULT    1 sys_arch_unprotect
  6851: 08057ba5   288 FUNC    GLOBAL DEFAULT    1 HAL_DMA_Abort_IT
  6852: 0805f291     2 FUNC    WEAK   DEFAULT    1 DMA2_Stream2_IRQHandler
  6853: 08047c41   548 FUNC    WEAK   DEFAULT    1 _ZN10clmdep_fmt11BasicWri
  6854: 08042e69    20 FUNC    GLOBAL DEFAULT    1 mriPlatform_GetTrapReason
  6855: 08063195    58 FUNC    GLOBAL DEFAULT    1 _ZNK10__cxxabiv120__si_cl
  6856: 08048f51    18 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v1lsI
  6857: 0804f759    48 FUNC    GLOBAL DEFAULT    1 osSemaphoreNew
  6858: 0806229d     2 FUNC    GLOBAL DEFAULT    1 _ZNSt13bad_exceptionD2Ev
  6859: 0805f291     2 FUNC    WEAK   DEFAULT    1 ADC3_IRQHandler
  6860: 08055e91    28 FUNC    GLOBAL DEFAULT    1 _ZN12DirectSerial4readEPv
  6861: 0804d54b     6 FUNC    WEAK   DEFAULT    1 _ZThn1216_N7arduino9USBSe
  6862: 08063831   174 FUNC    WEAK   DEFAULT    1 _ZNSt7__cxx1112basic_stri
  6863: 080652a5     6 FUNC    GLOBAL HIDDEN     1 _Unwind_GetTextRelBase
  6864: 08053b8d   134 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice14_request_s
  6865: 0804e949    44 FUNC    GLOBAL DEFAULT    1 osKernelStart
  6866: 080531c1    84 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice16complete_r
  6867: 08043e61     4 FUNC    WEAK   DEFAULT    1 _ZN7arduino5Print17availa
  6868: 2400dfc8   363 OBJECT  GLOBAL DEFAULT    6 memp_memory_FRAG_PBUF_bas
  6869: 24011ddc     4 OBJECT  WEAK   DEFAULT    6 _ZGVNSt7__cxx118messagesI
  6870: 08044089    20 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v117s
  6871: 0805fb51    44 FUNC    GLOBAL DEFAULT    1 _ZN8USBPhyHw7_usbisrEv
  6872: 080460c9    30 FUNC    WEAK   DEFAULT    1 _ZNSt8_Rb_treeIN10clmdep_
  6873: 080723bc    64 OBJECT  GLOBAL DEFAULT    1 ll_pin_defines
  6874: 08061525   368 FUNC    GLOBAL DEFAULT    1 pin_function
  6875: 080640a5     0 FUNC    GLOBAL HIDDEN     1 __aeabi_uldivmod
  6876: 24011eb0     1 OBJECT  GLOBAL DEFAULT    6 __lock___arc4random_mutex
  6877: 080507ad   104 FUNC    GLOBAL DEFAULT    1 mbed_rtos_start
  6878: 080638e1   396 FUNC    WEAK   DEFAULT    1 _ZNSt7__cxx1112basic_stri
  6879: 0804cbc9     4 FUNC    GLOBAL DEFAULT    1 _ZN7arduino6USBCDC17getPr
  6880: 08055e11     4 FUNC    WEAK   DEFAULT    1 _ZN12DirectSerial5closeEv
  6881: 0805f291     2 FUNC    WEAK   DEFAULT    1 SPI2_IRQHandler
  6882: 0804db97    40 FUNC    GLOBAL DEFAULT    1 _ZN7arduino6String7reserv
  6883: 08049c7b   154 FUNC    GLOBAL DEFAULT    1 virtio_create_virtqueues
  6884: 08051919    24 FUNC    GLOBAL DEFAULT    1 memp_malloc
  6885: 080694ad    20 FUNC    GLOBAL DEFAULT    1 __sprint_r
  6886: 08057ad5    36 FUNC    GLOBAL DEFAULT    1 HAL_NVIC_DisableIRQ
  6887: 08044025    20 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v117m
  6888: 0805f291     2 FUNC    WEAK   DEFAULT    1 BDMA_Channel1_IRQHandler
  6889: 08062d81   136 FUNC    GLOBAL DEFAULT    1 __cxa_end_catch
  6890: 0804349d    76 FUNC    GLOBAL DEFAULT    1 mriPlatform_ClearHardware
  6891: 08047e6b     2 FUNC    WEAK   DEFAULT    1 _ZNSt19_Sp_counted_delete
  6892: 08051cab    26 FUNC    GLOBAL DEFAULT    1 _ZN4mbed12DigitalInOut5in
  6893: 0805b5e1   120 FUNC    GLOBAL DEFAULT    1 HAL_PWREx_ConfigSupply
  6894: 0805ec89    32 FUNC    GLOBAL DEFAULT    1 USB_ActivateSetup
  6895: 080447a9   284 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v26pa
  6896: 0805e50d    14 FUNC    GLOBAL DEFAULT    1 USB_SetDevSpeed
  6897: 08064005     0 FUNC    GLOBAL HIDDEN     1 __aeabi_ldivmod
  6898: 08070980    80 OBJECT  GLOBAL DEFAULT    1 _ZTVN4mbed10FileHandleE
  6899: 08064dad     0 FUNC    GLOBAL HIDDEN     1 __gnu_Unwind_Save_VFP
  6900: 080510c1    52 FUNC    GLOBAL DEFAULT    1 _ZN10STM32_EMACC1Ev
  6901: 24011cf6     1 OBJECT  GLOBAL DEFAULT    6 sleep_manager_locked
  6902: 08070148    12 OBJECT  GLOBAL DEFAULT    1 memp_FRAG_PBUF
  6903: 0805f245    52 FUNC    WEAK   DEFAULT    1 Reset_Handler
  6904: 08057b8d    24 FUNC    GLOBAL DEFAULT    1 HAL_GetCurrentCPUID
  6905: 08055f49    68 FUNC    GLOBAL DEFAULT    1 __cxa_guard_acquire
  6906: 08063815    26 FUNC    WEAK   DEFAULT    1 _ZNSt7__cxx1112basic_stri
  6907: 0805ebcd    32 FUNC    GLOBAL DEFAULT    1 USB_SetDevAddress
  6908: 08062215    20 FUNC    GLOBAL DEFAULT    1 us_ticker_disable_interru
  6909: 080405cd    16 FUNC    GLOBAL DEFAULT    1 HAL_FDCAN_TxBufferComplet
  6910: 08052a4f    26 FUNC    GLOBAL DEFAULT    1 _ZN17OperationListBase10r
  6911: 080514ad    16 FUNC    GLOBAL DEFAULT    1 ETH_IRQHandler
  6912: 0804b12d    46 FUNC    GLOBAL DEFAULT    1 mriCmd_HandleSingleStepCo
  6913: 08050a61    16 FUNC    GLOBAL DEFAULT    1 rtos_idle_loop
  6914: 08053679   148 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice14endpoint_s
  6915: 08044011    20 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v119a
  6916: 0805a975    76 FUNC    GLOBAL DEFAULT    1 HAL_I2CEx_ConfigAnalogFil
  6917: 080701f0    56 OBJECT  GLOBAL DEFAULT    1 memp_pools
  6918: 08055b31    48 FUNC    GLOBAL DEFAULT    1 mbed_mem_trace_calloc
  6919: 08055a39    76 FUNC    WEAK   DEFAULT    1 error
  6920: 08055e01     6 FUNC    WEAK   DEFAULT    1 _ZN12DirectSerial4seekEli
  6921: 080475b5   360 FUNC    WEAK   DEFAULT    1 _ZN10clmdep_fmt11BasicWri
  6922: 08045c11    32 FUNC    WEAK   DEFAULT    1 _ZN10clmdep_fmt8internal1
  6923: 08064dbd     0 FUNC    GLOBAL HIDDEN     1 __gnu_Unwind_Save_VFP_D
  6924: 08048fb9   158 FUNC    GLOBAL DEFAULT    1 _ZNK3rpc6detail8response8
  6925: 080554d1    12 FUNC    GLOBAL DEFAULT    1 __wrap__malloc_r
  6926: 080543f9    16 FUNC    GLOBAL DEFAULT    1 _ZN4mbed16mbed_event_queu
  6927: 08043c95    80 FUNC    GLOBAL DEFAULT    1 mriPlatform_RtosRestorePr
  6928: 08042d75   128 FUNC    GLOBAL DEFAULT    1 _ZN7arduino21UsbDebugComm
  6929: 08055ad9    40 FUNC    GLOBAL DEFAULT    1 mbed_mem_trace_malloc
  6930: 0805e7c9   244 FUNC    GLOBAL DEFAULT    1 USB_EP0StartXfer
  6931: 0804d52f     6 FUNC    WEAK   DEFAULT    1 _ZN4mbed10FileHandle12ena
  6932: 0804bf99    28 FUNC    GLOBAL DEFAULT    1 mriToken_Init
  6933: 08064e19     0 FUNC    GLOBAL HIDDEN     1 __gnu_Unwind_Save_WMMXD
  6934: 0804c87b    42 FUNC    GLOBAL DEFAULT    1 _ZN7arduino18PluggableUSB
  6935: 080694c1  3108 FUNC    GLOBAL DEFAULT    1 _vfiprintf_r
  6936: 0806327d     2 FUNC    GLOBAL DEFAULT    1 _ZNSt9type_infoD1Ev
  6937: 080524f9    22 FUNC    GLOBAL DEFAULT    1 _ZN4mbed5TimerC1Ev
  6938: 08065795    12 FUNC    GLOBAL DEFAULT    1 __sfp_lock_release
  6939: 08063781    40 FUNC    GLOBAL DEFAULT    1 _ZNSt13runtime_errorC2EPK
  6940: 0805fbcd    32 FUNC    GLOBAL DEFAULT    1 _ZN8USBPhyHw14endpoint_ab
  6941: 0804d311    98 FUNC    GLOBAL DEFAULT    1 _ZN7arduino6USBCDC7send_n
  6942: 080578c9   160 FUNC    GLOBAL DEFAULT    1 HAL_ADCEx_Calibration_Sta
  6943: 0805f291     2 FUNC    WEAK   DEFAULT    1 CM7_SEV_IRQHandler
  6944: 08054289     4 FUNC    GLOBAL DEFAULT    1 equeue_tick_init
  6945: 080565f5   104 FUNC    GLOBAL DEFAULT    1 _open
  6946: 0806f220    12 OBJECT  WEAK   DEFAULT    1 _ZTIN14clmdep_msgpack2v11
  6947: 24010690     4 OBJECT  GLOBAL DEFAULT    6 _ZN4mbed8FileBase8_defaul
  6948: 24010820     4 OBJECT  GLOBAL DEFAULT    6 _ZN4mbed8internal8os_time
  6949: 080515c5   128 FUNC    GLOBAL DEFAULT    1 sys_mbox_trypost
  6950: 0805575f     4 FUNC    GLOBAL DEFAULT    1 core_util_in_critical_sec
  6951: 0807008c    68 OBJECT  GLOBAL DEFAULT    1 _ZTV10STM32_EMAC
  6952: 08043e5d     4 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v28un
  6953: 08058e25   984 FUNC    GLOBAL DEFAULT    1 HAL_FDCAN_Init
  6954: 08044039    20 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v117m
  6955: 0805247f    52 FUNC    GLOBAL DEFAULT    1 _ZNK4mbed9TimerBase12elap
  6956: 08049c77     2 FUNC    GLOBAL DEFAULT    1 metal_machine_cache_inval
  6957: 08052579    20 FUNC    GLOBAL DEFAULT    1 _ZN4mbed10TimerEventD2Ev
  6958: 0805eae5    86 FUNC    GLOBAL DEFAULT    1 USB_EPSetStall
  6959: 0804cbc3     6 FUNC    GLOBAL DEFAULT    1 _ZN7arduino6USBCDC22strin
  6960: 0806f2c0    28 OBJECT  WEAK   DEFAULT    1 _ZTVSt19_Sp_counted_delet
  6961: 0806565d    46 FUNC    GLOBAL DEFAULT    1 __sfmoreglue
  6962: 08045783     2 FUNC    WEAK   DEFAULT    1 _ZN7arduino14SerialRPCCla
  6963: 080413bd   164 FUNC    GLOBAL DEFAULT    1 _Z17Trd_internal_initP5ca
  6964: 08055f3f     8 FUNC    GLOBAL DEFAULT    1 __malloc_unlock
  6965: 08053179    72 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice9ep0_setupEv
  6966: 080646b9    18 FUNC    GLOBAL HIDDEN     1 __gnu_Unwind_ForcedUnwind
  6967: 0805b5c5    28 FUNC    GLOBAL DEFAULT    1 HAL_PWR_EnterSLEEPMode
  6968: 0805f291     2 FUNC    WEAK   DEFAULT    1 HOLD_CORE_IRQHandler
  6969: 08051bf9     2 FUNC    WEAK   DEFAULT    1 _ZN4mbed8AnalogInD2Ev
  6970: 24011e44     4 OBJECT  WEAK   DEFAULT    6 _ZGVNSt10moneypunctIcLb0E
  6971: 0805eb8d    64 FUNC    GLOBAL DEFAULT    1 USB_StopDevice
  6972: 0805e0b7   106 FUNC    GLOBAL DEFAULT    1 UART_CheckIdleState
  6973: 08060785    60 FUNC    GLOBAL DEFAULT    1 HAL_I2C_MasterTxCpltCallb
  6974: 080459d1   464 FUNC    WEAK   DEFAULT    1 _ZN7arduino14SerialRPCCla
  6975: 080443b9    36 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v26de
  6976: 080553fb    58 FUNC    GLOBAL DEFAULT    1 __wrap__calloc_r
  6977: 08048915    40 FUNC    WEAK   DEFAULT    1 _ZNSt12__shared_ptrIN14cl
  6978: 24010288     4 OBJECT  WEAK   DEFAULT    6 _ZGVZN4mbed33do_shared_ev
  6979: 0805b4a7   108 FUNC    GLOBAL DEFAULT    1 HAL_PCD_EP_ClrStall
  6980: 0805f295    96 FUNC    GLOBAL DEFAULT    1 analogin_pll_configuratio
  6981: 0805f291     2 FUNC    WEAK   DEFAULT    1 DMA1_Stream6_IRQHandler
  6982: 08045f91    44 FUNC    WEAK   DEFAULT    1 _ZN10clmdep_fmt8internal1
  6983: 0805b433   116 FUNC    GLOBAL DEFAULT    1 HAL_PCD_EP_SetStall
  6984: 0804aab5    42 FUNC    GLOBAL DEFAULT    1 mriCmd_ContinueExecution
  6985: 08047bd9   100 FUNC    WEAK   DEFAULT    1 _ZN10clmdep_fmt11BasicWri
  6986: 08055765    44 FUNC    GLOBAL DEFAULT    1 core_util_critical_sectio
  6987: 08063285    44 FUNC    GLOBAL DEFAULT    1 _ZNKSt9type_infoeqERKS_
  6988: 0804a57d    60 FUNC    GLOBAL DEFAULT    1 mriBuffer_WriteByteAsHex
  6989: 0804cfa9    28 FUNC    WEAK   DEFAULT    1 _ZN4mbed8CallbackIFvvEE11
  6990: 08054cbd     4 FUNC    WEAK   DEFAULT    1 _ZN4mbed10FileHandle6isat
  6991: 0804d699    76 FUNC    GLOBAL DEFAULT    1 _ZN7arduino9USBSerialD1Ev
  6992: 0806f88c   136 OBJECT  GLOBAL DEFAULT    1 _ZTVN7arduino18PluggableU
  6993: 08051c7d    10 FUNC    WEAK   DEFAULT    1 _ZN4mbed10FileHandle4tell
  6994: 0806e708    12 OBJECT  WEAK   DEFAULT    1 _ZTIN14clmdep_msgpack2v11
  6995: 08049d3f   196 FUNC    GLOBAL DEFAULT    1 virtqueue_add_buffer
  6996: 08053075    72 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice22complete_s
  6997: 08070a18    96 OBJECT  WEAK   DEFAULT    1 _ZTVN4mbed8FileLikeE
  6998: 08062e19    38 FUNC    GLOBAL DEFAULT    1 _ZN10__cxxabiv111__termin
  6999: 240102e8   768 OBJECT  WEAK   DEFAULT    6 _ZZN4mbed33do_shared_even
  7000: 08053c97    42 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice5resetEv
  7001: 08043c39    92 FUNC    GLOBAL DEFAULT    1 mriPlatform_RtosSetThread
  7002: 08055b91    32 FUNC    GLOBAL DEFAULT    1 mbed_mem_trace_lock
  7003: 080465f5    14 FUNC    WEAK   DEFAULT    1 _ZN10clmdep_fmt6BufferIcE
  7004: 0805f291     2 FUNC    WEAK   DEFAULT    1 TIM1_CC_IRQHandler
  7005: 0805ab41   274 FUNC    GLOBAL DEFAULT    1 HAL_PCD_Init
  7006: 08064d8d    24 FUNC    GLOBAL HIDDEN     1 __restore_core_regs
  7007: 08058629   356 FUNC    GLOBAL DEFAULT    1 HAL_ETH_IRQHandler
  7008: 0805f291     2 FUNC    WEAK   DEFAULT    1 OTG_HS_WKUP_IRQHandler
  7009: 0805f291     2 FUNC    WEAK   DEFAULT    1 TIM2_IRQHandler
  7010: 0805f291     2 FUNC    WEAK   DEFAULT    1 LPTIM2_IRQHandler
  7011: 0804db27    26 FUNC    GLOBAL DEFAULT    1 _ZN7arduino5Print5printEm
  7012: 0804db13    20 FUNC    GLOBAL DEFAULT    1 _ZN7arduino5Print7println
  7013: 0804da91    58 FUNC    GLOBAL DEFAULT    1 _ZN7arduino5Print11printN
  7014: 0804bc55    24 FUNC    GLOBAL DEFAULT    1 mriCore_RecordControlCFla
  7015: 08051c41    20 FUNC    WEAK   DEFAULT    1 _ZN4mbed8AnalogIn6unlockE
  7016: 08052929    10 FUNC    GLOBAL DEFAULT    1 _ZN16EndpointResolver12en
  7017: 0805f7d9   324 FUNC    GLOBAL DEFAULT    1 serial_irq_set
  7018: 0805fa9d     6 FUNC    GLOBAL DEFAULT    1 _ZN8USBPhyHw10sof_enableE
  7019: 24003a1c     4 OBJECT  GLOBAL DEFAULT    6 mriThreadOrigMemManagemen
  7020: 08050f07     4 FUNC    GLOBAL DEFAULT    1 _ZNK10STM32_EMAC20get_ali
  7021: 08062e11     8 FUNC    GLOBAL DEFAULT    1 __cxa_get_globals
  7022: 08045849   200 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v14pa
  7023: 08060f9d     8 FUNC    GLOBAL DEFAULT    1 lp_ticker_get_info
  7024: 0805f291     2 FUNC    WEAK   DEFAULT    1 DMA2_Stream6_IRQHandler
  7025: 08072740    44 OBJECT  GLOBAL DEFAULT    1 _ZTVN10__cxxabiv117__clas
  7026: 08052607     8 FUNC    GLOBAL DEFAULT    1 _ZThn124_N4mbed16Unbuffer
  7027: 08059327    38 FUNC    GLOBAL DEFAULT    1 HAL_FDCAN_EnableTimeoutCo
  7028: 08055753    12 FUNC    GLOBAL DEFAULT    1 core_util_is_isr_active
  7029: 08054019   152 FUNC    GLOBAL DEFAULT    1 equeue_enqueue
  7030: 080655dd    36 FUNC    GLOBAL DEFAULT    1 fflush
  7031: 0804aa0d    28 FUNC    GLOBAL DEFAULT    1 mriCmd_ReadUIntegerArgume
  7032: 0804bb8d    76 FUNC    GLOBAL DEFAULT    1 mriCore_SetTempBreakpoint
  7033: 080701e4    12 OBJECT  GLOBAL DEFAULT    1 memp_UDP_PCB
  7034: 08063065    88 FUNC    GLOBAL DEFAULT    1 __cxa_init_primary_except
  7035: 08056ec1   916 FUNC    GLOBAL DEFAULT    1 HAL_ADC_ConfigChannel
  7036: 0806e83c    20 OBJECT  WEAK   DEFAULT    1 _ZTVN14clmdep_msgpack2v11
  7037: 08066c31   148 FUNC    GLOBAL DEFAULT    1 memset
  7038: 080421c5   652 FUNC    GLOBAL DEFAULT    1 _Z14read_parameterP8LOITR
  7039: 08051dab   232 FUNC    GLOBAL DEFAULT    1 _ZN4mbed3I2C7recoverE7Pin
  7040: 0804e029    92 FUNC    GLOBAL DEFAULT    1 _Z12digitalWrite7PinName9
  7041: 08054a33    54 FUNC    GLOBAL DEFAULT    1 ticker_remove_event
  7042: 08054b69    16 FUNC    GLOBAL DEFAULT    1 _ZN4mbed19CriticalSection
  7043: 0805f291     2 FUNC    WEAK   DEFAULT    1 SAI2_IRQHandler
  7044: 0804d6f5    22 FUNC    GLOBAL DEFAULT    1 _ZN7arduino9USBSerialD0Ev
  7045: 08052c3d   338 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice23_request_g
  7046: 08055e61    48 FUNC    GLOBAL DEFAULT    1 _ZNK12DirectSerial4pollEs
  7047: 0805f291     2 FUNC    WEAK   DEFAULT    1 I2C3_EV_IRQHandler
  7048: 0804a219   122 FUNC    GLOBAL DEFAULT    1 metal_io_block_read
  7049: 080525ad     4 FUNC    WEAK   DEFAULT    1 _ZThn124_N4mbed16Unbuffer
  7050: 240045b8   316 OBJECT  GLOBAL DEFAULT    6 _UART3_
  7051: 0806e8a0    12 OBJECT  WEAK   DEFAULT    1 _ZTVN4mbed6TickerE
  7052: 08052e7d    96 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice7ep0_outEv
  7053: 0805f291     2 FUNC    WEAK   DEFAULT    1 FMC_IRQHandler
  7054: 08054d91    10 FUNC    GLOBAL DEFAULT    1 _ZN4mbed8FilePath6existsE
  7055: 080535f1   136 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice14endpoint_a
  7056: 0804b9a5   132 FUNC    GLOBAL DEFAULT    1 mriMem_ReadMemoryIntoHexB
  7057: 08056715    12 FUNC    GLOBAL DEFAULT    1 _ZN4rtos10EventFlagsC1EPK
  7058: 24011e74     4 OBJECT  GLOBAL DEFAULT    6 __malloc_max_total_mem
  7059: 080523e5    32 FUNC    GLOBAL DEFAULT    1 _ZN4mbed6TickerC2Ev
  7060: 0804f7d9    92 FUNC    GLOBAL DEFAULT    1 osSemaphoreRelease
  7061: 0805ad09  1436 FUNC    GLOBAL DEFAULT    1 HAL_PCD_IRQHandler
  7062: 0804ab0d    92 FUNC    GLOBAL DEFAULT    1 mriCmd_HandleContinueWith
  7063: 0804e915     2 FUNC    WEAK   DEFAULT    1 osRtxKernelPreInit
  7064: 0805f291     2 FUNC    WEAK   DEFAULT    1 TIM3_IRQHandler
  7065: 080672d5    16 FUNC    GLOBAL DEFAULT    1 srandom
  7066: 08043e51    12 FUNC    GLOBAL DEFAULT    1 _ZN7arduino21UsbDebugComm
  7067: 0805d62f   196 FUNC    GLOBAL DEFAULT    1 HAL_RTC_SetTime
  7068: 0804b0e5    24 FUNC    GLOBAL DEFAULT    1 mriCmd_HandleRegisterRead
  7069: 24011e1c     4 OBJECT  WEAK   DEFAULT    6 _ZGVNSt8messagesIcE2idE
  7070: 08066d19  1468 FUNC    GLOBAL DEFAULT    1 qsort
  7071: 08050351    64 FUNC    GLOBAL DEFAULT    1 osRtxThreadStartup
  7072: 0805f291     2 FUNC    WEAK   DEFAULT    1 LPTIM1_IRQHandler
  7073: 24003a20     4 OBJECT  GLOBAL DEFAULT    6 mriThreadOrigPendSV
  7074: 0805f291     2 FUNC    WEAK   DEFAULT    1 SPI3_IRQHandler
  7075: 0805f291     2 FUNC    WEAK   DEFAULT    1 TIM6_DAC_IRQHandler
  7076: 0805ab3f     2 FUNC    WEAK   DEFAULT    1 HAL_PCD_MspInit
  7077: 08051671    40 FUNC    GLOBAL DEFAULT    1 sys_mutex_unlock
  7078: 08053c13   132 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice17_complete_
  7079: 08047e6d     4 FUNC    WEAK   DEFAULT    1 _ZNSt19_Sp_counted_delete
  7080: 0804c41d    58 FUNC    WEAK   DEFAULT    1 _ZN7arduino9USBSerial5wri
  7081: 0804d811   284 FUNC    GLOBAL DEFAULT    1 _ZN7arduino9USBSerial5beg
  7082: 080662a5    92 FUNC    GLOBAL DEFAULT    1 __swhatbuf_r
  7083: 0805f291     2 FUNC    WEAK   DEFAULT    1 DMAMUX1_OVR_IRQHandler
  7084: 0804063d   112 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v16pa
  7085: 080600eb   120 FUNC    GLOBAL DEFAULT    1 HAL_PCD_ResetCallback
  7086: 080595bd   124 FUNC    GLOBAL DEFAULT    1 HAL_FDCAN_ActivateNotific
  7087: 0805f291     2 FUNC    WEAK   DEFAULT    1 DFSDM1_FLT2_IRQHandler
  7088: 0806008f    50 FUNC    GLOBAL DEFAULT    1 HAL_PCD_DataInStageCallba
  7089: 0805f291     2 FUNC    WEAK   DEFAULT    1 TIM8_TRG_COM_TIM14_IRQHan
  7090: 08052951     8 FUNC    GLOBAL DEFAULT    1 _ZN14LinkedListBaseC2Ev
  7091: 24011e14     4 OBJECT  WEAK   DEFAULT    6 _ZGVNSt7__cxx1110moneypun
  7092: 0806f2a4     8 OBJECT  WEAK   DEFAULT    1 _ZTIN3rpc6detail21handler
  7093: 0804c07d     4 FUNC    GLOBAL DEFAULT    1 mriPlatform_MemWrite16
  7094: 0806c689   116 FUNC    GLOBAL DEFAULT    1 __sflags
  7095: 0804c0ad    36 FUNC    WEAK   DEFAULT    1 _ZN4mbed3I2CD2Ev
  7096: 08052bad    44 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice4lockEv
  7097: 0806cfa9    16 FUNC    GLOBAL DEFAULT    1 _kill
  7098: 08054cc1    50 FUNC    GLOBAL DEFAULT    1 _ZN4mbed10FileHandle4size
  7099: 08050f0b     4 FUNC    GLOBAL DEFAULT    1 _ZNK10STM32_EMAC15get_hwa
  7100: 0804bcd1   120 FUNC    GLOBAL DEFAULT    1 mriCore_GdbCommandHandlin
  7101: 0804cd99    20 FUNC    WEAK   DEFAULT    1 _ZN7arduino6USBCDC9AsyncW
  7102: 0805878d    92 FUNC    GLOBAL DEFAULT    1 HAL_ETH_ReadPHYRegister
  7103: 08059ae1    10 FUNC    GLOBAL DEFAULT    1 HAL_GPIO_WritePin
  7104: 08054f71    90 FUNC    WEAK   DEFAULT    1 _ZNK4mbed8internal8SysTim
  7105: 38000400     0 NOTYPE  GLOBAL DEFAULT  ABS __OPENAMP_region_start__
  7106: 0805572d    26 FUNC    GLOBAL DEFAULT    1 mbed_error_printf
  7107: 08043f31    20 FUNC    GLOBAL DEFAULT    1 _ZN7arduino3RPC5writeEPKh
  7108: 0805f291     2 FUNC    WEAK   DEFAULT    1 SPI1_IRQHandler
  7109: 0805f291     2 FUNC    WEAK   DEFAULT    1 HRTIM1_Master_IRQHandler
  7110: 0804da39    10 FUNC    WEAK   DEFAULT    1 _ZN7arduino5Print5writeEP
  7111: 08059643     2 FUNC    WEAK   DEFAULT    1 HAL_FDCAN_RxBufferNewMess
  7112: 0804be6d   192 FUNC    GLOBAL DEFAULT    1 mriPacket_GetFromGDB
  7113: 080529b9    12 FUNC    GLOBAL DEFAULT    1 _ZN17OperationListBaseC1E
  7114: 08053a41   116 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice12write_fini
  7115: 08059f1d    14 FUNC    GLOBAL DEFAULT    1 HAL_I2C_EV_IRQHandler
  7116: 080600c1    12 FUNC    GLOBAL DEFAULT    1 HAL_PCD_SetupStageCallbac
  7117: 0805d96d     2 FUNC    WEAK   DEFAULT    1 HAL_TIM_OC_MspInit
  7118: 0805f291     2 FUNC    WEAK   DEFAULT    1 ECC_IRQHandler
  7119: 08052611    20 FUNC    WEAK   DEFAULT    1 _ZN4mbed16UnbufferedSeria
  7120: 08064e85    34 FUNC    GLOBAL HIDDEN     1 ___Unwind_RaiseException
  7121: 08058e21     2 FUNC    WEAK   DEFAULT    1 HAL_FDCAN_MspInit
  7122: 08071100    80 OBJECT  GLOBAL DEFAULT    1 _ZTV12DirectSerial
  7123: 08046ab5   380 FUNC    WEAK   DEFAULT    1 _ZN10clmdep_fmt8internal1
  7124: 0804bc79    12 FUNC    GLOBAL DEFAULT    1 mriCore_SetSemihostReturn
  7125: 08053d07    50 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice6deinitEv
  7126: 0805fb03    12 FUNC    GLOBAL DEFAULT    1 _ZN8USBPhyHw15ep0_read_re
  7127: 080442c3    74 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v14zo
  7128: 080510f5   128 FUNC    GLOBAL DEFAULT    1 _ZN10STM32_EMAC15low_leve
  7129: 08050589    48 FUNC    GLOBAL DEFAULT    1 osThreadFlagsWait
  7130: 08053e11    30 FUNC    GLOBAL DEFAULT    1 _ZN6events10EventQueueC2E
  7131: 0805f291     2 FUNC    WEAK   DEFAULT    1 I2C2_EV_IRQHandler
  7132: 2400f9c8   188 OBJECT  WEAK   DEFAULT    6 _ZZN4mbed33do_shared_even
  7133: 08063781    40 FUNC    GLOBAL DEFAULT    1 _ZNSt13runtime_errorC1EPK
  7134: 08072644    20 OBJECT  GLOBAL DEFAULT    1 _ZTVSt8bad_cast
  7135: 0806f248    12 OBJECT  WEAK   DEFAULT    1 _ZTIN3rpc6detail12client_
  7136: 08043eb5    54 FUNC    GLOBAL DEFAULT    1 _ZN7arduino3RPC28rpmsg_re
  7137: 08049fcd    34 FUNC    GLOBAL DEFAULT    1 metal_generic_dev_dma_unm
  7138: 0804a37b     6 FUNC    GLOBAL DEFAULT    1 metal_default_log_handler
  7139: 0805fce9    44 FUNC    GLOBAL DEFAULT    1 _ZN8USBPhyHw7connectEv
  7140: 08050af5     8 FUNC    WEAK   DEFAULT    1 _ZN6events10EventQueue13f
  7141: 08047e6b     2 FUNC    WEAK   DEFAULT    1 _ZNSt19_Sp_counted_delete
  7142: 08064f91   708 FUNC    GLOBAL HIDDEN     1 __gnu_unwind_execute
  7143: 0804962b    92 FUNC    GLOBAL DEFAULT    1 rpmsg_get_endpoint
  7144: 0804c76d     4 FUNC    WEAK   DEFAULT    1 _ZN9USBDevice18report_des
  7145: 08055191    16 FUNC    WEAK   DEFAULT    1 _ZN4mbed8internal8SysTime
  7146: 08054a95     8 FUNC    GLOBAL DEFAULT    1 get_us_ticker_data
  7147: 08060863    28 FUNC    GLOBAL DEFAULT    1 HAL_I2C_AbortCpltCallback
  7148: 0804fc2d    34 FUNC    GLOBAL DEFAULT    1 osRtxThreadListSort
  7149: 2400dd34    52 OBJECT  GLOBAL DEFAULT    6 whd_iface_shared
  7150: 08050a7b    12 FUNC    WEAK   DEFAULT    1 _ZN4mbed6detail12Callback
  7151: 080728c8    22 OBJECT  GLOBAL DEFAULT    1 _ZTSSt17bad_function_call
  7152: 0804e975    44 FUNC    GLOBAL DEFAULT    1 osKernelLock
  7153: 08045d89    20 FUNC    WEAK   DEFAULT    1 _ZN10clmdep_fmt11FormatEr
  7154: 080604e5    10 FUNC    GLOBAL DEFAULT    1 HAL_InitTick
  7155: 08061bb1   116 FUNC    GLOBAL DEFAULT    1 get_uart_index
  7156: 24011eb4     1 OBJECT  GLOBAL DEFAULT    6 __lock___sinit_recursive_
  7157: 08059275    50 FUNC    GLOBAL DEFAULT    1 HAL_FDCAN_ConfigGlobalFil
  7158: 0805ac7f    62 FUNC    GLOBAL DEFAULT    1 HAL_PCD_Start
  7159: 080508fd    12 FUNC    GLOBAL DEFAULT    1 EvrRtxThreadError
  7160: 08064dcd     0 FUNC    GLOBAL HIDDEN     1 __gnu_Unwind_Save_VFP_D_1
  7161: 0804154d    84 FUNC    GLOBAL DEFAULT    1 _Z11my_can_modeP5can_s7Ca
  7162: 08063381    42 FUNC    GLOBAL DEFAULT    1 _ZNK10__cxxabiv117__class
  7163: 24010668    40 OBJECT  GLOBAL DEFAULT    6 _ZN4mbed8FileBase6_mutexE
  7164: 0804c9c9    36 FUNC    GLOBAL DEFAULT    1 _ZN7arduino18PluggableUSB
  7165: 08051f91   120 FUNC    GLOBAL DEFAULT    1 _ZN4mbed10SerialBase16set
  7166: 0805ef45    28 FUNC    GLOBAL DEFAULT    1 cy_rtos_set_semaphore
  7167: 08054b79    16 FUNC    GLOBAL DEFAULT    1 _ZN4mbed19CriticalSection
  7168: 08050787     2 FUNC    WEAK   DEFAULT    1 mbed_main
  7169: 080635b9    20 FUNC    GLOBAL DEFAULT    1 _ZNSt12length_errorD1Ev
  7170: 080545e9    24 FUNC    GLOBAL DEFAULT    1 pinmap_find_peripheral
  7171: 0805d78f   360 FUNC    GLOBAL DEFAULT    1 HAL_RTC_SetAlarm_IT
  7172: 08055791    24 FUNC    GLOBAL DEFAULT    1 core_util_critical_sectio
  7173: 08040909  1060 FUNC    GLOBAL DEFAULT    1 loop
  7174: 08054431    56 FUNC    WEAK   DEFAULT    1 hal_critical_section_exit
  7175: 08045911   192 FUNC    WEAK   DEFAULT    1 _ZN3rpc6client4callIJSt6v
  7176: 0804d1a1    28 FUNC    GLOBAL DEFAULT    1 _ZN7arduino6USBCDC21callb
  7177: 08072784    12 OBJECT  GLOBAL DEFAULT    1 _ZTISt13runtime_error
  7178: 08072700    13 OBJECT  GLOBAL DEFAULT    1 _ZTSSt9type_info
  7179: 0805f291     2 FUNC    WEAK   DEFAULT    1 LTDC_IRQHandler
  7180: 080455ed   364 FUNC    GLOBAL DEFAULT    1 _ZN7arduino3RPC8dispatchE
  7181: 08051ea9    20 FUNC    GLOBAL DEFAULT    1 _ZN4mbed3I2C6unlockEv
  7182: 0804c075     4 FUNC    GLOBAL DEFAULT    1 mriPlatform_MemRead8
  7183: 0805f291     2 FUNC    WEAK   DEFAULT    1 SAI4_IRQHandler
  7184: 080652b1    14 FUNC    GLOBAL DEFAULT    1 abort
  7185: 0805d903     2 FUNC    WEAK   DEFAULT    1 HAL_SRAM_MspInit
  7186: 0805f291     2 FUNC    WEAK   DEFAULT    1 EXTI4_IRQHandler
  7187: 24000280  3104 OBJECT  GLOBAL DEFAULT    4 g_APinDescription
  7188: 080669d1    98 FUNC    GLOBAL DEFAULT    1 memcmp
  7189: 0806b6ed    32 FUNC    GLOBAL DEFAULT    1 vsnprintf
  7190: 0804e9a1    48 FUNC    GLOBAL DEFAULT    1 osKernelRestoreLock
  7191: 24004dc4  1592 OBJECT  GLOBAL DEFAULT    6 _SerialUSB
  7192: 0805635d     6 FUNC    GLOBAL DEFAULT    1 __wrap_exit
  7193: 080727a0    17 OBJECT  GLOBAL DEFAULT    1 _ZTSSt12length_error
  7194: 0805f291     2 FUNC    WEAK   DEFAULT    1 NMI_Handler
  7195: 0804d3c1   128 FUNC    GLOBAL DEFAULT    1 _ZN7arduino6USBCDC7receiv
  7196: 08045813    16 FUNC    WEAK   DEFAULT    1 _ZNSt12_Vector_baseIhSaIh
  7197: 08048239   296 FUNC    WEAK   DEFAULT    1 _ZN3rpc6detail8response10
  7198: 08055f2d     4 FUNC    GLOBAL DEFAULT    1 __wrap_atexit
  7199: 08063b25    48 FUNC    GLOBAL DEFAULT    1 _ZSt19__throw_logic_error
  7200: 0805397d   196 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice11write_star
  7201: 08055569    12 FUNC    GLOBAL DEFAULT    1 __wrap__free_r
  7202: 08050a59     8 FUNC    GLOBAL DEFAULT    1 OS_Tick_GetIRQn
  7203: 08066249    18 FUNC    GLOBAL DEFAULT    1 isprint
  7204: 080532c9    24 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice14_control_a
  7205: 08043a45    20 FUNC    GLOBAL DEFAULT    1 mriPlatform_CommHasReceiv
  7206: 08055a85     4 FUNC    GLOBAL DEFAULT    1 mbed_error_initialize
  7207: 08043ce5   164 FUNC    GLOBAL DEFAULT    1 mriDebugMonitorHandler
  7208: 0805295f    18 FUNC    GLOBAL DEFAULT    1 _ZN14LinkedListBase7enque
  7209: 0805086d     6 FUNC    GLOBAL DEFAULT    1 osRtxIdleThread
  7210: 0804a531    36 FUNC    GLOBAL DEFAULT    1 mriBuffer_WriteChar
  7211: 08063bbd    32 FUNC    GLOBAL DEFAULT    1 _ZSt25__throw_bad_functio
  7212: 08043e6d    24 FUNC    WEAK   DEFAULT    1 _ZN7arduino3RPC4peekEv
  7213: 24011db0     4 OBJECT  WEAK   DEFAULT    6 _ZGVNSt8time_getIwSt19ist
  7214: 08060fa5    16 FUNC    GLOBAL DEFAULT    1 lp_ticker_read
  7215: 0805f291     2 FUNC    WEAK   DEFAULT    1 QUADSPI_IRQHandler
  7216: 08045c89    20 FUNC    WEAK   DEFAULT    1 _ZN10clmdep_fmt11FormatEr
  7217: 0806542d   340 FUNC    GLOBAL DEFAULT    1 __sflush_r
  7218: 24011e10     4 OBJECT  WEAK   DEFAULT    6 _ZGVNSt7__cxx1110moneypun
  7219: 24001a30     4 OBJECT  GLOBAL DEFAULT    4 __malloc_trim_threshold
  7220: 08063325    66 FUNC    GLOBAL DEFAULT    1 _ZNK10__cxxabiv117__class
  7221: 08050a4d    12 FUNC    GLOBAL DEFAULT    1 OS_Tick_AcknowledgeIRQ
  7222: 0804e541    92 FUNC    GLOBAL DEFAULT    1 osEventFlagsWait
  7223: 08043aa1     6 FUNC    GLOBAL DEFAULT    1 mriPlatform_GetDeviceMemo
  7224: 08055031   228 FUNC    WEAK   DEFAULT    1 _ZN4mbed8internal8SysTime
  7225: 0805f291     2 FUNC    WEAK   DEFAULT    1 SPI5_IRQHandler
  7226: 080426cd    12 FUNC    GLOBAL DEFAULT    1 mriMemManagementHandlerSt
  7227: 08050515   116 FUNC    GLOBAL DEFAULT    1 osThreadFlagsSet
  7228: 08054cf5    80 FUNC    GLOBAL DEFAULT    1 _ZN4mbed8FilePathC2EPKc
  7229: 0805f291     2 FUNC    WEAK   DEFAULT    1 HRTIM1_TIME_IRQHandler
  7230: 080522d1   142 FUNC    GLOBAL DEFAULT    1 _ZN4mbed10SerialBase13ena
  7231: 08051b21    72 FUNC    GLOBAL DEFAULT    1 pbuf_take
  7232: 2400383c   468 OBJECT  GLOBAL DEFAULT    6 mriCortexMState
  7233: 0805202d   108 FUNC    GLOBAL DEFAULT    1 _ZN4mbed10SerialBaseC2E7P
  7234: 0806e74c    41 OBJECT  WEAK   DEFAULT    1 _ZTSN14clmdep_msgpack2v11
  7235: 08052389    40 FUNC    GLOBAL DEFAULT    1 _ZN4mbed10TickerBaseC1EPK
  7236: 08052625     6 FUNC    WEAK   DEFAULT    1 _ZThn124_N4mbed16Unbuffer
  7237: 08050921    20 FUNC    GLOBAL DEFAULT    1 EvrRtxSemaphoreError
  7238: 08045c5f    22 FUNC    WEAK   DEFAULT    1 _ZN10clmdep_fmt8internal1
  7239: 080533bf    62 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice4initEv
  7240: 08043a6d    32 FUNC    GLOBAL DEFAULT    1 mriPlatform_CommReceiveCh
  7241: 24011cec     1 OBJECT  GLOBAL DEFAULT    6 future_event_flag
  7242: 24003a2c     4 OBJECT  GLOBAL DEFAULT    6 mriThreadOrigUsageFault
  7243: 0805250f    22 FUNC    GLOBAL DEFAULT    1 _ZN4mbed13LowPowerTimerC1
  7244: 08045d89    20 FUNC    WEAK   DEFAULT    1 _ZN10clmdep_fmt11FormatEr
  7245: 080600cd    14 FUNC    GLOBAL DEFAULT    1 HAL_PCD_SuspendCallback
  7246: 080717fc   156 OBJECT  WEAK   DEFAULT    1 PinMap_I2C_SCL
  7247: 080607c9    38 FUNC    GLOBAL DEFAULT    1 i2c_slave_address
  7248: 0804c0ad    36 FUNC    WEAK   DEFAULT    1 _ZN4mbed3I2CD1Ev
  7249: 08044075    20 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v117s
  7250: 0804cf51    88 FUNC    GLOBAL DEFAULT    1 _ZN7arduino6USBCDC12_rece
  7251: 24011eb8     1 OBJECT  GLOBAL DEFAULT    6 __lock___dd_hash_mutex
  7252: 24011ebc     1 OBJECT  GLOBAL DEFAULT    6 __lock___tz_mutex
  7253: 24000004   201 OBJECT  WEAK   DEFAULT    4 _ZN10clmdep_fmt8internal9
  7254: 2400f275   259 OBJECT  GLOBAL DEFAULT    6 memp_memory_SYS_TIMEOUT_b
  7255: 2400dca4    68 OBJECT  GLOBAL DEFAULT    6 _main_obj
  7256: 08060435    44 FUNC    GLOBAL DEFAULT    1 gpio_set
  7257: 0804db69    22 FUNC    GLOBAL DEFAULT    1 _ZN7arduino6String10inval
  7258: 0805ec81     8 FUNC    GLOBAL DEFAULT    1 USB_GetMode
  7259: 0805262d    20 FUNC    WEAK   DEFAULT    1 _ZN4mbed16UnbufferedSeria
  7260: 0805faa9     8 FUNC    GLOBAL DEFAULT    1 _ZN8USBPhyHw14endpoint_ta
  7261: 08071748    96 OBJECT  WEAK   DEFAULT    1 PinMap_CAN_RD
  7262: 08070080    12 OBJECT  WEAK   DEFAULT    1 _ZZN4mbed8CallbackIFvvEE8
  7263: 0805f291     2 FUNC    WEAK   DEFAULT    1 EXTI9_5_IRQHandler
  7264: 08053e2f    20 FUNC    GLOBAL DEFAULT    1 _ZN6events10EventQueueD1E
  7265: 24001078     4 OBJECT  GLOBAL DEFAULT    4 SystemD2Clock
  7266: 240046f4   316 OBJECT  GLOBAL DEFAULT    6 _UART_USB_
  7267: 08053cc1    70 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice10disconnect
  7268: 080555d3    18 FUNC    GLOBAL DEFAULT    1 core_util_atomic_exchange
  7269: 08050739    12 FUNC    GLOBAL DEFAULT    1 __rtos_malloc_unlock
  7270: 08063bdd     8 FUNC    GLOBAL DEFAULT    1 _ZNKSt20bad_array_new_len
  7271: 0804c81f    52 FUNC    GLOBAL DEFAULT    1 _ZN7arduino18PluggableUSB
  7272: 0804a45b     6 FUNC    GLOBAL DEFAULT    1 mriBuffer_Reset
  7273: 08064ef1    34 FUNC    GLOBAL HIDDEN     1 ___Unwind_ForcedUnwind
  7274: 0804cd7f     4 FUNC    GLOBAL DEFAULT    1 _ZN7arduino6USBCDC22callb
  7275: 08066cc5    44 FUNC    GLOBAL DEFAULT    1 _open_r
  7276: 0806f96c    12 OBJECT  WEAK   DEFAULT    1 _ZZN4mbed8CallbackIFvvEE8
  7277: 080525a3     6 FUNC    WEAK   DEFAULT    1 _ZThn124_N4mbed16Unbuffer
  7278: 08050f13     6 FUNC    GLOBAL DEFAULT    1 _ZN10STM32_EMAC18set_memo
  7279: 0805f291     2 FUNC    WEAK   DEFAULT    1 DMAMUX2_OVR_IRQHandler
  7280: 0804d519     6 FUNC    WEAK   DEFAULT    1 _ZN4mbed10FileHandle8trun
  7281: 24011ced     1 OBJECT  GLOBAL DEFAULT    6 lp_Fired
  7282: 240014b8   364 OBJECT  GLOBAL DEFAULT    4 __global_locale
  7283: 080470f5    78 FUNC    WEAK   DEFAULT    1 _ZN10clmdep_fmt11BasicWri
  7284: 0804d541     2 FUNC    WEAK   DEFAULT    1 _ZN4mbed6Stream4lockEv
  7285: 08064ef1    34 FUNC    GLOBAL HIDDEN     1 _Unwind_ForcedUnwind
  7286: 08064dd5     0 FUNC    GLOBAL HIDDEN     1 __gnu_Unwind_Restore_WMMX
  7287: 080460f5    24 FUNC    WEAK   DEFAULT    1 _ZSt4copyIPKcPcET0_T_S4_S
  7288: 08055305   164 FUNC    GLOBAL DEFAULT    1 mbed_fault_handler
  7289: 0804ea4d    48 FUNC    WEAK   DEFAULT    1 osRtxMemoryInit
  7290: 080446a5    22 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v26pa
  7291: 0805268b     8 FUNC    GLOBAL DEFAULT    1 _ZThn124_N4mbed16Unbuffer
  7292: 08050729    16 FUNC    GLOBAL DEFAULT    1 __rtos_malloc_lock
  7293: 08047ff9   116 FUNC    WEAK   DEFAULT    1 _ZNK14clmdep_msgpack2v26o
  7294: 08062299     2 FUNC    GLOBAL DEFAULT    1 _ZNSt9exceptionD2Ev
  7295: 0804b1e9    72 FUNC    GLOBAL DEFAULT    1 mriCmd_HandleIsThreadActi
  7296: 08050ad1    36 FUNC    WEAK   DEFAULT    1 _ZN6events10EventQueue13f
  7297: 08055115    16 FUNC    WEAK   DEFAULT    1 _ZN4mbed8internal8SysTime
  7298: 0805f291     2 FUNC    WEAK   DEFAULT    1 RCC_IRQHandler
  7299: 0804fbe5    36 FUNC    GLOBAL DEFAULT    1 osRtxThreadListPut
  7300: 0806568d    88 FUNC    GLOBAL DEFAULT    1 __sinit
  7301: 0804d18d    20 FUNC    GLOBAL DEFAULT    1 _ZN7arduino6USBCDC14callb
  7302: 08043205    60 FUNC    GLOBAL DEFAULT    1 mriPlatform_ClearHardware
  7303: 0805f291     2 FUNC    WEAK   DEFAULT    1 HRTIM1_TIMC_IRQHandler
  7304: 08049f43    12 FUNC    GLOBAL DEFAULT    1 virtqueue_notification
  7305: 08045d3b     8 FUNC    WEAK   DEFAULT    1 _ZN10clmdep_fmt8internal7
  7306: 0805ecf5   228 FUNC    WEAK   DEFAULT    1 SystemInit
  7307: 08056081     4 FUNC    GLOBAL DEFAULT    1 _close
  7308: 08074b94     0 NOTYPE  GLOBAL DEFAULT    3 __etext
  7309: 080633ed     4 FUNC    GLOBAL DEFAULT    1 _ZSt18_Rb_tree_decrementP
  7310: 0804dc6b    48 FUNC    GLOBAL DEFAULT    1 _ZNK7arduino6String8getBy
  7311: 0805682d    52 FUNC    GLOBAL DEFAULT    1 _ZN4rtos5Mutex6unlockEv
  7312: 0804bf2d   108 FUNC    GLOBAL DEFAULT    1 mriPacket_SendToGDB
  7313: 080497f7    20 FUNC    GLOBAL DEFAULT    1 rpmsg_virtio_init_shm_poo
  7314: 0806ca01   330 FUNC    GLOBAL DEFAULT    1 __multiply
  7315: 0804649d   228 FUNC    WEAK   DEFAULT    1 _ZN10clmdep_fmt14BasicFor
  7316: 08066931     0 FUNC    GLOBAL DEFAULT    1 memchr
  7317: 08061a55   232 FUNC    GLOBAL DEFAULT    1 serial_baud
  7318: 2400f96c    40 OBJECT  GLOBAL DEFAULT    6 _ZN4mbed8AnalogIn6_mutexE
  7319: 08045c75    20 FUNC    WEAK   DEFAULT    1 _ZN10clmdep_fmt11FormatEr
  7320: 0805f291     2 FUNC    WEAK   DEFAULT    1 UART4_IRQHandler
  7321: 08063805    16 FUNC    WEAK   DEFAULT    1 _ZNSt7__cxx1112basic_stri
  7322: 08070298    24 OBJECT  GLOBAL DEFAULT    1 _ZTVN4mbed3I2CE
  7323: 08052a69    18 FUNC    GLOBAL DEFAULT    1 _ZN17OperationListBaseD2E
  7324: 08053e4b   110 FUNC    GLOBAL DEFAULT    1 equeue_create_inplace
  7325: 0804ac81    88 FUNC    GLOBAL DEFAULT    1 mriCmd_HandleBinaryMemory
  7326: 0806e698    12 OBJECT  WEAK   DEFAULT    1 _ZTIN14clmdep_msgpack2v11
  7327: 0806b921    36 FUNC    GLOBAL DEFAULT    1 _close_r
  7328: 080415ed    72 FUNC    GLOBAL DEFAULT    1 _Z8RTC_InitP8LOITRUCK
  7329: 08055e0d     4 FUNC    WEAK   DEFAULT    1 _ZN12DirectSerial6isattyE
  7330: 08072790    16 OBJECT  GLOBAL DEFAULT    1 _ZTSSt11logic_error
  7331: 0805df79   170 FUNC    GLOBAL DEFAULT    1 UART_AdvFeatureConfig
  7332: 24010900     4 OBJECT  GLOBAL DEFAULT    6 _ZN16QSPIFBlockDevice28_a
  7333: 24000000     0 NOTYPE  GLOBAL DEFAULT    4 __data_start__
  7334: 0804d92d     8 FUNC    GLOBAL DEFAULT    1 _ZThn1216_N7arduino9USBSe
  7335: 08048c7b    72 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v16pa
  7336: 08043f45    32 FUNC    GLOBAL DEFAULT    1 _ZN7arduino3RPC5writeEh
  7337: 08041355   104 FUNC    GLOBAL DEFAULT    1 _Z11Set_CAN_PinP5can_s7Pi
  7338: 0806ebdc    12 OBJECT  WEAK   DEFAULT    1 _ZTIN10clmdep_fmt11Format
  7339: 0804d441    42 FUNC    GLOBAL DEFAULT    1 _ZN7arduino6USBCDC18_rece
  7340: 0804c45d    80 FUNC    GLOBAL DEFAULT    1 _ZN7arduino4UART5writeEPK
  7341: 08051089    54 FUNC    GLOBAL DEFAULT    1 _Z25_phy_get_duplex_and_s
  7342: 08052959     2 FUNC    GLOBAL DEFAULT    1 _ZN14LinkedListBaseD2Ev
  7343: 24011d74     4 OBJECT  GLOBAL DEFAULT    6 timer_cnt_reg
  7344: 08051201    22 FUNC    GLOBAL DEFAULT    1 _ZN10STM32_EMAC17enable_i
  7345: 08040707   120 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v16pa
  7346: 24011e9c     4 OBJECT  GLOBAL DEFAULT    6 mriExceptionCode
  7347: 08049ac5   336 FUNC    GLOBAL DEFAULT    1 rpmsg_init_vdev
  7348: 08062e9d   176 FUNC    GLOBAL DEFAULT    1 __cxa_type_match
  7349: 080562fb     4 FUNC    GLOBAL DEFAULT    1 _lseek
  7350: 0804404d    20 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v117e
  7351: 08050b21    30 FUNC    WEAK   DEFAULT    1 _ZN4mbed8CallbackIFvvEE11
  7352: 08054505    80 FUNC    GLOBAL DEFAULT    1 gpio_init_inout
  7353: 0804bac1    78 FUNC    GLOBAL DEFAULT    1 mriMem_WriteBinaryBufferT
  7354: 08055e15     2 FUNC    WEAK   DEFAULT    1 _ZN12DirectSerialD1Ev
  7355: 08049509    42 FUNC    GLOBAL DEFAULT    1 rproc_virtio_init_vring
  7356: 08057ab9    28 FUNC    GLOBAL DEFAULT    1 HAL_NVIC_EnableIRQ
  7357: 24011e20     4 OBJECT  WEAK   DEFAULT    6 _ZGVNSt8time_getIcSt19ist
  7358: 08056ca1    20 FUNC    GLOBAL DEFAULT    1 HAL_SYSCFG_ETHInterfaceSe
  7359: 0806f274     8 OBJECT  WEAK   DEFAULT    1 _ZTIN3rpc6detail13handler
  7360: 08070184    12 OBJECT  GLOBAL DEFAULT    1 memp_PBUF_POOL
  7361: 080622a1     8 FUNC    GLOBAL DEFAULT    1 _ZNKSt13bad_exception4wha
  7362: 0804d0e5   168 FUNC    GLOBAL DEFAULT    1 _ZN7arduino6USBCDC26_chan
  7363: 080551c9    74 FUNC    GLOBAL DEFAULT    1 Fault_Handler
  7364: 08070320   140 OBJECT  GLOBAL DEFAULT    1 _ZTVN4mbed16UnbufferedSer
  7365: 080426f1    16 FUNC    GLOBAL DEFAULT    1 mriRTXHandlerStub
  7366: 08055efd    44 FUNC    WEAK   DEFAULT    1 _sbrk
  7367: 0805f290     2 NOTYPE  GLOBAL DEFAULT    1 Default_Handler
  7368: 2400dcec    28 OBJECT  GLOBAL DEFAULT    6 singleton_mutex_obj
  7369: 0804dbef    36 FUNC    GLOBAL DEFAULT    1 _ZN7arduino6StringC1EPKc
  7370: 08043aa9     8 FUNC    GLOBAL DEFAULT    1 mriPlatform_GetDeviceMemo
  7371: 080727b4    18 OBJECT  GLOBAL DEFAULT    1 _ZTSSt13runtime_error
  7372: 0805fbad    32 FUNC    GLOBAL DEFAULT    1 _ZN8USBPhyHw15endpoint_re
  7373: 24011dcc     4 OBJECT  WEAK   DEFAULT    6 _ZGVNSt9money_getIwSt19is
  7374: 0804d53f     2 FUNC    WEAK   DEFAULT    1 _ZN4mbed10FileHandle5sigi
  7375: 0804211b    26 FUNC    GLOBAL DEFAULT    1 _Z10find_valuePP3SDOm
  7376: 08065581    90 FUNC    GLOBAL DEFAULT    1 _fflush_r
  7377: 080525b5     4 FUNC    WEAK   DEFAULT    1 _ZThn124_N4mbed16Unbuffer
  7378: 24000240    64 OBJECT  GLOBAL DEFAULT    4 g_AAnalogPinDescription
  7379: 0805f291     2 FUNC    WEAK   DEFAULT    1 ETH_WKUP_IRQHandler
  7380: 08063be5    20 FUNC    GLOBAL DEFAULT    1 _ZNSt20bad_array_new_leng
  7381: 08054d9b     4 FUNC    GLOBAL DEFAULT    1 _ZN4mbed6Stream6isattyEv
  7382: 0804c0e5    60 FUNC    GLOBAL DEFAULT    1 _Z12fixup3V1Railv
  7383: 0804530d   296 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v28un
  7384: 08061991    32 FUNC    GLOBAL DEFAULT    1 serial_readable
  7385: 0806e864    20 OBJECT  WEAK   DEFAULT    1 _ZTVN14clmdep_msgpack2v11
  7386: 08053e2f    20 FUNC    GLOBAL DEFAULT    1 _ZN6events10EventQueueD2E
  7387: 080426c1    12 FUNC    GLOBAL DEFAULT    1 mriHardFaultHandlerStub
  7388: 2400f964     1 OBJECT  GLOBAL DEFAULT    6 pbuf_free_ooseq_pending
  7389: 0805830b   178 FUNC    GLOBAL DEFAULT    1 HAL_ETH_Transmit
  7390: 0806b80d    26 FUNC    GLOBAL DEFAULT    1 __ascii_wctomb
  7391: 0806fbe0    56 OBJECT  GLOBAL DEFAULT    1 os_cb_sections
  7392: 0806f254    29 OBJECT  WEAK   DEFAULT    1 _ZTSN3rpc6detail13handler
  7393: 0805f291     2 FUNC    WEAK   DEFAULT    1 TIM4_IRQHandler
  7394: 08058a69   540 FUNC    GLOBAL DEFAULT    1 HAL_ETH_Init
  7395: 0805101d    30 FUNC    GLOBAL DEFAULT    1 _ZN10STM32_EMAC17set_link
  7396: 08052231    18 FUNC    GLOBAL DEFAULT    1 _ZN4mbed10SerialBase12_ir
  7397: 0804d99f    62 FUNC    GLOBAL DEFAULT    1 _ZNK7arduino9IPAddress7pr
  7398: 0804dd55    36 FUNC    GLOBAL DEFAULT    1 millis
  7399: 0806e800    20 OBJECT  WEAK   DEFAULT    1 _ZTVN14clmdep_msgpack2v11
  7400: 08055c15   108 FUNC    WEAK   DEFAULT    1 _ZN4mbed8internal18do_sle
  7401: 08062ce1    32 FUNC    GLOBAL DEFAULT    1 __cxa_throw_bad_array_new
  7402: 080622b9   164 FUNC    GLOBAL DEFAULT    1 _ZSt11_Hash_bytesPKvjj
  7403: 0805428d    48 FUNC    GLOBAL DEFAULT    1 equeue_tick
  7404: 080433d9    60 FUNC    GLOBAL DEFAULT    1 mriPlatform_EnteringDebug
  7405: 08052db9    72 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice26complete_r
  7406: 0804409d    20 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v117b
  7407: 0804c549    40 FUNC    GLOBAL DEFAULT    1 _ZN7arduino4UART9availabl
  7408: 0804c961    58 FUNC    GLOBAL DEFAULT    1 _ZN7arduino18PluggableUSB
  7409: 0806529d     6 FUNC    GLOBAL HIDDEN     1 _Unwind_GetDataRelBase
  7410: 08065939   488 FUNC    GLOBAL DEFAULT    1 _free_r
  7411: 080443dd   128 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v26de
  7412: 0804bd49   236 FUNC    GLOBAL DEFAULT    1 mriDebugException
  7413: 08063bf9    28 FUNC    GLOBAL DEFAULT    1 _ZNSt20bad_array_new_leng
  7414: 0805462d    24 FUNC    GLOBAL DEFAULT    1 pinmap_find_function
  7415: 0806e6dc    41 OBJECT  WEAK   DEFAULT    1 _ZTSN14clmdep_msgpack2v11
  7416: 08059aed    28 FUNC    GLOBAL DEFAULT    1 HAL_HSEM_FastTake
  7417: 08057b15    32 FUNC    GLOBAL DEFAULT    1 HAL_MPU_Enable
  7418: 0804fcd5    40 FUNC    WEAK   DEFAULT    1 osRtxThreadStackCheck
  7419: 08051ba9    80 FUNC    WEAK   DEFAULT    1 _ZNK12SingletonPtrIN4rtos
  7420: 0804cd85    20 FUNC    WEAK   DEFAULT    1 _ZN7arduino6USBCDC9AsyncW
  7421: 080544f3     4 FUNC    GLOBAL DEFAULT    1 gpio_init_in_ex
  7422: 0805e8bd    38 FUNC    GLOBAL DEFAULT    1 USB_WritePacket
  7423: 08054c35    20 FUNC    GLOBAL DEFAULT    1 _ZN4mbed8FileBaseD0Ev
  7424: 0805f291     2 FUNC    WEAK   DEFAULT    1 OTG_FS_EP1_OUT_IRQHandler
  7425: 0805455d    20 FUNC    GLOBAL DEFAULT    1 lp_ticker_irq_handler
  7426: 08054ef1     6 FUNC    WEAK   DEFAULT    1 _ZN4mbed8internal8SysTime
  7427: 08056bf1    92 FUNC    GLOBAL DEFAULT    1 HAL_Init
  7428: 0804e5cd     2 FUNC    WEAK   DEFAULT    1 EvrRtxThreadPriorityUpdat
  7429: 24011cf8     4 OBJECT  GLOBAL DEFAULT    6 mbed_sdk_inited
  7430: 0805b3e3    16 FUNC    GLOBAL DEFAULT    1 HAL_PCD_EP_GetRxCount
  7431: 08051d69    66 FUNC    GLOBAL DEFAULT    1 _ZN4mbed3I2C5writeEiPKcib
  7432: 0806762d    16 FUNC    GLOBAL DEFAULT    1 raise
  7433: 080545b9    48 FUNC    GLOBAL DEFAULT    1 pinmap_merge
  7434: 08056c95    12 FUNC    GLOBAL DEFAULT    1 HAL_GetUIDw2
  7435: 08070160    12 OBJECT  GLOBAL DEFAULT    1 memp_NETBUF
  7436: 24011e40     4 OBJECT  WEAK   DEFAULT    6 _ZGVNSt10moneypunctIcLb1E
  7437: 0805b2a5    40 FUNC    GLOBAL DEFAULT    1 HAL_PCD_SetAddress
  7438: 0804d935     6 FUNC    GLOBAL DEFAULT    1 _ZN7arduino9USBSerial9con
  7439: 24011dd8     4 OBJECT  WEAK   DEFAULT    6 _ZGVNSt7__cxx117collateIc
  7440: 0805f9b1   228 FUNC    GLOBAL DEFAULT    1 serial_set_flow_control
  7441: 0805259d     6 FUNC    WEAK   DEFAULT    1 _ZN4mbed16UnbufferedSeria
  7442: 08054b89     4 FUNC    GLOBAL DEFAULT    1 _ZN4mbed8FileBase11getPat
  7443: 24000198   124 OBJECT  GLOBAL DEFAULT    4 shm_device
  7444: 08044c71   212 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v26de
  7445: 08048361   620 FUNC    GLOBAL DEFAULT    1 _ZN3rpc6detail10dispatche
  7446: 0805bfe5    36 FUNC    GLOBAL DEFAULT    1 HAL_RCC_GetPCLK1Freq
  7447: 0805f291     2 FUNC    WEAK   DEFAULT    1 USART3_IRQHandler
  7448: 0804b7b3    76 FUNC    GLOBAL DEFAULT    1 mriContext_CopyFromBuffer
  7449: 24010660     4 OBJECT  GLOBAL DEFAULT    6 _ZN10CThunkBase17_cthunk_
  7450: 0805963d     2 FUNC    WEAK   DEFAULT    1 HAL_FDCAN_RxFifo1Callback
  7451: 0805f291     2 FUNC    WEAK   DEFAULT    1 FPU_IRQHandler
  7452: 08052b15    32 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice13start_proc
  7453: 080530bd   120 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice19_request_g
  7454: 0806e6d0    12 OBJECT  WEAK   DEFAULT    1 _ZTIN14clmdep_msgpack2v11
  7455: 08048171   136 FUNC    GLOBAL DEFAULT    1 _ZN3rpc6detail10dispatche
  7456: 08056363    60 FUNC    GLOBAL DEFAULT    1 fstat
  7457: 0806527d    10 FUNC    GLOBAL HIDDEN     1 _Unwind_GetRegionStart
  7458: 08067789   732 FUNC    GLOBAL DEFAULT    1 strcmp
  7459: 0804fc1b    18 FUNC    GLOBAL DEFAULT    1 osRtxThreadListRemove
  7460: 08052b05     8 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice22string_iin
  7461: 080551bb     6 FUNC    GLOBAL DEFAULT    1 MemManage_Handler
  7462: 08061c25   604 FUNC    GLOBAL DEFAULT    1 serial_init
  7463: 080524b3    38 FUNC    GLOBAL DEFAULT    1 _ZN4mbed9TimerBase5resetE
  7464: 0804969d   244 FUNC    GLOBAL DEFAULT    1 rpmsg_create_ept
  7465: 0804db0f     4 FUNC    GLOBAL DEFAULT    1 _ZN7arduino5Print5printEi
  7466: 24003a10     4 OBJECT  GLOBAL DEFAULT    6 mriThreadId
  7467: 08051c91    26 FUNC    GLOBAL DEFAULT    1 _ZN4mbed12DigitalInOut6ou
  7468: 080602a5   400 FUNC    GLOBAL DEFAULT    1 Set_GPIO_Clock
  7469: 0804c06d     4 FUNC    GLOBAL DEFAULT    1 mriPlatform_MemRead32
  7470: 0804fc61    96 FUNC    GLOBAL DEFAULT    1 osRtxThreadDelayTick
  7471: 080503e5    40 FUNC    GLOBAL DEFAULT    1 osThreadGetId
  7472: 0805e30d   148 FUNC    GLOBAL DEFAULT    1 USB_CoreInit
  7473: 080646cd    68 FUNC    GLOBAL HIDDEN     1 __gnu_Unwind_Resume
  7474: 24011d20     4 OBJECT  GLOBAL DEFAULT    6 stdio_uart_inited
  7475: 2400e1b6   131 OBJECT  GLOBAL DEFAULT    6 memp_memory_NETBUF_base
  7476: 0805e249    86 FUNC    GLOBAL DEFAULT    1 FMC_NORSRAM_Timing_Init
  7477: 08043f65    32 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v16de
  7478: 0805fc69    36 FUNC    GLOBAL DEFAULT    1 _ZN8USBPhyHw14endpoint_st
  7479: 080589d9    24 FUNC    GLOBAL DEFAULT    1 HAL_ETH_SetMACConfig
  7480: 0804c99d    44 FUNC    GLOBAL DEFAULT    1 _ZN7arduino18PluggableUSB
  7481: 080668fd    42 FUNC    GLOBAL DEFAULT    1 __ascii_mbtowc
  7482: 08059651     2 FUNC    WEAK   DEFAULT    1 HAL_FDCAN_TT_GlobalTimeCa
  7483: 0805341d    50 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice7connectEv
  7484: 0805f291     2 FUNC    WEAK   DEFAULT    1 I2C3_ER_IRQHandler
  7485: 08072698    12 OBJECT  GLOBAL DEFAULT    1 _ZTIN10__cxxabiv120__si_c
  7486: 0805d3b9    20 FUNC    GLOBAL DEFAULT    1 HAL_RCCEx_EnableBootCore
  7487: 08074b94     0 NOTYPE  GLOBAL DEFAULT    3 _sidata
  7488: 08065341    12 FUNC    GLOBAL DEFAULT    1 __errno
  7489: 08056ab5    66 FUNC    GLOBAL DEFAULT    1 _ZN4rtos6Thread9terminate
  7490: 080663b5  1352 FUNC    GLOBAL DEFAULT    1 _malloc_r
  7491: 0805d971   204 FUNC    GLOBAL DEFAULT    1 TIM_Base_SetConfig
  7492: 08060461    64 FUNC    GLOBAL DEFAULT    1 gpio_init
  7493: 08050f0f     2 FUNC    GLOBAL DEFAULT    1 _ZN10STM32_EMAC19add_mult
  7494: 08040000     0 OBJECT  GLOBAL DEFAULT    1 g_pfnVectors
  7495: 0805964d     2 FUNC    WEAK   DEFAULT    1 HAL_FDCAN_TT_TimeMarkCall
  7496: 08053d39    68 FUNC    GLOBAL DEFAULT    1 _ZN9USBDeviceD2Ev
  7497: 0806e660    12 OBJECT  WEAK   DEFAULT    1 _ZTIN14clmdep_msgpack2v11
  7498: 24011db4     4 OBJECT  WEAK   DEFAULT    6 _ZGVNSt8time_putIwSt19ost
  7499: 08051ebd   120 FUNC    GLOBAL DEFAULT    1 _ZN4mbed3I2CC1E7PinNameS1
  7500: 08052559    20 FUNC    GLOBAL DEFAULT    1 _ZN4mbed10TimerEvent15ins
  7501: 08045c75    20 FUNC    WEAK   DEFAULT    1 _ZN10clmdep_fmt11FormatEr
  7502: 080568a5    16 FUNC    GLOBAL DEFAULT    1 _ZN4rtos9SemaphoreC1El
  7503: 08051495    24 FUNC    GLOBAL DEFAULT    1 HAL_ETH_RxCpltCallback
  7504: 0804cba9     4 FUNC    WEAK   DEFAULT    1 _ZN7arduino18PluggableUSB
  7505: 08062e71    16 FUNC    GLOBAL DEFAULT    1 _ZSt13get_terminatev
  7506: 0804e481    48 FUNC    GLOBAL DEFAULT    1 osEventFlagsNew
  7507: 08049687    22 FUNC    GLOBAL DEFAULT    1 rpmsg_register_endpoint
  7508: 0804420d    28 FUNC    WEAK   DEFAULT    1 _ZN4mbed8CallbackIFvvEE11
  7509: 0806d670    12 OBJECT  WEAK   DEFAULT    1 _ZZN4mbed8CallbackIFvvEE8
  7510: 24001a2c     4 OBJECT  GLOBAL DEFAULT    4 __malloc_sbrk_base
  7511: 08047e65     2 FUNC    WEAK   DEFAULT    1 _ZNSt19_Sp_counted_delete
  7512: 0805f291     2 FUNC    WEAK   DEFAULT    1 TIM5_IRQHandler
  7513: 0804cb17    18 FUNC    GLOBAL DEFAULT    1 _ZN7arduino18PluggableUSB
  7514: 08064659    94 FUNC    GLOBAL HIDDEN     1 __gnu_Unwind_RaiseExcepti
  7515: 08043ffd    20 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v119a
  7516: 080635a5    18 FUNC    GLOBAL DEFAULT    1 _ZNSt11logic_errorD0Ev
  7517: 0805f291     2 FUNC    WEAK   DEFAULT    1 BDMA_Channel6_IRQHandler
  7518: 24011df8     4 OBJECT  WEAK   DEFAULT    6 _ZGVNSt7__cxx117collateIw
  7519: 0804c1c7    76 FUNC    GLOBAL DEFAULT    1 _ZN7arduino4UART5beginEmt
  7520: 080474f1   196 FUNC    WEAK   DEFAULT    1 _ZN10clmdep_fmt8internal1
  7521: 080619c9   140 FUNC    GLOBAL DEFAULT    1 init_uart
  7522: 0805fd8d   524 FUNC    GLOBAL DEFAULT    1 _ZN8USBPhyHw4initEP12USBP
  7523: 08070314    12 OBJECT  WEAK   DEFAULT    1 _ZTVN4mbed10TimerEventE
  7524: 0805b513    50 FUNC    GLOBAL DEFAULT    1 HAL_PCD_EP_Flush
  7525: 08060f59    66 FUNC    GLOBAL DEFAULT    1 HAL_I2C_ErrorCallback
  7526: 08048709    18 FUNC    GLOBAL DEFAULT    1 _ZNK3rpc6detail8response1
  7527: 080657a1    40 FUNC    GLOBAL DEFAULT    1 fiprintf
  7528: 24011e78     4 OBJECT  GLOBAL DEFAULT    6 __malloc_top_pad
  7529: 0804eb99    72 FUNC    GLOBAL DEFAULT    1 osRtxMemoryPoolFree
  7530: 0804cad7    64 FUNC    GLOBAL DEFAULT    1 _ZN7arduino18PluggableUSB
  7531: 0806e7ec    20 OBJECT  WEAK   DEFAULT    1 _ZTVN14clmdep_msgpack2v11
  7532: 24000214    44 OBJECT  WEAK   DEFAULT    4 metal_generic_bus
  7533: 0806138d     2 FUNC    WEAK   DEFAULT    1 TargetBSP_Init
  7534: 08051c55    40 FUNC    GLOBAL DEFAULT    1 _ZN4mbed8AnalogInC1E7PinN
  7535: 0806f93c    24 OBJECT  WEAK   DEFAULT    1 _ZTVN7arduino6USBCDC9Asyn
  7536: 08050b65    12 FUNC    WEAK   DEFAULT    1 _ZN27whd_interface_shared
  7537: 0804c681    28 FUNC    WEAK   DEFAULT    1 _ZN7arduino11RingBufferNI
  7538: 08056c4d    36 FUNC    WEAK   DEFAULT    1 HAL_Delay
  7539: 08072710    12 OBJECT  GLOBAL DEFAULT    1 _ZTIN10__cxxabiv117__clas
  7540: 0804d70b     8 FUNC    GLOBAL DEFAULT    1 _ZThn1196_N7arduino9USBSe
  7541: 080635e9    64 FUNC    GLOBAL DEFAULT    1 _ZNSt13runtime_errorD1Ev
  7542: 08056d17    82 FUNC    GLOBAL DEFAULT    1 HAL_EXTI_D2_EventInputCon
  7543: 0805aa21     2 FUNC    WEAK   DEFAULT    1 HAL_LPTIM_MspInit
  7544: 08054e5d    52 FUNC    GLOBAL DEFAULT    1 _ZN4mbed6StreamD2Ev
  7545: 0805f291     2 FUNC    WEAK   DEFAULT    1 RNG_IRQHandler
  7546: 08051f39    88 FUNC    GLOBAL DEFAULT    1 _ZN4mbed10SerialBase5_ini
  7547: 0804404d    20 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v117e
  7548: 0804a0c5    60 FUNC    GLOBAL DEFAULT    1 metal_register_generic_de
  7549: 080446bb    44 FUNC    WEAK   DEFAULT    1 _ZNSt14__shared_countILN9
  7550: 08056735    22 FUNC    GLOBAL DEFAULT    1 _ZN4rtos10EventFlags8wait
  7551: 0805ec3d    16 FUNC    GLOBAL DEFAULT    1 USB_ReadDevAllInEpInterru
  7552: 08070308    12 OBJECT  GLOBAL DEFAULT    1 _ZTVN4mbed10TickerBaseE
  7553: 08071d48    36 OBJECT  WEAK   DEFAULT    1 PinMap_USB_FS
  7554: 0805f291     2 FUNC    WEAK   DEFAULT    1 TAMP_STAMP_IRQHandler
  7555: 0805258d     4 FUNC    WEAK   DEFAULT    1 _ZN4mbed10FileHandle4sync
  7556: 080551b5     6 FUNC    GLOBAL DEFAULT    1 HardFault_Handler
  7557: 0805dbd9     2 FUNC    WEAK   DEFAULT    1 HAL_UART_MspInit
  7558: 08055435   156 FUNC    GLOBAL DEFAULT    1 malloc_wrapper
  7559: 0804da69    20 FUNC    GLOBAL DEFAULT    1 _ZN7arduino5Print7println
  7560: 08047e79    14 FUNC    WEAK   DEFAULT    1 _ZNSt19_Sp_counted_delete
  7561: 0804c571    46 FUNC    WEAK   DEFAULT    1 _ZN7arduino9USBSerial4pee
  7562: 0805b545    64 FUNC    GLOBAL DEFAULT    1 HAL_PCDEx_SetTxFiFo
  7563: 08042e49    16 FUNC    GLOBAL DEFAULT    1 mriPlatform_IsSingleStepp
  7564: 0804d51f    12 FUNC    WEAK   DEFAULT    1 _ZN4mbed10FileHandle12set
  7565: 08045ba1    22 FUNC    WEAK   DEFAULT    1 _ZN7arduino14SerialRPCCla
  7566: 08060cd5   368 FUNC    GLOBAL DEFAULT    1 i2c_init_internal
  7567: 0805f989    40 FUNC    GLOBAL DEFAULT    1 serial_putc
  7568: 080663a5    16 FUNC    GLOBAL DEFAULT    1 free
  7569: 0804270d    12 FUNC    GLOBAL DEFAULT    1 mriPendSVHandlerStub
  7570: 0805235f    40 FUNC    GLOBAL DEFAULT    1 _ZN4mbed10TickerBase7hand
  7571: 0805f291     2 FUNC    WEAK   DEFAULT    1 DMA1_Stream4_IRQHandler
  7572: 080546f7    40 FUNC    GLOBAL DEFAULT    1 _ticker_match_interval_pa
  7573: 0806e62c    12 OBJECT  WEAK   DEFAULT    1 _ZTIN14clmdep_msgpack2v11
  7574: 08052a7f     6 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice3sofEi
  7575: 0806a169  5240 FUNC    GLOBAL DEFAULT    1 _vfprintf_r
  7576: 0805f229    24 FUNC    GLOBAL DEFAULT    1 SetSysClock
  7577: 0805e121    96 FUNC    GLOBAL DEFAULT    1 HAL_UART_Init
  7578: 080481f9    48 FUNC    WEAK   DEFAULT    1 _ZNSt14__shared_countILN9
  7579: 24011e70     4 OBJECT  GLOBAL DEFAULT    6 __malloc_max_sbrked_mem
  7580: 24011dd0     4 OBJECT  WEAK   DEFAULT    6 _ZGVNSt10moneypunctIwLb1E
  7581: 0804460f    14 FUNC    WEAK   DEFAULT    1 _ZNSt10unique_ptrIN14clmd
  7582: 0804b829     4 FUNC    GLOBAL DEFAULT    1 mriGdbConsole_WriteString
  7583: 0804e085    20 FUNC    GLOBAL DEFAULT    1 osSignalSet
  7584: 24003a28     4 OBJECT  GLOBAL DEFAULT    6 mriThreadOrigSysTick
  7585: 0804bc8d    16 FUNC    GLOBAL DEFAULT    1 mriCore_GetInitializedBuf
  7586: 08056d9d   284 FUNC    GLOBAL DEFAULT    1 HAL_ADC_PollForConversion
  7587: 0805295b     4 FUNC    GLOBAL DEFAULT    1 _ZN14LinkedListBase4headE
  7588: 0805963f     2 FUNC    WEAK   DEFAULT    1 HAL_FDCAN_TxFifoEmptyCall
  7589: 0804b03d   168 FUNC    GLOBAL DEFAULT    1 mriCmd_Send_T_StopRespons
  7590: 0805ad05     2 FUNC    WEAK   DEFAULT    1 HAL_PCD_ISOOUTIncompleteC
  7591: 08044d45    32 FUNC    WEAK   DEFAULT    1 _ZNSt6vectorIPN14clmdep_m
  7592: 08040605    56 FUNC    WEAK   DEFAULT    1 _ZNSt10unique_ptrIN14clmd
  7593: 24005c78     4 OBJECT  GLOBAL DEFAULT    6 mbed_stack_isr_size
  7594: 08054dcf    50 FUNC    GLOBAL DEFAULT    1 _ZN4mbed6Stream4readEPvj
  7595: 08054601    44 FUNC    GLOBAL DEFAULT    1 pinmap_peripheral
  7596: 0806f84c    52 OBJECT  GLOBAL DEFAULT    1 _ZTVN7arduino4UARTE
  7597: 0806e714    41 OBJECT  WEAK   DEFAULT    1 _ZTSN14clmdep_msgpack2v11
  7598: 0804aa29    28 FUNC    GLOBAL DEFAULT    1 mriCmd_ThrowIfNextCharIsN
  7599: 080676f9    34 FUNC    GLOBAL DEFAULT    1 __sread
  7600: 0804d71d   200 FUNC    GLOBAL DEFAULT    1 _ZN7arduino9USBSerialC2Eb
  7601: 0804dd7d    28 FUNC    GLOBAL DEFAULT    1 init
  7602: 24001624  1032 OBJECT  GLOBAL DEFAULT    4 __malloc_av_
  7603: 0805e689    22 FUNC    GLOBAL DEFAULT    1 USB_GetDevSpeed
  7604: 0804cbb9     2 FUNC    WEAK   DEFAULT    1 _ZN7arduino6USBCDC7data_t
  7605: 0805fa99     4 FUNC    GLOBAL DEFAULT    1 _ZN8USBPhyHw7poweredEv
  7606: 08052fb9    72 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice26complete_s
  7607: 0804eae7    60 FUNC    WEAK   DEFAULT    1 osRtxMemoryFree
  7608: 08047fa5    84 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v14ty
  7609: 08070154    12 OBJECT  GLOBAL DEFAULT    1 memp_IGMP_GROUP
  7610: 24011e00     4 OBJECT  WEAK   DEFAULT    6 _ZGVNSt7__cxx118time_getI
  7611: 08050391    48 FUNC    GLOBAL DEFAULT    1 osThreadNew
  7612: 0805ec5f    34 FUNC    GLOBAL DEFAULT    1 USB_ReadDevInEPInterrupt
  7613: 24001aa0     0 NOTYPE  GLOBAL DEFAULT    4 _edata
  7614: 080542c3     4 FUNC    GLOBAL DEFAULT    1 equeue_mutex_lock
  7615: 0806cbed   172 FUNC    GLOBAL DEFAULT    1 __lshift
  7616: 0806e8ac    12 OBJECT  WEAK   DEFAULT    1 _ZZN4mbed8CallbackIFvvEE8
  7617: 080562ff    46 FUNC    GLOBAL DEFAULT    1 fsync
  7618: 08043a59    20 FUNC    GLOBAL DEFAULT    1 mriPlatform_CommHasTransm
  7619: 0804d991     8 FUNC    GLOBAL DEFAULT    1 _Z10randomSeedm
  7620: 08053d7d    34 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice5powerEb
  7621: 08043269   100 FUNC    GLOBAL DEFAULT    1 mriPlatform_DisableSingle
  7622: 080542e7    22 FUNC    GLOBAL DEFAULT    1 equeue_sema_wait
  7623: 080620d1     8 FUNC    GLOBAL DEFAULT    1 us_ticker_get_info
  7624: 08054a69    40 FUNC    GLOBAL DEFAULT    1 ticker_read_us
  7625: 08056b49   136 FUNC    GLOBAL DEFAULT    1 _ZNK4rtos6Thread9get_stat
  7626: 08060295    12 FUNC    GLOBAL DEFAULT    1 FDCAN2_IT0_IRQHandler
  7627: 080567e1    14 FUNC    GLOBAL DEFAULT    1 _ZN4rtos5MutexC1Ev
  7628: 08051c55    40 FUNC    GLOBAL DEFAULT    1 _ZN4mbed8AnalogInC2E7PinN
  7629: 24011cfc    36 OBJECT  GLOBAL DEFAULT    6 stdio_uart
  7630: 08071a9c   348 OBJECT  WEAK   DEFAULT    1 PinMap_UART_RX
  7631: 0804d535     6 FUNC    WEAK   DEFAULT    1 _ZN4mbed10FileHandle13ena
  7632: 080725f8    13 OBJECT  GLOBAL DEFAULT    1 _ZTSSt9exception
  7633: 0804f8f1   144 FUNC    GLOBAL DEFAULT    1 osRtxPendSV_Handler
  7634: 0804db59    16 FUNC    GLOBAL DEFAULT    1 _ZN7arduino6StringD1Ev
  7635: 080567f1    60 FUNC    GLOBAL DEFAULT    1 _ZN4rtos5Mutex4lockEv
  7636: 080581dd    62 FUNC    GLOBAL DEFAULT    1 HAL_ETH_DescAssignMemory
  7637: 080533fd    32 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice10configured
  7638: 0805d477    98 FUNC    GLOBAL DEFAULT    1 HAL_RTC_AlarmIRQHandler
  7639: 24003a14     4 OBJECT  GLOBAL DEFAULT    6 mriThreadOrigBusFault
  7640: 08041709  2150 FUNC    GLOBAL DEFAULT    1 _Z17write_SDO_to_SRAMP8LO
  7641: 080632b1    54 FUNC    GLOBAL DEFAULT    1 _ZNK10__cxxabiv117__class
  7642: 080637bd    72 FUNC    WEAK   DEFAULT    1 _ZNSt7__cxx1112basic_stri
  7643: 08054b8d    68 FUNC    GLOBAL DEFAULT    1 _ZN4mbed8FileBaseC1EPKcNS
  7644: 08067e29    24 FUNC    GLOBAL DEFAULT    1 strerror
  7645: 08072974     8 OBJECT  GLOBAL DEFAULT    1 _ZTINSt3_V214error_catego
  7646: 080486f5    16 FUNC    GLOBAL DEFAULT    1 _ZN3rpc6detail8responseC1
  7647: 080632f5    20 FUNC    GLOBAL DEFAULT    1 _ZN10__cxxabiv117__class_
  7648: 08041ffd    46 FUNC    GLOBAL DEFAULT    1 _Z22manipulate_SDO_on_SRA
  7649: 0804aae1    44 FUNC    GLOBAL DEFAULT    1 mriCmd_HandleContinueComm
  7650: 08042f7d    24 FUNC    GLOBAL DEFAULT    1 mriPlatform_WasProgramCou
  7651: 08052389    40 FUNC    GLOBAL DEFAULT    1 _ZN4mbed10TickerBaseC2EPK
  7652: 0804dd49    12 FUNC    WEAK   DEFAULT    1 _ZN4mbed5TimerD2Ev
  7653: 080604a9    60 FUNC    GLOBAL DEFAULT    1 gpio_dir
  7654: 0804c081     4 FUNC    GLOBAL DEFAULT    1 mriPlatform_MemWrite8
  7655: 0804ea25    40 FUNC    GLOBAL DEFAULT    1 osKernelGetTickCount
  7656: 080519b1   100 FUNC    GLOBAL DEFAULT    1 pbuf_free
  7657: 08056421    24 FUNC    GLOBAL DEFAULT    1 _ZdlPvj
  7658: 080528dd    66 FUNC    GLOBAL DEFAULT    1 _ZN16EndpointResolver18ne
  7659: 0804d699    76 FUNC    GLOBAL DEFAULT    1 _ZN7arduino9USBSerialD2Ev
  7660: 08060fb5    52 FUNC    GLOBAL DEFAULT    1 lp_ticker_fire_interrupt
  7661: 0804c773     2 FUNC    WEAK   DEFAULT    1 _ZN9USBDevice12callback_s
  7662: 08047f89    28 FUNC    WEAK   DEFAULT    1 _ZNSt10unique_ptrIN14clmd
  7663: 08066cf1    40 FUNC    GLOBAL DEFAULT    1 printf
  7664: 0805fadf    36 FUNC    GLOBAL DEFAULT    1 _ZN8USBPhyHw21ep0_setup_r
  7665: 08070970    16 OBJECT  GLOBAL DEFAULT    1 _ZTVN4mbed8FileBaseE
  7666: 0806ea94    36 OBJECT  GLOBAL DEFAULT    1 _ZTVN7arduino3RPCE
  7667: 0805f291     2 FUNC    WEAK   DEFAULT    1 TIM17_IRQHandler
  7668: 080630f5   110 FUNC    GLOBAL DEFAULT    1 __cxa_rethrow
  7669: 0804d5b1    32 FUNC    GLOBAL DEFAULT    1 _ZN7arduino9USBSerial5_pu
  7670: 08069431     4 FUNC    GLOBAL DEFAULT    1 _user_strerror
  7671: 08062b79    20 FUNC    GLOBAL DEFAULT    1 _ZNSt9bad_allocD1Ev
  7672: 24011ec0     1 OBJECT  GLOBAL DEFAULT    6 __lock___sfp_recursive_mu
  7673: 08051059    36 FUNC    GLOBAL DEFAULT    1 _Z9_phy_initv
  7674: 080526c1    28 FUNC    GLOBAL DEFAULT    1 _ZN4mbed16UnbufferedSeria
  7675: 08043ab9    12 FUNC    GLOBAL DEFAULT    1 mriPlatform_RtosGetHalted
  7676: 08046749   326 FUNC    WEAK   DEFAULT    1 _ZN10clmdep_fmt11BasicWri
  7677: 08042135   144 FUNC    GLOBAL DEFAULT    1 _Z15write_parameterP8LOIT
  7678: 08054a03    48 FUNC    GLOBAL DEFAULT    1 ticker_insert_event_us
  7679: 08056509    64 FUNC    GLOBAL DEFAULT    1 _ZN4mbed6fdopenEPNS_10Fil
  7680: 24011e18     4 OBJECT  WEAK   DEFAULT    6 _ZGVNSt7collateIcE2idE
  7681: 08073378   200 OBJECT  GLOBAL DEFAULT    1 __mprec_tens
  7682: 08043ab1     4 FUNC    GLOBAL DEFAULT    1 mriSemihost_IsDebuggeeMak
  7683: 08073f0c     0 NOTYPE  GLOBAL DEFAULT    2 __exidx_start
  7684: 0804ba29   152 FUNC    GLOBAL DEFAULT    1 mriMem_WriteHexBufferToMe
  7685: 0806c86d    76 FUNC    GLOBAL DEFAULT    1 _Balloc
  7686: 080563d5    48 FUNC    GLOBAL DEFAULT    1 _Znwj
  7687: 0804d4bb    94 FUNC    WEAK   DEFAULT    1 _ZN7arduino6USBCDC9AsyncR
  7688: 08063699   100 FUNC    WEAK   DEFAULT    1 _ZNSs12_S_constructIPKcEE
  7689: 08063565    64 FUNC    GLOBAL DEFAULT    1 _ZNSt11logic_errorD2Ev
  7690: 0805da9d    28 FUNC    GLOBAL DEFAULT    1 TIM_CCxChannelCmd
  7691: 0805f291     2 FUNC    WEAK   DEFAULT    1 OTG_HS_EP1_OUT_IRQHandler
  7692: 0804cbbb     8 FUNC    WEAK   DEFAULT    1 _ZN7arduino6USBCDC9AsyncW
  7693: 0806f53c    36 OBJECT  GLOBAL DEFAULT    1 remoteproc_virtio_dispatc
  7694: 0805faa3     6 FUNC    GLOBAL DEFAULT    1 _ZN8USBPhyHw11sof_disable
  7695: 2400fa88  2048 OBJECT  WEAK   DEFAULT    6 _ZZN4mbed33do_shared_even
  7696: 0804cd39    48 FUNC    GLOBAL DEFAULT    1 _ZN7arduino6USBCDCD1Ev
  7697: 0806e828    20 OBJECT  WEAK   DEFAULT    1 _ZTVN14clmdep_msgpack2v11
  7698: 080566b9    20 FUNC    GLOBAL DEFAULT    1 _wait_us_ticks
  7699: 2400dd0c    20 OBJECT  GLOBAL DEFAULT    6 _ZN3ble4impl15BLEInstance
  7700: 08050909    12 FUNC    GLOBAL DEFAULT    1 EvrRtxEventFlagsError
  7701: 0804df21   114 FUNC    GLOBAL DEFAULT    1 _Z7pinMode7PinName7PinMod
  7702: 0805fa95     2 FUNC    GLOBAL DEFAULT    1 HAL_PCD_ConnectCallback
  7703: 08043ae1    32 FUNC    GLOBAL DEFAULT    1 mriPlatform_RtosGetNextTh
  7704: 08052959     2 FUNC    GLOBAL DEFAULT    1 _ZN14LinkedListBaseD1Ev
  7705: 08045d43    68 FUNC    WEAK   DEFAULT    1 _ZNSt14numeric_limitsIN10
  7706: 080495f9    50 FUNC    GLOBAL DEFAULT    1 rpmsg_send_ns_message
  7707: 08051d0d    42 FUNC    WEAK   DEFAULT    1 _ZN6CThunkIN4mbed3I2CEE10
  7708: 08072910    12 OBJECT  GLOBAL DEFAULT    1 _ZTISt20bad_array_new_len
  7709: 24011e3c     4 OBJECT  WEAK   DEFAULT    6 _ZGVNSt9money_getIcSt19is
  7710: 08052edd   142 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice11_control_i
  7711: 08045fed    48 FUNC    WEAK   DEFAULT    1 _ZN10clmdep_fmt8internal1
  7712: 08063251    42 FUNC    GLOBAL DEFAULT    1 _ZNK10__cxxabiv120__si_cl
  7713: 080584c5   158 FUNC    GLOBAL DEFAULT    1 HAL_ETH_GetRxDataBuffer
  7714: 08051b85    16 FUNC    GLOBAL DEFAULT    1 tcp_segs_free
  7715: 08042489   136 FUNC    GLOBAL DEFAULT    1 _Z19display_Linked_ListP8
  7716: 0805e51d   364 FUNC    GLOBAL DEFAULT    1 USB_DevInit
  7717: 080657c9   192 FUNC    GLOBAL DEFAULT    1 _fopen_r
  7718: 080525a9     4 FUNC    WEAK   DEFAULT    1 _ZN4mbed16UnbufferedSeria
  7719: 0805f91d   108 FUNC    GLOBAL DEFAULT    1 serial_getc
  7720: 0805f291     2 FUNC    WEAK   DEFAULT    1 I2C1_EV_IRQHandler
  7721: 08053451   236 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice12endpoint_a
  7722: 2400f47e   115 OBJECT  GLOBAL DEFAULT    6 memp_memory_TCP_PCB_LISTE
  7723: 08060165    72 FUNC    GLOBAL DEFAULT    1 _Z11get_usb_phyv
  7724: 080701d8    12 OBJECT  GLOBAL DEFAULT    1 memp_TCP_SEG
  7725: 08044a85    50 FUNC    WEAK   DEFAULT    1 _ZNKSt6vectorIPN14clmdep_
  7726: 08047e95    20 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v110t
  7727: 08042e7d   136 FUNC    GLOBAL DEFAULT    1 mriPlatform_DisplayFaultC
  7728: 080525eb    10 FUNC    GLOBAL DEFAULT    1 _ZN4mbed16UnbufferedSeria
  7729: 0806229d     2 FUNC    GLOBAL DEFAULT    1 _ZNSt13bad_exceptionD1Ev
  7730: 08057969   200 FUNC    GLOBAL DEFAULT    1 HAL_ADCEx_MultiModeConfig
  7731: 08044349   112 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v14zo
  7732: 0805fd49    68 FUNC    GLOBAL DEFAULT    1 _ZN8USBPhyHw6deinitEv
  7733: 080556f5    56 FUNC    GLOBAL DEFAULT    1 mbed_error_vprintf
  7734: 0805121d    36 FUNC    GLOBAL DEFAULT    1 _Z24mbed_default_mac_addr
  7735: 0805934d    50 FUNC    GLOBAL DEFAULT    1 HAL_FDCAN_Start
  7736: 08062e81    16 FUNC    GLOBAL DEFAULT    1 _ZSt14get_unexpectedv
  7737: 08047f75    20 FUNC    WEAK   DEFAULT    1 _ZNKSt8functionIFSt10uniq
  7738: 080524f9    22 FUNC    GLOBAL DEFAULT    1 _ZN4mbed5TimerC2Ev
  7739: 0804cbb7     2 FUNC    WEAK   DEFAULT    1 _ZN7arduino6USBCDC7data_r
  7740: 0804077f   124 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v14pa
  7741: 0805fb0f    32 FUNC    GLOBAL DEFAULT    1 _ZN8USBPhyHw20endpoint_re
  7742: 08047749   464 FUNC    WEAK   DEFAULT    1 _ZN10clmdep_fmt11BasicWri
  7743: 08047145   128 FUNC    WEAK   DEFAULT    1 _ZN10clmdep_fmt6formatB5c
  7744: 0805f291     2 FUNC    WEAK   DEFAULT    1 TIM8_BRK_TIM12_IRQHandler
  7745: 08054e09    84 FUNC    GLOBAL DEFAULT    1 _ZN4mbed6StreamC2EPKc
  7746: 080537f5    74 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice22_request_c
  7747: 08057575   300 FUNC    GLOBAL DEFAULT    1 ADC_ConfigureBoostMode
  7748: 08044b59   110 FUNC    WEAK   DEFAULT    1 _ZNSt6vectorIN14clmdep_ms
  7749: 08050725     4 FUNC    GLOBAL DEFAULT    1 __wrap_main
  7750: 0804d559    16 FUNC    WEAK   DEFAULT    1 _ZN7arduino9USBSerialcvbE
  7751: 080551c7     2 FUNC    GLOBAL DEFAULT    1 UsageFault_Handler
  7752: 0804a78d    48 FUNC    GLOBAL DEFAULT    1 mriBuffer_IsNextCharEqual
  7753: 0805fa95     2 FUNC    GLOBAL DEFAULT    1 _ZN8USBPhyHw13remote_wake
  7754: 08049533    68 FUNC    GLOBAL DEFAULT    1 rproc_virtio_notified
  7755: 080446fd    78 FUNC    WEAK   DEFAULT    1 _ZNSt10_HashtableINSt7__c
  7756: 0805f291     2 FUNC    WEAK   DEFAULT    1 DFSDM1_FLT1_IRQHandler
  7757: 2400106c     1 OBJECT  GLOBAL DEFAULT    4 uwTickFreq
  7758: 08042f61    12 FUNC    GLOBAL DEFAULT    1 mriPlatform_GetProgramCou
  7759: 0805ec25     8 FUNC    GLOBAL DEFAULT    1 USB_ReadInterrupts
  7760: 0805edd9   328 FUNC    GLOBAL DEFAULT    1 SystemCoreClockUpdate
  7761: 08055cc1    72 FUNC    GLOBAL DEFAULT    1 _ZN4mbed8internal45do_tim
  7762: 0806cdbd   186 FUNC    GLOBAL DEFAULT    1 __d2b
  7763: 08050afd    36 FUNC    WEAK   DEFAULT    1 _ZNK4mbed8CallbackIFvvEE4
  7764: 08055e3d    36 FUNC    GLOBAL DEFAULT    1 _ZN12DirectSerial5writeEP
  7765: 08058621     2 FUNC    WEAK   DEFAULT    1 HAL_ETH_TxCpltCallback
  7766: 08045f35    48 FUNC    GLOBAL DEFAULT    1 _ZN10clmdep_fmt8internal1
  7767: 080574cd   106 FUNC    GLOBAL DEFAULT    1 ADC_Disable
  7768: 0804ca6d    44 FUNC    GLOBAL DEFAULT    1 _ZN7arduino18PluggableUSB
  7769: 080725e4    18 OBJECT  GLOBAL DEFAULT    1 _ZTSSt13bad_exception
  7770: 24011ec4     1 OBJECT  GLOBAL DEFAULT    6 __lock___env_recursive_mu
  7771: 08050fed    48 FUNC    WEAK   DEFAULT    1 _ZN10STM32_EMACD2Ev
  7772: 08043b19   232 FUNC    GLOBAL DEFAULT    1 mriPlatform_RtosGetExtraT
  7773: 0807016c    12 OBJECT  GLOBAL DEFAULT    1 memp_NETCONN
  7774: 0806175d   564 FUNC    GLOBAL DEFAULT    1 serial_free
  7775: 08063df1     6 FUNC    GLOBAL DEFAULT    1 _ZNKSt3_V214error_categor
  7776: 08048229    16 FUNC    WEAK   DEFAULT    1 _ZNSt15__allocated_ptrISa
  7777: 080402d9     0 FUNC    GLOBAL DEFAULT    1 _mainCRTStartup
  7778: 080632f5    20 FUNC    GLOBAL DEFAULT    1 _ZN10__cxxabiv117__class_
  7779: 0806cc99    54 FUNC    GLOBAL DEFAULT    1 __mcmp
  7780: 24000ea4   164 OBJECT  GLOBAL DEFAULT    4 osRtxInfo
  7781: 0805f291     2 FUNC    WEAK   DEFAULT    1 HRTIM1_TIMD_IRQHandler
  7782: 0806b70d   176 FUNC    GLOBAL DEFAULT    1 __swbuf_r
  7783: 0805202d   108 FUNC    GLOBAL DEFAULT    1 _ZN4mbed10SerialBaseC1E7P
  7784: 0805964b     2 FUNC    WEAK   DEFAULT    1 HAL_FDCAN_TT_ScheduleSync
  7785: 080403dd   196 FUNC    GLOBAL DEFAULT    1 _Z15HAL_RTC_MspInitv
  7786: 08073350    40 OBJECT  GLOBAL DEFAULT    1 __mprec_bigtens
  7787: 08041215   320 FUNC    GLOBAL DEFAULT    1 _Z8Set_FreqP5can_sPK12can
  7788: 08056cb5    16 FUNC    GLOBAL DEFAULT    1 HAL_EnableCompensationCel
  7789: 08042719    12 FUNC    GLOBAL DEFAULT    1 mriSysTickHandlerStub
  7790: 08042685     6 FUNC    GLOBAL DEFAULT    1 mriDebugMonitorHandlerStu
  7791: 0804cb29    80 FUNC    GLOBAL DEFAULT    1 _Z13PluggableUSBDv
  7792: 0804a6b7    22 FUNC    GLOBAL DEFAULT    1 mriBuffer_WriteStringAsHe
  7793: 080726cc    44 OBJECT  GLOBAL DEFAULT    1 _ZTVN10__cxxabiv120__si_c
  7794: 0805c119    84 FUNC    GLOBAL DEFAULT    1 HAL_RCC_GetClockConfig
  7795: 0804898d    90 FUNC    WEAK   DEFAULT    1 _ZNSt12__shared_ptrIN14cl
  7796: 08044025    20 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v117m
  7797: 0804317d    76 FUNC    GLOBAL DEFAULT    1 mriPlatform_SetHardwareBr
  7798: 0804dc9d    64 FUNC    GLOBAL DEFAULT    1 _ZNK7arduino6String9subst
  7799: 08042825     4 FUNC    WEAK   DEFAULT    1 _ZN4mbed8CallbackIFvvEE11
  7800: 0804c079     4 FUNC    GLOBAL DEFAULT    1 mriPlatform_MemWrite32
  7801: 0806e605    36 OBJECT  WEAK   DEFAULT    1 _ZTSN14clmdep_msgpack2v11
  7802: 0804dc13    66 FUNC    GLOBAL DEFAULT    1 _ZN7arduino6String6concat
  7803: 0805fab1     4 FUNC    GLOBAL DEFAULT    1 _ZN8USBPhyHw18ep0_set_max
  7804: 080514ed   156 FUNC    GLOBAL DEFAULT    1 _ZN10STM32_EMAC8phy_taskE
  7805: 0805f291     2 FUNC    WEAK   DEFAULT    1 SDMMC2_IRQHandler
  7806: 08049c75     2 FUNC    GLOBAL DEFAULT    1 metal_machine_cache_flush
  7807: 0804a92d   112 FUNC    GLOBAL DEFAULT    1 mriCmd_HandleBreakpointWa
  7808: 24011de8     4 OBJECT  WEAK   DEFAULT    6 _ZGVNSt7__cxx119money_put
  7809: 08062e41    20 FUNC    GLOBAL DEFAULT    1 _ZSt9terminatev
  7810: 0804dd3d    12 FUNC    WEAK   DEFAULT    1 _ZN4mbed13LowPowerTimerD1
  7811: 08045c31    24 FUNC    WEAK   DEFAULT    1 _ZN10clmdep_fmt17BasicMem
  7812: 08043f85    20 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v112u
  7813: 0805ce71   340 FUNC    GLOBAL DEFAULT    1 HAL_RCCEx_GetPLL3ClockFre
  7814: 08052597     6 FUNC    WEAK   DEFAULT    1 _ZThn124_N4mbed16Unbuffer
  7815: 0805ec09    28 FUNC    GLOBAL DEFAULT    1 USB_DevDisconnect
  7816: 0804cb89    16 FUNC    GLOBAL DEFAULT    1 _ZN7arduino8internal18Plu
  7817: 08051259   204 FUNC    GLOBAL DEFAULT    1 _ZN10STM32_EMAC25low_leve
  7818: 0806cf99    16 FUNC    GLOBAL DEFAULT    1 _getpid
  7819: 0804034d    12 FUNC    GLOBAL DEFAULT    1 _Z20RTC_Alarm_IRQHandlerv
  7820: 0805250f    22 FUNC    GLOBAL DEFAULT    1 _ZN4mbed13LowPowerTimerC2
  7821: 0806c801    36 FUNC    GLOBAL DEFAULT    1 _isatty_r
  7822: 08054eb9    56 FUNC    WEAK   DEFAULT    1 _ZN4mbed8internal8SysTime
  7823: 08052209    20 FUNC    GLOBAL DEFAULT    1 _ZN4mbed10SerialBaseD0Ev
  7824: 0807258c    12 OBJECT  GLOBAL DEFAULT    1 _ZTISt13bad_exception
  7825: 080729d4    25 OBJECT  GLOBAL DEFAULT    1 _ZTSNSt3_V214error_catego
  7826: 080527e1   116 FUNC    GLOBAL DEFAULT    1 _ZN7AsyncOp4waitEPN4rtos5
  7827: 08052a69    18 FUNC    GLOBAL DEFAULT    1 _ZN17OperationListBaseD1E
  7828: 0804dc55    22 FUNC    GLOBAL DEFAULT    1 _ZN7arduino6String6concat
  7829: 080444dd   128 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v26de
  7830: 08056cc5    82 FUNC    GLOBAL DEFAULT    1 HAL_EXTI_D1_EventInputCon
  7831: 080607c1     8 FUNC    GLOBAL DEFAULT    1 HAL_I2C_MasterRxCpltCallb
  7832: 0804da4d     8 FUNC    GLOBAL DEFAULT    1 _ZN7arduino5Print5printEP
  7833: 0806f954    24 OBJECT  WEAK   DEFAULT    1 _ZTVN7arduino6USBCDC9Asyn
  7834: 08054f1f    20 FUNC    WEAK   DEFAULT    1 _ZNK4mbed8internal8SysTim
  7835: 080529b9    12 FUNC    GLOBAL DEFAULT    1 _ZN17OperationListBaseC2E
  7836: 0805d549    68 FUNC    GLOBAL DEFAULT    1 RTC_ExitInitMode
  7837: 080725a0    32 OBJECT  GLOBAL DEFAULT    1 _ZTSN10__cxxabiv115__forc
  7838: 08070178    12 OBJECT  GLOBAL DEFAULT    1 memp_PBUF
  7839: 08056721     6 FUNC    GLOBAL DEFAULT    1 _ZN4rtos10EventFlags3setE
  7840: 08046189    64 FUNC    WEAK   DEFAULT    1 _ZN10clmdep_fmt8internal1
  7841: 08053ab5   106 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice13_change_st
  7842: 0805d8f7    10 FUNC    GLOBAL DEFAULT    1 HAL_RTCEx_BKUPWrite
  7843: 080529c5    14 FUNC    GLOBAL DEFAULT    1 _ZN17OperationListBase5em
  7844: 0805f291     2 FUNC    WEAK   DEFAULT    1 EXTI2_IRQHandler
  7845: 0805884d   396 FUNC    GLOBAL DEFAULT    1 HAL_ETH_GetMACConfig
  7846: 0804dcdd    56 FUNC    WEAK   DEFAULT    1 main
  7847: 0806cfb9     0 FUNC    GLOBAL DEFAULT    1 _init
  7848: 08043eed    32 FUNC    GLOBAL DEFAULT    1 _Z12eventHandlerv
  7849: 0805f291     2 FUNC    WEAK   DEFAULT    1 SAI1_IRQHandler
  7850: 0804806d   148 FUNC    WEAK   DEFAULT    1 _ZNK14clmdep_msgpack2v26o
  7851: 08041f71   140 FUNC    GLOBAL DEFAULT    1 _Z15init_SDO_objectP8LOIT
  7852: 240000d0   160 OBJECT  WEAK   DEFAULT    4 _ZN10clmdep_fmt8internal9
  7853: 08054d9b     4 FUNC    GLOBAL DEFAULT    1 _ZN4mbed6Stream4sizeEv
  7854: 08051f35     2 FUNC    GLOBAL DEFAULT    1 _ZN4mbed10SerialBase4lock
  7855: 08053051    36 FUNC    GLOBAL DEFAULT    1 _ZN9USBDevice22_request_s
  7856: 0805f291     2 FUNC    WEAK   DEFAULT    1 DMA1_Stream2_IRQHandler
  7857: 080525e3     8 FUNC    GLOBAL DEFAULT    1 _ZThn124_NK4mbed16Unbuffe
  7858: 08044bed    28 FUNC    WEAK   DEFAULT    1 _ZNSt11__copy_moveILb1ELb
  7859: 08054469    12 FUNC    WEAK   DEFAULT    1 hal_in_critical_section
  7860: 08063745    40 FUNC    GLOBAL DEFAULT    1 _ZNSt11logic_errorC1EPKc
  7861: 0804c681    28 FUNC    WEAK   DEFAULT    1 _ZN7arduino11RingBufferNI
  7862: 0805c34d  2476 FUNC    GLOBAL DEFAULT    1 HAL_RCCEx_PeriphCLKConfig
  7863: 080514d5    24 FUNC    GLOBAL DEFAULT    1 HAL_ETH_MACErrorCallback
  7864: 08042701    12 FUNC    GLOBAL DEFAULT    1 mriSVCHandlerStub
  7865: 0806cb4d   160 FUNC    GLOBAL DEFAULT    1 __pow5mult
  7866: 08060045    30 FUNC    GLOBAL DEFAULT    1 HAL_PCD_SOFCallback
  7867: 08055ee5    24 FUNC    GLOBAL DEFAULT    1 _ZN9__gnu_cxx27__verbose_
  7868: 0805f291     2 FUNC    WEAK   DEFAULT    1 CRS_IRQHandler
  7869: 080440ed   120 FUNC    GLOBAL DEFAULT    1 _ZN7arduino3RPC14new_serv
  7870: 08072b84     4 OBJECT  GLOBAL DEFAULT    1 _global_impure_ptr
  7871: 08043ffd    20 FUNC    WEAK   DEFAULT    1 _ZN14clmdep_msgpack2v119a
  7872: 08050935    12 FUNC    GLOBAL DEFAULT    1 EvrRtxMessageQueueError
  7873: 38000000   140 OBJECT  GLOBAL DEFAULT    7 resource_table
  7874: 08046891   548 FUNC    WEAK   DEFAULT    1 _ZN10clmdep_fmt11BasicWri
  7875: 08057a31    36 FUNC    GLOBAL DEFAULT    1 HAL_NVIC_SetPriorityGroup

No version information found in this file.
Attribute Section: aeabi
File Attributes
  Tag_CPU_name: "7E-M"
  Tag_CPU_arch: v7E-M
  Tag_CPU_arch_profile: Microcontroller
  Tag_THUMB_ISA_use: Thumb-2
  Tag_FP_arch: FPv5/FP-D16 for ARMv8
  Tag_ABI_PCS_wchar_t: 4
  Tag_ABI_FP_denormal: Needed
  Tag_ABI_FP_exceptions: Needed
  Tag_ABI_FP_number_model: IEEE 754
  Tag_ABI_align_needed: 8-byte
  Tag_ABI_enum_size: small
  Tag_CPU_unaligned_access: v6




// CAN TRACE

09:44:45.455 -> 
09:44:45.455 -> *****************************
09:44:45.455 -> R :	641  40 2 20 1 0 0 0 0       // 2002.01 Seri number
09:44:45.455 -> 
09:44:45.455 -> S :	5C1  43 2 20 1 22 22 22 22
09:44:45.521 -> 
09:44:45.521 -> *****************************
09:44:45.521 -> R :	641  40 2 20 1 0 0 0 0
09:44:45.521 -> 
09:44:45.521 -> S :	5C1  43 2 20 1 22 22 22 22
09:44:45.588 -> 
09:44:45.588 -> *****************************
09:44:45.588 -> R :	641  40 0 20 1 0 0 0 0        // 2000.01 SW Sachnumber
09:44:45.588 -> 
09:44:45.588 -> S :	5C1  43 0 20 1 51 85 49 62
09:44:45.621 -> 
09:44:45.621 -> *****************************
09:44:45.621 -> R :	641  40 0 20 3 0 0 0 0        // 2000.03 HW Sachnumber
09:44:45.621 -> 
09:44:45.621 -> S :	5C1  43 0 20 3 51 22 68 1
09:44:45.621 -> 
09:44:45.621 -> *****************************
09:44:45.621 -> R :	643  40 0 20 1 0 0 0 0        // 2000.01 SW Sachnumber 
09:44:45.621 -> 
09:44:45.621 -> S :	5C3  43 0 20 1 51 85 49 62
09:44:45.621 -> 
09:44:45.621 -> *****************************
09:44:45.621 -> R :	643  40 0 20 3 0 0 0 0        // 2000.03 HW Sachnumber
09:44:45.621 -> 
09:44:45.621 -> S :	5C3  43 0 20 3 51 22 68 1
09:44:45.621 -> 
09:44:45.621 -> *****************************
09:44:45.621 -> R :	644  40 0 20 1 0 0 0 0        // 2000.03 HW Sachnumber
09:44:45.621 -> 
09:44:45.621 -> S :	5C4  43 0 20 1 51 85 49 62
09:44:45.621 -> 
09:44:45.621 -> *****************************
09:44:45.621 -> R :	644  40 0 20 3 0 0 0 0        // 2000.03 HW Sachnumber
09:44:45.621 -> 
09:44:45.621 -> S :	5C4  43 0 20 3 51 22 68 1
09:44:45.621 -> 
09:44:45.621 -> *****************************
09:44:45.621 -> R :	64D  40 0 20 1 0 0 0 0      
09:44:45.621 -> 
09:44:45.621 -> S :	5CD  43 0 20 1 51 85 49 62
09:44:45.621 -> 
09:44:45.621 -> *****************************
09:44:45.621 -> R :	64D  40 0 20 3 0 0 0 0
09:44:45.621 -> 
09:44:45.621 -> S :	5CD  43 0 20 3 51 22 68 1
09:44:45.621 -> 
09:44:45.621 -> *****************************
09:44:45.621 -> R :	656  40 0 20 1 0 0 0 0
09:44:45.621 -> 
09:44:45.654 -> S :	5D6  43 0 20 1 51 85 49 62
09:44:45.654 -> 
09:44:45.654 -> *****************************
09:44:45.654 -> R :	656  40 0 20 3 0 0 0 0
09:44:45.654 -> 
09:44:45.654 -> S :	5D6  43 0 20 3 51 22 68 1
09:44:45.654 -> 
09:44:45.654 -> *****************************
09:44:45.654 -> R :	650  40 0 20 1 0 0 0 0
09:44:45.654 -> 
09:44:45.654 -> S :	5D0  43 0 20 1 51 85 49 62
09:44:45.654 -> 
09:44:45.654 -> *****************************
09:44:45.654 -> R :	650  40 0 20 3 0 0 0 0
09:44:45.654 -> 
09:44:45.654 -> S :	5D0  43 0 20 3 51 22 68 1
09:44:45.654 -> 
09:44:45.654 -> *****************************
09:44:45.654 -> R :	65D  40 0 20 1 0 0 0 0
09:44:45.654 -> 
09:44:45.654 -> S :	5DD  43 0 20 1 51 85 49 62
09:44:45.654 -> 
09:44:45.654 -> *****************************
09:44:45.654 -> R :	65D  40 0 20 3 0 0 0 0
09:44:45.654 -> 
09:44:45.654 -> S :	5DD  43 0 20 3 51 22 68 1
09:44:45.654 -> 
09:44:45.654 -> *****************************
09:44:45.654 -> R :	65D  40 0 20 1 0 0 0 0
09:44:45.654 -> 
09:44:45.654 -> S :	5DD  43 0 20 1 51 85 49 62
09:44:45.687 -> 
09:44:45.687 -> *****************************
09:44:45.687 -> R :	65D  40 0 20 3 0 0 0 0
09:44:45.687 -> 
09:44:45.687 -> S :	5DD  43 0 20 3 51 22 68 1
09:44:45.687 -> 
09:44:45.687 -> *****************************
09:44:45.687 -> R :	65F  40 0 20 1 0 0 0 0
09:44:45.687 -> 
09:44:45.687 -> S :	5DF  43 0 20 1 51 85 49 62
09:44:45.687 -> 
09:44:45.687 -> *****************************
09:44:45.687 -> R :	65F  40 0 20 3 0 0 0 0
09:44:45.687 -> 
09:44:45.687 -> S :	5DF  43 0 20 3 51 22 68 1
09:44:45.687 -> 
09:44:45.687 -> *****************************
09:44:45.687 -> R :	67D  40 0 20 1 0 0 0 0
09:44:45.687 -> 
09:44:45.687 -> S :	5FD  43 0 20 1 51 85 49 62
09:44:45.687 -> 
09:44:45.687 -> *****************************
09:44:45.687 -> R :	67D  40 0 20 3 0 0 0 0
09:44:45.687 -> 
09:44:45.687 -> S :	5FD  43 0 20 3 51 22 68 1
09:44:46.020 -> 
09:44:46.020 -> *****************************
09:44:46.020 -> R :	740  7F
09:44:46.020 -> 
09:44:46.020 -> *****************************
09:44:46.020 -> R :	641  2F 0 5F 3 1 0 0 0      // write command
09:44:46.020 -> S :	5C1  60 0 5F 3 0 0 0 0
09:44:46.020 -> 
09:44:46.020 -> *****************************
09:44:46.020 -> R :	641  40 0 5F 2 0 0 0 0
09:44:46.020 -> 
09:44:46.020 -> S :	5C1  43 0 5F 2 0 0 0 0
09:44:46.020 -> 
09:44:46.020 -> *****************************
09:44:46.020 -> R :	641  40 1 5F 3 0 0 0 0
09:44:46.020 -> 
09:44:46.053 -> S :	5C1  43 1 5F 3 0 0 0 0
09:44:46.053 -> 
09:44:46.053 -> *****************************
09:44:46.053 -> R :	641  23 1 5F 4 BD 66 C3 5A
09:44:46.053 -> S :	5C1  60 1 5F 4 0 0 0 0
09:44:46.053 -> 
09:44:46.053 -> *****************************
09:44:46.053 -> R :	641  40 1 5F 3 0 0 0 0
09:44:46.053 -> 
09:44:46.053 -> S :	5C1  43 1 5F 3 0 0 0 0
09:44:46.053 -> 
09:44:46.053 -> *****************************
09:44:46.053 -> R :	641  23 1 5F 4 DB 3C 3C A5
09:44:46.053 -> S :	5C1  60 1 5F 4 0 0 0 0
09:44:46.053 -> 
09:44:46.053 -> *****************************
09:44:46.053 -> R :	641  2F 0 5F 3 3 0 0 0
09:44:46.053 -> S :	5C1  60 0 5F 3 0 0 0 0
09:44:46.053 -> 
09:44:46.053 -> *****************************
09:44:46.053 -> R :	641  40 0 5F 2 0 0 0 0
09:44:46.053 -> 
09:44:46.053 -> S :	5C1  43 0 5F 2 0 0 0 0
09:44:46.086 -> 
09:44:46.086 -> *****************************
09:44:46.086 -> R :	601  40 2 20 4 0 0 0 0      // read ident string
09:44:46.086 -> 
09:44:46.086 -> S :	581  41 2 20 4 20 0 0 0
09:44:46.086 -> 
09:44:46.086 -> *****************************
09:44:46.086 -> R :	601  60 2 20 4 0 0 0 0
09:44:46.086 -> 
09:44:46.086 -> S :	581  0 45 43 45 32 32 35 20  // 7 bytes
09:44:46.086 -> 
09:44:46.086 -> *****************************
09:44:46.086 -> R :	601  70 2 20 4 0 0 0 0
09:44:46.086 -> 
09:44:46.086 -> S :	581  10 20 20 20 20 20 20 20  // 7 bytes
09:44:46.086 -> 
09:44:46.086 -> *****************************
09:44:46.086 -> R :	601  60 2 20 4 0 0 0 0
09:44:46.086 -> 
09:44:46.086 -> S :	581  0 32 30 31 35 0 24 0     // 7 bytes
09:44:46.086 -> 
09:44:46.086 -> *****************************
09:44:46.086 -> R :	601  70 2 20 4 0 0 0 0
09:44:46.086 -> 
09:44:46.086 -> S :	581  10 1E 0 24 0 1E 0 24     // 7 bytes
09:44:46.086 -> 
09:44:46.086 -> *****************************
09:44:46.086 -> R :	601  60 2 20 4 0 0 0 0
09:44:46.086 -> 
09:44:46.086 -> S :	581  7 0 0 0 0 0 0 0
09:44:47.018 -> 
09:44:47.018 -> *****************************

32 bytes / 7 -> ~5
28 bytes = 16 + 12 = 1c

"ECE225        2015"
ECE2

25__

____

__20

15__

10:53:29.608 -> *****************************
10:53:29.608 -> R :	641  40 2 20 1 0 0 0 0
10:53:29.608 -> S :	5C1  43 2 20 1 22 22 22 22
10:53:29.740 -> *****************************
10:53:29.740 -> R :	601  40 2 20 4 0 0 0 0
10:53:29.740 -> S :	581  41 2 20 4 20 0 0 0
10:53:29.740 -> *****************************
10:53:29.740 -> R :	601  60 2 20 4 0 0 0 0
10:53:29.740 -> S :	581  0 45 43 45 32 32 35 20
10:53:29.740 -> *****************************
10:53:29.740 -> R :	601  70 2 20 4 0 0 0 0
10:53:29.740 -> S :	581  10 20 20 20 20 20 20 20
10:53:29.740 -> *****************************
10:53:29.740 -> R :	601  60 2 20 4 0 0 0 0
10:53:29.740 -> S :	581  0 32 30 31 35 20 20 0
10:53:29.740 -> *****************************
10:53:29.740 -> R :	601  70 2 20 4 0 0 0 0
10:53:29.740 -> S :	581  10 0 0 0 0 0 0 0
10:53:29.740 -> *****************************
10:53:29.740 -> R :	601  60 2 20 4 0 0 0 0
10:53:29.740 -> S :	581  7 0 0 0 0 0 0 0
10:53:29.740 -> *****************************
10:53:29.740 -> R :	601  40 2 20 4 0 0 0 0
10:53:29.740 -> S :	581  41 2 20 4 20 0 0 0
10:53:29.740 -> *****************************
10:53:29.740 -> R :	601  60 2 20 4 0 0 0 0
10:53:29.774 -> S :	581  0 45 43 45 32 32 35 20
10:53:29.774 -> *****************************
10:53:29.774 -> R :	601  70 2 20 4 0 0 0 0
10:53:29.774 -> S :	581  10 20 20 20 20 20 20 20
10:53:29.774 -> *****************************
10:53:29.774 -> R :	601  60 2 20 4 0 0 0 0
10:53:29.774 -> S :	581  0 32 30 31 35 20 20 0
10:53:29.774 -> *****************************
10:53:29.774 -> R :	601  70 2 20 4 0 0 0 0
10:53:29.774 -> S :	581  10 0 0 0 0 0 0 0
10:53:29.774 -> *****************************
10:53:29.774 -> R :	601  60 2 20 4 0 0 0 0
10:53:29.774 -> S :	581  7 0 0 0 0 0 0 0
10:53:29.774 -> *****************************
10:53:29.774 -> R :	641  40 2 20 1 0 0 0 0
10:53:29.774 -> S :	5C1  43 2 20 1 22 22 22 22
10:53:29.940 -> *****************************
10:53:29.940 -> R :	641  2F 0 5F 3 1 0 0 0
10:53:29.940 -> S :	5C1  60 0 5F 3 0 0 0 0
10:53:29.940 -> *****************************
10:53:29.940 -> R :	740  7F
10:53:29.940 -> *****************************
10:53:29.940 -> R :	641  40 0 5F 2 0 0 0 0
10:53:29.940 -> S :	5C1  43 0 5F 2 0 0 0 0
10:53:29.940 -> *****************************
10:53:29.940 -> R :	641  40 1 5F 3 0 0 0 0
10:53:29.940 -> S :	5C1  43 1 5F 3 0 0 0 0
10:53:29.973 -> *****************************
10:53:29.973 -> R :	641  23 1 5F 4 BD 66 C3 5A
10:53:29.973 -> S :	5C1  60 1 5F 4 0 0 0 0
10:53:29.973 -> *****************************
10:53:29.973 -> R :	641  40 1 5F 3 0 0 0 0
10:53:29.973 -> S :	5C1  43 1 5F 3 0 0 0 0
10:53:29.973 -> *****************************
10:53:29.973 -> R :	641  23 1 5F 4 DB 3C 3C A5
10:53:29.973 -> S :	5C1  60 1 5F 4 0 0 0 0
10:53:29.973 -> *****************************
10:53:29.973 -> R :	641  2F 0 5F 3 3 0 0 0
10:53:29.973 -> S :	5C1  60 0 5F 3 0 0 0 0
10:53:29.973 -> *****************************
10:53:29.973 -> R :	641  40 0 5F 2 0 0 0 0
10:53:29.973 -> S :	5C1  43 0 5F 2 0 0 0 0
10:53:29.973 -> *****************************
10:53:29.973 -> R :	641  40 2 20 6 0 0 0 0
10:53:29.973 -> S :	5C1  43 2 20 6 0 0 0 0
10:53:30.039 -> *****************************
10:53:30.039 -> R :	641  40 2 20 1 0 0 0 0
10:53:30.039 -> S :	5C1  43 2 20 1 22 22 22 22
10:53:30.039 -> *****************************
10:53:30.039 -> R :	641  40 2 20 1 0 0 0 0
10:53:30.039 -> S :	5C1  43 2 20 1 22 22 22 22
10:53:30.039 -> *****************************
10:53:30.039 -> R :	641  40 0 20 1 0 0 0 0
10:53:30.039 -> S :	5C1  43 0 20 1 51 85 49 62
10:53:30.039 -> *****************************
10:53:30.039 -> R :	641  40 0 20 3 0 0 0 0
10:53:30.039 -> S :	5C1  43 0 20 3 51 22 68 1
10:53:30.072 -> *****************************
10:53:30.072 -> R :	643  40 0 20 1 0 0 0 0
10:53:30.072 -> S :	5C3  43 0 20 1 51 85 49 62
10:53:30.072 -> *****************************
10:53:30.072 -> R :	643  40 0 20 3 0 0 0 0
10:53:30.072 -> S :	5C3  43 0 20 3 51 22 68 1
10:53:30.072 -> *****************************
10:53:30.072 -> R :	644  40 0 20 1 0 0 0 0
10:53:30.072 -> S :	5C4  43 0 20 1 51 85 49 62
10:53:30.072 -> *****************************
10:53:30.072 -> R :	644  40 0 20 3 0 0 0 0
10:53:30.072 -> S :	5C4  43 0 20 3 51 22 68 1
10:53:30.106 -> *****************************
10:53:30.106 -> R :	64D  40 0 20 1 0 0 0 0
10:53:30.106 -> S :	5CD  43 0 20 1 51 85 49 62
10:53:30.106 -> *****************************
10:53:30.106 -> R :	64D  40 0 20 3 0 0 0 0
10:53:30.106 -> S :	5CD  43 0 20 3 51 22 68 1
10:53:30.106 -> *****************************
10:53:30.106 -> R :	656  40 0 20 1 0 0 0 0
10:53:30.106 -> S :	5D6  43 0 20 1 51 85 49 62
10:53:30.106 -> *****************************
10:53:30.106 -> R :	656  40 0 20 3 0 0 0 0
10:53:30.106 -> S :	5D6  43 0 20 3 51 22 68 1
10:53:30.106 -> *****************************
10:53:30.106 -> R :	650  40 0 20 1 0 0 0 0
10:53:30.106 -> S :	5D0  43 0 20 1 51 85 49 62
10:53:30.139 -> *****************************
10:53:30.139 -> R :	650  40 0 20 3 0 0 0 0
10:53:30.139 -> S :	5D0  43 0 20 3 51 22 68 1
10:53:30.139 -> *****************************
10:53:30.139 -> R :	65D  40 0 20 1 0 0 0 0
10:53:30.139 -> S :	5DD  43 0 20 1 51 85 49 62
10:53:30.139 -> *****************************
10:53:30.139 -> R :	65D  40 0 20 3 0 0 0 0
10:53:30.139 -> S :	5DD  43 0 20 3 51 22 68 1
10:53:30.139 -> *****************************
10:53:30.139 -> R :	65D  40 0 20 1 0 0 0 0
10:53:30.139 -> S :	5DD  43 0 20 1 51 85 49 62
10:53:30.139 -> *****************************
10:53:30.139 -> R :	65D  40 0 20 3 0 0 0 0
10:53:30.139 -> S :	5DD  43 0 20 3 51 22 68 1
10:53:30.172 -> *****************************
10:53:30.172 -> R :	65F  40 0 20 1 0 0 0 0
10:53:30.172 -> S :	5DF  43 0 20 1 51 85 49 62
10:53:30.172 -> *****************************
10:53:30.172 -> R :	65F  40 0 20 3 0 0 0 0
10:53:30.172 -> S :	5DF  43 0 20 3 51 22 68 1
10:53:30.205 -> *****************************
10:53:30.205 -> R :	67D  40 0 20 1 0 0 0 0
10:53:30.205 -> S :	5FD  43 0 20 1 51 85 49 62
10:53:30.238 -> *****************************
10:53:30.238 -> R :	67D  40 0 20 3 0 0 0 0
10:53:30.238 -> S :	5FD  43 0 20 3 51 22 68 1
10:53:30.438 -> *****************************
10:53:30.438 -> R :	641  2F 0 5F 3 1 0 0 0
10:53:30.438 -> S :	5C1  60 0 5F 3 0 0 0 0
10:53:30.438 -> *****************************
10:53:30.438 -> R :	641  40 0 5F 2 0 0 0 0
10:53:30.438 -> S :	5C1  43 0 5F 2 0 0 0 0
10:53:30.438 -> *****************************
10:53:30.438 -> R :	641  40 1 5F 3 0 0 0 0
10:53:30.438 -> S :	5C1  43 1 5F 3 0 0 0 0
10:53:30.438 -> *****************************
10:53:30.438 -> R :	641  23 1 5F 4 BD 66 C3 5A
10:53:30.438 -> S :	5C1  60 1 5F 4 0 0 0 0
10:53:30.438 -> *****************************
10:53:30.438 -> R :	641  40 1 5F 3 0 0 0 0
10:53:30.438 -> S :	5C1  43 1 5F 3 0 0 0 0
10:53:30.438 -> *****************************
10:53:30.438 -> R :	641  23 1 5F 4 DB 3C 3C A5
10:53:30.438 -> S :	5C1  60 1 5F 4 0 0 0 0
10:53:30.438 -> *****************************
10:53:30.438 -> R :	641  2F 0 5F 3 3 0 0 0
10:53:30.438 -> S :	5C1  60 0 5F 3 0 0 0 0
10:53:30.438 -> *****************************
10:53:30.438 -> R :	641  40 0 5F 2 0 0 0 0
10:53:30.471 -> S :	5C1  43 0 5F 2 0 0 0 0
10:53:30.471 -> *****************************
10:53:30.471 -> R :	601  40 2 20 4 0 0 0 0      // Read ident string
10:53:30.471 -> S :	581  41 2 20 4 20 0 0 0
10:53:30.471 -> *****************************
10:53:30.471 -> R :	601  60 2 20 4 0 0 0 0
10:53:30.471 -> S :	581  0 45 43 45 32 32 35 20
10:53:30.471 -> *****************************
10:53:30.471 -> R :	601  70 2 20 4 0 0 0 0
10:53:30.471 -> S :	581  10 20 20 20 20 20 20 20
10:53:30.471 -> *****************************
10:53:30.471 -> R :	601  60 2 20 4 0 0 0 0
10:53:30.471 -> S :	581  0 32 30 31 35 20 20 0
10:53:30.471 -> *****************************
10:53:30.471 -> R :	601  70 2 20 4 0 0 0 0
10:53:30.471 -> S :	581  10 0 0 0 0 0 0 0
10:53:30.471 -> *****************************
10:53:30.471 -> R :	601  60 2 20 4 0 0 0 0
10:53:30.471 -> S :	581  7 0 0 0 0 0 0 0
10:53:30.935 -> *****************************

# truckscope wait for 1s