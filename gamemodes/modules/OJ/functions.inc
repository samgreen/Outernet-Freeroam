/*!
 * OJ/functions.inc
 *
 > Priority: 0
 */

stock this.SpawnCars() {
	// OJ Spawn point
	AddPlayerClass(299,-353.8105,1531.0774,75.3594,307.4156,0,0,0,0,0,0); // OJ Spawn

	// OJ Cars (first person in the Bronco is OJ)
	AddStaticVehicle(489,-316.0997,1502.8499,75.9185,231.3118,1,1); 	// OJ Bronco
	AddStaticVehicle(528,-314.7557,1515.2611,75.4023,1.0798,159,77); 	// OJ Riot Car 1
	AddStaticVehicle(528,-317.8251,1514.7574,75.4019,0.2683,159,77); 	// OJ Riot Car 2
	AddStaticVehicle(528,-321.0465,1514.6555,75.4017,0.5473,159,77); 	// OJ Riot Car 3
	AddStaticVehicle(490,-324.1983,1514.4603,75.4864,359.1485,0,0); 	// OJ FBI Rancher 1 (all ranchers need to be 0 0)
	AddStaticVehicle(490,-327.3044,1514.5951,75.4901,0.6575,0,0); 		// OJ FBI Rancher 2
	AddStaticVehicle(490,-330.4289,1514.3502,75.4858,359.7563,0,0); 	// OJ FBI Rancher 3
	AddStaticVehicle(490,-333.4405,1514.1614,75.4862,358.9199,0,0); 	// OJ FBI Rancher 4
	AddStaticVehicle(490,-336.6738,1514.4008,75.4853,1.0954,242,241); 	// OJ FBI Rancher 5
	AddStaticVehicle(427,-344.6514,1515.6349,75.4910,0.3610,1,0);   	// OJ Enforcer
	AddStaticVehicle(599,-266.9112,1546.0747,75.5507,136.9703,1,0); 	// OJ Police Rancher 1
	AddStaticVehicle(599,-269.8759,1548.2650,75.5418,134.7334,1,0); 	// OJ Police Rancher 2
	AddStaticVehicle(599,-271.6352,1551.2841,75.5384,135.9388,1,0); 	// OJ Police Rancher 3
	AddStaticVehicle(596,-277.4731,1555.1964,75.0775,134.8170,1,0); 	// OJ LSPD 1
	AddStaticVehicle(596,-279.5657,1558.2603,75.0811,135.8795,1,0); 	// OJ LSPD 2
	AddStaticVehicle(596,-281.8146,1560.7900,75.0788,133.4158,1,0); 	// OJ LSPD 3
	AddStaticVehicle(596,-284.4654,1563.0819,75.0813,133.9594,1,0); 	// OJ LSPD 4
	AddStaticVehicle(598,-286.8904,1565.7144,75.1030,133.6141,1,0); 	// OJ SFPD 1
	AddStaticVehicle(598,-289.4498,1568.0541,75.1081,133.9746,1,0); 	// OJ SFPD 2
	AddStaticVehicle(598,-292.4219,1569.7659,75.1072,134.7925,1,0); 	// OJ SFPD 3
	AddStaticVehicle(598,-294.9639,1572.4816,75.1067,136.7552,1,0); 	// OJ SFPD 4
	AddStaticVehicle(597,-297.2274,1574.9409,75.1255,133.6291,1,0); 	// OJ LVPD 1
	AddStaticVehicle(597,-299.9607,1577.4442,75.1294,135.9016,1,0); 	// OJ LVPD 2
	AddStaticVehicle(597,-301.9086,1580.5531,75.1293,132.5830,1,0); 	// OJ LVPD 3
	AddStaticVehicle(597,-304.4856,1582.7828,75.1261,136.1795,1,0); 	// OJ LVPD 4	
}

stock this.RemoveCars() {

}