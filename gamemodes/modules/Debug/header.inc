/*!
 * Debug/header.inc
 *
 > Priority: 0
 */

#define MAX_LINES 100
#define MAX_LINE_LENGTH 150

new this.lines[MAX_LINES][MAX_LINE_LENGTH];

new this.LEVELS[][] = {
	"Info",
	"Warning",
	"Error"
};