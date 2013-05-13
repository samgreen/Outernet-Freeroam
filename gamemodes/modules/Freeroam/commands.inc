/*!
 * Freeroam/commands.inc
 *
 > Priority: 0
 */


CommandDescription<gun> = @"Give yourself a weapon.";
YCMD:gun(playerid, params[], help) {
	new weapon;

	// Parse the weapon name or ID
	if (sscanf(params, "k<weapon>", weapon)) {
		SendClientUsage(playerid, "/gun [Part of name or PlayerID] [Weapon name/ID]");
		return 1;	
	}

    // Give the player this weapon with default ammo, and activate it
    GivePlayerWeapon(playerid, weapon, AMMO);
    SetPlayerArmedWeapon(playerid, weapon);
        
	return 1;
}

CommandDescription<goto> = @"Teleport to a player.";
YCMD:goto(playerid, params[], help) {
	new otherPlayerID;

	// Parse the player name or ID
	if (sscanf(params, "K<player_name>", otherPlayerID)) {
        SendClientUsage(playerid, "/goto [Part of name or PlayerID]");
    	return 1;
	}

    // Retrieve the other player's position
    new Float:x, Float:y, Float:z;
    GetPlayerPos(otherPlayerID, x, y, z);

    this.TeleportToWithVehicle(playerid, x, y, z);

	return 1;
}

CommandDescription<gotop> = @"Teleport to a place.";
YCMD:gotop(playerid, params[], help) {
    new placeName[32];

    // Parse the player name or ID
    if (sscanf(params, "s[32]", placeName)) {
        SendClientUsage(playerid, "/goto [Part of name or PlayerID]");
        SendClientUsage(playerid, "places: taxi corp1 corp2 pd lsair sfair lvair pier underwater boat mafjump skyscraper coalminer");
        SendClientUsage(playerid, "chiliad drift wheelarch locolow transfender halfpipe bridgetop lombardstreet skatepark casino skydive");
        SendClientUsage(playerid, "smokespot fc lb eq boneyard process cropdust trucker");
        return 1;
    }

    this.TeleportToPlace(playerid, placeName);

    return 1;
}

CommandDescription<joinoj> = @"Join the OJ minigame.";
YCMD:joinoj(playerid, params[], help) {
    OJ.Join(playerid);

    return 1;
}

CommandDescription<join> = @"Join a minigame.";
YCMD:join(playerid, params[], help) {
    new string:gameName[10];

    // Parse the player name or ID
    if (sscanf(params, "s[10]", gameName)) {
        SendClientUsage(playerid, "/join [OJ | King | Gumball]");
        return 1;
    }

    if (strcmp(gameName, "OJ", true) == 0) {
        OJ.Join(playerid);
    } else if (strcmp(gameName, "King", true) == 0) {
        King.Join(playerid);
    } else if (strcmp(gameName, "Gumball", true) == 0) {
        Gumball.Join(playerid);
    }

    return 1;
}

CommandDescription<skin> = @"Set your player skin.";
YCMD:skin(playerid, params[], help) {
    new skinID;

    // Parse the player name or ID
    if (sscanf(params, "i", skinID)) {
        SendClientUsage(playerid, "/skin [SkinID]");
        return 1;
    }

    if (!IsValidSkin(skinID)) {
        SendClientMessage(playerid, COLOR_COMMAND_ERROR, "Invalid Skin ID.");
    } else {
        SetPlayerSkin(playerid, skinID);
    }

    return 1;
}