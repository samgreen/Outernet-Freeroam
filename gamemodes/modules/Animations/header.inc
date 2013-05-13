/*!
 * Animations/header.inc
 *
 > Priority: 0
 */

new this.IsUsingLoopingAnim[MAX_PLAYERS];

#define SPECIAL_ACTION_PISS		68

// PRESSED(keys)
#define PRESSED(%0) \
	(((newkeys & (%0)) == (%0)) && ((oldkeys & (%0)) != (%0)))