/*!
 * Vehicles/functions.inc
 *
 > Priority: 0
 */

stock bool:CanPlayerSpawnVehicle(playerid) {
	return (this.DYNAMIC_CARS[playerid][0] == 0 || this.DYNAMIC_CARS[playerid][1] == 0 || IsPlayerAdmin(playerid));
}

stock GetPlayerDynamicVehicle(playerid, index) {
	return this.DYNAMIC_CARS[playerid][index];
}

stock SetPlayerDynamicVehicle(playerid, index, vehicleid) {
	return this.DYNAMIC_CARS[playerid][index] = vehicleid;
}

stock GetPlayerVehicleName(playerid) {
    return GetVehicleName(GetPlayerVehicleModel(playerid));
}

stock GetPlayerVehicleModel(playerid) {
    return GetVehicleModel(GetPlayerVehicleID(playerid));
}

stock SpawnAndEnterVehicle(playerid, vehicleid, color1 = 1, color2 = 1) {
	if (!CanPlayerSpawnVehicle(playerid)) {
		DestroyVehicle(this.DYNAMIC_CARS[playerid][0]);
		SetPlayerDynamicVehicle(playerid, 0, 0);
	}

	// Retrieve the player's position and facing angle
	new Float:x, Float:y, Float:z, Float:ang;
    GetPlayerPos(playerid, x, y, z);
    GetPlayerFacingAngle(playerid, ang);

    // Create the vehicle and save the car ID, since players may only spawn one vehicle at a time
    new newCarID = CreateVehicle(vehicleid, x, y, z, ang, color1, color2, 600000);
    if (GetPlayerDynamicVehicle(playerid, 0) == 0) {
    	SetPlayerDynamicVehicle(playerid, 0, newCarID);
    } else {
    	SetPlayerDynamicVehicle(playerid, 1, newCarID);
    }

    // Get the current interior and link the vehicle to it
    new interior = GetPlayerInterior(playerid);
    LinkVehicleToInterior(newCarID, interior);
    
    // Finally place this player in their vehicle
    PutPlayerInVehicle(playerid, newCarID, 0);
}


//
//  Neons - Paul Walker style RP
//
stock CreateNeons(playerid, modelID) {
    SetPVarInt(playerid, "neon1", CreateObject(modelID, 0, 0, 0, 0, 0, 0));
    SetPVarInt(playerid, "neon2", CreateObject(modelID, 0, 0, 0, 0, 0, 0));

    AttachObjectToVehicle(GetPVarInt(playerid, "neon1"), GetPlayerVehicleID(playerid), -0.8, 0.0, -0.70, 0.0, 0.0, 0.0);
    AttachObjectToVehicle(GetPVarInt(playerid, "neon2"), GetPlayerVehicleID(playerid),  0.8, 0.0, -0.70, 0.0, 0.0, 0.0);
}

stock DestroyNeons(playerid) {
    DestroyObject(GetPVarInt(playerid, "neon2")); 
    DestroyObject(GetPVarInt(playerid, "neon1"));
}

stock ShowNeonDialog(playerid) {
    ShowPlayerDialog(playerid, DIALOG_ID_NEON, DIALOG_STYLE_LIST, "Available Neon Colors", "{FF0000}Red\n{40FF00}Green\n{1500FF}Blue\n{FF00FB}Pink\nWhite\n{9900FF}{DDFF00}Yellow\nRemove Neon", "Select", "Cancel");
}