/*!
 * Animations/commands.inc
 *
 > Priority: 0
 */

/*

*/

CommandDescription<animlist> = @"List all available animations.";
YCMD:animlist(playerid, params[], help) {
    SendClientUsage(playerid, "Available Animations: /drunk, /bomb, /crossarms, /handsup,");
    SendClientUsage(playerid, "/seat, /gro, /lay, /laugh, /robman, /getarrested, /fall, /wave");
    SendClientUsage(playerid, "/crack, /chat, /deal, /taichi, /fucku, /smoke, /hide, /rap, /piss");
    SendClientUsage(playerid, "/dance, /cellin, /cellout, /vomit, /lightcig, /eatanim, /lookout");
    SendClientUsage(playerid, "/walk, /run, /sideways");
    SendClientUsage(playerid, "/stopani - Stops all animations");

    return 1;
}


// Drunk walk
YCMD:drunk(playerid, params[], help)
{
    if (this.CheckAnimationWhileCuffed(playerid)) {
        ApplyAnimation(playerid,"PED","WALK_DRUNK",4.1,1,1,1,1,1); // Drunk walk
        this.SetUsingLoopingAnimation(playerid, true);
    }
    
    return 1;
}

// Plant bomb
YCMD:bomb(playerid, params[], help)
{
    if (this.CheckAnimationWhileCuffed(playerid)) {
        ApplyAnimation(playerid, "BOMBER","BOM_Plant_Loop",4.0,0,0,0,0,0); // Plant bomb
    }
    
    return 1;
}

// Crossarms
YCMD:crossarms(playerid, params[], help)
{
    if (this.CheckAnimationWhileCuffed(playerid)) {
        ApplyAnimation(playerid, "COP_AMBIENT", "Coplook_loop", 4.0, 0, 1, 1, 1, -1); // Crossarms
        this.SetUsingLoopingAnimation(playerid, true);
    }
    
    return 1;
}

// Seat for chair
YCMD:seat(playerid, params[], help)
{
    if (this.CheckAnimationWhileCuffed(playerid)) {
        ApplyAnimation(playerid,"PED","SEAT_down",4.1,0,0,0,1,0); // chair sit
		this.SetUsingLoopingAnimation(playerid, true);
    }
    
    return 1;
}

// Lay
YCMD:lay(playerid, params[], help)
{
    if (this.CheckAnimationWhileCuffed(playerid)) {
        ApplyAnimation(playerid, "BEACH", "bather", 4.0,1,0,0,1,0); // lay down
		this.SetUsingLoopingAnimation(playerid, true);
    }
    
    return 1;
}

// Laugh
YCMD:laugh(playerid, params[], help)
{

    #pragma unused params // no params
    if (this.CheckAnimationWhileCuffed(playerid)) {
        ApplyAnimation(playerid, "RAPPING", "Laugh_01", 4.0, 0, 0, 0, 0, 0);
    }
    
    return 1;
}

// Robman - criminal point gun
YCMD:robman(playerid, params[], help)
{
    if (this.CheckAnimationWhileCuffed(playerid)) {
        ApplyAnimation(playerid, "SHOP", "ROB_Loop_Threat", 4.0, 1, 0, 0, 0, 0);
        this.SetUsingLoopingAnimation(playerid, true);
    }
    
    return 1;
}

// Get arrested - points gun
YCMD:getarrested(playerid, params[], help)
{
    if (this.CheckAnimationWhileCuffed(playerid)) {
        ApplyAnimation(playerid,"ped", "ARRESTgun", 4.0, 0, 1, 1, 1, -1);
        this.SetUsingLoopingAnimation(playerid, true);
    }
    
    return 1;
}

// Fall Down
YCMD:fall(playerid, params[], help)
{
    if (this.CheckAnimationWhileCuffed(playerid)) {
        ApplyAnimation(playerid,"PED","KO_skid_front",4.1,0,1,1,1,0);
        this.SetUsingLoopingAnimation(playerid, true);
    }
    
    return 1;
}

// Wave
YCMD:wave(playerid, params[], help)
{
    if (this.CheckAnimationWhileCuffed(playerid)) {
        ApplyAnimation(playerid, "ON_LOOKERS", "wave_loop", 4.0, 1, 0, 0, 0, 0); // Wave
        this.SetUsingLoopingAnimation(playerid, true);
    }
    
    return 1;
}

// Crack
YCMD:crack(playerid, params[], help)
{
    if (this.CheckAnimationWhileCuffed(playerid)) {
        ApplyAnimation(playerid, "CRACK", "crckdeth2", 4.0, 1, 0, 0, 0, 0); // Crack twitchy animation
        this.SetUsingLoopingAnimation(playerid, true);
    }
    
    return 1;
}

// Chat
YCMD:chat(playerid, params[], help)
{
    if (this.CheckAnimationWhileCuffed(playerid)) {
        ApplyAnimation(playerid,"PED","IDLE_CHAT",4.0,0,0,0,1,1);
    }

    return 1;
}

// Deal
YCMD:deal(playerid, params[], help)
{
    if (this.CheckAnimationWhileCuffed(playerid)) {
        ApplyAnimation(playerid, "DEALER", "DEALER_DEAL", 4.0, 0, 0, 0, 0, 0);
    }

    return 1;
}

// Tai Chi
YCMD:taichi(playerid, params[], help)
{
    if (this.CheckAnimationWhileCuffed(playerid)) {
        ApplyAnimation(playerid,"PARK","Tai_Chi_Loop",4.0,1,0,0,0,0);
        this.SetUsingLoopingAnimation(playerid, true);
    }

    return 1;
}

// Hide
YCMD:hide(playerid, params[], help)
{
    if (this.CheckAnimationWhileCuffed(playerid)) {
        ApplyAnimation(playerid, "ped", "cower", 3.0, 1, 0, 0, 0, 0);
        this.SetUsingLoopingAnimation(playerid, true);
    }

    return 1;
}

// Ground Sit
YCMD:gro(playerid, params[], help)
{
	if (this.CheckAnimationWhileCuffed(playerid)) {
        ApplyAnimation(playerid,"BEACH", "ParkSit_M_loop", 4.0, 1, 0, 0, 0, 0);
        this.SetUsingLoopingAnimation(playerid, true);
    }

    return 1;
}

// Slap ass
YCMD:slapass(playerid, params[], help)
{
    if (this.CheckAnimationWhileCuffed(playerid)) {
        ApplyAnimation(playerid, "SWEET", "sweet_ass_slap", 4.0, 0, 0, 0, 0, 0);
        this.SetUsingLoopingAnimation(playerid, true);
    }

    return 1;
}

// Fuck you!
YCMD:fucku(playerid, params[], help)
{
    if (this.CheckAnimationWhileCuffed(playerid)) {
        ApplyAnimation(playerid,"PED","fucku",4.0,0,0,0,0,0);
        this.SetUsingLoopingAnimation(playerid, true);
    }
    
    return 1;
}

// Hands up!
YCMD:handsup(playerid, params[], help)
{
    if (this.CheckAnimationWhileCuffed(playerid)) {
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_HANDSUP);
        Player.Info[playerid][IsSubmitting] = true;
        GameTextForPlayer(playerid, "~p~~n~~n~Press the fire button to stop the animation.", 5000, 3);
    }

    return 1;
}

// Rapping (cases)
YCMD:rap(playerid, params[], help)
{
    new rapID;
	if (sscanf(params, "d", rapID) || 0 < rapID < 5 || help) {
        SendClientUsage(playerid, "/rap [1 - 4]");
        return 1;
    }

    if (this.CheckAnimationWhileCuffed(playerid)) {
        switch (rapID)
        {
            case 1: {
                ApplyAnimation(playerid,"RAPPING","RAP_A_Loop",4.0,1,0,0,0,0);
            }
            case 2: {
                ApplyAnimation(playerid,"RAPPING","RAP_C_Loop",4.0,1,0,0,0,0);
            }
            case 3: {
                ApplyAnimation(playerid,"GANGS","prtial_gngtlkD",4.0,1,0,0,0,0);
            }
            case 4: {
                ApplyAnimation(playerid,"GANGS","prtial_gngtlkH",4.0,1,0,0,1,1);
            }
        }
        this.SetUsingLoopingAnimation(playerid, true);
    }

    return 1;
}

// Dancing (cases)
YCMD:dance(playerid, params[], help)
{
	new danceID;
	if (sscanf(params, "d", danceID) || 0 < danceID < 5 || help) {
        SendClientUsage(playerid, "/dance [1 - 4]");
        return 1;
    }

	if (this.CheckAnimationWhileCuffed(playerid)) {
        switch(danceID) {
            case 1: SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE1);
            case 2: SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE2);
            case 3: SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE3);
            case 4: SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE4);
        }
    }

    return 1;
}

// Smoking (cases)
YCMD:smoke(playerid, params[], help)
{
	new smokeID;
	if (sscanf(params, "d", smokeID) || 0 < smokeID < 5 || help) {
        SendClientUsage(playerid, "/smoke [1 - 4]");
        return 1;
    }

	if (this.CheckAnimationWhileCuffed(playerid)) {
        switch(smokeID)
        {
            case 1: {
                ApplyAnimation(playerid,"SMOKING", "M_smklean_loop", 4.0, 1, 0, 0, 0, 0); // male so what ifi just copy/paste the case
            }
            case 2: {
                ApplyAnimation(playerid,"SMOKING", "F_smklean_loop", 4.0, 1, 0, 0, 0, 0); //female
            }
            case 3: {
                ApplyAnimation(playerid,"SMOKING","M_smkstnd_loop", 4.0, 1, 0, 0, 0, 0); // standing-fucked
            }
            case 4: {
                ApplyAnimation(playerid,"SMOKING","M_smk_out", 4.0, 1, 0, 0, 0, 0); // standing
            }
        }
        this.SetUsingLoopingAnimation(playerid, true);
    }

    return 1;
}

// Run (cases)
YCMD:run(playerid, params[], help)
{
	new runID;
	if (sscanf(params, "d", runID) || help) {
        SendClientUsage(playerid, "/run [1 - 7]");
        return 1;
    }

	if (this.CheckAnimationWhileCuffed(playerid)) {
        switch(runID)
        {
            case 1: {
                ApplyAnimation(playerid,"FAT", "FATRUN", 4.1, 1, 1, 1, 1, 1); // run fatty
            }
            case 2: {
                ApplyAnimation(playerid,"MUSCULAR", "MUSCLERUN", 4.1, 1, 1, 1, 1, 1); // musclehead run
            }
            case 3: {
                ApplyAnimation(playerid,"PED", "RUN_CIVI", 4.1, 1, 1, 1, 1, 1); // civ run
            }
            case 4: {
                ApplyAnimation(playerid,"PED", "RUN_OLD", 4.1, 1, 1, 1, 1, 1); // oldie run
            }
            case 5: {
                ApplyAnimation(playerid,"PED", "RUN_GANG1", 4.1, 1, 1, 1, 1, 1); // gang member run
            }
            case 6: {
                ApplyAnimation(playerid,"PED", "WOMAN_RUN", 4.1, 1, 1, 1, 1, 1); // woman run
            }
            case 7: {
                ApplyAnimation(playerid,"PED", "WOMAN_RUNPANIC", 4.1, 1, 1, 1, 1, 1); // woman run, panicked
            }
        }
        this.SetUsingLoopingAnimation(playerid, true);
    }

    return 1;
}

// Walking (cases)
YCMD:walk(playerid, params[], help)
{
	new walkID;
	if (sscanf(params, "d", walkID) || help) {
        SendClientUsage(playerid, "/walk [1 - 9]");
        return 1;
    }

	if (this.CheckAnimationWhileCuffed(playerid)) {
        switch(walkID)
        {
            case 1: {
                ApplyAnimation(playerid,"PED","WALK_GANG1", 4.1, 1, 1, 1, 1, 1); // gang 1
            }
            case 2: {
                ApplyAnimation(playerid,"PED","WALK_GANG2", 4.1, 1, 1, 1, 1, 1); // gang 2
            }
            case 3: {
                ApplyAnimation(playerid,"PED","WALK_FAT", 4.1, 1, 1, 1, 1, 1); // fat!
            }
            case 4: {
                ApplyAnimation(playerid,"PED","WALK_FATOLD", 4.1, 1, 1, 1, 1, 1); // fat and old!!!
            }
            case 5: {
                ApplyAnimation(playerid,"PED","WALK_OLD", 4.1, 1, 1, 1, 1, 1); // just old
            }
            case 6: {
                ApplyAnimation(playerid,"PED","WOMAN_WALKNORM", 4.1, 1, 1, 1, 1, 1); // regular chick
            }
            case 7: {
                ApplyAnimation(playerid,"PED","WOMAN_WALKSEXY", 4.1, 1, 1, 1, 1, 1); // sexay chick
            }
            case 8: {
                ApplyAnimation(playerid,"MUSCULAR","MUSCLEWALK", 4.1, 1, 1, 1, 1, 1); // muscle walk? geodude
            }
            case 9: {
                ApplyAnimation(playerid,"PED","WALK_WUZI", 4.1, 1, 1, 1, 1, 1); // blind? woozie
            }
        }
        this.SetUsingLoopingAnimation(playerid, true);
    }

    return 1;
}

// Cell phone in and out - Player Special Action??
YCMD:cellin(playerid, params[], help)
{
    if (this.CheckAnimationWhileCuffed(playerid)) {
        SetPlayerSpecialAction(playerid,SPECIAL_ACTION_USECELLPHONE);
        GameTextForPlayer(playerid, "~p~~n~~n~Type /cellout to put your phone away.", 5000, 1);
    }

    return 1;
}

YCMD:cellout(playerid, params[], help)
{
    if (this.CheckAnimationWhileCuffed(playerid)) {
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_STOPUSECELLPHONE);
    }
   	
    return 1;
}

// Vomit
YCMD:vomit(playerid, params[], help)
{
    if (this.CheckAnimationWhileCuffed(playerid)) {
        ApplyAnimation(playerid, "FOOD", "EAT_Vomit_P", 3.0, 0, 0, 0, 0, 0);
    }

    return 1;
}

// Light Cig
YCMD:lightcig(playerid, params[], help)
{
    if (this.CheckAnimationWhileCuffed(playerid)) {
        ApplyAnimation(playerid,"SMOKING","M_smk_in",3.0,0,0,0,0,0);
    }

    return 1;
}

// Lookout
YCMD:lookout(playerid, params[], help)
{
    if (this.CheckAnimationWhileCuffed(playerid)) {
        ApplyAnimation(playerid, "SHOP", "ROB_Shifty", 4.0, 0, 0, 0, 0, 0);
    }

    return 1;
}

// Eat (/eatanim)
YCMD:eatanim(playerid, params[], help)
{
    if (this.CheckAnimationWhileCuffed(playerid)) {
        ApplyAnimation(playerid, "FOOD", "EAT_Burger", 3.0, 0, 0, 0, 0, 0);
    }

    return 1;
}

// sideways
YCMD:sideways(playerid, params[], help)
{
    if (IsPlayerAdmin(playerid))
    {
        ApplyAnimation(playerid,"ROB_BANK","CAT_Safe_Open_O",4.1,0,1,1,1,1);
    }
    return 1;
}

// piss
YCMD:piss(playerid, params[], help)
{
    SetPlayerSpecialAction(playerid, SPECIAL_ACTION_PISS); // piss anim
    // SendClientMessage(playerid, COLOR_HOTPINK, "THIS IS GOING TO COST YOU 5MILLION ROLEPLAY POINTS PER SECOND");
    GameTextForPlayer(playerid, "~p~5~h~0~p~0~h~0~p~0 ~h~[]~r~ROLEPLAY~p~~h~[]~r~POINTS~p~~h~[]", 2000, 5);
    return 1;
}

// /stopani
YCMD:stopani(playerid, params[], help)
{
	if (this.CheckAnimationWhileCuffed(playerid)) {
        Player.Info[playerid][IsSubmitting] = false;
        this.SetUsingLoopingAnimation(playerid, false);
        SendClientUsage(playerid, "All animations cleared.");
	}

    return 1;
}
