/*!
 * Roleplay/commands.inc
 *
 > Priority: 0
 */

CommandDescription<joinrp> = @"Join the Roleplay world.";
YCMD:joinrp(playerid, params[], help) {
	this.Join(playerid);
        
    return 1;
}

CommandDescription<dice> = @"Roll any sided die.";
YCMD(GROUP_ROLEPLAY):dice(playerid, params[], help) {
    new numSides;
    if (sscanf(params, "d", numSides) || help) {
        SendClientUsage(playerid, "/dice [Number of Sides]");
        return 1;
    }
    
    SendClientMessageEmote(playerid, "%p rolls a %d-sided die. The result is a %d", numSides, random(numSides));

    return 1;
}