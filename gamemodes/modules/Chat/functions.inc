/*!
 * Chat/functions.inc
 *
 > Priority: 0
 */

stock SendClientUsage(playerid, string:usageText[], color = COLOR_COMMAND_USAGE) {
	SendClientMessage(playerid, color, usageText);
}

stock SendClientMessageEmote(senderid, string:message[]) {
	SendClientMessageNearby(senderid, message, COLOR_EMOTE);
}

stock SendClientMessageNearby(senderid, string:message[], color = COLOR_WHITE) {
	foreach (new playerid : Player) {
		if (playerid == senderid) continue;

		SendClientMessage(playerid, color, message);
	}
	SendClientMessageRadius(senderid, message, color, 25.0);
}

stock SendClientMessageRadius(senderid, string:message[], color = COLOR_WHITE, Float:radius = 20.0) {
	foreach (new playerid : Player) {
		if (playerid == senderid) continue;

		if (IsPlayerInRangeOfPoint(playerid, radius, Player.Info[senderid][X], Player.Info[senderid][Y], Player.Info[senderid][Z])) {
			SendClientMessage(playerid, color, message);
		}
	}	
}
