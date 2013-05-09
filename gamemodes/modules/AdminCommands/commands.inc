/*!
 * AdminCommands/commands.inc
 *
 > Priority: 0
 */

CommandDescription<banish> = @"Banish a player to purgatory.";
YCMD(GROUP_MANAGEMENT, GROUP_RCON):banish(playerid, params[], help) {
	new banishPlayerID;
	// Parse the player name or ID
    if (sscanf(params, "k<player_name>", banishPlayerID)) {
        SendClientUsage(playerid, "/banish [Player name or ID]");
        return 1;
    } 

    // Track who is banished
    this.isBanished[banishPlayerID] = true;

	SetPlayerPos(banishPlayerID, 12465404.00,124417920.00,1043113472.00);
    SetPlayerInterior(banishPlayerID, 6);

    return 1;
}

CommandDescription<unbanish> = @"Remove a player from purgatory.";
YCMD(GROUP_MANAGEMENT, GROUP_RCON):unbanish(playerid, params[], help) {
	new banishPlayerID;
	// Parse the player name or ID
    if (sscanf(params, "k<player_name>", banishPlayerID)) {
        SendClientUsage(playerid, "/unbanish [Player name or ID]");
        return 1;
    } 

    // Track who is banished
    this.isBanished[banishPlayerID] = false;

	SetPlayerPos(banishPlayerID, 240.0390, -178.2970, 1.5781);
    SetPlayerInterior(banishPlayerID, 0);

    return 1;
}