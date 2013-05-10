/*!
 * Gumball/header.inc
 *
 > Priority: 0
 */

new StaticGroup<MINIGAME_GUMBALL> = "Gumball MiniGame Players";

const this.NUM_VEHICLES = 23;

new this.GUMBALL_VEHICLES[this.NUM_VEHICLES];
new this.vehicleCount = 0;
new bool:this.active = false;
