/*!
 * Gumball/functions.inc
 *
 > Priority: 0
 */

// -2465.5481,2247.0857,4.5688 // Bayside Parking Lot (Race Start)
// 1959.5157,-2624.7688,13.5469 // LS Airport (Race Finish)

stock this.Setup() {
	this.SpawnCars();

	this.active = true;
}

stock this.Teardown() {
	this.RemoveCars();

	this.active = false;
}

stock this.SetupCheckpoints() {

}

stock this.SpawnCars() {
	this.vehicleCount = 0;
	
	// Gumball Cars (possibly randomize colors on spawn?) Despite these car spawns, players should still be able to spawn 
	// vehicles of their choice for Gumball (with some restrictions)
	this.SaveCarID((541,-2482.5789,2224.6865,4.4657,359.8683,210,126)); // bs1
	this.SaveCarID((415,-2485.4619,2224.4580,4.6163,0.9543,15,38)); // bs2
	this.SaveCarID((541,-2479.6240,2224.0901,4.6130,358.9775,15,38)); // bs3
	this.SaveCarID((415,-2476.6565,2223.7046,4.6149,0.9196,15,38)); // bs4
	this.SaveCarID((451,-2473.5286,2223.7627,4.6157,358.9386,15,38)); // bs4
	this.SaveCarID((451,-2470.7314,2223.9722,4.6159,358.7144,15,38)); // bs6
	this.SaveCarID((415,-2467.5696,2224.2542,4.6173,1.1793,15,38)); // bs7
	this.SaveCarID((411,-2464.6665,2223.3484,4.6135,0.5418,15,38)); // bs8
	this.SaveCarID((411,-2461.7256,2224.2878,4.6135,0.1023,15,38)); // bs9
	this.SaveCarID((411,-2458.5962,2223.5249,4.6138,1.0579,15,38)); // bs10
	this.SaveCarID((568,-2455.8359,2223.6057,4.6138,359.6740,15,38)); // bs11
	this.SaveCarID((571,-2452.7485,2224.0593,4.6132,0.1966,15,38)); // bs12
	this.SaveCarID((489,-2449.7000,2223.8977,4.6132,0.4561,15,38)); // bs13
	this.SaveCarID((415,-2446.6709,2224.3110,4.6133,359.8491,15,38)); // bs14
	this.SaveCarID((489,-2443.6184,2223.7610,4.6132,359.6327,15,38)); // bs15
	this.SaveCarID((494,-2440.6968,2223.8774,4.6151,356.8679,15,38)); // bs16
}

stock this.SaveCarID(vehicleid) {
	this.GUMBALL_VEHICLES[this.vehicleCount] = vehicleid;
	this.vehicleCount++;
}

stock this.RemoveCars() {
	for (new i = 0; i < this.MAX_VEHICLES; i++) {
		DestroyVehicle(this.GUMBALL_VEHICLES[i]);
	}
}