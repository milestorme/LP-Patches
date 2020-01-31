//Modified by Marcus rewritten by LordPsyan
//original script created by ??
#include "LordPsyan.h"

#define GOSSIP_SENDER_MAIN      1000
#define MSG_TYPE                100004
#define MSG_PET                 100005
#define MAIN_MENU               "<= [Main Menu]"

class Npc_Beastmaster : public CreatureScript
{
public:
        Npc_Beastmaster() : CreatureScript("Npc_Beastmaster") { }


void static CreatePet(Player *player, Creature * m_creature, uint32 entry) {

    if(sConfigMgr->GetBoolDefault("BeastMaster.OnlyHunter", false)) // Checks to see if Only Hunters can have pets.
     {
        if(player->GetClass() != CLASS_HUNTER) {
            m_creature->Whisper("You are not a Hunter!", LANG_UNIVERSAL, player);
            return;
        }
     }

    if(player->GetPet()) {
        m_creature->Whisper("First you must abandon your Pet!", LANG_UNIVERSAL, player);
        return;
    }

    Creature *creatureTarget = m_creature->SummonCreature(entry, player->GetPositionX(), player->GetPositionY()+2, player->GetPositionZ(), player->GetOrientation(), TEMPSUMMON_CORPSE_TIMED_DESPAWN, 500);
    if(!creatureTarget) return;

    Pet* pet = player->CreateTamedPetFrom(creatureTarget, 0);

    if(!pet) return;

        // kill original creature
    creatureTarget->setDeathState(JUST_DIED);
    creatureTarget->RemoveCorpse();
    creatureTarget->SetHealth(0);                       // just for nice GM-mode view

    pet->SetPower(POWER_HAPPINESS, 1048000);

    // prepare visual effect for levelup
    pet->SetUInt32Value(UNIT_FIELD_LEVEL, player->GetLevel() - 1);
    pet->GetMap()->AddToMap((Creature*)pet);
        // visual effect for levelup
    pet->SetUInt32Value(UNIT_FIELD_LEVEL, player->GetLevel());

    if(!pet->InitStatsForLevel(player->GetLevel()))
        TC_LOG_ERROR("scripts", "Pet Create fail: no init stats for entry %u", entry);
        pet->UpdateAllStats();

    // caster have pet now
        player->SetMinion(pet, true);

        pet->SavePetToDB(PET_SAVE_AS_CURRENT);
        pet->InitTalentForLevel();
        player->PetSpellInitialize();
    //end
        CloseGossipMenuFor(player);
        m_creature->Whisper("Pet added. You might want to feed it and name it somehow.", LANG_UNIVERSAL, player);
        return;
    }

static bool OnGossipHello(Player* player, Creature* m_creature)
{
    bool EnableNormalPet = sConfigMgr->GetBoolDefault("BeastMaster.EnableNormalPet", true);
    bool EnableExoticPet = sConfigMgr->GetBoolDefault("BeastMaster.EnableExoticPet", true);

    // Main Menu

    // Check config if "Normal Pet " is enabled or not
    if(EnableNormalPet)
        AddGossipItemFor(player,  7, "|TInterface/ICONS/Ability_Hunter_Pet_Spider:30:30:-22|tNormal Pets ->"              , GOSSIP_SENDER_MAIN, 1000);
    // Check if player can have an exotic pet, and check config if "Exotic" is enabled or not
    if(player->CanTameExoticPets() && EnableExoticPet)
        AddGossipItemFor(player,  7, "|TInterface/ICONS/Ability_Hunter_Pet_Devilsaur:30:30:-22|tExotic Pets ->"              , GOSSIP_SENDER_MAIN, 2000);
    // Now to add the spells, vendor, and stable stuffs
    AddGossipItemFor(player, 4, "|TInterface/ICONS/INV_Misc_Book_11:30:30:-22|tTeach Me Pet spells ->"      , GOSSIP_SENDER_MAIN, 3000);
    AddGossipItemFor(player, 2, "|TInterface/ICONS/INV_Box_PetCarrier_01:25:25:-22|tPet Stable", GOSSIP_SENDER_MAIN, 6006);
    AddGossipItemFor(player, 6, "|TInterface/ICONS/INV_Misc_Petbiscuit_01:30:30:-22|tPet Food", GOSSIP_SENDER_MAIN, 6007);
    SendGossipMenuFor(player, MSG_TYPE, m_creature->GetGUID());
return true;
}

static bool showNormalPet(Player *player, Creature *m_creature, uint32 showFromId = 0)
{
 QueryResult result;
 result = WorldDatabase.PQuery("SELECT `entry`, `name` FROM `beastmaster` WHERE `cat_number` = 0 ORDER BY `entry` ASC");

 if (result)
 {
 uint32 entryNum = 0;
 std::string petName = "";
 uint8 tokenOrGold = 0;
 uint32 price = 0;
 uint32 nToken = 0;

  do
 {
 Field *fields = result->Fetch();
 entryNum = fields[0].GetInt32();
 petName = fields[1].GetString();

    AddGossipItemFor(player, 9, petName, GOSSIP_SENDER_MAIN, entryNum);
}
 while (result->NextRow());

    SendGossipMenuFor(player, MSG_PET, m_creature->GetGUID());
 return true;
 }
 else
 {
 if (showFromId == 0)
 {
 //you are too poor
 m_creature->Whisper("You don't have enough money.", LANG_UNIVERSAL, player);
 CloseGossipMenuFor(player);
 }
 else
 {

 //show Spells from beginning
 showNormalPet(player, m_creature, 0);
 }
 }

 return false;
}

static bool showExoticPet(Player *player, Creature *m_creature, uint32 showFromId = 0)
{
 QueryResult result;
 result = WorldDatabase.PQuery("SELECT `entry`, `name` FROM `beastmaster` WHERE `cat_number` = 1 ORDER BY `entry` ASC");

 if (result)
 {
 uint32 entryNum = 0;
 std::string petName = "";
  do
 {
 Field *fields = result->Fetch();
 entryNum = fields[0].GetInt32();
 petName = fields[1].GetString();

    AddGossipItemFor(player, 9, petName, GOSSIP_SENDER_MAIN, entryNum);
}
 while (result->NextRow());

    SendGossipMenuFor(player, MSG_PET, m_creature->GetGUID());
 return true;
 }
 else
 {
 if (showFromId == 0)
 {
 //you are too poor
 //m_creature->Whisper("You don't have enough money.", LANG_UNIVERSAL, player);
 //CloseGossipMenuFor(player);
 }
 else
 {

 //show Spells from beginning
 showExoticPet(player, m_creature, 0);
 }
 }

 return false;
}

static bool showPetSpells(Player *player, Creature *m_creature, uint32 showFromId = 0)
{
 QueryResult result;
 result = WorldDatabase.PQuery("SELECT `entry`, `name` FROM `beastmaster` WHERE `cat_number` = 2 ORDER BY `entry` ASC");

 if (result)
 {
 uint32 entryNum = 0;
 std::string petName = "";
 uint8 tokenOrGold = 0;
 uint32 price = 0;
 uint32 nToken = 0;

  do
 {
 Field *fields = result->Fetch();
 entryNum = fields[0].GetInt32();
 petName = fields[1].GetString();

    AddGossipItemFor(player, 9, petName, GOSSIP_SENDER_MAIN, entryNum);
}
 while (result->NextRow());

    SendGossipMenuFor(player, MSG_PET, m_creature->GetGUID());
 return true;
 }
 else
 {
 if (showFromId == 0)
 {
 //you are too poor
 m_creature->Whisper("You don't have enough money.", LANG_UNIVERSAL, player);
 CloseGossipMenuFor(player);
 }
 else
 {

 //show Spells from beginning
 showPetSpells(player, m_creature, 0);
 }
 }

 return false;
}

void static SendDefaultMenu(Player* player, Creature* m_creature, uint32 uiAction)
{

// Not allow in combat
if (player->IsInCombat())
{
    CloseGossipMenuFor(player);
    m_creature->Say("You are in combat!", LANG_UNIVERSAL);
    return;
}

    bool EnableNormalPet = sConfigMgr->GetBoolDefault("BeastMaster.EnableNormalPet", true);
    bool EnableExoticPet = sConfigMgr->GetBoolDefault("BeastMaster.EnableExoticPet", true);

  // send name as gossip item
       QueryResult result;
        uint32 spellId = 0;
        uint32 catNumber = 0;
        uint32 cost = 0;
        std::string spellName = "";
        uint32 token = 0;
        bool tokenOrGold = true;

        result = WorldDatabase.PQuery("SELECT * FROM `beastmaster` WHERE `entry` = %u LIMIT 1", uiAction);

if (result)
{
    do {
        Field *fields = result->Fetch();
        catNumber = fields[1].GetInt32();
        tokenOrGold = fields[2].GetBool();
        cost = fields[3].GetInt32();
        token = fields[4].GetInt32();
        spellName = fields[5].GetString();
        spellId = fields[6].GetInt32();

        if (tokenOrGold)
        {
            if (!player->HasItemCount(token, cost))
                {
                    m_creature->Whisper("You ain't gots no darn chips.", LANG_UNIVERSAL, player);
                    CloseGossipMenuFor(player);
                    return;
                }
            else if (uiAction != 1000 && uiAction != 2000 && uiAction != 3000 && catNumber != 2)
            {
    CloseGossipMenuFor(player);
    CreatePet(player, m_creature, spellId);
    player->DestroyItemCount(token, cost, true);
            }
            else if (catNumber == 2)
            {
            if (player->HasSpell(spellId))
            {
                m_creature->Whisper("You already know this spell.", LANG_UNIVERSAL, player);
                CloseGossipMenuFor(player);
                return;
            } else {
    CloseGossipMenuFor(player);
    player->LearnSpell(spellId, false);
    player->DestroyItemCount(token, cost, true);
            }
        }

        } else {
            if (player->GetMoney() < cost)
            {
                m_creature->Whisper("You dont have enough money!", LANG_UNIVERSAL, player);
                CloseGossipMenuFor(player);
                return;
            }
        else if (uiAction != 1000 && uiAction != 2000 && uiAction != 3000 && catNumber != 2)
        {
    CloseGossipMenuFor(player);
    CreatePet(player, m_creature, spellId);
    player->ModifyMoney(-int(cost));
        }
        else if (catNumber == 2)
        {
            if (player->HasSpell(spellId))
            {
                m_creature->Whisper("You already know this spell.", LANG_UNIVERSAL, player);
                CloseGossipMenuFor(player);
                return;
            } else {
    CloseGossipMenuFor(player);
    player->LearnSpell(spellId, false);
    player->ModifyMoney(-int(cost));
            }
        }
    }
} while (result->NextRow());
} else {
//AddGossipItemFor(player,  7, MAIN_MENU, GOSSIP_SENDER_MAIN, 5005);
}

 switch(uiAction)
{

case 1000: //Normal Pet
        showNormalPet(player, m_creature, 0);
        AddGossipItemFor(player,  7, "<- Main Menu"                            , GOSSIP_SENDER_MAIN, 5005);

    SendGossipMenuFor(player, MSG_PET, m_creature->GetGUID());
break;

case 2000: //Exotic Pet
        showExoticPet(player, m_creature, 0);
        AddGossipItemFor(player,  7, "<- Main Menu"                            , GOSSIP_SENDER_MAIN, 5005);

    SendGossipMenuFor(player, MSG_PET, m_creature->GetGUID());
break;

case 3000: //Pet Spells
        showPetSpells(player, m_creature, 0);
        AddGossipItemFor(player,  7, "<- Main Menu"                            , GOSSIP_SENDER_MAIN, 5005);

    SendGossipMenuFor(player, MSG_PET, m_creature->GetGUID());
break;

case 5005: //Back To Main Menu
    // Main Menu
    // Check config if "Normal Pet " is enabled or not
    if(EnableNormalPet)
        AddGossipItemFor(player,  7, "|TInterface/ICONS/Ability_Hunter_Pet_Spider:30:30:-22|tNormal Pets ->"              , GOSSIP_SENDER_MAIN, 1000);
    // Check if player can have an exotic pet, and check config if "Exotic" is enabled or not
    if(player->CanTameExoticPets() && EnableExoticPet)
        AddGossipItemFor(player,  7, "|TInterface/ICONS/Ability_Hunter_Pet_Devilsaur:30:30:-22|tExotic Pets ->"              , GOSSIP_SENDER_MAIN, 2000);
    // Now to add the spells, vendor, and stable stuffs
    AddGossipItemFor(player, 4, "|TInterface/ICONS/INV_Misc_Book_11:30:30:-22|tTeach Me Pet spells ->"      , GOSSIP_SENDER_MAIN, 3000);
    AddGossipItemFor(player, 2, "|TInterface/ICONS/INV_Box_PetCarrier_01:30:30:-22|tPet Stable", GOSSIP_SENDER_MAIN, 6006);
    AddGossipItemFor(player, 6, "|TInterface/ICONS/INV_Misc_Petbiscuit_01:30:30:-22|tPet Food", GOSSIP_SENDER_MAIN, 6007);
    AddGossipItemFor(player, 4, "|TInterface/ICONS/INV_Misc_Book_11:30:30:-22|tReset Talents", GOSSIP_SENDER_MAIN, 6008);
    SendGossipMenuFor(player, MSG_TYPE, m_creature->GetGUID());
break;

case 6006:
    player->GetSession()->SendStablePet(m_creature->GetGUID());
    CloseGossipMenuFor(player);
    break;

case 6007:
    player->GetSession()->SendListInventory(m_creature->GetGUID(), 0);
    CloseGossipMenuFor(player);
    break;

case 6008:
    player->ResetPetTalents();
    CloseGossipMenuFor(player);
    break;

 CloseGossipMenuFor(player);
 }

} //end of function

static bool OnGossipSelect(Player* player, Creature* m_creature, uint32 uiSender, uint32 uiAction)
{
    // Main menu
    player->PlayerTalkClass->ClearMenus();
    if (uiSender == GOSSIP_SENDER_MAIN)
    SendDefaultMenu(player, m_creature, uiAction);

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

void AddSC_Npc_Beastmaster()
{
    new Npc_Beastmaster();
}
