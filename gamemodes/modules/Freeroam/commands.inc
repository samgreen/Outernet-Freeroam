/*!
 * Freeroam/commands.inc
 *
 > Priority: 0
 */


CommandDescription<gun> = @"Equip yourself with a weapon.";
YCMD:gun(playerid, params[], help) {
	
	return 1;
}

CommandDescription<veh> = @"Spawn a vehicle.";
YCMD:veh(playerid, params[], help) {
	
	return 1;
}

CommandDescription<goto> = @"Teleport to another player.";
YCMD:goto(playerid, params[], help) {
	
	return 1;
}