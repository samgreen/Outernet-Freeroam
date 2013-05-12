/*!
 * CB/header.inc
 *
 > Priority: 0
 */

#define 			MyTime(%0,%1,%2)    (((%0)*3600+(%1)*60+(%2))*1000)

enum CBInfo {
 	Channel,
 	Status,
 	Level,
 	Owner,
	CBChannel
}

new this.Info[MAX_PLAYERS][CBInfo];