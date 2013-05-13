/*!
 * AdminCommands/commands.inc
 *
 > Priority: 0
 */

CommandDescription<banish> = @"Banish a player to purgatory.";
YCMD(GROUP_MANAGEMENT, GROUP_RCON):banish(playerid, params[], help) {
	new banishPlayerID;
	// Parse the player name or ID
    if (sscanf(params, "k<player_name>", banishPlayerID) || help) {
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
    if (sscanf(params, "k<player_name>", banishPlayerID) || help) {
        SendClientUsage(playerid, "/unbanish [Player name or ID]");
        return 1;
    } 

    // Track who is banished
    this.isBanished[banishPlayerID] = false;

	SetPlayerPos(banishPlayerID, 240.0390, -178.2970, 1.5781);
    SetPlayerInterior(banishPlayerID, 0);

    return 1;
}

CommandDescription<kick> = @"Kicks the player from the server temporarily.";
YCMD(GROUP_MANAGEMENT, GROUP_RCON):kick(playerid, params[], help) {
    new kickPlayerID;
    // Parse the player name or ID
    if (sscanf(params, "k<player_name>", kickPlayerID) || help) {
        SendClientUsage(playerid, "/kick [Player name or ID]");
        return 1;
    } 
    
    Kick(kickPlayerID);

    return 1;
}

CommandDescription<check> = @"Retrieve information about a player.";
YCMD(GROUP_MANAGEMENT, GROUP_RCON):check(playerid, params[], help) {
    new checkPlayerID;
    if (sscanf(params, "k<player_name>", checkPlayerID) || help) {
        SendClientUsage(playerid, "/check [Player name or ID]");
        return 1;
    }

    SendClientMessage(playerid, COLOR_GENERIC_INFO, "%s - IP: %s (%s) - Ping: %d", Player.Info[playerid][Name], Player.Info[playerid][IP], Player.Info[playerid][Location], Player.Info[playerid][Ping]);

    return 1;
}

CommandDescription<weather> = @"Updates the current weather status.";
YCMD(GROUP_MANAGEMENT, GROUP_RCON):weather(playerid, params[], help) {
    new weatherID;
    if (sscanf(params, "d", weatherID) || help) {
        SendClientUsage(playerid, "/weather [Player name or ID]");
        return 1;
    }

    SetWeather(weatherID);

    return 1;
}
