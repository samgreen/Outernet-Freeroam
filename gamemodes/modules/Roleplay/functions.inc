/*!
 * Roleplay/functions.inc
 *
 > Priority: 0
 */

stock this.Join(playerid) {
	Freeroam.Quit(playerid);
	
    Group_SetPlayer(GROUP_ROLEPLAY, playerid, true);

    // First, create the textdraw
    this.statusText[playerid] = CreatePlayerTextDraw(playerid, 638.0, 2.0, "Roleplay");
    PlayerTextDrawAlignment(playerid, PlayerText:this.statusText[playerid], 3);
    PlayerTextDrawFont(playerid, PlayerText:this.statusText[playerid], 2);
    PlayerTextDrawColor(playerid, PlayerText:this.statusText[playerid], COLOR_PURPLE);
    PlayerTextDrawShow(playerid, PlayerText:this.statusText[playerid]);
}

stock this.Quit(playerid) {
    Group_SetPlayer(GROUP_ROLEPLAY, playerid, false);

    PlayerTextDrawDestroy(playerid, PlayerText:this.statusText[playerid]);
}

stock bool:this.In(playerid) {
    return Group_GetPlayer(GROUP_ROLEPLAY, playerid);
}