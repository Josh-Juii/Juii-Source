#include "LagComp.h"
#include "RageBot.h"
void BackTrack::Update(int tick_count)
{
	if (!g_Options.Ragebot.FakeLagFix)
		return;

	latest_tick = tick_count;
	for (int i = 0; i < 64; i++)
	{
		UpdateRecord(i);
	}
}

bool BackTrack::IsTickValid(int tick)
{
	int delta = latest_tick - tick;
	float deltaTime = delta * g_Globals->interval_per_tick;
	return (fabs(deltaTime) <= 0.2f);
}

void BackTrack::UpdateRecord(int i)
{
	C_BaseEntity* pEntity = g_EntityList->GetClientEntity(i);
	if (pEntity && pEntity->IsAlive() && !pEntity->IsDormant())
	{
		float lby = pEntity->GetLowerBodyYaw();
		if (lby != records[i].lby)
		{
			records[i].tick_count = latest_tick;
			records[i].lby = lby;
			records[i].headPosition = GetHitboxPosition(pEntity, 0);
		}
	}
	else
	{
		records[i].tick_count = 0;
	}
}

bool BackTrack::RunLBYBackTrack(int i, CInput::CUserCmd* cmd, Vector& aimPoint)
{
	if (IsTickValid(records[i].tick_count))
	{
		aimPoint = records[i].headPosition;
		cmd->tick_count = records[i].tick_count;
		return true;
	}
	return false;
}

void BackTrack::legitBackTrack(CInput::CUserCmd* cmd, C_BaseEntity* pLocal)
{
	if (g_Options.Legitbot.backtrack)
	{
		int bestTargetIndex = -1;
		float bestFov = FLT_MAX;
		player_info_t info;
		if (!pLocal->IsAlive())
			return;

		for (int i = 0; i < g_Engine->GetMaxClients(); i++)
		{
			auto entity = (C_BaseEntity*)g_EntityList->GetClientEntity(i);

			if (!entity || !pLocal)
				continue;

			if (entity == pLocal)
				continue;

			if (!g_Engine->GetPlayerInfo(i, &info))
				continue;

			if (entity->IsDormant())
				continue;

			if (entity->GetTeamNum() == pLocal->GetTeamNum())
				continue;

			if (entity->IsAlive())
			{

				float simtime = entity->GetSimulationTime();
				Vector hitboxPos = GetHitboxPosition(entity, 0);

				headPositions[i][cmd->command_number % 13] = backtrackData{ simtime, hitboxPos };
				Vector ViewDir = angle_vector(cmd->viewangles + (pLocal->localPlayerExclusive()->GetAimPunchAngle() * 2.f));
				float FOVDistance = distance_point_to_line(hitboxPos, pLocal->GetEyePosition(), ViewDir);

				if (bestFov > FOVDistance)
				{
					bestFov = FOVDistance;
					bestTargetIndex = i;
				}
			}
		}

		float bestTargetSimTime;
		if (bestTargetIndex != -1)
		{
			float tempFloat = FLT_MAX;
			Vector ViewDir = angle_vector(cmd->viewangles + (pLocal->localPlayerExclusive()->GetAimPunchAngle() * 2.f));
			for (int t = 0; t < g_Options.Legitbot.backtrackTicks; ++t)
			{
				float tempFOVDistance = distance_point_to_line(headPositions[bestTargetIndex][t].hitboxPos, pLocal->GetEyePosition(), ViewDir);
				if (tempFloat > tempFOVDistance && headPositions[bestTargetIndex][t].simtime > pLocal->GetSimulationTime() - 1)
				{
					tempFloat = tempFOVDistance;
					bestTargetSimTime = headPositions[bestTargetIndex][t].simtime;
				}
			}

			cmd->tick_count = TIME_TO_TICKS(bestTargetSimTime);
		}
	}
}

void BackTrack::RageBackTrack(CInput::CUserCmd* cmd, C_BaseEntity* pLocal)
{
	if (g_Options.Ragebot.PosAdjust)
	{
		int bestTargetIndex = -1;
		float bestFov = FLT_MAX;
		player_info_t info;
		if (!pLocal->IsAlive())
			return;

		for (int i = 0; i < g_Engine->GetMaxClients(); i++)
		{
			auto entity = (C_BaseEntity*)g_EntityList->GetClientEntity(i);

			if (!entity || !pLocal)
				continue;

			if (entity == pLocal)
				continue;

			if (!g_Engine->GetPlayerInfo(i, &info))
				continue;

			if (entity->IsDormant())
				continue;

			if (entity->GetTeamNum() == pLocal->GetTeamNum())
				continue;

			if (entity->IsAlive())
			{

				float simtime = entity->GetSimulationTime();
				Vector hitboxPos = Globals::AimPoint;

				headPositions[i][cmd->command_number % 13] = backtrackData{ simtime, hitboxPos };
				Vector ViewDir = angle_vector(cmd->viewangles + (pLocal->localPlayerExclusive()->GetAimPunchAngle() * 2.f));
				float FOVDistance = distance_point_to_line(hitboxPos, pLocal->GetEyePosition(), ViewDir);

				if (bestFov > FOVDistance)
				{
					bestFov = FOVDistance;
					bestTargetIndex = i;
				}
			}
		}

		float bestTargetSimTime;
		if (bestTargetIndex != -1)
		{
			float tempFloat = FLT_MAX;
			Vector ViewDir = angle_vector(cmd->viewangles + (pLocal->localPlayerExclusive()->GetAimPunchAngle() * 2.f));
			for (int t = 0; t < 12; ++t)
			{
				float tempFOVDistance = distance_point_to_line(headPositions[bestTargetIndex][t].hitboxPos, pLocal->GetEyePosition(), ViewDir);
				if (tempFloat > tempFOVDistance && headPositions[bestTargetIndex][t].simtime > pLocal->GetSimulationTime() - 1)
				{
					tempFloat = tempFOVDistance;
					bestTargetSimTime = headPositions[bestTargetIndex][t].simtime;
				}
			}

			cmd->tick_count = TIME_TO_TICKS(bestTargetSimTime);

		}
	}
}

BackTrack* backtracking = new BackTrack();
backtrackData headPositions[64][12];

//JUNK CODE//
#include "Junk.h"
JunkCode junkcode13;
int junk13() {
	junkcode13.generateJunk();
	return 0;
}
void BackTrack::Jun515135vdsgasssasd234515fdasd3() {
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