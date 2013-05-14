/*!
 * Freeroam/callbacks/OnGameModeInit.inc
 *
 * OnGameModeInit()
 *
 > Priority: 0
 */

{
	// Outside of Ammu-Nation in Blueberry
	new ammunationSpawn = CreateSpawnLocation(
		.interior = 0,
		.x        = 240.0390,
		.y        = -178.2970,
		.z        = 1.5781,
		.rot      = 90.0
	);
	
	// Ammu-nation guy skin
	CreateClass(179, ammunationSpawn);

	Command_AddAltNamed("joinfr", "freeroam");
	Command_AddAltNamed("joinfr", "roam");
}