/*!
 * OJ/callbacks/OnPlayerDeath.inc
 *
 * OnPlayerDeath(playerid, killerid, reason)
 *
 > Priority: 0
 */

{
	if (this.active) {

		// Check to see if they killed OJ
		if (playerid == this.playerOJ) {
			SendDeathMessage(killerid, playerid, reason);
			SendClientMessageToAll(COLOR_GENERIC_INFO, "%s was finally killed by %s. The streets are safe again.", Player.Info[this.playerOJ][Name], Player.Info[killerid][Name]);
		}
	}
}