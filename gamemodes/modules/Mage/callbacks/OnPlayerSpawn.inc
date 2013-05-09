/*!
 * Mage/callbacks/OnPlayerSpawn.inc
 *
 * OnPlayerSpawn(playerid)
 *
 > Priority: 0
 */

{
	// The brawler spawns with 100 HP and 100 + (10 * Level) Armor.
	SetPlayerHealth(playerid, 100);
	SetPlayerArmour(playerid, 10); // 10 * pLevel
}