LilycoveCity_LilycoveMuseum_Exterior_MapScripts::
	.byte 0


MysteryGiftGirl_GiveItems::
# 6 "data/maps/LilycoveCity_LilycoveMuseum_Exterior/scripts.pory"
	lock
# 7 "data/maps/LilycoveCity_LilycoveMuseum_Exterior/scripts.pory"
	setflag FLAG_ENABLE_SHIP_SOUTHERN_ISLAND
# 8 "data/maps/LilycoveCity_LilycoveMuseum_Exterior/scripts.pory"
	setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
# 9 "data/maps/LilycoveCity_LilycoveMuseum_Exterior/scripts.pory"
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
# 10 "data/maps/LilycoveCity_LilycoveMuseum_Exterior/scripts.pory"
	setflag FLAG_ENABLE_SHIP_FARAWAY_ISLAND
# 11 "data/maps/LilycoveCity_LilycoveMuseum_Exterior/scripts.pory"
	goto_if_unset FLAG_LILYCOVE_MYSTERYGIFT_GIRL_SPOKEN, MysteryGiftGirl_GiveItems_2
# 31 "data/maps/LilycoveCity_LilycoveMuseum_Exterior/scripts.pory"
	msgbox MysteryGiftGirl_GiveItems_Text_3, MSGBOX_NPC
# 32 "data/maps/LilycoveCity_LilycoveMuseum_Exterior/scripts.pory"
	waitmessage
# 33 "data/maps/LilycoveCity_LilycoveMuseum_Exterior/scripts.pory"
	pokemart MysteryGiftGirl_Items
MysteryGiftGirl_GiveItems_1:
# 36 "data/maps/LilycoveCity_LilycoveMuseum_Exterior/scripts.pory"
	release
	return

MysteryGiftGirl_GiveItems_2:
# 12 "data/maps/LilycoveCity_LilycoveMuseum_Exterior/scripts.pory"
	setflag FLAG_LILYCOVE_MYSTERYGIFT_GIRL_SPOKEN
# 13 "data/maps/LilycoveCity_LilycoveMuseum_Exterior/scripts.pory"
	msgbox MysteryGiftGirl_GiveItems_Text_0, MSGBOX_SIGN
# 19 "data/maps/LilycoveCity_LilycoveMuseum_Exterior/scripts.pory"
	closemessage
# 20 "data/maps/LilycoveCity_LilycoveMuseum_Exterior/scripts.pory"
	playse SE_M_ICY_WIND
# 21 "data/maps/LilycoveCity_LilycoveMuseum_Exterior/scripts.pory"
	waitse
# 22 "data/maps/LilycoveCity_LilycoveMuseum_Exterior/scripts.pory"
	msgbox MysteryGiftGirl_GiveItems_Text_1, MSGBOX_SIGN
# 24 "data/maps/LilycoveCity_LilycoveMuseum_Exterior/scripts.pory"
	msgbox MysteryGiftGirl_GiveItems_Text_2, MSGBOX_NPC
# 27 "data/maps/LilycoveCity_LilycoveMuseum_Exterior/scripts.pory"
	waitmessage
# 28 "data/maps/LilycoveCity_LilycoveMuseum_Exterior/scripts.pory"
	pokemart MysteryGiftGirl_Items
	goto MysteryGiftGirl_GiveItems_1


	.align 2
# 39 "data/maps/LilycoveCity_LilycoveMuseum_Exterior/scripts.pory"
MysteryGiftGirl_Items:
# 40 "data/maps/LilycoveCity_LilycoveMuseum_Exterior/scripts.pory"
	.2byte ITEM_MYSTIC_TICKET
# 41 "data/maps/LilycoveCity_LilycoveMuseum_Exterior/scripts.pory"
	.2byte ITEM_EON_TICKET
# 42 "data/maps/LilycoveCity_LilycoveMuseum_Exterior/scripts.pory"
	.2byte ITEM_AURORA_TICKET
# 43 "data/maps/LilycoveCity_LilycoveMuseum_Exterior/scripts.pory"
	.2byte ITEM_OLD_SEA_MAP
# 44 "data/maps/LilycoveCity_LilycoveMuseum_Exterior/scripts.pory"
	.2byte ITEM_ENIGMA_BERRY
	.2byte ITEM_NONE

LilycoveLookout_Sign::
# 48 "data/maps/LilycoveCity_LilycoveMuseum_Exterior/scripts.pory"
	msgbox LilycoveLookout_Sign_Text_0, MSGBOX_SIGN
	return


MysteryGiftGirl_GiveItems_Text_0:
# 13 "data/maps/LilycoveCity_LilycoveMuseum_Exterior/scripts.pory"
	.string "............\p"
	.string "I was born in a very distant land.\p"
	.string "I have travelled to wonderous places\n"
	.string "and seen many beautiful things.\p"
	.string "And then I came to the HOENN region...\n"
	.string "I feel this is the place I truly belong...\p"
	.string "No matter how far I travel - sea, land or\n"
	.string "sky, it always leads back here.$"

MysteryGiftGirl_GiveItems_Text_1:
# 22 "data/maps/LilycoveCity_LilycoveMuseum_Exterior/scripts.pory"
	.string "Feel that coastal breeze...{PAUSE 60}\n"
	.string "it's pleasant isn't it?$"

MysteryGiftGirl_GiveItems_Text_2:
# 24 "data/maps/LilycoveCity_LilycoveMuseum_Exterior/scripts.pory"
	.string "Thank you for listening to me.\p"
	.string "I've come across a couple of\n"
	.string "curiosities in my travels that you might\l"
	.string "find interesting.\l"
	.string "Perhaps you'd like to take a look?$"

MysteryGiftGirl_GiveItems_Text_3:
# 31 "data/maps/LilycoveCity_LilycoveMuseum_Exterior/scripts.pory"
	.string "Oh hello again. Interested in my curious\n"
	.string "items?$"

LilycoveLookout_Sign_Text_0:
# 48 "data/maps/LilycoveCity_LilycoveMuseum_Exterior/scripts.pory"
	.string "{UP_ARROW} LILYCOVE LOOKOUT$"
