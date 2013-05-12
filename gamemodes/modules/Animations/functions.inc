/*!
 * Animations/functions.inc
 *
 > Priority: 0
 */

stock this.SetUsingLoopingAnimation(playerid, looping) {
	this.IsUsingLoopingAnim[playerid] = looping;

	if (looping) {
		GameTextForPlayer(playerid, "~p~~n~~n~Press the sprint key to stop the animation.", 3000, 1);
	} else {
		ClearAnimations(playerid);
	}
}

stock this.CheckAnimationWhileCuffed(playerid) {
	if (Player.Info[playerid][IsCuffed] == false) {
    	return true;
    } else {
        SendClientUsage(playerid, "You cannot do that while cuffed.");
        return false;
    }
}