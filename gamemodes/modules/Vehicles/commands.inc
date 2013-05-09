/*!
 * Vehicles/commands.inc
 *
 > Priority: 0
 */

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