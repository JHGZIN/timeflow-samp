/*
    ==========================================
    Include: timeflow.inc
	Author: JHGZIN
	Version: 1.0 
	Description: Automatic day and night cycle system for SA-MP. Updates the game time dynamically, creating a realistic effect.    ==========================================
    ==========================================
*/

#if !defined FILTERSCRIPT

#if defined _rCICLE_Included_
	#endinput
#endif

#define _rCICLE_Included_

#if !defined _samp_included
	#tryinclude <a_samp>
#endif

#if !defined _samp_included
	#tryinclude "a_samp"
#endif

static hour,
	   minute,
	   second,
	   bool:timer_TextShow[MAX_PLAYERS],
	   PlayerText:text_TimerPlayer[MAX_PLAYERS][9]
	   ;

#if defined CICLE_OnPlayerSpawn
	forward CICLE_OnPlayerSpawn(playerid);
#endif

#if defined CICLE_OnGameModeInit
	forward CICLE_OnGameModeInit();
#endif

#if defined CICLE_OnPlayerUpdate
	forward CICLE_OnPlayerUpdate(playerid);
#endif

forward StartTimer();

public OnGameModeInit() {
    new timer = random(12)+1;
    hour = timer;

	SetTimer("StartTimer", 1000, false);

	#if defined CICLE_OnGameModeInit
		return CICLE_OnGameModeInit();
	#else
		return true;
	#endif
}

public OnPlayerSpawn(playerid) {
	Create_PlayerTextTimer(playerid);

	#if defined CICLE_OnPlayerSpawn
		return CICLE_OnPlayerSpawn(playerid);
	#else
		return true;
	#endif
}

public OnPlayerUpdate(playerid) {
	new str[11]; format(str, sizeof str, "%02d:%02d", hour, minute);
	PlayerTextDrawSetString(playerid, text_TimerPlayer[playerid][8], str);
	#if defined CICLE_OnPlayerUpdate
		return CICLE_OnPlayerUpdate(playerid);
	#else
		return true;
	#endif
}

public StartTimer() {
	if(second >= 4) {
	    second = 0;
	    minute ++;
	}
	else if(minute >= 59) {
	    minute = 0;
	    hour ++;
	}
	else if(hour > 23) {
	    hour = 0;
	    hour ++;
	}
    SetTimer("StartTimer", 1000, false);
    second ++;
	SetWorldTime(hour);
	return true;
}

stock Create_PlayerTextTimer(playerid) {
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

stock Destroy_PlayerTextTimer(playerid) {
    if (timer_TextShow[playerid]) {
        for (new i = 0; i < sizeof text_TimerPlayer[]; i++) {
            PlayerTextDrawDestroy(playerid, text_TimerPlayer[playerid][i]);
            text_TimerPlayer[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
        }
    }
    timer_TextShow[playerid] = false;
    return true;
}

#if defined _ALS_OnPlayerSpawn
  #undef OnPlayerSpawn
#else
	#define _ALS_OnPlayerSpawn
#endif

#define OnPlayerSpawn CICLE_OnPlayerSpawn

#if defined _ALS_OnGameModeInit
  #undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif

#define OnGameModeInit CICLE_OnGameModeInit

#if defined _ALS_OnPlayerUpdate
  #undef OnPlayerUpdate
#else
	#define _ALS_OnPlayerUpdate
#endif

#define OnPlayerUpdate CICLE_OnPlayerUpdate

#endif