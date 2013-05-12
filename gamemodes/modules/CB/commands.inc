/*!
 * CB/commands.inc
 *
 > Priority: 0
 */


//==============================================================================
YCMD:joinchannel(playerid, params[], help)
{
	if (this.CanUse(playerid)) {
		new cbChannel;
		if (sscanf(params, "d", cbChannel)) {
			SendClientUsage(playerid, "/joinchannel [1 - 1000]");
			return 1;
		}

		if (cbChannel < 1 || cbChannel > 1000) return SendClientMessage(playerid, -1, "{FF0000}ERROR: {FFFFFF}The Channel Must Be Between {FF0000}(1 - 1000MHz)");

		this.Info[playerid][Channel] = cbChannel;

		foreach (new otherPlayerID : Player) {
		    if (this.OnSameChannel(playerid, otherPlayerID)) {
				SendClientMessage(otherPlayerID, -1, "{FF0000}>>{C0C0C0} %s Has Joined The Channel", playerid);
			}
		}
	}

	return 1;
}

//==============================================================================
YCMD:buycb(playerid, params[], help)
{
	if (Inventory.Info[playerid][ItemCB] != 0) return SendClientMessage(playerid, -1, "{FF0000}>>{FFFFFF} You {00FF00}Already Have{FFFFFF} A Radio");

	Inventory.Info[playerid][ItemCB] = 1;
	SendClientMessage(playerid, -1, "{FF0000}>>{FFFFFF} You Have {00FF00}Bought{FFFFFF} A Citizens Band (CB) Radio For Help Use {FF0000}(/cbhelp)");

	return 1;
}

//==============================================================================
YCMD:setcb(playerid, params[], help)
{
	new cbStatus;
	if (sscanf(params, "d", cbStatus)) {
		SendClientUsage(playerid, "/setcb [0 = Off] [1 = On]");
		return 1;
	}

	if (cbStatus != 0) {
	    if (this.Info[playerid][Status] == 1) {
	        SendClientMessage(playerid, -1, "{FF0000}>>{FFFFFF} Your Radio Is Already {00FF00}On");
		} else {
		    this.Info[playerid][Status] = 1;
		    SendClientMessage(playerid, -1, "{FF0000}>>{FFFFFF} You Have {00FF00}Successfully{FFFFFF} Turned {00FF00}On{FFFFFF} Your Radio");
		}
	} else {
	    if (this.Info[playerid][Status] == 0) {
	        SendClientMessage(playerid, -1, "{FF0000}>>{FFFFFF} Your Radio Is Already {FF0000}Off");
		} else {
		    this.Info[playerid][Status] = 0;
		    SendClientMessage(playerid, -1, "{FF0000}>>{FFFFFF} You Have {00FF00}Successfully{FFFFFF} Turned {FF0000}Off{FFFFFF} Your Radio");
		}
	}

	return 1;
}
//==============================================================================
YCMD:cb(playerid, params[], help)
{
	if (this.CanUse(playerid)) {
	
		new messageText[128];
		if (sscanf(params, "s[128]", messageText)) {
			SendClientUsage(playerid, "/cb [Your Message]");
			return 1;
		}

		foreach (new otherPlayerID : Player) {
		    if (this.OnSameChannel(playerid, otherPlayerID)) {
				SendClientMessage(otherPlayerID, -1, "{00FF00}[CB]{FF8000} %p: {FFFFFF}%s", playerid, messageText);
			}
		}
	}

	return 1;
}
//==============================================================================
YCMD:cbalert(playerid, params[], help)
{
	if (this.CanUse(playerid)) {

		new alertText[128];
		if (sscanf(params, "s[128]", alertText)) {
			SendClientUsage(playerid, "/cbalert [Your Message]");
			return 1;
		}

		foreach (new otherPlayerID : Player) {
		    if (this.OnSameChannel(playerid, otherPlayerID)) {
				GameTextForPlayer(otherPlayerID, alertText, MyTime(0, 0, 5), 6);
				SendClientMessage(otherPlayerID, -1, "{00FF00}[CB ALERT]{FF8000} %p", playerid);
			}
		}
	}
	
	return 1;
}

YCMD:cbhelp(playerid, params[], help)
{
	new dialogText[1500];
	strcat(dialogText, "\t\t{FF0000} - Citizens Band Radio System (CB) - \n{FFFFFF}A CB Radio Is A Communication Tool Used To Communicate In A Business Or \n{FFFFFF}Personally It Has A Max Of 1000 Channels You Can Choose From And Tell Your\n{FFFFFF}Gang For Example To Join That Specific Channel And You Can Talk Togeather\n\n", sizeof(dialogText));
	strcat(dialogText, "{FFFF00}Commands : \n{FF8000}\t\t- /joinchannel (To Join A Channel)\n\t\t{FF8000}- /buycb (To Buy A CB)\n\t\t{FF8000}- /setcb (To Turn Your CB On / Off", sizeof(dialogText));
	strcat(dialogText, "\n\t\t{FF8000}- /cb (To Talk Through The CB\n\t\t{FF8000}- /cbalert (To Send An Alert To All Users In The Channel\n\n", sizeof(dialogText));

	ShowPlayerDialog(playerid, 1212, DIALOG_STYLE_MSGBOX, "Citizens Band Radio", dialogText, "Close", "");

	return 1;
}