/*!
 * Freeroam/callbacks/OnPlayerText.inc
 *
 * OnPlayerText(playerid, text[])
 *
 > Priority: 0
 */

{
	foreach (new otherPlayerID : Player) {
		if (this.In(otherPlayerID)) {
			SendClientMessage(playerid, COLOR_WHITE, text);
		}
	}
}