/*!
 * Inventory/header.inc
 *
 > Priority: 0
 */

enum ItemTypes {
 	ItemCB,
 	ItemCalc,
    ItemPhoneBook,
    ItemCards,
    ItemDice, 
    ItemSleepingBag,
    // --- gun parts ---
    ItemShells,
    ItemRifleStocks,
    // --- drug parts ---
    // general
    ItemLightsLeft,
    ItemBunsonBurner,
    // PCP
    ItemHydroChloride,
    ItemPCP,
    ItemCyanide,
    // LSD
    ItemBlotterPaper, // amount of LSD a player has
    ItemLysergicAcid,
    ItemWaxPaper,
    ItemPot, // amount of pot a player has
    ItemRollingPapers,
    ItemBluntWraps,
    ItemPipe,
    ItemBong,
    ItemCrack,
    
    NumItems
}

new this.Info[MAX_PLAYERS][ItemTypes];