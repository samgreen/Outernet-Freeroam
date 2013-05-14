/*!
 * Roleplay/functions.inc
 *
 > Priority: 0
 */

stock this.Join(playerid) {
	Freeroam.Quit(playerid);
	
	this.InRoleplay[playerid] = true;

    // First, create the textdraw
    this.statusText[playerid] = CreatePlayerTextDraw(playerid, 640.0, 0.0, "Roleplay");
    PlayerTextDrawAlignment(playerid, PlayerText:this.statusText[playerid], 3);
    PlayerTextDrawShow(playerid, PlayerText:this.statusText[playerid]);
}

stock this.Quit(playerid) {
    this.InRoleplay[playerid] = false;

    PlayerTextDrawDestroy(playerid, PlayerText:this.statusText[playerid]);
}

stock bool:this.In(playerid) {
    return this.InRoleplay[playerid];
}