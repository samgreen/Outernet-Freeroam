/*!
 * OJ/header.inc
 *
 > Priority: 0
 */

new StaticGroup<MINIGAME_OJ> = "OJ MiniGame Players";

const this.NUM_VEHICLES = 23;
new this.OJ_VEHICLES[this.NUM_VEHICLES];
new this.vehicleCount = 0;

new this.playerOJ = -1;
new bool:this.active = false;