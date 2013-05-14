/*!
 * Freeroam/functions.inc
 *
 > Priority: 0
 */

stock this.Join(playerid) {
    Roleplay.Quit(playerid);

    this.InFreeroam[playerid] = true;

    // First, create the textdraw
    this.statusText[playerid] = CreatePlayerTextDraw(playerid, 640.0, 0.0, "Freeroam");
    PlayerTextDrawAlignment(playerid, PlayerText:this.statusText[playerid], 3);
    PlayerTextDrawShow(playerid, PlayerText:this.statusText[playerid]);
}

stock this.Quit(playerid) {
    this.InFreeroam[playerid] = false;

    PlayerTextDrawDestroy(playerid, PlayerText:this.statusText[playerid]);
}

stock bool:this.In(playerid) {
    return this.InFreeroam[playerid];
}

stock this.TeleportToPlace(playerid, placeName[]) {

	if (strcmp(placeName, "smokespot", true) == 0) {
        this.TeleportToWithVehicle(playerid, 934.9451, -139.8434, 4.1254);
        return 1;
    }

    if (strcmp(placeName, "taxi", true) == 0) {
        this.TeleportToWithVehicle(playerid,-300.9337,1322.2476,54.2912);
        return 1;
    }

    if (strcmp(placeName, "corp1", true) == 0) {
        this.TeleportToWithVehicle(playerid,641.5588,1194.2560,11.7188);
        return 1;
    }

    if (strcmp(placeName, "corp2", true) == 0) {
        this.TeleportToWithVehicle(playerid,-702.7709,954.3311,12.3812);
        return 1;
    }

    if (strcmp(placeName, "pd", true) == 0) {
        this.TeleportToWithVehicle(playerid,213.9422,1903.9194,17.6406);
        return 1;
    }
    
    if (strcmp(placeName, "lsair", true) == 0) {
        this.TeleportToWithVehicle(playerid,2006.3446,-2532.9819,13.5469);
        return 1;
    }
    
    if (strcmp(placeName, "sfair", true) == 0) {
        this.TeleportToWithVehicle(playerid,-1109.7617,374.7649,14.1484);
        return 1;
    }
    
    if (strcmp(placeName, "lvair", true) == 0) {
        this.TeleportToWithVehicle(playerid,1435.2316,1464.0927,10.8203);
        return 1;
    }
    
    if (strcmp(placeName, "pier", true) == 0) {
        this.TeleportToWithVehicle(playerid,835.3309,-2055.8435,12.8672);
        return 1;
    }
    
    if (strcmp(placeName, "chiliad", true) == 0) {
        this.TeleportToWithVehicle(playerid,-2317.3325,-1618.2611,483.7491);
        return 1;
    }
    
    if (strcmp(placeName, "drift", true) == 0) {
        this.TeleportToWithVehicle(playerid,-2402.9199,-597.4742,132.6484);
        return 1;
    }
    
    if (strcmp(placeName, "wheelarch", true) == 0) {
        this.TeleportToWithVehicle(playerid,-2705.5552,218.5947,4.1797);
        return 1;
    }
    
    if (strcmp(placeName, "locolow", true) == 0) {
        this.TeleportToWithVehicle(playerid,2646.9751,-2004.6864,13.3828);
        return 1;
    }
    
    if (strcmp(placeName, "transfender", true) == 0) {
        this.TeleportToWithVehicle(playerid,-1936.0275,228.9241,34.1563);
        return 1;
    }
    
    if (strcmp(placeName, "coalminer", true) == 0) {
        this.TeleportToWithVehicle(playerid,858.2095,867.3469,13.3516);
        return 1;
    }
    
    if (strcmp(placeName, "skatepark", true) == 0) {
        this.TeleportToWithVehicle(playerid,1882.3457,-1394.2074,13.5703);
        return 1;
    }
    
    if (strcmp(placeName, "skyscraper", true) == 0) {
        this.TeleportToWithVehicle(playerid,1543.8177,-1353.3562,329.4742);
        return 1;
    }
    
    if (strcmp(placeName, "mafjump", true) == 0) {
        this.TeleportToWithVehicle(playerid,1311.2545,-1767.1433,13.3828);
        return 1;
    }
    
    if (strcmp(placeName, "lombardstreet", true) == 0) {
        this.TeleportToWithVehicle(playerid,-2138.5032,918.8997,79.8516);
        return 1;
    }
    
    if (strcmp(placeName, "boat", true) == 0) {
        this.TeleportToWithVehicle(playerid,-2473.3965,1541.1923,36.8047);
        return 1;
    }
    
    if (strcmp(placeName, "bridgetop", true) == 0) {
        this.TeleportToWithVehicle(playerid,-2678.0583,1595.1338,217.2739);
        return 1;
    }
    
    if (strcmp(placeName, "halfpipe", true) == 0) {
        this.TeleportToWithVehicle(playerid,-1642.9333,100.1801,-11.1626);
        return 1;
    }
    
    if (strcmp(placeName, "underwater", true) == 0) {
        this.TeleportToWithVehicle(playerid,-1687.6527,172.3593,-51.7813);
        return 1;
    }
    
    if (strcmp(placeName, "casino", true) == 0) {
        this.TeleportToWithVehicle(playerid,-524.9528,2592.3601,53.4141);
        return 1;
    }
    
    if (strcmp(placeName, "skydive", true) == 0) {
        this.TeleportToWithVehicle(playerid,443.1121,662.1830,4755.9175);
        return 1;
    }
    
    if (strcmp(placeName, "smokespot", true) == 0) {
        this.TeleportToWithVehicle(playerid,770.8389,3778.0808,8.5173);
        return 1;
    }
    
    if (strcmp(placeName, "fc", true) == 0) {
        this.TeleportToWithVehicle(playerid,-191.8151,1099.8364,19.5938);
        return 1;
    }
    
    if (strcmp(placeName, "lb", true) == 0) {
        this.TeleportToWithVehicle(playerid,-844.7393,1546.5504,23.1495);
        return 1;
    }
    
    if (strcmp(placeName, "eq", true) == 0) {
        this.TeleportToWithVehicle(playerid,-1495.7999,2603.5476,55.6929);
        return 1;
    }
    
    if (strcmp(placeName, "boneyard", true) == 0) {
        this.TeleportToWithVehicle(playerid,339.1008,2500.8767,16.4844);
        return 1;
    }
    
    if (strcmp(placeName, "process", true) == 0) {				
        this.TeleportToWithVehicle(playerid,-928.9985, 2022.5295, 60.9141);
        return 1;
    }
    
    if (strcmp(placeName, "cropdust", true) == 0) {				
        this.TeleportToWithVehicle(playerid,-156.5437, 39.6247, 3.1172);
        return 1;
    }
    
    if (strcmp(placeName, "trucker", true) == 0) {				
        this.TeleportToWithVehicle(playerid, 607.6465, 1669.4261, 7.1712);
        return 1;
    }		

    if (strcmp(placeName, "ubermotors", true) == 0) {				
        this.TeleportToWithVehicle(playerid, 1094.1666, 1599.0883, 12.5469);
        return 1;
    }
    
    // if (strcmp(placeName, "hotel1", true) == 0)
    // {				
    //     this.TeleportToWithVehicle(playerid, 2251.85, -1138.16, 1050.63);
    //     SetPlayerInterior(playerid, 9);
    //     return 1;
    // }
    // if (strcmp(placeName, "hotel2", true) == 0)
    // {				
    //     this.TeleportToWithVehicle(playerid, 2259.5757, -1135.9651, 1050.6328);
    //     SetPlayerInterior(playerid, 10);
    //     return 1;
    // }
    // if (strcmp(placeName, "hotel3", true) == 0) {				
    //     this.TeleportToWithVehicle(playerid, 444.646911, 508.239044, 1001.419494);
    //     SetPlayerInterior(playerid, 12);
    //     return 1;
    // }
    

    return -1;
}

stock this.TeleportToWithVehicle(playerid, Float:x, Float:y, Float:z) {
    // Check if the player is in a vehicle
    new vehicleID = GetPlayerVehicleID(playerid);
    if (vehicleID > 0) {
        SetVehiclePos(vehicleID, x, y, z);
        // LinkVehicleToInterior(vehicleID, GetPlayerInterior(otherPlayerID));
    } else {
        SetPlayerPos(playerid, x, y, z);
    }

    // SetPlayerInterior(playerid, GetPlayerInterior(otherPlayerID));
    // SetPlayerVirtualWorld(playerid, GetPlayerVirtualWorld(otherPlayerID));
}