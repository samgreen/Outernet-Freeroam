/*!
 * Brawler/commands.inc
 *
 > Priority: 0
 */

// Ground stomp (Level 2) (/gs) - Stuns and damages enemies in a 5.0 + (0.5 * Level) radius, and 
// damages players for 8 + (0.5 * Level) health.
CommandDescription<gs> = @"Stomp the ground with a mighty fury, causing damage to all nearby players.";
YCMD:gs(playerid, params[], help) {
	
	return 1;
}

// Berserk (Level 4) (/ber) - Allows the brawler to ignore all damage for 3 + (0.5 * Level) seconds..
CommandDescription<ber> = @"Ignore all damage as you are overtaken by a berzerk rage.";
YCMD:ber(playerid, params[], help) {
	
	return 1;
}

// Revenge (Level 6) (/rev) - Activates “Revenge” mode for a brawler for 3 + (2 * Level) seconds. 
// While “Revenge” mode is activated, as the brawler reaches 1HP he causes a large explosion around himself, 
// taking down himself and all in the vicinity.
CommandDescription<rev> = @"If you are killed while revenge is active, your soul shatters causing massive damage to all nearby players.";
YCMD:rev(playerid, params[], help) {
	
	return 1;
}

// Spirit of Bear (Level 9) (/sob) - Activates “Bear Mode” for a brawler. Gives the brawler 
// a katana (and only a katana). When the brawler hits someone with this katana, he strikes a fatal blow. 
// As soon as the brawler kills someone with SOB, it is deactivated.
CommandDescription<sob> = @"You become infused with the spirit of the bear, your next successful attack will always be a fatal blow.";
YCMD:sob(playerid, params[], help) {
	
	return 1;
}