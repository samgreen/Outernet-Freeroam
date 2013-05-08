/*!
 * Mage/commands.inc
 *
 > Priority: 0
 */


// Summon - Allows the mage to create weapons, vehicles, and some structures. 
// As the player progresses in levels more items will become available. Summoned vehicles 
// have the characteristics of a ‘steed.’
CommandDescription<summon> = @"";
YCMD:summon(playerid, params[], help) {
	// Level 1: Dodo, MP5
	// Level 2: Maverick, Molotovs
	// Level 3: Bullet, Country Rifle
	// Level 4: Firetruck w/ Hose, M4
	// Level 5: Dune, Desert Eagle
	// Level 6: Sawn-Offs
	// Level 7: Mr. Splashy
	// Level 8: SPAS-12
	// Level 9: Rustler
	// Level 10: Minigun (w/ strict ammo??)
	
	return 1;
}

// Fireball (/fireball or /fb) - Sends a deadly fireball at the mage’s target.
CommandDescription<fb> = @"";
YCMD:fb(playerid, params[], help) {
	
	return 1;
}

// Missile (/missle or /mis) - Fires a magical missle at the target, exploding upon impact.
CommandDescription<mis> = @"";
YCMD:mis(playerid, params[], help) {
	
	return 1;
}

// Treeform (/tree) - Summons the forces of nature in the form of a tree ontop of the target.
CommandDescription<tree> = @"";
YCMD:tree(playerid, params[], help) {
	
	return 1;
}

// Spirit of Eagle (/soe) - Puts the player 200 ft. into the air and summons a shamal.
CommandDescription<soe> = @"";
YCMD:soe(playerid, params[], help) {
	
	return 1;
}
