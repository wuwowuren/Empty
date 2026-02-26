#include "RunEncrypt.h"


//#define  _FUNCTION_IMP(name, x ,...) 	{  _Kernel_SELFCALL _Buffer_Imp = 0;\
//                                         do{ _Buffer_Imp = (_Kernel_SELFCALL)fNtos->MmAllocateNonCachedMemory(fArry->##name##.nPageSize);}while (_Buffer_Imp == 0); \
//                                        fNtos->CopyMemory((PVOID)_Buffer_Imp, fArry->##name##.Ptr, fArry->##name##.MaxSize);\
//                                       ((Global_Data*)pGData)->_hEncrypt_DEC_V.SelfTradition(pGData,fArry->##name##.Sgin,_Buffer_Imp,fArry->##name##.MaxSize);\
//                                       ((Global_Data*)pGData)->SetAddressExecute.SelfTradition(pGData, (PVOID)_Buffer_Imp, fArry->##name##.MaxSize, 0);\
//										x = _Buffer_Imp(__VA_ARGS__);\
//										((Global_Data*)pGData)->SetAddressExecute.SelfTradition(pGData, (PVOID)_Buffer_Imp, fArry->##name##.MaxSize, 1);\
//										fNtos->MmFreeNonCachedMemory((PVOID)_Buffer_Imp, fArry->##name##.nPageSize);}\


//BOOLEAN ExFreeFunctionMemoryRun(PVOID _pGData, SOCKET s, MEMORY_FLAGS* Flags);

#define  _FUNCTION_ENTRY(name,x,y)  /*PMDL pMdl = 0 ;*/ x = pGData->FAllocateMemory(pGData,s, &fArry->##name/*, &pMdl*/); \
                                            u##name = (y)x.ExePtr;

#define  _FUNCTION_ENTRY_NEW(name,x,y)  /*PMDL pMdl = 0 ;*/ x = pGData->FAllocateMemory(pGData,s, &fArry->##name/*, &pMdl*/); \
                                           // u##name = (y)x.Ptr;

//#define  _FUNCTION_ENTRY_MDL(name,x,y,z)  x = (y)pGData->FAllocateMemoryApc(pGData, &fArry->##name/*, z*/);

#define  FREE_FUNCTION_ENTRY(name,x)    pGData->FreeMemory(pGData, s, &x);//(pGData, s, &x);//if (x.Ptr != 0) {fNtos->ExFreePoolWithTag(x.Ptr,'Tag');}//if (x.Flags == 2) { fNtos->MmFreeContiguousMemory(x.Ptr); }else { fNtos->MmFreeNonCachedMemory(x.Ptr, fArry->##name##.nPageSize); }// fNtos->MmFreeNonCachedMemory((PVOID)x, fArry->##name##.nPageSize);\

#define  _FUNCTION_IMP(name, x ,...) 	{ /*PMDL pMdlIMP = 0; */ MEMORY_FLAGS MFlagsIMP = pGData->FAllocateMemory(pGData,s,&fArry->##name##/*, &pMdlIMP*/);\
                                         x = ((_Kernel_SELFCALL)MFlagsIMP.ExePtr)(__VA_ARGS__);\
										 FREE_FUNCTION_ENTRY(name, MFlagsIMP);}\

#define  _FUNCTION_IMP_RET(name, x ,y,...) 	{ MEMORY_FLAGS MFlagsIMP = pGData->FAllocateMemory(pGData,s,&fArry->##name##/*, &pMdlIMP*/);\
										    x = (y)((_Kernel_SELFCALL)MFlagsIMP.ExePtr)(__VA_ARGS__);\
										    FREE_FUNCTION_ENTRY(name, MFlagsIMP);}



//#define  _FUNCTION_IMP(name, x ,...) 	{ /*PMDL pMdlIMP = 0; */\
//                                         _Kernel_SELFCALL _Buffer_Imp = (_Kernel_SELFCALL)pGData->FAllocateMemory(pGData,&fArry->##name##/*, &pMdlIMP*/);\
//										  x = _Buffer_Imp(__VA_ARGS__);\
//										  pGData->fNtos.MmFreeContiguousMemory((PVOID)_Buffer_Imp);\
//                                         /* pGData->fNtos.IoFreeMdl(pMdlIMP);*/} \
//
//#define  _FUNCTION_IMP_APC(name, x ,...) 	{ /*PMDL pMdlIMP = 0; */\
//                                         _Kernel_SELFCALL _Buffer_Imp = (_Kernel_SELFCALL)pGData->FAllocateMemoryApc(pGData,&fArry->##name##/*, &pMdlIMP*/);\
//										  x = _Buffer_Imp(__VA_ARGS__);\
//										 fNtos->MmFreeNonCachedMemory((PVOID)x,fArry->##name##.nPageSize);\
//                                         /* pGData->fNtos.IoFreeMdl(pMdlIMP);*/} \
//
//
//#define  _FUNCTION_IMP_RET(name, x ,y,...) 	{ /*PMDL pMdlIMP = 0; */\
//                                         _Kernel_SELFCALL _Buffer_Imp = (_Kernel_SELFCALL)pGData->FAllocateMemory(pGData,&fArry->##name##/*, &pMdlIMP*/);\
//										  x = (y)_Buffer_Imp(__VA_ARGS__);\
//										  pGData->fNtos.MmFreeContiguousMemory((PVOID)_Buffer_Imp);\
//                                          /*pGData->fNtos.IoFreeMdl(pMdlIMP);*/} \
//
//
//#define  _FUNCTION_ENTRY2(name,x,y) 	{ y _Buffer_Imp = 0;\
//                                     do{ _Buffer_Imp = (y)fNtos->MmAllocateNonCachedMemory(fArry->##name##.nPageSize);}while (_Buffer_Imp == 0); \
//                                     if(_Buffer_Imp != 0) {fNtos->CopyMemory((PVOID)_Buffer_Imp, fArry->##name##.Ptr, fArry->##name##.MaxSize);\
//                                       ((Global_Data*)pGData)->_hEncrypt_DEC_V.SelfTradition(pGData,fArry->##name##.Sgin,_Buffer_Imp,fArry->##name##.MaxSize);\
//                                       ((Global_Data*)pGData)->SetAddressExecute.SelfTradition(pGData, (PVOID)_Buffer_Imp, fArry->##name##.MaxSize, 0);\
//										x = _Buffer_Imp;}}\
//
//
//
//#define  FREE_FUNCTION_ENTRY2(name,x) 	{ if(x != 0){ \
//                                            ((Global_Data*)pGData)->SetAddressExecute.SelfTradition(pGData, (PVOID)x, fArry->##name##.MaxSize, 0);\
//										fNtos->MmFreeNonCachedMemory((PVOID)x,fArry->##name##.nPageSize); x = 0; }}\
//
//
//
//
//#define  _FUNCTION_ENTRY(name,x,y)  /*PMDL pMdl = 0 ; */x = (y)pGData->FAllocateMemory(pGData, &fArry->##name/*, &pMdl*/);
//
//#define  _FUNCTION_ENTRY_MDL(name,x,y,z)  x = (y)pGData->FAllocateMemory(pGData, &fArry->##name/*, z*/);
//
//#define  FREE_FUNCTION_ENTRY(name,x)  fNtos->MmFreeContiguousMemory((PVOID)name);\
//                                      //fNtos->IoFreeMdl(x);
//
//#define  FREE_FUNCTION_ENTRY(name,x)  fNtos->MmFreeNonCachedMemory((PVOID)x,fArry->##name##.nPageSize);
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
//#define FLUSH_FUNCTION_ENTRY(name,x,y) 		FREE_FUNCTION_ENTRY(name, x);\
//                                            _FUNCTION_ENTRY(name, x, y);


#define InsertHeadListV(ListHead, Entry) {PLIST_ENTRY NextEntry = ListHead->Flink;\
	Entry->Flink = NextEntry;\
	Entry->Blink = ListHead;\
	NextEntry->Blink = Entry;\
	ListHead->Flink = Entry;}



FORCEINLINE
BOOLEAN ChangeEntryList(PVOID _pGData, SOCKET s, PLIST_ENTRY HeadEntry, PLIST_ENTRY NowEntry, BOOLEAN Flags) {


	Global_Data* pGData = (Global_Data*)_pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	SOCKET_INFO* pSocket = &pGData->wsk._SocketArry[s];
	KIRQL irql = fNtos->KeAcquireSpinLockRaiseToDpc(&pSocket->MemoryLock);
	if (Flags) {
		InsertHeadList(HeadEntry, NowEntry);
	}
	else
	{
		RemoveEntryList(NowEntry);
	}
	fNtos->KeReleaseSpinLock(&pSocket->MemoryLock, irql);
	return TRUE;
}
//extern BOOLEAN ChangeEntryList(PVOID _pGData, SOCKET s, PLIST_ENTRY HeadEntry, PLIST_ENTRY NowEntry, BOOLEAN Flags);

//__forceinline BOOLEAN ExFreeFunctionMemoryRun(PVOID _pGData, SOCKET s, MEMORY_FLAGS* Flags) {
//
//	Global_Data* pGData = (Global_Data*)_pGData;
//	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
//	SOCKET_INFO* sInfo = &pGData->wsk._SocketArry[s];
//
//
//
//	MMPTE NewPte; NewPte.u.Long = 0x0A00000000000139;
//	NewPte.u.Hard.PageFrameNumber = Flags->pMpte->u.Hard.PageFrameNumber;
//	NewPte.u.Hard.NoExecute = 1;
//	NewPte.u.Hard.Write = 1;
//
//	*(Flags->pMpte) = NewPte;
//	__invlpg(Flags->pMpte);
//
//
//	fNtos->memset(Flags->Ptr, 0, Flags->Size);
//
//	if (Flags->Flags == 2) {
//		if (Flags->MemoryExePtr == 0) {
//			Memory_Exe_Info* MemoryExePtr = (Memory_Exe_Info*)fNtos->ExAllocatePoolWithTag(NonPagedPool, sizeof(Memory_Exe_Info), 'Tag');
//			MemoryExePtr->Ptr = Flags->Ptr;
//			MemoryExePtr->nPageSize = (DWORD)Flags->Size;
//			MemoryExePtr->Flags = Flags->Flags;
//			
//			Flags->MemoryExePtr = MemoryExePtr;
//		}
//		//fNtos->memset(Flags->Ptr, 0, Flags->Size);
//		ChangeEntryList(_pGData, s, (&sInfo->DpcMemory), (&Flags->MemoryExePtr->Link), 1);
//		//InsertHeadListV((&sInfo->DpcMemory), (&Flags->MemoryExePtr->Link));
//	}
//	else
//	{
//		if (Flags->MemoryExePtr == 0) {
//			Memory_Exe_Info* MemoryExePtr = (Memory_Exe_Info*)fNtos->ExAllocatePoolWithTag(NonPagedPool, sizeof(Memory_Exe_Info), 'Tag');
//			MemoryExePtr->Ptr = Flags->Ptr;
//			MemoryExePtr->nPageSize = (DWORD)Flags->Size;
//			MemoryExePtr->Flags = Flags->Flags;
//			Flags->MemoryExePtr = MemoryExePtr;
//		}
//
//		ChangeEntryList(_pGData, s, (&sInfo->ApcMemory), (&Flags->MemoryExePtr->Link), 1);
//
//		//fNtos->memset(Flags->Ptr, 0, Flags->Size);
//		//InsertHeadListV((&sInfo->ApcMemory), (&Flags->MemoryExePtr->Link));
//	}
//	return TRUE;
//}



typedef int (*_sendEncrypt)(PVOID _pGData, SOCKET s, uint32_t Sgin, void* pBuffer, uint32_t nLen);

//#pragma optimize("", off)
unsigned int _hEncrypt0(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {
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
unsigned int _hEncrypt1(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {
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
unsigned int _hEncrypt2(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {
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
unsigned int _hEncrypt3(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {
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
unsigned int _hEncrypt4(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {
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
unsigned int _hEncrypt5(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {
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
unsigned int _hEncrypt6(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {
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
unsigned int _hEncrypt7(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {
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
unsigned int _hEncrypt8(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {
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
unsigned int _hEncrypt9(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {
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
unsigned int _hEncrypt10(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {
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
unsigned int _hEncrypt11(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {
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
unsigned int _hEncrypt12(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {
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
unsigned int _hEncrypt13(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {
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
unsigned int _hEncrypt14(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {
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
unsigned int _hEncrypt15(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {
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
unsigned int _hEncrypt16(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {
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
unsigned int _hEncrypt17(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {
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
unsigned int _hEncrypt18(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {
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
unsigned int _hEncrypt19(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {
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
unsigned int _hEncrypt20(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {
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
///#pragma optimize("", on)


//-----------------------------------------------------------------------------------------------------


void _hEncrypt_DEC0(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {
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
void _hEncrypt_DEC1(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {
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
void _hEncrypt_DEC2(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {
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
void _hEncrypt_DEC3(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {
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
void _hEncrypt_DEC4(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {
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
void _hEncrypt_DEC5(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {
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
void _hEncrypt_DEC6(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {
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
void _hEncrypt_DEC7(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {
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
void _hEncrypt_DEC8(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {
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
void _hEncrypt_DEC9(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {
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
void _hEncrypt_DEC10(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {
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
void _hEncrypt_DEC11(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {
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
void _hEncrypt_DEC12(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {
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
void _hEncrypt_DEC13(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {
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
void _hEncrypt_DEC14(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {
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
void _hEncrypt_DEC15(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {
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
void _hEncrypt_DEC16(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {
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
void _hEncrypt_DEC17(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {
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
void _hEncrypt_DEC18(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {
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
void _hEncrypt_DEC19(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {
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


//-----------------------------------------------------------------------------------------------------



void _hEncrypt_DEC_V0(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {

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
void _hEncrypt_DEC_V1(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {

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
void _hEncrypt_DEC_V2(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {

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
void _hEncrypt_DEC_V3(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {

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
void _hEncrypt_DEC_V4(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {

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
void _hEncrypt_DEC_V5(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {

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
void _hEncrypt_DEC_V6(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {

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
void _hEncrypt_DEC_V7(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {

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
void _hEncrypt_DEC_V8(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {

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
void _hEncrypt_DEC_V9(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {

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
void _hEncrypt_DEC_V10(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {

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
void _hEncrypt_DEC_V11(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {

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
void _hEncrypt_DEC_V12(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {

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
void _hEncrypt_DEC_V13(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {

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
void _hEncrypt_DEC_V14(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {

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
void _hEncrypt_DEC_V15(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {

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
void _hEncrypt_DEC_V16(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {

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
void _hEncrypt_DEC_V17(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {

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
void _hEncrypt_DEC_V18(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {

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
void _hEncrypt_DEC_V19(PVOID pGData, unsigned int RandSgin, void* pDate, unsigned int Size) {

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


void SetAddressExecute0(PVOID pGData, PVOID Ptr, DWORD nSize, DWORD Flags) {

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
		pMmpte->u.Hard.NoExecute = Flags;
		__invlpg(pMmpte);
	}
}
void SetAddressExecute1(PVOID pGData, PVOID Ptr, DWORD nSize, DWORD Flags) {

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
		pMmpte->u.Hard.NoExecute = Flags;
		__invlpg(pMmpte);
	}
}
void SetAddressExecute2(PVOID pGData, PVOID Ptr, DWORD nSize, DWORD Flags) {

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
		pMmpte->u.Hard.NoExecute = Flags;
		__invlpg(pMmpte);
	}
}
void SetAddressExecute3(PVOID pGData, PVOID Ptr, DWORD nSize, DWORD Flags) {

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
		pMmpte->u.Hard.NoExecute = Flags;
		__invlpg(pMmpte);
	}
}
void SetAddressExecute4(PVOID pGData, PVOID Ptr, DWORD nSize, DWORD Flags) {

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
		pMmpte->u.Hard.NoExecute = Flags;
		__invlpg(pMmpte);
	}
}
void SetAddressExecute5(PVOID pGData, PVOID Ptr, DWORD nSize, DWORD Flags) {

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
		pMmpte->u.Hard.NoExecute = Flags;
		__invlpg(pMmpte);
	}
}
void SetAddressExecute6(PVOID pGData, PVOID Ptr, DWORD nSize, DWORD Flags) {

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
		pMmpte->u.Hard.NoExecute = Flags;
		__invlpg(pMmpte);
	}
}
void SetAddressExecute7(PVOID pGData, PVOID Ptr, DWORD nSize, DWORD Flags) {

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
		pMmpte->u.Hard.NoExecute = Flags;
		__invlpg(pMmpte);
	}
}
void SetAddressExecute8(PVOID pGData, PVOID Ptr, DWORD nSize, DWORD Flags) {

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
		pMmpte->u.Hard.NoExecute = Flags;
		__invlpg(pMmpte);
	}
}
void SetAddressExecute9(PVOID pGData, PVOID Ptr, DWORD nSize, DWORD Flags) {

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
		pMmpte->u.Hard.NoExecute = Flags;
		__invlpg(pMmpte);
	}
}
void SetAddressExecute10(PVOID pGData, PVOID Ptr, DWORD nSize, DWORD Flags) {

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
		pMmpte->u.Hard.NoExecute = Flags;
		__invlpg(pMmpte);
	}
}
void SetAddressExecute11(PVOID pGData, PVOID Ptr, DWORD nSize, DWORD Flags) {

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
		pMmpte->u.Hard.NoExecute = Flags;
		__invlpg(pMmpte);
	}
}
void SetAddressExecute12(PVOID pGData, PVOID Ptr, DWORD nSize, DWORD Flags) {

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
		pMmpte->u.Hard.NoExecute = Flags;
		__invlpg(pMmpte);
	}
}
void SetAddressExecute13(PVOID pGData, PVOID Ptr, DWORD nSize, DWORD Flags) {

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
		pMmpte->u.Hard.NoExecute = Flags;
		__invlpg(pMmpte);
	}
}
void SetAddressExecute14(PVOID pGData, PVOID Ptr, DWORD nSize, DWORD Flags) {

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
		pMmpte->u.Hard.NoExecute = Flags;
		__invlpg(pMmpte);
	}
}
void SetAddressExecute15(PVOID pGData, PVOID Ptr, DWORD nSize, DWORD Flags) {

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
		pMmpte->u.Hard.NoExecute = Flags;
		__invlpg(pMmpte);
	}
}
void SetAddressExecute16(PVOID pGData, PVOID Ptr, DWORD nSize, DWORD Flags) {

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
		pMmpte->u.Hard.NoExecute = Flags;
		__invlpg(pMmpte);
	}
}
void SetAddressExecute17(PVOID pGData, PVOID Ptr, DWORD nSize, DWORD Flags) {

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
		pMmpte->u.Hard.NoExecute = Flags;
		__invlpg(pMmpte);
	}
}
void SetAddressExecute18(PVOID pGData, PVOID Ptr, DWORD nSize, DWORD Flags) {

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
		pMmpte->u.Hard.NoExecute = Flags;
		__invlpg(pMmpte);
	}
}
void SetAddressExecute19(PVOID pGData, PVOID Ptr, DWORD nSize, DWORD Flags) {

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
		pMmpte->u.Hard.NoExecute = Flags;
		__invlpg(pMmpte);
	}
}





//---------------------------------------------------------------------------------------



void _WORKER_THREAD_ROUTINE0(PVOID Parameter) {
	WORKER_THREAD_INFO* pWorkInfo = (WORKER_THREAD_INFO*)Parameter;
	Global_Data* pGData = (Global_Data*)pWorkInfo->pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	SELF_F_ARRY* fArry = &pGData->SelfFArry;
	DWORD64 Ret = 0;
	SOCKET s = pWorkInfo->s;
	_FUNCTION_IMP(RunApcRunCode, Ret, pGData, pWorkInfo->s, pWorkInfo->Flags);
}
void _WORKER_THREAD_ROUTINE1(PVOID Parameter) {
	WORKER_THREAD_INFO* pWorkInfo = (WORKER_THREAD_INFO*)Parameter;
	Global_Data* pGData = (Global_Data*)pWorkInfo->pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	SELF_F_ARRY* fArry = &pGData->SelfFArry;
	DWORD64 Ret = 0;
	SOCKET s = pWorkInfo->s;
	_FUNCTION_IMP(RunApcRunCode, Ret, pGData, pWorkInfo->s, pWorkInfo->Flags);
}
void _WORKER_THREAD_ROUTINE2(PVOID Parameter) {
	WORKER_THREAD_INFO* pWorkInfo = (WORKER_THREAD_INFO*)Parameter;
	Global_Data* pGData = (Global_Data*)pWorkInfo->pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	SELF_F_ARRY* fArry = &pGData->SelfFArry;
	DWORD64 Ret = 0;
	SOCKET s = pWorkInfo->s;
	_FUNCTION_IMP(RunApcRunCode, Ret, pGData, pWorkInfo->s, pWorkInfo->Flags);
}
void _WORKER_THREAD_ROUTINE3(PVOID Parameter) {
	WORKER_THREAD_INFO* pWorkInfo = (WORKER_THREAD_INFO*)Parameter;
	Global_Data* pGData = (Global_Data*)pWorkInfo->pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	SELF_F_ARRY* fArry = &pGData->SelfFArry;
	DWORD64 Ret = 0;
	SOCKET s = pWorkInfo->s;
	_FUNCTION_IMP(RunApcRunCode, Ret, pGData, pWorkInfo->s, pWorkInfo->Flags);
}
void _WORKER_THREAD_ROUTINE4(PVOID Parameter) {
	WORKER_THREAD_INFO* pWorkInfo = (WORKER_THREAD_INFO*)Parameter;
	Global_Data* pGData = (Global_Data*)pWorkInfo->pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	SELF_F_ARRY* fArry = &pGData->SelfFArry;
	DWORD64 Ret = 0;
	SOCKET s = pWorkInfo->s;
	_FUNCTION_IMP(RunApcRunCode, Ret, pGData, pWorkInfo->s, pWorkInfo->Flags);
}
void _WORKER_THREAD_ROUTINE5(PVOID Parameter) {
	WORKER_THREAD_INFO* pWorkInfo = (WORKER_THREAD_INFO*)Parameter;
	Global_Data* pGData = (Global_Data*)pWorkInfo->pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	SELF_F_ARRY* fArry = &pGData->SelfFArry;
	DWORD64 Ret = 0;
	SOCKET s = pWorkInfo->s;
	_FUNCTION_IMP(RunApcRunCode, Ret, pGData, pWorkInfo->s, pWorkInfo->Flags);
}
void _WORKER_THREAD_ROUTINE6(PVOID Parameter) {
	WORKER_THREAD_INFO* pWorkInfo = (WORKER_THREAD_INFO*)Parameter;
	Global_Data* pGData = (Global_Data*)pWorkInfo->pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	SELF_F_ARRY* fArry = &pGData->SelfFArry;
	DWORD64 Ret = 0;
	SOCKET s = pWorkInfo->s;
	_FUNCTION_IMP(RunApcRunCode, Ret, pGData, pWorkInfo->s, pWorkInfo->Flags);
}
void _WORKER_THREAD_ROUTINE7(PVOID Parameter) {
	WORKER_THREAD_INFO* pWorkInfo = (WORKER_THREAD_INFO*)Parameter;
	Global_Data* pGData = (Global_Data*)pWorkInfo->pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	SELF_F_ARRY* fArry = &pGData->SelfFArry;
	DWORD64 Ret = 0;
	SOCKET s = pWorkInfo->s;
	_FUNCTION_IMP(RunApcRunCode, Ret, pGData, pWorkInfo->s, pWorkInfo->Flags);
}
void _WORKER_THREAD_ROUTINE8(PVOID Parameter) {
	WORKER_THREAD_INFO* pWorkInfo = (WORKER_THREAD_INFO*)Parameter;
	Global_Data* pGData = (Global_Data*)pWorkInfo->pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	SELF_F_ARRY* fArry = &pGData->SelfFArry;
	DWORD64 Ret = 0;
	SOCKET s = pWorkInfo->s;
	_FUNCTION_IMP(RunApcRunCode, Ret, pGData, pWorkInfo->s, pWorkInfo->Flags);
}
void _WORKER_THREAD_ROUTINE9(PVOID Parameter) {
	WORKER_THREAD_INFO* pWorkInfo = (WORKER_THREAD_INFO*)Parameter;
	Global_Data* pGData = (Global_Data*)pWorkInfo->pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	SELF_F_ARRY* fArry = &pGData->SelfFArry;
	DWORD64 Ret = 0;
	SOCKET s = pWorkInfo->s;
	_FUNCTION_IMP(RunApcRunCode, Ret, pGData, pWorkInfo->s, pWorkInfo->Flags);
}
void _WORKER_THREAD_ROUTINE10(PVOID Parameter) {
	WORKER_THREAD_INFO* pWorkInfo = (WORKER_THREAD_INFO*)Parameter;
	Global_Data* pGData = (Global_Data*)pWorkInfo->pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	SELF_F_ARRY* fArry = &pGData->SelfFArry;
	DWORD64 Ret = 0;
	SOCKET s = pWorkInfo->s;
	_FUNCTION_IMP(RunApcRunCode, Ret, pGData, pWorkInfo->s, pWorkInfo->Flags);
}
void _WORKER_THREAD_ROUTINE11(PVOID Parameter) {
	WORKER_THREAD_INFO* pWorkInfo = (WORKER_THREAD_INFO*)Parameter;
	Global_Data* pGData = (Global_Data*)pWorkInfo->pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	SELF_F_ARRY* fArry = &pGData->SelfFArry;
	DWORD64 Ret = 0;
	SOCKET s = pWorkInfo->s;
	_FUNCTION_IMP(RunApcRunCode, Ret, pGData, pWorkInfo->s, pWorkInfo->Flags);
}
void _WORKER_THREAD_ROUTINE12(PVOID Parameter) {
	WORKER_THREAD_INFO* pWorkInfo = (WORKER_THREAD_INFO*)Parameter;
	Global_Data* pGData = (Global_Data*)pWorkInfo->pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	SELF_F_ARRY* fArry = &pGData->SelfFArry;
	DWORD64 Ret = 0;
	SOCKET s = pWorkInfo->s;
	_FUNCTION_IMP(RunApcRunCode, Ret, pGData, pWorkInfo->s, pWorkInfo->Flags);
}
void _WORKER_THREAD_ROUTINE13(PVOID Parameter) {
	WORKER_THREAD_INFO* pWorkInfo = (WORKER_THREAD_INFO*)Parameter;
	Global_Data* pGData = (Global_Data*)pWorkInfo->pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	SELF_F_ARRY* fArry = &pGData->SelfFArry;
	DWORD64 Ret = 0;
	SOCKET s = pWorkInfo->s;
	_FUNCTION_IMP(RunApcRunCode, Ret, pGData, pWorkInfo->s, pWorkInfo->Flags);
}
void _WORKER_THREAD_ROUTINE14(PVOID Parameter) {
	WORKER_THREAD_INFO* pWorkInfo = (WORKER_THREAD_INFO*)Parameter;
	Global_Data* pGData = (Global_Data*)pWorkInfo->pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	SELF_F_ARRY* fArry = &pGData->SelfFArry;
	DWORD64 Ret = 0;
	SOCKET s = pWorkInfo->s;
	_FUNCTION_IMP(RunApcRunCode, Ret, pGData, pWorkInfo->s, pWorkInfo->Flags);
}
void _WORKER_THREAD_ROUTINE15(PVOID Parameter) {
	WORKER_THREAD_INFO* pWorkInfo = (WORKER_THREAD_INFO*)Parameter;
	Global_Data* pGData = (Global_Data*)pWorkInfo->pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	SELF_F_ARRY* fArry = &pGData->SelfFArry;
	DWORD64 Ret = 0;
	SOCKET s = pWorkInfo->s;
	_FUNCTION_IMP(RunApcRunCode, Ret, pGData, pWorkInfo->s, pWorkInfo->Flags);
}
void _WORKER_THREAD_ROUTINE16(PVOID Parameter) {
	WORKER_THREAD_INFO* pWorkInfo = (WORKER_THREAD_INFO*)Parameter;
	Global_Data* pGData = (Global_Data*)pWorkInfo->pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	SELF_F_ARRY* fArry = &pGData->SelfFArry;
	DWORD64 Ret = 0;
	SOCKET s = pWorkInfo->s;
	_FUNCTION_IMP(RunApcRunCode, Ret, pGData, pWorkInfo->s, pWorkInfo->Flags);
}
void _WORKER_THREAD_ROUTINE17(PVOID Parameter) {
	WORKER_THREAD_INFO* pWorkInfo = (WORKER_THREAD_INFO*)Parameter;
	Global_Data* pGData = (Global_Data*)pWorkInfo->pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	SELF_F_ARRY* fArry = &pGData->SelfFArry;
	DWORD64 Ret = 0;
	SOCKET s = pWorkInfo->s;
	_FUNCTION_IMP(RunApcRunCode, Ret, pGData, pWorkInfo->s, pWorkInfo->Flags);
}
void _WORKER_THREAD_ROUTINE18(PVOID Parameter) {
	WORKER_THREAD_INFO* pWorkInfo = (WORKER_THREAD_INFO*)Parameter;
	Global_Data* pGData = (Global_Data*)pWorkInfo->pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	SELF_F_ARRY* fArry = &pGData->SelfFArry;
	DWORD64 Ret = 0;
	SOCKET s = pWorkInfo->s;
	_FUNCTION_IMP(RunApcRunCode, Ret, pGData, pWorkInfo->s, pWorkInfo->Flags);
}
void _WORKER_THREAD_ROUTINE19(PVOID Parameter) {
	WORKER_THREAD_INFO* pWorkInfo = (WORKER_THREAD_INFO*)Parameter;
	Global_Data* pGData = (Global_Data*)pWorkInfo->pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	SELF_F_ARRY* fArry = &pGData->SelfFArry;
	DWORD64 Ret = 0;
	SOCKET s = pWorkInfo->s;
	_FUNCTION_IMP(RunApcRunCode, Ret, pGData, pWorkInfo->s, pWorkInfo->Flags);
}






//---------------------------------------------------------------------------------------
void _Work_Memory0(PVOID Parameter) {
	WORKER_T_INFO* pWorkInfo = (WORKER_T_INFO*)Parameter;
	Global_Data* pGData = (Global_Data*)pWorkInfo->pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	SELF_F_ARRY* fArry = &pGData->SelfFArry;
	DWORD64 Ret = 0; SOCKET s = pWorkInfo->s;
	_FUNCTION_IMP(IOSocketBuffer, Ret, pGData, pWorkInfo->s, pWorkInfo->IOMajor, pWorkInfo->pInfo, pWorkInfo->rBuffer);
}
void _Work_Memory1(PVOID Parameter) {
	WORKER_T_INFO* pWorkInfo = (WORKER_T_INFO*)Parameter;
	Global_Data* pGData = (Global_Data*)pWorkInfo->pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	SELF_F_ARRY* fArry = &pGData->SelfFArry;
	DWORD64 Ret = 0; SOCKET s = pWorkInfo->s;
	_FUNCTION_IMP(IOSocketBuffer, Ret, pGData, pWorkInfo->s, pWorkInfo->IOMajor, pWorkInfo->pInfo, pWorkInfo->rBuffer);
}
void _Work_Memory2(PVOID Parameter) {
	WORKER_T_INFO* pWorkInfo = (WORKER_T_INFO*)Parameter;
	Global_Data* pGData = (Global_Data*)pWorkInfo->pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	SELF_F_ARRY* fArry = &pGData->SelfFArry;
	DWORD64 Ret = 0; SOCKET s = pWorkInfo->s;
	_FUNCTION_IMP(IOSocketBuffer, Ret, pGData, pWorkInfo->s, pWorkInfo->IOMajor, pWorkInfo->pInfo, pWorkInfo->rBuffer);
}
void _Work_Memory3(PVOID Parameter) {
	WORKER_T_INFO* pWorkInfo = (WORKER_T_INFO*)Parameter;
	Global_Data* pGData = (Global_Data*)pWorkInfo->pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	SELF_F_ARRY* fArry = &pGData->SelfFArry;
	DWORD64 Ret = 0; SOCKET s = pWorkInfo->s;
	_FUNCTION_IMP(IOSocketBuffer, Ret, pGData, pWorkInfo->s, pWorkInfo->IOMajor, pWorkInfo->pInfo, pWorkInfo->rBuffer);
}
void _Work_Memory4(PVOID Parameter) {
	WORKER_T_INFO* pWorkInfo = (WORKER_T_INFO*)Parameter;
	Global_Data* pGData = (Global_Data*)pWorkInfo->pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	SELF_F_ARRY* fArry = &pGData->SelfFArry;
	DWORD64 Ret = 0; SOCKET s = pWorkInfo->s;
	_FUNCTION_IMP(IOSocketBuffer, Ret, pGData, pWorkInfo->s, pWorkInfo->IOMajor, pWorkInfo->pInfo, pWorkInfo->rBuffer);
}
void _Work_Memory5(PVOID Parameter) {
	WORKER_T_INFO* pWorkInfo = (WORKER_T_INFO*)Parameter;
	Global_Data* pGData = (Global_Data*)pWorkInfo->pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	SELF_F_ARRY* fArry = &pGData->SelfFArry;
	DWORD64 Ret = 0; SOCKET s = pWorkInfo->s;
	_FUNCTION_IMP(IOSocketBuffer, Ret, pGData, pWorkInfo->s, pWorkInfo->IOMajor, pWorkInfo->pInfo, pWorkInfo->rBuffer);
}
void _Work_Memory6(PVOID Parameter) {
	WORKER_T_INFO* pWorkInfo = (WORKER_T_INFO*)Parameter;
	Global_Data* pGData = (Global_Data*)pWorkInfo->pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	SELF_F_ARRY* fArry = &pGData->SelfFArry;
	DWORD64 Ret = 0; SOCKET s = pWorkInfo->s;
	_FUNCTION_IMP(IOSocketBuffer, Ret, pGData, pWorkInfo->s, pWorkInfo->IOMajor, pWorkInfo->pInfo, pWorkInfo->rBuffer);
}
void _Work_Memory7(PVOID Parameter) {
	WORKER_T_INFO* pWorkInfo = (WORKER_T_INFO*)Parameter;
	Global_Data* pGData = (Global_Data*)pWorkInfo->pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	SELF_F_ARRY* fArry = &pGData->SelfFArry;
	DWORD64 Ret = 0; SOCKET s = pWorkInfo->s;
	_FUNCTION_IMP(IOSocketBuffer, Ret, pGData, pWorkInfo->s, pWorkInfo->IOMajor, pWorkInfo->pInfo, pWorkInfo->rBuffer);
}
void _Work_Memory8(PVOID Parameter) {
	WORKER_T_INFO* pWorkInfo = (WORKER_T_INFO*)Parameter;
	Global_Data* pGData = (Global_Data*)pWorkInfo->pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	SELF_F_ARRY* fArry = &pGData->SelfFArry;
	DWORD64 Ret = 0; SOCKET s = pWorkInfo->s;
	_FUNCTION_IMP(IOSocketBuffer, Ret, pGData, pWorkInfo->s, pWorkInfo->IOMajor, pWorkInfo->pInfo, pWorkInfo->rBuffer);
}
void _Work_Memory9(PVOID Parameter) {
	WORKER_T_INFO* pWorkInfo = (WORKER_T_INFO*)Parameter;
	Global_Data* pGData = (Global_Data*)pWorkInfo->pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	SELF_F_ARRY* fArry = &pGData->SelfFArry;
	DWORD64 Ret = 0; SOCKET s = pWorkInfo->s;
	_FUNCTION_IMP(IOSocketBuffer, Ret, pGData, pWorkInfo->s, pWorkInfo->IOMajor, pWorkInfo->pInfo, pWorkInfo->rBuffer);
}
void _Work_Memory10(PVOID Parameter) {
	WORKER_T_INFO* pWorkInfo = (WORKER_T_INFO*)Parameter;
	Global_Data* pGData = (Global_Data*)pWorkInfo->pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	SELF_F_ARRY* fArry = &pGData->SelfFArry;
	DWORD64 Ret = 0; SOCKET s = pWorkInfo->s;
	_FUNCTION_IMP(IOSocketBuffer, Ret, pGData, pWorkInfo->s, pWorkInfo->IOMajor, pWorkInfo->pInfo, pWorkInfo->rBuffer);
}
void _Work_Memory11(PVOID Parameter) {
	WORKER_T_INFO* pWorkInfo = (WORKER_T_INFO*)Parameter;
	Global_Data* pGData = (Global_Data*)pWorkInfo->pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	SELF_F_ARRY* fArry = &pGData->SelfFArry;
	DWORD64 Ret = 0; SOCKET s = pWorkInfo->s;
	_FUNCTION_IMP(IOSocketBuffer, Ret, pGData, pWorkInfo->s, pWorkInfo->IOMajor, pWorkInfo->pInfo, pWorkInfo->rBuffer);
}
void _Work_Memory12(PVOID Parameter) {
	WORKER_T_INFO* pWorkInfo = (WORKER_T_INFO*)Parameter;
	Global_Data* pGData = (Global_Data*)pWorkInfo->pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	SELF_F_ARRY* fArry = &pGData->SelfFArry;
	DWORD64 Ret = 0; SOCKET s = pWorkInfo->s;
	_FUNCTION_IMP(IOSocketBuffer, Ret, pGData, pWorkInfo->s, pWorkInfo->IOMajor, pWorkInfo->pInfo, pWorkInfo->rBuffer);
}
void _Work_Memory13(PVOID Parameter) {
	WORKER_T_INFO* pWorkInfo = (WORKER_T_INFO*)Parameter;
	Global_Data* pGData = (Global_Data*)pWorkInfo->pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	SELF_F_ARRY* fArry = &pGData->SelfFArry;
	DWORD64 Ret = 0; SOCKET s = pWorkInfo->s;
	_FUNCTION_IMP(IOSocketBuffer, Ret, pGData, pWorkInfo->s, pWorkInfo->IOMajor, pWorkInfo->pInfo, pWorkInfo->rBuffer);
}
void _Work_Memory14(PVOID Parameter) {
	WORKER_T_INFO* pWorkInfo = (WORKER_T_INFO*)Parameter;
	Global_Data* pGData = (Global_Data*)pWorkInfo->pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	SELF_F_ARRY* fArry = &pGData->SelfFArry;
	DWORD64 Ret = 0; SOCKET s = pWorkInfo->s;
	_FUNCTION_IMP(IOSocketBuffer, Ret, pGData, pWorkInfo->s, pWorkInfo->IOMajor, pWorkInfo->pInfo, pWorkInfo->rBuffer);
}
void _Work_Memory15(PVOID Parameter) {
	WORKER_T_INFO* pWorkInfo = (WORKER_T_INFO*)Parameter;
	Global_Data* pGData = (Global_Data*)pWorkInfo->pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	SELF_F_ARRY* fArry = &pGData->SelfFArry;
	DWORD64 Ret = 0; SOCKET s = pWorkInfo->s;
	_FUNCTION_IMP(IOSocketBuffer, Ret, pGData, pWorkInfo->s, pWorkInfo->IOMajor, pWorkInfo->pInfo, pWorkInfo->rBuffer);
}
void _Work_Memory16(PVOID Parameter) {
	WORKER_T_INFO* pWorkInfo = (WORKER_T_INFO*)Parameter;
	Global_Data* pGData = (Global_Data*)pWorkInfo->pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	SELF_F_ARRY* fArry = &pGData->SelfFArry;
	DWORD64 Ret = 0; SOCKET s = pWorkInfo->s;
	_FUNCTION_IMP(IOSocketBuffer, Ret, pGData, pWorkInfo->s, pWorkInfo->IOMajor, pWorkInfo->pInfo, pWorkInfo->rBuffer);
}
void _Work_Memory17(PVOID Parameter) {
	WORKER_T_INFO* pWorkInfo = (WORKER_T_INFO*)Parameter;
	Global_Data* pGData = (Global_Data*)pWorkInfo->pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	SELF_F_ARRY* fArry = &pGData->SelfFArry;
	DWORD64 Ret = 0; SOCKET s = pWorkInfo->s;
	_FUNCTION_IMP(IOSocketBuffer, Ret, pGData, pWorkInfo->s, pWorkInfo->IOMajor, pWorkInfo->pInfo, pWorkInfo->rBuffer);
}
void _Work_Memory18(PVOID Parameter) {
	WORKER_T_INFO* pWorkInfo = (WORKER_T_INFO*)Parameter;
	Global_Data* pGData = (Global_Data*)pWorkInfo->pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	SELF_F_ARRY* fArry = &pGData->SelfFArry;
	DWORD64 Ret = 0; SOCKET s = pWorkInfo->s;
	_FUNCTION_IMP(IOSocketBuffer, Ret, pGData, pWorkInfo->s, pWorkInfo->IOMajor, pWorkInfo->pInfo, pWorkInfo->rBuffer);
}
void _Work_Memory19(PVOID Parameter) {
	WORKER_T_INFO* pWorkInfo = (WORKER_T_INFO*)Parameter;
	Global_Data* pGData = (Global_Data*)pWorkInfo->pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	SELF_F_ARRY* fArry = &pGData->SelfFArry;
	DWORD64 Ret = 0; SOCKET s = pWorkInfo->s;
	_FUNCTION_IMP(IOSocketBuffer, Ret, pGData, pWorkInfo->s, pWorkInfo->IOMajor, pWorkInfo->pInfo, pWorkInfo->rBuffer);
}



//----------------------------------------------------------------------------------------------------------


void RunApcNo0(PVOID NormalContext,PVOID SystemArgument1,PVOID SystemArgument2) {

	// 不能使用  FUNCTION_IMP
	__try {
		RUN_APC_ARG* Arg = (RUN_APC_ARG*)NormalContext;
		Global_Data* pGData = (Global_Data*)Arg->_pGData;
		NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;

		SELF_F_ARRY* fArry = &((Global_Data*)pGData)->SelfFArry;
		SELF_STRING_ARRY* AArry = &((Global_Data*)pGData)->SelfAArry;
		PKSOCKET pSocket = &pGData->wsk.bWsk.kSocket[Arg->s]; SOCKET s =Arg->s;
		SOCKET_INFO* pSocketInfo = (SOCKET_INFO*)&pGData->wsk._SocketArry[Arg->s];

		int Flags = 0;
		if (Arg->RunCode > 0x80000000)
			Flags = 1;
		IOINFO* pIO_INFO = Arg->rBuffer;

		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, Arg->_Run_Routine, KeGetCurrentIrql(), Flags);
		if (Flags) {
			FREE_FUNCTION_ENTRY(RunApcSocketBuffer, Arg->_Run_Routine);
			return;
		}
		FREE_FUNCTION_ENTRY(RunApc, Arg->_Run_Routine);
		//LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, Arg->_Run_Routine, KeGetCurrentIrql(), Flags);
		//FREE_FUNCTION_ENTRY(RunApc, Arg->_Run_Routine);



	

		NTSTATUS status = 0;
_sendEncrypt usendEncrypt = 0; MEMORY_FLAGS MFlags;

		_FUNCTION_ENTRY(sendEncrypt, MFlags, _sendEncrypt);
		status = usendEncrypt(pGData, Arg->s, 0x21212121, Arg->rBuffer, Arg->rLen);
		FREE_FUNCTION_ENTRY(sendEncrypt, MFlags);

		//FREE_FUNCTION_ENTRY(sendEncrypt, MFlags);

		if (!NT_SUCCESS(status))
		{
			if (pSocket->AsyncContext.Irp != 0) {
				fNtos->IoFreeIrp(pSocket->AsyncContext.Irp);
				pSocket->AsyncContext.Irp = 0;
			}
			if (pSocketInfo->kSendBuffer.Mdl != 0) {
				fNtos->MmUnlockPages(pSocketInfo->kSendBuffer.Mdl);
				fNtos->IoFreeMdl(pSocketInfo->kSendBuffer.Mdl);
				pSocketInfo->kSendBuffer.Mdl = 0;
				fNtos->MmFreeNonCachedMemory(pSocketInfo->pSendBuffer, SEND_SIZE);
				pSocketInfo->pSendBuffer = 0;
			}
			if (pSocketInfo->kRecvBuffer.Mdl != 0)
			{
				fNtos->MmUnlockPages(pSocketInfo->kRecvBuffer.Mdl);
				fNtos->IoFreeMdl(pSocketInfo->kRecvBuffer.Mdl);
				pSocketInfo->kRecvBuffer.Mdl = 0;
				fNtos->MmFreeNonCachedMemory(pSocketInfo->pRecvBuffer, RECV_SIZE);
				pSocketInfo->pRecvBuffer = 0;
			}
			ChangeEntryList(pGData, pGData->wsk.s_Sever, &pSocketInfo->List.Link, &pSocketInfo->List.Link, 0);//RemoveEntryList(&pSocketInfo->List.Link);
		}
	}
	__except (1) {


	}


}
void RunApcNo1(PVOID NormalContext, PVOID SystemArgument1, PVOID SystemArgument2) {

	// 不能使用  FUNCTION_IMP
	__try {
		RUN_APC_ARG* Arg = (RUN_APC_ARG*)NormalContext;
		Global_Data* pGData = (Global_Data*)Arg->_pGData;
		NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;

		SELF_F_ARRY* fArry = &((Global_Data*)pGData)->SelfFArry;
		SELF_STRING_ARRY* AArry = &((Global_Data*)pGData)->SelfAArry;
		PKSOCKET pSocket = &pGData->wsk.bWsk.kSocket[Arg->s]; SOCKET s =Arg->s;
		SOCKET_INFO* pSocketInfo = (SOCKET_INFO*)&pGData->wsk._SocketArry[Arg->s];

		int Flags = 0;
		if (Arg->RunCode > 0x80000000)
			Flags = 1;
		IOINFO* pIO_INFO = Arg->rBuffer;
		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, Arg->_Run_Routine, KeGetCurrentIrql(), Flags);
		//FREE_FUNCTION_ENTRY(Arg->_Run_Routine, 0);
		if (Flags) {
			FREE_FUNCTION_ENTRY(RunApcSocketBuffer, Arg->_Run_Routine);
			return;
		}
		FREE_FUNCTION_ENTRY(RunApc, Arg->_Run_Routine);

		NTSTATUS status = 0;
        _sendEncrypt usendEncrypt = 0; MEMORY_FLAGS MFlags;
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
				fNtos->MmUnlockPages(pSocketInfo->kSendBuffer.Mdl);
				fNtos->IoFreeMdl(pSocketInfo->kSendBuffer.Mdl);
				pSocketInfo->kSendBuffer.Mdl = 0;
				fNtos->MmFreeNonCachedMemory(pSocketInfo->pSendBuffer, SEND_SIZE);
				pSocketInfo->pSendBuffer = 0;
			}
			if (pSocketInfo->kRecvBuffer.Mdl != 0)
			{
				fNtos->MmUnlockPages(pSocketInfo->kRecvBuffer.Mdl);
				fNtos->IoFreeMdl(pSocketInfo->kRecvBuffer.Mdl);
				pSocketInfo->kRecvBuffer.Mdl = 0;
				fNtos->MmFreeNonCachedMemory(pSocketInfo->pRecvBuffer, RECV_SIZE);
				pSocketInfo->pRecvBuffer = 0;
			}
			ChangeEntryList(pGData, pGData->wsk.s_Sever, &pSocketInfo->List.Link, &pSocketInfo->List.Link, 0);//RemoveEntryList(&pSocketInfo->List.Link);
		}
	}
	__except (1) {


	}


}
void RunApcNo2(PVOID NormalContext, PVOID SystemArgument1, PVOID SystemArgument2) {

	// 不能使用  FUNCTION_IMP
	__try {
		RUN_APC_ARG* Arg = (RUN_APC_ARG*)NormalContext;
		Global_Data* pGData = (Global_Data*)Arg->_pGData;
		NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;

		SELF_F_ARRY* fArry = &((Global_Data*)pGData)->SelfFArry;
		SELF_STRING_ARRY* AArry = &((Global_Data*)pGData)->SelfAArry;
		PKSOCKET pSocket = &pGData->wsk.bWsk.kSocket[Arg->s]; SOCKET s =Arg->s;
		SOCKET_INFO* pSocketInfo = (SOCKET_INFO*)&pGData->wsk._SocketArry[Arg->s];

		int Flags = 0;
		if (Arg->RunCode > 0x80000000)
			Flags = 1;
		IOINFO* pIO_INFO = Arg->rBuffer;
		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, Arg->_Run_Routine, KeGetCurrentIrql(), Flags);
		if (Flags) {
			FREE_FUNCTION_ENTRY(RunApcSocketBuffer, Arg->_Run_Routine);
			return;
		}
		FREE_FUNCTION_ENTRY(RunApc, Arg->_Run_Routine);
		//FREE_FUNCTION_ENTRY(RunApc, Arg->_Run_Routine);

		NTSTATUS status = 0;
_sendEncrypt usendEncrypt = 0; MEMORY_FLAGS MFlags;
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
				fNtos->MmUnlockPages(pSocketInfo->kSendBuffer.Mdl);
				fNtos->IoFreeMdl(pSocketInfo->kSendBuffer.Mdl);
				pSocketInfo->kSendBuffer.Mdl = 0;
				fNtos->MmFreeNonCachedMemory(pSocketInfo->pSendBuffer, SEND_SIZE);
				pSocketInfo->pSendBuffer = 0;
			}
			if (pSocketInfo->kRecvBuffer.Mdl != 0)
			{
				fNtos->MmUnlockPages(pSocketInfo->kRecvBuffer.Mdl);
				fNtos->IoFreeMdl(pSocketInfo->kRecvBuffer.Mdl);
				pSocketInfo->kRecvBuffer.Mdl = 0;
				fNtos->MmFreeNonCachedMemory(pSocketInfo->pRecvBuffer, RECV_SIZE);
				pSocketInfo->pRecvBuffer = 0;
			}
			ChangeEntryList(pGData, pGData->wsk.s_Sever, &pSocketInfo->List.Link, &pSocketInfo->List.Link, 0);//RemoveEntryList(&pSocketInfo->List.Link);
		}
	}
	__except (1) {


	}


}
void RunApcNo3(PVOID NormalContext, PVOID SystemArgument1, PVOID SystemArgument2) {

	// 不能使用  FUNCTION_IMP
	__try {
		RUN_APC_ARG* Arg = (RUN_APC_ARG*)NormalContext;
		Global_Data* pGData = (Global_Data*)Arg->_pGData;
		NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;

		SELF_F_ARRY* fArry = &((Global_Data*)pGData)->SelfFArry;
		SELF_STRING_ARRY* AArry = &((Global_Data*)pGData)->SelfAArry;
		PKSOCKET pSocket = &pGData->wsk.bWsk.kSocket[Arg->s]; SOCKET s =Arg->s;
		SOCKET_INFO* pSocketInfo = (SOCKET_INFO*)&pGData->wsk._SocketArry[Arg->s];
		int Flags = 0;
		if (Arg->RunCode > 0x80000000)
			Flags = 1;
		IOINFO* pIO_INFO = Arg->rBuffer;
		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, Arg->_Run_Routine, KeGetCurrentIrql(), Flags);
		if (Flags) {
			FREE_FUNCTION_ENTRY(RunApcSocketBuffer, Arg->_Run_Routine);
			return;
		}
		FREE_FUNCTION_ENTRY(RunApc, Arg->_Run_Routine);
		//FREE_FUNCTION_ENTRY(RunApc, Arg->_Run_Routine);

		NTSTATUS status = 0;
_sendEncrypt usendEncrypt = 0; MEMORY_FLAGS MFlags;
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
				fNtos->MmUnlockPages(pSocketInfo->kSendBuffer.Mdl);
				fNtos->IoFreeMdl(pSocketInfo->kSendBuffer.Mdl);
				pSocketInfo->kSendBuffer.Mdl = 0;
				fNtos->MmFreeNonCachedMemory(pSocketInfo->pSendBuffer, SEND_SIZE);
				pSocketInfo->pSendBuffer = 0;
			}
			if (pSocketInfo->kRecvBuffer.Mdl != 0)
			{
				fNtos->MmUnlockPages(pSocketInfo->kRecvBuffer.Mdl);
				fNtos->IoFreeMdl(pSocketInfo->kRecvBuffer.Mdl);
				pSocketInfo->kRecvBuffer.Mdl = 0;
				fNtos->MmFreeNonCachedMemory(pSocketInfo->pRecvBuffer, RECV_SIZE);
				pSocketInfo->pRecvBuffer = 0;
			}
			ChangeEntryList(pGData, pGData->wsk.s_Sever, &pSocketInfo->List.Link, &pSocketInfo->List.Link, 0);//RemoveEntryList(&pSocketInfo->List.Link);
		}
	}
	__except (1) {


	}


}
void RunApcNo4(PVOID NormalContext, PVOID SystemArgument1, PVOID SystemArgument2) {

	// 不能使用  FUNCTION_IMP
	__try {
		RUN_APC_ARG* Arg = (RUN_APC_ARG*)NormalContext;
		Global_Data* pGData = (Global_Data*)Arg->_pGData;
		NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;

		SELF_F_ARRY* fArry = &((Global_Data*)pGData)->SelfFArry;
		SELF_STRING_ARRY* AArry = &((Global_Data*)pGData)->SelfAArry;
		PKSOCKET pSocket = &pGData->wsk.bWsk.kSocket[Arg->s]; SOCKET s =Arg->s;
		SOCKET_INFO* pSocketInfo = (SOCKET_INFO*)&pGData->wsk._SocketArry[Arg->s];
		int Flags = 0;
		if (Arg->RunCode > 0x80000000)
			Flags = 1;
		IOINFO* pIO_INFO = Arg->rBuffer;
		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, Arg->_Run_Routine, KeGetCurrentIrql(), Flags);
		if (Flags) {
			FREE_FUNCTION_ENTRY(RunApcSocketBuffer, Arg->_Run_Routine);
			return;
		}
		FREE_FUNCTION_ENTRY(RunApc, Arg->_Run_Routine);
		//FREE_FUNCTION_ENTRY(RunApc, Arg->_Run_Routine);

		NTSTATUS status = 0;
_sendEncrypt usendEncrypt = 0; MEMORY_FLAGS MFlags;
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
				fNtos->MmUnlockPages(pSocketInfo->kSendBuffer.Mdl);
				fNtos->IoFreeMdl(pSocketInfo->kSendBuffer.Mdl);
				pSocketInfo->kSendBuffer.Mdl = 0;
				fNtos->MmFreeNonCachedMemory(pSocketInfo->pSendBuffer, SEND_SIZE);
				pSocketInfo->pSendBuffer = 0;
			}
			if (pSocketInfo->kRecvBuffer.Mdl != 0)
			{
				fNtos->MmUnlockPages(pSocketInfo->kRecvBuffer.Mdl);
				fNtos->IoFreeMdl(pSocketInfo->kRecvBuffer.Mdl);
				pSocketInfo->kRecvBuffer.Mdl = 0;
				fNtos->MmFreeNonCachedMemory(pSocketInfo->pRecvBuffer, RECV_SIZE);
				pSocketInfo->pRecvBuffer = 0;
			}
			ChangeEntryList(pGData, pGData->wsk.s_Sever, &pSocketInfo->List.Link, &pSocketInfo->List.Link, 0);//RemoveEntryList(&pSocketInfo->List.Link);
		}
	}
	__except (1) {


	}


}
void RunApcNo5(PVOID NormalContext, PVOID SystemArgument1, PVOID SystemArgument2) {

	// 不能使用  FUNCTION_IMP
	__try {
		RUN_APC_ARG* Arg = (RUN_APC_ARG*)NormalContext;
		Global_Data* pGData = (Global_Data*)Arg->_pGData;
		NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;

		SELF_F_ARRY* fArry = &((Global_Data*)pGData)->SelfFArry;
		SELF_STRING_ARRY* AArry = &((Global_Data*)pGData)->SelfAArry;
		PKSOCKET pSocket = &pGData->wsk.bWsk.kSocket[Arg->s]; SOCKET s =Arg->s;
		SOCKET_INFO* pSocketInfo = (SOCKET_INFO*)&pGData->wsk._SocketArry[Arg->s];
		int Flags = 0;
		if (Arg->RunCode > 0x80000000)
			Flags = 1;
		IOINFO* pIO_INFO = Arg->rBuffer;
		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, Arg->_Run_Routine, KeGetCurrentIrql(), Flags);
		if (Flags) {
			FREE_FUNCTION_ENTRY(RunApcSocketBuffer, Arg->_Run_Routine);
			return;
		}
		FREE_FUNCTION_ENTRY(RunApc, Arg->_Run_Routine);
		//FREE_FUNCTION_ENTRY(RunApc, Arg->_Run_Routine);

		NTSTATUS status = 0;
        _sendEncrypt usendEncrypt = 0; MEMORY_FLAGS MFlags;
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
				fNtos->MmUnlockPages(pSocketInfo->kSendBuffer.Mdl);
				fNtos->IoFreeMdl(pSocketInfo->kSendBuffer.Mdl);
				pSocketInfo->kSendBuffer.Mdl = 0;
				fNtos->MmFreeNonCachedMemory(pSocketInfo->pSendBuffer, SEND_SIZE);
				pSocketInfo->pSendBuffer = 0;
			}
			if (pSocketInfo->kRecvBuffer.Mdl != 0)
			{
				fNtos->MmUnlockPages(pSocketInfo->kRecvBuffer.Mdl);
				fNtos->IoFreeMdl(pSocketInfo->kRecvBuffer.Mdl);
				pSocketInfo->kRecvBuffer.Mdl = 0;
				fNtos->MmFreeNonCachedMemory(pSocketInfo->pRecvBuffer, RECV_SIZE);
				pSocketInfo->pRecvBuffer = 0;
			}
			ChangeEntryList(pGData, pGData->wsk.s_Sever, &pSocketInfo->List.Link, &pSocketInfo->List.Link, 0);//RemoveEntryList(&pSocketInfo->List.Link);
		}
	}
	__except (1) {


	}


}
void RunApcNo6(PVOID NormalContext, PVOID SystemArgument1, PVOID SystemArgument2) {

	// 不能使用  FUNCTION_IMP
	__try {
		RUN_APC_ARG* Arg = (RUN_APC_ARG*)NormalContext;
		Global_Data* pGData = (Global_Data*)Arg->_pGData;
		NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;

		SELF_F_ARRY* fArry = &((Global_Data*)pGData)->SelfFArry;
		SELF_STRING_ARRY* AArry = &((Global_Data*)pGData)->SelfAArry;
		PKSOCKET pSocket = &pGData->wsk.bWsk.kSocket[Arg->s]; SOCKET s =Arg->s;
		SOCKET_INFO* pSocketInfo = (SOCKET_INFO*)&pGData->wsk._SocketArry[Arg->s];
		int Flags = 0;
		if (Arg->RunCode > 0x80000000)
			Flags = 1;
		IOINFO* pIO_INFO = Arg->rBuffer;
		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, Arg->_Run_Routine, KeGetCurrentIrql(), Flags);
		if (Flags) {
			FREE_FUNCTION_ENTRY(RunApcSocketBuffer, Arg->_Run_Routine);
			return;
		}
		FREE_FUNCTION_ENTRY(RunApc, Arg->_Run_Routine);
		//FREE_FUNCTION_ENTRY(RunApc, Arg->_Run_Routine);

		NTSTATUS status = 0;
_sendEncrypt usendEncrypt = 0; MEMORY_FLAGS MFlags;
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
				fNtos->MmUnlockPages(pSocketInfo->kSendBuffer.Mdl);
				fNtos->IoFreeMdl(pSocketInfo->kSendBuffer.Mdl);
				pSocketInfo->kSendBuffer.Mdl = 0;
				fNtos->MmFreeNonCachedMemory(pSocketInfo->pSendBuffer, SEND_SIZE);
				pSocketInfo->pSendBuffer = 0;
			}
			if (pSocketInfo->kRecvBuffer.Mdl != 0)
			{
				fNtos->MmUnlockPages(pSocketInfo->kRecvBuffer.Mdl);
				fNtos->IoFreeMdl(pSocketInfo->kRecvBuffer.Mdl);
				pSocketInfo->kRecvBuffer.Mdl = 0;
				fNtos->MmFreeNonCachedMemory(pSocketInfo->pRecvBuffer, RECV_SIZE);
				pSocketInfo->pRecvBuffer = 0;
			}
			ChangeEntryList(pGData, pGData->wsk.s_Sever, &pSocketInfo->List.Link, &pSocketInfo->List.Link, 0);//RemoveEntryList(&pSocketInfo->List.Link);
		}
	}
	__except (1) {


	}


}
void RunApcNo7(PVOID NormalContext, PVOID SystemArgument1, PVOID SystemArgument2) {

	// 不能使用  FUNCTION_IMP
	__try {
		RUN_APC_ARG* Arg = (RUN_APC_ARG*)NormalContext;
		Global_Data* pGData = (Global_Data*)Arg->_pGData;
		NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;

		SELF_F_ARRY* fArry = &((Global_Data*)pGData)->SelfFArry;
		SELF_STRING_ARRY* AArry = &((Global_Data*)pGData)->SelfAArry;
		PKSOCKET pSocket = &pGData->wsk.bWsk.kSocket[Arg->s]; SOCKET s =Arg->s;
		SOCKET_INFO* pSocketInfo = (SOCKET_INFO*)&pGData->wsk._SocketArry[Arg->s];
		int Flags = 0;
		if (Arg->RunCode > 0x80000000)
			Flags = 1;
		IOINFO* pIO_INFO = Arg->rBuffer;
		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, Arg->_Run_Routine, KeGetCurrentIrql(), Flags);
		if (Flags) {
			FREE_FUNCTION_ENTRY(RunApcSocketBuffer, Arg->_Run_Routine);
			return;
		}
		FREE_FUNCTION_ENTRY(RunApc, Arg->_Run_Routine);
		//FREE_FUNCTION_ENTRY(RunApc, Arg->_Run_Routine);

		NTSTATUS status = 0;
_sendEncrypt usendEncrypt = 0; MEMORY_FLAGS MFlags;
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
				fNtos->MmUnlockPages(pSocketInfo->kSendBuffer.Mdl);
				fNtos->IoFreeMdl(pSocketInfo->kSendBuffer.Mdl);
				pSocketInfo->kSendBuffer.Mdl = 0;
				fNtos->MmFreeNonCachedMemory(pSocketInfo->pSendBuffer, SEND_SIZE);
				pSocketInfo->pSendBuffer = 0;
			}
			if (pSocketInfo->kRecvBuffer.Mdl != 0)
			{
				fNtos->MmUnlockPages(pSocketInfo->kRecvBuffer.Mdl);
				fNtos->IoFreeMdl(pSocketInfo->kRecvBuffer.Mdl);
				pSocketInfo->kRecvBuffer.Mdl = 0;
				fNtos->MmFreeNonCachedMemory(pSocketInfo->pRecvBuffer, RECV_SIZE);
				pSocketInfo->pRecvBuffer = 0;
			}
			ChangeEntryList(pGData, pGData->wsk.s_Sever, &pSocketInfo->List.Link, &pSocketInfo->List.Link, 0);//RemoveEntryList(&pSocketInfo->List.Link);
		}
	}
	__except (1) {


	}


}
void RunApcNo8(PVOID NormalContext, PVOID SystemArgument1, PVOID SystemArgument2) {

	// 不能使用  FUNCTION_IMP
	__try {
		RUN_APC_ARG* Arg = (RUN_APC_ARG*)NormalContext;
		Global_Data* pGData = (Global_Data*)Arg->_pGData;
		NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;

		SELF_F_ARRY* fArry = &((Global_Data*)pGData)->SelfFArry;
		SELF_STRING_ARRY* AArry = &((Global_Data*)pGData)->SelfAArry;
		PKSOCKET pSocket = &pGData->wsk.bWsk.kSocket[Arg->s]; SOCKET s =Arg->s;
		SOCKET_INFO* pSocketInfo = (SOCKET_INFO*)&pGData->wsk._SocketArry[Arg->s];
		int Flags = 0;
		if (Arg->RunCode > 0x80000000)
			Flags = 1;
		IOINFO* pIO_INFO = Arg->rBuffer;
		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, Arg->_Run_Routine, KeGetCurrentIrql(), Flags);
		if (Flags) {
			FREE_FUNCTION_ENTRY(RunApcSocketBuffer, Arg->_Run_Routine);
			return;
		}
		FREE_FUNCTION_ENTRY(RunApc, Arg->_Run_Routine);
		//FREE_FUNCTION_ENTRY(RunApc, Arg->_Run_Routine);

		NTSTATUS status = 0;
        _sendEncrypt usendEncrypt = 0; MEMORY_FLAGS MFlags;
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
				fNtos->MmUnlockPages(pSocketInfo->kSendBuffer.Mdl);
				fNtos->IoFreeMdl(pSocketInfo->kSendBuffer.Mdl);
				pSocketInfo->kSendBuffer.Mdl = 0;
				fNtos->MmFreeNonCachedMemory(pSocketInfo->pSendBuffer, SEND_SIZE);
				pSocketInfo->pSendBuffer = 0;
			}
			if (pSocketInfo->kRecvBuffer.Mdl != 0)
			{
				fNtos->MmUnlockPages(pSocketInfo->kRecvBuffer.Mdl);
				fNtos->IoFreeMdl(pSocketInfo->kRecvBuffer.Mdl);
				pSocketInfo->kRecvBuffer.Mdl = 0;
				fNtos->MmFreeNonCachedMemory(pSocketInfo->pRecvBuffer, RECV_SIZE);
				pSocketInfo->pRecvBuffer = 0;
			}
			ChangeEntryList(pGData, pGData->wsk.s_Sever, &pSocketInfo->List.Link, &pSocketInfo->List.Link, 0);//RemoveEntryList(&pSocketInfo->List.Link);
		}
	}
	__except (1) {


	}


}
void RunApcNo9(PVOID NormalContext, PVOID SystemArgument1, PVOID SystemArgument2) {

	// 不能使用  FUNCTION_IMP
	__try {
		RUN_APC_ARG* Arg = (RUN_APC_ARG*)NormalContext;
		Global_Data* pGData = (Global_Data*)Arg->_pGData;
		NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;

		SELF_F_ARRY* fArry = &((Global_Data*)pGData)->SelfFArry;
		SELF_STRING_ARRY* AArry = &((Global_Data*)pGData)->SelfAArry;
		PKSOCKET pSocket = &pGData->wsk.bWsk.kSocket[Arg->s]; SOCKET s =Arg->s;
		SOCKET_INFO* pSocketInfo = (SOCKET_INFO*)&pGData->wsk._SocketArry[Arg->s];
		int Flags = 0;
		if (Arg->RunCode > 0x80000000)
			Flags = 1;
		IOINFO* pIO_INFO = Arg->rBuffer;
		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, Arg->_Run_Routine, KeGetCurrentIrql(), Flags);
		if (Flags) {
			FREE_FUNCTION_ENTRY(RunApcSocketBuffer, Arg->_Run_Routine);
			return;
		}
		FREE_FUNCTION_ENTRY(RunApc, Arg->_Run_Routine);
		//FREE_FUNCTION_ENTRY(RunApc, Arg->_Run_Routine);

		NTSTATUS status = 0;
_sendEncrypt usendEncrypt = 0; MEMORY_FLAGS MFlags;
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
				fNtos->MmUnlockPages(pSocketInfo->kSendBuffer.Mdl);
				fNtos->IoFreeMdl(pSocketInfo->kSendBuffer.Mdl);
				pSocketInfo->kSendBuffer.Mdl = 0;
				fNtos->MmFreeNonCachedMemory(pSocketInfo->pSendBuffer, SEND_SIZE);
				pSocketInfo->pSendBuffer = 0;
			}
			if (pSocketInfo->kRecvBuffer.Mdl != 0)
			{
				fNtos->MmUnlockPages(pSocketInfo->kRecvBuffer.Mdl);
				fNtos->IoFreeMdl(pSocketInfo->kRecvBuffer.Mdl);
				pSocketInfo->kRecvBuffer.Mdl = 0;
				fNtos->MmFreeNonCachedMemory(pSocketInfo->pRecvBuffer, RECV_SIZE);
				pSocketInfo->pRecvBuffer = 0;
			}
			ChangeEntryList(pGData, pGData->wsk.s_Sever, &pSocketInfo->List.Link, &pSocketInfo->List.Link, 0);//RemoveEntryList(&pSocketInfo->List.Link);
		}
	}
	__except (1) {


	}


}
void RunApcNo10(PVOID NormalContext, PVOID SystemArgument1, PVOID SystemArgument2) {

	// 不能使用  FUNCTION_IMP
	__try {
		RUN_APC_ARG* Arg = (RUN_APC_ARG*)NormalContext;
		Global_Data* pGData = (Global_Data*)Arg->_pGData;
		NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;

		SELF_F_ARRY* fArry = &((Global_Data*)pGData)->SelfFArry;
		SELF_STRING_ARRY* AArry = &((Global_Data*)pGData)->SelfAArry;
		PKSOCKET pSocket = &pGData->wsk.bWsk.kSocket[Arg->s]; SOCKET s =Arg->s;
		SOCKET_INFO* pSocketInfo = (SOCKET_INFO*)&pGData->wsk._SocketArry[Arg->s];
		int Flags = 0;
		if (Arg->RunCode > 0x80000000)
			Flags = 1;
		IOINFO* pIO_INFO = Arg->rBuffer;

		//LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, Arg->_Run_Routine, KeGetCurrentIrql(), Flags);
		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, Arg->_Run_Routine, KeGetCurrentIrql(), Flags);
		if (Flags) {
			FREE_FUNCTION_ENTRY(RunApcSocketBuffer, Arg->_Run_Routine);
			return;
		}
		FREE_FUNCTION_ENTRY(RunApc, Arg->_Run_Routine);
		//FREE_FUNCTION_ENTRY(RunApc, Arg->_Run_Routine);

		NTSTATUS status = 0;
_sendEncrypt usendEncrypt = 0; MEMORY_FLAGS MFlags;
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
				fNtos->MmUnlockPages(pSocketInfo->kSendBuffer.Mdl);
				fNtos->IoFreeMdl(pSocketInfo->kSendBuffer.Mdl);
				pSocketInfo->kSendBuffer.Mdl = 0;
				fNtos->MmFreeNonCachedMemory(pSocketInfo->pSendBuffer, SEND_SIZE);
				pSocketInfo->pSendBuffer = 0;
			}
			if (pSocketInfo->kRecvBuffer.Mdl != 0)
			{
				fNtos->MmUnlockPages(pSocketInfo->kRecvBuffer.Mdl);
				fNtos->IoFreeMdl(pSocketInfo->kRecvBuffer.Mdl);
				pSocketInfo->kRecvBuffer.Mdl = 0;
				fNtos->MmFreeNonCachedMemory(pSocketInfo->pRecvBuffer, RECV_SIZE);
				pSocketInfo->pRecvBuffer = 0;
			}
			ChangeEntryList(pGData, pGData->wsk.s_Sever, &pSocketInfo->List.Link, &pSocketInfo->List.Link, 0);//RemoveEntryList(&pSocketInfo->List.Link);
		}
	}
	__except (1) {


	}


}
void RunApcNo11(PVOID NormalContext, PVOID SystemArgument1, PVOID SystemArgument2) {

	// 不能使用  FUNCTION_IMP
	__try {
		RUN_APC_ARG* Arg = (RUN_APC_ARG*)NormalContext;
		Global_Data* pGData = (Global_Data*)Arg->_pGData;
		NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;

		SELF_F_ARRY* fArry = &((Global_Data*)pGData)->SelfFArry;
		SELF_STRING_ARRY* AArry = &((Global_Data*)pGData)->SelfAArry;
		PKSOCKET pSocket = &pGData->wsk.bWsk.kSocket[Arg->s]; SOCKET s =Arg->s;
		SOCKET_INFO* pSocketInfo = (SOCKET_INFO*)&pGData->wsk._SocketArry[Arg->s];
		int Flags = 0;
		if (Arg->RunCode > 0x80000000)
			Flags = 1;
		IOINFO* pIO_INFO = Arg->rBuffer;
		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, Arg->_Run_Routine, KeGetCurrentIrql(), Flags);
		if (Flags) {
			FREE_FUNCTION_ENTRY(RunApcSocketBuffer, Arg->_Run_Routine);
			return;
		}
		FREE_FUNCTION_ENTRY(RunApc, Arg->_Run_Routine);
		//FREE_FUNCTION_ENTRY(RunApc, Arg->_Run_Routine);

		NTSTATUS status = 0;
_sendEncrypt usendEncrypt = 0; MEMORY_FLAGS MFlags;
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
				fNtos->MmUnlockPages(pSocketInfo->kSendBuffer.Mdl);
				fNtos->IoFreeMdl(pSocketInfo->kSendBuffer.Mdl);
				pSocketInfo->kSendBuffer.Mdl = 0;
				fNtos->MmFreeNonCachedMemory(pSocketInfo->pSendBuffer, SEND_SIZE);
				pSocketInfo->pSendBuffer = 0;
			}
			if (pSocketInfo->kRecvBuffer.Mdl != 0)
			{
				fNtos->MmUnlockPages(pSocketInfo->kRecvBuffer.Mdl);
				fNtos->IoFreeMdl(pSocketInfo->kRecvBuffer.Mdl);
				pSocketInfo->kRecvBuffer.Mdl = 0;
				fNtos->MmFreeNonCachedMemory(pSocketInfo->pRecvBuffer, RECV_SIZE);
				pSocketInfo->pRecvBuffer = 0;
			}
			ChangeEntryList(pGData, pGData->wsk.s_Sever, &pSocketInfo->List.Link, &pSocketInfo->List.Link, 0);//RemoveEntryList(&pSocketInfo->List.Link);
		}
	}
	__except (1) {


	}


}
void RunApcNo12(PVOID NormalContext, PVOID SystemArgument1, PVOID SystemArgument2) {

	// 不能使用  FUNCTION_IMP
	__try {
		RUN_APC_ARG* Arg = (RUN_APC_ARG*)NormalContext;
		Global_Data* pGData = (Global_Data*)Arg->_pGData;
		NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;

		SELF_F_ARRY* fArry = &((Global_Data*)pGData)->SelfFArry;
		SELF_STRING_ARRY* AArry = &((Global_Data*)pGData)->SelfAArry;
		PKSOCKET pSocket = &pGData->wsk.bWsk.kSocket[Arg->s]; SOCKET s =Arg->s;
		SOCKET_INFO* pSocketInfo = (SOCKET_INFO*)&pGData->wsk._SocketArry[Arg->s];
		int Flags = 0;
		if (Arg->RunCode > 0x80000000)
			Flags = 1;
		IOINFO* pIO_INFO = Arg->rBuffer;
		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, Arg->_Run_Routine, KeGetCurrentIrql(), Flags);
		if (Flags) {
			FREE_FUNCTION_ENTRY(RunApcSocketBuffer, Arg->_Run_Routine);
			return;
		}
		FREE_FUNCTION_ENTRY(RunApc, Arg->_Run_Routine);
		//FREE_FUNCTION_ENTRY(RunApc, Arg->_Run_Routine);

		NTSTATUS status = 0;
_sendEncrypt usendEncrypt = 0; MEMORY_FLAGS MFlags;
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
				fNtos->MmUnlockPages(pSocketInfo->kSendBuffer.Mdl);
				fNtos->IoFreeMdl(pSocketInfo->kSendBuffer.Mdl);
				pSocketInfo->kSendBuffer.Mdl = 0;
				fNtos->MmFreeNonCachedMemory(pSocketInfo->pSendBuffer, SEND_SIZE);
				pSocketInfo->pSendBuffer = 0;
			}
			if (pSocketInfo->kRecvBuffer.Mdl != 0)
			{
				fNtos->MmUnlockPages(pSocketInfo->kRecvBuffer.Mdl);
				fNtos->IoFreeMdl(pSocketInfo->kRecvBuffer.Mdl);
				pSocketInfo->kRecvBuffer.Mdl = 0;
				fNtos->MmFreeNonCachedMemory(pSocketInfo->pRecvBuffer, RECV_SIZE);
				pSocketInfo->pRecvBuffer = 0;
			}
			ChangeEntryList(pGData, pGData->wsk.s_Sever, &pSocketInfo->List.Link, &pSocketInfo->List.Link, 0);//RemoveEntryList(&pSocketInfo->List.Link);
		}
	}
	__except (1) {


	}


}
void RunApcNo13(PVOID NormalContext, PVOID SystemArgument1, PVOID SystemArgument2) {

	// 不能使用  FUNCTION_IMP
	__try {
		RUN_APC_ARG* Arg = (RUN_APC_ARG*)NormalContext;
		Global_Data* pGData = (Global_Data*)Arg->_pGData;
		NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;

		SELF_F_ARRY* fArry = &((Global_Data*)pGData)->SelfFArry;
		SELF_STRING_ARRY* AArry = &((Global_Data*)pGData)->SelfAArry;
		PKSOCKET pSocket = &pGData->wsk.bWsk.kSocket[Arg->s]; SOCKET s =Arg->s;
		SOCKET_INFO* pSocketInfo = (SOCKET_INFO*)&pGData->wsk._SocketArry[Arg->s];
		int Flags = 0;
		if (Arg->RunCode > 0x80000000)
			Flags = 1;
		IOINFO* pIO_INFO = Arg->rBuffer;
		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, Arg->_Run_Routine, KeGetCurrentIrql(), Flags);
		if (Flags) {
			FREE_FUNCTION_ENTRY(RunApcSocketBuffer, Arg->_Run_Routine);
			return;
		}
		FREE_FUNCTION_ENTRY(RunApc, Arg->_Run_Routine);
		//FREE_FUNCTION_ENTRY(RunApc, Arg->_Run_Routine);

		NTSTATUS status = 0;
_sendEncrypt usendEncrypt = 0; MEMORY_FLAGS MFlags;
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
				fNtos->MmUnlockPages(pSocketInfo->kSendBuffer.Mdl);
				fNtos->IoFreeMdl(pSocketInfo->kSendBuffer.Mdl);
				pSocketInfo->kSendBuffer.Mdl = 0;
				fNtos->MmFreeNonCachedMemory(pSocketInfo->pSendBuffer, SEND_SIZE);
				pSocketInfo->pSendBuffer = 0;
			}
			if (pSocketInfo->kRecvBuffer.Mdl != 0)
			{
				fNtos->MmUnlockPages(pSocketInfo->kRecvBuffer.Mdl);
				fNtos->IoFreeMdl(pSocketInfo->kRecvBuffer.Mdl);
				pSocketInfo->kRecvBuffer.Mdl = 0;
				fNtos->MmFreeNonCachedMemory(pSocketInfo->pRecvBuffer, RECV_SIZE);
				pSocketInfo->pRecvBuffer = 0;
			}
			ChangeEntryList(pGData, pGData->wsk.s_Sever, &pSocketInfo->List.Link, &pSocketInfo->List.Link, 0);//RemoveEntryList(&pSocketInfo->List.Link);
		}
	}
	__except (1) {


	}


}
void RunApcNo14(PVOID NormalContext, PVOID SystemArgument1, PVOID SystemArgument2) {

	// 不能使用  FUNCTION_IMP
	__try {
		RUN_APC_ARG* Arg = (RUN_APC_ARG*)NormalContext;
		Global_Data* pGData = (Global_Data*)Arg->_pGData;
		NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;

		SELF_F_ARRY* fArry = &((Global_Data*)pGData)->SelfFArry;
		SELF_STRING_ARRY* AArry = &((Global_Data*)pGData)->SelfAArry;
		PKSOCKET pSocket = &pGData->wsk.bWsk.kSocket[Arg->s]; SOCKET s =Arg->s;
		SOCKET_INFO* pSocketInfo = (SOCKET_INFO*)&pGData->wsk._SocketArry[Arg->s];
		int Flags = 0;
		if (Arg->RunCode > 0x80000000)
			Flags = 1;
		IOINFO* pIO_INFO = Arg->rBuffer;
		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, Arg->_Run_Routine, KeGetCurrentIrql(), Flags);
		if (Flags) {
			FREE_FUNCTION_ENTRY(RunApcSocketBuffer, Arg->_Run_Routine);
			return;
		}
		FREE_FUNCTION_ENTRY(RunApc, Arg->_Run_Routine);
		//FREE_FUNCTION_ENTRY(RunApc, Arg->_Run_Routine);

		NTSTATUS status = 0;
_sendEncrypt usendEncrypt = 0; MEMORY_FLAGS MFlags;
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
				fNtos->MmUnlockPages(pSocketInfo->kSendBuffer.Mdl);
				fNtos->IoFreeMdl(pSocketInfo->kSendBuffer.Mdl);
				pSocketInfo->kSendBuffer.Mdl = 0;
				fNtos->MmFreeNonCachedMemory(pSocketInfo->pSendBuffer, SEND_SIZE);
				pSocketInfo->pSendBuffer = 0;
			}
			if (pSocketInfo->kRecvBuffer.Mdl != 0)
			{
				fNtos->MmUnlockPages(pSocketInfo->kRecvBuffer.Mdl);
				fNtos->IoFreeMdl(pSocketInfo->kRecvBuffer.Mdl);
				pSocketInfo->kRecvBuffer.Mdl = 0;
				fNtos->MmFreeNonCachedMemory(pSocketInfo->pRecvBuffer, RECV_SIZE);
				pSocketInfo->pRecvBuffer = 0;
			}
			ChangeEntryList(pGData, pGData->wsk.s_Sever, &pSocketInfo->List.Link, &pSocketInfo->List.Link, 0);//RemoveEntryList(&pSocketInfo->List.Link);
		}
	}
	__except (1) {


	}


}
void RunApcNo15(PVOID NormalContext, PVOID SystemArgument1, PVOID SystemArgument2) {

	// 不能使用  FUNCTION_IMP
	__try {
		RUN_APC_ARG* Arg = (RUN_APC_ARG*)NormalContext;
		Global_Data* pGData = (Global_Data*)Arg->_pGData;
		NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;

		SELF_F_ARRY* fArry = &((Global_Data*)pGData)->SelfFArry;
		SELF_STRING_ARRY* AArry = &((Global_Data*)pGData)->SelfAArry;
		PKSOCKET pSocket = &pGData->wsk.bWsk.kSocket[Arg->s]; SOCKET s =Arg->s;
		SOCKET_INFO* pSocketInfo = (SOCKET_INFO*)&pGData->wsk._SocketArry[Arg->s];
		int Flags = 0;
		if (Arg->RunCode > 0x80000000)
			Flags = 1;
		IOINFO* pIO_INFO = Arg->rBuffer;
		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, Arg->_Run_Routine, KeGetCurrentIrql(), Flags);
		if (Flags) {
			FREE_FUNCTION_ENTRY(RunApcSocketBuffer, Arg->_Run_Routine);
			return;
		}
		FREE_FUNCTION_ENTRY(RunApc, Arg->_Run_Routine);
		//FREE_FUNCTION_ENTRY(RunApc, Arg->_Run_Routine);

		NTSTATUS status = 0;
_sendEncrypt usendEncrypt = 0; MEMORY_FLAGS MFlags;
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
				fNtos->MmUnlockPages(pSocketInfo->kSendBuffer.Mdl);
				fNtos->IoFreeMdl(pSocketInfo->kSendBuffer.Mdl);
				pSocketInfo->kSendBuffer.Mdl = 0;
				fNtos->MmFreeNonCachedMemory(pSocketInfo->pSendBuffer, SEND_SIZE);
				pSocketInfo->pSendBuffer = 0;
			}
			if (pSocketInfo->kRecvBuffer.Mdl != 0)
			{
				fNtos->MmUnlockPages(pSocketInfo->kRecvBuffer.Mdl);
				fNtos->IoFreeMdl(pSocketInfo->kRecvBuffer.Mdl);
				pSocketInfo->kRecvBuffer.Mdl = 0;
				fNtos->MmFreeNonCachedMemory(pSocketInfo->pRecvBuffer, RECV_SIZE);
				pSocketInfo->pRecvBuffer = 0;
			}
			ChangeEntryList(pGData, pGData->wsk.s_Sever, &pSocketInfo->List.Link, &pSocketInfo->List.Link, 0);//RemoveEntryList(&pSocketInfo->List.Link);
		}
	}
	__except (1) {


	}


}
void RunApcNo16(PVOID NormalContext, PVOID SystemArgument1, PVOID SystemArgument2) {

	// 不能使用  FUNCTION_IMP
	__try {
		RUN_APC_ARG* Arg = (RUN_APC_ARG*)NormalContext;
		Global_Data* pGData = (Global_Data*)Arg->_pGData;
		NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;

		SELF_F_ARRY* fArry = &((Global_Data*)pGData)->SelfFArry;
		SELF_STRING_ARRY* AArry = &((Global_Data*)pGData)->SelfAArry;
		PKSOCKET pSocket = &pGData->wsk.bWsk.kSocket[Arg->s]; SOCKET s =Arg->s;
		SOCKET_INFO* pSocketInfo = (SOCKET_INFO*)&pGData->wsk._SocketArry[Arg->s];
		int Flags = 0;
		if (Arg->RunCode > 0x80000000)
			Flags = 1;
		IOINFO* pIO_INFO = Arg->rBuffer;
		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, Arg->_Run_Routine, KeGetCurrentIrql(), Flags);
		if (Flags) {
			FREE_FUNCTION_ENTRY(RunApcSocketBuffer, Arg->_Run_Routine);
			return;
		}
		FREE_FUNCTION_ENTRY(RunApc, Arg->_Run_Routine);
		//FREE_FUNCTION_ENTRY(RunApc, Arg->_Run_Routine);

		NTSTATUS status = 0;
_sendEncrypt usendEncrypt = 0; MEMORY_FLAGS MFlags;
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
				fNtos->MmUnlockPages(pSocketInfo->kSendBuffer.Mdl);
				fNtos->IoFreeMdl(pSocketInfo->kSendBuffer.Mdl);
				pSocketInfo->kSendBuffer.Mdl = 0;
				fNtos->MmFreeNonCachedMemory(pSocketInfo->pSendBuffer, SEND_SIZE);
				pSocketInfo->pSendBuffer = 0;
			}
			if (pSocketInfo->kRecvBuffer.Mdl != 0)
			{
				fNtos->MmUnlockPages(pSocketInfo->kRecvBuffer.Mdl);
				fNtos->IoFreeMdl(pSocketInfo->kRecvBuffer.Mdl);
				pSocketInfo->kRecvBuffer.Mdl = 0;
				fNtos->MmFreeNonCachedMemory(pSocketInfo->pRecvBuffer, RECV_SIZE);
				pSocketInfo->pRecvBuffer = 0;
			}
			ChangeEntryList(pGData, pGData->wsk.s_Sever, &pSocketInfo->List.Link, &pSocketInfo->List.Link, 0);//RemoveEntryList(&pSocketInfo->List.Link);
		}
	}
	__except (1) {


	}


}
void RunApcNo17(PVOID NormalContext, PVOID SystemArgument1, PVOID SystemArgument2) {

	// 不能使用  FUNCTION_IMP
	__try {
		RUN_APC_ARG* Arg = (RUN_APC_ARG*)NormalContext;
		Global_Data* pGData = (Global_Data*)Arg->_pGData;
		NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;

		SELF_F_ARRY* fArry = &((Global_Data*)pGData)->SelfFArry;
		SELF_STRING_ARRY* AArry = &((Global_Data*)pGData)->SelfAArry;
		PKSOCKET pSocket = &pGData->wsk.bWsk.kSocket[Arg->s]; SOCKET s =Arg->s;
		SOCKET_INFO* pSocketInfo = (SOCKET_INFO*)&pGData->wsk._SocketArry[Arg->s];
		int Flags = 0;
		if (Arg->RunCode > 0x80000000)
			Flags = 1;
		IOINFO* pIO_INFO = Arg->rBuffer;
		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, Arg->_Run_Routine, KeGetCurrentIrql(), Flags);
		if (Flags) {
			FREE_FUNCTION_ENTRY(RunApcSocketBuffer, Arg->_Run_Routine);
			return;
		}
		FREE_FUNCTION_ENTRY(RunApc, Arg->_Run_Routine);
		//FREE_FUNCTION_ENTRY(RunApc, Arg->_Run_Routine);

		NTSTATUS status = 0;
_sendEncrypt usendEncrypt = 0; MEMORY_FLAGS MFlags;
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
				fNtos->MmUnlockPages(pSocketInfo->kSendBuffer.Mdl);
				fNtos->IoFreeMdl(pSocketInfo->kSendBuffer.Mdl);
				pSocketInfo->kSendBuffer.Mdl = 0;
				fNtos->MmFreeNonCachedMemory(pSocketInfo->pSendBuffer, SEND_SIZE);
				pSocketInfo->pSendBuffer = 0;
			}
			if (pSocketInfo->kRecvBuffer.Mdl != 0)
			{
				fNtos->MmUnlockPages(pSocketInfo->kRecvBuffer.Mdl);
				fNtos->IoFreeMdl(pSocketInfo->kRecvBuffer.Mdl);
				pSocketInfo->kRecvBuffer.Mdl = 0;
				fNtos->MmFreeNonCachedMemory(pSocketInfo->pRecvBuffer, RECV_SIZE);
				pSocketInfo->pRecvBuffer = 0;
			}
			ChangeEntryList(pGData, pGData->wsk.s_Sever, &pSocketInfo->List.Link, &pSocketInfo->List.Link, 0);//RemoveEntryList(&pSocketInfo->List.Link);
		}
	}
	__except (1) {


	}


}
void RunApcNo18(PVOID NormalContext, PVOID SystemArgument1, PVOID SystemArgument2) {

	// 不能使用  FUNCTION_IMP
	__try {
		RUN_APC_ARG* Arg = (RUN_APC_ARG*)NormalContext;
		Global_Data* pGData = (Global_Data*)Arg->_pGData;
		NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;

		SELF_F_ARRY* fArry = &((Global_Data*)pGData)->SelfFArry;
		SELF_STRING_ARRY* AArry = &((Global_Data*)pGData)->SelfAArry;
		PKSOCKET pSocket = &pGData->wsk.bWsk.kSocket[Arg->s]; SOCKET s =Arg->s;
		SOCKET_INFO* pSocketInfo = (SOCKET_INFO*)&pGData->wsk._SocketArry[Arg->s];
		int Flags = 0;
		if (Arg->RunCode > 0x80000000)
			Flags = 1;
		IOINFO* pIO_INFO = Arg->rBuffer;
		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, Arg->_Run_Routine, KeGetCurrentIrql(), Flags);
		if (Flags) {
			FREE_FUNCTION_ENTRY(RunApcSocketBuffer, Arg->_Run_Routine);
			return;
		}
		FREE_FUNCTION_ENTRY(RunApc, Arg->_Run_Routine);
		//FREE_FUNCTION_ENTRY(RunApc, Arg->_Run_Routine);

		NTSTATUS status = 0;
_sendEncrypt usendEncrypt = 0; MEMORY_FLAGS MFlags;
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
				fNtos->MmUnlockPages(pSocketInfo->kSendBuffer.Mdl);
				fNtos->IoFreeMdl(pSocketInfo->kSendBuffer.Mdl);
				pSocketInfo->kSendBuffer.Mdl = 0;
				fNtos->MmFreeNonCachedMemory(pSocketInfo->pSendBuffer, SEND_SIZE);
				pSocketInfo->pSendBuffer = 0;
			}
			if (pSocketInfo->kRecvBuffer.Mdl != 0)
			{
				fNtos->MmUnlockPages(pSocketInfo->kRecvBuffer.Mdl);
				fNtos->IoFreeMdl(pSocketInfo->kRecvBuffer.Mdl);
				pSocketInfo->kRecvBuffer.Mdl = 0;
				fNtos->MmFreeNonCachedMemory(pSocketInfo->pRecvBuffer, RECV_SIZE);
				pSocketInfo->pRecvBuffer = 0;
			}
			ChangeEntryList(pGData, pGData->wsk.s_Sever, &pSocketInfo->List.Link, &pSocketInfo->List.Link, 0);//RemoveEntryList(&pSocketInfo->List.Link);
		}
	}
	__except (1) {


	}


}
void RunApcNo19(PVOID NormalContext, PVOID SystemArgument1, PVOID SystemArgument2) {

	// 不能使用  FUNCTION_IMP
	__try {
		RUN_APC_ARG* Arg = (RUN_APC_ARG*)NormalContext;
		Global_Data* pGData = (Global_Data*)Arg->_pGData;
		NTOSKRNL_FUN* fNtos = &((Global_Data*)pGData)->fNtos;

		SELF_F_ARRY* fArry = &((Global_Data*)pGData)->SelfFArry;
		SELF_STRING_ARRY* AArry = &((Global_Data*)pGData)->SelfAArry;
		PKSOCKET pSocket = &pGData->wsk.bWsk.kSocket[Arg->s]; SOCKET s =Arg->s;
		SOCKET_INFO* pSocketInfo = (SOCKET_INFO*)&pGData->wsk._SocketArry[Arg->s];
		int Flags = 0;
		if (Arg->RunCode > 0x80000000)
			Flags = 1;
		IOINFO* pIO_INFO = Arg->rBuffer;

		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, Arg->_Run_Routine, KeGetCurrentIrql(), Flags);
		if (Flags) {
			FREE_FUNCTION_ENTRY(RunApcSocketBuffer, Arg->_Run_Routine);
			return;
		}
		FREE_FUNCTION_ENTRY(RunApc, Arg->_Run_Routine);
		//FREE_FUNCTION_ENTRY(RunApc, Arg->_Run_Routine);

		NTSTATUS status = 0;
_sendEncrypt usendEncrypt = 0; MEMORY_FLAGS MFlags;
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
				fNtos->MmUnlockPages(pSocketInfo->kSendBuffer.Mdl);
				fNtos->IoFreeMdl(pSocketInfo->kSendBuffer.Mdl);
				pSocketInfo->kSendBuffer.Mdl = 0;
				fNtos->MmFreeNonCachedMemory(pSocketInfo->pSendBuffer, SEND_SIZE);
				pSocketInfo->pSendBuffer = 0;
			}
			if (pSocketInfo->kRecvBuffer.Mdl != 0)
			{
				fNtos->MmUnlockPages(pSocketInfo->kRecvBuffer.Mdl);
				fNtos->IoFreeMdl(pSocketInfo->kRecvBuffer.Mdl);
				pSocketInfo->kRecvBuffer.Mdl = 0;
				fNtos->MmFreeNonCachedMemory(pSocketInfo->pRecvBuffer, RECV_SIZE);
				pSocketInfo->pRecvBuffer = 0;
			}
			ChangeEntryList(pGData, pGData->wsk.s_Sever, &pSocketInfo->List.Link, &pSocketInfo->List.Link, 0);//RemoveEntryList(&pSocketInfo->List.Link);
		}
	}
	__except (1) {


	}


}




//------------------------------------------------------------------------------------------


void _WORKER_THREAD_ROUTINE_ACCEPT_SEND_RECV20(PVOID Parameter) {
	PWSK_COMPLETION_ROUTINE pWskCompletionRoutine = (PWSK_COMPLETION_ROUTINE)Parameter;
	Global_Data* pGData = (Global_Data*)pWskCompletionRoutine->pGData;
	SELF_F_ARRY* fArry = &pGData->SelfFArry;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	DWORD64 Ret = 0;  SOCKET s = pWskCompletionRoutine->s;
	SELF_STRING_ARRY* AArry = &pGData->SelfAArry;
	WSK_SERVER_INFO* WskInfo = &pGData->wsk;
	fNtos->KeSetPriorityThread(KeGetCurrentThread(), HIGH_PRIORITY);
	if (pWskCompletionRoutine->Flags == 2) {
		_FUNCTION_IMP(ACCEPT_ROUTINE, Ret, pGData, pWskCompletionRoutine->s);
	}
	else {
		_FUNCTION_IMP(RECV_SEND_ROUTINE, Ret, pGData, pWskCompletionRoutine->s, pWskCompletionRoutine->Flags);
	}
}

#define _WORKER_THREAD_ROUTINE_ACCEPT_SEND_RECV_FUN(x) void _WORKER_THREAD_ROUTINE_ACCEPT_SEND_RECV##x(PVOID Parameter) {\
PWSK_COMPLETION_ROUTINE pWskCompletionRoutine = (PWSK_COMPLETION_ROUTINE)Parameter;\
Global_Data* pGData = (Global_Data*)pWskCompletionRoutine->pGData;\
SELF_F_ARRY* fArry = &pGData->SelfFArry;\
NTOSKRNL_FUN* fNtos = &pGData->fNtos;\
DWORD64 Ret = 0;  SOCKET s = pWskCompletionRoutine->s;\
SELF_STRING_ARRY* AArry = &pGData->SelfAArry;\
WSK_SERVER_INFO* WskInfo = &pGData->wsk;\
fNtos->KeSetPriorityThread(KeGetCurrentThread(), HIGH_PRIORITY);\
if (pWskCompletionRoutine->Flags == 2) {\
	_FUNCTION_IMP(ACCEPT_ROUTINE, Ret, pGData, pWskCompletionRoutine->s);\
}\
else {\
	_FUNCTION_IMP(RECV_SEND_ROUTINE, Ret, pGData, pWskCompletionRoutine->s, pWskCompletionRoutine->Flags);\
}\
}\


_WORKER_THREAD_ROUTINE_ACCEPT_SEND_RECV_FUN(0)
_WORKER_THREAD_ROUTINE_ACCEPT_SEND_RECV_FUN(1)
_WORKER_THREAD_ROUTINE_ACCEPT_SEND_RECV_FUN(2)
_WORKER_THREAD_ROUTINE_ACCEPT_SEND_RECV_FUN(3)
_WORKER_THREAD_ROUTINE_ACCEPT_SEND_RECV_FUN(4)
_WORKER_THREAD_ROUTINE_ACCEPT_SEND_RECV_FUN(5)
_WORKER_THREAD_ROUTINE_ACCEPT_SEND_RECV_FUN(6)
_WORKER_THREAD_ROUTINE_ACCEPT_SEND_RECV_FUN(7)
_WORKER_THREAD_ROUTINE_ACCEPT_SEND_RECV_FUN(8)
_WORKER_THREAD_ROUTINE_ACCEPT_SEND_RECV_FUN(9)
_WORKER_THREAD_ROUTINE_ACCEPT_SEND_RECV_FUN(10)
_WORKER_THREAD_ROUTINE_ACCEPT_SEND_RECV_FUN(11)
_WORKER_THREAD_ROUTINE_ACCEPT_SEND_RECV_FUN(12)
_WORKER_THREAD_ROUTINE_ACCEPT_SEND_RECV_FUN(13)
_WORKER_THREAD_ROUTINE_ACCEPT_SEND_RECV_FUN(14)
_WORKER_THREAD_ROUTINE_ACCEPT_SEND_RECV_FUN(15)
_WORKER_THREAD_ROUTINE_ACCEPT_SEND_RECV_FUN(16)
_WORKER_THREAD_ROUTINE_ACCEPT_SEND_RECV_FUN(17)
_WORKER_THREAD_ROUTINE_ACCEPT_SEND_RECV_FUN(18)
_WORKER_THREAD_ROUTINE_ACCEPT_SEND_RECV_FUN(19)




NTSTATUS IO_COMPLETION_ROUTINE_Ex0(PDEVICE_OBJECT DeviceObject, PIRP Irp, PVOID Context) {
	PWSK_COMPLETION_ROUTINE pWskCompletionRoutine = (PWSK_COMPLETION_ROUTINE)Context;
	Global_Data* pGData = (Global_Data*)pWskCompletionRoutine->pGData;
	SELF_F_ARRY* fArry = &pGData->SelfFArry;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	DWORD64 Ret = 0;  SOCKET s = pWskCompletionRoutine->s;
	SELF_STRING_ARRY* AArry = &pGData->SelfAArry;
	WSK_SERVER_INFO* WskInfo = &pGData->wsk;
	if (pGData->HandleMode == 0){
		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s, pWskCompletionRoutine->Flags);
		if (pWskCompletionRoutine->Flags == 2) {
			_FUNCTION_IMP(ACCEPT_ROUTINE, Ret, pGData, pWskCompletionRoutine->s);
		}
		else {
			_FUNCTION_IMP(RECV_SEND_ROUTINE, Ret, pGData, pWskCompletionRoutine->s, pWskCompletionRoutine->Flags);
		}
	}else if (pGData->HandleMode == 1) {
		WORKER_T_INFO* pWorkInfo = &WskInfo->_SocketArry[s].TWorker;
		//ULONG Time = fNtos->ExSetTimerResolution(fNtos->MinTimerRound, TRUE);
		ExInitializeWorkItem(&pWorkInfo->WorkQueueItem, (PWORKER_THREAD_ROUTINE)pGData->WORKER_THREAD_ROUTINE_ACCEPT_SEND_RECV.SelfTradition, pWskCompletionRoutine);
		fNtos->ExQueueWorkItem(&pWorkInfo->WorkQueueItem, CriticalWorkQueue);
	}
	return STATUS_MORE_PROCESSING_REQUIRED;
}

//#define IO_COMPLETION_ROUTINE_ExFun(x) IO_COMPLETION_ROUTINE_Ex##x(PDEVICE_OBJECT DeviceObject, PIRP Irp, PVOID Context){\
//	PWSK_COMPLETION_ROUTINE pWskCompletionRoutine = (PWSK_COMPLETION_ROUTINE)Context;\
//Global_Data* pGData = (Global_Data*)pWskCompletionRoutine->pGData;\
//SELF_F_ARRY* fArry = &pGData->SelfFArry;\
//NTOSKRNL_FUN* fNtos = &pGData->fNtos;\
//DWORD64 Ret = 0;  SOCKET s = pWskCompletionRoutine->s;\
//SELF_STRING_ARRY* AArry = &pGData->SelfAArry;\
//WSK_SERVER_INFO* WskInfo = &pGData->wsk;\
//LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s, pWskCompletionRoutine->Flags);\
//if (pWskCompletionRoutine->Flags == 2) {\
//	_FUNCTION_IMP(ACCEPT_ROUTINE, Ret, pGData, pWskCompletionRoutine->s);\
//}\
//else {\
//	_FUNCTION_IMP(RECV_SEND_ROUTINE, Ret, pGData, pWskCompletionRoutine->s, pWskCompletionRoutine->Flags);\
//}\
//return STATUS_MORE_PROCESSING_REQUIRED;\
//}\

#define IO_COMPLETION_ROUTINE_ExFun(x) IO_COMPLETION_ROUTINE_Ex##x(PDEVICE_OBJECT DeviceObject, PIRP Irp, PVOID Context){\
PWSK_COMPLETION_ROUTINE pWskCompletionRoutine = (PWSK_COMPLETION_ROUTINE)Context;\
Global_Data* pGData = (Global_Data*)pWskCompletionRoutine->pGData;\
SELF_F_ARRY* fArry = &pGData->SelfFArry;\
NTOSKRNL_FUN* fNtos = &pGData->fNtos;\
DWORD64 Ret = 0;  SOCKET s = pWskCompletionRoutine->s;\
SELF_STRING_ARRY* AArry = &pGData->SelfAArry;\
WSK_SERVER_INFO* WskInfo = &pGData->wsk;\
if (pGData->HandleMode == 0) {\
	if (pWskCompletionRoutine->Flags == 2) {\
		_FUNCTION_IMP(ACCEPT_ROUTINE, Ret, pGData, pWskCompletionRoutine->s);\
	}\
	else {\
		_FUNCTION_IMP(RECV_SEND_ROUTINE, Ret, pGData, pWskCompletionRoutine->s, pWskCompletionRoutine->Flags);\
	}\
}\
else if (pGData->HandleMode == 1) {\
	WORKER_T_INFO* pWorkInfo = &WskInfo->_SocketArry[s].TWorker;\
	ExInitializeWorkItem(&pWorkInfo->WorkQueueItem, (PWORKER_THREAD_ROUTINE)pGData->WORKER_THREAD_ROUTINE_ACCEPT_SEND_RECV.SelfTradition, pWskCompletionRoutine);\
	fNtos->ExQueueWorkItem(&pWorkInfo->WorkQueueItem, CriticalWorkQueue);\
}\
return STATUS_MORE_PROCESSING_REQUIRED;\
}\



IO_COMPLETION_ROUTINE_ExFun(1)
IO_COMPLETION_ROUTINE_ExFun(2)
IO_COMPLETION_ROUTINE_ExFun(3)
IO_COMPLETION_ROUTINE_ExFun(4)
IO_COMPLETION_ROUTINE_ExFun(5)
IO_COMPLETION_ROUTINE_ExFun(6)
IO_COMPLETION_ROUTINE_ExFun(7)
IO_COMPLETION_ROUTINE_ExFun(8)
IO_COMPLETION_ROUTINE_ExFun(9)
IO_COMPLETION_ROUTINE_ExFun(10)
IO_COMPLETION_ROUTINE_ExFun(11)
IO_COMPLETION_ROUTINE_ExFun(12)
IO_COMPLETION_ROUTINE_ExFun(13)
IO_COMPLETION_ROUTINE_ExFun(14)
IO_COMPLETION_ROUTINE_ExFun(15)
IO_COMPLETION_ROUTINE_ExFun(16)
IO_COMPLETION_ROUTINE_ExFun(17)
IO_COMPLETION_ROUTINE_ExFun(18)
IO_COMPLETION_ROUTINE_ExFun(19)


//NTSTATUS IO_COMPLETION_ROUTINE_Ex1(PDEVICE_OBJECT DeviceObject, PIRP Irp, PVOID Context) {
//
//	PWSK_COMPLETION_ROUTINE pWskCompletionRoutine = (PWSK_COMPLETION_ROUTINE)Context;
//
//	Global_Data* pGData = (Global_Data*)pWskCompletionRoutine->pGData;
//	SELF_F_ARRY* fArry = &pGData->SelfFArry;
//	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
//	DWORD64 Ret = 0;  SOCKET s = pWskCompletionRoutine->s;
//	SELF_STRING_ARRY* AArry = &pGData->SelfAArry;
//
//
//	WSK_SERVER_INFO* WskInfo = &pGData->wsk;
//
//	// 移除废掉的内存
//
//
//	//	LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s,pWskCompletionRoutine->Flags);
//	//LIST_ENTRY* pEntry = &WskInfo->_SocketArry[pWskCompletionRoutine->s].CallBackEntry;
//	//LIST_ENTRY* bEntry = pEntry->Flink;
//	//while (bEntry != pEntry) {
//
//	//	PCOMPLETION_ROUTINE_INFO pComRouInfo = (PCOMPLETION_ROUTINE_INFO)bEntry;
//	//	if (fNtos->KeReadStateEvent(&pComRouInfo->RemoveEvent)) {
//	//		bEntry = bEntry->Flink;
//	//		RemoveEntryList(&pComRouInfo->Link);
//	//		fNtos->ExFreePoolWithTag(pComRouInfo, 'Tag');
//	//		continue;
//	//	}
//	//	bEntry = bEntry->Flink;
//	//}
//
//	LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s,pWskCompletionRoutine->Flags);
//	//fNtos->KeLowerIrql(APC_LEVEL);
//	if (pWskCompletionRoutine->Flags == 2) {
//		// LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s);
//		_FUNCTION_IMP(ACCEPT_ROUTINE, Ret, pGData, pWskCompletionRoutine->s);
//	}
//	else
//	{
//		_FUNCTION_IMP(RECV_SEND_ROUTINE, Ret, pGData, pWskCompletionRoutine->s, pWskCompletionRoutine->Flags);
//	}
//	//fNtos->KfRaiseIrql(DISPATCH_LEVEL);
//	//PCOMPLETION_ROUTINE_INFO pComRouInfo = pWskCompletionRoutine->pComRouInfo;
//	//fNtos->KeSetEvent(&pComRouInfo->RemoveEvent, IO_NO_INCREMENT, FALSE);
//	return STATUS_MORE_PROCESSING_REQUIRED;
//}
//NTSTATUS IO_COMPLETION_ROUTINE_Ex2(PDEVICE_OBJECT DeviceObject, PIRP Irp, PVOID Context) {
//
//	PWSK_COMPLETION_ROUTINE pWskCompletionRoutine = (PWSK_COMPLETION_ROUTINE)Context;
//
//	Global_Data* pGData = (Global_Data*)pWskCompletionRoutine->pGData;
//	SELF_F_ARRY* fArry = &pGData->SelfFArry;
//	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
//	DWORD64 Ret = 0;  SOCKET s = pWskCompletionRoutine->s;
//	SELF_STRING_ARRY* AArry = &pGData->SelfAArry;
//
//
//	WSK_SERVER_INFO* WskInfo = &pGData->wsk;
//
//	// 移除废掉的内存
//
//
//		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s,pWskCompletionRoutine->Flags);
//	//LIST_ENTRY* pEntry = &WskInfo->_SocketArry[pWskCompletionRoutine->s].CallBackEntry;
//	//LIST_ENTRY* bEntry = pEntry->Flink;
//	//while (bEntry != pEntry) {
//
//	//	PCOMPLETION_ROUTINE_INFO pComRouInfo = (PCOMPLETION_ROUTINE_INFO)bEntry;
//	//	if (fNtos->KeReadStateEvent(&pComRouInfo->RemoveEvent)) {
//	//		bEntry = bEntry->Flink;
//	//		RemoveEntryList(&pComRouInfo->Link);
//	//		fNtos->ExFreePoolWithTag(pComRouInfo, 'Tag');
//	//		continue;
//	//	}
//	//	bEntry = bEntry->Flink;
//	//}
//
//	LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s,pWskCompletionRoutine->Flags);
//	//fNtos->KeLowerIrql(APC_LEVEL);
//	if (pWskCompletionRoutine->Flags == 2) {
//		// LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s);
//		_FUNCTION_IMP(ACCEPT_ROUTINE, Ret, pGData, pWskCompletionRoutine->s);
//	}
//	else
//	{
//		_FUNCTION_IMP(RECV_SEND_ROUTINE, Ret, pGData, pWskCompletionRoutine->s, pWskCompletionRoutine->Flags);
//	}
//	//fNtos->KfRaiseIrql(DISPATCH_LEVEL);
//	//PCOMPLETION_ROUTINE_INFO pComRouInfo = pWskCompletionRoutine->pComRouInfo;
//	//fNtos->KeSetEvent(&pComRouInfo->RemoveEvent, IO_NO_INCREMENT, FALSE);
//	return STATUS_MORE_PROCESSING_REQUIRED;
//}
//NTSTATUS IO_COMPLETION_ROUTINE_Ex3(PDEVICE_OBJECT DeviceObject, PIRP Irp, PVOID Context) {
//
//	PWSK_COMPLETION_ROUTINE pWskCompletionRoutine = (PWSK_COMPLETION_ROUTINE)Context;
//
//	Global_Data* pGData = (Global_Data*)pWskCompletionRoutine->pGData;
//	SELF_F_ARRY* fArry = &pGData->SelfFArry;
//	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
//	DWORD64 Ret = 0;  SOCKET s = pWskCompletionRoutine->s;
//	SELF_STRING_ARRY* AArry = &pGData->SelfAArry;
//
//
//	WSK_SERVER_INFO* WskInfo = &pGData->wsk;
//
//	// 移除废掉的内存
//
//
//		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s,pWskCompletionRoutine->Flags);
//	//LIST_ENTRY* pEntry = &WskInfo->_SocketArry[pWskCompletionRoutine->s].CallBackEntry;
//	//LIST_ENTRY* bEntry = pEntry->Flink;
//	//while (bEntry != pEntry) {
//
//	//	PCOMPLETION_ROUTINE_INFO pComRouInfo = (PCOMPLETION_ROUTINE_INFO)bEntry;
//	//	if (fNtos->KeReadStateEvent(&pComRouInfo->RemoveEvent)) {
//	//		bEntry = bEntry->Flink;
//	//		RemoveEntryList(&pComRouInfo->Link);
//	//		fNtos->ExFreePoolWithTag(pComRouInfo, 'Tag');
//	//		continue;
//	//	}
//	//	bEntry = bEntry->Flink;
//	//}
//
//		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s,pWskCompletionRoutine->Flags);
//		//fNtos->KeLowerIrql(APC_LEVEL);
//		if (pWskCompletionRoutine->Flags == 2) {
//			// LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s);
//			_FUNCTION_IMP(ACCEPT_ROUTINE, Ret, pGData, pWskCompletionRoutine->s);
//		}
//		else
//		{
//			_FUNCTION_IMP(RECV_SEND_ROUTINE, Ret, pGData, pWskCompletionRoutine->s, pWskCompletionRoutine->Flags);
//		}
//		//fNtos->KfRaiseIrql(DISPATCH_LEVEL);
//	//PCOMPLETION_ROUTINE_INFO pComRouInfo = pWskCompletionRoutine->pComRouInfo;
//	//fNtos->KeSetEvent(&pComRouInfo->RemoveEvent, IO_NO_INCREMENT, FALSE);
//	return STATUS_MORE_PROCESSING_REQUIRED;
//}
//NTSTATUS IO_COMPLETION_ROUTINE_Ex4(PDEVICE_OBJECT DeviceObject, PIRP Irp, PVOID Context) {
//
//	PWSK_COMPLETION_ROUTINE pWskCompletionRoutine = (PWSK_COMPLETION_ROUTINE)Context;
//
//	Global_Data* pGData = (Global_Data*)pWskCompletionRoutine->pGData;
//	SELF_F_ARRY* fArry = &pGData->SelfFArry;
//	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
//	DWORD64 Ret = 0;  SOCKET s = pWskCompletionRoutine->s;
//	SELF_STRING_ARRY* AArry = &pGData->SelfAArry;
//
//
//	WSK_SERVER_INFO* WskInfo = &pGData->wsk;
//
//	// 移除废掉的内存
//
//
//		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s,pWskCompletionRoutine->Flags);
//	//LIST_ENTRY* pEntry = &WskInfo->_SocketArry[pWskCompletionRoutine->s].CallBackEntry;
//	//LIST_ENTRY* bEntry = pEntry->Flink;
//	//while (bEntry != pEntry) {
//
//	//	PCOMPLETION_ROUTINE_INFO pComRouInfo = (PCOMPLETION_ROUTINE_INFO)bEntry;
//	//	if (fNtos->KeReadStateEvent(&pComRouInfo->RemoveEvent)) {
//	//		bEntry = bEntry->Flink;
//	//		RemoveEntryList(&pComRouInfo->Link);
//	//		fNtos->ExFreePoolWithTag(pComRouInfo, 'Tag');
//	//		continue;
//	//	}
//	//	bEntry = bEntry->Flink;
//	//}
//
//		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s,pWskCompletionRoutine->Flags);
//		//fNtos->KeLowerIrql(APC_LEVEL);
//		if (pWskCompletionRoutine->Flags == 2) {
//			// LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s);
//			_FUNCTION_IMP(ACCEPT_ROUTINE, Ret, pGData, pWskCompletionRoutine->s);
//		}
//		else
//		{
//			_FUNCTION_IMP(RECV_SEND_ROUTINE, Ret, pGData, pWskCompletionRoutine->s, pWskCompletionRoutine->Flags);
//		}
//		//fNtos->KfRaiseIrql(DISPATCH_LEVEL);
//	//PCOMPLETION_ROUTINE_INFO pComRouInfo = pWskCompletionRoutine->pComRouInfo;
//	//fNtos->KeSetEvent(&pComRouInfo->RemoveEvent, IO_NO_INCREMENT, FALSE);
//	return STATUS_MORE_PROCESSING_REQUIRED;
//}
//NTSTATUS IO_COMPLETION_ROUTINE_Ex5(PDEVICE_OBJECT DeviceObject, PIRP Irp, PVOID Context) {
//
//	PWSK_COMPLETION_ROUTINE pWskCompletionRoutine = (PWSK_COMPLETION_ROUTINE)Context;
//
//	Global_Data* pGData = (Global_Data*)pWskCompletionRoutine->pGData;
//	SELF_F_ARRY* fArry = &pGData->SelfFArry;
//	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
//	DWORD64 Ret = 0;  SOCKET s = pWskCompletionRoutine->s;
//	SELF_STRING_ARRY* AArry = &pGData->SelfAArry;
//
//
//	WSK_SERVER_INFO* WskInfo = &pGData->wsk;
//
//	// 移除废掉的内存
//
//
//		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s,pWskCompletionRoutine->Flags);
//	//LIST_ENTRY* pEntry = &WskInfo->_SocketArry[pWskCompletionRoutine->s].CallBackEntry;
//	//LIST_ENTRY* bEntry = pEntry->Flink;
//	//while (bEntry != pEntry) {
//
//	//	PCOMPLETION_ROUTINE_INFO pComRouInfo = (PCOMPLETION_ROUTINE_INFO)bEntry;
//	//	if (fNtos->KeReadStateEvent(&pComRouInfo->RemoveEvent)) {
//	//		bEntry = bEntry->Flink;
//	//		RemoveEntryList(&pComRouInfo->Link);
//	//		fNtos->ExFreePoolWithTag(pComRouInfo, 'Tag');
//	//		continue;
//	//	}
//	//	bEntry = bEntry->Flink;
//	//}
//
//		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s,pWskCompletionRoutine->Flags);
//		//fNtos->KeLowerIrql(APC_LEVEL);
//		if (pWskCompletionRoutine->Flags == 2) {
//			// LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s);
//			_FUNCTION_IMP(ACCEPT_ROUTINE, Ret, pGData, pWskCompletionRoutine->s);
//		}
//		else
//		{
//			_FUNCTION_IMP(RECV_SEND_ROUTINE, Ret, pGData, pWskCompletionRoutine->s, pWskCompletionRoutine->Flags);
//		}
//		//fNtos->KfRaiseIrql(DISPATCH_LEVEL);
//	//PCOMPLETION_ROUTINE_INFO pComRouInfo = pWskCompletionRoutine->pComRouInfo;
//	//fNtos->KeSetEvent(&pComRouInfo->RemoveEvent, IO_NO_INCREMENT, FALSE);
//	return STATUS_MORE_PROCESSING_REQUIRED;
//}
//NTSTATUS IO_COMPLETION_ROUTINE_Ex6(PDEVICE_OBJECT DeviceObject, PIRP Irp, PVOID Context) {
//
//	PWSK_COMPLETION_ROUTINE pWskCompletionRoutine = (PWSK_COMPLETION_ROUTINE)Context;
//
//	Global_Data* pGData = (Global_Data*)pWskCompletionRoutine->pGData;
//	SELF_F_ARRY* fArry = &pGData->SelfFArry;
//	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
//	DWORD64 Ret = 0;  SOCKET s = pWskCompletionRoutine->s;
//	SELF_STRING_ARRY* AArry = &pGData->SelfAArry;
//
//
//	WSK_SERVER_INFO* WskInfo = &pGData->wsk;
//
//	// 移除废掉的内存
//
//
//		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s,pWskCompletionRoutine->Flags);
//	//LIST_ENTRY* pEntry = &WskInfo->_SocketArry[pWskCompletionRoutine->s].CallBackEntry;
//	//LIST_ENTRY* bEntry = pEntry->Flink;
//	//while (bEntry != pEntry) {
//
//	//	PCOMPLETION_ROUTINE_INFO pComRouInfo = (PCOMPLETION_ROUTINE_INFO)bEntry;
//	//	if (fNtos->KeReadStateEvent(&pComRouInfo->RemoveEvent)) {
//	//		bEntry = bEntry->Flink;
//	//		RemoveEntryList(&pComRouInfo->Link);
//	//		fNtos->ExFreePoolWithTag(pComRouInfo, 'Tag');
//	//		continue;
//	//	}
//	//	bEntry = bEntry->Flink;
//	//}
//
//		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s,pWskCompletionRoutine->Flags);
//		//fNtos->KeLowerIrql(APC_LEVEL);
//		if (pWskCompletionRoutine->Flags == 2) {
//			// LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s);
//			_FUNCTION_IMP(ACCEPT_ROUTINE, Ret, pGData, pWskCompletionRoutine->s);
//		}
//		else
//		{
//			_FUNCTION_IMP(RECV_SEND_ROUTINE, Ret, pGData, pWskCompletionRoutine->s, pWskCompletionRoutine->Flags);
//		}
//		//fNtos->KfRaiseIrql(DISPATCH_LEVEL);
//	//PCOMPLETION_ROUTINE_INFO pComRouInfo = pWskCompletionRoutine->pComRouInfo;
//	//fNtos->KeSetEvent(&pComRouInfo->RemoveEvent, IO_NO_INCREMENT, FALSE);
//	return STATUS_MORE_PROCESSING_REQUIRED;
//}
//NTSTATUS IO_COMPLETION_ROUTINE_Ex7(PDEVICE_OBJECT DeviceObject, PIRP Irp, PVOID Context) {
//
//	PWSK_COMPLETION_ROUTINE pWskCompletionRoutine = (PWSK_COMPLETION_ROUTINE)Context;
//
//	Global_Data* pGData = (Global_Data*)pWskCompletionRoutine->pGData;
//	SELF_F_ARRY* fArry = &pGData->SelfFArry;
//	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
//	DWORD64 Ret = 0;  SOCKET s = pWskCompletionRoutine->s;
//	SELF_STRING_ARRY* AArry = &pGData->SelfAArry;
//
//
//	WSK_SERVER_INFO* WskInfo = &pGData->wsk;
//
//	// 移除废掉的内存
//
//
//		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s,pWskCompletionRoutine->Flags);
//	//LIST_ENTRY* pEntry = &WskInfo->_SocketArry[pWskCompletionRoutine->s].CallBackEntry;
//	//LIST_ENTRY* bEntry = pEntry->Flink;
//	//while (bEntry != pEntry) {
//
//	//	PCOMPLETION_ROUTINE_INFO pComRouInfo = (PCOMPLETION_ROUTINE_INFO)bEntry;
//	//	if (fNtos->KeReadStateEvent(&pComRouInfo->RemoveEvent)) {
//	//		bEntry = bEntry->Flink;
//	//		RemoveEntryList(&pComRouInfo->Link);
//	//		fNtos->ExFreePoolWithTag(pComRouInfo, 'Tag');
//	//		continue;
//	//	}
//	//	bEntry = bEntry->Flink;
//	//}
//
//		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s,pWskCompletionRoutine->Flags);
//		//fNtos->KeLowerIrql(APC_LEVEL);
//		if (pWskCompletionRoutine->Flags == 2) {
//			// LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s);
//			_FUNCTION_IMP(ACCEPT_ROUTINE, Ret, pGData, pWskCompletionRoutine->s);
//		}
//		else
//		{
//			_FUNCTION_IMP(RECV_SEND_ROUTINE, Ret, pGData, pWskCompletionRoutine->s, pWskCompletionRoutine->Flags);
//		}
//		//fNtos->KfRaiseIrql(DISPATCH_LEVEL);
//	//PCOMPLETION_ROUTINE_INFO pComRouInfo = pWskCompletionRoutine->pComRouInfo;
//	//fNtos->KeSetEvent(&pComRouInfo->RemoveEvent, IO_NO_INCREMENT, FALSE);
//	return STATUS_MORE_PROCESSING_REQUIRED;
//}
//NTSTATUS IO_COMPLETION_ROUTINE_Ex8(PDEVICE_OBJECT DeviceObject, PIRP Irp, PVOID Context) {
//
//	PWSK_COMPLETION_ROUTINE pWskCompletionRoutine = (PWSK_COMPLETION_ROUTINE)Context;
//
//	Global_Data* pGData = (Global_Data*)pWskCompletionRoutine->pGData;
//	SELF_F_ARRY* fArry = &pGData->SelfFArry;
//	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
//	DWORD64 Ret = 0;  SOCKET s = pWskCompletionRoutine->s;
//	SELF_STRING_ARRY* AArry = &pGData->SelfAArry;
//
//
//	WSK_SERVER_INFO* WskInfo = &pGData->wsk;
//
//	// 移除废掉的内存
//
//
//		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s,pWskCompletionRoutine->Flags);
//	//LIST_ENTRY* pEntry = &WskInfo->_SocketArry[pWskCompletionRoutine->s].CallBackEntry;
//	//LIST_ENTRY* bEntry = pEntry->Flink;
//	//while (bEntry != pEntry) {
//
//	//	PCOMPLETION_ROUTINE_INFO pComRouInfo = (PCOMPLETION_ROUTINE_INFO)bEntry;
//	//	if (fNtos->KeReadStateEvent(&pComRouInfo->RemoveEvent)) {
//	//		bEntry = bEntry->Flink;
//	//		RemoveEntryList(&pComRouInfo->Link);
//	//		fNtos->ExFreePoolWithTag(pComRouInfo, 'Tag');
//	//		continue;
//	//	}
//	//	bEntry = bEntry->Flink;
//	//}
//
//		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s,pWskCompletionRoutine->Flags);
//		//fNtos->KeLowerIrql(APC_LEVEL);
//		if (pWskCompletionRoutine->Flags == 2) {
//			// LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s);
//			_FUNCTION_IMP(ACCEPT_ROUTINE, Ret, pGData, pWskCompletionRoutine->s);
//		}
//		else
//		{
//			_FUNCTION_IMP(RECV_SEND_ROUTINE, Ret, pGData, pWskCompletionRoutine->s, pWskCompletionRoutine->Flags);
//		}
//		//fNtos->KfRaiseIrql(DISPATCH_LEVEL);
//	//PCOMPLETION_ROUTINE_INFO pComRouInfo = pWskCompletionRoutine->pComRouInfo;
//	//fNtos->KeSetEvent(&pComRouInfo->RemoveEvent, IO_NO_INCREMENT, FALSE);
//	return STATUS_MORE_PROCESSING_REQUIRED;
//}
//NTSTATUS IO_COMPLETION_ROUTINE_Ex9(PDEVICE_OBJECT DeviceObject, PIRP Irp, PVOID Context) {
//
//	PWSK_COMPLETION_ROUTINE pWskCompletionRoutine = (PWSK_COMPLETION_ROUTINE)Context;
//
//	Global_Data* pGData = (Global_Data*)pWskCompletionRoutine->pGData;
//	SELF_F_ARRY* fArry = &pGData->SelfFArry;
//	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
//	DWORD64 Ret = 0;  SOCKET s = pWskCompletionRoutine->s;
//	SELF_STRING_ARRY* AArry = &pGData->SelfAArry;
//
//
//	WSK_SERVER_INFO* WskInfo = &pGData->wsk;
//
//	// 移除废掉的内存
//
//
//		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s,pWskCompletionRoutine->Flags);
//	//LIST_ENTRY* pEntry = &WskInfo->_SocketArry[pWskCompletionRoutine->s].CallBackEntry;
//	//LIST_ENTRY* bEntry = pEntry->Flink;
//	//while (bEntry != pEntry) {
//
//	//	PCOMPLETION_ROUTINE_INFO pComRouInfo = (PCOMPLETION_ROUTINE_INFO)bEntry;
//	//	if (fNtos->KeReadStateEvent(&pComRouInfo->RemoveEvent)) {
//	//		bEntry = bEntry->Flink;
//	//		RemoveEntryList(&pComRouInfo->Link);
//	//		fNtos->ExFreePoolWithTag(pComRouInfo, 'Tag');
//	//		continue;
//	//	}
//	//	bEntry = bEntry->Flink;
//	//}
//
//		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s,pWskCompletionRoutine->Flags);
//		//fNtos->KeLowerIrql(APC_LEVEL);
//		if (pWskCompletionRoutine->Flags == 2) {
//			// LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s);
//			_FUNCTION_IMP(ACCEPT_ROUTINE, Ret, pGData, pWskCompletionRoutine->s);
//		}
//		else
//		{
//			_FUNCTION_IMP(RECV_SEND_ROUTINE, Ret, pGData, pWskCompletionRoutine->s, pWskCompletionRoutine->Flags);
//		}
//		//fNtos->KfRaiseIrql(DISPATCH_LEVEL);
//	//PCOMPLETION_ROUTINE_INFO pComRouInfo = pWskCompletionRoutine->pComRouInfo;
//	//fNtos->KeSetEvent(&pComRouInfo->RemoveEvent, IO_NO_INCREMENT, FALSE);
//	return STATUS_MORE_PROCESSING_REQUIRED;
//}
//NTSTATUS IO_COMPLETION_ROUTINE_Ex10(PDEVICE_OBJECT DeviceObject, PIRP Irp, PVOID Context) {
//
//	PWSK_COMPLETION_ROUTINE pWskCompletionRoutine = (PWSK_COMPLETION_ROUTINE)Context;
//
//	Global_Data* pGData = (Global_Data*)pWskCompletionRoutine->pGData;
//	SELF_F_ARRY* fArry = &pGData->SelfFArry;
//	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
//	DWORD64 Ret = 0;  SOCKET s = pWskCompletionRoutine->s;
//	SELF_STRING_ARRY* AArry = &pGData->SelfAArry;
//
//
//	WSK_SERVER_INFO* WskInfo = &pGData->wsk;
//
//	// 移除废掉的内存
//
//
//		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s,pWskCompletionRoutine->Flags);
//	//LIST_ENTRY* pEntry = &WskInfo->_SocketArry[pWskCompletionRoutine->s].CallBackEntry;
//	//LIST_ENTRY* bEntry = pEntry->Flink;
//	//while (bEntry != pEntry) {
//
//	//	PCOMPLETION_ROUTINE_INFO pComRouInfo = (PCOMPLETION_ROUTINE_INFO)bEntry;
//	//	if (fNtos->KeReadStateEvent(&pComRouInfo->RemoveEvent)) {
//	//		bEntry = bEntry->Flink;
//	//		RemoveEntryList(&pComRouInfo->Link);
//	//		fNtos->ExFreePoolWithTag(pComRouInfo, 'Tag');
//	//		continue;
//	//	}
//	//	bEntry = bEntry->Flink;
//	//}
//
//		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s,pWskCompletionRoutine->Flags);
//		//fNtos->KeLowerIrql(APC_LEVEL);
//		if (pWskCompletionRoutine->Flags == 2) {
//			// LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s);
//			_FUNCTION_IMP(ACCEPT_ROUTINE, Ret, pGData, pWskCompletionRoutine->s);
//		}
//		else
//		{
//			_FUNCTION_IMP(RECV_SEND_ROUTINE, Ret, pGData, pWskCompletionRoutine->s, pWskCompletionRoutine->Flags);
//		}
//		//fNtos->KfRaiseIrql(DISPATCH_LEVEL);
//	//PCOMPLETION_ROUTINE_INFO pComRouInfo = pWskCompletionRoutine->pComRouInfo;
//	//fNtos->KeSetEvent(&pComRouInfo->RemoveEvent, IO_NO_INCREMENT, FALSE);
//	return STATUS_MORE_PROCESSING_REQUIRED;
//}
//NTSTATUS IO_COMPLETION_ROUTINE_Ex11(PDEVICE_OBJECT DeviceObject, PIRP Irp, PVOID Context) {
//
//	PWSK_COMPLETION_ROUTINE pWskCompletionRoutine = (PWSK_COMPLETION_ROUTINE)Context;
//
//	Global_Data* pGData = (Global_Data*)pWskCompletionRoutine->pGData;
//	SELF_F_ARRY* fArry = &pGData->SelfFArry;
//	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
//	DWORD64 Ret = 0;  SOCKET s = pWskCompletionRoutine->s;
//	SELF_STRING_ARRY* AArry = &pGData->SelfAArry;
//
//
//	WSK_SERVER_INFO* WskInfo = &pGData->wsk;
//
//	// 移除废掉的内存
//
//
//		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s,pWskCompletionRoutine->Flags);
//	//LIST_ENTRY* pEntry = &WskInfo->_SocketArry[pWskCompletionRoutine->s].CallBackEntry;
//	//LIST_ENTRY* bEntry = pEntry->Flink;
//	//while (bEntry != pEntry) {
//
//	//	PCOMPLETION_ROUTINE_INFO pComRouInfo = (PCOMPLETION_ROUTINE_INFO)bEntry;
//	//	if (fNtos->KeReadStateEvent(&pComRouInfo->RemoveEvent)) {
//	//		bEntry = bEntry->Flink;
//	//		RemoveEntryList(&pComRouInfo->Link);
//	//		fNtos->ExFreePoolWithTag(pComRouInfo, 'Tag');
//	//		continue;
//	//	}
//	//	bEntry = bEntry->Flink;
//	//}
//
//		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s,pWskCompletionRoutine->Flags);
//		//LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, pWskCompletionRoutine->Flags);
//		//fNtos->KeLowerIrql(APC_LEVEL);
//		if (pWskCompletionRoutine->Flags == 2) {
//			// LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s);
//			_FUNCTION_IMP(ACCEPT_ROUTINE, Ret, pGData, pWskCompletionRoutine->s);
//		}
//		else
//		{
//			_FUNCTION_IMP(RECV_SEND_ROUTINE, Ret, pGData, pWskCompletionRoutine->s, pWskCompletionRoutine->Flags);
//		}
//		//fNtos->KfRaiseIrql(DISPATCH_LEVEL);
//	//PCOMPLETION_ROUTINE_INFO pComRouInfo = pWskCompletionRoutine->pComRouInfo;
//	//fNtos->KeSetEvent(&pComRouInfo->RemoveEvent, IO_NO_INCREMENT, FALSE);
//	return STATUS_MORE_PROCESSING_REQUIRED;
//}
//NTSTATUS IO_COMPLETION_ROUTINE_Ex12(PDEVICE_OBJECT DeviceObject, PIRP Irp, PVOID Context) {
//
//	PWSK_COMPLETION_ROUTINE pWskCompletionRoutine = (PWSK_COMPLETION_ROUTINE)Context;
//
//	Global_Data* pGData = (Global_Data*)pWskCompletionRoutine->pGData;
//	SELF_F_ARRY* fArry = &pGData->SelfFArry;
//	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
//	DWORD64 Ret = 0;  SOCKET s = pWskCompletionRoutine->s;
//	SELF_STRING_ARRY* AArry = &pGData->SelfAArry;
//
//
//	WSK_SERVER_INFO* WskInfo = &pGData->wsk;
//
//	// 移除废掉的内存
//
//
//		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s,pWskCompletionRoutine->Flags);
//	//LIST_ENTRY* pEntry = &WskInfo->_SocketArry[pWskCompletionRoutine->s].CallBackEntry;
//	//LIST_ENTRY* bEntry = pEntry->Flink;
//	//while (bEntry != pEntry) {
//
//	//	PCOMPLETION_ROUTINE_INFO pComRouInfo = (PCOMPLETION_ROUTINE_INFO)bEntry;
//	//	if (fNtos->KeReadStateEvent(&pComRouInfo->RemoveEvent)) {
//	//		bEntry = bEntry->Flink;
//	//		RemoveEntryList(&pComRouInfo->Link);
//	//		fNtos->ExFreePoolWithTag(pComRouInfo, 'Tag');
//	//		continue;
//	//	}
//	//	bEntry = bEntry->Flink;
//	//}
//
//		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s, pWskCompletionRoutine->Flags);
//		//fNtos->KeLowerIrql(APC_LEVEL);
//		if (pWskCompletionRoutine->Flags == 2) {
//			// LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s);
//			_FUNCTION_IMP(ACCEPT_ROUTINE, Ret, pGData, pWskCompletionRoutine->s);
//		}
//		else
//		{
//			_FUNCTION_IMP(RECV_SEND_ROUTINE, Ret, pGData, pWskCompletionRoutine->s, pWskCompletionRoutine->Flags);
//		}
//		//fNtos->KfRaiseIrql(DISPATCH_LEVEL);
//	//PCOMPLETION_ROUTINE_INFO pComRouInfo = pWskCompletionRoutine->pComRouInfo;
//	//fNtos->KeSetEvent(&pComRouInfo->RemoveEvent, IO_NO_INCREMENT, FALSE);
//	return STATUS_MORE_PROCESSING_REQUIRED;
//}
//NTSTATUS IO_COMPLETION_ROUTINE_Ex13(PDEVICE_OBJECT DeviceObject, PIRP Irp, PVOID Context) {
//
//	PWSK_COMPLETION_ROUTINE pWskCompletionRoutine = (PWSK_COMPLETION_ROUTINE)Context;
//
//	Global_Data* pGData = (Global_Data*)pWskCompletionRoutine->pGData;
//	SELF_F_ARRY* fArry = &pGData->SelfFArry;
//	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
//	DWORD64 Ret = 0;  SOCKET s = pWskCompletionRoutine->s;
//	SELF_STRING_ARRY* AArry = &pGData->SelfAArry;
//
//
//	WSK_SERVER_INFO* WskInfo = &pGData->wsk;
//
//	// 移除废掉的内存
//
//
//		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s,pWskCompletionRoutine->Flags);
//	//LIST_ENTRY* pEntry = &WskInfo->_SocketArry[pWskCompletionRoutine->s].CallBackEntry;
//	//LIST_ENTRY* bEntry = pEntry->Flink;
//	//while (bEntry != pEntry) {
//
//	//	PCOMPLETION_ROUTINE_INFO pComRouInfo = (PCOMPLETION_ROUTINE_INFO)bEntry;
//	//	if (fNtos->KeReadStateEvent(&pComRouInfo->RemoveEvent)) {
//	//		bEntry = bEntry->Flink;
//	//		RemoveEntryList(&pComRouInfo->Link);
//	//		fNtos->ExFreePoolWithTag(pComRouInfo, 'Tag');
//	//		continue;
//	//	}
//	//	bEntry = bEntry->Flink;
//	//}
//	LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s,pWskCompletionRoutine->Flags);
//	//fNtos->KeLowerIrql(APC_LEVEL);
//	if (pWskCompletionRoutine->Flags == 2) {
//		// LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s);
//		_FUNCTION_IMP(ACCEPT_ROUTINE, Ret, pGData, pWskCompletionRoutine->s);
//	}
//	else
//	{
//		_FUNCTION_IMP(RECV_SEND_ROUTINE, Ret, pGData, pWskCompletionRoutine->s, pWskCompletionRoutine->Flags);
//	}
//	//fNtos->KfRaiseIrql(DISPATCH_LEVEL);
//	//PCOMPLETION_ROUTINE_INFO pComRouInfo = pWskCompletionRoutine->pComRouInfo;
//	//fNtos->KeSetEvent(&pComRouInfo->RemoveEvent, IO_NO_INCREMENT, FALSE);
//	return STATUS_MORE_PROCESSING_REQUIRED;
//}
//NTSTATUS IO_COMPLETION_ROUTINE_Ex14(PDEVICE_OBJECT DeviceObject, PIRP Irp, PVOID Context) {
//
//	PWSK_COMPLETION_ROUTINE pWskCompletionRoutine = (PWSK_COMPLETION_ROUTINE)Context;
//
//	Global_Data* pGData = (Global_Data*)pWskCompletionRoutine->pGData;
//	SELF_F_ARRY* fArry = &pGData->SelfFArry;
//	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
//	DWORD64 Ret = 0;  SOCKET s = pWskCompletionRoutine->s;
//	SELF_STRING_ARRY* AArry = &pGData->SelfAArry;
//
//
//	WSK_SERVER_INFO* WskInfo = &pGData->wsk;
//
//	// 移除废掉的内存
//
//
//		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s,pWskCompletionRoutine->Flags);
//	//LIST_ENTRY* pEntry = &WskInfo->_SocketArry[pWskCompletionRoutine->s].CallBackEntry;
//	//LIST_ENTRY* bEntry = pEntry->Flink;
//	//while (bEntry != pEntry) {
//
//	//	PCOMPLETION_ROUTINE_INFO pComRouInfo = (PCOMPLETION_ROUTINE_INFO)bEntry;
//	//	if (fNtos->KeReadStateEvent(&pComRouInfo->RemoveEvent)) {
//	//		bEntry = bEntry->Flink;
//	//		RemoveEntryList(&pComRouInfo->Link);
//	//		fNtos->ExFreePoolWithTag(pComRouInfo, 'Tag');
//	//		continue;
//	//	}
//	//	bEntry = bEntry->Flink;
//	//}
//
//	LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s,pWskCompletionRoutine->Flags);
//	//fNtos->KeLowerIrql(APC_LEVEL);
//	if (pWskCompletionRoutine->Flags == 2) {
//		// LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s);
//		_FUNCTION_IMP(ACCEPT_ROUTINE, Ret, pGData, pWskCompletionRoutine->s);
//	}
//	else
//	{
//		_FUNCTION_IMP(RECV_SEND_ROUTINE, Ret, pGData, pWskCompletionRoutine->s, pWskCompletionRoutine->Flags);
//	}
//	//fNtos->KfRaiseIrql(DISPATCH_LEVEL);
//	//PCOMPLETION_ROUTINE_INFO pComRouInfo = pWskCompletionRoutine->pComRouInfo;
//	//fNtos->KeSetEvent(&pComRouInfo->RemoveEvent, IO_NO_INCREMENT, FALSE);
//	return STATUS_MORE_PROCESSING_REQUIRED;
//}
//NTSTATUS IO_COMPLETION_ROUTINE_Ex15(PDEVICE_OBJECT DeviceObject, PIRP Irp, PVOID Context) {
//
//	PWSK_COMPLETION_ROUTINE pWskCompletionRoutine = (PWSK_COMPLETION_ROUTINE)Context;
//
//	Global_Data* pGData = (Global_Data*)pWskCompletionRoutine->pGData;
//	SELF_F_ARRY* fArry = &pGData->SelfFArry;
//	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
//	DWORD64 Ret = 0;  SOCKET s = pWskCompletionRoutine->s;
//	SELF_STRING_ARRY* AArry = &pGData->SelfAArry;
//
//
//	WSK_SERVER_INFO* WskInfo = &pGData->wsk;
//
//	// 移除废掉的内存
//
//
//		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s,pWskCompletionRoutine->Flags);
//	//LIST_ENTRY* pEntry = &WskInfo->_SocketArry[pWskCompletionRoutine->s].CallBackEntry;
//	//LIST_ENTRY* bEntry = pEntry->Flink;
//	//while (bEntry != pEntry) {
//
//	//	PCOMPLETION_ROUTINE_INFO pComRouInfo = (PCOMPLETION_ROUTINE_INFO)bEntry;
//	//	if (fNtos->KeReadStateEvent(&pComRouInfo->RemoveEvent)) {
//	//		bEntry = bEntry->Flink;
//	//		RemoveEntryList(&pComRouInfo->Link);
//	//		fNtos->ExFreePoolWithTag(pComRouInfo, 'Tag');
//	//		continue;
//	//	}
//	//	bEntry = bEntry->Flink;
//	//}
//
//		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s,pWskCompletionRoutine->Flags);
//		//fNtos->KeLowerIrql(APC_LEVEL);
//		if (pWskCompletionRoutine->Flags == 2) {
//			// LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s);
//			_FUNCTION_IMP(ACCEPT_ROUTINE, Ret, pGData, pWskCompletionRoutine->s);
//		}
//		else
//		{
//			_FUNCTION_IMP(RECV_SEND_ROUTINE, Ret, pGData, pWskCompletionRoutine->s, pWskCompletionRoutine->Flags);
//		}
//		//fNtos->KfRaiseIrql(DISPATCH_LEVEL);
//	//PCOMPLETION_ROUTINE_INFO pComRouInfo = pWskCompletionRoutine->pComRouInfo;
//	//fNtos->KeSetEvent(&pComRouInfo->RemoveEvent, IO_NO_INCREMENT, FALSE);
//	return STATUS_MORE_PROCESSING_REQUIRED;
//}
//NTSTATUS IO_COMPLETION_ROUTINE_Ex16(PDEVICE_OBJECT DeviceObject, PIRP Irp, PVOID Context) {
//
//	PWSK_COMPLETION_ROUTINE pWskCompletionRoutine = (PWSK_COMPLETION_ROUTINE)Context;
//
//	Global_Data* pGData = (Global_Data*)pWskCompletionRoutine->pGData;
//	SELF_F_ARRY* fArry = &pGData->SelfFArry;
//	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
//	DWORD64 Ret = 0;  SOCKET s = pWskCompletionRoutine->s;
//	SELF_STRING_ARRY* AArry = &pGData->SelfAArry;
//
//
//	WSK_SERVER_INFO* WskInfo = &pGData->wsk;
//
//	// 移除废掉的内存
//
//
//		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s,pWskCompletionRoutine->Flags);
//	//LIST_ENTRY* pEntry = &WskInfo->_SocketArry[pWskCompletionRoutine->s].CallBackEntry;
//	//LIST_ENTRY* bEntry = pEntry->Flink;
//	//while (bEntry != pEntry) {
//
//	//	PCOMPLETION_ROUTINE_INFO pComRouInfo = (PCOMPLETION_ROUTINE_INFO)bEntry;
//	//	if (fNtos->KeReadStateEvent(&pComRouInfo->RemoveEvent)) {
//	//		bEntry = bEntry->Flink;
//	//		RemoveEntryList(&pComRouInfo->Link);
//	//		fNtos->ExFreePoolWithTag(pComRouInfo, 'Tag');
//	//		continue;
//	//	}
//	//	bEntry = bEntry->Flink;
//	//}
//
//		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s,pWskCompletionRoutine->Flags);
//		//fNtos->KeLowerIrql(APC_LEVEL);
//		if (pWskCompletionRoutine->Flags == 2) {
//			// LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s);
//			_FUNCTION_IMP(ACCEPT_ROUTINE, Ret, pGData, pWskCompletionRoutine->s);
//		}
//		else
//		{
//			_FUNCTION_IMP(RECV_SEND_ROUTINE, Ret, pGData, pWskCompletionRoutine->s, pWskCompletionRoutine->Flags);
//		}
//		//fNtos->KfRaiseIrql(DISPATCH_LEVEL);
//	//PCOMPLETION_ROUTINE_INFO pComRouInfo = pWskCompletionRoutine->pComRouInfo;
//	//fNtos->KeSetEvent(&pComRouInfo->RemoveEvent, IO_NO_INCREMENT, FALSE);
//	return STATUS_MORE_PROCESSING_REQUIRED;
//}
//NTSTATUS IO_COMPLETION_ROUTINE_Ex17(PDEVICE_OBJECT DeviceObject, PIRP Irp, PVOID Context) {
//
//	PWSK_COMPLETION_ROUTINE pWskCompletionRoutine = (PWSK_COMPLETION_ROUTINE)Context;
//
//	Global_Data* pGData = (Global_Data*)pWskCompletionRoutine->pGData;
//	SELF_F_ARRY* fArry = &pGData->SelfFArry;
//	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
//	DWORD64 Ret = 0;  SOCKET s = pWskCompletionRoutine->s;
//	SELF_STRING_ARRY* AArry = &pGData->SelfAArry;
//
//
//	WSK_SERVER_INFO* WskInfo = &pGData->wsk;
//
//	// 移除废掉的内存
//
//
//		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s,pWskCompletionRoutine->Flags);
//	//LIST_ENTRY* pEntry = &WskInfo->_SocketArry[pWskCompletionRoutine->s].CallBackEntry;
//	//LIST_ENTRY* bEntry = pEntry->Flink;
//	//while (bEntry != pEntry) {
//
//	//	PCOMPLETION_ROUTINE_INFO pComRouInfo = (PCOMPLETION_ROUTINE_INFO)bEntry;
//	//	if (fNtos->KeReadStateEvent(&pComRouInfo->RemoveEvent)) {
//	//		bEntry = bEntry->Flink;
//	//		RemoveEntryList(&pComRouInfo->Link);
//	//		fNtos->ExFreePoolWithTag(pComRouInfo, 'Tag');
//	//		continue;
//	//	}
//	//	bEntry = bEntry->Flink;
//	//}
//
//		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s,pWskCompletionRoutine->Flags);
//		//fNtos->KeLowerIrql(APC_LEVEL);
//		if (pWskCompletionRoutine->Flags == 2) {
//			// LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s);
//			_FUNCTION_IMP(ACCEPT_ROUTINE, Ret, pGData, pWskCompletionRoutine->s);
//		}
//		else
//		{
//			_FUNCTION_IMP(RECV_SEND_ROUTINE, Ret, pGData, pWskCompletionRoutine->s, pWskCompletionRoutine->Flags);
//		}
//		//fNtos->KfRaiseIrql(DISPATCH_LEVEL);
//	//PCOMPLETION_ROUTINE_INFO pComRouInfo = pWskCompletionRoutine->pComRouInfo;
//	//fNtos->KeSetEvent(&pComRouInfo->RemoveEvent, IO_NO_INCREMENT, FALSE);
//	return STATUS_MORE_PROCESSING_REQUIRED;
//}
//NTSTATUS IO_COMPLETION_ROUTINE_Ex18(PDEVICE_OBJECT DeviceObject, PIRP Irp, PVOID Context) {
//
//	PWSK_COMPLETION_ROUTINE pWskCompletionRoutine = (PWSK_COMPLETION_ROUTINE)Context;
//
//	Global_Data* pGData = (Global_Data*)pWskCompletionRoutine->pGData;
//	SELF_F_ARRY* fArry = &pGData->SelfFArry;
//	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
//	DWORD64 Ret = 0;  SOCKET s = pWskCompletionRoutine->s;
//	SELF_STRING_ARRY* AArry = &pGData->SelfAArry;
//
//
//	WSK_SERVER_INFO* WskInfo = &pGData->wsk;
//
//	// 移除废掉的内存
//
//
//		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s,pWskCompletionRoutine->Flags);
//	//LIST_ENTRY* pEntry = &WskInfo->_SocketArry[pWskCompletionRoutine->s].CallBackEntry;
//	//LIST_ENTRY* bEntry = pEntry->Flink;
//	//while (bEntry != pEntry) {
//
//	//	PCOMPLETION_ROUTINE_INFO pComRouInfo = (PCOMPLETION_ROUTINE_INFO)bEntry;
//	//	if (fNtos->KeReadStateEvent(&pComRouInfo->RemoveEvent)) {
//	//		bEntry = bEntry->Flink;
//	//		RemoveEntryList(&pComRouInfo->Link);
//	//		fNtos->ExFreePoolWithTag(pComRouInfo, 'Tag');
//	//		continue;
//	//	}
//	//	bEntry = bEntry->Flink;
//	//}
//
//		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s,pWskCompletionRoutine->Flags);
//		//fNtos->KeLowerIrql(APC_LEVEL);
//		if (pWskCompletionRoutine->Flags == 2) {
//			// LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s);
//			_FUNCTION_IMP(ACCEPT_ROUTINE, Ret, pGData, pWskCompletionRoutine->s);
//		}
//		else
//		{
//			_FUNCTION_IMP(RECV_SEND_ROUTINE, Ret, pGData, pWskCompletionRoutine->s, pWskCompletionRoutine->Flags);
//		}
//		//fNtos->KfRaiseIrql(DISPATCH_LEVEL);
//	//PCOMPLETION_ROUTINE_INFO pComRouInfo = pWskCompletionRoutine->pComRouInfo;
//	//fNtos->KeSetEvent(&pComRouInfo->RemoveEvent, IO_NO_INCREMENT, FALSE);
//	return STATUS_MORE_PROCESSING_REQUIRED;
//}
//NTSTATUS IO_COMPLETION_ROUTINE_Ex19(PDEVICE_OBJECT DeviceObject, PIRP Irp, PVOID Context) {
//
//	PWSK_COMPLETION_ROUTINE pWskCompletionRoutine = (PWSK_COMPLETION_ROUTINE)Context;
//
//	Global_Data* pGData = (Global_Data*)pWskCompletionRoutine->pGData;
//	SELF_F_ARRY* fArry = &pGData->SelfFArry;
//	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
//	DWORD64 Ret = 0;  SOCKET s = pWskCompletionRoutine->s;
//	SELF_STRING_ARRY* AArry = &pGData->SelfAArry;
//
//
//	WSK_SERVER_INFO* WskInfo = &pGData->wsk;
//
//	// 移除废掉的内存
//
//
//	LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s,pWskCompletionRoutine->Flags);
//	//LIST_ENTRY* pEntry = &WskInfo->_SocketArry[pWskCompletionRoutine->s].CallBackEntry;
//	//LIST_ENTRY* bEntry = pEntry->Flink;
//	//while (bEntry != pEntry) {
//
//	//	PCOMPLETION_ROUTINE_INFO pComRouInfo = (PCOMPLETION_ROUTINE_INFO)bEntry;
//	//	if (fNtos->KeReadStateEvent(&pComRouInfo->RemoveEvent)) {
//	//		bEntry = bEntry->Flink;
//	//		RemoveEntryList(&pComRouInfo->Link);
//	//		fNtos->ExFreePoolWithTag(pComRouInfo, 'Tag');
//	//		continue;
//	//	}
//	//	bEntry = bEntry->Flink;
//	//}
//
//		LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s,pWskCompletionRoutine->Flags);
//		////fNtos->KeLowerIrql(APC_LEVEL);
//		if (pWskCompletionRoutine->Flags == 2) {
//			// LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, pGData, pWskCompletionRoutine->s);
//			_FUNCTION_IMP(ACCEPT_ROUTINE, Ret, pGData, pWskCompletionRoutine->s);
//		}
//		else
//		{
//			_FUNCTION_IMP(RECV_SEND_ROUTINE, Ret, pGData, pWskCompletionRoutine->s, pWskCompletionRoutine->Flags);
//		}
//		////fNtos->KfRaiseIrql(DISPATCH_LEVEL);
//	//PCOMPLETION_ROUTINE_INFO pComRouInfo = pWskCompletionRoutine->pComRouInfo;
//	//fNtos->KeSetEvent(&pComRouInfo->RemoveEvent, IO_NO_INCREMENT, FALSE);
//	return STATUS_MORE_PROCESSING_REQUIRED;
//}





FORCEINLINE
BOOLEAN ChangePageEntryList(PVOID _pGData, SOCKET s, CODE_CALL* pCodeCall, MEMORY_FLAGS* MMFlags, PLIST_ENTRY HeadEntry, PLIST_ENTRY NowEntry, BOOLEAN Flags) {

	//KeAcquireSpinLockAtDpcLevel
	Global_Data* pGData = (Global_Data*)_pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	SOCKET_INFO* pSocket = &pGData->wsk._SocketArry[s];
	KIRQL irql = fNtos->KeAcquireSpinLockRaiseToDpc(&pSocket->MemoryLock);
	if (Flags == 1) {
		InsertHeadList(HeadEntry, NowEntry);
	}
	else if(Flags == 0){

		LIST_ENTRY* pNext = HeadEntry->Blink;

		while (pNext != HeadEntry) {

			Memory_Exe_Info* pMemory = (Memory_Exe_Info*)pNext;
			if (pMemory->nPageSize >= pCodeCall->nPageSize) {
				MMFlags->MemoryExePtr = pMemory;
				MMFlags->Ptr = pMemory->Ptr;
				RemoveEntryList(pNext);
				break;
			}
			pNext = pNext->Blink;
		}
	}
	fNtos->KeReleaseSpinLock(&pSocket->MemoryLock, irql);
	return TRUE;
}


__forceinline void  _ExAllocateFunctionMemoryDpc(PVOID _pGData, SOCKET s, CODE_CALL* pCodeCall, MEMORY_FLAGS * MMFlags) {
	Global_Data* pGData = (Global_Data*)_pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	SOCKET_INFO* pSocket = &pGData->wsk._SocketArry[s];

	SELF_STRING_ARRY* AArry = &pGData->SelfAArry;

	//fNtos->DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL, AArry->Line_Ptr_DWORD.Ptr, __LINE__, MMFlags->Ptr, 0);


	//POOL_FLAG_NON_PAGED

	//ExAllocatePoolWithTag(NonPagedPoolExecute)

	ChangePageEntryList(_pGData, s, pCodeCall, MMFlags, &pSocket->DpcMemory, 0, 0);
	if (MMFlags->Ptr == 0) {
		PHYSICAL_ADDRESS Low = { 0 };
		PHYSICAL_ADDRESS High = { MAXULONG64 };
		
		//ExAllocatePool2
		//KIRQL oldIrql = fNtos->KfRaiseIrql(DISPATCH_LEVEL);
		do {
			MMFlags->Ptr = fNtos->MmAllocateContiguousMemorySpecifyCache(pCodeCall->nPageSize, Low, High, Low, MmNonCached);
		} while (MMFlags->Ptr == 0);
		//fNtos->KeLowerIrql(oldIrql);
		//fNtos->DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL, AArry->Line_Ptr_DWORD.Ptr,__LINE__, MMFlags->Ptr, 0);
	}
}

__forceinline void  _ExAllocateFunctionMemoryApc(PVOID _pGData, SOCKET s, CODE_CALL* pCodeCall, MEMORY_FLAGS* MMFlags) {
	Global_Data* pGData = (Global_Data*)_pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	SOCKET_INFO* pSocket = &pGData->wsk._SocketArry[s];
	SELF_STRING_ARRY* AArry = &pGData->SelfAArry;

	ChangePageEntryList(_pGData, s, pCodeCall, MMFlags, &pSocket->ApcMemory, 0, 0);

	if (MMFlags->Ptr == 0) {
		do {
			MMFlags->Ptr = fNtos->MmAllocateNonCachedMemory(pCodeCall->nPageSize); 
		} while (MMFlags->Ptr == 0);
	}
}

MEMORY_FLAGS ExAllocateFunctionMemory0(PVOID _pGData, SOCKET s, CODE_CALL* pCodeCall) {

	Global_Data* pGData = (Global_Data*)_pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	MEMORY_FLAGS MemoryFlags; fNtos->memset(&MemoryFlags, 0, sizeof(MemoryFlags));
	MemoryFlags.Flags = KeGetCurrentIrql();
	MemoryFlags.Size = pCodeCall->nPageSize;
	SOCKET_INFO* pSocket = &pGData->wsk._SocketArry[s];
	SELF_STRING_ARRY* AArry = &pGData->SelfAArry;



	pGData->sTime = fNtos->KeQueryPerformanceCounter(0);
	LOG_DEBUG_TIME(AArry->Line_Ptr_DWORD.Ptr, __LINE__, pGData->sTime.QuadPart, pGData->sTime.QuadPart - pGData->KTime.QuadPart);
	pGData->KTime = fNtos->KeQueryPerformanceCounter(0);
	MemoryFlags.Flags = 2;
	if (MemoryFlags.Flags == 2) {
		_ExAllocateFunctionMemoryDpc(_pGData, s, pCodeCall, &MemoryFlags);
	}
	else
	{
		_ExAllocateFunctionMemoryApc(_pGData, s, pCodeCall, &MemoryFlags);
	}
	KIRQL OldIrql = KeGetCurrentIrql();
	if (OldIrql > APC_LEVEL)fNtos->KeLowerIrql(APC_LEVEL);
	
	pGData->sTime = fNtos->KeQueryPerformanceCounter(0);
	LOG_DEBUG_TIME(AArry->Line_Ptr_DWORD.Ptr, __LINE__, pGData->sTime.QuadPart, pGData->sTime.QuadPart - pGData->KTime.QuadPart);
	pGData->KTime = fNtos->KeQueryPerformanceCounter(0);
	LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, MemoryFlags.Ptr, 0);
	MemoryFlags.ExePtr = MemoryFlags.Ptr;
	fNtos->CopyMemory(MemoryFlags.ExePtr, pCodeCall->Ptr, pCodeCall->MaxSize);
	pGData->_hEncrypt_DEC_V.SelfTradition(pGData, pCodeCall->Sgin, MemoryFlags.ExePtr, pCodeCall->MaxSize);
	MMPTE* pMmpte = 0;
	GetAddressPfn((DWORD64)MemoryFlags.ExePtr, pGData->PTE_BASE, pMmpte);
	if (KeGetCurrentIrql() < OldIrql) fNtos->KfRaiseIrql(OldIrql);
	if (pMmpte != 0) {
		MMPTE NewPte; NewPte.u.Long = 0x0A00000000000139;
		NewPte.u.Hard.PageFrameNumber = pMmpte->u.Hard.PageFrameNumber;
		*pMmpte = NewPte;
		__invlpg(pMmpte); 
		MemoryFlags.pMpte = pMmpte;
	}
	LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD.Ptr, __LINE__, MemoryFlags.Ptr, 0);

	pGData->sTime = fNtos->KeQueryPerformanceCounter(0);
	LOG_DEBUG_TIME(AArry->Line_Ptr_DWORD.Ptr, __LINE__, pGData->sTime.QuadPart, pGData->sTime.QuadPart - pGData->KTime.QuadPart);
	pGData->KTime = fNtos->KeQueryPerformanceCounter(0);
	return MemoryFlags;
}





#define ExAllocateFunctionMemoryFun(x) MEMORY_FLAGS ExAllocateFunctionMemory##x(PVOID _pGData, SOCKET s, CODE_CALL* pCodeCall) {\
	Global_Data* pGData = (Global_Data*)_pGData;\
NTOSKRNL_FUN* fNtos = &pGData->fNtos;\
MEMORY_FLAGS MemoryFlags; fNtos->memset(&MemoryFlags, 0, sizeof(MemoryFlags));\
MemoryFlags.Flags = KeGetCurrentIrql();\
MemoryFlags.Size = pCodeCall->nPageSize;\
SOCKET_INFO* pSocket = &pGData->wsk._SocketArry[s];\
SELF_STRING_ARRY* AArry = &pGData->SelfAArry;\
MemoryFlags.Flags = 2;\
if (MemoryFlags.Flags == 2) {\
	_ExAllocateFunctionMemoryDpc(_pGData, s, pCodeCall, &MemoryFlags);\
}\
else\
{\
	_ExAllocateFunctionMemoryApc(_pGData, s, pCodeCall, &MemoryFlags);\
}\
MemoryFlags.ExePtr = MemoryFlags.Ptr;\
fNtos->CopyMemory(MemoryFlags.ExePtr, pCodeCall->Ptr, pCodeCall->MaxSize);\
pGData->_hEncrypt_DEC_V.SelfTradition(pGData, pCodeCall->Sgin, MemoryFlags.ExePtr, pCodeCall->MaxSize);\
MMPTE* pMmpte = 0;\
GetAddressPfn((DWORD64)MemoryFlags.ExePtr, pGData->PTE_BASE, pMmpte);\
if (pMmpte != 0) {\
	MMPTE NewPte; NewPte.u.Long = 0x0A00000000000139;\
	NewPte.u.Hard.PageFrameNumber = pMmpte->u.Hard.PageFrameNumber;\
	*pMmpte = NewPte;\
	__invlpg(pMmpte); MemoryFlags.pMpte = pMmpte;\
}\
return MemoryFlags;\
}\

//KIRQL OldIrql = KeGetCurrentIrql(); \
//if (OldIrql > APC_LEVEL)fNtos->KeLowerIrql(APC_LEVEL); 
// fNtos->KfRaiseIrql(OldIrql);

ExAllocateFunctionMemoryFun(1)
ExAllocateFunctionMemoryFun(2)
ExAllocateFunctionMemoryFun(3)
ExAllocateFunctionMemoryFun(4)
ExAllocateFunctionMemoryFun(5)
ExAllocateFunctionMemoryFun(6)
ExAllocateFunctionMemoryFun(7)
ExAllocateFunctionMemoryFun(8)
ExAllocateFunctionMemoryFun(9)
ExAllocateFunctionMemoryFun(10)
ExAllocateFunctionMemoryFun(11)
ExAllocateFunctionMemoryFun(12)
ExAllocateFunctionMemoryFun(13)
ExAllocateFunctionMemoryFun(14)
ExAllocateFunctionMemoryFun(15)
ExAllocateFunctionMemoryFun(16)
ExAllocateFunctionMemoryFun(17)
ExAllocateFunctionMemoryFun(18)
ExAllocateFunctionMemoryFun(19)


//#define ExAllocateFunctionMemoryFun(x) MEMORY_FLAGS ExAllocateFunctionMemory##x(PVOID _pGData, SOCKET s, CODE_CALL* pCodeCall){\
//          	Global_Data* pGData = (Global_Data*)_pGData;\
//            NTOSKRNL_FUN* fNtos = &pGData->fNtos;\
//            MEMORY_FLAGS MemoryFlags; MemoryFlags.MemoryExePtr = 0;\
//            MemoryFlags.Flags = KeGetCurrentIrql();\
//            MemoryFlags.Size = pCodeCall->nPageSize;\
//            PVOID Ptr = 0;\
//            SOCKET_INFO* pSocket = &pGData->wsk._SocketArry[s];\
//            LIST_ENTRY* pNext = pSocket->DpcMemory.Blink;\
//do\
//{\
//	if (pNext == &pSocket->DpcMemory) {\
//		break;\
//	}\
//	Memory_Exe_Info* pMemory = (Memory_Exe_Info*)pNext;\
//	if (pMemory->nPageSize >= pCodeCall->nPageSize) {\
//		Ptr = pMemory->Ptr;\
//		MemoryFlags.MemoryExePtr = pMemory;\
//		ChangeEntryList(pGData, s, pNext, pNext, 0);\
//		break;\
//	}\
//	pNext = pNext->Blink;\
//} while (pNext != &pSocket->DpcMemory);\
//if (Ptr == 0)\
//{\
//	PHYSICAL_ADDRESS Low = { 0 };\
//	PHYSICAL_ADDRESS High = { MAXULONG64 };\
//	do {\
//		Ptr = fNtos->MmAllocateContiguousMemorySpecifyCache(pCodeCall->nPageSize, Low, High, Low, MmNonCached);\
//	} while (Ptr == 0);\
//}\
//MemoryFlags.ExePtr = Ptr;\
//MemoryFlags.Ptr = Ptr;\
//fNtos->CopyMemory(MemoryFlags.ExePtr, pCodeCall->Ptr, pCodeCall->MaxSize);\
//pGData->_hEncrypt_DEC_V.SelfTradition(pGData, pCodeCall->Sgin, MemoryFlags.ExePtr, pCodeCall->MaxSize);\
//MMPTE* pMmpte = 0;\
//GetAddressPfn((DWORD64)MemoryFlags.ExePtr, pGData->PTE_BASE, pMmpte);\
//if (pMmpte != 0) {\
//	MMPTE NewPte; NewPte.u.Long = 0x0A00000000000139;\
//	NewPte.u.Hard.PageFrameNumber = pMmpte->u.Hard.PageFrameNumber;\
//	*pMmpte = NewPte;\
//	__invlpg(pMmpte); MemoryFlags.pMpte = pMmpte;\
//}\
//SELF_STRING_ARRY* AArry = &pGData->SelfAArry;\
//return MemoryFlags;\
//}\
//
//
//



//MEMORY_FLAGS ExAllocateFunctionMemory4(PVOID _pGData, SOCKET s, CODE_CALL* pCodeCall) {
//
//	Global_Data* pGData = (Global_Data*)_pGData;
//	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
//
//	MEMORY_FLAGS MemoryFlags;MemoryFlags.MemoryExePtr = 0;
//	MemoryFlags.Flags = KeGetCurrentIrql();
//	MemoryFlags.Size = pCodeCall->nPageSize;
//	PVOID Ptr = 0;
//
//	SOCKET_INFO* pSocket = &pGData->wsk._SocketArry[s];
//
//	if (MemoryFlags.Flags == 2) {
//
//		LIST_ENTRY* pNext = pSocket->DpcMemory.Blink;
//		do
//		{
//			if (pNext == &pSocket->DpcMemory) {
//				break;
//			}
//			Memory_Exe_Info* pMemory = (Memory_Exe_Info*)pNext;
//			if (pMemory->nPageSize >= pCodeCall->nPageSize) {
//				Ptr = pMemory->Ptr;
//				MemoryFlags.MemoryExePtr = pMemory;
//				ChangeEntryList(pGData, s, pNext, pNext, 0);
//				break;
//			}
//			pNext = pNext->Blink;
//		} while (pNext != &pSocket->DpcMemory);
//
//		if (Ptr == 0)
//		{
//			PHYSICAL_ADDRESS Low = { 0 };
//			PHYSICAL_ADDRESS High = { MAXULONG64 };
//			do {
//
//				Ptr = fNtos->MmAllocateContiguousMemorySpecifyCache(pCodeCall->nPageSize, Low, High, Low, MmNonCached);
//
//			} while (Ptr == 0);
//		}
//	}
//	else
//	{
//
//
//		LIST_ENTRY* pNext = pSocket->ApcMemory.Blink;
//		do
//		{
//			if (pNext == &pSocket->ApcMemory)
//			{
//				break;
//			}
//			Memory_Exe_Info* pMemory = (Memory_Exe_Info*)pNext;
//			if (pMemory->nPageSize >= pCodeCall->nPageSize) {
//				Ptr = pMemory->Ptr;
//				MemoryFlags.MemoryExePtr = pMemory;
//				ChangeEntryList(pGData, s, pNext, pNext, 0);
//				break;
//			}
//			pNext = pNext->Blink;
//		} while (pNext != &pSocket->ApcMemory);
//		if (Ptr == 0)
//		{
//			do {
//				Ptr = fNtos->MmAllocateNonCachedMemory(pCodeCall->nPageSize);
//			} while (Ptr == 0);
//		}
//	}
//	MemoryFlags.ExePtr = Ptr;
//	MemoryFlags.Ptr = Ptr;
//
//	fNtos->CopyMemory(MemoryFlags.ExePtr, pCodeCall->Ptr, pCodeCall->MaxSize);
//	pGData->_hEncrypt_DEC_V.SelfTradition(pGData, pCodeCall->Sgin, MemoryFlags.ExePtr, pCodeCall->MaxSize);
//	MMPTE* pMmpte = 0;
//	GetAddressPfn((DWORD64)MemoryFlags.ExePtr, pGData->PTE_BASE, pMmpte);
//	if (pMmpte != 0) {
//		MMPTE NewPte; NewPte.u.Long = 0x0A00000000000139;
//		NewPte.u.Hard.PageFrameNumber = pMmpte->u.Hard.PageFrameNumber;
//		*pMmpte = NewPte;
//		__invlpg(pMmpte);MemoryFlags.pMpte = pMmpte;
//	}
//	SELF_STRING_ARRY* AArry = &pGData->SelfAArry;
//	//LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, _pGData, 0, 0);
//	return MemoryFlags;
//}
//MEMORY_FLAGS ExAllocateFunctionMemory5(PVOID _pGData, SOCKET s, CODE_CALL* pCodeCall) {
//
//	Global_Data* pGData = (Global_Data*)_pGData;
//	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
//
//	MEMORY_FLAGS MemoryFlags;MemoryFlags.MemoryExePtr = 0;
//	MemoryFlags.Flags = KeGetCurrentIrql();
//	MemoryFlags.Size = pCodeCall->nPageSize;
//	PVOID Ptr = 0;
//
//	SOCKET_INFO* pSocket = &pGData->wsk._SocketArry[s];
//
//	if (MemoryFlags.Flags == 2) {
//
//		LIST_ENTRY* pNext = pSocket->DpcMemory.Blink;
//		do
//		{
//			if (pNext == &pSocket->DpcMemory) {
//				break;
//			}
//			Memory_Exe_Info* pMemory = (Memory_Exe_Info*)pNext;
//			if (pMemory->nPageSize >= pCodeCall->nPageSize) {
//				Ptr = pMemory->Ptr;
//				MemoryFlags.MemoryExePtr = pMemory;
//				ChangeEntryList(pGData, s, pNext, pNext, 0);
//				break;
//			}
//			pNext = pNext->Blink;
//		} while (pNext != &pSocket->DpcMemory);
//
//		if (Ptr == 0)
//		{
//			PHYSICAL_ADDRESS Low = { 0 };
//			PHYSICAL_ADDRESS High = { MAXULONG64 };
//			do {
//
//				Ptr = fNtos->MmAllocateContiguousMemorySpecifyCache(pCodeCall->nPageSize, Low, High, Low, MmNonCached);
//
//			} while (Ptr == 0);
//		}
//	}
//	else
//	{
//
//
//		LIST_ENTRY* pNext = pSocket->ApcMemory.Blink;
//		do
//		{
//			if (pNext == &pSocket->ApcMemory)
//			{
//				break;
//			}
//			Memory_Exe_Info* pMemory = (Memory_Exe_Info*)pNext;
//			if (pMemory->nPageSize >= pCodeCall->nPageSize) {
//				Ptr = pMemory->Ptr;
//				MemoryFlags.MemoryExePtr = pMemory;
//				ChangeEntryList(pGData, s, pNext, pNext, 0);
//				break;
//			}
//			pNext = pNext->Blink;
//		} while (pNext != &pSocket->ApcMemory);
//		if (Ptr == 0)
//		{
//			do {
//				Ptr = fNtos->MmAllocateNonCachedMemory(pCodeCall->nPageSize);
//			} while (Ptr == 0);
//		}
//	}
//	MemoryFlags.ExePtr = Ptr;
//	MemoryFlags.Ptr = Ptr;
//
//	fNtos->CopyMemory(MemoryFlags.ExePtr, pCodeCall->Ptr, pCodeCall->MaxSize);
//	pGData->_hEncrypt_DEC_V.SelfTradition(pGData, pCodeCall->Sgin, MemoryFlags.ExePtr, pCodeCall->MaxSize);
//	MMPTE* pMmpte = 0;
//	GetAddressPfn((DWORD64)MemoryFlags.ExePtr, pGData->PTE_BASE, pMmpte);
//	if (pMmpte != 0) {
//		MMPTE NewPte; NewPte.u.Long = 0x0A00000000000139;
//		NewPte.u.Hard.PageFrameNumber = pMmpte->u.Hard.PageFrameNumber;
//		*pMmpte = NewPte;
//		__invlpg(pMmpte);MemoryFlags.pMpte = pMmpte;
//	}
//	SELF_STRING_ARRY* AArry = &pGData->SelfAArry;
//	//LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, _pGData, 0, 0);
//	return MemoryFlags;
//}
//MEMORY_FLAGS ExAllocateFunctionMemory6(PVOID _pGData, SOCKET s, CODE_CALL* pCodeCall) {
//
//	Global_Data* pGData = (Global_Data*)_pGData;
//	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
//
//	MEMORY_FLAGS MemoryFlags;MemoryFlags.MemoryExePtr = 0;
//	MemoryFlags.Flags = KeGetCurrentIrql();
//	MemoryFlags.Size = pCodeCall->nPageSize;
//	PVOID Ptr = 0;
//
//	SOCKET_INFO* pSocket = &pGData->wsk._SocketArry[s];
//
//	if (MemoryFlags.Flags == 2) {
//
//		LIST_ENTRY* pNext = pSocket->DpcMemory.Blink;
//		do
//		{
//			if (pNext == &pSocket->DpcMemory) {
//				break;
//			}
//			Memory_Exe_Info* pMemory = (Memory_Exe_Info*)pNext;
//			if (pMemory->nPageSize >= pCodeCall->nPageSize) {
//				Ptr = pMemory->Ptr;
//				MemoryFlags.MemoryExePtr = pMemory;
//				ChangeEntryList(pGData, s, pNext, pNext, 0);
//				break;
//			}
//			pNext = pNext->Blink;
//		} while (pNext != &pSocket->DpcMemory);
//
//		if (Ptr == 0)
//		{
//			PHYSICAL_ADDRESS Low = { 0 };
//			PHYSICAL_ADDRESS High = { MAXULONG64 };
//			do {
//
//				Ptr = fNtos->MmAllocateContiguousMemorySpecifyCache(pCodeCall->nPageSize, Low, High, Low, MmNonCached);
//
//			} while (Ptr == 0);
//		}
//	}
//	else
//	{
//
//
//		LIST_ENTRY* pNext = pSocket->ApcMemory.Blink;
//		do
//		{
//			if (pNext == &pSocket->ApcMemory)
//			{
//				break;
//			}
//			Memory_Exe_Info* pMemory = (Memory_Exe_Info*)pNext;
//			if (pMemory->nPageSize >= pCodeCall->nPageSize) {
//				Ptr = pMemory->Ptr;
//				MemoryFlags.MemoryExePtr = pMemory;
//				ChangeEntryList(pGData, s, pNext, pNext, 0);
//				break;
//			}
//			pNext = pNext->Blink;
//		} while (pNext != &pSocket->ApcMemory);
//		if (Ptr == 0)
//		{
//			do {
//				Ptr = fNtos->MmAllocateNonCachedMemory(pCodeCall->nPageSize);
//			} while (Ptr == 0);
//		}
//	}
//	MemoryFlags.ExePtr = Ptr;
//	MemoryFlags.Ptr = Ptr;
//
//	fNtos->CopyMemory(MemoryFlags.ExePtr, pCodeCall->Ptr, pCodeCall->MaxSize);
//	pGData->_hEncrypt_DEC_V.SelfTradition(pGData, pCodeCall->Sgin, MemoryFlags.ExePtr, pCodeCall->MaxSize);
//	MMPTE* pMmpte = 0;
//	GetAddressPfn((DWORD64)MemoryFlags.ExePtr, pGData->PTE_BASE, pMmpte);
//	if (pMmpte != 0) {
//		MMPTE NewPte; NewPte.u.Long = 0x0A00000000000139;
//		NewPte.u.Hard.PageFrameNumber = pMmpte->u.Hard.PageFrameNumber;
//		*pMmpte = NewPte;
//		__invlpg(pMmpte);MemoryFlags.pMpte = pMmpte;
//	}
//	SELF_STRING_ARRY* AArry = &pGData->SelfAArry;
//	//LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, _pGData, 0, 0);
//	return MemoryFlags;
//}
//MEMORY_FLAGS ExAllocateFunctionMemory7(PVOID _pGData, SOCKET s, CODE_CALL* pCodeCall) {
//
//	Global_Data* pGData = (Global_Data*)_pGData;
//	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
//
//	MEMORY_FLAGS MemoryFlags;MemoryFlags.MemoryExePtr = 0;
//	MemoryFlags.Flags = KeGetCurrentIrql();
//	MemoryFlags.Size = pCodeCall->nPageSize;
//	PVOID Ptr = 0;
//
//	SOCKET_INFO* pSocket = &pGData->wsk._SocketArry[s];
//
//	if (MemoryFlags.Flags == 2) {
//
//		LIST_ENTRY* pNext = pSocket->DpcMemory.Blink;
//		do
//		{
//			if (pNext == &pSocket->DpcMemory) {
//				break;
//			}
//			Memory_Exe_Info* pMemory = (Memory_Exe_Info*)pNext;
//			if (pMemory->nPageSize >= pCodeCall->nPageSize) {
//				Ptr = pMemory->Ptr;
//				MemoryFlags.MemoryExePtr = pMemory;
//				ChangeEntryList(pGData, s, pNext, pNext, 0);
//				break;
//			}
//			pNext = pNext->Blink;
//		} while (pNext != &pSocket->DpcMemory);
//
//		if (Ptr == 0)
//		{
//			PHYSICAL_ADDRESS Low = { 0 };
//			PHYSICAL_ADDRESS High = { MAXULONG64 };
//			do {
//
//				Ptr = fNtos->MmAllocateContiguousMemorySpecifyCache(pCodeCall->nPageSize, Low, High, Low, MmNonCached);
//
//			} while (Ptr == 0);
//		}
//	}
//	else
//	{
//
//
//		LIST_ENTRY* pNext = pSocket->ApcMemory.Blink;
//		do
//		{
//			if (pNext == &pSocket->ApcMemory)
//			{
//				break;
//			}
//			Memory_Exe_Info* pMemory = (Memory_Exe_Info*)pNext;
//			if (pMemory->nPageSize >= pCodeCall->nPageSize) {
//				Ptr = pMemory->Ptr;
//				MemoryFlags.MemoryExePtr = pMemory;
//				ChangeEntryList(pGData, s, pNext, pNext, 0);
//				break;
//			}
//			pNext = pNext->Blink;
//		} while (pNext != &pSocket->ApcMemory);
//		if (Ptr == 0)
//		{
//			do {
//				Ptr = fNtos->MmAllocateNonCachedMemory(pCodeCall->nPageSize);
//			} while (Ptr == 0);
//		}
//	}
//	MemoryFlags.ExePtr = Ptr;
//	MemoryFlags.Ptr = Ptr;
//
//	fNtos->CopyMemory(MemoryFlags.ExePtr, pCodeCall->Ptr, pCodeCall->MaxSize);
//	pGData->_hEncrypt_DEC_V.SelfTradition(pGData, pCodeCall->Sgin, MemoryFlags.ExePtr, pCodeCall->MaxSize);
//	MMPTE* pMmpte = 0;
//	GetAddressPfn((DWORD64)MemoryFlags.ExePtr, pGData->PTE_BASE, pMmpte);
//	if (pMmpte != 0) {
//		MMPTE NewPte; NewPte.u.Long = 0x0A00000000000139;
//		NewPte.u.Hard.PageFrameNumber = pMmpte->u.Hard.PageFrameNumber;
//		*pMmpte = NewPte;
//		__invlpg(pMmpte);MemoryFlags.pMpte = pMmpte;
//	}
//	SELF_STRING_ARRY* AArry = &pGData->SelfAArry;
//	//LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, MemoryFlags.Ptr, 0, 0);
//	return MemoryFlags;
//}
//MEMORY_FLAGS ExAllocateFunctionMemory8(PVOID _pGData, SOCKET s, CODE_CALL* pCodeCall) {
//
//	Global_Data* pGData = (Global_Data*)_pGData;
//	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
//
//	MEMORY_FLAGS MemoryFlags;MemoryFlags.MemoryExePtr = 0;
//	MemoryFlags.Flags = KeGetCurrentIrql();
//	MemoryFlags.Size = pCodeCall->nPageSize;
//	PVOID Ptr = 0;
//
//	SOCKET_INFO* pSocket = &pGData->wsk._SocketArry[s];
//
//	if (MemoryFlags.Flags == 2) {
//
//		LIST_ENTRY* pNext = pSocket->DpcMemory.Blink;
//		do
//		{
//			if (pNext == &pSocket->DpcMemory) {
//				break;
//			}
//			Memory_Exe_Info* pMemory = (Memory_Exe_Info*)pNext;
//			if (pMemory->nPageSize >= pCodeCall->nPageSize) {
//				Ptr = pMemory->Ptr;
//				MemoryFlags.MemoryExePtr = pMemory;
//				ChangeEntryList(pGData, s, pNext, pNext, 0);
//				break;
//			}
//			pNext = pNext->Blink;
//		} while (pNext != &pSocket->DpcMemory);
//
//		if (Ptr == 0)
//		{
//			PHYSICAL_ADDRESS Low = { 0 };
//			PHYSICAL_ADDRESS High = { MAXULONG64 };
//			do {
//
//				Ptr = fNtos->MmAllocateContiguousMemorySpecifyCache(pCodeCall->nPageSize, Low, High, Low, MmNonCached);
//
//			} while (Ptr == 0);
//		}
//	}
//	else
//	{
//
//
//		LIST_ENTRY* pNext = pSocket->ApcMemory.Blink;
//		do
//		{
//			if (pNext == &pSocket->ApcMemory)
//			{
//				break;
//			}
//			Memory_Exe_Info* pMemory = (Memory_Exe_Info*)pNext;
//			if (pMemory->nPageSize >= pCodeCall->nPageSize) {
//				Ptr = pMemory->Ptr;
//				MemoryFlags.MemoryExePtr = pMemory;
//				ChangeEntryList(pGData, s, pNext, pNext, 0);
//				break;
//			}
//			pNext = pNext->Blink;
//		} while (pNext != &pSocket->ApcMemory);
//		if (Ptr == 0)
//		{
//			do {
//				Ptr = fNtos->MmAllocateNonCachedMemory(pCodeCall->nPageSize);
//			} while (Ptr == 0);
//		}
//	}
//	MemoryFlags.ExePtr = Ptr;
//	MemoryFlags.Ptr = Ptr;
//
//	fNtos->CopyMemory(MemoryFlags.ExePtr, pCodeCall->Ptr, pCodeCall->MaxSize);
//	pGData->_hEncrypt_DEC_V.SelfTradition(pGData, pCodeCall->Sgin, MemoryFlags.ExePtr, pCodeCall->MaxSize);
//	MMPTE* pMmpte = 0;
//	GetAddressPfn((DWORD64)MemoryFlags.ExePtr, pGData->PTE_BASE, pMmpte);
//	if (pMmpte != 0) {
//		MMPTE NewPte; NewPte.u.Long = 0x0A00000000000139;
//		NewPte.u.Hard.PageFrameNumber = pMmpte->u.Hard.PageFrameNumber;
//		*pMmpte = NewPte;
//		__invlpg(pMmpte);MemoryFlags.pMpte = pMmpte;
//	}
//	SELF_STRING_ARRY* AArry = &pGData->SelfAArry;
//	//LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, MemoryFlags.Ptr, 0, 0);
//	return MemoryFlags;
//}
//MEMORY_FLAGS ExAllocateFunctionMemory9(PVOID _pGData, SOCKET s, CODE_CALL* pCodeCall) {
//
//	Global_Data* pGData = (Global_Data*)_pGData;
//	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
//
//	MEMORY_FLAGS MemoryFlags;MemoryFlags.MemoryExePtr = 0;
//	MemoryFlags.Flags = KeGetCurrentIrql();
//	MemoryFlags.Size = pCodeCall->nPageSize;
//	PVOID Ptr = 0;
//
//	SOCKET_INFO* pSocket = &pGData->wsk._SocketArry[s];
//
//	if (MemoryFlags.Flags == 2) {
//
//		LIST_ENTRY* pNext = pSocket->DpcMemory.Blink;
//		do
//		{
//			if (pNext == &pSocket->DpcMemory) {
//				break;
//			}
//			Memory_Exe_Info* pMemory = (Memory_Exe_Info*)pNext;
//			if (pMemory->nPageSize >= pCodeCall->nPageSize) {
//				Ptr = pMemory->Ptr;
//				MemoryFlags.MemoryExePtr = pMemory;
//				ChangeEntryList(pGData, s, pNext, pNext, 0);
//				break;
//			}
//			pNext = pNext->Blink;
//		} while (pNext != &pSocket->DpcMemory);
//
//		if (Ptr == 0)
//		{
//			PHYSICAL_ADDRESS Low = { 0 };
//			PHYSICAL_ADDRESS High = { MAXULONG64 };
//			do {
//
//				Ptr = fNtos->MmAllocateContiguousMemorySpecifyCache(pCodeCall->nPageSize, Low, High, Low, MmNonCached);
//
//			} while (Ptr == 0);
//		}
//	}
//	else
//	{
//
//
//		LIST_ENTRY* pNext = pSocket->ApcMemory.Blink;
//		do
//		{
//			if (pNext == &pSocket->ApcMemory)
//			{
//				break;
//			}
//			Memory_Exe_Info* pMemory = (Memory_Exe_Info*)pNext;
//			if (pMemory->nPageSize >= pCodeCall->nPageSize) {
//				Ptr = pMemory->Ptr;
//				MemoryFlags.MemoryExePtr = pMemory;
//				ChangeEntryList(pGData, s, pNext, pNext, 0);
//				break;
//			}
//			pNext = pNext->Blink;
//		} while (pNext != &pSocket->ApcMemory);
//		if (Ptr == 0)
//		{
//			do {
//				Ptr = fNtos->MmAllocateNonCachedMemory(pCodeCall->nPageSize);
//			} while (Ptr == 0);
//		}
//	}
//	MemoryFlags.ExePtr = Ptr;
//	MemoryFlags.Ptr = Ptr;
//
//	fNtos->CopyMemory(MemoryFlags.ExePtr, pCodeCall->Ptr, pCodeCall->MaxSize);
//	pGData->_hEncrypt_DEC_V.SelfTradition(pGData, pCodeCall->Sgin, MemoryFlags.ExePtr, pCodeCall->MaxSize);
//	MMPTE* pMmpte = 0;
//	GetAddressPfn((DWORD64)MemoryFlags.ExePtr, pGData->PTE_BASE, pMmpte);
//	if (pMmpte != 0) {
//		MMPTE NewPte; NewPte.u.Long = 0x0A00000000000139;
//		NewPte.u.Hard.PageFrameNumber = pMmpte->u.Hard.PageFrameNumber;
//		*pMmpte = NewPte;
//		__invlpg(pMmpte);MemoryFlags.pMpte = pMmpte;
//	}
//	SELF_STRING_ARRY* AArry = &pGData->SelfAArry;
//	//LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, MemoryFlags.Ptr, 0, 0);
//	return MemoryFlags;
//}
//MEMORY_FLAGS ExAllocateFunctionMemory10(PVOID _pGData, SOCKET s, CODE_CALL* pCodeCall) {
//
//	Global_Data* pGData = (Global_Data*)_pGData;
//	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
//
//	MEMORY_FLAGS MemoryFlags;MemoryFlags.MemoryExePtr = 0;
//	MemoryFlags.Flags = KeGetCurrentIrql();
//	MemoryFlags.Size = pCodeCall->nPageSize;
//	PVOID Ptr = 0;
//
//	SOCKET_INFO* pSocket = &pGData->wsk._SocketArry[s];
//
//	if (MemoryFlags.Flags == 2) {
//
//		LIST_ENTRY* pNext = pSocket->DpcMemory.Blink;
//		do
//		{
//			if (pNext == &pSocket->DpcMemory) {
//				break;
//			}
//			Memory_Exe_Info* pMemory = (Memory_Exe_Info*)pNext;
//			if (pMemory->nPageSize >= pCodeCall->nPageSize) {
//				Ptr = pMemory->Ptr;
//				MemoryFlags.MemoryExePtr = pMemory;
//				ChangeEntryList(pGData, s, pNext, pNext, 0);
//				break;
//			}
//			pNext = pNext->Blink;
//		} while (pNext != &pSocket->DpcMemory);
//
//		if (Ptr == 0)
//		{
//			PHYSICAL_ADDRESS Low = { 0 };
//			PHYSICAL_ADDRESS High = { MAXULONG64 };
//			do {
//
//				Ptr = fNtos->MmAllocateContiguousMemorySpecifyCache(pCodeCall->nPageSize, Low, High, Low, MmNonCached);
//
//			} while (Ptr == 0);
//		}
//	}
//	else
//	{
//
//
//		LIST_ENTRY* pNext = pSocket->ApcMemory.Blink;
//		do
//		{
//			if (pNext == &pSocket->ApcMemory)
//			{
//				break;
//			}
//			Memory_Exe_Info* pMemory = (Memory_Exe_Info*)pNext;
//			if (pMemory->nPageSize >= pCodeCall->nPageSize) {
//				Ptr = pMemory->Ptr;
//				MemoryFlags.MemoryExePtr = pMemory;
//				ChangeEntryList(pGData, s, pNext, pNext, 0);
//				break;
//			}
//			pNext = pNext->Blink;
//		} while (pNext != &pSocket->ApcMemory);
//		if (Ptr == 0)
//		{
//			do {
//				Ptr = fNtos->MmAllocateNonCachedMemory(pCodeCall->nPageSize);
//			} while (Ptr == 0);
//		}
//	}
//	MemoryFlags.ExePtr = Ptr;
//	MemoryFlags.Ptr = Ptr;
//
//	fNtos->CopyMemory(MemoryFlags.ExePtr, pCodeCall->Ptr, pCodeCall->MaxSize);
//	pGData->_hEncrypt_DEC_V.SelfTradition(pGData, pCodeCall->Sgin, MemoryFlags.ExePtr, pCodeCall->MaxSize);
//	MMPTE* pMmpte = 0;
//	GetAddressPfn((DWORD64)MemoryFlags.ExePtr, pGData->PTE_BASE, pMmpte);
//	if (pMmpte != 0) {
//		MMPTE NewPte; NewPte.u.Long = 0x0A00000000000139;
//		NewPte.u.Hard.PageFrameNumber = pMmpte->u.Hard.PageFrameNumber;
//		*pMmpte = NewPte;
//		__invlpg(pMmpte);MemoryFlags.pMpte = pMmpte;
//	}
//	SELF_STRING_ARRY* AArry = &pGData->SelfAArry;
//	//LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, MemoryFlags.Ptr, 0, 0);
//	return MemoryFlags;
//}
//MEMORY_FLAGS ExAllocateFunctionMemory11(PVOID _pGData, SOCKET s, CODE_CALL* pCodeCall) {
//
//	Global_Data* pGData = (Global_Data*)_pGData;
//	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
//
//	MEMORY_FLAGS MemoryFlags;MemoryFlags.MemoryExePtr = 0;
//	MemoryFlags.Flags = KeGetCurrentIrql();
//	MemoryFlags.Size = pCodeCall->nPageSize;
//	PVOID Ptr = 0;
//
//	SOCKET_INFO* pSocket = &pGData->wsk._SocketArry[s];
//
//	if (MemoryFlags.Flags == 2) {
//
//		LIST_ENTRY* pNext = pSocket->DpcMemory.Blink;
//		do
//		{
//			if (pNext == &pSocket->DpcMemory) {
//				break;
//			}
//			Memory_Exe_Info* pMemory = (Memory_Exe_Info*)pNext;
//			if (pMemory->nPageSize >= pCodeCall->nPageSize) {
//				Ptr = pMemory->Ptr;
//				MemoryFlags.MemoryExePtr = pMemory;
//				ChangeEntryList(pGData, s, pNext, pNext, 0);
//				break;
//			}
//			pNext = pNext->Blink;
//		} while (pNext != &pSocket->DpcMemory);
//
//		if (Ptr == 0)
//		{
//			PHYSICAL_ADDRESS Low = { 0 };
//			PHYSICAL_ADDRESS High = { MAXULONG64 };
//			do {
//
//				Ptr = fNtos->MmAllocateContiguousMemorySpecifyCache(pCodeCall->nPageSize, Low, High, Low, MmNonCached);
//
//			} while (Ptr == 0);
//		}
//	}
//	else
//	{
//
//
//		LIST_ENTRY* pNext = pSocket->ApcMemory.Blink;
//		do
//		{
//			if (pNext == &pSocket->ApcMemory)
//			{
//				break;
//			}
//			Memory_Exe_Info* pMemory = (Memory_Exe_Info*)pNext;
//			if (pMemory->nPageSize >= pCodeCall->nPageSize) {
//				Ptr = pMemory->Ptr;
//				MemoryFlags.MemoryExePtr = pMemory;
//				ChangeEntryList(pGData, s, pNext, pNext, 0);
//				break;
//			}
//			pNext = pNext->Blink;
//		} while (pNext != &pSocket->ApcMemory);
//		if (Ptr == 0)
//		{
//			do {
//				Ptr = fNtos->MmAllocateNonCachedMemory(pCodeCall->nPageSize);
//			} while (Ptr == 0);
//		}
//	}
//	MemoryFlags.ExePtr = Ptr;
//	MemoryFlags.Ptr = Ptr;
//
//	fNtos->CopyMemory(MemoryFlags.ExePtr, pCodeCall->Ptr, pCodeCall->MaxSize);
//	pGData->_hEncrypt_DEC_V.SelfTradition(pGData, pCodeCall->Sgin, MemoryFlags.ExePtr, pCodeCall->MaxSize);
//	MMPTE* pMmpte = 0;
//	GetAddressPfn((DWORD64)MemoryFlags.ExePtr, pGData->PTE_BASE, pMmpte);
//	if (pMmpte != 0) {
//		MMPTE NewPte; NewPte.u.Long = 0x0A00000000000139;
//		NewPte.u.Hard.PageFrameNumber = pMmpte->u.Hard.PageFrameNumber;
//		*pMmpte = NewPte;
//		__invlpg(pMmpte);MemoryFlags.pMpte = pMmpte;
//	}
//	SELF_STRING_ARRY* AArry = &pGData->SelfAArry;
//	//LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, MemoryFlags.Ptr, 0, 0);
//	return MemoryFlags;
//}
//MEMORY_FLAGS ExAllocateFunctionMemory12(PVOID _pGData, SOCKET s, CODE_CALL* pCodeCall) {
//
//	Global_Data* pGData = (Global_Data*)_pGData;
//	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
//
//	MEMORY_FLAGS MemoryFlags;MemoryFlags.MemoryExePtr = 0;
//	MemoryFlags.Flags = KeGetCurrentIrql();
//	MemoryFlags.Size = pCodeCall->nPageSize;
//	PVOID Ptr = 0;
//
//	SOCKET_INFO* pSocket = &pGData->wsk._SocketArry[s];
//
//	if (MemoryFlags.Flags == 2) {
//
//		LIST_ENTRY* pNext = pSocket->DpcMemory.Blink;
//		do
//		{
//			if (pNext == &pSocket->DpcMemory) {
//				break;
//			}
//			Memory_Exe_Info* pMemory = (Memory_Exe_Info*)pNext;
//			if (pMemory->nPageSize >= pCodeCall->nPageSize) {
//				Ptr = pMemory->Ptr;
//				MemoryFlags.MemoryExePtr = pMemory;
//				ChangeEntryList(pGData, s, pNext, pNext, 0);
//				break;
//			}
//			pNext = pNext->Blink;
//		} while (pNext != &pSocket->DpcMemory);
//
//		if (Ptr == 0)
//		{
//			PHYSICAL_ADDRESS Low = { 0 };
//			PHYSICAL_ADDRESS High = { MAXULONG64 };
//			do {
//
//				Ptr = fNtos->MmAllocateContiguousMemorySpecifyCache(pCodeCall->nPageSize, Low, High, Low, MmNonCached);
//
//			} while (Ptr == 0);
//		}
//	}
//	else
//	{
//
//
//		LIST_ENTRY* pNext = pSocket->ApcMemory.Blink;
//		do
//		{
//			if (pNext == &pSocket->ApcMemory)
//			{
//				break;
//			}
//			Memory_Exe_Info* pMemory = (Memory_Exe_Info*)pNext;
//			if (pMemory->nPageSize >= pCodeCall->nPageSize) {
//				Ptr = pMemory->Ptr;
//				MemoryFlags.MemoryExePtr = pMemory;
//				ChangeEntryList(pGData, s, pNext, pNext, 0);
//				break;
//			}
//			pNext = pNext->Blink;
//		} while (pNext != &pSocket->ApcMemory);
//		if (Ptr == 0)
//		{
//			do {
//				Ptr = fNtos->MmAllocateNonCachedMemory(pCodeCall->nPageSize);
//			} while (Ptr == 0);
//		}
//	}
//	MemoryFlags.ExePtr = Ptr;
//	MemoryFlags.Ptr = Ptr;
//
//	fNtos->CopyMemory(MemoryFlags.ExePtr, pCodeCall->Ptr, pCodeCall->MaxSize);
//	pGData->_hEncrypt_DEC_V.SelfTradition(pGData, pCodeCall->Sgin, MemoryFlags.ExePtr, pCodeCall->MaxSize);
//	MMPTE* pMmpte = 0;
//	GetAddressPfn((DWORD64)MemoryFlags.ExePtr, pGData->PTE_BASE, pMmpte);
//	if (pMmpte != 0) {
//		MMPTE NewPte; NewPte.u.Long = 0x0A00000000000139;
//		NewPte.u.Hard.PageFrameNumber = pMmpte->u.Hard.PageFrameNumber;
//		*pMmpte = NewPte;
//		__invlpg(pMmpte);MemoryFlags.pMpte = pMmpte;
//	}
//	SELF_STRING_ARRY* AArry = &pGData->SelfAArry;
//	//LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, MemoryFlags.Ptr, 0, 0);
//	return MemoryFlags;
//}
//MEMORY_FLAGS ExAllocateFunctionMemory13(PVOID _pGData, SOCKET s, CODE_CALL* pCodeCall) {
//
//	Global_Data* pGData = (Global_Data*)_pGData;
//	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
//
//	MEMORY_FLAGS MemoryFlags;MemoryFlags.MemoryExePtr = 0;
//	MemoryFlags.Flags = KeGetCurrentIrql();
//	MemoryFlags.Size = pCodeCall->nPageSize;
//	PVOID Ptr = 0;
//
//	SOCKET_INFO* pSocket = &pGData->wsk._SocketArry[s];
//
//	if (MemoryFlags.Flags == 2) {
//
//		LIST_ENTRY* pNext = pSocket->DpcMemory.Blink;
//		do
//		{
//			if (pNext == &pSocket->DpcMemory) {
//				break;
//			}
//			Memory_Exe_Info* pMemory = (Memory_Exe_Info*)pNext;
//			if (pMemory->nPageSize >= pCodeCall->nPageSize) {
//				Ptr = pMemory->Ptr;
//				MemoryFlags.MemoryExePtr = pMemory;
//				ChangeEntryList(pGData, s, pNext, pNext, 0);
//				break;
//			}
//			pNext = pNext->Blink;
//		} while (pNext != &pSocket->DpcMemory);
//
//		if (Ptr == 0)
//		{
//			PHYSICAL_ADDRESS Low = { 0 };
//			PHYSICAL_ADDRESS High = { MAXULONG64 };
//			do {
//
//				Ptr = fNtos->MmAllocateContiguousMemorySpecifyCache(pCodeCall->nPageSize, Low, High, Low, MmNonCached);
//
//			} while (Ptr == 0);
//		}
//	}
//	else
//	{
//
//
//		LIST_ENTRY* pNext = pSocket->ApcMemory.Blink;
//		do
//		{
//			if (pNext == &pSocket->ApcMemory)
//			{
//				break;
//			}
//			Memory_Exe_Info* pMemory = (Memory_Exe_Info*)pNext;
//			if (pMemory->nPageSize >= pCodeCall->nPageSize) {
//				Ptr = pMemory->Ptr;
//				MemoryFlags.MemoryExePtr = pMemory;
//				ChangeEntryList(pGData, s, pNext, pNext, 0);
//				break;
//			}
//			pNext = pNext->Blink;
//		} while (pNext != &pSocket->ApcMemory);
//		if (Ptr == 0)
//		{
//			do {
//				Ptr = fNtos->MmAllocateNonCachedMemory(pCodeCall->nPageSize);
//			} while (Ptr == 0);
//		}
//	}
//	MemoryFlags.ExePtr = Ptr;
//	MemoryFlags.Ptr = Ptr;
//
//	fNtos->CopyMemory(MemoryFlags.ExePtr, pCodeCall->Ptr, pCodeCall->MaxSize);
//	pGData->_hEncrypt_DEC_V.SelfTradition(pGData, pCodeCall->Sgin, MemoryFlags.ExePtr, pCodeCall->MaxSize);
//	MMPTE* pMmpte = 0;
//	GetAddressPfn((DWORD64)MemoryFlags.ExePtr, pGData->PTE_BASE, pMmpte);
//	if (pMmpte != 0) {
//		MMPTE NewPte; NewPte.u.Long = 0x0A00000000000139;
//		NewPte.u.Hard.PageFrameNumber = pMmpte->u.Hard.PageFrameNumber;
//		*pMmpte = NewPte;
//		__invlpg(pMmpte);MemoryFlags.pMpte = pMmpte;
//	}
//	return MemoryFlags;
//	//SELF_STRING_ARRY* AArry = &pGData->SelfAArry;
//	//LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, MemoryFlags.Ptr, 0, 0);
//}
//MEMORY_FLAGS ExAllocateFunctionMemory14(PVOID _pGData, SOCKET s, CODE_CALL* pCodeCall) {
//
//	Global_Data* pGData = (Global_Data*)_pGData;
//	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
//
//	MEMORY_FLAGS MemoryFlags;MemoryFlags.MemoryExePtr = 0;
//	MemoryFlags.Flags = KeGetCurrentIrql();
//	MemoryFlags.Size = pCodeCall->nPageSize;
//	PVOID Ptr = 0;
//
//	SOCKET_INFO* pSocket = &pGData->wsk._SocketArry[s];
//
//	if (MemoryFlags.Flags == 2) {
//
//		LIST_ENTRY* pNext = pSocket->DpcMemory.Blink;
//		do
//		{
//			if (pNext == &pSocket->DpcMemory) {
//				break;
//			}
//			Memory_Exe_Info* pMemory = (Memory_Exe_Info*)pNext;
//			if (pMemory->nPageSize >= pCodeCall->nPageSize) {
//				Ptr = pMemory->Ptr;
//				MemoryFlags.MemoryExePtr = pMemory;
//				ChangeEntryList(pGData, s, pNext, pNext, 0);
//				break;
//			}
//			pNext = pNext->Blink;
//		} while (pNext != &pSocket->DpcMemory);
//
//		if (Ptr == 0)
//		{
//			PHYSICAL_ADDRESS Low = { 0 };
//			PHYSICAL_ADDRESS High = { MAXULONG64 };
//			do {
//
//				Ptr = fNtos->MmAllocateContiguousMemorySpecifyCache(pCodeCall->nPageSize, Low, High, Low, MmNonCached);
//
//			} while (Ptr == 0);
//		}
//	}
//	else
//	{
//
//
//		LIST_ENTRY* pNext = pSocket->ApcMemory.Blink;
//		do
//		{
//			if (pNext == &pSocket->ApcMemory)
//			{
//				break;
//			}
//			Memory_Exe_Info* pMemory = (Memory_Exe_Info*)pNext;
//			if (pMemory->nPageSize >= pCodeCall->nPageSize) {
//				Ptr = pMemory->Ptr;
//				MemoryFlags.MemoryExePtr = pMemory;
//				ChangeEntryList(pGData, s, pNext, pNext, 0);
//				break;
//			}
//			pNext = pNext->Blink;
//		} while (pNext != &pSocket->ApcMemory);
//		if (Ptr == 0)
//		{
//			do {
//				Ptr = fNtos->MmAllocateNonCachedMemory(pCodeCall->nPageSize);
//			} while (Ptr == 0);
//		}
//	}
//	MemoryFlags.ExePtr = Ptr;
//	MemoryFlags.Ptr = Ptr;
//
//	fNtos->CopyMemory(MemoryFlags.ExePtr, pCodeCall->Ptr, pCodeCall->MaxSize);
//	pGData->_hEncrypt_DEC_V.SelfTradition(pGData, pCodeCall->Sgin, MemoryFlags.ExePtr, pCodeCall->MaxSize);
//	MMPTE* pMmpte = 0;
//	GetAddressPfn((DWORD64)MemoryFlags.ExePtr, pGData->PTE_BASE, pMmpte);
//	if (pMmpte != 0) {
//		MMPTE NewPte; NewPte.u.Long = 0x0A00000000000139;
//		NewPte.u.Hard.PageFrameNumber = pMmpte->u.Hard.PageFrameNumber;
//		*pMmpte = NewPte;
//		__invlpg(pMmpte);MemoryFlags.pMpte = pMmpte;
//	}
//	SELF_STRING_ARRY* AArry = &pGData->SelfAArry;
//	//LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, MemoryFlags.Ptr, 0, 0);
//	return MemoryFlags;
//}
//MEMORY_FLAGS ExAllocateFunctionMemory15(PVOID _pGData, SOCKET s, CODE_CALL* pCodeCall) {
//
//	Global_Data* pGData = (Global_Data*)_pGData;
//	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
//
//	MEMORY_FLAGS MemoryFlags;MemoryFlags.MemoryExePtr = 0;
//	MemoryFlags.Flags = KeGetCurrentIrql();
//	MemoryFlags.Size = pCodeCall->nPageSize;
//	PVOID Ptr = 0;
//
//	SOCKET_INFO* pSocket = &pGData->wsk._SocketArry[s];
//
//	if (MemoryFlags.Flags == 2) {
//
//		LIST_ENTRY* pNext = pSocket->DpcMemory.Blink;
//		do
//		{
//			if (pNext == &pSocket->DpcMemory) {
//				break;
//			}
//			Memory_Exe_Info* pMemory = (Memory_Exe_Info*)pNext;
//			if (pMemory->nPageSize >= pCodeCall->nPageSize) {
//				Ptr = pMemory->Ptr;
//				MemoryFlags.MemoryExePtr = pMemory;
//				ChangeEntryList(pGData, s, pNext, pNext, 0);
//				break;
//			}
//			pNext = pNext->Blink;
//		} while (pNext != &pSocket->DpcMemory);
//
//		if (Ptr == 0)
//		{
//			PHYSICAL_ADDRESS Low = { 0 };
//			PHYSICAL_ADDRESS High = { MAXULONG64 };
//			do {
//
//				Ptr = fNtos->MmAllocateContiguousMemorySpecifyCache(pCodeCall->nPageSize, Low, High, Low, MmNonCached);
//
//			} while (Ptr == 0);
//		}
//	}
//	else
//	{
//
//
//		LIST_ENTRY* pNext = pSocket->ApcMemory.Blink;
//		do
//		{
//			if (pNext == &pSocket->ApcMemory)
//			{
//				break;
//			}
//			Memory_Exe_Info* pMemory = (Memory_Exe_Info*)pNext;
//			if (pMemory->nPageSize >= pCodeCall->nPageSize) {
//				Ptr = pMemory->Ptr;
//				MemoryFlags.MemoryExePtr = pMemory;
//				ChangeEntryList(pGData, s, pNext, pNext, 0);
//				break;
//			}
//			pNext = pNext->Blink;
//		} while (pNext != &pSocket->ApcMemory);
//		if (Ptr == 0)
//		{
//			do {
//				Ptr = fNtos->MmAllocateNonCachedMemory(pCodeCall->nPageSize);
//			} while (Ptr == 0);
//		}
//	}
//	MemoryFlags.ExePtr = Ptr;
//	MemoryFlags.Ptr = Ptr;
//
//	fNtos->CopyMemory(MemoryFlags.ExePtr, pCodeCall->Ptr, pCodeCall->MaxSize);
//	pGData->_hEncrypt_DEC_V.SelfTradition(pGData, pCodeCall->Sgin, MemoryFlags.ExePtr, pCodeCall->MaxSize);
//	MMPTE* pMmpte = 0;
//	GetAddressPfn((DWORD64)MemoryFlags.ExePtr, pGData->PTE_BASE, pMmpte);
//	if (pMmpte != 0) {
//		MMPTE NewPte; NewPte.u.Long = 0x0A00000000000139;
//		NewPte.u.Hard.PageFrameNumber = pMmpte->u.Hard.PageFrameNumber;
//		*pMmpte = NewPte;
//		__invlpg(pMmpte);MemoryFlags.pMpte = pMmpte;
//	}
//	SELF_STRING_ARRY* AArry = &pGData->SelfAArry;
//	//LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, MemoryFlags.Ptr, 0, 0);
//	return MemoryFlags;
//}
//MEMORY_FLAGS ExAllocateFunctionMemory16(PVOID _pGData, SOCKET s, CODE_CALL* pCodeCall) {
//
//	Global_Data* pGData = (Global_Data*)_pGData;
//	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
//
//	MEMORY_FLAGS MemoryFlags;MemoryFlags.MemoryExePtr = 0;
//	MemoryFlags.Flags = KeGetCurrentIrql();
//	MemoryFlags.Size = pCodeCall->nPageSize;
//	PVOID Ptr = 0;
//
//	SOCKET_INFO* pSocket = &pGData->wsk._SocketArry[s];
//
//	if (MemoryFlags.Flags == 2) {
//
//		LIST_ENTRY* pNext = pSocket->DpcMemory.Blink;
//		do
//		{
//			if (pNext == &pSocket->DpcMemory) {
//				break;
//			}
//			Memory_Exe_Info* pMemory = (Memory_Exe_Info*)pNext;
//			if (pMemory->nPageSize >= pCodeCall->nPageSize) {
//				Ptr = pMemory->Ptr;
//				MemoryFlags.MemoryExePtr = pMemory;
//				ChangeEntryList(pGData, s, pNext, pNext, 0);
//				break;
//			}
//			pNext = pNext->Blink;
//		} while (pNext != &pSocket->DpcMemory);
//
//		if (Ptr == 0)
//		{
//			PHYSICAL_ADDRESS Low = { 0 };
//			PHYSICAL_ADDRESS High = { MAXULONG64 };
//			do {
//
//				Ptr = fNtos->MmAllocateContiguousMemorySpecifyCache(pCodeCall->nPageSize, Low, High, Low, MmNonCached);
//
//			} while (Ptr == 0);
//		}
//	}
//	else
//	{
//
//
//		LIST_ENTRY* pNext = pSocket->ApcMemory.Blink;
//		do
//		{
//			if (pNext == &pSocket->ApcMemory)
//			{
//				break;
//			}
//			Memory_Exe_Info* pMemory = (Memory_Exe_Info*)pNext;
//			if (pMemory->nPageSize >= pCodeCall->nPageSize) {
//				Ptr = pMemory->Ptr;
//				MemoryFlags.MemoryExePtr = pMemory;
//				ChangeEntryList(pGData, s, pNext, pNext, 0);
//				break;
//			}
//			pNext = pNext->Blink;
//		} while (pNext != &pSocket->ApcMemory);
//		if (Ptr == 0)
//		{
//			do {
//				Ptr = fNtos->MmAllocateNonCachedMemory(pCodeCall->nPageSize);
//			} while (Ptr == 0);
//		}
//	}
//	MemoryFlags.ExePtr = Ptr;
//	MemoryFlags.Ptr = Ptr;
//
//	fNtos->CopyMemory(MemoryFlags.ExePtr, pCodeCall->Ptr, pCodeCall->MaxSize);
//	pGData->_hEncrypt_DEC_V.SelfTradition(pGData, pCodeCall->Sgin, MemoryFlags.ExePtr, pCodeCall->MaxSize);
//	MMPTE* pMmpte = 0;
//	GetAddressPfn((DWORD64)MemoryFlags.ExePtr, pGData->PTE_BASE, pMmpte);
//	if (pMmpte != 0) {
//		MMPTE NewPte; NewPte.u.Long = 0x0A00000000000139;
//		NewPte.u.Hard.PageFrameNumber = pMmpte->u.Hard.PageFrameNumber;
//		*pMmpte = NewPte;
//		__invlpg(pMmpte);MemoryFlags.pMpte = pMmpte;
//	}
//	SELF_STRING_ARRY* AArry = &pGData->SelfAArry;
//	//LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, MemoryFlags.Ptr, 0, 0);
//	return MemoryFlags;
//}
//MEMORY_FLAGS ExAllocateFunctionMemory17(PVOID _pGData, SOCKET s, CODE_CALL* pCodeCall) {
//
//	Global_Data* pGData = (Global_Data*)_pGData;
//	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
//
//	MEMORY_FLAGS MemoryFlags;MemoryFlags.MemoryExePtr = 0;
//	MemoryFlags.Flags = KeGetCurrentIrql();
//	MemoryFlags.Size = pCodeCall->nPageSize;
//	PVOID Ptr = 0;
//
//	SOCKET_INFO* pSocket = &pGData->wsk._SocketArry[s];
//
//	if (MemoryFlags.Flags == 2) {
//
//		LIST_ENTRY* pNext = pSocket->DpcMemory.Blink;
//		do
//		{
//			if (pNext == &pSocket->DpcMemory) {
//				break;
//			}
//			Memory_Exe_Info* pMemory = (Memory_Exe_Info*)pNext;
//			if (pMemory->nPageSize >= pCodeCall->nPageSize) {
//				Ptr = pMemory->Ptr;
//				MemoryFlags.MemoryExePtr = pMemory;
//				ChangeEntryList(pGData, s, pNext, pNext, 0);
//				break;
//			}
//			pNext = pNext->Blink;
//		} while (pNext != &pSocket->DpcMemory);
//
//		if (Ptr == 0)
//		{
//			PHYSICAL_ADDRESS Low = { 0 };
//			PHYSICAL_ADDRESS High = { MAXULONG64 };
//			do {
//
//				Ptr = fNtos->MmAllocateContiguousMemorySpecifyCache(pCodeCall->nPageSize, Low, High, Low, MmNonCached);
//
//			} while (Ptr == 0);
//		}
//	}
//	else
//	{
//
//
//		LIST_ENTRY* pNext = pSocket->ApcMemory.Blink;
//		do
//		{
//			if (pNext == &pSocket->ApcMemory)
//			{
//				break;
//			}
//			Memory_Exe_Info* pMemory = (Memory_Exe_Info*)pNext;
//			if (pMemory->nPageSize >= pCodeCall->nPageSize) {
//				Ptr = pMemory->Ptr;
//				MemoryFlags.MemoryExePtr = pMemory;
//				ChangeEntryList(pGData, s, pNext, pNext, 0);
//				break;
//			}
//			pNext = pNext->Blink;
//		} while (pNext != &pSocket->ApcMemory);
//		if (Ptr == 0)
//		{
//			do {
//				Ptr = fNtos->MmAllocateNonCachedMemory(pCodeCall->nPageSize);
//			} while (Ptr == 0);
//		}
//	}
//	MemoryFlags.ExePtr = Ptr;
//	MemoryFlags.Ptr = Ptr;
//
//	fNtos->CopyMemory(MemoryFlags.ExePtr, pCodeCall->Ptr, pCodeCall->MaxSize);
//	pGData->_hEncrypt_DEC_V.SelfTradition(pGData, pCodeCall->Sgin, MemoryFlags.ExePtr, pCodeCall->MaxSize);
//	MMPTE* pMmpte = 0;
//	GetAddressPfn((DWORD64)MemoryFlags.ExePtr, pGData->PTE_BASE, pMmpte);
//	if (pMmpte != 0) {
//		MMPTE NewPte; NewPte.u.Long = 0x0A00000000000139;
//		NewPte.u.Hard.PageFrameNumber = pMmpte->u.Hard.PageFrameNumber;
//		*pMmpte = NewPte;
//		__invlpg(pMmpte);MemoryFlags.pMpte = pMmpte;
//	}
//	SELF_STRING_ARRY* AArry = &pGData->SelfAArry;
//	//LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, MemoryFlags.Ptr, 0, 0);
//	return MemoryFlags;
//}
//MEMORY_FLAGS ExAllocateFunctionMemory18(PVOID _pGData, SOCKET s, CODE_CALL* pCodeCall) {
//
//	Global_Data* pGData = (Global_Data*)_pGData;
//	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
//
//	MEMORY_FLAGS MemoryFlags;MemoryFlags.MemoryExePtr = 0;
//	MemoryFlags.Flags = KeGetCurrentIrql();
//	MemoryFlags.Size = pCodeCall->nPageSize;
//	PVOID Ptr = 0;
//
//	SOCKET_INFO* pSocket = &pGData->wsk._SocketArry[s];
//
//	if (MemoryFlags.Flags == 2) {
//
//		LIST_ENTRY* pNext = pSocket->DpcMemory.Blink;
//		do
//		{
//			if (pNext == &pSocket->DpcMemory) {
//				break;
//			}
//			Memory_Exe_Info* pMemory = (Memory_Exe_Info*)pNext;
//			if (pMemory->nPageSize >= pCodeCall->nPageSize) {
//				Ptr = pMemory->Ptr;
//				MemoryFlags.MemoryExePtr = pMemory;
//				ChangeEntryList(pGData, s, pNext, pNext, 0);
//				break;
//			}
//			pNext = pNext->Blink;
//		} while (pNext != &pSocket->DpcMemory);
//
//		if (Ptr == 0)
//		{
//			PHYSICAL_ADDRESS Low = { 0 };
//			PHYSICAL_ADDRESS High = { MAXULONG64 };
//			do {
//
//				Ptr = fNtos->MmAllocateContiguousMemorySpecifyCache(pCodeCall->nPageSize, Low, High, Low, MmNonCached);
//
//			} while (Ptr == 0);
//		}
//	}
//	else
//	{
//
//
//		LIST_ENTRY* pNext = pSocket->ApcMemory.Blink;
//		do
//		{
//			if (pNext == &pSocket->ApcMemory)
//			{
//				break;
//			}
//			Memory_Exe_Info* pMemory = (Memory_Exe_Info*)pNext;
//			if (pMemory->nPageSize >= pCodeCall->nPageSize) {
//				Ptr = pMemory->Ptr;
//				MemoryFlags.MemoryExePtr = pMemory;
//				ChangeEntryList(pGData, s, pNext, pNext, 0);
//				break;
//			}
//			pNext = pNext->Blink;
//		} while (pNext != &pSocket->ApcMemory);
//		if (Ptr == 0)
//		{
//			do {
//				Ptr = fNtos->MmAllocateNonCachedMemory(pCodeCall->nPageSize);
//			} while (Ptr == 0);
//		}
//	}
//	MemoryFlags.ExePtr = Ptr;
//	MemoryFlags.Ptr = Ptr;
//
//	fNtos->CopyMemory(MemoryFlags.ExePtr, pCodeCall->Ptr, pCodeCall->MaxSize);
//	pGData->_hEncrypt_DEC_V.SelfTradition(pGData, pCodeCall->Sgin, MemoryFlags.ExePtr, pCodeCall->MaxSize);
//	MMPTE* pMmpte = 0;
//	GetAddressPfn((DWORD64)MemoryFlags.ExePtr, pGData->PTE_BASE, pMmpte);
//	if (pMmpte != 0) {
//		MMPTE NewPte; NewPte.u.Long = 0x0A00000000000139;
//		NewPte.u.Hard.PageFrameNumber = pMmpte->u.Hard.PageFrameNumber;
//		*pMmpte = NewPte;
//		__invlpg(pMmpte);MemoryFlags.pMpte = pMmpte;
//	}
//	SELF_STRING_ARRY* AArry = &pGData->SelfAArry;
//	//LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, MemoryFlags.Ptr, 0, 0);
//	return MemoryFlags;
//}
//MEMORY_FLAGS ExAllocateFunctionMemory19(PVOID _pGData, SOCKET s, CODE_CALL* pCodeCall) {
//
//	Global_Data* pGData = (Global_Data*)_pGData;
//	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
//
//	MEMORY_FLAGS MemoryFlags;MemoryFlags.MemoryExePtr = 0;
//	MemoryFlags.Flags = KeGetCurrentIrql();
//	MemoryFlags.Size = pCodeCall->nPageSize;
//	PVOID Ptr = 0;
//
//	SOCKET_INFO* pSocket = &pGData->wsk._SocketArry[s];
//
//	if (MemoryFlags.Flags == 2) {
//
//		LIST_ENTRY* pNext = pSocket->DpcMemory.Blink;
//		do
//		{
//			if (pNext == &pSocket->DpcMemory) {
//				break;
//			}
//			Memory_Exe_Info* pMemory = (Memory_Exe_Info*)pNext;
//			if (pMemory->nPageSize >= pCodeCall->nPageSize) {
//				Ptr = pMemory->Ptr;
//				MemoryFlags.MemoryExePtr = pMemory;
//				ChangeEntryList(pGData, s, pNext, pNext, 0);
//				break;
//			}
//			pNext = pNext->Blink;
//		} while (pNext != &pSocket->DpcMemory);
//
//		if (Ptr == 0)
//		{
//			PHYSICAL_ADDRESS Low = { 0 };
//			PHYSICAL_ADDRESS High = { MAXULONG64 };
//			do {
//
//				Ptr = fNtos->MmAllocateContiguousMemorySpecifyCache(pCodeCall->nPageSize, Low, High, Low, MmNonCached);
//
//			} while (Ptr == 0);
//		}
//	}
//	else
//	{
//
//
//		LIST_ENTRY* pNext = pSocket->ApcMemory.Blink;
//		do
//		{
//			if (pNext == &pSocket->ApcMemory)
//			{
//				break;
//			}
//			Memory_Exe_Info* pMemory = (Memory_Exe_Info*)pNext;
//			if (pMemory->nPageSize >= pCodeCall->nPageSize) {
//				Ptr = pMemory->Ptr;
//				MemoryFlags.MemoryExePtr = pMemory;
//				ChangeEntryList(pGData, s, pNext, pNext, 0);
//				break;
//			}
//			pNext = pNext->Blink;
//		} while (pNext != &pSocket->ApcMemory);
//		if (Ptr == 0)
//		{
//			do {
//				Ptr = fNtos->MmAllocateNonCachedMemory(pCodeCall->nPageSize);
//			} while (Ptr == 0);
//		}
//	}
//	MemoryFlags.ExePtr = Ptr;
//	MemoryFlags.Ptr = Ptr;
//
//	fNtos->CopyMemory(MemoryFlags.ExePtr, pCodeCall->Ptr, pCodeCall->MaxSize);
//	pGData->_hEncrypt_DEC_V.SelfTradition(pGData, pCodeCall->Sgin, MemoryFlags.ExePtr, pCodeCall->MaxSize);
//	MMPTE* pMmpte = 0;
//	GetAddressPfn((DWORD64)MemoryFlags.ExePtr, pGData->PTE_BASE, pMmpte);
//	if (pMmpte != 0) {
//		MMPTE NewPte; NewPte.u.Long = 0x0A00000000000139;
//		NewPte.u.Hard.PageFrameNumber = pMmpte->u.Hard.PageFrameNumber;
//		*pMmpte = NewPte;
//		__invlpg(pMmpte);MemoryFlags.pMpte = pMmpte;
//	}
//	SELF_STRING_ARRY* AArry = &pGData->SelfAArry;
//	//LOG_DEBUG_CODE(AArry->Line_Ptr_DWORD_DWORD.Ptr, __LINE__, MemoryFlags.Ptr, 0, 0);
//	return MemoryFlags;
//}


//#define ExFreeFunctionMemoryFun(x) BOOLEAN ExFreeFunctionMemory##x(PVOID _pGData, SOCKET s, MEMORY_FLAGS* Flags) {\
//	Global_Data* pGData = (Global_Data*)_pGData;\
//NTOSKRNL_FUN* fNtos = &pGData->fNtos;\
//SOCKET_INFO* sInfo = &pGData->wsk._SocketArry[s];\
//MMPTE NewPte; NewPte.u.Long = 0x0A00000000000139;\
//NewPte.u.Hard.PageFrameNumber = Flags->pMpte->u.Hard.PageFrameNumber;\
//NewPte.u.Hard.NoExecute = 1;\
//NewPte.u.Hard.Write = 1;\
//if (Flags->Size <= 0x1000)\
//{\
//	*(Flags->pMpte) = NewPte;\
//	__invlpg(Flags->pMpte);\
//}\
//else\
//{\
//	MMPTE* pMmpte = 0;\
//	for (size_t iP = 0; iP < Flags->Size / 0x1000; iP++)\
//	{\
//		GetAddressPfn(((DWORD64)Flags->Ptr + iP * 0x1000), pGData->PTE_BASE, pMmpte);\
//		if (pMmpte != 0)\
//		{\
//			NewPte.u.Hard.PageFrameNumber = pMmpte->u.Hard.PageFrameNumber;\
//			*pMmpte = NewPte;\
//			__invlpg(pMmpte);\
//		}\
//	}\
//}\
//fNtos->memset(Flags->Ptr, 0, Flags->Size);\
//		if (Flags->MemoryExePtr == 0) {\
//Memory_Exe_Info* MemoryExePtr = (Memory_Exe_Info*)fNtos->ExAllocatePoolWithTag(NonPagedPool, sizeof(Memory_Exe_Info), 'Tag');\
//MemoryExePtr->Ptr = Flags->Ptr;\
//MemoryExePtr->nPageSize = (DWORD)Flags->Size;\
//MemoryExePtr->Flags = Flags->Flags;\
//Flags->MemoryExePtr = MemoryExePtr;\
//		}\
//		ChangeEntryList(_pGData, s, (&sInfo->DpcMemory), (&Flags->MemoryExePtr->Link), 1);\
//return TRUE;\
//}\
//
//
//
//
//ExFreeFunctionMemoryFun(0)
//ExFreeFunctionMemoryFun(1)
//ExFreeFunctionMemoryFun(2)
//ExFreeFunctionMemoryFun(3)
//ExFreeFunctionMemoryFun(4)
//ExFreeFunctionMemoryFun(5)
//ExFreeFunctionMemoryFun(6)
//ExFreeFunctionMemoryFun(7)
//ExFreeFunctionMemoryFun(8)
//ExFreeFunctionMemoryFun(9)
//ExFreeFunctionMemoryFun(10)
//ExFreeFunctionMemoryFun(11)
//ExFreeFunctionMemoryFun(12)
//ExFreeFunctionMemoryFun(13)
//ExFreeFunctionMemoryFun(14)
//ExFreeFunctionMemoryFun(15)
//ExFreeFunctionMemoryFun(16)
//ExFreeFunctionMemoryFun(17)
//ExFreeFunctionMemoryFun(18)
//ExFreeFunctionMemoryFun(19)



__forceinline void SetAddressReadWrite(Global_Data* pGData, MEMORY_FLAGS* Flags) {

	MMPTE NewPte; NewPte.u.Long = 0x0A00000000000139;
	NewPte.u.Hard.PageFrameNumber = Flags->pMpte->u.Hard.PageFrameNumber;
	NewPte.u.Hard.NoExecute = 1;
	NewPte.u.Hard.Write = 1;
	if (Flags->Size <= 0x1000){
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
}







BOOLEAN ExFreeFunctionMemory0(PVOID _pGData, SOCKET s, MEMORY_FLAGS* Flags) {
	Global_Data* pGData = (Global_Data*)_pGData;
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;
	SOCKET_INFO* sInfo = &pGData->wsk._SocketArry[s];
	SetAddressReadWrite(pGData, Flags);
	fNtos->memset(Flags->Ptr, 0, Flags->Size);
	if (Flags->MemoryExePtr == 0) {
		do{
			Flags->MemoryExePtr = (Memory_Exe_Info*)fNtos->ExAllocatePoolWithTag(NonPagedPool, sizeof(Memory_Exe_Info), 'Tag');
		} while (Flags->MemoryExePtr == 0);
		fNtos->memset(Flags->MemoryExePtr, 0, sizeof(Memory_Exe_Info));
		Flags->MemoryExePtr->Ptr = Flags->Ptr;
		Flags->MemoryExePtr->nPageSize = (DWORD)Flags->Size;
		Flags->MemoryExePtr->Flags = Flags->Flags;
	}
	if (Flags->Flags == 2) {
		ChangeEntryList(_pGData, s, (&sInfo->DpcMemory), (&Flags->MemoryExePtr->Link), 1);
	}
	else
	{
		ChangeEntryList(_pGData, s, (&sInfo->ApcMemory), (&Flags->MemoryExePtr->Link), 1);
	}
	return TRUE;
}

#define ExFreeFunctionMemoryFun(x) BOOLEAN ExFreeFunctionMemory##x(PVOID _pGData, SOCKET s, MEMORY_FLAGS* Flags) {\
	Global_Data* pGData = (Global_Data*)_pGData;\
	NTOSKRNL_FUN* fNtos = &pGData->fNtos;\
	SOCKET_INFO* sInfo = &pGData->wsk._SocketArry[s];\
	SetAddressReadWrite(pGData, Flags);\
	fNtos->memset(Flags->Ptr, 0, Flags->Size);\
	if (Flags->MemoryExePtr == 0) {\
		do{\
Flags->MemoryExePtr = (Memory_Exe_Info*)fNtos->ExAllocatePoolWithTag(NonPagedPool, sizeof(Memory_Exe_Info), 'Tag');\
		} while (Flags->MemoryExePtr == 0);\
fNtos->memset(Flags->MemoryExePtr, 0, sizeof(Memory_Exe_Info));\
Flags->MemoryExePtr->Ptr = Flags->Ptr;\
Flags->MemoryExePtr->nPageSize = (DWORD)Flags->Size;\
Flags->MemoryExePtr->Flags = Flags->Flags;\
	}\
	if (Flags->Flags == 2)\
		ChangeEntryList(_pGData, s, (&sInfo->DpcMemory), (&Flags->MemoryExePtr->Link), 1);\
	else\
		ChangeEntryList(_pGData, s, (&sInfo->ApcMemory), (&Flags->MemoryExePtr->Link), 1);\
	return TRUE;\
}\


ExFreeFunctionMemoryFun(1)
ExFreeFunctionMemoryFun(2)
ExFreeFunctionMemoryFun(3)
ExFreeFunctionMemoryFun(4)
ExFreeFunctionMemoryFun(5)
ExFreeFunctionMemoryFun(6)
ExFreeFunctionMemoryFun(7)
ExFreeFunctionMemoryFun(8)
ExFreeFunctionMemoryFun(9)
ExFreeFunctionMemoryFun(10)
ExFreeFunctionMemoryFun(11)
ExFreeFunctionMemoryFun(12)
ExFreeFunctionMemoryFun(13)
ExFreeFunctionMemoryFun(14)
ExFreeFunctionMemoryFun(15)
ExFreeFunctionMemoryFun(16)
ExFreeFunctionMemoryFun(17)
ExFreeFunctionMemoryFun(18)
ExFreeFunctionMemoryFun(19)












NTSYSAPI PRUNTIME_FUNCTION RtlLookupFunctionEntry(
	DWORD64 ControlPc,
	PDWORD64 ImageBase,
	PUNWIND_HISTORY_TABLE HistoryTable
);


#define INI_CODE_ENCRYPT(a,x,y,z,g) InitializeFunCODE_Encrypt(x, y, z); \
            LOG_DEBUG(#a " [%08X] <%p>\n", (x)->Size,g);


//#define FLUSH_FUNCTION_ENCRYPT(x,y,z,g,h,i) RtlZeroMemory(&h, sizeof(UNWIND_HISTORY_TABLE));\
//        y = RtlLookupFunctionEntry((DWORD64)&x, &g, &h);\
//        if (y == NULL) {LOG_DEBUG( #x " Error\n");}\
//        else {INI_CODE_ENCRYPT(&i->x, y, z);}


#pragma warning(disable: 4310)

BOOLEAN FLUSH_FUNCTION_ENCRYPT_P(PVOID Ptr, ULONG64 DllBase, CODE_CALL* pCodeCall) {

	UNWIND_HISTORY_TABLE Table = { 0 };
	ULONG64 hModBase = DllBase;
	PRUNTIME_FUNCTION pRunTime = 0;

	DWORD64 uFun = 0;
	char* uChar = 0;
	uChar = (char*)Ptr; uFun = (DWORD64)Ptr;
	if (uChar[0] == (char)0xE9) { int offset = *((int*)&uChar[1]); uFun = (DWORD64)((LONGLONG)uChar + offset + 5); }
	pRunTime = RtlLookupFunctionEntry(uFun, &hModBase, &Table);
	if (pRunTime == NULL) { return FALSE; }
	else {
		return	InitializeFunCODE_Encrypt(pCodeCall, pRunTime, hModBase);
	}
}

//FLUSH_FUNCTION_ENCRYPT_N

#define FLUSH_FUNCTION_ENCRYPT_V(x,y,z,g,h,i) FLUSH_FUNCTION_ENCRYPT_P((PVOID)&x##i,g,&Sig[i]); \
                                              LOG_DEBUG(#x#i " [%08X] <%p>\n", Sig[i].Size, Sig[i].Ptr);
        //uChar = (char *)&x##i; uFun = (DWORD64)&x##i;\
        //if(uChar[0] ==(char)0xE9){ int offset = *((int *)&uChar[1]); uFun = (DWORD64)((LONGLONG)uChar + offset +5);}\
        //y = RtlLookupFunctionEntry(uFun, &g, &h);\
        //if (y == NULL) {LOG_DEBUG( #x#i " Error\n");}\
        //else {INI_CODE_ENCRYPT(x##i,&Sig[i], y, z, uFun);}

//#define FLUSH_FUNCTION_ENCRYPT_V(x,y,z,g,h,i) RtlZeroMemory(&h, sizeof(UNWIND_HISTORY_TABLE));\
//        uChar = (char *)&x##i; uFun = (DWORD64)&x##i;\
//        if(uChar[0] ==(char)0xE9){ int offset = *((int *)&uChar[1]); uFun = (DWORD64)((LONGLONG)uChar + offset +5);}\
//        y = RtlLookupFunctionEntry(uFun, &g, &h);\
//        if (y == NULL) {LOG_DEBUG( #x#i " Error\n");}\
//        else {INI_CODE_ENCRYPT(x##i,&Sig[i], y, z, uFun);}








void _FlushEnctrypt(PVOID _pGData,ULONG64 DllBase) {

	Global_Data* pGData = (Global_Data*)_pGData;


	LARGE_INTEGER NowTime;
	KeQuerySystemTime(&NowTime);

	int iBox = NowTime.QuadPart % 20;

	CODE_CALL Sig[20] = { 0 };
	//Sig[0] = ini
	DWORD64 uFun = 0;
	char* uChar = 0;
	UNWIND_HISTORY_TABLE Table = { 0 };
	ULONG64 hModBase = DllBase;
	PRUNTIME_FUNCTION pRunTime = 0;


	LOG_DEBUG("iBox %d \n", iBox);


	////RtlZeroMemory(&Table, sizeof(UNWIND_HISTORY_TABLE));
	////pRunTime = RtlLookupFunctionEntry((DWORD64)&_hEncrypt0, &hModBase, &Table);
	////if (pRunTime == NULL) { LOG_DEBUG(#x " Error\n"); }
	////else { INI_CODE_ENCRYPT(&i->x, y, z); }

	//////ULONG64 hModBase = DllBase;
	////InitializeFunCODE_Encrypt(&Sig[0], pRunTime, hModBase);

	//char El = 0xE9;

	//RtlZeroMemory(&Table, sizeof(UNWIND_HISTORY_TABLE));
	//uChar = (char*)&_hEncrypt0; 
	//uFun = (DWORD64)&_hEncrypt0;
	//if (uChar[0] == (char)0xE9) {

	//	int offset = *((int*)&uChar[1]); 
	//	uFun = (DWORD64)((LONGLONG)uChar + offset + 5); 

	//}
	//pRunTime = RtlLookupFunctionEntry(uFun, &hModBase, &Table);
	//		if (pRunTime == NULL) { }\
	//		else { INI_CODE_ENCRYPT(&Sig[0], pRunTime, DllBase, uFun); }



	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt, pRunTime, DllBase, hModBase, Table, 0);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt, pRunTime, DllBase, hModBase, Table, 1);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt, pRunTime, DllBase, hModBase, Table, 2);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt, pRunTime, DllBase, hModBase, Table, 3);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt, pRunTime, DllBase, hModBase, Table, 4);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt, pRunTime, DllBase, hModBase, Table, 5);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt, pRunTime, DllBase, hModBase, Table, 6);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt, pRunTime, DllBase, hModBase, Table, 7);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt, pRunTime, DllBase, hModBase, Table, 8);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt, pRunTime, DllBase, hModBase, Table, 9);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt, pRunTime, DllBase, hModBase, Table, 10);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt, pRunTime, DllBase, hModBase, Table, 11);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt, pRunTime, DllBase, hModBase, Table, 12);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt, pRunTime, DllBase, hModBase, Table, 13);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt, pRunTime, DllBase, hModBase, Table, 14);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt, pRunTime, DllBase, hModBase, Table, 15);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt, pRunTime, DllBase, hModBase, Table, 16);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt, pRunTime, DllBase, hModBase, Table, 17);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt, pRunTime, DllBase, hModBase, Table, 18);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt, pRunTime, DllBase, hModBase, Table, 19);

	//iBox
	pGData->_hEncrypt = Sig[iBox];
	for (int i = 0; i < 20; i++) {
		if (i != iBox) {
			ExFreePoolWithTag(Sig[i].Ptr, 'Mem');
		}
	}

	



	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt_DEC, pRunTime, DllBase, hModBase, Table, 0);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt_DEC, pRunTime, DllBase, hModBase, Table, 1);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt_DEC, pRunTime, DllBase, hModBase, Table, 2);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt_DEC, pRunTime, DllBase, hModBase, Table, 3);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt_DEC, pRunTime, DllBase, hModBase, Table, 4);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt_DEC, pRunTime, DllBase, hModBase, Table, 5);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt_DEC, pRunTime, DllBase, hModBase, Table, 6);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt_DEC, pRunTime, DllBase, hModBase, Table, 7);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt_DEC, pRunTime, DllBase, hModBase, Table, 8);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt_DEC, pRunTime, DllBase, hModBase, Table, 9);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt_DEC, pRunTime, DllBase, hModBase, Table, 10);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt_DEC, pRunTime, DllBase, hModBase, Table, 11);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt_DEC, pRunTime, DllBase, hModBase, Table, 12);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt_DEC, pRunTime, DllBase, hModBase, Table, 13);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt_DEC, pRunTime, DllBase, hModBase, Table, 14);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt_DEC, pRunTime, DllBase, hModBase, Table, 15);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt_DEC, pRunTime, DllBase, hModBase, Table, 16);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt_DEC, pRunTime, DllBase, hModBase, Table, 17);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt_DEC, pRunTime, DllBase, hModBase, Table, 18);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt_DEC, pRunTime, DllBase, hModBase, Table, 19);

	pGData->_hEncrypt_DEC = Sig[iBox];
	for (int i = 0; i < 20; i++){
		if (i != iBox){
			ExFreePoolWithTag(Sig[i].Ptr, 'Mem');
		}
	}



	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt_DEC_V, pRunTime, DllBase, hModBase, Table, 0);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt_DEC_V, pRunTime, DllBase, hModBase, Table, 1);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt_DEC_V, pRunTime, DllBase, hModBase, Table, 2);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt_DEC_V, pRunTime, DllBase, hModBase, Table, 3);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt_DEC_V, pRunTime, DllBase, hModBase, Table, 4);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt_DEC_V, pRunTime, DllBase, hModBase, Table, 5);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt_DEC_V, pRunTime, DllBase, hModBase, Table, 6);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt_DEC_V, pRunTime, DllBase, hModBase, Table, 7);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt_DEC_V, pRunTime, DllBase, hModBase, Table, 8);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt_DEC_V, pRunTime, DllBase, hModBase, Table, 9);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt_DEC_V, pRunTime, DllBase, hModBase, Table, 10);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt_DEC_V, pRunTime, DllBase, hModBase, Table, 11);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt_DEC_V, pRunTime, DllBase, hModBase, Table, 12);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt_DEC_V, pRunTime, DllBase, hModBase, Table, 13);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt_DEC_V, pRunTime, DllBase, hModBase, Table, 14);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt_DEC_V, pRunTime, DllBase, hModBase, Table, 15);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt_DEC_V, pRunTime, DllBase, hModBase, Table, 16);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt_DEC_V, pRunTime, DllBase, hModBase, Table, 17);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt_DEC_V, pRunTime, DllBase, hModBase, Table, 18);
	FLUSH_FUNCTION_ENCRYPT_V(_hEncrypt_DEC_V, pRunTime, DllBase, hModBase, Table, 19);


	pGData->_hEncrypt_DEC_V = Sig[iBox];

	for (int i = 0; i < 20; i++) {
		if (i != iBox) {
			ExFreePoolWithTag(Sig[i].Ptr, 'Mem');
		}
	}

	FLUSH_FUNCTION_ENCRYPT_V(SetAddressExecute, pRunTime, DllBase, hModBase, Table, 0);
	FLUSH_FUNCTION_ENCRYPT_V(SetAddressExecute, pRunTime, DllBase, hModBase, Table, 1);
	FLUSH_FUNCTION_ENCRYPT_V(SetAddressExecute, pRunTime, DllBase, hModBase, Table, 2);
	FLUSH_FUNCTION_ENCRYPT_V(SetAddressExecute, pRunTime, DllBase, hModBase, Table, 3);
	FLUSH_FUNCTION_ENCRYPT_V(SetAddressExecute, pRunTime, DllBase, hModBase, Table, 4);
	FLUSH_FUNCTION_ENCRYPT_V(SetAddressExecute, pRunTime, DllBase, hModBase, Table, 5);
	FLUSH_FUNCTION_ENCRYPT_V(SetAddressExecute, pRunTime, DllBase, hModBase, Table, 6);
	FLUSH_FUNCTION_ENCRYPT_V(SetAddressExecute, pRunTime, DllBase, hModBase, Table, 7);
	FLUSH_FUNCTION_ENCRYPT_V(SetAddressExecute, pRunTime, DllBase, hModBase, Table, 8);
	FLUSH_FUNCTION_ENCRYPT_V(SetAddressExecute, pRunTime, DllBase, hModBase, Table, 9);
	FLUSH_FUNCTION_ENCRYPT_V(SetAddressExecute, pRunTime, DllBase, hModBase, Table, 10);
	FLUSH_FUNCTION_ENCRYPT_V(SetAddressExecute, pRunTime, DllBase, hModBase, Table, 11);
	FLUSH_FUNCTION_ENCRYPT_V(SetAddressExecute, pRunTime, DllBase, hModBase, Table, 12);
	FLUSH_FUNCTION_ENCRYPT_V(SetAddressExecute, pRunTime, DllBase, hModBase, Table, 13);
	FLUSH_FUNCTION_ENCRYPT_V(SetAddressExecute, pRunTime, DllBase, hModBase, Table, 14);
	FLUSH_FUNCTION_ENCRYPT_V(SetAddressExecute, pRunTime, DllBase, hModBase, Table, 15);
	FLUSH_FUNCTION_ENCRYPT_V(SetAddressExecute, pRunTime, DllBase, hModBase, Table, 16);
	FLUSH_FUNCTION_ENCRYPT_V(SetAddressExecute, pRunTime, DllBase, hModBase, Table, 17);
	FLUSH_FUNCTION_ENCRYPT_V(SetAddressExecute, pRunTime, DllBase, hModBase, Table, 18);
	FLUSH_FUNCTION_ENCRYPT_V(SetAddressExecute, pRunTime, DllBase, hModBase, Table, 19);


	pGData->SetAddressExecute = Sig[iBox];

	for (int i = 0; i < 20; i++) {
		if (i != iBox) {
			ExFreePoolWithTag(Sig[i].Ptr, 'Mem');
		}
	}


	FLUSH_FUNCTION_ENCRYPT_V(_WORKER_THREAD_ROUTINE, pRunTime, DllBase, hModBase, Table, 0);
	FLUSH_FUNCTION_ENCRYPT_V(_WORKER_THREAD_ROUTINE, pRunTime, DllBase, hModBase, Table, 1);
	FLUSH_FUNCTION_ENCRYPT_V(_WORKER_THREAD_ROUTINE, pRunTime, DllBase, hModBase, Table, 2);
	FLUSH_FUNCTION_ENCRYPT_V(_WORKER_THREAD_ROUTINE, pRunTime, DllBase, hModBase, Table, 3);
	FLUSH_FUNCTION_ENCRYPT_V(_WORKER_THREAD_ROUTINE, pRunTime, DllBase, hModBase, Table, 4);
	FLUSH_FUNCTION_ENCRYPT_V(_WORKER_THREAD_ROUTINE, pRunTime, DllBase, hModBase, Table, 5);
	FLUSH_FUNCTION_ENCRYPT_V(_WORKER_THREAD_ROUTINE, pRunTime, DllBase, hModBase, Table, 6);
	FLUSH_FUNCTION_ENCRYPT_V(_WORKER_THREAD_ROUTINE, pRunTime, DllBase, hModBase, Table, 7);
	FLUSH_FUNCTION_ENCRYPT_V(_WORKER_THREAD_ROUTINE, pRunTime, DllBase, hModBase, Table, 8);
	FLUSH_FUNCTION_ENCRYPT_V(_WORKER_THREAD_ROUTINE, pRunTime, DllBase, hModBase, Table, 9);
	FLUSH_FUNCTION_ENCRYPT_V(_WORKER_THREAD_ROUTINE, pRunTime, DllBase, hModBase, Table, 10);
	FLUSH_FUNCTION_ENCRYPT_V(_WORKER_THREAD_ROUTINE, pRunTime, DllBase, hModBase, Table, 11);
	FLUSH_FUNCTION_ENCRYPT_V(_WORKER_THREAD_ROUTINE, pRunTime, DllBase, hModBase, Table, 12);
	FLUSH_FUNCTION_ENCRYPT_V(_WORKER_THREAD_ROUTINE, pRunTime, DllBase, hModBase, Table, 13);
	FLUSH_FUNCTION_ENCRYPT_V(_WORKER_THREAD_ROUTINE, pRunTime, DllBase, hModBase, Table, 14);
	FLUSH_FUNCTION_ENCRYPT_V(_WORKER_THREAD_ROUTINE, pRunTime, DllBase, hModBase, Table, 15);
	FLUSH_FUNCTION_ENCRYPT_V(_WORKER_THREAD_ROUTINE, pRunTime, DllBase, hModBase, Table, 16);
	FLUSH_FUNCTION_ENCRYPT_V(_WORKER_THREAD_ROUTINE, pRunTime, DllBase, hModBase, Table, 17);
	FLUSH_FUNCTION_ENCRYPT_V(_WORKER_THREAD_ROUTINE, pRunTime, DllBase, hModBase, Table, 18);
	FLUSH_FUNCTION_ENCRYPT_V(_WORKER_THREAD_ROUTINE, pRunTime, DllBase, hModBase, Table, 19);


	pGData->_WORKER_THREAD_ROUTINE = Sig[iBox];

	for (int i = 0; i < 20; i++) {
		if (i != iBox) {
			ExFreePoolWithTag(Sig[i].Ptr, 'Mem');
		}
	}

	FLUSH_FUNCTION_ENCRYPT_V(_Work_Memory, pRunTime, DllBase, hModBase, Table, 0);
	FLUSH_FUNCTION_ENCRYPT_V(_Work_Memory, pRunTime, DllBase, hModBase, Table, 1);
	FLUSH_FUNCTION_ENCRYPT_V(_Work_Memory, pRunTime, DllBase, hModBase, Table, 2);
	FLUSH_FUNCTION_ENCRYPT_V(_Work_Memory, pRunTime, DllBase, hModBase, Table, 3);
	FLUSH_FUNCTION_ENCRYPT_V(_Work_Memory, pRunTime, DllBase, hModBase, Table, 4);
	FLUSH_FUNCTION_ENCRYPT_V(_Work_Memory, pRunTime, DllBase, hModBase, Table, 5);
	FLUSH_FUNCTION_ENCRYPT_V(_Work_Memory, pRunTime, DllBase, hModBase, Table, 6);
	FLUSH_FUNCTION_ENCRYPT_V(_Work_Memory, pRunTime, DllBase, hModBase, Table, 7);
	FLUSH_FUNCTION_ENCRYPT_V(_Work_Memory, pRunTime, DllBase, hModBase, Table, 8);
	FLUSH_FUNCTION_ENCRYPT_V(_Work_Memory, pRunTime, DllBase, hModBase, Table, 9);
	FLUSH_FUNCTION_ENCRYPT_V(_Work_Memory, pRunTime, DllBase, hModBase, Table, 10);
	FLUSH_FUNCTION_ENCRYPT_V(_Work_Memory, pRunTime, DllBase, hModBase, Table, 11);
	FLUSH_FUNCTION_ENCRYPT_V(_Work_Memory, pRunTime, DllBase, hModBase, Table, 12);
	FLUSH_FUNCTION_ENCRYPT_V(_Work_Memory, pRunTime, DllBase, hModBase, Table, 13);
	FLUSH_FUNCTION_ENCRYPT_V(_Work_Memory, pRunTime, DllBase, hModBase, Table, 14);
	FLUSH_FUNCTION_ENCRYPT_V(_Work_Memory, pRunTime, DllBase, hModBase, Table, 15);
	FLUSH_FUNCTION_ENCRYPT_V(_Work_Memory, pRunTime, DllBase, hModBase, Table, 16);
	FLUSH_FUNCTION_ENCRYPT_V(_Work_Memory, pRunTime, DllBase, hModBase, Table, 17);
	FLUSH_FUNCTION_ENCRYPT_V(_Work_Memory, pRunTime, DllBase, hModBase, Table, 18);
	FLUSH_FUNCTION_ENCRYPT_V(_Work_Memory, pRunTime, DllBase, hModBase, Table, 19);


	pGData->_Work_Memory = Sig[iBox];

	for (int i = 0; i < 20; i++) {
		if (i != iBox) {
			ExFreePoolWithTag(Sig[i].Ptr, 'Mem');
		}
	}


	FLUSH_FUNCTION_ENCRYPT_V(RunApcNo, pRunTime, DllBase, hModBase, Table, 0);
	FLUSH_FUNCTION_ENCRYPT_V(RunApcNo, pRunTime, DllBase, hModBase, Table, 1);
	FLUSH_FUNCTION_ENCRYPT_V(RunApcNo, pRunTime, DllBase, hModBase, Table, 2);
	FLUSH_FUNCTION_ENCRYPT_V(RunApcNo, pRunTime, DllBase, hModBase, Table, 3);
	FLUSH_FUNCTION_ENCRYPT_V(RunApcNo, pRunTime, DllBase, hModBase, Table, 4);
	FLUSH_FUNCTION_ENCRYPT_V(RunApcNo, pRunTime, DllBase, hModBase, Table, 5);
	FLUSH_FUNCTION_ENCRYPT_V(RunApcNo, pRunTime, DllBase, hModBase, Table, 6);
	FLUSH_FUNCTION_ENCRYPT_V(RunApcNo, pRunTime, DllBase, hModBase, Table, 7);
	FLUSH_FUNCTION_ENCRYPT_V(RunApcNo, pRunTime, DllBase, hModBase, Table, 8);
	FLUSH_FUNCTION_ENCRYPT_V(RunApcNo, pRunTime, DllBase, hModBase, Table, 9);
	FLUSH_FUNCTION_ENCRYPT_V(RunApcNo, pRunTime, DllBase, hModBase, Table, 10);
	FLUSH_FUNCTION_ENCRYPT_V(RunApcNo, pRunTime, DllBase, hModBase, Table, 11);
	FLUSH_FUNCTION_ENCRYPT_V(RunApcNo, pRunTime, DllBase, hModBase, Table, 12);
	FLUSH_FUNCTION_ENCRYPT_V(RunApcNo, pRunTime, DllBase, hModBase, Table, 13);
	FLUSH_FUNCTION_ENCRYPT_V(RunApcNo, pRunTime, DllBase, hModBase, Table, 14);
	FLUSH_FUNCTION_ENCRYPT_V(RunApcNo, pRunTime, DllBase, hModBase, Table, 15);
	FLUSH_FUNCTION_ENCRYPT_V(RunApcNo, pRunTime, DllBase, hModBase, Table, 16);
	FLUSH_FUNCTION_ENCRYPT_V(RunApcNo, pRunTime, DllBase, hModBase, Table, 17);
	FLUSH_FUNCTION_ENCRYPT_V(RunApcNo, pRunTime, DllBase, hModBase, Table, 18);
	FLUSH_FUNCTION_ENCRYPT_V(RunApcNo, pRunTime, DllBase, hModBase, Table, 19);

	pGData->RunApcNo = Sig[iBox];

	for (int i = 0; i < 20; i++) {
		if (i != iBox) {
			ExFreePoolWithTag(Sig[i].Ptr, 'Mem');
		}
	}

	//------------------------------------------------------------------------------
	FLUSH_FUNCTION_ENCRYPT_V(IO_COMPLETION_ROUTINE_Ex, pRunTime, DllBase, hModBase, Table, 0);
	FLUSH_FUNCTION_ENCRYPT_V(IO_COMPLETION_ROUTINE_Ex, pRunTime, DllBase, hModBase, Table, 1);
	FLUSH_FUNCTION_ENCRYPT_V(IO_COMPLETION_ROUTINE_Ex, pRunTime, DllBase, hModBase, Table, 2);
	FLUSH_FUNCTION_ENCRYPT_V(IO_COMPLETION_ROUTINE_Ex, pRunTime, DllBase, hModBase, Table, 3);
	FLUSH_FUNCTION_ENCRYPT_V(IO_COMPLETION_ROUTINE_Ex, pRunTime, DllBase, hModBase, Table, 4);
	FLUSH_FUNCTION_ENCRYPT_V(IO_COMPLETION_ROUTINE_Ex, pRunTime, DllBase, hModBase, Table, 5);
	FLUSH_FUNCTION_ENCRYPT_V(IO_COMPLETION_ROUTINE_Ex, pRunTime, DllBase, hModBase, Table, 6);
	FLUSH_FUNCTION_ENCRYPT_V(IO_COMPLETION_ROUTINE_Ex, pRunTime, DllBase, hModBase, Table, 7);
	FLUSH_FUNCTION_ENCRYPT_V(IO_COMPLETION_ROUTINE_Ex, pRunTime, DllBase, hModBase, Table, 8);
	FLUSH_FUNCTION_ENCRYPT_V(IO_COMPLETION_ROUTINE_Ex, pRunTime, DllBase, hModBase, Table, 9);
	FLUSH_FUNCTION_ENCRYPT_V(IO_COMPLETION_ROUTINE_Ex, pRunTime, DllBase, hModBase, Table, 10);
	FLUSH_FUNCTION_ENCRYPT_V(IO_COMPLETION_ROUTINE_Ex, pRunTime, DllBase, hModBase, Table, 11);
	FLUSH_FUNCTION_ENCRYPT_V(IO_COMPLETION_ROUTINE_Ex, pRunTime, DllBase, hModBase, Table, 12);
	FLUSH_FUNCTION_ENCRYPT_V(IO_COMPLETION_ROUTINE_Ex, pRunTime, DllBase, hModBase, Table, 13);
	FLUSH_FUNCTION_ENCRYPT_V(IO_COMPLETION_ROUTINE_Ex, pRunTime, DllBase, hModBase, Table, 14);
	FLUSH_FUNCTION_ENCRYPT_V(IO_COMPLETION_ROUTINE_Ex, pRunTime, DllBase, hModBase, Table, 15);
	FLUSH_FUNCTION_ENCRYPT_V(IO_COMPLETION_ROUTINE_Ex, pRunTime, DllBase, hModBase, Table, 16);
	FLUSH_FUNCTION_ENCRYPT_V(IO_COMPLETION_ROUTINE_Ex, pRunTime, DllBase, hModBase, Table, 17);
	FLUSH_FUNCTION_ENCRYPT_V(IO_COMPLETION_ROUTINE_Ex, pRunTime, DllBase, hModBase, Table, 18);
	FLUSH_FUNCTION_ENCRYPT_V(IO_COMPLETION_ROUTINE_Ex, pRunTime, DllBase, hModBase, Table, 19);
	pGData->IO_COMPLETION_ROUTINE_Ex = Sig[iBox];
	for (int i = 0; i < 20; i++) {
		if (i != iBox) {
			ExFreePoolWithTag(Sig[i].Ptr, 'Mem');
		}
	}


	//------------------------------------------------------------------------------
	FLUSH_FUNCTION_ENCRYPT_V(ExAllocateFunctionMemory, pRunTime, DllBase, hModBase, Table, 0);
	FLUSH_FUNCTION_ENCRYPT_V(ExAllocateFunctionMemory, pRunTime, DllBase, hModBase, Table, 1);
	FLUSH_FUNCTION_ENCRYPT_V(ExAllocateFunctionMemory, pRunTime, DllBase, hModBase, Table, 2);
	FLUSH_FUNCTION_ENCRYPT_V(ExAllocateFunctionMemory, pRunTime, DllBase, hModBase, Table, 3);
	FLUSH_FUNCTION_ENCRYPT_V(ExAllocateFunctionMemory, pRunTime, DllBase, hModBase, Table, 4);
	FLUSH_FUNCTION_ENCRYPT_V(ExAllocateFunctionMemory, pRunTime, DllBase, hModBase, Table, 5);
	FLUSH_FUNCTION_ENCRYPT_V(ExAllocateFunctionMemory, pRunTime, DllBase, hModBase, Table, 6);
	FLUSH_FUNCTION_ENCRYPT_V(ExAllocateFunctionMemory, pRunTime, DllBase, hModBase, Table, 7);
	FLUSH_FUNCTION_ENCRYPT_V(ExAllocateFunctionMemory, pRunTime, DllBase, hModBase, Table, 8);
	FLUSH_FUNCTION_ENCRYPT_V(ExAllocateFunctionMemory, pRunTime, DllBase, hModBase, Table, 9);
	FLUSH_FUNCTION_ENCRYPT_V(ExAllocateFunctionMemory, pRunTime, DllBase, hModBase, Table, 10);
	FLUSH_FUNCTION_ENCRYPT_V(ExAllocateFunctionMemory, pRunTime, DllBase, hModBase, Table, 11);
	FLUSH_FUNCTION_ENCRYPT_V(ExAllocateFunctionMemory, pRunTime, DllBase, hModBase, Table, 12);
	FLUSH_FUNCTION_ENCRYPT_V(ExAllocateFunctionMemory, pRunTime, DllBase, hModBase, Table, 13);
	FLUSH_FUNCTION_ENCRYPT_V(ExAllocateFunctionMemory, pRunTime, DllBase, hModBase, Table, 14);
	FLUSH_FUNCTION_ENCRYPT_V(ExAllocateFunctionMemory, pRunTime, DllBase, hModBase, Table, 15);
	FLUSH_FUNCTION_ENCRYPT_V(ExAllocateFunctionMemory, pRunTime, DllBase, hModBase, Table, 16);
	FLUSH_FUNCTION_ENCRYPT_V(ExAllocateFunctionMemory, pRunTime, DllBase, hModBase, Table, 17);
	FLUSH_FUNCTION_ENCRYPT_V(ExAllocateFunctionMemory, pRunTime, DllBase, hModBase, Table, 18);
	FLUSH_FUNCTION_ENCRYPT_V(ExAllocateFunctionMemory, pRunTime, DllBase, hModBase, Table, 19);


	pGData->ExAllocateFunctionMemory = Sig[iBox];
	for (int i = 0; i < 20; i++) {
		if (i != iBox) {
			ExFreePoolWithTag(Sig[i].Ptr, 'Mem');
		}
	}



	//------------------------------------------------------------------------------
	FLUSH_FUNCTION_ENCRYPT_V(ExFreeFunctionMemory, pRunTime, DllBase, hModBase, Table, 0);
	FLUSH_FUNCTION_ENCRYPT_V(ExFreeFunctionMemory, pRunTime, DllBase, hModBase, Table, 1);
	FLUSH_FUNCTION_ENCRYPT_V(ExFreeFunctionMemory, pRunTime, DllBase, hModBase, Table, 2);
	FLUSH_FUNCTION_ENCRYPT_V(ExFreeFunctionMemory, pRunTime, DllBase, hModBase, Table, 3);
	FLUSH_FUNCTION_ENCRYPT_V(ExFreeFunctionMemory, pRunTime, DllBase, hModBase, Table, 4);
	FLUSH_FUNCTION_ENCRYPT_V(ExFreeFunctionMemory, pRunTime, DllBase, hModBase, Table, 5);
	FLUSH_FUNCTION_ENCRYPT_V(ExFreeFunctionMemory, pRunTime, DllBase, hModBase, Table, 6);
	FLUSH_FUNCTION_ENCRYPT_V(ExFreeFunctionMemory, pRunTime, DllBase, hModBase, Table, 7);
	FLUSH_FUNCTION_ENCRYPT_V(ExFreeFunctionMemory, pRunTime, DllBase, hModBase, Table, 8);
	FLUSH_FUNCTION_ENCRYPT_V(ExFreeFunctionMemory, pRunTime, DllBase, hModBase, Table, 9);
	FLUSH_FUNCTION_ENCRYPT_V(ExFreeFunctionMemory, pRunTime, DllBase, hModBase, Table, 10);
	FLUSH_FUNCTION_ENCRYPT_V(ExFreeFunctionMemory, pRunTime, DllBase, hModBase, Table, 11);
	FLUSH_FUNCTION_ENCRYPT_V(ExFreeFunctionMemory, pRunTime, DllBase, hModBase, Table, 12);
	FLUSH_FUNCTION_ENCRYPT_V(ExFreeFunctionMemory, pRunTime, DllBase, hModBase, Table, 13);
	FLUSH_FUNCTION_ENCRYPT_V(ExFreeFunctionMemory, pRunTime, DllBase, hModBase, Table, 14);
	FLUSH_FUNCTION_ENCRYPT_V(ExFreeFunctionMemory, pRunTime, DllBase, hModBase, Table, 15);
	FLUSH_FUNCTION_ENCRYPT_V(ExFreeFunctionMemory, pRunTime, DllBase, hModBase, Table, 16);
	FLUSH_FUNCTION_ENCRYPT_V(ExFreeFunctionMemory, pRunTime, DllBase, hModBase, Table, 17);
	FLUSH_FUNCTION_ENCRYPT_V(ExFreeFunctionMemory, pRunTime, DllBase, hModBase, Table, 18);
	FLUSH_FUNCTION_ENCRYPT_V(ExFreeFunctionMemory, pRunTime, DllBase, hModBase, Table, 19);


	pGData->ExFreeFunctionMemory = Sig[iBox];
	for (int i = 0; i < 20; i++) {
		if (i != iBox) {
			ExFreePoolWithTag(Sig[i].Ptr, 'Mem');
		}
	}



	//------------------------------------------------------------------------------
	FLUSH_FUNCTION_ENCRYPT_V(_WORKER_THREAD_ROUTINE_ACCEPT_SEND_RECV, pRunTime, DllBase, hModBase, Table, 0);
	FLUSH_FUNCTION_ENCRYPT_V(_WORKER_THREAD_ROUTINE_ACCEPT_SEND_RECV, pRunTime, DllBase, hModBase, Table, 1);
	FLUSH_FUNCTION_ENCRYPT_V(_WORKER_THREAD_ROUTINE_ACCEPT_SEND_RECV, pRunTime, DllBase, hModBase, Table, 2);
	FLUSH_FUNCTION_ENCRYPT_V(_WORKER_THREAD_ROUTINE_ACCEPT_SEND_RECV, pRunTime, DllBase, hModBase, Table, 3);
	FLUSH_FUNCTION_ENCRYPT_V(_WORKER_THREAD_ROUTINE_ACCEPT_SEND_RECV, pRunTime, DllBase, hModBase, Table, 4);
	FLUSH_FUNCTION_ENCRYPT_V(_WORKER_THREAD_ROUTINE_ACCEPT_SEND_RECV, pRunTime, DllBase, hModBase, Table, 5);
	FLUSH_FUNCTION_ENCRYPT_V(_WORKER_THREAD_ROUTINE_ACCEPT_SEND_RECV, pRunTime, DllBase, hModBase, Table, 6);
	FLUSH_FUNCTION_ENCRYPT_V(_WORKER_THREAD_ROUTINE_ACCEPT_SEND_RECV, pRunTime, DllBase, hModBase, Table, 7);
	FLUSH_FUNCTION_ENCRYPT_V(_WORKER_THREAD_ROUTINE_ACCEPT_SEND_RECV, pRunTime, DllBase, hModBase, Table, 8);
	FLUSH_FUNCTION_ENCRYPT_V(_WORKER_THREAD_ROUTINE_ACCEPT_SEND_RECV, pRunTime, DllBase, hModBase, Table, 9);
	FLUSH_FUNCTION_ENCRYPT_V(_WORKER_THREAD_ROUTINE_ACCEPT_SEND_RECV, pRunTime, DllBase, hModBase, Table, 10);
	FLUSH_FUNCTION_ENCRYPT_V(_WORKER_THREAD_ROUTINE_ACCEPT_SEND_RECV, pRunTime, DllBase, hModBase, Table, 11);
	FLUSH_FUNCTION_ENCRYPT_V(_WORKER_THREAD_ROUTINE_ACCEPT_SEND_RECV, pRunTime, DllBase, hModBase, Table, 12);
	FLUSH_FUNCTION_ENCRYPT_V(_WORKER_THREAD_ROUTINE_ACCEPT_SEND_RECV, pRunTime, DllBase, hModBase, Table, 13);
	FLUSH_FUNCTION_ENCRYPT_V(_WORKER_THREAD_ROUTINE_ACCEPT_SEND_RECV, pRunTime, DllBase, hModBase, Table, 14);
	FLUSH_FUNCTION_ENCRYPT_V(_WORKER_THREAD_ROUTINE_ACCEPT_SEND_RECV, pRunTime, DllBase, hModBase, Table, 15);
	FLUSH_FUNCTION_ENCRYPT_V(_WORKER_THREAD_ROUTINE_ACCEPT_SEND_RECV, pRunTime, DllBase, hModBase, Table, 16);
	FLUSH_FUNCTION_ENCRYPT_V(_WORKER_THREAD_ROUTINE_ACCEPT_SEND_RECV, pRunTime, DllBase, hModBase, Table, 17);
	FLUSH_FUNCTION_ENCRYPT_V(_WORKER_THREAD_ROUTINE_ACCEPT_SEND_RECV, pRunTime, DllBase, hModBase, Table, 18);
	FLUSH_FUNCTION_ENCRYPT_V(_WORKER_THREAD_ROUTINE_ACCEPT_SEND_RECV, pRunTime, DllBase, hModBase, Table, 19);


	pGData->WORKER_THREAD_ROUTINE_ACCEPT_SEND_RECV = Sig[iBox];
	for (int i = 0; i < 20; i++) {
		if (i != iBox) {
			ExFreePoolWithTag(Sig[i].Ptr, 'Mem');
		}
	}

	//WORKER_THREAD_ROUTINE_ACCEPT_SEND_RECV

}