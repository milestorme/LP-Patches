/*
Idea and base script by Vextah.
Help and fixes on original script by: Core surgeon & (cant remember other who initially helped but kudos)
Modified by LordPsyan
*/

#include "ScriptMgr.h"
#include "LordPsyan.h"

class custom_CongratsOnLevel : public PlayerScript
{
public:
    custom_CongratsOnLevel() : PlayerScript("custom_CongratsOnLevel") { }

    void OnLevelChanged(Player* player, uint8 newLevel)
    {
        uint32 money, item, item2, spell;

        switch(++newLevel)
        {
            case 10:
            {
            QueryResult result;
            result = WorldDatabase.PQuery("SELECT * FROM `congrats_on_level` WHERE `level` = 10");
            if (!result)
            {
               return;
            } else {
               uint32 money = 0;
               uint32 item1 = 0;
               uint32 item2 = 0;
               uint32 spell = 0;
            do
            {
               Field *fields = result->Fetch();
               money = fields[1].GetInt32();
               item1 = fields[2].GetInt32();
               item2 = fields[3].GetInt32();
               spell = fields[4].GetInt32();

               player->ModifyMoney(money * 10000);
               player->AddItem(item1, 1);
               player->AddItem(item2, 1);
               player->CastSpell(player, spell);
            }
            while (result->NextRow());
               return;
            }
            }
            break;
            case 20:
            {
            QueryResult result;
            result = WorldDatabase.PQuery("SELECT * FROM `congrats_on_level` WHERE `level` = 20");
            if (!result)
            {
               return;
            } else {
               uint32 money = 0;
               uint32 item1 = 0;
               uint32 item2 = 0;
               uint32 spell = 0;
            do
            {
               Field *fields = result->Fetch();
               money = fields[1].GetInt32();
               item1 = fields[2].GetInt32();
               item2 = fields[3].GetInt32();
               spell = fields[4].GetInt32();

               player->ModifyMoney(money * 10000);
               player->AddItem(item1, 1);
               player->AddItem(item2, 1);
               player->CastSpell(player, spell);
            }
            while (result->NextRow());
               return;
            }
            }
            break;
            case 30:
            {
            QueryResult result;
            result = WorldDatabase.PQuery("SELECT * FROM `congrats_on_level` WHERE `level` = 30");
            if (!result)
            {
               return;
            } else {
               uint32 money = 0;
               uint32 item1 = 0;
               uint32 item2 = 0;
               uint32 spell = 0;
            do
            {
               Field *fields = result->Fetch();
               money = fields[1].GetInt32();
               item1 = fields[2].GetInt32();
               item2 = fields[3].GetInt32();
               spell = fields[4].GetInt32();

               player->ModifyMoney(money * 10000);
               player->AddItem(item1, 1);
               player->AddItem(item2, 1);
               player->CastSpell(player, spell);
            }
            while (result->NextRow());
               return;
            }
            }
            break;
            case 40:
            {
            QueryResult result;
            result = WorldDatabase.PQuery("SELECT * FROM `congrats_on_level` WHERE `level` = 40");
            if (!result)
            {
               return;
            } else {
               uint32 money = 0;
               uint32 item1 = 0;
               uint32 item2 = 0;
               uint32 spell = 0;
            do
            {
               Field *fields = result->Fetch();
               money = fields[1].GetInt32();
               item1 = fields[2].GetInt32();
               item2 = fields[3].GetInt32();
               spell = fields[4].GetInt32();

               player->ModifyMoney(money * 10000);
               player->AddItem(item1, 1);
               player->AddItem(item2, 1);
               player->CastSpell(player, spell);
            }
            while (result->NextRow());
               return;
            }
            }
            break;
            case 50:
            {
            QueryResult result;
            result = WorldDatabase.PQuery("SELECT * FROM `congrats_on_level` WHERE `level` = 50");
            if (!result)
            {
               return;
            } else {
               uint32 money = 0;
               uint32 item1 = 0;
               uint32 item2 = 0;
               uint32 spell = 0;
            do
            {
               Field *fields = result->Fetch();
               money = fields[1].GetInt32();
               item1 = fields[2].GetInt32();
               item2 = fields[3].GetInt32();
               spell = fields[4].GetInt32();

               player->ModifyMoney(money * 10000);
               player->AddItem(item1, 1);
               player->AddItem(item2, 1);
               player->CastSpell(player, spell);
            }
            while (result->NextRow());
               return;
            }
            }
            break;
            case 60:
            {
            QueryResult result;
            result = WorldDatabase.PQuery("SELECT * FROM `congrats_on_level` WHERE `level` = 60");
            if (!result)
            {
               return;
            } else {
               uint32 money = 0;
               uint32 item1 = 0;
               uint32 item2 = 0;
               uint32 spell = 0;
            do
            {
               Field *fields = result->Fetch();
               money = fields[1].GetInt32();
               item1 = fields[2].GetInt32();
               item2 = fields[3].GetInt32();
               spell = fields[4].GetInt32();

               player->ModifyMoney(money * 10000);
               player->AddItem(item1, 1);
               player->AddItem(item2, 1);
               player->CastSpell(player, spell);
            }
            while (result->NextRow());
               return;
            }
            }
            break;
            case 70:
            {
            QueryResult result;
            result = WorldDatabase.PQuery("SELECT * FROM `congrats_on_level` WHERE `level` = 70");
            if (!result)
            {
               return;
            } else {
               uint32 money = 0;
               uint32 item1 = 0;
               uint32 item2 = 0;
               uint32 spell = 0;
            do
            {
               Field *fields = result->Fetch();
               money = fields[1].GetInt32();
               item1 = fields[2].GetInt32();
               item2 = fields[3].GetInt32();
               spell = fields[4].GetInt32();

               player->ModifyMoney(money * 10000);
               player->AddItem(item1, 1);
               player->AddItem(item2, 1);
               player->CastSpell(player, spell);
            }
            while (result->NextRow());
               return;
            }
            }
            break;
            case 80:
            {
            QueryResult result;
            result = WorldDatabase.PQuery("SELECT * FROM `congrats_on_level` WHERE `level` = 80");
            if (!result)
            {
               return;
            } else {
               uint32 money = 0;
               uint32 item1 = 0;
               uint32 item2 = 0;
               uint32 spell = 0;
            do
            {
               Field *fields = result->Fetch();
               money = fields[1].GetInt32();
               item1 = fields[2].GetInt32();
               item2 = fields[3].GetInt32();
               spell = fields[4].GetInt32();

               player->ModifyMoney(money * 10000);
               player->AddItem(item1, 1);
               player->AddItem(item2, 1);
               player->CastSpell(player, spell);
            }
            while (result->NextRow());
               return;
            }
            }
            break;
            default:
        return;
        }

        std::ostringstream ss;
        ss << "|cffFF0000[Faction Gaming]|r Congrats to " << player->GetName() << " on reaching level " << (uint32)newLevel;
        sWorld->SendServerMessage(SERVER_MSG_STRING, ss.str().c_str());

        std::ostringstream ss2;
        ss2 << "For your hard work and dedication you have been awarded " << money << " gold, special items, and a powerful buff!";
        player->GetSession()->SendNotification(ss2.str().c_str());

        player->ModifyMoney(money*GOLD);
        player->AddItem(item, 1);
        player->AddItem(item2, 1);
        player->CastSpell(player, spell, false);
    }
};

void AddSC_custom_CongratsOnLevel()
{
    new custom_CongratsOnLevel();
}