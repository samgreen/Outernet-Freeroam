/*!
 * Gumball/functions.inc
 *
 > Priority: 0
 */

stock this.SpawnCars() {
	// King of the Mountain teleports (different building-tops of varying size/complexity:
	AddPlayerClass(299,1576.1821,-1241.3708,277.8767,136.4489,0,0,0,0,0,0); // kingofthemountain
	AddPlayerClass(299,-1955.4894,631.0583,145.3173,277.1562,0,0,0,0,0,0); // kingofthemountain 2
	AddPlayerClass(299,-1943.9519,535.8376,209.4050,300.0583,0,0,0,0,0,0); // kingofthemountain 3
	AddPlayerClass(299,-1809.5675,574.1158,234.8906,31.1420,0,0,0,0,0,0); // kingofthemountain 4

	// Gumball Rally (Bayside -> Los Santos Airport)
	AddStaticVehicle(415,-2465.5481,2247.0857,4.5688,358.5792,15,38); // Bayside Parking Lot (Race Start)
	// Gumball Cars (possibly randomize colors on spawn?) Despite these car spawns, players should still be able to spawn // vehicles of their choice for Gumball (with some restrictions)
	AddStaticVehicle(541,-2482.5789,2224.6865,4.4657,359.8683,210,126); // bs1
	AddStaticVehicle(415,-2485.4619,2224.4580,4.6163,0.9543,15,38); // bs2
	AddStaticVehicle(541,-2479.6240,2224.0901,4.6130,358.9775,15,38); // bs3
	AddStaticVehicle(415,-2476.6565,2223.7046,4.6149,0.9196,15,38); // bs4
	AddStaticVehicle(451,-2473.5286,2223.7627,4.6157,358.9386,15,38); // bs4
	AddStaticVehicle(451,-2470.7314,2223.9722,4.6159,358.7144,15,38); // bs6
	AddStaticVehicle(415,-2467.5696,2224.2542,4.6173,1.1793,15,38); // bs7
	AddStaticVehicle(411,-2464.6665,2223.3484,4.6135,0.5418,15,38); // bs8
	AddStaticVehicle(411,-2461.7256,2224.2878,4.6135,0.1023,15,38); // bs9
	AddStaticVehicle(411,-2458.5962,2223.5249,4.6138,1.0579,15,38); // bs10
	AddStaticVehicle(568,-2455.8359,2223.6057,4.6138,359.6740,15,38); // bs11
	AddStaticVehicle(571,-2452.7485,2224.0593,4.6132,0.1966,15,38); // bs12
	AddStaticVehicle(489,-2449.7000,2223.8977,4.6132,0.4561,15,38); // bs13
	AddStaticVehicle(415,-2446.6709,2224.3110,4.6133,359.8491,15,38); // bs14
	AddStaticVehicle(489,-2443.6184,2223.7610,4.6132,359.6327,15,38); // bs15
	AddStaticVehicle(494,-2440.6968,2223.8774,4.6151,356.8679,15,38); // bs16

	AddPlayerClass(299,1959.5157,-2624.7688,13.5469,7.0334,0,0,0,0,0,0); // LS Airport (Race Finish)
}

stock this.DestroyCars() {
	
}