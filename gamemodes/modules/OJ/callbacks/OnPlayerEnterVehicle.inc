/*!
 * OJ/callbacks/OnPlayerEnterVehicle.inc
 *
 * OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
 *
 > Priority: 0
 */

{
	if (this.active) {

		// Check if a player has entered the OJ car, and they are the first player to do so
		if (vehicleid == this.GetOJCar() && this.PlayerOJ != -1) {
			this.PlayerOJ = playerid;

			SendClientMessageToAll(COLOR_GENERIC_INFO, "%s has entered OJ's bronco, and is now on the run!", Player.Info[this.PlayerOJ][Name]);
		}
	}
}