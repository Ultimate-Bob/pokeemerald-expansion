LilycoveCity_Harbor_EventScript_FerryAttendant::
# 2 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveHarbor_FerryAttendantDynamic
	return


LilycoveHarbor_FerryAttendantDynamic::
# 6 "data/maps/LilycoveCity_Harbor/scripts.pory"
	lock
# 7 "data/maps/LilycoveCity_Harbor/scripts.pory"
	faceplayer
# 8 "data/maps/LilycoveCity_Harbor/scripts.pory"
	special PopulateFerryOptions
# 10 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_set FLAG_TEMP_SSTIDAL_HAS_SS_TICKET, LilycoveHarbor_FerryAttendantDynamic_2
# 17 "data/maps/LilycoveCity_Harbor/scripts.pory"
	compare VAR_TEMP_SSTIDAL_EVENT_TICKET_COUNT, 0
	goto_if_gt LilycoveHarbor_FerryAttendantDynamic_3
# 28 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_set FLAG_HIDE_LILYCOVE_HARBOR_SSTIDAL, LilycoveHarbor_FerryAttendantDynamic_7
# 33 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox LilycoveHarbor_FerryAttendantDynamic_Text_1, MSGBOX_NPC
LilycoveHarbor_FerryAttendantDynamic_1:
# 37 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
	end

LilycoveHarbor_FerryAttendantDynamic_2:
# 12 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveHarbor_PushDynTickets
# 13 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox LilycoveCity_Harbor_Text_MayISeeYourTicket, MSGBOX_DEFAULT
# 14 "data/maps/LilycoveCity_Harbor/scripts.pory"
	dynmultistack 1, 1, FALSE, 4, FALSE, ITEM_SS_TICKET, DYN_MULTICHOICE_CB_SHOW_ITEM
# 15 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveHarbor_CheckTicketPresented
	goto LilycoveHarbor_FerryAttendantDynamic_1

LilycoveHarbor_FerryAttendantDynamic_3:
# 19 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveHarbor_PushDynTickets
# 20 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox LilycoveHarbor_FerryAttendantDynamic_Text_0, MSGBOX_DEFAULT
# 23 "data/maps/LilycoveCity_Harbor/scripts.pory"
	dynmultistack 1, 1, FALSE, 4, FALSE, ITEM_SS_TICKET, DYN_MULTICHOICE_CB_SHOW_ITEM
# 24 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveHarbor_CheckTicketPresented
	goto LilycoveHarbor_FerryAttendantDynamic_1

LilycoveHarbor_FerryAttendantDynamic_7:
# 29 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox LilycoveCity_Harbor_Text_FerryUnavailable, MSGBOX_NPC
	goto LilycoveHarbor_FerryAttendantDynamic_1


LilycoveHarbor_PushDynTickets::
# 43 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_set FLAG_TEMP_SSTIDAL_HAS_SS_TICKET, LilycoveHarbor_PushDynTickets_2
LilycoveHarbor_PushDynTickets_1:
# 49 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_set FLAG_TEMP_SSTIDAL_HAS_MYSTIC_TICKET, LilycoveHarbor_PushDynTickets_5
LilycoveHarbor_PushDynTickets_4:
# 53 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_set FLAG_TEMP_SSTIDAL_HAS_EON_TICKET, LilycoveHarbor_PushDynTickets_8
LilycoveHarbor_PushDynTickets_7:
# 57 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_set FLAG_TEMP_SSTIDAL_HAS_AURORA_TICKET, LilycoveHarbor_PushDynTickets_11
LilycoveHarbor_PushDynTickets_10:
# 61 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_set FLAG_TEMP_SSTIDAL_HAS_OLD_SEA_MAP, LilycoveHarbor_PushDynTickets_13
	return

LilycoveHarbor_PushDynTickets_2:
# 44 "data/maps/LilycoveCity_Harbor/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_SS_TICKET
# 45 "data/maps/LilycoveCity_Harbor/scripts.pory"
	dynmultipush LilycoveHarbor_PushDynTickets_Text_0, ITEM_SS_TICKET
	goto LilycoveHarbor_PushDynTickets_1

LilycoveHarbor_PushDynTickets_5:
# 50 "data/maps/LilycoveCity_Harbor/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_MYSTIC_TICKET
# 51 "data/maps/LilycoveCity_Harbor/scripts.pory"
	dynmultipush LilycoveHarbor_PushDynTickets_Text_0, ITEM_MYSTIC_TICKET
	goto LilycoveHarbor_PushDynTickets_4

LilycoveHarbor_PushDynTickets_8:
# 54 "data/maps/LilycoveCity_Harbor/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_EON_TICKET
# 55 "data/maps/LilycoveCity_Harbor/scripts.pory"
	dynmultipush LilycoveHarbor_PushDynTickets_Text_0, ITEM_EON_TICKET
	goto LilycoveHarbor_PushDynTickets_7

LilycoveHarbor_PushDynTickets_11:
# 58 "data/maps/LilycoveCity_Harbor/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_AURORA_TICKET
# 59 "data/maps/LilycoveCity_Harbor/scripts.pory"
	dynmultipush LilycoveHarbor_PushDynTickets_Text_0, ITEM_AURORA_TICKET
	goto LilycoveHarbor_PushDynTickets_10

LilycoveHarbor_PushDynTickets_13:
# 62 "data/maps/LilycoveCity_Harbor/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_OLD_SEA_MAP
# 63 "data/maps/LilycoveCity_Harbor/scripts.pory"
	dynmultipush LilycoveHarbor_PushDynTickets_Text_0, ITEM_OLD_SEA_MAP
	return


LilycoveHarbor_CheckTicketPresented::
# 68 "data/maps/LilycoveCity_Harbor/scripts.pory"
	switch VAR_RESULT
# 69 "data/maps/LilycoveCity_Harbor/scripts.pory"
	case ITEM_SS_TICKET, LilycoveHarbor_CheckTicketPresented_2
# 71 "data/maps/LilycoveCity_Harbor/scripts.pory"
	case ITEM_MYSTIC_TICKET, LilycoveHarbor_CheckTicketPresented_3
# 73 "data/maps/LilycoveCity_Harbor/scripts.pory"
	case ITEM_EON_TICKET, LilycoveHarbor_CheckTicketPresented_4
# 75 "data/maps/LilycoveCity_Harbor/scripts.pory"
	case ITEM_AURORA_TICKET, LilycoveHarbor_CheckTicketPresented_5
# 77 "data/maps/LilycoveCity_Harbor/scripts.pory"
	case ITEM_OLD_SEA_MAP, LilycoveHarbor_CheckTicketPresented_6
	return

LilycoveHarbor_CheckTicketPresented_2:
# 70 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveHarbor_SelectedSSTicket
	return

LilycoveHarbor_CheckTicketPresented_3:
# 72 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveHarbor_SelectedMysticTicket
	return

LilycoveHarbor_CheckTicketPresented_4:
# 74 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveHarbor_SelectedEonTicket
	return

LilycoveHarbor_CheckTicketPresented_5:
# 76 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveHarbor_SelectedAuroraTicket
	return

LilycoveHarbor_CheckTicketPresented_6:
# 78 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveHarbor_SelectedOldSeaMap
	return


LilycoveHarbor_SelectedSSTicket::
# 83 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox LilycoveCity_Harbor_Text_FlashTicketWhereTo, MSGBOX_DEFAULT
# 84 "data/maps/LilycoveCity_Harbor/scripts.pory"
	dynmultipush LilycoveHarbor_SelectedSSTicket_Text_0, 0
# 85 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_set FLAG_MET_SCOTT_ON_SS_TIDAL, LilycoveHarbor_SelectedSSTicket_2
LilycoveHarbor_SelectedSSTicket_1:
# 88 "data/maps/LilycoveCity_Harbor/scripts.pory"
	dynmultistack 1, 1, FALSE, 4, FALSE, 0, DYN_MULTICHOICE_CB_NONE
# 89 "data/maps/LilycoveCity_Harbor/scripts.pory"
	switch VAR_RESULT
# 90 "data/maps/LilycoveCity_Harbor/scripts.pory"
	case 0, LilycoveHarbor_SelectedSSTicket_6
# 95 "data/maps/LilycoveCity_Harbor/scripts.pory"
	case 1, LilycoveHarbor_SelectedSSTicket_7
LilycoveHarbor_SelectedSSTicket_4:
# 100 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
	return

LilycoveHarbor_SelectedSSTicket_2:
# 86 "data/maps/LilycoveCity_Harbor/scripts.pory"
	dynmultipush LilycoveHarbor_SelectedSSTicket_Text_1, 1
	goto LilycoveHarbor_SelectedSSTicket_1

LilycoveHarbor_SelectedSSTicket_6:
# 91 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_BOARD_LILYCOVE
# 92 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerry
# 93 "data/maps/LilycoveCity_Harbor/scripts.pory"
	warp MAP_SS_TIDAL_CORRIDOR, 1, 10
# 94 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitstate
	goto LilycoveHarbor_SelectedSSTicket_4

LilycoveHarbor_SelectedSSTicket_7:
# 96 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerry
# 97 "data/maps/LilycoveCity_Harbor/scripts.pory"
	warp MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 19, 67
# 98 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitstate
	goto LilycoveHarbor_SelectedSSTicket_4


LilycoveHarbor_SelectedMysticTicket::
# 104 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveHarbor_LadyFetchesSailor
# 105 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_unset FLAG_SHOWN_MYSTIC_TICKET, LilycoveHarbor_SelectedMysticTicket_2
# 110 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox LilycoveHarbor_SelectedMysticTicket_Text_0, MSGBOX_NPC
LilycoveHarbor_SelectedMysticTicket_1:
# 112 "data/maps/LilycoveCity_Harbor/scripts.pory"
	closemessage
# 113 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerryWithSailor
# 114 "data/maps/LilycoveCity_Harbor/scripts.pory"
	warp MAP_NAVEL_ROCK_HARBOR, 8, 4
# 115 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitstate
# 116 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
	return

LilycoveHarbor_SelectedMysticTicket_2:
# 106 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setflag FLAG_SHOWN_MYSTIC_TICKET
# 107 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox EventTicket_Text_OddTicketGetOnBoard, MSGBOX_NPC
	goto LilycoveHarbor_SelectedMysticTicket_1


LilycoveHarbor_SelectedEonTicket::
# 120 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveHarbor_LadyFetchesSailor
# 121 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_unset FLAG_SHOWN_EON_TICKET, LilycoveHarbor_SelectedEonTicket_2
# 126 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox LilycoveHarbor_SelectedEonTicket_Text_0, MSGBOX_NPC
LilycoveHarbor_SelectedEonTicket_1:
# 128 "data/maps/LilycoveCity_Harbor/scripts.pory"
	closemessage
# 129 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerryWithSailor
# 130 "data/maps/LilycoveCity_Harbor/scripts.pory"
	warp MAP_SOUTHERN_ISLAND_EXTERIOR, 13, 22
# 131 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitstate
# 132 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
	return

LilycoveHarbor_SelectedEonTicket_2:
# 122 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setflag FLAG_SHOWN_EON_TICKET
# 123 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox EventTicket_Text_ShowEonTicket, MSGBOX_NPC
	goto LilycoveHarbor_SelectedEonTicket_1


LilycoveHarbor_SelectedAuroraTicket::
# 137 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveHarbor_LadyFetchesSailor
# 138 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_unset FLAG_SHOWN_AURORA_TICKET, LilycoveHarbor_SelectedAuroraTicket_2
# 143 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox LilycoveHarbor_SelectedAuroraTicket_Text_0, MSGBOX_NPC
LilycoveHarbor_SelectedAuroraTicket_1:
# 145 "data/maps/LilycoveCity_Harbor/scripts.pory"
	closemessage
# 146 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerryWithSailor
# 147 "data/maps/LilycoveCity_Harbor/scripts.pory"
	warp MAP_BIRTH_ISLAND_HARBOR, 8, 4
# 148 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitstate
# 149 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
	return

LilycoveHarbor_SelectedAuroraTicket_2:
# 139 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setflag FLAG_SHOWN_AURORA_TICKET
# 140 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox EventTicket_Text_OddTicketGetOnBoard, MSGBOX_NPC
	goto LilycoveHarbor_SelectedAuroraTicket_1


LilycoveHarbor_SelectedOldSeaMap::
# 153 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveHarbor_LadyFetchesSailor
# 154 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_unset FLAG_SHOWN_OLD_SEA_MAP, LilycoveHarbor_SelectedOldSeaMap_2
# 159 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox LilycoveHarbor_SelectedOldSeaMap_Text_0, MSGBOX_NPC
# 160 "data/maps/LilycoveCity_Harbor/scripts.pory"
	closemessage
# 161 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerryWithSailor
LilycoveHarbor_SelectedOldSeaMap_1:
# 163 "data/maps/LilycoveCity_Harbor/scripts.pory"
	warp MAP_FARAWAY_ISLAND_ENTRANCE, 13, 38
# 164 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitstate
# 165 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
	return

LilycoveHarbor_SelectedOldSeaMap_2:
# 155 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setflag FLAG_SHOWN_OLD_SEA_MAP
# 156 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveHarbor_OldSeaMapFirstTime
	goto LilycoveHarbor_SelectedOldSeaMap_1


LilycoveHarbor_OldSeaMapFirstTime::
# 169 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox EventTicket_Text_OldSeaMapTooFar, MSGBOX_DEFAULT
# 170 "data/maps/LilycoveCity_Harbor/scripts.pory"
	closemessage
# 171 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_LILYCOVE_HARBOR_FERRY_SAILOR, Common_Movement_WalkInPlaceFasterUp
# 172 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 173 "data/maps/LilycoveCity_Harbor/scripts.pory"
	playse SE_PIN
# 174 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_LILYCOVE_HARBOR_FERRY_SAILOR, Common_Movement_ExclamationMark
# 175 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 176 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_LILYCOVE_HARBOR_FERRY_SAILOR, Common_Movement_Delay48
# 177 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 178 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, LilycoveCity_Harbor_EventScript_MoveSailorOutOfWayNorth
# 179 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, LilycoveCity_Harbor_EventScript_MoveSailorOutOfWayEast
# 180 "data/maps/LilycoveCity_Harbor/scripts.pory"
	addobject LOCALID_LILYCOVE_HARBOR_BRINEY
# 181 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, LilycoveCity_Harbor_EventScript_BrineyFaceSailorNorth
# 182 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, LilycoveCity_Harbor_EventScript_BrineyFaceSailorEast
# 183 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox EventTicket_Text_BrineyHoldOnASecond, MSGBOX_DEFAULT
# 184 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, LilycoveCity_Harbor_EventScript_BrineyFacePlayerNorth
# 185 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, LilycoveCity_Harbor_EventScript_BrineyFacePlayerEast
# 186 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox EventTicket_Text_BrineyLetsSail, MSGBOX_DEFAULT
# 187 "data/maps/LilycoveCity_Harbor/scripts.pory"
	closemessage
# 188 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, LilycoveCity_Harbor_EventScript_BoardFerryWithBrineyAndSailorNorth
# 189 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, LilycoveCity_Harbor_EventScript_BoardFerryWithBrineyAndSailorEast
# 190 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_0x8004, LOCALID_LILYCOVE_HARBOR_SS_TIDAL
# 191 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call Common_EventScript_FerryDepart
	return


LilycoveHarbor_SailorComeBackIfYouChangeYourMind::
# 195 "data/maps/LilycoveCity_Harbor/scripts.pory"
	checkplayergender
# 196 "data/maps/LilycoveCity_Harbor/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq LilycoveHarbor_SailorComeBackIfYouChangeYourMind_2
# 200 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox LilycoveHarbor_SailorComeBackIfYouChangeYourMind_Text_1, MSGBOX_NPC
LilycoveHarbor_SailorComeBackIfYouChangeYourMind_1:
# 202 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveHarbor_SailorReturns
	return

LilycoveHarbor_SailorComeBackIfYouChangeYourMind_2:
# 197 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox LilycoveHarbor_SailorComeBackIfYouChangeYourMind_Text_0, MSGBOX_NPC
	goto LilycoveHarbor_SailorComeBackIfYouChangeYourMind_1


LilycoveHarbor_SailorReturns::
# 206 "data/maps/LilycoveCity_Harbor/scripts.pory"
	closemessage
# 207 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_LILYCOVE_HARBOR_FERRY_SAILOR, Common_Movement_WalkInPlaceFasterUp
# 208 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 209 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay 30
# 210 "data/maps/LilycoveCity_Harbor/scripts.pory"
	removeobject LOCALID_LILYCOVE_HARBOR_FERRY_SAILOR, MAP_LILYCOVE_CITY_HARBOR
# 211 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay 60
# 212 "data/maps/LilycoveCity_Harbor/scripts.pory"
	showobjectat LOCALID_LILYCOVE_HARBOR_ATTENDANT, MAP_LILYCOVE_CITY_HARBOR
# 213 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay 30
# 214 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_LILYCOVE_HARBOR_ATTENDANT, Common_Movement_FacePlayer
# 215 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 216 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox LilycoveHarbor_SailorReturns_Text_0, MSGBOX_NPC
	return


LilycoveHarbor_LadyFetchesSailor::
# 220 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox LilycoveHarbor_LadyFetchesSailor_Text_0
# 221 "data/maps/LilycoveCity_Harbor/scripts.pory"
	closemessage
# 222 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterUp
# 223 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 224 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay 30
# 225 "data/maps/LilycoveCity_Harbor/scripts.pory"
	hideobjectat VAR_LAST_TALKED, MAP_LILYCOVE_CITY_HARBOR
# 226 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay 60
# 227 "data/maps/LilycoveCity_Harbor/scripts.pory"
	addobject LOCALID_LILYCOVE_HARBOR_FERRY_SAILOR
# 228 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay 30
# 229 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_LILYCOVE_HARBOR_FERRY_SAILOR, Common_Movement_FacePlayer
# 230 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
	return


# 234 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 235 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_MapScripts::
# 236 "data/maps/LilycoveCity_Harbor/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_Harbor_OnTransition
# 237 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.byte 0
# 238 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 239 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_OnTransition:
# 240 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setescapewarp MAP_LILYCOVE_CITY, 12, 33
# 241 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 242 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 243 "data/maps/LilycoveCity_Harbor/scripts.pory"
@ First goto_if_eq is unnecessary; identical scripts
# 244 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_NoFirstTimeEventTickets::
# 245 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_eq VAR_TEMP_A, 0, LilycoveCity_Harbor_EventScript_NoEventTickets
# 246 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox LilycoveCity_Harbor_Text_MayISeeYourTicket, MSGBOX_DEFAULT
# 247 "data/maps/LilycoveCity_Harbor/scripts.pory"
	message LilycoveCity_Harbor_Text_FlashTicketWhereTo
# 248 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmessage
# 249 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto LilycoveCity_Harbor_EventScript_FerryRegularLocationSelect
# 250 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 251 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 252 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_FerryRegularLocationSelect::
# 253 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_0x8004, 0
# 254 "data/maps/LilycoveCity_Harbor/scripts.pory"
	special ScriptMenu_CreateLilycoveSSTidalMultichoice
# 255 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitstate
# 256 "data/maps/LilycoveCity_Harbor/scripts.pory"
	special GetLilycoveSSTidalSelection
# 257 "data/maps/LilycoveCity_Harbor/scripts.pory"
	switch VAR_RESULT
# 258 "data/maps/LilycoveCity_Harbor/scripts.pory"
	case 0, LilycoveCity_Harbor_EventScript_GoToSlateport
# 259 "data/maps/LilycoveCity_Harbor/scripts.pory"
	case 1, LilycoveCity_Harbor_EventScript_GoToBattleFrontier
# 260 "data/maps/LilycoveCity_Harbor/scripts.pory"
	case 2, LilycoveCity_Harbor_EventScript_GoToSouthernIsland
# 261 "data/maps/LilycoveCity_Harbor/scripts.pory"
	case 3, LilycoveCity_Harbor_EventScript_GoToNavelRock
# 262 "data/maps/LilycoveCity_Harbor/scripts.pory"
	case 4, LilycoveCity_Harbor_EventScript_GoToBirthIsland
# 263 "data/maps/LilycoveCity_Harbor/scripts.pory"
	case 5, LilycoveCity_Harbor_EventScript_GoToFarawayIsland
# 264 "data/maps/LilycoveCity_Harbor/scripts.pory"
	case 6, LilycoveCity_Harbor_EventScript_ExitSailSelect
# 265 "data/maps/LilycoveCity_Harbor/scripts.pory"
	case MULTI_B_PRESSED, LilycoveCity_Harbor_EventScript_ExitSailSelect
# 266 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 267 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 268 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GoToSouthernIsland::
# 269 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerry
# 270 "data/maps/LilycoveCity_Harbor/scripts.pory"
	warp MAP_SOUTHERN_ISLAND_EXTERIOR, 13, 22
# 271 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitstate
# 272 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 273 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 274 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 275 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GoToNavelRock::
# 276 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerry
# 277 "data/maps/LilycoveCity_Harbor/scripts.pory"
	warp MAP_NAVEL_ROCK_HARBOR, 8, 4
# 278 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitstate
# 279 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 280 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 281 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 282 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GoToBirthIsland::
# 283 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerry
# 284 "data/maps/LilycoveCity_Harbor/scripts.pory"
	warp MAP_BIRTH_ISLAND_HARBOR, 8, 4
# 285 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitstate
# 286 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 287 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 288 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 289 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GoToFarawayIsland::
# 290 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerry
# 291 "data/maps/LilycoveCity_Harbor/scripts.pory"
	warp MAP_FARAWAY_ISLAND_ENTRANCE, 13, 38
# 292 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitstate
# 293 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 294 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 295 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 296 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GoToSlateport::
# 297 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox LilycoveCity_Harbor_Text_SlateportItIs, MSGBOX_YESNO
# 298 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LilycoveCity_Harbor_EventScript_FerryDestinationChangeMind
# 299 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_BOARD_LILYCOVE
# 300 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerry
# 301 "data/maps/LilycoveCity_Harbor/scripts.pory"
	warp MAP_SS_TIDAL_CORRIDOR, 1, 10
# 302 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitstate
# 303 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 304 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 305 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 306 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GoToBattleFrontier::
# 307 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox LilycoveCity_Harbor_Text_BattleFrontierItIs, MSGBOX_YESNO
# 308 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LilycoveCity_Harbor_EventScript_FerryDestinationChangeMind
# 309 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerry
# 310 "data/maps/LilycoveCity_Harbor/scripts.pory"
	warp MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 19, 67
# 311 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitstate
# 312 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 313 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 314 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 315 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GetEonTicketState::
# 316 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_TEMP_E, 0
# 317 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_unset FLAG_ENABLE_SHIP_SOUTHERN_ISLAND, Common_EventScript_NopReturn
# 318 "data/maps/LilycoveCity_Harbor/scripts.pory"
	checkitem ITEM_EON_TICKET
# 319 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_NopReturn
# 320 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_TEMP_E, 1
# 321 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_set FLAG_SHOWN_EON_TICKET, Common_EventScript_NopReturn
# 322 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_TEMP_E, 2
# 323 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 324 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 325 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GetAuroraTicketState::
# 326 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_TEMP_D, 0
# 327 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_unset FLAG_ENABLE_SHIP_BIRTH_ISLAND, Common_EventScript_NopReturn
# 328 "data/maps/LilycoveCity_Harbor/scripts.pory"
	checkitem ITEM_AURORA_TICKET
# 329 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_NopReturn
# 330 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_TEMP_D, 1
# 331 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_set FLAG_SHOWN_AURORA_TICKET, Common_EventScript_NopReturn
# 332 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_TEMP_D, 2
# 333 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 334 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 335 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GetOldSeaMapState::
# 336 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_TEMP_C, 0
# 337 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_unset FLAG_ENABLE_SHIP_FARAWAY_ISLAND, Common_EventScript_NopReturn
# 338 "data/maps/LilycoveCity_Harbor/scripts.pory"
	checkitem ITEM_OLD_SEA_MAP
# 339 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_NopReturn
# 340 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_TEMP_C, 1
# 341 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_set FLAG_SHOWN_OLD_SEA_MAP, Common_EventScript_NopReturn
# 342 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_TEMP_C, 2
# 343 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 344 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 345 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GetMysticTicketState::
# 346 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_TEMP_9, 0
# 347 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_unset FLAG_ENABLE_SHIP_NAVEL_ROCK, Common_EventScript_NopReturn
# 348 "data/maps/LilycoveCity_Harbor/scripts.pory"
	checkitem ITEM_MYSTIC_TICKET
# 349 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_NopReturn
# 350 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_TEMP_9, 1
# 351 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_set FLAG_SHOWN_MYSTIC_TICKET, Common_EventScript_NopReturn
# 352 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_TEMP_9, 2
# 353 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 354 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 355 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GetFirstTimeShowingTicket::
# 356 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_TEMP_B, 0
# 357 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq VAR_TEMP_E, 2, LilycoveCity_Harbor_EventScript_SetFirstTimeShowingEonTicket
# 358 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq VAR_TEMP_D, 2, LilycoveCity_Harbor_EventScript_SetFirstTimeShowingAuroraTicket
# 359 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq VAR_TEMP_C, 2, LilycoveCity_Harbor_EventScript_SetFirstTimeShowingOldSeaMap
# 360 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq VAR_TEMP_9, 2, LilycoveCity_Harbor_EventScript_SetFirstTimeShowingMysticTicket
# 361 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 362 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 363 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_SetFirstTimeShowingEonTicket::
# 364 "data/maps/LilycoveCity_Harbor/scripts.pory"
	addvar VAR_TEMP_B, 1
# 365 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 366 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 367 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_SetFirstTimeShowingAuroraTicket::
# 368 "data/maps/LilycoveCity_Harbor/scripts.pory"
	addvar VAR_TEMP_B, 2
# 369 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 370 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 371 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_SetFirstTimeShowingOldSeaMap::
# 372 "data/maps/LilycoveCity_Harbor/scripts.pory"
	addvar VAR_TEMP_B, 4
# 373 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 374 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 375 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_SetFirstTimeShowingMysticTicket::
# 376 "data/maps/LilycoveCity_Harbor/scripts.pory"
	addvar VAR_TEMP_B, 8
# 377 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 378 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 379 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GetHasTicketsState::
# 380 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_TEMP_A, 0
# 381 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq VAR_TEMP_E, 1, LilycoveCity_Harbor_EventScript_SetHasEonTicket
# 382 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq VAR_TEMP_D, 1, LilycoveCity_Harbor_EventScript_SetHasAuroraTicket
# 383 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq VAR_TEMP_C, 1, LilycoveCity_Harbor_EventScript_SetHasOldSeaMap
# 384 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq VAR_TEMP_9, 1, LilycoveCity_Harbor_EventScript_SetHasMysticTicket
# 385 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 386 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 387 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_SetHasEonTicket::
# 388 "data/maps/LilycoveCity_Harbor/scripts.pory"
	addvar VAR_TEMP_A, 1
# 389 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 390 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 391 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_SetHasAuroraTicket::
# 392 "data/maps/LilycoveCity_Harbor/scripts.pory"
	addvar VAR_TEMP_A, 2
# 393 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 394 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 395 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_SetHasOldSeaMap::
# 396 "data/maps/LilycoveCity_Harbor/scripts.pory"
	addvar VAR_TEMP_A, 4
# 397 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 398 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 399 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_SetHasMysticTicket::
# 400 "data/maps/LilycoveCity_Harbor/scripts.pory"
	addvar VAR_TEMP_A, 8
# 401 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 402 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 403 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_EonTicketFirstTime::
# 404 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setflag FLAG_SHOWN_EON_TICKET
# 405 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox EventTicket_Text_ThatPass, MSGBOX_DEFAULT
# 406 "data/maps/LilycoveCity_Harbor/scripts.pory"
	closemessage
# 407 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_GetEventTicketSailor
# 408 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox EventTicket_Text_ShowEonTicket, MSGBOX_DEFAULT
# 409 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto LilycoveCity_Harbor_EventScript_GoToSouthernIslandFirstTime
# 410 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 411 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 412 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GoToSouthernIslandFirstTime::
# 413 "data/maps/LilycoveCity_Harbor/scripts.pory"
	closemessage
# 414 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerryWithSailor
# 415 "data/maps/LilycoveCity_Harbor/scripts.pory"
	warp MAP_SOUTHERN_ISLAND_EXTERIOR, 13, 22
# 416 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitstate
# 417 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 418 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 419 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 420 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_AuroraTicketFirstTime::
# 421 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setflag FLAG_SHOWN_AURORA_TICKET
# 422 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox EventTicket_Text_ThatPass, MSGBOX_DEFAULT
# 423 "data/maps/LilycoveCity_Harbor/scripts.pory"
	closemessage
# 424 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_GetEventTicketSailor
# 425 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox EventTicket_Text_OddTicketGetOnBoard, MSGBOX_DEFAULT
# 426 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto LilycoveCity_Harbor_EventScript_GoToBirthIslandFirstTime
# 427 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 428 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 429 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GoToBirthIslandFirstTime::
# 430 "data/maps/LilycoveCity_Harbor/scripts.pory"
	closemessage
# 431 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerryWithSailor
# 432 "data/maps/LilycoveCity_Harbor/scripts.pory"
	warp MAP_BIRTH_ISLAND_HARBOR, 8, 4
# 433 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitstate
# 434 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 435 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 436 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 437 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_OldSeaMapFirstTime::
# 438 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setflag FLAG_SHOWN_OLD_SEA_MAP
# 439 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox EventTicket_Text_ShowOldSeaMap, MSGBOX_DEFAULT
# 440 "data/maps/LilycoveCity_Harbor/scripts.pory"
	closemessage
# 441 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_GetEventTicketSailor
# 442 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox EventTicket_Text_OldSeaMapTooFar, MSGBOX_DEFAULT
# 443 "data/maps/LilycoveCity_Harbor/scripts.pory"
	closemessage
# 444 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_LILYCOVE_HARBOR_FERRY_SAILOR, Common_Movement_WalkInPlaceFasterUp
# 445 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 446 "data/maps/LilycoveCity_Harbor/scripts.pory"
	playse SE_PIN
# 447 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_LILYCOVE_HARBOR_FERRY_SAILOR, Common_Movement_ExclamationMark
# 448 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 449 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_LILYCOVE_HARBOR_FERRY_SAILOR, Common_Movement_Delay48
# 450 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 451 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, LilycoveCity_Harbor_EventScript_MoveSailorOutOfWayNorth
# 452 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, LilycoveCity_Harbor_EventScript_MoveSailorOutOfWayEast
# 453 "data/maps/LilycoveCity_Harbor/scripts.pory"
	addobject LOCALID_LILYCOVE_HARBOR_BRINEY
# 454 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, LilycoveCity_Harbor_EventScript_BrineyFaceSailorNorth
# 455 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, LilycoveCity_Harbor_EventScript_BrineyFaceSailorEast
# 456 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox EventTicket_Text_BrineyHoldOnASecond, MSGBOX_DEFAULT
# 457 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, LilycoveCity_Harbor_EventScript_BrineyFacePlayerNorth
# 458 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, LilycoveCity_Harbor_EventScript_BrineyFacePlayerEast
# 459 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox EventTicket_Text_BrineyLetsSail, MSGBOX_DEFAULT
# 460 "data/maps/LilycoveCity_Harbor/scripts.pory"
	closemessage
# 461 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, LilycoveCity_Harbor_EventScript_BoardFerryWithBrineyAndSailorNorth
# 462 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, LilycoveCity_Harbor_EventScript_BoardFerryWithBrineyAndSailorEast
# 463 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_0x8004, LOCALID_LILYCOVE_HARBOR_SS_TIDAL
# 464 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call Common_EventScript_FerryDepart
# 465 "data/maps/LilycoveCity_Harbor/scripts.pory"
	warp MAP_FARAWAY_ISLAND_ENTRANCE, 13, 38
# 466 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitstate
# 467 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 468 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 469 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 470 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GoToFarawayIslandFirstTime::
# 471 "data/maps/LilycoveCity_Harbor/scripts.pory"
	closemessage
# 472 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerryWithSailor
# 473 "data/maps/LilycoveCity_Harbor/scripts.pory"
	warp MAP_FARAWAY_ISLAND_ENTRANCE, 13, 38
# 474 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitstate
# 475 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 476 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 477 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 478 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_MysticTicketFirstTime::
# 479 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setflag FLAG_SHOWN_MYSTIC_TICKET
# 480 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox EventTicket_Text_ThatPass, MSGBOX_DEFAULT
# 481 "data/maps/LilycoveCity_Harbor/scripts.pory"
	closemessage
# 482 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_GetEventTicketSailor
# 483 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox EventTicket_Text_OddTicketGetOnBoard, MSGBOX_DEFAULT
# 484 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto LilycoveCity_Harbor_EventScript_GoToNavelRockFirstTime
# 485 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 486 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 487 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GoToNavelRockFirstTime::
# 488 "data/maps/LilycoveCity_Harbor/scripts.pory"
	closemessage
# 489 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerryWithSailor
# 490 "data/maps/LilycoveCity_Harbor/scripts.pory"
	warp MAP_NAVEL_ROCK_HARBOR, 8, 4
# 491 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitstate
# 492 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 493 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 494 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 495 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_MultipleEventTicketsFirstTime::
# 496 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox EventTicket_Text_ThatPass, MSGBOX_DEFAULT
# 497 "data/maps/LilycoveCity_Harbor/scripts.pory"
	closemessage
# 498 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_GetEventTicketSailor
# 499 "data/maps/LilycoveCity_Harbor/scripts.pory"
	message EventTicket_Text_OddTicketsWhereTo
# 500 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmessage
# 501 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_0x8004, 1
# 502 "data/maps/LilycoveCity_Harbor/scripts.pory"
	special ScriptMenu_CreateLilycoveSSTidalMultichoice
# 503 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitstate
# 504 "data/maps/LilycoveCity_Harbor/scripts.pory"
	special GetLilycoveSSTidalSelection
# 505 "data/maps/LilycoveCity_Harbor/scripts.pory"
	switch VAR_RESULT
# 506 "data/maps/LilycoveCity_Harbor/scripts.pory"
	case 2, LilycoveCity_Harbor_EventScript_GoToSouthernIslandFirstTime
# 507 "data/maps/LilycoveCity_Harbor/scripts.pory"
	case 3, LilycoveCity_Harbor_EventScript_GoToNavelRockFirstTime
# 508 "data/maps/LilycoveCity_Harbor/scripts.pory"
	case 4, LilycoveCity_Harbor_EventScript_GoToBirthIslandFirstTime
# 509 "data/maps/LilycoveCity_Harbor/scripts.pory"
	case 5, LilycoveCity_Harbor_EventScript_GoToFarawayIslandFirstTime
# 510 "data/maps/LilycoveCity_Harbor/scripts.pory"
	case 6, LilycoveCity_Harbor_EventScript_ExitFirstTimeTicketSailSelect
# 511 "data/maps/LilycoveCity_Harbor/scripts.pory"
	case MULTI_B_PRESSED, LilycoveCity_Harbor_EventScript_ExitFirstTimeTicketSailSelect
# 512 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 513 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 514 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 515 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_ExitFirstTimeTicketSailSelect::
# 516 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox EventTicket_Text_AsYouLike, MSGBOX_DEFAULT
# 517 "data/maps/LilycoveCity_Harbor/scripts.pory"
	closemessage
# 518 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_LILYCOVE_HARBOR_FERRY_SAILOR, Common_Movement_WalkInPlaceFasterUp
# 519 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 520 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay 30
# 521 "data/maps/LilycoveCity_Harbor/scripts.pory"
	removeobject LOCALID_LILYCOVE_HARBOR_FERRY_SAILOR
# 522 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay 30
# 523 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_LILYCOVE_HARBOR_ATTENDANT, Common_Movement_WalkInPlaceFasterDown
# 524 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 525 "data/maps/LilycoveCity_Harbor/scripts.pory"
	showobjectat LOCALID_LILYCOVE_HARBOR_ATTENDANT, MAP_LILYCOVE_CITY_HARBOR
# 526 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay 30
# 527 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox LilycoveCity_Harbor_Text_SailAnotherTime, MSGBOX_DEFAULT
# 528 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 529 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 530 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 531 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GetEventTicketSailor::
# 532 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterUp
# 533 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 534 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay 30
# 535 "data/maps/LilycoveCity_Harbor/scripts.pory"
	hideobjectat VAR_LAST_TALKED, MAP_LILYCOVE_CITY_HARBOR
# 536 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay 60
# 537 "data/maps/LilycoveCity_Harbor/scripts.pory"
	addobject LOCALID_LILYCOVE_HARBOR_FERRY_SAILOR
# 538 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay 30
# 539 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_LILYCOVE_HARBOR_FERRY_SAILOR, Common_Movement_FacePlayer
# 540 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 541 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 542 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 543 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_BoardFerryWithSailor::
# 544 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_LILYCOVE_HARBOR_FERRY_SAILOR, Common_Movement_WalkInPlaceFasterUp
# 545 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 546 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay 30
# 547 "data/maps/LilycoveCity_Harbor/scripts.pory"
	removeobject LOCALID_LILYCOVE_HARBOR_FERRY_SAILOR
# 548 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, LilycoveCity_Harbor_EventScript_PlayerBoardFerryNorth
# 549 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, LilycoveCity_Harbor_EventScript_PlayerBoardFerryEast
# 550 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay 30
# 551 "data/maps/LilycoveCity_Harbor/scripts.pory"
	hideplayer
# 552 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_0x8004, LOCALID_LILYCOVE_HARBOR_SS_TIDAL
# 553 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call Common_EventScript_FerryDepart
# 554 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 555 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 556 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_FerryUnavailable::
# 557 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox LilycoveCity_Harbor_Text_FerryUnavailable, MSGBOX_DEFAULT
# 558 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 559 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 560 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 561 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_NoEventTickets::
# 562 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox LilycoveCity_Harbor_Text_MayISeeYourTicket, MSGBOX_DEFAULT
# 563 "data/maps/LilycoveCity_Harbor/scripts.pory"
	message LilycoveCity_Harbor_Text_FlashTicketWhereTo
# 564 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmessage
# 565 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto LilycoveCity_Harbor_EventScript_FerryRegularLocationSelect
# 566 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 567 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 568 "data/maps/LilycoveCity_Harbor/scripts.pory"
@ Unused
# 569 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_NoTicket::
# 570 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox LilycoveCity_Harbor_Text_NoTicket, MSGBOX_DEFAULT
# 571 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 572 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 573 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 574 "data/maps/LilycoveCity_Harbor/scripts.pory"
@ Unused
# 575 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GoToSlateportUnused::
# 576 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox LilycoveCity_Harbor_Text_SlateportItIs, MSGBOX_YESNO
# 577 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LilycoveCity_Harbor_EventScript_FerryDestinationChangeMind
# 578 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_BOARD_LILYCOVE
# 579 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerry
# 580 "data/maps/LilycoveCity_Harbor/scripts.pory"
	warp MAP_SS_TIDAL_CORRIDOR, 1, 10
# 581 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitstate
# 582 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 583 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 584 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 585 "data/maps/LilycoveCity_Harbor/scripts.pory"
@ Unused
# 586 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GoToBattleFrontierUnused::
# 587 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox LilycoveCity_Harbor_Text_BattleFrontierItIs, MSGBOX_YESNO
# 588 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LilycoveCity_Harbor_EventScript_FerryDestinationChangeMind
# 589 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerry
# 590 "data/maps/LilycoveCity_Harbor/scripts.pory"
	warp MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 19, 67
# 591 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitstate
# 592 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 593 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 594 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 595 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_FerryDestinationChangeMind::
# 596 "data/maps/LilycoveCity_Harbor/scripts.pory"
	message LilycoveCity_Harbor_Text_WhereWouldYouLikeToGo
# 597 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmessage
# 598 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto LilycoveCity_Harbor_EventScript_FerryRegularLocationSelect
# 599 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 600 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 601 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_BoardFerry::
# 602 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox LilycoveCity_Harbor_Text_PleaseBoard, MSGBOX_DEFAULT
# 603 "data/maps/LilycoveCity_Harbor/scripts.pory"
	closemessage
# 604 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterUp
# 605 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 606 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay 30
# 607 "data/maps/LilycoveCity_Harbor/scripts.pory"
	hideobjectat VAR_LAST_TALKED, MAP_LILYCOVE_CITY_HARBOR
# 608 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, LilycoveCity_Harbor_EventScript_PlayerBoardFerryNorth
# 609 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, LilycoveCity_Harbor_EventScript_PlayerBoardFerryEast
# 610 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay 30
# 611 "data/maps/LilycoveCity_Harbor/scripts.pory"
	hideplayer
# 612 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_0x8004, LOCALID_LILYCOVE_HARBOR_SS_TIDAL
# 613 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call Common_EventScript_FerryDepart
# 614 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 615 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 616 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_PlayerBoardFerryEast::
# 617 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_PLAYER, LilycoveCity_Harbor_Movement_PlayerBoardFerryEast
# 618 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 619 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 620 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 621 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_PlayerBoardFerryNorth::
# 622 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_PLAYER, LilycoveCity_Harbor_Movement_PlayerBoardFerryNorth
# 623 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 624 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 625 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 626 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_ExitSailSelect::
# 627 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox LilycoveCity_Harbor_Text_SailAnotherTime, MSGBOX_DEFAULT
# 628 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 629 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 630 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 631 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Movement_PlayerBoardFerryEast:
# 632 "data/maps/LilycoveCity_Harbor/scripts.pory"
	walk_right
# 633 "data/maps/LilycoveCity_Harbor/scripts.pory"
	walk_in_place_faster_up
# 634 "data/maps/LilycoveCity_Harbor/scripts.pory"
	step_end
# 635 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 636 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Movement_PlayerBoardFerryNorth:
# 637 "data/maps/LilycoveCity_Harbor/scripts.pory"
	walk_up
# 638 "data/maps/LilycoveCity_Harbor/scripts.pory"
	step_end
# 639 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 640 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Movement_UnusedBoardFerry:
# 641 "data/maps/LilycoveCity_Harbor/scripts.pory"
	walk_up
# 642 "data/maps/LilycoveCity_Harbor/scripts.pory"
	step_end
# 643 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 644 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_Sailor::
# 645 "data/maps/LilycoveCity_Harbor/scripts.pory"
	lock
# 646 "data/maps/LilycoveCity_Harbor/scripts.pory"
	faceplayer
# 647 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_Harbor_EventScript_SailorFerryAvailable
# 648 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox LilycoveCity_Harbor_Text_SailorFerryUnavailable, MSGBOX_DEFAULT
# 649 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 650 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 651 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 652 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_SailorFerryAvailable::
# 653 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox LilycoveCity_Harbor_Text_SailorFerryAvailable, MSGBOX_DEFAULT
# 654 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 655 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 656 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 657 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_MoveSailorOutOfWayNorth::
# 658 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_LILYCOVE_HARBOR_FERRY_SAILOR, LilycoveCity_Harbor_Movement_SailorOutOfWayNorth
# 659 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 660 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 661 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 662 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_MoveSailorOutOfWayEast::
# 663 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_LILYCOVE_HARBOR_FERRY_SAILOR, LilycoveCity_Harbor_Movement_SailorOutOfWayEast
# 664 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 665 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 666 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 667 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Movement_SailorOutOfWayNorth:
# 668 "data/maps/LilycoveCity_Harbor/scripts.pory"
	walk_in_place_faster_right
# 669 "data/maps/LilycoveCity_Harbor/scripts.pory"
	lock_facing_direction
# 670 "data/maps/LilycoveCity_Harbor/scripts.pory"
	walk_left
# 671 "data/maps/LilycoveCity_Harbor/scripts.pory"
	unlock_facing_direction
# 672 "data/maps/LilycoveCity_Harbor/scripts.pory"
	step_end
# 673 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 674 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Movement_SailorOutOfWayEast:
# 675 "data/maps/LilycoveCity_Harbor/scripts.pory"
	lock_facing_direction
# 676 "data/maps/LilycoveCity_Harbor/scripts.pory"
	walk_down
# 677 "data/maps/LilycoveCity_Harbor/scripts.pory"
	unlock_facing_direction
# 678 "data/maps/LilycoveCity_Harbor/scripts.pory"
	step_end
# 679 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 680 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_BrineyFaceSailorNorth::
# 681 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_LILYCOVE_HARBOR_BRINEY, Common_Movement_WalkInPlaceFasterLeft
# 682 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 683 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 684 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 685 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_BrineyFaceSailorEast::
# 686 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_LILYCOVE_HARBOR_BRINEY, Common_Movement_WalkInPlaceFasterDown
# 687 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 688 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 689 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 690 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_BrineyFacePlayerNorth::
# 691 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_LILYCOVE_HARBOR_BRINEY, Common_Movement_WalkInPlaceFasterDown
# 692 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 693 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 694 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 695 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_BrineyFacePlayerEast::
# 696 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_LILYCOVE_HARBOR_BRINEY, Common_Movement_WalkInPlaceFasterLeft
# 697 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 698 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 699 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 700 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_BoardFerryWithBrineyAndSailorNorth::
# 701 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_LILYCOVE_HARBOR_BRINEY, LilycoveCity_Harbor_Movement_BrineyBoardFerry
# 702 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_PLAYER, LilycoveCity_Harbor_Movement_PlayerBoardWithBrineyNorth
# 703 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_LILYCOVE_HARBOR_FERRY_SAILOR, LilycoveCity_Harbor_Movement_SailorBoardWithBrineyNorth
# 704 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 705 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 706 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 707 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_BoardFerryWithBrineyAndSailorEast::
# 708 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_LILYCOVE_HARBOR_BRINEY, LilycoveCity_Harbor_Movement_BrineyBoardFerry
# 709 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_PLAYER, LilycoveCity_Harbor_Movement_PlayerBoardWithBrineyEast
# 710 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_LILYCOVE_HARBOR_FERRY_SAILOR, LilycoveCity_Harbor_Movement_SailorBoardWithBrineyEast
# 711 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 712 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 713 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 714 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Movement_BrineyBoardFerry:
# 715 "data/maps/LilycoveCity_Harbor/scripts.pory"
	walk_in_place_faster_up
# 716 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay_8
# 717 "data/maps/LilycoveCity_Harbor/scripts.pory"
	set_invisible
# 718 "data/maps/LilycoveCity_Harbor/scripts.pory"
	step_end
# 719 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 720 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Movement_PlayerBoardWithBrineyNorth:
# 721 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay_16
# 722 "data/maps/LilycoveCity_Harbor/scripts.pory"
	walk_up
# 723 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay_16
# 724 "data/maps/LilycoveCity_Harbor/scripts.pory"
	set_invisible
# 725 "data/maps/LilycoveCity_Harbor/scripts.pory"
	step_end
# 726 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 727 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Movement_SailorBoardWithBrineyNorth:
# 728 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay_16
# 729 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay_16
# 730 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay_16
# 731 "data/maps/LilycoveCity_Harbor/scripts.pory"
	walk_right
# 732 "data/maps/LilycoveCity_Harbor/scripts.pory"
	walk_in_place_faster_up
# 733 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay_16
# 734 "data/maps/LilycoveCity_Harbor/scripts.pory"
	set_invisible
# 735 "data/maps/LilycoveCity_Harbor/scripts.pory"
	step_end
# 736 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 737 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Movement_PlayerBoardWithBrineyEast:
# 738 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay_16
# 739 "data/maps/LilycoveCity_Harbor/scripts.pory"
	walk_right
# 740 "data/maps/LilycoveCity_Harbor/scripts.pory"
	walk_in_place_faster_up
# 741 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay_16
# 742 "data/maps/LilycoveCity_Harbor/scripts.pory"
	set_invisible
# 743 "data/maps/LilycoveCity_Harbor/scripts.pory"
	step_end
# 744 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 745 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Movement_SailorBoardWithBrineyEast:
# 746 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay_16
# 747 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay_16
# 748 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay_16
# 749 "data/maps/LilycoveCity_Harbor/scripts.pory"
	walk_up
# 750 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay_16
# 751 "data/maps/LilycoveCity_Harbor/scripts.pory"
	set_invisible
# 752 "data/maps/LilycoveCity_Harbor/scripts.pory"
	step_end
# 753 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 754 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Text_FerryUnavailable:
# 755 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "I beg your pardon?\n"
# 756 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "You're looking for a ship?\p"
# 757 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "I'm sorry, the ferry service isn't\n"
# 758 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "available at present…$"
# 759 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 760 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Text_MayISeeYourTicket:
# 761 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "Hello, are you here for the ferry?\n"
# 762 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "May I see your TICKET?$"
# 763 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 764 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Text_NoTicket:
# 765 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "{PLAYER} doesn't have the TICKET…\p"
# 766 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "I'm terribly sorry.\p"
# 767 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "You must have a TICKET to board\n"
# 768 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "the ferry.$"
# 769 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 770 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Text_FlashTicketWhereTo:
# 771 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "{PLAYER} flashed the TICKET.\p"
# 772 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "Perfect! That's all you need!\p"
# 773 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "And where would you like to go?$"
# 774 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 775 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Text_SailAnotherTime:
# 776 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "Please sail with us another time!$"
# 777 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 778 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Text_SlateportItIs:
# 779 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "SLATEPORT CITY it is, then!$"
# 780 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 781 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Text_BattleFrontierItIs:
# 782 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "BATTLE FRONTIER it is, then!$"
# 783 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 784 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Text_PleaseBoard:
# 785 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "Please board the ferry and wait for\n"
# 786 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "departure.$"
# 787 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 788 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Text_WhereWouldYouLikeToGo:
# 789 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "Then, where would you like to go?$"
# 790 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 791 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Text_SailorFerryUnavailable:
# 792 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "Until they finish making the ferry,\n"
# 793 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "we sailors have nothing to do…\p"
# 794 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "I wish they'd get a move on, the folks\n"
# 795 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "at the SHIPYARD in SLATEPORT.$"
# 796 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 797 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Text_SailorFerryAvailable:
# 798 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "The ferry S.S. TIDAL is finally in\n"
# 799 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "operation.\p"
# 800 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "The folks at the SHIPYARD in SLATEPORT\n"
# 801 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "must've worked extra hard.\p"
# 802 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "Well, it's my turn to get busy now!$"

LilycoveHarbor_FerryAttendantDynamic_Text_0:
# 20 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "The ferry to SLATEPORT is…\p"
	.string "Oh? That PASS…$"

LilycoveHarbor_FerryAttendantDynamic_Text_1:
# 33 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "I'm sorry, the ferry service isn't\n"
	.string "available at the moment due to\l"
	.string "maintenance.\p"
	.string "Sorry for the inconvenience.$"

LilycoveHarbor_PushDynTickets_Text_0:
# 45 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "{STR_VAR_1}$"

LilycoveHarbor_SelectedSSTicket_Text_0:
# 84 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "Slateport$"

LilycoveHarbor_SelectedSSTicket_Text_1:
# 86 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "Battle Frontier$"

LilycoveHarbor_SelectedMysticTicket_Text_0:
# 110 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "We're setting sail for Navel Rock!$"

LilycoveHarbor_SelectedEonTicket_Text_0:
# 126 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "We're setting sail for the Southern\n"
	.string "Island!$"

LilycoveHarbor_SelectedAuroraTicket_Text_0:
# 143 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "We're setting sail for Birth Island!$"

LilycoveHarbor_SelectedOldSeaMap_Text_0:
# 159 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "We're setting sail for Faraway Island!$"

LilycoveHarbor_SailorComeBackIfYouChangeYourMind_Text_0:
# 197 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "Come back and talk to me again if you\n"
	.string "change your mind lad.$"

LilycoveHarbor_SailorComeBackIfYouChangeYourMind_Text_1:
# 200 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "Come back and talk to me again if you\n"
	.string "change your mind lass.$"

LilycoveHarbor_SailorReturns_Text_0:
# 216 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "Please come back again.$"

LilycoveHarbor_LadyFetchesSailor_Text_0:
# 220 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "Hold on, let me find someone who can\n"
	.string "help you better.$"
