/*!
 * Vehicles/callbacks/OnDialogResponse.inc
 *
 * OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
 *
 > Priority: 0
 */

{
	switch (dialogid) {

		case DIALOG_ID_NEON: {

        	if (response) {

        		if (listitem < 6) {

        			new modelID = 18647 + listitem;
        			CreateNeons(playerid, modelID);

        			SendClientMessageEmote(playerid, "%s modifies the %v with neon lights.", Player.Info[playerid][Name], GetPlayerVehicleName(playerid));

                    return 1;
        		} else {

        			DestroyNeons(playerid);

                    return 1;
        		}
            }
		}
	}
}
