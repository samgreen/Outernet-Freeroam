/*!
 * Vehicles/commands.inc
 *
 > Priority: 0
 */

CommandDescription<veh> = @"Spawn a vehicle.";
YCMD(GROUP_FREEROAM):veh(playerid, params[], help) {
    new vehicleID, color1, color2;

    // Parse the name or vehicle ID, and the first color, followed by an optional color
    if (sscanf(params, "k<vehicle>I(0)I(0)", vehicleID, color1, color2)) {
        SendClientUsage(playerid, "/veh [Vehicle ID] [Color 1 (Optional)] [Color 2 (Optional)]");
        return 1;
    }

    new oldVehicleID = GetPlayerVehicleID(playerid);
    if (oldVehicleID > 0) {
        // Remove the player from the vehicle and destroy it
        // RemovePlayerFromVehicle(oldVehicleID);
        DestroyVehicle(oldVehicleID);
    }

    SpawnAndEnterVehicle(playerid, vehicleID, color1, color2);

    return 1;
}

CommandDescription<eject> = @"Eject a player from a vehicle you are driving.";
YCMD:eject(playerid, params[], help) {
    new ejectPlayerID;

    // Parse the name or vehicle ID, and the first color, followed by an optional color
    if (sscanf(params, "k<player_name>I(0)I(0)", ejectPlayerID)) {
        SendClientUsage(playerid, "/eject [Player Name or ID]");
        return 1;
    }

    // Ensure the player is driving a vehicle
    if (GetPlayerState(playerid) == PLAYER_STATE_DRIVER) { 
    
        // Are the player, and the player to be ejected in the same vehicle?
        if (GetPlayerVehicleID(playerid) == GetPlayerVehicleID(ejectPlayerID)) {
            
            // Remove the player from their vehicle
            RemovePlayerFromVehicle(ejectPlayerID);

            SendClientMessageEmote(playerid, "%s opens the door and shoves %s out of the vehicle.", Player.Info[playerid][Name], Player.Info[ejectPlayerID][Name]);
            
        } else return SendClientError(playerid, "That player must be in your car to eject them.");
        
    } else return SendClientError(playerid, "You must be driving a car to eject a player.");

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
    if (OJ.In(playerid)) {
        SendClientMessage(playerid, COLOR_COMMAND_ERROR, "You may not use NOS while the OJ minigame is active.");
        return 1;
    }

    new vehicleID = GetPlayerVehicleID(playerid);
    if (vehicleID == 0) {
        SendClientUsage(playerid, "You must be in a vehicle to add NOS.");
        return 1;
    }

    // Add the NOS component to this vehicle
    AddVehicleComponent(vehicleID, COMPONENT_NOS);
    SendClientMessageEmote(playerid, "%s modifies the %v with nitrous.", Player.Info[playerid][Name], GetPlayerVehicleName(playerid));

    return 1;
}

CommandDescription<neon> = @"Add neon lights";
YCMD:neon(playerid, params[], help) {
    if (GetPlayerState(playerid) != PLAYER_STATE_DRIVER) {
        SendClientUsage(playerid, "You must be in a vehicle to add neon.");
        return 1;
    }

    ShowPlayerDialog(playerid, DIALOG_ID_NEON, DIALOG_STYLE_LIST, "Available Neon Colors", "{1500FF}Blue\n{FF0000}Red\n{40FF00}Green\nWhite\n{FF00FB}Pink\n{DDFF00}Yellow\n{9900FF}Remove Neon", "Select", "Cancel");

    return 1;
}

CommandDescription<fix> = @"Fully repair your vehicle.";
YCMD:fix(playerid, params[], help) {
    if (OJ.In(playerid)) {
        SendClientMessage(playerid, COLOR_COMMAND_ERROR, "You may not repair your vehicle while the OJ minigame is active.");
        return 1;
    }

    new vehicleID = GetPlayerVehicleID(playerid);
    if (vehicleID == 0) {
        SendClientUsage(playerid, "You must be in a vehicle to repair it.");
        return 1;
    }

    // Fully repair the vehicle
    SetVehicleHealth(vehicleID, 1000.0);
    SendClientMessageEmote(playerid, "%s repairs the %v.", Player.Info[playerid][Name], GetPlayerVehicleName(playerid));

    return 1;
}