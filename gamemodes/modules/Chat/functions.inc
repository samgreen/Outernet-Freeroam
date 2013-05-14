/*!
 * Chat/functions.inc
 *
 > Priority: 0
 */

stock SendClientUsage(playerid, string:usageText[], color = COLOR_COMMAND_USAGE) {
	SendClientMessage(playerid, color, usageText);

	return 1;
}

stock SendClientError(playerid, string:errorText[], color = COLOR_COMMAND_ERROR) {
	SendClientMessage(playerid, color, errorText);

	return 1;
}

stock SendClientHelp(playerid, string:helpText[], color = COLOR_COMMAND_HELP) {
	SendClientMessage(playerid, color, helpText);

	return 1;
}

stock SendClientMessageEmote(senderid, string:message[]) {
	SendClientMessageNearby(senderid, message, COLOR_EMOTE);

	return 1;
}

stock SendClientMessageNearby(senderid, string:message[], color = COLOR_WHITE) {
	foreach (new playerid : Player) {
		if (playerid == senderid) continue;

		SendClientMessage(playerid, color, message);
	}
	SendClientMessageRadius(senderid, message, color, 25.0);

	return 1;
}

stock SendClientMessageRadius(senderid, string:message[], color = COLOR_WHITE, Float:radius = 20.0) {
	foreach (new playerid : Player) {
		// if (playerid == senderid) continue;

		if (IsPlayerInRangeOfPoint(playerid, radius, Player.Info[senderid][X], Player.Info[senderid][Y], Player.Info[senderid][Z])) {
			SendClientMessage(playerid, color, message);
		}
	}	

	return 1;
}
