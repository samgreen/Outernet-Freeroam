/*!
 * OJ/callbacks/OnPlayerExitVehicle.inc
 *
 * OnPlayerExitVehicle(playerid, vehicleid)
 *
 > Priority: 0
 */

{
	if (this.active) {
		
		// Check if the player left the OJ bronco
		if (vehicleid == this.GetOJCar() && playerid == this.PlayerOJ) {
			SendClientMessageToAll(COLOR_GENERIC_INFO, "%s has abandoned the bronco and is now running on foot!", Player.Info[this.PlayerOJ][Name]);
		}
	}
}