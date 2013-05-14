/*******************************************************************************
				
		Player attached object editor (rewritten from the remains of 
					the old holding object editor).
						~ a creation of bren. ~

*******************************************************************************/

#include 				<a_samp>
// #include				<foreach>
#include				<zcmd>

#define					COLOR_WHITE										0xFFFFFFFF
#define					COLOR_LIME										0xB9FF2BFF
#define 				COLOR_GREY 										0xCECECEFF
#define					COLOR_NICERED									0xFF5F47FF

#define					SAVED_OBJECT_FILE								"attachments.txt"
#define					IsKeyJustDown(%0)								((newkeys & %0) && !(oldkeys & %0))

#define					lol_arbitary_number								(9001) // In case your gamemode runs dialogs and you cbf changing like me

#define					DIALOG_START									(1 + lol_arbitary_number)
#define					DIALOG_OBJECT									(2 + lol_arbitary_number)
#define					DIALOG_BONE										(3 + lol_arbitary_number)		
#define					DIALOG_EDIT										(4 + lol_arbitary_number)	
#define					DIALOG_DELETE									(5 + lol_arbitary_number)		

#define					offsetX											(0)
#define					offsetY											(1)
#define					offsetZ											(2)
#define					rotationX										(3)
#define					rotationY										(4)
#define					rotationZ										(5)
#define					scaleX											(6)
#define					scaleY											(7)
#define					scaleZ											(8)

enum objEnum {
	objID,
	objBone,
}

enum editorEnum {
	editingIndex,
	editingStat,
	Text: editingText,
}

new stock
	objVars[MAX_PLAYERS][MAX_PLAYER_ATTACHED_OBJECTS][objEnum],
	Float: objFloats[MAX_PLAYERS][MAX_PLAYER_ATTACHED_OBJECTS][9],
	editorVars[MAX_PLAYERS][editorEnum];

stock resetSlot(playerid, index) {
	if(IsPlayerAttachedObjectSlotUsed(playerid, index)) RemovePlayerAttachedObject(playerid, index);
	objVars[playerid][index][objID] = -1;
	objVars[playerid][index][objBone] = 0;
	objFloats[playerid][index][offsetX] = 0.0;
	objFloats[playerid][index][offsetY] = 0.0;
	objFloats[playerid][index][offsetZ] = 0.0;
	objFloats[playerid][index][rotationX] = 0.0;
	objFloats[playerid][index][rotationY] = 0.0;
	objFloats[playerid][index][rotationZ] = 0.0;
	objFloats[playerid][index][scaleX] = 1.0;
	objFloats[playerid][index][scaleY] = 1.0;
	objFloats[playerid][index][scaleZ] = 1.0;
	return 1;
}

stock updateAttachedObject(playerid, index) {
	
	new
		sz_textStr[128];
	
	switch(editorVars[playerid][editingStat]) {
		case 0: switch(objVars[playerid][index][objBone]) {
			case 1: format(sz_textStr, sizeof(sz_textStr), "X OFFSET~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Spine", objFloats[playerid][index][offsetX], index, objVars[playerid][index][objID]);
			case 2: format(sz_textStr, sizeof(sz_textStr), "X OFFSET~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Head", objFloats[playerid][index][offsetX], index, objVars[playerid][index][objID]);
			case 3: format(sz_textStr, sizeof(sz_textStr), "X OFFSET~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left upper arm", objFloats[playerid][index][offsetX], index, objVars[playerid][index][objID]);
			case 4: format(sz_textStr, sizeof(sz_textStr), "X OFFSET~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right upper arm", objFloats[playerid][index][offsetX], index, objVars[playerid][index][objID]);
			case 5: format(sz_textStr, sizeof(sz_textStr), "X OFFSET~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left hand", objFloats[playerid][index][offsetX], index, objVars[playerid][index][objID]);
			case 6: format(sz_textStr, sizeof(sz_textStr), "X OFFSET~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right hand", objFloats[playerid][index][offsetX], index, objVars[playerid][index][objID]);
			case 7: format(sz_textStr, sizeof(sz_textStr), "X OFFSET~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left thigh", objFloats[playerid][index][offsetX], index, objVars[playerid][index][objID]);
			case 8: format(sz_textStr, sizeof(sz_textStr), "X OFFSET~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right thigh", objFloats[playerid][index][offsetX], index, objVars[playerid][index][objID]);
			case 9: format(sz_textStr, sizeof(sz_textStr), "X OFFSET~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left foot", objFloats[playerid][index][offsetX], index, objVars[playerid][index][objID]);
			case 10: format(sz_textStr, sizeof(sz_textStr), "X OFFSET~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right foot", objFloats[playerid][index][offsetX], index, objVars[playerid][index][objID]);
			case 11: format(sz_textStr, sizeof(sz_textStr), "X OFFSET~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right calf", objFloats[playerid][index][offsetX], index, objVars[playerid][index][objID]);
			case 12: format(sz_textStr, sizeof(sz_textStr), "X OFFSET~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left calf", objFloats[playerid][index][offsetX], index, objVars[playerid][index][objID]);
			case 13: format(sz_textStr, sizeof(sz_textStr), "X OFFSET~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left forearm", objFloats[playerid][index][offsetX], index, objVars[playerid][index][objID]);
			case 14: format(sz_textStr, sizeof(sz_textStr), "X OFFSET~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right forearm", objFloats[playerid][index][offsetX], index, objVars[playerid][index][objID]);
			case 15: format(sz_textStr, sizeof(sz_textStr), "X OFFSET~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left clavicle", objFloats[playerid][index][offsetX], index, objVars[playerid][index][objID]);
			case 16: format(sz_textStr, sizeof(sz_textStr), "X OFFSET~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right clavicle", objFloats[playerid][index][offsetX], index, objVars[playerid][index][objID]);
			case 17: format(sz_textStr, sizeof(sz_textStr), "X OFFSET~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Neck", objFloats[playerid][index][offsetX], index, objVars[playerid][index][objID]);
			case 18: format(sz_textStr, sizeof(sz_textStr), "X OFFSET~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Jaw", objFloats[playerid][index][offsetX], index, objVars[playerid][index][objID]);
			// default: format(sz_textStr, sizeof(sz_textStr), "EVERYTHING FUCKING BLOW UP NOW IT'S BONE ZERO!111");
		}
		case 1: switch(objVars[playerid][index][objBone]) {
			case 1: format(sz_textStr, sizeof(sz_textStr), "Y OFFSET~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Spine", objFloats[playerid][index][offsetY], index, objVars[playerid][index][objID]);
			case 2: format(sz_textStr, sizeof(sz_textStr), "Y OFFSET~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Head", objFloats[playerid][index][offsetY], index, objVars[playerid][index][objID]);
			case 3: format(sz_textStr, sizeof(sz_textStr), "Y OFFSET~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left upper arm", objFloats[playerid][index][offsetY], index, objVars[playerid][index][objID]);
			case 4: format(sz_textStr, sizeof(sz_textStr), "Y OFFSET~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right upper arm", objFloats[playerid][index][offsetY], index, objVars[playerid][index][objID]);
			case 5: format(sz_textStr, sizeof(sz_textStr), "Y OFFSET~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left hand", objFloats[playerid][index][offsetY], index, objVars[playerid][index][objID]);
			case 6: format(sz_textStr, sizeof(sz_textStr), "Y OFFSET~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right hand", objFloats[playerid][index][offsetY], index, objVars[playerid][index][objID]);
			case 7: format(sz_textStr, sizeof(sz_textStr), "Y OFFSET~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left thigh", objFloats[playerid][index][offsetY], index, objVars[playerid][index][objID]);
			case 8: format(sz_textStr, sizeof(sz_textStr), "Y OFFSET~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right thigh", objFloats[playerid][index][offsetY], index, objVars[playerid][index][objID]);
			case 9: format(sz_textStr, sizeof(sz_textStr), "Y OFFSET~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left foot", objFloats[playerid][index][offsetY], index, objVars[playerid][index][objID]);
			case 10: format(sz_textStr, sizeof(sz_textStr), "Y OFFSET~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right foot", objFloats[playerid][index][offsetY], index, objVars[playerid][index][objID]);
			case 11: format(sz_textStr, sizeof(sz_textStr), "Y OFFSET~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right calf", objFloats[playerid][index][offsetY], index, objVars[playerid][index][objID]);
			case 12: format(sz_textStr, sizeof(sz_textStr), "Y OFFSET~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left calf", objFloats[playerid][index][offsetY], index, objVars[playerid][index][objID]);
			case 13: format(sz_textStr, sizeof(sz_textStr), "Y OFFSET~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left forearm", objFloats[playerid][index][offsetY], index, objVars[playerid][index][objID]);
			case 14: format(sz_textStr, sizeof(sz_textStr), "Y OFFSET~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right forearm", objFloats[playerid][index][offsetY], index, objVars[playerid][index][objID]);
			case 15: format(sz_textStr, sizeof(sz_textStr), "Y OFFSET~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left clavicle", objFloats[playerid][index][offsetY], index, objVars[playerid][index][objID]);
			case 16: format(sz_textStr, sizeof(sz_textStr), "Y OFFSET~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right clavicle", objFloats[playerid][index][offsetY], index, objVars[playerid][index][objID]);
			case 17: format(sz_textStr, sizeof(sz_textStr), "Y OFFSET~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Neck", objFloats[playerid][index][offsetY], index, objVars[playerid][index][objID]);
			case 18: format(sz_textStr, sizeof(sz_textStr), "Y OFFSET~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Jaw", objFloats[playerid][index][offsetY], index, objVars[playerid][index][objID]);
			// default: format(sz_textStr, sizeof(sz_textStr), "EVERYTHING FUCKING BLOW UP NOW IT'S BONE ZERO!111");
		}
		case 2: switch(objVars[playerid][index][objBone]) {
			case 1: format(sz_textStr, sizeof(sz_textStr), "Z OFFSET~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Spine", objFloats[playerid][index][offsetZ], index, objVars[playerid][index][objID]);
			case 2: format(sz_textStr, sizeof(sz_textStr), "Z OFFSET~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Head", objFloats[playerid][index][offsetZ], index, objVars[playerid][index][objID]);
			case 3: format(sz_textStr, sizeof(sz_textStr), "Z OFFSET~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left upper arm", objFloats[playerid][index][offsetZ], index, objVars[playerid][index][objID]);
			case 4: format(sz_textStr, sizeof(sz_textStr), "Z OFFSET~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right upper arm", objFloats[playerid][index][offsetZ], index, objVars[playerid][index][objID]);
			case 5: format(sz_textStr, sizeof(sz_textStr), "Z OFFSET~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left hand", objFloats[playerid][index][offsetZ], index, objVars[playerid][index][objID]);
			case 6: format(sz_textStr, sizeof(sz_textStr), "Z OFFSET~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right hand", objFloats[playerid][index][offsetZ], index, objVars[playerid][index][objID]);
			case 7: format(sz_textStr, sizeof(sz_textStr), "Z OFFSET~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left thigh", objFloats[playerid][index][offsetZ], index, objVars[playerid][index][objID]);
			case 8: format(sz_textStr, sizeof(sz_textStr), "Z OFFSET~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right thigh", objFloats[playerid][index][offsetZ], index, objVars[playerid][index][objID]);
			case 9: format(sz_textStr, sizeof(sz_textStr), "Z OFFSET~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left foot", objFloats[playerid][index][offsetZ], index, objVars[playerid][index][objID]);
			case 10: format(sz_textStr, sizeof(sz_textStr), "Z OFFSET~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right foot", objFloats[playerid][index][offsetZ], index, objVars[playerid][index][objID]);
			case 11: format(sz_textStr, sizeof(sz_textStr), "Z OFFSET~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right calf", objFloats[playerid][index][offsetZ], index, objVars[playerid][index][objID]);
			case 12: format(sz_textStr, sizeof(sz_textStr), "Z OFFSET~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left calf", objFloats[playerid][index][offsetZ], index, objVars[playerid][index][objID]);
			case 13: format(sz_textStr, sizeof(sz_textStr), "Z OFFSET~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left forearm", objFloats[playerid][index][offsetZ], index, objVars[playerid][index][objID]);
			case 14: format(sz_textStr, sizeof(sz_textStr), "Z OFFSET~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right forearm", objFloats[playerid][index][offsetZ], index, objVars[playerid][index][objID]);
			case 15: format(sz_textStr, sizeof(sz_textStr), "Z OFFSET~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left clavicle", objFloats[playerid][index][offsetZ], index, objVars[playerid][index][objID]);
			case 16: format(sz_textStr, sizeof(sz_textStr), "Z OFFSET~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right clavicle", objFloats[playerid][index][offsetZ], index, objVars[playerid][index][objID]);
			case 17: format(sz_textStr, sizeof(sz_textStr), "Z OFFSET~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Neck", objFloats[playerid][index][offsetZ], index, objVars[playerid][index][objID]);
			case 18: format(sz_textStr, sizeof(sz_textStr), "Z OFFSET~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Jaw", objFloats[playerid][index][offsetZ], index, objVars[playerid][index][objID]);
			// default: format(sz_textStr, sizeof(sz_textStr), "EVERYTHING FUCKING BLOW UP NOW IT'S BONE ZERO!111");
		}	
		case 3: switch(objVars[playerid][index][objBone]) {
			case 1: format(sz_textStr, sizeof(sz_textStr), "X ROTATION~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Spine", objFloats[playerid][index][rotationX], index, objVars[playerid][index][objID]);
			case 2: format(sz_textStr, sizeof(sz_textStr), "X ROTATION~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Head", objFloats[playerid][index][rotationX], index, objVars[playerid][index][objID]);
			case 3: format(sz_textStr, sizeof(sz_textStr), "X ROTATION~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left upper arm", objFloats[playerid][index][rotationX], index, objVars[playerid][index][objID]);
			case 4: format(sz_textStr, sizeof(sz_textStr), "X ROTATION~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right upper arm", objFloats[playerid][index][rotationX], index, objVars[playerid][index][objID]);
			case 5: format(sz_textStr, sizeof(sz_textStr), "X ROTATION~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left hand", objFloats[playerid][index][rotationX], index, objVars[playerid][index][objID]);
			case 6: format(sz_textStr, sizeof(sz_textStr), "X ROTATION~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right hand", objFloats[playerid][index][rotationX], index, objVars[playerid][index][objID]);
			case 7: format(sz_textStr, sizeof(sz_textStr), "X ROTATION~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left thigh", objFloats[playerid][index][rotationX], index, objVars[playerid][index][objID]);
			case 8: format(sz_textStr, sizeof(sz_textStr), "X ROTATION~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right thigh", objFloats[playerid][index][rotationX], index, objVars[playerid][index][objID]);
			case 9: format(sz_textStr, sizeof(sz_textStr), "X ROTATION~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left foot", objFloats[playerid][index][rotationX], index, objVars[playerid][index][objID]);
			case 10: format(sz_textStr, sizeof(sz_textStr), "X ROTATION~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right foot", objFloats[playerid][index][rotationX], index, objVars[playerid][index][objID]);
			case 11: format(sz_textStr, sizeof(sz_textStr), "X ROTATION~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right calf", objFloats[playerid][index][rotationX], index, objVars[playerid][index][objID]);
			case 12: format(sz_textStr, sizeof(sz_textStr), "X ROTATION~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left calf", objFloats[playerid][index][rotationX], index, objVars[playerid][index][objID]);
			case 13: format(sz_textStr, sizeof(sz_textStr), "X ROTATION~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left forearm", objFloats[playerid][index][rotationX], index, objVars[playerid][index][objID]);
			case 14: format(sz_textStr, sizeof(sz_textStr), "X ROTATION~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right forearm", objFloats[playerid][index][rotationX], index, objVars[playerid][index][objID]);
			case 15: format(sz_textStr, sizeof(sz_textStr), "X ROTATION~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left clavicle", objFloats[playerid][index][rotationX], index, objVars[playerid][index][objID]);
			case 16: format(sz_textStr, sizeof(sz_textStr), "X ROTATION~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right clavicle", objFloats[playerid][index][rotationX], index, objVars[playerid][index][objID]);
			case 17: format(sz_textStr, sizeof(sz_textStr), "X ROTATION~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Neck", objFloats[playerid][index][rotationX], index, objVars[playerid][index][objID]);
			case 18: format(sz_textStr, sizeof(sz_textStr), "X ROTATION~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Jaw", objFloats[playerid][index][rotationX], index, objVars[playerid][index][objID]);
			// default: format(sz_textStr, sizeof(sz_textStr), "EVERYTHING FUCKING BLOW UP NOW IT'S BONE ZERO!111");
		}	
		case 4: switch(objVars[playerid][index][objBone]) {
			case 1: format(sz_textStr, sizeof(sz_textStr), "Y ROTATION~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Spine", objFloats[playerid][index][rotationY], index, objVars[playerid][index][objID]);
			case 2: format(sz_textStr, sizeof(sz_textStr), "Y ROTATION~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Head", objFloats[playerid][index][rotationY], index, objVars[playerid][index][objID]);
			case 3: format(sz_textStr, sizeof(sz_textStr), "Y ROTATION~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left upper arm", objFloats[playerid][index][rotationY], index, objVars[playerid][index][objID]);
			case 4: format(sz_textStr, sizeof(sz_textStr), "Y ROTATION~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right upper arm", objFloats[playerid][index][rotationY], index, objVars[playerid][index][objID]);
			case 5: format(sz_textStr, sizeof(sz_textStr), "Y ROTATION~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left hand", objFloats[playerid][index][rotationY], index, objVars[playerid][index][objID]);
			case 6: format(sz_textStr, sizeof(sz_textStr), "Y ROTATION~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right hand", objFloats[playerid][index][rotationY], index, objVars[playerid][index][objID]);
			case 7: format(sz_textStr, sizeof(sz_textStr), "Y ROTATION~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left thigh", objFloats[playerid][index][rotationY], index, objVars[playerid][index][objID]);
			case 8: format(sz_textStr, sizeof(sz_textStr), "Y ROTATION~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right thigh", objFloats[playerid][index][rotationY], index, objVars[playerid][index][objID]);
			case 9: format(sz_textStr, sizeof(sz_textStr), "Y ROTATION~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left foot", objFloats[playerid][index][rotationY], index, objVars[playerid][index][objID]);
			case 10: format(sz_textStr, sizeof(sz_textStr), "Y ROTATION~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right foot", objFloats[playerid][index][rotationY], index, objVars[playerid][index][objID]);
			case 11: format(sz_textStr, sizeof(sz_textStr), "Y ROTATION~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right calf", objFloats[playerid][index][rotationY], index, objVars[playerid][index][objID]);
			case 12: format(sz_textStr, sizeof(sz_textStr), "Y ROTATION~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left calf", objFloats[playerid][index][rotationY], index, objVars[playerid][index][objID]);
			case 13: format(sz_textStr, sizeof(sz_textStr), "Y ROTATION~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left forearm", objFloats[playerid][index][rotationY], index, objVars[playerid][index][objID]);
			case 14: format(sz_textStr, sizeof(sz_textStr), "Y ROTATION~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right forearm", objFloats[playerid][index][rotationY], index, objVars[playerid][index][objID]);
			case 15: format(sz_textStr, sizeof(sz_textStr), "Y ROTATION~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left clavicle", objFloats[playerid][index][rotationY], index, objVars[playerid][index][objID]);
			case 16: format(sz_textStr, sizeof(sz_textStr), "Y ROTATION~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right clavicle", objFloats[playerid][index][rotationY], index, objVars[playerid][index][objID]);
			case 17: format(sz_textStr, sizeof(sz_textStr), "Y ROTATION~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Neck", objFloats[playerid][index][rotationY], index, objVars[playerid][index][objID]);
			case 18: format(sz_textStr, sizeof(sz_textStr), "Y ROTATION~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Jaw", objFloats[playerid][index][rotationY], index, objVars[playerid][index][objID]);
			// default: format(sz_textStr, sizeof(sz_textStr), "EVERYTHING FUCKING BLOW UP NOW IT'S BONE ZERO!111");
		}	
		case 5: switch(objVars[playerid][index][objBone]) {
			case 1: format(sz_textStr, sizeof(sz_textStr), "Z ROTATION~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Spine", objFloats[playerid][index][rotationZ], index, objVars[playerid][index][objID]);
			case 2: format(sz_textStr, sizeof(sz_textStr), "Z ROTATION~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Head", objFloats[playerid][index][rotationZ], index, objVars[playerid][index][objID]);
			case 3: format(sz_textStr, sizeof(sz_textStr), "Z ROTATION~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left upper arm", objFloats[playerid][index][rotationZ], index, objVars[playerid][index][objID]);
			case 4: format(sz_textStr, sizeof(sz_textStr), "Z ROTATION~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right upper arm", objFloats[playerid][index][rotationZ], index, objVars[playerid][index][objID]);
			case 5: format(sz_textStr, sizeof(sz_textStr), "Z ROTATION~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left hand", objFloats[playerid][index][rotationZ], index, objVars[playerid][index][objID]);
			case 6: format(sz_textStr, sizeof(sz_textStr), "Z ROTATION~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right hand", objFloats[playerid][index][rotationZ], index, objVars[playerid][index][objID]);
			case 7: format(sz_textStr, sizeof(sz_textStr), "Z ROTATION~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left thigh", objFloats[playerid][index][rotationZ], index, objVars[playerid][index][objID]);
			case 8: format(sz_textStr, sizeof(sz_textStr), "Z ROTATION~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right thigh", objFloats[playerid][index][rotationZ], index, objVars[playerid][index][objID]);
			case 9: format(sz_textStr, sizeof(sz_textStr), "Z ROTATION~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left foot", objFloats[playerid][index][rotationZ], index, objVars[playerid][index][objID]);
			case 10: format(sz_textStr, sizeof(sz_textStr), "Z ROTATION~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right foot", objFloats[playerid][index][rotationZ], index, objVars[playerid][index][objID]);
			case 11: format(sz_textStr, sizeof(sz_textStr), "Z ROTATION~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right calf", objFloats[playerid][index][rotationZ], index, objVars[playerid][index][objID]);
			case 12: format(sz_textStr, sizeof(sz_textStr), "Z ROTATION~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left calf", objFloats[playerid][index][rotationZ], index, objVars[playerid][index][objID]);
			case 13: format(sz_textStr, sizeof(sz_textStr), "Z ROTATION~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left forearm", objFloats[playerid][index][rotationZ], index, objVars[playerid][index][objID]);
			case 14: format(sz_textStr, sizeof(sz_textStr), "Z ROTATION~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right forearm", objFloats[playerid][index][rotationZ], index, objVars[playerid][index][objID]);
			case 15: format(sz_textStr, sizeof(sz_textStr), "Z ROTATION~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left clavicle", objFloats[playerid][index][rotationZ], index, objVars[playerid][index][objID]);
			case 16: format(sz_textStr, sizeof(sz_textStr), "Z ROTATION~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right clavicle", objFloats[playerid][index][rotationZ], index, objVars[playerid][index][objID]);
			case 17: format(sz_textStr, sizeof(sz_textStr), "Z ROTATION~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Neck", objFloats[playerid][index][rotationZ], index, objVars[playerid][index][objID]);
			case 18: format(sz_textStr, sizeof(sz_textStr), "Z ROTATION~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Jaw", objFloats[playerid][index][rotationZ], index, objVars[playerid][index][objID]);
			// default: format(sz_textStr, sizeof(sz_textStr), "EVERYTHING FUCKING BLOW UP NOW IT'S BONE ZERO!111");
		}	
		case 6: switch(objVars[playerid][index][objBone]) {
			case 1: format(sz_textStr, sizeof(sz_textStr), "X SCALE~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Spine", objFloats[playerid][index][scaleX], index, objVars[playerid][index][objID]);
			case 2: format(sz_textStr, sizeof(sz_textStr), "X SCALE~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Head", objFloats[playerid][index][scaleX], index, objVars[playerid][index][objID]);
			case 3: format(sz_textStr, sizeof(sz_textStr), "X SCALE~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left upper arm", objFloats[playerid][index][scaleX], index, objVars[playerid][index][objID]);
			case 4: format(sz_textStr, sizeof(sz_textStr), "X SCALE~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right upper arm", objFloats[playerid][index][scaleX], index, objVars[playerid][index][objID]);
			case 5: format(sz_textStr, sizeof(sz_textStr), "X SCALE~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left hand", objFloats[playerid][index][scaleX], index, objVars[playerid][index][objID]);
			case 6: format(sz_textStr, sizeof(sz_textStr), "X SCALE~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right hand", objFloats[playerid][index][scaleX], index, objVars[playerid][index][objID]);
			case 7: format(sz_textStr, sizeof(sz_textStr), "X SCALE~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left thigh", objFloats[playerid][index][scaleX], index, objVars[playerid][index][objID]);
			case 8: format(sz_textStr, sizeof(sz_textStr), "X SCALE~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right thigh", objFloats[playerid][index][scaleX], index, objVars[playerid][index][objID]);
			case 9: format(sz_textStr, sizeof(sz_textStr), "X SCALE~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left foot", objFloats[playerid][index][scaleX], index, objVars[playerid][index][objID]);
			case 10: format(sz_textStr, sizeof(sz_textStr), "X SCALE~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right foot", objFloats[playerid][index][scaleX], index, objVars[playerid][index][objID]);
			case 11: format(sz_textStr, sizeof(sz_textStr), "X SCALE~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right calf", objFloats[playerid][index][scaleX], index, objVars[playerid][index][objID]);
			case 12: format(sz_textStr, sizeof(sz_textStr), "X SCALE~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left calf", objFloats[playerid][index][scaleX], index, objVars[playerid][index][objID]);
			case 13: format(sz_textStr, sizeof(sz_textStr), "X SCALE~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left forearm", objFloats[playerid][index][scaleX], index, objVars[playerid][index][objID]);
			case 14: format(sz_textStr, sizeof(sz_textStr), "X SCALE~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right forearm", objFloats[playerid][index][scaleX], index, objVars[playerid][index][objID]);
			case 15: format(sz_textStr, sizeof(sz_textStr), "X SCALE~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left clavicle", objFloats[playerid][index][scaleX], index, objVars[playerid][index][objID]);
			case 16: format(sz_textStr, sizeof(sz_textStr), "X SCALE~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right clavicle", objFloats[playerid][index][scaleX], index, objVars[playerid][index][objID]);
			case 17: format(sz_textStr, sizeof(sz_textStr), "X SCALE~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Neck", objFloats[playerid][index][scaleX], index, objVars[playerid][index][objID]);
			case 18: format(sz_textStr, sizeof(sz_textStr), "X SCALE~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Jaw", objFloats[playerid][index][scaleX], index, objVars[playerid][index][objID]);
			// default: format(sz_textStr, sizeof(sz_textStr), "EVERYTHING FUCKING BLOW UP NOW IT'S BONE ZERO!111");
		}	
		case 7: switch(objVars[playerid][index][objBone]) {
			case 1: format(sz_textStr, sizeof(sz_textStr), "Y SCALE~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Spine", objFloats[playerid][index][scaleY], index, objVars[playerid][index][objID]);
			case 2: format(sz_textStr, sizeof(sz_textStr), "Y SCALE~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Head", objFloats[playerid][index][scaleY], index, objVars[playerid][index][objID]);
			case 3: format(sz_textStr, sizeof(sz_textStr), "Y SCALE~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left upper arm", objFloats[playerid][index][scaleY], index, objVars[playerid][index][objID]);
			case 4: format(sz_textStr, sizeof(sz_textStr), "Y SCALE~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right upper arm", objFloats[playerid][index][scaleY], index, objVars[playerid][index][objID]);
			case 5: format(sz_textStr, sizeof(sz_textStr), "Y SCALE~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left hand", objFloats[playerid][index][scaleY], index, objVars[playerid][index][objID]);
			case 6: format(sz_textStr, sizeof(sz_textStr), "Y SCALE~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right hand", objFloats[playerid][index][scaleY], index, objVars[playerid][index][objID]);
			case 7: format(sz_textStr, sizeof(sz_textStr), "Y SCALE~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left thigh", objFloats[playerid][index][scaleY], index, objVars[playerid][index][objID]);
			case 8: format(sz_textStr, sizeof(sz_textStr), "Y SCALE~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right thigh", objFloats[playerid][index][scaleY], index, objVars[playerid][index][objID]);
			case 9: format(sz_textStr, sizeof(sz_textStr), "Y SCALE~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left foot", objFloats[playerid][index][scaleY], index, objVars[playerid][index][objID]);
			case 10: format(sz_textStr, sizeof(sz_textStr), "Y SCALE~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right foot", objFloats[playerid][index][scaleY], index, objVars[playerid][index][objID]);
			case 11: format(sz_textStr, sizeof(sz_textStr), "Y SCALE~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right calf", objFloats[playerid][index][scaleY], index, objVars[playerid][index][objID]);
			case 12: format(sz_textStr, sizeof(sz_textStr), "Y SCALE~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left calf", objFloats[playerid][index][scaleY], index, objVars[playerid][index][objID]);
			case 13: format(sz_textStr, sizeof(sz_textStr), "Y SCALE~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left forearm", objFloats[playerid][index][scaleY], index, objVars[playerid][index][objID]);
			case 14: format(sz_textStr, sizeof(sz_textStr), "Y SCALE~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right forearm", objFloats[playerid][index][scaleY], index, objVars[playerid][index][objID]);
			case 15: format(sz_textStr, sizeof(sz_textStr), "Y SCALE~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left clavicle", objFloats[playerid][index][scaleY], index, objVars[playerid][index][objID]);
			case 16: format(sz_textStr, sizeof(sz_textStr), "Y SCALE~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right clavicle", objFloats[playerid][index][scaleY], index, objVars[playerid][index][objID]);
			case 17: format(sz_textStr, sizeof(sz_textStr), "Y SCALE~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Neck", objFloats[playerid][index][scaleY], index, objVars[playerid][index][objID]);
			case 18: format(sz_textStr, sizeof(sz_textStr), "Y SCALE~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Jaw", objFloats[playerid][index][scaleY], index, objVars[playerid][index][objID]);
			// default: format(sz_textStr, sizeof(sz_textStr), "EVERYTHING FUCKING BLOW UP NOW IT'S BONE ZERO!111");
		}	
		case 8: switch(objVars[playerid][index][objBone]) {
			case 1: format(sz_textStr, sizeof(sz_textStr), "Z SCALE~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Spine", objFloats[playerid][index][scaleZ], index, objVars[playerid][index][objID]);
			case 2: format(sz_textStr, sizeof(sz_textStr), "Z SCALE~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Head", objFloats[playerid][index][scaleZ], index, objVars[playerid][index][objID]);
			case 3: format(sz_textStr, sizeof(sz_textStr), "Z SCALE~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left upper arm", objFloats[playerid][index][scaleZ], index, objVars[playerid][index][objID]);
			case 4: format(sz_textStr, sizeof(sz_textStr), "Z SCALE~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right upper arm", objFloats[playerid][index][scaleZ], index, objVars[playerid][index][objID]);
			case 5: format(sz_textStr, sizeof(sz_textStr), "Z SCALE~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left hand", objFloats[playerid][index][scaleZ], index, objVars[playerid][index][objID]);
			case 6: format(sz_textStr, sizeof(sz_textStr), "Z SCALE~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right hand", objFloats[playerid][index][scaleZ], index, objVars[playerid][index][objID]);
			case 7: format(sz_textStr, sizeof(sz_textStr), "Z SCALE~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left thigh", objFloats[playerid][index][scaleZ], index, objVars[playerid][index][objID]);
			case 8: format(sz_textStr, sizeof(sz_textStr), "Z SCALE~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right thigh", objFloats[playerid][index][scaleZ], index, objVars[playerid][index][objID]);
			case 9: format(sz_textStr, sizeof(sz_textStr), "Z SCALE~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left foot", objFloats[playerid][index][scaleZ], index, objVars[playerid][index][objID]);
			case 10: format(sz_textStr, sizeof(sz_textStr), "Z SCALE~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right foot", objFloats[playerid][index][scaleZ], index, objVars[playerid][index][objID]);
			case 11: format(sz_textStr, sizeof(sz_textStr), "Z SCALE~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right calf", objFloats[playerid][index][scaleZ], index, objVars[playerid][index][objID]);
			case 12: format(sz_textStr, sizeof(sz_textStr), "Z SCALE~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left calf", objFloats[playerid][index][scaleZ], index, objVars[playerid][index][objID]);
			case 13: format(sz_textStr, sizeof(sz_textStr), "Z SCALE~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left forearm", objFloats[playerid][index][scaleZ], index, objVars[playerid][index][objID]);
			case 14: format(sz_textStr, sizeof(sz_textStr), "Z SCALE~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right forearm", objFloats[playerid][index][scaleZ], index, objVars[playerid][index][objID]);
			case 15: format(sz_textStr, sizeof(sz_textStr), "Z SCALE~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Left clavicle", objFloats[playerid][index][scaleZ], index, objVars[playerid][index][objID]);
			case 16: format(sz_textStr, sizeof(sz_textStr), "Z SCALE~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Right clavicle", objFloats[playerid][index][scaleZ], index, objVars[playerid][index][objID]);
			case 17: format(sz_textStr, sizeof(sz_textStr), "Z SCALE~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Neck", objFloats[playerid][index][scaleZ], index, objVars[playerid][index][objID]);
			case 18: format(sz_textStr, sizeof(sz_textStr), "Z SCALE~n~~r~%f~w~~n~~n~INDEX: ~r~%i~w~~n~~n~OBJECT: ~r~%i~w~~n~~n~BONE:~r~ Jaw", objFloats[playerid][index][scaleZ], index, objVars[playerid][index][objID]);
			// default: format(sz_textStr, sizeof(sz_textStr), "EVERYTHING FUCKING BLOW UP NOW IT'S BONE ZERO!111");
		}	
	}
	TextDrawSetString(editorVars[playerid][editingText], sz_textStr);
	return SetPlayerAttachedObject(playerid, index, objVars[playerid][index][objID], objVars[playerid][index][objBone], objFloats[playerid][index][offsetX], objFloats[playerid][index][offsetY], objFloats[playerid][index][offsetZ], objFloats[playerid][index][rotationX], objFloats[playerid][index][rotationY], objFloats[playerid][index][rotationZ], objFloats[playerid][index][scaleX], objFloats[playerid][index][scaleY], objFloats[playerid][index][scaleZ]);
}

public OnPlayerUpdate(playerid) {
	if(editorVars[playerid][editingStat] >= 0) {
		new
			i_Keys[3];
			
		GetPlayerKeys(playerid, i_Keys[0], i_Keys[1], i_Keys[2]);
		
		if(i_Keys[1] < 0) {
			if(i_Keys[0] & KEY_SPRINT) objFloats[playerid][editorVars[playerid][editingIndex]][editorVars[playerid][editingStat]] += 1.0;
			else if(i_Keys[0] & KEY_SECONDARY_ATTACK) objFloats[playerid][editorVars[playerid][editingIndex]][editorVars[playerid][editingStat]] += 0.01;
			else if(i_Keys[0] == 0) objFloats[playerid][editorVars[playerid][editingIndex]][editorVars[playerid][editingStat]] += 0.1;
			updateAttachedObject(playerid, editorVars[playerid][editingIndex]);
		}
		else if(i_Keys[1] > 0) {
			if(i_Keys[0] & KEY_SPRINT) objFloats[playerid][editorVars[playerid][editingIndex]][editorVars[playerid][editingStat]] -= 1.0;
			else if(i_Keys[0] & KEY_SECONDARY_ATTACK) objFloats[playerid][editorVars[playerid][editingIndex]][editorVars[playerid][editingStat]] -= 0.01;
			else if(i_Keys[0] == 0) objFloats[playerid][editorVars[playerid][editingIndex]][editorVars[playerid][editingStat]] -= 0.1;
			updateAttachedObject(playerid, editorVars[playerid][editingIndex]);
		}
		else if(i_Keys[2] > 0) {
			switch(editorVars[playerid][editingStat]) {
				case 0 .. 7: editorVars[playerid][editingStat]++;
				default: editorVars[playerid][editingStat] = 0;
			}
			updateAttachedObject(playerid, editorVars[playerid][editingIndex]);
		}
		else if(i_Keys[2] < 0) {
			switch(editorVars[playerid][editingStat]) {
				case 1 .. 8: editorVars[playerid][editingStat]--;
				default: editorVars[playerid][editingStat] = 8;
			}
			updateAttachedObject(playerid, editorVars[playerid][editingIndex]);
		}
	}
	return 1;
}

public OnPlayerSpawn(playerid) {
	return SendClientMessage(playerid, COLOR_WHITE, "Use {B9FF2B}/editor{FFFFFF} to begin.");
}

public OnFilterScriptInit() {
	return print("[Attachment Editor] Loaded.\r\n~ a creation of bren. ~");
}

public OnFilterScriptExit() {
	print("[Attachment Editor] Unloaded - removing all existing objects...");
	
	#if !defined foreach
		#define foreach(Player,%0) for(new %0; %0 < MAX_PLAYERS; %0++) if(IsPlayerConnected(%0))
	#endif
	
	foreach(Player, x) {
		for(new a; a < MAX_PLAYER_ATTACHED_OBJECTS; a++) if(objVars[x][a][objID] >= 0) {
			resetSlot(x, a);
		}
	}
	return print("[Attachment Editor] Complete!");
}

public OnPlayerConnect(playerid) {
	
	editorVars[playerid][editingText] = TextDrawCreate(622.000000, 298.000000, "X OFFSET~n~200.0~n~~n~INDEX: 5~n~~n~OBJECT: 1337~n~~n~BONE: Head");
	TextDrawAlignment(editorVars[playerid][editingText], 3);
	TextDrawFont(editorVars[playerid][editingText], 1);
	TextDrawLetterSize(editorVars[playerid][editingText], 0.390000, 1.600000);
	TextDrawColor(editorVars[playerid][editingText], -1);
	TextDrawSetOutline(editorVars[playerid][editingText], 1);
	TextDrawSetProportional(editorVars[playerid][editingText], 1);
	
	editorVars[playerid][editingIndex] = -1;
	editorVars[playerid][editingStat] = -1;
	
	for(new x; x < MAX_PLAYER_ATTACHED_OBJECTS; x++) {
		resetSlot(playerid, x);
	}
	return 1;
}

public OnPlayerDisconnect(playerid, reason) {
	editorVars[playerid][editingStat] = -1;
	return TextDrawDestroy(editorVars[playerid][editingText]);
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]) {
	switch(dialogid) {
		case DIALOG_START: {
			if(response) switch(listitem) {
				case 0: {
				
					new
						i_Iter;
						
					while(i_Iter < MAX_PLAYER_ATTACHED_OBJECTS) {
						if(!IsPlayerAttachedObjectSlotUsed(playerid, i_Iter)) {
							editorVars[playerid][editingIndex] = i_Iter;
							return ShowPlayerDialog(playerid, DIALOG_OBJECT, DIALOG_STYLE_INPUT, "{B9FF2B}EDITOR:{FFFFFF} Object", "Specify an object ID you wish to attach.", "Select", "Return");
						}
						i_Iter++;
					}
					SendClientMessage(playerid, COLOR_WHITE, "All available object slots are in use - delete one first.");
					ShowPlayerDialog(playerid, DIALOG_START, DIALOG_STYLE_LIST, "{B9FF2B}EDITOR:{FFFFFF} Start", "Add New Object\r\nEdit Existing Object\r\nRemove Object", "Select", "Return");
				}	
				case 1: {
					
					new
						sz_dialogStr[256], // Needs $$$$$$$$$$$$ size $$$$$$$$$$$
						i_Iter;
						
					while(i_Iter < MAX_PLAYER_ATTACHED_OBJECTS) {
						if(objVars[playerid][i_Iter][objID] == -1) {
							if(!i_Iter) format(sz_dialogStr, sizeof(sz_dialogStr), "Index %i: {FF5F47}Unused{FFFFFF}", i_Iter);
							else format(sz_dialogStr, sizeof(sz_dialogStr), "%s\r\nIndex %i: {FF5F47}Unused{FFFFFF}", sz_dialogStr, i_Iter, objVars[playerid][i_Iter][objID]);
						}
						else {
							if(!i_Iter) format(sz_dialogStr, sizeof(sz_dialogStr), "Index {B9FF2B}%i{FFFFFF}: Object ID {B9FF2B}%i{FFFFFF}", i_Iter, objVars[playerid][i_Iter][objID]);
							else format(sz_dialogStr, sizeof(sz_dialogStr), "%s\r\nIndex {B9FF2B}%i{FFFFFF}: Object ID {B9FF2B}%i{FFFFFF}", sz_dialogStr, i_Iter, objVars[playerid][i_Iter][objID]);
						}
						++i_Iter;
					}
					ShowPlayerDialog(playerid, DIALOG_EDIT, DIALOG_STYLE_LIST, "{B9FF2B}EDITOR:{FFFFFF} Edit Existing Object", sz_dialogStr, "Select", "Return");
				}
				case 2: {
					new
						sz_dialogStr[256],
						i_Iter;
						
					while(i_Iter < MAX_PLAYER_ATTACHED_OBJECTS) {
						if(objVars[playerid][i_Iter][objID] == -1) {
							if(!i_Iter) format(sz_dialogStr, sizeof(sz_dialogStr), "Index %i: {FF5F47}Unused{FFFFFF}", i_Iter);
							else format(sz_dialogStr, sizeof(sz_dialogStr), "%s\r\nIndex %i: {FF5F47}Unused{FFFFFF}", sz_dialogStr, i_Iter, objVars[playerid][i_Iter][objID]);
						}
						else {
							if(!i_Iter) format(sz_dialogStr, sizeof(sz_dialogStr), "Index {B9FF2B}%i{FFFFFF}: Object ID {B9FF2B}%i{FFFFFF}", i_Iter, objVars[playerid][i_Iter][objID]);
							else format(sz_dialogStr, sizeof(sz_dialogStr), "%s\r\nIndex {B9FF2B}%i{FFFFFF}: Object ID {B9FF2B}%i{FFFFFF}", sz_dialogStr, i_Iter, objVars[playerid][i_Iter][objID]);
						}
						++i_Iter;
					}
					ShowPlayerDialog(playerid, DIALOG_DELETE, DIALOG_STYLE_LIST, "{B9FF2B}EDITOR:{FFFFFF} Delete Object", sz_dialogStr, "Select", "Return");				
				}
			}
		}
		case DIALOG_EDIT: {
			if(response) {
				if(objVars[playerid][listitem][objID] == -1) {
					SendClientMessage(playerid, COLOR_GREY, "This index is not in use; therefore, it can not be edited.");
					
					new
						sz_dialogStr[256],
						i_Iter;
						
					while(i_Iter < MAX_PLAYER_ATTACHED_OBJECTS) {
						if(objVars[playerid][i_Iter][objID] == -1) {
							if(!i_Iter) format(sz_dialogStr, sizeof(sz_dialogStr), "Index %i: {FF5F47}Unused{FFFFFF}", i_Iter);
							else format(sz_dialogStr, sizeof(sz_dialogStr), "%s\r\nIndex %i: {FF5F47}Unused{FFFFFF}", sz_dialogStr, i_Iter, objVars[playerid][i_Iter][objID]);
						}
						else {
							if(!i_Iter) format(sz_dialogStr, sizeof(sz_dialogStr), "Index {B9FF2B}%i{FFFFFF}: Object ID {B9FF2B}%i{FFFFFF}", i_Iter, objVars[playerid][i_Iter][objID]);
							else format(sz_dialogStr, sizeof(sz_dialogStr), "%s\r\nIndex {B9FF2B}%i{FFFFFF}: Object ID {B9FF2B}%i{FFFFFF}", sz_dialogStr, i_Iter, objVars[playerid][i_Iter][objID]);
						}
						++i_Iter;
					}
					ShowPlayerDialog(playerid, DIALOG_EDIT, DIALOG_STYLE_LIST, "{B9FF2B}EDITOR:{FFFFFF} Edit Existing Object", sz_dialogStr, "Select", "Return");
				}
				else {
					editorVars[playerid][editingIndex] = listitem;
					editorVars[playerid][editingStat] = 0;
					
					updateAttachedObject(playerid, editorVars[playerid][editingIndex]);
					TogglePlayerControllable(playerid, false);
					
					TextDrawShowForPlayer(playerid, editorVars[playerid][editingText]);
					SendClientMessage(playerid, COLOR_WHITE, "Use the {B9FF2B}up{FFFFFF} and {B9FF2B}down{FFFFFF} keys to move the object. Press {B9FF2B}jump{FFFFFF} to return to the menu.");
					SendClientMessage(playerid, COLOR_WHITE, "The current editing axis may be changed at any time with the {B9FF2B}left{FFFFFF} or {B9FF2B}right{FFFFFF} keys.");
					SendClientMessage(playerid, COLOR_WHITE, "Use {B9FF2B}sprint{FFFFFF} for a speed boost, or {B9FF2B}enter{FFFFFF} for accuracy, {B9FF2B}/saveattachments{FFFFFF} to save.");				
				}
			}
			else ShowPlayerDialog(playerid, DIALOG_START, DIALOG_STYLE_LIST, "{B9FF2B}EDITOR:{FFFFFF} Start", "Add New Object\r\nEdit Existing Object\r\nRemove Object", "Select", "Return");
		}
		case DIALOG_DELETE: {
			if(response) {
				if(objVars[playerid][listitem][objID] == -1) {
					SendClientMessage(playerid, COLOR_GREY, "This index is not in use; therefore, it can not be deleted.");
					
					new
						sz_dialogStr[256],
						i_Iter;
						
					while(i_Iter < MAX_PLAYER_ATTACHED_OBJECTS) {
						if(objVars[playerid][i_Iter][objID] == -1) {
							if(!i_Iter) format(sz_dialogStr, sizeof(sz_dialogStr), "Index %i: {FF5F47}Unused{FFFFFF}", i_Iter);
							else format(sz_dialogStr, sizeof(sz_dialogStr), "%s\r\nIndex %i: {FF5F47}Unused{FFFFFF}", sz_dialogStr, i_Iter, objVars[playerid][i_Iter][objID]);
						}
						else {
							if(!i_Iter) format(sz_dialogStr, sizeof(sz_dialogStr), "Index {B9FF2B}%i{FFFFFF}: Object ID {B9FF2B}%i{FFFFFF}", i_Iter, objVars[playerid][i_Iter][objID]);
							else format(sz_dialogStr, sizeof(sz_dialogStr), "%s\r\nIndex {B9FF2B}%i{FFFFFF}: Object ID {B9FF2B}%i{FFFFFF}", sz_dialogStr, i_Iter, objVars[playerid][i_Iter][objID]);
						}
						++i_Iter;
					}
					ShowPlayerDialog(playerid, DIALOG_DELETE, DIALOG_STYLE_LIST, "{B9FF2B}EDITOR:{FFFFFF} Delete Object", sz_dialogStr, "Select", "Return");
				}
				else {
					SendClientMessage(playerid, COLOR_WHITE, "You have successfully {B9FF2B}deleted{FFFFFF} this object.");
					resetSlot(playerid, listitem);
					
					new
						sz_dialogStr[256],
						i_Iter;
						
					while(i_Iter < MAX_PLAYER_ATTACHED_OBJECTS) {
						if(objVars[playerid][i_Iter][objID] == -1) {
							if(!i_Iter) format(sz_dialogStr, sizeof(sz_dialogStr), "Index %i: {FF5F47}Unused{FFFFFF}", i_Iter);
							else format(sz_dialogStr, sizeof(sz_dialogStr), "%s\r\nIndex %i: {FF5F47}Unused{FFFFFF}", sz_dialogStr, i_Iter, objVars[playerid][i_Iter][objID]);
						}
						else {
							if(!i_Iter) format(sz_dialogStr, sizeof(sz_dialogStr), "Index {B9FF2B}%i{FFFFFF}: Object ID {B9FF2B}%i{FFFFFF}", i_Iter, objVars[playerid][i_Iter][objID]);
							else format(sz_dialogStr, sizeof(sz_dialogStr), "%s\r\nIndex {B9FF2B}%i{FFFFFF}: Object ID {B9FF2B}%i{FFFFFF}", sz_dialogStr, i_Iter, objVars[playerid][i_Iter][objID]);
						}
						++i_Iter;
					}
					ShowPlayerDialog(playerid, DIALOG_DELETE, DIALOG_STYLE_LIST, "{B9FF2B}EDITOR:{FFFFFF} Delete Object", sz_dialogStr, "Select", "Return");
				}
			}
			else ShowPlayerDialog(playerid, DIALOG_START, DIALOG_STYLE_LIST, "{B9FF2B}EDITOR:{FFFFFF} Start", "Add New Object\r\nEdit Existing Object\r\nRemove Object", "Select", "Return");
		}
		case DIALOG_OBJECT: {
			if(response) switch(strval(inputtext)) {
				case 321 .. 3399: {
					objVars[playerid][editorVars[playerid][editingIndex]][objID] = strval(inputtext);
					ShowPlayerDialog(playerid, DIALOG_BONE, DIALOG_STYLE_LIST, "{B9FF2B}EDITOR:{FFFFFF} Bone", "Spine\r\nHead\r\nLeft upper arm\r\nRight upper arm\r\nLeft hand\r\nRight hand\r\nLeft thigh\r\nRight thigh\r\nLeft foot\r\nRight foot\r\nRight calf\r\nLeft calf\r\nLeft forearm\r\nRight forearm\r\nLeft clavicle\r\nRight clavicle\r\nNeck\r\nJaw", "Select", "Return");
				}
				default: ShowPlayerDialog(playerid, DIALOG_OBJECT, DIALOG_STYLE_INPUT, "{B9FF2B}EDITOR:{FFFFFF} Object", "Invalid object specified.\n\nSpecify an object ID you wish to attach.", "Select", "Return");
			}
			else {
				ShowPlayerDialog(playerid, DIALOG_START, DIALOG_STYLE_LIST, "{B9FF2B}EDITOR:{FFFFFF} Start", "Add New Object\r\nEdit Existing Object\r\nRemove Object", "Select", "Return");
				editorVars[playerid][editingIndex] = -1;
			}
		}
		case DIALOG_BONE: {
			if(response) {
				editorVars[playerid][editingStat] = 0;
				objVars[playerid][editorVars[playerid][editingIndex]][objBone] = listitem + 1;
				
				updateAttachedObject(playerid, editorVars[playerid][editingIndex]);
				TogglePlayerControllable(playerid, false);
				
				TextDrawShowForPlayer(playerid, editorVars[playerid][editingText]);
				SendClientMessage(playerid, COLOR_WHITE, "Use the {B9FF2B}up{FFFFFF} and {B9FF2B}down{FFFFFF} keys to move the object. Press {B9FF2B}jump{FFFFFF} to return to the menu.");
				SendClientMessage(playerid, COLOR_WHITE, "The current editing axis may be changed at any time with the {B9FF2B}left{FFFFFF} or {B9FF2B}right{FFFFFF} keys.");
				SendClientMessage(playerid, COLOR_WHITE, "Use {B9FF2B}sprint{FFFFFF} for a speed boost, or {B9FF2B}enter{FFFFFF} for accuracy, {B9FF2B}/saveattachments{FFFFFF} to save.");
			}
			else ShowPlayerDialog(playerid, DIALOG_OBJECT, DIALOG_STYLE_INPUT, "{B9FF2B}EDITOR:{FFFFFF} Object", "Specify an object ID you wish to attach.", "Select", "Return");
		}
	}
	return 1;
}

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
	if(IsKeyJustDown(KEY_JUMP) && editorVars[playerid][editingIndex] >= 0) {
		
		TextDrawHideForPlayer(playerid, editorVars[playerid][editingText]);
		editorVars[playerid][editingIndex] = -1;
		editorVars[playerid][editingStat] = -1;
		
		new
			sz_dialogStr[256], // Needs $$$$$$$$$$$$ size $$$$$$$$$$$
			i_Iter;
			
		while(i_Iter < MAX_PLAYER_ATTACHED_OBJECTS) {
			if(objVars[playerid][i_Iter][objID] == -1) {
				if(!i_Iter) format(sz_dialogStr, sizeof(sz_dialogStr), "Index %i: {FF5F47}Unused{FFFFFF}", i_Iter);
				else format(sz_dialogStr, sizeof(sz_dialogStr), "%s\r\nIndex %i: {FF5F47}Unused{FFFFFF}", sz_dialogStr, i_Iter, objVars[playerid][i_Iter][objID]);
			}
			else {
				if(!i_Iter) format(sz_dialogStr, sizeof(sz_dialogStr), "Index {B9FF2B}%i{FFFFFF}: Object ID {B9FF2B}%i{FFFFFF}", i_Iter, objVars[playerid][i_Iter][objID]);
				else format(sz_dialogStr, sizeof(sz_dialogStr), "%s\r\nIndex {B9FF2B}%i{FFFFFF}: Object ID {B9FF2B}%i{FFFFFF}", sz_dialogStr, i_Iter, objVars[playerid][i_Iter][objID]);
			}
			++i_Iter;
		}
		ShowPlayerDialog(playerid, DIALOG_EDIT, DIALOG_STYLE_LIST, "{B9FF2B}EDITOR:{FFFFFF} Edit Existing Object", sz_dialogStr, "Select", "Return");
		TogglePlayerControllable(playerid, true);
	}
	return 1;
}

CMD:editor(playerid, params[]) {
	switch(editorVars[playerid][editingIndex]) {
		case -1: ShowPlayerDialog(playerid, DIALOG_START, DIALOG_STYLE_LIST, "{B9FF2B}EDITOR:{FFFFFF} Start", "Add New Object\r\nEdit Existing Object\r\nRemove Object", "Select", "Return");
		default: {
			TogglePlayerControllable(playerid, true);
			TextDrawHideForPlayer(playerid, editorVars[playerid][editingText]);
			editorVars[playerid][editingIndex] = -1;
			editorVars[playerid][editingStat] = -1;		
		}
	}
	return 1;
}

CMD:saveattachments(playerid, params[]) {
	
	new
		i_Iter;
		
	while(i_Iter < MAX_PLAYER_ATTACHED_OBJECTS) {
		if(IsPlayerAttachedObjectSlotUsed(playerid, i_Iter)) break;
		++i_Iter;
	}
	if(i_Iter == MAX_PLAYER_ATTACHED_OBJECTS) {
		return SendClientMessage(playerid, COLOR_GREY, "You have no attached objects to save.");
	}
	i_Iter = 0;
		
	while(params[i_Iter] > 0) {
		if(params[i_Iter] == '\\') {
			return SendClientMessage(playerid, COLOR_GREY, "Escape characters ({B9FF2B}'\\'{CECECE}) may not be used in comments.");
		}
		++i_Iter;
	}

    new 
		arr_TimeStamper[2][3],
		File: i_objFile,
		sz_Formatted[256];
		
	i_objFile = fopen(SAVED_OBJECT_FILE, io_append);
	
	getdate(arr_TimeStamper[0][0], arr_TimeStamper[0][1], arr_TimeStamper[0][2]);
	gettime(arr_TimeStamper[1][0], arr_TimeStamper[1][1], arr_TimeStamper[1][2]);

	format(sz_Formatted, sizeof(sz_Formatted), "SESSION DATE (%i/%i/%i) TIME (%i:%i.%i) COMMENT:", arr_TimeStamper[0][2], arr_TimeStamper[0][1], arr_TimeStamper[0][0], arr_TimeStamper[1][0], arr_TimeStamper[1][1], arr_TimeStamper[1][2]);
	fwrite(i_objFile, sz_Formatted);
	fwrite(i_objFile, params);
	fwrite(i_objFile, "\r\n");
	
	for(new x; x < MAX_PLAYER_ATTACHED_OBJECTS; x++) if(IsPlayerAttachedObjectSlotUsed(playerid, x)) {
		format(sz_Formatted, sizeof(sz_Formatted), "SetPlayerAttachedObject(playerid, %i, %i, %i, %f, %f, %f, %f, %f, %f, %f, %f, %f);\r\n", x, objVars[playerid][x][objID], objVars[playerid][x][objBone], objFloats[playerid][x][offsetX], objFloats[playerid][x][offsetY], objFloats[playerid][x][offsetZ], objFloats[playerid][x][rotationX], objFloats[playerid][x][rotationY], objFloats[playerid][x][rotationZ], objFloats[playerid][x][scaleX], objFloats[playerid][x][scaleY], objFloats[playerid][x][scaleZ]);
		fwrite(i_objFile, sz_Formatted);
	}
	
	fclose(i_objFile);
	SendClientMessage(playerid, COLOR_WHITE, "All attached objects have been saved to {B9FF2B}'attachments.txt'{FFFFFF}, inside your {B9FF2B}/scriptfiles/{FFFFFF} directory.");
	return 1;
}