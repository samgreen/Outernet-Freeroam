/*!
 * PBP/Player/callbacks/OnPlayerConnect.inc
 *
 * OnPlayerConnect(playerid)
 *
 > Priority: 9
 */

{
	
	// Reset the player info
	memset(Player.Info[playerid], sizeof(Player.Info[]), 0);
	
	// Every player starts as level 1
	Player.Info[playerid][Level] = 1;

	GetPlayerIp(playerid, Player.Info[playerid][IP], sizeof(Player.Info[playerid][IP]));
	GetPlayerName(playerid, Player.Info[playerid][Name], MAX_PLAYER_NAME);

	new req[128];
	format(req, sizeof(req), "geoip.freevar.com/?IP=%s", Player.Info[playerid][IP]); 
	HTTP(playerid, HTTP_GET, req, "", "GEOIP_HTTPREQUEST");
}