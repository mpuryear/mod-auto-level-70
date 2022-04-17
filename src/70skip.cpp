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
         AddGossipItemFor(player, GOSSIP_ICON_INTERACT_1, "Yes", GOSSIP_SENDER_MAIN, 12);
	 AddGossipItemFor(player, GOSSIP_ICON_INTERACT_1, "No", GOSSIP_SENDER_MAIN, 13);
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
	   
   }
   
   void MaxAllTBCReps(Player* player) {
	   float amount = 42000;
	   int factions[] = [1012, 934, 932, 942, 989, 947];
	   
	   for (int i = 0; i < factions.size; i++) {
		player->GetReputationMgr().SetOneFactionReputation(factions[i], amount, false);
		player->GetReputationMgr().SendState(player->GetReputationMgr().GetState(factions[i]));
	   }
   }
};

void AddLvl70SkipScripts()
{
   new Azerothcore_level_70_skip;
}