/*!
 * Chat/commands.inc
 *
 > Priority: 0
 */

CommandDescription<b> = @"Local of out of character.";
YCMD(GROUP_ROLEPLAY):b(playerid, params[], help) {
    new oocText[128];
    if (sscanf(params, "s[128]", oocText) || help) {
        SendClientUsage(playerid, "/b [Local OOC Text]");
        return 1;
    }

    new message[128];
    format(message, sizeof(message), "(( %p: %s ))", playerid, oocText);
    SendClientMessageRadius(playerid, message, COLOR_WHITE, 25.0);

    return 1;
}


CommandDescription<me> = @"Emote a character action.";
YCMD(GROUP_ROLEPLAY):me(playerid, params[], help) {
    new emoteText[128];
    if (sscanf(params, "s[128]", emoteText) || help) {
        SendClientUsage(playerid, "/me [emote]");
        return 1;
    }

    SendClientMessageEmote(playerid, "%p %s (ID: %d)", playerid, emoteText, playerid);

    return 1;
}

CommandDescription<do> = @"Emote an action.";
YCMD(GROUP_ROLEPLAY):do(playerid, params[], help) {
    new emoteText[128];
    if (sscanf(params, "s[128]", emoteText) || help) {
        SendClientUsage(playerid, "/do [emote]");
        return 1;
    }

    SendClientMessageEmote(playerid, "%s (ID: %d)", emoteText, playerid);

    return 1;
}

CommandDescription<shout> = @"Shout something at the top of your lungs.";
YCMD(GROUP_ROLEPLAY):shout(playerid, params[], help) {
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
YCMD(GROUP_ROLEPLAY):ad(playerid, params[], help) {
    
    return 1;
}

CommandDescription<o> = @"Server wide out of character chat.";
YCMD(GROUP_ROLEPLAY):o(playerid, params[], help) {
	new text[128];
	if (sscanf(params, "s[128]", text)) {
        SendClientUsage(playerid, "/o [Out of Character text]");
        return 1;
    } 

	SendClientMessageToAll(COLOR_WHITE, "(( %p: %s ))", playerid, text);
    
    return 1;
}