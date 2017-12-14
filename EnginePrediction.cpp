
#include "SDK.h"
float m_flOldCurtime;
float m_flOldFrametime;
CMoveData m_MoveData;

int* m_pPredictionRandomSeed;

void StartPrediction(CInput::CUserCmd* pCmd) {
	C_BaseEntity *pLocal = g_EntityList->GetClientEntity(g_Engine->GetLocalPlayer());
	static bool bInit = false;
	if (!bInit) {
		m_pPredictionRandomSeed = *(int**)(U::FindPattern("client.dll", (PBYTE)"\x8B\x0D\x00\x00\x00\x00\xBA\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x83\xC4\x04", "xx????x????x????xxx") + 2);
		bInit = true;
	}


	*m_pPredictionRandomSeed = pCmd->random_seed;


	m_flOldCurtime = g_Globals->curtime;
	m_flOldFrametime = g_Globals->frametime;

	g_Globals->curtime = pLocal->GetTickBase() * g_Globals->interval_per_tick;
	g_Globals->frametime = g_Globals->interval_per_tick;

	g_GameMovement->StartTrackPredictionErrors(pLocal);

	memset(&m_MoveData, 0, sizeof(m_MoveData));
	g_MoveHelper->SetHost(pLocal);
	g_Prediction->SetupMove(pLocal, pCmd, g_MoveHelper, &m_MoveData);
	g_GameMovement->ProcessMovement(pLocal, &m_MoveData);
	g_Prediction->FinishMove(pLocal, pCmd, &m_MoveData);

}

void EndPrediction(CInput::CUserCmd* pCmd) {
	C_BaseEntity *pLocal = g_EntityList->GetClientEntity(g_Engine->GetLocalPlayer());
	g_GameMovement->FinishTrackPredictionErrors(pLocal);
	g_MoveHelper->SetHost(0);

	*m_pPredictionRandomSeed = -1;

	g_Globals->curtime = m_flOldCurtime;
	g_Globals->frametime = m_flOldFrametime;
}
//JUNK CODE//
#include "Junk.h"
JunkCode junkcode12;
int junk12() {
	junkcode12.generateJunk();
	return 0;
}
void Junasssafdasdgkogfjghjghjhgj3() {
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