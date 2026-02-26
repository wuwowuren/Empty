#include "INI_CODE_NEED.h"

#include <ntifs.h>


NTSYSAPI NTSTATUS NTAPI ZwQuerySystemInformation(
	IN int SystemInformationClass,
	OUT PVOID SystemInformation,
	IN ULONG SystemInformationLength,
	OUT PULONG ReturnLength OPTIONAL
);

NTSYSAPI NTSTATUS NTAPI NtQuerySystemInformation(
	IN int SystemInformationClass,
	OUT PVOID SystemInformation,
	IN ULONG SystemInformationLength,
	OUT PULONG ReturnLength OPTIONAL
);

//NtQuerySystemInformation


//NTSYSAPI
//NTSTATUS
//NTAPI
//NtQuerySystemInformation(
//	IN int SystemInformationClass,
//	OUT PVOID SystemInformation,
//	IN ULONG SystemInformationLength,
//	OUT PULONG ReturnLength OPTIONAL
//);



typedef struct _KDDEBUGGER_DATA_ADDITION64 {

	// Longhorn addition

	ULONG64   VfCrashDataBlock;
	ULONG64   MmBadPagesDetected;
	ULONG64   MmZeroedPageSingleBitErrorsDetected;

	// Windows 7 addition

	ULONG64   EtwpDebuggerData;
	USHORT    OffsetPrcbContext;

	// Windows 8 addition

	USHORT    OffsetPrcbMaxBreakpoints;
	USHORT    OffsetPrcbMaxWatchpoints;

	ULONG     OffsetKThreadStackLimit;
	ULONG     OffsetKThreadStackBase;
	ULONG     OffsetKThreadQueueListEntry;
	ULONG     OffsetEThreadIrpList;

	USHORT    OffsetPrcbIdleThread;
	USHORT    OffsetPrcbNormalDpcState;
	USHORT    OffsetPrcbDpcStack;
	USHORT    OffsetPrcbIsrStack;

	USHORT    SizeKDPC_STACK_FRAME;

	// Windows 8.1 Addition

	USHORT    OffsetKPriQueueThreadListHead;
	USHORT    OffsetKThreadWaitReason;

	// Windows 10 RS1 Addition

	USHORT    Padding;
	ULONG64   PteBase;

	// Windows 10 RS5 Addition

	ULONG64 RetpolineStubFunctionTable;
	ULONG RetpolineStubFunctionTableSize;
	ULONG RetpolineStubOffset;
	ULONG RetpolineStubSize;

}KDDEBUGGER_DATA_ADDITION64, * PKDDEBUGGER_DATA_ADDITION64;


typedef struct _DBGKD_DEBUG_DATA_HEADER64 {

	//
	// Link to other blocks
	//

	LIST_ENTRY64 List;

	//
	// This is a unique tag to identify the owner of the block.
	// If your component only uses one pool tag, use it for this, too.
	//

	ULONG           OwnerTag;

	//
	// This must be initialized to the size of the data block,
	// including this structure.
	//

	ULONG           Size;

} DBGKD_DEBUG_DATA_HEADER64, * PDBGKD_DEBUG_DATA_HEADER64;

typedef struct _KDDEBUGGER_DATA64 {

	DBGKD_DEBUG_DATA_HEADER64 Header;

	//
	// Base address of kernel image
	//

	ULONG64   KernBase;

	//
	// DbgBreakPointWithStatus is a function which takes an argument
	// and hits a breakpoint.  This field contains the address of the
	// breakpoint instruction.  When the debugger sees a breakpoint
	// at this address, it may retrieve the argument from the first
	// argument register, or on x86 the eax register.
	//

	ULONG64   BreakpointWithStatus;       // address of breakpoint

	//
	// Address of the saved context record during a bugcheck
	//
	// N.B. This is an automatic in KeBugcheckEx's frame, and
	// is only valid after a bugcheck.
	//

	ULONG64   SavedContext;

	//
	// help for walking stacks with user callbacks:
	//

	//
	// The address of the thread structure is provided in the
	// WAIT_STATE_CHANGE packet.  This is the offset from the base of
	// the thread structure to the pointer to the kernel stack frame
	// for the currently active usermode callback.
	//

	USHORT  ThCallbackStack;            // offset in thread data

	//
	// these values are offsets into that frame:
	//

	USHORT  NextCallback;               // saved pointer to next callback frame
	USHORT  FramePointer;               // saved frame pointer

	//
	// pad to a quad boundary
	//
	USHORT  PaeEnabled : 1;

	//
	// Address of the kernel callout routine.
	//

	ULONG64   KiCallUserMode;             // kernel routine

	//
	// Address of the usermode entry point for callbacks.
	//

	ULONG64   KeUserCallbackDispatcher;   // address in ntdll


	//
	// Addresses of various kernel data structures and lists
	// that are of interest to the kernel debugger.
	//

	ULONG64   PsLoadedModuleList;
	ULONG64   PsActiveProcessHead;
	ULONG64   PspCidTable;

	ULONG64   ExpSystemResourcesList;
	ULONG64   ExpPagedPoolDescriptor;
	ULONG64   ExpNumberOfPagedPools;

	ULONG64   KeTimeIncrement;
	ULONG64   KeBugCheckCallbackListHead;
	ULONG64   KiBugcheckData;

	ULONG64   IopErrorLogListHead;

	ULONG64   ObpRootDirectoryObject;
	ULONG64   ObpTypeObjectType;

	ULONG64   MmSystemCacheStart;
	ULONG64   MmSystemCacheEnd;
	ULONG64   MmSystemCacheWs;

	ULONG64   MmPfnDatabase;
	ULONG64   MmSystemPtesStart;
	ULONG64   MmSystemPtesEnd;
	ULONG64   MmSubsectionBase;
	ULONG64   MmNumberOfPagingFiles;

	ULONG64   MmLowestPhysicalPage;
	ULONG64   MmHighestPhysicalPage;
	ULONG64   MmNumberOfPhysicalPages;

	ULONG64   MmMaximumNonPagedPoolInBytes;
	ULONG64   MmNonPagedSystemStart;
	ULONG64   MmNonPagedPoolStart;
	ULONG64   MmNonPagedPoolEnd;

	ULONG64   MmPagedPoolStart;
	ULONG64   MmPagedPoolEnd;
	ULONG64   MmPagedPoolInformation;
	ULONG64   MmPageSize;

	ULONG64   MmSizeOfPagedPoolInBytes;

	ULONG64   MmTotalCommitLimit;
	ULONG64   MmTotalCommittedPages;
	ULONG64   MmSharedCommit;
	ULONG64   MmDriverCommit;
	ULONG64   MmProcessCommit;
	ULONG64   MmPagedPoolCommit;
	ULONG64   MmExtendedCommit;

	ULONG64   MmZeroedPageListHead;
	ULONG64   MmFreePageListHead;
	ULONG64   MmStandbyPageListHead;
	ULONG64   MmModifiedPageListHead;
	ULONG64   MmModifiedNoWritePageListHead;
	ULONG64   MmAvailablePages;
	ULONG64   MmResidentAvailablePages;

	ULONG64   PoolTrackTable;
	ULONG64   NonPagedPoolDescriptor;

	ULONG64   MmHighestUserAddress;
	ULONG64   MmSystemRangeStart;
	ULONG64   MmUserProbeAddress;

	ULONG64   KdPrintCircularBuffer;
	ULONG64   KdPrintCircularBufferEnd;
	ULONG64   KdPrintWritePointer;
	ULONG64   KdPrintRolloverCount;

	ULONG64   MmLoadedUserImageList;

	// NT 5.1 Addition

	ULONG64   NtBuildLab;
	ULONG64   KiNormalSystemCall;

	// NT 5.0 QFE addition

	ULONG64   KiProcessorBlock;
	ULONG64   MmUnloadedDrivers;
	ULONG64   MmLastUnloadedDriver;
	ULONG64   MmTriageActionTaken;
	ULONG64   MmSpecialPoolTag;
	ULONG64   KernelVerifier;
	ULONG64   MmVerifierData;
	ULONG64   MmAllocatedNonPagedPool;
	ULONG64   MmPeakCommitment;
	ULONG64   MmTotalCommitLimitMaximum;
	ULONG64   CmNtCSDVersion;

	// NT 5.1 Addition

	ULONG64   MmPhysicalMemoryBlock;
	ULONG64   MmSessionBase;
	ULONG64   MmSessionSize;
	ULONG64   MmSystemParentTablePage;

	// Server 2003 addition

	ULONG64   MmVirtualTranslationBase;

	USHORT    OffsetKThreadNextProcessor;
	USHORT    OffsetKThreadTeb;
	USHORT    OffsetKThreadKernelStack;
	USHORT    OffsetKThreadInitialStack;

	USHORT    OffsetKThreadApcProcess;
	USHORT    OffsetKThreadState;
	USHORT    OffsetKThreadBStore;
	USHORT    OffsetKThreadBStoreLimit;

	USHORT    SizeEProcess;
	USHORT    OffsetEprocessPeb;
	USHORT    OffsetEprocessParentCID;
	USHORT    OffsetEprocessDirectoryTableBase;

	USHORT    SizePrcb;
	USHORT    OffsetPrcbDpcRoutine;
	USHORT    OffsetPrcbCurrentThread;
	USHORT    OffsetPrcbMhz;

	USHORT    OffsetPrcbCpuType;
	USHORT    OffsetPrcbVendorString;
	USHORT    OffsetPrcbProcStateContext;
	USHORT    OffsetPrcbNumber;

	USHORT    SizeEThread;

	ULONG64   KdPrintCircularBufferPtr;
	ULONG64   KdPrintBufferSize;

	ULONG64   KeLoaderBlock;

	USHORT    SizePcr;
	USHORT    OffsetPcrSelfPcr;
	USHORT    OffsetPcrCurrentPrcb;
	USHORT    OffsetPcrContainedPrcb;

	USHORT    OffsetPcrInitialBStore;
	USHORT    OffsetPcrBStoreLimit;
	USHORT    OffsetPcrInitialStack;
	USHORT    OffsetPcrStackLimit;

	USHORT    OffsetPrcbPcrPage;
	USHORT    OffsetPrcbProcStateSpecialReg;
	USHORT    GdtR0Code;
	USHORT    GdtR0Data;

	USHORT    GdtR0Pcr;
	USHORT    GdtR3Code;
	USHORT    GdtR3Data;
	USHORT    GdtR3Teb;

	USHORT    GdtLdt;
	USHORT    GdtTss;
	USHORT    Gdt64R3CmCode;
	USHORT    Gdt64R3CmTeb;

	ULONG64   IopNumTriageDumpDataBlocks;
	ULONG64   IopTriageDumpDataBlocks;

} KDDEBUGGER_DATA64, * PKDDEBUGGER_DATA64;

typedef struct _DUMP_HEADER {
	ULONG Signature;
	ULONG ValidDump;
	ULONG MajorVersion;
	ULONG MinorVersion;
	ULONG_PTR DirectoryTableBase;
	ULONG_PTR PfnDataBase;
	PLIST_ENTRY PsLoadedModuleList;
	PLIST_ENTRY PsActiveProcessHead;
	ULONG MachineImageType;
	ULONG NumberProcessors;
	ULONG BugCheckCode;
	ULONG_PTR BugCheckParameter1;
	ULONG_PTR BugCheckParameter2;
	ULONG_PTR BugCheckParameter3;
	ULONG_PTR BugCheckParameter4;
	CHAR VersionUser[32];

#ifndef _WIN64
	ULONG PaeEnabled;
#endif // !_WIN64

	struct _KDDEBUGGER_DATA64* KdDebuggerDataBlock;
} DUMP_HEADER, * PDUMP_HEADER;

#ifndef _WIN64
#define DUMP_BLOCK_SIZE 0x20000
#else
#define DUMP_BLOCK_SIZE 0x40000
#endif // !_WIN64


NTSYSAPI
ULONG
NTAPI
KeCapturePersistentThreadState(
	__in PCONTEXT Context,
	__in_opt PKTHREAD Thread,
	__in ULONG BugCheckCode,
	__in ULONG_PTR BugCheckParameter1,
	__in ULONG_PTR BugCheckParameter2,
	__in ULONG_PTR BugCheckParameter3,
	__in ULONG_PTR BugCheckParameter4,
	__in PDUMP_HEADER DumpHeader
);
#ifndef _WIN64
#define KDDEBUGGER_DATA_OFFSET 0x1068
#else
#define KDDEBUGGER_DATA_OFFSET 0x2080
#endif // !_WIN64

//#define SEC_IMAGE         0x1000000 

DWORD64 GetBasePTE() {

	CONTEXT Context = { 0 };
	PDUMP_HEADER DumpHeader = NULL;
	PKDDEBUGGER_DATA64 KdDebuggerDataBlock = NULL;
	PKDDEBUGGER_DATA_ADDITION64 KdDebuggerDataAdditionBlock = NULL;

	Context.ContextFlags = CONTEXT_FULL;

	RtlCaptureContext(&Context);

	DumpHeader = ExAllocatePoolWithTag(NonPagedPool, DUMP_BLOCK_SIZE, 'tag');

	if (DumpHeader == 0)
	{
		return 0;
	}
	DWORD64 PteBase = 0;

	if (NULL != DumpHeader) {
		KeCapturePersistentThreadState(
			&Context,
			NULL,
			0,
			0,
			0,
			0,
			0,
			DumpHeader);

		KdDebuggerDataBlock = (PKDDEBUGGER_DATA64)((UCHAR*)DumpHeader + KDDEBUGGER_DATA_OFFSET);

		KdDebuggerDataAdditionBlock = (PKDDEBUGGER_DATA_ADDITION64)(KdDebuggerDataBlock + 1);

		PteBase = KdDebuggerDataAdditionBlock->PteBase;
	}
	ExFreePoolWithTag(DumpHeader, 'tag');
	return PteBase;
}



#include<ntimage.h>



DWORD64 KernelBaseSize = 0;
ULONG_PTR kernelBase = 0;
ULONG_PTR Win32kBase = 0;
ULONG_PTR Win32kBaseBase = 0;
ULONG_PTR Win32kBaseFull = 0;



typedef NTSTATUS(NTAPI* QuerySystemInformation)(
	IN SYSTEM_INFORMATION_CLASS SystemInformationClass,
	OUT PVOID SystemInformation,
	IN ULONG SystemInformationLength,
	OUT PULONG ReturnLength OPTIONAL);


static QuerySystemInformation NtQuerySystemInformationV = 0;
//------------------------

NTSTATUS NTAPI _ZwQuerySystemInformation(
	IN SYSTEM_INFORMATION_CLASS SystemInformationClass,
	OUT PVOID SystemInformation,
	IN ULONG SystemInformationLength,
	OUT PULONG ReturnLength OPTIONAL)
{
	if (NtQuerySystemInformationV == NULL)
	{
		UNICODE_STRING routineName;
		RtlInitUnicodeString(&routineName, L"NtQuerySystemInformation");

		NtQuerySystemInformationV = (QuerySystemInformation)MmGetSystemRoutineAddress(&routineName);
		LOG_DEBUG("NtQuerySystemInformation %I64X\n", NtQuerySystemInformationV);
		if (NtQuerySystemInformationV == NULL)
		{
			return STATUS_FAIL_CHECK;
		}
		//LOG_DEBUG("NtQuerySystemInformation <%p>\n", NtQuerySystemInformation);
		//return STATUS_FAIL_CHECK;
	}
	return NtQuerySystemInformationV(SystemInformationClass, SystemInformation, SystemInformationLength, ReturnLength);
}

PVOID GetKernelBase(PULONG pImageSize)
{
	typedef struct _SYSTEM_MODULE_ENTRY
	{
		HANDLE Section;
		PVOID MappedBase;
		PVOID ImageBase;
		ULONG ImageSize;
		ULONG Flags;
		USHORT LoadOrderIndex;
		USHORT InitOrderIndex;
		USHORT LoadCount;
		USHORT OffsetToFileName;
		UCHAR FullPathName[256];
	} SYSTEM_MODULE_ENTRY, * PSYSTEM_MODULE_ENTRY;

#pragma warning(disable:4200)
	typedef struct _SYSTEM_MODULE_INFORMATION
	{
		ULONG Count;
		SYSTEM_MODULE_ENTRY Module[0];
	} SYSTEM_MODULE_INFORMATION, * PSYSTEM_MODULE_INFORMATION;

	PVOID pModuleBase = NULL;
	PSYSTEM_MODULE_INFORMATION pSystemInfoBuffer = NULL;

	ULONG SystemInfoBufferSize = 0;

	NTSTATUS status = _ZwQuerySystemInformation(SystemModuleInformation,
		NULL,
		0,
		&SystemInfoBufferSize);

	LOG_DEBUG("SystemInfoBufferSize Szie %d\n", SystemInfoBufferSize);

	// kernelBase

	//sizeof(SYSTEM_MODULE_INFORMATION)

	if (!SystemInfoBufferSize)
	{
		LOG_DEBUG("_ZwQuerySystemInformation ERROR %I64X\n", status);
		return NULL;
	}

	LOG_DEBUG("SystemInfoBufferSize Szie %d\n", SystemInfoBufferSize);

	pSystemInfoBuffer = (PSYSTEM_MODULE_INFORMATION)ExAllocatePoolWithTag(NonPagedPool, SystemInfoBufferSize * 2, 'tag');

	if (!pSystemInfoBuffer)
	{
		LOG_DEBUG("_ZwQuerySystemInformation ExAllocatePool ERROR\n");
		return NULL;
	}

	memset(pSystemInfoBuffer, 0, SystemInfoBufferSize * 2);

	status = _ZwQuerySystemInformation(
		SystemModuleInformation,
		pSystemInfoBuffer,
		SystemInfoBufferSize * 2,
		&SystemInfoBufferSize);

	LOG_DEBUG("nCount %d   size %08X\n", pSystemInfoBuffer->Count, SystemInfoBufferSize);

	//sizeof(SYSTEM_MODULE_ENTRY)

	if (NT_SUCCESS(status))
	{
		pModuleBase = pSystemInfoBuffer->Module[0].ImageBase;
		LOG_DEBUG("Kenerl: %s  %I64X\n", pSystemInfoBuffer->Module[0].FullPathName, pModuleBase);

		if (pImageSize)
			*pImageSize = pSystemInfoBuffer->Module[0].ImageSize;



		//ANSI_STRING Win32KString;
		//RtlInitAnsiString(&Win32KString, "win32k.sys");

		UNICODE_STRING Win32KStringFULL;
		RtlInitUnicodeString(&Win32KStringFULL, L"*WIN32KFULL.SYS");

		UNICODE_STRING Win32KStringBASE;
		RtlInitUnicodeString(&Win32KStringBASE, L"*WIN32KBASE.SYS");

		UNICODE_STRING Win32KString;
		RtlInitUnicodeString(&Win32KString, L"*WIN32K.SYS");
		for (size_t i = 0; i < pSystemInfoBuffer->Count; i++) {

			ANSI_STRING ModString;
			RtlInitAnsiString(&ModString, (PCSZ)pSystemInfoBuffer->Module[i].FullPathName);

			UNICODE_STRING uModString;
			RtlAnsiStringToUnicodeString(&uModString, &ModString, TRUE);


			if (FsRtlIsNameInExpression(&Win32KString, &uModString, TRUE, 0))
			{
				Win32kBase = (ULONG_PTR)pSystemInfoBuffer->Module[i].ImageBase;
				LOG_DEBUG("Win32kBase  Win32k <%p>\n", Win32kBase);
				//break;
			}
			if (FsRtlIsNameInExpression(&Win32KStringBASE, &uModString, TRUE, 0))
			{
				Win32kBaseBase = (ULONG_PTR)pSystemInfoBuffer->Module[i].ImageBase;
				LOG_DEBUG("Win32KStringBASE  Win32k <%p>\n", Win32kBase);
				//break;
			}
			if (FsRtlIsNameInExpression(&Win32KStringFULL, &uModString, TRUE, 0))
			{
				Win32kBaseFull = (ULONG_PTR)pSystemInfoBuffer->Module[i].ImageBase;
				LOG_DEBUG("Win32kBaseFull  Win32k <%p>\n", Win32kBase);
				//break;
			}
			RtlFreeUnicodeString(&uModString);
			if (Win32kBase != 0 && Win32kBaseBase != 0 && Win32kBaseFull != 0)
			{
				break;
			}
		}
	}

#ifdef DEBUG

	//pSystemInfoBuffer->Module[]


#endif


	ExFreePoolWithTag(pSystemInfoBuffer, 'tag');
	return pModuleBase;
}




#define NT_HEADER(Base) (PIMAGE_NT_HEADERS)((ULONG64)(Base) + ((PIMAGE_DOS_HEADER)(Base))->e_lfanew)

PVOID GetProcAddress_Kernel(PVOID ModBase, const char* Name)
{
	PIMAGE_NT_HEADERS64 NT_Head = NT_HEADER(ModBase);
	PIMAGE_EXPORT_DIRECTORY ExportDir = (PIMAGE_EXPORT_DIRECTORY)((ULONG64)ModBase + NT_Head->OptionalHeader.DataDirectory[0].VirtualAddress);

	ULONG* AddressFun = (ULONG*)((ULONG64)ModBase + ExportDir->AddressOfFunctions);
	USHORT* AddressOfNameOrdinals = (USHORT*)((ULONG64)ModBase + ExportDir->AddressOfNameOrdinals);
	ULONG* AddressOfNames = (ULONG*)((ULONG64)ModBase + ExportDir->AddressOfNames);
	for (ULONG i = 0; i < ExportDir->NumberOfNames; i++)
	{
		USHORT Ordinal = AddressOfNameOrdinals[i];
		const char* ExpName = (const char*)ModBase + AddressOfNames[i];
		if (_stricmp(Name, ExpName) == 0) {

			//LOG_DEBUG("%s %s  %08X \n", Name, ExpName, AddressFun[Ordinal]);
			return (PVOID)((ULONG64)ModBase + AddressFun[Ordinal]);
		}

	}
	return 0;

}

BOOLEAN get_PspCidTable(ULONG64* tableAddr) {

	// 获取 PsLookupProcessByProcessId 地址
	UNICODE_STRING uc_funcName;
	RtlInitUnicodeString(&uc_funcName, L"PsLookupProcessByProcessId");
	ULONG64 ul_funcAddr = (ULONG64)MmGetSystemRoutineAddress(&uc_funcName);
	if (ul_funcAddr == 0) {
		//DbgPrint("[LYSM] MmGetSystemRoutineAddress error.\n");
		LOG_DEBUG("[LYSM] MmGetSystemRoutineAddress error  PsLookupProcessByProcessId\n");
		return FALSE;
	}
	//DbgPrint("[LYSM] PsLookupProcessByProcessId:%p\n", ul_funcAddr);

	// 前 40 字节有 call（PspReferenceCidTableEntry）
	ULONG64 ul_entry = 0;
	for (INT i = 0; i < 40; i++) {
		if (*(PUCHAR)(ul_funcAddr + i) == 0xe8) {
			ul_entry = ul_funcAddr + i;
			break;
		}
	}
	if (ul_entry != 0) {
		// 解析 call 地址
		INT i_callCode = *(INT*)(ul_entry + 1);
		//DbgPrint("[LYSM] i_callCode:%X\n", i_callCode);
		ULONG64 ul_callJmp = ul_entry + i_callCode + 5;
		//DbgPrint("[LYSM] ul_callJmp:%p\n", ul_callJmp);
		// 来到 call（PspReferenceCidTableEntry） 内找 PspCidTable
		for (INT i = 0; i < 0x30; i++) {
			if (*(PUCHAR)(ul_callJmp + i) == 0x48 &&
				*(PUCHAR)(ul_callJmp + i + 1) == 0x8b &&
				*(PUCHAR)(ul_callJmp + i + 2) == 0x05) {
				// 解析 mov 地址
				INT i_movCode = *(INT*)(ul_callJmp + i + 3);
				//DbgPrint("[LYSM] i_movCode:%X\n", i_movCode);
				ULONG64 ul_movJmp = ul_callJmp + i + i_movCode + 7;
				//DbgPrint("[LYSM] ul_movJmp:%p\n", ul_movJmp);
				// 得到 PspCidTable
				*tableAddr = ul_movJmp;
				return TRUE;
			}
		}
		LOG_DEBUG("PsLookupProcessByProcessId  find NoTable 1\n");
	}

	// 前 40字节没有 call
	else {
		// 直接在 PsLookupProcessByProcessId 找 PspCidTable
		for (INT i = 0; i < 70; i++) {
			if (*(PUCHAR)(ul_funcAddr + i) == 0x49 &&
				*(PUCHAR)(ul_funcAddr + i + 1) == 0x8b &&
				*(PUCHAR)(ul_funcAddr + i + 2) == 0xdc &&
				*(PUCHAR)(ul_funcAddr + i + 3) == 0x48 &&
				*(PUCHAR)(ul_funcAddr + i + 4) == 0x8b &&
				*(PUCHAR)(ul_funcAddr + i + 5) == 0xd1 &&
				*(PUCHAR)(ul_funcAddr + i + 6) == 0x48 &&
				*(PUCHAR)(ul_funcAddr + i + 7) == 0x8b) {
				// 解析 mov 地址
				INT i_movCode = *(INT*)(ul_funcAddr + i + 6 + 3);
				//DbgPrint("[LYSM] i_movCode:%X\n", i_movCode);
				ULONG64 ul_movJmp = ul_funcAddr + i + 6 + i_movCode + 7;
				//DbgPrint("[LYSM] ul_movJmp:%p\n", ul_movJmp);
				// 得到 PspCidTable
				*tableAddr = ul_movJmp;
				return TRUE;
			}
		}
		LOG_DEBUG("PsLookupProcessByProcessId  find NoTable2\n");
	}
	LOG_DEBUG("PsLookupProcessByProcessId  find NoTable\n");
	return FALSE;
}





#define INI_NTOS_PTR(x) fNtoskernl->x = &x;   LOG_DEBUG("%s <%p>\n",#x,fNtoskernl->x);

//NTKERNELAPI void* __cdecl memset(void* _Dst, int Val, size_t Size);
//NTKERNELAPI void* __cdecl memcpy(void* _Dst, const void* _Src,  size_t _MaxCount);

#define INI_NTOS_PTR_N(x) fNtoskernl->x = (_Kernel_##x)GetProcAddress_Kernel((PVOID)kernelBase,#x);   LOG_DEBUG("%s <%p>\n",#x,fNtoskernl->x);

NTKERNELAPI UCHAR* PsGetProcessImageFileName(PEPROCESS Process);
NTKERNELAPI  PVOID   PsGetProcessSectionBaseAddress(PEPROCESS eprocess);


//__kernel_entry NTSYSCALLAPI
//NTSTATUS
//NTAPI
//NtQueryVirtualMemory(
//	_In_ HANDLE ProcessHandle,
//	_In_opt_ PVOID BaseAddress,
//	_In_ MEMORY_INFORMATION_CLASS MemoryInformationClass,
//	_Out_writes_bytes_(MemoryInformationLength) PVOID MemoryInformation,
//	_In_ SIZE_T MemoryInformationLength,
//	_Out_opt_ PSIZE_T ReturnLength
//);


static ULONGLONG pKeServiceDescriptorTable = 0;
static ULONGLONG pKeServiceDescriptorTable2 = 0;
static ULONGLONG pKeServiceDescriptorTableShow = 0;

NTKERNELAPI PIMAGE_NT_HEADERS NTAPI RtlImageNtHeader(_In_ PVOID Base);

ULONGLONG getKeServiceDescriptorTable7_10(ULONG_PTR kernelBaseV)
{
	//if (pKeServiceDescriptorTable != 0)
	//{
	//	return pKeServiceDescriptorTable;
	//}
		//x64 code


	//

	//KDPC*  = (KDPC*)(KiWaitNever ^ __ROR8__(
	//	(unsigned __int64)Timer ^ _byteswap_uint64((unsigned __int64)Dpc ^ KiWaitAlways),
	//	KiWaitNever));

	//KeSetTimerEx()


	__try {
		ULONG64 kernelSize = KernelBaseSize;


	//	kernelBase = (ULONG_PTR)FindImageBase(L"ntoskrnl.exe", &kernelSize);    //(ULONG_PTR)GetKernelBase(&kernelSize);

		//ULONG64 Win32kSize = 0;

		//Win32kBaseFull = (ULONG_PTR)FindImageBase(L"WIN32KFULL.SYS", &Win32kSize);

		//Win32kBaseBase = (ULONG_PTR)FindImageBase(L"WIN32KBASE.SYS", &Win32kSize);

		//Win32kBase = (ULONG_PTR)FindImageBase(L"WIN32K.SYS", &Win32kSize);


		//LOG_DEBUG("Win32kBaseFull %I64X   Win32kBaseBase %I64X  Win32kBase %I64X", Win32kBaseFull, Win32kBaseBase, Win32kBase);


		if (kernelBaseV == 0 || kernelSize == 0) {

			LOG_DEBUG("GetKernelBase ERROR\n");
			return 0;
		}
		KernelBaseSize = kernelSize;
		const PIMAGE_DOS_HEADER dos_header = (PIMAGE_DOS_HEADER)(kernelBaseV);
		const PIMAGE_NT_HEADERS pNtHeader = (PIMAGE_NT_HEADERS)((PUCHAR)(kernelBaseV)+dos_header->
			e_lfanew);
		const USHORT section_size = pNtHeader->FileHeader.NumberOfSections;
		const PIMAGE_SECTION_HEADER sections_array = (PIMAGE_SECTION_HEADER)((PUCHAR)(pNtHeader)+sizeof(
			IMAGE_NT_HEADERS));
		//for (auto i = 0; i < section_size; i++) {

		//	if (_stricmp(sections_array[i].Name, ".text") == 0)
		//	{
		//		ULONG64 scan_base = (ULONG64)(kernelBaseV)+sections_array[i].VirtualAddress;
		//		int scan_size = max(sections_array[i].SizeOfRawData, sections_array[i].Misc.VirtualSize);
		//		//_Begin_TEXT = sections_array[i].VirtualAddress;
		//		//_Lenth_TEXT = scan_size;

		//		//LOG_DEBUG("TEXT <%08X>  <%08X>\n", _Begin_TEXT, _Lenth_TEXT);

		//	}
		//}
		//	return 0;




		PIMAGE_NT_HEADERS ntHeaders = RtlImageNtHeader((PVOID)kernelBaseV);
		PIMAGE_SECTION_HEADER textSection = NULL;
		PIMAGE_SECTION_HEADER section = IMAGE_FIRST_SECTION(ntHeaders);
		for (ULONG i = 0; i < ntHeaders->FileHeader.NumberOfSections; ++i)
		{
			char sectionName[IMAGE_SIZEOF_SHORT_NAME + 1];
			RtlCopyMemory(sectionName, section->Name, IMAGE_SIZEOF_SHORT_NAME);
			sectionName[IMAGE_SIZEOF_SHORT_NAME] = '\0';
			if (strncmp(sectionName, ".text", sizeof(".text") - sizeof(char)) == 0)
			{
				textSection = section;
				break;
			}
			section++;
		}
		if (textSection == NULL)
		{
			LOG_DEBUG("textSection ERROR\n");
			return 0;
		}



		//LOG_DEBUG(" kernelBase :<%p> textSection->VirtualAddress:<%p> textSection->Misc.VirtualSize : %08X ERROR\n", kernelBase, textSection->VirtualAddress, textSection->Misc.VirtualSize);




		// Find KiSystemServiceStart in .text
		const unsigned char KiSystemServiceStartPattern[] = { 0x8B, 0xF8, 0xC1, 0xEF, 0x07, 0x83, 0xE7, 0x20, 0x25, 0xFF, 0x0F, 0x00, 0x00 };
		const ULONG signatureSize = sizeof(KiSystemServiceStartPattern);
		BOOLEAN found = 0;
		ULONG KiSSSOffset;


		//KIRQL irql = WPOFFx64();

		for (KiSSSOffset = 0; KiSSSOffset < textSection->Misc.VirtualSize - signatureSize; KiSSSOffset++)
		{
			if (RtlCompareMemory(((unsigned char*)kernelBaseV + textSection->VirtualAddress + KiSSSOffset), KiSystemServiceStartPattern, signatureSize) == signatureSize)
			{
				found = 1;
				break;
			}
		}
		if (!found) {


			LOG_DEBUG("found ERROR\n");
			return 0;

		}



		// lea r10, KeServiceDescriptorTable

	// h



		//return 0;



		ULONG_PTR address = kernelBaseV + textSection->VirtualAddress + KiSSSOffset + signatureSize;
		LONG relativeOffset1 = 0;
		LONG relativeOffset2 = 0;

		//KIRQL irql = WPOFFx64();
		//irql = WPOFFx64();
		if ((*(unsigned char*)address == 0x4c) &&
			(*(unsigned char*)(address + 1) == 0x8d) &&
			(*(unsigned char*)(address + 2) == 0x15))
		{

			relativeOffset1 = *(LONG*)(address + 3);

			relativeOffset2 = *(LONG*)(address + 3 + 7);

		}
		//WPONx64(irql);


		LOG_DEBUG("Found IP<%p>\n", address);

		//HideMemory((PVOID)address,0,0);


		//return 0;


		if (relativeOffset1 == 0)
		{
			LOG_DEBUG("found2 ERROR\n");
			return 0;
		}
		pKeServiceDescriptorTable = (ULONGLONG)(address + relativeOffset1 + 7);
		pKeServiceDescriptorTable2 = (ULONGLONG)(address + 7 + relativeOffset2 + 7);
		pKeServiceDescriptorTableShow = pKeServiceDescriptorTable2 + 0x20;
		// SSDT 和 SSDTSHOW 本质上是挨着一起的



		LOG_DEBUG("Table : <%p>   TableShow : <%p>\n", pKeServiceDescriptorTable, pKeServiceDescriptorTableShow);


		return pKeServiceDescriptorTable;
	}
	__except (1) {


		LOG_DEBUG("%s   __except : <%08X>\n", __FUNCTION__, GetExceptionCode());

		return 0;

	}
}



int FindNtIndex(PVOID pZwFun) {

	unsigned char* pFun = (unsigned char*)pZwFun;
	int Index = -1;
	for (size_t i = 0; i < 0x30; i++)
	{
		unsigned char* Now = pFun + i;
		if (Now[0] == (unsigned char)0xB8 &&
			Now[3] == (unsigned char)0 &&
			Now[4] == (unsigned char)0)
		{
			int* pIndex = (int *)(Now + 1);
			Index = *pIndex;
			break;
		}
	}
	return Index;
}


//获取SSDT中的函数地址
ULONGLONG GetSSDTFuncCurrentAddr(PSYSTEM_SERVICE_TABLE std, ULONG id)
{
	if (std != 0)
	{
		LONG dwtemp = 0;
		PULONG ServiceTableBase = NULL;
		ServiceTableBase = (PULONG)std->ServiceTableBase;
		dwtemp = ServiceTableBase[id];
		dwtemp = dwtemp >> 4;
		return (LONGLONG)dwtemp + (ULONGLONG)ServiceTableBase;
	}
	return 0;
}

BOOLEAN Initialize_Ntoskrnl(PNTOSKRNL_FUN fNtoskernl)
{



	kernelBase = (ULONG_PTR)GetKernelBase((PULONG)&KernelBaseSize);
	getKeServiceDescriptorTable7_10(kernelBase);




	fNtoskernl->MmInSwapVirtualAddresses = (_Kernel_MmInSwapVirtualAddresses)(kernelBase + 0x734950);

	LOG_DEBUG("MmInSwapVirtualAddresses %I64X",  *((DWORD64*)fNtoskernl->MmInSwapVirtualAddresses));


	fNtoskernl->MmUserProbeAddress = MmUserProbeAddress;

	fNtoskernl->IoFileObjectType = IoFileObjectType;

	get_PspCidTable(&fNtoskernl->PspCidTable);

	LOG_DEBUG("fNtoskernl->PspCidTable %I64X", fNtoskernl->PspCidTable);

	char* pOffset = (char *)&PsGetProcessSectionBaseAddress;
	pOffset += 3;

	fNtoskernl->offsetSection = *((DWORD*)pOffset) - 8;

	LOG_DEBUG("fNtoskernl->offsetSection %08X", fNtoskernl->offsetSection);

	//IoQueryFileInformation
	

	char* pFun = (char*)&PsGetProcessId;
	fNtoskernl->offsetProcessLink = (*((DWORD*)(pFun + 3)))  + 8;
	LOG_DEBUG("fNtoskernl->offsetProcessLink %08X", fNtoskernl->offsetProcessLink);

	PEPROCESS eprocess = IoGetCurrentProcess();

	fNtoskernl->offsetProcessName = (DWORD64)PsGetProcessImageFileName(eprocess) - (DWORD64)eprocess;

	//INI_NTOS_PTR(ExAllocatePoolWithTag);

	INI_NTOS_PTR(ExAllocatePoolWithTag);
	INI_NTOS_PTR(ExFreePoolWithTag);
	
	INI_NTOS_PTR(RtlStringCchPrintfW);
	INI_NTOS_PTR(RtlEqualUnicodeString);
	INI_NTOS_PTR(RtlInitUnicodeString);


	INI_NTOS_PTR(PsLookupProcessByProcessId);
	INI_NTOS_PTR(PsLookupThreadByThreadId);
	INI_NTOS_PTR(ObfDereferenceObject);
	INI_NTOS_PTR(ObReferenceObjectByHandle);

	//GetProcAddress_Kernel
	fNtoskernl->CopyMemory = (_Kernel_memcpy)GetProcAddress_Kernel((PVOID)kernelBase, "memcpy"); 
	LOG_DEBUG("%s <%p>\n", "CopyMemory", fNtoskernl->CopyMemory);
	//INI_NTOS_PTR(memcpy_s);
	INI_NTOS_PTR_N(memset);
	//INI_NTOS_PTR_N(stricmp);
	fNtoskernl->stricmp = (_Kernel_stricmp)GetProcAddress_Kernel((PVOID)kernelBase, "_stricmp");
	LOG_DEBUG("%s <%p>\n", "stricmp", fNtoskernl->stricmp);


	INI_NTOS_PTR_N(swprintf_s);

	INI_NTOS_PTR_N(RtlStringCbPrintfW);
	//fNtoskernl->RtlStringCbPrintfW = ()
	// RtlStringCbPrintfW

	//INI_NTOS_PTR(strnlen);
	INI_NTOS_PTR_N(strnlen);

	INI_NTOS_PTR(DbgPrintEx);
	INI_NTOS_PTR(IoAllocateMdl);
	INI_NTOS_PTR(IoFreeMdl);
	INI_NTOS_PTR(IoReuseIrp);
	INI_NTOS_PTR(IoAllocateIrp);
	INI_NTOS_PTR(IoFreeIrp);
	INI_NTOS_PTR(IoGetCurrentProcess);

	INI_NTOS_PTR(IoCreateFile);

	INI_NTOS_PTR(IoGetRelatedDeviceObject);
	INI_NTOS_PTR(IofCallDriver);


	INI_NTOS_PTR(MmIsAddressValid);
	INI_NTOS_PTR(MmMapLockedPagesSpecifyCache);
	INI_NTOS_PTR(MmUnmapLockedPages);
	INI_NTOS_PTR(MmProtectMdlSystemAddress);
	INI_NTOS_PTR(MmBuildMdlForNonPagedPool);
	INI_NTOS_PTR(MmGetPhysicalAddress);
	INI_NTOS_PTR(MmAllocateNonCachedMemory);
	INI_NTOS_PTR(MmFreeNonCachedMemory);
	INI_NTOS_PTR(MmProbeAndLockPages);
	INI_NTOS_PTR(MmProbeAndLockSelectedPages);
	INI_NTOS_PTR(MmUnlockPages);

	INI_NTOS_PTR(MmAllocateContiguousMemorySpecifyCache);
	INI_NTOS_PTR(MmFreeContiguousMemory);


	INI_NTOS_PTR(KeStackAttachProcess);
	INI_NTOS_PTR(KeUnstackDetachProcess);
	INI_NTOS_PTR(KeInitializeTimer);
	INI_NTOS_PTR(KeInitializeDpc);
	INI_NTOS_PTR(KeSetTimer);
	INI_NTOS_PTR(KeSetTimerEx);
	INI_NTOS_PTR(KeCancelTimer);
	INI_NTOS_PTR(KeDelayExecutionThread);
	INI_NTOS_PTR(KfRaiseIrql);

	INI_NTOS_PTR(KeSetEvent);
	INI_NTOS_PTR(KeResetEvent);
	INI_NTOS_PTR(KeReadStateEvent);
	INI_NTOS_PTR(KeInitializeEvent);

	INI_NTOS_PTR(KeInitializeApc);
	INI_NTOS_PTR(KeInsertQueueApc);
	//INI_NTOS_PTR(KeRemoveQueueApc);

	INI_NTOS_PTR(KeWaitForSingleObject);
	INI_NTOS_PTR(KeEnterCriticalRegion);
	INI_NTOS_PTR(KeLeaveCriticalRegion);

	INI_NTOS_PTR(KeSetPriorityThread);

	INI_NTOS_PTR(KeSetSystemAffinityThread);

	INI_NTOS_PTR(KeQueryPerformanceCounter);
	INI_NTOS_PTR(KeAcquireSpinLockRaiseToDpc);
	INI_NTOS_PTR(KeReleaseSpinLock);

	INI_NTOS_PTR(KeLowerIrql);
	INI_NTOS_PTR(KfRaiseIrql);

	//IoQueueWorkItem
	INI_NTOS_PTR(ExQueueWorkItem);

	INI_NTOS_PTR(ExGetPreviousMode);

	INI_NTOS_PTR(ExAllocateTimer)
	INI_NTOS_PTR(ExSetTimer)
	INI_NTOS_PTR(ExCancelTimer)
	INI_NTOS_PTR(ExDeleteTimer)

	INI_NTOS_PTR(ExSetTimerResolution);

	INI_NTOS_PTR(ZwAllocateVirtualMemory);
	INI_NTOS_PTR(ZwFreeVirtualMemory);

	//fNtoskernl->ZwAllocateVirtualMemory = &NtAllocateVirtualMemory;
	//fNtoskernl->ZwFreeVirtualMemory = &NtFreeVirtualMemory;

	INI_NTOS_PTR(ZwClose);
	INI_NTOS_PTR(ZwQueryValueKey);
	INI_NTOS_PTR(ZwOpenKey);
	INI_NTOS_PTR(ZwDeleteKey);
	INI_NTOS_PTR(ZwUnloadDriver);
	INI_NTOS_PTR(ZwOpenDirectoryObject);
	INI_NTOS_PTR(ZwOpenSymbolicLinkObject);
	INI_NTOS_PTR(ZwQuerySymbolicLinkObject);


	INI_NTOS_PTR(ZwQueryVirtualMemory);
	

	int Index = FindNtIndex((PVOID)&ZwQueryVirtualMemory);

	LOG_DEBUG("ZwQueryVirtualMemory Index %d %04X", Index, Index);

	if (Index != -1)
	{
		fNtoskernl->NtQueryVirtualMemory = (_Kernel_NtQueryVirtualMemory)GetSSDTFuncCurrentAddr((PSYSTEM_SERVICE_TABLE)pKeServiceDescriptorTable, Index);

		LOG_DEBUG("fNtoskernl->NtQueryVirtualMemory <%p>", fNtoskernl->NtQueryVirtualMemory);
	}
	
	//INI_NTOS_PTR_N(NtQueryVirtualMemory);

	INI_NTOS_PTR(ZwQuerySystemInformation);
	INI_NTOS_PTR(NtQuerySystemInformation);

	INI_NTOS_PTR(PsGetThreadId);
	INI_NTOS_PTR(PsGetProcessPeb);
	INI_NTOS_PTR(PsGetProcessId);

	INI_NTOS_PTR(RtlUnicodeStringToAnsiString);
	INI_NTOS_PTR(RtlFreeAnsiString);



	return TRUE;
}


void* GetWin32kAddress(char* Name) {

	void* fAddress = 0;
	if (Win32kBase != 0){
		fAddress = GetProcAddress_Kernel((PVOID)Win32kBase, Name);
		if (fAddress == 0 && (Win32kBaseFull != 0)) {
			fAddress = GetProcAddress_Kernel((PVOID)Win32kBaseFull, Name);
			if (fAddress == 0 && (Win32kBaseBase != 0)) {
				fAddress = GetProcAddress_Kernel((PVOID)Win32kBaseBase, Name);
			}
		}
	}
	return fAddress;
}


#define  WIN32K_FUN(X) fWin32k->X = GetWin32kAddress(#X);\
             LOG_DEBUG("Win32k "#X "<%p>\n", fWin32k->X);

#pragma warning(disable:4152)

BOOLEAN Initialize_Win32k(WIN32K_FUN* fWin32k) {

	WIN32K_FUN(NtUserEnumDisplaySettings)

	WIN32K_FUN(ValidateHwnd);

	WIN32K_FUN(NtUserCallOneParam);

	WIN32K_FUN(NtUserMapDesktopObject);


	WIN32K_FUN(NtUserGetThreadState);

	WIN32K_FUN(NtUserPostMessage);

	WIN32K_FUN(NtUserCallHwndLock);

	WIN32K_FUN(NtUserGetForegroundWindow);

	WIN32K_FUN(NtUserSetWindowLongPtr);

	WIN32K_FUN(NtUserFindWindowEx);

	WIN32K_FUN(NtUserSendInput);

	WIN32K_FUN(NtUserCloseClipboard);

	WIN32K_FUN(NtUserOpenClipboard);

	WIN32K_FUN(NtUserSetClipboardData);

	WIN32K_FUN(NtUserCreateLocalMemHandle);

	WIN32K_FUN(NtUserEmptyClipboard);

	WIN32K_FUN(NtUserGetClipboardData);

	WIN32K_FUN(NtUserConvertMemHandle);

	WIN32K_FUN(NtUserSetWindowLongPtr);

	WIN32K_FUN(NtUserGetDC); // win32k_NtUserGetDC = 0;

	WIN32K_FUN(NtGdiCreateCompatibleBitmap);//_win32k_NtGdiCreateCompatibleBitmap win32k_NtGdiCreateCompatibleBitmap = 0;

	WIN32K_FUN(NtGdiCreateCompatibleDC);//_win32k_NtGdiCreateCompatibleDC win32k_NtGdiCreateCompatibleDC = 0;

	WIN32K_FUN(NtGdiBitBlt);//_win32k_NtGdiBitBlt win32k_NtGdiBitBlt = 0;

	WIN32K_FUN(NtGdiSelectBitmap);//_win32k_NtGdiSelectBitmap win32k_NtGdiSelectBitmap = 0;


	WIN32K_FUN(NtUserReleaseDC);//_win32k_NtUserReleaseDC Win32k_NtUserReleaseDC = 0;

	WIN32K_FUN(NtGdiExtGetObjectW);//_win32k_NtGdiExtGetObjectW Win32k_NtGdiExtGetObjectW = 0;

	WIN32K_FUN(NtGdiGetBitmapBits);

	RTL_OSVERSIONINFOEXW OsVersion = { 0 };
	OsVersion.dwOSVersionInfoSize = sizeof(OsVersion);
	RtlGetVersion((PRTL_OSVERSIONINFOW)&OsVersion);

	if (OsVersion.dwMajorVersion == 6 && OsVersion.dwMinorVersion == 1)
	{
		fWin32k->SET_FORE_WINDW = 0x73;
		fWin32k->GET_tagHNW = 58;
	}
	else if (OsVersion.dwBuildNumber >= 17763 && OsVersion.dwBuildNumber < 18362) {

		fWin32k->SET_FORE_WINDW = 0x73;
		fWin32k->GET_tagHNW = 58;
	}
	else if (OsVersion.dwBuildNumber >= 18362 && OsVersion.dwBuildNumber < 19041) {
		fWin32k->SET_FORE_WINDW = 0x73;
		fWin32k->GET_tagHNW = 57;
	}
	else if (OsVersion.dwBuildNumber >= 19041 && OsVersion.dwBuildNumber < 20384) {
		fWin32k->SET_FORE_WINDW = 0x70;
		fWin32k->GET_tagHNW = 56;
	}
	else
	{
		fWin32k->SET_FORE_WINDW = 0x70;
		fWin32k->GET_tagHNW = 56;
	}




	return TRUE;
}
