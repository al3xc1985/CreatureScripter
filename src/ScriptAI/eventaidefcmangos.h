#ifndef EVENTAIDEFCMANGOS_H
#define EVENTAIDEFCMANGOS_H

#include <QVector>
#include <QMap>

#include "eventaidefcommon.h"

namespace EventAI
{

static const QVector<TypeValue> SheetState =
{
TypeValue{0, "No Weapon", "Sheets the weapons of the creature"},
TypeValue{1, "Melee Weapon", "Unsheets the melee weapons of the creature"},
TypeValue{2, "Ranged Weapon", "Unsheets the ranged weapon of the creature"}
};

// used by ParameterType::TARGET (19)
static const QVector<TypeValue> TargetTypes =
{
TypeValue{0, /*TARGET_T_*/"SELF"                           ,"Self Cast"},
TypeValue{1, /*TARGET_T_*/"HOSTILE"                        ,"Current Target (ie: Highest Aggro)"},
TypeValue{2, /*TARGET_T_*/"HOSTILE_SECOND_AGGRO"           ,"Second Highest Aggro (Generaly used for Cleaves and some special attacks)"},
TypeValue{3, /*TARGET_T_*/"HOSTILE_LAST_AGGRO"             ,"Dead Last on Aggro (no idea what this could be used for)"},
TypeValue{4, /*TARGET_T_*/"HOSTILE_RANDOM"                 ,"Random Target on The Threat List"},
TypeValue{5, /*TARGET_T_*/"HOSTILE_RANDOM_NOT_TOP"         ,"Any Random Target Except Top Threat"},
TypeValue{6, /*TARGET_T_*/"ACTION_INVOKER"                 ,"Unit Who Caused This Event to Occur (only works for EVENT_T_AGGRO, EVENT_T_KILL, EVENT_T_DEATH, EVENT_T_SPELLHIT, EVENT_T_OOC_LOS, EVENT_T_FRIENDLY_HP, EVENT_T_FRIENDLY_IS_CC, EVENT_T_FRIENDLY_MISSING_BUFF, EVENT_T_RECEIVE_EMOTE, EVENT_T_RECEIVE_AI_EVENT)"},
TypeValue{7, /*TARGET_T_*/"ACTION_INVOKER_OWNER"           ,"Unit who is responsible for Event to occur (only works for EVENT_T_AGGRO, EVENT_T_KILL, EVENT_T_DEATH, EVENT_T_SPELLHIT, EVENT_T_OOC_LOS, EVENT_T_FRIENDLY_HP, EVENT_T_FRIENDLY_IS_CC, EVENT_T_FRIENDLY_MISSING_BUFF, EVENT_T_RECEIVE_EMOTE, EVENT_T_RECEIVE_AI_EVENT)"},
TypeValue{8, /*TARGET_T_*/"HOSTILE_RANDOM_PLAYER"          ,"Random Player on The Threat List"},
TypeValue{9, /*TARGET_T_*/"HOSTILE_RANDOM_NOT_TOP_PLAYER"  ,"Any Random Player Except Top Threat"},
TypeValue{10,/*TARGET_T_*/"EVENT_SENDER"                   ,"Creature who sent a received AIEvent - only triggered by EVENT_T_RECEIVE_AI_EVENT"},
TypeValue{11,/*TARGET_T_*/"SUMMONER"                       ,"Summoner of given Unit if it has one"}
};

static const QVector<TypeValue> CastFlags =
{
TypeValue{1 , /*CAST_*/"INTURRUPT_PREVIOUS" , "Interrupts any previous spell casting (basicaly makes sure that this spell goes off)"},
TypeValue{2 , /*CAST_*/"TRIGGERED"          , "Forces the spell to be instant cast and require no mana/reagents."},
TypeValue{4 , /*CAST_*/"FORCE_CAST"         , "Forces spell to cast even if the target is possibly out of range or the creature is possibly out of mana"},
TypeValue{8 , /*CAST_*/"NO_MELEE_IF_OOM"    , "Prevents creature from entering melee if out of mana or out of range"},
TypeValue{16, /*CAST_*/"FORCE_TARGET_SELF"  , "Forces the target to cast this spell on itself"},
TypeValue{32, /*CAST_*/"AURA_NOT_PRESENT"   , "Only casts the spell on the target if the target does not have the aura from that spell on itself already."}
};

static const QVector<TypeValue> EventTypeMask =
{
TypeValue{0x01, /*AI_EVENT_*/"JUST_DIED",       "Sender = Killed Npc, Invoker = Killer - Sent when npc dies"},
TypeValue{0x02, /*AI_EVENT_*/"CRITICAL_HEALTH", "Sender = Hurt Npc, Invoker = DamageDealer - Sent when damaged below 10% health"},
TypeValue{0x04, /*AI_EVENT_*/"LOST_HEALTH",     "Sender = Hurt Npc, Invoker = DamageDealer - Sent when damaged below 50% health"},
TypeValue{0x08, /*AI_EVENT_*/"LOST_SOME_HEALTH","Sender = Hurt Npc, Invoker = DamageDealer - Sent when damaged below 90% health"},
TypeValue{0x10, /*AI_EVENT_*/"GOT_FULL_HEALTH", "Sender = Healed Npc, Invoker = Healer - Sent when healed to full health"},
};

static const QVector<TypeValue> EventFlags =
{
TypeValue{1         ,"REPEATABLE"     ,"Event repeats (Does not repeat if this flag is not set)"},
TypeValue{2         ,"NORMAL"         ,"Event occurs in Normal instance difficulty (will not occur in Normal if not set)"},
TypeValue{4         ,"HEROIC"         ,"Event occurs in Heroic instance difficulty (will not occur in Heroic if not set)"},
TypeValue{8         ,""                     ,""},
TypeValue{16        ,""                     ,""},
TypeValue{32        ,"RANDOM_ACTION"  ,"At event occur execute one random action from event actions instead all actions."},
TypeValue{64        ,""                     ,""},
TypeValue{128       ,"DEBUG_ONLY"     ,"Prevents events from occuring on Release builds. Useful for testing new features."}
};

// referenced in description of 44   ACTION_T_CHANCED_TEXT, but cant see how it should be used. Not used yet
static const QVector<TypeValue> TextTypes =
{
TypeValue{0,    /*CHAT_TYPE_*/"SAY"                 ,"This type sets the text to be displayed as a Say (Speech Bubble)."},
TypeValue{1,    /*CHAT_TYPE_*/"YELL"                ,"This type sets the text to be displayed as a Yell (Red Speech Bubble) and usually has a matching Sound ID."},
TypeValue{2,    /*CHAT_TYPE_*/"TEX T_EMOTE"          ,"This type sets the text to be displayed as a text emote in orange in the chat log."},
TypeValue{3,    /*CHAT_TYPE_*/"BOSS_EMOTE"          ,"This type sets the text to be displayed as a text emote in orange in the chat log (Used only for specific Bosses)."},
TypeValue{4,    /*CHAT_TYPE_*/"WHISPER"             ,"This type sets the text to be displayed as a whisper to the player in the chat log."},
TypeValue{5,    /*CHAT_TYPE_*/"BOSS_WHISPER"        ,"This type sets the text to be displayed as a whisper to the player in the chat log (Used only for specific Bosses)."},
TypeValue{6,    /*CHAT_TYPE_*/"ZONE_YELL"           ,"Same as CHAT_TYPE_YELL but will display to all players in current zone."}
};


// Not used yet, not sure if it will be either
static const QVector<TypeValue> LanguageTypes =
{
TypeValue{0 ,   "UNIVERSAL"                    ,"Text in this language is understood by ALL Races."},
TypeValue{1 ,   "ORCISH"                       ,"Text in this language is understood ONLY by Horde Races."},
TypeValue{2 ,   "DARNASSIAN"                   ,"Text in this language is understood ONLY by the Night Elf Race."},
TypeValue{3 ,   "TAURAHE"                      ,"Text in this language is understood ONLY by the Tauren Race."},
TypeValue{6 ,   "DWARVISH"                     ,"Text in this language is understood ONLY by the Dwarf Race."},
TypeValue{7 ,   "COMMON"                       ,"Text in this language is understood ONLY by Alliance Races."},
TypeValue{8 ,   "DEMONIC"                      ,"Text in this language is understood ONLY by the Demon Race (Not Implimented)."},
TypeValue{9 ,   "TITAN"                        ,"This language was used by Sargeras to speak with other Titians (Not Implemented)."},
TypeValue{10,   "THALASSIAN"                   ,"Text in this language is understood ONLY by the Blood Elf Race."},
TypeValue{11,   "DRACONIC"                     ,"Text in this language is understood ONLY by the Dragon Race."},
TypeValue{12,   "KALIMAG"                      ,"Text will display as Kalimag (not readable by players, language of all elementals)"},
TypeValue{13,   "GNOMISH"                      ,"Text in this language is understood ONLY by the Gnome Race."},
TypeValue{14,   "TROLL"                        ,"Text in this language is understood ONLY by the Troll Race."},
TypeValue{33,   "GUTTERSPEAK"                  ,"Text in this language is understood ONLY by the Undead Race."},
TypeValue{35,   "DRAENEI"                      ,"Text in this language is understood ONLY by the Draenai Race."},
TypeValue{36,   "ZOMBIE"                       ,"(not currently used?)"},
TypeValue{37,   "GNOMISH BINARY"               ,"Binary language used by Alliance when drinking Binary Brew"},
TypeValue{38,   "GOBLIN BINARY"                ,"Binary language used by Horce when drinking Binary Brew"}
};

static const QVector<TypeValue> StandState =
{
TypeValue{0, /*UNIT_STAND_STATE_*/"STAND", ""},
TypeValue{1, /*UNIT_STAND_STATE_*/"SIT", ""},
TypeValue{2, /*UNIT_STAND_STATE_*/"SIT_CHAIR", ""},
TypeValue{3, /*UNIT_STAND_STATE_*/"SLEEP", ""},
TypeValue{4, /*UNIT_STAND_STATE_*/"SIT_LOW_CHAIR", ""},
TypeValue{5, /*UNIT_STAND_STATE_*/"SIT_MEDIUM_CHAIR", ""},
TypeValue{6, /*UNIT_STAND_STATE_*/"SIT_HIGH_CHAIR", ""},
TypeValue{7, /*UNIT_STAND_STATE_*/"DEAD", ""},
TypeValue{8, /*UNIT_STAND_STATE_*/"KNEEL", ""}
};

static const QVector<TypeValue> MovementType =
{
TypeValue{0, "Idle", ""},
TypeValue{1, "Random", ""},
TypeValue{2, "Waypoint", ""}
};

static const QVector<TypeValue> ReactState =
{
TypeValue{0, "Passive", ""},
TypeValue{1, "Defensive", ""},
TypeValue{2, "Aggressive", ""}
};

static const QVector<TypeValue> factionFlags = {
TypeValue{0x00, /*"TEMPFACTION_*/"NONE", "A persistent faction change and will require manual change to default/another faction when changed once"},
TypeValue{0x01, /*"TEMPFACTION_*/"RESTORE_RESPAWN", "Default faction will be restored at respawn"},
TypeValue{0x02, /*"TEMPFACTION_*/"RESTORE_COMBAT_STOP", "... at CombatStop() (happens at creature death, at evade or custom scripte among others)"},
TypeValue{0x04, /*"TEMPFACTION_*/"RESTORE_REACH_HOME", "... at reaching home in home movement (evade), if not already done at CombatStop()"}
};











}
#endif // EVENTAIDEFCMANGOS_H
