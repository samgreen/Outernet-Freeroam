/*!
 * Cleric/commands.inc
 *
 > Priority: 0
 */


// Protect (/prot) - Restores the target’s armor.
CommandDescription<prot> = @"";
YCMD:prot(playerid, params[], help) {
	
	return 1;
}

// Dispell (/disp) - Removes mage spell effects from players - root, tree, etc.
CommandDescription<disp> = @"";
YCMD:disp(playerid, params[], help) {
	
	return 1;
}

// Desummoning Prayer (/desum) - Despawns the target players vehicle (strict radius restriction, must be close by) (???)
CommandDescription<desum> = @"";
YCMD:desum(playerid, params[], help) {
	
	return 1;
}

// Holy Fountain (/hf) - Summons a Fountain object - anyone in the vincinity of this fountain regenerates HP 
// over time. Regens HP 1 + (1 * Level) and lasts 30sec + (10 * Level)
CommandDescription<hf> = @"";
YCMD:hf(playerid, params[], help) {
	
	return 1;
}

// Prayer of Haste (/poh) - Adds NOS to the target players’ steed. Radius Restriction.
CommandDescription<poh> = @"";
YCMD:poh(playerid, params[], help) {
	
	return 1;
}

// Heal (/heal) - Heals the target player for a certain amount of damage (heal becomes more effective 
// as the player levels up)
CommandDescription<heal> = @"";
YCMD:heal(playerid, params[], help) {
	
	return 1;
}

// Cure - Removes some poisons applied by the Assassin (damage, DoT, blind)
CommandDescription<cure> = @"";
YCMD:cure(playerid, params[], help) {
	
	return 1;
}
