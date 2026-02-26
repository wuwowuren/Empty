#pragma once

#include <ntifs.h>
#include <windef.h>
#include <ntddk.h>
#include <wdm.h>
#include <ntstrsafe.h>
#include <tdikrnl.h>

//typedef PIO_STACK_LOCATION (WINAPI* _Kernel_IoGetCurrentIrpStackLocation)(PIRP Irp);

#ifdef DEBUG
#define LOG_DEBUG(format,...) DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL,"[%d]" format,__LINE__, __VA_ARGS__);
#else
#define LOG_DEBUG(format,...) //DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL,"[%d]" format,__LINE__, __VA_ARGS__);
#endif



#define RECV_SIZE 0x8000
#define SEND_SIZE 0x100000


#define KERNEL_STACK_READ 0x100
#define KERNEL_STACK_WRITE 0x101

#define KERNEL_READ 0
#define KERNEL_WRITE 1

#define KERNEL_POOL 2
#define KERNEL_READ_LIST 3
#define KERNEL_READ_OFFSET 4
#define KERNEL_KeServiceDescriptorTableShadow 3
#define KERNEL_HIDE_PROCESS 4
#define KERNEL_SHOW_PROCESS 5
#define KERNEL_PICTURE 6


#define KERNEL_READ_NEWWORLD_1 0x1001
#define KERNEL_READ_NEWWORLD_2 0x1002
#define KERNEL_READ_NEWWORLD_3 0x1003


#define KERNEL_READ_MEMORY_0 0x8000
#define KERNEL_READ_MEMORY_1 0x8001






typedef enum _KAPC_ENVIRONMENT {
    OriginalApcEnvironment,
    AttachedApcEnvironment,
    CurrentApcEnvironment,
    InsertApcEnvironment
} KAPC_ENVIRONMENT;

typedef
_Function_class_(KRUNDOWN_ROUTINE)
_IRQL_requires_max_(PASSIVE_LEVEL)
_IRQL_requires_min_(PASSIVE_LEVEL)
_IRQL_requires_(PASSIVE_LEVEL)
_IRQL_requires_same_
VOID
KRUNDOWN_ROUTINE(
    _In_ struct _KAPC* Apc
);
typedef KRUNDOWN_ROUTINE* PKRUNDOWN_ROUTINE;

typedef
_Function_class_(KNORMAL_ROUTINE)
_IRQL_requires_max_(PASSIVE_LEVEL)
_IRQL_requires_min_(PASSIVE_LEVEL)
_IRQL_requires_(PASSIVE_LEVEL)
_IRQL_requires_same_
VOID
KNORMAL_ROUTINE(
    _In_opt_ PVOID NormalContext,
    _In_opt_ PVOID SystemArgument1,
    _In_opt_ PVOID SystemArgument2
);
typedef KNORMAL_ROUTINE* PKNORMAL_ROUTINE;
typedef
_Function_class_(KKERNEL_ROUTINE)
_IRQL_requires_max_(APC_LEVEL)
_IRQL_requires_min_(APC_LEVEL)
_IRQL_requires_(APC_LEVEL)
_IRQL_requires_same_
VOID
KKERNEL_ROUTINE(
    _In_ struct _KAPC* Apc,
    _Inout_ PKNORMAL_ROUTINE* NormalRoutine,
    _Inout_ PVOID* NormalContext,
    _Inout_ PVOID* SystemArgument1,
    _Inout_ PVOID* SystemArgument2
);
typedef KKERNEL_ROUTINE* PKKERNEL_ROUTINE;



NTKERNELAPI
VOID
KeInitializeApc(PRKAPC Apc, PRKTHREAD Thread, KAPC_ENVIRONMENT Environment, PKKERNEL_ROUTINE KernelRoutine,
    PKRUNDOWN_ROUTINE RundownRoutine, PKNORMAL_ROUTINE NormalRoutine, KPROCESSOR_MODE ProcessorMode,
    PVOID NormalContext);

NTKERNELAPI
BOOLEAN
KeInsertQueueApc(
    PRKAPC Apc,
    PVOID SystemArgument1,
    PVOID SystemArgument2,
    KPRIORITY Increment
);

//NTKERNELAPI  BOOLEAN KeRemoveQueueApc(PRKAPC Apc);

NTKERNELAPI PVOID NTAPI PsGetProcessPeb(_In_ PEPROCESS Process);

#pragma pack(push)
#pragma pack(4)

typedef struct IOINFO {
	DWORD Error; //要读写的数据,
	DWORD Type; // 需要操作的代码
	DWORD pID;//要读写的进程ID
	void* pAdr; //要读写的地址
	DWORD pAdrSize;//读写长度
	void* pVal;//要读写的数据,
	DWORD pValSize;//读写长度
}IOINFO, * LPIOINFO;



typedef unsigned int uint32_t;

typedef struct _MSGHEAD {
    uint32_t len; 
    uint32_t checknum; 
    uint32_t sgin;
}MSGHEAD;

#define MSGHEAD 	uint32_t len; uint32_t checknum; uint32_t sgin; 

typedef struct MSGCOMMAND {
    MSGHEAD 
	uint32_t Extra;
	char command[16];
}*LPMSGCOMMAND;

// 通用
typedef struct MSGCOMMON {
    MSGHEAD 
	uint32_t common;
}MSGCOMMON, * LPMSGCOMMON;


#pragma pack(pop)


#pragma pack(push, 8)

typedef enum _THREAD_STATE
{
	StateInitialized,
	StateReady,
	StateRunning,
	StateStandby,
	StateTerminated,
	StateWait,
	StateTransition,
	StateUnknown
} THREAD_STATE;


typedef struct _SYSTEM_THREADS_X64
{
	LARGE_INTEGER KernelTime;
	LARGE_INTEGER UserTime;
	LARGE_INTEGER CreateTime;
	ULONG WaitTime;
	PVOID StartAddress;
	CLIENT_ID ClientId;
	KPRIORITY Priority;
	KPRIORITY BasePriority;
	ULONG ContextSwitchCount;
	THREAD_STATE ThreadState;
	KWAIT_REASON WaitReason;
	ULONG Reserved;
} SYSTEM_THREADS_X64, * PSYSTEM_THREADS_X64;

typedef struct _SYSTEM_PROCESSES
{
	ULONG NextEntryDelta; //构成结构序列的偏移量;
	ULONG ThreadCount; //线程数目;
	ULONG Reserved1[6];
	LARGE_INTEGER CreateTime; //创建时间;
	LARGE_INTEGER UserTime;//用户模式(Ring 3)的CPU时间;
	LARGE_INTEGER KernelTime; //内核模式(Ring 0)的CPU时间;
	UNICODE_STRING ProcessName; //进程名称;
	KPRIORITY BasePriority;//进程优先权;
	HANDLE ProcessId; //进程标识符;
	HANDLE InheritedFromProcessId; //父进程的标识符;
	ULONG HandleCount; //句柄数目;
	ULONG Reserved2[2];
	ULONG_PTR PageDirectoryBase;
	VM_COUNTERS  VmCounters; //虚拟存储器的结构，见下;
	SIZE_T PrivatePageCount;
	IO_COUNTERS IoCounters; //IO计数结构，见下;
	struct _SYSTEM_THREADS_X64 Threads[1]; //进程相关线程的结构数组

} _SYSTEM_PROCESSES, * PSYSTEM_PROCESSES;


#define SystemProcessesAndThreadsInformation 5
#pragma pack(pop)

//--------------
//POBJECT_NAME_INFORMATION

typedef struct _SYSTEM_SERVICE_TABLE {
    void* ServiceTableBase;
    void* ServiceCounterTableBase;
    unsigned long long NumberOfServices;
    void* ParamTableBase;
} SYSTEM_SERVICE_TABLE, * PSYSTEM_SERVICE_TABLE;


typedef enum _SYSTEM_INFORMATION_CLASS {
    SystemBasicInformation,                 // q: SYSTEM_BASIC_INFORMATION
    SystemProcessorInformation,             // q: SYSTEM_PROCESSOR_INFORMATION
    SystemPerformanceInformation,           // q: SYSTEM_PERFORMANCE_INFORMATION
    SystemTimeOfDayInformation,             // q: SYSTEM_TIMEOFDAY_INFORMATION
    SystemPathInformation,                  // not implemented
    SystemProcessInformation,               // q: SYSTEM_PROCESS_INFORMATION
    SystemCallCountInformation,             // q: SYSTEM_CALL_COUNT_INFORMATION
    SystemDeviceInformation,                // q: SYSTEM_DEVICE_INFORMATION
    SystemProcessorPerformanceInformation,  // q:
             // SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION
    SystemFlagsInformation,     // q: SYSTEM_FLAGS_INFORMATION
    SystemCallTimeInformation,  // not implemented // SYSTEM_CALL_TIME_INFORMATION
          // // 10
    SystemModuleInformation,    // q: RTL_PROCESS_MODULES
    SystemLocksInformation,     // q: RTL_PROCESS_LOCKS
    SystemStackTraceInformation,    // q: RTL_PROCESS_BACKTRACES
    SystemPagedPoolInformation,     // not implemented
    SystemNonPagedPoolInformation,  // not implemented
    SystemHandleInformation,        // q: SYSTEM_HANDLE_INFORMATION
    SystemObjectInformation,        // q: SYSTEM_OBJECTTYPE_INFORMATION mixed with
    // SYSTEM_OBJECT_INFORMATION
    SystemPageFileInformation,      // q: SYSTEM_PAGEFILE_INFORMATION
    SystemVdmInstemulInformation,   // q
    SystemVdmBopInformation,        // not implemented // 20
    SystemFileCacheInformation,    // q: SYSTEM_FILECACHE_INFORMATION; s (requires
    // SeIncreaseQuotaPrivilege) (info for
    // WorkingSetTypeSystemCache)
    SystemPoolTagInformation,      // q: SYSTEM_POOLTAG_INFORMATION
    SystemInterruptInformation,    // q: SYSTEM_INTERRUPT_INFORMATION
    SystemDpcBehaviorInformation,  // q: SYSTEM_DPC_BEHAVIOR_INFORMATION; s:
    // SYSTEM_DPC_BEHAVIOR_INFORMATION (requires
    // SeLoadDriverPrivilege)
    SystemFullMemoryInformation,   // not implemented
    SystemLoadGdiDriverInformation,    // s (kernel-mode only)
    SystemUnloadGdiDriverInformation,  // s (kernel-mode only)
    SystemTimeAdjustmentInformation,   // q: SYSTEM_QUERY_TIME_ADJUST_INFORMATION;
 // s: SYSTEM_SET_TIME_ADJUST_INFORMATION
 // (requires SeSystemtimePrivilege)
    SystemSummaryMemoryInformation,    // not implemented
    SystemMirrorMemoryInformation,     // s (requires license value
     // "Kernel-MemoryMirroringSupported")
     // (requires SeShutdownPrivilege) // 30
     SystemPerformanceTraceInformation,  // q; s: (type depends on
          // EVENT_TRACE_INFORMATION_CLASS)
          SystemObsolete0,                    // not implemented
          SystemExceptionInformation,         // q: SYSTEM_EXCEPTION_INFORMATION
          SystemCrashDumpStateInformation,    // s (requires SeDebugPrivilege)
          SystemKernelDebuggerInformation,    // q: SYSTEM_KERNEL_DEBUGGER_INFORMATION
          SystemContextSwitchInformation,     // q: SYSTEM_CONTEXT_SWITCH_INFORMATION
          SystemRegistryQuotaInformation,     // q: SYSTEM_REGISTRY_QUOTA_INFORMATION; s
        // (requires SeIncreaseQuotaPrivilege)
        SystemExtendServiceTableInformation,  // s (requires SeLoadDriverPrivilege) //
               // loads win32k only
               SystemPrioritySeperation,             // s (requires SeTcbPrivilege)
               SystemVerifierAddDriverInformation,   // s (requires SeDebugPrivilege) // 40
               SystemVerifierRemoveDriverInformation,  // s (requires SeDebugPrivilege)
               SystemProcessorIdleInformation,    // q: SYSTEM_PROCESSOR_IDLE_INFORMATION
               SystemLegacyDriverInformation,     // q: SYSTEM_LEGACY_DRIVER_INFORMATION
               SystemCurrentTimeZoneInformation,  // q; s: RTL_TIME_ZONE_INFORMATION
               SystemLookasideInformation,        // q: SYSTEM_LOOKASIDE_INFORMATION
               SystemTimeSlipNotification,        // s (requires SeSystemtimePrivilege)
               SystemSessionCreate,               // not implemented
               SystemSessionDetach,               // not implemented
               SystemSessionInformation,     // not implemented (SYSTEM_SESSION_INFORMATION)
               SystemRangeStartInformation,  // q: SYSTEM_RANGE_START_INFORMATION // 50
               SystemVerifierInformation,    // q: SYSTEM_VERIFIER_INFORMATION; s (requires
              // SeDebugPrivilege)
              SystemVerifierThunkExtend,    // s (kernel-mode only)
              SystemSessionProcessInformation,   // q: SYSTEM_SESSION_PROCESS_INFORMATION
              SystemLoadGdiDriverInSystemSpace,  // s (kernel-mode only) (same as
           // SystemLoadGdiDriverInformation)
           SystemNumaProcessorMap,            // q
           SystemPrefetcherInformation,       // q: PREFETCHER_INFORMATION; s:
               // PREFETCHER_INFORMATION //
               // PfSnQueryPrefetcherInformation
               SystemExtendedProcessInformation,  // q: SYSTEM_PROCESS_INFORMATION
               SystemRecommendedSharedDataAlignment,  // q
               SystemComPlusPackage,                  // q; s
               SystemNumaAvailableMemory,             // 60
               SystemProcessorPowerInformation,  // q: SYSTEM_PROCESSOR_POWER_INFORMATION
               SystemEmulationBasicInformation,  // q
               SystemEmulationProcessorInformation,
               SystemExtendedHandleInformation,     // q: SYSTEM_HANDLE_INFORMATION_EX
               SystemLostDelayedWriteInformation,   // q: ULONG
               SystemBigPoolInformation,            // q: SYSTEM_BIGPOOL_INFORMATION
               SystemSessionPoolTagInformation,     // q: SYSTEM_SESSION_POOLTAG_INFORMATION
               SystemSessionMappedViewInformation,  // q:
                     // SYSTEM_SESSION_MAPPED_VIEW_INFORMATION
                     SystemHotpatchInformation,           // q; s: SYSTEM_HOTPATCH_CODE_INFORMATION
                     SystemObjectSecurityMode,            // q: ULONG // 70
                     SystemWatchdogTimerHandler,          // s (kernel-mode only)
                     SystemWatchdogTimerInformation,  // q (kernel-mode only); s (kernel-mode only)
                     SystemLogicalProcessorInformation,  // q: SYSTEM_LOGICAL_PROCESSOR_INFORMATION
                     SystemWow64SharedInformationObsolete,           // not implemented
                     SystemRegisterFirmwareTableInformationHandler,  // s (kernel-mode only)
                     SystemFirmwareTableInformation,   // SYSTEM_FIRMWARE_TABLE_INFORMATION
                     SystemModuleInformationEx,        // q: RTL_PROCESS_MODULE_INFORMATION_EX
                     SystemVerifierTriageInformation,  // not implemented
                     SystemSuperfetchInformation,      // q; s: SUPERFETCH_INFORMATION //
                 // PfQuerySuperfetchInformation
                 SystemMemoryListInformation,      // q: SYSTEM_MEMORY_LIST_INFORMATION; s:
                    // SYSTEM_MEMORY_LIST_COMMAND (requires
                    // SeProfileSingleProcessPrivilege) // 80
                    SystemFileCacheInformationEx,  // q: SYSTEM_FILECACHE_INFORMATION; s (requires
                    // SeIncreaseQuotaPrivilege) (same as
                    // SystemFileCacheInformation)
                    SystemThreadPriorityClientIdInformation,  // s:
                        // SYSTEM_THREAD_CID_PRIORITY_INFORMATION
                        // (requires
                        // SeIncreaseBasePriorityPrivilege)
                        SystemProcessorIdleCycleTimeInformation,  // q:
    // SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION[]
    SystemVerifierCancellationInformation,  // not implemented //
      // name:wow64:whNT32QuerySystemVerifierCancellationInformation
      SystemProcessorPowerInformationEx,  // not implemented
      SystemRefTraceInformation,          // q; s: SYSTEM_REF_TRACE_INFORMATION //
           // ObQueryRefTraceInformation
           SystemSpecialPoolInformation,       // q; s (requires SeDebugPrivilege) //
                // MmSpecialPoolTag, then
                // MmSpecialPoolCatchOverruns != 0
                SystemProcessIdInformation,         // q: SYSTEM_PROCESS_ID_INFORMATION
                SystemErrorPortInformation,         // s (requires SeTcbPrivilege)
                SystemBootEnvironmentInformation,   // q: SYSTEM_BOOT_ENVIRONMENT_INFORMATION
              // // 90
              SystemHypervisorInformation,        // q; s (kernel-mode only)
              SystemVerifierInformationEx,        // q; s: SYSTEM_VERIFIER_INFORMATION_EX
              SystemTimeZoneInformation,          // s (requires SeTimeZonePrivilege)
              SystemImageFileExecutionOptionsInformation,  // s:
                            // SYSTEM_IMAGE_FILE_EXECUTION_OPTIONS_INFORMATION
                            // (requires SeTcbPrivilege)
                            SystemCoverageInformation,  // q; s //
                         // name:wow64:whNT32QuerySystemCoverageInformation;
                         // ExpCovQueryInformation
                         SystemPrefetchPatchInformation,    // not implemented
                         SystemVerifierFaultsInformation,   // s (requires SeDebugPrivilege)
                         SystemSystemPartitionInformation,  // q: SYSTEM_SYSTEM_PARTITION_INFORMATION
                         SystemSystemDiskInformation,       // q: SYSTEM_SYSTEM_DISK_INFORMATION
                         SystemProcessorPerformanceDistribution,  // q:
                            // SYSTEM_PROCESSOR_PERFORMANCE_DISTRIBUTION
                            // // 100
                            SystemNumaProximityNodeInformation,  // q
                            SystemDynamicTimeZoneInformation,    // q; s (requires SeTimeZonePrivilege)
                            SystemCodeIntegrityInformation,      // q: SYSTEM_CODEINTEGRITY_INFORMATION //
   // SeCodeIntegrityQueryInformation
   SystemProcessorMicrocodeUpdateInformation,  // s
   SystemProcessorBrandString,  // q // HaliQuerySystemInformation ->
 // HalpGetProcessorBrandString, info class 23
 SystemVirtualAddressInformation,  // q: SYSTEM_VA_LIST_INFORMATION[]; s:
                            // SYSTEM_VA_LIST_INFORMATION[] (requires
                            // SeIncreaseQuotaPrivilege) //
                            // MmQuerySystemVaInformation
                            SystemLogicalProcessorAndGroupInformation,  // q:
          // SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX
          // // since WIN7 //
          // KeQueryLogicalProcessorRelationship
          SystemProcessorCycleTimeInformation,  // q:
          // SYSTEM_PROCESSOR_CYCLE_TIME_INFORMATION[]
          SystemStoreInformation,      // q; s // SmQueryStoreInformation
          SystemRegistryAppendString,  // s: SYSTEM_REGISTRY_APPEND_STRING_PARAMETERS //
        // 110
        SystemAitSamplingValue,      // s: ULONG (requires
      // SeProfileSingleProcessPrivilege)
      SystemVhdBootInformation,    // q: SYSTEM_VHD_BOOT_INFORMATION
      SystemCpuQuotaInformation,   // q; s // PsQueryCpuQuotaInformation
      SystemNativeBasicInformation,       // not implemented
      SystemSpare1,                       // not implemented
      SystemLowPriorityIoInformation,     // q: SYSTEM_LOW_PRIORITY_IO_INFORMATION
      SystemTpmBootEntropyInformation,    // q: TPM_BOOT_ENTROPY_NT_RESULT //
    // ExQueryTpmBootEntropyInformation
    SystemVerifierCountersInformation,  // q: SYSTEM_VERIFIER_COUNTERS_INFORMATION
    SystemPagedPoolInformationEx,  // q: SYSTEM_FILECACHE_INFORMATION; s (requires
    // SeIncreaseQuotaPrivilege) (info for
    // WorkingSetTypePagedPool)
    SystemSystemPtesInformationEx,  // q: SYSTEM_FILECACHE_INFORMATION; s
     // (requires SeIncreaseQuotaPrivilege) (info
     // for WorkingSetTypeSystemPtes) // 120
     SystemNodeDistanceInformation,  // q
     SystemAcpiAuditInformation,     // q: SYSTEM_ACPI_AUDIT_INFORMATION //
      // HaliQuerySystemInformation ->
      // HalpAuditQueryResults, info class 26
      SystemBasicPerformanceInformation,  // q: SYSTEM_BASIC_PERFORMANCE_INFORMATION
    // //
    // name:wow64:whNtQuerySystemInformation_SystemBasicPerformanceInformation
    SystemQueryPerformanceCounterInformation,  // q:
                // SYSTEM_QUERY_PERFORMANCE_COUNTER_INFORMATION
                // // since WIN7 SP1
                SystemSessionBigPoolInformation,  // q: SYSTEM_SESSION_POOLTAG_INFORMATION //
            // since WIN8
            SystemBootGraphicsInformation,    // q; s: SYSTEM_BOOT_GRAPHICS_INFORMATION
               // (kernel-mode only)
               SystemScrubPhysicalMemoryInformation,  // q; s: MEMORY_SCRUB_INFORMATION
               SystemBadPageInformation,
               SystemProcessorProfileControlArea,  // q; s:
                    // SYSTEM_PROCESSOR_PROFILE_CONTROL_AREA
                    SystemCombinePhysicalMemoryInformation,  // s: MEMORY_COMBINE_INFORMATION,
                       // MEMORY_COMBINE_INFORMATION_EX,
                       // MEMORY_COMBINE_INFORMATION_EX2 //
                       // 130
                       SystemEntropyInterruptTimingCallback,
                       SystemConsoleInformation,         // q: SYSTEM_CONSOLE_INFORMATION
                       SystemPlatformBinaryInformation,  // q: SYSTEM_PLATFORM_BINARY_INFORMATION
                       SystemThrottleNotificationInformation,
                       SystemHypervisorProcessorCountInformation,  // q:
     // SYSTEM_HYPERVISOR_PROCESSOR_COUNT_INFORMATION
     SystemDeviceDataInformation,  // q: SYSTEM_DEVICE_DATA_INFORMATION
     SystemDeviceDataEnumerationInformation,
     SystemMemoryTopologyInformation,  // q: SYSTEM_MEMORY_TOPOLOGY_INFORMATION
     SystemMemoryChannelInformation,   // q: SYSTEM_MEMORY_CHANNEL_INFORMATION
     SystemBootLogoInformation,        // q: SYSTEM_BOOT_LOGO_INFORMATION // 140
     SystemProcessorPerformanceInformationEx,  // q:
         // SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION_EX
         // // since WINBLUE
         SystemSpare0,
         SystemSecureBootPolicyInformation,  // q: SYSTEM_SECUREBOOT_POLICY_INFORMATION
         SystemPageFileInformationEx,        // q: SYSTEM_PAGEFILE_INFORMATION_EX
         SystemSecureBootInformation,        // q: SYSTEM_SECUREBOOT_INFORMATION
         SystemEntropyInterruptTimingRawInformation,
         SystemPortableWorkspaceEfiLauncherInformation,  // q:
                          // SYSTEM_PORTABLE_WORKSPACE_EFI_LAUNCHER_INFORMATION
                          SystemFullProcessInformation,       // q: SYSTEM_PROCESS_INFORMATION with
// SYSTEM_PROCESS_INFORMATION_EXTENSION
// (requires admin)
SystemKernelDebuggerInformationEx,  // q:
                             // SYSTEM_KERNEL_DEBUGGER_INFORMATION_EX
                             SystemBootMetadataInformation,      // 150
                             SystemSoftRebootInformation,
                             SystemElamCertificateInformation,  // s: SYSTEM_ELAM_CERTIFICATE_INFORMATION
                             SystemOfflineDumpConfigInformation,
                             SystemProcessorFeaturesInformation,  // q:
    // SYSTEM_PROCESSOR_FEATURES_INFORMATION
    SystemRegistryReconciliationInformation,
    SystemEdidInformation,
    SystemManufacturingInformation,  // q: SYSTEM_MANUFACTURING_INFORMATION //
      // since THRESHOLD
      SystemEnergyEstimationConfigInformation,  // q:
          // SYSTEM_ENERGY_ESTIMATION_CONFIG_INFORMATION
          SystemHypervisorDetailInformation,  // q: SYSTEM_HYPERVISOR_DETAIL_INFORMATION
          SystemProcessorCycleStatsInformation,  // q:
                  // SYSTEM_PROCESSOR_CYCLE_STATS_INFORMATION
                  // // 160
                  SystemVmGenerationCountInformation,
                  SystemTrustedPlatformModuleInformation,  // q: SYSTEM_TPM_INFORMATION
                  SystemKernelDebuggerFlags,
                  SystemCodeIntegrityPolicyInformation,  // q:
                   // SYSTEM_CODEINTEGRITYPOLICY_INFORMATION
                   SystemIsolatedUserModeInformation,  // q:
                        // SYSTEM_ISOLATED_USER_MODE_INFORMATION
                        SystemHardwareSecurityTestInterfaceResultsInformation,
                        SystemSingleModuleInformation,  // q: SYSTEM_SINGLE_MODULE_INFORMATION
                        SystemAllowedCpuSetsInformation,
                        SystemDmaProtectionInformation,     // q: SYSTEM_DMA_PROTECTION_INFORMATION
                        SystemInterruptCpuSetsInformation,  // q: SYSTEM_INTERRUPT_CPU_SET_INFORMATION
                             // // 170
                             SystemSecureBootPolicyFullInformation,  // q:
// SYSTEM_SECUREBOOT_POLICY_FULL_INFORMATION
SystemCodeIntegrityPolicyFullInformation,
SystemAffinitizedInterruptProcessorInformation,
SystemRootSiloInformation,  // q: SYSTEM_ROOT_SILO_INFORMATION
SystemCpuSetInformation,  // q: SYSTEM_CPU_SET_INFORMATION // since THRESHOLD2
SystemCpuSetTagInformation,  // q: SYSTEM_CPU_SET_TAG_INFORMATION
SystemWin32WerStartCallout,
   SystemSecureKernelProfileInformation,  // q:
        // SYSTEM_SECURE_KERNEL_HYPERGUARD_PROFILE_INFORMATION
        SystemCodeIntegrityPlatformManifestInformation,  // q:
                   // SYSTEM_SECUREBOOT_PLATFORM_MANIFEST_INFORMATION
                   // // since REDSTONE
                   SystemInterruptSteeringInformation,  // 180
                   SystemSupportedProcessorArchitectures,
                   SystemMemoryUsageInformation,  // q: SYSTEM_MEMORY_USAGE_INFORMATION
                   SystemCodeIntegrityCertificateInformation,  // q:
 // SYSTEM_CODEINTEGRITY_CERTIFICATE_INFORMATION
    SystemPhysicalMemoryInformation,  // q: SYSTEM_PHYSICAL_MEMORY_INFORMATION //
    // since REDSTONE2
    SystemControlFlowTransition,
    SystemKernelDebuggingAllowed,
    SystemActivityModerationExeState,      // SYSTEM_ACTIVITY_MODERATION_EXE_STATE
    SystemActivityModerationUserSettings,  // SYSTEM_ACTIVITY_MODERATION_USER_SETTINGS
    SystemCodeIntegrityPoliciesFullInformation,
    SystemCodeIntegrityUnlockInformation,  // SYSTEM_CODEINTEGRITY_UNLOCK_INFORMATION
     // // 190
     SystemIntegrityQuotaInformation,
     SystemFlushInformation,              // q: SYSTEM_FLUSH_INFORMATION
     SystemProcessorIdleMaskInformation,  // since REDSTONE3
     SystemSecureDumpEncryptionInformation,
     SystemWriteConstraintInformation,  // SYSTEM_WRITE_CONSTRAINT_INFORMATION
     MaxSystemInfoClass
} SYSTEM_INFORMATION_CLASS;


#define MI_MAXIMUM_PAGEFILE_SIZE (((UINT64)4 * 1024 * 1024 * 1024 - 1) * PAGE_SIZE)

#define MI_PTE_LOOKUP_NEEDED ((ULONG64)0xffffffff)



#define _HARDWARE_PTE_WORKING_SET_BITS  11

typedef struct _HARDWARE_PTE {
    ULONG64 Valid : 1;
    ULONG64 Write : 1;                // UP version
    ULONG64 Owner : 1;
    ULONG64 WriteThrough : 1;
    ULONG64 CacheDisable : 1;
    ULONG64 Accessed : 1;
    ULONG64 Dirty : 1;
    ULONG64 LargePage : 1;
    ULONG64 Global : 1;
    ULONG64 CopyOnWrite : 1;          // software field
    ULONG64 Prototype : 1;            // software field
    ULONG64 reserved0 : 1;            // software field
    ULONG64 PageFrameNumber : 28;
    ULONG64 reserved1 : 24 - (_HARDWARE_PTE_WORKING_SET_BITS + 1);
    ULONG64 SoftwareWsIndex : _HARDWARE_PTE_WORKING_SET_BITS;
    ULONG64 NoExecute : 1;
} HARDWARE_PTE, * PHARDWARE_PTE;

#define PTE_PER_PAGE_BITS 10 
typedef struct _MMPTE_SOFTWARE {
    ULONGLONG Valid : 1;
    ULONGLONG PageFileLow : 4;
    ULONGLONG Protection : 5;
    ULONGLONG Prototype : 1;
    ULONGLONG Transition : 1;
    ULONGLONG UsedPageTableEntries : PTE_PER_PAGE_BITS;
    ULONGLONG Reserved : 20 - PTE_PER_PAGE_BITS;
    ULONGLONG PageFileHigh : 32;
} MMPTE_SOFTWARE;

typedef struct _MMPTE_TRANSITION {
    ULONGLONG Valid : 1;
    ULONGLONG Write : 1;
    ULONGLONG Owner : 1;
    ULONGLONG WriteThrough : 1;
    ULONGLONG CacheDisable : 1;
    ULONGLONG Protection : 5;
    ULONGLONG Prototype : 1;
    ULONGLONG Transition : 1;
    ULONGLONG PageFrameNumber : 28;
    ULONGLONG Unused : 24;
} MMPTE_TRANSITION;

typedef struct _MMPTE_PROTOTYPE {
    ULONGLONG Valid : 1;
    ULONGLONG Unused0 : 7;
    ULONGLONG ReadOnly : 1;
    ULONGLONG Unused1 : 1;
    ULONGLONG Prototype : 1;
    ULONGLONG Protection : 5;
    LONGLONG ProtoAddress : 48;
} MMPTE_PROTOTYPE;

typedef struct _MMPTE_SUBSECTION {
    ULONGLONG Valid : 1;
    ULONGLONG Unused0 : 4;
    ULONGLONG Protection : 5;
    ULONGLONG Prototype : 1;
    ULONGLONG Unused1 : 5;
    LONGLONG SubsectionAddress : 48;
} MMPTE_SUBSECTION;

typedef struct _MMPTE_LIST {
    ULONGLONG Valid : 1;
    ULONGLONG OneEntry : 1;
    ULONGLONG filler0 : 3;

    //
    // Note the Prototype bit must not be used for lists like freed nonpaged
    // pool because lookaside pops can legitimately reference bogus addresses
    // (since the pop is unsynchronized) and the fault handler must be able to
    // distinguish lists from protos so a retry status can be returned (vs a
    // fatal bugcheck).
    //
    // The same caveat applies to both the Transition and the Protection
    // fields as they are similarly examined in the fault handler and would
    // be misinterpreted if ever nonzero in the freed nonpaged pool chains.
    //

    ULONGLONG Protection : 5;
    ULONGLONG Prototype : 1;        // MUST BE ZERO as per above comment.
    ULONGLONG Transition : 1;

    ULONGLONG filler1 : 20;
    ULONGLONG NextEntry : 32;
} MMPTE_LIST;

typedef struct _MMPTE_HIGHLOW {
    ULONG LowPart;
    ULONG HighPart;
} MMPTE_HIGHLOW;


typedef struct _MMPTE_HARDWARE_LARGEPAGE {
    ULONGLONG Valid : 1;//1
    ULONGLONG Write : 1;//2
    ULONGLONG Owner : 1;//4
    ULONGLONG WriteThrough : 1;//8
    ULONGLONG CacheDisable : 1;//0x10
    ULONGLONG Accessed : 1;//0x20
    ULONGLONG Dirty : 1;//0x40
    ULONGLONG LargePage : 1;//0x80
    ULONGLONG Global : 1;//0x100
    ULONGLONG CopyOnWrite : 1; // software field//0x200
    ULONGLONG Prototype : 1;   // software field // 0x400
    ULONGLONG reserved0 : 1;   // software field //0x800
    ULONGLONG PAT : 1;
    ULONGLONG reserved1 : 8;   // software field
    ULONGLONG PageFrameNumber : 19;
    ULONGLONG reserved2 : 24;   // software field
} MMPTE_HARDWARE_LARGEPAGE, * PMMPTE_HARDWARE_LARGEPAGE;

//
// A Page Table Entry on AMD64 has the following definition.
// Note the MP version is to avoid stalls when flushing TBs across processors.
//

//
// Uniprocessor version.
//

//typedef struct _MMPTE_HARDWARE {
//    ULONGLONG Valid : 1;  // 1
//#if defined(NT_UP)
//    ULONGLONG Write : 1;        // UP version
//#else
//    ULONGLONG Writable : 1;        // changed for MP version // 2
//#endif
//    ULONGLONG Owner : 1;   // 4
//    ULONGLONG WriteThrough : 1; // 8
//    ULONGLONG CacheDisable : 1; //0x10
//    ULONGLONG Accessed : 1; //0x20
//    ULONGLONG Dirty : 1; // 0x40
//    ULONGLONG LargePage : 1; // 0x80
//    ULONGLONG Global : 1; //0x100
//    ULONGLONG CopyOnWrite : 1; // software field //0x200
//    ULONGLONG Prototype : 1;   // software field //0x400
//#if defined(NT_UP)
//    ULONGLONG reserved0 : 1;  // software field
//#else
//    ULONGLONG Write : 1;       // software field - MP change //0x800
//#endif
//    ULONGLONG PageFrameNumber : 28;
//    ULONG64 reserved1 : 24 - (_HARDWARE_PTE_WORKING_SET_BITS + 1);
//    ULONGLONG SoftwareWsIndex : _HARDWARE_PTE_WORKING_SET_BITS;
//    ULONG64 NoExecute : 1;
//} MMPTE_HARDWARE, * PMMPTE_HARDWARE;



typedef struct _MMPTE_HARDWARE {
    ULONGLONG Valid : 1;   //1
    ULONGLONG Dirty1 : 1;   // 2
    ULONGLONG Owner : 1;    // 4
    ULONGLONG WriteThrough : 1; // 8
    ULONGLONG CacheDisable : 1; // 10
    ULONGLONG Accessed : 1; // 20
    ULONGLONG Dirty : 1; // 40
    ULONGLONG LargePage : 1; // 80
    ULONGLONG Global : 1;
    ULONGLONG CopyOnWrite : 1;
    ULONGLONG Unused : 1;
    ULONGLONG Write : 1;
    ULONGLONG PageFrameNumber : 36;
    ULONGLONG ReservedForHardware : 4;
    ULONGLONG ReservedForSoftware : 4;
    ULONGLONG WsleAge : 4;
    ULONGLONG WsleProtection : 3;
    ULONGLONG NoExecute : 1;
} MMPTE_HARDWARE, * PMMPTE_HARDWARE;

//





#if defined(NT_UP)
#define HARDWARE_PTE_DIRTY_MASK     0x40
#else
#define HARDWARE_PTE_DIRTY_MASK     0x42
#endif

#define MI_PDE_MAPS_LARGE_PAGE(PDE) ((PDE)->u.Hard.LargePage == 1)

#define MI_MAKE_PDE_MAP_LARGE_PAGE(PDE) ((PDE)->u.Hard.LargePage = 1)

#define MI_GET_PAGE_FRAME_FROM_PTE(PTE) ((PTE)->u.Hard.PageFrameNumber)
#define MI_GET_PAGE_FRAME_FROM_TRANSITION_PTE(PTE) ((PTE)->u.Trans.PageFrameNumber)
#define MI_GET_PROTECTION_FROM_SOFT_PTE(PTE) ((ULONG)(PTE)->u.Soft.Protection)
#define MI_GET_PROTECTION_FROM_TRANSITION_PTE(PTE) ((ULONG)(PTE)->u.Trans.Protection)

typedef struct _MMPTE {
    union {
        ULONG_PTR Long;
        MMPTE_HARDWARE Hard;
        MMPTE_HARDWARE_LARGEPAGE HardLarge;
        HARDWARE_PTE Flush;
        MMPTE_PROTOTYPE Proto;
        MMPTE_SOFTWARE Soft;
        MMPTE_TRANSITION Trans;
        MMPTE_SUBSECTION Subsect;
        MMPTE_LIST List;
    } u;
} MMPTE, * PMMPTE;


#define PTE_SIZE 512




typedef PVOID(NTAPI* _Kernel_PsGetProcessPeb)(_In_ PEPROCESS Process);

typedef PVOID(NTAPI* _Kernel_ExAllocatePoolWithTag)(POOL_TYPE PoolType, SIZE_T NumberOfBytes, ULONG Tag);

typedef NTSTATUS (NTAPI* _Kernel_RtlStringCchPrintfW)(NTSTRSAFE_PWSTR  pszDest,size_t cchDest,NTSTRSAFE_PCWSTR pszFormat,...);
typedef BOOLEAN(NTAPI* _Kernel_RtlEqualUnicodeString)(PCUNICODE_STRING String1, PCUNICODE_STRING String2, BOOLEAN CaseInSensitive);

typedef VOID(NTAPI* _Kernel_RtlInitUnicodeString)( PUNICODE_STRING DestinationString, PCWSTR SourceString);

typedef NTSTATUS (NTAPI* _Kernel_PsLookupProcessByProcessId)(HANDLE ProcessId,PEPROCESS* Process);

typedef NTSTATUS(NTAPI* _Kernel_PsLookupThreadByThreadId)( HANDLE ThreadId, PETHREAD* Thread);



typedef VOID(NTAPI* _Kernel_KeStackAttachProcess)(PRKPROCESS PROCESS,PRKAPC_STATE ApcState);
typedef VOID(NTAPI* _Kernel_KeUnstackDetachProcess)(PRKAPC_STATE ApcState);
typedef VOID(NTAPI* _Kernel_ExFreePoolWithTag)(PVOID P,ULONG Tag);

typedef	VOID *(__cdecl* _Kernel_memcpy)(void* _Dst, void* _Src, size_t _MaxCount);

typedef VOID *(__cdecl* _Kernel_memset)(void* _Dst, int _Val, size_t _Size);

typedef int (__cdecl* _Kernel_stricmp)(_In_z_ const char* _Str1, _In_z_ const char* _Str2);


typedef size_t(__ALTDECL* _Kernel_strnlen)(const char* _Str, size_t _MaxCount);

typedef BOOLEAN (NTAPI* _Kernel_MmIsAddressValid)(PVOID VirtualAddress);

typedef LONG_PTR (FASTCALL* _Kernel_ObfDereferenceObject)(PVOID Object);


typedef PVOID(NTAPI* _Kernel_MmAllocateNonCachedMemory)(SIZE_T NumberOfBytes);

typedef VOID(NTAPI* _Kernel_MmFreeNonCachedMemory)( PVOID BaseAddress, SIZE_T NumberOfBytes);

typedef PMDL (NTAPI*_Kernel_IoAllocateMdl)(PVOID VirtualAddress,ULONG Length,
	BOOLEAN SecondaryBuffer,BOOLEAN ChargeQuota,PIRP Irp);

typedef VOID (NTAPI* _Kernel_IoReuseIrp)( PIRP Irp,NTSTATUS Iostatus);

typedef PIRP(NTAPI* _Kernel_IoAllocateIrp)( CCHAR StackSize, BOOLEAN ChargeQuota);

typedef VOID(NTAPI* _Kernel_IoFreeIrp)(PIRP Irp);

typedef VOID(NTAPI* _Kernel_IoFreeMdl)(PMDL Mdl);

typedef ULONG (__cdecl* _Kernel_DbgPrintEx)(ULONG ComponentId, ULONG Level, PCSTR Format, ...);

typedef PVOID
(NTAPI* _Kernel_MmMapLockedPagesSpecifyCache)(PMDL MemoryDescriptorList,KPROCESSOR_MODE AccessMode,MEMORY_CACHING_TYPE CacheType,
	PVOID RequestedAddress,ULONG BugCheckOnFailure,ULONG Priority);

typedef VOID(NTAPI* _Kernel_MmUnmapLockedPages)(PVOID BaseAddress,PMDL MemoryDescriptorList);

typedef VOID(NTAPI* _Kernel_MmUnlockPages)(PMDL MemoryDescriptorList);

typedef VOID(NTAPI* _Kernel_MmBuildMdlForNonPagedPool)(PMDL MemoryDescriptorList);

typedef NTSTATUS(NTAPI* _Kernel_MmProtectMdlSystemAddress)(PMDL MemoryDescriptorList,ULONG NewProtect);

typedef VOID(NTAPI* _Kernel_MmProbeAndLockPages)(PMDL MemoryDescriptorList,KPROCESSOR_MODE AccessMode,LOCK_OPERATION Operation);

typedef VOID(NTAPI* _Kernel_MmProbeAndLockSelectedPages)(PMDL MemoryDescriptorList, PFILE_SEGMENT_ELEMENT SegmentArray, KPROCESSOR_MODE AccessMode, LOCK_OPERATION Operation);


//typedef PVOID
//(NTAPI* _Kernel_MmMapLockedPagesSpecifyCache)(PMDL MemoryDescriptorList,KPROCESSOR_MODE AccessMode,MEMORY_CACHING_TYPE CacheType,
//    PVOID RequestedAddress,ULONG BugCheckOnFailure,ULONG Priority);

typedef LARGE_INTEGER(NTAPI* _Kernel_KeQueryPerformanceCounter)(PLARGE_INTEGER PerformanceFrequency);


typedef VOID(NTAPI* _Kernel_MmFreeContiguousMemory)(PVOID BaseAddress);

typedef NTSTATUS (NTAPI* _Kernel_ZwAllocateVirtualMemory)(HANDLE ProcessHandle, PVOID* BaseAddress,ULONG_PTR ZeroBits,
	PSIZE_T RegionSize, ULONG AllocationType,ULONG Protect);
typedef NTSTATUS (NTAPI* _Kernel_ZwFreeVirtualMemory)(HANDLE ProcessHandle,PVOID* BaseAddress,
	PSIZE_T RegionSize,ULONG FreeType);

typedef
NTSTATUS
(NTAPI* _Kernel_ZwQueryVirtualMemory)(
    _In_ HANDLE ProcessHandle,
    _In_opt_ PVOID BaseAddress,
    _In_ MEMORY_INFORMATION_CLASS MemoryInformationClass,
    _Out_writes_bytes_(MemoryInformationLength) PVOID MemoryInformation,
    _In_ SIZE_T MemoryInformationLength,
    _Out_opt_ PSIZE_T ReturnLength
);

typedef
NTSTATUS
(NTAPI* _Kernel_NtQueryVirtualMemory)(
    _In_ HANDLE ProcessHandle,
    _In_opt_ PVOID BaseAddress,
    _In_ MEMORY_INFORMATION_CLASS MemoryInformationClass,
    _Out_writes_bytes_(MemoryInformationLength) PVOID MemoryInformation,
    _In_ SIZE_T MemoryInformationLength,
    _Out_opt_ PSIZE_T ReturnLength
);



typedef NTSTATUS (NTAPI* _Kernel_ZwQuerySystemInformation)(int SystemInformationClass, PVOID SystemInformation,
	ULONG SystemInformationLength, PULONG ReturnLength);

typedef NTSTATUS(NTAPI* _Kernel_NtQuerySystemInformation)(int SystemInformationClass, PVOID SystemInformation,
    ULONG SystemInformationLength, PULONG ReturnLength);


typedef KPROCESSOR_MODE(NTAPI* _Kernel_ExGetPreviousMode)(VOID);

typedef PHYSICAL_ADDRESS (NTAPI* _Kernel_MmGetPhysicalAddress)(PVOID BaseAddress);


typedef NTSTATUS(NTAPI* _Kernel_MmInSwapVirtualAddresses)(PEPROCESS Process, PVOID BaseAddress);

typedef VOID(NTAPI* _Kernel_KeInitializeTimer)(PKTIMER Timer);
typedef
KPRIORITY
(NTAPI* _Kernel_KeSetPriorityThread)(
    _Inout_ PKTHREAD Thread,
    _In_ KPRIORITY Priority
);

typedef VOID(NTAPI* _Kernel_KeInitializeDpc)(PRKDPC Dpc,PKDEFERRED_ROUTINE DeferredRoutine,PVOID DeferredContext);
typedef BOOLEAN(NTAPI* _Kernel_KeSetTimer)(PKTIMER Timer,LARGE_INTEGER DueTime,PKDPC Dpc);
typedef BOOLEAN (NTAPI* _Kernel_KeSetTimerEx)( PKTIMER Timer, LARGE_INTEGER DueTime, LONG Period, PKDPC Dpc);
typedef BOOLEAN(NTAPI* _Kernel_KeCancelTimer)( PKTIMER Timer);

typedef KIRQL(NTAPI* _Kernel_KfRaiseIrql)(KIRQL NewIrql);
typedef VOID(NTAPI* _Kernel_KeLowerIrql)(KIRQL NewIrql);
typedef VOID(NTAPI* _Kernel_KeInitializeEvent)(PRKEVENT Event, EVENT_TYPE Type, BOOLEAN State);

typedef LONG(NTAPI* _Kernel_KeResetEvent)( PRKEVENT Event);

typedef LONG(NTAPI* _Kernel_KeSetEvent)( PRKEVENT Event, KPRIORITY Increment, BOOLEAN Wait);

typedef LONG (NTAPI* _Kernel_KeReadStateEvent)(PRKEVENT Event);

typedef BOOLEAN(NTAPI* _Kernel_KeRemoveQueueApc)(PRKAPC Apc);

typedef ULONG(NTAPI* _Kernel_ExSetTimerResolution)( ULONG DesiredTime, BOOLEAN SetResolution);

typedef
HANDLE
(NTAPI* _Kernel_PsGetProcessId)(
    _In_ PEPROCESS Process
);


typedef
VOID
(NTAPI* _Kernel_KeInitializeApc)(
    _Out_ PRKAPC Apc,
    _In_ PRKTHREAD Thread,
    _In_ KAPC_ENVIRONMENT Environment,
    _In_ PKKERNEL_ROUTINE KernelRoutine,
    _In_opt_ PKRUNDOWN_ROUTINE RundownRoutine,
    _In_opt_ PKNORMAL_ROUTINE NormalRoutine,
    _In_opt_ KPROCESSOR_MODE ProcessorMode,
    _In_opt_ PVOID NormalContext
);

typedef
BOOLEAN
(NTAPI* _Kernel_KeInsertQueueApc)(
    _Inout_ PRKAPC Apc,
    _In_opt_ PVOID SystemArgument1,
    _In_opt_ PVOID SystemArgument2,
    _In_ KPRIORITY Increment
);



typedef
KIRQL
(NTAPI* _Kernel_KeAcquireSpinLockRaiseToDpc)(
    _Inout_ PKSPIN_LOCK SpinLock
);

typedef
VOID
(NTAPI* _Kernel_KeReleaseSpinLock)(
    _Inout_ PKSPIN_LOCK SpinLock,
    _In_ _IRQL_restores_ KIRQL NewIrql
);


typedef
NTSTATUS
(NTAPI* _Kernel_RtlUnicodeStringToAnsiString)(
    _When_(AllocateDestinationString, _Out_ _At_(DestinationString->Buffer, __drv_allocatesMem(Mem)))
    _When_(!AllocateDestinationString, _Inout_)
    PANSI_STRING DestinationString,
    _In_ PCUNICODE_STRING SourceString,
    _In_ BOOLEAN AllocateDestinationString
);


typedef
VOID
(NTAPI* _Kernel_RtlFreeAnsiString)(
    _Inout_ _At_(AnsiString->Buffer, _Frees_ptr_opt_)
    PANSI_STRING AnsiString
);

typedef
NTSTATUS
(NTAPI* _Kernel_IoCreateFile)(
    _Out_ PHANDLE FileHandle,
    _In_  ACCESS_MASK DesiredAccess,
    _In_  POBJECT_ATTRIBUTES ObjectAttributes,
    _Out_ PIO_STATUS_BLOCK IoStatusBlock,
    _In_opt_ PLARGE_INTEGER AllocationSize,
    _In_  ULONG FileAttributes,
    _In_  ULONG ShareAccess,
    _In_  ULONG Disposition,
    _In_  ULONG CreateOptions,
    _In_opt_ PVOID EaBuffer,
    _In_  ULONG EaLength,
    _In_  CREATE_FILE_TYPE CreateFileType,
    _In_opt_ PVOID InternalParameters,
    _In_  ULONG Options
);






typedef KIRQL(NTAPI* _Kernel_KfRaiseIrql)(KIRQL NewIrql);

typedef NTSTATUS(NTAPI* _Kernel_KeDelayExecutionThread)(KPROCESSOR_MODE WaitMode, BOOLEAN Alertable, PLARGE_INTEGER Interval);

typedef VOID(NTAPI* _Kernel_ExQueueWorkItem)(PWORK_QUEUE_ITEM WorkItem, WORK_QUEUE_TYPE QueueType);

#define ExInitializeWorkItemV(Item,Routine,Context) Item->WorkerRoutine = Routine;\
                                                         Item->Parameter = Context;\
                                                           Item->List.Flink = NULL;


typedef
PEX_TIMER(NTAPI* _Kernel_ExAllocateTimer)(
    _In_opt_ PEXT_CALLBACK Callback,
    _In_opt_ PVOID CallbackContext,
    _In_ ULONG Attributes
);

typedef BOOLEAN(NTAPI* _Kernel_ExSetTimer)(
    _In_ PEX_TIMER Timer,
    _In_ LONGLONG DueTime,
    _In_ LONGLONG Period,
    _In_opt_ PEXT_SET_PARAMETERS Parameters
);

typedef
BOOLEAN
(NTAPI* _Kernel_ExCancelTimer)(
    _Inout_ PEX_TIMER Timer,
    _In_opt_ PEXT_CANCEL_PARAMETERS Parameters
);

typedef
BOOLEAN
(NTAPI* _Kernel_ExDeleteTimer)(
    _In_ PEX_TIMER Timer,
    _In_ BOOLEAN Cancel,
    _In_ BOOLEAN Wait,
    _In_opt_ PEXT_DELETE_PARAMETERS Parameters
);



typedef PVOID(NTAPI* _Kernel_MmAllocateContiguousMemorySpecifyCache)(SIZE_T NumberOfBytes, PHYSICAL_ADDRESS LowestAcceptableAddress, PHYSICAL_ADDRESS HighestAcceptableAddress,
    PHYSICAL_ADDRESS BoundaryAddressMultiple, MEMORY_CACHING_TYPE CacheType);

//MmAllocatePagesForMdlEx


typedef HANDLE(NTAPI* _Kernel_PsGetThreadId)( PETHREAD Thread);

typedef PEPROCESS(NTAPI* _Kernel_IoGetCurrentProcess)(VOID);

typedef
NTSTATUS
(NTAPI* _Kernel_ObReferenceObjectByHandle)(
    _In_ HANDLE Handle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_opt_ POBJECT_TYPE ObjectType,
    _In_ KPROCESSOR_MODE AccessMode,
    _Out_ PVOID* Object,
    _Out_opt_ POBJECT_HANDLE_INFORMATION HandleInformation
);

typedef
PDEVICE_OBJECT
(NTAPI* _Kernel_IoGetRelatedDeviceObject)(
    _In_ PFILE_OBJECT FileObject
);

typedef
NTSTATUS
(NTAPI* _Kernel_KeWaitForSingleObject)(
    _In_ _Points_to_data_ PVOID Object,
    _In_ _Strict_type_match_ KWAIT_REASON WaitReason,
    _In_ __drv_strictType(KPROCESSOR_MODE / enum _MODE, __drv_typeConst) KPROCESSOR_MODE WaitMode,
    _In_ BOOLEAN Alertable,
    _In_opt_ PLARGE_INTEGER Timeout
);

typedef
VOID
(NTAPI* _Kernel_KeEnterCriticalRegion)(
    VOID
);

typedef
VOID
(NTAPI* _Kernel_KeLeaveCriticalRegion)(
    VOID
);


typedef
NTSTATUS
(FASTCALL
    * _Kernel_IofCallDriver)(
    _In_ PDEVICE_OBJECT DeviceObject,
    _Inout_ __drv_aliasesMem PIRP Irp
);

typedef
NTSTATUS
(NTAPI* _Kernel_ZwClose)(
    _In_ HANDLE Handle
);


typedef
NTSTATUS
(NTAPI* _Kernel_ZwOpenKey)(
    _Out_ PHANDLE KeyHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_ POBJECT_ATTRIBUTES ObjectAttributes
);

typedef
NTSTATUS
(NTAPI* _Kernel_ZwQueryValueKey)(
    _In_ HANDLE KeyHandle,
    _In_ PUNICODE_STRING ValueName,
    _In_ KEY_VALUE_INFORMATION_CLASS KeyValueInformationClass,
    _Out_writes_bytes_to_opt_(Length, *ResultLength) PVOID KeyValueInformation,
    _In_ ULONG Length,
    _Out_ PULONG ResultLength
);

typedef
NTSTATUS
(NTAPI* _Kernel_ZwUnloadDriver)(
    _In_ PUNICODE_STRING DriverServiceName
);

typedef
NTSTATUS
(NTAPI* _Kernel_ZwOpenDirectoryObject)(
    _Out_ PHANDLE DirectoryHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_ POBJECT_ATTRIBUTES ObjectAttributes
);

typedef
NTSTATUS
(NTAPI* _Kernel_ZwOpenSymbolicLinkObject)(
    _Out_ PHANDLE LinkHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_ POBJECT_ATTRIBUTES ObjectAttributes
);


typedef
NTSTATUS
(NTAPI* _Kernel_ZwQuerySymbolicLinkObject)(
    _In_ HANDLE LinkHandle,
    _Inout_ PUNICODE_STRING LinkTarget,
    _Out_opt_ PULONG ReturnedLength
);

typedef
NTSTATUS
(NTAPI* _Kernel_ZwDeleteKey)(
    _In_ HANDLE KeyHandle
);

typedef
VOID
(NTAPI* _Kernel_KeSetSystemAffinityThread)(
    _In_ KAFFINITY Affinity
);


typedef
NTSTATUS
(NTAPI* _Kernel_RtlStringCbPrintfW)(
    _Out_writes_bytes_(cbDest) _Always_(_Post_z_) NTSTRSAFE_PWSTR pszDest,
    _In_ size_t cbDest,
    _In_ _Printf_format_string_ NTSTRSAFE_PCWSTR pszFormat,
    ...);

typedef
int (__cdecl* _Kernel_swprintf_s)(_Out_writes_z_(_SizeInWords) wchar_t* _Dst, _In_ size_t _SizeInWords, _In_z_ _Printf_format_string_ const wchar_t* _Format, ...);


#define _NTOSKRNL_DEF(x) _Kernel_##x x


typedef int SOCKET;

typedef struct _NTOSKRNL_FUN{
    SOCKET s;
	_Kernel_ExAllocatePoolWithTag ExAllocatePoolWithTag;
	_Kernel_ExFreePoolWithTag ExFreePoolWithTag;
	_Kernel_RtlStringCchPrintfW RtlStringCchPrintfW;
    _NTOSKRNL_DEF(RtlStringCbPrintfW);

	_Kernel_PsLookupProcessByProcessId PsLookupProcessByProcessId;
    _NTOSKRNL_DEF(PsLookupThreadByThreadId);
    _NTOSKRNL_DEF(PsGetProcessPeb);
	_Kernel_KeStackAttachProcess KeStackAttachProcess;
	_Kernel_KeUnstackDetachProcess KeUnstackDetachProcess;
	_Kernel_MmGetPhysicalAddress MmGetPhysicalAddress;
	_Kernel_ObfDereferenceObject ObfDereferenceObject;

    _Kernel_ObReferenceObjectByHandle ObReferenceObjectByHandle;

	_Kernel_MmIsAddressValid MmIsAddressValid;
	_Kernel_memcpy memcpy_s;
	_Kernel_memcpy CopyMemory;
	_Kernel_memset memset;

    _Kernel_MmInSwapVirtualAddresses MmInSwapVirtualAddresses;

    _Kernel_swprintf_s swprintf_s;
	_Kernel_IoAllocateMdl IoAllocateMdl;
	_Kernel_IoFreeMdl IoFreeMdl;

    _NTOSKRNL_DEF(KeSetSystemAffinityThread);
    _NTOSKRNL_DEF(KeQueryPerformanceCounter);

    _NTOSKRNL_DEF(strnlen);

    _NTOSKRNL_DEF(IoReuseIrp);
    _NTOSKRNL_DEF(IoAllocateIrp);
    _NTOSKRNL_DEF(IoFreeIrp);
    _NTOSKRNL_DEF(IoGetCurrentProcess);

    _NTOSKRNL_DEF(IoCreateFile);

    _NTOSKRNL_DEF(IoGetRelatedDeviceObject);

    _NTOSKRNL_DEF(IofCallDriver);

	_Kernel_MmMapLockedPagesSpecifyCache MmMapLockedPagesSpecifyCache;
	_Kernel_MmUnmapLockedPages MmUnmapLockedPages;
    _NTOSKRNL_DEF(MmProbeAndLockSelectedPages);
	_Kernel_MmProtectMdlSystemAddress MmProtectMdlSystemAddress;
	_Kernel_MmBuildMdlForNonPagedPool MmBuildMdlForNonPagedPool;

    _NTOSKRNL_DEF(MmProbeAndLockPages);
    _NTOSKRNL_DEF(MmUnlockPages);

	_Kernel_DbgPrintEx  DbgPrintEx;

    //KeDelayExecutionThread


    _NTOSKRNL_DEF(RtlEqualUnicodeString);
    _NTOSKRNL_DEF(RtlInitUnicodeString);

    _NTOSKRNL_DEF(KeInitializeTimer);
    _NTOSKRNL_DEF(KeInitializeDpc);
    _NTOSKRNL_DEF(KeSetTimer);
    _NTOSKRNL_DEF(KeSetTimerEx);
    _NTOSKRNL_DEF(KeCancelTimer);
    _NTOSKRNL_DEF(KeDelayExecutionThread);

    _NTOSKRNL_DEF(KeSetPriorityThread);

    _NTOSKRNL_DEF(KeSetEvent);
    _NTOSKRNL_DEF(KeResetEvent);
    _NTOSKRNL_DEF(KeReadStateEvent);
    _NTOSKRNL_DEF(KeInitializeEvent);

    _NTOSKRNL_DEF(KeInitializeApc);
    _NTOSKRNL_DEF(KeInsertQueueApc);
    _NTOSKRNL_DEF(KeRemoveQueueApc);

    _NTOSKRNL_DEF(KeWaitForSingleObject);
    _NTOSKRNL_DEF(KeEnterCriticalRegion);
    _NTOSKRNL_DEF(KeLeaveCriticalRegion);

    _NTOSKRNL_DEF(KeAcquireSpinLockRaiseToDpc);
    _NTOSKRNL_DEF(KeReleaseSpinLock);

    

    _NTOSKRNL_DEF(RtlUnicodeStringToAnsiString);
    _NTOSKRNL_DEF(RtlFreeAnsiString);

    _NTOSKRNL_DEF(KeLowerIrql);
    _NTOSKRNL_DEF(KfRaiseIrql);

    _NTOSKRNL_DEF(MmAllocateNonCachedMemory);
    _NTOSKRNL_DEF(MmFreeNonCachedMemory);
    //_NTOSKRNL_DEF(MmMapLockedPagesSpecifyCache);
    _NTOSKRNL_DEF(MmAllocateContiguousMemorySpecifyCache);

    _NTOSKRNL_DEF(MmFreeContiguousMemory);

    _NTOSKRNL_DEF(ExQueueWorkItem);

    _NTOSKRNL_DEF(ExAllocateTimer);
    _NTOSKRNL_DEF(ExSetTimer);
    _NTOSKRNL_DEF(ExCancelTimer);
    _NTOSKRNL_DEF(ExDeleteTimer);

    _NTOSKRNL_DEF(ExGetPreviousMode);

    _NTOSKRNL_DEF(ExSetTimerResolution);

    _NTOSKRNL_DEF(PsGetProcessId);


    _NTOSKRNL_DEF(ZwClose);
    _NTOSKRNL_DEF(ZwQueryValueKey);
    _NTOSKRNL_DEF(ZwOpenKey);
    _NTOSKRNL_DEF(ZwDeleteKey);
    _NTOSKRNL_DEF(ZwUnloadDriver);
    _NTOSKRNL_DEF(ZwOpenDirectoryObject);
    _NTOSKRNL_DEF(ZwOpenSymbolicLinkObject);
    _NTOSKRNL_DEF(ZwQuerySymbolicLinkObject);
    _NTOSKRNL_DEF(ZwQueryVirtualMemory);
    _NTOSKRNL_DEF(NtQueryVirtualMemory);

	_Kernel_ZwAllocateVirtualMemory ZwAllocateVirtualMemory;
	_Kernel_ZwFreeVirtualMemory ZwFreeVirtualMemory;
	_Kernel_ZwQuerySystemInformation ZwQuerySystemInformation;
    _Kernel_NtQuerySystemInformation NtQuerySystemInformation;
    _NTOSKRNL_DEF(PsGetThreadId);


    _NTOSKRNL_DEF(stricmp);

    ULONG64 MmUserProbeAddress;

    POBJECT_TYPE* IoFileObjectType;

    DWORD64 offsetSection;

    DWORD64 offsetProcessLink;
    DWORD64 offsetProcessName;

    ULONG64 PspCidTable;


    ULONG MinTimerRound;

 //typedef int SOCKET;
 //   SOCKET s;

}NTOSKRNL_FUN,* PNTOSKRNL_FUN;


typedef HWND(*_Win32k_NtUserFindWindowEx)(
    IN UINT hwndParent,
    IN UINT hwndChild,
    IN PUNICODE_STRING pstrClassName OPTIONAL,
    IN PUNICODE_STRING pstrWindowName OPTIONAL,
    IN DWORD dwType);



//NtUserGetForegroundWindow

#define  LPARAM LONG_PTR

#define  WPARAM LONG_PTR

typedef  DWORD(*_Win32k_NtUserPostMessage)(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
typedef LONG_PTR(*_Win32k_NtUserSetWindowLongPtr)(HWND hWnd, int nIndex, LONG_PTR dwNewLong, DWORD Flags);
typedef HWND(*_Win32k_NtUserGetForegroundWindow)();

typedef UINT(*_User32_FindWindowW)(LPCWSTR lpClassName, LPCWSTR lpWindowName);

typedef DWORD64(*_Win32k_ValidateHwnd)(HWND Hwnd);




//#define _TDI_DEF(x) _Tdi_##x x;
//
//typedef struct _TDI_FUN {
//
//	//_TDI_DEF(RtlEqualUnicodeString)
//	//	_TDI_DEF(RtlInitUnicodeString)
//	//	_TDI_DEF(KeInitializeTimer)
//	//	_TDI_DEF(KeInitializeDpc)
//	//	_TDI_DEF(KeSetTimer)
//	//	_TDI_DEF(KeSetTimerEx)
//	//	_TDI_DEF(MmAllocateNonCachedMemory)
//	//	_TDI_DEF(MmFreeNonCachedMemory)
//
//}TDI_FUN, * PTDI_FUN;



#include <windef.h>
typedef unsigned long       DWORD;
typedef int                 BOOL;
typedef unsigned char       BYTE;
typedef unsigned int        UINT;
typedef unsigned int* PUINT;
//typedef UINT_PTR            WPARAM;
typedef unsigned short      WORD;

typedef struct tagRAWHID {
	DWORD dwSizeHid;
	DWORD dwCount;
	BYTE  bRawData[1];
} RAWHID, * PRAWHID, * LPRAWHID;

#pragma warning(disable:4201 4100) 
typedef struct tagRAWMOUSE {
	USHORT usFlags;
	union {
		ULONG ulButtons;
		struct {
			USHORT usButtonFlags;
			USHORT usButtonData;
		} DUMMYSTRUCTNAME;
	} DUMMYUNIONNAME;
	ULONG  ulRawButtons;
	LONG   lLastX;
	LONG   lLastY;
	ULONG  ulExtraInformation;
} RAWMOUSE, * PRAWMOUSE, * LPRAWMOUSE;

typedef struct tagRAWKEYBOARD {
	USHORT MakeCode;
	USHORT Flags;
	USHORT Reserved;
	USHORT VKey;
	UINT   Message;
	ULONG  ExtraInformation;
} RAWKEYBOARD, * PRAWKEYBOARD, * LPRAWKEYBOARD;

typedef struct tagRAWINPUTHEADER {
	DWORD  dwType;
	DWORD  dwSize;
	HANDLE hDevice;
	WPARAM wParam;
} RAWINPUTHEADER, * PRAWINPUTHEADER, * LPRAWINPUTHEADER;

typedef struct tagRAWINPUT {
	RAWINPUTHEADER header;
	union {
		RAWMOUSE    mouse;
		RAWKEYBOARD keyboard;
		RAWHID      hid;
	} data;
} RAWINPUT, * PRAWINPUT, * LPRAWINPUT;


#define CCHDEVICENAME 32
#define CCHFORMNAME 32
typedef struct _devicemodeW {
	WCHAR  dmDeviceName[CCHDEVICENAME];
	WORD dmSpecVersion;
	WORD dmDriverVersion;
	WORD dmSize;
	WORD dmDriverExtra;
	DWORD dmFields;
	union {
		/* printer only fields */
		struct {
			short dmOrientation;
			short dmPaperSize;
			short dmPaperLength;
			short dmPaperWidth;
			short dmScale;
			short dmCopies;
			short dmDefaultSource;
			short dmPrintQuality;
		} DUMMYSTRUCTNAME;
		/* display only fields */
		struct {
			POINTL dmPosition;
			DWORD  dmDisplayOrientation;
			DWORD  dmDisplayFixedOutput;
		} DUMMYSTRUCTNAME2;
	} DUMMYUNIONNAME;
	short dmColor;
	short dmDuplex;
	short dmYResolution;
	short dmTTOption;
	short dmCollate;
	WCHAR  dmFormName[CCHFORMNAME];
	WORD   dmLogPixels;
	DWORD  dmBitsPerPel;
	DWORD  dmPelsWidth;
	DWORD  dmPelsHeight;
	union {
		DWORD  dmDisplayFlags;
		DWORD  dmNup;
	} DUMMYUNIONNAME2;
	DWORD  dmDisplayFrequency;
#if(WINVER >= 0x0400)
	DWORD  dmICMMethod;
	DWORD  dmICMIntent;
	DWORD  dmMediaType;
	DWORD  dmDitherType;
	DWORD  dmReserved1;
	DWORD  dmReserved2;
#if (WINVER >= 0x0500) || (_WIN32_WINNT >= _WIN32_WINNT_NT4)
	DWORD  dmPanningWidth;
	DWORD  dmPanningHeight;
#endif
#endif /* WINVER >= 0x0400 */
}DEVMODEW, * PDEVMODEW, * NPDEVMODEW, * LPDEVMODEW;













typedef DWORD(*_Win32k_NtUserGetThreadState)(UINT nInputs);

typedef DWORD64(*_Win32k_NtUserSendInput)(UINT nInputs, void* pInput, INT cbSize);

typedef DWORD(*_Win32k_NtUserCallHwndLock)(HWND Hwnd, DWORD Flags);

typedef void (*_Win32k_NtUserCallTwoParam)(void* Val, DWORD nInputs, DWORD Flags);

typedef DWORD64(*_Win32k_NtUserCallOneParam)(HWND Hwnd, DWORD Flags);

typedef void  (*_Win32k_NtUserCloseClipboard)();

typedef BOOL(*_Win32k_NtUserOpenClipboard)(HWND hWnd, PULONG pFlags);

typedef HANDLE(*_Win32k_NtUserSetClipboardData)(UINT Flags, HANDLE hMem, PULONG pFlags);

typedef HANDLE(*_Win32k_NtUserGetClipboardData)(UINT Flags, PULONG pFlags);

typedef void(*_Win32k_NtUserEmptyClipboard)();

typedef HANDLE(*_Win32k_NtUserConvertMemHandle)(PVOID pData, SIZE_T cbData);

typedef NTSTATUS(*_Win32k_NtUserCreateLocalMemHandle)(HANDLE hMem,
    PVOID pData,
    DWORD cbData,
    DWORD* pcbData);


typedef NTSTATUS(*_Win32k_NtUserEnumDisplaySettings)(PUNICODE_STRING lpszDeviceName, DWORD iModeNum,
    DEVMODEW* lpDevMode, DWORD dwFlags);

typedef HDC(*_win32k_NtUserGetDC)(HWND hwnd);

typedef HBITMAP(*_win32k_NtGdiCreateCompatibleBitmap)(HDC hDC, int cx, int cy);

typedef HDC(*_win32k_NtGdiCreateCompatibleDC)(HDC hdc);

typedef NTSTATUS(*_win32k_NtGdiBitBlt)(HDC hDC, int x, int y, int cx, int cy, HDC hDcSrc, int x1, int y1, DWORD Rop, DWORD64 Flags, DWORD64 Zero);

typedef HGDIOBJ(*_win32k_NtGdiSelectBitmap)(HDC hdc, HGDIOBJ h);

typedef NTSTATUS(*_win32k_NtUserReleaseDC)(HDC hdc);

typedef int(*_win32k_NtGdiExtGetObjectW)(HANDLE h, int c, LPVOID pv);

typedef LONG(*_win32k_NtGdiGetBitmapBits)(HBITMAP hbit, LONG cb, LPVOID lpvBits);


typedef DWORD64(*_win32k_NtUserMapDesktopObject)(HWND hwnd);


typedef struct _WIN32K_FUN {

    _Win32k_NtUserGetThreadState NtUserGetThreadState;
    _Win32k_NtUserCallHwndLock NtUserCallHwndLock;
    _Win32k_NtUserSendInput  NtUserSendInput;
    _Win32k_NtUserCallTwoParam  NtUserCallTwoParam;
    _Win32k_NtUserCallOneParam NtUserCallOneParam;

    _win32k_NtUserMapDesktopObject  NtUserMapDesktopObject;

    _Win32k_NtUserFindWindowEx NtUserFindWindowEx;
    _Win32k_NtUserGetForegroundWindow NtUserGetForegroundWindow;
    _Win32k_NtUserSetWindowLongPtr NtUserSetWindowLongPtr;
    _Win32k_NtUserPostMessage NtUserPostMessage;

    _Win32k_NtUserCloseClipboard NtUserCloseClipboard;
    _Win32k_NtUserOpenClipboard NtUserOpenClipboard;
    _Win32k_NtUserSetClipboardData NtUserSetClipboardData;
    _Win32k_NtUserGetClipboardData NtUserGetClipboardData;

    _Win32k_NtUserConvertMemHandle NtUserConvertMemHandle;
    _Win32k_NtUserCreateLocalMemHandle NtUserCreateLocalMemHandle;
    _Win32k_NtUserEmptyClipboard NtUserEmptyClipboard;
    _Win32k_NtUserEnumDisplaySettings NtUserEnumDisplaySettings;

    //----------  GDI PICTURE

    //_Win32k_ NtUserEnumDisplaySettings

    _win32k_NtUserGetDC NtUserGetDC;

    _win32k_NtGdiCreateCompatibleBitmap NtGdiCreateCompatibleBitmap;

    _win32k_NtGdiCreateCompatibleDC NtGdiCreateCompatibleDC;

    _win32k_NtGdiBitBlt NtGdiBitBlt;

    _win32k_NtGdiSelectBitmap NtGdiSelectBitmap;

    _win32k_NtUserReleaseDC NtUserReleaseDC;

    _win32k_NtGdiExtGetObjectW NtGdiExtGetObjectW;

    _win32k_NtGdiGetBitmapBits NtGdiGetBitmapBits;

    _Win32k_ValidateHwnd  ValidateHwnd;




    DWORD SET_FORE_WINDW;
    DWORD GET_tagHNW;

}WIN32K_FUN,* PWIN32K_FUN;





DWORD64 GetBasePTE();

PVOID GetKernelBase(PULONG pImageSize);

BOOLEAN Initialize_Ntoskrnl(PNTOSKRNL_FUN fNtoskernl);

BOOLEAN Initialize_Win32k(WIN32K_FUN * fWin32k);

//BOOLEAN InitializeCodeFun();







