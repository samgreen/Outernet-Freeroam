/*!
 * WizardsAndDragons/commands.inc
 *
 > Priority: 0
 */

// Summon Steed (Level 1) (/ss) - Allows the brawler to summon Mr. Splashy (/ss 1) or a Wayfarer (/ss 2)
// Summon Steed (Level 1) (/ss) - Allows the assassin to summon an NRG (/ss 1) or a Sparrow (/ss 2)
// Summon Steed (Level 1) (/ss) - Allows the mage to summon a Sultan (/ss 1) or a PCJ(/ss 2)
// Summon Steed (/ss) - Allows the cleric to summon an Ambulance (/ss 1) or an FCR-900 (/ss 2). 
//		Group mates sitting in the ambulance will slowly regenerate health over time.
CommandDescription<ss> = @"Summon a mighty steed and ride forth in to battle.";
YCMD:ss(playerid, params[], help) {
	
	return 1;
}
