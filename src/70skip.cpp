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

#define LOCALE_SKIP_0 "Reset me level 70"

class Azerothcore_level_70_skip : public CreatureScript
{
public:
   Azerothcore_level_70_skip() : CreatureScript("npc_ac_70_skip") { }

   bool OnGossipHello(Player* player, Creature* creature) override
   {
      AddGossipItemFor(player, GOSSIP_ICON_INTERACT_1, LOCALE_SKIP_0, GOSSIP_SENDER_MAIN, 11);
      SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature);
      return true;
   }

   bool OnGossipSelect(Player* player, Creature* creature, uint32 /*menuId*/, uint32 gossipListId) override
   {
      int level = 70;
      CloseGossipMenuFor(player);
	  ClearGossipMenuFor(player);
      switch(gossipListId)
      {
      case 11:
         AddGossipItemFor(player, GOSSIP_ICON_INTERACT_1, "Reset me level 70", GOSSIP_SENDER_MAIN, 12);
         SendGossipMenuFor(player, player->GetGossipTextId(creature), creature->GetGUID());
         break;

      case 12:
         player->GiveLevel(level);
		 player->SetMoney(MAX_MONEY_AMOUNT);
		 LearnAllClassQuestSkills(player);
		 MaxAllTBCReps(player);
         ObjectAccessor::SaveAllPlayers();//Save
         CloseGossipMenuFor(player);
         break;
      
      case 13: 
         CloseGossipMenuFor(player);
         break;
  
      default:
         break;
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
				break;
			case 4: // Rogue
				break;
			case 5: // Priest
				break;
			case 6: // DK
				break;
			case 7: // Shaman
				break;
			case 8: // Mage
				break;
			case 8: // Warlock
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
   }
   
   void LearnPaladinQuestSkills(Player* player) {
		player->learnSpell(7328); //redemption
   }
   
   void LearnDruidQuestSkills(Player* player) {
		player->learnSpell(5487); //bear form
		player->learnSpell(6795); // growl
		player->learnSpell(40120); //swift flight
		
   }
   
   void MaxAllTBCReps(Player* player) {
	   float amount = 42000;
	   int factions[] = { 1012, 934, 932, 942, 989, 947 };
	   
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
}