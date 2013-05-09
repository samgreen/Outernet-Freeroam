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
		SendClientUsage(playerid, "/givegun [Part of name or PlayerID] [Weapon name/ID]");
		return 1;	
	}

    // Give the player this weapon with default ammo, and activate it
    GivePlayerWeapon(playerid, weapon, AMMO);
    SetPlayerArmedWeapon(playerid, weapon);
        
	return 1;
}

CommandDescription<veh> = @"Spawn a vehicle.";
YCMD:veh(playerid, params[], help) {
    new vehicleID, color1, color2;

    // Parse the name or vehicle ID, and the first color, followed by an optional color
    if (sscanf(params, "k<vehicle>I(0)I(0)", vehicleID, color1, color2)) {
    	SendClientUsage(playerid, "/veh [Vehicle ID] [Color 1 (Optional)] [Color 2 (Optional)]");
    	return 1;
    } 

	// // Ensure the player isn't already in a vehicle
 //    if (IsPlayerInAnyVehicle(playerid)) { 
 //    	// Save their current vehicle ID
 //    	new oldVehicleID = GetPlayerVehicleID(playerid);
 //    	// Remove the player from the vehicle and destroy it
 //    	RemovePlayerFromVehicle(oldVehicleID);
 //    	DestroyVehicle(oldVehicleID);
 //    }

	// Ensure it is a valid vehicle ID
	if (vehicleID != 1) {
		SpawnAndEnterVehicle(playerid, vehicleID, color1, color2);
	}

    return 1;
}

CommandDescription<goto> = @"Teleport to a player or minigame.";
YCMD:goto(playerid, params[], help) {
	new otherPlayerID;

	// Parse the player name or ID
	if (sscanf(params, "k<player_name>", otherPlayerID)) {
		SendClientUsage(playerid, "/goto [Part of name or PlayerID]");
    	return 1;
	} 

	// Retrieve the other player's position
    new Float:x, Float:y, Float:z;
    GetPlayerPos(otherPlayerID, x, y, z);

    // Set this player's position, interior, and virtual world to match the other player
    SetPlayerPos(playerid, x, y, z);
    SetPlayerInterior(playerid, GetPlayerInterior(otherPlayerID));
    SetPlayerVirtualWorld(playerid, GetPlayerVirtualWorld(otherPlayerID));

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
        return 1;
    } else {
        SetPlayerSkin(playerid, skinID);
    }

    return 1;
}