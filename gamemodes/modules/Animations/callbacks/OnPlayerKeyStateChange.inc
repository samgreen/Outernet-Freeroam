/*!
 * Animations/callbacks/OnPlayerKeyStateChange.inc
 *
 * OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
 *
 > Priority: 0
 */

{
    if (PRESSED(KEY_SPRINT, newkeys, oldkeys)) {

        // if player is doing an animation
        if (this.IsUsingLoopingAnim[playerid] != 0) {
        	// Clear all animations and reset the flag
            ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 0, 0, 0, 0, 0);
            this.IsUsingLoopingAnim[playerid] = 0;
        }
    }
}

