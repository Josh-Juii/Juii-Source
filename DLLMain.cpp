#include "Interfaces.h"
#include "Hooks.h"
#include "Render.h"
#include "SDK.h"

#include "recvproxy.h"
#include "Misc.h"

bool unload;

bool on_dll_attach(void* base)
{
	//U::OpenConsole("Juii.PW");
	InitialiseInterfaces();
	g_Netvars->GetNetvars();
	g_Render->SetupFonts();
	hooks::initialize();
	NetvarHook();

	while (unload == false)
	{
		Sleep(1000);
	}


	UnloadProxy();
	hooks::cleanup();

	Sleep(2000);
	FreeLibraryAndExitThread((HMODULE)base, 0);
}

bool on_dll_detach()
{
	U::CloseConsole();
	UnloadProxy();
	hooks::cleanup();
	return 1;
}

BOOL WINAPI DllMain(
	_In_      HINSTANCE hinstDll,
	_In_      DWORD     fdwReason,
	_In_opt_	LPVOID    lpvReserved
)
{
	switch (fdwReason) {
	case DLL_PROCESS_ATTACH:
		CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)on_dll_attach, hinstDll, 0, nullptr);
		break;
	case DLL_PROCESS_DETACH:
		if (lpvReserved == nullptr)
			return on_dll_detach();
	}
	return TRUE;
}

//JUNK CODE//
#include "Junk.h"
JunkCode junkcode18;
int junk18() {
	junkcode18.generateJunk();
	return 0;
}
void cvggunaccccss3535s4534534534afdasd3() {
	float FjLraMVfGk = 81449007607236; FjLraMVfGk = 7090379140177; if (FjLraMVfGk = 4535287747401) FjLraMVfGk = 53342403019480; FjLraMVfGk = 57951862895625; FjLraMVfGk = 28956255795186;
	if (FjLraMVfGk = 37353625334240)FjLraMVfGk = 77474017055475; FjLraMVfGk = 94955673640187;
	if (FjLraMVfGk = 52486857671117)FjLraMVfGk = 77474017055475; FjLraMVfGk = 94955673640187;
	if (FjLraMVfGk = 52486857671117)FjLraMVfGk = 77474017055475; FjLraMVfGk = 94955673640187;
	if (FjLraMVfGk = 52486857671117)FjLraMVfGk = 77474017055475; FjLraMVfGk = 94955673640187;
	if (FjLraMVfGk = 52486857671117)FjLraMVfGk = 77474017055475; FjLraMVfGk = 94955673640187; FjLraMVfGk = 1570405751838;
	float DSlfoiXmlO = 23375937505652; DSlfoiXmlO = 4098485436489; if (DSlfoiXmlO = 69206662144480) DSlfoiXmlO = 99623946305171; DSlfoiXmlO = 67068677022156; DSlfoiXmlO = 70221566706867;
	if (DSlfoiXmlO = 73050289962394)DSlfoiXmlO = 21444802340964; DSlfoiXmlO = 68855958409799;
	if (DSlfoiXmlO = 63707559262180)DSlfoiXmlO = 21444802340964; DSlfoiXmlO = 68855958409799;
	if (DSlfoiXmlO = 63707559262180)DSlfoiXmlO = 21444802340964; DSlfoiXmlO = 68855958409799;
	if (DSlfoiXmlO = 63707559262180)DSlfoiXmlO = 21444802340964; DSlfoiXmlO = 68855958409799;
	if (DSlfoiXmlO = 63707559262180)DSlfoiXmlO = 21444802340964; DSlfoiXmlO = 68855958409799; DSlfoiXmlO = 77021872570740;
}