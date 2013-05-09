/*!
 * King/functions.inc
 *
 > Priority: 0
 */

stock this.Setup() {
    if (this.active) return 1;

	this.locationIndex = random(4);
    this.active = true;

    return 1;
}

stock this.Teardown() {

	this.active = false;
}

stock this.TeleportTo(playerid) {
    // If this is the first player, we need to setup the game
    if (!this.active) this.Setup();

	// King of the Mountain teleports (different building-tops of varying size/complexity:
	switch(this.locationIndex) {
        case 0: SetPlayerPos(playerid,1576.1821,-1241.3708,277.8767);
        case 1: SetPlayerPos(playerid,-1955.4894,631.0583,145.3173); 
        case 2: SetPlayerPos(playerid,-1943.9519,535.8376,209.4050); 
        case 3: SetPlayerPos(playerid,-1809.5675,574.1158,234.8906); 
        case 4: SetPlayerPos(playerid,-353.8105,1531.0774,75.3594);
    }

    SendClientMessage(playerid, COLOR_COMMAND_INFO, "You have joined the King of the Hill minigame.");
}

