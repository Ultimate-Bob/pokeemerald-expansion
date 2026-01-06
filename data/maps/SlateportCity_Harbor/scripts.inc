SlateportCity_Harbor_EventScript_FerryAttendant::
# 2 "data/maps/SlateportCity_Harbor/scripts.pory"
	call SlateportHarbor_FerryAttendantDynamic
	return


SlateportHarbor_FerryAttendantDynamic::
# 6 "data/maps/SlateportCity_Harbor/scripts.pory"
	lock
# 7 "data/maps/SlateportCity_Harbor/scripts.pory"
	faceplayer
# 8 "data/maps/SlateportCity_Harbor/scripts.pory"
	special PopulateFerryOptions
# 10 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_set FLAG_TEMP_SSTIDAL_HAS_SS_TICKET, SlateportHarbor_FerryAttendantDynamic_2
# 19 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_FerryServiceUnavailable, MSGBOX_NPC
SlateportHarbor_FerryAttendantDynamic_1:
# 21 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
	end

SlateportHarbor_FerryAttendantDynamic_2:
# 12 "data/maps/SlateportCity_Harbor/scripts.pory"
	call SlateportHarbor_PushDynTickets
# 13 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_MayISeeYourTicket, MSGBOX_DEFAULT
# 14 "data/maps/SlateportCity_Harbor/scripts.pory"
	dynmultistack 1, 1, FALSE, 4, FALSE, ITEM_SS_TICKET, DYN_MULTICHOICE_CB_SHOW_ITEM
# 15 "data/maps/SlateportCity_Harbor/scripts.pory"
	call SlateportHarbor_CheckTicketPresented
	goto SlateportHarbor_FerryAttendantDynamic_1


SlateportHarbor_PushDynTickets::
# 27 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_set FLAG_TEMP_SSTIDAL_HAS_SS_TICKET, SlateportHarbor_PushDynTickets_1
	return

SlateportHarbor_PushDynTickets_1:
# 28 "data/maps/SlateportCity_Harbor/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_SS_TICKET
# 29 "data/maps/SlateportCity_Harbor/scripts.pory"
	dynmultipush SlateportHarbor_PushDynTickets_Text_0, ITEM_SS_TICKET
	return


SlateportHarbor_CheckTicketPresented::
# 34 "data/maps/SlateportCity_Harbor/scripts.pory"
	switch VAR_RESULT
# 35 "data/maps/SlateportCity_Harbor/scripts.pory"
	case ITEM_SS_TICKET, SlateportHarbor_CheckTicketPresented_2
	return

SlateportHarbor_CheckTicketPresented_2:
# 36 "data/maps/SlateportCity_Harbor/scripts.pory"
	call SlateportHarbor_SelectedSSTicket
	return


SlateportHarbor_SelectedSSTicket::
# 41 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_FlashedTicketWhereTo, MSGBOX_DEFAULT
# 42 "data/maps/SlateportCity_Harbor/scripts.pory"
	dynmultipush SlateportHarbor_SelectedSSTicket_Text_0, 0
# 43 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_set FLAG_MET_SCOTT_ON_SS_TIDAL, SlateportHarbor_SelectedSSTicket_2
SlateportHarbor_SelectedSSTicket_1:
# 46 "data/maps/SlateportCity_Harbor/scripts.pory"
	dynmultistack 1, 1, FALSE, 4, FALSE, 0, DYN_MULTICHOICE_CB_NONE
# 47 "data/maps/SlateportCity_Harbor/scripts.pory"
	switch VAR_RESULT
# 48 "data/maps/SlateportCity_Harbor/scripts.pory"
	case 0, SlateportHarbor_SelectedSSTicket_6
# 53 "data/maps/SlateportCity_Harbor/scripts.pory"
	case 1, SlateportHarbor_SelectedSSTicket_7
SlateportHarbor_SelectedSSTicket_4:
# 58 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
	return

SlateportHarbor_SelectedSSTicket_2:
# 44 "data/maps/SlateportCity_Harbor/scripts.pory"
	dynmultipush SlateportHarbor_SelectedSSTicket_Text_1, 1
	goto SlateportHarbor_SelectedSSTicket_1

SlateportHarbor_SelectedSSTicket_6:
# 49 "data/maps/SlateportCity_Harbor/scripts.pory"
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_BOARD_SLATEPORT
# 50 "data/maps/SlateportCity_Harbor/scripts.pory"
	call SlateportCity_Harbor_EventScript_BoardFerry
# 51 "data/maps/SlateportCity_Harbor/scripts.pory"
	warp MAP_SS_TIDAL_CORRIDOR, 1, 10
# 52 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitstate
	goto SlateportHarbor_SelectedSSTicket_4

SlateportHarbor_SelectedSSTicket_7:
# 54 "data/maps/SlateportCity_Harbor/scripts.pory"
	call SlateportCity_Harbor_EventScript_BoardFerry
# 55 "data/maps/SlateportCity_Harbor/scripts.pory"
	warp MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 19, 67
# 56 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitstate
	goto SlateportHarbor_SelectedSSTicket_4


# 63 "data/maps/SlateportCity_Harbor/scripts.pory"

# 64 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_MapScripts::
# 65 "data/maps/SlateportCity_Harbor/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_Harbor_OnTransition
# 66 "data/maps/SlateportCity_Harbor/scripts.pory"
	.byte 0
# 67 "data/maps/SlateportCity_Harbor/scripts.pory"

# 68 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_OnTransition:
# 69 "data/maps/SlateportCity_Harbor/scripts.pory"
	setescapewarp MAP_SLATEPORT_CITY, 28, 13
# 70 "data/maps/SlateportCity_Harbor/scripts.pory"
	setvar VAR_TEMP_1, 0
# 71 "data/maps/SlateportCity_Harbor/scripts.pory"
	call_if_eq VAR_SLATEPORT_HARBOR_STATE, 1, SlateportCity_Harbor_EventScript_ReadyAquaEscapeScene
# 72 "data/maps/SlateportCity_Harbor/scripts.pory"
	call_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_ShowSSTidal
# 73 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 74 "data/maps/SlateportCity_Harbor/scripts.pory"

# 75 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_ShowSSTidal::
# 76 "data/maps/SlateportCity_Harbor/scripts.pory"
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SS_TIDAL
# 77 "data/maps/SlateportCity_Harbor/scripts.pory"
	return
# 78 "data/maps/SlateportCity_Harbor/scripts.pory"

# 79 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_ReadyAquaEscapeScene::
# 80 "data/maps/SlateportCity_Harbor/scripts.pory"
	savebgm MUS_ENCOUNTER_AQUA
# 81 "data/maps/SlateportCity_Harbor/scripts.pory"
	setobjectxyperm LOCALID_SLATEPORT_HARBOR_CAPT_STERN, 12, 13
# 82 "data/maps/SlateportCity_Harbor/scripts.pory"
	setobjectmovementtype LOCALID_SLATEPORT_HARBOR_CAPT_STERN, MOVEMENT_TYPE_FACE_LEFT
# 83 "data/maps/SlateportCity_Harbor/scripts.pory"
	setflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS
# 84 "data/maps/SlateportCity_Harbor/scripts.pory"
	return
# 85 "data/maps/SlateportCity_Harbor/scripts.pory"

# 86 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_AquaEscapeTrigger0::
# 87 "data/maps/SlateportCity_Harbor/scripts.pory"
	lockall
# 88 "data/maps/SlateportCity_Harbor/scripts.pory"
	setvar VAR_0x8008, 0
# 89 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
# 90 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 91 "data/maps/SlateportCity_Harbor/scripts.pory"

# 92 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_AquaEscapeTrigger1::
# 93 "data/maps/SlateportCity_Harbor/scripts.pory"
	lockall
# 94 "data/maps/SlateportCity_Harbor/scripts.pory"
	setvar VAR_0x8008, 1
# 95 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
# 96 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 97 "data/maps/SlateportCity_Harbor/scripts.pory"

# 98 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_AquaEscapeTrigger2::
# 99 "data/maps/SlateportCity_Harbor/scripts.pory"
	lockall
# 100 "data/maps/SlateportCity_Harbor/scripts.pory"
	setvar VAR_0x8008, 2
# 101 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
# 102 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 103 "data/maps/SlateportCity_Harbor/scripts.pory"

# 104 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_AquaEscapeTrigger3::
# 105 "data/maps/SlateportCity_Harbor/scripts.pory"
	lockall
# 106 "data/maps/SlateportCity_Harbor/scripts.pory"
	setvar VAR_0x8008, 3
# 107 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_PLAYER, SlateportCity_Harbor_Movement_PlayerWalkUp
# 108 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 109 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
# 110 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 111 "data/maps/SlateportCity_Harbor/scripts.pory"

# 112 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_AquaEscapeScene::
# 113 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_SLATEPORT_HARBOR_ARCHIE, Common_Movement_WalkInPlaceFasterDown
# 114 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 115 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_SLATEPORT_HARBOR_GRUNT, Common_Movement_WalkInPlaceFasterDown
# 116 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 117 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 118 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_ArchieYouAgainHideoutInLilycove, MSGBOX_DEFAULT
# 119 "data/maps/SlateportCity_Harbor/scripts.pory"
	closemessage
# 120 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_SLATEPORT_HARBOR_GRUNT, SlateportCity_Harbor_Movement_AquaBoardSub
# 121 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_SLATEPORT_HARBOR_ARCHIE, SlateportCity_Harbor_Movement_AquaBoardSub
# 122 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_SLATEPORT_HARBOR_SUBMARINE, SlateportCity_Harbor_Movement_SubmarineExit
# 123 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 124 "data/maps/SlateportCity_Harbor/scripts.pory"
	removeobject LOCALID_SLATEPORT_HARBOR_GRUNT
# 125 "data/maps/SlateportCity_Harbor/scripts.pory"
	removeobject LOCALID_SLATEPORT_HARBOR_ARCHIE
# 126 "data/maps/SlateportCity_Harbor/scripts.pory"
	removeobject LOCALID_SLATEPORT_HARBOR_SUBMARINE
# 127 "data/maps/SlateportCity_Harbor/scripts.pory"
	setvar VAR_SLATEPORT_HARBOR_STATE, 2
# 128 "data/maps/SlateportCity_Harbor/scripts.pory"
	setflag FLAG_MET_TEAM_AQUA_HARBOR
# 129 "data/maps/SlateportCity_Harbor/scripts.pory"
	setflag FLAG_HIDE_LILYCOVE_MOTEL_SCOTT
# 130 "data/maps/SlateportCity_Harbor/scripts.pory"
	call_if_eq VAR_0x8008, 0, SlateportCity_Harbor_EventScript_SternApproachPlayer0
# 131 "data/maps/SlateportCity_Harbor/scripts.pory"
	call_if_eq VAR_0x8008, 1, SlateportCity_Harbor_EventScript_SternApproachPlayer1
# 132 "data/maps/SlateportCity_Harbor/scripts.pory"
	call_if_eq VAR_0x8008, 2, SlateportCity_Harbor_EventScript_SternApproachPlayer
# 133 "data/maps/SlateportCity_Harbor/scripts.pory"
	call_if_eq VAR_0x8008, 3, SlateportCity_Harbor_EventScript_SternApproachPlayer
# 134 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_CaptSternWhyStealMySubmarine, MSGBOX_DEFAULT
# 135 "data/maps/SlateportCity_Harbor/scripts.pory"
	closemessage
# 136 "data/maps/SlateportCity_Harbor/scripts.pory"
	setflag FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_1_BLOCKING_ENTRANCE
# 137 "data/maps/SlateportCity_Harbor/scripts.pory"
	setflag FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_2_BLOCKING_ENTRANCE
# 138 "data/maps/SlateportCity_Harbor/scripts.pory"
	copyobjectxytoperm LOCALID_SLATEPORT_HARBOR_CAPT_STERN
# 139 "data/maps/SlateportCity_Harbor/scripts.pory"
	setobjectmovementtype LOCALID_SLATEPORT_HARBOR_CAPT_STERN, MOVEMENT_TYPE_FACE_RIGHT
# 140 "data/maps/SlateportCity_Harbor/scripts.pory"
	releaseall
# 141 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 142 "data/maps/SlateportCity_Harbor/scripts.pory"

# 143 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_SternApproachPlayer0::
# 144 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_SLATEPORT_HARBOR_CAPT_STERN, SlateportCity_Harbor_Movement_SternApproachPlayer0
# 145 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 146 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 147 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 148 "data/maps/SlateportCity_Harbor/scripts.pory"
	return
# 149 "data/maps/SlateportCity_Harbor/scripts.pory"

# 150 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_SternApproachPlayer1::
# 151 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_SLATEPORT_HARBOR_CAPT_STERN, SlateportCity_Harbor_Movement_SternApproachPlayer1
# 152 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 153 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 154 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 155 "data/maps/SlateportCity_Harbor/scripts.pory"
	return
# 156 "data/maps/SlateportCity_Harbor/scripts.pory"

# 157 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_SternApproachPlayer::
# 158 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_SLATEPORT_HARBOR_CAPT_STERN, SlateportCity_Harbor_Movement_SternApproachPlayer
# 159 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 160 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 161 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 162 "data/maps/SlateportCity_Harbor/scripts.pory"
	return
# 163 "data/maps/SlateportCity_Harbor/scripts.pory"

# 164 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Movement_AquaBoardSub:
# 165 "data/maps/SlateportCity_Harbor/scripts.pory"
	delay_16
# 166 "data/maps/SlateportCity_Harbor/scripts.pory"
	delay_16
# 167 "data/maps/SlateportCity_Harbor/scripts.pory"
	jump_up
# 168 "data/maps/SlateportCity_Harbor/scripts.pory"
	set_invisible
# 169 "data/maps/SlateportCity_Harbor/scripts.pory"
	step_end
# 170 "data/maps/SlateportCity_Harbor/scripts.pory"

# 171 "data/maps/SlateportCity_Harbor/scripts.pory"
@ Unused, Archie instead shares above identical movement script with Grunt
# 172 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Movement_ArchieBoardSub:
# 173 "data/maps/SlateportCity_Harbor/scripts.pory"
	delay_16
# 174 "data/maps/SlateportCity_Harbor/scripts.pory"
	delay_16
# 175 "data/maps/SlateportCity_Harbor/scripts.pory"
	jump_up
# 176 "data/maps/SlateportCity_Harbor/scripts.pory"
	set_invisible
# 177 "data/maps/SlateportCity_Harbor/scripts.pory"
	step_end
# 178 "data/maps/SlateportCity_Harbor/scripts.pory"

# 179 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Movement_SubmarineExit:
# 180 "data/maps/SlateportCity_Harbor/scripts.pory"
	delay_16
# 181 "data/maps/SlateportCity_Harbor/scripts.pory"
	delay_16
# 182 "data/maps/SlateportCity_Harbor/scripts.pory"
	delay_16
# 183 "data/maps/SlateportCity_Harbor/scripts.pory"
	delay_16
# 184 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_right
# 185 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_right
# 186 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_right
# 187 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_fast_right
# 188 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_fast_right
# 189 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_fast_right
# 190 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_fast_right
# 191 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_fast_right
# 192 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_fast_right
# 193 "data/maps/SlateportCity_Harbor/scripts.pory"
	step_end
# 194 "data/maps/SlateportCity_Harbor/scripts.pory"

# 195 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Movement_SternApproachPlayer0:
# 196 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_left
# 197 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_left
# 198 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_left
# 199 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_left
# 200 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_up
# 201 "data/maps/SlateportCity_Harbor/scripts.pory"
	step_end
# 202 "data/maps/SlateportCity_Harbor/scripts.pory"

# 203 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Movement_SternApproachPlayer1:
# 204 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_left
# 205 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_left
# 206 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_up
# 207 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_left
# 208 "data/maps/SlateportCity_Harbor/scripts.pory"
	step_end
# 209 "data/maps/SlateportCity_Harbor/scripts.pory"

# 210 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Movement_SternApproachPlayer:
# 211 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_left
# 212 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_left
# 213 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_left
# 214 "data/maps/SlateportCity_Harbor/scripts.pory"
	step_end
# 215 "data/maps/SlateportCity_Harbor/scripts.pory"

# 216 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Movement_PlayerWalkUp:
# 217 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_up
# 218 "data/maps/SlateportCity_Harbor/scripts.pory"
	step_end
# 219 "data/maps/SlateportCity_Harbor/scripts.pory"

# 220 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_AskForTicket::
# 221 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_MayISeeYourTicket, MSGBOX_DEFAULT
# 222 "data/maps/SlateportCity_Harbor/scripts.pory"
	message SlateportCity_Harbor_Text_FlashedTicketWhereTo
# 223 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmessage
# 224 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto SlateportCity_Harbor_EventScript_ChooseDestination
# 225 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 226 "data/maps/SlateportCity_Harbor/scripts.pory"

# 227 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_ChooseDestination::
# 228 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_set FLAG_MET_SCOTT_ON_SS_TIDAL, SlateportCity_Harbor_EventScript_ChooseDestinationWithBattleFrontier
# 229 "data/maps/SlateportCity_Harbor/scripts.pory"
	multichoicedefault 18, 8, MULTI_SSTIDAL_SLATEPORT_NO_BF, 2, FALSE
# 230 "data/maps/SlateportCity_Harbor/scripts.pory"
	switch VAR_RESULT
# 231 "data/maps/SlateportCity_Harbor/scripts.pory"
	case 0, SlateportCity_Harbor_EventScript_Lilycove
# 232 "data/maps/SlateportCity_Harbor/scripts.pory"
	case 1, SlateportCity_Harbor_EventScript_CancelDestinationSelect
# 233 "data/maps/SlateportCity_Harbor/scripts.pory"
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_CancelDestinationSelect
# 234 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 235 "data/maps/SlateportCity_Harbor/scripts.pory"

# 236 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_ChooseDestinationWithBattleFrontier::
# 237 "data/maps/SlateportCity_Harbor/scripts.pory"
	multichoicedefault 17, 6, MULTI_SSTIDAL_SLATEPORT_WITH_BF, 2, FALSE
# 238 "data/maps/SlateportCity_Harbor/scripts.pory"
	switch VAR_RESULT
# 239 "data/maps/SlateportCity_Harbor/scripts.pory"
	case 0, SlateportCity_Harbor_EventScript_Lilycove
# 240 "data/maps/SlateportCity_Harbor/scripts.pory"
	case 1, SlateportCity_Harbor_EventScript_BattleFrontier
# 241 "data/maps/SlateportCity_Harbor/scripts.pory"
	case 2, SlateportCity_Harbor_EventScript_CancelDestinationSelect
# 242 "data/maps/SlateportCity_Harbor/scripts.pory"
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_CancelDestinationSelect
# 243 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 244 "data/maps/SlateportCity_Harbor/scripts.pory"

# 245 "data/maps/SlateportCity_Harbor/scripts.pory"
@ Unused. Should be impossible for player to reach Ferry without having received SS Tidal ticket
# 246 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_NoTicket::
# 247 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_YouMustHaveTicket, MSGBOX_DEFAULT
# 248 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 249 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 250 "data/maps/SlateportCity_Harbor/scripts.pory"

# 251 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_Lilycove::
# 252 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_LilycoveItIs, MSGBOX_YESNO
# 253 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseNewDestination
# 254 "data/maps/SlateportCity_Harbor/scripts.pory"
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_BOARD_SLATEPORT
# 255 "data/maps/SlateportCity_Harbor/scripts.pory"
	call SlateportCity_Harbor_EventScript_BoardFerry
# 256 "data/maps/SlateportCity_Harbor/scripts.pory"
	warp MAP_SS_TIDAL_CORRIDOR, 1, 10
# 257 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitstate
# 258 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 259 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 260 "data/maps/SlateportCity_Harbor/scripts.pory"

# 261 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_BattleFrontier::
# 262 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_BattleFrontierItIs, MSGBOX_YESNO
# 263 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseNewDestination
# 264 "data/maps/SlateportCity_Harbor/scripts.pory"
	call SlateportCity_Harbor_EventScript_BoardFerry
# 265 "data/maps/SlateportCity_Harbor/scripts.pory"
	warp MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 19, 67
# 266 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitstate
# 267 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 268 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 269 "data/maps/SlateportCity_Harbor/scripts.pory"

# 270 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_ChooseNewDestination::
# 271 "data/maps/SlateportCity_Harbor/scripts.pory"
	message SlateportCity_Harbor_Text_WhereWouldYouLikeToGo
# 272 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmessage
# 273 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto SlateportCity_Harbor_EventScript_ChooseDestination
# 274 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 275 "data/maps/SlateportCity_Harbor/scripts.pory"

# 276 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_BoardFerry::
# 277 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_PleaseBoardFerry, MSGBOX_DEFAULT
# 278 "data/maps/SlateportCity_Harbor/scripts.pory"
	closemessage
# 279 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterUp
# 280 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 281 "data/maps/SlateportCity_Harbor/scripts.pory"
	delay 30
# 282 "data/maps/SlateportCity_Harbor/scripts.pory"
	hideobjectat VAR_LAST_TALKED, MAP_SLATEPORT_CITY_HARBOR
# 283 "data/maps/SlateportCity_Harbor/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, SlateportCity_Harbor_EventScript_BoardFerryNorth
# 284 "data/maps/SlateportCity_Harbor/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, SlateportCity_Harbor_EventScript_BoardFerryEast
# 285 "data/maps/SlateportCity_Harbor/scripts.pory"
	delay 30
# 286 "data/maps/SlateportCity_Harbor/scripts.pory"
	hideplayer
# 287 "data/maps/SlateportCity_Harbor/scripts.pory"
	setvar VAR_0x8004, LOCALID_SLATEPORT_HARBOR_SS_TIDAL
# 288 "data/maps/SlateportCity_Harbor/scripts.pory"
	call Common_EventScript_FerryDepart
# 289 "data/maps/SlateportCity_Harbor/scripts.pory"
	return
# 290 "data/maps/SlateportCity_Harbor/scripts.pory"

# 291 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_CancelDestinationSelect::
# 292 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_SailAnotherTime, MSGBOX_DEFAULT
# 293 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 294 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 295 "data/maps/SlateportCity_Harbor/scripts.pory"

# 296 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_BoardFerryEast::
# 297 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_PLAYER, SlateportCity_Harbor_Movement_BoardFerryEast
# 298 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 299 "data/maps/SlateportCity_Harbor/scripts.pory"
	return
# 300 "data/maps/SlateportCity_Harbor/scripts.pory"

# 301 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_BoardFerryNorth::
# 302 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_PLAYER, SlateportCity_Harbor_Movement_BoardFerryNorth
# 303 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 304 "data/maps/SlateportCity_Harbor/scripts.pory"
	return
# 305 "data/maps/SlateportCity_Harbor/scripts.pory"

# 306 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Movement_BoardFerryEast:
# 307 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_right
# 308 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_in_place_faster_up
# 309 "data/maps/SlateportCity_Harbor/scripts.pory"
	step_end
# 310 "data/maps/SlateportCity_Harbor/scripts.pory"

# 311 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Movement_BoardFerryNorth:
# 312 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_up
# 313 "data/maps/SlateportCity_Harbor/scripts.pory"
	step_end
# 314 "data/maps/SlateportCity_Harbor/scripts.pory"

# 315 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_Sailor::
# 316 "data/maps/SlateportCity_Harbor/scripts.pory"
	lock
# 317 "data/maps/SlateportCity_Harbor/scripts.pory"
	faceplayer
# 318 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_unset FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather
# 319 "data/maps/SlateportCity_Harbor/scripts.pory"
	setvar VAR_0x8004, 0
# 320 "data/maps/SlateportCity_Harbor/scripts.pory"
	call_if_set FLAG_DEFEATED_KYOGRE, SlateportCity_Harbor_EventScript_CountDefeatedLegendary
# 321 "data/maps/SlateportCity_Harbor/scripts.pory"
	call_if_set FLAG_DEFEATED_GROUDON, SlateportCity_Harbor_EventScript_CountDefeatedLegendary
# 322 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_eq VAR_0x8004, 2, SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather  @ Defeated both
# 323 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_AbnormalWeather, MSGBOX_DEFAULT
# 324 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 325 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 326 "data/maps/SlateportCity_Harbor/scripts.pory"

# 327 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather::
# 328 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_LoveToGoDeepUnderwaterSomeday, MSGBOX_DEFAULT
# 329 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 330 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 331 "data/maps/SlateportCity_Harbor/scripts.pory"

# 332 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_CountDefeatedLegendary::
# 333 "data/maps/SlateportCity_Harbor/scripts.pory"
	addvar VAR_0x8004, 1
# 334 "data/maps/SlateportCity_Harbor/scripts.pory"
	return
# 335 "data/maps/SlateportCity_Harbor/scripts.pory"

# 336 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_FatMan::
# 337 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_SubTooSmallForMe, MSGBOX_NPC
# 338 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 339 "data/maps/SlateportCity_Harbor/scripts.pory"

# 340 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_CaptStern::
# 341 "data/maps/SlateportCity_Harbor/scripts.pory"
	lock
# 342 "data/maps/SlateportCity_Harbor/scripts.pory"
	faceplayer
# 343 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_set FLAG_BADGE07_GET, SlateportCity_Harbor_EventScript_CaptSternFerryOrScannerComment
# 344 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_set FLAG_EVIL_TEAM_ESCAPED_STERN_SPOKE, SlateportCity_Harbor_EventScript_NeedDive
# 345 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, SlateportCity_Harbor_EventScript_TeamAquaLeftNeedDive
# 346 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_eq VAR_SLATEPORT_HARBOR_STATE, 2, SlateportCity_Harbor_EventScript_WhyStealSubmarine
# 347 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_SameThugsTriedToRobAtMuseum, MSGBOX_DEFAULT
# 348 "data/maps/SlateportCity_Harbor/scripts.pory"
	closemessage
# 349 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 350 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 351 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 352 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 353 "data/maps/SlateportCity_Harbor/scripts.pory"

# 354 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_WhyStealSubmarine::
# 355 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_CaptSternWhyStealMySubmarine, MSGBOX_DEFAULT
# 356 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 357 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 358 "data/maps/SlateportCity_Harbor/scripts.pory"

# 359 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_TeamAquaLeftNeedDive::
# 360 "data/maps/SlateportCity_Harbor/scripts.pory"
	setflag FLAG_EVIL_TEAM_ESCAPED_STERN_SPOKE
# 361 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_TeamAquaLeftNeedDive, MSGBOX_DEFAULT
# 362 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 363 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 364 "data/maps/SlateportCity_Harbor/scripts.pory"

# 365 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_NeedDive::
# 366 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_NeedDiveToCatchSub, MSGBOX_DEFAULT
# 367 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 368 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 369 "data/maps/SlateportCity_Harbor/scripts.pory"

# 370 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_CaptSternFerryOrScannerComment::
# 371 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_eq VAR_TEMP_1, 1, SlateportCity_Harbor_EventScript_TradedScanner
# 372 "data/maps/SlateportCity_Harbor/scripts.pory"
	checkitem ITEM_SCANNER
# 373 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_Harbor_EventScript_AskToTradeScanner
# 374 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_FerryFinished
# 375 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_WontBeLongBeforeWeFinishFerry, MSGBOX_DEFAULT
# 376 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 377 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 378 "data/maps/SlateportCity_Harbor/scripts.pory"

# 379 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_FerryFinished::
# 380 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_FinishedMakingFerry, MSGBOX_DEFAULT
# 381 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 382 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 383 "data/maps/SlateportCity_Harbor/scripts.pory"

# 384 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_AskToTradeScanner::
# 385 "data/maps/SlateportCity_Harbor/scripts.pory"
	message SlateportCity_Harbor_Text_WouldYouTradeScanner
# 386 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmessage
# 387 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto SlateportCity_Harbor_EventScript_ChooseScannerTrade
# 388 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 389 "data/maps/SlateportCity_Harbor/scripts.pory"

# 390 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_ChooseScannerTrade::
# 391 "data/maps/SlateportCity_Harbor/scripts.pory"
	multichoice 0, 0, MULTI_STERN_DEEPSEA, FALSE
# 392 "data/maps/SlateportCity_Harbor/scripts.pory"
	switch VAR_RESULT
# 393 "data/maps/SlateportCity_Harbor/scripts.pory"
	case 0, SlateportCity_Harbor_EventScript_DeepSeaTooth
# 394 "data/maps/SlateportCity_Harbor/scripts.pory"
	case 1, SlateportCity_Harbor_EventScript_DeepSeaScale
# 395 "data/maps/SlateportCity_Harbor/scripts.pory"
	case 2, SlateportCity_Harbor_EventScript_DeclineTrade
# 396 "data/maps/SlateportCity_Harbor/scripts.pory"
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_DeclineTrade
# 397 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 398 "data/maps/SlateportCity_Harbor/scripts.pory"

# 399 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_DeepSeaTooth::
# 400 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_TradeForDeepSeaTooth, MSGBOX_YESNO
# 401 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseDifferentTrade
# 402 "data/maps/SlateportCity_Harbor/scripts.pory"
	giveitem ITEM_DEEP_SEA_TOOTH
# 403 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 404 "data/maps/SlateportCity_Harbor/scripts.pory"
	removeitem ITEM_SCANNER
# 405 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_HandedScannerToStern, MSGBOX_DEFAULT
# 406 "data/maps/SlateportCity_Harbor/scripts.pory"
	setflag FLAG_EXCHANGED_SCANNER
# 407 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto SlateportCity_Harbor_EventScript_TradedScanner
# 408 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 409 "data/maps/SlateportCity_Harbor/scripts.pory"

# 410 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_DeepSeaScale::
# 411 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_TradeForDeepSeaScale, MSGBOX_YESNO
# 412 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseDifferentTrade
# 413 "data/maps/SlateportCity_Harbor/scripts.pory"
	giveitem ITEM_DEEP_SEA_SCALE
# 414 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 415 "data/maps/SlateportCity_Harbor/scripts.pory"
	removeitem ITEM_SCANNER
# 416 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_HandedScannerToStern, MSGBOX_DEFAULT
# 417 "data/maps/SlateportCity_Harbor/scripts.pory"
	setflag FLAG_EXCHANGED_SCANNER
# 418 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto SlateportCity_Harbor_EventScript_TradedScanner
# 419 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 420 "data/maps/SlateportCity_Harbor/scripts.pory"

# 421 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_DeclineTrade::
# 422 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_IfYouWantToTradeLetMeKnow, MSGBOX_DEFAULT
# 423 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 424 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 425 "data/maps/SlateportCity_Harbor/scripts.pory"

# 426 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_ChooseDifferentTrade::
# 427 "data/maps/SlateportCity_Harbor/scripts.pory"
	message SlateportCity_Harbor_Text_WhichOneDoYouWant
# 428 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmessage
# 429 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto SlateportCity_Harbor_EventScript_ChooseScannerTrade
# 430 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 431 "data/maps/SlateportCity_Harbor/scripts.pory"

# 432 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_TradedScanner::
# 433 "data/maps/SlateportCity_Harbor/scripts.pory"
	setvar VAR_TEMP_1, 1
# 434 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_ThisWillHelpResearch, MSGBOX_DEFAULT
# 435 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 436 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 437 "data/maps/SlateportCity_Harbor/scripts.pory"

# 438 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_FerryServiceUnavailable:
# 439 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "I beg your pardon?\n"
# 440 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "You're looking for a ship?\p"
# 441 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "I'm sorry, the ferry service isn't\n"
# 442 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "available at present…$"
# 443 "data/maps/SlateportCity_Harbor/scripts.pory"

# 444 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_MayISeeYourTicket:
# 445 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Hello, are you here for the ferry?\n"
# 446 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "May I see your TICKET?$"
# 447 "data/maps/SlateportCity_Harbor/scripts.pory"

# 448 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_YouMustHaveTicket:
# 449 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "{PLAYER} doesn't have the TICKET…\p"
# 450 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "I'm terribly sorry.\p"
# 451 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "You must have a TICKET to board\n"
# 452 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "the ferry.$"
# 453 "data/maps/SlateportCity_Harbor/scripts.pory"

# 454 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_FlashedTicketWhereTo:
# 455 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "{PLAYER} flashed the TICKET.\p"
# 456 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Perfect! That's all you need!\p"
# 457 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "And where would you like to go?$"
# 458 "data/maps/SlateportCity_Harbor/scripts.pory"

# 459 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_SailAnotherTime:
# 460 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Please sail with us another time!$"
# 461 "data/maps/SlateportCity_Harbor/scripts.pory"

# 462 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_LilycoveItIs:
# 463 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "LILYCOVE CITY it is, then!$"
# 464 "data/maps/SlateportCity_Harbor/scripts.pory"

# 465 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_BattleFrontierItIs:
# 466 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "BATTLE FRONTIER it is, then!$"
# 467 "data/maps/SlateportCity_Harbor/scripts.pory"

# 468 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_PleaseBoardFerry:
# 469 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Please board the ferry and wait for\n"
# 470 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "departure.$"
# 471 "data/maps/SlateportCity_Harbor/scripts.pory"

# 472 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_WhereWouldYouLikeToGo:
# 473 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Then, where would you like to go?$"
# 474 "data/maps/SlateportCity_Harbor/scripts.pory"

# 475 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_LoveToGoDeepUnderwaterSomeday:
# 476 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "A journey to the bottom of the sea…\n"
# 477 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "I wonder what it'd be like?\p"
# 478 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "I'd love to go deep underwater like\n"
# 479 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "that someday.$"
# 480 "data/maps/SlateportCity_Harbor/scripts.pory"

# 481 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_AbnormalWeather:
# 482 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "For a ship to sail safely, we need to\n"
# 483 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "know about the weather!\p"
# 484 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Speaking of weather, I heard something\n"
# 485 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "from a guy at the WEATHER INSTITUTE.\p"
# 486 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "He was saying abnormal weather has\n"
# 487 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "been reported all over the place!\p"
# 488 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "You should visit the WEATHER INSTITUTE\n"
# 489 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "and ask around!$"
# 490 "data/maps/SlateportCity_Harbor/scripts.pory"

# 491 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_SubTooSmallForMe:
# 492 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "I wanted to go with CAPT. STERN on\n"
# 493 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "the ocean floor exploration.\p"
# 494 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "But the sub's too small for me.\p"
# 495 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "If I squeezed in, there wouldn't be\n"
# 496 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "any room for the CAPTAIN…$"
# 497 "data/maps/SlateportCity_Harbor/scripts.pory"

# 498 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_SameThugsTriedToRobAtMuseum:
# 499 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "CAPT. STERN: Those thugs…\p"
# 500 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "They're the same lot who tried to rob\n"
# 501 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "the DEVON GOODS at the MUSEUM.$"
# 502 "data/maps/SlateportCity_Harbor/scripts.pory"

# 503 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_ArchieYouAgainHideoutInLilycove:
# 504 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "ARCHIE: Oh?\n"
# 505 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Not you again…\p"
# 506 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "You are tenacious to track us here,\n"
# 507 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "that much I will give you.\p"
# 508 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "But now…\n"
# 509 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "No one can stop us! No one!\p"
# 510 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Or, will you follow us back to our\n"
# 511 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "HIDEOUT in LILYCOVE CITY?\p"
# 512 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Fwahahahaha…$"
# 513 "data/maps/SlateportCity_Harbor/scripts.pory"

# 514 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_CaptSternWhyStealMySubmarine:
# 515 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "CAPT. STERN: Why…\p"
# 516 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Why would TEAM AQUA steal my\n"
# 517 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "SUBMARINE EXPLORER 1?\p"
# 518 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "They can't be after the slumbering\n"
# 519 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "POKéMON at the bottom of the sea…\p"
# 520 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "But even if I were to chase them,\n"
# 521 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "I don't stand a chance against them…$"
# 522 "data/maps/SlateportCity_Harbor/scripts.pory"

# 523 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_TeamAquaLeftNeedDive:
# 524 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "CAPT. STERN: Oh, {PLAYER}{KUN}…\p"
# 525 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Okay… So TEAM AQUA left before you\n"
# 526 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "could stop them…\p"
# 527 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Oh, no, don't blame yourself.\n"
# 528 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "You're not responsible for this.\p"
# 529 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Trying to catch a submarine…\n"
# 530 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "It's impossible for most people.\p"
# 531 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "You would need a POKéMON that knows\n"
# 532 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "how to DIVE…\p"
# 533 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Perhaps if you went out to\n"
# 534 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "MOSSDEEP CITY…\p"
# 535 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "A lot of divers live out there, so\n"
# 536 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "someone might teach you…$"
# 537 "data/maps/SlateportCity_Harbor/scripts.pory"

# 538 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_NeedDiveToCatchSub:
# 539 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "CAPT. STERN: Trying to catch a\n"
# 540 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "submarine… It's impossible.\p"
# 541 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "You would need a POKéMON that knows\n"
# 542 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "how to DIVE…\p"
# 543 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Perhaps if you went out to\n"
# 544 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "MOSSDEEP CITY…\p"
# 545 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "A lot of divers live out there, so\n"
# 546 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "someone might teach you…$"
# 547 "data/maps/SlateportCity_Harbor/scripts.pory"

# 548 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_WontBeLongBeforeWeFinishFerry:
# 549 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "CAPT. STERN: Oh, yes.\n"
# 550 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "MR. BRINEY came to our SHIPYARD.\p"
# 551 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "It won't be long now before we finish\n"
# 552 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "making the ferry!$"
# 553 "data/maps/SlateportCity_Harbor/scripts.pory"

# 554 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_FinishedMakingFerry:
# 555 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "CAPT. STERN: {PLAYER}{KUN}!\p"
# 556 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "We finally finished making the ferry\n"
# 557 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "S.S. TIDAL!\p"
# 558 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "We couldn't have done it without\n"
# 559 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "your friend MR. BRINEY.\p"
# 560 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Please go for a short cruise on it!$"
# 561 "data/maps/SlateportCity_Harbor/scripts.pory"

# 562 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_WouldYouTradeScanner:
# 563 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "CAPT. STERN: Oh?\n"
# 564 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "{PLAYER}{KUN}, that item you have…\p"
# 565 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "That's a SCANNER! That would sure\n"
# 566 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "help us on our explorations.\p"
# 567 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "{PLAYER}{KUN}, would you trade your\n"
# 568 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "SCANNER for something?\p"
# 569 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Like, say, a DEEPSEATOOTH or\n"
# 570 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "a DEEPSEASCALE that I have?$"
# 571 "data/maps/SlateportCity_Harbor/scripts.pory"

# 572 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_IfYouWantToTradeLetMeKnow:
# 573 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "CAPT. STERN: Are you certain?\n"
# 574 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "It's useless to you, {PLAYER}{KUN}…\p"
# 575 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Well, okay, then. If you want to trade\n"
# 576 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "your SCANNER, let me know.$"
# 577 "data/maps/SlateportCity_Harbor/scripts.pory"

# 578 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_TradeForDeepSeaTooth:
# 579 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "CAPT. STERN: So you'll trade it for\n"
# 580 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "my DEEPSEATOOTH?$"
# 581 "data/maps/SlateportCity_Harbor/scripts.pory"

# 582 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_TradeForDeepSeaScale:
# 583 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "CAPT. STERN: So you'll trade it for\n"
# 584 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "my DEEPSEASCALE?$"
# 585 "data/maps/SlateportCity_Harbor/scripts.pory"

# 586 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_WhichOneDoYouWant:
# 587 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "CAPT. STERN: Which one do you want?$"
# 588 "data/maps/SlateportCity_Harbor/scripts.pory"

# 589 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_HandedScannerToStern:
# 590 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "{PLAYER} handed the SCANNER to\n"
# 591 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "CAPT. STERN.$"
# 592 "data/maps/SlateportCity_Harbor/scripts.pory"

# 593 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_ThisWillHelpResearch:
# 594 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "CAPT. STERN: Thanks, {PLAYER}{KUN}!\n"
# 595 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "This will help our research a lot!$"

SlateportHarbor_PushDynTickets_Text_0:
# 29 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "{STR_VAR_1}$"

SlateportHarbor_SelectedSSTicket_Text_0:
# 42 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Lilycove$"

SlateportHarbor_SelectedSSTicket_Text_1:
# 44 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Battle Frontier$"
