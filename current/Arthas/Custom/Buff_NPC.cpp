/* Copyright (C) 2010 SAMCC Studios <http://www.samccstudios.com/>
 * Written by LordPsyan
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

 /*
Script Name: npc_buff v1.1
Complete: 100%
Comment: Database Driven Buff Master
*/

#include "LordPsyan.h"

#define GOSSIP_SENDER_MAIN      1000
#define GOSSIP_SMALLBUFF        2000
#define GOSSIP_LARGEBUFF        3000
#define GOSSIP_GMBUFF           4000
#define GOSSIP_PLAYERTOOLS      5000

#define SPELL_RESURRECTION_SICKNESS_15007  15007

#define NB_BUFF_PAGE            10
#define MSG_TYPE                100002
#define MSG_BUFF                100003

#define NEXT_PAGE               "-> [Next Page]"
#define PREV_PAGE               "<- [Previous Page]"
#define MAIN_MENU               "<= [Main Menu]"

class npc_buff : public CreatureScript
{
public:
    npc_buff() : CreatureScript("npc_buff") {}

static bool OnGossipHello(Player* player, Creature* pCreature)
{
    if(sWorld->getBoolConfig(CONFIG_NPC_BUFF_ONLYGMS)) // If Npc_Buff.OnlyGMs is enabled in worldserver.conf
        if (player->GetSession()->GetSecurity() == SEC_PLAYER)
        {
            pCreature->Whisper("Sorry, I can only Buff Platinum Members.", LANG_UNIVERSAL, player);
            return true;
        }

    bool EnableSmallBuff = sWorld->getBoolConfig(CONFIG_NPC_BUFF_ENABLESMALLBUFF);
    bool EnableGreatBuff = sWorld->getBoolConfig(CONFIG_NPC_BUFF_ENABLEGREATBUFF);
    bool EnableGMBuff = sWorld->getBoolConfig(CONFIG_NPC_BUFF_ENABLEGMBUFF);
    bool EnablePlayerTools = sWorld->getBoolConfig(CONFIG_NPC_BUFF_ENABLEPLAYERTOOLS);
    bool EnableResSickness = sWorld->getBoolConfig(CONFIG_NPC_BUFF_ENABLEREMOVERESSICKNESS);
    bool EnableGivemeGold = sWorld->getBoolConfig(CONFIG_NPC_BUFF_ENABLEGIVEGOLD);

    // Main Menu

    // Check config if "Small  Buff " is enabled or not
    if(EnableSmallBuff)
        AddGossipItemFor(player,   7, "Small Buff ->"              , GOSSIP_SENDER_MAIN, 1000);
    // Check config if "Great Buff" is enabled or not
    if(EnableGreatBuff)
        AddGossipItemFor(player,   7, "Great Buff ->"              , GOSSIP_SENDER_MAIN, 2000);
    // Check config if "GM Buff" is enabled or not
    if(EnableGMBuff)
    {
    if (player->GetSession()->GetSecurity() > SEC_PLAYER)
        {
        AddGossipItemFor(player,   7, "Platinum Members Buff ->"                 , GOSSIP_SENDER_MAIN, 3000);
        }
    }
    // Check config if "Player Tools" is enabled or not
    if(EnablePlayerTools)
        AddGossipItemFor(player,   7, "Player Tools ->"            , GOSSIP_SENDER_MAIN, 4000);

    // Check config file if "Remove res sickness" option is enabled or not
    if(EnableResSickness)
        AddGossipItemFor(player,   10, "Remove Resurrect Sickness" , GOSSIP_SENDER_MAIN, 5000);

    SendGossipMenuFor(player,  MSG_TYPE, pCreature->GetGUID());

return true;
}

static bool showSmallBuff(Player *player, Creature *pCreature, uint32 showFromId = 0)
{


 QueryResult result;
 result = WorldDatabase.PQuery("SELECT `name`, `cat_number` FROM `npc_buff_spells` WHERE `cat_number` < 2000 ORDER BY `cat_number` ASC");

 if (result)
 {
 std::string name = "";
 uint32 catNumber = 0;
  do
 {
 Field *fields = result->Fetch();
 name = fields[0].GetString();
 catNumber = fields[1].GetInt32();

    AddGossipItemFor(player,  9, name, GOSSIP_SENDER_MAIN, catNumber);
}
 while (result->NextRow());

    SendGossipMenuFor(player,  MSG_BUFF, pCreature->GetGUID());
 return true;
 }
 else
 {
 if (showFromId = 0)
 {
 //you are too poor
 pCreature->Whisper("You don't have enough money.", LANG_UNIVERSAL, player);
 CloseGossipMenuFor(player);
 }
 else
 {

 //show Spells from beginning
 showSmallBuff(player, pCreature, 0);
 }
 }

 return false;
}

static bool showGreatBuff(Player *player, Creature *pCreature, uint32 showFromId = 0)
{

 QueryResult result;
 result = WorldDatabase.PQuery("SELECT `name`, `cat_number` FROM `npc_buff_spells` WHERE `cat_number` < 3000 AND `cat_number` > 2000 ORDER BY `cat_number` ASC");

 if (result)
 {
 std::string name = "";
 uint32 catNumber = 0;
  do
 {
 Field *fields = result->Fetch();
 name = fields[0].GetString();
 catNumber = fields[1].GetInt32();

    AddGossipItemFor(player,  9, name, GOSSIP_SENDER_MAIN, catNumber);
}
 while (result->NextRow());

    SendGossipMenuFor(player,  MSG_BUFF, pCreature->GetGUID());
 return true;
 }
 else
 {
 if (showFromId = 0)
 {
 //you are too poor
 pCreature->Whisper("You don't have enough money.", LANG_UNIVERSAL, player);
 CloseGossipMenuFor(player);
 }
 else
 {

 //show Spells from beginning
 showGreatBuff(player, pCreature, 0);
 }
 }

 return false;
}

static bool showGmBuff(Player *player, Creature *pCreature, uint32 showFromId = 0)
{


 QueryResult result;
 result = WorldDatabase.PQuery("SELECT `name`, `cat_number` FROM `npc_buff_spells` WHERE `cat_number` < 4000 AND `cat_number` > 3000 ORDER BY `cat_number` ASC");

 if (result)
 {
 std::string name = "";
 uint32 catNumber = 0;
  do
 {
 Field *fields = result->Fetch();
 name = fields[0].GetString();
 catNumber = fields[1].GetInt32();

    AddGossipItemFor(player,  9, name, GOSSIP_SENDER_MAIN, catNumber);
}
 while (result->NextRow());

    SendGossipMenuFor(player,  MSG_BUFF, pCreature->GetGUID());
 return true;
 }
 else
 {
 if (showFromId = 0)
 {
 //you are too poor
 pCreature->Whisper("You don't have enough money.", LANG_UNIVERSAL, player);
 CloseGossipMenuFor(player);
 }
 else
 {

 //show Spells from beginning
 showGmBuff(player, pCreature, 0);
 }
 }

 return false;
}

static bool showPlayerTools(Player *player, Creature *pCreature, uint32 showFromId = 0)
{


 QueryResult result;
 result = WorldDatabase.PQuery("SELECT `name`, `cat_number` FROM `npc_buff_spells` WHERE `cat_number` < 5000 AND `cat_number` > 4000 ORDER BY `cat_number` ASC");

 if (result)
 {
 std::string name = "";
 uint32 catNumber = 0;
  do
 {
 Field *fields = result->Fetch();
 name = fields[0].GetString();
 catNumber = fields[1].GetInt32();

    AddGossipItemFor(player,  9, name, GOSSIP_SENDER_MAIN, catNumber);
}
 while (result->NextRow());

    SendGossipMenuFor(player,  MSG_BUFF, pCreature->GetGUID());
 return true;
 }
 else
 {
 if (showFromId = 0)
 {
 //you are too poor
 pCreature->Whisper("You don't have enough money.", LANG_UNIVERSAL, player);
 CloseGossipMenuFor(player);
 }
 else
 {

 //show Spells from beginning
 showPlayerTools(player, pCreature, 0);
 }
 }

 return false;
}

void static SendDefaultMenu(Player* player, Creature* pCreature, uint32 uiAction)
{

// Not allow in combat
if (player->IsInCombat())
{
    CloseGossipMenuFor(player);
    pCreature->Say("You are in combat!", LANG_UNIVERSAL);
    return;
}

    bool EnableSmallBuff = sWorld->getBoolConfig(CONFIG_NPC_BUFF_ENABLESMALLBUFF);
    bool EnableGreatBuff = sWorld->getBoolConfig(CONFIG_NPC_BUFF_ENABLEGREATBUFF);
    bool EnableGMBuff = sWorld->getBoolConfig(CONFIG_NPC_BUFF_ENABLEGMBUFF);
    bool EnablePlayerTools = sWorld->getBoolConfig(CONFIG_NPC_BUFF_ENABLEPLAYERTOOLS);
    bool EnableResSickness = sWorld->getBoolConfig(CONFIG_NPC_BUFF_ENABLEREMOVERESSICKNESS);
    bool EnableGivemeGold = sWorld->getBoolConfig(CONFIG_NPC_BUFF_ENABLEGIVEGOLD);

  // send name as gossip item


       QueryResult result;
        uint32 spellId = 0;
        uint32 catNumber = 0;
        uint32 goldCost = 0;
        std::string spellName = "";

        result = WorldDatabase.PQuery("SELECT `spell_id`, `cat_number`, `cost`, `name` FROM `npc_buff_spells` WHERE `cat_number` = %u LIMIT 1", uiAction);

        if (result)
        {

            do {

            Field *fields = result->Fetch();
            spellId = fields[0].GetInt32();
            catNumber = fields[1].GetInt32();
            goldCost = fields[2].GetInt32();
            spellName = fields[3].GetString();

            if (player->GetMoney() < goldCost)
            {
                pCreature->Whisper("You dont have enough money!", LANG_UNIVERSAL, player);
                CloseGossipMenuFor(player);
                return;
            }
            else if (uiAction < 5000 && uiAction != 1000 && uiAction != 2000 && uiAction != 3000 && uiAction != 4000 && uiAction != 5005)
            {
    CloseGossipMenuFor(player);
    player->CastSpell(player,spellId,false);
    player->ModifyMoney(-goldCost);

            }

            } while (result->NextRow());
        } else {
            //AddGossipItemFor(player,   7, MAIN_MENU, GOSSIP_SENDER_MAIN, 5005);
        }

 switch(uiAction)
{

case 1000: //Small  Buff
         showSmallBuff(player, pCreature, 0);
        //AddGossipItemFor(player,   7, "<- Main Menu"                            , GOSSIP_SENDER_MAIN, 5005);

    SendGossipMenuFor(player,  MSG_BUFF, pCreature->GetGUID());
break;

case 2000: //Great Buff


        showGreatBuff(player, pCreature, 0);
        //AddGossipItemFor(player,   7, "<- Main Menu"                            , GOSSIP_SENDER_MAIN, 5005);

    SendGossipMenuFor(player,  MSG_BUFF, pCreature->GetGUID());
break;

case 3000: //GM  Buff

        showGmBuff(player, pCreature, 0);
        //AddGossipItemFor(player,   7, "<- Main Menu"                            , GOSSIP_SENDER_MAIN, 5005);

    SendGossipMenuFor(player,  MSG_BUFF,pCreature->GetGUID());
break;

case 4000: //Player Tools
    // Check config if "Give me Gold" is enabled or not

        showPlayerTools(player, pCreature, 0);
        //AddGossipItemFor(player,   7, "<- Main Menu"                            , GOSSIP_SENDER_MAIN, 5005);

    SendGossipMenuFor(player,  MSG_BUFF,pCreature->GetGUID());
break;

case 5005: //Back To Main Menu
    // Main Menu
    // Check config if "Small  Buff " is enabled or not
    if(EnableSmallBuff)
        AddGossipItemFor(player,   7, "Small Buff ->"              , GOSSIP_SMALLBUFF, 1000);
    // Check config if "Great Buff" is enabled or not
    if(EnableGreatBuff)
        AddGossipItemFor(player,   7, "Great Buff ->"              , GOSSIP_LARGEBUFF, 2000);
    // Check config if "GM Buff" is enabled or not
    if(EnableGMBuff)
    {
    if (player->GetSession()->GetSecurity() > SEC_PLAYER)
        {
        AddGossipItemFor(player,   7, "Platinum Members Buff ->"                 , GOSSIP_SENDER_MAIN, 3000);
        }
    }
    // Check config if "Player Tools" is enabled or not
    if(EnablePlayerTools)
        AddGossipItemFor(player,   7, "Player Tools ->"            , GOSSIP_PLAYERTOOLS, 4000);
    // Check if Ress Sickness option is enabled
    if(EnableResSickness)
        AddGossipItemFor(player,   10, "Remove Resurrect Sickness" , GOSSIP_SENDER_MAIN, 5000);

    SendGossipMenuFor(player,  MSG_TYPE, pCreature->GetGUID());
break;

case 5000://Remove Res Sickness
    if(!player->HasAura(SPELL_RESURRECTION_SICKNESS_15007))
    {
        pCreature->Whisper("You don't have resurrection sickness.", LANG_UNIVERSAL, player);
        OnGossipHello(player, pCreature);
        return;
    }

    pCreature->CastSpell(player,38588,false); // Healing effect
    player->RemoveAurasDueToSpell(SPELL_RESURRECTION_SICKNESS_15007);
    CloseGossipMenuFor(player);
break;
 CloseGossipMenuFor(player);
 }

} //end of function

static bool OnGossipSelect(Player* player, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    // Main menu
    player->PlayerTalkClass->ClearMenus();
    if (uiSender == GOSSIP_SENDER_MAIN)
    SendDefaultMenu(player, pCreature, uiAction);

return true;
}

    static bool OnGossipSelectCode(Player* player, Creature* m_creature, uint32 sender, uint32 action, char const* code)
        {
            player->PlayerTalkClass->ClearMenus();
            // code
            return true;
        }
    struct MyAI : public ScriptedAI
        {
            MyAI(Creature* m_creature) : ScriptedAI(m_creature) { }
            bool GossipHello(Player* player) override
            {
                return OnGossipHello(player, me);
            }
            bool GossipSelect(Player* player, uint32 menuId, uint32 gossipListId) override
            {
                uint32 sender = player->PlayerTalkClass->GetGossipOptionSender(gossipListId);
                uint32 action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
                return OnGossipSelect(player, me, sender, action);
            }
            bool GossipSelectCode(Player* player, uint32 menuId, uint32 gossipListId, char const* code) override
            {
                uint32 sender = player->PlayerTalkClass->GetGossipOptionSender(gossipListId);
                uint32 action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
                return OnGossipSelectCode(player, me, sender, action, code);
            }
        };

    CreatureAI* GetAI(Creature* m_creature) const override
        {
            return new MyAI(m_creature);
        }
};

void AddSC_Npc_Buff()
{
    new npc_buff();
}