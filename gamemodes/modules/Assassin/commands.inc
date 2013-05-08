/*!
 * Assassin/commands.inc
 *
 > Priority: 0
*/

// Sneak (Level 1) (/sneak) - Camouflages the assassin in the world for a maximum of 6 + (1.5 * Level) seconds. 
// The effect may be cancelled early. Activate sneak effect when assassin crouches?
CommandDescription<sneak> = @"";
YCMD:sneak(playerid, params[], help) {
	
	return 1;
}

// Slow poison (Level 1) (/poi 1) - A severe poison that slows the player it is applied to for 4 + (1.0 * Level) seconds.
// 		The poison reduces the maximum foot speed for the player. Assassin obtains a “poisoned” silenced pistol 
//		after initiating /poi 1 - the first person hit with the silenced pistol will be poisoned. 
// Debilitate (Level 3) (/poi 3) - A curable toxin that blinds the target for 6 + (2 * Level), creating a blindfold 
//		effect. Player retains all control of his person and can run/shoot. 
// Deadly poison (Level 2) (/poi 2) - A curable toxin that damages players for 2 + (1.0 * Level) every 4 seconds 
//		for 40 seconds. 
CommandDescription<poi> = @"";
YCMD:poi(playerid, params[], help) {
	
	return 1;
}

// Ground Spikes (Level 5) (/spi) - The assassin has the ability to drop spike strips. This ability is obtained at level 6.
CommandDescription<spi> = @"";
YCMD:spi(playerid, params[], help) {
	
	return 1;
}

// Fire Trap (Level 7) (/ft) - The assassin can plant a deadly explosive, detonated at his pleasure.
CommandDescription<ft> = @"";
YCMD:ft(playerid, params[], help) {
	
	return 1;
}

// Owl Scout (Level 10) (/owl) - Zooms the camera out substantially, giving the Assassin the ability to scout 
// locations from great distances, at no harm to himself.
CommandDescription<owl> = @"";
YCMD:owl(playerid, params[], help) {
	
	return 1;
}