/*!
 * Freeroam/commands.inc
 *
 > Priority: 0
 */


CommandDescription<gun> = @"/givegun [Part of name or PlayerID] [Weapon name/ID]";
YCMD:gun(playerid, params[], help) {
	new weapon;

	// Parse the weapon name or ID
	if (sscanf(params, "k<weapon>", weapon)) {
		// SendClientUsage(playerid, this.Description);
		return 1;	
	} else {
		// Give the player this weapon with default ammo, and activate it
		GivePlayerWeapon(playerid, weapon, AMMO);
    	SetPlayerArmedWeapon(playerid, weapon);
	}
        
	return 1;
}

CommandDescription<veh> = @"/veh [Car ID] [Color 1 (Optional)] [Color 2 (Optional)]";
YCMD:veh(playerid, params[], help) {
    new vehicleID, color1, color2;

    // Parse the name or vehicle ID, and the first color, followed by an optional color
    if (sscanf(params, "k<vehicle>I(0)I(0)", vehicleID, color1, color2)) {
    	// SendClientUsage(playerid, this.Description);
    	return 1;
    } else {

		// Ensure the player isn't already in a vehicle
	    if (IsPlayerInAnyVehicle(playerid)) { 
	    	// Save their current vehicle ID
	    	new oldVehicleID = GetPlayerVehicleID(playerid);
	    	// Remove the player from the vehicle and destroy it
	    	RemovePlayerFromVehicle(oldVehicleID);
	    	DestroyVehicle(oldVehicleID);
	    }

    	// Ensure it is a valid vehicle ID
    	if (vehicleID != 1) {

    		// Retrieve the player's position and facing angle
     		new Float:x, Float:y, Float:z, Float:ang;
            GetPlayerPos(playerid, x, y, z);
            GetPlayerFacingAngle(playerid, ang);

            // Create the vehicle and save the car ID
            new newCarID = CreateVehicle(vehicleID, x, y, z, ang, color1, color2, 600000);
            // Get the current interior and link the vehicle to it
            new interior = GetPlayerInterior(playerid);
            LinkVehicleToInterior(newCarID, interior);

            // Finally place this player in their vehicle
            PutPlayerInVehicle(playerid, newCarID, 0);
    	}
    }

    return 1;
}

CommandDescription<goto> = @"/goto [Part of name or PlayerID]";
YCMD:goto(playerid, params[], help) {
	new otherPlayerID;

	// Parse the player name or ID
	if (sscanf(params, "k<player_name>", otherPlayerID)) {
		// SendClientUsage(playerid, this.Description);
    	return 1;
	} else {
		// Retrieve the other player's position
        new Float:x, Float:y, Float:z;
        GetPlayerPos(otherPlayerID, x, y, z);

        // Set this player's position, interior, and virtual world to match the other player
        SetPlayerPos(playerid, x, y, z);
        SetPlayerInterior(playerid, GetPlayerInterior(otherPlayerID));
        SetPlayerVirtualWorld(playerid, GetPlayerVirtualWorld(otherPlayerID));
	}

	return 1;
}

CommandDescription<skin> = @"/skin [SkinID]";
YCMD:skin(playerid, params[], help) {
    new skinID;

    // Parse the player name or ID
    if (sscanf(params, "i", skinID)) {
        // SendClientUsage(playerid, this.Description);
        return 1;
    } else {
        if (!IsValidSkin(skinID)) {
            SendClientMessage(playerid, COLOR_COMMAND_ERROR, "Invalid Skin ID.");
            return 1;
        } else {
            SetPlayerSkin(playerid, skinID);
        }
    }

    return 1;
}