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
    	SendClientUsage(playerid, "/veh [Car ID] [Color 1 (Optional)] [Color 2 (Optional)]");
    	return 1;
    } 

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

CommandDescription<paint> = @"A shiny new paint job for your vehicle.";
YCMD:paint(playerid, params[], help) {
    new color1, color2;

    if (sscanf(params, "iI(1)", color1, color2)) {
        SendClientUsage(playerid, "/paint [Color 1] [Color 2 (Optional)]");
        return 1;
    }

    new vehicleID = GetPlayerVehicleID(playerid);
    if (vehicleID == 0) {
        SendClientUsage(playerid, "You must be in a vehicle give it a new paint job.");
        return 1;
    } else {
        // Update the vehicle's color
        ChangeVehicleColor(vehicleID, color1, color2);
    }

    return 1;
}

CommandDescription<nos> = @"Add nitrous to your vehicle.";
YCMD:nos(playerid, params[], help) {
    new vehicleID = GetPlayerVehicleID(playerid);
    if (vehicleID == 0) {
        SendClientUsage(playerid, "You must be in a vehicle to add NOS.");
        return 1;
    }

    // Add the NOS component to this vehicle
    AddVehicleComponent(vehicleID, COMPONENT_NOS);

    return 1;
}

CommandDescription<fix> = @"Fully repair your vehicle.";
YCMD:fix(playerid, params[], help) {
    new vehicleID = GetPlayerVehicleID(playerid);
    if (vehicleID == 0) {
        SendClientUsage(playerid, "You must be in a vehicle to repair it.");
        return 1;
    } else {
        SetVehicleHealth(vehicleID, 1000.0);
    }
    return 1;
}