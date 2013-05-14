/*!
 * Freeroam/callbacks/OnPlayerText.inc
 *
 * OnPlayerText(playerid, text[])
 *
 > Priority: 0
 */

{
	if (this.In(playerid)) {
		// foreach (Group(GROUP_FREEROAM), playerid) {
		// 	SendClientMessage(playerid, COLOR_WHITE, text);
		// }
		return 1;
	}
}