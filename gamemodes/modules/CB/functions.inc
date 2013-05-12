/*!
 * CB/functions.inc
 *
 > Priority: 0
 */

stock this.OnSameChannel(playerID, otherPlayerID) {
	return (this.Info[otherPlayerID][Channel] == this.Info[playerID][Channel]);
}

stock this.SetChannel(playerid, channel) {
	this.Info[playerid][Channel] = channel;
}

stock this.CanUse(playerid, bool:checkOwned = true) {
	if (checkOwned) {
	    if (Inventory.Info[playerid][ItemCB] == 0) {
	    	SendClientMessage(playerid, -1, "{FF0000}>>{FFFFFF} You {FF0000}Don't Have{FFFFFF} A Radio You Need To Buy One First {FF0000}(/cbhelp)");
	    	return false;
	    }
	}
	if (this.Info[playerid][Status] == 0) {
		SendClientMessage(playerid, -1, "{FF0000}>>{FFFFFF} Your Radio Is Turned Off Turn It On Using {FF0000}(/setcb)");
		return false;
	}			

	return true;
}
