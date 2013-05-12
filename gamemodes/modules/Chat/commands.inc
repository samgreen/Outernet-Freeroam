/*!
 * Chat/commands.inc
 *
 > Priority: 0
 */

CommandDescription<b> = @"Local of out of character.";
YCMD:b(playerid, params[], help) {
    
    return 1;
}


CommandDescription<me> = @"Emote an action.";
YCMD:me(playerid, params[], help) {
    new emoteText[128];
    if (sscanf(params, "s[128]", emoteText) || help) {
        SendClientUsage(playerid, "/me [emote]");
        return 1;
    }

    new message[128];
    format(message, sizeof(message), "%s (ID: %d)", emoteText, playerid);
    SendClientMessageEmote(playerid, message);

    return 1;
}

CommandDescription<shout> = @"Shout something at the top of your lungs.";
YCMD:shout(playerid, params[], help) {
    new shoutText[128];
    if (sscanf(params, "s[128]", shoutText) || help) {
        SendClientUsage(playerid, "/shout [Text]");
        return 1;
    }

    new message[128];
    format(message, sizeof(message), "%p shouts, \"%s\"!", playerid, shoutText);
    SendClientMessageRadius(playerid, message, COLOR_RED, 75.0);

    return 1;
}

CommandDescription<ad> = @"Create an advertisement for all players to see.";
YCMD:ad(playerid, params[], help) {
    
    return 1;
}

CommandDescription<o> = @"Server wide out of character chat.";
YCMD:o(playerid, params[], help) {
	new text[128];
	if (sscanf(params, "s[128]", text)) {
        SendClientUsage(playerid, "/o [Out of Character text]");
        return 1;
    } 

	SendClientMessageToAll(COLOR_WHITE, "(( %s ))", text);
    
    return 1;
}