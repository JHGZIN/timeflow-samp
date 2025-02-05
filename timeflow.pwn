/*
    ==========================================
	File: timeflow.pwn
	Author: JHGZIN
	Description: Automatic day and night cycle system for SA-MP. Updates the game time dynamically, creating a realistic effect.    ==========================================
    ==========================================
*/
#define FILTERSCRIPT

#include <a_samp>

static bool:timer_TextShow[MAX_PLAYERS], PlayerText:text_TimerPlayer[MAX_PLAYERS][9];

enum E_TIMEFLOW  {
	Hour,
	Minute,
	Second,
	TimerFlow
}

static g_TimeFlow[E_TIMEFLOW];

#if defined FILTERSCRIPT

public OnFilterScriptInit() {
    static timer; 
    timer = random(12)+1;
    g_TimeFlow[Hour] = timer;
	g_TimeFlow[TimerFlow] = SetTimer("StartTimer", 1000, false);
	return true;
}

public OnFilterScriptExit() {
	KillTimer(g_TimeFlow[TimerFlow]);
	return true;
}
#endif

public OnPlayerSpawn(playerid) {
	Create_PlayerTextTimer(playerid);
	return true;
}

public OnPlayerDisconnect(playerid, reason) {
	Destroy_PlayerTextTimer(playerid);
	return true;
}

public OnPlayerUpdate(playerid) {
	static str[11]; format(str, sizeof str, "%02d:%02d", g_TimeFlow[Hour], g_TimeFlow[Minute]);
	PlayerTextDrawSetString(playerid, text_TimerPlayer[playerid][8], str);
	return true;
}

forward StartTimer();
public StartTimer() {
	if(g_TimeFlow[Second] >= 4) {
	    g_TimeFlow[Second] = 0;
	    g_TimeFlow[Minute] ++;
	}
	else if(g_TimeFlow[Minute] >= 59) {
	    g_TimeFlow[Minute] = 0;
	    g_TimeFlow[Hour] ++;
	}
	else if(g_TimeFlow[Hour] > 23) {
	    g_TimeFlow[Hour] = 0;
	    g_TimeFlow[Hour] ++;
	}
    SetTimer("StartTimer", 1000, false);
    g_TimeFlow[Second] ++;
	SetWorldTime(g_TimeFlow[Hour]);
	return true;
}

static stock Create_PlayerTextTimer(playerid) {
	if(!timer_TextShow[playerid]) {
		text_TimerPlayer[playerid][0] = CreatePlayerTextDraw(playerid, 490.000, 8.000, "_");
		PlayerTextDrawLetterSize(playerid, text_TimerPlayer[playerid][0], 0.300, 2.200);
		PlayerTextDrawTextSize(playerid, text_TimerPlayer[playerid][0], 0.000, 35.000);
		PlayerTextDrawAlignment(playerid, text_TimerPlayer[playerid][0], 2);
		PlayerTextDrawColor(playerid, text_TimerPlayer[playerid][0], -1);
		PlayerTextDrawUseBox(playerid, text_TimerPlayer[playerid][0], 1);
		PlayerTextDrawBoxColor(playerid, text_TimerPlayer[playerid][0], 858993663);
		PlayerTextDrawSetShadow(playerid, text_TimerPlayer[playerid][0], 1);
		PlayerTextDrawSetOutline(playerid, text_TimerPlayer[playerid][0], 1);
		PlayerTextDrawBackgroundColor(playerid, text_TimerPlayer[playerid][0], 150);
		PlayerTextDrawFont(playerid, text_TimerPlayer[playerid][0], 1);
		PlayerTextDrawSetProportional(playerid, text_TimerPlayer[playerid][0], 1);
		
		text_TimerPlayer[playerid][1] = CreatePlayerTextDraw(playerid, 490.000, 14.798, "_");
		PlayerTextDrawLetterSize(playerid, text_TimerPlayer[playerid][1], 0.300, 0.600);
		PlayerTextDrawTextSize(playerid, text_TimerPlayer[playerid][1], 0.000, 42.299);
		PlayerTextDrawAlignment(playerid, text_TimerPlayer[playerid][1], 2);
		PlayerTextDrawColor(playerid, text_TimerPlayer[playerid][1], -1);
		PlayerTextDrawUseBox(playerid, text_TimerPlayer[playerid][1], 1);
		PlayerTextDrawBoxColor(playerid, text_TimerPlayer[playerid][1], 858993663);
		PlayerTextDrawSetShadow(playerid, text_TimerPlayer[playerid][1], 1);
		PlayerTextDrawSetOutline(playerid, text_TimerPlayer[playerid][1], 1);
		PlayerTextDrawBackgroundColor(playerid, text_TimerPlayer[playerid][1], 150);
		PlayerTextDrawFont(playerid, text_TimerPlayer[playerid][1], 1);
		PlayerTextDrawSetProportional(playerid, text_TimerPlayer[playerid][1], 1);
		
		text_TimerPlayer[playerid][2] = CreatePlayerTextDraw(playerid, 466.198, 4.098, "LD_BEAT:chit");
		PlayerTextDrawTextSize(playerid, text_TimerPlayer[playerid][2], 10.000, 15.000);
		PlayerTextDrawAlignment(playerid, text_TimerPlayer[playerid][2], 1);
		PlayerTextDrawColor(playerid, text_TimerPlayer[playerid][2], 858993663);
		PlayerTextDrawSetShadow(playerid, text_TimerPlayer[playerid][2], 0);
		PlayerTextDrawSetOutline(playerid, text_TimerPlayer[playerid][2], 0);
		PlayerTextDrawBackgroundColor(playerid, text_TimerPlayer[playerid][2], 255);
		PlayerTextDrawFont(playerid, text_TimerPlayer[playerid][2], 4);
		PlayerTextDrawSetProportional(playerid, text_TimerPlayer[playerid][2], 1);
		
		text_TimerPlayer[playerid][3] = CreatePlayerTextDraw(playerid, 504.098, 4.098, "LD_BEAT:chit");
		PlayerTextDrawTextSize(playerid, text_TimerPlayer[playerid][3], 10.000, 15.000);
		PlayerTextDrawAlignment(playerid, text_TimerPlayer[playerid][3], 1);
		PlayerTextDrawColor(playerid, text_TimerPlayer[playerid][3], 858993663);
		PlayerTextDrawSetShadow(playerid, text_TimerPlayer[playerid][3], 0);
		PlayerTextDrawSetOutline(playerid, text_TimerPlayer[playerid][3], 0);
		PlayerTextDrawBackgroundColor(playerid, text_TimerPlayer[playerid][3], 255);
		PlayerTextDrawFont(playerid, text_TimerPlayer[playerid][3], 4);
		PlayerTextDrawSetProportional(playerid, text_TimerPlayer[playerid][3], 1);
		
		text_TimerPlayer[playerid][4] = CreatePlayerTextDraw(playerid, 503.898, 16.998, "LD_BEAT:chit");
		PlayerTextDrawTextSize(playerid, text_TimerPlayer[playerid][4], 10.000, 15.000);
		PlayerTextDrawAlignment(playerid, text_TimerPlayer[playerid][4], 1);
		PlayerTextDrawColor(playerid, text_TimerPlayer[playerid][4], 858993663);
		PlayerTextDrawSetShadow(playerid, text_TimerPlayer[playerid][4], 0);
		PlayerTextDrawSetOutline(playerid, text_TimerPlayer[playerid][4], 0);
		PlayerTextDrawBackgroundColor(playerid, text_TimerPlayer[playerid][4], 255);
		PlayerTextDrawFont(playerid, text_TimerPlayer[playerid][4], 4);
		PlayerTextDrawSetProportional(playerid, text_TimerPlayer[playerid][4], 1);
		
		text_TimerPlayer[playerid][5] = CreatePlayerTextDraw(playerid, 465.998, 16.998, "LD_BEAT:chit");
		PlayerTextDrawTextSize(playerid, text_TimerPlayer[playerid][5], 10.000, 15.000);
		PlayerTextDrawAlignment(playerid, text_TimerPlayer[playerid][5], 1);
		PlayerTextDrawColor(playerid, text_TimerPlayer[playerid][5], 858993663);
		PlayerTextDrawSetShadow(playerid, text_TimerPlayer[playerid][5], 0);
		PlayerTextDrawSetOutline(playerid, text_TimerPlayer[playerid][5], 0);
		PlayerTextDrawBackgroundColor(playerid, text_TimerPlayer[playerid][5], 255);
		PlayerTextDrawFont(playerid, text_TimerPlayer[playerid][5], 4);
		PlayerTextDrawSetProportional(playerid, text_TimerPlayer[playerid][5], 1);
		
		text_TimerPlayer[playerid][6] = CreatePlayerTextDraw(playerid, 467.598, 6.898, "LD_BEAT:chit");
		PlayerTextDrawTextSize(playerid, text_TimerPlayer[playerid][6], 15.000, 21.000);
		PlayerTextDrawAlignment(playerid, text_TimerPlayer[playerid][6], 1);
		PlayerTextDrawColor(playerid, text_TimerPlayer[playerid][6], 255);
		PlayerTextDrawSetShadow(playerid, text_TimerPlayer[playerid][6], 0);
		PlayerTextDrawSetOutline(playerid, text_TimerPlayer[playerid][6], 0);
		PlayerTextDrawBackgroundColor(playerid, text_TimerPlayer[playerid][6], 255);
		PlayerTextDrawFont(playerid, text_TimerPlayer[playerid][6], 4);
		PlayerTextDrawSetProportional(playerid, text_TimerPlayer[playerid][6], 1);
		
		text_TimerPlayer[playerid][7] = CreatePlayerTextDraw(playerid, 473.898, 13.100, "L");
		PlayerTextDrawLetterSize(playerid, text_TimerPlayer[playerid][7], 0.300, 0.699);
		PlayerTextDrawAlignment(playerid, text_TimerPlayer[playerid][7], 1);
		PlayerTextDrawColor(playerid, text_TimerPlayer[playerid][7], -1);
		PlayerTextDrawSetShadow(playerid, text_TimerPlayer[playerid][7], 1);
		PlayerTextDrawSetOutline(playerid, text_TimerPlayer[playerid][7], 1);
		PlayerTextDrawBackgroundColor(playerid, text_TimerPlayer[playerid][7], 0);
		PlayerTextDrawFont(playerid, text_TimerPlayer[playerid][7], 1);
		PlayerTextDrawSetProportional(playerid, text_TimerPlayer[playerid][7], 1);
		
		text_TimerPlayer[playerid][8] = CreatePlayerTextDraw(playerid, 483.898, 11.100, "04:20");
		PlayerTextDrawLetterSize(playerid, text_TimerPlayer[playerid][8], 0.200, 1.199);
		PlayerTextDrawAlignment(playerid, text_TimerPlayer[playerid][8], 1);
		PlayerTextDrawColor(playerid, text_TimerPlayer[playerid][8], -1);
		PlayerTextDrawSetShadow(playerid, text_TimerPlayer[playerid][8], 1);
		PlayerTextDrawSetOutline(playerid, text_TimerPlayer[playerid][8], 1);
		PlayerTextDrawBackgroundColor(playerid, text_TimerPlayer[playerid][8], 0);
		PlayerTextDrawFont(playerid, text_TimerPlayer[playerid][8], 1);
		PlayerTextDrawSetProportional(playerid, text_TimerPlayer[playerid][8], 1);
		timer_TextShow[playerid] = true;
	}
    for (new i = 0; i < sizeof text_TimerPlayer[]; i++) PlayerTextDrawShow(playerid, text_TimerPlayer[playerid][i]);
	return true;
}

static stock Destroy_PlayerTextTimer(playerid) {
    if (timer_TextShow[playerid]) {
        for (new i = 0; i < sizeof text_TimerPlayer[]; i++) {
            PlayerTextDrawDestroy(playerid, text_TimerPlayer[playerid][i]);
            text_TimerPlayer[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
        }
    }
    timer_TextShow[playerid] = false;
    return true;
}