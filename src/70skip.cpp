/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "ScriptMgr.h"
#include "Player.h"
#include "Config.h"
#include "Chat.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ReputationMgr.h"
#include "SpellInfo.h"
#include "SpellMgr.h"

class Azerothcore_level_70_skip : public CreatureScript
{
public:
   Azerothcore_level_70_skip() : CreatureScript("Azerothcore_level_70_skip") { }

   bool OnGossipHello(Player* player, Creature* creature) override
   {
      AddGossipItemFor(player, GOSSIP_ICON_INTERACT_1, "Set me to level 70", GOSSIP_SENDER_MAIN, 1);
	  AddGossipItemFor(player, GOSSIP_ICON_INTERACT_1, "Cancel", GOSSIP_SENDER_MAIN, 2);
      SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature);
      return true;
   }

   bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 Sender, uint32 gossipListId) override
   {
		int level = 70;
		player->PlayerTalkClass->ClearMenus();
	  
		if (Sender == GOSSIP_SENDER_MAIN) {
			if (gossipListId == 1) {
				player->GiveLevel(level);
				player->SetMoney(MAX_MONEY_AMOUNT);
				LearnAllClassQuestSkills(player);
				MaxAllTBCReps(player);
				ObjectAccessor::SaveAllPlayers();//Save
				CloseGossipMenuFor(player);
			} else if (gossipListId == 2) {
				CloseGossipMenuFor(player);
			}
		}

		return true;
   }
   
   void LearnAllClassQuestSkills(Player* player) {
	   switch(player->getClass()) {
		   case 1: // warrior
				LearnWarriorQuestSkills(player);
				break;
			case 2: // paladin
				LearnPaladinQuestSkills(player);
				break;
			case 3: // hunter
				LearnHunterQuestSkills(player);
				break;
			case 4: // Rogue
				break;
			case 5: // Priest
				break;
			case 6: // DK
				break;
			case 7: // Shaman
				LearnShamanQuestSkills(player);
				break;
			case 8: // Mage
				break;
			case 9: // Warlock
				LearnWarlockQuestSkills(player);
				break;
			case 11: // Druid
				LearnDruidQuestSkills(player);
				break;
			default: break;
	   }
   }
   
   void LearnWarriorQuestSkills(Player* player) {  
		player->learnSpell(71); //dstance
		player->learnSpell(355); //taunt
		player->learnSpell(2458); //zerkerstance 
		player->learnSpell(7386); // sunder		
   }
   
   void LearnPaladinQuestSkills(Player* player) {
		player->learnSpell(7328); //redemption
   }
   
   void LearnDruidQuestSkills(Player* player) {
		player->learnSpell(5487); //bear form
		player->learnSpell(33878); //Mangle bear
		player->learnSpell(33876); //Mangle cat
		player->learnSpell(6807); //Maul
		player->learnSpell(6795); // growl
		player->learnSpell(40120); //swift flight
   }
   
   void LearnHunterQuestSkills(Player* player) {
		player->learnSpell(6991); //Feed Pet
		player->learnSpell(883); //Call pet
		player->learnSpell(2641); //Dismiss Pet
		player->learnSpell(1515); //Tame Beast
		player->learnSpell(1462); //Beast Lore
		player->learnSpell(982); // revive pet
   }
   
   void LearnWarlockQuestSkills(Player* player) {
		player->learnSpell(691); //summon felhunter
   }
   
   void LearnShamanQuestSkills(Player* player) {
		player->learnSpell(3599); //Searing Totem
   }
   
   void MaxAllTBCReps(Player* player) {
	   float amount = 42000;
	   int factions[] = { 1012, 934, 932, 935, 942, 989, 947 };
	   
	   for (auto const& faction : factions) {
	    FactionEntry const* factionEntry = sFactionStore.LookupEntry(faction);
		player->GetReputationMgr().SetOneFactionReputation(factionEntry, amount, false);
		player->GetReputationMgr().SendState(player->GetReputationMgr().GetState(factionEntry));
	   }
   }
};

class Azerothcore_level_80_skip : public CreatureScript
{
public:
   Azerothcore_level_80_skip() : CreatureScript("Azerothcore_level_80_skip") { }

   bool OnGossipHello(Player* player, Creature* creature) override
   {
      AddGossipItemFor(player, GOSSIP_ICON_INTERACT_1, "Set me to level 80", GOSSIP_SENDER_MAIN, 1);
	  AddGossipItemFor(player, GOSSIP_ICON_INTERACT_1, "Cancel", GOSSIP_SENDER_MAIN, 2);
      SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature);
      return true;
   }

   bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 Sender, uint32 gossipListId) override
   {
		int level = 80;
		player->PlayerTalkClass->ClearMenus();
	  
		if (Sender == GOSSIP_SENDER_MAIN) {
			if (gossipListId == 1) {
				player->GiveLevel(level);
				player->SetMoney(MAX_MONEY_AMOUNT);
				LearnAllClassQuestSkills(player);
				MaxAllWrathReps(player);
				ObjectAccessor::SaveAllPlayers();//Save
				CloseGossipMenuFor(player);
			} else if (gossipListId == 2) {
				CloseGossipMenuFor(player);
			}
		}

		return true;
   }
   
   void LearnAllClassQuestSkills(Player* player) {
	   switch(player->getClass()) {
		   case 1: // warrior
				LearnWarriorQuestSkills(player);
				break;
			case 2: // paladin
				LearnPaladinQuestSkills(player);
				break;
			case 3: // hunter
				LearnHunterQuestSkills(player);
				break;
			case 4: // Rogue
				break;
			case 5: // Priest
				break;
			case 6: // DK
				break;
			case 7: // Shaman
				LearnShamanQuestSkills(player);
				break;
			case 8: // Mage
				break;
			case 9: // Warlock
				LearnWarlockQuestSkills(player);
				break;
			case 11: // Druid
				LearnDruidQuestSkills(player);
				break;
			default: break;
	   }
   }
   
   void LearnWarriorQuestSkills(Player* player) {  
		player->learnSpell(71); //dstance
		player->learnSpell(355); //taunt
		player->learnSpell(2458); //zerkerstance
		player->learnSpell(7386); // sunder
   }
   
   void LearnPaladinQuestSkills(Player* player) {
		player->learnSpell(7328); //redemption
   }
   
   void LearnDruidQuestSkills(Player* player) {
		player->learnSpell(5487); //bear form
		player->learnSpell(33878); //Mangle bear
		player->learnSpell(33876); //Mangle cat
		player->learnSpell(6807); // Maul
		player->learnSpell(6795); // growl
		player->learnSpell(40120); //swift flight
   }
   
   void LearnHunterQuestSkills(Player* player) {
		player->learnSpell(6991); //Feed Pet
		player->learnSpell(883); //Call pet
		player->learnSpell(2641); //Dismiss Pet
		player->learnSpell(1515); //Tame Beast
		player->learnSpell(1462); //Beast Lore
   }
   
   void LearnWarlockQuestSkills(Player* player) {
		player->learnSpell(691); //summon felhunter
   }
   
   void LearnShamanQuestSkills(Player* player) {
		player->learnSpell(3599); //Searing Totem
		player->learnSpell(8071); //Stoneskin Totem
		player->learnSpell(5394); //healing stream Totem
   }
   
   void MaxAllWrathReps(Player* player) {
	   float amount = 80000;
	   int factions[] = {
			1052, // Horde exp
			1073, // Kaluak
			1091, // Wyrmrest
			1090, // kirin tor
			1098, // Knights of the ebonblade
			1106, // Argent Crusade
			1105, // Oracles
			1104, // Frenzyheart
			1119, // Hodir
			1012, 
			934,
			932,
			935,
			942,
			989,
			947
		};
	   
	   for (auto const& faction : factions) {
	    FactionEntry const* factionEntry = sFactionStore.LookupEntry(faction);
		player->GetReputationMgr().SetOneFactionReputation(factionEntry, amount, false);
		player->GetReputationMgr().SendState(player->GetReputationMgr().GetState(factionEntry));
	   }
   }
};


void AddLvl70SkipScripts()
{
   new Azerothcore_level_70_skip;
   new Azerothcore_level_80_skip;
}