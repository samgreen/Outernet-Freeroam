/*!
 * Chat/functions.inc
 *
 > Priority: 0
 */

stock SendClientUsage(playerid, const string:usageText[], color = COLOR_COMMAND_USAGE) {
	SendClientMessage(playerid, color, usageText);

	return 1;
}

stock SendClientError(playerid, const string:errorText[], color = COLOR_COMMAND_ERROR) {
	SendClientMessage(playerid, color, errorText);

	return 1;
}

stock SendClientHelp(playerid, const string:helpText[], color = COLOR_COMMAND_HELP) {
	SendClientMessage(playerid, color, helpText);

	return 1;
}

stock SendClientMessageEmote(senderid, const string:message[], va_args<>) {
	new string:emoteText[128];
	va_format(emoteText, sizeof(emoteText), message, va_start<2>);

	foreach (new playerid : Player) {
		// Skip freeroam players for emotes
		if (Group_GetPlayer(GROUP_FREEROAM, playerid)) continue;

		if (IsPlayerInRangeOfPoint(playerid, radius, Player.Info[senderid][X], Player.Info[senderid][Y], Player.Info[senderid][Z])) {
			SendClientMessage(playerid, color, emoteText);
		}
	}
}

stock SendClientMessageNearby(senderid, string:message[], color = COLOR_WHITE) {
	SendClientMessageRadius(senderid, message, color, 25.0);

	return 1;
}

stock SendClientMessageRadius(senderid, string:message[], color = COLOR_WHITE, Float:radius = 20.0) {
	foreach (new playerid : Player) {
		if (IsPlayerInRangeOfPoint(playerid, radius, Player.Info[senderid][X], Player.Info[senderid][Y], Player.Info[senderid][Z])) {
			SendClientMessage(playerid, color, message);
		}
	}	

	return 1;
}
